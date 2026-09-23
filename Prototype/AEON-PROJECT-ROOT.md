# Aeon project root and imports

Aeon resolves local modules relative to its process working directory, including
`cwd/libraries`. Sending `initialize.rootUri` alone does not change that directory.

For an Aeon document, TextMate walks upwards from its directory:

1. Use the first ancestor with a `libraries/` directory.
2. Stop at `.git` (file or directory), `.hg`, or `pyproject.toml`, using that
   directory as the root even if it has no libraries. This avoids borrowing
   libraries from an enclosing, unrelated project.
3. Without a marker, fall back to the document's own directory.

The server starts using `/usr/bin/env -C <root> <aeon executable> -lsp` with
separate arguments, without a shell. `env` execs the server, so PID tracking,
stdio and cancellation still target Aeon. TextMate's own working directory is
never changed. `initialize.rootUri` and `workspaceFolders` use the same root.
clangd startup is unchanged. Executable selection and explicit `LSPAeonPath`
overrides are unchanged. Restart an already-running server to apply this change.

For [alcides/aeonbox](https://github.com/alcides/aeonbox), this is the **outer
repository directory** containing `main.ae`, `libraries/`, `examples/` and the
inner Python package `aeonbox/`, not the repository's parent directory.

## Verification

- `TextMate --lsp-build-check` covers nested documents, library documents,
  spaces/Unicode, nested repository boundaries, `.git` worktree files,
  `pyproject.toml` and standalone files.
- `python3 Prototype/test_aeon_imports.py /path/to/aeon /path/to/aeonbox` compares
  real LSP diagnostics from the wrong cwd and the project root for `main.ae`,
  `examples/dry_run.ae` and `libraries/Agent.ae`. It never runs those programs.
- Native opt-in test: `-LSPAeonImportsTest YES -LSPPrototypeTestPath <file>
  -LSPAeonImportRoot <root> -LSPAeonPath <executable>`. This verifies the actual
  server process cwd, unchanged editor cwd and zero error diagnostics.

The PyPI AeonLang 4.8.2 build resolves aeonbox's local modules with the correct
cwd but rejects its `linear` syntax. aeonbox declares a Git dependency, not the
PyPI release. Correct working-directory selection does not make an older server
understand newer language syntax; select the project's compatible server using
`LSPAeonPath` when needed.

Validated on Intel macOS on 2026-09-23 against aeonbox commit `57b3a321` and
its locked Aeon Git revision `f552f78d`. The temporary project environment used
`llvmlite==0.45.1` because the locked 0.48.0 has no Intel wheel; no original
project files or global server preferences were changed. The native client
test confirmed `examples/dry_run.ae` has zero errors, the server cwd is the
outer repository root, and TextMate's cwd is unchanged. Build, root-discovery
regressions and code-signature verification passed.
The real LSP comparison also passed for all three files: the wrong cwd produced
missing-module errors; the project-root cwd produced empty diagnostics for
`main.ae`, `examples/dry_run.ae` and `libraries/Agent.ae`.
