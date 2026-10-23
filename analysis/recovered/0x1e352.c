/* ev_a1065c78c5436a9bb4109121074110a21ea1a7be612efe221beb6bd14572fa94 */

uint __cdecl16near FUN_1000_e352(uint param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000_e8c5(param_1,param_2);
  if (iVar1 < 0) {
    param_1 = 0xffff;
  }
  else {
    iVar1 = FUN_1000_e8c5(param_1 >> 8,param_2);
    if (iVar1 < 0) {
      param_1 = 0xffff;
    }
  }
  return param_1;
}

