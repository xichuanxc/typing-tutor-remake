# Startup welcome and first-user detection

Delivered 2026-10-24 from retained REA assembly and original data. These findings are static recovery; the supplied YouTube video could not be retrieved and no new native DOS runtime comparison was performed.

## Browser behavior

A browser with no saved faithful or earlier-prototype data opens the welcome. Press a key or click the bottom prompt to start the simulated typing, keyboard highlights, animated logo and recovered music. This initial gesture permits audio under browser autoplay rules. Escape skips immediately without opening an audio context. Once playing, any ordinary key or the bottom prompt continues to Registration; otherwise the sequence ends automatically and opens Registration.

Registration uses the recovered title, name prompt and input geometry. Enter a valid name of1–25 characters and press Enter to open the main menu; Escape exits. The initial Student value is only a placeholder, so Student is accepted as a new name. Registration marks the working session changed without writing a save. Quit → Save persists the name; Quit → No discards it, and Begin again asks for a name without replaying the welcome.

The original next asks for date confirmation. This browser adaptation omits that screen at the owner’s suggestion and continues using the browser-provided date. Other native new-student questions remain outside this delivery.

Existing browser saves go directly to the main menu. Unreadable or blocked storage also bypasses the welcome and keeps the existing warning/data handling. No original student history is imported. The welcome changes no scores, practice counters, saved settings or session dirty flag, and writes no first-visit marker.

Persistence still uses the normal explicit save flow: after practice or a settings change, Quit → Yes, save session to history. Reloading without ever saving leaves no profile, so that browser will show the welcome again. Quitting/restarting within the same page does not replay the welcome; a session without a saved profile reopens Registration. Older prototype data also suppresses the welcome, without being migrated or relabeled.

To try the welcome while keeping existing progress, open https://tt.xcstudio.dev in a new Chrome Incognito session. Close existing Incognito windows first if that private session already holds a save. To deliberately start over, use Reset all Typing Tutor data beside Export. The confirmation offers Export first, Clear data and Cancel. Clearing removes both app save entries and the unsaved session, then reloads into this welcome. It preserves unrelated data at the same origin. This resets progress; use a fresh Incognito session when you only want to preview the welcome.

## Original evidence

| Area | Static source | Finding |
| --- | --- | --- |
| Startup | 0x10860 → 0x1095c | Native startup runs the sequence before student selection unless a buffered key bypasses it. First-user-only gating is the owner's requested browser policy. |
| Title typing | 0x10c43, 0x10bbb, 0x14cb5, 0x14d14 | Original strings and coordinates; III corrected with two Backspaces to IV; deliberately mismatched uppercase W in the subtitle. Native wait compares quantized centiseconds strictly above 6 or 5. |
| Keyboard | 0x1c78e, 0x1c98e, DS0168/0169 | Original keyboard at row12/column13 with simulated-key highlighting. |
| Logo/layout | 0x1095c, 0x1ca33, DS8940–89db | Title frame, three copyright panels,50 logo points, five colors and registered marker. |
| Music | 0x17e47 case7 → 0x1804e, DS7bc8–7ccf | 64 tones,303 BIOS ticks including quantized rests, about16.64 seconds. Square wave pitches use native PIT divisors; duration/rest conversion follows 0x17a75/0x17ce8. |
| Registration/date order | 0x10860 → 0x10e3f/0x10d63 → 0x10f9a; 0x1b751 | Registration/name follows welcome, then Date. DS01c9/01ae/0843 supply Registration, Please type your name and exit text; shared input geometry matches the current name editor. |
| Profile file | 0x10128, 0x10f47, 0x10e3f, 0x10ddc | Opens TT.HIS read/write; enumerates eight slots, reads26-byte names at1996-byte strides, and loads a1996-byte student record or unnamed template. This is not a complete history-format/import specification. |

The protected TT.HIS reference exists and remains unchanged. The remake stores its own versioned profiles in localStorage under type-tutor-remake.faithful.v2; type-tutor-remake.v1 identifies the earlier prototype. Neither is a DOS history file.

The extractor is scripts/extract-welcome-data.py; resources and supporting assembly hashes are in analysis/welcome/resources.json. Regenerate locally with npm run resources:welcome when the verified unpacked reference is available. CI uses the checked-in generated data and retained assembly, without requiring the proprietary executable.

## Verification and limits

npm test covers profile gating and storage errors, original title correction/error markers, recovered geometry/logo data, native timing boundaries,64-note/303-tick vectors, and resource/source hashes. npm run test:welcome drives installed Google Chrome with strict autoplay: no audio before a gesture, title/logo rendering, scheduled melody and nonzero rendered waveform, automatic completion, key/click cancellation to Registration, blank-name validation, placeholder-name acceptance, exit/restart, name save/discard and saved-profile reload bypass and unchanged existing/invalid data. Captures: [typing](screenshots/welcome-typing.png), [logo](screenshots/welcome-logo.png), [Registration](screenshots/startup-registration.png). The extracted-package check covers first-run welcome at root and project-path hosting.

The browser paints logo color changes at BIOS-tick intervals; the original loop is not explicitly paced, so its CPU-dependent animation speed is not asserted. The native 7ms title-key pulse quantizes below one BIOS tick; sub-tick PC-speaker pulses are not synthesized. Wrong-character cues and the full logo tune use recovered definitions. Physical speaker output, exact interrupt scheduling, native font rasterization, Safari and remaining native new-student questionnaires remain open. The welcome now leads to Registration, followed by the remake main menu.
