# Automatic Aeon setup through uv

If `LSPAeonPath` is set to a nonempty path, TextMate uses that executable exactly;
an invalid explicit path reports an error rather than silently installing another
server. If unset or empty, clicking **Start Aeon** offers automatic setup.

TextMate searches for executable uv binaries in this order:

1. `~/.local/bin/uv` (standalone installer default)
2. `/opt/homebrew/bin/uv` (Apple Silicon Homebrew)
3. `/usr/local/bin/uv` (Intel Homebrew)
4. Absolute directories in the app's PATH

No login shell is launched and uv itself is never downloaded automatically.
If absent, install [uv](https://docs.astral.sh/uv/getting-started/installation/)
or configure `LSPAeonPath` manually.

After the one-time **Install and Start** confirmation, TextMate runs:

```sh
UV_TOOL_DIR="$HOME/Library/Application Support/TextMate/LSP/Aeon/tools" \
UV_TOOL_BIN_DIR="$HOME/Library/Application Support/TextMate/LSP/Aeon/bin" \
uv tool install --no-config --upgrade --python 3.12 --no-build-package llvmlite aeonlang
```

This resolves the latest compatible release of the **aeonlang** package (not the
unrelated `aeon` package). uv manages its isolated environment and may download
Python 3.12 and dependencies. This avoids the Python 3.14 incompatibility of
Aeon's current pinned native dependencies. `llvmlite` must have a compatible
wheel, avoiding a source build requiring a separate LLVM toolchain on Intel.
The application's interpreter is then launched directly
as `bin/aeon -lsp`; installation logs never enter LSP stdout. Project uv config
is ignored; uv's normal environment/index and cache settings still apply.

Setup runs off the UI thread and is serialized across documents. Each installer
has a five-minute timeout and can be stopped. The Problems bar shows setup progress or the uv
error. Failed setup is not cached. Successful setup is reused until TextMate
exits; the next app launch checks for upgrades on the first Aeon start, not on
every edit. If offline setup fails, an explicit `LSPAeonPath` can point at the
already-installed managed `bin/aeon` to skip the update check.

The consent preference is `LSPAllowAeonUV`. Remove/disable it to ask again. This
does not uninstall the managed tool. `TM_AEON` still overrides Cmd-R; otherwise
the Run bundle can reuse the managed executable without installing anything.

Implementation follows uv's [isolated tool installation model](https://docs.astral.sh/uv/concepts/tools/).
Downloading the latest package is intentionally not a reproducible version pin;
use `LSPAeonPath` for a pinned environment.

Validated on Intel macOS on 2026-09-23: discovered `~/.local/bin/uv`, installed
AeonLang 4.8.2 from PyPI with Python 3.12.13 and a llvmlite 0.45.1 wheel, then
initialized the real server without an explicit `LSPAeonPath`. Native tests
passed for function/local-binding definitions and zero diagnostics. Native Cmd-R
also reused the managed Aeon 4.8.2 installation without `TM_AEON`, printed
`Hello from Aeon in TextMate!`, and exited successfully. The initial
Python 3.14 source-build failure was correctly reported in the Problems bar;
the Python/wheel policy above addresses it without installing LLVM.
