# Aeon-specific code inventory

The action list is now server-owned: no algorithm names or language-specific
action-kind filters remain in the production menu/request path. This does **not**
make server configuration or command execution fully generic.

## Production code

### Server selection and launch

[OakLSPClient.mm](/Users/alcides/Code/TextmateLSP/Frameworks/OakLSP/src/OakLSPClient.mm:30)
stores `bool aeon`. `startWithPath:` selects it using `.ae`. Session startup
uses the `LSPAeonPath` preference, requires an explicit executable, launches it
with `-lsp`, sends language ID `aeon`, and allows 30 seconds for initialization
(versus 8 for clangd). These are hardcoded, not server-advertised configuration.

### Unversioned diagnostics and synchronization

[Session diagnostics and worker](/Users/alcides/Code/TextmateLSP/Frameworks/OakLSP/src/OakLSPClient.mm:88)
assume this Aeon server publishes once per open/change without a version.
`analysisVersion`, `analysisText`, `awaitingDiagnostics`, and `analysisStarted`
associate replies with one outstanding analysis. Stale diagnostics are dropped;
requests wait for the latest analysis. Both open/change paths set these fields.
The worker reports an Aeon-specific timeout after 30 seconds and asks for a
manual restart. Other servers are not automatically assigned this workaround.

### Synthetic hole rows (not server diagnostics)

[Hole detection block](/Users/alcides/Code/TextmateLSP/Frameworks/OakLSP/src/OakLSPClient.mm:106)
scans Aeon text using `\\?[A-Za-z_][A-Za-z0-9_]*`, skips matches with a preceding
`#` on the same line, and adds severity-3 `Synthesize ?name` rows with source
`Aeon` and a synthetic range/diagnostic. This is a lexical heuristic, not an
Aeon parser; the server decides which actions exist at the selected range.

### Synthesis command adapter and edit authorization

[Complete executeSynthesis implementation](/Users/alcides/Code/TextmateLSP/Frameworks/OakLSP/src/OakLSPClient.mm:474)
is Aeon-specific. It requires an Aeon session, command `aeon.synthesize`, exactly
three arguments (URI, hole, backend), a nonempty string backend, and a matching
document path; actions with edits or disabled reasons are rejected. It permits
one synthesis at a time, authorizes one edit for the current buffer version,
forwards the returned command/arguments, and appends `5.0` as the budget because
this Aeon/pygls version requires a fourth argument. It waits up to 20 seconds;
timeout stops the session and requires restart. No backend-name allowlist remains.

[workspace/applyEdit handler](/Users/alcides/Code/TextmateLSP/Frameworks/OakLSP/src/OakLSPClient.mm:66)
accepts only an Aeon session with one active synthesis authorization.
`authorizedVersion.exchange(0)` consumes that authorization; `synthesisApplied`
records whether a replacement was accepted. The client-to-editor callback checks
the originating session/version. Editing revokes authorization. Missing/rejected
results produce synthesis-specific messages. These restrictions also mean this
is not yet a general-purpose execute-command/apply-edit implementation.

[OakLSPClient.h](/Users/alcides/Code/TextmateLSP/Frameworks/OakLSP/src/OakLSPClient.h:20)
exposes the specialized `executeSynthesis:completion:` API. Its workspace-edit
and notice callbacks support this adapter; edit validation itself is reusable.

### Editor integration

[OakDocumentView setup](/Users/alcides/Code/TextmateLSP/Frameworks/OakTextView/src/OakDocumentView.mm:401)
includes `ae` in the supported extensions and displays `Aeon` rather than `clangd`
for that extension.

[Action dispatch and confirmation](/Users/alcides/Code/TextmateLSP/Frameworks/OakTextView/src/OakDocumentView.mm:435)
recognizes `aeon.synthesize`, asks for confirmation (including the possible
external-service/cost warning), rechecks client/version on acceptance, invokes
`executeSynthesis:completion:`, and displays synthesis progress/result strings.
Other actions go through the existing workspace-edit validator.

[Notice logging](/Users/alcides/Code/TextmateLSP/Frameworks/OakTextView/src/OakDocumentView.mm:499)
prints `AEON SERVER:` only under the opt-in `LSPAeonSynthesisTest` flag.

### Removed hardcoding

Program execution is now implemented entirely in
`Applications/TextMate/support/Bundles/Aeon.tmbundle`: a `.ae`/`source.aeon`
grammar, scoped ⌘R command, and Ruby adapter using `TM_AEON` (fallback `aeon`)
with the shared TextMate Executor. No native Run adapter remains.
`RunAeonBundleTest` / `LSPAeonBundleTest` is test-only, and `Prototype/run.ae`
is its fixture. See [AEON-RUN.md](AEON-RUN.md) for details.

- The menu's `smt`, `tdsyn_enumerative`, `tactics` allowlist.
- The same three-backend allowlist in the executor.
- The `.ae → refactor.rewrite`, other files → `quickfix` request filter.

[Menu construction](/Users/alcides/Code/TextmateLSP/Frameworks/OakTextView/src/OakLSPPanel.mm:180)
now contains no Aeon branch: every returned action gets an item in original
order, with its returned title/payload and disabled reason. Request capabilities
advertise the standard action kinds supported by the protocol library. Unsupported
commands may still be listed but report an execution error rather than being hidden.

## Test-only code and fixtures

- [LSPPrototypeTest.mm](/Users/alcides/Code/TextmateLSP/Applications/TextMate/src/LSPPrototypeTest.mm:105):
  `RunAeonSynthesisTest` targets `?hole` on line 5, selects `smt`, approves its
  confirmation, checks synthesis/Undo and cancellation using the server notice
  prefix `Synthesizing ?hole with`. It now checks the full menu against the server.
  `LSPAeonSyncTest` exercises repeated edits and a stable server PID;
  `LSPAeonNavigationTest` checks known fixture positions and this server version's
  definition-supported/rename-unsupported capabilities. All are opt-in flags.
- [OakLSP.mm](/Users/alcides/Code/TextmateLSP/Frameworks/OakLSP/src/OakLSP.mm:12):
  the JSON variant smoke test includes an `aeon.synthesize` CodeAction alongside
  a generic Command and edit-only action. This is test data, not dispatch logic.
- `Prototype/*.ae` are Aeon example/test programs. Prototype documentation records
  the temporary Aeon checkout, executable, version, launch flags and test results.
  None of these paths is an automatic production-server fallback.

No synthesis algorithm registry has been copied into TextMate. The external
Aeon server owns that registry; its checkout was not changed by this work.
