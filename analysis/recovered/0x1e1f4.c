/* ev_77b3e9012e5fff7c966a407dcadfa38c4120aaa3f9c68ff69b16424721980d58 */

int __cdecl16near FUN_1000_e1f4(undefined1 *param_1,int param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  undefined2 unaff_DS;
  int local_6;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (param_3 <= iVar2) {
      return iVar2;
    }
    for (local_6 = param_2; local_6 != 0; local_6 = local_6 + -1) {
      iVar1 = FUN_1000_e3ce(param_4);
      if (iVar1 == -1) {
        return iVar2;
      }
      *param_1 = (char)iVar1;
      param_1 = param_1 + 1;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}

