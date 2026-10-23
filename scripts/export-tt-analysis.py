"""Derive readable exports and menu data from retained REA/Ghidra evidence.
This does not execute TT or claim exhaustive code discovery.
"""
from pathlib import Path
import hashlib
import html
import json
import struct

ROOT = Path(__file__).resolve().parents[1]
RAW = ROOT / "analysis/rea"
OUT = ROOT / "analysis/recovered"
OUT.mkdir(parents=True, exist_ok=True)

def evidence(name):
    result = json.loads((RAW / (name + ".json")).read_text())["result"]
    if result.get("isError"):
        raise ValueError("REA operation failed: " + name)
    return result["structuredContent"]

manifest = json.loads((ROOT / "analysis/toolchain.json").read_text())
binary = (ROOT / "analysis/derived/TT.unpacked.exe").read_bytes()
expected = next(x for x in manifest["artifacts"] if x["path"].endswith("TT.unpacked.exe"))
assert hashlib.sha256(binary).hexdigest() == expected["sha256"]
image = evidence("seeded-load-image")
assert image["normalized_result"]["status"] == "verified"
data_mapping = next(m for m in image["normalized_result"]["observations"]["mappings"] if m["start"] == "0x1f8e0")
data_file = data_mapping["file_offset"]
data_address = int(data_mapping["start"], 16)

def string(offset):
    start = data_file + offset
    return binary[start:binary.index(0, start)].decode("cp437")

def word(offset):
    return struct.unpack_from("<H", binary, data_file + offset)[0]

menu_bytes = evidence("menu-data-and-descriptions")["normalized_result"]
assert menu_bytes["complete"] and menu_bytes["returned_bytes"] == menu_bytes["requested_bytes"]
assert bytes.fromhex(menu_bytes["bytes_hex"]) == binary[data_file+0x134c:data_file+0x134c+1472]
menus = []
for index in range(8):
    offset = 0x134c + index * 31
    count = binary[data_file + offset + 2]
    items = []
    column = 0
    for i in range(count):
        label_pointer = word(offset+3+i*2)
        action = struct.unpack_from("<h", binary, data_file+offset+17+i*2)[0]
        label = string(label_pointer)
        item = {"label": label, "column": column, "label_ds_offset": hex(label_pointer), "action": action}
        if action >= 0:
            item["submenu_index"] = action
        else:
            handler = word(0x1759 + (-action) * 2)
            item["handler_address"] = hex(0x10000 + handler)
            item["description"] = string(word(0x14f5 + (-action) * 2))
        items.append(item)
        column += len(label) + 2
    menus.append({"index": index, "title": string(word(offset)), "record_address": hex(data_address+offset),
                  "record_file_offset": hex(data_file+offset), "items": items})
(OUT / "menus.json").write_text(json.dumps({"evidence": [
    evidence("menu-dispatcher")["evidence_id"], evidence("menu-data-and-descriptions")["evidence_id"],
    evidence("menu-screen-layout")["evidence_id"], evidence("menu-current-description")["evidence_id"]],
    "menus": menus}, indent=2)+"\n")

inventory = evidence("seeded-procedures")["normalized_result"]
exports = []
all_code = ["/* Ghidra pseudocode from REA. Not original source; not expected to compile. */",
            "/* Shared-prologue and register conventions can produce incomplete/misleading pseudocode. Consult assembly. */"]
all_asm = ["; REA / Ghidra 12.1.4 — analyzed function inventory; not exhaustive code coverage."]
for item in inventory:
    address = item["address"]
    pseudo = evidence("function-"+address)
    assembly = evidence("assembly-"+address)
    code = pseudo["normalized_result"]
    asm = assembly["normalized_result"]
    assert isinstance(code, str) and isinstance(asm, str)
    (OUT / (address+".c")).write_text("/* "+pseudo["evidence_id"]+" */\n"+code)
    (OUT / (address+".asm")).write_text("; "+assembly["evidence_id"]+"\n"+asm+"\n")
    all_code.append("/* "+address+" "+pseudo["evidence_id"]+" */\n"+code)
    all_asm.append("; "+address+" "+assembly["evidence_id"]+"\n"+asm)
    exports.append({"address": address, "ghidra_name": item["value"],
                    "pseudocode_evidence_id": pseudo["evidence_id"],
                    "assembly_evidence_id": assembly["evidence_id"],
                    "pseudocode_characters": len(code),
                    "assembly_lines": len(asm.splitlines()),
                    "warnings": [line.strip() for line in code.splitlines() if "WARNING" in line],
                    "pseudocode_path": "analysis/recovered/"+address+".c",
                    "assembly_path": "analysis/recovered/"+address+".asm"})
