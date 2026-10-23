/* ev_9b27ef0ea1068e9561e8c1b9ec286a8b2cce6dc889bb4ef9f6a44e5b0f335a91 */

void __cdecl16near FUN_1000_6f1b(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar3 = FUN_1000_72ff(0x20ff);
  *(char *)(unaff_BP + -1) = cVar3;
  if (cVar3 == '\0') {
    iVar4 = FUN_1000_bd74(3);
    if (iVar4 != 0) {
      FUN_1000_737b(unaff_BP + 4,5);
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x2c;
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x20;
    }
  }
  if (*(char *)(unaff_BP + -1) == '\0') {
    FUN_1000_737b(unaff_BP + 4,6);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
  }
  else {
    FUN_1000_745c(unaff_BP + 4);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = *(undefined1 *)(unaff_BP + -1);
  }
  cVar3 = FUN_1000_72ff(0x2102);
  *(char *)(unaff_BP + -2) = cVar3;
  if (cVar3 == '\0') {
    FUN_1000_73cc(unaff_BP + 4);
  }
  else {
    pcVar2 = (char *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *pcVar2 = cVar3;
    FUN_1000_73ad(unaff_BP + 4);
  }
  if (*(char *)(unaff_BP + -1) == '\0') {
    iVar4 = FUN_1000_bd74(3);
    if (iVar4 != 0) {
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x2c;
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x20;
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x31;
      FUN_1000_73ad(unaff_BP + 4);
      FUN_1000_73ad(unaff_BP + 4);
      FUN_1000_73ad(unaff_BP + 4);
    }
  }
  else {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = *(undefined1 *)(unaff_BP + -1);
    FUN_1000_73ad(unaff_BP + 4);
    FUN_1000_73ad(unaff_BP + 4);
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0;
  return;
}

