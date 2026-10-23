/* ev_c47f69d6cf150e4137c0d176607f2f19fd9aa6d1531bdc7d4460e6ab73eb2a9a */

undefined2 __cdecl16near FUN_1000_cd3c(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_0128();
  iVar1 = FUN_1000_0f47();
  FUN_1000_e74e(*(undefined2 *)((*(int *)0x9d2e + 1) * 2 + 0x6d5),0x9072);
  if (*(int *)0x9d34 != 0) {
    iVar1 = iVar1 + 1;
  }
  iVar1 = FUN_1000_0d63(iVar1);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
    FUN_1000_e913(*(undefined2 *)0x9070);
    return 0xffff;
  }
  uVar2 = FUN_1000_e913(*(undefined2 *)0x9070);
  *(undefined1 *)0x906e = 1;
  return uVar2;
}

