extern NSUInteger const OakChoiceMenuKeyUnused;
extern NSUInteger const OakChoiceMenuKeyReturn;
extern NSUInteger const OakChoiceMenuKeyTab;
extern NSUInteger const OakChoiceMenuKeyCancel;
extern NSUInteger const OakChoiceMenuKeyMovement;

@interface OakChoiceMenu : NSWindowController
@property (nonatomic) NSArray* choices;
@property (nonatomic) NSUInteger choiceIndex;
@property (nonatomic, readonly) NSString* selectedChoice;
@property (nonatomic) NSFont* font;
// Optional mouse acceptance; snippet choices retain their keyboard-only behavior.
@property (nonatomic, copy) void (^choiceAccepted)(NSUInteger index);
- (void)showAtTopLeftPoint:(NSPoint)aPoint forView:(NSView*)aView;
- (BOOL)isVisible;
- (NSUInteger)didHandleKeyEvent:(NSEvent*)anEvent;
@end
