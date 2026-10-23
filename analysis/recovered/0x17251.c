/* ev_7d354cbcaa1c54fa2c99527dfca2da22062f83d89a17a7e5e67d9117d97acaaa */

int __cdecl16near FUN_1000_7251(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -0x38) = 0;
  iVar6 = 0;
  iVar5 = 0;
  while( true ) {
    iVar3 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
    if (iVar3 <= iVar6) break;
    iVar4 = FUN_1000_72dd((int)*(char *)(*(int *)(unaff_BP + 4) + iVar6));
    iVar3 = iVar5;
    if (iVar4 != 0) {
      cVar1 = *(char *)(*(int *)(unaff_BP + 4) + iVar6);
      *(char *)(unaff_BP + iVar5 + -0x1b) = cVar1;
      iVar3 = FUN_1000_722b((int)cVar1);
      bVar2 = *(byte *)(iVar3 + -0x6f45);
      iVar3 = iVar5 + 1;
      *(byte *)(iVar5 + unaff_BP + -0x36) = bVar2;
      *(int *)(unaff_BP + -0x38) = *(int *)(unaff_BP + -0x38) + (uint)bVar2;
    }
    iVar6 = iVar6 + 1;
    iVar5 = iVar3;
  }
  if (iVar5 != 0) {
    iVar5 = FUN_1000_bd74(*(undefined2 *)(unaff_BP + -0x38));
    *(uint *)(unaff_BP + -0x38) = (uint)*(byte *)(unaff_BP + -0x36);
    iVar6 = 0;
    while (*(int *)(unaff_BP + -0x38) < iVar5) {
      iVar6 = iVar6 + 1;
      *(int *)(unaff_BP + -0x38) =
           *(int *)(unaff_BP + -0x38) + (uint)*(byte *)(iVar6 + unaff_BP + -0x36);
    }
    return (int)*(char *)(unaff_BP + iVar6 + -0x1b);
  }
  return 0;
}

