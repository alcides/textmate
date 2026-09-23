// Opt-in UI smoke test. Never runs in ordinary editor sessions.
#import <DocumentWindow/DocumentWindowController.h>
#import <OakTextView/OakDocumentView.h>
#import <document/OakDocumentController.h>
#import <document/OakDocument.h>
#import "../../../Frameworks/OakTextView/src/OakLSPPanel.h"
#import "../../../Frameworks/OakTextView/src/OakChoiceMenu.h"
#import <OakLSP/OakLSPClient.h>
#import <WebKit/WebKit.h>
#include <bundles/bundles.h>
#include <parse/grammar.h>
#include <parse/parse.h>
#include <libproc.h>
#include <sys/proc_info.h>

@interface OakDocumentView (LSPPrototypeTesting)
@property (nonatomic) OakLSPPanel* lspPanel;
@property (nonatomic) OakLSPClient* lspClient;
- (void)startLSP;
@end

@interface OakLSPPanel (LSPListingTesting)
- (NSMenu*)codeActionMenuForActions:(NSArray*)actions error:(NSString*)error;
@end

// Supply the clicked row while exercising the real table target/action wiring.
@interface LSPDiagnosticClickTestTable : NSTableView
@property (nonatomic) NSInteger testClickedRow;
@end
@implementation LSPDiagnosticClickTestTable
- (NSInteger)clickedRow { return self.testClickedRow; }
@end

static BOOL TestDiagnosticRows(OakDocumentView* view) {
	OakLSPPanel* panel = view.lspPanel;
	NSArray* original = panel.diagnostics;
	NSMutableDictionary* diagnostic = [original.firstObject mutableCopy];
	NSString* message = @"First line\nsecond line\r\nthird line\rfourth\u2028fifth\u2029last";
	diagnostic[@"message"] = message;
	[panel showState:@"Ready" diagnostics:@[diagnostic] running:YES];
	NSTableView* table = [panel valueForKey:@"table"];
	BOOL passed = table.target == panel && table.action != nil;
	for(NSTableColumn* column in table.tableColumns) {
		NSView* cell = [panel tableView:table viewForTableColumn:column row:0];
		NSTextField* label = (NSTextField*)cell.subviews.firstObject;
		passed &= [label.toolTip isEqual:message] && [cell.toolTip isEqual:message];
		passed &= [label.stringValue rangeOfCharacterFromSet:NSCharacterSet.newlineCharacterSet].location == NSNotFound;
		if([column.identifier isEqual:@"message"]) passed &= label.alignment == NSTextAlignmentLeft && [label.stringValue containsString:@"last"];
	}
	passed &= [[panel tableView:table rowViewForRow:0].toolTip isEqual:message];
	fprintf(stderr,"LSP ROW TEST: presentation=%d\n",passed);
	[view.window makeFirstResponder:table];
	[table selectRowIndexes:[NSIndexSet indexSetWithIndex:0] byExtendingSelection:NO];
	passed &= view.window.firstResponder == table;
	NSString* destination = view.textView.selectionString;
	NSTextField* detail = [panel valueForKey:@"detail"];
	passed &= [detail.toolTip isEqual:message] && [detail.stringValue rangeOfCharacterFromSet:NSCharacterSet.newlineCharacterSet].location == NSNotFound;
	fprintf(stderr,"LSP ROW TEST: selection/footer=%d destination=%s\n",passed,destination.UTF8String);
	LSPDiagnosticClickTestTable* click = [LSPDiagnosticClickTestTable new];
	click.testClickedRow = 0;
	// Move away without changing the selected row, then click that same row again.
	view.textView.selectionString = @"1:1";
	[view.window makeFirstResponder:table];
	[NSApp sendAction:table.action to:table.target from:click];
	passed &= [view.textView.selectionString isEqual:destination] && view.window.firstResponder == view.textView;
	fprintf(stderr,"LSP ROW TEST: click=%d selection=%s focus=%s\n",passed,view.textView.selectionString.UTF8String,NSStringFromClass(view.window.firstResponder.class).UTF8String);
	click.testClickedRow = -1;
	view.textView.selectionString = @"1:1";
	NSString* unchanged = view.textView.selectionString;
	[NSApp sendAction:table.action to:table.target from:click];
	passed &= [view.textView.selectionString isEqual:unchanged];
	[panel showState:@"Ready" diagnostics:original running:YES];
	fprintf(stderr,"LSP ROW TEST: %s single-line rows/footer, full multiline tooltips, repeated-click navigation, editor focus, empty click\n", passed ? "PASS" : "FAIL");
	return passed;
}

static void CapturePrototype(NSWindow* window, NSString* name) {
	[window.contentView layoutSubtreeIfNeeded];
	[window displayIfNeeded];
	NSView* view = window.contentView;
	// Print-rendered artifacts are not a substitute for screen-capture validation.
	NSData* pdf = [view dataWithPDFInsideRect:view.bounds];
	NSImage* rendered = [[NSImage alloc] initWithData:pdf];
	NSBitmapImageRep* bitmap = [[NSBitmapImageRep alloc] initWithData:rendered.TIFFRepresentation];
	NSString* directory = [NSUserDefaults.standardUserDefaults stringForKey:@"LSPPrototypeArtifacts"];
	[[bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}] writeToFile:[directory stringByAppendingPathComponent:name] atomically:YES];
	// Also retain the ordinary AppKit drawing path to catch differences hidden
	// by print rendering. This is still not a full-screen WindowServer capture.
	NSBitmapImageRep* raster = [view bitmapImageRepForCachingDisplayInRect:view.bounds];
	[view cacheDisplayInRect:view.bounds toBitmapImageRep:raster];
	[[raster representationUsingType:NSBitmapImageFileTypePNG properties:@{}] writeToFile:[directory stringByAppendingPathComponent:[@"cached-" stringByAppendingString:name]] atomically:YES];
}


static void RunAeonSnippetTest(NSString* path) {
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	NSArray* triggers = @[@"def", @"val", @"inductive", @"indp", @"match", @"let", @"if", @"fun", @"ref", @"open", @"import"];
	NSArray* expected = @[@"def name (x : Int) : Int :=\tx;\n", @"def name : Int := 0;\n", @"inductive Nat\n| zero : Nat\n| succ (n : Nat) : Nat\n", @"inductive Maybe a\n| none : (Maybe a)\n| some (value : a) : (Maybe a)\n", @"match value with\n| none => 0\n| some x => x", @"let x := 0 in\nx", @"if true then\n\t0\nelse\n\t1", @"fun x => x", @"{v : Int | v >= 0}", @"open Math\n", @"import Math;\n"];
	NSMutableDictionary* expanded = [NSMutableDictionary dictionary];
	__block NSString* original;
	__block NSUInteger index = 0, ticks = 0;
	__block BOOL waiting = NO;
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		OakDocumentView* view = [[DocumentWindowController controllerForDocument:doc] valueForKey:@"documentView"];
		if(++ticks > 160) { fprintf(stderr,"AEON SNIPPETS: FAIL timeout\n"); [timer invalidate]; return; }
		if(!view) return;
		if(!original) original = doc.content;
		if(!waiting) {
			[view.textView selectAll:nil]; [view.textView insertText:triggers[index]];
			auto items = bundles::query(bundles::kFieldTabTrigger, [triggers[index] UTF8String], [view.textView scopeContext]);
			if(items.size() != 1) { fprintf(stderr,"AEON SNIPPETS: FAIL trigger lookup %s\n",[triggers[index] UTF8String]); [timer invalidate]; return; }
			[view.textView insertTab:nil]; waiting = YES;
			return;
		}
		auto tokens = [](NSString* text) {
			return [[text componentsSeparatedByCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet] filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"length > 0"]];
		};
		if(![tokens(doc.content) isEqual:tokens(expected[index])]) {
			fprintf(stderr,"AEON SNIPPETS: FAIL expansion %s: %s\n",[triggers[index] UTF8String],doc.content.UTF8String); [timer invalidate]; return;
		}
		expanded[triggers[index]] = doc.content;
		if([triggers[index] isEqual:@"inductive"]) {
			[view.textView insertText:@"Natural"];
			if([doc.content containsString:@"Nat\n"] || ![doc.content containsString:@"inductive Natural"] || ![doc.content containsString:@": Natural"]) {
				fprintf(stderr,"AEON SNIPPETS: FAIL linked type placeholders\n"); [timer invalidate]; return;
			}
		}
		// Leave snippet mode before testing the next trigger.
		for(NSUInteger tab = 0; tab < 12; ++tab) [view.textView insertTab:nil];
		waiting = NO;
		if(++index < triggers.count) return;
		NSString* directory = [NSUserDefaults.standardUserDefaults stringForKey:@"LSPPrototypeArtifacts"];
		NSData* json = [NSJSONSerialization dataWithJSONObject:expanded options:NSJSONWritingPrettyPrinted error:nil];
		BOOL written = [json writeToFile:[directory stringByAppendingPathComponent:@"aeon-snippets.json"] atomically:YES];
		[view.textView selectAll:nil]; [view.textView insertText:original]; [doc markDocumentSaved];
		fprintf(stderr,"AEON SNIPPETS: %s 11 native Tab expansions and linked placeholders; fixture restored\n",written ? "PASS" : "FAIL artifact write");
		[timer invalidate];
	}];
}


