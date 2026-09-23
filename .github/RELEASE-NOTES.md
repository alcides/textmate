Experimental TextMate fork with LSP support and an Aeon Cmd-R bundle.

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
