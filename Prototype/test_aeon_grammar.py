"""Verify the TextMate grammar is a lossless adaptation of the VS Code grammar.

Usage: python3 Prototype/test_aeon_grammar.py /path/to/vscode-aeon/syntaxes/aeon.json
"""
import json
import pathlib
import plistlib
import sys

root = pathlib.Path(__file__).resolve().parents[1]
grammar_path = root / 'Applications/TextMate/support/Bundles/Aeon.tmbundle/Syntaxes/Aeon.tmLanguage'
with grammar_path.open('rb') as stream:
    grammar = plistlib.load(stream)
assert grammar.pop('uuid') == 'DE924C99-967E-4820-B5AD-F2C648C1C572'
assert '9ca65e83e4e3794214472377ae9e455395f2444d' in grammar.pop('comment')
with open(sys.argv[1]) as stream:
    upstream = json.load(stream)
assert grammar == upstream, 'Grammar rules differ from the upstream VS Code grammar'
assert grammar['scopeName'] == 'source.aeon' and grammar['fileTypes'] == ['ae']
print('PASS lossless VS Code grammar conversion, stable UUID, scope and file association')
