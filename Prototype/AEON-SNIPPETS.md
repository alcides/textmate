# Aeon templates

In an `.ae` file, type a trigger and press **Tab**, or choose a template from
**Bundles → Aeon → Templates**. Tab moves to the next editable placeholder;
Shift-Tab moves back. Repeated names are linked (for example, renaming an
inductive type updates its constructors). No language server is required.

| Trigger | Template |
| --- | --- |
| `def` | Function with argument, return type and body |
| `val` | Typed value definition |
| `inductive` | Recursive inductive type, initially `Nat` |
| `indp` | Parameterized inductive type, initially `Maybe a` |
| `match` | Two-constructor pattern match |
| `let` | Local binding with `in` body |
| `if` | Conditional expression |
| `fun` | Lambda |
| `ref` | Refinement type |
| `open` | Open a module |
| `import` | Qualified module import |

Expression templates intentionally omit a trailing semicolon so they can be
nested inside larger expressions. Place declarations before definitions, as
required by Aeon's grammar. Templates do not activate in comments or strings.

## Validation

The templates follow Aeon 4.10.1 syntax. Launch the local build with
`-LSPAeonSnippetTest YES -LSPPrototypeTestPath <absolute .ae fixture path>
-LSPPrototypeArtifacts <existing artifact directory>` to test native Tab
expansion and linked placeholders. The test restores the fixture without
saving and writes `aeon-snippets.json` into the artifact directory.

Run `Prototype/test_aeon_snippets.py <artifact directory>/aeon-snippets.json`
with a Python environment containing `aeonlang` to parse all actual expansions
(expression snippets are wrapped in suitable declarations).
