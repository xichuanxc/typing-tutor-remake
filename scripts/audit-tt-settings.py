"""Recover Options choices and selected profile fields from retained REA evidence.
Reads references only; writes derived specification under analysis/settings/.
"""
from pathlib import Path
import hashlib
import json
import struct

root = Path(__file__).resolve().parents[1]
raw = root / "analysis/rea"
binary = (root / "analysis/derived/TT.unpacked.exe").read_bytes()
history = (root / "TT/TT.HIS").read_bytes()
toolchain = json.loads((root / "analysis/toolchain.json").read_text())
expected = next(a for a in toolchain["artifacts"] if a["path"].endswith("TT.unpacked.exe"))
assert hashlib.sha256(binary).hexdigest() == expected["sha256"]
base = 0xfae0

def cstr(offset):
    start = base + offset
    return binary[start:binary.index(0, start)].decode("cp437")

def pointers(offset, count):
    return [cstr(p) for p in struct.unpack_from("<"+"H"*count,binary,base+offset)]

def evidence(address, kind="function"):
    data = json.loads((raw / (kind+"-"+address+".json")).read_text())
    assert not data["result"].get("isError")
    result = data["result"]["structuredContent"]
    return {"address":address,"evidence_id":result["evidence_id"],
            "path":"analysis/rea/"+kind+"-"+address+".json"}

def asm_contains(address, *fragments):
    text = json.loads((raw / ("assembly-"+address+".json")).read_text())["result"]["structuredContent"]["normalized_result"]
    assert all(f in text for f in fragments), address

asm_contains("0x1cbd7","MOV [0x90b8], AL","MOV DI, 0xa","CMP SI, 0xa")
asm_contains("0x1cc89","MOV [0x90b7], AL","MOV AX, 0x7")
asm_contains("0x1ccdd","MOV [0x90b6], AL","MOV CX, 0x5","MOV AX, 0x4")
asm_contains("0x1cb56","MOV [0x90ad], AL","MOV AX, 0x2")
weekly_labels=pointers(0x7fb,7)
numeric=list(binary[base+0x7ed:base+0x7fb])
weekly=[{"index":i,"label":label,"min_hours":numeric[i*2],"max_hours":numeric[i*2+1]}
        for i,label in enumerate(weekly_labels)]
drill_labels=pointers(0x89ed,4)
drills=[int(s) for s in drill_labels]
assert drills==[5,10,15,20]
assert [(v["min_hours"],v["max_hours"]) for v in weekly]==[(1,2),(3,4),(5,6),(7,9),(10,14),(15,19),(20,168)]
sound_labels=pointers(0x89e0,2)
assert sound_labels==["Sound","No sound"]
speed=[{"index":i,"label":f"{10+i*10:3d} - {19+i*10:2d}" if i<9 else "100+",
        "stored_min_wpm":10+i*10} for i in range(10)]
fields=[{"key":"name","ds_offset":"0x9072","record_offset":"0x00","bytes":26},
        {"key":"sound","ds_offset":"0x90ad","record_offset":"0x3b","bytes":1},
        {"key":"experience","ds_offset":"0x90b5","record_offset":"0x43","bytes":1},
        {"key":"drills","ds_offset":"0x90b6","record_offset":"0x44","bytes":1},
        {"key":"weekly_time_index","ds_offset":"0x90b7","record_offset":"0x45","bytes":1},
        {"key":"minimum_wpm","ds_offset":"0x90b8","record_offset":"0x46","bytes":1}]
for f in fields:
    assert int(f["ds_offset"],16)-0x9072==int(f["record_offset"],16)
blank=[]
for index in range(9):
    record=history[index*0x7cc:(index+1)*0x7cc]
    if record[0]==0:
        blank.append({"slot":index,"sound_raw":record[0x3b],"drills":record[0x44],
                      "weekly_time_index":record[0x45],"minimum_wpm":record[0x46]})
assert blank and all(d["drills"]==10 and d["sound_raw"]==1 for d in blank)
options=json.loads((root/"analysis/recovered/menus.json").read_text())["menus"][4]
functions=["0x12ead","0x12ec5","0x12edd","0x12ef5","0x12f0d","0x12f25",
           "0x1cbd7","0x1cc89","0x1ccdd","0x1cb56","0x1cd3c","0x1b21d",
           "0x10d63","0x1b8be","0x1f105","0x114f2","0x11170","0x10860",
           "0x10335","0x10e3f","0x19018"]
spec={"scope":"Static Options/profile audit; not runtime confirmation",
      "source_sha256":expected["sha256"],"history_sha256":hashlib.sha256(history).hexdigest(),
      "options_menu":options,
      "choices":{"wpm":speed,"weekly_time":weekly,"drills":drills,"sound":sound_labels},
      "prompts":{"wpm":cstr(0xd38),"weekly_time":cstr(0xdd1),"drills":cstr(0x8a3b),
                 "sound":cstr(0x8a01),"name":cstr(0x1ae)},
      "student_record":{"bytes":0x7cc,"memory_base":"0x9072","fields":fields},
      "blank_record_observations":blank,
      "onboarding":{"weekly_initial_highlight":1,"weekly_initial_label":weekly_labels[1],
                    "beginner_initial_goal_min":20,"two_finger_initial_goal_min":30,
                    "note":"Initial goal picker is experience-dependent; accepting/skipping/canceling affects final values. Blank-record values are not a universal new-student configuration."},
      "behavior":{"listbox_navigation":["ArrowUp","ArrowDown","Space"],
                  "listbox_enter":"Commit current index; only changed values set dirty flag",
                  "options_cancel":"Handlers queue Escape; static dispatcher path returns toward Main Menu",
                  "name_max_characters":25,"name_duplicate_comparison":"case-sensitive bytes",
                  "name_editor":"Nonempty; no leading space; ASCII letters/digits plus space, period, comma, apostrophe, and noninitial hyphen",
                  "sound_stored_mapping":{"1":"Sound","0":"No sound"},
                  "save":"Changes live in the profile buffer; Quit offers save / do not save / cancel. No automatic per-option disk save."},
      "evidence":[evidence(a) for a in functions],
      "assembly_evidence":[evidence(a,"assembly") for a in ["0x1cbd7","0x1cc89","0x1ccdd","0x1cb56","0x10335","0x1b8be"]],
      "remaining_unknowns":["No live DOS Options session captured.",
                           "Full legacy history format and all new-student defaults are not claimed.",
                           "Sound waveform/timing and browser audio mapping are not validated.",
                           "Current browser prototype has not yet adopted these choices or save semantics."]}
out=root/"analysis/settings"
out.mkdir(parents=True,exist_ok=True)
(out/"specification.json").write_text(json.dumps(spec,indent=2)+"\n")
print("PASS: Options choices decoded; four setting writers verified in assembly; profile offsets checked; blank-slot defaults distinguished from onboarding.")
