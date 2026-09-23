# lsp-framework validation

Validated on macOS 15.7.5 (Intel), using Xcode 26.3 (17C529), Apple Clang 17.
The OS was not upgraded. Xcode 14.2 remains installed separately.

Upstream: https://github.com/leon-bckl/lsp-framework
Revision: `87c2f29d351048296ec6782fe29efbffde8aea8b`
Test dependency: `testtest` at `144d613e62fd189c3ec70aa7e0392c0f9e6dc84f`.

## Result

Viable for a prototype, with two local patches. Unmodified upstream does not
compile with this toolchain: TaskFunction's forwarding constructor recursively
evaluates its own move-constructibility constraint.

1. In `lsp/task_function.h`, prepend
   `(!std::same_as<std::decay_t<F>, TaskFunction>) &&` to the forwarding
   constructor's constraints.
2. In `lsp/process.cpp`, guard `WIFEXITED(status)` with `pid > 0` after
   `waitpid(..., WNOHANG)`, so status is not read when no child status is available.
   This is a targeted correction, not a complete audit of process error handling.

The static library and examples built. All 17 CTest entries passed (16 in the
sandbox; the socket test passed when rerun outside it).

An Objective-C++ executable linked Foundation and liblsp, converted diagnostic
messages to NSString, and talked to Xcode 26.3's real clangd over stdio:

```text
server=clangd
diagnostic line=2 Use of undeclared identifier 'variavel_inexistente'
cleared=1 exit=0 alive=0
```

The test initialized the server, opened C source containing an undeclared
identifier, received diagnostics, sent corrected full content via didChange,
received empty diagnostics, then sent didClose/shutdown/exit and checked that
the child process no longer existed.

## Reproduction artifacts

Temporary checkout: `/private/tmp/textmate-lsp-framework-validation`
Build: `build-xcode26` within that checkout.
Test source: `smoke.mm`; executable: `smoke`.
Temporary artifacts may be removed by OS cleanup.

Use `DEVELOPER_DIR=/Applications/Xcode-26.3.app/Contents/Developer` and explicitly
select that Xcode's clang and clang++ for CMake. The build enables C++20,
LSP_BUILD_EXAMPLES and LSP_BUILD_TESTS.

## Native TextMate integration

The pinned library source, generated LSP 3.18 types and the two patches now live
in `vendor/lsp-framework/`. Rave compiles the library directly and the new
`OakLSP` Objective-C++ target connects it to the TextMate executable. Licenses
and provenance are also included in the application's About resources.

`TextMate --lsp-build-check` exercises generated initialize-message JSON,
floating-point JSON serialization and file URI round trips (including spaces
and non-ASCII characters), then returns
without starting NSApplication or loading the user's editor session. This makes
the library a real link dependency, not just an unused compiled target.

### Reproduce this machine's build

Dependencies are installed through Homebrew as described in README.md. The
existing ignored `local.rave` specifies `-I/usr/local/include` and
`-L/usr/local/lib` for this Intel Homebrew installation. It works around the
upstream configure script's ambiguous libcapnp wildcard check. Other machines
must use their own dependency prefix.

From the checkout root:

```sh
export DEVELOPER_DIR=/Applications/Xcode-26.3.app/Contents/Developer
bin/rave -crelease -tTextMate -b "$PWD/build-xcode26"
ninja -j4 TextMate
build-xcode26/release/Applications/TextMate/TextMate.app/Contents/MacOS/TextMate --lsp-build-check
codesign --verify --deep --strict build-xcode26/release/Applications/TextMate/TextMate.app
```

No global `xcode-select` change is required. The old `build/` output and Xcode
14.2 installation are preserved.

### Deployment target

This experimental checkout now declares macOS 14.0 as its minimum, consistently
for compilation, linking and application metadata. With the previous 10.12
target, Apple Clang rejects `std::to_chars(double)` in the library's JSON writer:
the SDK marks it as introduced in macOS 13.3. The installed Homebrew capnp/kj
dylibs additionally require macOS 14.0. Declaring a target is not a runtime test
on that OS: this machine runs 15.7.5, and neither macOS 14 nor Apple Silicon has
been tested. No macOS update was performed.

### Current validation status

All C/C++/Objective-C++ sources compiled with Xcode 26.3 and the TextMate
executable linked successfully. Running the executable produced exit status 0:

```text
lsp-framework 1.3.1; LSP 3.18.0; Objective-C++/JSON/URI OK
```

The earlier standalone `smoke.mm` was also recompiled against the actual Rave
release objects in `build-xcode26/release/_CompileClang/vendor/lsp-framework/`
(not the upstream CMake archive), using C++20, `-funsigned-char`, macOS 14.0
deployment and Foundation. `/private/tmp/textmate-lsp-native-smoke` passed the
real clangd diagnostic/clear/shutdown test with exit status 0 and the same
output shown above. This checks the library under TextMate's compile options,
but remains separate from the editor UI.

**The full application bundle built successfully on 2026-09-18.** After the
user completed Xcode's administrator-authorized first-launch setup, `ibtool
--version` reported 26.3 and `ninja -j4 TextMate` completed interface compilation,
resource assembly and signing with exit status 0.

`codesign --verify --deep --strict` passed for the complete bundle, and its
`--lsp-build-check` passed again. The output is
`build-xcode26/release/Applications/TextMate/TextMate.app` (Intel x86_64).
The signature is local/ad hoc, not a notarized distribution signature. The
editor's graphical session was not opened as part of this verification.

The previous Interface Builder failure was caused by a missing Xcode support
component, `DVTDownloads.framework`, not a C++ compile error or a requirement
to upgrade macOS. `xcodebuild -checkFirstLaunchStatus` alone had not detected
that incomplete setup.

## Limits

The initial build-only validation has now been extended with a native clangd
diagnostics prototype; see `Prototype/README.md`. It includes live full-document
synchronization, version-gated results, UTF-16 to byte-position conversion,
a collapsible Problems panel while retaining the native gutter. It is not full LSP support:
hover, project-wide diagnostics and server discovery/settings
UI are not implemented. The earlier standalone smoke test remains distinct
from the new in-application UI test. Existing Homebrew dynamic dependencies
mean this build is not yet a self-contained distributable application.

Diagnostic quick fixes were added on 2026-09-22. See
`Prototype/CODE-ACTIONS.md` for the current-file edit scope and native clangd tests.

Explicit plain-text LSP completion now reuses TextMate's native choice popup and completion engine.
See `Prototype/COMPLETION.md` for supported edits and the native integration test.
