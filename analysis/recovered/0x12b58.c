/* ev_b1f41467c365024648cb8cedc50e532d5ef9c66ec499ff4727c3d1da1d50d0f3 */

void __cdecl16near FUN_1000_2b58(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  uint uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x10cb,0x101e);
  *(undefined2 *)0x9d2c = 4;
  *(undefined2 *)0x9d4c = 1;
  iVar1 = FUN_1000_b5b2(0xffe,0,0,unaff_BP + -2);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
    return;
  }
  if (*(int *)(unaff_BP + -2) == 0) {
    FUN_1000_b194(0x12fb,0x23,4);
    FUN_1000_2612(0x183,0);
    FUN_1000_f831();
    return;
  }
  uVar2 = FUN_1000_e74e(0x9d3e,*(undefined2 *)(unaff_BP + -2),0x1722);
  uVar2 = FUN_1000_e7cd(uVar2);
  *(undefined2 *)0x9070 = uVar2;
  uVar2 = FUN_1000_e74e(0xcbc,0x9d3e,0x1328,0x101e);
  uVar2 = FUN_1000_e717(uVar2);
  FUN_1000_2692(uVar2);
  *(undefined1 *)0x9d4e = 1;
  while( true ) {
    iVar1 = FUN_1000_3a6d(0,6,0x48,1);
    if (iVar1 != 0) break;
    *(undefined1 *)0x9d38 = 0;
    FUN_1000_b1f3(0,1,7);
    FUN_1000_2723(*(undefined2 *)(unaff_BP + 4));
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  *(undefined1 *)0x9d50 = 0;
  if (*(char *)0x9d38 != '\0') {
    FUN_1000_51c5();
    uVar2 = FUN_1000_e74e(0xcbc,0x10a3,0x9d3e,0x1328,0x843);
    uVar2 = FUN_1000_e717(uVar2);
    uVar2 = FUN_1000_e717(uVar2);
    FUN_1000_2692(uVar2);
    FUN_1000_8c42(4,0x1724);
    FUN_1000_2565();
  }
  *(undefined2 *)0x9d36 = 0;
  for (uVar3 = 0; uVar3 < *(byte *)0x90ae + 4; uVar3 = uVar3 + 1) {
    iVar1 = FUN_1000_722b((int)*(char *)(uVar3 + 0x7aee));
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar1 + -0x6f45);
  }
  return;
}

