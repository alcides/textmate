# Persistent document synchronization

Editing no longer restarts Aeon. The client sends `didOpen` once, versioned
`didChange` notifications during editing, and `didClose` on session shutdown.
Both Full and Incremental sync providers accept the full-content change event
used here. This is full-text document synchronization, not minimal range diffs.

Edits are coalesced for 150 ms. An explicit feature request flushes pending
text sooner. Identical content does not increment the version or clear results.

The current Aeon server publishes one unversioned diagnostic batch for each
open/change. The client therefore keeps one analysis in flight and remembers
that analysis's version and text. If editing supersedes it, the batch is used
only as an acknowledgement, not displayed; the latest text is sent next.
Requests wait for that analysis to refresh Aeon's cached syntax/type data.
This is specific to Aeon's current notification behavior, not a generic way
to version arbitrary servers' unversioned diagnostics. Clangd's versioned
diagnostics retain their existing version checks.

Editing immediately revokes pending synthesis-edit authorization. Synthesis
may continue computing until its command returns, but cannot replace newer
text. The server is not restarted for ordinary edits or Undo. An Aeon analysis
that fails to publish diagnostics within 30 seconds produces an explicit error
requiring a manual restart rather than guessing which snapshot a result belongs
to. Stop, document switching and exceptional server failures still end sessions.

Native regression test: launch the prototype with `-LSPAeonSyncTest YES`,
`-LSPPrototypeTestPath /Users/alcides/Code/TextmateLSP/Prototype/navigation.ae`,
the existing `-LSPAeonPath`, and `-LSPPrototypeArtifacts` directory. The test
checks a stable server PID, increasing versions, error/clean transitions,
coalesced edits, superseded analysis, and navigation using newly renamed text.

Validated on 2026-09-23 with real Aeon: one PID survived 24 document versions,
including error recovery and rapid edits. The existing SMT synthesis regression
also passed: successful replacement, single Undo, and rejection of an old
result after typing, without restart-on-edit.
