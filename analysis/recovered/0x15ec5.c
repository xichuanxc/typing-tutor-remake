/* ev_10aff5f97979e7ef1ee8c102d57d43aeb719f075f8973366d1662dfbee378c68 */

int __cdecl16near FUN_1000_5ec5(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_0128();
  iVar1 = FUN_1000_0f47();
  if ((iVar1 == 0) && (*(int *)0x9d4e == 0)) {
    FUN_1000_b194(0x205a,0x27,4);
    FUN_1000_e913(*(undefined2 *)0x9070);
    FUN_1000_2612(0x183,0);
    FUN_1000_f831();
    return -1;
  }
  if (*(int *)0x9d4e == 0) {
    *(undefined2 *)(unaff_BP + -2) = 1;
  }
  else {
    FUN_1000_e74e(*(undefined2 *)0x6d5,0x1314);
    *(undefined2 *)(unaff_BP + -2) = 0;
    iVar1 = iVar1 + 1;
  }
  iVar1 = FUN_1000_b21d(iVar1,0x1a,*(int *)(unaff_BP + -2) * 2 + 0x6d5,0,0,0x962);
  if (iVar1 == -1) {
    FUN_1000_e913(*(undefined2 *)0x9070);
    return -1;
  }
  if (*(int *)0x9d4e == 0) {
    FUN_1000_e247(*(undefined2 *)0x9070,iVar1 * 0x7cc,0,0);
    FUN_1000_e1f4(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    FUN_1000_e74e(*(undefined2 *)0x6d5,0x9072);
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  return iVar1;
}

