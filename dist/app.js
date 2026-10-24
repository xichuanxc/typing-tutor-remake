import {InvadersGame,invadersTick} from "./invaders.js";
import WELCOME from "./welcome-data.js";
import GAME from "./invaders-data.js";
import {GameAudio} from "./game-audio.js";
import {shouldShowWelcome,WelcomeSequence,drawWelcome,welcomeNotes} from "./welcome.js";
import {drawGameSetup,drawSecondName,drawRoundReady,drawGame,drawGameOver,drawScores} from "./invaders-screen.js";
import {DiskTest} from "./disk-test.js";
import DISK from "./disk-data.js";
import {drawDiskPicker,prepareDiskFiles} from "./disk-screen.js";
import {createCurriculum} from "./curriculum.js";
import {FingeringReview,drawFingering} from "./fingering.js";
import {KeypadLesson,KeypadTest} from "./keypad.js";
import KEYPAD from "./keypad-data.js";
import {drawKeypadIntro,drawKeypadActivity,drawKeypadSummary} from "./keypad-screen.js";
import DATA from "./original-data.js";
import {Grid,PALETTE,wrap,choiceLayout} from "./grid.js";
import {StudentSession,PROFILE_KEY,LEGACY_KEY,validName,clearBrowserData} from "./faithful-session.js";

import {browserClock} from "./practice.js";
import {AdaptiveLesson} from "./adaptive-lesson.js";
import CURRICULUM from "./curriculum-data.js";
import {drawKeyboard,drawTutorial} from "./keyboard-screen.js";
import {drawPractice} from "./practice-screen.js";
import {TypingTest} from "./typing-test.js";
import {progressModel,graphModel,testSummary} from "./reports-model.js";
import REPORT from "./report-data.js";
import {drawProgress,drawGraph,drawTest} from "./report-screen.js";

const terminal=document.querySelector("#terminal"), cells=document.querySelector("#cells");
const resetDialog=document.querySelector("#reset-dialog"),resetError=document.querySelector("#reset-error");
let resetting=false;
const controls=document.querySelector("#controls"), title=document.querySelector("#screen-title");
let storage;
try {storage=localStorage;} catch {storage={getItem(){throw Error("Storage unavailable");},setItem(){throw Error("Storage unavailable");}};}
const student=new StudentSession(storage), grid=new Grid();
const state={mode:"menu",menu:0,selected:0,dialog:null,page:0,pages:[],readerTitle:"",returnMenu:0,
  idle:false,warning:student.warning,name:"",nameError:"",message:"",messageTitle:""};
