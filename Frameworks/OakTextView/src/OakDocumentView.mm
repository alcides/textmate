#import "OakDocumentView.h"
#import "GutterView.h"
#import "OTVStatusBar.h"
#import "OakLSPPanel.h"
#import <OakLSP/OakLSPClient.h>
#import <document/OakDocument.h>
#import <document/OakDocumentController.h>
#import <file/type.h>
#import <text/ctype.h>
#import <text/parse.h>
#import <ns/ns.h>
#import <oak/debug.h>
#import <bundles/bundles.h>
#import <settings/settings.h>
#import <OakFilterList/SymbolChooser.h>
#import <OakFoundation/NSString Additions.h>
#import <OakAppKit/OakAppKit.h>
#import <OakAppKit/NSImage Additions.h>
#import <OakAppKit/OakToolTip.h>
#import <OakAppKit/OakPasteboardChooser.h>
#import <OakAppKit/OakPasteboard.h>
#import <OakAppKit/OakUIConstructionFunctions.h>
#import <OakAppKit/NSMenuItem Additions.h>
#import <BundleMenu/BundleMenu.h>

static NSString* const kUserDefaultsLineNumberScaleFactorKey = @"lineNumberScaleFactor";
static NSString* const kUserDefaultsLineNumberFontNameKey    = @"lineNumberFontName";

static NSString* const kBookmarksColumnIdentifier = @"bookmarks";
static NSString* const kFoldingsColumnIdentifier  = @"foldings";

@interface OakDocumentView () <NSAccessibilityGroup, GutterViewDelegate, GutterViewColumnDataSource, GutterViewColumnDelegate, OTVStatusBarDelegate>
{
	NSScrollView* gutterScrollView;
	GutterView* gutterView;
	NSMutableDictionary* gutterImages;

	OakBackgroundFillView* gutterDividerView;

	NSScrollView* textScrollView;

	NSMutableArray* topAuxiliaryViews;
	NSMutableArray* bottomAuxiliaryViews;

	IBOutlet NSPanel* tabSizeSelectorPanel;
}
@property (nonatomic, readonly) OTVStatusBar* statusBar;
@property (nonatomic) SymbolChooser* symbolChooser;
@property (nonatomic) NSArray* observedKeys;
@property (nonatomic) OakLSPPanel* lspPanel;
@property (nonatomic) OakLSPClient* lspClient;
@property (nonatomic) NSString* lspPath;
@property (nonatomic) BOOL lspEnabled;
@property (nonatomic) BOOL aeonSetupPromptVisible;
@property (nonatomic) BOOL symbolBusy;
@property (nonatomic) NSUInteger symbolSerial;
- (void)updateStyle;
@end

@implementation OakDocumentView
- (id)initWithFrame:(NSRect)aRect
{
	if(self = [super initWithFrame:aRect])
	{
		self.accessibilityRole  = NSAccessibilityGroupRole;
		self.accessibilityLabel = @"Editor";

		_textView = [[OakTextView alloc] initWithFrame:NSZeroRect];
		_textView.autoresizingMask = NSViewWidthSizable|NSViewHeightSizable;

		textScrollView = [[NSScrollView alloc] initWithFrame:NSZeroRect];
		textScrollView.hasVerticalScroller      = YES;
		textScrollView.verticalScrollElasticity = NSScrollElasticityAllowed;
		textScrollView.hasHorizontalScroller    = YES;
		textScrollView.autohidesScrollers       = YES;
		textScrollView.borderType               = NSNoBorder;
		textScrollView.documentView             = _textView;

		gutterView = [[GutterView alloc] initWithFrame:NSZeroRect];
		gutterView.partnerView = _textView;
		gutterView.delegate    = self;
		[gutterView insertColumnWithIdentifier:kBookmarksColumnIdentifier atPosition:0 dataSource:self delegate:self];
		[gutterView insertColumnWithIdentifier:kFoldingsColumnIdentifier atPosition:2 dataSource:self delegate:self];
		if([NSUserDefaults.standardUserDefaults boolForKey:@"DocumentView Disable Line Numbers"])
			[gutterView setVisibility:NO forColumnWithIdentifier:GVLineNumbersColumnIdentifier];
		[gutterView setTranslatesAutoresizingMaskIntoConstraints:NO];

		gutterScrollView = [[NSScrollView alloc] initWithFrame:NSZeroRect];
		gutterScrollView.accessibilityElement = NO;
		gutterScrollView.borderType   = NSNoBorder;
		gutterScrollView.documentView = gutterView;

		[gutterScrollView.contentView addConstraint:[NSLayoutConstraint constraintWithItem:gutterView attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:gutterScrollView.contentView attribute:NSLayoutAttributeLeft multiplier:1.0 constant:0.0]];
		[gutterScrollView.contentView addConstraint:[NSLayoutConstraint constraintWithItem:gutterView attribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:gutterScrollView.contentView attribute:NSLayoutAttributeTop multiplier:1.0 constant:0.0]];
		[gutterScrollView.contentView addConstraint:[NSLayoutConstraint constraintWithItem:gutterView attribute:NSLayoutAttributeRight relatedBy:NSLayoutRelationEqual toItem:gutterScrollView.contentView attribute:NSLayoutAttributeRight multiplier:1.0 constant:0.0]];

		gutterDividerView = OakCreateVerticalLine(OakBackgroundFillViewStyleNone);

		_statusBar = [[OTVStatusBar alloc] initWithFrame:NSZeroRect];
		_statusBar.delegate = self;
		_statusBar.target = self;

		OakAddAutoLayoutViewsToSuperview(@[ gutterScrollView, gutterDividerView, textScrollView, _statusBar ], self);
		OakSetupKeyViewLoop(@[ self, _textView, _statusBar ]);

		self.document = [OakDocument documentWithString:@"" fileType:@"text.plain" customName:@"placeholder"];

		self.observedKeys = @[ @"selectionString", @"symbol", @"recordingMacro", @"themeUUID" ];
		for(NSString* keyPath in self.observedKeys)
			[_textView addObserver:self forKeyPath:keyPath options:NSKeyValueObservingOptionInitial context:NULL];
	}
	return self;
}

