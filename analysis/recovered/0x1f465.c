/* ev_e7c98dff8b7252b521417dbacc256b1a99e7c63a3b1aa4d5c17acf297cb4873f */

undefined2 __cdecl16near FUN_1000_f465(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x8f00 = uVar2;
    return 0xffff;
  }
  return 0;
}

