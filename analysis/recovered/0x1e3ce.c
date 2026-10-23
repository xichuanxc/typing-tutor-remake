/* ev_7f1e37a6b213ea3abe262617a2bd14fd72ffd09e8f6ddedabef349a14df546e7 */

uint __cdecl16near FUN_1000_e3ce(uint *param_1)

{
  uint uVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  if (param_1[1] <= *param_1) {
    if ((param_1[3] & 0x18) != 0) {
      return 0xffff;
    }
    *(byte *)(param_1 + 3) = (byte)param_1[3] & 0xfb;
    if (param_1[2] == 0) {
      FUN_1000_ea5e(param_1);
    }
    iVar4 = FUN_1000_f3e0((int)*(char *)((int)param_1 + 7),param_1[2],
                          *(undefined2 *)((int)param_1 + 9));
    if (iVar4 < 1) {
      bVar3 = 0x10;
      if (iVar4 == 0) {
        bVar3 = 8;
      }
      *(byte *)(param_1 + 3) = (byte)param_1[3] | bVar3;
      return 0xffff;
    }
    uVar1 = param_1[2];
    *param_1 = uVar1;
    param_1[1] = uVar1 + iVar4;
  }
  pbVar2 = (byte *)*param_1;
  *param_1 = *param_1 + 1;
  return (uint)*pbVar2;
}

