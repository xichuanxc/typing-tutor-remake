/* ev_61aae4557fe4fd75f1a175ac74d7fec186314915282641af8585b3da1ce21fd1 */

int __cdecl16near FUN_1000_ccdd(void)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar2 = *(byte *)0x90b6 / 5 - 1;
  iVar1 = FUN_1000_b21d(4,3,0x89ed,0,iVar2,0x8a3b);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
    return -1;
  }
  if (iVar1 != iVar2) {
    iVar1 = (iVar1 + 1) * 5;
    *(undefined1 *)0x90b6 = (char)iVar1;
    *(undefined1 *)0x906e = 1;
  }
  return iVar1;
}