static void RunAeonCommentTest(NSString* path) {
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSUInteger stage = 0, ticks = 0;
	__block NSString* original;
	NSString* source = @"    def greeting : String := \"Olá 🌍\";\n    def answer : Int := 42;\n";
	NSString* commented = @"    # def greeting : String := \"Olá 🌍\";\n    # def answer : Int := 42;\n";
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		OakDocumentView* view = [[DocumentWindowController controllerForDocument:doc] valueForKey:@"documentView"];
		if(++ticks > 120) { fprintf(stderr,"AEON COMMENT: FAIL timeout stage %lu\n",stage); [timer invalidate]; return; }
		if(!view) return;
		auto toggle = [&]() {
			auto actions = bundles::query(bundles::kFieldKeyEquivalent, "@/", [view.textView scopeContext]);
			if(actions.size() != 1 || actions.front()->uuid() != oak::uuid_t("73EAE95D-A09C-4FC2-B4E3-42505678B57E")) {
				fprintf(stderr,"AEON COMMENT: FAIL native Cmd-/ lookup\n"); [timer invalidate]; return;
			}
			[view.textView performBundleItem:actions.front()];
		};
		if(stage == 0) {
			original = doc.content;
			[view.textView selectAll:nil]; [view.textView insertText:source];
			[view.textView selectAll:nil]; toggle(); stage = 1;
		} else if(stage == 1 && [doc.content isEqual:commented]) {
			[view.textView selectAll:nil]; toggle(); stage = 2;
		} else if(stage == 2 && [doc.content isEqual:source]) {
			view.textView.selectionString = @"2:8"; toggle(); stage = 3;
		} else if(stage == 3 && [doc.content isEqual:@"    def greeting : String := \"Olá 🌍\";\n    # def answer : Int := 42;\n"]) {
			view.textView.selectionString = @"2:10"; toggle(); stage = 4;
		} else if(stage == 4 && [doc.content isEqual:source]) {
			[view.textView selectAll:nil]; [view.textView insertText:original]; [doc markDocumentSaved];
			fprintf(stderr,"AEON COMMENT: PASS native Cmd-/ command, selected lines and current line, comment/uncomment, indentation and Unicode; fixture restored\n");
			[timer invalidate];
		}
	}];
}

static void RunAeonFormatBundleTest(NSString* path) {
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSUInteger ticks = 0;
	__block BOOL invoked = NO;
	__block NSString* original;
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
		OakDocumentView* view = [controller valueForKey:@"documentView"];
		auto fail = [&](NSString* reason) { fprintf(stderr,"AEON FORMAT: FAIL %s\n",reason.UTF8String); [timer invalidate]; };
		if(++ticks > 240) { fail(@"timeout"); return; }
		if(!view) return;
		if(!invoked) {
			auto actions = bundles::query(bundles::kFieldKeyEquivalent, "~F", [view.textView scopeContext]);
			if(actions.size() != 1 || actions.front()->uuid() != oak::uuid_t("B19FB1FA-4893-48CB-9A10-3D0881FE0463")) { fail(@"bundle shortcut lookup"); return; }
			if([[NSApp.mainMenu itemWithTitle:@"Text"].submenu itemWithTitle:@"Format Document"]) { fail(@"global menu still present"); return; }
			// Exercise unsaved content, not the original disk file.
			[view.textView selectAll:nil]; [view.textView insertText:@"def main(args:Int):Unit := print \"Olá 🌍\"\n"];
			original = doc.content;
			[view.window makeFirstResponder:view.textView];
			// Dispatch the shortcut's resolved bundle item without requiring global focus.
			[view.textView performBundleItem:actions.front()];
			invoked = YES;
			fprintf(stderr,"AEON FORMAT: bundle dispatched\n");
		} else if(![doc.content isEqual:original]) {
			if(![doc.content containsString:@"Olá 🌍"] || ![doc.content containsString:@"args : Int"]) { fail(@"formatted buffer or Unicode"); return; }
			[view.lspPanel showState:@"Failed · Example multiline error\nDetails stay left-aligned." diagnostics:@[] running:NO];
			view.lspPanel.expanded = YES;
			NSTextField* message = [view.lspPanel valueForKey:@"empty"];
			if(message.alignment != NSTextAlignmentLeft) { fail(@"message alignment"); return; }
			CapturePrototype(controller.window,@"aeon-format-bundle.png");
			[view.textView tryToPerform:@selector(undo:) with:nil];
			if(![doc.content isEqual:original]) { fail(@"single undo"); return; }
			fprintf(stderr,"AEON FORMAT: PASS shortcut lookup, native bundle dispatch, unsaved buffer, Unicode, single Undo, left-aligned errors; no global Format menu\n");
			[timer invalidate];
		}
	}];
}

static void RunAeonBundleTest(NSString* path) {
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSUInteger ticks = 0;
	__block BOOL invoked = NO;
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
		OakDocumentView* view = [controller valueForKey:@"documentView"];
		if(++ticks > 240) { fprintf(stderr,"AEON BUNDLE: FAIL timeout\n"); [timer invalidate]; return; }
		if(!view) return;
		if(!invoked) {
			if(![doc.fileType isEqual:@"source.aeon"]) { fprintf(stderr,"AEON BUNDLE: FAIL file scope %s; grammar indexed=%d command indexed=%d\n",doc.fileType.UTF8String, !!bundles::lookup(oak::uuid_t("DE924C99-967E-4820-B5AD-F2C648C1C572")), !!bundles::lookup(oak::uuid_t("899C211A-D997-4D87-B6CC-EF3DA2707C19"))); [timer invalidate]; return; }
			auto actions = bundles::query(bundles::kFieldKeyEquivalent, "@r", [view.textView scopeContext]);
			if(actions.size() != 1 || actions.front()->uuid() != oak::uuid_t("899C211A-D997-4D87-B6CC-EF3DA2707C19")) { fprintf(stderr,"AEON BUNDLE: FAIL Cmd-R lookup\n"); [timer invalidate]; return; }
			[view.window makeFirstResponder:view.textView];
			NSEvent* key = [NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:NSEventModifierFlagCommand timestamp:0 windowNumber:view.window.windowNumber context:nil characters:@"r" charactersIgnoringModifiers:@"r" isARepeat:NO keyCode:15];
			invoked = [view.textView performKeyEquivalent:key];
			fprintf(stderr,"AEON BUNDLE: Cmd-R dispatched=%d scope=%s\n",invoked,doc.fileType.UTF8String);
		} else {
			id output = [controller valueForKey:@"htmlOutputView"];
			id outputController = [controller valueForKey:@"htmlOutputWindowController"];
			if(!output) output = [outputController valueForKey:@"htmlOutputView"];
			WebView* web = [output valueForKey:@"webView"];
			NSString* body = [web stringByEvaluatingJavaScriptFromString:@"document.body ? document.body.innerText : ''"];
			if([body containsString:@"Hello from Aeon in TextMate!"] && [body containsString:@"Program exited with code #0"]) {
				fprintf(stderr,"AEON BUNDLE: PASS native Cmd-R, source.aeon scope, real Aeon, shared HTML output\n%s\n",body.UTF8String);
				CapturePrototype(controller.window,@"aeon-bundle-run.png"); [timer invalidate];
				if(outputController) CapturePrototype([outputController window],@"aeon-bundle-output.png");
			} else if(ticks % 40 == 0) fprintf(stderr,"AEON BUNDLE: output %s\n",body.UTF8String);
		}
	}];
}

