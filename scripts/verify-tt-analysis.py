"""Check the retained analysis files against their recorded SHA-256 inventory."""
from pathlib import Path
import hashlib
import json
import sys

root = Path(__file__).resolve().parents[1]
index = json.loads((root / "analysis/evidence-index.json").read_text())
failures = []
for item in index["files"]:
    path = root / item["path"]
    if not path.is_file():
        failures.append("Missing: " + item["path"])
        continue
    with path.open("rb") as stream:
        digest = hashlib.file_digest(stream, "sha256").hexdigest()
    if path.stat().st_size != item["bytes"] or digest != item["sha256"]:
        failures.append("Changed: " + item["path"])
if failures:
    print("\n".join(failures),file=sys.stderr)
    sys.exit(1)
print(f"PASS: {len(index['files'])} retained analysis files match the recorded sizes and SHA-256 hashes.")
