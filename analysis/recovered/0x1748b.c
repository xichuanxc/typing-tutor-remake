/* ev_9fa1d6d0f5367b7ad83c9b61e1c4b2d7559205f8d0a3fc5f546b8f70ee932161 */

void __cdecl16near FUN_1000_748b(void)

{
  int *piVar1;
  undefined1 *puVar2;
  char cVar3;
  undefined1 uVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar3 = FUN_1000_7251(0x7aee);
  uVar4 = FUN_1000_e793((int)cVar3);
  puVar2 = (undefined1 *)*(int *)*(undefined2 *)(unaff_BP + 4);
  piVar1 = (int *)*(undefined2 *)(unaff_BP + 4);
  *piVar1 = *piVar1 + 1;
  *puVar2 = uVar4;
  return;
}