static void RunCodeActionsTest(NSString* path) {
	NSString* uri = [NSURL fileURLWithPath:path].absoluteString;
	auto textEdit = [](NSInteger start, NSInteger end, NSString* text) { return @{@"range":@{@"start":@{@"line":@0,@"character":@(start)},@"end":@{@"line":@0,@"character":@(end)}},@"newText":text}; };
	auto action = [&](NSArray* edits) { return @{@"edit":@{@"changes":@{uri:edits}}}; };
	NSString* error = nil;
	BOOL checks = [OakLSPApplyCodeAction(action(@[textEdit(3,4,@"B"),textEdit(0,1,@"A")]), @"a🌍b", path, 1, &error) isEqualToString:@"A🌍B"];
	checks &= OakLSPApplyCodeAction(action(@[textEdit(2,3,@"x")]), @"a🌍b", path, 1, &error) == nil;
	checks &= OakLSPApplyCodeAction(action(@[textEdit(0,2,@"x"),textEdit(1,3,@"y")]), @"abc", path, 1, &error) == nil;
	checks &= OakLSPApplyCodeAction(action(@[textEdit(0,9,@"x")]), @"abc", path, 1, &error) == nil;
	checks &= OakLSPApplyCodeAction(@{@"command":@"not-supported",@"edit":action(@[textEdit(0,1,@"x")])[@"edit"]}, @"abc", path, 1, &error) == nil;
	checks &= OakLSPApplyCodeAction(@{@"edit":@{@"changes":@{@"file:///tmp/other.cpp":@[textEdit(0,1,@"x")],uri:@[textEdit(0,1,@"y")]}}}, @"abc", path, 1, &error) == nil;
	NSDictionary* versioned = @{@"edit":@{@"documentChanges":@[@{@"textDocument":@{@"uri":uri,@"version":@1},@"edits":@[textEdit(0,1,@"x")]}]}};
	checks &= [OakLSPApplyCodeAction(versioned, @"abc", path, 1, &error) isEqualToString:@"xbc"];
	checks &= OakLSPApplyCodeAction(versioned, @"abc", path, 2, &error) == nil;
	if(!checks) { fprintf(stderr, "CODE ACTION TEST: FAIL edit validation\n"); return; }
	fprintf(stderr, "CODE ACTION TEST: edit validation PASS (Unicode, multiple edits, overlap, bounds, commands, other files, versions)\n");
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSInteger stage = 0;
	__block NSUInteger ticks = 0;
	__block NSString* original = nil;
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		if(++ticks > 200) { fprintf(stderr,"CODE ACTION TEST: FAIL timeout stage %ld\n",stage); [timer invalidate]; return; }
		DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
		OakDocumentView* view = [controller valueForKey:@"documentView"];
		if(!view.lspPanel) return;
		if(stage == 0) { original = doc.content; [view startLSP]; stage = 1; }
		else if(stage == 1 && view.lspPanel.diagnostics.count) {
			stage = 2;
			[view.lspPanel selectDiagnosticAtLine:[view.lspPanel.diagnostics.firstObject[@"line"] unsignedIntegerValue]];
			NSButton* button = [view.lspPanel valueForKey:@"actions"];
			if(!button.enabled) { fprintf(stderr,"CODE ACTION TEST: FAIL Quick Fix button disabled\n"); [timer invalidate]; return; }
			CapturePrototype(controller.window, @"code-action-available.png");
			view.lspPanel.requestActions(view.lspPanel.diagnostics.firstObject, ^(NSArray* actions, NSString* failure) {
				NSDictionary* selected = nil;
				for(NSDictionary* candidate in actions) if(candidate[@"edit"] && !candidate[@"command"] && !candidate[@"disabled"]) { selected = candidate; break; }
				if(!selected) { fprintf(stderr,"CODE ACTION TEST: FAIL no applicable action: %s\n", (failure ?: actions.description).UTF8String); [timer invalidate]; return; }
				fprintf(stderr,"CODE ACTION TEST: clangd action: %s\n",[selected[@"title"] UTF8String]);
				view.lspPanel.applyAction(selected);
				if(![doc.content containsString:@"return 0;"]) { fprintf(stderr,"CODE ACTION TEST: FAIL edit not applied\n"); [timer invalidate]; return; }
				stage = 3;
			});
		} else if(stage == 3 && !view.lspPanel.diagnostics.count) {
			// Wait for Ready rather than the immediate Checking state, which also clears diagnostics.
			NSTextField* status = [view.lspPanel valueForKey:@"status"];
			if(![status.stringValue hasPrefix:@"0 errors"]) return;
			CapturePrototype(controller.window, @"code-action-applied.png");
			[view.textView tryToPerform:@selector(undo:) with:nil];
			if(![doc.content isEqualToString:original]) { fprintf(stderr,"CODE ACTION TEST: FAIL Undo\n"); [timer invalidate]; return; }
			stage = 4;
		} else if(stage == 4 && view.lspPanel.diagnostics.count) {
			stage = 5;
			[view.lspClient codeActionsForDiagnostic:view.lspPanel.diagnostics.firstObject completion:^(NSArray* actions, NSString* failure) {
				if(actions.count || !failure) { fprintf(stderr,"CODE ACTION TEST: FAIL stale result accepted\n"); [timer invalidate]; return; }
				[view.textView tryToPerform:@selector(undo:) with:nil];
				if(![doc.content isEqual:original]) { fprintf(stderr,"CODE ACTION TEST: FAIL stale-test restoration\n"); [timer invalidate]; return; }
				fprintf(stderr,"CODE ACTION TEST: PASS real clangd fix, diagnostic cleared, single Undo, stale result rejected\n");
				[doc markDocumentSaved];
				CapturePrototype(controller.window, @"code-action-final.png");
				[timer invalidate];
			}];
			[view.textView selectAll:nil]; [view.textView insertText:[original stringByAppendingString:@"\n// Intervening edit invalidates the request.\n"]];
		}
	}];
}

static void RunAeonSynthesisTest(NSString* path) {
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSInteger stage = 0;
	__block NSUInteger ticks = 0, cancelledAt = 0;
	__block NSString* original;
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		if(++ticks > 480) { fprintf(stderr,"AEON TEST: FAIL timeout stage %ld\n",stage); [timer invalidate]; return; }
		DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
		OakDocumentView* view = [controller valueForKey:@"documentView"];
		if(!view.lspPanel) return;
		NSDictionary* hole = nil;
		if(stage == 2 && ticks % 20 == 0) fprintf(stderr,"AEON TEST: waiting: %s\n", [[view.lspPanel valueForKey:@"status"] stringValue].UTF8String);
		for(NSDictionary* d in view.lspPanel.diagnostics) if([d[@"message"] isEqual:@"Synthesize ?hole"] && [d[@"line"] integerValue] == 4) hole = d;
		if(stage == 0) { original = doc.content; [view startLSP]; stage = 1; }
		else if((stage == 1 || stage == 4) && hole) {
			BOOL cancel = stage == 4; stage = cancel ? 5 : 2;
			[view.lspPanel selectDiagnosticAtLine:4];
			CapturePrototype(controller.window, @"aeon-before.png");
			view.lspPanel.requestActions(hole, ^(NSArray* actions, NSString* error) {
				NSMenu* menu = [view.lspPanel codeActionMenuForActions:actions error:error];
				BOOL listingOK = actions.count > 3 && menu.numberOfItems == actions.count;
				for(NSUInteger i = 0; i < actions.count && listingOK; ++i) {
					NSMenuItem* item = [menu itemAtIndex:i];
					listingOK &= [item.title isEqual:actions[i][@"title"]] && [item.representedObject[@"action"] isEqual:actions[i]] && item.enabled == !actions[i][@"disabled"];
				}
				NSArray* generic = @[@{@"title":@"Other server command", @"command":@"other.run"}, @{@"title":@"Unavailable action", @"disabled":@{@"reason":@"Missing dependency"}}];
				NSMenu* genericMenu = [view.lspPanel codeActionMenuForActions:generic error:nil];
				listingOK &= genericMenu.numberOfItems == 2 && [genericMenu itemAtIndex:0].enabled && ![genericMenu itemAtIndex:1].enabled && [[genericMenu itemAtIndex:1].toolTip isEqual:@"Missing dependency"];
				if(!listingOK) { fprintf(stderr,"AEON TEST: FAIL unfiltered listing\n"); [timer invalidate]; return; }
				fprintf(stderr,"AEON TEST: listing PASS %lu server actions, same order/titles/payloads; generic disabled action preserved\n", actions.count);
				NSDictionary* selected;
				for(NSDictionary* action in actions) if([action[@"command"] isKindOfClass:NSDictionary.class] && [[action[@"command"][@"arguments"] lastObject] isEqual:@"smt"]) { selected = action; break; }
				if(!selected) { fprintf(stderr,"AEON TEST: FAIL no SMT action: %s\n", (error ?: actions.description).UTF8String); [timer invalidate]; return; }
				fprintf(stderr,"AEON TEST: action %s\n",[selected[@"title"] UTF8String]);
				if(cancel) {
					void (^previousNotice)(NSString*) = view.lspClient.notice;
					__weak OakDocumentView* weakView = view;
					view.lspClient.notice = ^(NSString* message) {
						if(previousNotice) previousNotice(message);
						OakDocumentView* current = weakView;
						if(current && [message hasPrefix:@"Synthesizing ?hole with"]) {
							current.lspClient.notice = previousNotice;
							[current.textView selectAll:nil]; [current.textView insertText:[original stringByAppendingString:@"\n# User edit cancels synthesis.\n"]];
							fprintf(stderr,"AEON TEST: edited after server confirmed synthesis started\n");
							cancelledAt = ticks; stage = 6;
						}
					};
				}
				view.lspPanel.applyAction(selected);
				// Only the explicitly selected local SMT action is approved by this opt-in test.
				if(!controller.window.attachedSheet) { fprintf(stderr,"AEON TEST: FAIL missing synthesis consent\n"); [timer invalidate]; return; }
				[NSApp endSheet:controller.window.attachedSheet returnCode:NSAlertFirstButtonReturn];
			});
		} else if(stage == 2 && ![doc.content containsString:@":= ?hole"] && view.lspPanel.diagnostics.count == 0) {
			NSTextField* status = [view.lspPanel valueForKey:@"status"];
			if(![status.stringValue hasPrefix:@"0 errors"]) return;
			fprintf(stderr,"AEON TEST: synthesized buffer:\n%s\n",doc.content.UTF8String);
			CapturePrototype(controller.window, @"aeon-synthesized.png");
			[view.textView tryToPerform:@selector(undo:) with:nil];
			if(![doc.content isEqual:original]) { fprintf(stderr,"AEON TEST: FAIL Undo\n"); [timer invalidate]; return; }
			stage = 4;
		} else if(stage == 6 && ticks > cancelledAt + 28 && hole) {
			if(![doc.content isEqual:[original stringByAppendingString:@"\n# User edit cancels synthesis.\n"]]) { fprintf(stderr,"AEON TEST: FAIL cancelled edit applied\n"); [timer invalidate]; return; }
			[view.textView selectAll:nil]; [view.textView insertText:original]; [doc markDocumentSaved]; stage = 7;
		} else if(stage == 7 && hole) {
			[view.lspPanel selectDiagnosticAtLine:4];
			CapturePrototype(controller.window, @"aeon-final.png");
			fprintf(stderr,"AEON TEST: PASS real synthesis, no errors, single Undo, editing cancellation; fixture restored\n");
			[timer invalidate];
		}
	}];
}

