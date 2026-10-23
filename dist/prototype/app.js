import {STAGES, makeLines, createSession, input, pause, metrics, summary, qualifies, aggregate} from "./engine.js";
import {load, save} from "./storage.js";

const screen = document.querySelector("#screen");
const loaded = loadSafe();
let data = loaded.data, warning = loaded.warning, view = "menu", selected = 0;
let session = null, lastResult = null, paused = false, savedThisRun = false;
const menu = [["Lessons","Home-row drills and new keys"],["Tests","Three-line practice test"],
  ["Reports","Your progress and per-key accuracy"],["Options","Name, goals and lesson length"],["Help","How to practice"]];
const escape = text => String(text).replace(/[&<>"']/g, c => ({"&":"&amp;","<":"&lt;",">":"&gt;",'"':"&quot;","'":"&#39;"}[c]));
function loadSafe() { try { return load(localStorage); } catch { return load({ getItem() { throw Error(); } }); } }
function persist() {
  try { warning = save(localStorage, data); }
  catch { warning = "Progress could not be saved. Keep this page open to retain the session."; }
  showNotice();
}
function showNotice() {
  const n=document.querySelector("#notice"); n.hidden=!warning; n.textContent=warning;
}
function setView(name,title,help="Esc Main Menu · Tab Move focus") {
  view=name; document.querySelector("#screen-name").textContent=title;
  document.querySelector("#student").textContent=data.name;
  document.querySelector("#key-help").textContent=help; showNotice();
}
function button(label,action,primary=false) {
  return '<button type="button" class="action '+(primary?'primary':'')+'" data-action="'+action+'">'+label+'</button>';
}
function goMenu() {
  session=null; paused=false; setView("menu","Main Menu","↑ ↓ Choose · Enter Open · L T R O H");
  const total=aggregate(data.history);
  screen.innerHTML='<div class="eyebrow">A LITTLE PRACTICE, EVERY DAY.</div><h1>Make the keyboard<br>second nature.</h1><p class="intro">Find your home keys. Build a steady rhythm.<br>Let speed follow accuracy.</p>'+
    '<div class="home-grid"><nav class="menu" aria-label="Main menu">'+menu.map(([label,desc],i)=>
    '<button data-menu="'+i+'" class="'+(i===selected?'selected':'')+'"><span class="shortcut">'+label[0]+'</span><span>'+label+'</span><span class="arrow">→</span></button>').join("")+
    '</nav><aside class="side-panel"><div class="eyebrow">YOUR PRACTICE DESK</div><div class="stat-row"><span>Current lesson</span><strong>'+escape(STAGES[data.stage].name)+'</strong></div><div class="stat-row"><span>Speed goal</span><strong>'+data.goal+' WPM</strong></div><div class="stat-row"><span>Completed</span><strong>'+data.history.length+' exercises</strong></div><hr class="rule"><p class="hint">'+(data.history.length?'Your overall accuracy is '+total.accuracy.toFixed(1)+'%. Keep showing up.':'Start with Lessons. Rest your fingers on A S D F and J K L ;.')+'</p></aside></div>';
}
function openMenu(i) {
  selected=i;
  [()=>start("lesson"),()=>start("test"),reports,options,help][i]();
}
function start(mode) {
  session=createSession(makeLines(data.stage,mode==="test"?3:data.drills),mode,data.stage);
  paused=false; savedThisRun=false; lastResult=null; drawExercise();
}
function drawExercise() {
  setView("exercise",session.mode==="lesson"?"Practice Lesson":"Practice Test","Type the text · Backspace Correct · Esc Pause");
  const line=session.lines[session.row], m=metrics(session,performance.now());
  const end=session.typed.length===line.length;
  screen.innerHTML='<div class="top-row"><div><div class="eyebrow">'+escape(STAGES[session.stage].name)+'</div><h2>'+(session.mode==="lesson"?'Build your rhythm.':'Put your practice to the test.')+'</h2></div><span class="hint">LINE '+(session.row+1)+' / '+session.lines.length+'</span></div>'+
    '<p class="hint">'+escape(STAGES[session.stage].hint)+'</p><div class="progress-track"><span></span></div>'+
    '<div class="exercise" id="typing-area" tabindex="0" role="group" aria-label="Typing exercise. Type the displayed line.">'+
    '<div class="line" aria-label="'+escape(line)+'">'+[...line].map((char,i)=>
      '<span class="char '+(i<session.typed.length?(session.typed[i]===char?'hit':'miss'):i===session.typed.length?'current':'')+'">'+escape(char)+'</span>').join("")+
    '<span class="char '+(end?'current':'')+'">&nbsp;</span></div><div class="line-done">'+(end?'Line complete. Press Enter or Space to continue.':'Follow the ▲ pointer. Errors are marked with ▼.')+'</div></div>'+
    '<div class="metrics"><div class="metric"><span>SPEED</span><strong id="speed">'+m.wpm.toFixed(0)+'</strong> WPM</div><div class="metric"><span>ACCURACY</span><strong id="accuracy">'+m.accuracy.toFixed(1)+'</strong> %</div><div class="metric"><span>ELAPSED</span><strong id="elapsed">'+(m.elapsedMs/1000).toFixed(0)+'</strong> s</div></div>'+
    '<div class="keyboard" aria-hidden="true">'+[..."asdfjkl;"].map(k=>'<span class="key learned '+(!end&&line[session.typed.length]===k?'target':'')+'">'+k.toUpperCase()+'</span>').join("")+'</div>'+
    '<p class="hint">Timing begins on your first character. Accuracy remembers corrected mistakes.</p>'+button("Pause [Esc]","pause");
  screen.querySelector(".progress-track span").style.width=(session.row/session.lines.length*100)+"%";
  screen.querySelector("#typing-area").focus({preventScroll:true});
}
function pauseExercise() {
  pause(session,performance.now()); paused=true;
  setView("paused","Practice Paused","Enter Resume · Esc Main Menu");
  screen.innerHTML='<div class="eyebrow">TAKE YOUR TIME</div><h1>Practice paused.</h1><div class="paused"><p>The timer is stopped. Your current line is waiting.</p>'+button("Resume [Enter]","resume",true)+button("Discard exercise","discard")+'</div><p class="hint">Only completed exercises are saved to your progress.</p>';
  screen.querySelector("button").focus();
}
function finish() {
  if(savedThisRun) return;
  lastResult=summary(session,performance.now()); savedThisRun=true;
  data.history.push(lastResult);
  const advance=qualifies(lastResult,data.goal)&&data.stage<STAGES.length-1;
  if(advance) data.stage++;
  persist();
  setView("results","Exercise Results","Enter Practice again · Esc Main Menu");
  const r=lastResult;
  screen.innerHTML='<div class="eyebrow">'+(advance?'NEXT LESSON UNLOCKED':'EXERCISE COMPLETE')+'</div><h1>'+ (r.accuracy>=95?'Steady hands. Good work.':'Keep accuracy in focus.')+'</h1><p class="intro">'+(advance?'Next up: '+escape(STAGES[data.stage].name)+'.':'Aim for 95% accuracy and '+data.goal+' WPM to advance after a lesson.')+'</p>'+
    '<div class="metrics"><div class="metric"><span>SPEED</span><strong>'+r.wpm.toFixed(1)+'</strong> WPM</div><div class="metric"><span>ACCURACY</span><strong>'+r.accuracy.toFixed(1)+'</strong> %</div><div class="metric"><span>PRACTICE TIME</span><strong>'+(r.elapsedMs/1000).toFixed(1)+'</strong> s</div></div>'+
    '<p class="hint">'+r.correct+' correct of '+r.attempts+' character attempts · '+r.lines+' lines completed</p>'+
    button("Practice again [Enter]","again",true)+button("View reports","reports")+button("Main Menu [Esc]","menu");
  screen.querySelector("button").focus();
}
function reports() {
  setView("reports","Progress Report");
  const a=aggregate(data.history), recent=data.history.slice(-10).reverse();
  screen.innerHTML='<div class="eyebrow">EVERY SESSION ADDS UP</div><h1>Your progress.</h1>'+
    (recent.length?'<div class="metrics"><div class="metric"><span>OVERALL SPEED</span><strong>'+a.wpm.toFixed(1)+'</strong> WPM</div><div class="metric"><span>OVERALL ACCURACY</span><strong>'+a.accuracy.toFixed(1)+'</strong> %</div><div class="metric"><span>COMPLETED</span><strong>'+data.history.length+'</strong></div></div>'+
    '<h2>Recent exercises</h2><div class="table-scroll"><table><thead><tr><th>Date</th><th>Exercise</th><th>WPM</th><th>Accuracy</th></tr></thead><tbody>'+
    recent.map(r=>'<tr><td>'+escape(new Date(r.date).toLocaleDateString())+'</td><td>'+escape(STAGES[r.stage].name)+' · '+r.mode+'</td><td>'+r.wpm.toFixed(1)+'</td><td>'+r.accuracy.toFixed(1)+'%</td></tr>').join("")+'</tbody></table></div>'+
    '<h2>Accuracy by expected key</h2><div class="table-scroll"><table><thead><tr><th>Key</th><th>Attempts</th><th>Accuracy</th><th> </th></tr></thead><tbody>'+
    Object.entries(a.perKey).sort(([a],[b])=>a.localeCompare(b)).map(([k,v])=>{
      const pct=v.correct/v.attempts*100;
      return '<tr><td>'+escape(k===" "?"Space":k.toUpperCase())+'</td><td>'+v.attempts+'</td><td>'+pct.toFixed(1)+'%</td><td><div class="bar"><span style="width:'+pct+'%"></span></div></td></tr>';
    }).join("")+'</tbody></table></div>':'<p class="intro">Your practice story starts here. Complete a lesson or test to see your results and per-key accuracy.</p>')+
    button("Start a lesson","lesson",true)+button("Export progress","export")+button("Main Menu [Esc]","menu");
}
function options() {
  setView("options","Options");
  screen.innerHTML='<div class="eyebrow">MAKE IT YOUR PRACTICE</div><h1>Set a comfortable pace.</h1><form id="settings">'+
    '<label>Your name<input name="name" maxlength="24" required value="'+escape(data.name)+'" autocomplete="nickname"></label>'+
    '<label>Speed goal (5–150 WPM)<input name="goal" type="number" min="5" max="150" step="1" required value="'+data.goal+'"></label>'+
    '<label>Drills per lesson (1–20)<input name="drills" type="number" min="1" max="20" step="1" required value="'+data.drills+'"></label>'+
    '<label>Practice level<select name="stage">'+STAGES.map((s,i)=>'<option value="'+i+'" '+(i===data.stage?'selected':'')+'>'+escape(s.name)+'</option>').join("")+'</select></label>'+
    '<button class="action primary" type="submit">Save options</button>'+button("Cancel [Esc]","menu")+'</form>';
}
function help() {
  setView("help","Help");
  screen.innerHTML='<div class="eyebrow">THE HOME ROW IS HOME BASE</div><h1>Accuracy first. Speed follows.</h1><ul class="help-list">'+
    '<li><strong>Find your position.</strong> Left fingers on A S D F; right fingers on J K L ;. Feel the bumps on F and J.</li>'+
    '<li><strong>Follow the pointer.</strong> Type the displayed line. A mistake advances the pointer and gets a ▼ marker. Use Backspace to revisit it.</li>'+
    '<li><strong>Finish each line.</strong> Press Enter or Space after its final character. The timer starts on your first character and includes line review.</li>'+
    '<li><strong>Take a break.</strong> Escape pauses; switching tabs also pauses. Enter resumes. Leaving an unfinished exercise discards it.</li>'+
    '<li><strong>Read your results.</strong> WPM = correct character attempts ÷ 5 ÷ active minutes. Accuracy = correct attempts ÷ all attempts. Corrections do not erase earlier errors.</li>'+
    '<li><strong>Build your skills.</strong> Complete a lesson at 95% accuracy and your WPM goal to advance. You can select any level in Options.</li>'+
    '<li><strong>Keep your progress.</strong> Completed exercises save in this browser. Export a JSON copy from Reports. Browser storage settings affect retention.</li></ul>'+
    '<p class="hint">This first version re-creates the teaching workflow. Original scoring and adaptive rules are still being investigated. Keypad, custom texts and Letter Invaders are planned.</p>'+button("Start a lesson","lesson",true)+button("Main Menu [Esc]","menu");
}
document.addEventListener("click",e=>{
  const menuButton=e.target.closest("[data-menu]");
  if(menuButton) {openMenu(Number(menuButton.dataset.menu));return;}
  const action=e.target.closest("[data-action]")?.dataset.action;
  if(!action)return;
  const actions={menu:goMenu,discard:goMenu,lesson:()=>start("lesson"),reports,pause:pauseExercise,
    resume:()=>{paused=false;drawExercise();},again:()=>start(lastResult.mode),export:()=>{
      const url=URL.createObjectURL(new Blob([JSON.stringify(data,null,2)],{type:"application/json"}));
      const link=document.createElement("a");link.href=url;link.download="type-tutor-progress.json";link.click();
      setTimeout(()=>URL.revokeObjectURL(url),1000);
    }};
  actions[action]?.();
});
document.addEventListener("submit",e=>{
  if(e.target.id!=="settings")return;
  e.preventDefault(); const form=new FormData(e.target),name=String(form.get("name")).trim();
  if(!name){e.target.elements.name.setCustomValidity("Please enter your name.");e.target.elements.name.reportValidity();return;}
  data={...data,name,goal:Number(form.get("goal")),drills:Number(form.get("drills")),stage:Number(form.get("stage"))};
  persist();goMenu();
});
document.addEventListener("input",e=>{if(e.target.name==="name")e.target.setCustomValidity("");});
document.addEventListener("keydown",e=>{
  if(e.ctrlKey||e.metaKey||e.altKey||e.isComposing)return;
  if(view==="exercise") {
    if(e.key==="Escape"){e.preventDefault();pauseExercise();return;}
    if(e.key==="Tab")return;
    if(e.target.closest("button"))return;
    if(e.repeat){e.preventDefault();return;}
    const result=input(session,e.key,performance.now());
    if(result!=="ignored"){e.preventDefault();if(result==="finished")finish();else drawExercise();}
    else if(e.key===" "||e.key==="Enter")e.preventDefault();
    return;
  }
  if(e.key==="Escape"){e.preventDefault();goMenu();return;}
  if(view==="paused"&&e.key==="Enter"&&!e.target.closest("button")){e.preventDefault();paused=false;drawExercise();return;}
  if(view==="results"&&e.key==="Enter"&&!e.target.closest("button")){e.preventDefault();start(lastResult.mode);return;}
  if(view!=="menu")return;
  if(e.key==="ArrowDown"||e.key==="ArrowUp"){
    e.preventDefault();selected=(selected+(e.key==="ArrowDown"?1:-1)+menu.length)%menu.length;goMenu();
    screen.querySelector('[data-menu="'+selected+'"]').focus();return;
  }
  if(e.key==="Enter"&&!e.target.closest("button")){e.preventDefault();openMenu(selected);return;}
  const index=menu.findIndex(([label])=>label[0].toLowerCase()===e.key.toLowerCase());
  if(index>=0){e.preventDefault();openMenu(index);}
});
document.addEventListener("visibilitychange",()=>{if(document.hidden&&view==="exercise"&&!paused)pauseExercise();});
window.addEventListener("blur",()=>{if(view==="exercise"&&!paused)pauseExercise();});
setInterval(()=>{
  if(view!=="exercise")return;
  const m=metrics(session,performance.now());
  document.querySelector("#speed").textContent=m.wpm.toFixed(0);
  document.querySelector("#elapsed").textContent=(m.elapsedMs/1000).toFixed(0);
},250);
goMenu();
