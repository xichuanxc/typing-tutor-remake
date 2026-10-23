/* ev_35e91c820944d4c7149c5a30c96d0cd01394ea278a56456e4f01499ceec1880d */

int __cdecl16near FUN_1000_75e2(void)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  uint uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  undefined4 uVar8;
  undefined2 *puVar9;
  
  FUN_1000_e7bd();
  bVar7 = false;
  if (((int *)*(int *)(unaff_BP + 4))[1] == 0) {
    bVar7 = *(int *)*(int *)(unaff_BP + 4) == 0;
  }
  if (!bVar7) {
    cVar3 = FUN_1000_7251(0x2149);
    *(char *)(unaff_BP + -1) = cVar3;
    if (cVar3 != '=') {
      iVar4 = FUN_1000_bd74(100);
      iVar5 = FUN_1000_bd74(100);
      uVar6 = iVar4 + iVar5 + 1;
      if (((*(char *)(unaff_BP + -1) == '>') &&
          ((iVar4 = *(int *)(*(int *)(unaff_BP + 4) + 2), 0 < iVar4 || (iVar4 == 0)))) ||
         ((*(char *)(unaff_BP + -1) == '<' &&
          ((iVar4 = *(int *)(*(int *)(unaff_BP + 4) + 2), iVar4 < 1 && (iVar4 != 0)))))) {
        puVar9 = (undefined2 *)*(undefined2 *)(unaff_BP + 4);
        uVar8 = FUN_1000_f04d();
        puVar9[1] = (int)((ulong)uVar8 >> 0x10);
        *puVar9 = (int)uVar8;
      }
      else {
        puVar1 = (uint *)*(int *)(unaff_BP + 4);
        uVar2 = *puVar1;
        puVar9 = (undefined2 *)*(int *)(unaff_BP + 4);
        puVar9[1] = (int)((ulong)uVar6 * (ulong)uVar2 >> 0x10) +
                    uVar6 * puVar1[1] + ((int)uVar6 >> 0xf) * *puVar1;
        *puVar9 = (int)((ulong)uVar6 * (ulong)uVar2);
      }
    }
    return (int)*(char *)(unaff_BP + -1);
  }
  return 0x3d;
}

