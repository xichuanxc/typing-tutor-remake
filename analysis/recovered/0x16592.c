/* ev_a15dc46b72b8877bd0225e7de048b1435bc8d261ba74fb5b2d1dc75767e6b5f3 */

int __cdecl16near FUN_1000_6592(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  undefined2 local_4;
  
  iVar1 = FUN_1000_bd74(*(undefined2 *)0x9d36);
  iVar2 = FUN_1000_722b((int)*(char *)0x7aee);
  local_4 = (uint)*(byte *)(iVar2 + -0x6f45);
  iVar2 = 0;
  for (; (int)local_4 < iVar1; local_4 = local_4 + *(byte *)(iVar3 + -0x6f45)) {
    iVar3 = FUN_1000_722b((int)*(char *)(iVar2 + 0x7aef));
    iVar2 = iVar2 + 1;
  }
  iVar1 = 0;
  if (3 < iVar2) {
    iVar1 = iVar2 + -3;
  }
  *(int *)0x9d98 = iVar1;
  iVar3 = ((uint)*(byte *)0x90ae - *(int *)0x9d98) + 1;
  iVar1 = FUN_1000_bd74((int)((((uint)*(byte *)0x90ae - *(int *)0x9d98) + 2) * iVar3) / 2);
  iVar2 = *(int *)0x9d98;
  for (local_4 = iVar3; (int)local_4 < iVar1; local_4 = local_4 + iVar3) {
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

