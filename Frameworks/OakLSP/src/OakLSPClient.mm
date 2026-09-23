#import "OakLSPClient.h"
#include <lsp/client_endpoint.h>
#include <lsp/process.h>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <signal.h>
#include <lsp/json/parser.h>
#include <lsp/json/writer.h>
#include <deque>
#include <functional>

namespace {
template <typename T> NSDictionary* CocoaJSON(T const& value) {
	std::string encoded;
	{ lsp::json::Writer writer(encoded); auto object = writer.beginObject(); lsp::writeJson(value, object); }
	return [NSJSONSerialization JSONObjectWithData:[NSData dataWithBytes:encoded.data() length:encoded.size()] options:0 error:nil];
}
struct Session {
	std::mutex mutex;
	std::condition_variable wake;
	std::string text, path;
	NSInteger version = 1;
	NSInteger analysisVersion = 0;
	std::string analysisText;
	bool awaitingDiagnostics = false;
	std::chrono::steady_clock::time_point analysisStarted, lastEdit;
	std::atomic<int> processIdentifier = 0;
	bool aeon = false;
	std::atomic<bool> formattingSupported = false;
	std::atomic<bool> definitionSupported = false, renameSupported = false, prepareRenameSupported = false;
	std::atomic<NSInteger> authorizedVersion = 0;
	std::atomic<bool> synthesisBusy = false, synthesisApplied = false;
	NSString* (^applyEdit)(NSDictionary*, NSInteger);
	void (^notice)(NSString*);
	std::atomic<bool> stopping = false;
	std::deque<std::function<void(lsp::ClientEndpoint&)>> requests;
	void (^changed)(NSString*, NSArray*, NSInteger);

	void report(NSString* state, NSArray* items, NSInteger revision) {
		auto callback = changed;
		dispatch_async(dispatch_get_main_queue(), ^{ callback(state, items, revision); });
	}

