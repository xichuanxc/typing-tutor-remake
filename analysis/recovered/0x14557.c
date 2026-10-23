/* ev_652969abb3576886c42d0d6ddaf9d5770cbb472e977941fa32ab574741264a1a */

int __cdecl16near FUN_1000_4557(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int unaff_BP;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar4 = 0;
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined2 *)(unaff_BP + -4) = 0;
  *(undefined2 *)(unaff_BP + -8) = 0;
  *(undefined2 *)(unaff_BP + -10) = 0;
  if ((*(char *)(unaff_BP + 8) != '\0') && ((*(byte *)0x90af < 8 || (*(char *)0x90b2 == '\0')))) {
    if ((*(int *)(unaff_BP + 10) == 1) && (*(char *)0x9d50 == '\0')) {
      FUN_1000_4232(7,0x1a);
    }
    *(undefined1 *)0x90b2 = 0;
    *(undefined1 *)0x9d50 = 0;
    return 0;
  }
  if (*(char *)(unaff_BP + 8) != '\0') {
    uVar1 = FUN_1000_e7a7(*(undefined1 *)0x90b2);
    iVar2 = FUN_1000_e677(*(undefined2 *)(unaff_BP + 4),uVar1);
    if (iVar2 == 0) {
      uVar1 = FUN_1000_e793(*(undefined1 *)0x90b2);
      iVar2 = FUN_1000_e677(*(undefined2 *)(unaff_BP + 4),uVar1);
      if (iVar2 == 0) goto LAB_1000_4710;
    }
  }
  *(undefined1 *)0x9d4e = 1;
  *(undefined1 *)0x9d51 = 1;
  FUN_1000_2692(0x1c4f,0x101e);
  FUN_1000_c78e(0xc,0xd);
  FUN_1000_4757();
  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
    FUN_1000_6298(unaff_BP + -0x5b,*(undefined1 *)(unaff_BP + 6));
    FUN_1000_4802(5,0x18,1);
    FUN_1000_f7da(5,0x1c);
    FUN_1000_f6a4(0x1c5f,unaff_BP + -0x5b);
    FUN_1000_bd1f();
    iVar4 = FUN_1000_4a70(6,0x1c,unaff_BP + -0x5b,unaff_BP + -2,unaff_BP + -4,unaff_BP + -10);
    if (iVar4 == -1) break;
  }
  uVar3 = (uint)*(byte *)0x90b2;
  *(uint *)(unaff_BP + -6) = uVar3;
  if (((*(byte *)(uVar3 + 0x8e7d) & 3) != 0) &&
     (uVar3 = FUN_1000_722b(uVar3), uVar3 <= *(byte *)0x90af)) {
    iVar2 = FUN_1000_722b(*(undefined2 *)(unaff_BP + -6));
    *(int *)0x9d36 = *(int *)0x9d36 - (uint)*(byte *)(iVar2 + -0x6f45);
    uVar3 = 0xff;
    iVar2 = FUN_1000_722b(*(undefined2 *)(unaff_BP + -6));
    *(undefined1 *)(iVar2 + -0x6f45) = 0xff;
    *(int *)0x9d36 = *(int *)0x9d36 + (uVar3 & 0xff);
  }
  *(undefined1 *)0x90b2 = 0;
  *(undefined1 *)0x9d51 = 0;
  if (((*(char *)(unaff_BP + 8) != '\0') && (*(int *)(unaff_BP + 10) != 1)) && (iVar4 != -1)) {
    FUN_1000_4232(7,0x1a);
    FUN_1000_f7da(0x12,0x28);
    FUN_1000_f6a4(0x1c62,*(undefined2 *)0x9d56);
    FUN_1000_f7da(0x13,0x2b);
    FUN_1000_f6a4(0x1c6a,*(undefined2 *)0x9d54);
  }
LAB_1000_4710:
  if ((*(int *)(unaff_BP + 10) == 1) && (iVar4 != -1)) {
    FUN_1000_4232(7,0x1a);
  }
  return iVar4;
}

