# Letter Invaders and global scores — F5c

Delivered 2026-10-24. Evidence is retained REA assembly plus tests of the JavaScript remake in installed Google Chrome. The original DOS programme has not been run for comparison. Help text supplies context; the implementation rules below come from recovered code unless explicitly identified as browser choices.

## Playing

Choose Game → Play, then Practice Keys or Full Keyboard and One or Two players. Two-player mode asks for a second name. Names use the existing 25-character student-name rules. A ready screen shows the original instructions; an ordinary key starts the round.

Type the displayed letters with their exact case. Starting a word locks the target; a wrong character resets the word's typed prefix. Completing a target launches a missile; points are awarded on collision. Normal letters score 10, words score 5 × length × (length + 1), Boomlets score 50 and Word Ships double word points. A wrong key or ground impact costs 10, clamped at zero. Enter and Space are ignored only when no word is locked.

Each player starts with 80 ground columns, rather than a fixed lives count. Impacts remove intact columns. Rounds prepare 40 payloads; later rounds shorten spawn/fall intervals down to the recovered floors. Accuracy above 90% adds (accuracy − 90) × hits, retaining the native signed 16-bit intermediate overflow before addition to the score.

Escape during play surrenders the current player. The surviving second player can continue. Escape from a ready/between-round prompt ends the game and returns directly to Main Menu. The game-over screen leads to Play another game, Practice Lesson or Return to Main Menu.

Practice Keys temporarily prepares the eligible learned range, including the original eight-home-key minimum. Full Keyboard enables all 64 entries for generation. Neither changes teaching position, weights, pending introductions or typing counters. Only the original random seed advances.

## Timing and display

The pure engine accepts BIOS-like 18.2 Hz ticks. It updates once when the tick changes, without catching up missed ticks. The browser calls it through requestAnimationFrame; background throttling can slow play. There is no added pause mechanic.

The 80×25 renderer uses recovered text, geometry and colors, clipped targets, typed prefixes, bright-red missiles, explosions and a deterministic city silhouette. Terrain drawing uses a copied random state. The existing browser font and short sound effects approximate DOS presentation; font rasterization, waveform and physical timing still need native comparison.

## Global scores and persistence

Game → Scores shows separate Practice Keys and Full Keyboard tables, with five places each. Tables belong to the application database, across student profiles. Insertion uses the native signed 32-bit comparison: zero/nonpositive candidates do not qualify and equal scores stay below existing equals. Native submission order is retained, including the repeated first-player submission when one player dies and Escape is then pressed at the next prompt.

The optional v2 database field gameScores stores the two tables. Optional profile gameRecords store version-1 letter-invaders-f5c audit records with setup, scores, rounds and ordered submissions. Browser records are a remake supervision choice, separate from typing records. Existing profiles and the prototype namespace remain compatible. No names or scores are imported from TT.HIS.

The browser applies submissions to working tables when the whole game finishes, preserving their native order. Scores viewing is read-only. Quit → Yes commits the profile and global tables together; No discards both; Return keeps working data. Failed or stale saves retain the working session. Export includes working/saved tables and any in-progress game. Game dates use the browser start date, stored as ISO text and formatted for display; this is a browser adapter rather than a complete DOS date/history import.

## Static evidence

Addresses identify immutable exports under analysis/recovered/.

| Functions | Recovered behavior |
| --- | --- |
| 0x12f68, 0x12f7f | Play and Scores dispatch |
| 0x19538, 0x1980e | Setup, temporary key range/weights, 40 payloads, word limits, round preparation |
| 0x191df | 90 case-sensitive target slots |
| 0x1947e, 0x19296, 0x1922d | Header, copied-seed terrain and playfield clipping |
| 0x19f66, 0x19ecc | Input, word lock, missiles and miss penalty |
| 0x1a541, 0x1a22a | Movement, spawning, collision points, ground loss and explosions |
| 0x19bec | Accuracy bonus and signed intermediate |
| 0x1ab36 | Turns, surrender, prompt Escape and ordered score submissions |
| 0x1768e, 0x1787b, 0x17a3a | Strict signed score insertion and two five-entry tables |
| 0x1b1f3, 0x1c1c4 | Bright foreground attributes and BIOS clock |
| 0x10335 | Save writes the global score tail as well as the profile |

The two tables begin at DS9843, outside the active profile. Each has five 35-byte entries: 26 name bytes, 4 score bytes, 1 key-count byte and 4 date bytes. The save path writes a 355-byte tail from DS983e to TT.HIS offset 0x462c. This partial layout is evidence, not a finished history importer.

Resource extraction is reproducible with scripts/extract-invaders-data.py; analysis/invaders/resources.json records string offsets, output/extractor hashes and supporting functions.

## Verification and limits