	void run() {
		@autoreleasepool {
		lsp::Process process;
		std::unique_ptr<lsp::ClientEndpoint> endpoint;
		std::thread reader;
		std::atomic<bool> ended = false;
		try {
			NSString* configured = [NSUserDefaults.standardUserDefaults stringForKey:aeon ? @"LSPAeonPath" : @"LSPClangdPath"];
			NSString* executable = configured ?: @"";
			if(!configured && !aeon) {
				NSTask* lookup = [NSTask new]; lookup.executableURL = [NSURL fileURLWithPath:@"/usr/bin/xcrun"];
				lookup.arguments = @[@"--find", @"clangd"];
				NSPipe* output = [NSPipe pipe]; lookup.standardOutput = output;
				lookup.standardError = NSFileHandle.fileHandleWithNullDevice;
				if([lookup launchAndReturnError:nil]) {
					NSData* data = [output.fileHandleForReading readDataToEndOfFile]; [lookup waitUntilExit];
					if(lookup.terminationStatus == 0) executable = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet];
				}
			}
			if(![NSFileManager.defaultManager isExecutableFileAtPath:executable])
				throw std::runtime_error(aeon ? "Aeon not found. Set LSPAeonPath to the aeon executable." : "clangd not found. Set LSPClangdPath to an executable path.");
			process = lsp::Process::start(executable.UTF8String, aeon ? std::vector<std::string>{"-lsp"} : std::vector<std::string>{"--log=error", "--background-index=true", "-j=2"});
			processIdentifier = process.id();
			endpoint = std::make_unique<lsp::ClientEndpoint>(process.stdIO());
			auto uri = lsp::Uri::fileUriFromPath(path);
			endpoint->onWindowShowMessage([&](lsp::ShowMessageParams&& p) {
				NSString* message = [NSString stringWithUTF8String:p.message.c_str()];
				auto callback = notice;
				dispatch_async(dispatch_get_main_queue(), ^{ callback(message); });
			});
			endpoint->onWorkspaceApplyEdit([&](lsp::ApplyWorkspaceEditParams&& p) {
				@autoreleasepool {
				lsp::ApplyWorkspaceEditResult result; result.applied = false;
				NSInteger revision = authorizedVersion.exchange(0);
				if(!aeon || stopping || !revision) { result.failureReason = "No active synthesis authorized this edit."; return result; }
				NSDictionary* edit = CocoaJSON(p.edit);
				__block NSString* error;
				dispatch_sync(dispatch_get_main_queue(), ^{ error = applyEdit(edit, revision); });
				result.applied = error == nil;
				synthesisApplied = result.applied;
				if(error) result.failureReason = std::string(error.UTF8String);
				return result;
				}
			});
			endpoint->onTextDocumentPublishDiagnostics([&, uri](lsp::PublishDiagnosticsParams&& p) {
				@autoreleasepool {
				if(stopping || p.uri != uri) return;
				NSInteger revision;
				std::string diagnosticText;
				{
					std::lock_guard lock(mutex);
					revision = version;
					if(aeon) {
						// Aeon publishes once per didOpen/didChange, without a version.
						// Keep exactly one analysis in flight, never guess the latest version.
						if(!awaitingDiagnostics || (p.version && *p.version != analysisVersion)) return;
						awaitingDiagnostics = false; wake.notify_all();
						if(analysisVersion != version) return;
						diagnosticText = analysisText;
					} else if(!p.version || *p.version != revision) return;
				}
				NSMutableArray* items = [NSMutableArray new];
				for(auto const& d : p.diagnostics) {
					auto message = std::get_if<lsp::String>(&d.message);
					[items addObject:@{@"raw": CocoaJSON(d), @"message": message ? [NSString stringWithUTF8String:message->c_str()] : @"Diagnostic",
						@"line": @(d.range.start.line), @"column": @(d.range.start.character),
						@"endLine": @(d.range.end.line), @"endColumn": @(d.range.end.character),
						@"severity": @(d.severity ? static_cast<int>(*d.severity) : 1),
						@"source": d.source ? [NSString stringWithUTF8String:d.source->c_str()] : @"clangd"}];
				}
				if(aeon) {
					NSString* snapshot = [NSString stringWithUTF8String:diagnosticText.c_str()];
					NSRegularExpression* holes = [NSRegularExpression regularExpressionWithPattern:@"\\?[A-Za-z_][A-Za-z0-9_]*" options:0 error:nil];
					for(NSTextCheckingResult* match in [holes matchesInString:snapshot options:0 range:NSMakeRange(0,snapshot.length)]) {
						NSString* prefix = [snapshot substringToIndex:match.range.location];
						NSArray* lines = [prefix componentsSeparatedByString:@"\n"];
						if([lines.lastObject containsString:@"#"]) continue;
						NSUInteger line = lines.count-1, column = [lines.lastObject length];
						NSString* message = [@"Synthesize " stringByAppendingString:[snapshot substringWithRange:match.range]];
						NSDictionary* raw = @{@"range":@{@"start":@{@"line":@(line),@"character":@(column)},@"end":@{@"line":@(line),@"character":@(column+match.range.length)}},@"message":message};
						[items addObject:@{@"raw":raw,@"message":message,@"source":@"Aeon",@"severity":@3,@"line":@(line),@"column":@(column),@"endLine":@(line),@"endColumn":@(column+match.range.length)}];
					}
				}
				report(@"Ready", items, revision);
				}
			});
			reader = std::thread([&] {
				try { endpoint->runMessageLoop(); } catch(...) {}
				ended = true;
				wake.notify_all();
			});
			lsp::InitializeParams params;
			params.processId = getpid();
			params.rootUri = lsp::Uri::fileUriFromPath([[NSString stringWithUTF8String:path.c_str()] stringByDeletingLastPathComponent].UTF8String);
			params.capabilities.textDocument.emplace();
			params.capabilities.textDocument->definition.emplace();
			params.capabilities.textDocument->definition->linkSupport = true;
			params.capabilities.textDocument->rename.emplace();
			params.capabilities.textDocument->rename->prepareSupport = true;
			params.capabilities.textDocument->hover.emplace();
			params.capabilities.textDocument->hover->contentFormat = {lsp::MarkupKind::PlainText};
			params.capabilities.textDocument->completion.emplace();
			params.capabilities.textDocument->completion->completionItem.emplace();
			params.capabilities.textDocument->completion->completionItem->snippetSupport = false;
			params.capabilities.workspace.emplace();
			params.capabilities.workspace->applyEdit = true;
			params.capabilities.textDocument->codeAction.emplace();
			params.capabilities.textDocument->codeAction->codeActionLiteralSupport.emplace();
			params.capabilities.textDocument->codeAction->codeActionLiteralSupport->codeActionKind.valueSet = {lsp::CodeActionKind::Empty, lsp::CodeActionKind::QuickFix, lsp::CodeActionKind::Refactor, lsp::CodeActionKind::RefactorExtract, lsp::CodeActionKind::RefactorInline, lsp::CodeActionKind::RefactorMove, lsp::CodeActionKind::RefactorRewrite, lsp::CodeActionKind::Source, lsp::CodeActionKind::SourceOrganizeImports, lsp::CodeActionKind::SourceFixAll, lsp::CodeActionKind::Notebook};
			params.capabilities.textDocument->codeAction->disabledSupport = true;
			params.capabilities.textDocument->publishDiagnostics.emplace();
			params.capabilities.textDocument->publishDiagnostics->versionSupport = true;
			auto initialized = endpoint->initialize(params);
			if(!initialized.wait(aeon ? 30000 : 8000)) throw std::runtime_error("Language server initialization timed out");
			auto initialization = initialized.get();
			id formatting = CocoaJSON(initialization)[@"capabilities"][@"documentFormattingProvider"];
			formattingSupported = [formatting isKindOfClass:NSDictionary.class] || ([formatting isKindOfClass:NSNumber.class] && [formatting boolValue]);
			NSDictionary* capabilities = CocoaJSON(initialization)[@"capabilities"];
			id sync = capabilities[@"textDocumentSync"];
			NSInteger syncKind = [sync isKindOfClass:NSDictionary.class] ? [sync[@"change"] integerValue] : [sync isKindOfClass:NSNumber.class] ? [sync integerValue] : 0;
			if(syncKind != 1 && syncKind != 2) throw std::runtime_error("Server does not support document change synchronization.");
			auto supported = [&](NSString* key) { id v = capabilities[key]; return [v isKindOfClass:NSDictionary.class] || ([v isKindOfClass:NSNumber.class] && [v boolValue]); };
			definitionSupported = supported(@"definitionProvider"); renameSupported = supported(@"renameProvider");
			id rename = capabilities[@"renameProvider"];
			prepareRenameSupported = [rename isKindOfClass:NSDictionary.class] && [rename[@"prepareProvider"] boolValue];
			endpoint->initialized({});
			NSInteger sent;
			std::string initialText;
			{
				std::lock_guard lock(mutex);
				sent = version;
				initialText = text;
				if(aeon) { analysisVersion = sent; analysisText = text; awaitingDiagnostics = true; analysisStarted = std::chrono::steady_clock::now(); }
			}
			std::string language = aeon ? "aeon" : path.ends_with(".c") ? "c" : path.ends_with(".m") ? "objective-c" : path.ends_with(".mm") ? "objective-cpp" : "cpp";
			endpoint->textDocumentDidOpen({.textDocument = {.uri=uri, .languageId=std::move(language), .version=static_cast<int>(sent), .text=std::move(initialText)}});
			while(!stopping && !ended) {
				std::unique_lock lock(mutex);
				wake.wait_for(lock, std::chrono::milliseconds(50), [&]{
					return stopping || ended || ((!aeon || !awaitingDiagnostics) && ((version == sent && !requests.empty()) || (version != sent && (!requests.empty() || std::chrono::steady_clock::now()-lastEdit >= std::chrono::milliseconds(150)))));
				});
				if(stopping || ended) break;
				if(aeon && awaitingDiagnostics) {
					if(std::chrono::steady_clock::now()-analysisStarted > std::chrono::seconds(30)) throw std::runtime_error("Aeon analysis timed out. Restart the server to resynchronize.");
					continue;
				}
				if(version != sent && requests.empty() && std::chrono::steady_clock::now()-lastEdit < std::chrono::milliseconds(150)) continue;
				if(version != sent) {
					lsp::DidChangeTextDocumentParams change;
					change.textDocument.uri = uri;
					change.textDocument.version = static_cast<int>(version);
					change.contentChanges = {lsp::TextDocumentContentChangeWholeDocument{.text=text}};
					sent = version;
					if(aeon) { analysisVersion = sent; analysisText = text; awaitingDiagnostics = true; analysisStarted = std::chrono::steady_clock::now(); }
					lock.unlock();
					endpoint->textDocumentDidChange(change);
					if(aeon) continue; // Requests need the freshly analysed Aeon cache.
				}
				if(!lock.owns_lock()) lock.lock();
				auto pending = std::move(requests); requests.clear();
				lock.unlock();
				for(auto& request : pending) { if(!stopping) request(*endpoint); }
				(void)process.readAvailableStdErr();
			}
			if(ended && !stopping) throw std::runtime_error("clangd disconnected. Restart to reconnect.");
			endpoint->textDocumentDidClose({.textDocument={.uri=uri}});
			auto shutdown = endpoint->shutdown();
			if(shutdown.wait(1000)) { (void)shutdown.get(); endpoint->exit(); }
		} catch(std::exception const& e) {
			if(!stopping) { std::lock_guard lock(mutex); report([@"Failed · " stringByAppendingString:[NSString stringWithUTF8String:e.what()]], @[], version); }
		}
		// Bound shutdown without blocking the main thread. Reap after the reader
		// exits so Process never closes a descriptor underneath its read call.
		for(int i=0; reader.joinable() && !ended && i<20; ++i)
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		if(process.id() > 0 && !ended) kill(process.id(), SIGKILL);
		if(reader.joinable()) reader.join();
		if(process.id() > 0) { if(process.isRunning()) kill(process.id(), SIGKILL); (void)process.wait(); }
		processIdentifier = 0;
		}
	}
};
}

