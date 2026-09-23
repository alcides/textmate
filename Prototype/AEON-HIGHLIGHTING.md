# Aeon syntax highlighting

The bundled Aeon grammar now uses the TextMate rules from `alcides/vscode-aeon`
at commit `9ca65e83e4e3794214472377ae9e455395f2444d`. The conversion to XML preserves
the rules and their ordering exactly. The existing `source.aeon` scope, `.ae`
file association and grammar UUID are preserved, so Run and Format keep their
existing scope bindings. No LSP server is required for highlighting.

Coverage follows upstream: comments, escaped strings, integers/floats, booleans,
function/type declarations, imports, decorators, let bindings/multiplicity,
control keywords, primitive types, ASCII/Unicode operators and lambdas, and
embedded Python in `native` expressions. Embedded Python's detailed coloring
requires the Python bundle. Colors depend on the active TextMate theme.

License and provenance ship inside `Aeon.tmbundle` as `LICENSE-vscode-aeon.txt`
and `SYNTAX-SOURCE.md`; the grammar also contains a modification notice.

## Commenting

Use **⌘/** (Bundles → Source → Comment Line / Selection) to toggle `# `
comments on selected lines, or the current line when nothing is selected.
The Aeon bundle provides `source.aeon` comment preferences; the existing Source
bundle command handles indentation, selection, and uncommenting, just as for
Python. No language server is needed.

Run the native regression test with `-LSPAeonCommentTest YES
-LSPPrototypeTestPath <absolute path to an .ae fixture>`. It checks the standard
shortcut command on selected lines and the current line, both directions,
including indentation and Unicode, then restores the fixture without saving.

## Syntax tests

`python3 Prototype/test_aeon_grammar.py /path/to/vscode-aeon/syntaxes/aeon.json`
verifies lossless conversion and identity metadata.

Launch TextMate with `-LSPAeonHighlightTest YES -LSPPrototypeTestPath <absolute
path to Prototype/highlighting.ae> -LSPPrototypeArtifacts <artifact directory>`
for native grammar scope assertions and an editor rendering. This is an opt-in
test only; it never starts a language server or runs the example code. Artifacts
are AppKit renderings, not full-screen captures.

Validated on 2026-09-23: lossless-conversion check, all 22 native grammar scope
assertions, application build, LSP smoke check and code-signature verification
passed. The rendered editor example was visually inspected.
