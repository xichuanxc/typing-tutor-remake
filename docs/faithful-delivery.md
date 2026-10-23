# F1/F2 delivery — original menus and settings

Completed 2026-10-23. This delivery implements the next bounded stage authorized by the owner.
F3 (the original typing/scoring loop) remains outstanding.

## Delivered behavior
The main route now uses a logical 80×25 display with DOS color attributes and a complete CP437 character-to-Unicode map.
All six student menus use recovered label positions, previews, first-letter actions and horizontal navigation.
After five idle seconds, the screen draws the recovered instruction-panel text inside the recovered rectangle.

Options reproduces the original discrete choices, initial selection, wraparound, Enter commit and Escape cancellation.
Name input uses the recovered 25-character limit, permitted character set and case-sensitive duplicate checks.
Intro and per-menu Help use the original HLP sections, with ASDF/JKL; substituted for the source placeholders.
Working settings and saved settings are separate; Quit has save, do-not-save and return choices.
A failed/conflicting save leaves the session available. The browser's own close warning is used when there are unsaved settings.

Unfinished lesson/test/report/game actions open an explicit planned-feature screen.
The fully playable earlier prototype is retained under /prototype/, with its own scoring and storage.

## Evidence and fidelity matrix
| Area | Evidence | Implemented / remaining |
| --- | --- | --- |
| Main-menu cells and labels | Accepted recovered frame; menu table | Initial 25 rows equal the recovered text frame exactly in Chrome |
| Colors and glyphs | 0x1f6bf, menu routines, CP437 values | DOS attributes and glyph identities reproduced; Courier New raster and RGB palette remain browser approximations |
| Menu navigation | 0x132ed, 0x135f5, 0x138f1 | Horizontal wrap, Space, first letters, Enter and Escape implemented |
| Settings dialogs | 0x1b21d and four option setters | Count, choices, selection values, colors and recovered integer layout model implemented |
| Name editor | 0x1b751, 0x1b8be, 0x10d63 | Original editor length/character rules and duplicate comparison; error-message presentation uses the same grid but is not fully runtime-verified |
| Intro / Help | TT.HLP, 0x19018 | Original text, section boundaries and placeholders retained; deterministic browser pagination is not yet verified page-for-page against DOS |
| Idle panel | 0x1370e and original strings | Recovered box/text; browser wrapping/paragraph spacing are deterministic reconstructions, not runtime-confirmed |
| Sound | 0x1cb56 | Choice and state respected; short Web Audio square-tone feedback is a remake implementation, not a recovered waveform |
| Settings persistence | Profile setters, dirty flag, 0x10335 | Explicit save/discard/cancel, session retention, storage failures and concurrent-save conflict handling |
| Saved profiles | Original field audit | Browser settings schema is independent of TT.HIS; full registration/profile selection/history import is not implemented |
| WPM adaptation side effects | 0x154c1 | Goal setting retained; adaptive threshold recalculation waits for the recovered teaching engine |
| Exit | Browser adaptation | Explicit session-ended/restart screen; no DOS command shell is emulated |
| Practice/scoring/game | Original handlers recovered | Planned in the faithful shell; earlier prototype remains available separately |

## Data choices
- New faithful store: type-tutor-remake.faithful.v2.
- Previous prototype store: type-tutor-remake.v1; never read as compatible scores, overwritten or removed by the faithful app.
- New default working profile: Student, 20 WPM minimum tier, 3–4 weekly hours, 10 drills, Sound.
  These are selected to match the beginner onboarding highlights and initial drill length. This is not a claim to have implemented the full original onboarding.
- The schema permits multiple retained profiles for duplicate checking, but this delivery edits one active profile and does not add a profile-selector flow.
- Saving updates only that active profile. Discard restores the last saved profile; Return to Main Menu retains working changes.
- Corrupt saves are not overwritten; export browser data retains raw saved strings for recovery.
- Concurrent changes in another tab block a stale save rather than overwrite another session.
- Unsaved browser-tab close uses the browser's generic warning, which may be suppressed by browser policy. It cannot guarantee the original Quit dialog.
- The original's separate random-generator seed write on a no-save exit is not reproduced in the browser settings store.

## Source layout
- dist/grid.js and cp437.js: logical cells, glyphs, DOS attributes and dialog geometry.
- dist/original-data.js: generated menus, choices, prompts, idle text and HLP sections.
- dist/app.js: menu/dialog/reader state machine, input, audio and screen painting.
- dist/faithful-session.js: validated working/saved profiles and explicit commits.
- dist/prototype/: retained v0.1 app and its original modules.
- scripts/build-faithful-resources.py: verified-input resource generator.
- tests/faithful.test.mjs: new session/display/resource checks.
- tests/browser-smoke.mjs: faithful-delivery Chrome workflow.
- tests/prototype-smoke.mjs: preserved-prototype Chrome workflow.

The original REA evidence and its 1,588-file integrity baseline were not changed.

## Verification
Passed:
- 17 unit tests: eight faithful session/grid/resource cases and nine preserved prototype engine/storage cases.
- Chrome faithful workflow: frame equality, all submenus, mouse selection, horizontal/list navigation, WPM bounds,
  weekly/drill/sound choices, name validation, session-only changes, canceled choices, Quit cancel/save/discard,
  restart/reload, Introduction/Help, idle text, legacy-key preservation, JSON export, failed-save retention and narrow-window layout.
- Chrome preserved-prototype workflow: typing, correction, results, progression, tests, pausing, persistence and reports/export.
- No JavaScript page errors reported in either workflow.
- Original reference hashes and original analysis integrity checks.
- JavaScript syntax checks and resource generation.

Observed and corrected during validation:
- Replacing controls during focus could consume a mouse click; focus no longer redraws its own target.
- Character backgrounds produced seams at fractional scales; continuous row backgrounds remove those seams.
- Scaled-screen overflow is clipped at the viewport; viewport checks wait for the resize event.
- Browser test expectations were corrected for character-cell textContent, dialog option accessibility roles and Options routing after restart.

Representative captures:
[Main menu](screenshots/faithful-main-menu.png),
[Options](screenshots/faithful-options-menu.png),
[WPM choice](screenshots/faithful-wpm-dialog.png),
[Quit](screenshots/faithful-quit-dialog.png),
[Idle instructions](screenshots/faithful-idle-help.png),
[Narrow viewport](screenshots/faithful-mobile.png).

No independent DOS runtime comparison or Safari verification was performed in this delivery.
All test-owned browser processes and preview servers were stopped.

## Next
Implement F3: original practice-screen boxes, pointers, correction/error accounting and timing.
Use the retained assembly to establish deterministic expected traces before replacing the prototype's provisional scoring.
