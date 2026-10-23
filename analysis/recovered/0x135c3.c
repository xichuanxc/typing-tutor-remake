/* ev_99e51f51af172380670b414410b3f14c40dd56d32fc20431aa21ef03c64256f8 */

uint __cdecl16near FUN_1000_35c3(void)

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x17a0 == '\0') {
    uVar1 = FUN_1000_f831();
  }
  else {
    uVar1 = (uint)*(byte *)0x17a0;
    for (iVar2 = 0; *(char *)(iVar2 + 0x17a0) != '\0'; iVar2 = iVar2 + 1) {
      *(undefined1 *)(iVar2 + 0x17a0) = *(undefined1 *)(iVar2 + 0x17a1);
    }
  }
  return uVar1;
}

