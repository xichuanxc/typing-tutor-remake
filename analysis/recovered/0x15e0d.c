/* ev_45d0a092db978d20fb7e190bd3ef9eca089a3a64df621ab9b993bbdd27f73591 */

void __cdecl16near FUN_1000_5e0d(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_b12a(0x9072,8,0x1a,0xb,0x36);
  FUN_1000_f7da(10,0x1c);
  FUN_1000_f6a4(0x2046);
  FUN_1000_0128();
  while (*(int *)(unaff_BP + 4) < 8) {
    FUN_1000_e247(*(undefined2 *)0x9070,(long)(*(int *)(unaff_BP + 4) + 1) * 0x7cc,0);
    FUN_1000_e1f4(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    FUN_1000_e247(*(undefined2 *)0x9070,(long)*(int *)(unaff_BP + 4) * 0x7cc,0);
    FUN_1000_e852(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_e74e(0x9072,0x1314);
  return;
}

