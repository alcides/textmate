#import "OakLSPPanel.h"

@implementation OakLSPPanel {
	NSButton *_disclosure, *_server, *_previous, *_next, *_actions;
	NSUInteger _actionGeneration;
	NSTextField *_status, *_empty, *_detail;
	NSTableView* _table;
	NSScrollView* _scroll;
	NSLayoutConstraint* _height;
}
- (instancetype)initWithFrame:(NSRect)frame {
	if(self = [super initWithFrame:frame]) {
		// NSView no longer clips by default when linked against modern AppKit.
		// Keep this auxiliary panel (and its collapsed contents) out of the editor.
		self.clipsToBounds = YES;
		self.accessibilityLabel = @"Language server diagnostics";
		_disclosure = [NSButton buttonWithTitle:@"▸ Problems" target:self action:@selector(toggleExpanded:)];
		_disclosure.bordered = NO;
		_disclosure.font = [NSFont systemFontOfSize:12 weight:NSFontWeightSemibold];
		_server = [NSButton buttonWithTitle:@"Start clangd" target:self action:@selector(toggleServerAction:)];
		_server.bezelStyle = NSBezelStyleRounded;
		_server.controlSize = NSControlSizeSmall;
		_actions = [NSButton buttonWithTitle:@"Quick Fix…" target:self action:@selector(requestCodeActions:)];
		_actions.bezelStyle = NSBezelStyleRounded;
		_actions.controlSize = NSControlSizeSmall;
		_actions.toolTip = @"Code actions for the selected problem";
		_previous = [NSButton buttonWithImage:[NSImage imageWithSystemSymbolName:@"chevron.up" accessibilityDescription:@"Previous problem"] target:self action:@selector(previous:)];
		_next = [NSButton buttonWithImage:[NSImage imageWithSystemSymbolName:@"chevron.down" accessibilityDescription:@"Next problem"] target:self action:@selector(next:)];
		_previous.bordered = _next.bordered = NO;
		_previous.toolTip = @"Previous problem"; _next.toolTip = @"Next problem";
		_status = [NSTextField labelWithString:@""];
		_status.font = [NSFont systemFontOfSize:11];
		_status.alignment = NSTextAlignmentLeft;
		_status.textColor = NSColor.secondaryLabelColor;
		_status.lineBreakMode = NSLineBreakByTruncatingTail;
		[_status setContentCompressionResistancePriority:250 forOrientation:NSLayoutConstraintOrientationHorizontal];
		_table = [[NSTableView alloc] initWithFrame:NSZeroRect];
		_table.headerView = nil; _table.rowHeight = 32; _table.intercellSpacing = NSMakeSize(0, 0);
		_table.usesAlternatingRowBackgroundColors = YES;
		_table.style = NSTableViewStyleFullWidth;
		_table.dataSource = self; _table.delegate = self;
		_table.accessibilityLabel = @"Problems in current file";
		NSTableColumn* message = [[NSTableColumn alloc] initWithIdentifier:@"message"];
		message.resizingMask = NSTableColumnAutoresizingMask; message.width = 600;
		[_table addTableColumn:message];
		NSTableColumn* position = [[NSTableColumn alloc] initWithIdentifier:@"position"];
		position.width = 100; position.minWidth = 100; position.maxWidth = 100;
		position.resizingMask = NSTableColumnNoResizing;
		[_table addTableColumn:position];
		_scroll = [[NSScrollView alloc] initWithFrame:NSZeroRect];
		_scroll.documentView = _table; _scroll.hasVerticalScroller = YES; _scroll.autohidesScrollers = YES;
		_empty = [NSTextField wrappingLabelWithString:@""];
		_empty.textColor = NSColor.secondaryLabelColor; _empty.alignment = NSTextAlignmentLeft;
		_detail = [NSTextField labelWithString:@"Select a problem to reveal it in the editor."];
		_detail.font = [NSFont systemFontOfSize:11]; _detail.textColor = NSColor.secondaryLabelColor;
		_detail.alignment = NSTextAlignmentLeft;
		_detail.lineBreakMode = NSLineBreakByTruncatingTail;
		for(NSView* v in @[_disclosure, _status, _previous, _next, _server, _scroll, _empty, _detail, _actions]) {
			v.translatesAutoresizingMaskIntoConstraints = NO; [self addSubview:v];
		}
		_height = [self.heightAnchor constraintEqualToConstant:38];
		[NSLayoutConstraint activateConstraints:@[_height,
			[_disclosure.leadingAnchor constraintEqualToAnchor:self.leadingAnchor constant:10], [_disclosure.topAnchor constraintEqualToAnchor:self.topAnchor constant:7],
			[_status.leadingAnchor constraintEqualToAnchor:_disclosure.trailingAnchor constant:12], [_status.centerYAnchor constraintEqualToAnchor:_disclosure.centerYAnchor],
			[_previous.leadingAnchor constraintGreaterThanOrEqualToAnchor:_status.trailingAnchor constant:8], [_previous.centerYAnchor constraintEqualToAnchor:_disclosure.centerYAnchor], [_previous.widthAnchor constraintEqualToConstant:22],
			[_next.leadingAnchor constraintEqualToAnchor:_previous.trailingAnchor constant:4], [_next.centerYAnchor constraintEqualToAnchor:_disclosure.centerYAnchor], [_next.widthAnchor constraintEqualToConstant:22],
			[_actions.leadingAnchor constraintEqualToAnchor:_next.trailingAnchor constant:8], [_actions.centerYAnchor constraintEqualToAnchor:_disclosure.centerYAnchor],
			[_server.leadingAnchor constraintEqualToAnchor:_actions.trailingAnchor constant:8], [_server.trailingAnchor constraintEqualToAnchor:self.trailingAnchor constant:-12], [_server.centerYAnchor constraintEqualToAnchor:_disclosure.centerYAnchor],
			[_scroll.leadingAnchor constraintEqualToAnchor:self.leadingAnchor], [_scroll.trailingAnchor constraintEqualToAnchor:self.trailingAnchor], [_scroll.topAnchor constraintEqualToAnchor:self.topAnchor constant:38], [_scroll.heightAnchor constraintEqualToConstant:132],
			[_empty.centerYAnchor constraintEqualToAnchor:_scroll.centerYAnchor],
			[_empty.leadingAnchor constraintEqualToAnchor:self.leadingAnchor constant:14], [_empty.trailingAnchor constraintEqualToAnchor:self.trailingAnchor constant:-14],
			[_detail.leadingAnchor constraintEqualToAnchor:self.leadingAnchor constant:14], [_detail.trailingAnchor constraintEqualToAnchor:self.trailingAnchor constant:-14], [_detail.topAnchor constraintEqualToAnchor:_scroll.bottomAnchor constant:8]]];
		self.expanded = NO;
		[self showState:@"Start clangd to check this file" diagnostics:@[] running:NO];
	}
	return self;
}
- (BOOL)isFlipped { return YES; }
- (void)drawRect:(NSRect)rect {
	[NSGraphicsContext saveGraphicsState];
	NSRectClip(self.bounds);
	[NSColor.windowBackgroundColor setFill]; NSRectFill(NSIntersectionRect(rect, self.bounds));
	[NSColor.separatorColor setFill]; NSRectFill(NSMakeRect(0, 0, self.bounds.size.width, 1));
	[NSGraphicsContext restoreGraphicsState];
}
- (void)setExpanded:(BOOL)expanded {
	_expanded = expanded; _height.constant = expanded ? 202 : 38;
	_scroll.hidden = _detail.hidden = !expanded;
	_empty.hidden = !expanded || _diagnostics.count != 0;
	_disclosure.title = expanded ? @"▾ Problems" : @"▸ Problems";
}
- (void)toggleExpanded:(id)sender { self.expanded = !self.expanded; }
- (void)toggleServerAction:(id)sender { if(self.toggleServer) self.toggleServer(); }
- (void)showState:(NSString*)state diagnostics:(NSArray*)diagnostics running:(BOOL)running {
	++_actionGeneration; _actions.enabled = NO; _actions.title = @"Quick Fix…";
	_diagnostics = [diagnostics copy];
	NSUInteger errors=0, warnings=0;
	for(NSDictionary* d in diagnostics) { errors += [d[@"severity"] intValue] == 1; warnings += [d[@"severity"] intValue] == 2; }
	BOOL ready = [state isEqualToString:@"Ready"];
	_status.stringValue = ready ? [NSString stringWithFormat:@"%lu error%@ · %lu warning%@  —  clangd", errors, errors==1?@"":@"s", warnings, warnings==1?@"":@"s"] : state;
	_status.toolTip = _status.stringValue;
	_server.title = running ? @"Stop" : [state hasPrefix:@"Failed"] ? @"Restart clangd" : @"Start clangd";
	_empty.stringValue = ready ? @"✓ No problems in this file" : state;
	_empty.toolTip = state;
	_previous.enabled = _next.enabled = diagnostics.count != 0;
	_detail.stringValue = @"Current file only · Select a problem to reveal it in the editor";
	[_table deselectAll:nil]; [_table reloadData];
	if(self.serverName) {
		_status.stringValue = [_status.stringValue stringByReplacingOccurrencesOfString:@"clangd" withString:self.serverName];
		_server.title = [_server.title stringByReplacingOccurrencesOfString:@"clangd" withString:self.serverName];
		_empty.stringValue = [_empty.stringValue stringByReplacingOccurrencesOfString:@"clangd" withString:self.serverName];
	}
	self.expanded = self.expanded;
}
- (NSInteger)numberOfRowsInTableView:(NSTableView*)table { return _diagnostics.count; }
- (NSView*)tableView:(NSTableView*)table viewForTableColumn:(NSTableColumn*)column row:(NSInteger)row {
	NSDictionary* d = _diagnostics[row];
	NSTextField* label = [NSTextField labelWithString:@""];
	label.font = [NSFont systemFontOfSize:12]; label.lineBreakMode = NSLineBreakByTruncatingTail;
	if([column.identifier isEqualToString:@"position"]) {
		label.stringValue = [NSString stringWithFormat:@"%ld:%ld", [d[@"line"] integerValue]+1, [d[@"column"] integerValue]+1];
		label.textColor = NSColor.secondaryLabelColor; label.alignment = NSTextAlignmentRight;
	} else {
		label.alignment = NSTextAlignmentLeft;
		int severity = [d[@"severity"] intValue];
		NSString* kind = severity==1 ? @"Error" : severity==2 ? @"Warning" : @"Note";
		label.stringValue = [NSString stringWithFormat:@"%@  %@", severity==1 ? @"●" : severity==2 ? @"▲" : @"●", d[@"message"]];
		label.accessibilityLabel = [NSString stringWithFormat:@"%@: %@", kind, d[@"message"]];
		NSMutableAttributedString* title = [[NSMutableAttributedString alloc] initWithString:label.stringValue];
		NSMutableParagraphStyle* paragraph = [[NSMutableParagraphStyle alloc] init];
		paragraph.alignment = NSTextAlignmentLeft;
		paragraph.lineBreakMode = NSLineBreakByTruncatingTail;
		[title addAttribute:NSParagraphStyleAttributeName value:paragraph range:NSMakeRange(0, title.length)];
		[title addAttribute:NSForegroundColorAttributeName value:severity==1 ? NSColor.systemRedColor : severity==2 ? NSColor.systemOrangeColor : NSColor.systemBlueColor range:NSMakeRange(0, 1)];
		label.attributedStringValue = title;
	}
	label.toolTip = d[@"message"];
	NSView* cell = [[NSView alloc] initWithFrame:NSZeroRect];
	label.translatesAutoresizingMaskIntoConstraints = NO; [cell addSubview:label];
	[NSLayoutConstraint activateConstraints:@[[label.leadingAnchor constraintEqualToAnchor:cell.leadingAnchor constant:14], [label.trailingAnchor constraintEqualToAnchor:cell.trailingAnchor constant:-12], [label.centerYAnchor constraintEqualToAnchor:cell.centerYAnchor]]];
	return cell;
}
- (void)tableViewSelectionDidChange:(NSNotification*)notification {
	++_actionGeneration;
	_actions.title = @"Quick Fix…";
	NSInteger row = _table.selectedRow;
	_actions.enabled = row >= 0 && row < (NSInteger)_diagnostics.count;
	if(row < 0 || row >= (NSInteger)_diagnostics.count) return;
	NSDictionary* d = _diagnostics[row];
	_detail.stringValue = [NSString stringWithFormat:@"%@ · %@", d[@"source"], d[@"message"]];
	_detail.toolTip = _detail.stringValue;
	if(self.navigate) self.navigate(d);
}
- (void)selectRow:(NSInteger)row {
	if(!_diagnostics.count) return;
	self.expanded = YES;
	row = (row + _diagnostics.count) % _diagnostics.count;
	[_table selectRowIndexes:[NSIndexSet indexSetWithIndex:row] byExtendingSelection:NO];
	[_table scrollRowToVisible:row];
}
- (void)next:(id)sender { [self selectRow:_table.selectedRow+1]; }
- (void)previous:(id)sender { [self selectRow:_table.selectedRow < 0 ? _diagnostics.count-1 : _table.selectedRow-1]; }
- (void)selectDiagnosticAtLine:(NSUInteger)line {
	for(NSUInteger i=0; i<_diagnostics.count; ++i) if([_diagnostics[i][@"line"] unsignedIntegerValue] == line) { [self selectRow:i]; break; }
}
- (void)requestCodeActions:(id)sender {
	NSInteger row = _table.selectedRow;
	if(row < 0 || row >= (NSInteger)_diagnostics.count || !self.requestActions) return;
	NSUInteger generation = ++_actionGeneration;
	_actions.enabled = NO; _actions.title = @"Loading…";
	__weak OakLSPPanel* weakSelf = self;
	self.requestActions(_diagnostics[row], ^(NSArray* actions, NSString* error) {
		OakLSPPanel* panel = weakSelf;
		if(!panel || panel->_actionGeneration != generation) return;
		panel->_actions.enabled = YES; panel->_actions.title = @"Quick Fix…";
		NSMenu* menu = [panel codeActionMenuForActions:actions error:error];
		[menu popUpMenuPositioningItem:nil atLocation:NSMakePoint(0, NSHeight(panel->_actions.bounds)) inView:panel->_actions];
	});
}
- (NSMenu*)codeActionMenuForActions:(NSArray*)actions error:(NSString*)error {
		NSMenu* menu = [NSMenu new]; menu.autoenablesItems = NO;
		for(NSDictionary* action in actions) {
			NSMenuItem* item = [[NSMenuItem alloc] initWithTitle:action[@"title"] ?: @"Code action" action:@selector(applyCodeAction:) keyEquivalent:@""];
			item.target = self; item.representedObject = @{@"action":action, @"generation":@(_actionGeneration)};
			item.enabled = !action[@"disabled"];
			item.toolTip = action[@"disabled"][@"reason"];
			[menu addItem:item];
		}
		if(!menu.numberOfItems) { NSMenuItem* item = [[NSMenuItem alloc] initWithTitle:error ?: @"No quick fixes available" action:nil keyEquivalent:@""]; item.enabled = NO; [menu addItem:item]; }
		return menu;
}
- (void)applyCodeAction:(NSMenuItem*)item {
	if([item.representedObject[@"generation"] unsignedIntegerValue] != _actionGeneration) { NSBeep(); return; }
	if(self.applyAction) self.applyAction(item.representedObject[@"action"]);
}
@end
