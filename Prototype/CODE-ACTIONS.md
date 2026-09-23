# Code actions: first integration

Update: Aeon synthesis now also supports the scoped `aeon.synthesize` command
and `workspace/applyEdit`; see [AEON-SYNTHESIS.md](AEON-SYNTHESIS.md). The
restrictions below describe general-purpose actions; Aeon is the explicit exception.

Select a diagnostic in the Problems panel and click **Quick Fix…**. The menu
contains the server's quick fixes for that diagnostic. Choosing an applicable
action updates the unsaved buffer through OakTextView; Undo restores the
previous content. No file is automatically saved.

This keeps the existing editor layout, adding just one button to the bottom
panel. Loading, no-action, request-error and disabled-action states are handled.

## Supported

- `textDocument/codeAction`, with the original diagnostic (including server data)
  and its range; the request asks for `quickfix` actions.
- Literal actions with direct `WorkspaceEdit.changes` or
  `WorkspaceEdit.documentChanges` text edits in the current file.
- Multiple non-overlapping edits, applied against one original buffer snapshot.
- UTF-16 positions, including rejection of positions splitting surrogate pairs.
- Document-version checks and menu invalidation after edits, selection changes,
  stop/restart, and switching documents.
- Bounded requests on the LSP worker, not on the main UI thread.

## Deliberately unsupported in this first implementation

- Commands, including actions containing both an edit and a command.
- Other-file edits, file creation/deletion/renaming and annotated edits.
- Lazy resolution, refactorings and cursor/selection actions without a diagnostic.

Unsupported actions are rejected before any editor mutation, with a message.
Resolve support is not advertised. Existing language/server restrictions still
apply: the UI currently activates clangd for C-family files.

## Native integration test

Build TextMate, then launch its executable with:

```sh
-disableSessionRestore YES -disableNewDocumentAtStartup YES \
-LSPPrototypeTestPath /Users/alcides/Code/TextmateLSP/Prototype/code-actions.cpp \
-LSPCodeActionsTest YES \
-LSPPrototypeArtifacts /Users/alcides/Code/TextmateLSP/Prototype/artifacts
```

The opt-in test validates edit safety, requests a real clangd fix for a missing
semicolon, applies it via the panel's callback, checks diagnostics clear,
checks one Undo restores the original buffer, and rejects a stale response.
It leaves the original erroneous fixture open without saving it. Successful
completion emits `CODE ACTION TEST: PASS` to stderr. Cached AppKit renderings
are saved as `cached-code-action-applied.png` and
`cached-code-action-final.png`; these are not full-screen captures.

Validation on 2026-09-22: the native test passed with Xcode 26.3 clangd
(`insert ';'`), including diagnostics clearing, single Undo, stale-result
rejection and all listed edit-safety checks. The app built successfully and
passed `codesign --verify --deep --strict`.
