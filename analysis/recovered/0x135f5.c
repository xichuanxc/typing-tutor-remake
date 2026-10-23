/* ev_5e8b1e6d86790f276508b45892b910a70bfa67fbc04fb333cd803e48c6246282 */

undefined2 __cdecl16near FUN_1000_35f5(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(int *)(unaff_BP + 4) == 0xcd) {
    uVar1 = *(undefined2 *)(unaff_BP + 8);
    *(int *)(unaff_BP + 8) = *(int *)(unaff_BP + 8) + 1;
    FUN_1000_39c4(*(undefined2 *)(unaff_BP + 6),uVar1);
    if (*(byte *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134e) - 1 < *(uint *)(unaff_BP + 8)) {
      *(undefined2 *)(unaff_BP + 8) = 0;
    }
  }
  else {
    uVar1 = *(undefined2 *)(unaff_BP + 8);
    *(int *)(unaff_BP + 8) = *(int *)(unaff_BP + 8) + -1;
    FUN_1000_39c4(*(undefined2 *)(unaff_BP + 6),uVar1);
    if (*(int *)(unaff_BP + 8) < 0) {
      *(int *)(unaff_BP + 8) = *(byte *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134e) - 1;
    }
  }
  FUN_1000_394a(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8));
  return *(undefined2 *)(unaff_BP + 8);
}