- (void)updateConstraints
{
	[self removeConstraints:[self constraints]];
	[super updateConstraints];

	NSMutableArray* stackedViews = [NSMutableArray array];
	[stackedViews addObjectsFromArray:topAuxiliaryViews];
	[stackedViews addObject:gutterScrollView];
	[stackedViews addObjectsFromArray:bottomAuxiliaryViews];

	if(_statusBar)
	{
		[stackedViews addObject:_statusBar];
		[self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|[_statusBar]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(_statusBar)]];
	}

	[self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|[gutterScrollView(==gutterView)][gutterDividerView][textScrollView(>=100)]|" options:NSLayoutFormatAlignAllTop|NSLayoutFormatAlignAllBottom metrics:nil views:NSDictionaryOfVariableBindings(gutterScrollView, gutterView, gutterDividerView, textScrollView)]];
	[self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[topView]" options:0 metrics:nil views:@{ @"topView": stackedViews[0] }]];
	[self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[bottomView]|" options:0 metrics:nil views:@{ @"bottomView": [stackedViews lastObject] }]];

	for(size_t i = 0; i < [stackedViews count]-1; ++i)
		[self addConstraint:[NSLayoutConstraint constraintWithItem:stackedViews[i] attribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:stackedViews[i+1] attribute:NSLayoutAttributeTop multiplier:1 constant:0]];

	NSArray* array[] = { topAuxiliaryViews, bottomAuxiliaryViews };
	for(NSArray* views : array)
	{
		for(NSView* view in views)
			[self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|[view]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(view)]];
	}
}

- (void)setHideStatusBar:(BOOL)flag
{
	if(_hideStatusBar == flag)
		return;

	_hideStatusBar = flag;
	if(_hideStatusBar)
	{
		[_statusBar removeFromSuperview];
		_statusBar.delegate = nil;
		_statusBar.target = nil;
		_statusBar = nil;
	}
	else
	{
		_statusBar = [[OTVStatusBar alloc] initWithFrame:NSZeroRect];
		_statusBar.delegate = self;
		_statusBar.target = self;

		OakAddAutoLayoutViewsToSuperview(@[ _statusBar ], self);
	}
	[self setNeedsUpdateConstraints:YES];
}

- (CGFloat)lineHeight
{
	return round(std::min(1.5 * [_textView.font capHeight], [_textView.font ascender] - [_textView.font descender] + [_textView.font leading]));
}

- (NSImage*)gutterImage:(NSString*)aName
{
	id res = gutterImages[aName];
	if(!res)
	{
		gutterImages = gutterImages ?: [NSMutableDictionary new];

		NSImage* image = [aName hasPrefix:@"/"] ? [[NSImage alloc] initWithContentsOfFile:aName] : [NSImage imageNamed:aName inSameBundleAsClass:[self class]];
		if(!image && ![aName hasPrefix:@"/"] && ![aName hasSuffix:@" Template"])
			image = [NSImage imageNamed:[aName stringByAppendingString:@" Template"] inSameBundleAsClass:[self class]];

		if([aName hasPrefix:@"/"] && [[aName stringByDeletingPathExtension] hasSuffix:@" Template"])
			[image setTemplate:YES];

		if(image)
		{
			CGFloat imageWidth  = image.size.width;
			CGFloat imageHeight = image.size.height;

			CGFloat viewWidth   = [self widthForColumnWithIdentifier:nil];
			CGFloat viewHeight  = self.lineHeight;

			res = image = [image copy];

			if(imageWidth / imageHeight < viewWidth / viewHeight)
					image.size = NSMakeSize(round(viewHeight * imageWidth / imageHeight), viewHeight);
			else	image.size = NSMakeSize(viewWidth, round(viewWidth * imageHeight / imageWidth));
		}
		else
		{
			res = [NSNull null];
			NSLog(@"%s no image named ‘%@’", sel_getName(_cmd), aName);
		}

		gutterImages[aName] = res;
	}
	return res == [NSNull null] ? nil : res;
}

- (void)updateGutterViewFont:(id)sender
{
	CGFloat const scaleFactor = [NSUserDefaults.standardUserDefaults floatForKey:kUserDefaultsLineNumberScaleFactorKey] ?: 0.8;
	NSString* lineNumberFontName = [NSUserDefaults.standardUserDefaults stringForKey:kUserDefaultsLineNumberFontNameKey] ?: [_textView.font fontName];

	gutterImages = nil; // force image sizes to be recalculated
	gutterView.lineNumberFont = [NSFont fontWithName:lineNumberFontName size:round(scaleFactor * [_textView.font pointSize] * _textView.fontScaleFactor)];
	[gutterView reloadData:self];
}

- (IBAction)makeTextLarger:(id)sender
{
	_textView.fontScaleFactor += 0.1;
	[self updateGutterViewFont:self];
}

- (IBAction)makeTextSmaller:(id)sender
{
	if(_textView.fontScaleFactor > 0.1)
	{
		_textView.fontScaleFactor -= 0.1;
		[self updateGutterViewFont:self];
	}
}

- (IBAction)makeTextStandardSize:(id)sender
{
	_textView.fontScaleFactor = 1;
	[self updateGutterViewFont:self];
}

- (void)changeFont:(id)sender
{
	NSFont* defaultFont = [NSFont userFixedPitchFontOfSize:0];
	if(NSFont* newFont = [sender convertFont:_textView.font ?: defaultFont])
	{
		std::string fontName = [newFont.fontName isEqualToString:defaultFont.fontName] ? NULL_STR : to_s(newFont.fontName);
		settings_t::set(kSettingsFontNameKey, fontName);
		settings_t::set(kSettingsFontSizeKey, [newFont pointSize]);
		_textView.font = newFont;
		[self updateGutterViewFont:self];
	}
}

- (void)observeValueForKeyPath:(NSString*)aKeyPath ofObject:(id)observableController change:(NSDictionary*)changeDictionary context:(void*)userData
{
	if([aKeyPath isEqualToString:@"selectionString"])
	{
		NSString* str = [_textView valueForKey:@"selectionString"];
		[gutterView setHighlightedRange:to_s(str ?: @"1")];
		[_statusBar setSelectionString:str];
		_symbolChooser.selectionString = str;
	}
	else if([aKeyPath isEqualToString:@"symbol"])
	{
		_statusBar.symbolName = _textView.symbol;
	}
	else if([aKeyPath isEqualToString:@"recordingMacro"])
	{
		_statusBar.recordingMacro = _textView.isRecordingMacro;
	}
	else if([aKeyPath isEqualToString:@"fileType"])
	{
		_statusBar.fileType = self.document.fileType;
	}
	else if([aKeyPath isEqualToString:@"tabSize"])
	{
		_statusBar.tabSize = self.document.tabSize;
	}
	else if([aKeyPath isEqualToString:@"softTabs"])
	{
		_statusBar.softTabs = self.document.softTabs;
	}
	else if([aKeyPath isEqualToString:@"themeUUID"])
	{
		[self updateStyle];
	}
}

- (void)dealloc
{
	for(NSString* keyPath in self.observedKeys)
		[_textView removeObserver:self forKeyPath:keyPath];
	[NSNotificationCenter.defaultCenter removeObserver:self];

	self.document = nil;
	self.symbolChooser = nil;
}

- (void)setDocument:(OakDocument*)aDocument
{
	[self.lspClient stop]; self.lspClient = nil;
	NSArray* const documentKeys = @[ @"fileType", @"tabSize", @"softTabs" ];

	OakDocument* oldDocument = self.document;
	if(oldDocument)
	{
		for(NSString* key in documentKeys)
			[oldDocument removeObserver:self forKeyPath:key];
		[NSNotificationCenter.defaultCenter removeObserver:self name:OakDocumentMarksDidChangeNotification object:oldDocument];
		[NSNotificationCenter.defaultCenter removeObserver:self name:OakDocumentContentDidChangeNotification object:oldDocument];
		[NSNotificationCenter.defaultCenter removeObserver:self name:OakDocumentDidSaveNotification object:oldDocument];
	}

	if(aDocument)
		[aDocument loadModalForWindow:self.window completionHandler:nullptr];

	if(_document = aDocument)
	{
		[NSNotificationCenter.defaultCenter addObserver:self selector:@selector(documentMarksDidChange:) name:OakDocumentMarksDidChangeNotification object:self.document];
		[NSNotificationCenter.defaultCenter addObserver:self selector:@selector(lspContentChanged:) name:OakDocumentContentDidChangeNotification object:self.document];
		[NSNotificationCenter.defaultCenter addObserver:self selector:@selector(lspDocumentSaved:) name:OakDocumentDidSaveNotification object:self.document];
		for(NSString* key in documentKeys)
			[self.document addObserver:self forKeyPath:key options:NSKeyValueObservingOptionInitial context:nullptr];
	}

	[_textView setDocument:self.document];
	[gutterView reloadData:self];
	[self updateStyle];
	[self configureLSP];

	if(_symbolChooser)
	{
		_symbolChooser.TMDocument      = self.document;
		_symbolChooser.selectionString = _textView.selectionString;
	}

	if(oldDocument)
		[oldDocument close];
}

- (void)updateStyle
{
	if(theme_ptr theme = _textView.theme)
	{
		[textScrollView setBackgroundColor:[NSColor colorWithCGColor:theme->background(to_s(self.document.fileType))]];
		[textScrollView setScrollerKnobStyle:theme->is_dark() ? NSScrollerKnobStyleLight : NSScrollerKnobStyleDark];

		if(@available(macOS 10.14, *))
		{
			[_textView setIbeamCursor:NSCursor.IBeamCursor];
		}
		else
		{
			if(theme->is_dark())
			{
				NSImage* whiteIBeamImage = [NSImage imageNamed:@"IBeam white" inSameBundleAsClass:[self class]];		
				[whiteIBeamImage setSize:NSCursor.IBeamCursor.image.size];
				[_textView setIbeamCursor:[[NSCursor alloc] initWithImage:whiteIBeamImage hotSpot:NSMakePoint(4, 9)]];
			}
			else
			{
				[_textView setIbeamCursor:NSCursor.IBeamCursor];
			}
		}

		[self updateGutterViewFont:self]; // trigger update of gutter view’s line number font
		auto const& styles = theme->gutter_styles();

		gutterView.foregroundColor           = [NSColor colorWithCGColor:styles.foreground];
		gutterView.backgroundColor           = [NSColor colorWithCGColor:styles.background];
		gutterView.iconColor                 = [NSColor colorWithCGColor:styles.icons];
		gutterView.iconHoverColor            = [NSColor colorWithCGColor:styles.iconsHover];
		gutterView.iconPressedColor          = [NSColor colorWithCGColor:styles.iconsPressed];
		gutterView.selectionForegroundColor  = [NSColor colorWithCGColor:styles.selectionForeground];
		gutterView.selectionBackgroundColor  = [NSColor colorWithCGColor:styles.selectionBackground];
		gutterView.selectionIconColor        = [NSColor colorWithCGColor:styles.selectionIcons];
		gutterView.selectionIconHoverColor   = [NSColor colorWithCGColor:styles.selectionIconsHover];
		gutterView.selectionIconPressedColor = [NSColor colorWithCGColor:styles.selectionIconsPressed];
		gutterView.selectionBorderColor      = [NSColor colorWithCGColor:styles.selectionBorder];
		gutterScrollView.backgroundColor     = gutterView.backgroundColor;
		gutterDividerView.activeBackgroundColor = [NSColor colorWithCGColor:styles.divider];

		[gutterView setNeedsDisplay:YES];
	}
}

// LSP stays opt-in. One session follows the active document in this editor.
- (void)configureLSP
{
	++self.symbolSerial; self.symbolBusy = NO;
	self.textView.hoverProvider = nil;
	self.textView.lspDiagnostics = nil;
	self.textView.completionProvider = nil;
	[self.lspClient stop]; self.lspClient = nil;
	if(self.lspPanel) [self removeAuxiliaryView:self.lspPanel];
	self.lspPanel = nil;
	self.lspPath = self.document.path;
	BOOL supported = [@[@"c", @"h", @"cc", @"cpp", @"cxx", @"hpp", @"m", @"mm", @"ae"] containsObject:self.lspPath.pathExtension.lowercaseString];
	if(!supported) return;
	self.lspPanel = [[OakLSPPanel alloc] initWithFrame:NSZeroRect];
	self.lspPanel.serverName = [self.lspPath.pathExtension.lowercaseString isEqual:@"ae"] ? @"Aeon" : @"clangd";
	[self.lspPanel showState:@"Start clangd to check this file" diagnostics:@[] running:NO];
	__weak OakDocumentView* weakSelf = self;
	self.lspPanel.toggleServer = ^{
		OakDocumentView* view = weakSelf;
		view.lspEnabled = !view.lspEnabled;
		if(view.lspEnabled) [view startLSP];
		else {
			++view.symbolSerial; view.symbolBusy = NO;
			view.lspPanel.formattingEnabled = NO; view.lspPanel.formattingBusy = NO;
			view.textView.hoverProvider = nil;
			view.textView.lspDiagnostics = nil;
			view.textView.completionProvider = nil;
			[view.lspClient stop]; view.lspClient = nil;
			[view.lspPanel showState:@"Stopped · Start clangd to check this file" diagnostics:@[] running:NO];
		}
	};
	self.lspPanel.navigate = ^(NSDictionary* diagnostic, BOOL focusEditor) {
		OakDocumentView* view = weakSelf;
		[view revealLSPDiagnostic:diagnostic];
		if(focusEditor) [view.window makeFirstResponder:view.textView];
	};
	__block NSInteger actionVersion = 0;
	__block __weak OakLSPClient* actionClient = nil;
	// The panel invalidates its menu on selection, content and session changes.
	self.lspPanel.requestActions = ^(NSDictionary* diagnostic, void (^completion)(NSArray*, NSString*)) {
		OakDocumentView* view = weakSelf;
		actionVersion = view.lspClient.version;
		actionClient = view.lspClient;
		[view.lspClient codeActionsForDiagnostic:diagnostic completion:completion];
	};
	self.lspPanel.applyAction = ^(NSDictionary* action) {
		OakDocumentView* view = weakSelf;
		if(!view || !view.lspEnabled || actionClient != view.lspClient || actionVersion != view.lspClient.version) { NSBeep(); return; }
		if([action[@"command"] isKindOfClass:NSDictionary.class] && [action[@"command"][@"command"] isEqual:@"aeon.synthesize"]) {
			OakLSPClient* requestedClient = view.lspClient;
			NSInteger requestedVersion = actionVersion;
			NSAlert* consent = [NSAlert new];
			consent.messageText = @"Run synthesis?";
			consent.informativeText = [NSString stringWithFormat:@"%@\n\nThe language server chooses how this backend runs. Depending on its configuration, it may send source code to an external service and incur charges. TextMate does not classify the backend as local or remote.", action[@"title"] ?: @"Synthesis"];
			[consent addButtonWithTitle:@"Run"]; [consent addButtonWithTitle:@"Cancel"];
			[consent beginSheetModalForWindow:view.window completionHandler:^(NSModalResponse response) {
			OakDocumentView* view = weakSelf;
			if(response != NSAlertFirstButtonReturn || !view || view.lspClient != requestedClient || view.lspClient.version != requestedVersion || !view.lspEnabled) return;
			[view.lspPanel showState:@"Synthesizing… · editing cancels the result" diagnostics:view.lspPanel.diagnostics running:YES];
			[view.lspClient executeSynthesis:action completion:^(NSString* error) {
				OakDocumentView* current = weakSelf;
				if(!current) return;
				[current.lspPanel showState:error ?: @"Synthesis complete" diagnostics:current.lspPanel.diagnostics running:YES];
			}];
			}];
			return;
		}
		NSString* error = nil;
		NSString* updated = OakLSPApplyCodeAction(action, view.document.content, view.lspPath, actionVersion, &error);
		if(!updated) { NSAlert* alert = [NSAlert new]; alert.messageText = @"Cannot apply code action"; alert.informativeText = error; [alert beginSheetModalForWindow:view.window completionHandler:nil]; return; }
		[view.textView selectAll:nil];
		[view.textView insertText:updated];
		[view.window makeFirstResponder:view.textView];
	};
	[self addAuxiliaryView:self.lspPanel atEdge:NSMinYEdge];
	if(self.lspEnabled) [self startLSP];
}
- (void)startLSP
{
	if([self.lspPath.pathExtension.lowercaseString isEqual:@"ae"] && ![NSUserDefaults.standardUserDefaults stringForKey:@"LSPAeonPath"].length && ![NSUserDefaults.standardUserDefaults boolForKey:@"LSPAllowAeonUV"]) {
		if(self.aeonSetupPromptVisible) return;
		self.lspEnabled = NO;
		NSString* uv = OakLSPFindUV();
		if(!uv) { [self.lspPanel showState:@"uv not found · Install uv or set LSPAeonPath" diagnostics:@[] running:NO]; return; }
		self.aeonSetupPromptVisible = YES;
		NSString* path = self.lspPath;
		NSAlert* alert = [NSAlert new]; alert.messageText = @"Set up Aeon with uv?";
		alert.informativeText = [NSString stringWithFormat:@"TextMate will use %@ to download the latest aeonlang package and its dependencies into a private TextMate tools directory. uv may also download Python. Setup checks for updates once per app launch when you start Aeon. Your global Python environment is not changed.", uv];
		[alert addButtonWithTitle:@"Install and Start"]; [alert addButtonWithTitle:@"Cancel"];
		__weak OakDocumentView* weakSelf = self;
		[alert beginSheetModalForWindow:self.window completionHandler:^(NSModalResponse response) {
			OakDocumentView* view = weakSelf;
			view.aeonSetupPromptVisible = NO;
			if(response != NSAlertFirstButtonReturn || !view || ![view.lspPath isEqual:path]) return;
			[NSUserDefaults.standardUserDefaults setBool:YES forKey:@"LSPAllowAeonUV"];
			[view startLSP];
		}];
		return;
	}
	++self.symbolSerial; self.symbolBusy = NO;
	self.lspPanel.formattingEnabled = NO; self.lspPanel.formattingBusy = NO;
	self.textView.lspDiagnostics = nil;
	if(!self.lspPath || !self.lspPanel) return;
	[self.lspClient stop];
	self.lspEnabled = YES;
	self.lspClient = [OakLSPClient new];
	self.lspPanel.expanded = YES;
	[self.lspPanel showState:@"Starting clangd…" diagnostics:@[] running:YES];
	__weak OakDocumentView* weakSelf = self;
	self.lspClient.applyWorkspaceEdit = ^NSString*(NSDictionary* edit, NSInteger version) {
		OakDocumentView* view = weakSelf;
		if(!view || !view.lspEnabled) return @"Editor is no longer active.";
		NSString* error = nil;
		NSString* updated = OakLSPApplyCodeAction(@{@"edit":edit}, view.document.content, view.lspPath, version, &error);
		if(!updated) return error;
		[view.textView selectAll:nil]; [view.textView insertText:updated];
		[view.window makeFirstResponder:view.textView];
		return nil;
	};
	__weak OakLSPClient* completionClient = self.lspClient;
	self.textView.hoverProvider = ^(NSUInteger line, NSUInteger character, void (^reply)(NSString*)) {
		OakLSPClient* client = completionClient;
		if(client) [client hoverAtLine:line character:character completion:reply]; else reply(nil);
	};
	self.textView.completionProvider = ^(NSUInteger line, NSUInteger character, NSString* prefix, void (^reply)(NSArray<NSString*>*)) {
		OakLSPClient* client = completionClient;
		if(client) [client completionsAtLine:line character:character prefix:prefix completion:reply];
		else reply(@[]);
	};
	self.lspClient.notice = ^(NSString* message) {
		OakDocumentView* view = weakSelf;
		if(view) [view.lspPanel showState:message diagnostics:view.lspPanel.diagnostics running:YES];
		if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPAeonSynthesisTest"]) fprintf(stderr,"AEON SERVER: %s\n",message.UTF8String);
	};
	self.lspClient.changed = ^(NSString* state, NSArray* diagnostics, NSInteger version) {
		OakDocumentView* view = weakSelf;
		if(!view) return;
		BOOL failed = [state hasPrefix:@"Failed"];
		view.lspPanel.formattingEnabled = !failed && view.lspClient.supportsFormatting;
		view.textView.lspDiagnostics = failed ? nil : diagnostics;
		if(failed) { view.lspEnabled = NO; view.textView.completionProvider = nil; view.textView.hoverProvider = nil; }
		[view.lspPanel showState:state diagnostics:diagnostics running:!failed];
	};
	[self.lspClient startPath:self.lspPath content:self.document.content];
}
- (void)lspContentChanged:(NSNotification*)notification
{
	if(!self.lspClient || !self.lspEnabled) return;
	NSInteger previousVersion = self.lspClient.version;
	[self.lspClient updateContent:self.document.content];
	if(previousVersion == self.lspClient.version) { self.textView.lspDiagnostics = self.lspPanel.diagnostics; return; }
	self.textView.lspDiagnostics = nil;
	[self.lspPanel showState:@"Checking… · clangd" diagnostics:@[] running:YES];
}
- (void)lspDocumentSaved:(NSNotification*)notification
{
	if(![self.lspPath isEqualToString:self.document.path]) [self configureLSP];
}
- (IBAction)formatDocument:(id)sender
{
	if(!self.lspEnabled || !self.lspClient.supportsFormatting || self.lspPanel.formattingBusy) { NSBeep(); return; }
	OakLSPClient* client = self.lspClient;
	OakDocument* document = self.document;
	NSString* content = document.content;
	NSString* path = self.lspPath;
	NSInteger version = client.version;
	self.lspPanel.formattingBusy = YES;
	__weak OakDocumentView* weakSelf = self;
	[client formatWithTabSize:self.textView.tabSize insertSpaces:self.textView.softTabs completion:^(NSArray* edits, NSString* failure) {
		OakDocumentView* view = weakSelf;
		if(!view || view.lspClient != client || view.document != document || !view.lspEnabled) return;
		view.lspPanel.formattingBusy = NO;
		NSString* error = failure;
		if(client.version != version || ![document.content isEqual:content] || ![view.lspPath isEqual:path]) error = @"Document changed. Format again.";
		NSString* updated = nil;
		if(!error && edits.count) {
			NSDictionary* action = @{@"edit":@{@"changes":@{[NSURL fileURLWithPath:path].absoluteString:edits}}};
			updated = OakLSPApplyCodeAction(action, content, path, version, &error);
		}
		if(error) { [view.lspPanel showState:error diagnostics:view.lspPanel.diagnostics running:YES]; return; }
		if(!updated || [updated isEqual:content]) {
			[view.lspPanel showState:@"Already formatted" diagnostics:view.lspPanel.diagnostics running:YES]; return;
		}
		NSString* selection = view.textView.selectionString;
		[view.textView selectAll:nil]; [view.textView insertText:updated];
		view.textView.selectionString = selection;
		[view.window makeFirstResponder:view.textView];
	}];
}

// Strict UTF-16 → native byte-column conversion, also used for cross-file jumps.
static NSString* LSPSelection(NSString* content, NSDictionary* range)
{
	if(![range isKindOfClass:NSDictionary.class]) return nil;
	NSArray* lines = [content componentsSeparatedByString:@"\n"];
	NSMutableArray* positions = [NSMutableArray array];
	for(NSString* key in @[@"start",@"end"]) {
		NSDictionary* p = range[key];
		if(![p isKindOfClass:NSDictionary.class] || ![p[@"line"] isKindOfClass:NSNumber.class] || ![p[@"character"] isKindOfClass:NSNumber.class]) return nil;
		NSInteger line = [p[@"line"] integerValue], column = [p[@"character"] integerValue];
		if(line < 0 || line >= lines.count || column < 0 || column > [lines[line] length]) return nil;
		NSString* text = lines[line];
		if(column > 0 && column < text.length && CFStringIsSurrogateHighCharacter([text characterAtIndex:column-1]) && CFStringIsSurrogateLowCharacter([text characterAtIndex:column])) return nil;
		[positions addObject:[NSString stringWithFormat:@"%ld:%lu",line+1,[[text substringToIndex:column] lengthOfBytesUsingEncoding:NSUTF8StringEncoding]+1]];
	}
	return [positions componentsJoinedByString:@"-"];
}
- (void)showLSPSymbolMessage:(NSString*)message
{
	if([NSUserDefaults.standardUserDefaults boolForKey:@"LSPSymbolTest"]) fprintf(stderr,"SYMBOL STATUS: %s\n",message.UTF8String);
	[self.lspPanel showState:message diagnostics:self.lspPanel.diagnostics running:self.lspEnabled];
}
- (void)openDefinitionChoice:(id)sender
{
	NSDictionary* location = [sender representedObject];
	NSURL* url = [NSURL URLWithString:location[@"uri"] ?: location[@"targetUri"] ?: @""];
	if(!url.isFileURL || (url.host.length && ![url.host isEqual:@"localhost"])) { [self showLSPSymbolMessage:@"Only local-file definitions can be opened."]; return; }
	NSDictionary* range = location[@"targetSelectionRange"] ?: location[@"range"];
	OakDocument* target = [OakDocumentController.sharedInstance documentWithPath:url.path];
	__weak OakDocumentView* weakSelf = self;
	[target loadModalForWindow:self.window completionHandler:^(OakDocumentIOResult result, NSString* error, oak::uuid_t const&) {
		OakDocumentView* view = weakSelf;
		if(!view) return;
		if(result != OakDocumentIOResultSuccess) { [view showLSPSymbolMessage:error ?: @"Could not open definition."]; return; }
		NSString* selection = LSPSelection(target.content,range);
		if(!selection) { [view showLSPSymbolMessage:@"The server returned an invalid definition range."]; return; }
		if(target == view.document) { [view selectAndCenter:selection]; [view.window makeFirstResponder:view.textView]; }
		else [OakDocumentController.sharedInstance showDocument:target andSelect:text::range_t(to_s(selection)) inProject:nil bringToFront:YES];
	}];
}
- (IBAction)goToDefinition:(id)sender
{
	NSDictionary* position = self.textView.lspSymbolPosition;
	if(!self.lspEnabled || !self.lspClient.supportsDefinition || self.symbolBusy || !position) { NSBeep(); return; }
	NSUInteger serial = ++self.symbolSerial; self.symbolBusy = YES;
	NSString* selection = self.textView.selectionString;
	__weak OakDocumentView* weakSelf = self;
	[self.lspClient definitionsAtLine:[position[@"line"] unsignedIntegerValue] character:[position[@"character"] unsignedIntegerValue] completion:^(NSArray* locations, NSString* error) {
		OakDocumentView* view = weakSelf;
		if(!view || view.symbolSerial != serial) return;
		view.symbolBusy = NO;
		if(![selection isEqual:view.textView.selectionString]) return;
		if(error || !locations.count) { [view showLSPSymbolMessage:error ?: @"No definition found."]; return; }
		NSMenu* menu = [[NSMenu alloc] initWithTitle:@"Definitions"];
		for(NSDictionary* location in locations) {
			NSString* uri = location[@"uri"] ?: location[@"targetUri"];
			NSDictionary* range = location[@"targetSelectionRange"] ?: location[@"range"];
			NSMenuItem* item = [[NSMenuItem alloc] initWithTitle:[NSString stringWithFormat:@"%@:%lu",[NSURL URLWithString:uri].path ?: uri,[range[@"start"][@"line"] unsignedIntegerValue]+1] action:@selector(openDefinitionChoice:) keyEquivalent:@""];
			item.target = view; item.representedObject = location; [menu addItem:item];
		}
		if(menu.numberOfItems == 1) [view openDefinitionChoice:menu.itemArray.firstObject];
		else [menu popUpMenuPositioningItem:nil atLocation:[view.textView convertPoint:[view.window convertPointFromScreen:view.textView.positionForWindowUnderCaret] fromView:nil] inView:view.textView];
	}];
}

- (void)applyRenameEdit:(NSDictionary*)edit source:(OakDocument*)source content:(NSString*)content version:(NSInteger)version serial:(NSUInteger)serial
{
	auto reject = [&](NSString* reason) { self.symbolBusy = NO; [self showLSPSymbolMessage:reason]; };
	if(!edit || (!edit[@"changes"] && !edit[@"documentChanges"])) { reject(@"Rename returned no edits."); return; }
	if(edit[@"changeAnnotations"] || (edit[@"changes"] && edit[@"documentChanges"])) { reject(@"Annotated or ambiguous rename edits are not supported."); return; }
	NSMutableDictionary* files = [NSMutableDictionary dictionary];
	for(NSString* uri in edit[@"changes"]) files[uri] = edit[@"changes"][uri];
	for(NSDictionary* change in edit[@"documentChanges"]) {
		NSDictionary* document = change[@"textDocument"];
		if(change[@"kind"] || !document || files[document[@"uri"]]) { reject(@"Rename file operations or duplicate file edits are not supported."); return; }
		id v = document[@"version"];
		if(v && v != NSNull.null && (![document[@"uri"] isEqual:[NSURL fileURLWithPath:source.path].absoluteString] || [v integerValue] != version)) { reject(@"Rename targets an unknown or stale document version."); return; }
		files[document[@"uri"]] = change[@"edits"];
	}
	if(!files.count) { reject(@"Rename returned no edits."); return; }
	NSMutableArray* targets = [NSMutableArray array]; NSMutableSet* paths = [NSMutableSet set]; NSMutableSet* documentIDs = [NSMutableSet set];
	for(NSString* uri in files) {
		NSURL* url = [NSURL URLWithString:uri]; NSString* path = url.path.stringByStandardizingPath;
		if(!url.isFileURL || !path.length || (url.host.length && ![url.host isEqual:@"localhost"]) || [paths containsObject:path]) { reject(@"Rename requires distinct local files."); return; }
		[paths addObject:path];
		OakDocument* document = [OakDocumentController.sharedInstance documentWithPath:path];
		if([documentIDs containsObject:document.identifier]) { reject(@"Rename contains aliases for the same file; no changes applied."); return; }
		[documentIDs addObject:document.identifier];
		if(document.inViewingMode || (document != source && document.documentEdited)) { reject(@"Save other modified target files before renaming; no changes applied."); return; }
		[targets addObject:[@{@"document":document,@"uri":uri} mutableCopy]];
	}
	__weak OakDocumentView* weakSelf = self;
	__block NSUInteger next = 0;
	__block void (^loadNext)(void);
	loadNext = ^{
		OakDocumentView* view = weakSelf;
		if(!view || view.symbolSerial != serial) { loadNext = nil; return; }
		void (^fail)(NSString*) = ^(NSString* reason) { view.symbolBusy = NO; [view showLSPSymbolMessage:reason]; loadNext = nil; };
		if(view.document != source || view.lspClient.version != version || ![source.content isEqual:content]) { fail(@"Document changed. Rename again."); return; }
		if(next < targets.count) {
			NSMutableDictionary* target = targets[next++]; OakDocument* document = target[@"document"];
			[document loadModalForWindow:view.window completionHandler:^(OakDocumentIOResult result, NSString* error, oak::uuid_t const&) {
				if(result != OakDocumentIOResultSuccess) { weakSelf.symbolBusy = NO; [weakSelf showLSPSymbolMessage:error ?: @"Could not load rename target."]; loadNext = nil; return; }
				if(document != source && document.documentEdited) { weakSelf.symbolBusy = NO; [weakSelf showLSPSymbolMessage:@"A target has unsaved changes. Save it and rename again."]; loadNext = nil; return; }
				NSString* snapshot = document.content;
				NSString* validationError = nil;
				NSString* updated = OakLSPApplyCodeAction(@{@"edit":@{@"changes":@{target[@"uri"]:files[target[@"uri"]]}}},snapshot,document.path,version,&validationError);
				if(!updated) { weakSelf.symbolBusy = NO; [weakSelf showLSPSymbolMessage:validationError]; loadNext = nil; return; }
				target[@"before"] = snapshot; target[@"after"] = updated;
				if(loadNext) loadNext();
			}];
			return;
		}
		void (^apply)(BOOL) = ^(BOOL accepted) {
			OakDocumentView* current = weakSelf;
			if(!current || current.symbolSerial != serial) return;
			current.symbolBusy = NO;
			if(!accepted) return;
			if(current.document != source || current.lspClient.version != version || ![source.content isEqual:content]) { [current showLSPSymbolMessage:@"Document changed. Rename again."]; return; }
			for(NSDictionary* target in targets) {
				OakDocument* document = target[@"document"];
				if(!document.loaded || document.inViewingMode || ![document.content isEqual:target[@"before"]]) { [current showLSPSymbolMessage:@"A target file changed. No rename edits applied."]; return; }
			}
			// Every loaded target is validated before the first synchronous edit.
			for(NSDictionary* target in targets) {
				OakDocument* document = target[@"document"];
				std::multimap<std::pair<size_t,size_t>,std::string> replacements;
				replacements.emplace(std::make_pair(0,[target[@"before"] lengthOfBytesUsingEncoding:NSUTF8StringEncoding]),to_s(target[@"after"]));
				[document performReplacements:replacements checksum:0];
			}
			if(targets.count > 1) [OakDocumentController.sharedInstance showDocuments:[targets valueForKey:@"document"]];
			[current showLSPSymbolMessage:[NSString stringWithFormat:@"Renamed in %lu file(s) · unsaved · Undo in each file",targets.count]];
		};
		if(targets.count == 1) apply(YES);
		else {
			NSAlert* alert = [NSAlert new]; alert.messageText = [NSString stringWithFormat:@"Rename in %lu files?",targets.count];
			NSMutableArray* names = [NSMutableArray array]; for(NSDictionary* target in targets) [names addObject:[target[@"document"] path]];
			alert.informativeText = [[names componentsJoinedByString:@"\n"] stringByAppendingString:@"\n\nChanges remain unsaved. Undo is per file."];
			[alert addButtonWithTitle:@"Rename"]; [alert addButtonWithTitle:@"Cancel"];
			[alert beginSheetModalForWindow:view.window completionHandler:^(NSModalResponse response) { apply(response == NSAlertFirstButtonReturn); }];
		}
		loadNext = nil;
	};
	loadNext();
}

- (IBAction)renameSymbol:(id)sender
{
	NSDictionary* position = self.textView.lspSymbolPosition;
	if(!self.lspEnabled || !self.lspClient.supportsRename || self.symbolBusy || !position || self.document.inViewingMode) { NSBeep(); return; }
	NSUInteger serial = ++self.symbolSerial; self.symbolBusy = YES;
	OakDocument* source = self.document; NSString* content = source.content; NSString* selection = self.textView.selectionString;
	NSInteger version = self.lspClient.version;
	__weak OakDocumentView* weakSelf = self;
	[self.lspClient prepareRenameAtLine:[position[@"line"] unsignedIntegerValue] character:[position[@"character"] unsignedIntegerValue] completion:^(NSDictionary* prepared, NSString* error) {
		OakDocumentView* view = weakSelf;
		if(!view || view.symbolSerial != serial) return;
		if(error || !prepared || ![selection isEqual:view.textView.selectionString]) { view.symbolBusy = NO; if(error) [view showLSPSymbolMessage:error]; return; }
		NSDictionary* renameRange = prepared[@"range"] ?: (prepared[@"start"] ? prepared : nil);
		if((renameRange && !LSPSelection(content,renameRange)) || (prepared[@"defaultBehavior"] && ![prepared[@"defaultBehavior"] boolValue])) { view.symbolBusy = NO; [view showLSPSymbolMessage:@"This symbol cannot be renamed."]; return; }
		NSAlert* alert = [NSAlert new]; alert.messageText = @"Rename Symbol"; alert.informativeText = @"Enter the new name. The language server will find references to update.";
		NSTextField* input = [[NSTextField alloc] initWithFrame:NSMakeRect(0,0,360,24)]; input.stringValue = prepared[@"placeholder"] ?: position[@"word"] ?: @"";
		input.accessibilityLabel = @"New symbol name"; alert.accessoryView = input;
		[alert addButtonWithTitle:@"Rename"]; [alert addButtonWithTitle:@"Cancel"];
		[alert beginSheetModalForWindow:view.window completionHandler:^(NSModalResponse response) {
			OakDocumentView* current = weakSelf;
			if(!current || current.symbolSerial != serial) return;
			if(response != NSAlertFirstButtonReturn) { current.symbolBusy = NO; return; }
			NSString* name = input.stringValue;
			if(!name.length || [name rangeOfCharacterFromSet:NSCharacterSet.whitespaceAndNewlineCharacterSet].location != NSNotFound) { current.symbolBusy = NO; [current showLSPSymbolMessage:@"Enter a nonempty symbol name without whitespace."]; return; }
			if(current.document != source || current.lspClient.version != version || ![source.content isEqual:content]) { current.symbolBusy = NO; [current showLSPSymbolMessage:@"Document changed. Rename again."]; return; }
			[current.lspClient renameAtLine:[position[@"line"] unsignedIntegerValue] character:[position[@"character"] unsignedIntegerValue] newName:name completion:^(NSDictionary* edit, NSString* failure) {
				OakDocumentView* editor = weakSelf;
				if(!editor || editor.symbolSerial != serial) return;
				if(failure) { editor.symbolBusy = NO; [editor showLSPSymbolMessage:failure]; return; }
				[editor applyRenameEdit:edit source:source content:content version:version serial:serial];
			}];
		}];
		[alert.window makeFirstResponder:input]; [input selectText:nil];
	}];
}
- (void)revealLSPDiagnostic:(NSDictionary*)diagnostic
{
	NSArray<NSString*>* lines = [self.document.content componentsSeparatedByString:@"\n"];
	auto position = [&](NSString* lineKey, NSString* columnKey) {
		NSUInteger line = MIN([diagnostic[lineKey] unsignedIntegerValue], lines.count-1);
		NSString* text = lines[line];
		NSUInteger utf16 = MIN([diagnostic[columnKey] unsignedIntegerValue], text.length);
		NSUInteger byteColumn = [[text substringToIndex:utf16] lengthOfBytesUsingEncoding:NSUTF8StringEncoding];
		return [NSString stringWithFormat:@"%lu:%lu", line+1, byteColumn+1];
	};
	[self selectAndCenter:position(@"line", @"column")];
}

- (IBAction)toggleLineNumbers:(id)sender
{
	BOOL isVisibleFlag = ![gutterView visibilityForColumnWithIdentifier:GVLineNumbersColumnIdentifier];
	[gutterView setVisibility:isVisibleFlag forColumnWithIdentifier:GVLineNumbersColumnIdentifier];
	if(isVisibleFlag)
			[NSUserDefaults.standardUserDefaults removeObjectForKey:@"DocumentView Disable Line Numbers"];
	else	[NSUserDefaults.standardUserDefaults setObject:@YES forKey:@"DocumentView Disable Line Numbers"];
}

- (BOOL)validateMenuItem:(NSMenuItem*)aMenuItem
{
	if(aMenuItem.action == @selector(goToDefinition:)) return self.lspEnabled && self.lspClient.supportsDefinition && !self.symbolBusy && self.textView.lspSymbolPosition != nil;
	if(aMenuItem.action == @selector(renameSymbol:)) return self.lspEnabled && self.lspClient.supportsRename && !self.symbolBusy && self.textView.lspSymbolPosition != nil && !self.document.inViewingMode;
	if(aMenuItem.action == @selector(formatDocument:)) return self.lspEnabled && self.lspClient.supportsFormatting && !self.lspPanel.formattingBusy;
	if([aMenuItem action] == @selector(toggleLineNumbers:))
		[aMenuItem setTitle:[gutterView visibilityForColumnWithIdentifier:GVLineNumbersColumnIdentifier] ? @"Hide Line Numbers" : @"Show Line Numbers"];
	else if([aMenuItem action] == @selector(takeTabSizeFrom:))
		[aMenuItem setState:_textView.tabSize == [aMenuItem tag] ? NSControlStateValueOn : NSControlStateValueOff];
	else if([aMenuItem action] == @selector(showTabSizeSelectorPanel:))
	{
		static NSInteger const predefined[] = { 2, 3, 4, 8 };
		if(oak::contains(std::begin(predefined), std::end(predefined), _textView.tabSize))
		{
			[aMenuItem setTitle:@"Other…"];
			[aMenuItem setState:NSControlStateValueOff];
		}
		else
		{
			[aMenuItem setDynamicTitle:[NSString stringWithFormat:@"Other (%zd)…", _textView.tabSize]];
			[aMenuItem setState:NSControlStateValueOn];
		}
	}
	else if([aMenuItem action] == @selector(setIndentWithTabs:))
		[aMenuItem setState:_textView.softTabs ? NSControlStateValueOff : NSControlStateValueOn];
	else if([aMenuItem action] == @selector(setIndentWithSpaces:))
		[aMenuItem setState:_textView.softTabs ? NSControlStateValueOn : NSControlStateValueOff];
	else if([aMenuItem action] == @selector(takeGrammarUUIDFrom:))
	{
		NSString* uuidString = [aMenuItem representedObject];
		if(bundles::item_ptr bundleItem = bundles::lookup(to_s(uuidString)))
		{
			bool selectedGrammar = to_s(self.document.fileType) == bundleItem->value_for_field(bundles::kFieldGrammarScope);
			[aMenuItem setState:selectedGrammar ? NSControlStateValueOn : NSControlStateValueOff];
		}
	}
	return YES;
}

// ===================
// = Auxiliary Views =
// ===================

- (void)addAuxiliaryView:(NSView*)aView atEdge:(NSRectEdge)anEdge
{
	topAuxiliaryViews    = topAuxiliaryViews    ?: [NSMutableArray new];
	bottomAuxiliaryViews = bottomAuxiliaryViews ?: [NSMutableArray new];
	if(anEdge == NSMinYEdge)
			[bottomAuxiliaryViews addObject:aView];
	else	[topAuxiliaryViews addObject:aView];
	OakAddAutoLayoutViewsToSuperview(@[ aView ], self);
	[self setNeedsUpdateConstraints:YES];
}

- (void)removeAuxiliaryView:(NSView*)aView
{
	if([topAuxiliaryViews containsObject:aView])
		[topAuxiliaryViews removeObject:aView];
	else if([bottomAuxiliaryViews containsObject:aView])
		[bottomAuxiliaryViews removeObject:aView];
	else
		return;
	[aView removeFromSuperview];
	[self setNeedsUpdateConstraints:YES];
}

// ======================
// = Pasteboard History =
// ======================

- (void)showClipboardHistory:(id)sender
{
	OakPasteboardChooser* chooser = [OakPasteboardChooser sharedChooserForPasteboard:OakPasteboard.generalPasteboard];
	chooser.action = @selector(paste:);
	[chooser showWindowRelativeToFrame:[self.window convertRectToScreen:[_textView convertRect:[_textView visibleRect] toView:nil]]];
}

- (void)showFindHistory:(id)sender
{
	OakPasteboardChooser* chooser = [OakPasteboardChooser sharedChooserForPasteboard:OakPasteboard.findPasteboard];
	chooser.action          = @selector(findNext:);
	chooser.alternateAction = @selector(orderFrontFindPanelForProject:);
	[chooser showWindowRelativeToFrame:[self.window convertRectToScreen:[_textView convertRect:[_textView visibleRect] toView:nil]]];
}

// ==================
// = Symbol Chooser =
// ==================

- (void)selectAndCenter:(NSString*)aSelectionString
{
	_textView.selectionString = aSelectionString;
	[_textView centerSelectionInVisibleArea:self];
}

- (void)setSymbolChooser:(SymbolChooser*)aSymbolChooser
{
	if(_symbolChooser == aSymbolChooser)
		return;

	if(_symbolChooser)
	{
		[NSNotificationCenter.defaultCenter removeObserver:self name:NSWindowWillCloseNotification object:_symbolChooser.window];

		_symbolChooser.target     = nil;
		_symbolChooser.TMDocument = nil;
	}

	if(_symbolChooser = aSymbolChooser)
	{
		_symbolChooser.target          = self;
		_symbolChooser.action          = @selector(symbolChooserDidSelectItems:);
		_symbolChooser.filterString    = @"";
		_symbolChooser.TMDocument      = self.document;
		_symbolChooser.selectionString = _textView.selectionString;

		[NSNotificationCenter.defaultCenter addObserver:self selector:@selector(symbolChooserWillClose:) name:NSWindowWillCloseNotification object:_symbolChooser.window];
	}
}

- (void)symbolChooserWillClose:(NSNotification*)aNotification
{
	self.symbolChooser = nil;
}

- (IBAction)showSymbolChooser:(id)sender
{
	self.symbolChooser = SymbolChooser.sharedInstance;
	[self.symbolChooser showWindowRelativeToFrame:[self.window convertRectToScreen:[_textView convertRect:[_textView visibleRect] toView:nil]]];
}

- (void)symbolChooserDidSelectItems:(id)sender
{
	for(id item in [sender selectedItems])
		[self selectAndCenter:[item selectionString]];
}

// =======================
// = Status bar delegate =
// =======================

- (void)takeGrammarUUIDFrom:(id)sender
{
	if(bundles::item_ptr item = bundles::lookup(to_s([sender representedObject])))
		[_textView performBundleItem:item];
}

- (void)goToSymbol:(id)sender
{
	[self selectAndCenter:[sender representedObject]];
}

- (void)showSymbolSelector:(NSPopUpButton*)symbolPopUp
{
	NSMenu* symbolMenu = symbolPopUp.menu;
	[symbolMenu removeAllItems];

	text::selection_t sel(to_s(_textView.selectionString));
	text::pos_t caret = sel.last().max();

	__block NSInteger index = 0;
	[self.document enumerateSymbolsUsingBlock:^(text::pos_t const& pos, NSString* symbol){
		if([symbol isEqualToString:@"-"])
		{
			[symbolMenu addItem:[NSMenuItem separatorItem]];
		}
		else
		{
			NSUInteger indent = 0;
			while(indent < symbol.length && [symbol characterAtIndex:indent] == 0x2003) // Em-space
				++indent;

			NSMenuItem* item = [symbolMenu addItemWithTitle:[symbol substringFromIndex:indent] action:@selector(goToSymbol:) keyEquivalent:@""];
			[item setIndentationLevel:indent];
			[item setTarget:self];
			[item setRepresentedObject:to_ns(pos)];
		}

		if(pos <= caret)
			++index;
	}];

	if(symbolMenu.numberOfItems == 0)
		[symbolMenu addItemWithTitle:@"No symbols to show for current document." action:@selector(nop:) keyEquivalent:@""];

	[symbolPopUp selectItemAtIndex:(index ? index-1 : 0)];
}

- (void)showBundlesMenu:(id)sender
{
	if(!self.statusBar)
		return NSBeep();

	[NSApp sendAction:_cmd to:self.statusBar from:self];
}

- (void)showBundleItemSelector:(NSPopUpButton*)bundleItemsPopUp
{
	NSMenu* bundleItemsMenu = bundleItemsPopUp.menu;
	[bundleItemsMenu removeAllItems];

	std::multimap<std::string, bundles::item_ptr, text::less_t> ordered;
	for(auto item : bundles::query(bundles::kFieldAny, NULL_STR, scope::wildcard, bundles::kItemTypeBundle))
		ordered.emplace(item->name(), item);

	NSMenuItem* selectedItem = nil;
	for(auto pair : ordered)
	{
		bool selectedGrammar = false;
		for(auto item : bundles::query(bundles::kFieldGrammarScope, to_s(self.document.fileType), scope::wildcard, bundles::kItemTypeGrammar, pair.second->uuid(), true, true))
			selectedGrammar = true;
		if(!selectedGrammar && pair.second->hidden_from_user() || pair.second->menu().empty())
			continue;

		NSMenuItem* menuItem = [bundleItemsMenu addItemWithTitle:[NSString stringWithCxxString:pair.first] action:NULL keyEquivalent:@""];
		menuItem.submenu = [[NSMenu alloc] initWithTitle:[NSString stringWithCxxString:pair.second->uuid()]];
		menuItem.submenu.delegate = BundleMenuDelegate.sharedInstance;

		if(selectedGrammar)
		{
			[menuItem setState:NSControlStateValueOn];
			selectedItem = menuItem;
		}
	}

	if(ordered.empty())
		[bundleItemsMenu addItemWithTitle:@"No Bundles Loaded" action:@selector(nop:) keyEquivalent:@""];

	if(selectedItem)
		[bundleItemsPopUp selectItem:selectedItem];
}

- (NSUInteger)tabSize
{
	return _textView.tabSize;
}

- (void)setTabSize:(NSUInteger)newTabSize
{
	_textView.tabSize = newTabSize;
	settings_t::set(kSettingsTabSizeKey, (size_t)newTabSize, to_s(self.document.fileType));
}

- (IBAction)takeTabSizeFrom:(id)sender
{
	ASSERT([sender respondsToSelector:@selector(tag)]);
	if([sender tag] > 0)
		self.tabSize = [sender tag];
}

- (IBAction)setIndentWithSpaces:(id)sender
{
	_textView.softTabs = YES;
	settings_t::set(kSettingsSoftTabsKey, true, to_s(self.document.fileType));
}

- (IBAction)setIndentWithTabs:(id)sender
{
	_textView.softTabs = NO;
	settings_t::set(kSettingsSoftTabsKey, false, to_s(self.document.fileType));
}

- (IBAction)showTabSizeSelectorPanel:(id)sender
{
	if(!tabSizeSelectorPanel)
		[[NSBundle bundleForClass:[self class]] loadNibNamed:@"TabSizeSetting" owner:self topLevelObjects:NULL];
	[tabSizeSelectorPanel makeKeyAndOrderFront:self];
}

- (void)toggleMacroRecording:(id)sender    { [_textView toggleMacroRecording:sender]; }

// =============================
// = GutterView Delegate Proxy =
// =============================

- (GVLineRecord)lineRecordForPosition:(CGFloat)yPos                              { return [_textView lineRecordForPosition:yPos];               }
- (GVLineRecord)lineFragmentForLine:(NSUInteger)aLine column:(NSUInteger)aColumn { return [_textView lineFragmentForLine:aLine column:aColumn]; }

// =========================
// = GutterView DataSource =
// =========================

- (CGFloat)widthForColumnWithIdentifier:(id)columnIdentifier
{
	return floor((self.lineHeight-1) / 2) * 2 + 1;
}

- (NSImage*)imageForLine:(NSUInteger)lineNumber inColumnWithIdentifier:(id)columnIdentifier state:(GutterViewRowState)rowState
{
	if([columnIdentifier isEqualToString:kBookmarksColumnIdentifier])
	{
		__block std::map<size_t, NSString*> gutterImageName;

		[self.document enumerateBookmarksAtLine:lineNumber block:^(text::pos_t const& pos, NSString* type, NSString* payload){
			if(payload.length != 0)
				gutterImageName.emplace(0, type);
			else if([type isEqualToString:OakDocumentBookmarkIdentifier])
				gutterImageName.emplace(1, rowState != GutterViewRowStateRegular ? @"Bookmark Hover Remove Template" : @"Bookmark Template");
			else if(rowState == GutterViewRowStateRegular)
				gutterImageName.emplace(2, type);
		}];

		if(rowState != GutterViewRowStateRegular)
			gutterImageName.emplace(3, @"Bookmark Hover Add Template");

		if(!gutterImageName.empty())
			return [self gutterImage:gutterImageName.begin()->second];
	}
	else if([columnIdentifier isEqualToString:kFoldingsColumnIdentifier])
	{
		switch([_textView foldingStateForLine:lineNumber])
		{
			case kFoldingTop:       return [self gutterImage:rowState == GutterViewRowStateRegular ? @"Folding Top Template"       : @"Folding Top Hover Template"];
			case kFoldingCollapsed: return [self gutterImage:rowState == GutterViewRowStateRegular ? @"Folding Collapsed Template" : @"Folding Collapsed Hover Template"];
			case kFoldingBottom:    return [self gutterImage:rowState == GutterViewRowStateRegular ? @"Folding Bottom Template"    : @"Folding Bottom Hover Template"];
		}
	}
	return nil;
}

// =============================
// = Bookmark Submenu Delegate =
// =============================

- (void)takeBookmarkFrom:(id)sender
{
	if([sender respondsToSelector:@selector(representedObject)])
		[self selectAndCenter:[sender representedObject]];
}

- (void)updateBookmarksMenu:(NSMenu*)aMenu
{
	[self.document enumerateBookmarksUsingBlock:^(text::pos_t const& pos, NSString* excerpt){
		NSString* prefix = to_ns(text::pad(pos.line+1, 4) + ": ");
		NSMenuItem* item = [aMenu addItemWithTitle:[prefix stringByAppendingString:excerpt] action:@selector(takeBookmarkFrom:) keyEquivalent:@""];
		[item setRepresentedObject:to_ns(pos)];
	}];

	BOOL hasBookmarks = aMenu.numberOfItems;
	if(hasBookmarks)
		[aMenu addItem:[NSMenuItem separatorItem]];
	[aMenu addItemWithTitle:@"Clear Bookmarks" action:hasBookmarks ? @selector(clearAllBookmarks:) : @selector(nop:) keyEquivalent:@""];
}

// =======================
// = GutterView Delegate =
// =======================

- (void)userDidClickColumnWithIdentifier:(id)columnIdentifier atLine:(NSUInteger)lineNumber
{
	if([columnIdentifier isEqualToString:kBookmarksColumnIdentifier])
	{
		__block std::vector<text::pos_t> bookmarks;
		__block NSMutableArray* content = [NSMutableArray array];

		[self.document enumerateBookmarksAtLine:lineNumber block:^(text::pos_t const& pos, NSString* type, NSString* payload){
			if(payload.length != 0)
				[content addObject:payload];
			else if([type isEqualToString:OakDocumentBookmarkIdentifier])
				bookmarks.push_back(pos);
		}];

		if(content.count == 0)
		{
			if(bookmarks.empty())
					[self.document setMarkOfType:OakDocumentBookmarkIdentifier atPosition:text::pos_t(lineNumber, 0) content:nil];
			else	[self.document removeMarkOfType:OakDocumentBookmarkIdentifier atPosition:bookmarks.front()];
		}
		else
		{
			NSView* popoverContainerView = [[NSView alloc] initWithFrame:NSZeroRect];

			NSTextField* textField = OakCreateLabel([content componentsJoinedByString:@"\n"]);
			OakAddAutoLayoutViewsToSuperview(@[ textField ], popoverContainerView);

			NSDictionary* views = NSDictionaryOfVariableBindings(textField);
			[popoverContainerView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-(5)-[textField]-(5)-|" options:0 metrics:0 views:views]];
			[popoverContainerView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-(10)-[textField]-(10)-|" options:0 metrics:0 views:views]];

			NSViewController* viewController = [NSViewController new];
			viewController.view = popoverContainerView;

			NSPopover* popover = [NSPopover new];
			popover.behavior = NSPopoverBehaviorTransient;
			popover.contentViewController = viewController;

			GVLineRecord record = [self lineFragmentForLine:lineNumber column:0];
			NSRect rect = NSMakeRect(0, record.firstY, [self widthForColumnWithIdentifier:columnIdentifier], record.lastY - record.firstY);
			[popover showRelativeToRect:rect ofView:gutterView preferredEdge:NSMaxXEdge];
		}
	}
	else if([columnIdentifier isEqualToString:kFoldingsColumnIdentifier])
	{
		[_textView toggleFoldingAtLine:lineNumber recursive:OakIsAlternateKeyOrMouseEvent()];
		[NSNotificationCenter.defaultCenter postNotificationName:GVColumnDataSourceDidChange object:self];
	}
}

- (void)clearAllBookmarks:(id)sender
{
	[self.document removeAllMarksOfType:OakDocumentBookmarkIdentifier];
}

- (void)documentMarksDidChange:(NSNotification*)aNotification
{
	[NSNotificationCenter.defaultCenter postNotificationName:GVColumnDataSourceDidChange object:self];
}

// ============
// = Printing =
// ============

- (void)printDocument:(id)sender
{
	[self.document runPrintOperationModalForWindow:self.window fontName:_textView.font.fontName];
}
@end
