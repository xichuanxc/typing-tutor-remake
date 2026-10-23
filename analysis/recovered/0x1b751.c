/* ev_c52fc2218d27fa1e1ebaccdaad36df4d60f556f1c06180b26553cbb0df20c5b5 */

undefined2 __cdecl16near FUN_1000_b751(void)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  iVar2 = iVar1 + 2;
  if (iVar1 + 2 < *(int *)(unaff_BP + 8)) {
    iVar2 = *(int *)(unaff_BP + 8);
  }
  *(int *)(unaff_BP + -6) = iVar2;
  if (iVar2 < 0x4c) {
    iVar2 = (0x4a - iVar2) / 2;
    *(int *)(unaff_BP + -2) = iVar2;
    iVar2 = (iVar2 + -2) / 3;
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) - iVar2;
    *(int *)(unaff_BP + -4) = iVar2 * 2 + *(int *)(unaff_BP + -2) + *(int *)(unaff_BP + -6) + 5;
    *(undefined2 *)(unaff_BP + -8) = 1;
  }
  else {
    *(undefined2 *)(unaff_BP + -2) = 2;
    *(undefined2 *)(unaff_BP + -4) = 0x4d;
    *(undefined2 *)(unaff_BP + -8) = 2;
  }
  FUN_1000_b1f3(0,1,7);
  FUN_1000_ae2b(9,*(undefined2 *)(unaff_BP + -2),*(int *)(unaff_BP + -8) + 0x10,
                *(undefined2 *)(unaff_BP + -4),0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  FUN_1000_b1f3(0,1,7);
  uVar3 = 0xffff;
  if (1 < *(int *)(unaff_BP + 10)) {
    uVar3 = 0;
  }
  FUN_1000_af51(*(undefined2 *)(unaff_BP + 4),uVar3,10,*(undefined2 *)(unaff_BP + -2),
                *(int *)(unaff_BP + -8) + 0xb,*(undefined2 *)(unaff_BP + -4),0,0);
  FUN_1000_f6a4(0x859c);
  FUN_1000_af51(0x859f,1,*(int *)(unaff_BP + -8) + 0xd,*(undefined2 *)(unaff_BP + -2),
                *(int *)(unaff_BP + -8) + 0xf,*(undefined2 *)(unaff_BP + -4),0,0);
  FUN_1000_b1f3(0,1,7);
  iVar2 = FUN_1000_b8be(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                        *(int *)(unaff_BP + -8) + 0xc,
                        (((*(int *)(unaff_BP + -4) - *(int *)(unaff_BP + -2)) -
                         *(int *)(unaff_BP + 8)) + -2) / 2 + *(int *)(unaff_BP + -2) + 2,
                        *(undefined2 *)(unaff_BP + 10));
  if (iVar2 == -1) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

