/* ev_9ab7237111411dadb57c58b82371b8d6761c7048a191c5543378cb391424cc7c */

char * __cdecl16near FUN_1000_e76b(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  pcVar3 = param_1;
  while( true ) {
    if (param_3 == 0) {
      return param_1;
    }
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    if (*pcVar1 == '\0') break;
    pcVar2 = pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar2 = *pcVar1;
    param_3 = param_3 + -1;
  }
  for (; param_3 != 0; param_3 = param_3 + -1) {
    pcVar1 = pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar1 = '\0';
  }
  return param_1;
}

