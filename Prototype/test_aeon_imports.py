"""Compare real LSP diagnostics with the editor's old and project-root cwd.

Usage: python3 Prototype/test_aeon_imports.py /path/to/aeon /path/to/aeonbox
Only initializes the server and opens documents; never executes the program.
"""
import json
import pathlib
import queue
import subprocess
import sys
import threading
import time


def diagnostics(executable, root, relative, cwd):
    path = root / relative
    process = subprocess.Popen([executable, '-lsp'], cwd=cwd,
                               stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                               stderr=subprocess.DEVNULL)
    messages = queue.Queue()

    def read():
        while True:
            headers = {}
            while True:
                line = process.stdout.readline()
                if not line:
                    return
                if line == b'\r\n':
                    break
                key, value = line.decode().split(':', 1)
                headers[key.lower()] = value.strip()
            messages.put(json.loads(process.stdout.read(int(headers['content-length']))))

    reader = threading.Thread(target=read, daemon=True)
    reader.start()

    def send(method, params, identifier=None):
        message = dict(jsonrpc='2.0', method=method, params=params)
        if identifier is not None:
            message['id'] = identifier
        body = json.dumps(message).encode()
        process.stdin.write(f'Content-Length: {len(body)}\r\n\r\n'.encode() + body)
        process.stdin.flush()

    def receive(predicate):
        deadline = time.monotonic() + 90
        while time.monotonic() < deadline:
            message = messages.get(timeout=max(0.1, deadline - time.monotonic()))
            if predicate(message):
                return message
        raise TimeoutError('No LSP response')

    try:
        send('initialize', dict(processId=None, rootUri=root.as_uri(),
             workspaceFolders=[dict(uri=root.as_uri(), name=root.name)], capabilities={}), 1)
        response = receive(lambda m: m.get('id') == 1)
        assert 'error' not in response, response
        send('initialized', {})
        send('textDocument/didOpen', dict(textDocument=dict(
            uri=path.as_uri(), languageId='aeon', version=1, text=path.read_text())))
        response = receive(lambda m: m.get('method') == 'textDocument/publishDiagnostics'
                           and m['params']['uri'] == path.as_uri())
        return response['params']['diagnostics']
    finally:
        process.terminate()
        try:
            process.wait(timeout=5)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait()
        reader.join(timeout=2)


if __name__ == '__main__':
    executable, project = sys.argv[1:]
    root = pathlib.Path(project).resolve()
    for relative in ('main.ae', 'examples/dry_run.ae', 'libraries/Agent.ae'):
        for label, cwd in [('wrong cwd', root.parent), ('project root', root)]:
            result = diagnostics(executable, root, relative, cwd)
            print(json.dumps(dict(file=relative, cwd=label, diagnostics=result), ensure_ascii=False), flush=True)
            missing = [d for d in result if 'Could not find module' in d['message']]
            if label == 'wrong cwd':
                assert missing, f'{relative}: expected the baseline import failure'
            else:
                assert not missing, f'{relative}: project-root imports still fail: {missing}'
    print('PASS import regression: main, nested example and library; inspect other diagnostics above')
