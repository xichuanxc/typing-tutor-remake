"Read-only comparison of supplied OLD help with the preserved Y2K-fixed reference."
from pathlib import Path
import argparse
import hashlib
import json

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--original', type=Path, required=True, help='Path to the earlier TT.HLP; never modified')
parser.add_argument('--output', type=Path, default=Path('analysis/help-comparison'))
args = parser.parse_args()
root = Path(__file__).resolve().parents[1]
fixed_path = root / 'TT/TT.HLP'
original = args.original.read_bytes()
fixed = fixed_path.read_bytes()
# Preserve the intact earlier opening. The modified file splits it with credits/contact pages.
welcome_end = original.index(b'@') + 1
continuation = fixed.index(b'This introduction will explain')
candidate = original[:welcome_end] + b'\r\n' + fixed[continuation:]
if len(candidate) != len(original):
    raise SystemExit('Unexpected lengths: comparison requires manual review; no output written.')
candidate.decode('ascii')
runs = []
start = None
for index, (old, new) in enumerate(zip(original, candidate)):
    if old != new and start is None:
        start = index
    elif old == new and start is not None:
        runs.append([start, index])
        start = None
if start is not None:
    runs.append([start, len(original)])
groups = []
for low, high in runs:
    if groups and low - groups[-1][1] < 64:
        groups[-1][1] = high
    else:
        groups.append([low, high])
intro = candidate.split(b'^', 1)[0]
hash_bytes = lambda data: hashlib.sha256(data).hexdigest()
def identity(path, data):
    return {'path': str(path), 'bytes': len(data), 'sha256': hash_bytes(data)}
report = {
    'date': '2026-10-24',
    'scope': 'Static HLP byte comparison only; neither executable run or assessed for Y2K behavior',
    'inputs': [identity(args.original, original), identity(Path('TT/TT.HLP'), fixed)],
    'observation': 'Earlier file has non-text bytes and zero-filled spans replacing help prose; cause unknown.',
    'original_zero_bytes': original.count(b'\0'),
    'original_high_bytes': sum(byte > 127 for byte in original),
    'fixed_zero_bytes': fixed.count(b'\0'),
    'fixed_high_bytes': sum(byte > 127 for byte in fixed),
    'candidate_recipe': 'Intact OLD welcome through first @ + CRLF + fixed text from This introduction will explain through EOF',
    'candidate_full_file_bytes': len(candidate),
    'candidate_full_file_sha256': hash_bytes(candidate),
    'fixed_added_bytes_relative_to_candidate': len(fixed) - len(candidate),
    'different_ranges_exclusive': [
        {'start': low, 'end': high, 'start_hex': hex(low), 'end_hex': hex(high),
         'bytes': high - low, 'old_zero_bytes': original[low:high].count(b'\0')}
        for low, high in groups
    ],
    'equal_outside_these_ranges': all(
        original[index] == byte for index, byte in enumerate(candidate)
        if not any(low <= index < high for low, high in groups)
    ),
    'interpretation': 'Credit-free candidate matches every earlier byte outside two damaged spans; missing text is sourced from fixed copy, not independently corroborated.',
    'intro': {'path': 'analysis/help-comparison/intro-reconstructed.txt',
              'bytes': len(intro), 'sha256': hash_bytes(intro),
              'pages': len([page for page in intro.split(b'@') if page.strip()]),
              'source_note': 'Composite reconstruction; literal * and # placeholders retained. Not a pristine original extract.'},
    'release_status': 'Public repository exists; v0.2.0 release not published and held pending Intro decision.',
}
args.output.mkdir(parents=True, exist_ok=True)
(args.output / 'intro-reconstructed.txt').write_bytes(intro)
(args.output / 'comparison.json').write_text(json.dumps(report, indent=2) + '\n')
assert args.original.read_bytes() == original
assert fixed_path.read_bytes() == fixed
print('Compared help files; preserved both sources. Candidate Intro pages:', report['intro']['pages'])
print('Different ranges after removing added credits:', groups)
