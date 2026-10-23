/* ev_1823eebd798d66c94c37252c1f965647e67abc17d23c64ca97557d2f4ce7e345 */

undefined2 __cdecl16near FUN_1000_f404(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x8f00 = uVar2;
    uVar2 = 0xffff;
  }
  return uVar2;
}

