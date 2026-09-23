# Aeon bundle formatting

Use **Bundles → Aeon → Format Document**, or **Option–Shift–F** (⌥⇧F) in
`source.aeon` files. Formatting is owned by the Aeon bundle: there is no Format
button in the Problems bar or global Text → Format Document item. Existing
paragraph reformatting and indentation commands remain unchanged.

The bundle runs `aeon --format` on a temporary copy of the current buffer,
including unsaved edits. It does not execute the program or save the document.
It uses `TM_AEON`, the managed uv installation, or `aeon` on PATH, in that order,
just like Run. Start Aeon first to install the managed tool if needed; the
formatter itself does not install anything or require a running LSP server.
Successful output replaces the document through TextMate's standard command
infrastructure (with Undo). Failures and empty output become tooltips and do
not replace code. Temporary files are cleaned up after the command.

Run `ruby Prototype/test_aeon_format.rb` for real CLI formatting/error checks.
Use `-LSPAeonFormatBundleTest YES` with `Prototype/run.ae` for shortcut lookup,
native bundle dispatch, unsaved-buffer, Unicode, Undo and left-aligned error
checks. These passed with AeonLang 4.8.2 on Intel macOS on 2026-09-23. The
AppKit rendering was inspected; physical keyboard delivery is not covered by
this background-safe test.

## Retained generic LSP formatting API

The internal LSP formatting implementation remains available and tested, but
is no longer exposed by the global menu or bottom bar.

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

The test uses real clangd and checks the internal request API, Unicode
preservation, single Undo, no-op formatting, and rejection after intervening
edits. It leaves the formatted demo open without saving to disk. Image
artifacts are AppKit renderings, not full-screen captures.
