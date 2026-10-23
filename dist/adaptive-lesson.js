import {LineInput,PracticeLesson} from "./practice.js";
import {nextKey,completeNewKey,recordAttempt,recalculateThreshold,rankings,summaryRankings} from "./curriculum.js";
import DATA from "./curriculum-data.js";
import {DrillGenerator} from "./drill-generator.js";
import {speed} from "./scoring.js";
export class AdaptiveLesson extends PracticeLesson{
  constructor(curriculum,drills=10,goal=20,startedAt=new Date().toISOString()){
    super(drills,goal,startedAt);this.curriculum=curriculum;this.initialIntroduced=curriculum.introduced;
    this.generator=new DrillGenerator(curriculum);this.pendingGuide=null;this.tutorial=null;
    recalculateThreshold(curriculum,goal,0);recalculateThreshold(curriculum,goal,1);
    this.prepare();
  }
  prepare(){
    const state=this.curriculum;
    const previousIntroduced=state.introduced;
    const introduction=nextKey(state);
    if((state.introduced!==previousIntroduced&&state.introduced<9)||introduction.shiftLesson){this.generator.fresh=true;this.generator.pointer=null;}
    this.line=new LineInput(this.generator.line());this.focus=rankings(state,this.line.target,0);
    this.line.focus=this.focus;
    if(introduction.shiftLesson)this.pendingGuide={type:"shift"};
    else if(introduction.key&&state.introduced<8){
      this.pendingGuide={type:"home",key:introduction.key};
      completeNewKey(state);
    }else if(introduction.key&&this.line.target.toLowerCase().includes(introduction.key.toLowerCase())){
      this.tutorial={key:introduction.key,count:0,line:new LineInput(this.generator.homeDrill(introduction.key,true))};
    }
  }
  acknowledgeGuide(){this.pendingGuide=null;}
  input(key,now){
    if(this.pendingGuide||this.finished)return {ignored:true};
    if(this.tutorial){
      const event=this.tutorial.line.input(key,now);
      if(event.aborted){completeNewKey(this.curriculum);this.tutorial=null;this.finished=true;this.line.aborted=true;return event;}
      if(event.done){
        this.tutorial.count++;
        if(this.tutorial.count===3){completeNewKey(this.curriculum);this.tutorial=null;return {tutorialDone:true};}
        this.tutorial.line=new LineInput(this.generator.homeDrill(this.tutorial.key));
        return {tutorialLineDone:true};
      }
      return event;
    }
    const before=this.line.attempts.length,event=this.line.input(key,now);
    for(const attempt of this.line.attempts.slice(before))recordAttempt(this.curriculum,attempt);
    if(event.aborted){this.finished=true;return event;}
    if(event.done){
      this.lines.push(this.line);
      if(this.lines.length===this.drills){
        this.finished=true;this.focus=rankings(this.curriculum,this.line.target,0);
        recalculateThreshold(this.curriculum,this.goal,0);recalculateThreshold(this.curriculum,this.goal,1);
        return {...event,lessonDone:true};
      }
      this.prepare();
    }
    return event;
  }
  summary(){
    const {best,worst}=summaryRankings(this.curriculum);
    return {best,worst,above:this.curriculum.current.slice(0,64).filter(s=>speed(s.correct,s.errors,s.time)>=this.goal).length};
  }
  record(){
    return {...super.record(),kind:this.curriculum.introduced>28?"adaptive-keyboard-f4c":"adaptive-alpha-f4",introducedAtStart:this.initialIntroduced,
      introducedAtEnd:this.curriculum.introduced,
      lines:this.lines.map(line=>({target:line.target,focus:line.focus,result:{...line.result},attempts:line.attempts.map(a=>({...a})),observations:line.observations.map(a=>({...a}))})),
      partialObservations:this.lines.includes(this.line)?[]:this.line.observations.map(a=>({...a}))};
  }
}
