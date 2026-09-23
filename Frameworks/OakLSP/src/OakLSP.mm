#import "OakLSP.h"
#import "OakLSPClient.h"
#include <lsp/types.h>
#include <lsp/version.h>
#include <lsp/protocol_version.h>
#include <lsp/json/parser.h>
#include <lsp/json/writer.h>
#include <stdexcept>
#include <unistd.h>

NSString* OakLSPBuildCheck ()
{
	// Project-root regression tests: nested sources, libraries, worktree markers,
	// spaces/Unicode, standalone files and isolation from enclosing projects.
	NSFileManager* files = NSFileManager.defaultManager;
	NSString* temporary = [NSTemporaryDirectory() stringByAppendingPathComponent:[@"TextMate-root-" stringByAppendingString:NSUUID.UUID.UUIDString]];
	NSString* project = [temporary stringByAppendingPathComponent:@"Aeon ação project"];
	BOOL created = YES;
	for(NSString* relative in @[@"libraries", @"examples/nested", @"inner/.git", @"standalone"])
		created &= [files createDirectoryAtPath:[project stringByAppendingPathComponent:relative] withIntermediateDirectories:YES attributes:nil error:nil];
	BOOL roots = created;
	for(NSString* relative in @[@"main.ae", @"examples/nested/test.ae", @"libraries/Agent.ae"])
		roots &= [OakLSPAeonProjectRoot([project stringByAppendingPathComponent:relative]) isEqual:project];
	NSString* inner = [project stringByAppendingPathComponent:@"inner"];
	roots &= [OakLSPAeonProjectRoot([inner stringByAppendingPathComponent:@"file.ae"]) isEqual:inner];
	[files removeItemAtPath:[inner stringByAppendingPathComponent:@".git"] error:nil];
	roots &= [@"gitdir: /unused" writeToFile:[inner stringByAppendingPathComponent:@".git"] atomically:YES encoding:NSUTF8StringEncoding error:nil];
	roots &= [OakLSPAeonProjectRoot([inner stringByAppendingPathComponent:@"file.ae"]) isEqual:inner];
	[files removeItemAtPath:[project stringByAppendingPathComponent:@"libraries"] error:nil];
	NSString* standalone = [project stringByAppendingPathComponent:@"standalone"];
	roots &= [OakLSPAeonProjectRoot([standalone stringByAppendingPathComponent:@"file.ae"]) isEqual:standalone];
	roots &= [@"[project]" writeToFile:[project stringByAppendingPathComponent:@"pyproject.toml"] atomically:YES encoding:NSUTF8StringEncoding error:nil];
	roots &= [OakLSPAeonProjectRoot([standalone stringByAppendingPathComponent:@"file.ae"]) isEqual:project];
	[files removeItemAtPath:temporary error:nil];
	if(!roots) throw std::runtime_error("Aeon project-root discovery failed");

	for(auto const& source : {R"({"title":"Synthesize","command":{"title":"Synthesize","command":"aeon.synthesize","arguments":[]}})", R"({"title":"Command","command":"example.run"})", R"({"title":"Edit","edit":{"changes":{}}})"}) {
		lsp::json::Parser parser(source);
		lsp::OneOf<lsp::Command, lsp::CodeAction> action;
		lsp::fromJson(parser.parse(), action);
		bool plain = std::string_view(source).find("example.run") != std::string_view::npos;
		if(std::holds_alternative<lsp::Command>(action) != plain) throw std::runtime_error("CodeAction/Command discrimination failed");
	}
	auto uri = lsp::Uri::fileUriFromPath("/tmp/TextMate LSP/ação.c");
	if(lsp::Uri::parse(uri.toString()).fsPath() != "/tmp/TextMate LSP/ação.c")
		throw std::runtime_error("LSP URI round trip failed");

	lsp::InitializeParams params;
	params.processId = getpid();
	params.rootUri = uri;
	std::string encoded;
	{
		lsp::json::Writer writer(encoded);
		auto object = writer.beginObject();
		lsp::writeJson(params, object);
	}

	lsp::InitializeParams decoded;
	lsp::json::Parser parser(encoded);
	lsp::fromJson(parser.parse(), decoded);
	if(decoded.rootUri.isNull() || decoded.rootUri.value() != uri ||
	   decoded.processId.isNull() || decoded.processId.value() != getpid())
		throw std::runtime_error("LSP initialize serialization round trip failed");

	std::string number;
	lsp::json::Writer(number).write(1.25);
	if(number != "1.25")
		throw std::runtime_error("LSP floating-point JSON serialization failed");

	return [NSString stringWithFormat:@"lsp-framework %s; LSP %s; Objective-C++/JSON/URI OK", LSP_VERSION_STR, LSP_PROTOCOL_VERSION_STR];
}
