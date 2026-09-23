#import <Cocoa/Cocoa.h>

@interface OakLSPPanel : NSView <NSTableViewDataSource, NSTableViewDelegate>
@property (nonatomic, copy) void (^toggleServer)(void);
@property (nonatomic) BOOL formattingEnabled;
@property (nonatomic) BOOL formattingBusy;
@property (nonatomic, copy) void (^navigate)(NSDictionary* diagnostic, BOOL focusEditor);
@property (nonatomic, copy) void (^requestActions)(NSDictionary* diagnostic, void (^completion)(NSArray*, NSString*));
@property (nonatomic, copy) void (^applyAction)(NSDictionary* action);
@property (nonatomic, readonly) NSArray<NSDictionary*>* diagnostics;
@property (nonatomic) BOOL expanded;
@property (nonatomic, copy) NSString* serverName;
- (void)showState:(NSString*)state diagnostics:(NSArray*)diagnostics running:(BOOL)running;
- (void)selectDiagnosticAtLine:(NSUInteger)line;
@end
