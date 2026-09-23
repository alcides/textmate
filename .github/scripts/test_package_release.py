"""macOS integration test for the release merger, with tiny cross-built apps."""
import importlib.util
import pathlib
import plistlib
import subprocess
import tempfile
import unittest

spec = importlib.util.spec_from_file_location('packager', pathlib.Path(__file__).with_name('package-release.py'))
packager = importlib.util.module_from_spec(spec)
spec.loader.exec_module(packager)


class PackagingTest(unittest.TestCase):
    def test_universal_helpers_signatures_and_rejections(self):
        with tempfile.TemporaryDirectory(prefix='textmate-package-test-') as directory:
            root = pathlib.Path(directory)
            source = root / 'main.c'
            source.write_text('int main(void) { return 0; }\n')
            entitlements = root / 'entitlements.plist'
            expected_entitlements = {'com.apple.security.cs.disable-library-validation': True}
            entitlements.write_bytes(plistlib.dumps(expected_entitlements))
            for arch in ['arm64', 'x86_64']:
                app = root / arch / 'TextMate.app'
                executable = app / 'Contents/MacOS/TextMate'
                executable.parent.mkdir(parents=True)
                (app / 'Contents/Info.plist').write_bytes(plistlib.dumps({
                    'CFBundleIdentifier': 'org.example.textmate-package-test',
                    'CFBundleExecutable': 'TextMate', 'CFBundlePackageType': 'APPL'}))
                subprocess.check_call(['xcrun', 'clang', '-arch', arch,
                                       '-mmacosx-version-min=14.0', str(source), '-o', str(executable)])
                helper = app / 'Contents/MacOS/helper'
                helper.write_bytes(executable.read_bytes())
                helper.chmod(0o755)
                plugin = app / 'Contents/PlugIns/Test.tmplugin'
                plugin_executable = plugin / 'Contents/MacOS/Test'
                plugin_executable.parent.mkdir(parents=True)
                plugin_executable.write_bytes(executable.read_bytes())
                plugin_executable.chmod(0o755)
                (plugin / 'Contents/Info.plist').write_bytes(plistlib.dumps({
                    'CFBundleIdentifier': 'org.example.textmate-test-plugin',
                    'CFBundleExecutable': 'Test', 'CFBundlePackageType': 'BNDL'}))
                packager.run('codesign', '--force', '--sign', '-', plugin)
                packager.run('codesign', '--force', '--sign', '-', helper)
                packager.run('codesign', '--force', '--sign', '-', '--entitlements', entitlements, app)
            arm, intel = root / 'arm64/TextMate.app', root / 'x86_64/TextMate.app'
            with self.assertRaisesRegex(RuntimeError, 'architectures'):
                packager.verify(arm, ['x86_64'])
            universal = root / 'universal/TextMate.app'
            packager.merge(arm, intel, universal)
            self.assertEqual(len(packager.binaries(universal)), 3)
            actual_entitlements = subprocess.check_output(['codesign', '-d', '--entitlements', ':-', str(universal)])
            self.assertEqual(plistlib.loads(actual_entitlements), expected_entitlements)
            with self.assertRaisesRegex(RuntimeError, 'overwrite'):
                packager.merge(arm, intel, universal)


if __name__ == '__main__':
    unittest.main()
