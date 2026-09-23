# Native diagnostics prototype

Open `diagnostics.cpp` in the experimental TextMate build and click **Start
clangd** in the Problems bar below the editor. This is real server output,
not a mock data source. The installed TextMate application is not replaced.

## Interface

- The existing editor and status bar remain intact. Problems occupies an
  auxiliary bottom panel and collapses to a 38-point summary bar.
- The original line-number, bookmark and folding columns are unchanged. There
  is no extra LSP gutter column. Click a table row to place the caret at the
  diagnostic's start and focus the editor, including clicks on an already
  selected row;
  arrows in the header move between rows.
  The native table supports keyboard selection without losing keyboard focus.
  Rows and the selected-message footer replace newline characters with spaces.
  Hover anywhere on a row to see the full, original multiline message in a
  tooltip; severity also has an accessibility label.
- Starting, checking, clean, stopped and failure states are explicit. A failed
  server offers Restart rather than presenting an empty list as success.
- Edits immediately invalidate old results; only diagnostics with the current
  document version are accepted. Server communication stays off the main thread.
- Starting is opt-in per editor view. Once enabled it follows the active eligible
  file in that view; changing tabs closes the previous session and starts a new
  one. Stop disables it. Unsaved unnamed buffers and other languages have no bar.

The prototype uses Cocoa controls and semantic colors for the current macOS
appearance. It does not introduce a web view or a replacement text editor.
The demo no longer overrides the editor font or window geometry. Existing
TextMate preferences control both, including line-number visibility.

## Scope

Supported extensions: c, h, cc, cpp, cxx, hpp, m, mm. A file needs a path, but
unsaved edits are sent to clangd. Headers default to C++. clangd discovers build
flags using its normal parent-directory search; projects without correct build
configuration can have misleading include/flag diagnostics.

The default executable is this machine's Xcode 26.3 clangd. Override it for a
single launch with `-LSPClangdPath /absolute/path/to/clangd`. There is not yet a
server preferences screen or automatic executable discovery.

This is current-file diagnostics, not a workspace problem index. It uses full
text updates, one server per active editor view and UTF-16 positions. Results
without versions are deliberately ignored (the targeted clangd supports them).
Aeon is an exception: `.ae` files support diagnostics and local synthesis using
persistent server sessions with serialized document updates. See [AEON-SYNTHESIS.md](AEON-SYNTHESIS.md)
for setup, safety and limitations.
Quick fixes for the selected diagnostic are available through **Quick Fix…**;
see [CODE-ACTIONS.md](CODE-ACTIONS.md) for supported edits, limits and tests.

Explicit LSP completion now uses TextMate's native choice popup and insertion engine; see
[COMPLETION.md](COMPLETION.md) for scope and tests.

Hover, diagnostic underlines, formatting, rename and definition navigation are
implemented; see their feature notes in this directory. Persistent full-text
synchronization is described in [SYNCHRONIZATION.md](SYNCHRONIZATION.md).
Minimal range-diff updates and automatic recovery from server failure are not
implemented. Very large files and pathological hung servers need more hardening;
initialization and normal shutdown have response timeouts.

## Reproducing the in-application test

Build using `LSP-VALIDATION.md`, create `Prototype/artifacts`, then run from the
repository root:

```sh
build-xcode26/release/Applications/TextMate/TextMate.app/Contents/MacOS/TextMate \
  -disableSessionRestore YES -disableNewDocumentAtStartup YES \
  -LSPPrototypeTestPath "$PWD/Prototype/diagnostics.cpp" \
  -LSPPrototypeArtifacts "$PWD/Prototype/artifacts"
```

This opt-in hook opens the real document view, clicks the same panel actions
programmatically, edits through OakTextView and captures rendered native views.
It disables session saving, recent-file tracking and backups for the fixture,
never saves the edited fixture, restores its original content and leaves the
prototype open. It does not run on a normal launch. Watch stderr for
`LSP UI TEST: PASS` or a failure/timeout. Captures are ignored by git.

The checks cover real errors, navigation after an emoji (UTF-16 vs UTF-8),
single-line messages with multiline tooltips, repeated-click navigation and focus,
clearing diagnostics after edits, collapsing, stopping/restarting, warnings and
missing-executable recovery. The latter changes only the process's volatile
argument domain, not saved user preferences. Captures use AppKit's print
rendering path. They are not screen captures and must not be used alone to
validate on-screen compositing: the print output previously showed the editor
even when it was hidden in the actual window.

Validated on Intel macOS 15.7.5 with Xcode 26.3 clangd on 2026-09-18. The final
run passed all of the checks above. Captures `01-problems.png`, `02-clean.png`,
`03-collapsed.png`, `04-final.png`, `05-warning.png` and `06-server-failure.png`
record the states inspected during the iterations. The graphical checks used
the real Cocoa controls programmatically, not mouse/keyboard automation through
macOS Accessibility. Light appearance, other OS versions and other language
servers have not been visually validated.

On 2026-09-21, the Problems panel was changed to explicitly clip itself and its
children to its bounds, and to intersect/clip background drawing to those bounds.
Modern AppKit defaults `NSView.clipsToBounds` to NO; filling an unconstrained
dirty rectangle can otherwise paint over sibling views. The corrected build
still needs full-screen visual confirmation. The screen-capture permission
check returned false; the attempted full-screen capture contained only the
desktop and menu bar, not application windows.

The subsequent native-layout revision removed the LSP gutter column and also
restored legacy clipping for OakTextView and GutterView. Gutter drawing now
uses view-local bounds and intersects the dirty rectangle before enumerating
lines. The UI test checks line-number visibility and nonzero gutter width and
additionally emits `cached-*.png` using ordinary AppKit cached drawing, to
compare against the print captures. Neither replaces full-screen validation.

That comparison reproduced a flat gutter in cached drawing while numbers still
appeared in print output. The shared `OakBackgroundFillView` used for the gutter
divider also filled an unbounded dirty rectangle. It now clips to its bounds
and intersects color fills, preserving the original divider width and layout.
After that change, `cached-04-final.png` visibly contains the line numbers,
folding controls, editor text and original status bar. The complete UI smoke
test and strict bundle signature verification passed again; the native gutter
reported 42 points wide with the configured Menlo font. Full-screen capture
remains permission-blocked; this result is from the normal AppKit drawing path.
