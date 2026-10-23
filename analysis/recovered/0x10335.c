/* ev_10c424ac7b1d69a1a322db505dd8d466f6897cf409b8bad85d674c1e76841687 */

void __cdecl16near FUN_1000_0335(void)

{
  uint *puVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  int iVar7;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar8;
  undefined4 uVar9;
  
  FUN_1000_e7bd();
  if (*(char *)0x99a1 == '\0') goto LAB_1000_0775;
  bVar8 = false;
  if (*(int *)0x9719 == 0) {
    bVar8 = *(int *)0x9717 == 0;
  }
  if (bVar8) {
    bVar8 = false;
    if (*(int *)0x97b7 == 0) {
      bVar8 = *(int *)0x97b5 == 0;
    }
    if (!bVar8) goto LAB_1000_037d;
    bVar8 = false;
    if (*(int *)0x97bb == 0) {
      bVar8 = *(int *)0x97b9 == 0;
    }
    if (!bVar8) goto LAB_1000_037d;
    bVar8 = false;
    if (*(int *)0x971d == 0) {
      bVar8 = *(int *)0x971b == 0;
    }
    if (!bVar8) goto LAB_1000_037d;
    if (*(char *)0x906e == '\0') goto LAB_1000_0775;
  }
  else {
LAB_1000_037d:
    FUN_1000_2692(0x113f,0x11b);
    FUN_1000_2612(0x183,0);
    FUN_1000_8c42(8,0x11c);
    if ((*(int *)0x9719 + *(int *)0x97b7 + (uint)CARRY2(*(uint *)0x9717,*(uint *)0x97b5) == 0) &&
       (*(uint *)0x9717 + *(uint *)0x97b5 < 0x3e9)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    *(undefined1 *)0x99a2 = uVar6;
  }
  FUN_1000_2692(0x11d,0x122);
  FUN_1000_f7da(0x18,0);
  FUN_1000_f74a();
  while (iVar7 = FUN_1000_b21d(3,0x1d,0xaf,0,0,0x123), iVar7 == -1) {
    FUN_1000_7e47(5);
  }
  if (iVar7 != 1) {
    if (iVar7 == 2) {
      return;
    }
    uVar9 = FUN_1000_4cb5();
    *(undefined2 *)(unaff_BP + -6) = (int)((ulong)uVar9 >> 0x10);
    *(undefined2 *)(unaff_BP + -8) = (int)uVar9;
    uVar3 = *(undefined2 *)0x99a4;
    *(undefined2 *)(unaff_BP + -2) = *(undefined2 *)0x99a6;
    *(undefined2 *)(unaff_BP + -4) = uVar3;
    if ((*(int *)(unaff_BP + -6) <= *(int *)0x9068) &&
       ((*(int *)(unaff_BP + -6) != *(int *)0x9068 || (*(uint *)(unaff_BP + -8) < *(uint *)0x9066)))
       ) {
      puVar1 = (uint *)(unaff_BP + -8);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + 0xd600;
      *(int *)(unaff_BP + -6) = *(int *)(unaff_BP + -6) + 0x83 + (uint)(0x29ff < uVar2);
      for (iVar7 = 0; iVar7 < 6; iVar7 = iVar7 + 1) {
        *(undefined2 *)(iVar7 * 2 + -0x6f68) = *(undefined2 *)((iVar7 + 1) * 2 + -0x6f68);
      }
      *(undefined2 *)0x90a4 = 0;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + 1;
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + (uint)(0xfffe < uVar2);
    }
    uVar9 = FUN_1000_f04d();
    *(undefined2 *)(unaff_BP + -0xe) = (int)((ulong)uVar9 >> 0x10);
    *(undefined2 *)(unaff_BP + -0x10) = (int)uVar9;
    bVar8 = false;
    if (*(int *)(unaff_BP + -0xe) == 0) {
      bVar8 = *(int *)(unaff_BP + -0x10) == 0;
    }
    if (bVar8) {
      *(undefined2 *)(unaff_BP + -0xe) = 0;
      *(undefined2 *)(unaff_BP + -0x10) = 1;
    }
    iVar7 = *(int *)(unaff_BP + -0xe);
    uVar4 = *(uint *)(unaff_BP + -0x10);
    puVar1 = (uint *)0x9094;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar4;
    *(int *)0x9096 = *(int *)0x9096 + iVar7 + (uint)CARRY2(uVar2,uVar4);
    uVar3 = *(undefined2 *)(unaff_BP + -4);
    *(undefined2 *)0x9092 = *(undefined2 *)(unaff_BP + -2);
    *(undefined2 *)0x9090 = uVar3;
    *(int *)0x90a4 = *(int *)0x90a4 + *(int *)(unaff_BP + -0x10);
    FUN_1000_0128();
    for (iVar7 = 0; iVar7 < 0x4b; iVar7 = iVar7 + 1) {
      FUN_1000_02e0(iVar7 * 4 + -0x6efa,iVar7 * 4 + -0x6658);
      FUN_1000_02e0(iVar7 * 4 + -0x6dce,iVar7 * 4 + -0x652c);
      FUN_1000_02e0(iVar7 * 4 + -0x6ca2,iVar7 * 4 + -0x6400);
    }
    *(undefined2 *)0x9d2c = 9;
    FUN_1000_8f6e(0x9232,0x935e,0x9106);
    *(undefined2 *)0x9d2c = 0xb;
    FUN_1000_8f6e(0x9232,0x935e,0x9106);
    FUN_1000_02e0(0x9762,0x9713);
    FUN_1000_02e0(0x9766,0x9717);
    FUN_1000_02e0(0x976a,0x971b);
    FUN_1000_02e0(0x976e,0x971f);
    FUN_1000_02e0(0x9800,0x97b1);
    FUN_1000_02e0(0x9804,0x97b5);
    FUN_1000_02e0(0x9808,0x97b9);
    FUN_1000_02e0(0x980c,0x97bd);
    FUN_1000_02e0(0x9772,0x9723);
    FUN_1000_02e0(0x9776,0x9727);
    FUN_1000_02e0(0x977a,0x972b);
    FUN_1000_02e0(0x977e,0x972f);
    FUN_1000_02e0(0x9782,0x9733);
    FUN_1000_02e0(0x9786,0x9737);
    FUN_1000_02e0(0x978a,0x973b);
    FUN_1000_02e0(0x978e,0x973f);
    FUN_1000_02e0(0x9792,0x9743);
    *(undefined2 *)0x9721 = 0;
    *(undefined2 *)0x971f = 0;
    *(undefined2 *)0x971d = 0;
    *(undefined2 *)0x971b = 0;
    *(undefined2 *)0x9719 = 0;
    *(undefined2 *)0x9717 = 0;
    *(undefined2 *)0x9715 = 0;
    *(undefined2 *)0x9713 = 0;
    *(undefined2 *)0x97bf = 0;
    *(undefined2 *)0x97bd = 0;
    *(undefined2 *)0x97bb = 0;
    *(undefined2 *)0x97b9 = 0;
    *(undefined2 *)0x97b7 = 0;
    *(undefined2 *)0x97b5 = 0;
    *(undefined2 *)0x97b3 = 0;
    *(undefined2 *)0x97b1 = 0;
    *(undefined2 *)0x9745 = 0;
    *(undefined2 *)0x9743 = 0;
    *(undefined2 *)0x9741 = 0;
    *(undefined2 *)0x973f = 0;
    *(undefined2 *)0x973d = 0;
    *(undefined2 *)0x973b = 0;
    *(undefined2 *)0x9739 = 0;
    *(undefined2 *)0x9737 = 0;
    *(undefined2 *)0x9735 = 0;
    *(undefined2 *)0x9733 = 0;
    *(undefined2 *)0x9731 = 0;
    *(undefined2 *)0x972f = 0;
    *(undefined2 *)0x972d = 0;
    *(undefined2 *)0x972b = 0;
    *(undefined2 *)0x9729 = 0;
    *(undefined2 *)0x9727 = 0;
    *(undefined2 *)0x9725 = 0;
    *(undefined2 *)0x9723 = 0;
    for (iVar7 = 0; iVar7 < 10; iVar7 = iVar7 + 1) {
      *(undefined1 *)(iVar7 + -0x681b) = 0;
      *(undefined1 *)(iVar7 + -0x68b9) = 0;
    }
    uVar5 = *(undefined2 *)0x9092;
    uVar3 = *(undefined2 *)0x9090;
    *(undefined2 *)0x97fe = uVar5;
    *(undefined2 *)0x97fc = uVar3;
    *(undefined2 *)0x9760 = uVar5;
    *(undefined2 *)0x975e = uVar3;
    FUN_1000_e247(*(undefined2 *)0x9070,*(int *)0x9d2e * 0x7cc,0,0);
    FUN_1000_e852(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    FUN_1000_e247(*(undefined2 *)0x9070,0x462c,0,0);
    FUN_1000_e852(0x983e,1,0x163,*(undefined2 *)0x9070);
    FUN_1000_e913(*(undefined2 *)0x9070);
  }
LAB_1000_0775:
  FUN_1000_0128();
  if ((-1 < *(int *)0x9d2e) && (*(int *)0x9d2e < 7)) {
    FUN_1000_e247(*(undefined2 *)0x9070,*(int *)0x9d2e * 0x7cc + 0x34,0,0);
    FUN_1000_e852(0x90a6,1,2,*(undefined2 *)0x9070);
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_0079();
  FUN_1000_f3ba();
  return;
}

