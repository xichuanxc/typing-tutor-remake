/* ev_e56422d647f641d93ca96172adfa1150e5455c9ccd74a485191bb82fa99aba07 */

int __cdecl16near FUN_1000_e469(char *param_1)

{
  bool bVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  for (; (*param_1 == ' ' || (*param_1 == '\t')); param_1 = param_1 + 1) {
  }
  bVar1 = false;
  if (*param_1 == '-') {
    bVar1 = true;
    param_1 = param_1 + 1;
  }
  else if (*param_1 == '+') {
    param_1 = param_1 + 1;
  }
  iVar2 = 0;
  while ((*(byte *)(*param_1 + -0x7183) & 4) != 0) {
    iVar2 = (int)*param_1 + iVar2 * 10 + -0x30;
    param_1 = param_1 + 1;
  }
  if (bVar1) {
    iVar2 = -iVar2;
  }
  return iVar2;
}

