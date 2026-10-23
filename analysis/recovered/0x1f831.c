/* ev_83daa3f6d8cc6f27a935647cc487dbd971e166c1b5d29bab89b7d91723d3412b */

uint __cdecl16near FUN_1000_f831(void)

{
  code *pcVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  pcVar1 = (code *)swi(0x16);
  (*pcVar1)();
  uVar2 = FUN_1000_f858();
  if ((*(char *)0x8f40 != '\0') && (uVar2 < 0x80)) {
    FUN_1000_f873();
  }
  return uVar2;
}

