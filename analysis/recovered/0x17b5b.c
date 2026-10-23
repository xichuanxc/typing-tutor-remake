/* ev_7d9d848042ed619bb8cc60972cbcac9aefb3d1f55a2bc05b835fdfa55ccc2f56 */

undefined2 __cdecl16near FUN_1000_7b5b(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 unaff_DS;
  
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    iVar1 = FUN_1000_7a75(*param_2,param_2[1],param_2[2],param_2[3]);
    if (iVar1 == -1) break;
    param_2 = param_2 + 4;
    param_1 = param_1 + -1;
  }
  return 0xffff;
}