static void CompletionKey(OakTextView* view, NSString* characters, unsigned short code) {
	NSEventModifierFlags flags = code == 125 || code == 126 ? NSEventModifierFlagFunction | NSEventModifierFlagNumericPad : 0;
	[view keyDown:[NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:flags timestamp:0 windowNumber:view.window.windowNumber context:nil characters:characters charactersIgnoringModifiers:characters isARepeat:NO keyCode:code]];
}

static void CaptureCompletionPopup(NSWindow* parent, OakChoiceMenu* menu) {
	CapturePrototype(parent, @"completion-editor.png");
	CapturePrototype(menu.window, @"completion-list.png");
	NSView* view = parent.contentView;
	NSBitmapImageRep* base = [view bitmapImageRepForCachingDisplayInRect:view.bounds];
	[view cacheDisplayInRect:view.bounds toBitmapImageRep:base];
	NSView* popup = menu.window.contentView;
	NSBitmapImageRep* overlay = [popup bitmapImageRepForCachingDisplayInRect:popup.bounds];
	[popup cacheDisplayInRect:popup.bounds toBitmapImageRep:overlay];
	NSRect screen = [parent convertRectToScreen:[view convertRect:view.bounds toView:nil]];
	NSRect placement = NSOffsetRect(menu.window.frame, -screen.origin.x, -screen.origin.y);
	NSImage* combined = [[NSImage alloc] initWithSize:view.bounds.size];
	[combined lockFocus];
	[base drawInRect:NSMakeRect(0,0,NSWidth(view.bounds),NSHeight(view.bounds))];
	[overlay drawInRect:placement];
	[combined unlockFocus];
	NSBitmapImageRep* rendered = [NSBitmapImageRep imageRepWithData:combined.TIFFRepresentation];
	NSString* directory = [NSUserDefaults.standardUserDefaults stringForKey:@"LSPPrototypeArtifacts"];
	[[rendered representationUsingType:NSBitmapImageFileTypePNG properties:@{}] writeToFile:[directory stringByAppendingPathComponent:@"completion-popup-composite.png"] atomically:YES];
}

static void RunCompletionTest(NSString* path) {
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSInteger stage = 0;
	__block NSUInteger ticks = 0, requests = 0;
	__block NSString* original;
	__block NSArray* received;
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		auto fail = [&](NSString* reason) { fprintf(stderr,"COMPLETION TEST: FAIL %s\n",reason.UTF8String); [timer invalidate]; };
		if(++ticks > 240) { fail([NSString stringWithFormat:@"timeout stage %ld",stage]); return; }
		DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
		OakDocumentView* view = [controller valueForKey:@"documentView"];
		if(!view.lspPanel) return;
		if(stage == 0) { original = doc.content; [view startLSP]; stage = 1; }
		else if(stage == 1 && view.lspPanel.diagnostics.count) {
			NSString* line = [doc.content componentsSeparatedByString:@"\n"][1];
			NSUInteger column = [line rangeOfString:@"value.al"].location + @"value.al".length;
			view.textView.selectionString = [NSString stringWithFormat:@"2:%lu",[[line substringToIndex:column] lengthOfBytesUsingEncoding:NSUTF8StringEncoding]+1];
			[view.window makeFirstResponder:view.textView];
			auto provider = view.textView.completionProvider;
			view.textView.completionProvider = ^(NSUInteger requestedLine, NSUInteger character, NSString* prefix, void (^reply)(NSArray<NSString*>*)) {
				++requests;
				if(requestedLine != 1 || character != column || ![prefix isEqual:@"al"]) { fprintf(stderr,"COMPLETION TEST: FAIL UTF-16 position/prefix\n"); [timer invalidate]; return; }
				provider(requestedLine, character, prefix, ^(NSArray<NSString*>* values) {
					received = values;
					fprintf(stderr,"COMPLETION TEST: clangd suffixes %s\n",values.description.UTF8String);
					reply(values);
				});
			};
			[view.textView tryToPerform:@selector(complete:) with:nil]; stage = 2;
		} else if(stage == 2 && [[view.textView valueForKey:@"completionMenu"] isVisible]) {
			OakChoiceMenu* menu = [view.textView valueForKey:@"completionMenu"];
			if(![received containsObject:@"pha"] || ![received containsObject:@"pine"]) { fail(@"real member suggestions missing"); return; }
			if(![doc.content isEqual:original] || ![menu.choices isEqual:@[@"alpha",@"alpine"]]) { fail(@"popup opening changed text or labels"); return; }
			NSUInteger count = requests;
			CompletionKey(view.textView, [NSString stringWithFormat:@"%C",NSDownArrowFunctionKey], 125);
			if(menu.choiceIndex != 1 || ![doc.content isEqual:original] || requests != count) { fail(@"Down changed the document or did not select"); return; }
			CompletionKey(view.textView, [NSString stringWithFormat:@"%C",NSUpArrowFunctionKey], 126);
			if(menu.choiceIndex != 0 || ![doc.content isEqual:original]) { fail(@"Up failed"); return; }
			CaptureCompletionPopup(controller.window, menu);
			CompletionKey(view.textView, @"\t", 48);
			if(![doc.content isEqual:[original stringByReplacingOccurrencesOfString:@"value.al;" withString:@"value.alpha;"]] || [view.textView valueForKey:@"completionMenu"]) { fail(@"Tab acceptance failed"); return; }
			[view.textView tryToPerform:@selector(undo:) with:nil];
			if(![doc.content isEqual:original]) { fail(@"single Undo did not restore buffer"); return; }
			[view.textView tryToPerform:@selector(complete:) with:nil]; stage = 3;
		} else if(stage == 3 && [[view.textView valueForKey:@"completionMenu"] isVisible]) {
			CompletionKey(view.textView, @"\033", 53);
			if(![doc.content isEqual:original] || [view.textView valueForKey:@"completionMenu"]) { fail(@"Escape did not cancel without changes"); return; }
			[view.textView tryToPerform:@selector(complete:) with:nil]; stage = 4;
		} else if(stage == 4 && [[view.textView valueForKey:@"completionMenu"] isVisible]) {
			OakChoiceMenu* menu = [view.textView valueForKey:@"completionMenu"];
			NSTableView* table = [menu valueForKey:@"tableView"];
			NSRect row = [table rectOfRow:1];
			NSPoint point = [table convertPoint:NSMakePoint(NSMidX(row),NSMidY(row)) toView:nil];
			NSEvent* up = [NSEvent mouseEventWithType:NSEventTypeLeftMouseUp location:point modifierFlags:0 timestamp:0.1 windowNumber:menu.window.windowNumber context:nil eventNumber:2 clickCount:1 pressure:0];
			[NSApp postEvent:up atStart:YES];
			[NSApp sendEvent:[NSEvent mouseEventWithType:NSEventTypeLeftMouseDown location:point modifierFlags:0 timestamp:0 windowNumber:menu.window.windowNumber context:nil eventNumber:1 clickCount:1 pressure:1]];
			if(![doc.content isEqual:[original stringByReplacingOccurrencesOfString:@"value.al;" withString:@"value.alpine;"]]) { fail(@"mouse acceptance failed"); return; }
			[view.textView tryToPerform:@selector(undo:) with:nil];
			if(![doc.content isEqual:original]) { fail(@"mouse acceptance Undo failed"); return; }
			[view.textView tryToPerform:@selector(complete:) with:nil]; stage = 5;
		} else if(stage == 5 && [[view.textView valueForKey:@"completionMenu"] isVisible]) {
			CompletionKey(view.textView, @"\r", 36);
			if(![doc.content isEqual:[original stringByReplacingOccurrencesOfString:@"value.al;" withString:@"value.alpha;"]]) { fail(@"Return acceptance failed"); return; }
			// Exercise a delayed provider deterministically to check caret and content guards.
			[view.textView selectAll:nil]; [view.textView insertText:original];
			NSString* line = [original componentsSeparatedByString:@"\n"][1];
			NSUInteger column = [line rangeOfString:@"value.al"].location + @"value.al".length;
			NSString* caret = [NSString stringWithFormat:@"2:%lu",[[line substringToIndex:column] lengthOfBytesUsingEncoding:NSUTF8StringEncoding]+1];
			view.textView.selectionString = caret;
			__block void (^pending)(NSArray*);
			view.textView.completionProvider = ^(NSUInteger l, NSUInteger c, NSString* p, void (^reply)(NSArray<NSString*>*)) { pending = reply; };
			[view.textView tryToPerform:@selector(complete:) with:nil];
			if(!pending) { fail(@"delayed request was not invoked"); return; }
			view.textView.selectionString = @"1:1"; pending(@[@"WRONG"]);
			if(![doc.content isEqual:original] || [view.textView valueForKey:@"completionMenu"]) { fail(@"caret-stale completion applied or reopened popup"); return; }
			view.textView.selectionString = caret;
			[view.textView tryToPerform:@selector(complete:) with:nil];
			[view.textView insertText:@"x"]; NSString* changed = doc.content;
			pending(@[@"WRONG"]);
			pending = nil;
			if(![doc.content isEqual:changed] || [view.textView valueForKey:@"completionMenu"]) { fail(@"text-stale completion applied or reopened popup"); return; }
			view.textView.completionProvider = nil;
			[view.textView selectAll:nil]; [view.textView insertText:@"fallbackCandidate fal"];
			[view.textView tryToPerform:@selector(complete:) with:nil];
			if(![doc.content isEqual:@"fallbackCandidate fallbackCandidate"]) { fail(@"native fallback changed"); return; }
			[view.textView selectAll:nil]; [view.textView insertText:original]; [doc markDocumentSaved];
			view.textView.selectionString = caret;
			view.textView.completionProvider = ^(NSUInteger l, NSUInteger c, NSString* p, void (^reply)(NSArray<NSString*>*)) { reply(@[@"pha",@"pine"]); };
			[view.textView tryToPerform:@selector(complete:) with:nil];
			CompletionKey(view.textView, @"x", 7);
			if([view.textView valueForKey:@"completionMenu"] || ![doc.content containsString:@"value.alx;"]) { fail(@"typing did not dismiss popup safely"); return; }
			[view.textView selectAll:nil]; [view.textView insertText:original]; view.textView.selectionString = caret;
			[view.textView tryToPerform:@selector(complete:) with:nil];
			[view.window makeFirstResponder:nil];
			if([view.textView valueForKey:@"completionMenu"]) { fail(@"focus loss did not dismiss popup"); return; }
			[view.window makeFirstResponder:view.textView];
			[doc markDocumentSaved];
			[view startLSP]; view.textView.selectionString = caret;
			stage = 6;
		} else if(stage == 6 && view.lspPanel.diagnostics.count) {
			[view.textView tryToPerform:@selector(complete:) with:nil]; stage = 7;
		} else if(stage == 7 && [[view.textView valueForKey:@"completionMenu"] isVisible]) {
			CaptureCompletionPopup(controller.window, [view.textView valueForKey:@"completionMenu"]);
			fprintf(stderr,"COMPLETION TEST: PASS real clangd popup, UTF-16, arrows, Tab/Return, mouse, Escape, Undo, stale guards, native fallback; popup left open\n");
			[timer invalidate];
		}
	}];
}

