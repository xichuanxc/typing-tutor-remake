/* ev_77b50ddbfe574679d254eea9da29d6f1393cf6da5edcc1b20c8c2b3b2fd6fe6c */

void __cdecl16near FUN_1000_74ab(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  int unaff_BP;
  int iVar6;
  int iVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  pcVar1 = (char *)*(undefined2 *)(unaff_BP + 4);
  *(uint *)(unaff_BP + -0xf) = (uint)(*pcVar1 == '-');
  uVar4 = 3;
  if (*(char *)(unaff_BP + 6) != '\0') {
    uVar4 = 5;
  }
  *(undefined2 *)(unaff_BP + -0xd) = uVar4;
  FUN_1000_e74e(unaff_BP + -0xb,pcVar1);
  iVar6 = 0;
  iVar5 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  if (*(int *)(unaff_BP + -0xd) + *(int *)(unaff_BP + -0xf) < iVar5) {
    for (; iVar6 < iVar5 - *(int *)(unaff_BP + -0xd); iVar6 = iVar6 + 1) {
      uVar3 = *(undefined1 *)(iVar6 + unaff_BP + -0xb);
      puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar2 = uVar3;
    }
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = 0x2c;
  }
  for (; iVar6 < (iVar5 - *(int *)(unaff_BP + -0xd)) + 3; iVar6 = iVar6 + 1) {
    uVar3 = *(undefined1 *)(iVar6 + unaff_BP + -0xb);
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = uVar3;
  }
  if (*(char *)(unaff_BP + 6) != '\0') {
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = 0x2e;
    uVar3 = 0x30;
    iVar7 = iVar6;
    if (1 < iVar5) {
      iVar7 = iVar6 + 1;
      uVar3 = *(undefined1 *)(iVar6 + unaff_BP + -0xb);
    }
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = uVar3;
    uVar3 = *(undefined1 *)(unaff_BP + iVar7 + -0xb);
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = uVar3;
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

