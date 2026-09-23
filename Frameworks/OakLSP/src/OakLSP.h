#import <Foundation/Foundation.h>

// Verifies the vendored LSP types/serialization and Cocoa bridge without
// starting the editor or a language server. Throws on a failed check.
NSString* OakLSPBuildCheck ();
