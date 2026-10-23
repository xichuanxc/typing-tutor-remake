"""Verify the three immutable DOS references against the recorded manifest."""
from pathlib import Path
import hashlib
import json
import sys

root = Path(__file__).resolve().parents[1]
manifest = json.loads((root / "docs/original-manifest.json").read_text())
expected = {item["path"] for item in manifest["files"]}
actual = {str(path.relative_to(root)) for path in (root / "TT").iterdir()}
errors = []
if actual != expected:
    errors.append(f"Reference inventory differs: expected {sorted(expected)}, got {sorted(actual)}")
for item in manifest["files"]:
    path = root / item["path"]
    if not path.is_file():
        errors.append(f"Missing reference: {item['path']}")
        continue
    data = path.read_bytes()
    if len(data) != item["bytes"] or hashlib.sha256(data).hexdigest() != item["sha256"]:
        errors.append(f"Reference changed: {item['path']}")
if errors:
    print("\n".join(errors), file=sys.stderr)
    sys.exit(1)
print("PASS: exactly three reference files; sizes and SHA-256 hashes match.")
