/* ev_92abfbe1a4a0d1ce18f6876d451e67329d458a2c85e7950cdbfc527370f471a9 */

char * __cdecl16near FUN_1000_e717(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined2 unaff_DS;
  
  iVar3 = 0x7fff;
  pcVar4 = param_1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar2 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar2 != '\0');
  pcVar4 = pcVar4 + -1;
  iVar3 = 0x7fff;
  do {
    pcVar2 = param_2;
    param_2 = param_2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar2 = cVar1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0 && cVar1 != '\0');
  if (cVar1 != '\0') {
    *pcVar4 = '\0';
  }
  return param_1;
}

