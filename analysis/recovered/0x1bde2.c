/* ev_55914a5b220b4b4816c91042bf8d8092acd441528075f622c2c1e1299c790a65 */

/* WARNING: Removing unreachable block (ram,0x0001bf89) */

void __cdecl16near
FUN_1000_bde2(undefined2 param_1,undefined2 param_2,undefined2 *param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  long lVar3;
  int local_e;
  int local_a;
  
  iVar1 = FUN_1000_f04d();
  FUN_1000_f04d();
  local_e = FUN_1000_f04d();
  FUN_1000_f04d();
  lVar3 = FUN_1000_f04d();
  uVar2 = FUN_1000_f04d();
  *param_3 = uVar2;
  local_e = iVar1 * 100 + local_e;
  if (lVar3 < 10) {
    local_a = (int)lVar3 + 3;
  }
  else {
    local_a = (int)lVar3 + -9;
    local_e = local_e + 1;
  }
  *param_5 = local_e;
  *param_4 = local_a;
  return;
}

