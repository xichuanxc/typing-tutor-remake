/* ev_05f8ccf26d3f120899296667f0a5d844c3ab4fd13d6c66f3fed4a7f5f9cbe355 */

undefined2 __cdecl16near FUN_1000_cb56(void)

{
  uint uVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_7e47(5);
  uVar1 = FUN_1000_b21d(2,9,0x89e0,0,*(char *)0x90ad == '\0',0x8a01);
  if (uVar1 == 0xffff) {
    FUN_1000_e74e(0x17a0,0x1004);
    return 0xffff;
  }
  if (*(byte *)0x90ad == uVar1) {
    *(bool *)0x90ad = uVar1 == 0;
    *(undefined1 *)0x906e = 1;
    if (*(char *)0x90ad == '\0') {
      FUN_1000_7c0a();
    }
    else {
      FUN_1000_7b92();
    }
  }
  uVar2 = FUN_1000_7e47(5);
  return uVar2;
}

