/* ev_8470d0d64f681604777bfc0f7ed4296fa1809e1040be3db9b642812d2d0a68b0 */

void __cdecl16near FUN_1000_8f6e(void)

{
  char *pcVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int unaff_BP;
  int iVar7;
  int iVar8;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if ((*(int *)0x9d2c == 8) || (*(int *)0x9d2c == 9)) {
    uVar2 = 0x40;
  }
  else {
    uVar2 = 0x4b;
  }
  *(undefined2 *)(unaff_BP + -2) = uVar2;
  for (iVar7 = 0; iVar7 < 10; iVar7 = iVar7 + 1) {
    *(undefined1 *)(*(int *)0x9d2c * 0x4f + iVar7 + -0x6b31) = 0;
    if ((*(int *)0x9d2c == 10) || (*(int *)0x9d2c == 0xb)) {
      iVar8 = 0x40;
    }
    else {
      iVar8 = 0;
    }
    for (; iVar8 < *(int *)(unaff_BP + -2); iVar8 = iVar8 + 1) {
      puVar4 = (undefined2 *)(iVar8 * 4 + *(int *)(unaff_BP + 8));
      puVar5 = (undefined2 *)(iVar8 * 4 + *(int *)(unaff_BP + 6));
      puVar6 = (undefined2 *)(iVar8 * 4 + *(int *)(unaff_BP + 4));
      iVar3 = FUN_1000_52dc(*puVar6,puVar6[1],*puVar5,puVar5[1],*puVar4,puVar4[1]);
      if ((iVar7 + 1) * 10 <= iVar3) {
        pcVar1 = (char *)(*(int *)0x9d2c * 0x4f + iVar7 + -0x6b31);
        *pcVar1 = *pcVar1 + '\x01';
      }
    }
  }
  return;
}

