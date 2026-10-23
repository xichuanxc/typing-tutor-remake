/* ev_5c2ca4b624e32b279be83d75d80670f34e6a0733f542bc309088acc7ea225841 */

void __cdecl16near FUN_1000_2a2c(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined2 *)0x9d36 = 0;
  while (*(int *)(unaff_BP + -2) < 0x1a) {
    iVar3 = FUN_1000_722b((int)*(char *)(*(int *)(unaff_BP + -2) + 0x7aee));
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar3 + -0x6f45);
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
  }
  uVar1 = *(undefined1 *)0x90ae;
  uVar2 = *(undefined1 *)0x90af;
  *(uint *)(unaff_BP + -2) = (uint)*(byte *)0x90ba;
  *(undefined1 *)0x90ae = 0x16;
  *(undefined1 *)0x90af = 0x3f;
  *(undefined1 *)0x90ba = 1;
  *(uint *)0x9d2c = (uint)(*(char *)0x90b5 == '\x02');
  *(undefined2 *)0x9d4c = 3;
  FUN_1000_2692(0x10bd,0x101e);
  *(undefined1 *)0x9d4e = 1;
  FUN_1000_3a6d(0,6,0x48,0);
  if (*(char *)0x9d38 != '\0') {
    FUN_1000_51c5();
    uVar4 = FUN_1000_e74e(0xcbc,0x10a3,0x10bd,0x843);
    uVar4 = FUN_1000_e717(uVar4);
    FUN_1000_2692(uVar4);
    FUN_1000_8c42(*(char *)0x90b5 == '\x02',0x1721);
    FUN_1000_2565();
  }
  *(undefined1 *)0x90ae = uVar1;
  *(undefined1 *)0x90af = uVar2;
  *(undefined1 *)0x90ba = (char)*(undefined2 *)(unaff_BP + -2);
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined2 *)0x9d36 = 0;
  while (*(uint *)(unaff_BP + -2) < *(byte *)0x90ae + 4) {
    iVar3 = FUN_1000_722b((int)*(char *)(*(int *)(unaff_BP + -2) + 0x7aee));
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar3 + -0x6f45);
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
  }
  *(undefined2 *)0x9d4c = 2;
  return;
}

