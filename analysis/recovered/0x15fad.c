/* ev_b0c7cb144fa64bd18464cf695f16bbb6769e499a88aaa08f3a0680d7485c14a7 */

uint __cdecl16near FUN_1000_5fad(void)

{
  int iVar1;
  byte bVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d50 == '\x02') {
    *(undefined1 *)0x9d50 = 1;
    return 0x20;
  }
  iVar1 = *(int *)0x9d8e;
  *(int *)0x9d8e = *(int *)0x9d8e + 1;
  *(int *)(unaff_BP + -2) = iVar1 % 7 + 1;
  iVar1 = FUN_1000_e3ce(*(undefined2 *)0x9070);
  bVar2 = (byte)*(undefined2 *)(unaff_BP + -2);
  return (iVar1 << (8 - bVar2 & 0x1f) | iVar1 >> (bVar2 & 0x1f)) & 0xff;
}

