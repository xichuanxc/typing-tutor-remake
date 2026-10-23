/* ev_739d7379547824108513649af69e86c099e05db550de91b7ef2fd348fd48bdc8 */

void __cdecl16near FUN_1000_4757(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_bdcb(*(undefined1 *)0x90b2);
  *(char *)(unaff_BP + -1) = cVar1;
  iVar2 = FUN_1000_722b((int)cVar1);
  FUN_1000_c98e(0xc,0xd,(int)*(char *)(unaff_BP + -1),1);
  FUN_1000_c98e(0xc,0xd,*(undefined1 *)0x90b2,1);
  FUN_1000_f7c2(1);
  FUN_1000_f7da(10,8);
  iVar3 = iVar2;
  if (3 < iVar2) {
    iVar3 = 7 - iVar2;
  }
  FUN_1000_f6a4(0x1a50,(uint)(3 < iVar2) * 6 + 0x1a8f,iVar3 * 7 + 0x1a9b,
                (int)*(char *)(unaff_BP + -1),*(undefined1 *)0x90b2);
  FUN_1000_f7c2(0);
  return;
}

