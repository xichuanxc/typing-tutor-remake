/* ev_b005eb4dc7fa21fc81f4e1816f2ed590cd1edbe1ac1e6e12f814db532b3f27ea */

char * __cdecl16near FUN_1000_e74e(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  pcVar3 = param_1;
  do {
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    cVar2 = *pcVar1;
    pcVar1 = pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar1 = cVar2;
  } while (cVar2 != '\0');
  return param_1;
}