(OUT / "all-functions.c").write_text("\n\n".join(all_code))
(OUT / "all-functions.asm").write_text("\n\n".join(all_asm)+"\n")
(OUT / "function-index.json").write_text(json.dumps(exports,indent=2)+"\n")

# Reconstruct only the statically established frame, before the idle help panel.
# The supplied name is a placeholder; font rasterization is browser-selected.
cells = [[[" ",0x1f] for col in range(80)] for row in range(25)]
def put(row, col, text, attr):
    for index,char in enumerate(text):
        if 0 <= row < 25 and 0 <= col+index < 80:
            cells[row][col+index] = [char,attr]
def fill(row,attr):
    cells[row] = [[" ",attr] for _ in range(80)]

name = "Student"
put(0,0," "+menus[0]["title"],0x1f)
put(0,79-len(name),name,0x1f)
put(1,0,"═"*80,0x1f)
fill(3,0x5f)
fill(4,0x5e)
for item in menus[0]["items"]:
    put(3,item["column"],item["label"]+"  ",0x5f)
first=menus[0]["items"][0]
put(3,0,first["label"],0x5e)
submenu=menus[first["submenu_index"]]
put(4,0,"".join(i["label"]+"  " for i in submenu["items"]),0x5e)
fill(24,0x5e)
footer=string(0x1552)+string(0x843)
put(24,(80-len(footer))//2,footer,0x5e)
(OUT / "main-menu-frame.txt").write_text("\n".join("".join(c[0] for c in row) for row in cells)+"\n")
palette=["#000000","#0000aa","#00aa00","#00aaaa","#aa0000","#aa00aa","#aa5500","#aaaaaa",
         "#555555","#5555ff","#55ff55","#55ffff","#ff5555","#ff55ff","#ffff55","#ffffff"]
rows=[]
for row in cells:
    spans=[]
    for char,attr in row:
        spans.append('<span style="color:'+palette[attr&15]+';background:'+palette[(attr>>4)&7]+'">'+html.escape(char)+'</span>')
    rows.append("".join(spans))
document='''<!doctype html><html lang="en"><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>TT IV — recovered static menu frame</title>
<style>body{background:#171717;color:#ddd;font:14px monospace;margin:24px}h1{font-size:18px}p{max-width:900px;line-height:1.6}
pre{font:16px/1.25 "Courier New",monospace;white-space:pre;width:max-content;padding:0;margin:24px 0}pre span{display:inline-block;width:1ch;height:1.25em}
.wrap{overflow:auto}a{color:#8df}</style>
<h1>TT IV: menu frame reconstructed from machine-code evidence</h1>
<p>This is an analysis artifact, not a DOS screenshot or the remake. The layout, labels and DOS color attributes come from REA/Ghidra.
The browser font and "Student" name are placeholders. The later idle help panel and other runtime content are not drawn here.</p>
<div class="wrap"><pre aria-label="Recovered 80-column, 25-row main-menu frame">'''+ "\n".join(rows)+'''</pre></div>
<p>Evidence: menu dispatcher 0x132ed; header 0x12692; footer 0x12612; menu rendering 0x1366e / 0x137f2 / 0x1394a; attributes 0x1f6bf.</p></html>'''
(OUT / "main-menu-frame.html").write_text(document)
report={"artifact_sha256":expected["sha256"],"analyzed_procedures":len(inventory),
        "pseudocode_exports":len(exports),"assembly_exports":len(exports),"menus_decoded":len(menus),
        "total_assembly_lines":sum(e["assembly_lines"] for e in exports),
        "limitations":["Only Ghidra's analyzed/seeded function inventory is exported; undiscovered code/data may remain.",
                       "Pseudocode is not original source and can lose register-based arithmetic and stack context.",
                       "Static screen frame excludes the idle help panel and uses an approximate browser font.",
                       "No runtime equivalence or scoring parity is established."]}
(OUT / "coverage.json").write_text(json.dumps(report,indent=2)+"\n")
print(json.dumps(report,indent=2))
