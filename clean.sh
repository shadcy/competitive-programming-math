#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "Cleaning compiled outputs in: $ROOT_DIR"

find "$ROOT_DIR" \
  -not -path "$ROOT_DIR/.git/*" \
  -type f \( -name "*.exe" -o -name "main.exe" -o -name "a.out" -o -name "main" \) \
  -print -delete

echo "Done."
