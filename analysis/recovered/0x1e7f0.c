/* ev_3acd6eaf4d5bf1fff3c6a704cf3af0f413e71c2a6e2bef2cd6f6f4a277f4069a */

int __cdecl16near FUN_1000_e7f0(undefined2 param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e913(param_3);
  pcVar2 = (char *)0x8d34;
  while( true ) {
    if (*pcVar2 == '\0') {
      *(undefined2 *)0x8f00 = 1;
      return 0;
    }
    iVar1 = FUN_1000_f105(pcVar2,param_2);
    if (iVar1 == 0) break;
    pcVar2 = pcVar2 + 5;
  }
  iVar1 = FUN_1000_efbb(param_1,*(undefined2 *)(pcVar2 + 3));
  if (iVar1 == -1) {
    return 0;
  }
  *(undefined1 *)(param_3 + 7) = (char)iVar1;
  *(undefined1 *)(param_3 + 6) = 1;
  return param_3;
}