let idleTimer, audio, lesson, testSession, fingering, keypadSession, diskSession;
let diskFiles=[],diskLoadToken=0;
let gameSession=null,gameFrame=null;
let welcome=null,welcomeFrame=null,welcomeStartedAt=0;
const spanNodes=[];
for(let row=0;row<25;row++){
  const line=document.createElement("div");line.className="row";line.dataset.row=row;
  for(let col=0;col<80;col++){
    const cell=document.createElement("span");cell.className="cell";cell.dataset.col=col;
    line.append(cell);spanNodes.push(cell);
  }
  cells.append(line);
}
function resize(){
  const scale=Math.max(.25,Math.min((innerWidth-32)/768,(innerHeight-128)/500,1.6));
  document.documentElement.style.setProperty("--screen-scale",scale);
}
window.addEventListener("resize",resize);resize();
function announce(message){document.querySelector("#screen-status").textContent=message;}
function audioContext(){
  audio??=new (window.AudioContext||window.webkitAudioContext)();
  if(audio.state==="suspended")audio.resume().catch(()=>{});
  return audio;
}
const gameAudio=new GameAudio(audioContext);
const welcomeAudio=new GameAudio(audioContext);
function beep(){
  if(!student.working.sound)return;
  try{
    audioContext();
    const tone=audio.createOscillator(),gain=audio.createGain();
    tone.type="square";tone.frequency.value=660;gain.gain.value=.025;
    tone.connect(gain);gain.connect(audio.destination);tone.start();tone.stop(audio.currentTime+.055);
  }catch{/* Audio support is optional; the setting remains usable. */}
}
function startWelcome(){
 if(!welcome||welcome.phase!=="ready")return;
 if(student.working.sound)welcomeAudio.unlock();
 welcome.start();welcomeStartedAt=performance.now();render();
 const frame=()=>{
  welcomeFrame=null;if(state.mode!=="welcome")return;
  const before=[welcome.phase,welcome.line,welcome.index,welcome.logoFrame].join(":");
  welcome.advance(performance.now()-welcomeStartedAt);
  const events=welcome.drainEvents();
  if(welcome.phase==="done"){finishWelcome();return;}
  if(student.working.sound){
   if(events.some(event=>event.type==="music"))welcomeAudio.startNotes(welcomeNotes(),"welcome");
   else if(events.some(event=>event.type==="wrong"))welcomeAudio.play("wrong");
  }
  if(before!==[welcome.phase,welcome.line,welcome.index,welcome.logoFrame].join(":"))render(false);
  welcomeFrame=requestAnimationFrame(frame);
 };
 welcomeFrame=requestAnimationFrame(frame);
}
function finishWelcome(){
 if(welcomeFrame!==null){cancelAnimationFrame(welcomeFrame);welcomeFrame=null;}
 welcomeAudio.stop();welcome.phase="done";openRegistration();
}
function welcomeScreen(){
 title.textContent="Welcome to Typing Tutor IV";
 drawWelcome(grid,welcome);
 hotspot(welcome.phase==="ready"?"Play welcome":"Continue to registration",24,0,80,()=>{
  if(welcome.phase==="ready")startWelcome();else finishWelcome();
 });
}
function footer(text,escape=true){
  grid.fill(24,0x5e);
  const label=(escape?"Esc -> ":"")+text;
  grid.put(24,Math.trunc((80-label.length)/2),label,0x5e);
}
function header(text,returnTo="Main Menu",escape=true,name=student.working.name){
  grid.clear();grid.put(0,0," "+text);
  grid.put(0,79-name.length,name);
  grid.put(1,0,"═".repeat(80));footer(returnTo,escape);
  title.textContent=text;
}
function hotspot(label,row,col,width,callback,options={}){
  const button=document.createElement("button");
  button.type="button";button.className="hotspot";button.setAttribute("aria-label",label);
  if(options.role)button.setAttribute("role",options.role);
  if(options.selected!==undefined)button.setAttribute(options.role==="option"?"aria-selected":"aria-current",String(options.selected));
  button.style.cssText="top:"+row*20+"px;left:"+col*9.6+"px;width:"+width*9.6+"px;height:20px";
  button.addEventListener("click",callback);
  controls.append(button);return button;
}
function paint(){
  let index=0;
  // Merge vertically adjacent background runs. One rectangle has no seams
  // between logical rows when the whole 80x25 screen is fractionally scaled.
  const base=(grid.cells[0][0].attr>>4)&7,rectangles=[],active=new Map();
  for(const [rowIndex,row] of grid.cells.entries()){
    let start=0;
    const present=new Set();
    for(let col=1;col<=80;col++){
      if(col===80||((row[col].attr>>4)&7)!==((row[start].attr>>4)&7)){
        const color=(row[start].attr>>4)&7,key=start+":"+col+":"+color;
        if(color!==base){
          present.add(key);let rect=active.get(key);
          if(!rect||rect.top+rect.height!==rowIndex){rect={left:start,width:col-start,top:rowIndex,height:0,color};rectangles.push(rect);}
          rect.height++;active.set(key,rect);
        }
        start=col;
      }
    }
    for(const key of active.keys())if(!present.has(key))active.delete(key);
    cells.children[rowIndex].style.backgroundColor="transparent";
    cells.children[rowIndex].style.backgroundImage="none";
    for(const {char,attr} of row){
      const span=spanNodes[index++];if(span.textContent!==char)span.textContent=char;
      span.dataset.attr=attr.toString(16).padStart(2,"0");
      span.style.color=PALETTE[attr&15];
    }
  }
  cells.style.backgroundColor=PALETTE[base];
  cells.style.backgroundImage=rectangles.map(r=>"linear-gradient("+PALETTE[r.color]+","+PALETTE[r.color]+")").join(",")||"none";
  cells.style.backgroundPosition=rectangles.map(r=>(r.left*9.6)+"px "+(r.top*20)+"px").join(",");
  cells.style.backgroundSize=rectangles.map(r=>(r.width*9.6)+"px "+(r.height*20)+"px").join(",");
  cells.style.backgroundRepeat="no-repeat";
  document.querySelector("#screen-text").textContent=grid.lines().map(line=>line.trimEnd()).join("\n");
  terminal.dataset.mode=state.mode;terminal.dataset.menu=state.menu;
  terminal.dataset.welcomePhase=welcome?.phase??"";
  terminal.dataset.selected=state.mode==="choice"?state.dialog.selected:state.selected;
  terminal.dataset.dirty=String(student.dirty);
  terminal.dataset.testType=state.testType??"";
  terminal.dataset.line=testSession?String(Math.min(testSession.activeLine,5)):"";
  terminal.dataset.reportKind=state.reportKind??"";
  terminal.dataset.gamePhase=gameSession?.phase??"";
  terminal.dataset.gameRound=String(gameSession?.round??0);
  terminal.dataset.gamePlayer=String(gameSession?.player??0);
  terminal.dataset.gameScore=String(gameSession?.score??0);
  terminal.dataset.gameState=JSON.stringify(gameSession?.snapshot??null);
  terminal.dataset.diskTarget=diskSession?.line?.target??"";
  terminal.dataset.diskPage=String(diskSession?.page??0);
  terminal.dataset.diskLine=String(diskSession?.activeLine??0);
  terminal.dataset.diskFilename=diskSession?.name??"";
  terminal.dataset.fingeringTutorial=String(!!fingering?.tutorial);
  terminal.dataset.fingeringTarget=fingering?.tutorial?.line.target??"";
  terminal.dataset.keypadTarget=(keypadSession?.tutorial?.line??keypadSession?.line)?.target??"";
  terminal.dataset.keypadEntry=String(keypadSession?.tutorial?.activeEntry??keypadSession?.activeEntry??0);
  terminal.dataset.keypadActivity=keypadSession?.activity??"";
  terminal.dataset.keypadDrill=String((keypadSession?.batches??0)+1);
  document.querySelector("#session-note").textContent=state.warning||(
    state.mode==="welcome"?(welcome.phase==="ready"?"Welcome · Press a key or click the prompt to start · Esc: skip":"Welcome · Any key or click the prompt: Registration"):
    state.mode==="registration"?"Registration · Type your name · Enter: continue · Esc: exit":
    state.mode==="game-playing"?"Letter Invaders · Type exact letters / words · Esc: surrender this player":
    ["game-ready","game-round"].includes(state.mode)?"Letter Invaders · Any key: begin round · Esc: Main Menu":
    state.mode==="game-scores"?"Score board · Esc: Main Menu":
    state.mode.startsWith("game")?"Letter Invaders · Choose next activity · Quit to save":
    state.mode==="disk-picker"?"Disk Test · Choose local test files below · Up / Down: choose · Enter: start":
    state.mode==="disk-test"?"Disk Test · Screen "+(diskSession.page+1)+" · Enter / Space: end line · "+(diskSession.source.format==="rotated"?"Esc: typing error":"Esc: return"):
    state.mode==="disk-test-result"?"Disk Test complete · Choose next activity · Quit to save":
    ["disk-loading","disk-error"].includes(state.mode)?(state.diskError||"Reading local test file..."):
    state.mode==="fingering"?"Fingering review · Choose a key · Esc: return":
    state.mode.startsWith("keypad")?(keypadSession.activity==="test"?"Keypad Test":"Keypad Lesson")+" · Plus / Enter: end number · Esc: return":
    state.mode==="test"?testTitle()+" · Line "+(testSession.activeLine+1)+" / 6 · Enter / Space: end line · Esc: return":
    state.mode==="test-summary"?"Test complete · Choose next activity · Quit to save":
    state.mode==="report"?"Reports · Any key: next report · Esc: Main Menu"+(state.reportLimited?" · Earlier category breakdown unavailable":""):
    ["practice","home-practice","guide","lesson-end","summary"].includes(state.mode)?"Original keyboard curriculum · Drill "+Math.min(lesson.lines.length+1,lesson.drills)+" / "+lesson.drills+(state.mode==="summary"?" · Esc: quit":state.mode==="lesson-end"?" · Any key: summary":state.mode==="guide"?" · Any key: continue":" · Esc: return"):
    student.dirty?"Session changed · Quit to save settings and practice":
    state.mode==="choice"?"Up / Down or Space: choose · Enter: accept · Esc: cancel":
    "Left / Right or Space: choose · Enter: select · Esc: return");
}
function paragraph(text,row,col,width,attr=0x1f,maxRow=23){
  for(const line of wrap(text,width)){if(row>maxRow)break;grid.put(row++,col,line,attr);}
  return row;
}
function resetIdle(){
  clearTimeout(idleTimer);state.idle=false;
  if(state.mode==="menu")idleTimer=setTimeout(()=>{state.idle=true;render(false);},5000);
}
function menuScreen(){
  const menu=DATA.menus[state.menu], item=menu.items[state.selected];
  header(menu.title,state.menu===0?"Exit Typing Tutor IV":"Main Menu");
  grid.fill(3,0x5f);grid.fill(4,0x5e);
  for(const [i,entry] of menu.items.entries()){
    grid.put(3,entry.column,entry.label+"  ",i===state.selected?0x5e:0x5f);
    hotspot(entry.label,3,entry.column,entry.label.length,()=>activate(i),{
      selected:i===state.selected,focus:()=>{
        if(state.mode==="menu"&&state.selected!==i){state.selected=i;state.idle=false;render(false);}
      }});
  }
  if(item.submenu_index!==undefined)
    grid.put(4,0,DATA.menus[item.submenu_index].items.map(i=>i.label+"  ").join(""),0x5e);
  else grid.put(4,0,item.description,0x5e);
  if(state.idle){
    grid.box(7,3,21,76);
    let row=8;
    for(const text of [DATA.idle[0]+DATA.idle[1],DATA.idle[2],DATA.idle[3]]){
      row=paragraph(text,row,5,70,0x1f,20)+1;
    }
  }
}
function activate(index){
  clearTimeout(idleTimer);const menu=DATA.menus[state.menu];state.selected=index;
  const item=menu.items[index];
  if(item.submenu_index!==undefined){state.menu=item.submenu_index;state.selected=0;state.mode="menu";resetIdle();render();return;}
  if(item.label==="Quit"){quit();return;}
  if(item.label==="Help"){openHelp(state.menu);return;}
  if(state.menu===4){openOption(item.label);return;}
  if(state.menu===5&&item.label==="Play"){openGameSetup();return;}
  if(state.menu===5&&item.label==="Scores"){openGameScores();return;}
  if(state.menu===1&&item.label==="Fingering"){startFingering();return;}
  if((state.menu===1||state.menu===2)&&item.label==="Keypad"){startKeypad(state.menu===2?"test":"lesson");return;}
  if(state.menu===1&&item.label==="Practice"){startPractice();return;}
  if(state.menu===2&&item.label==="Disk"){openDiskPicker();return;}
  if(state.menu===2&&["Practice","All-keys"].includes(item.label)){startTest(item.label==="Practice"?"practice":"all-keys");return;}
  if(state.menu===3&&["Progress","Speed","Accuracy"].includes(item.label)){openReport(item.label.toLowerCase());return;}
  state.returnMenu=state.menu;state.mode="message";state.messageTitle=item.description;
  state.message=item.label+" is planned for the next practice delivery. The earlier typing prototype remains available below this screen.";
  render();announce(state.message);
}
const optionConfig={
  WPM:{key:"wpm",title:DATA.optionTitles.wpm,width:9,labels:DATA.choices.wpm.map(i=>i.label),
    values:DATA.choices.wpm.map(i=>i.stored_min_wpm),prompt:DATA.prompts.wpm},
  Time:{key:"weekly",title:DATA.optionTitles.weekly,width:8,labels:DATA.choices.weekly_time.map(i=>i.label),
    values:DATA.choices.weekly_time.map(i=>i.index),prompt:DATA.prompts.weekly_time},
  Drills:{key:"drills",title:DATA.optionTitles.drills,width:3,labels:DATA.choices.drills.map(n=>String(n).padStart(2)),
    values:DATA.choices.drills,prompt:DATA.prompts.drills},
  Sound:{key:"sound",title:DATA.optionTitles.sound,width:9,labels:DATA.choices.sound,
    values:[true,false],prompt:DATA.prompts.sound}
};
function openOption(label){
  if(label==="Intro"){openReader(DATA.help[0],DATA.optionTitles.intro,4);return;}
  if(label==="Name"){
    state.mode="name";state.name="";state.nameError="";render();return;
  }
  const c=optionConfig[label];
  if(!c)return;
  state.mode="choice";state.dialog={...c,selected:c.values.indexOf(student.working[c.key]),kind:"option"};
  render();announce(c.title+". "+c.labels[state.dialog.selected]);
}
function choiceScreen(){
  const d=state.dialog;
  header(d.title,d.kind==="quit"?"":"Main Menu",d.kind!=="quit");
  if(d.kind==="quit")grid.fill(24,0x1f);
  const g=choiceLayout(d.labels.length,d.width,d.prompt);
  grid.box(g.top,g.left,g.bottom,g.right);
  paragraph(d.prompt,g.promptTop+1,g.left+4,g.right-g.left-7,0x1f,g.listTop-2);
  const instruction="..press Enter to select highlighted item.";
  grid.put(g.instructionRow,g.right-1-instruction.length,instruction);
  grid.box(g.listTop,g.listLeft,g.listBottom,g.listRight,0x2f,true);
  const list=document.createElement("div");list.setAttribute("role","listbox");list.setAttribute("aria-label",d.title);controls.append(list);
  for(const [i,label] of d.labels.entries()){
    const attr=i===d.selected?0x1a:0x29;
    grid.put(g.listTop+i+1,g.listLeft+1,(" "+label).padEnd(d.width+1),attr);
    const b=hotspot(label,g.listTop+i+1,g.listLeft+1,d.width+1,()=>{d.selected=i;acceptChoice();},
      {role:"option",selected:i===d.selected,focus:()=>{if(d.selected!==i){d.selected=i;render(false);}}});
    list.append(b);
  }
  if(state.warning)paragraph(state.warning,21,4,72,0x1e,23);
}
function acceptChoice(){
  const d=state.dialog;
  if(d.kind==="quit"){
    if(d.selected===2){state.warning="";goMenu(0);return;}
    if(d.selected===0){const error=student.commit();if(error){state.warning=error;beep();render();announce(error);return;}}
    else student.discard();
    state.warning="";state.mode="exited";state.dialog=null;render();return;
  }
  student.change(d.key,d.values[d.selected]);
  if(d.key==="sound")beep();
  state.dialog=null;goMenu(4,false);
}
function quit(){
  if(!student.dirty){state.mode="exited";clearTimeout(idleTimer);render();return;}
  state.mode="choice";state.dialog={kind:"quit",title:DATA.quit.title,prompt:DATA.quit.prompt,
    labels:DATA.quit.choices,width:29,selected:0};render();announce(DATA.quit.prompt);
}
function openRegistration(){
  clearTimeout(idleTimer);state.mode="registration";state.name="";state.nameError="";render();
}
function nameScreen(){
  if(state.mode==="registration")header(WELCOME.registration.title,WELCOME.registration.exit,true,"");
  else header(DATA.optionTitles.name);
  grid.box(9,17,17,62);grid.put(10,19,WELCOME.registration.prompt);
  grid.put(13,27,"_".repeat(25));
  grid.put(15,42,"..then press Enter.");
  if(state.nameError)paragraph(state.nameError,19,5,70,0x1e,22);
  const input=document.createElement("input");input.id="name-entry";input.type="text";input.maxLength=25;
  input.setAttribute("aria-label","Student name");input.autocomplete="off";input.spellcheck=false;
  input.style.top="260px";input.style.left=(27*9.6)+"px";input.value=state.name;input.placeholder="_".repeat(25);
  input.addEventListener("input",()=>{
    const clean=filterName(input.value);if(clean!==input.value)beep();input.value=clean;state.name=clean;
    state.nameError="";
  });
  controls.append(input);
}
function filterName(text){
  let output="";
  for(const char of text){
    if(output.length===25)break;
    if((output?/^[A-Za-z0-9 .,\x27-]$/:/^[A-Za-z0-9.,']$/).test(char))output+=char;
  }
  return output;
}
function acceptName(){
  const registering=state.mode==="registration";
  const error=registering?student.register(state.name):student.rename(state.name);
  if(error){state.nameError=error;beep();render();announce(error);return;}
  goMenu(registering?0:4,registering);
}
const helpIndex={0:6,1:1,2:2,3:3,4:4,5:7};
function paginate(paragraphs){
  const pages=[];let current=[];
  for(const text of paragraphs){
    const lines=wrap(text,70);
    if(current.length&&current.length+lines.length+1>15){pages.push(current);current=[];}
    if(current.length)current.push("");
    for(const line of lines){
      if(current.length===15){pages.push(current);current=[];}
      current.push(line);
    }
  }
  if(current.length)pages.push(current);
  return pages;
}
function openHelp(menu){
  openReader(DATA.help[helpIndex[menu]],"Information about "+DATA.menus[menu].title,menu);
}
function openReader(paragraphs,heading,back){
  clearTimeout(idleTimer);state.mode="reader";state.pages=paginate(paragraphs);state.page=0;
  state.readerTitle=heading;state.returnMenu=back;render();
  announce(heading+". Page 1 of "+state.pages.length);
}
function readerScreen(){
  header(state.readerTitle,"Main Menu");
  grid.box(3,1,22,78);
  state.pages[state.page].forEach((line,i)=>grid.put(5+i,5,line));
  grid.put(21,48,"..press Enter to continue.");
  grid.put(23,3,"Page "+(state.page+1)+" / "+state.pages.length);
  hotspot("Next page",21,48,25,nextPage);
  if(state.page>0)hotspot("Previous page",23,3,18,()=>{state.page--;render();});
}
function nextPage(){
  if(state.page+1<state.pages.length){state.page++;render();announce("Page "+(state.page+1)+" of "+state.pages.length);}
  else goMenu(state.returnMenu,false);
}
function messageScreen(){
  header(state.messageTitle,"Main Menu");
  grid.box(8,6,16,74);
  paragraph(state.message,10,10,60);
  grid.put(15,43,"..press Enter to return.");
  hotspot("Return to menu",15,43,25,()=>goMenu(state.returnMenu,false));
}
function exitScreen(){
  grid.clear(0x07);title.textContent="Typing Tutor IV — session ended";
  grid.put(9,22,"Thank you for using Typing Tutor IV.",0x07);
  grid.put(12,25,"Press Enter to begin again.",0x07);
  hotspot("Begin again",12,25,26,restart);
}
function restart(){student.restart();state.warning="";if(shouldShowWelcome(storage,student))openRegistration();else goMenu(0);}
function goMenu(menu=0,resetSelection=true){
  stopGameClock();
  state.mode="menu";state.menu=menu;state.dialog=null;
  if(resetSelection)state.selected=0;
  state.selected=Math.min(state.selected,DATA.menus[menu].items.length-1);
  resetIdle();render();announce(DATA.menus[menu].title+". "+DATA.menus[menu].items[state.selected].label);
}



function stopGameClock(){if(gameFrame!==null){cancelAnimationFrame(gameFrame);gameFrame=null;}gameAudio.stop();}
function openGameSetup(){
  stopGameClock();clearTimeout(idleTimer);gameSession=null;
  state.mode="game-setup";state.selected=0;state.gameMode="practice";state.gameNameError="";
  render();announce(GAME.modePrompt);
}
function gameSetupScreen(){
  const kind=state.mode==="game-setup"?"mode":"players";
  header(kind==="mode"?GAME.levelTitle:GAME.playersTitle,GAME.gameMenu);
  const g=drawGameSetup(grid,kind,state.selected);
  g.labels.forEach((label,i)=>hotspot(label,g.listTop+i+1,g.listLeft+1,g.width+1,()=>{state.selected=i;acceptGameSetup();},{role:"option",selected:i===state.selected}));
}
function acceptGameSetup(){
  if(state.mode==="game-setup"){
    state.gameMode=state.selected===0?"practice":"full";state.mode="game-players";state.selected=0;render();return;
  }
  if(state.selected===1){state.mode="game-name";state.gameSecondName??="";render();return;}
  startInvaders([student.working.name]);
}
function gameNameScreen(){
  header(GAME.secondNamePrompt,GAME.gameMenu);
  const g=drawSecondName(grid,state.gameSecondName??"");
  if(state.gameNameError)grid.put(19,15,state.gameNameError,0x1e);
  const input=document.createElement("input");input.id="game-second-name";input.type="text";input.maxLength=25;
  input.setAttribute("aria-label","Player 2 name");input.autocomplete="off";input.spellcheck=false;
  input.style.top=(g.row*20)+"px";input.style.left=(g.col*9.6)+"px";
  input.style.width=(25*9.6)+"px";input.value=state.gameSecondName??"";input.placeholder="_".repeat(25);
  input.addEventListener("input",()=>{const clean=filterName(input.value);if(clean!==input.value)beep();input.value=clean;state.gameSecondName=clean;state.gameNameError="";});
  controls.append(input);
}
function acceptGameName(){
  if(!validName(state.gameSecondName)){state.gameNameError="Please enter 1 to 25 valid name characters.";beep();render();return;}
  startInvaders([student.working.name,state.gameSecondName]);
}
function startInvaders(players){
  stopGameClock();
  if(student.working.sound)gameAudio.unlock();
  gameSession=new InvadersGame(student.beginAdaptivePractice(),{mode:state.gameMode,players});
  syncGameMode();render();announce("Round 1. Press Enter to begin.");
}
function gameView(){return {...gameSession.snapshot,mode:gameSession.mode==="full"?1:0,lastSummary:gameSession.lastSummary};}
function retainGame(){
  if(!gameSession.recorded){student.recordGame(gameSession.record());gameSession.recorded=true;}
}
function syncGameMode(){
  state.mode=({"ready":"game-ready","playing":"game-playing","level-end":"game-round","game-over":"game-over"})[gameSession.phase];
}
function gameSounds(){
  gameAudio.update(gameSession.drainEvents(),{
    enabled:student.working.sound,playing:gameSession.phase==="playing",
    specialType:gameSession.targets.find(target=>target.type>1)?.type??0
  });
}
function armGameClock(){
  if(gameFrame!==null||state.mode!=="game-playing")return;
  const frame=()=>{
    gameFrame=null;if(state.mode!=="game-playing")return;
    const result=gameSession.step(invadersTick(performance.now()));
    if(!result.ignored){
      gameSounds();syncGameMode();if(gameSession.finished)retainGame();render(false);
    }
    if(state.mode==="game-playing")gameFrame=requestAnimationFrame(frame);
  };
  gameFrame=requestAnimationFrame(frame);
}
function invadersKey(key){
  if(student.working.sound)gameAudio.unlock();
  const previous=gameSession.phase;
  const result=gameSession.input(key,invadersTick(performance.now()));
  gameSounds();syncGameMode();
  if(gameSession.finished){stopGameClock();retainGame();}
  if(key==="Escape"&&["ready","level-end"].includes(previous)){goMenu(0);return;}
  render(false);armGameClock();
}
function invadersScreen(){
  if(["game-setup","game-players"].includes(state.mode)){gameSetupScreen();return;}
  if(state.mode==="game-name"){gameNameScreen();return;}
  if(state.mode==="game-scores"){header(GAME.scoresTitle);drawScores(grid,student.workingScores);return;}
  if(state.mode==="game-end"){
    header(GAME.title,REPORT.testExit);
    const top=choiceLayout(3,20,GAME.endPrompt).top;
    activityChoices(GAME.endChoices,nextGameActivity,{top,width:20,prompt:GAME.endPrompt});return;
  }
  const view=gameView();
  header(GAME.roundTitle,GAME.roundFooter,false);
  grid.put(0,79-view.players[view.player].length,view.players[view.player]);
  if(state.mode==="game-ready"||state.mode==="game-round")drawRoundReady(grid,view);
  else if(state.mode==="game-over")drawGameOver(grid,view,student.workingScores);
  else drawGame(grid,view);
}
function openGameScores(){stopGameClock();clearTimeout(idleTimer);state.mode="game-scores";render();announce(GAME.scoresTitle);}
function nextGameActivity(){
  if(state.selected===0)openGameSetup();
  else if(state.selected===1)startPractice();
  else goMenu(0);
}

function openDiskPicker(){
  clearTimeout(idleTimer);diskLoadToken++;state.mode="disk-picker";state.selected=0;state.diskError="";
  render();announce(diskFiles.length?DISK.pickerPrompt:DISK.noFiles+" Choose local test files with the browser button.");
}
function diskPickerScreen(){
  header(DISK.title);
  const g=drawDiskPicker(grid,{files:diskFiles,selected:state.selected});
  if(!diskFiles.length)return;
  const list=document.createElement("div");list.setAttribute("role","listbox");list.setAttribute("aria-label","Disk Test files");controls.append(list);
  diskFiles.forEach((file,i)=>list.append(hotspot(file.name,g.listTop+i+1,g.listLeft+1,DISK.pickerWidth+1,()=>{state.selected=i;startDiskTest(i);},{role:"option",selected:i===state.selected})));
}
async function startDiskTest(index){
  const selected=diskFiles[index];if(!selected)return;
  const request=++diskLoadToken;state.mode="disk-loading";state.diskError="";render();
  try{
    if(selected.file.size>1048576)throw Error("Choose a test file no larger than 1 MiB.");
    const bytes=new Uint8Array(await selected.file.arrayBuffer());
    const sha256=[...new Uint8Array(await crypto.subtle.digest("SHA-256",bytes))].map(n=>n.toString(16).padStart(2,"0")).join("");
    if(request!==diskLoadToken)return;
    const c=structuredClone(student.working.curriculum??createCurriculum(student.working.wpm));
    const next=new DiskTest(c,bytes,{name:selected.name,originalName:selected.originalName,sha256,goal:student.working.wpm});
    student.working={...student.working,curriculum:c};student.dirty=true;
    diskSession=next;state.mode="disk-test";render();announce(selected.name+DISK.suffix+". Type each line; Escape returns to Main Menu.");
  }catch(error){
    if(request!==diskLoadToken)return;
    state.diskError=error instanceof Error?error.message:"The local test file could not be read.";
    state.mode="disk-error";render();announce(state.diskError);
  }
}
function retainDisk(){
  if(!diskSession.recorded){student.recordPractice(diskSession.record());diskSession.recorded=true;}
}
function diskKey(key){
  const event=diskSession.input(key,browserClock(performance.now()));
  if(event.ignored)return;
  student.dirty=true;if(event.error||event.beep)beep();
  if(event.aborted){retainDisk();goMenu(0);return;}
  if(event.testDone){retainDisk();state.mode="disk-test-result";state.selected=0;announce("Disk Test complete. Choose next activity.");}
  else if(event.pageDone)announce("Next screen of "+diskSession.name+DISK.suffix+".");
  render(false);
}
function diskScreen(){
  if(state.mode==="disk-picker"){diskPickerScreen();return;}
  if(state.mode==="disk-loading"){header(DISK.title);grid.put(11,22,"Reading local test file...");return;}
  if(state.mode==="disk-error"){
    header(DISK.title);grid.box(7,5,18,74);paragraph(state.diskError,9,8,64,0x1f,15);
    grid.put(17,27,"Press Enter to choose another file.");return;
  }
  const title=diskSession.name+DISK.suffix;
  if(state.mode==="disk-test-result"){
    header(DISK.resultPrefix+title,DISK.exit);
    drawProgress(grid,testSummary(diskSession.record(),student.working.wpm),{wpmGoal:student.working.wpm});
    activityChoices(DISK.choices,nextDiskActivity,{top:11,width:20,prompt:DISK.testPrompt});return;
  }
  header(title);drawTest(grid,diskSession);
}
function nextDiskActivity(){
  if(state.selected===0)openDiskPicker();
  else if(state.selected===1)startPractice();
  else goMenu(0);
}

function startFingering(){
  clearTimeout(idleTimer);fingering=new FingeringReview(student.beginAdaptivePractice());
  state.mode="fingering";render();announce(KEYPAD.fingeringTitle+". Choose a key for reach practice; Escape returns to Main Menu.");
}
function fingeringScreen(){
  header(fingering.tutorial?KEYPAD.homeTitle:KEYPAD.fingeringTitle);
  drawFingering(grid,fingering);
}
function fingeringKey(key){
  const event=fingering.input(key,browserClock(performance.now()));
  if(event.ignored)return;
  if(event.invalid||event.error||event.beep)beep();
  if(event.aborted){goMenu(0);return;}
  render(false);
}
function syncKeypadMode(){state.mode=keypadSession.pendingGuide?"keypad-intro":keypadSession.tutorial?"keypad-tutorial":"keypad";}
function startKeypad(activity="lesson"){
  clearTimeout(idleTimer);
  const c=student.beginAdaptivePractice();
  keypadSession=activity==="test"?new KeypadTest(c,student.working.wpm):new KeypadLesson(c,student.working.drills,student.working.wpm);
  syncKeypadMode();render();announce((activity==="test"?KEYPAD.testTitle:KEYPAD.lessonTitle)+". Type each number; Plus or Enter finishes it. Escape returns to Main Menu.");
}
function retainKeypad(){
  if(!keypadSession.recorded){student.recordPractice(keypadSession.record());keypadSession.recorded=true;}
}
function keypadKey(key){
  const event=keypadSession.input(key,browserClock(performance.now()));
  if(event.ignored)return;
  student.dirty=true;if(event.error||event.beep)beep();
  if(event.aborted){retainKeypad();goMenu(0);return;}
  if(event.lessonDone){retainKeypad();state.mode="keypad-lesson-end";announce("End of Lesson. Press any key for the summary.");}
  else if(event.testDone){retainKeypad();state.mode="keypad-test-result";state.selected=0;announce("Keypad Test complete. Choose next activity.");}
  else syncKeypadMode();
  render(false);
}
function activityChoices(labels,callback,{top=10,width=21,prompt=DATA.practice.prompt}={}){
  const g=choiceLayout(3,width,prompt),delta=top-g.top;
  grid.box(top,g.left,g.bottom+delta,g.right);
  grid.put(g.promptTop+delta+1,g.left+4,prompt);
  grid.put(g.instructionRow+delta,g.right-41,"..press Enter to select highlighted item.");
  grid.box(g.listTop+delta,g.listLeft,g.listBottom+delta,g.listRight,0x2f,true);
  labels.forEach((label,i)=>{
    grid.put(g.listTop+delta+i+1,g.listLeft+1,(" "+label).padEnd(width+1),i===state.selected?0x1a:0x29);
    hotspot(label,g.listTop+delta+i+1,g.listLeft+1,width+1,()=>{state.selected=i;callback();},{role:"option",selected:i===state.selected});
  });
}
function keypadScreen(){
  const mode=state.mode;
  if(mode==="keypad-summary"){
    header(KEYPAD.summaryTitle,REPORT.testExit);
    drawKeypadSummary(grid,{...keypadSession.record(),totals:keypadSession.displayTotals()},keypadSession.summary());
    activityChoices(KEYPAD.lessonChoices,nextKeypadActivity);return;
  }
  if(mode==="keypad-test-result"){
    header(REPORT.testResultPrefix+KEYPAD.testTitle,REPORT.testExit);
    drawProgress(grid,testSummary(keypadSession.record(),student.working.wpm),{wpmGoal:student.working.wpm});
    activityChoices(KEYPAD.testChoices,nextKeypadActivity,{top:11,width:20,prompt:REPORT.testPrompt});return;
  }
  header(mode==="keypad-tutorial"?KEYPAD.homeTitle:keypadSession.activity==="test"?KEYPAD.testTitle:KEYPAD.lessonTitle);
  if(mode==="keypad-intro"){drawKeypadIntro(grid);footer("Press any key to continue.",false);return;}
  drawKeypadActivity(grid,keypadSession,{test:keypadSession.activity==="test",stats:keypadSession.lastResult??null});
  if(mode==="keypad-lesson-end"){grid.put(9,34,"End of Lesson");footer("Press any key to continue.",false);}
}
function nextKeypadActivity(){
  const test=state.mode==="keypad-test-result";
  if(state.selected===2){goMenu(0);return;}
  startKeypad((state.selected===0)===test?"test":"lesson");
}
function keypadEventKey(event){
  if(/^Numpad[0-9]$/.test(event.code))return event.code.slice(-1);
  if(event.code==="NumpadDecimal")return ".";
  if(event.code==="NumpadAdd")return "+";
  return event.key;
}

function startPractice(){
  clearTimeout(idleTimer);lesson=new AdaptiveLesson(student.beginAdaptivePractice(),student.working.drills,student.working.wpm);
  if(!lesson.curriculum.introShown){state.mode="guide";state.guide={type:"intro"};}else syncLessonMode();
  render();announce(state.mode==="guide"?"Fingering introduction. Press any key to continue.":"Practice Lesson. Type the line, then press Space or Enter. Backspace corrects; Escape ends practice.");
}
function syncLessonMode(){
  state.mode=lesson.pendingGuide?"guide":lesson.tutorial?"home-practice":"practice";
  state.guide=lesson.pendingGuide;
}
function guideScreen(){
  const guide=state.guide,strings=CURRICULUM.guideStrings;
  header(DATA.practice.title,"Press any key to continue.",false);
  if(guide.type==="shift"){
    grid.box(6,3,19,76);
    let row=7;
    for(const key of ["1c92","1d5c","1e04"])row=paragraph(strings[key],row,5,70,0x1f,18)+1;
  }else if(guide.type==="intro"){
    drawKeyboard(grid,3,13,"asdf");grid.box(15,13,21,67);
    paragraph(strings["1567"],16,15,50,0x1f,20);
  }else if(guide.type==="home"){
    const index=CURRICULUM.keyIndex[guide.key];
    drawKeyboard(grid,3,13,guide.key);grid.box(15,13,21,67);
    grid.put(16,15,strings["1ef0"].replace("%c",guide.key.toUpperCase()));
    grid.put(17,15,strings["1f21"].replace("%s",CURRICULUM.fingers[7-index]).replace("%s",CURRICULUM.handRight));
    grid.put(18,15,strings["1f4c"].replace("%c",guide.key.toUpperCase()));
    grid.put(19,15,strings["1f7d"]);grid.put(20,15,strings["1fb2"]);
  }else{
    header("Home Key Lesson");drawTutorial(grid,lesson);
    footer("Press any key to continue.",false);
  }
}
function retainPractice(){
  if(!lesson.recorded){student.recordPractice(lesson.record());lesson.recorded=true;}
}
function practiceScreen(){
  header(DATA.practice.title);drawPractice(grid,lesson,DATA.practice);
  if(state.mode==="lesson-end")footer("Press any key to continue.",false);
}
function summaryScreen(){
  header(DATA.practice.summary,"Exit Typing Tutor IV");
  const result=lesson.record().totals;
  grid.box(3,27,9,53,0x2f);
  grid.put(4,29,"Speed: "+result.wpm+" WPM",0x2f);
  grid.put(5,29,"Accuracy: "+result.accuracy+"%",0x2f);
  const ranking=lesson.summary();
  grid.put(6,29,"Keys Above "+lesson.goal+" WPM: "+ranking.above,0x2f);
  grid.put(7,29,"Best Keys: "+[...ranking.best].join(" "),0x2f);
  grid.put(8,29,"Keys to Work on: "+[...ranking.worst].join(" "),0x2f);
  const labels=DATA.practiceChoices,g=choiceLayout(3,21,DATA.practice.prompt),delta=10-g.top;
  grid.box(10,g.left,g.bottom+delta,g.right);
  grid.put(g.promptTop+delta+1,g.left+4,DATA.practice.prompt);
  grid.put(g.instructionRow+delta,g.right-41,"..press Enter to select highlighted item.");
  grid.box(g.listTop+delta,g.listLeft,g.listBottom+delta,g.listRight,0x2f,true);
  for(const [i,label] of labels.entries()){
    grid.put(g.listTop+delta+i+1,g.listLeft+1,(" "+label).padEnd(22),i===state.selected?0x1a:0x29);
    hotspot(label,g.listTop+delta+i+1,g.listLeft+1,22,()=>{state.selected=i;nextActivity();},{role:"option",selected:i===state.selected});
  }
}
function nextActivity(){
  if(state.selected===0){startPractice();return;}
  if(state.selected===2){goMenu(0);return;}
  startTest("practice");
}
function practiceKey(key){
  const event=lesson.input(key,browserClock(performance.now()));
  if(event.ignored)return;
  // Warn on tab close even while a line is unfinished; do not silently autosave.
  student.dirty=true;
  if(event.error||event.beep)beep();
  if(event.aborted){retainPractice();goMenu(0);return;}
  if(event.lessonDone){retainPractice();state.mode="lesson-end";announce("End of Lesson. Press any key for the summary.");}
  else {
    syncLessonMode();
    if(event.done&&event.result)announce("Drill "+lesson.lines.length+" complete. Speed "+event.result.wpm+" WPM. Accuracy "+event.result.accuracy+" percent.");
  }
  render(false);
}
function testTitle(){return state.testType==="all-keys"?REPORT.testTitles.allKeys:REPORT.testTitles.practice;}
function startTest(kind="practice"){
  clearTimeout(idleTimer);state.testType=kind;
  testSession=new TypingTest(student.beginAdaptivePractice(),kind,student.working.wpm);
  state.mode="test";render();announce(testTitle()+". Six lines. Type each line and finish it with Enter or Space. Escape returns to Main Menu.");
}
function retainTest(){
  if(!testSession.recorded){student.recordPractice(testSession.record());testSession.recorded=true;}
}
function testKey(key){
  const event=testSession.input(key,browserClock(performance.now()));
  if(event.ignored)return;
  student.dirty=true;if(event.error||event.beep)beep();
  if(event.aborted){retainTest();goMenu(0);return;}
  if(event.testDone){
    retainTest();state.mode="test-summary";state.selected=0;announce(testTitle()+" complete. Choose next activity.");
  }else if(event.done)announce("Line "+testSession.activeLine+" complete. Continue with the next line.");
  render(false);
}
function testScreen(){
  header(testTitle());drawTest(grid,testSession);
}
function testResultScreen(){
  header(REPORT.testResultPrefix+testTitle(),REPORT.testExit);
  drawProgress(grid,testSummary(testSession.record(),student.working.wpm),{wpmGoal:student.working.wpm});
  const labels=REPORT.testChoices,g=choiceLayout(3,20,REPORT.testPrompt),delta=11-g.top;
  grid.box(11,g.left,g.bottom+delta,g.right);
  grid.put(g.promptTop+delta+1,g.left+4,REPORT.testPrompt);
  grid.put(g.instructionRow+delta,g.right-41,"..press Enter to select highlighted item.");
  grid.box(g.listTop+delta,g.listLeft,g.listBottom+delta,g.listRight,0x2f,true);
  for(const [i,label] of labels.entries()){
    grid.put(g.listTop+delta+i+1,g.listLeft+1,(" "+label).padEnd(21),i===state.selected?0x1a:0x29);
    hotspot(label,g.listTop+delta+i+1,g.listLeft+1,21,()=>{state.selected=i;nextTestActivity();},{role:"option",selected:i===state.selected});
  }
}
function nextTestActivity(){
  if(state.selected===0)startTest(state.testType);
  else if(state.selected===1)startPractice();
  else goMenu(0);
}
const reportOrder=["progress","speed","accuracy"];
function openReport(kind){
  clearTimeout(idleTimer);state.reportKind=kind;state.mode="report";render();
  announce(REPORT.titles[reportOrder.indexOf(kind)]+". Any key cycles reports; Escape returns to Main Menu.");
}
function nextReport(){openReport(reportOrder[(reportOrder.indexOf(state.reportKind)+1)%3]);}
function reportScreen(){
  const index=reportOrder.indexOf(state.reportKind),next=REPORT.titles[(index+1)%3];
  header(REPORT.titles[index],"Main Menu,  any other key -> "+next);
  state.reportLimited=false;
  if(state.reportKind==="progress"){
    const model=progressModel(student.working,student.saved);state.reportLimited=model.legacyBreakdownMissing;
    drawProgress(grid,model,{wpmGoal:student.working.wpm});
  }else drawGraph(grid,graphModel(student.working.curriculum,state.reportKind));
  hotspot("Next report",24,0,80,nextReport);
}
function render(focus=true){
  document.querySelector("#export-data").hidden=state.mode==="welcome";
  document.querySelector("#reset-data").hidden=state.mode==="welcome";
  document.querySelector("#choose-disk-files").hidden=!["disk-picker","disk-error"].includes(state.mode);
  controls.replaceChildren();
  if(state.mode==="welcome")welcomeScreen();
  else if(state.mode==="menu")menuScreen();
  else if(state.mode==="choice")choiceScreen();
  else if(state.mode==="name"||state.mode==="registration")nameScreen();
  else if(state.mode==="reader")readerScreen();
  else if(state.mode==="message")messageScreen();
  else if(state.mode==="practice"||state.mode==="lesson-end")practiceScreen();
  else if(state.mode==="summary")summaryScreen();
  else if(state.mode==="test")testScreen();
  else if(state.mode==="test-summary")testResultScreen();
  else if(state.mode==="report")reportScreen();
  else if(state.mode.startsWith("game"))invadersScreen();
  else if(state.mode.startsWith("disk"))diskScreen();
  else if(state.mode==="fingering")fingeringScreen();
  else if(state.mode.startsWith("keypad"))keypadScreen();
  else if(state.mode==="guide")guideScreen();
  else if(state.mode==="home-practice"){header("Home Key Lesson");drawTutorial(grid,lesson);}
  else exitScreen();
  paint();
  if(focus){
    if(state.mode==="game-name"){const input=document.querySelector("#game-second-name");input.focus({preventScroll:true});input.setSelectionRange(input.value.length,input.value.length);}
    else if(state.mode==="name"||state.mode==="registration"){const input=document.querySelector("#name-entry");input.focus({preventScroll:true});input.setSelectionRange(input.value.length,input.value.length);}
    else terminal.focus({preventScroll:true});
  }
}
document.addEventListener("keydown",event=>{
  if(resetDialog.open)return;
  if(event.ctrlKey||event.metaKey||event.altKey||event.isComposing)return;
  if(event.target.closest(".browser-tools"))return;
  const key=event.key;
  if(state.mode==="welcome"){
    if(["Shift","Control","Alt","Meta","CapsLock"].includes(key))return;
    event.preventDefault();
    if(key==="Escape"||welcome.phase!=="ready")finishWelcome();else startWelcome();
    return;
  }

  if(["game-setup","game-players"].includes(state.mode)){
    if(["ArrowUp","ArrowDown"," "].includes(key)){event.preventDefault();state.selected=(state.selected+1)%2;render();}
    else if(key==="Enter"){event.preventDefault();if(event.target.matches(".hotspot"))event.target.click();else acceptGameSetup();}
    else if(key==="Escape"){event.preventDefault();goMenu(0);}
    return;
  }
  if(state.mode==="game-name"){
    if(key==="Escape"){event.preventDefault();goMenu(0);}
    else if(key==="Enter"){event.preventDefault();acceptGameName();}return;
  }
  if(["game-ready","game-playing","game-round"].includes(state.mode)){
    if(key.length===1||["Escape","Enter","Backspace","Tab"].includes(key)){event.preventDefault();invadersKey(key);}return;
  }
  if(state.mode==="game-over"){
    if(key.length===1||["Escape","Enter","Backspace","Tab"].includes(key)){event.preventDefault();state.mode="game-end";state.selected=0;render();}return;
  }
  if(state.mode==="game-end"){
    if(["ArrowUp","ArrowDown"," "].includes(key)){event.preventDefault();state.selected=(state.selected+(key==="ArrowUp"?-1:1)+3)%3;render();}
    else if(key==="Enter"){event.preventDefault();if(event.target.matches(".hotspot"))event.target.click();else nextGameActivity();}
    else if(key==="Escape"){event.preventDefault();quit();}return;
  }
  if(state.mode==="game-scores"){
    if(key==="Escape"){event.preventDefault();goMenu(0);}
    else if(key.length===1||["Enter","Backspace","Tab"].includes(key)){event.preventDefault();goMenu(5,false);}return;
  }

  if(state.mode==="disk-picker"){
    if(["ArrowUp","ArrowDown"," "].includes(key)&&diskFiles.length){
      event.preventDefault();state.selected=(state.selected+(key==="ArrowUp"?-1:1)+diskFiles.length)%diskFiles.length;render();
    }else if(key==="Enter"){
      event.preventDefault();if(!diskFiles.length)goMenu(0);
      else if(event.target.matches(".hotspot"))event.target.click();else startDiskTest(state.selected);
    }else if(key==="Escape"){event.preventDefault();goMenu(0);}
    return;
  }
  if(state.mode==="disk-loading"){
    if(key==="Escape"){event.preventDefault();diskLoadToken++;goMenu(0);}return;
  }
  if(state.mode==="disk-error"){
    if(["Enter","Escape"].includes(key)){event.preventDefault();openDiskPicker();}return;
  }
  if(state.mode==="disk-test"){
    if(["Escape","Backspace","Enter","Tab"].includes(key)||(key.length===1&&key.charCodeAt(0)>=32&&key.charCodeAt(0)<=126)){event.preventDefault();diskKey(key);}return;
  }
  if(state.mode==="disk-test-result"){
    if(["ArrowUp","ArrowDown"," "].includes(key)){event.preventDefault();state.selected=(state.selected+(key==="ArrowUp"?-1:1)+3)%3;render();}
    else if(key==="Enter"){event.preventDefault();if(event.target.matches(".hotspot"))event.target.click();else nextDiskActivity();}
    else if(key==="Escape"){event.preventDefault();quit();}return;
  }

  if(state.mode==="fingering"){
    if(["Escape","Backspace","Enter","Tab"].includes(key)||key.length===1){event.preventDefault();fingeringKey(key);}
    return;
  }
  if(state.mode==="keypad-intro"){
    if(key.length===1||["Enter","Escape","Tab","Backspace"].includes(key)){event.preventDefault();keypadSession.acknowledgeGuide();syncKeypadMode();render();}
    return;
  }
  if(["keypad","keypad-tutorial"].includes(state.mode)){
    const input=keypadEventKey(event);
    if(["Escape","Backspace","Enter","Tab"].includes(input)||(input.length===1&&input.charCodeAt(0)>=32&&input.charCodeAt(0)<=126)){event.preventDefault();keypadKey(input);}
    return;
  }
  if(state.mode==="keypad-lesson-end"){
    if(key.length===1||["Enter","Escape","Tab","Backspace"].includes(key)){event.preventDefault();state.mode="keypad-summary";state.selected=0;render();}
    return;
  }
  if(["keypad-summary","keypad-test-result"].includes(state.mode)){
    if(["ArrowUp","ArrowDown"," "].includes(key)){event.preventDefault();state.selected=(state.selected+(key==="ArrowUp"?-1:1)+3)%3;render();}
    else if(key==="Enter"){event.preventDefault();if(event.target.matches(".hotspot"))event.target.click();else nextKeypadActivity();}
    else if(key==="Escape"){event.preventDefault();quit();}
    return;
  }

  if(state.mode==="test"){
    if(["Escape","Backspace","Enter","Tab"].includes(key)||(key.length===1&&key.charCodeAt(0)>=32&&key.charCodeAt(0)<=126)){
      event.preventDefault();testKey(key);
    }
    return;
  }
  if(state.mode==="guide"){
    if(key.length===1||["Enter","Escape","Tab","Backspace"].includes(key)){
      event.preventDefault();
      if(state.guide.type==="intro")lesson.curriculum.introShown=true;
      else lesson.acknowledgeGuide();
      syncLessonMode();render();
    }
    return;
  }
  if(state.mode==="practice"||state.mode==="home-practice"){
    if(["Escape","Backspace","Enter","Tab"].includes(key)||(key.length===1&&key.charCodeAt(0)>=32&&key.charCodeAt(0)<=126)){event.preventDefault();practiceKey(key);}
    return;
  }
  if(state.mode==="lesson-end"){
    if(key.length===1||["Enter","Backspace","Tab","Escape"].includes(key)){event.preventDefault();state.mode="summary";state.selected=0;render();announce(DATA.practice.summary);}
    return;
  }
  if(key==="Enter"&&event.target.matches(".hotspot")){event.preventDefault();event.target.click();return;}
  if(state.mode==="report"){
    if(key==="Escape"){event.preventDefault();goMenu(0);}
    else if(key!=="Tab"&&(key.length===1||["Enter","Backspace","ArrowUp","ArrowDown","ArrowLeft","ArrowRight","PageUp","PageDown"].includes(key))){event.preventDefault();nextReport();}
    return;
  }
  if(state.mode==="test-summary"){
    if(["ArrowUp","ArrowDown"," "].includes(key)){event.preventDefault();state.selected=(state.selected+(key==="ArrowUp"?-1:1)+3)%3;render();announce(REPORT.testChoices[state.selected]);}
    else if(key==="Enter"){event.preventDefault();nextTestActivity();}
    else if(key==="Escape"){event.preventDefault();quit();}
    return;
  }
  if(state.mode==="name"||state.mode==="registration"){
    if(key==="Enter"){event.preventDefault();acceptName();}
    else if(key==="Escape"){event.preventDefault();if(state.mode==="registration"){state.mode="exited";render();}else goMenu(0);}
    return;
  }
  if(!["Enter","Escape"," ","ArrowLeft","ArrowRight","ArrowUp","ArrowDown","Backspace","PageDown","PageUp"].includes(key)&&key.length!==1)return;
  if(state.mode==="exited"){
    if(key==="Enter"){event.preventDefault();restart();}return;
  }
  if(state.mode==="choice"){
    if(["ArrowUp","ArrowDown"," "].includes(key)){
      event.preventDefault();const d=state.dialog;d.selected=(d.selected+(key==="ArrowUp"?-1:1)+d.labels.length)%d.labels.length;
      render();announce(d.labels[d.selected]);return;
    }
    if(key==="Enter"){event.preventDefault();acceptChoice();return;}
    if(key==="Escape"){
      event.preventDefault();if(state.dialog.kind==="quit"){beep();return;}
      goMenu(0);return;
    }
    if(key.length===1){event.preventDefault();beep();}return;
  }
  if(state.mode==="summary"){
    if(["ArrowUp","ArrowDown"," "].includes(key)){event.preventDefault();state.selected=(state.selected+(key==="ArrowUp"?-1:1)+3)%3;render();announce(DATA.practiceChoices[state.selected]);}
    else if(key==="Enter"){event.preventDefault();nextActivity();}
    else if(key==="Escape"){event.preventDefault();quit();}
    return;
  }
  if(state.mode==="reader"){
    if(["Enter"," ","PageDown","ArrowRight"].includes(key)){event.preventDefault();nextPage();}
    else if(["PageUp","ArrowLeft"].includes(key)){event.preventDefault();if(state.page){state.page--;render();}}
    else if(key==="Escape"){event.preventDefault();goMenu(0);}
    return;
  }
  if(state.mode==="message"){if(["Enter","Escape"].includes(key)){event.preventDefault();goMenu(state.returnMenu,false);}return;}
  if(["ArrowLeft","ArrowRight"," "].includes(key)){
    event.preventDefault();state.selected=(state.selected+(key==="ArrowLeft"?-1:1)+DATA.menus[state.menu].items.length)%DATA.menus[state.menu].items.length;
    resetIdle();render();announce(DATA.menus[state.menu].items[state.selected].label);return;
  }
  if(key==="Enter"){event.preventDefault();activate(state.selected);return;}
  if(key==="Escape"){event.preventDefault();if(state.menu===0)quit();else goMenu(0);return;}
  if(key.length===1){
    const index=DATA.menus[state.menu].items.findIndex(item=>item.label[0].toLowerCase()===key.toLowerCase());
    if(index>=0){event.preventDefault();activate(index);}else beep();
  }
});
window.addEventListener("beforeunload",event=>{if(student.dirty&&!resetting){event.preventDefault();event.returnValue="";}});
function exportBrowserData(){
  try{
    const raw={exportedAt:new Date().toISOString(),faithfulSaved:storage.getItem(PROFILE_KEY),
      earlierPrototype:storage.getItem(LEGACY_KEY),workingSettings:student.working,
      workingGameScores:student.workingScores,savedGameScores:student.savedScores,
      inProgressGame:gameSession&&!gameSession.finished?gameSession.record():null,
      inProgressDisk:state.mode==="disk-test"?diskSession.record():null,
      inProgressKeypad:["keypad","keypad-tutorial","keypad-intro"].includes(state.mode)?keypadSession.record():null,
      inProgressPractice:["practice","home-practice","guide"].includes(state.mode)?lesson.record():null,
      inProgressTest:state.mode==="test"?testSession.record():null};
    const url=URL.createObjectURL(new Blob([JSON.stringify(raw,null,2)],{type:"application/json"}));
    const a=document.createElement("a");a.href=url;a.download="typing-tutor-browser-data.json";a.click();
    setTimeout(()=>URL.revokeObjectURL(url),1000);
    return true;
  }catch(error){
    const message="Browser data could not be exported.";
    if(resetDialog.open)resetError.textContent=message;
    else{state.warning=message;render(false);announce(message);}
    return false;
  }
}
document.querySelector("#export-data").addEventListener("click",exportBrowserData);
document.querySelector("#reset-data").addEventListener("click",()=>{
  resetError.textContent="";resetDialog.showModal();document.querySelector("#reset-cancel").focus();
});
document.querySelector("#reset-cancel").addEventListener("click",()=>resetDialog.close());
document.querySelector("#reset-export").addEventListener("click",()=>{
  resetError.textContent="";exportBrowserData();
});
document.querySelector("#reset-confirm").addEventListener("click",()=>{
  try{
    clearBrowserData(storage);resetting=true;window.location.reload();
  }catch{
    resetting=false;resetError.textContent="Reset could not be completed. Some saved data may remain. Your current session is still open; export a backup or try again.";
  }
});
document.querySelector("#choose-disk-files").addEventListener("click",()=>document.querySelector("#disk-files").click());
document.querySelector("#disk-files").addEventListener("change",event=>{
  diskFiles=prepareDiskFiles(event.target.files);event.target.value="";openDiskPicker();
});

if(shouldShowWelcome(storage,student)){state.mode="welcome";welcome=new WelcomeSequence();render();}
else{resetIdle();render();}
