/* ev_3977ca3d802b3955ea7a4fd9d8b74bd298f1e9de4a226127725d4c1b693fd720 */

undefined2 __cdecl16near FUN_1000_f44d(void)

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

