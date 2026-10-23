import {validInvadersRecord} from "./invaders.js";
import {validGameScores,insertGameScore} from "./game-scores.js";
import {validDiskRecord} from "./disk-test.js";
import {validKeypadRecord} from "./keypad.js";
import {validTestRecord} from "./typing-test.js";
import {createCurriculum,validCurriculum,commitCurriculum,recalculateThreshold} from "./curriculum.js";
import {validPracticeRecord} from "./practice.js";
export const PROFILE_KEY="type-tutor-remake.faithful.v2";
export const LEGACY_KEY="type-tutor-remake.v1";
export const DEFAULT_PROFILE=Object.freeze({id:"student-1",name:"Student",wpm:20,weekly:1,drills:10,sound:true});
export function validName(name) {
  return typeof name==="string"&&name.length>0&&name.length<=25&&/^[A-Za-z0-9.,'][A-Za-z0-9 .,\x27-]*$/.test(name);
}
function validProfile(p) {
  return p&&typeof p.id==="string"&&/^[a-zA-Z0-9-]{1,80}$/.test(p.id)&&validName(p.name)&&
    Number.isInteger(p.wpm)&&p.wpm>=10&&p.wpm<=100&&p.wpm%10===0&&
    Number.isInteger(p.weekly)&&p.weekly>=0&&p.weekly<7&&[5,10,15,20].includes(p.drills)&&typeof p.sound==="boolean"&&
    (p.curriculum===undefined||(validCurriculum(p.curriculum)&&p.curriculum.introduced>=3&&p.curriculum.introduced<=63))&&
    (p.gameRecords===undefined||(Array.isArray(p.gameRecords)&&p.gameRecords.every(r=>validInvadersRecord(r)&&r.completed)))&&
    (p.practiceRecords===undefined||(Array.isArray(p.practiceRecords)&&p.practiceRecords.every(r=>validPracticeRecord(r)||validTestRecord(r)||validKeypadRecord(r)||validDiskRecord(r))));
}
function validate(db) {
  return db&&db.version===2&&(db.gameScores===undefined||validGameScores(db.gameScores))&&Array.isArray(db.profiles)&&db.profiles.length>0&&db.profiles.every(validProfile)&&
    new Set(db.profiles.map(p=>p.id)).size===db.profiles.length&&
    new Set(db.profiles.map(p=>p.name)).size===db.profiles.length&&db.profiles.some(p=>p.id===db.activeId);
}
export class StudentSession {
  constructor(storage) {
    this.storage=storage;this.warning="";this.readable=true;this.baseRaw=null;
    this.db={version:2,activeId:DEFAULT_PROFILE.id,profiles:[{...DEFAULT_PROFILE}]};
    try {
      this.baseRaw=storage.getItem(PROFILE_KEY);
      if(this.baseRaw!==null){const db=JSON.parse(this.baseRaw);if(!validate(db))throw Error();this.db=db;}
    } catch {this.readable=false;this.warning="Saved browser data could not be read. Existing browser data has been left untouched.";}
    this.restart();
  }
  restart(){this.saved=structuredClone(this.db.profiles.find(p=>p.id===this.db.activeId));this.working=structuredClone(this.saved);this.savedScores=structuredClone(this.db.gameScores??[[],[]]);this.workingScores=structuredClone(this.savedScores);this.scoreTablesChanged=false;this.dirty=false;}
  change(key,value) {
    if(!["wpm","weekly","drills","sound"].includes(key))throw Error("Unknown setting");
    const next={...this.working,[key]:value};
    if(!validProfile(next))throw Error("Invalid setting");
    if(this.working[key]!==value){
      this.working=next;
      if(key==="wpm"&&this.working.curriculum){recalculateThreshold(this.working.curriculum,value,0);recalculateThreshold(this.working.curriculum,value,1);}
      this.dirty=true;
    }
  }
  rename(name) {
    if(!validName(name))return "Please enter 1 to 25 valid name characters.";
    // Original comparison includes the existing name and is case-sensitive.
    const names=this.db.profiles.map(p=>p.id===this.working.id?this.working.name:p.name);
    if(names.includes(name))return "This name duplicates one already registered. Please reenter name differently.";
    this.working={...this.working,name};this.dirty=true;return "";
  }
  beginAdaptivePractice(){
    if(!this.working.curriculum)this.working={...this.working,curriculum:createCurriculum(this.working.wpm)};
    this.dirty=true;return this.working.curriculum;
  }
  recordPractice(record){
    if(!validPracticeRecord(record)&&!validTestRecord(record)&&!validKeypadRecord(record)&&!validDiskRecord(record))throw Error("Invalid practice record");
    this.working={...this.working,practiceRecords:[...(this.working.practiceRecords??[]),structuredClone(record)]};
    this.dirty=true;
  }
  recordGame(record){
    if(!validInvadersRecord(record)||!record.completed)throw Error("Invalid game record");
    let tables=structuredClone(this.workingScores),changed=false;
    for(const submission of record.submissions){
      const inserted=insertGameScore(tables,record.mode==="full"?1:0,{
        name:record.players[submission.player],score:submission.score,keys:submission.keys,date:record.startedAt
      });
      tables=inserted.tables;changed||=inserted.index>=0;
    }
    this.working={...this.working,gameRecords:[...(this.working.gameRecords??[]),structuredClone(record)]};
    this.workingScores=tables;this.scoreTablesChanged||=changed;this.dirty=true;
  }
  commit() {
    if(!this.readable)return "Saved browser data could not be read. Export browser data before repairing this save.";
    const committed=structuredClone(this.working);
    if(committed.curriculum)commitCurriculum(committed.curriculum);
    const next={...this.db,profiles:this.db.profiles.map(p=>p.id===this.working.id?committed:p)};
    if(this.db.gameScores!==undefined||this.scoreTablesChanged)next.gameScores=structuredClone(this.workingScores);
    try {
      if(this.storage.getItem(PROFILE_KEY)!==this.baseRaw)return "Saved browser data changed in another tab. Reopen this page before saving.";
      const raw=JSON.stringify(next);this.storage.setItem(PROFILE_KEY,raw);
      this.db=next;this.baseRaw=raw;this.working=structuredClone(committed);this.saved=structuredClone(committed);this.savedScores=structuredClone(this.workingScores);this.scoreTablesChanged=false;this.dirty=false;return "";
    } catch {return "Session could not be saved. Your changes are still here; return to the menu and try again.";}
  }
  discard(){this.working=structuredClone(this.saved);this.workingScores=structuredClone(this.savedScores);this.scoreTablesChanged=false;this.dirty=false;}
}
