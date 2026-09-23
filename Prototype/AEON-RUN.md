# Running Aeon with the TextMate bundle

Open an `.ae` file and press **⌘R**, or choose **Bundles → Aeon → Run**.
The command uses TextMate's existing bundle runner and HTML output window,
just like the Python and Ruby bundles. It works without starting the LSP server.
The prototype packages `Aeon.tmbundle` in its standard SharedSupport/Bundles
directory; the same bundle can be installed separately in stock TextMate.
After first adding the bundle to an existing development build, let TextMate's
bundle index refresh and reopen any document still marked Plain Text (or choose
Aeon in its language selector).

## Interpreter configuration

Set `TM_AEON` in TextMate Settings → Variables to the Aeon executable's path,
or set it in a project `.tm_properties` file:

```ini
[ source.aeon ]
TM_AEON = '/absolute/path/to/aeon'
```

If unset, the command finds `aeon` on its PATH. Supply an executable path, not a
shell command with flags. The bundle does not read the native LSP preference;
`LSPAeonPath` and `TM_AEON` are independent settings. No development-machine path
is hardcoded in the bundle.

## Behavior

- `.ae` maps to `source.aeon` through a minimal bundled grammar (comments and
  strings), which scopes ⌘R to Aeon and leaves other language commands unchanged.
- Existing files are saved by TextMate's `saveActiveFile` command machinery.
  Canceling a required save cancels the run. Untitled Aeon documents use the
  shared `save_if_untitled('ae')` helper and a temporary file.
- The shared `TextMate::Executor` runs the interpreter with the file path as a
  separate argument, from the file's directory, without shell interpolation or
  a `-lsp` flag. Output, errors and exit status appear in the usual output panel.
- This executes the program with normal user permissions; it is not a sandbox.
  Aeon's CLI itself determines behavior for programs containing synthesis holes.
- No custom native Run selector, Terminal launcher or extra keybinding is added.

`Prototype/run.ae` prints `Hello from Aeon in TextMate!`.
The opt-in `LSPAeonBundleTest` checks `.ae` scope selection, the scoped ⌘R lookup,
dispatches that key through the editor, and checks real output and status 0 in
the shared HTML output view. Configure `TM_AEON` for the test just as for normal use.

Validated 2026-09-23 with Aeon 4.9.0: native ⌘R dispatch, automatic `source.aeon`
selection, a filename containing spaces and an apostrophe, and real interpreter
output with exit code 0. Missing-interpreter feedback was also observed before
configuring `TM_AEON`. Bundle plist/Ruby syntax, build and app signature checks
passed. AppKit-rendered test artifacts are not full-screen captures.