@implementation OakLSPClient {
	std::shared_ptr<Session> _session;
}
- (void)startPath:(NSString*)path content:(NSString*)content {
	[self stop];
	_version = 1;
	auto session = std::make_shared<Session>();
	session->path = path.UTF8String;
	session->aeon = [path.pathExtension.lowercaseString isEqualToString:@"ae"];
	session->text = content.UTF8String ?: "";
	__weak OakLSPClient* weakSelf = self;
	std::weak_ptr<Session> weakSession = session;
	session->notice = ^(NSString* message) {
		OakLSPClient* client = weakSelf;
		if(client && client->_session && client->_session == weakSession.lock() && client.notice) client.notice(message);
	};
	session->applyEdit = ^NSString*(NSDictionary* edit, NSInteger revision) {
		OakLSPClient* client = weakSelf;
		if(!client || !client->_session || client->_session != weakSession.lock() || client.version != revision)
			return @"Document changed or synthesis was stopped; edit rejected.";
		return client.applyWorkspaceEdit ? client.applyWorkspaceEdit(edit, revision) : @"No editor accepts this edit.";
	};
	session->changed = ^(NSString* state, NSArray* items, NSInteger version) {
		OakLSPClient* client = weakSelf;
		if(client && client->_session && client->_session == weakSession.lock() && client.version == version && client.changed)
			client.changed(state, items, version);
	};
	_session = session;
	std::thread([session]{ session->run(); }).detach();
}
- (void)updateContent:(NSString*)content {
	if(!_session) return;
	std::lock_guard lock(_session->mutex);
	std::string text = content.UTF8String ?: "";
	if(_session->text == text) return;
	_session->text = std::move(text);
	_session->version = ++_version;
	_session->lastEdit = std::chrono::steady_clock::now();
	_session->authorizedVersion = 0; // Editing revokes any pending synthesis edit.
	_session->wake.notify_all();
}
- (NSInteger)processIdentifier { return _session ? _session->processIdentifier.load() : 0; }
- (void)stop {
	if(_session) { _session->stopping = true; _session->wake.notify_all(); _session.reset(); }
}
- (void)codeActionsForDiagnostic:(NSDictionary*)diagnostic completion:(void (^)(NSArray*, NSString*))completion {
	if(!_session) { completion(@[], @"Start the language server first."); return; }
	auto session = _session;
	NSInteger revision = self.version;
	__weak OakLSPClient* weakSelf = self;
	std::weak_ptr<Session> weakSession = session;
	auto deliver = [weakSelf, weakSession, revision, completion](NSArray* actions, NSString* error) {
		dispatch_async(dispatch_get_main_queue(), ^{
			OakLSPClient* client = weakSelf;
			if(!client || !client->_session || client->_session != weakSession.lock() || client.version != revision)
				completion(@[], @"Document changed. Request actions again.");
			else completion(actions, error);
		});
	};
	std::string path = session->path;
	std::lock_guard lock(session->mutex);
	session->requests.push_back([diagnostic, path, deliver](lsp::ClientEndpoint& endpoint) {
		try {
			NSData* data = [NSJSONSerialization dataWithJSONObject:diagnostic[@"raw"] options:0 error:nil];
			std::string json((char const*)data.bytes, data.length);
			lsp::Diagnostic original; lsp::json::Parser parser(json); lsp::fromJson(parser.parse(), original);
			lsp::CodeActionParams params;
			params.textDocument.uri = lsp::Uri::fileUriFromPath(path);
			params.range = original.range;
			params.context.diagnostics = {original};
			// No language-specific action-kind filter: the server supplies the list.
			auto request = endpoint.textDocumentCodeAction(params);
			if(!request.wait(5000)) throw std::runtime_error("Code actions timed out.");
			auto result = request.get();
			NSMutableArray* actions = [NSMutableArray new];
			if(!result.isNull()) for(auto const& action : result.value())
				std::visit([&](auto const& value) { [actions addObject:CocoaJSON(value)]; }, action);
			deliver(actions, nil);
		} catch(std::exception const& e) { deliver(@[], [NSString stringWithUTF8String:e.what()]); }
	});
	session->wake.notify_all();
}
- (void)dealloc { [self stop]; }
- (BOOL)supportsFormatting { return _session && !_session->stopping && _session->formattingSupported; }
- (BOOL)supportsDefinition { return _session && !_session->stopping && _session->definitionSupported; }
- (BOOL)supportsRename { return _session && !_session->stopping && _session->renameSupported; }

