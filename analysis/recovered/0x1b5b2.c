/* ev_803aa67d244b27e0c2520346a4d07261a234e64e17d322453ee3de826d0fee43 */

undefined2 __cdecl16near FUN_1000_b5b2(void)

{
  bool bVar1;
  int iVar2;
  int unaff_BP;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar3 = 0;
  *(undefined2 *)*(undefined2 *)(unaff_BP + 10) = 0;
  FUN_1000_e56c(0x1a,unaff_BP + -0x2b,0);
  iVar2 = FUN_1000_e56c(0x4e,*(undefined2 *)(unaff_BP + 4),0);
  if ((iVar2 != 0x12) && (iVar2 != 2)) {
    iVar2 = FUN_1000_e7cd(unaff_BP + -0xd,0x8540);
    *(int *)0x9070 = iVar2;
    if (iVar2 != 0) {
      bVar1 = true;
      if (*(char *)(unaff_BP + 6) != '\0') {
        iVar2 = FUN_1000_e3ce(*(undefined2 *)0x9070);
        if (iVar2 == 1) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
      }
      if (bVar1) {
        FUN_1000_e74e(*(undefined2 *)0x6d5,unaff_BP + -0xd);
      }
      FUN_1000_e913(*(undefined2 *)0x9070);
      uVar3 = (uint)bVar1;
      while ((iVar2 = FUN_1000_e56c(0x4f,*(undefined2 *)(unaff_BP + 4),0), iVar2 != 0x12 &&
             ((int)uVar3 < 8))) {
        iVar2 = FUN_1000_e7cd(unaff_BP + -0xd,0x8542);
        *(int *)0x9070 = iVar2;
        if (iVar2 != 0) {
          bVar1 = true;
          if (*(char *)(unaff_BP + 6) != '\0') {
            iVar2 = FUN_1000_e3ce(*(undefined2 *)0x9070);
            if (iVar2 == 1) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
          }
          uVar4 = uVar3;
          if (bVar1) {
            uVar4 = uVar3 + 1;
            FUN_1000_e74e(*(undefined2 *)(uVar3 * 2 + 0x6d5),unaff_BP + -0xd);
          }
          FUN_1000_e913(*(undefined2 *)0x9070);
          uVar3 = uVar4;
        }
      }
    }
  }
  FUN_1000_2723(0x101e);
  uVar4 = uVar3;
  if ((*(char *)(unaff_BP + 6) == '\0') && (*(char *)(unaff_BP + 8) != '\0')) {
    uVar4 = uVar3 + 1;
    FUN_1000_e74e(*(undefined2 *)(uVar3 * 2 + 0x6d5),0x8544);
  }
  if (uVar4 != 0) {
    iVar2 = FUN_1000_b21d(uVar4,0xd,0x6d5,0,0,0x854c);
    if (iVar2 == -1) {
      return 0xffff;
    }
    *(undefined2 *)*(undefined2 *)(unaff_BP + 10) = *(undefined2 *)(iVar2 * 2 + 0x6d5);
  }
  return 0;
}

