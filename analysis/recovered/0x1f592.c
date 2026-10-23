/* ev_b0eebcf43fbbc0a7a525c0393307bfee6584a7bd726f36062c5e03701425deca */

undefined2 __cdecl16near FUN_1000_f592(void)

{
  code *pcVar1;
  byte extraout_DL;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if (((!(bool)in_CF) && ((extraout_DL & 0x80) != 0)) && ((extraout_DL & 3) != 0)) {
    return 1;
  }
  return 0;
}

