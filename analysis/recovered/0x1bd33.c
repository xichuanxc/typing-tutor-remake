/* ev_bbce2478399e59db76193635a324bbd1d312fe4aeaa191b72dcc0e4a1699c67a */

undefined4 __cdecl16near FUN_1000_bd33(uint param_1,int param_2)

{
  ulong uVar1;
  uint uVar2;
  bool bVar3;
  
  if ((param_2 < 1) && (param_2 != 0)) {
    uVar1 = (ulong)param_1;
    uVar2 = (uint)(uVar1 * 2);
    bVar3 = param_1 < uVar2;
    param_1 = param_1 - uVar2;
    param_2 = (-param_2 - (int)(uVar1 * 2 >> 0x10)) - (uint)bVar3;
  }
  return CONCAT22(param_2,param_1);
}

