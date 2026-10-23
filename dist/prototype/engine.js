// Pure typing rules. No DOM, clock, or storage dependency.
export const STAGES = [
  { name: "Left home row", keys: "asdf", hint: "Left hand: little A · ring S · middle D · index F" },
  { name: "Both home rows", keys: "asdfjkl;", hint: "Keep your index fingers on F and J. Reach with the matching finger." },
  { name: "E and I", keys: "asdfjkl;ei", hint: "Middle fingers reach from D to E and K to I." },
  { name: "T and N", keys: "asdfjkl;eitn", hint: "Left index reaches T; right index reaches N." },
  { name: "R and O", keys: "asdfjkl;eitnro", hint: "Left index reaches R; right ring finger reaches O." },
  { name: "Full alphabet", keys: "abcdefghijklmnopqrstuvwxyz;", hint: "Return to your home keys between reaches. Accuracy comes first." },
];

export function makeLines(stageIndex, count = 10, random = Math.random) {
  const keys = STAGES[stageIndex].keys;
  return Array.from({ length: count }, (_, row) =>
    Array.from({ length: 6 }, (_, group) =>
      Array.from({ length: 4 }, (_, col) => {
        // Alternate a repeated pattern with varied combinations.
        const index = row % 3 === 0 ? (group + col + row) % keys.length : Math.floor(random() * keys.length);
        return keys[index];
      }).join("")
    ).join(" ")
  );
}

export function createSession(lines, mode = "lesson", stage = 0) {
  if (!lines.length || lines.some(line => !line.length)) throw new Error("Nonempty lines required");
  return { lines: [...lines], mode, stage, row: 0, typed: [], attempts: 0, correct: 0,
    startedAt: null, finishedAt: null, lastAt: null, elapsedMs: 0, perKey: {} };
}

export function isComplete(session) { return session.finishedAt !== null; }

export function input(session, key, now) {
  if (isComplete(session)) return "ignored";
  if (key === "Backspace") {
    if (session.typed.length) session.typed.pop();
    return "corrected";
  }
  const line = session.lines[session.row];
  if (session.typed.length === line.length) {
    if (key !== "Enter" && key !== " ") return "ignored";
    if (session.row === session.lines.length - 1) {
      session.finishedAt = now;
      return "finished";
    }
    session.row++;
    session.typed = [];
    session.lastAt = null; // Between-line reading is excluded from per-key latency.
    return "next";
  }
  if (key.length !== 1 || key.charCodeAt(0) < 32 || key.charCodeAt(0) > 126) return "ignored";
  if (session.startedAt === null) session.startedAt = now;
  const expected = line[session.typed.length];
  const correct = key === expected;
  session.attempts++;
  session.correct += Number(correct);
  const stats = session.perKey[expected] ??= { attempts: 0, correct: 0, latencyMs: 0, samples: 0 };
  stats.attempts++;
  stats.correct += Number(correct);
  if (session.lastAt !== null) {
    stats.latencyMs += Math.max(0, now - session.lastAt);
    stats.samples++;
  }
  session.lastAt = now;
  session.typed.push(key);
  return correct ? "hit" : "miss";
}

// Pause excludes time away from the exercise. Completed line review still counts.
export function pause(session, now) {
  if (session.startedAt !== null && !isComplete(session)) {
    session.elapsedMs += Math.max(0, now - session.startedAt);
    session.startedAt = null;
    session.lastAt = null;
  }
}

export function metrics(session, now) {
  const elapsedMs = session.elapsedMs + (session.startedAt === null ? 0 :
    Math.max(0, (session.finishedAt ?? now) - session.startedAt));
  const minutes = elapsedMs / 60000;
  return { elapsedMs, attempts: session.attempts, correct: session.correct,
    wpm: minutes > 0 ? session.correct / 5 / minutes : 0,
    accuracy: session.attempts ? session.correct / session.attempts * 100 : 100 };
}

export function summary(session, now, date = new Date().toISOString()) {
  if (!isComplete(session)) throw new Error("Cannot save an incomplete exercise");
  return { ...metrics(session, now), date, mode: session.mode, stage: session.stage,
    lines: session.lines.length, perKey: structuredClone(session.perKey) };
}

export function qualifies(result, goal) {
  return result.mode === "lesson" && result.accuracy >= 95 && result.wpm >= goal;
}

export function aggregate(results) {
  const total = { elapsedMs: 0, attempts: 0, correct: 0, perKey: {} };
  for (const r of results) {
    total.elapsedMs += r.elapsedMs; total.attempts += r.attempts; total.correct += r.correct;
    for (const [key, value] of Object.entries(r.perKey)) {
      const k = total.perKey[key] ??= { attempts: 0, correct: 0, latencyMs: 0, samples: 0 };
      for (const field of Object.keys(k)) k[field] += value[field];
    }
  }
  return { ...total, wpm: total.elapsedMs ? total.correct / 5 / (total.elapsedMs / 60000) : 0,
    accuracy: total.attempts ? total.correct / total.attempts * 100 : 100 };
}
