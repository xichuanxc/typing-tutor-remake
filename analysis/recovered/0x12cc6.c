/* ev_a4da69448f9c0d00a27b641cc7e155616a8903229bef967eb2c02ced265a9321 */

void __cdecl16near FUN_1000_2cc6(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_07c9(0x20,1);
  FUN_1000_2692(0x10d5,0x101e);
  *(uint *)0x9d2c = (uint)(*(char *)0x90b5 == '\x02');
  *(undefined2 *)0x9d4c = 5;
  *(undefined1 *)0x9d4f = 1;
  *(undefined1 *)0x9d4e = 1;
  FUN_1000_d6a0(4);
  if (*(char *)0x9d38 != '\0') {
    FUN_1000_51c5();
    uVar1 = FUN_1000_e74e(0xcbc,0x10a3,0x10d5,0x843);
    uVar1 = FUN_1000_e717(uVar1);
    FUN_1000_2692(uVar1);
    FUN_1000_8c42(*(char *)0x90b5 == '\x02',0x1725);
    FUN_1000_2565();
  }
  FUN_1000_07c9(0x20,0);
  *(undefined1 *)0x9d4f = 0;
  return;
}

