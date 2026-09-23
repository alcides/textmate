#!/bin/bash
set -euo pipefail

# Only successful trusted-branch/tag builds reach this job; PRs never publish.
if [[ "$GITHUB_REPOSITORY" != alcides/textmate || "$GITHUB_EVENT_NAME" == pull_request ]]; then
  echo 'This run is not authorized to publish.' >&2
  exit 1
fi
case "$GITHUB_REF" in
  refs/tags/lsp-v*) release_tag=${GITHUB_REF#refs/tags/} ;;
  refs/heads/master) release_tag="lsp-build-${GITHUB_RUN_NUMBER}-${GITHUB_SHA:0:7}" ;;
  *) echo 'Only master or lsp-v tags may publish.' >&2; exit 1 ;;
esac

test -s dist/TextMate-LSP-universal.zip
test -s dist/TextMate-LSP-arm64.zip
if command -v sha256sum >/dev/null; then
  (cd dist && sha256sum --check SHA256SUMS.txt)
else
  (cd dist && shasum -a 256 --check SHA256SUMS.txt)
fi

# A draft makes interrupted uploads retryable without publishing partial assets.
# Published releases are immutable here; rerunning the same build is a no-op.
if draft=$(gh release view "$release_tag" --repo "$GITHUB_REPOSITORY" --json isDraft --jq .isDraft); then
  if [[ "$draft" == false ]]; then
    echo "Release $release_tag is already published."
    exit 0
  fi
else
  gh release create "$release_tag" --repo "$GITHUB_REPOSITORY" \
    --target "$GITHUB_SHA" --title "TextMate LSP $release_tag" \
    --notes-file .github/RELEASE-NOTES.md --prerelease --draft
fi
gh release upload "$release_tag" --repo "$GITHUB_REPOSITORY" \
  dist/TextMate-LSP-universal.zip dist/TextMate-LSP-arm64.zip dist/SHA256SUMS.txt --clobber
gh release edit "$release_tag" --repo "$GITHUB_REPOSITORY" --draft=false
