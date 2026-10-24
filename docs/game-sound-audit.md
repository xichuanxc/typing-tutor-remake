# Letter Invaders sound audit

Audited 2026-10-24 against retained REA assembly and the browser remake. This is static code-path coverage plus automated Chrome observation; it does not certify physical PC-speaker equivalence or native DOS runtime timing.

## Gameplay inventory

| Trigger | Native call | Recovered sound | Remake / verification |
| --- | --- | --- | --- |
| Boomlet appears | 0x1a541 → 0x17e47 case0 | 72 descending notes over six octave divisors | Recovered; actual round-two spawn, waveform, cancellation and mute checked |
| Word Ship appears | 0x1a541 → 0x17e47 case1 | 85-tone melody with quantized rests | Recovered; actual round-three spawn, waveform, cancellation and mute checked |
| Wrong key, including broken word lock | 0x19ecc → 0x17e47 case5 | One high tone, pitch104650/100 Hz before PIT quantization | Recovered; actual wrong key and kernel word-lock/error tests |
| Missile destroys a target | 0x1a22a → 0x17e47 case3 | Three descending tones, DS7b98 | Recovered; actual successful shots and engine event routing |
| Target reaches ground | 0x1a22a → 0x17e47 case2 | Three low ascending tones, DS7bb0 | Recovered; deliberate missed target and engine ground-impact routing |

The original routines suppress the short wrong/hit/impact cues while the speaker queue is occupied. The remake now uses one audio voice for these events rather than generic overlapping beeps. Special warnings remain prominent and stop when the special target is gone. Exact interrupt queue occupancy when a special sound follows an already-playing short cue remains a browser scheduling approximation.

Durations use floor((ms × 182 + 5000) / 10000) BIOS ticks. The rounding boundary matters: the 80 ms hit/impact records become one tick each; the 83 ms Boomlet notes become two. Silence records are retained only when they occupy a nonzero tick.

## Paths checked for silence and stopping

No separate gameplay sound call was found for ordinary target movement/spawn, correct character entry, missile launch/flight, accuracy bonus, game-over display or high-score insertion. They must not receive invented extra effects.

- 0x19f66: correct typing and missile launch update visuals/counters without an effect call.
- 0x1a541: Word Ship exits clear the queue through 0x17d49.
- 0x1a22a: destroying/impacting a special target clears its warning before the outcome cue.
- 0x19bec: round summary clears the queue; no accuracy-bonus jingle.
- 0x1768e: score insertion has no sound call.
- 0x1ab36: turn/exit handling does not add a separate game-over effect.

## Automated coverage

npm test includes six sound-coverage cases in tests/game-sound-coverage.test.mjs. It checks the complete set of emitted engine sound events against the supported effect inventory, pitch/duration vectors, real engine-to-audio routing, silent shots/empty frames, both special spawns, destruction, offscreen escape, priority and mute/exit behavior. A newly introduced engine sound event fails the inventory check until mapped deliberately.

npm run test:audio uses installed Chrome with strict user-activation requirements. It deliberately lets a target hit the ground, makes a wrong key, then plays through rounds one/two/three to verify successful hits, Boomlets and Word Ships. It checks actual oscillator schedules, collision stopping, Sound Off and complete rendered waveforms. Measured RMS: wrong0.01134, hit0.02019, impact0.02045, Boomlet0.0490 and Word Ship0.0446. These are waveform checks, not a physical listening test.

## Shared interface and startup sounds

These paths are outside the five gameplay cues:

- Shared invalid-choice/name/help/input feedback also calls case5. Existing general UI beeps remain a browser approximation; the game-specific wrong cue now uses its recovered definition.
- Startup title lettering calls case4 through 0x10bbb, and startup title/logo animation calls case7 through 0x1095c → 0x1ca33. The remake does not yet reproduce that native startup sequence. This is not a missing Letter Invaders event.
- Options → Sound installs/removes native sound support and gives feedback through 0x1cb56. Browser audio uses the existing Sound setting and gesture policy.

This distinction keeps game sound coverage concrete while leaving startup/onboarding fidelity visibly open.
