"""Validate self-contained Mach-O apps and merge all native binaries."""
import argparse
import pathlib
import shutil
import subprocess
import tempfile

MAGICS = {b'\xfe\xed\xfa\xce', b'\xce\xfa\xed\xfe', b'\xfe\xed\xfa\xcf',
          b'\xcf\xfa\xed\xfe', b'\xca\xfe\xba\xbe', b'\xbe\xba\xfe\xca',
          b'\xca\xfe\xba\xbf', b'\xbf\xba\xfe\xca'}


def run(*args):
    return subprocess.check_output([str(a) for a in args], text=True)


def binaries(app):
    result = {}
    for path in app.rglob('*'):
        if path.is_file() and not path.is_symlink():
            with path.open('rb') as stream:
                if stream.read(4) in MAGICS:
                    result[path.relative_to(app)] = path
    if pathlib.Path('Contents/MacOS/TextMate') not in result:
        raise RuntimeError('Missing TextMate executable')
    return result


def verify(app, expected):
    for relative, binary in binaries(app).items():
        actual = set(run('lipo', '-archs', binary).split())
        if actual != set(expected):
            raise RuntimeError(f'{relative}: architectures {actual}, expected {expected}')
        for line in run('otool', '-L', binary).splitlines():
            if not line.startswith('\t'):
                continue
            dependency = line.strip().split(' (compatibility version')[0]
            if not dependency.startswith(('/System/Library/', '/usr/lib/')):
                raise RuntimeError(f'{relative}: non-system dependency {dependency}')
    run('codesign', '--verify', '--deep', '--strict', app)
    print(f'Verified {len(binaries(app))} Mach-O files in {app}: {expected}')


def merge(arm, intel, destination):
    verify(arm, ['arm64'])
    verify(intel, ['x86_64'])
    arm_files, intel_files = binaries(arm), binaries(intel)
    if arm_files.keys() != intel_files.keys():
        raise RuntimeError('Architecture builds contain different native binaries')
    if destination.exists():
        raise RuntimeError(f'Refusing to overwrite {destination}')
    shutil.copytree(arm, destination, symlinks=True)
    with tempfile.TemporaryDirectory(prefix='textmate-signing-') as temp:
        for index, (relative, binary) in enumerate(arm_files.items()):
            entitlements = pathlib.Path(temp) / f'{index}.plist'
            result = subprocess.run(['codesign', '-d', '--entitlements', ':-', str(binary)],
                                    capture_output=True, check=True)
            target = destination / relative
            run('lipo', '-create', binary, intel_files[relative], '-output', target)
            args = ['codesign', '--force', '--sign', '-', '--options', 'runtime', '--timestamp=none']
            if result.stdout.strip():
                entitlements.write_bytes(result.stdout)
                args += ['--entitlements', entitlements]
            run(*args, target)
        nested = [p for p in destination.rglob('*') if p.is_dir() and
                  p.suffix in {'.app', '.framework', '.xpc', '.appex', '.qlgenerator', '.tmplugin'}]
        for bundle in sorted(nested, key=lambda p: len(p.parts), reverse=True) + [destination]:
            run('codesign', '--force', '--sign', '-', '--options', 'runtime', '--timestamp=none',
                '--preserve-metadata=entitlements', bundle)
    verify(destination, ['arm64', 'x86_64'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='command', required=True)
    v = sub.add_parser('verify')
    v.add_argument('app', type=pathlib.Path)
    v.add_argument('arches', nargs='+', choices=['arm64', 'x86_64'])
    m = sub.add_parser('merge')
    for name in ['arm', 'intel', 'destination']:
        m.add_argument(name, type=pathlib.Path)
    args = parser.parse_args()
    if args.command == 'verify':
        verify(args.app, args.arches)
    else:
        merge(args.arm, args.intel, args.destination)
