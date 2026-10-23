/* ev_672cd776b9d1e07ebb1716a46a94fc4375a25ea5de0b28a9ed649d1155f64747 */

char * __cdecl16near FUN_1000_f139(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  iVar2 = 0x7fff;
  pcVar3 = param_1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar1 = pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (*pcVar1 != '\0');
  return pcVar3 + (-1 - (int)param_1);
}

