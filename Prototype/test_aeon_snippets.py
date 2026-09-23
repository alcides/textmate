"""Parse actual TextMate-expanded snippets with an installed Aeon parser.

First run the native LSPAeonSnippetTest. Then pass its aeon-snippets.json
artifact to this script using a Python environment containing aeonlang.
"""

import json
import sys
from pathlib import Path

from aeon.sugar.parser import parse_program


expanded = json.loads(Path(sys.argv[1]).read_text())
assert set(expanded) == {
    "def", "val", "inductive", "indp", "match", "let", "if", "fun", "ref", "open", "import"
}
for trigger, source in expanded.items():
    if trigger == "match":
        source = expanded["indp"] + "\ndef test (value : (Maybe Int)) : Int := " + source + ";"
    elif trigger in ("let", "if"):
        source = "def test : Int := " + source + ";"
    elif trigger == "fun":
        source = "def test : (x : Int) -> Int := " + source + ";"
    elif trigger == "ref":
        source = "def test : " + source + " := 0;"
    parse_program(source)
    print(f"PASS {trigger}")
print("All 11 native snippet expansions parse successfully.")
