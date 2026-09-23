# lsp-framework snapshot

Upstream: https://github.com/leon-bckl/lsp-framework
Revision: `87c2f29d351048296ec6782fe29efbffde8aea8b` (version 1.3.1).

`vendor/lsp/` contains upstream library sources; `generated/lsp/` contains
the generated LSP 3.18 sources. TextMate compiles these directly through Rave;
no CMake, generator, network access, or temporary checkout is required for this
dependency during an ordinary TextMate build.

## Local changes

- `vendor/lsp/task_function.h`: exclude `TaskFunction` itself before evaluating
  forwarding-constructor constraints. This avoids recursive constraint
  evaluation with Apple Clang 17.
- `vendor/lsp/process.cpp`: only inspect `WIFEXITED(status)` when `waitpid`
  returns a positive PID. A zero result means the child is still running.
- `generated/lsp/types.{h,cpp}`: distinguish the `Command | CodeAction`
  union by the type of `command` (string versus object), not just required
  property names. Aeon returns code actions containing commands. Covered by
  TextMate's `--lsp-build-check` for command, command-bearing action and edit.

Keep these changes when replacing the snapshot unless upstream has equivalent
fixes. These changes are not a complete process-lifecycle audit.

## Regenerating

Check out the exact revision above, apply the vendor changes, and build upstream
with CMake and a C++20-capable toolchain (validated with Xcode 26.3). Its `lspgen`
target processes `lspgen/meta_model/metaModel_3.18.json`; building `lsp` writes
the output into `<cmake-build>/generated/lsp`. Copy that directory here and
copy upstream `lsp/` to `vendor/lsp/`. Run the upstream tests and the TextMate
`--lsp-build-check` command after any update.
Reapply the generated Command/CodeAction discriminator after regeneration.

## Licensing

The library is MIT licensed; see `LICENSE`. Generated protocol types derive
from Microsoft's LSP meta model, under CC BY 4.0; see `THIRD_PARTY_NOTICES.md`
for attribution, original sources and license links. Unlike the upstream meta
model JSON files described there, the files in `generated/lsp/` are generated
C++ adaptations, not verbatim copies of the JSON.
