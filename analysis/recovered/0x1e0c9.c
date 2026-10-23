/* ev_df2625a17544252192a0fad62d2699ebcf7b7e66084e7023c6ee0696ebde5e18 */

int __cdecl16near FUN_1000_e0c9(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint local_1a;
  byte local_18 [11];
  char local_d [11];
  
  local_1a = 0;
  iVar6 = 0;
  iVar5 = 0;
  while( true ) {
    iVar3 = FUN_1000_f139(param_1);
    if (iVar3 <= iVar6) break;
    iVar4 = FUN_1000_e0a7((int)*(char *)(param_1 + iVar6));
    iVar3 = iVar5;
    if (iVar4 != 0) {
      cVar1 = *(char *)(param_1 + iVar6);
      local_d[iVar5] = cVar1;
      iVar3 = FUN_1000_e08c((int)cVar1);
      bVar2 = *(byte *)(iVar3 + -0x6f45);
      iVar3 = iVar5 + 1;
      local_18[iVar5] = bVar2;
      local_1a = local_1a + bVar2;
    }
    iVar6 = iVar6 + 1;
    iVar5 = iVar3;
  }
  if (iVar5 == 0) {
    iVar5 = 0;
  }
  else {
    iVar6 = FUN_1000_bd74(local_1a);
    local_1a = (uint)local_18[0];
    iVar5 = 0;
    while ((int)local_1a < iVar6) {
      local_1a = local_1a + local_18[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = (int)local_d[iVar5];
  }
  return iVar5;
}

