/* ev_5ebf7f971f604be6a4a07799e0cc9125e42cc02cde47f2e2a10d99cfd48d1ab4 */

void __cdecl16near FUN_1000_68e3(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d89 == '\0') {
    cVar3 = FUN_1000_7251(0x20eb);
    *(char *)0x9d89 = cVar3;
    if (cVar3 != '\0') {
      pcVar2 = (char *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *pcVar2 = cVar3;
      *(undefined1 *)0x9d88 = 1;
      if (cVar3 == '(') {
        iVar5 = FUN_1000_72dd(0x29);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x29;
        }
        *(undefined1 *)0x9d89 = uVar4;
      }
      else if (cVar3 == '<') {
        iVar5 = FUN_1000_72dd(0x3e);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x3e;
        }
        *(undefined1 *)0x9d89 = uVar4;
      }
      else if (cVar3 == '[') {
        iVar5 = FUN_1000_72dd(0x5d);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x5d;
        }
        *(undefined1 *)0x9d89 = uVar4;
      }
      else if (cVar3 == '{') {
        iVar5 = FUN_1000_72dd(0x7d);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x7d;
        }
        *(undefined1 *)0x9d89 = uVar4;
      }
    }
  }
  else {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = *(undefined1 *)0x9d89;
    *(undefined1 *)0x9d89 = 0;
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

