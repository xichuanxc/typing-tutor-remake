/* ev_acadac75e53ed01b500ad5e45e832c9199424df10e719d94dc6c107275cd8419 */

undefined4 __cdecl16near FUN_1000_e4d3(char *param_1)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  bool bVar5;
  uint local_6;
  int local_4;
  
  for (; (*param_1 == ' ' || (*param_1 == '\t')); param_1 = param_1 + 1) {
  }
  bVar5 = false;
  if (*param_1 == '-') {
    bVar5 = true;
    param_1 = param_1 + 1;
  }
  else if (*param_1 == '+') {
    param_1 = param_1 + 1;
  }
  local_4 = 0;
  local_6 = 0;
  while ((*(byte *)(*param_1 + -0x7183) & 4) != 0) {
    uVar2 = (uint)*param_1;
    uVar1 = (ulong)local_6;
    uVar3 = (uint)(uVar1 * 10);
    uVar4 = uVar2 + uVar3;
    local_6 = uVar4 - 0x30;
    local_4 = ((int)uVar2 >> 0xf) + (int)(uVar1 * 10 >> 0x10) + local_4 * 10 +
              (uint)CARRY2(uVar2,uVar3) + -1 + (uint)(0x2f < uVar4);
    param_1 = param_1 + 1;
  }
  if (bVar5) {
    bVar5 = local_6 != 0;
    local_6 = -local_6;
    local_4 = -(uint)bVar5 - local_4;
  }
  return CONCAT22(local_4,local_6);
}

