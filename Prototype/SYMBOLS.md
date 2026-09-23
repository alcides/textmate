# LSP symbol commands

- **Navigate → Go to Definition**, **F12** (Fn–F12 if macOS uses media keys).
- **Text → Rename Symbol…**, **Option–Shift–Command–R** (⌥⇧⌘R).

Start the language server and place one caret in the symbol, or select it.
Commands are enabled according to the server's advertised capabilities. Existing
F2 bookmark shortcuts and Option–Command–R search shortcuts are unchanged.

Definition handles Location, arrays of Locations, and LocationLink arrays. A
single destination opens directly; multiple destinations appear in a choice
menu. Cross-file results load through TextMate's document controller and select
the target identifier using UTF-16-to-UTF-8 conversion. Only local file URIs are
opened. Missing definitions, invalid ranges and server failures show a status
message. There is no new navigation-history stack in this version.

Rename uses prepareRename when advertised, prompts for the name, then requests
textDocument/rename. All target files are loaded and validated before any edit.
Multi-file changes require confirmation listing the target paths. Changes are
left unsaved, with native Undo in each affected file (not one global Undo).
Other modified target files must be saved first, because their unsaved contents
may not be synchronized with the requesting server. Stale source/target
snapshots, overlapping edits, versioned edits to unknown document sessions,
file operations, annotations and duplicate file aliases are rejected.

Requests are asynchronous with five-second timeouts and session/version checks.
This implementation uses initially advertised capabilities; dynamic capability
registration is not implemented. Cross-file coverage depends on the server's
project/index configuration.
Clangd background indexing is enabled (two workers). The included compilation
database is a local test fixture; update its directory if moving this checkout.
Real projects should supply their own `compile_commands.json` and allow indexing
to finish before relying on project-wide rename coverage.

Native smoke-test arguments:

```sh
-disableSessionRestore YES -disableNewDocumentAtStartup YES \
-LSPPrototypeTestPath /Users/alcides/Code/TextmateLSP/Prototype/symbols.cpp \
-LSPSymbolTest YES \
-LSPPrototypeArtifacts /Users/alcides/Code/TextmateLSP/Prototype/artifacts
```

The test exercises real clangd preparation and rename, Unicode positions,
same-file and header definitions, both shortcuts, multi-file confirmation and
cancellation, rejection after an intervening edit, and per-file Undo.
It restores both fixture buffers without saving. Visual artifacts are AppKit
renderings, not full-screen captures.
