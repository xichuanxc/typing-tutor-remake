export const STORAGE_KEY = "type-tutor-remake.v1";
export function defaults() {
  return { version: 1, name: "Student", goal: 25, drills: 10, stage: 0, history: [] };
}
export function validResult(r) {
  return r && ["lesson", "test"].includes(r.mode) && Number.isInteger(r.stage) && r.stage >= 0 && r.stage < 6 &&
    typeof r.date === "string" && Number.isFinite(Date.parse(r.date)) &&
    ["elapsedMs", "attempts", "correct", "wpm", "accuracy", "lines"].every(k => Number.isFinite(r[k]) && r[k] >= 0) &&
    r.correct <= r.attempts && r.accuracy <= 100 && r.perKey && typeof r.perKey === "object" &&
    Object.entries(r.perKey).every(([k, v]) => k.length === 1 && v &&
      ["attempts", "correct", "latencyMs", "samples"].every(f => Number.isFinite(v[f]) && v[f] >= 0) &&
      v.correct <= v.attempts);
}
export function load(storage) {
  try {
    const raw = storage.getItem(STORAGE_KEY);
    if (raw === null) return { data: defaults(), warning: "" };
    const d = JSON.parse(raw);
    if (d.version !== 1 || typeof d.name !== "string" || !d.name.trim() || d.name.length > 24 ||
        !Number.isInteger(d.goal) || d.goal < 5 || d.goal > 150 ||
        !Number.isInteger(d.drills) || d.drills < 1 || d.drills > 20 ||
        !Number.isInteger(d.stage) || d.stage < 0 || d.stage > 5 ||
        !Array.isArray(d.history) || !d.history.every(validResult)) throw new Error("Invalid saved data");
    return { data: d, warning: "" };
  } catch {
    return { data: defaults(), warning: "Saved progress could not be read. Defaults are active; existing data is untouched until you save." };
  }
}
export function save(storage, data) {
  try { storage.setItem(STORAGE_KEY, JSON.stringify(data)); return ""; }
  catch { return "Progress could not be saved. This session remains available until you close the page."; }
}
