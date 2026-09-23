# Inline diagnostics

Active LSP errors have red squiggly underlines; warnings have orange/amber
underlines. The Problems panel remains available and unchanged. Information
and hint diagnostics remain in the panel without inline decoration.

Ranges are converted from LSP UTF-16 coordinates to the editor's UTF-8 byte
positions once per diagnostic update. Invalid positions (including positions
inside surrogate pairs) are ignored. Drawing uses the editor's caret geometry,
with short markers for zero-length ranges, and does not modify text or layout.

Markers clear on edits, document changes, server restart/stop or failure.
Fresh diagnostics repopulate them through the existing version-gated LSP client.

The native diagnostics smoke test checks real clangd errors, Unicode navigation,
warning delivery, immediate invalidation after edits, and stop/restart recovery.
Inspected `artifacts/cached-04-final.png` and `artifacts/cached-05-warning.png`
show error and warning underlines respectively. These are AppKit renderings,
not full-screen captures. Wrapping, folding and dark-theme appearance have not
been separately visually tested.