static void RunHoverTest(NSString* path) {
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSInteger stage = 0;
	__block NSUInteger ticks = 0;
	__block void (^pending)(NSString*);
	__block NSString* original;
	__block NSPoint point;
	__block void (^realProvider)(NSUInteger, NSUInteger, void (^)(NSString*));
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		auto fail = [&](NSString* message) { fprintf(stderr,"HOVER TEST: FAIL %s\n",message.UTF8String); [timer invalidate]; };
		if(++ticks > 200) { fail([NSString stringWithFormat:@"timeout stage %ld",stage]); return; }
		DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
		OakDocumentView* view = [controller valueForKey:@"documentView"];
		if(!view.lspPanel) return;
		void (^move)(void) = ^{
			NSEvent* event = [NSEvent mouseEventWithType:NSEventTypeMouseMoved location:point modifierFlags:0 timestamp:NSProcessInfo.processInfo.systemUptime windowNumber:controller.window.windowNumber context:nil eventNumber:0 clickCount:0 pressure:0];
			[view.textView mouseMoved:event];
		};
		if(stage == 0) { original = doc.content; [view startLSP]; stage = 1; }
		else if(stage == 1 && view.lspPanel.diagnostics.count) {
			NSUInteger location = [doc.content rangeOfString:@"value.al"].location;
			NSRect rect = [(id<NSTextInputClient>)view.textView firstRectForCharacterRange:NSMakeRange(location,0) actualRange:NULL];
			rect = [controller.window convertRectFromScreen:rect]; point = NSMakePoint(NSMinX(rect)+1,NSMidY(rect));
			realProvider = view.textView.hoverProvider;
			view.textView.hoverProvider = ^(NSUInteger line, NSUInteger column, void (^reply)(NSString*)) {
				NSString* sourceLine = [doc.content componentsSeparatedByString:@"\n"][1];
				if(line != 1 || column != [sourceLine rangeOfString:@"value.al"].location) { fail(@"UTF-16 position"); return; }
				realProvider(line,column,reply);
			};
			move(); stage = 2;
		} else if(stage == 2 && [[view.textView valueForKey:@"hoverPanel"] isVisible]) {
			NSPanel* panel = [view.textView valueForKey:@"hoverPanel"];
			NSString* text = [(NSTextField*)panel.contentView.subviews.firstObject stringValue];
			if(![text containsString:@"CompletionDemo"] || ![doc.content isEqual:original]) { fail(@"server text or document changed"); return; }
			fprintf(stderr,"HOVER TEST: clangd: %s\n",text.UTF8String);
			CapturePrototype(panel,@"hover-popup.png");
			[view.textView mouseExited:nil];
			if([[view.textView valueForKey:@"hoverPanel"] isVisible]) { fail(@"exit did not dismiss"); return; }
			view.textView.hoverProvider = ^(NSUInteger line,NSUInteger column,void (^reply)(NSString*)) { pending = [reply copy]; };
			move(); stage = 3;
		} else if(stage == 3 && pending) {
			[view.textView mouseExited:nil]; pending(@"STALE"); pending = nil;
			if([view.textView valueForKey:@"hoverPanel"]) { fail(@"stale pointer reply"); return; }
			move(); stage = 4;
		} else if(stage == 4 && pending) {
			[view.textView insertText:@"x"]; pending(@"STALE"); pending = nil;
			if([view.textView valueForKey:@"hoverPanel"]) { fail(@"stale edited reply"); return; }
			[view.textView selectAll:nil]; [view.textView insertText:original]; [doc markDocumentSaved];
			view.textView.hoverProvider = realProvider;
			[view startLSP];
			stage = 5;
		} else if(stage == 5 && view.lspPanel.diagnostics.count) { move(); stage = 6; }
		else if(stage == 6 && [[view.textView valueForKey:@"hoverPanel"] isVisible]) {
			CapturePrototype([view.textView valueForKey:@"hoverPanel"],@"hover-popup.png");
			CapturePrototype(controller.window,@"hover-editor.png");
			fprintf(stderr,"HOVER TEST: PASS real clangd, UTF-16, no edits, pointer exit, stale pointer/edit replies; fixture restored\n");
			[timer invalidate];
		}
	}];
}

static void RunFormattingTest(NSString* path) {
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSInteger stage = 0;
	__block NSUInteger ticks = 0;
	__block NSString* original;
	__block NSString* formatted;
	__block NSString* edited;
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		auto fail = [&](NSString* reason) { fprintf(stderr,"FORMAT TEST: FAIL %s\n",reason.UTF8String); [timer invalidate]; };
		if(++ticks > 240) { fail([NSString stringWithFormat:@"timeout stage %ld",stage]); return; }
		DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
		OakDocumentView* view = [controller valueForKey:@"documentView"];
		if(!view.lspPanel) return;
		if(stage == 0) { original = doc.content; [view startLSP]; stage = 1; }
		else if(stage == 1 && view.lspPanel.formattingEnabled) {
			CapturePrototype(controller.window,@"format-before.png");
			[view formatDocument:nil];
			if(!view.lspPanel.formattingBusy && [doc.content isEqual:original]) { fail(@"format request not dispatched"); return; }
			stage = 2;
		} else if(stage == 2 && !view.lspPanel.formattingBusy) {
			formatted = doc.content;
			if([formatted isEqual:original] || ![formatted containsString:@"a + b"] || ![formatted containsString:@"Olá 🌍"]) { fail(@"formatting edits or Unicode"); return; }
			CapturePrototype(controller.window,@"format-after.png");
			[view.textView tryToPerform:@selector(undo:) with:nil];
			if(![doc.content isEqual:original]) { fail(@"single Undo"); return; }
			[controller.window makeFirstResponder:view.textView];
			NSMenuItem* item = [[NSApp.mainMenu itemWithTitle:@"Text"].submenu itemWithTitle:@"Format Document"];
			if(item) { fail(@"formatting should belong to the Aeon bundle, not Text menu"); return; }
			[view formatDocument:nil];
			stage = 3;
		} else if(stage == 3 && !view.lspPanel.formattingBusy) {
			if(![doc.content isEqual:formatted]) { fail(@"shortcut did not format"); return; }
			[view formatDocument:nil]; stage = 4;
		} else if(stage == 4 && !view.lspPanel.formattingBusy) {
			if(![doc.content isEqual:formatted]) { fail(@"no-op changed text"); return; }
			[view.textView selectAll:nil]; [view.textView insertText:original];
			[view formatDocument:nil];
			[view.textView insertText:@"\n// User edit during formatting\n"];
			edited = doc.content; stage = 5;
		} else if(stage == 5 && !view.lspPanel.formattingBusy) {
			if(![doc.content isEqual:edited]) { fail(@"stale formatting overwrote edit"); return; }
			[view.textView selectAll:nil]; [view.textView insertText:original]; [doc markDocumentSaved];
			[view startLSP]; stage = 6;
		} else if(stage == 6 && view.lspPanel.formattingEnabled) {
			[view formatDocument:nil]; stage = 7;
		} else if(stage == 7 && !view.lspPanel.formattingBusy) {
			if(![doc.content isEqual:formatted]) { fail(@"final format"); return; }
			CapturePrototype(controller.window,@"format-final.png");
			fprintf(stderr,"FORMAT TEST: PASS core clangd formatting, Unicode, single Undo, no-op, stale edits; no global Format menu\n");
			[timer invalidate];
		}
	}];
}

