"""Generate explicit Ghidra seeds from TT's observed shared-prologue call pattern.
These are analyst assertions; Ghidra's seed outcome and later assembly remain evidence.
"""
from pathlib import Path
import json
import struct
root = Path(__file__).resolve().parents[1]
binary = (root / "analysis/derived/TT.unpacked.exe").read_bytes()
header_bytes = struct.unpack_from("<H", binary, 8)[0] * 16
code = binary[header_bytes:header_bytes + 0xf8e0]
seeds = []
for start in range(len(code) - 6):
    if code[start] == 0xb8 and code[start + 3] == 0xe8:
        relative = struct.unpack_from("<h", code, start + 4)[0]
        if (start + 6 + relative) & 0xffff == 0xe7bd:
            seeds.append({"address": hex(0x10000 + start), "stack_bytes": struct.unpack_from("<H", code, start + 1)[0]})
out = root / "analysis/seeds"
out.mkdir(parents=True, exist_ok=True)
(out / "compiler-prologues.tsv").write_text("".join(s["address"] + "\tfunction\n" for s in seeds))
(out / "compiler-prologues.json").write_text(json.dumps({
    "basis": "MOV AX, stack_bytes; CALL near 0xe7bd; match exact relative target in CODE_0",
    "warning": "Pattern-based analyst seeds, not proof of function ownership",
    "count": len(seeds), "seeds": seeds}, indent=2)+"\n")
print(f"Recorded {len(seeds)} analyst function seeds.")
