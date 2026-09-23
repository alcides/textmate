# Python and Aeon LSP compatibility check

Update (2026-09-22): Aeon has since been integrated into the native editor,
including local synthesis. See [AEON-SYNTHESIS.md](AEON-SYNTHESIS.md).
The report below records the earlier protocol-only verification.

Validated on 2026-09-21, macOS 15.7.5 Intel, Xcode 26.3.

## Scope

These are real stdio server tests using a standalone Objective-C++ client
linked against the same compiled lsp-framework objects as TextMate. They
validate transport, initialization, diagnostics, full-document changes and
shutdown, **not support in the current TextMate UI**. No production code or
system Python installation was changed.

Temporary environments, checkout and test client:
`/private/tmp/textmate-language-check.rzquY5`.

The client advertised `publishDiagnostics.versionSupport = true`, opened an
invalid document at version 1, waited for diagnostics, replaced the complete
buffer with valid text at version 2, waited for an empty diagnostics list,
then sent close, shutdown and exit. Both servers exited with status 0.

## Python: PASS

- Python 3.14.6, python-lsp-server 1.15.0, pyflakes 3.4.0.
- Executable: `python-env/bin/pylsp`, no arguments (stdio).
- Language ID: `python`; document extension: `.py`.
- Invalid: `print(unknown_value)`.
- Result: one diagnostic, `undefined name 'unknown_value'`, line 1, column 7.
- Diagnostic version: 1.
- Replacement: `print(42)`.
- Result: zero diagnostics, version 2.

## Aeon: PASS, with compatibility caveats

- Repository: https://github.com/alcides/aeon
- Revision: `ef66bd95e6b7d2d5309453ee63640bc7fa1d988f`.
- AeonLang 4.9.0, Python 3.12.13, pygls 2.1.1.
- Executable: `aeon/.venv/bin/aeon -lsp` (stdio).
- Language ID: `aeon`; document extension: `.ae`.
- Invalid: `def x : Int := true;`.
- Result: one type diagnostic, line 1, column 1:
  `Expression ?todo? has type Bool , but is expected to have type Int  ().`
- Replacement: `def x : Int := 42;`.
- Result: zero diagnostics.
- **Both diagnostic notifications omitted the optional version field.**

The default dependency resolution selected llvmlite 0.49.0, whose local build
failed because LLVM development CMake files were unavailable. Installation
succeeded with a compatible Intel binary by running:

```sh
uv sync --project /private/tmp/textmate-language-check.rzquY5/aeon \
  --python 3.12 --no-dev --upgrade-package llvmlite==0.43.0
```

This selects an older dependency allowed by Aeon's unconstrained llvmlite
requirement. No Aeon source changes were made. This test does not validate
Aeon's LLVM compilation backend with that dependency selection.

## What still prevents using these servers in the editor

1. OakDocumentView only enables the panel for C-family extensions.
2. OakLSPClient hardcodes clangd executable defaults, arguments and language IDs.
3. Panel labels and some client messages assume clangd.
4. OakLSPClient rejects all unversioned diagnostics. Consequently Aeon's real
   diagnostics would be invisible even after changing the executable.

Python's versioned diagnostics fit the current revision filter. Aeon needs an
explicit unversioned-diagnostics policy or server-side version support. Simply
assigning the latest local revision to a notification cannot prove that its
ranges correspond to the current buffer during rapid edits. The sequential
smoke test does not test stale-diagnostic ordering, rapid typing, Unicode
positions, project imports, or editor navigation for either new language.

Next integration work should introduce server profiles (extensions, language
ID, executable, arguments and display name), decide Aeon's revision policy,
and repeat the native UI test for both languages without changing the layout.
