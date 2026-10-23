/* ev_be2c321daca8f71e491e03d87fe2b5773ec7ce86da51de4adca24034f923d952 */

void __cdecl16near FUN_1000_71ce(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  char cVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d8a == '\0') {
    cVar3 = FUN_1000_7251(0x2113);
    *(char *)0x9d8a = cVar3;
    if (cVar3 != '\0') {
      pcVar2 = (char *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *pcVar2 = cVar3;
      *(undefined1 *)0x9d88 = 1;
      if (cVar3 == '\"') {
        *(undefined1 *)0x9d8a = 0x22;
      }
      else if (cVar3 == '\'') {
        *(undefined1 *)0x9d8a = 0x27;
      }
    }
  }
  else {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = *(undefined1 *)0x9d8a;
    *(undefined1 *)0x9d8a = 0;
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

