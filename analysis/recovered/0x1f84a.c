/* ev_37b2236f49506c89bff53251e2bf1887d3ef5deef987bdabd05eecb74e589c2c */

undefined2 __cdecl16near FUN_1000_f84a(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined1 in_ZF;
  
  pcVar1 = (code *)swi(0x16);
  (*pcVar1)();
  if ((bool)in_ZF) {
    return 0xffff;
  }
  uVar2 = FUN_1000_f858();
  return uVar2;
}