// Share the request queue and snapshot checks for symbol operations.
- (void)symbolRequest:(NSString*)kind line:(NSUInteger)line character:(NSUInteger)character name:(NSString*)name completion:(void (^)(id, NSString*))completion {
	if(!_session) { completion(nil,@"Start the language server first."); return; }
	auto session = _session;
	NSInteger revision = self.version;
	__weak OakLSPClient* weakSelf = self;
	std::weak_ptr<Session> weakSession = session;
	std::string path = session->path;
	bool prepare = session->prepareRenameSupported;
	std::lock_guard lock(session->mutex);
	session->requests.push_back([weakSelf, weakSession, revision, path, line, character, name, kind, prepare, completion](lsp::ClientEndpoint& endpoint) {
		id value = nil; NSString* error = nil;
		try {
			if([kind isEqual:@"definition"]) {
				lsp::DefinitionParams params; params.textDocument.uri = lsp::Uri::fileUriFromPath(path); params.position = {.line=(unsigned)line,.character=(unsigned)character};
				auto request = endpoint.textDocumentDefinition(params);
				if(!request.wait(5000)) throw std::runtime_error("Go to Definition timed out.");
				auto result = request.get(); NSMutableArray* locations = [NSMutableArray array];
				if(!result.isNull()) std::visit([&](auto const& definition) {
					if constexpr(std::is_same_v<std::decay_t<decltype(definition)>, lsp::Definition>) std::visit([&](auto const& location) {
						if constexpr(std::is_same_v<std::decay_t<decltype(location)>, lsp::Location>) [locations addObject:CocoaJSON(location)];
						else for(auto const& item : location) [locations addObject:CocoaJSON(item)];
					}, definition);
					else for(auto const& item : definition) [locations addObject:CocoaJSON(item)];
				}, result.value());
				value = locations;
			} else if([kind isEqual:@"prepare"]) {
				if(!prepare) value = @{@"defaultBehavior":@YES};
				else {
					lsp::PrepareRenameParams params; params.textDocument.uri = lsp::Uri::fileUriFromPath(path); params.position = {.line=(unsigned)line,.character=(unsigned)character};
					auto request = endpoint.textDocumentPrepareRename(params);
					if(!request.wait(5000)) throw std::runtime_error("Prepare Rename timed out.");
					auto result = request.get();
					if(!result.isNull()) std::visit([&](auto const& item) { value = CocoaJSON(item); }, result.value());
					else error = @"This symbol cannot be renamed.";
				}
			} else {
				lsp::RenameParams params; params.textDocument.uri = lsp::Uri::fileUriFromPath(path); params.position = {.line=(unsigned)line,.character=(unsigned)character}; params.newName = name.UTF8String;
				auto request = endpoint.textDocumentRename(params);
				if(!request.wait(5000)) throw std::runtime_error("Rename timed out. No changes applied.");
				auto result = request.get(); if(!result.isNull()) value = CocoaJSON(result.value());
			}
		} catch(std::exception const& e) { error = [NSString stringWithUTF8String:e.what()]; }
		dispatch_async(dispatch_get_main_queue(), ^{
			OakLSPClient* client = weakSelf;
			if(!client || !client->_session || client->_session != weakSession.lock() || client.version != revision) completion(nil,@"Document or server changed. Try again.");
			else completion(value,error);
		});
	});
	session->wake.notify_all();
}
- (void)definitionsAtLine:(NSUInteger)line character:(NSUInteger)character completion:(void (^)(NSArray<NSDictionary*>*, NSString*))completion { [self symbolRequest:@"definition" line:line character:character name:nil completion:completion]; }
- (void)prepareRenameAtLine:(NSUInteger)line character:(NSUInteger)character completion:(void (^)(NSDictionary*, NSString*))completion { [self symbolRequest:@"prepare" line:line character:character name:nil completion:completion]; }
- (void)renameAtLine:(NSUInteger)line character:(NSUInteger)character newName:(NSString*)name completion:(void (^)(NSDictionary*, NSString*))completion { [self symbolRequest:@"rename" line:line character:character name:name completion:completion]; }
- (void)formatWithTabSize:(NSUInteger)tabSize insertSpaces:(BOOL)insertSpaces completion:(void (^)(NSArray<NSDictionary*>*, NSString*))completion {
	if(!self.supportsFormatting) { completion(nil, @"This server does not support document formatting."); return; }
	auto session = _session;
	NSInteger revision = self.version;
	__weak OakLSPClient* weakSelf = self;
	std::weak_ptr<Session> weakSession = session;
	std::string path = session->path;
	std::lock_guard lock(session->mutex);
	session->requests.push_back([weakSelf, weakSession, revision, tabSize, insertSpaces, completion, path](lsp::ClientEndpoint& endpoint) {
		NSMutableArray* edits = [NSMutableArray array];
		NSString* error = nil;
		try {
			lsp::DocumentFormattingParams params;
			params.textDocument.uri = lsp::Uri::fileUriFromPath(path);
			params.options.tabSize = std::max((NSUInteger)1, tabSize);
			params.options.insertSpaces = insertSpaces;
			auto request = endpoint.textDocumentFormatting(params);
			if(!request.wait(5000)) throw std::runtime_error("Formatting timed out. No changes applied.");
			auto result = request.get();
			if(!result.isNull()) for(auto const& edit : result.value()) [edits addObject:CocoaJSON(edit)];
		} catch(std::exception const& e) { error = [NSString stringWithUTF8String:e.what()]; }
		dispatch_async(dispatch_get_main_queue(), ^{
			OakLSPClient* client = weakSelf;
			if(!client || !client->_session || client->_session != weakSession.lock() || client.version != revision) completion(nil,@"Document or server changed. Format again.");
			else completion(error ? nil : edits,error);
		});
	});
	session->wake.notify_all();
}
- (void)hoverAtLine:(NSUInteger)line character:(NSUInteger)character completion:(void (^)(NSString*))completion {
	if(!_session) { completion(nil); return; }
	auto session = _session;
	NSInteger revision = self.version;
	__weak OakLSPClient* weakSelf = self;
	std::weak_ptr<Session> weakSession = session;
	std::string path = session->path;
	std::lock_guard lock(session->mutex);
	session->requests.push_back([weakSelf, weakSession, revision, line, character, completion, path](lsp::ClientEndpoint& endpoint) {
		NSString* text = nil;
		try {
			lsp::HoverParams params;
			params.textDocument.uri = lsp::Uri::fileUriFromPath(path);
			params.position.line = line; params.position.character = character;
			auto request = endpoint.textDocumentHover(params);
			if(!request.wait(5000)) throw std::runtime_error("Hover timed out");
			auto result = request.get();
			if(!result.isNull()) {
				id contents = CocoaJSON(result.value())[@"contents"];
				NSMutableArray* parts = [NSMutableArray array];
				for(id part in ([contents isKindOfClass:NSArray.class] ? contents : @[contents ?: @""])) {
					id value = [part isKindOfClass:NSDictionary.class] ? part[@"value"] : part;
					if([value isKindOfClass:NSString.class] && [value length]) [parts addObject:value];
				}
				text = [parts componentsJoinedByString:@"\n\n"];
			}
		} catch(...) {}
		dispatch_async(dispatch_get_main_queue(), ^{
			OakLSPClient* client = weakSelf;
			completion(client && client->_session && client->_session == weakSession.lock() && client.version == revision ? text : nil);
		});
	});
	session->wake.notify_all();
}
- (void)completionsAtLine:(NSUInteger)line character:(NSUInteger)character prefix:(NSString*)prefix completion:(void (^)(NSArray<NSString*>*))completion {
	if(!_session) { completion(@[]); return; }
	auto session = _session;
	NSInteger revision = self.version;
	__weak OakLSPClient* weakSelf = self;
	std::weak_ptr<Session> weakSession = session;
	std::string path = session->path;
	std::lock_guard lock(session->mutex);
	session->requests.push_back([weakSelf, weakSession, revision, line, character, prefix, completion, path](lsp::ClientEndpoint& endpoint) {
		NSMutableArray* items = [NSMutableArray new];
		try {
			lsp::CompletionParams params;
			params.textDocument.uri = lsp::Uri::fileUriFromPath(path);
			params.position.line = line; params.position.character = character;
			auto request = endpoint.textDocumentCompletion(params);
			if(!request.wait(5000)) throw std::runtime_error("Completion timed out");
			auto result = request.get();
			if(!result.isNull()) std::visit([&](auto const& value) {
				if constexpr(std::is_same_v<std::decay_t<decltype(value)>, lsp::CompletionList>) {
					// Item defaults were not advertised. Do not silently omit their semantics.
					if(!value.itemDefaults) for(auto const& item : value.items) [items addObject:CocoaJSON(item)];
				} else for(auto const& item : value) [items addObject:CocoaJSON(item)];
			}, result.value());
		} catch(...) { [items removeAllObjects]; }
		[items sortUsingComparator:^NSComparisonResult(NSDictionary* a, NSDictionary* b) { return [(a[@"sortText"] ?: a[@"label"]) compare:(b[@"sortText"] ?: b[@"label"])]; }];
		NSMutableArray* suffixes = [NSMutableArray new];
		for(NSDictionary* item in items) {
			if([item[@"insertTextFormat"] intValue] == 2 || [item[@"additionalTextEdits"] count] || item[@"command"]) continue;
			NSString* text = item[@"insertText"] ?: item[@"label"];
			NSDictionary* edit = item[@"textEdit"];
			if(edit) {
				NSDictionary* range = edit[@"range"] ?: edit[@"replace"];
				if(!range || [range[@"start"][@"line"] unsignedIntegerValue] != line || [range[@"end"][@"line"] unsignedIntegerValue] != line || [range[@"end"][@"character"] unsignedIntegerValue] != character) continue;
				NSUInteger start = [range[@"start"][@"character"] unsignedIntegerValue];
				text = edit[@"newText"];
				if(start == character) text = [prefix stringByAppendingString:text];
				else if(character < prefix.length || start != character-prefix.length) continue;
			}
			if(![text hasPrefix:prefix] || text.length <= prefix.length || [text rangeOfCharacterFromSet:NSCharacterSet.newlineCharacterSet].location != NSNotFound) continue;
			NSString* suffix = [text substringFromIndex:prefix.length];
			if(![suffixes containsObject:suffix]) [suffixes addObject:suffix];
		}
		dispatch_async(dispatch_get_main_queue(), ^{
			OakLSPClient* client = weakSelf;
			if(client && client->_session && client->_session == weakSession.lock() && client.version == revision) completion(suffixes);
			else completion(@[]);
		});
	});
	session->wake.notify_all();
}
- (void)executeSynthesis:(NSDictionary*)action completion:(void (^)(NSString*))completion {
	NSDictionary* command = action[@"command"];
	NSArray* arguments = command[@"arguments"];
	if(!_session || !_session->aeon || action[@"edit"] || action[@"disabled"] || ![command[@"command"] isEqual:@"aeon.synthesize"] || arguments.count != 3 ||
		![arguments.lastObject isKindOfClass:NSString.class] || ![arguments.lastObject length] ||
		![[NSURL URLWithString:arguments.firstObject].path.stringByStandardizingPath isEqualToString:[NSString stringWithUTF8String:_session->path.c_str()].stringByStandardizingPath]) {
		completion(@"Invalid Aeon synthesis command for this document."); return;
	}
	auto session = _session;
	NSInteger revision = self.version;
	if(session->synthesisBusy.exchange(true)) { completion(@"Synthesis is already running."); return; }
	session->synthesisApplied = false;
	session->authorizedVersion = revision;
	__weak OakLSPClient* weakSelf = self;
	std::weak_ptr<Session> weakSession = session;
	std::lock_guard lock(session->mutex);
	session->requests.push_back([command, weakSelf, weakSession, completion](lsp::ClientEndpoint& endpoint) {
		auto active = weakSession.lock();
		NSString* error = nil;
		try {
			NSData* data = [NSJSONSerialization dataWithJSONObject:command options:0 error:nil];
			std::string json((char const*)data.bytes, data.length);
			lsp::Command parsed; lsp::json::Parser parser(json); lsp::fromJson(parser.parse(), parsed);
			lsp::ExecuteCommandParams params; params.command = parsed.command; params.arguments = parsed.arguments;
			// This Aeon/pygls version counts the defaulted budget as required,
			// although its code action supplies only URI, hole and backend.
			params.arguments->emplace_back(5.0);
			auto request = endpoint.workspaceExecuteCommand(params);
			bool ready = false;
			for(int i=0; i<200 && !active->stopping; ++i) if(request.wait(100)) { ready = true; break; }
			if(!ready) { active->stopping = true; throw std::runtime_error("Synthesis cancelled or timed out. Restart the server to retry."); }
			(void)request.get();
			active->authorizedVersion = 0;
			if(!active->synthesisApplied) error = @"No replacement was applied. The result may be unavailable or rejected. Try another backend.";
		} catch(std::exception const& e) { active->authorizedVersion = 0; error = [NSString stringWithUTF8String:e.what()]; }
		active->synthesisBusy = false;
		dispatch_async(dispatch_get_main_queue(), ^{
			OakLSPClient* client = weakSelf;
			if(client && client->_session == weakSession.lock()) completion(error);
		});
	});
	session->wake.notify_all();
}
@end