static NSTextField* RenameInput(NSView* view) {
	if([view isKindOfClass:NSTextField.class] && [view.accessibilityLabel isEqual:@"New symbol name"]) return (NSTextField*)view;
	for(NSView* child in view.subviews) if(NSTextField* input = RenameInput(child)) return input;
	return nil;
}

static void RunSymbolTest(NSString* path) {
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	OakDocument* header = [OakDocumentController.sharedInstance documentWithPath:[path.stringByDeletingLastPathComponent stringByAppendingPathComponent:@"symbols.hpp"]];
	doc.recentTrackingDisabled = header.recentTrackingDisabled = YES; doc.keepBackupFile = header.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSInteger stage = 0;
	__block NSUInteger ticks = 0;
	__block NSString* original;
	__block NSString* headerOriginal;
	__block NSInteger multiAttempt = 0;
	__block NSString* interveningEdit;
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		auto fail = [&](NSString* reason) { fprintf(stderr,"SYMBOL TEST: FAIL %s\n",reason.UTF8String); [timer invalidate]; };
		if(++ticks > 320) { fail([NSString stringWithFormat:@"timeout stage %ld",stage]); return; }
		DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
		OakDocumentView* view = [controller valueForKey:@"documentView"];
		if(!view.lspPanel) return;
		auto position = [&](NSUInteger line, NSString* symbol) {
			NSString* text = [doc.content componentsSeparatedByString:@"\n"][line];
			NSUInteger column = [text rangeOfString:symbol].location;
			view.textView.selectionString = [NSString stringWithFormat:@"%lu:%lu",line+1,[[text substringToIndex:column] lengthOfBytesUsingEncoding:NSUTF8StringEncoding]+1];
			[controller.window makeFirstResponder:view.textView];
		};
		if(ticks % 20 == 0) fprintf(stderr,"SYMBOL TEST: stage %ld file %s status %s\n",stage,view.document.path.UTF8String,[(NSTextField*)[view.lspPanel valueForKey:@"status"] stringValue].UTF8String);
		if(stage == 0) { original = doc.content; [view startLSP]; stage = 1; }
		else if(stage == 1 && view.lspClient.supportsRename && view.lspClient.supportsDefinition) {
			position(3,@"local_double");
			NSDictionary* p = view.textView.lspSymbolPosition;
			if([p[@"character"] unsignedIntegerValue] != [[doc.content componentsSeparatedByString:@"\n"][3] rangeOfString:@"local_double"].location) { fail(@"UTF-16 symbol position"); return; }
			NSEvent* key = [NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:NSEventModifierFlagFunction timestamp:0 windowNumber:controller.window.windowNumber context:nil characters:[NSString stringWithFormat:@"%C",(unichar)NSF12FunctionKey] charactersIgnoringModifiers:[NSString stringWithFormat:@"%C",(unichar)NSF12FunctionKey] isARepeat:NO keyCode:111];
			if(![NSApp.mainMenu performKeyEquivalent:key]) { fail(@"definition shortcut"); return; }
			stage = 2;
		} else if(stage == 2 && [view.textView.selectionString hasPrefix:@"2:5-"]) {
			position(3,@"local_double");
			NSEvent* key = [NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:NSEventModifierFlagOption|NSEventModifierFlagShift|NSEventModifierFlagCommand timestamp:0 windowNumber:controller.window.windowNumber context:nil characters:@"R" charactersIgnoringModifiers:@"R" isARepeat:NO keyCode:15];
			if(![NSApp.mainMenu performKeyEquivalent:key]) { fail(@"rename shortcut"); return; }
			stage = 3;
		} else if(stage == 3 && controller.window.attachedSheet) {
			NSTextField* input = RenameInput(controller.window.attachedSheet.contentView);
			if(!input) return;
			if(![input.stringValue isEqual:@"local_double"]) { fail(@"prepareRename placeholder"); return; }
			input.stringValue = @"twice";
			[NSApp endSheet:controller.window.attachedSheet returnCode:NSAlertFirstButtonReturn]; stage = 4;
		} else if(stage == 4 && [doc.content containsString:@"int twice("]) {
			if([doc.content containsString:@"local_double"] || ![doc.content containsString:@"Olá 🌍"]) { fail(@"rename references or Unicode"); return; }
			CapturePrototype(controller.window,@"rename-local.png");
			[doc undo];
			if(![doc.content isEqual:original]) { fail(@"rename single Undo"); return; }
			position(4,@"shared_add"); [view goToDefinition:nil]; stage = 5;
		} else if(stage == 5 && view.document == header) {
			if(![view.textView.selectionString hasPrefix:@"2:12-"]) { fail(@"header definition selection"); return; }
			headerOriginal = header.content;
			CapturePrototype(controller.window,@"definition-header.png");
			[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t(4,9) inProject:nil bringToFront:YES];
			stage = 6;
		} else if(stage == 6 && view.document == doc) {
			[view startLSP]; stage = 7;
		} else if(stage == 7 && view.lspClient.supportsRename) {
			position(4,@"shared_add"); [view renameSymbol:nil]; stage = 8;
		} else if(stage == 8 && controller.window.attachedSheet) {
			NSTextField* input = RenameInput(controller.window.attachedSheet.contentView); if(!input) return;
			input.stringValue = @"sum_values"; [NSApp endSheet:controller.window.attachedSheet returnCode:NSAlertFirstButtonReturn]; stage = 9;
		} else if(stage == 9 && controller.window.attachedSheet && !RenameInput(controller.window.attachedSheet.contentView)) {
			CapturePrototype(controller.window.attachedSheet,@"rename-confirmation.png");
			if(multiAttempt++ == 0) { [NSApp endSheet:controller.window.attachedSheet returnCode:NSAlertSecondButtonReturn]; stage = 11; }
			else if(multiAttempt == 2) {
				[view.textView selectAll:nil]; [view.textView insertText:[original stringByAppendingString:@"// Edit while rename confirmation is open\n"]];
				interveningEdit = doc.content;
				[NSApp endSheet:controller.window.attachedSheet returnCode:NSAlertFirstButtonReturn]; stage = 12;
			} else { [NSApp endSheet:controller.window.attachedSheet returnCode:NSAlertFirstButtonReturn]; stage = 10; }
		} else if(stage == 11 && !controller.window.attachedSheet && ![[view valueForKey:@"symbolBusy"] boolValue]) {
			if(![doc.content isEqual:original] || ![header.content isEqual:headerOriginal]) { fail(@"cancel changed documents"); return; }
			stage = 7;
		} else if(stage == 12 && !controller.window.attachedSheet && ![[view valueForKey:@"symbolBusy"] boolValue]) {
			if(![doc.content isEqual:interveningEdit] || ![header.content isEqual:headerOriginal]) { fail(@"stale rename partially applied"); return; }
			[doc undo]; if(![doc.content isEqual:original]) { fail(@"restore after stale test"); return; }
			[doc markDocumentSaved]; [view startLSP]; stage = 7;
		} else if(stage == 10 && [doc.content containsString:@"sum_values"] && [header.content containsString:@"sum_values"]) {
			[doc undo]; [header undo];
			if(![doc.content isEqual:original] || ![header.content isEqual:headerOriginal]) { fail(@"multi-file Undo"); return; }
			[doc markDocumentSaved]; [header markDocumentSaved];
			[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t(3,0) inProject:nil bringToFront:YES];
			fprintf(stderr,"SYMBOL TEST: PASS clangd prepare/rename, shortcuts, Unicode, local and header definition, multi-file confirmation/cancel/stale guards, per-file Undo; fixtures restored\n");
			[timer invalidate];
		}
	}];
}

