# Aeon synthesis in TextMate

Open `Prototype/synthesis.ae`, start Aeon in the Problems panel, select the
`Synthesize ?hole` row, and choose **Quick Fix… → Synthesize ?hole with SMT**
(the exact backend label comes from Aeon), then confirm **Run**. SMT runs locally. Its
replacement is applied to the unsaved buffer and can be undone with Cmd-Z.

The example asks for an expression matching two input/output examples. Those
examples do not constitute a proof of the function's behavior for every input.

## Server setup

The existing isolated Aeon checkout is at
`/private/tmp/textmate-language-check.rzquY5/aeon`, revision
`ef66bd95e6b7d2d5309453ee63640bc7fa1d988f`, with its virtual environment in
`.venv`. This is a temporary development installation, not a bundled server.
Pass `-LSPAeonPath /absolute/path/to/aeon` when launching TextMate; there is no
automatic Aeon discovery. No Aeon server code was modified.

For the opt-in native test, launch the built TextMate executable with:

```sh
-disableSessionRestore YES -disableNewDocumentAtStartup YES \
-LSPPrototypeTestPath /Users/alcides/Code/TextmateLSP/Prototype/synthesis.ae \
-LSPAeonSynthesisTest YES \
-LSPAeonPath /private/tmp/textmate-language-check.rzquY5/aeon/.venv/bin/aeon \
-LSPPrototypeArtifacts /Users/alcides/Code/TextmateLSP/Prototype/artifacts
```

## Protocol and safety

- `.ae` selects Aeon (`aeon -lsp`, language ID `aeon`). C-family files still
  select clangd.
- The client requests actions at the hole without an action-kind filter, executes the
  returned `aeon.synthesize` command, and handles `workspace/applyEdit`.
- Every returned action is listed in server order, with its title and disabled
  reason preserved. No backend allowlist is maintained in TextMate. All nonempty
  backend IDs returned by Aeon can be passed to `aeon.synthesize` for the current
  document. Dependencies, credentials and backend availability are the server's
  responsibility. Listing an action does not prove its backend is configured.
- Synthesis requires confirmation: depending on the selected backend's server
  configuration, source code may be sent externally and charges may apply.
  TextMate does not classify backend names as local or remote.
  Arbitrary server commands and other-file code-action edits remain unsupported.
- One command authorizes one workspace edit, only on its originating session
  and buffer version. Unsolicited or stale edits are rejected.
- Aeon stays running during edits and receives versioned `didChange` updates.
  Because its diagnostics are unversioned, only one analysis is in flight;
  obsolete results are discarded before sending the latest queued text.
  Editing revokes synthesis-edit authorization without restarting the server.
- Execution is bounded to about 20 seconds and cancelled on stop or editing.
  The client supplies an explicit five-second synthesis budget: this Aeon/pygls
  version requires that fourth argument although its code action only sends three.
- The hole rows are client-side lexical candidates, not diagnostics reported
  by Aeon. The server decides whether it actually offers synthesis there.
  Candidate detection is basic and skips lines with a preceding `#`.
- The prototype now ships a minimal Aeon bundle for `.ae` scope selection,
  comment/string highlighting and Cmd-R execution. Diagnostics and synthesis
  remain independent of that bundle. See [AEON-RUN.md](AEON-RUN.md).

The native test requests real SMT synthesis, checks the replacement and fresh
diagnostics, tests single Undo and cancellation by editing, then restores the
original example. It also compares every real server action with its menu item
(count, order, title, payload and disabled state), and checks a generic command
and disabled action. Only the test's selected SMT command is executed.
It writes `AEON TEST: PASS` on success. Cached AppKit images
are not full-screen captures.

Validated on 2026-09-22: real SMT synthesis replaced the hole with `(n + n)`;
fresh diagnostics were empty, one Undo restored the original, and an edit made
after the server's synthesis-start notification prevented the replacement from
being applied. The fixture was restored and left open. The clangd code-action
regression, protocol build checks and app signature verification also passed.

Validated on 2026-09-23 after removing the filters: the real Aeon server returned
36 actions for this hole, and all 36 appeared in the constructed native menu in
the same order with identical titles and payloads. Generic disabled-action
handling, real local SMT synthesis, Undo, cancellation by editing, clangd's fix
and stale-result regression, protocol checks and signature verification passed.
Other synthesis backends were listed but not executed.

See [the complete Aeon-specific code inventory](AEON-HARDCODING.md) for the
remaining specialized adapters and source links.
