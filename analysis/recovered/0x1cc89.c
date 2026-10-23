/* ev_2f955fcf6180890c508a4f070e9eeafdc81608cb800d95ab214a13877c86bbc2 */

uint __cdecl16near FUN_1000_cc89(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_b21d(7,8,0x7fb,0,*(undefined1 *)0x90b7,0xdd1);
  if (uVar1 == 0xffff) {
    FUN_1000_e74e(0x17a0,0x1004);
    return 0xffff;
  }
  uVar2 = (uint)*(byte *)0x90b7;
  if (*(byte *)0x90b7 != uVar1) {
    *(undefined1 *)0x90b7 = (char)uVar1;
    *(undefined1 *)0x906e = 1;
    uVar2 = uVar1;
  }
  return uVar2;
}

