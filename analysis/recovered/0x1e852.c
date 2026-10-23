/* ev_a780240561a816ed1955c866cbc72282b9c6be5217a91a6eb59af323057c25bd */

int __cdecl16near FUN_1000_e852(char *param_1,int param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0;
  while( true ) {
    if ((uint)(param_2 * param_3) <= uVar2) {
      return param_3;
    }
    iVar1 = FUN_1000_e8c5((int)*param_1,param_4);
    if (iVar1 == -1) break;
    uVar2 = uVar2 + 1;
    param_1 = param_1 + 1;
  }
  return 0;
}

