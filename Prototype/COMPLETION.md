# LSP completion using TextMate's existing engine

With the language server running, invoke TextMate's normal completion command
(Escape at a word). Compatible server candidates appear in a popup reusing
TextMate's existing `OakChoiceMenu`, also used for snippet choices.
Up/Down changes the selection; Enter, Tab or a mouse click accepts it. Escape
cancels. Opening the popup and changing its selection do not edit the document.

`OakTextView` requests candidates asynchronously. Compatible insertion suffixes
are shown with the already typed prefix. On acceptance, the selected suffix is
passed to `ng::editor_t`'s existing completion state and replacement path,
preserving native caret placement and Undo. The native buffer
and bundle completion sources remain the fallback when LSP returns no compatible
items or fails; with LSP disabled the original cycling flow is used directly.
Typing dismisses the popup and inserts the typed character normally. Edits,
caret changes, outside clicks and focus loss also dismiss it.

## Scope

- Explicit invocation at one caret, at an identifier's end or an empty prefix.
- UTF-8 editor positions converted to LSP UTF-16 positions.
- Both completion arrays and `CompletionList` responses; server sort ordering
  and deduplication of insertion suffixes.
- Plain-text insertions and compatible text edits that preserve the already
  typed prefix. Insert/replace edits are accepted only when their replace range
  ends at the caret and matches the supported prefix range.
- Replies are discarded after edits, caret changes, document/provider changes,
  loss of editor focus or a superseding request. The LSP client also gates them
  by session identity and document version.
- Five-second request timeout with native fallback. No main-thread server wait.

Not yet supported: automatic triggering while typing, snippets/placeholders,
completion-item resolution, documentation popups, commit characters, additional
edits/auto-imports, commands, multiline insertions, or arbitrary replacement ranges.
Items requiring unsupported operations are skipped rather than partially applied.
Selection and multi-caret completion continue to use the native implementation.
Incomplete lists are used for the explicit invocation; new text requires a new
invocation rather than live filtering. Item defaults are not advertised, and
responses unexpectedly using defaults are skipped.

The provider is attached to existing LSP sessions, so the current clangd/Aeon
language configuration applies. The native end-to-end completion test below
uses clangd; it does not establish feature parity with Aeon's completion server.

## Native integration test

Launch the built TextMate executable with:

```sh
-disableSessionRestore YES -disableNewDocumentAtStartup YES \
-LSPPrototypeTestPath /Users/alcides/Code/TextmateLSP/Prototype/completion.cpp \
-LSPCompletionTest YES \
-LSPPrototypeArtifacts /Users/alcides/Code/TextmateLSP/Prototype/artifacts
```

Validated with real clangd: `value.al` offers `alpha` and `alpine`, with an emoji
earlier on the same line to test position conversion. The test checks popup
labels, arrow navigation without document changes or additional requests,
Tab/Enter and mouse acceptance, Escape cancellation, single Undo, deterministic
delayed-response guards for cursor and text changes, typing/focus dismissal,
and native completion with LSP disabled. It restores the fixture without saving,
leaves the popup open after `value.al`, and emits `COMPLETION TEST: PASS`.

`completion-popup-composite.png` combines AppKit renderings of the editor and
popup at their relative window positions; it is not a full-screen capture.
