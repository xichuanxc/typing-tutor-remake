/* ev_7d3f4bdd012903c2b510504403a6d3a76c3c0137d7726245dfbbdf6d8078317f */

void __cdecl16near FUN_1000_f42e(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x8f00 = uVar2;
  }
  return;
}

