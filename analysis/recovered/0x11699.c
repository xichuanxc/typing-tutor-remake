/* ev_beff1764ca9cea4306931acfa7a0fcce703f6b2cdd8237ba5bf91bfdb401da2a */

/* WARNING: Removing unreachable block (ram,0x0001218b) */

void __cdecl16near FUN_1000_1699(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  undefined4 uVar8;
  long lVar9;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -4) = 3;
  *(undefined2 *)(unaff_BP + -6) = 3;
  FUN_1000_2692(0xfef,0x843);
  *(int *)(unaff_BP + -0xc) = (uint)*(byte *)((uint)*(byte *)0x90b7 * 2 + 0x7ed) * 10;
  *(int *)(unaff_BP + -0xe) = (uint)*(byte *)((uint)*(byte *)0x90b7 * 2 + 0x7ee) * 10;
  uVar2 = (uint)((ulong)*(uint *)0x976e * 2);
  uVar5 = *(uint *)0x9766 + *(uint *)0x976a;
  uVar2 = FUN_1000_52dc(uVar5 - uVar2,
                        ((*(int *)0x9768 + *(int *)0x976c +
                         (uint)CARRY2(*(uint *)0x9766,*(uint *)0x976a)) -
                        ((int)((ulong)*(uint *)0x976e * 2 >> 0x10) + *(int *)0x9770 * 2)) -
                        (uint)(uVar5 < uVar2),0,0,*(undefined2 *)0x9762,*(undefined2 *)0x9764);
  *(int *)(unaff_BP + -2) = *(int *)0x99a4 - *(int *)0x908c;
  iVar3 = *(int *)0x99a4 - *(int *)0x9090;
  *(int *)(unaff_BP + -10) = iVar3;
  if (iVar3 != 0) {
    if (iVar3 < 7) {
      for (iVar3 = *(int *)(unaff_BP + -10); iVar3 < 7; iVar3 = iVar3 + 1) {
        *(undefined2 *)((iVar3 - *(int *)(unaff_BP + -10)) * 2 + -0x6f68) =
             *(undefined2 *)(iVar3 * 2 + -0x6f68);
      }
      for (iVar3 = 7 - *(int *)(unaff_BP + -10); iVar3 < 7; iVar3 = iVar3 + 1) {
        *(undefined2 *)(iVar3 * 2 + -0x6f68) = 0;
      }
    }
    else {
      for (iVar3 = 0; iVar3 < 7; iVar3 = iVar3 + 1) {
        *(undefined2 *)(iVar3 * 2 + -0x6f68) = 0;
      }
    }
  }
  *(undefined2 *)(unaff_BP + -8) = 0;
  for (iVar3 = 0; iVar3 < 7; iVar3 = iVar3 + 1) {
    *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + *(int *)(iVar3 * 2 + -0x6f68);
  }
  uVar4 = FUN_1000_af51(0x1d6,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  if (*(int *)(unaff_BP + -10) < 0xf) {
    if (*(int *)(unaff_BP + -10) < 8) {
      if (*(int *)(unaff_BP + -0xe) < *(int *)(unaff_BP + -8)) {
        uVar4 = FUN_1000_af51(0x2b7,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
      if (0 < *(int *)(unaff_BP + -8)) {
        uVar4 = FUN_1000_af51(0x343,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_24e8(*(int *)(unaff_BP + -8),*(int *)(unaff_BP + -8) >> 0xf,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_167f(*(int *)(unaff_BP + -8),*(int *)(unaff_BP + -8) >> 0xf,0xffff,2,1,0x17
                              ,0x4e,unaff_BP + -4,unaff_BP + -6);
        uVar4 = FUN_1000_af51(uVar4);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x359,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
      if (*(int *)(unaff_BP + -8) < *(int *)(unaff_BP + -0xc)) {
        uVar4 = FUN_1000_af51(0x36c,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        iVar3 = *(int *)(unaff_BP + -0xc) - *(int *)(unaff_BP + -8);
        FUN_1000_24e8(iVar3,iVar3 >> 0xf,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        iVar3 = *(int *)(unaff_BP + -0xc) - *(int *)(unaff_BP + -8);
        uVar4 = FUN_1000_167f(iVar3,iVar3 >> 0xf,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        uVar4 = FUN_1000_af51(uVar4);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x3a3,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
      else if (*(int *)(unaff_BP + -0xe) < *(int *)(unaff_BP + -8)) {
        uVar4 = FUN_1000_af51(0x2be,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x662,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
      else {
        uVar4 = FUN_1000_af51(0x3c6,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_24e8(*(int *)(unaff_BP + -0xc),*(int *)(unaff_BP + -0xc) >> 0xf,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x65a,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_24e8(*(int *)(unaff_BP + -0xe),*(int *)(unaff_BP + -0xe) >> 0xf,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_167f(*(int *)(unaff_BP + -0xe),*(int *)(unaff_BP + -0xe) >> 0xf,0xffff,2,1,
                              0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        uVar4 = FUN_1000_af51(uVar4);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x3f2,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
    }
    else {
      uVar4 = FUN_1000_af51(0x26b,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
    }
  }
  else {
    uVar4 = FUN_1000_af51(0x1f7,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
  }
  bVar7 = false;
  if (*(int *)0x9768 == 0) {
    bVar7 = *(int *)0x9766 == 0;
  }
  if (bVar7) {
    bVar7 = false;
    if (*(int *)0x976c == 0) {
      bVar7 = *(int *)0x976a == 0;
    }
    if (bVar7) goto LAB_1000_200c;
  }
  FUN_1000_253e(unaff_BP + -4,unaff_BP + -6);
  if (*(int *)(unaff_BP + -2) < 0xf) {
    uVar4 = FUN_1000_af51(0x4a3,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    if (1 < *(int *)(unaff_BP + -2)) {
      FUN_1000_bc82(*(int *)(unaff_BP + -2),*(int *)(unaff_BP + -2) >> 0xf,unaff_BP + -0x21);
      uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x4c8,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
    }
    uVar4 = FUN_1000_af51(0x4d4,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    FUN_1000_24e8(*(undefined2 *)0x9094,*(undefined2 *)0x9096,unaff_BP + -0x21);
    uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_167f(*(undefined2 *)0x9094,*(undefined2 *)0x9096,0xffff,2,1,0x17,0x4e,
                          unaff_BP + -4,unaff_BP + -6);
    uVar4 = FUN_1000_af51(uVar4);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_af51(0x4f3,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
  }
  else {
    uVar4 = FUN_1000_af51(0x438,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar8 = FUN_1000_f04d(unaff_BP + -0x21);
    FUN_1000_bc82(uVar8);
    uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_af51(0x46b,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    FUN_1000_24e8(*(undefined2 *)0x9094,*(undefined2 *)0x9096,unaff_BP + -0x21);
    uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_167f(*(undefined2 *)0x9094,*(undefined2 *)0x9096,0xffff,2,1,0x17,0x4e,
                          unaff_BP + -4,unaff_BP + -6);
    uVar4 = FUN_1000_af51(uVar4);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_af51(0x487,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar8 = FUN_1000_f0a7(unaff_BP + -0x21);
    FUN_1000_24e8(uVar8);
    uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar8 = FUN_1000_f0a7(0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    uVar4 = FUN_1000_167f(uVar8);
    uVar4 = FUN_1000_af51(uVar4);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_af51(0x498,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
  }
  uVar4 = FUN_1000_af51(0x4f5,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  FUN_1000_bc82(uVar2,(int)uVar2 >> 0xf,unaff_BP + -0x21);
  uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  uVar4 = FUN_1000_af51(0x50e,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  iVar3 = FUN_1000_529a(*(undefined2 *)0x9766,*(undefined2 *)0x9768,*(undefined2 *)0x976a,
                        *(undefined2 *)0x976c,unaff_BP + -0x21);
  FUN_1000_bc82(iVar3,iVar3 >> 0xf);
  uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  uVar4 = FUN_1000_af51(0x65f,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
LAB_1000_200c:
  if (((*(int *)0x9096 != 0) || (0x28 < *(uint *)0x9094)) && (1 < *(int *)(unaff_BP + -2))) {
    FUN_1000_253e(unaff_BP + -4,unaff_BP + -6);
    if ((uVar2 < *(byte *)0x90b8) || (*(byte *)0x90af < 0x3f)) {
      lVar9 = (ulong)*(uint *)(unaff_BP + -2) * (ulong)(uint)*(byte *)0x90b8;
      *(int *)(unaff_BP + -0x14) =
           (int)((ulong)lVar9 >> 0x10) +
           ((int)*(uint *)(unaff_BP + -2) >> 0xf) * (uint)*(byte *)0x90b8;
      *(undefined2 *)(unaff_BP + -0x16) = (int)lVar9;
      if (*(char *)0x90b5 == '\x02') {
        uVar5 = (uint)((ulong)*(uint *)0x94a7 * 2);
        uVar6 = *(uint *)0x949f + *(uint *)0x94a3;
        iVar3 = FUN_1000_52dc(uVar6 - uVar5,
                              ((*(int *)0x94a1 + *(int *)0x94a5 +
                               (uint)CARRY2(*(uint *)0x949f,*(uint *)0x94a3)) -
                              ((int)((ulong)*(uint *)0x94a7 * 2 >> 0x10) + *(int *)0x94a9 * 2)) -
                              (uint)(uVar6 < uVar5),0,0,*(undefined2 *)0x949b,*(undefined2 *)0x949d)
        ;
        if (iVar3 < (int)uVar2) {
          uVar8 = FUN_1000_f04d();
        }
        else {
          uVar8 = 999999;
        }
        *(undefined2 *)(unaff_BP + -0x10) = (int)((ulong)uVar8 >> 0x10);
        *(undefined2 *)(unaff_BP + -0x12) = (int)uVar8;
      }
      else {
        if (uVar2 == 0) {
          uVar8 = 999999;
        }
        else {
          uVar8 = FUN_1000_f04d();
        }
        *(undefined2 *)(unaff_BP + -0x10) = (int)((ulong)uVar8 >> 0x10);
        *(undefined2 *)(unaff_BP + -0x12) = (int)uVar8;
      }
      uVar5 = *(uint *)(unaff_BP + -2);
      puVar1 = (uint *)(unaff_BP + -0x12);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 - uVar5;
      *(int *)(unaff_BP + -0x10) =
           (*(int *)(unaff_BP + -0x10) - ((int)uVar5 >> 0xf)) - (uint)(uVar2 < uVar5);
      if ((*(int *)(unaff_BP + -0x10) < 1) &&
         ((*(int *)(unaff_BP + -0x10) != 0 || (*(int *)(unaff_BP + -0x12) == 0)))) {
        *(undefined2 *)(unaff_BP + -0x10) = 0;
        *(undefined2 *)(unaff_BP + -0x12) = 1;
      }
      lVar9 = FUN_1000_f0a7();
      lVar9 = (lVar9 - *(int *)(unaff_BP + -2)) *
              CONCAT22(*(undefined2 *)(unaff_BP + -0x10),*(undefined2 *)(unaff_BP + -0x12));
      *(undefined2 *)(unaff_BP + -0x10) = (int)((ulong)lVar9 >> 0x10);
      *(undefined2 *)(unaff_BP + -0x12) = (int)lVar9;
      if (lVar9 < 0xb4) {
        uVar4 = FUN_1000_af51(0x535,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_bc82(*(undefined1 *)0x90b8,0,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x57b,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_c0c6(*(uint *)0x99a4 + *(uint *)(unaff_BP + -0x12),
                      *(int *)0x99a6 + *(int *)(unaff_BP + -0x10) +
                      (uint)CARRY2(*(uint *)0x99a4,*(uint *)(unaff_BP + -0x12)),unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x599,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
    }
    else if (((uVar2 < *(byte *)0x90b8) || (*(byte *)0x90b8 + 9 < uVar2)) ||
            (*(char *)0x90b8 == 'd')) {
      uVar4 = FUN_1000_af51(0x61e,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      FUN_1000_bc82(*(byte *)0x90b8 + 9,0xfff6 < *(byte *)0x90b8,unaff_BP + -0x21);
      uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x64c,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x662,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
    }
    else {
      uVar4 = FUN_1000_af51(0x5c9,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      FUN_1000_bc82(*(undefined1 *)0x90b8,0,unaff_BP + -0x21);
      uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x65a,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      FUN_1000_bc82(*(byte *)0x90b8 + 9,0xfff6 < *(byte *)0x90b8,unaff_BP + -0x21);
      uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x5ee,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x662,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
    }
  }
  iVar3 = *(int *)(unaff_BP + -4);
  if (*(int *)(unaff_BP + -6) != 3) {
    iVar3 = iVar3 + 1;
  }
  FUN_1000_ae2b(2,1,iVar3,0x4e,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  if (*(int *)(unaff_BP + -6) == 3) {
    iVar3 = *(int *)(unaff_BP + -4) + 1;
  }
  else {
    iVar3 = *(int *)(unaff_BP + -4) + 2;
  }
  FUN_1000_1605(iVar3);
  return;
}

