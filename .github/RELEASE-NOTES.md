Experimental TextMate fork with LSP support and an Aeon Cmd-R bundle.

Aeon syntax highlighting now uses the grammar from `alcides/vscode-aeon`,
including declarations, types, keywords, operators, literals and embedded
Python. It works without a running LSP and preserves Run/Format shortcuts.
The upstream Apache-2.0 license and source attribution are included.

Aeon servers now start in the document's discovered project root, so local
`libraries/` imports work from nested files as well. The LSP workspace root
matches the server's working directory. Verified with aeonbox's Git-pinned Aeon
server; projects using newer syntax such as `linear` still need a compatible
server via `LSPAeonPath`, rather than the older PyPI build.

- **TextMate-LSP-universal.zip**: Apple Silicon (arm64) and Intel (x86_64).
- **TextMate-LSP-arm64.zip**: Apple Silicon only.
- Requires macOS 14 or later. SHA-256 checksums are included.
- Ad-hoc signed, **not Apple Developer ID signed or notarized**. Gatekeeper may
  block first launch; inspect the source/checksum before choosing Open Anyway in
  System Settings → Privacy & Security. Do not disable Gatekeeper globally.
- Language servers/interpreters are not bundled. Install Xcode/clangd or configure
  `LSPClangdPath`. With uv installed, Start Aeon can download/setup `aeonlang`
  automatically. `LSPAeonPath` and `TM_AEON` remain explicit overrides.
- This is not an official MacroMates release. Do not use the upstream in-app
  updater for this fork; obtain fork updates from this repository's Releases.

See RELEASE.md and Prototype/ for feature scope, setup and known limitations.
