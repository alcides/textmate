# LSP hover

With the language server running, pause the mouse over a symbol for 550 ms.
A non-activating native popup shows the server's signature/type/documentation.
No document edits or caret movement are performed.

The client requests `textDocument/hover` asynchronously, with UTF-16 positions
and a five-second timeout. Null responses, unsupported methods and failures
silently produce no popup. Session/version checks plus editor request serials
reject stale results. Pointer movement/exit, edits, selection changes, typing,
clicks, scrolling, focus loss and completion invocation dismiss the popup.
Stopping/changing the server or document also invalidates the provider.

This first version advertises plaintext, supports MarkupContent and legacy
MarkedString/string arrays, and displays their text without interpreting HTML,
fetching images or following links. Markdown returned despite the plaintext
preference is shown literally. Long documentation is a bounded preview (up to
2000 characters and 20 lines), not a scrollable documentation browser.

Native test launch arguments:

```sh
-disableSessionRestore YES -disableNewDocumentAtStartup YES \
-LSPPrototypeTestPath /Users/alcides/Code/TextmateLSP/Prototype/completion.cpp \
-LSPHoverTest YES \
-LSPPrototypeArtifacts /Users/alcides/Code/TextmateLSP/Prototype/artifacts
```

The test exercises real clangd hover after an emoji on the same line, popup
content, absence of document edits, pointer exit and delayed replies after
pointer exit/edits. Artifacts are AppKit renderings, not full-screen captures.