NSString* OakLSPApplyCodeAction(NSDictionary* action, NSString* content, NSString* path, NSInteger version, NSString** error) {
	auto reject = [&](NSString* reason) -> NSString* { if(error) *error = reason; return nil; };
	if(action[@"disabled"]) return reject(action[@"disabled"][@"reason"] ?: @"This action is disabled.");
	if(action[@"command"]) return reject(@"Actions requiring server commands are not supported yet.");
	NSDictionary* edit = action[@"edit"];
	if(![edit isKindOfClass:NSDictionary.class]) return reject(@"This action has no directly applicable edit.");
	if(edit[@"changeAnnotations"]) return reject(@"Actions requiring annotated edits are not supported yet.");
	auto sameFile = [&](NSString* uri) { NSURL* url = [NSURL URLWithString:uri]; return url.isFileURL && [url.path.stringByStandardizingPath isEqualToString:path.stringByStandardizingPath]; };
	NSMutableArray* edits = [NSMutableArray new];
	if(edit[@"changes"] && edit[@"documentChanges"]) return reject(@"Ambiguous workspace edit.");
	for(NSString* uri in edit[@"changes"]) {
		if(!sameFile(uri)) return reject(@"This action changes another file; no edits were applied.");
		[edits addObjectsFromArray:edit[@"changes"][uri]];
	}
	for(NSDictionary* change in edit[@"documentChanges"]) {
		NSDictionary* document = change[@"textDocument"];
		if(change[@"kind"] || !document || !sameFile(document[@"uri"])) return reject(@"File operations and edits to other files are not supported yet.");
		id revision = document[@"version"];
		if(revision && revision != NSNull.null && [revision integerValue] != version) return reject(@"The action targets an older document version.");
		[edits addObjectsFromArray:change[@"edits"]];
	}
	if(!edits.count) return reject(@"This action contains no edits.");
	NSArray* lines = [content componentsSeparatedByString:@"\n"];
	auto offset = [&](NSDictionary* position) -> NSUInteger {
		id lineValue = position[@"line"], columnValue = position[@"character"];
		if(![lineValue isKindOfClass:NSNumber.class] || ![columnValue isKindOfClass:NSNumber.class]) return NSNotFound;
		NSInteger line = [lineValue integerValue], column = [columnValue integerValue];
		if(line < 0 || line >= (NSInteger)lines.count || column < 0) return NSNotFound;
		NSString* text = lines[line];
		NSUInteger length = text.length - ([text hasSuffix:@"\r"] ? 1 : 0);
		if((NSUInteger)column > length) return NSNotFound;
		if(column > 0 && (NSUInteger)column < text.length && CFStringIsSurrogateHighCharacter([text characterAtIndex:column-1]) && CFStringIsSurrogateLowCharacter([text characterAtIndex:column])) return NSNotFound;
		NSUInteger result = column;
		for(NSInteger i=0; i<line; ++i) result += [lines[i] length] + 1;
		return result;
	};
	NSMutableArray* replacements = [NSMutableArray new];
	for(NSDictionary* item in edits) {
		if(item[@"annotationId"] || ![item[@"newText"] isKindOfClass:NSString.class]) return reject(@"Unsupported text edit.");
		NSUInteger start = offset(item[@"range"][@"start"]), end = offset(item[@"range"][@"end"]);
		if(start == NSNotFound || end == NSNotFound || end < start) return reject(@"Invalid edit range; no edits were applied.");
		[replacements addObject:@{@"start":@(start), @"end":@(end), @"text":item[@"newText"]}];
	}
	[replacements sortUsingComparator:^NSComparisonResult(NSDictionary* a, NSDictionary* b) { return [b[@"start"] compare:a[@"start"]]; }];
	NSUInteger boundary = content.length + 1, previousStart = NSNotFound;
	NSMutableString* result = [content mutableCopy];
	for(NSDictionary* item in replacements) {
		NSUInteger start = [item[@"start"] unsignedIntegerValue], end = [item[@"end"] unsignedIntegerValue];
		if(end > boundary || start == previousStart) return reject(@"Overlapping edits; no edits were applied.");
		[result replaceCharactersInRange:NSMakeRange(start, end-start) withString:item[@"text"]];
		boundary = previousStart = start;
	}
	return result;
}
