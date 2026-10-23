/* ev_3b447d68835afccb713cf7080ac3626a3a38bad5ebd4ae37314a6726e2d4b971 */

undefined2 __cdecl16near FUN_1000_b21d(void)

{
  int *piVar1;
  int iVar2;
  int unaff_BP;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -10) = 0;
  if (*(int *)(unaff_BP + 10) < 2) {
    *(undefined2 *)(unaff_BP + 10) = 2;
  }
  *(int *)(unaff_BP + -0xc) = 0x18 - *(int *)(unaff_BP + 10);
  iVar2 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 0xe));
  *(int *)(unaff_BP + -2) = iVar2 / 0x45;
  *(int *)(unaff_BP + -8) = iVar2 / 0x45 + *(int *)(unaff_BP + 4) + 10;
  *(undefined2 *)(unaff_BP + -0xe) = 0;
  while ((*(int *)(unaff_BP + -0xe) < 2 && (*(int *)(unaff_BP + -0xc) < *(int *)(unaff_BP + -8)))) {
    *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + -2;
    *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + 1;
    *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + 1;
  }
  if (*(int *)(unaff_BP + -0xc) < *(int *)(unaff_BP + -8)) {
    return *(undefined2 *)(unaff_BP + 0xc);
  }
  iVar2 = (*(int *)(unaff_BP + -0xc) - *(int *)(unaff_BP + -8)) / 2 + *(int *)(unaff_BP + 10);
  *(int *)(unaff_BP + -0xe) = iVar2;
  *(int *)(unaff_BP + -0x10) = (uint)(*(int *)(unaff_BP + -10) == 0) + iVar2;
  iVar2 = 4;
  if (*(int *)(unaff_BP + -10) != 0) {
    iVar2 = 3;
  }
  *(int *)(unaff_BP + -0x12) = (*(int *)(unaff_BP + -0xe) + *(int *)(unaff_BP + -8)) - iVar2;
  *(int *)(unaff_BP + -0x14) =
       (*(int *)(unaff_BP + -0xe) + *(int *)(unaff_BP + -2) + 4) - *(int *)(unaff_BP + -10);
  iVar2 = (0x4d - *(int *)(unaff_BP + 6)) / 2;
  *(int *)(unaff_BP + -6) = iVar2 / 3;
  FUN_1000_b1f3(0,1,7);
  FUN_1000_ae2b(*(undefined2 *)(unaff_BP + -0xe),*(undefined2 *)(unaff_BP + -6),
                *(int *)(unaff_BP + -0xe) + *(int *)(unaff_BP + -8) + -1,
                0x50 - *(int *)(unaff_BP + -6),0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  FUN_1000_b1f3(0,1,7);
  FUN_1000_af51(*(undefined2 *)(unaff_BP + 0xe),0xffff,*(undefined2 *)(unaff_BP + -0x10),
                *(int *)(unaff_BP + -6) + 2,0x18,0x4e - *(int *)(unaff_BP + -6),0,0);
  FUN_1000_f6a4(0x8513);
  FUN_1000_af51(0x8516,1,*(undefined2 *)(unaff_BP + -0x12),*(int *)(unaff_BP + -6) + 2,0x18,
                0x4e - *(int *)(unaff_BP + -6),0,0);
  FUN_1000_b1f3(0,2,7);
  FUN_1000_ae2b(*(undefined2 *)(unaff_BP + -0x14),iVar2,
                *(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 4) + 1,
                iVar2 + *(int *)(unaff_BP + 6) + 2,0,0xcd,0xba,0xc9,0xbb,200,0xbc);
  FUN_1000_b1f3(0,2,1);
  for (iVar3 = 0; iVar3 < *(int *)(unaff_BP + 4); iVar3 = iVar3 + 1) {
    FUN_1000_b714(*(int *)(unaff_BP + -0x14) + iVar3 + 1,iVar2 + 1,
                  *(undefined2 *)(iVar3 * 2 + *(int *)(unaff_BP + 8)),*(undefined2 *)(unaff_BP + 6))
    ;
  }
  FUN_1000_b1f3(1,1,2);
  FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                *(undefined2 *)(unaff_BP + 6));
  FUN_1000_b1f3(0,1,7);
LAB_1000_b459:
  do {
    while( true ) {
      while( true ) {
        iVar3 = FUN_1000_f831();
        *(int *)(unaff_BP + -4) = iVar3;
        if (iVar3 == 0xd) {
          FUN_1000_b1f3(0,1,7);
          return *(undefined2 *)(unaff_BP + 0xc);
        }
        if (iVar3 != 0x1b) break;
        if (*(char *)0x2 != '\0') {
          FUN_1000_b1f3(0,1,7);
          return 0xffff;
        }
        FUN_1000_7e47(5);
      }
      if (iVar3 != 0x20) break;
LAB_1000_b4fe:
      FUN_1000_b1f3(0,2,1);
      FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                    *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                    *(undefined2 *)(unaff_BP + 6));
      FUN_1000_b1f3(1,1,2);
      *(int *)(unaff_BP + 0xc) = *(int *)(unaff_BP + 0xc) + 1;
      if (*(int *)(unaff_BP + 4) <= *(int *)(unaff_BP + 0xc)) {
        *(undefined2 *)(unaff_BP + 0xc) = 0;
      }
      FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                    *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                    *(undefined2 *)(unaff_BP + 6));
    }
    if (iVar3 != 200) {
      if (iVar3 == 0xd0) goto LAB_1000_b4fe;
      FUN_1000_7e47(5);
      goto LAB_1000_b459;
    }
    FUN_1000_b1f3(0,2,1);
    FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                  *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                  *(undefined2 *)(unaff_BP + 6));
    FUN_1000_b1f3(1,1,2);
    piVar1 = (int *)(unaff_BP + 0xc);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    if (SBORROW2(iVar3,1) != *piVar1 < 0) {
      *(int *)(unaff_BP + 0xc) = *(int *)(unaff_BP + 4) + -1;
    }
    FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                  *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                  *(undefined2 *)(unaff_BP + 6));
  } while( true );
}

