#import <Foundation/Foundation.h>

// Common standalone/Homebrew locations, followed by absolute PATH entries.
NSString* OakLSPFindUV(void);

// Nearest ancestor containing libraries/, bounded by a project/repository marker.
NSString* OakLSPAeonProjectRoot(NSString* documentPath);

// Validate the complete action before modifying the editor. nil means rejection.
NSString* OakLSPApplyCodeAction(NSDictionary* action, NSString* content, NSString* path, NSInteger version, NSString** error);

// Call on the main thread. Results are delivered on the main thread.
@interface OakLSPClient : NSObject
@property (nonatomic, copy) void (^changed)(NSString* state, NSArray<NSDictionary*>* diagnostics, NSInteger version);
@property (nonatomic, readonly) NSInteger version;
@property (nonatomic, readonly) NSInteger processIdentifier;
@property (nonatomic, readonly) BOOL supportsFormatting;
@property (nonatomic, readonly) BOOL supportsDefinition;
@property (nonatomic, readonly) BOOL supportsRename;
- (void)definitionsAtLine:(NSUInteger)line character:(NSUInteger)character completion:(void (^)(NSArray<NSDictionary*>*, NSString*))completion;
- (void)prepareRenameAtLine:(NSUInteger)line character:(NSUInteger)character completion:(void (^)(NSDictionary*, NSString*))completion;
- (void)renameAtLine:(NSUInteger)line character:(NSUInteger)character newName:(NSString*)name completion:(void (^)(NSDictionary*, NSString*))completion;
- (void)formatWithTabSize:(NSUInteger)tabSize insertSpaces:(BOOL)insertSpaces completion:(void (^)(NSArray<NSDictionary*>*, NSString*))completion;
@property (nonatomic, copy) NSString* (^applyWorkspaceEdit)(NSDictionary* edit, NSInteger version);
@property (nonatomic, copy) void (^notice)(NSString* message);
- (void)executeSynthesis:(NSDictionary*)action completion:(void (^)(NSString*))completion;
- (void)startPath:(NSString*)path content:(NSString*)content;
- (void)updateContent:(NSString*)content;
- (void)codeActionsForDiagnostic:(NSDictionary*)diagnostic completion:(void (^)(NSArray*, NSString*))completion;
- (void)completionsAtLine:(NSUInteger)line character:(NSUInteger)character prefix:(NSString*)prefix completion:(void (^)(NSArray<NSString*>*))completion;
- (void)stop;
- (void)hoverAtLine:(NSUInteger)line character:(NSUInteger)character completion:(void (^)(NSString*))completion;
@end
