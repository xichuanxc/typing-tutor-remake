/* ev_69cd99cf87954ac66f77d436784e3114a3bfaf3426a859347e761fbb01086c02 */

void __cdecl16near FUN_1000_6b80(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  long lVar5;
  undefined1 uVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 *puVar9;
  int *piVar10;
  int unaff_BP;
  int iVar11;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar12;
  undefined4 uVar13;
  
  FUN_1000_e7bd();
  uVar6 = FUN_1000_7251(0x20f2);
  *(undefined1 *)(unaff_BP + -0x2b) = uVar6;
  for (iVar11 = 0; iVar11 < 2; iVar11 = iVar11 + 1) {
    iVar7 = FUN_1000_72ff(0x20f9);
    if (iVar7 == 0) {
      uVar6 = 0x30;
    }
    else {
      uVar6 = 0x2d;
    }
    *(undefined1 *)(iVar11 * 8 + unaff_BP + -0x18) = uVar6;
    for (iVar7 = 1; iVar7 < 4; iVar7 = iVar7 + 1) {
      FUN_1000_7448(iVar11 * 8 + iVar7 + unaff_BP + -0x18);
      *(undefined2 *)((iVar7 + -1) * 2 + unaff_BP + -0x2a) = 0;
    }
    *(undefined1 *)(iVar11 * 8 + iVar7 + unaff_BP + -0x18) = 0;
    uVar13 = FUN_1000_e4d3(iVar11 * 8 + unaff_BP + -0x18);
    puVar9 = (undefined2 *)(iVar11 * 4 + unaff_BP + -0x24);
    puVar9[1] = (int)((ulong)uVar13 >> 0x10);
    *puVar9 = (int)uVar13;
    if ((*(char *)(unaff_BP + -0x2b) == '@') || (*(char *)(unaff_BP + -0x2b) == '%')) {
      iVar7 = FUN_1000_bd33(uVar13);
      piVar10 = (int *)(iVar11 * 4 + unaff_BP + -0x24);
      piVar10[1] = iVar7 >> 0xf;
      *piVar10 = iVar7;
    }
  }
  cVar1 = *(char *)(unaff_BP + -0x2b);
  if (cVar1 == '%') {
    *(undefined2 *)(unaff_BP + -0x26) = 1;
    *(undefined2 *)(unaff_BP + -0x28) = 1;
    uVar13 = FUN_1000_f04d();
    *(undefined2 *)(unaff_BP + -0x22) = (int)((ulong)uVar13 >> 0x10);
    *(undefined2 *)(unaff_BP + -0x24) = (int)uVar13;
    uVar8 = *(undefined2 *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1a) = *(undefined2 *)(unaff_BP + -0x1e);
    *(undefined2 *)(unaff_BP + -0x1c) = uVar8;
    bVar12 = false;
    if (*(int *)(unaff_BP + -0x22) == 0) {
      bVar12 = *(int *)(unaff_BP + -0x24) == 0;
    }
    if (bVar12) {
      *(undefined2 *)(unaff_BP + -0x22) = 0;
      *(undefined2 *)(unaff_BP + -0x24) = 100;
    }
    uVar13 = FUN_1000_f04d();
    *(undefined2 *)(unaff_BP + -0x1e) = (int)((ulong)uVar13 >> 0x10);
    *(undefined2 *)(unaff_BP + -0x20) = (int)uVar13;
  }
  else if (cVar1 == '*') {
    uVar8 = FUN_1000_757b(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x26) = uVar8;
    *(undefined2 *)(unaff_BP + -0x2a) = uVar8;
    lVar5 = (ulong)*(uint *)(unaff_BP + -0x24) * (ulong)*(uint *)(unaff_BP + -0x20);
    *(int *)(unaff_BP + -0x1a) =
         (int)((ulong)lVar5 >> 0x10) +
         *(uint *)(unaff_BP + -0x24) * *(int *)(unaff_BP + -0x1e) +
         *(int *)(unaff_BP + -0x22) * *(int *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1c) = (int)lVar5;
  }
  else if (cVar1 == '+') {
    uVar8 = FUN_1000_757b(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x26) = uVar8;
    *(undefined2 *)(unaff_BP + -0x28) = uVar8;
    *(undefined2 *)(unaff_BP + -0x2a) = uVar8;
    uVar2 = *(uint *)(unaff_BP + -0x24);
    uVar3 = *(uint *)(unaff_BP + -0x20);
    *(int *)(unaff_BP + -0x1a) =
         *(int *)(unaff_BP + -0x22) + *(int *)(unaff_BP + -0x1e) +
         (uint)CARRY2(uVar2,*(uint *)(unaff_BP + -0x20));
    *(int *)(unaff_BP + -0x1c) = uVar2 + uVar3;
  }
  else if (cVar1 == '-') {
    uVar8 = FUN_1000_757b(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x26) = uVar8;
    *(undefined2 *)(unaff_BP + -0x28) = uVar8;
    *(undefined2 *)(unaff_BP + -0x2a) = uVar8;
    uVar8 = *(undefined2 *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1a) = *(undefined2 *)(unaff_BP + -0x1e);
    *(undefined2 *)(unaff_BP + -0x1c) = uVar8;
    uVar8 = *(undefined2 *)(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x1e) = *(undefined2 *)(unaff_BP + -0x22);
    *(undefined2 *)(unaff_BP + -0x20) = uVar8;
    if (*(int *)(unaff_BP + -0x26) != 0) {
      iVar11 = FUN_1000_bd33(*(undefined2 *)(unaff_BP + -0x1c),*(undefined2 *)(unaff_BP + -0x1a));
      *(int *)(unaff_BP + -0x1a) = iVar11 >> 0xf;
      *(int *)(unaff_BP + -0x1c) = iVar11;
      iVar11 = FUN_1000_bd33(*(undefined2 *)(unaff_BP + -0x20),*(undefined2 *)(unaff_BP + -0x1e));
      *(int *)(unaff_BP + -0x1e) = iVar11 >> 0xf;
      *(int *)(unaff_BP + -0x20) = iVar11;
    }
    uVar2 = *(uint *)(unaff_BP + -0x1c);
    uVar3 = *(uint *)(unaff_BP + -0x20);
    *(int *)(unaff_BP + -0x22) =
         *(int *)(unaff_BP + -0x1a) + *(int *)(unaff_BP + -0x1e) +
         (uint)CARRY2(uVar2,*(uint *)(unaff_BP + -0x20));
    *(int *)(unaff_BP + -0x24) = uVar2 + uVar3;
  }
  else if (cVar1 == '/') {
    uVar8 = FUN_1000_757b(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x26) = uVar8;
    *(undefined2 *)(unaff_BP + -0x2a) = uVar8;
    uVar8 = *(undefined2 *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1a) = *(undefined2 *)(unaff_BP + -0x1e);
    *(undefined2 *)(unaff_BP + -0x1c) = uVar8;
    iVar11 = *(int *)(unaff_BP + -0x22);
    uVar2 = *(uint *)(unaff_BP + -0x24);
    *(int *)(unaff_BP + -0x1e) = iVar11;
    *(uint *)(unaff_BP + -0x20) = uVar2;
    lVar5 = (ulong)uVar2 * (ulong)*(uint *)(unaff_BP + -0x1c);
    *(int *)(unaff_BP + -0x22) =
         (int)((ulong)lVar5 >> 0x10) +
         uVar2 * *(int *)(unaff_BP + -0x1a) + iVar11 * *(int *)(unaff_BP + -0x1c);
    *(undefined2 *)(unaff_BP + -0x24) = (int)lVar5;
  }
  else if (cVar1 == '@') {
    *(undefined2 *)(unaff_BP + -0x26) = 1;
    *(undefined2 *)(unaff_BP + -0x28) = 1;
    lVar5 = (ulong)*(uint *)(unaff_BP + -0x24) * (ulong)*(uint *)(unaff_BP + -0x20);
    *(int *)(unaff_BP + -0x1a) =
         (int)((ulong)lVar5 >> 0x10) +
         *(uint *)(unaff_BP + -0x24) * *(int *)(unaff_BP + -0x1e) +
         *(int *)(unaff_BP + -0x22) * *(int *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1c) = (int)lVar5;
  }
  if (*(int *)(unaff_BP + -0x2a) != 0) {
    puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar4 = 0x24;
  }
  FUN_1000_bc82(*(undefined2 *)(unaff_BP + -0x24),*(undefined2 *)(unaff_BP + -0x22),
                *(undefined2 *)(unaff_BP + 4));
  FUN_1000_74ab(*(undefined2 *)(unaff_BP + 4),*(undefined2 *)(unaff_BP + -0x2a));
  iVar11 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar11;
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = 0x20;
  if (*(char *)(unaff_BP + -0x2b) == '@') {
    FUN_1000_c63b(*(undefined2 *)(unaff_BP + 4));
    iVar11 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar11;
    puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar4 = 0x20;
  }
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = *(undefined1 *)(unaff_BP + -0x2b);
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = 0x20;
  if (*(char *)(unaff_BP + -0x2b) == '%') {
    FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),0x20fb);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 3;
  }
  if (*(int *)(unaff_BP + -0x28) != 0) {
    puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar4 = 0x24;
  }
  FUN_1000_bc82(*(undefined2 *)(unaff_BP + -0x20),*(undefined2 *)(unaff_BP + -0x1e),
                *(undefined2 *)(unaff_BP + 4));
  FUN_1000_74ab(*(undefined2 *)(unaff_BP + 4),*(undefined2 *)(unaff_BP + -0x28));
  iVar11 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar11;
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = 0x20;
  uVar6 = FUN_1000_75e2(unaff_BP + -0x1c);
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = uVar6;
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = 0x20;
  if (*(int *)(unaff_BP + -0x26) != 0) {
    puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar4 = 0x24;
  }
  FUN_1000_bc82(*(undefined2 *)(unaff_BP + -0x1c),*(undefined2 *)(unaff_BP + -0x1a),
                *(undefined2 *)(unaff_BP + 4));
  FUN_1000_74ab(*(undefined2 *)(unaff_BP + 4),*(undefined2 *)(unaff_BP + -0x26));
  return;
}