143 unit tests pass: the prior 120 plus 11 engine, six screen/resource, two score-table and four session tests. Coverage includes generation/seed vectors, tick boundaries, lock resets, missile collision, Boomlets/ships, signed bonus overflow, ground overlap, ordered two-player submissions, table ties, malformed records and explicit/failed/stale save behavior.

All eight installed-Chrome workflows pass: menus/settings, practice, adaptive/full keyboard, tests/reports, fingering/keypad, Disk tests, preserved prototype and Letter Invaders. The game workflow uses real keyboard input and controlled browser time, without production test hooks. Seven game captures are retained:

- [Mode choice](screenshots/invaders-mode.png)
- [Round ready](screenshots/invaders-ready.png)
- [Playing](screenshots/invaders-playing.png)
- [Game over](screenshots/invaders-game-over.png)
- [Score tables](screenshots/invaders-scores.png)
- [Two players](screenshots/invaders-two-player.png)
- [Narrow layout](screenshots/invaders-mobile.png)

These captures are remake observations, not DOS captures. Automated scores are test data. Original references and retained analysis remain unchanged.

Next is F6: a bounded fidelity comparison using a disposable DOS working copy, followed by remaining onboarding/history compatibility, font/audio and Safari checks. Instructor features remain separate scope. Full programme parity is not claimed. No server is left running and nothing is published.

## Boomlet warning correction (2026-10-24)

The fast-falling type-2 letter is a Boomlet. Native spawn code 0x1a541 calls sound routine 0x17e47 case 0, which queues 12 descending pitches at each divisor 1/2/4/8/16/32. DS7dd0 contains the 12 uint32 pitches in hundredths of Hz; 0x17a75 converts them to PIT divisors and rounds each 83 ms duration to two BIOS ticks. 0x17ce8 consumes the queue; 0x1a22a/0x17d49 clear special-target sound on destruction.

The initial remake reduced this event to the same short generic beep as other events. It now schedules the recovered 72-note sequence as a square wave. Audio is opened/resumed in the game-start/key gesture so Chrome can play later asynchronous spawns. The warning is silenced when the Boomlet disappears, the player leaves play or Sound is off. Ordinary short event sounds remain approximations; this does not claim complete PC-speaker/runtime parity.

Two unit checks cover pitch/timing vectors and voice replacement/cleanup. A dedicated installed-Chrome test plays a real first round, reaches a second-round Boomlet, checks the 72 scheduled pitches and running context, destroys it and checks cancellation. Real OfflineAudioContext rendering produces nonzero waveform RMS 0.0490. The same gameplay with Sound Off opens no audio context. This verifies generated audio data and browser scheduling, not physical speaker output or a recorded original-machine comparison.

See [Chrome's Web Audio guidance](https://developer.chrome.com/blog/web-audio-autoplay) for the browser gesture requirement. The timing/pitch findings above come from retained assembly, not that browser document.

## Word Ship music and summary percent correction (2026-10-24)

Horizontal type-3 targets are Word Ships. Native 0x1a541 calls 0x17e47 case 1, which expands eight phrase helpers (0x180e1–0x181a5) over 8-byte pitch/duration/rest records at DS7cd0–7dcf. The recovered phrase order contains 85 tones and 35 nonzero quantized rests, totalling 163 BIOS ticks before target-based cancellation. The browser now plays that melody through the same special-target voice as Boomlets, suppresses generic short beeps while it is playing, and stops it when the ship disappears, play ends or Sound is off. Exact timer-interrupt queue occupancy and physical PC-speaker reproduction still need native runtime comparison.

The native summary format is Accuracy: %d%%. C printf turns %% into one literal percent sign; the JavaScript formatter formerly substituted the number but left both signs. It now processes placeholders and escaped percent tokens in one pass, leaving any percent characters inside substituted names alone. Accuracy calculations are unchanged.

Unit checks cover native melody order/timing/rest vectors, voice replacement and literal percentages in round/game-over summaries. Strict-autoplay Chrome verification plays through to round-three Word Ships with Sound On/Off, checks all85 tone changes, collision cancellation, nonzero rendered waveform RMS0.0446 and a single summary percent sign. Existing Boomlet checks continue to pass.

## Complete gameplay sound inventory (2026-10-24)

A follow-up audit found three remaining generic placeholders: wrong keys, successful hits and ground impacts. All now use their recovered native definitions and speaker-busy policy. The five gameplay cues have automated inventory, engine-routing, mute/exit/priority and real-Chrome waveform coverage. See [the sound audit](game-sound-audit.md), including paths that are intentionally silent and separate startup/UI sounds still outside gameplay fidelity.

## Documentation capture refresh — 2026-10-24

The [README gallery](../README.md#screenshots) now features the recovered welcome and Letter Invaders alongside the main menu. The playing capture was refreshed from the current app in installed Chrome using a disposable profile, real spawned targets and a successful shot/score. It includes the current Export and Reset browser controls. No game state or screen pixels were fabricated, and no actual user progress was changed. Captures demonstrate the remake, not native DOS runtime equivalence.
