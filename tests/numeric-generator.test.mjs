import test from 'node:test';
import assert from 'node:assert/strict';
import D from '../dist/curriculum-data.js';
import {createCurriculum} from '../dist/curriculum.js';
import {DrillGenerator} from '../dist/drill-generator.js';
import {formatNumber} from '../dist/numeric-generator.js';
function at(level=63,seed=0){const s=createCurriculum();Object.assign(s,{introduced:level,alphabetic:22,shiftLearned:1,seed});return s;}
test('full-key generation emits six bounded test lines',()=>{
  const state=at(),g=new DrillGenerator(state,{testType:3});
  const lines=Array.from({length:6},()=>g.line(72));
  assert.equal(lines[0],'Offer one: jelly, hollyhock, & silks.  An analyst [halting by one');
  assert.ok(lines.every(s=>s.length>=2&&s.length<=72));assert.notEqual(state.seed,0);
  assert.ok(lines.some(s=>/[0-9]/.test(s)));assert.ok(lines.some(s=>/[\[\]<>]/.test(s)));
});
test('numeric and punctuation grammar uses only introduced keys across every later level',()=>{
  let lines=0;
  for(let level=29;level<=63;level++)for(let seed=0;seed<50;seed++){
    const g=new DrillGenerator(at(level,seed),{testType:3});
    for(let n=0;n<12;n++){const line=g.line(72);assert.ok(line.length<=72);assert.ok([...line].every(c=>c===' '||g.known(c)),level+': '+line);lines++;}
  }
  assert.equal(lines,21000);assert.equal(new DrillGenerator(at()).known('\\'),false);
});
test('All-keys selection ignores saved mastery while ordinary generation respects it',()=>{
  const a=at();for(const key of a.saved)Object.assign(key,{correct:31,errors:0,time:1860});
  const full=new DrillGenerator(a,{testType:3}),ordinary=new DrillGenerator(at());
  assert.equal(full.isMastered(0),false);assert.equal(new DrillGenerator(a).isMastered(0),true);
  assert.deepEqual(Array.from({length:6},()=>full.line(72)),Array.from({length:6},()=>ordinary.line(72)));
});
test('native number formatting preserves a single thousands comma and cents without an added zero',()=>{
  assert.equal(formatNumber(123456), '123,456');assert.equal(formatNumber(-123456), '-123,456');
  assert.equal(formatNumber(12345678,true),'123,456.78');assert.equal(formatNumber(12,true),'.12');
  assert.equal(formatNumber(7,true),'.07');assert.equal(formatNumber(0,true),'.00');
});
function arithmetic(operator,money=false,comparison='='){
  const g=new DrillGenerator(at()),digits=[...'123456'];
  g.choose=s=>s===D.selectionStrings['20f2']?operator:s===D.selectionStrings['2116']?digits.shift():comparison;
  g.optional=s=>s===D.selectionStrings['2141']&&money?'$':'';g.word=()=> 'cat';g.random.next=()=>49;
  return g.callback(6);
}
test('arithmetic callbacks derive operands and results instead of inserting equation fixtures',()=>{
  assert.equal(arithmetic('+'),'123 + 456 = 579');
  assert.equal(arithmetic('-'),'579 - 123 = 456');
  assert.equal(arithmetic('*'),'123 * 456 = 56,088');
  assert.equal(arithmetic('/'),'56,088 / 123 = 456');
  assert.equal(arithmetic('@'),'123 cats @ $4.56 = $560.88');
  assert.equal(arithmetic('%'),'12 % of $38.00 = $4.56');
  assert.equal(arithmetic('+',true),'$1.23 + $4.56 = $5.79');
});
test('comparison callbacks perturb the result with the native integer factor',()=>{
  assert.equal(arithmetic('+',false,'>'),'123 + 456 > 5');
  assert.equal(arithmetic('+',false,'<'),'123 + 456 < 57,321');
});
test('bracket and quote callbacks retain paired closures and suppress following spacing',()=>{
  const g=new DrillGenerator(at());g.choose=()=> '(';
  assert.equal(g.callback(3),'(');assert.equal(g.join,true);assert.equal(g.callback(3),')');assert.equal(g.pair,'');
  g.choose=()=> '"';assert.equal(g.callback(11),'"');assert.equal(g.callback(11),'"');assert.equal(g.quote,'');
  const partial=new DrillGenerator(at(D.keyIndex['(']));partial.choose=()=> '(';
  assert.equal(partial.callback(3),'(');assert.equal(partial.pair,'');
});
test('all recovered nonalphabetic callback branches run deterministically on full state',()=>{
  for(let id=3;id<=15;id++)for(let seed=0;seed<100;seed++){
    const a=new DrillGenerator(at(63,seed)),b=new DrillGenerator(at(63,seed));
    const first=a.callback(id),second=b.callback(id);assert.equal(first,second);assert.equal(a.state.seed,b.state.seed);
    assert.ok([...first].every(c=>c===' '||a.known(c)),id+': '+first);
    if(id===8)assert.match(first,/^\d{1,2}:\d{2}(:\d{2})? [AP]M$/);
    if(id===10)assert.match(first,/^SSN #\d{3}-\d{2}-\d{4}$/);
  }
});