void RunLSPPrototypeTest(NSString* path) {
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonSnippetTest"]) { RunAeonSnippetTest(path); return; }
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonCommentTest"]) { RunAeonCommentTest(path); return; }
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonHighlightTest"]) {
		[DocumentWindowController disableSessionSave];
		auto item = bundles::lookup(oak::uuid_t("DE924C99-967E-4820-B5AD-F2C648C1C572"));
		if(!item) { fprintf(stderr,"AEON SYNTAX: FAIL grammar not indexed\n"); return; }
		auto grammar = parse::parse_grammar(item);
		struct Sample { char const* source; char const* token; char const* expected; };
		Sample samples[] = {
			{"# a comment", "comment", "comment.line.aeon"},
			{"open Agent", "open", "keyword.control.import.aeon"},
			{"open Agent", "Agent", "entity.name.namespace.aeon"},
			{"def greet (x : Int) : Int := 42", "def", "keyword.declaration.function.aeon"},
			{"def greet (x : Int) : Int := 42", "greet", "entity.name.function.aeon"},
			{"def greet (x : Int) : Int := 42", "Int", "storage.type.primitive.aeon"},
			{"def greet (x : Int) : Int := 42", ":=", "keyword.operator.assignment.aeon"},
			{"42", "42", "constant.numeric.integer.aeon"},
			{"3.14", "3.14", "constant.numeric.float.aeon"},
			{"true", "true", "constant.language.boolean.aeon"},
			{"if x then 1 else 0", "then", "keyword.control.aeon"},
			{"type Positive", "Positive", "entity.name.type.aeon"},
			{"let 1 session := x", "session", "variable.declaration.aeon"},
			{"@example", "example", "entity.name.tag.macro.aeon"},
			{"fun x -> x", "fun", "keyword.control.lambda.aeon"},
			{"λx → x", "λ", "keyword.control.lambda.aeon"},
			{"Λa => x", "Λ", "keyword.operator.kind.lambda.symbol.aeon"},
			{"x ≤ 2", "≤", "keyword.operator.comparison.aeon"},
			{"\"Olá 🌍\"", "Olá", "string.quoted.double.aeon"},
			{R"ae("a\"b")ae", R"ae(\")ae", "constant.character.escape.aeon"},
			{"native_import \"os\"", "os", "string.quoted.module.python"},
			{"native \"x + 1\"", "x", "source.python"},
		};
		for(auto const& sample : samples) {
			std::string source = sample.source;
			std::map<size_t, scope::scope_t> scopes;
			parse::parse(source.data(), source.data()+source.size(), grammar->seed(), scopes, true);
			auto found = scopes.upper_bound(source.find(sample.token));
			std::string actual = found == scopes.begin() ? "" : scope::to_s(std::prev(found)->second);
			if(actual.find(sample.expected) == std::string::npos) {
				fprintf(stderr,"AEON SYNTAX: FAIL token=%s expected=%s actual=%s\n",sample.token,sample.expected,actual.c_str()); return;
			}
		}
		fprintf(stderr,"AEON SYNTAX: PASS %lu native grammar scope checks\n",sizeof(samples)/sizeof(samples[0]));
		OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
		doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
		[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
		dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 3*NSEC_PER_SEC), dispatch_get_main_queue(), ^{
			CapturePrototype([DocumentWindowController controllerForDocument:doc].window, @"aeon-highlighting.png");
		});
		return;
	}
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonImportsTest"]) {
		[DocumentWindowController disableSessionSave];
		NSString* expected = [NSUserDefaults.standardUserDefaults stringForKey:@"LSPAeonImportRoot"];
		NSString* root = OakLSPAeonProjectRoot(path);
		if(![root.stringByResolvingSymlinksInPath isEqual:expected.stringByResolvingSymlinksInPath]) {
			fprintf(stderr,"AEON IMPORTS: FAIL root %s expected %s\n",root.UTF8String,expected.UTF8String); return;
		}
		NSString* parentDirectory = NSFileManager.defaultManager.currentDirectoryPath;
		__block OakLSPClient* client = [OakLSPClient new];
		__block BOOL completed = NO;
		client.changed = ^(NSString* state, NSArray* diagnostics, NSInteger version) {
			if(completed || (![state isEqual:@"Ready"] && ![state hasPrefix:@"Failed"])) return;
			completed = YES;
			struct proc_vnodepathinfo info = {};
			BOOL read = proc_pidinfo((int)client.processIdentifier, PROC_PIDVNODEPATHINFO, 0, &info, sizeof(info)) == sizeof(info);
			NSString* cwd = read ? [NSString stringWithUTF8String:info.pvi_cdir.vip_path] : @"unavailable";
			BOOL correct = [cwd.stringByResolvingSymlinksInPath isEqual:root.stringByResolvingSymlinksInPath];
			BOOL preserved = [NSFileManager.defaultManager.currentDirectoryPath isEqual:parentDirectory];
			NSUInteger errors = 0;
			for(NSDictionary* diagnostic in diagnostics) {
				errors += [diagnostic[@"severity"] integerValue] == 1;
				fprintf(stderr,"AEON IMPORTS: diagnostic %s\n",[diagnostic[@"message"] UTF8String]);
			}
			fprintf(stderr,"AEON IMPORTS: %s path=%s cwd=%s parent-cwd-preserved=%d errors=%lu state=%s\n",
				correct && preserved && !errors && [state isEqual:@"Ready"] ? "PASS" : "FAIL",
				path.UTF8String, cwd.UTF8String, preserved, errors, state.UTF8String);
			[client stop]; client.changed = nil; client = nil;
		};
		[client startPath:path content:[NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil]];
		dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 90*NSEC_PER_SEC), dispatch_get_main_queue(), ^{
			if(completed) return;
			completed = YES; fprintf(stderr,"AEON IMPORTS: FAIL timeout\n");
			[client stop]; client.changed = nil; client = nil;
		});
		return;
	}
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonSyncTest"]) {
		[DocumentWindowController disableSessionSave];
		OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
		doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
		[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
		__block NSInteger stage = 0, pid = 0; __block NSUInteger ticks = 0;
		__block NSString* original; __block OakLSPClient* client;
		[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
			DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
			OakDocumentView* view = [controller valueForKey:@"documentView"];
			void (^fail)(NSString*) = ^(NSString* reason) { fprintf(stderr,"AEON SYNC: FAIL %s stage %ld\n",reason.UTF8String,stage); [timer invalidate]; };
			if(++ticks > 360) { fail(@"timeout"); return; }
			if(!view.lspPanel) return;
			NSString* status = [(NSTextField*)[view.lspPanel valueForKey:@"status"] stringValue];
			if(pid && (view.lspClient != client || client.processIdentifier != pid)) { fail(@"server restarted"); return; }
			if(stage == 0) { original = doc.content; [view startLSP]; client = view.lspClient; stage = 1; }
			else if(stage == 1 && [status hasPrefix:@"0 errors"]) {
				pid = client.processIdentifier;
				[view.textView selectAll:nil]; [view.textView insertText:@"def main (u:Int) : Int := missing_value;\n"];
				stage = 2;
			} else if(stage == 2 && view.lspPanel.diagnostics.count) {
				fprintf(stderr,"AEON SYNC: diagnostics updated on PID %ld version %ld\n",pid,client.version);
				for(NSUInteger i=0; i<20; ++i) { [view.textView selectAll:nil]; [view.textView insertText:[NSString stringWithFormat:@"def main (u:Int) : Int := missing_%lu;\n",i]]; }
				stage = 3;
			} else if(stage == 3) {
				[view.textView selectAll:nil]; [view.textView insertText:[original stringByReplacingOccurrencesOfString:@"inc" withString:@"plus_one"]];
				stage = 4;
			} else if(stage == 4 && [status hasPrefix:@"0 errors"]) {
				view.textView.selectionString = @"4:14"; [controller.window makeFirstResponder:view.textView]; [view goToDefinition:nil]; stage = 5;
			} else if(stage == 5 && [view.textView.selectionString isEqual:@"1:5-1:13"]) {
				CapturePrototype(controller.window,@"aeon-sync-updated.png");
				[view.textView selectAll:nil]; [view.textView insertText:original]; [doc markDocumentSaved]; stage = 6;
			} else if(stage == 6 && [status hasPrefix:@"0 errors"]) {
				CapturePrototype(controller.window,@"aeon-sync-final.png");
				fprintf(stderr,"AEON SYNC: PASS persistent PID %ld; version %ld; diagnostics, rapid edits, superseded analysis, latest definition; fixture restored\n",pid,client.version);
				[timer invalidate];
			}
		}];
		return;
	}
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonNavigationTest"]) {
		[DocumentWindowController disableSessionSave];
		OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
		doc.recentTrackingDisabled = YES; doc.keepBackupFile = NO;
		[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
		__block NSInteger stage = 0; __block NSUInteger ticks = 0;
		[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
			DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
			OakDocumentView* view = [controller valueForKey:@"documentView"];
			NSUInteger limit = [NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonUVTest"] ? 1440 : 240;
			if(++ticks > limit) { fprintf(stderr,"AEON NAV: FAIL timeout stage %ld status %s\n",stage,[(NSTextField*)[view.lspPanel valueForKey:@"status"] stringValue].UTF8String); [timer invalidate]; return; }
			if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonUVTest"] && ticks % 20 == 0) fprintf(stderr,"AEON UV: %s\n",[(NSTextField*)[view.lspPanel valueForKey:@"status"] stringValue].UTF8String);
			if(!view.lspPanel) return;
			if(stage == 0) { [view startLSP]; stage = 1; }
			else if(stage == 1 && [[(NSTextField*)[view.lspPanel valueForKey:@"status"] stringValue] hasPrefix:@"0 errors"]) {
				fprintf(stderr,"AEON NAV: capabilities definition=%d rename=%d\n",view.lspClient.supportsDefinition,view.lspClient.supportsRename);
				if(!view.lspClient.supportsDefinition || view.lspClient.supportsRename) { fprintf(stderr,"AEON NAV: FAIL unexpected capabilities\n"); [timer invalidate]; return; }
				view.textView.selectionString = @"4:14"; [controller.window makeFirstResponder:view.textView];
				[NSApp.mainMenu update];
				NSMenuItem* rename = [[NSApp.mainMenu itemWithTitle:@"Text"].submenu itemWithTitle:@"Rename Symbol…"];
				if([(id<NSMenuItemValidation>)view validateMenuItem:rename]) { fprintf(stderr,"AEON NAV: FAIL Rename enabled\n"); [timer invalidate]; return; }
				CapturePrototype(controller.window,@"aeon-definition-before.png");
				[view goToDefinition:nil]; stage = 2;
			} else if(stage == 2 && [view.textView.selectionString hasPrefix:@"1:"]) {
				fprintf(stderr,"AEON NAV: function definition selected %s\n",view.textView.selectionString.UTF8String);
				CapturePrototype(controller.window,@"aeon-definition-function.png");
				view.textView.selectionString = @"4:18"; [view goToDefinition:nil]; stage = 3;
			} else if(stage == 3 && [view.textView.selectionString hasPrefix:@"3:"]) {
				fprintf(stderr,"AEON NAV: binding definition selected %s\n",view.textView.selectionString.UTF8String);
				view.textView.selectionString = @"4:14"; [view goToDefinition:nil]; stage = 4;
			} else if(stage == 4 && [view.textView.selectionString hasPrefix:@"1:"]) {
				CapturePrototype(controller.window,@"aeon-definition-final.png");
				fprintf(stderr,"AEON NAV: PASS real Aeon function and local-binding definitions; unsupported Rename disabled; demo left open\n");
				[timer invalidate];
			}
		}];
		return;
	}
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPSymbolTest"]) { RunSymbolTest(path); return; }
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonBundleTest"]) { RunAeonBundleTest(path); return; }
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonFormatBundleTest"]) { RunAeonFormatBundleTest(path); return; }
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPFormattingTest"]) { RunFormattingTest(path); return; }
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPHoverTest"]) { RunHoverTest(path); return; }
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPCompletionTest"]) { RunCompletionTest(path); return; }
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonSynthesisTest"]) { RunAeonSynthesisTest(path); return; }
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPCodeActionsTest"]) { RunCodeActionsTest(path); return; }
	[DocumentWindowController disableSessionSave];
	OakDocument* doc = [OakDocumentController.sharedInstance documentWithPath:path];
	doc.recentTrackingDisabled = YES;
	doc.keepBackupFile = NO;
	[OakDocumentController.sharedInstance showDocument:doc andSelect:text::pos_t::undefined inProject:nil bringToFront:YES];
	__block NSInteger stage = 0;
	__block NSUInteger ticks = 0;
	__block NSString* original = nil;
	__block NSDictionary* originalArguments = nil;
	[NSTimer scheduledTimerWithTimeInterval:0.25 repeats:YES block:^(NSTimer* timer) {
		if(++ticks > 240) { fprintf(stderr, "LSP UI TEST: timeout at stage %ld\n", stage); [timer invalidate]; return; }
		DocumentWindowController* controller = [DocumentWindowController controllerForDocument:doc];
		OakDocumentView* view = [controller valueForKey:@"documentView"];
		if(!view.lspPanel) return;
		if(stage == 0) {
			[view layoutSubtreeIfNeeded];
			GutterView* gutter = [view valueForKey:@"gutterView"];
			if(![gutter visibilityForColumnWithIdentifier:GVLineNumbersColumnIdentifier] || NSWidth(gutter.frame) <= 0) {
				fprintf(stderr, "LSP UI TEST: FAIL line numbers hidden or gutter has no width\n"); [timer invalidate]; return;
			}
			fprintf(stderr, "LSP UI TEST: native line-number gutter visible (%g pt); font %s\n", NSWidth(gutter.frame), view.textView.font.fontName.UTF8String);
			original = doc.content;
			[view startLSP]; stage = 1;
		} else if(stage == 1 && view.lspPanel.diagnostics.count >= 2) {
			if(!TestDiagnosticRows(view)) { [timer invalidate]; return; }
			if(view.textView.lspDiagnostics.count != view.lspPanel.diagnostics.count || ![[view.textView valueForKey:@"diagnosticByteRanges"] count]) { fprintf(stderr,"LSP UI TEST: FAIL missing inline ranges\n"); [timer invalidate]; return; }
			NSDictionary* first = view.lspPanel.diagnostics.firstObject;
			[view.lspPanel selectDiagnosticAtLine:9];
			if(![view.textView.selectionString isEqualToString:@"10:44"]) {
				fprintf(stderr, "LSP UI TEST: FAIL Unicode navigation: %s\n", view.textView.selectionString.UTF8String); [timer invalidate]; return;
			}
			fprintf(stderr, "LSP UI TEST: UTF-16 to UTF-8 navigation passed\n");
			[view.lspPanel selectDiagnosticAtLine:[first[@"line"] unsignedIntegerValue]];
			fprintf(stderr, "LSP UI TEST: %lu diagnostics; selected %s\n", view.lspPanel.diagnostics.count, view.textView.selectionString.UTF8String);
			CapturePrototype(controller.window, @"01-problems.png");
			[view.textView selectAll:nil];
			[view.textView insertText:[original stringByReplacingOccurrencesOfString:@"discount;" withString:@"2;"]];
			if(view.textView.lspDiagnostics.count) { fprintf(stderr,"LSP UI TEST: FAIL stale underlines after edit\n"); [timer invalidate]; return; }
			[view.textView selectAll:nil];
			[view.textView insertText:[doc.content stringByReplacingOccurrencesOfString:@"missing_quantity" withString:@"3"]];
			stage = 2;
		} else if(stage == 2 && view.lspPanel.diagnostics.count == 0) {
			NSTextField* status = [view.lspPanel valueForKey:@"_status"];
			if(![status.stringValue hasPrefix:@"0 errors"]) return;
			CapturePrototype(controller.window, @"02-clean.png");
			view.lspPanel.expanded = NO;
			CapturePrototype(controller.window, @"03-collapsed.png");
			fprintf(stderr, "LSP UI TEST: edited through OakTextView; diagnostics cleared; collapse passed\n");
			[view.textView selectAll:nil]; [view.textView insertText:original];
			view.lspPanel.expanded = YES;
			stage = 3;
		} else if(stage == 3 && view.lspPanel.diagnostics.count >= 2) {
			[view.lspPanel selectDiagnosticAtLine:[view.lspPanel.diagnostics.firstObject[@"line"] unsignedIntegerValue]];
			CapturePrototype(controller.window, @"04-final.png");
			[doc markDocumentSaved];
			view.lspPanel.toggleServer();
			if(view.lspPanel.diagnostics.count || view.textView.lspDiagnostics.count) { fprintf(stderr, "LSP UI TEST: FAIL stop retained diagnostics\n"); [timer invalidate]; return; }
			stage = 4;
		} else if(stage == 4) {
			view.lspPanel.toggleServer(); stage = 5;
		} else if(stage == 5 && view.lspPanel.diagnostics.count >= 2) {
			[view.textView selectAll:nil];
			[view.textView insertText:@"#warning Prototype warning\nint main() { return 0; }\n"];
			stage = 6;
		} else if(stage == 6 && view.lspPanel.diagnostics.count == 1 && [view.lspPanel.diagnostics.firstObject[@"severity"] intValue] == 2) {
			if([view.textView.lspDiagnostics.firstObject[@"severity"] intValue] != 2) { fprintf(stderr,"LSP UI TEST: FAIL missing warning underline\n"); [timer invalidate]; return; }
			CapturePrototype(controller.window, @"05-warning.png");
			[view.textView selectAll:nil]; [view.textView insertText:original];
			view.lspPanel.toggleServer();
			originalArguments = [NSUserDefaults.standardUserDefaults volatileDomainForName:NSArgumentDomain];
			NSMutableDictionary* arguments = [originalArguments mutableCopy];
			arguments[@"LSPClangdPath"] = @"/nonexistent/textmate-lsp-test-clangd";
			[NSUserDefaults.standardUserDefaults setVolatileDomain:arguments forName:NSArgumentDomain];
			view.lspPanel.toggleServer(); stage = 7;
		} else if(stage == 7 && [[[view.lspPanel valueForKey:@"_status"] stringValue] hasPrefix:@"Failed"]) {
			CapturePrototype(controller.window, @"06-server-failure.png");
			[NSUserDefaults.standardUserDefaults setVolatileDomain:originalArguments forName:NSArgumentDomain];
			view.lspPanel.toggleServer(); stage = 8;
		} else if(stage == 8 && view.lspPanel.diagnostics.count >= 2) {
			[view.lspPanel selectDiagnosticAtLine:4];
			[doc markDocumentSaved];
			CapturePrototype(controller.window, @"04-final.png");
			fprintf(stderr, "LSP UI TEST: PASS; stop/restart, warnings, missing-server recovery passed; restored sample, prototype left open\n");
			[timer invalidate];
		}
	}];
}
