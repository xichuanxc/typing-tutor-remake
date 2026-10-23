# Original Typing Tutor IV settings

Audit recorded 2026-10-23, using the already retained REA/Ghidra assembly, pseudocode and reference bytes.
No new DOS execution or REA provider session was needed.
The owner accepted the first static-recovery stage and confirmed that its reconstructed menu frame resembles the original.

[Machine-readable specification](../analysis/settings/specification.json) ·
[First-stage REA report](reverse-engineering.md) · [Next-stage plan](next-steps.md)

## Options menu
The original's horizontal Options bar is:
WPM · Time · Drills · Sound · Name · Intro · Help

The menu record is at 0x20ca8; its labels start at columns 0, 5, 11, 19, 26, 32 and 39.
Columns are zero-based. Hexadecimal code/table addresses below are Ghidra analysis addresses, not DOS runtime addresses.

| Option | Actual choices / effect | Handler → implementation |
| --- | --- | --- |
| WPM | Ten tiers: 10–19, 20–29, …, 90–99, 100+ WPM | 0x12ead → 0x1cbd7 |
| Time | Weekly hours: 1–2, 3–4, 5–6, 7–9, 10–14, 15–19, 20+ | 0x12ec5 → 0x1cc89 |
| Drills | 5, 10, 15, or 20 drills per lesson | 0x12edd → 0x1ccdd |
| Sound | Sound / No sound | 0x12ef5 → 0x1cb56 |
| Name | Edit student name; 25 typed characters maximum | 0x12f0d → 0x1cd3c |
| Intro | Read introduction pages from TT.HLP | 0x12f25 → 0x19018 |
| Help | Explain the Options menu | 0x12f50; TT.HLP options section |

WPM stores the selected tier's lower bound (10, 20, …, 100); it is not an arbitrary numeric input.
The final label is explicitly shortened to 100+, rather than displayed as 100–109.
Changing it recalculates two practice threshold values through 0x154c1.

Time stores a range index, not elapsed seconds or a lesson countdown.
The data table represents the last 20+ range as 20–168 hours for calculations; the visible label is 20+.
This affects practice-goal feedback. It does not set a test time limit.

Drills controls the number of drills before the lesson summary; the keyboard and keypad loops read the same profile byte.
The help says ten is the initial lesson length, and all inspected unnamed records in this supplied history contain ten.

Sound stores 1 for Sound, 0 for No sound. Its listbox uses the inverse index (0 selects Sound).
The native code installs/removes its sound support and plays a feedback sound around the choice.
Exact waveform/timing remains unverified; browser audio will need a documented implementation.

Intro and Help are actions, not stored settings.
There is no general theme picker, accuracy-goal input or manual six-stage level selector in this menu.
The prototype's free-entry WPM/drill controls and level selector are remake choices, not recovered original settings.

## Dialog interaction
Listboxes use the shared 0x1b21d routine:
- Up/Down arrows move through choices and wrap; Space moves forward.
- Enter accepts the highlighted choice.
- Existing profile values determine the initial highlight.
- Escape cancellation is enabled in the ordinary menu context.
- Most Options cancel handlers queue an Escape character. Tracing the menu dispatcher shows this unwinds the Options menu toward Main Menu; this should be checked in a runtime comparison.

The horizontal menu itself still uses Left/Right arrows or Space, plus first-letter shortcuts.
The distinction between horizontal menu navigation and vertical dialog navigation matters for the remake.

Normal dialog choices use attribute 0x29 (bright blue on green); selected choices use 0x1a (bright green on blue) in the color branch.
The explanatory outer panel and choice-box layouts come from 0x1b21d, not a modern HTML form.
Attribute values are static observations; actual RGB/font appearance still depends on display configuration.

## Student names
The shared editor receives a 26-byte buffer length, leaving space for the terminator: 25 typed characters.
It requires nonempty input, rejects leading spaces, and permits the original ASCII name character set:
letters, digits, internal spaces, periods, commas, apostrophes and noninitial hyphens.
Backspace edits; Escape cancels.

The registration/rename path checks candidate names using bytewise, case-sensitive comparison through 0x1f105.
The current name also appears among loaded names, so do not assume submitting it unchanged will be accepted by the rename path.
Student names from the supplied history were not copied into this audit.

## Profile fields and saving
These offsets are established for the fields below; this is not a complete TT.HIS format specification.

The active profile starts at DS:0x9072. Full profile reads/writes use a 0x7cc-byte (1,996-byte) record.

| Field | Offset inside profile | Active DS offset | Representation |
| --- | --- | --- | --- |
| Name | 0x00 | 0x9072 | 26-byte name buffer |
| Sound | 0x3b | 0x90ad | Byte: 1 on, 0 off |
| Experience | 0x43 | 0x90b5 | Onboarding selection; outside Options |
| Drills | 0x44 | 0x90b6 | Byte: 5/10/15/20 |
| Weekly goal | 0x45 | 0x90b7 | Byte: range index 0–6 |
| Minimum WPM | 0x46 | 0x90b8 | Byte: tier lower bound |

Option setters change the in-memory profile and set a dirty flag at DS:0x906e.
They do not immediately write a full profile record to disk.

Quit (0x10335) checks practice activity and that flag. It presents save, do-not-save and cancel choices.
The save branch writes the profile containing the changed settings. The no-save path skips that full write; a separate two-byte random-generator seed update at DS:0x90a6 can still occur.
The F4a trace of 0x1bd74 identifies this field as the generator seed; the earlier date-related interpretation was incorrect.
Thus “do not save” should not be described as absolutely no filesystem write, although it skips persisting these options.
Cancel returns to the programme with the working profile still available.

The browser prototype's immediate saving does not match this session/save flow.
The faithful remake should keep a working profile and a saved profile, then commit or discard explicitly at Quit.
Whether to add an optional modern autosave mode is deferred; the default plan follows the original.

## Defaults require context
The supplied TT.HIS has unnamed profile records with:
- Sound on
- 10 drills
- Weekly index 0 (1–2 hours)
- Minimum WPM 10

These are observed blank-record values, not a universal final new-student configuration.
Onboarding subsequently asks for experience and goals:
- Beginner's initial speed highlight is 20–29 WPM.
- Two-finger typist's initial highlight is 30–39 WPM.
- Touch typist's initial goal can depend on the initial test.
- Weekly-goal onboarding initially highlights 3–4 hours, while later Options highlights the currently saved range.

Avoid treating a blank template as the completed onboarding result.
The referenced initial.tst is absent from the three supplied reference files; the touch-typist initial-test path remains a separate compatibility question.

## Evidence and reproducibility
The [settings JSON](../analysis/settings/specification.json) lists the exact retained Evidence IDs and source response paths.
Key sources are the paired .c/.asm files under analysis/recovered/ for:
0x1cbd7, 0x1cc89, 0x1ccdd, 0x1cb56, 0x1cd3c, 0x1b21d, 0x1b8be, 0x10d63, 0x114f2 and 0x10335.

Run:
```sh
python3 scripts/audit-tt-settings.py
python3 scripts/verify-originals.py
python3 scripts/verify-tt-analysis.py
```

The audit validates the unpacked executable identity, checks the four setters against assembly, decodes choice tables,
checks profile-field offsets and records unnamed-slot observations without exporting student names.
The first-stage 1,588-file integrity baseline remains untouched.

Static recovery establishes these settings and code paths. A live DOS settings session, exact sound comparison and end-to-end save/reload behavior remain unverified.
