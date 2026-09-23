# Aeon syntax highlighting

The grammar in `Syntaxes/Aeon.tmLanguage` is adapted from
[alcides/vscode-aeon](https://github.com/alcides/vscode-aeon/blob/9ca65e83e4e3794214472377ae9e455395f2444d/vscode-aeon/syntaxes/aeon.json),
revision `9ca65e83e4e3794214472377ae9e455395f2444d`.

The source is licensed under Apache-2.0; the accompanying
`LICENSE-vscode-aeon.txt` preserves the upstream license. No upstream NOTICE
file was present at this revision.

Changes made for TextMate: JSON converted to an XML property list, the existing
grammar UUID retained, and a provenance comment added. All syntax rules, their
ordering and scope names are unchanged. Files ending in `.ae` use `source.aeon`,
so the existing Run and Format commands remain available.

Embedded `native` Python uses `source.python` from the Python bundle when that
bundle is installed. Highlight colors come from the active TextMate theme;
they need not be identical to the VS Code theme. No running LSP is required.
