/* ev_2f0312fc0c416c8e46632844f1bf3f1377dea23604e2d0b747fa21736909184d */

int __cdecl16near FUN_1000_f4eb(undefined2 param_1,char *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined2 unaff_DS;
  
  iVar2 = param_3;
  pcVar4 = param_2;
  while (iVar3 = iVar2 + -1, iVar2 != 0) {
    pcVar5 = pcVar4 + 1;
    pcVar1 = pcVar4;
    iVar2 = iVar3;
    pcVar4 = pcVar5;
    if (*pcVar1 == '\n') {
      FUN_1000_f3d6(param_1,param_2,(int)pcVar5 - (int)param_2);
      FUN_1000_f3d6(param_1,0x8f39,1);
      param_2 = pcVar5;
    }
  }
  if (pcVar4 != param_2) {
    FUN_1000_f3d6(param_1,param_2,(int)pcVar4 - (int)param_2);
  }
  return param_3;
}

