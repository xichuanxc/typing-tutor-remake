/* ev_ce97b7020ac4e95e27044da24460b86a51cd970f1db8db9187022b193e6cc8e2 */

void __cdecl16near FUN_1000_2952(void)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(uint *)0x9d2c = (uint)(*(char *)0x90b5 == '\x02');
  *(undefined2 *)0x9d4c = 2;
  FUN_1000_2692(0x10af,0x101e);
  *(undefined1 *)0x9d4e = 1;
  uVar1 = (uint)*(byte *)0x90b2;
  if ((uVar1 != 0) && (*(char *)0x90af = *(char *)0x90af + -1, (*(byte *)(uVar1 + 0x8e7d) & 3) != 0)
     ) {
    iVar2 = FUN_1000_722b(uVar1);
    *(int *)0x9d36 = *(int *)0x9d36 - (uint)*(byte *)(iVar2 + -0x6f45);
    *(char *)0x90ae = *(char *)0x90ae + -1;
  }
  FUN_1000_3a6d(0,6,0x48,0);
  if (*(char *)0x9d38 != '\0') {
    FUN_1000_51c5();
    uVar3 = FUN_1000_e74e(0xcbc,0x10a3,0x10af,0x843);
    uVar3 = FUN_1000_e717(uVar3);
    FUN_1000_2692(uVar3);
    FUN_1000_8c42(*(char *)0x90b5 == '\x02',0x1720);
    FUN_1000_2565();
  }
  if ((uVar1 != 0) &&
     (*(char *)0x90af = *(char *)0x90af + '\x01', (*(byte *)(uVar1 + 0x8e7d) & 3) != 0)) {
    iVar2 = FUN_1000_722b(uVar1);
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar2 + -0x6f45);
    *(char *)0x90ae = *(char *)0x90ae + '\x01';
  }
  return;
}

