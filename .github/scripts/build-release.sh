#!/bin/bash
set -euo pipefail
test "$(uname -m)" = "$1"
test ! -e local.rave || { echo 'Release builds require a clean checkout without local.rave.' >&2; exit 1; }
dep_prefix="$PWD/.release-deps/install"
cmake -S .release-deps/capnproto -B .release-deps/build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$dep_prefix" \
  -DCMAKE_OSX_DEPLOYMENT_TARGET=14.0 -DCMAKE_OSX_ARCHITECTURES="$1" \
  -DBUILD_SHARED_LIBS=OFF -DBUILD_TESTING=OFF -DWITH_OPENSSL=OFF -DWITH_ZLIB=OFF
cmake --build .release-deps/build --parallel 3
cmake --install .release-deps/build
export PATH="$dep_prefix/bin:$PATH"
brew_prefix=$(brew --prefix)
# Prefer the pinned static libraries, never the runner's Homebrew dylibs.
cat > local.rave <<EOF
add FLAGS "-I${dep_prefix}/include -I${brew_prefix}/include"
add LN_FLAGS "-L${dep_prefix}/lib"
add IB_FLAGS "--minimum-deployment-target=14.0"
EOF
mkdir -p build-release
builddir="$PWD/build-release" ./configure
ninja -j3 TextMate
app=build-release/release/Applications/TextMate/TextMate.app
cp .release-deps/capnproto/LICENSE "$app/Contents/Resources/About/CapnProto-LICENSE.txt"
codesign --force --sign - --options runtime --timestamp=none \
  --entitlements build-release/release/_ExpandVariables/Applications/TextMate/Entitlements.plist "$app"
