/* ev_8d75657e22a556edfe1de6d153ebb0eebd08a890affd218a40d5b37b9de58173 */

void __cdecl16near FUN_1000_745c(void)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar3 = FUN_1000_72ff(0x213f);
  if (iVar3 == 0) {
    FUN_1000_73cc(*(undefined2 *)(unaff_BP + 4));
  }
  else {
    puVar2 = (undefined1 *)*(int *)*(undefined2 *)(unaff_BP + 4);
    piVar1 = (int *)*(undefined2 *)(unaff_BP + 4);
    *piVar1 = *piVar1 + 1;
    *puVar2 = 0x31;
    FUN_1000_7429(*(undefined2 *)(unaff_BP + 4));
  }
  return;
}

