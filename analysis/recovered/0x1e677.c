/* ev_e8fa5bf8b11ab4a11dc9d49d7a5a593506a81e66a23b269e5afe0d1b1534d4fe */

char * __cdecl16near FUN_1000_e677(char *param_1,char param_2)

{
  char *pcVar1;
  undefined2 unaff_DS;
  
  do {
    pcVar1 = param_1;
    if (*pcVar1 == '\0') {
      return (char *)0x0;
    }
    param_1 = pcVar1 + 1;
  } while (*pcVar1 != param_2);
  return pcVar1;
}

