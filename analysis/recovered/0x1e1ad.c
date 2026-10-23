/* ev_0edc08b4a8b3830a85949bda1dc9fa526751c41d95a58f69c00d727ed079a5a0 */

int __cdecl16near FUN_1000_e1ad(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  if (*(byte *)0x90b0 < 0x4a) {
    iVar3 = 0;
    for (uVar2 = 0x40; uVar2 <= *(byte *)0x90b0; uVar2 = uVar2 + 1) {
      iVar1 = FUN_1000_544e(uVar2);
      if (iVar1 == 0) {
        iVar3 = iVar3 + 1;
      }
    }
    if (iVar3 < 3) {
      *(char *)0x90b0 = *(char *)0x90b0 + '\x01';
      return (int)*(char *)(*(byte *)0x90b0 + 0x7ad4);
    }
  }
  return 0x20;
}

