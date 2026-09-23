# Fork builds and releases

This is an experimental fork, not an official MacroMates distribution.

The **Build and release** GitHub Actions workflow builds each native architecture
on its matching macOS 15 runner with Xcode 26.3. It builds Cap'n Proto 1.5.0 from
the pinned source commit with static libraries and a macOS 14 deployment target,
so users do not need the build runner's Homebrew installation. Headers/build
tools come from Homebrew. Language servers and Aeon itself are not bundled.

Each native app is architecture-checked, dependency-checked, signature-checked
and runs `--lsp-build-check`. Packaging merges **every Mach-O file**, including
helpers/plugins, with `lipo`, re-signs inside-out while preserving entitlements,
then repeats architecture/dependency/signature checks. ARM resources are used
for the universal app. Both native architectures are smoke-tested; the merged
app is additionally smoke-tested on the ARM packaging runner.

Successful pushes to `master` and manual workflow runs on `master` automatically
publish a prerelease named `lsp-build-<run-number>-<commit>`. Each build gets its
own release; previous downloads remain available. Pull requests only produce
Actions artifacts and never publish releases. For a named version, push a new
tag matching `lsp-v*`, for example:

```sh
git tag -a lsp-v0.1.0 -m 'First experimental LSP release'
git push fork lsp-v0.1.0
```

After both builds and packaging pass, the workflow creates a GitHub prerelease:

- `TextMate-LSP-universal.zip` — arm64 + x86_64
- `TextMate-LSP-arm64.zip` — arm64 only
- `SHA256SUMS.txt`

No external publishing token is required. Only the final publishing job has
`contents: write`; PR/build jobs are read-only and do not retain checkout credentials.
Publishing is restricted to `alcides/textmate`. Assets and checksums are uploaded
to a draft before it becomes public. Reruns resume draft uploads or leave an
already-published release unchanged.

## Signing and installation

Applications are ad-hoc signed, **not notarized**. Developer ID/notarization is
not configured because no Apple signing credentials were supplied. Gatekeeper
may block downloaded apps; verify the source and checksum before using macOS's
per-app Open Anyway option. Do not disable Gatekeeper globally.

The fork currently retains TextMate's bundle identifier/settings and upstream
update UI. Keep an existing installation backed up, do not install over it
unintentionally, and obtain fork updates from GitHub rather than the upstream
in-app updater. macOS 14 is the deployment target, not a claim of runtime tests
on every supported OS release.

For server setup use `LSPClangdPath` or the active Xcode's `xcrun --find clangd`,
`LSPAeonPath` for a specific Aeon server, or leave it unset for
[automatic uv setup](Prototype/AEON-SETUP.md). `TM_AEON` overrides Cmd-R; otherwise
the bundle reuses the managed installation when available.
See [Prototype/AEON-RUN.md](Prototype/AEON-RUN.md) and the other prototype guides.
