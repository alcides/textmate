# LSP document formatting

Start the language server, then use **Format** in the bottom Problems bar,
**Text → Format Document**, or **Option–Shift–F** (⌥⇧F).
The controls require the server's advertised document-formatting capability;
they are disabled during a request. The button remains visible when Problems
is collapsed. Existing paragraph reformatting and indentation commands remain
unchanged.

Formatting requests use `textDocument/formatting` with the editor's tab size
and soft-tabs preference. The server may apply its own project style settings
(for example `.clang-format`). No formatting-on-save or selection formatting
is enabled by this change.

Requests run off the main thread with a five-second timeout. The complete edit
list is validated using the code-action edit validator before changing text.
Malformed, overlapping, or stale edits are rejected. The replacement uses the
native editor Undo path; one Undo restores the original document. The current
line/column selection is restored where possible, rather than semantically
tracking the selected syntax through edits. Empty/no-change results display
“Already formatted”. Server errors appear in the bottom status bar.

Native test arguments:

```sh
-disableSessionRestore YES -disableNewDocumentAtStartup YES \
-LSPPrototypeTestPath /Users/alcides/Code/TextmateLSP/Prototype/formatting.cpp \
-LSPFormattingTest YES \
-LSPPrototypeArtifacts /Users/alcides/Code/TextmateLSP/Prototype/artifacts
```

The test uses real clangd and checks the button, menu key equivalent, Unicode
preservation, single Undo, no-op formatting, and rejection after intervening
edits. It leaves the formatted demo open without saving to disk. Image
artifacts are AppKit renderings, not full-screen captures.
