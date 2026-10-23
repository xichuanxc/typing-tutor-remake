/* ev_45448bc5826e5a68b5463f5c4aa636ba38ec9088caa3c86ae434137b82c6fdf5 */

undefined2 __cdecl16near FUN_1000_64cc(void)

{
  byte bVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  
  pbVar2 = (byte *)*(undefined2 *)0x9d72;
  *(int *)0x9d72 = *(int *)0x9d72 + 1;
  bVar1 = *pbVar2;
  if (bVar1 == 0) {
    if (*(char *)*(undefined2 *)0x9d72 == '\0') {
      if (*(int *)0x2086 == -0x628c) {
        return 0;
      }
      *(int *)0x2086 = *(int *)0x2086 + -2;
      *(undefined2 *)0x9d72 = *(undefined2 *)*(undefined2 *)0x2086;
      uVar5 = FUN_1000_64cc();
      return uVar5;
    }
    FUN_1000_e74e(0x9bb,(char *)*(undefined2 *)0x9d72);
    iVar4 = FUN_1000_f139(*(undefined2 *)0x9d72);
    *(int *)0x9d72 = *(int *)0x9d72 + iVar4 + 1;
  }
  else if (((int)(char)bVar1 & 0x80U) == 0) {
    if ((bVar1 & 0x40) != 0) {
      puVar3 = (undefined2 *)*(undefined2 *)0x2086;
      *(int *)0x2086 = *(int *)0x2086 + 2;
      *puVar3 = *(undefined2 *)0x9d72;
      *(int *)0x9d72 = *(int *)(((int)(char)bVar1 & 0x3fU) * 2 + -0x79ce) + -0x7968;
      uVar5 = FUN_1000_64cc();
      return uVar5;
    }
    FUN_1000_665a(((int)(char)bVar1 & 0x3fU) - 1,0x9bb);
  }
  else {
    (*(code *)*(undefined2 *)(((int)(char)bVar1 & 0x7fU) * 2 + 0x2088))(0x9bb);
  }
  return 1;
}

