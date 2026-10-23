/* ev_e4e2119d12d0fbda88c0feee88f8cb76ac4a2839cc2048589ca98e30bee9cc28 */

void __cdecl16near FUN_1000_4232(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x1043,0x101e);
  FUN_1000_4802(*(undefined1 *)(unaff_BP + 4),0x18,1);
  FUN_1000_ae2b(*(byte *)(unaff_BP + 4) + 6,*(byte *)(unaff_BP + 6) - 1,*(byte *)(unaff_BP + 4) + 8,
                0x50 - (uint)*(byte *)(unaff_BP + 6),1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 7,*(byte *)(unaff_BP + 6) + 1);
  FUN_1000_f6a4(0x1b91);
  if (*(char *)0x9d52 == '\0') {
    FUN_1000_ae2b(*(byte *)(unaff_BP + 4) + 10,4,*(byte *)(unaff_BP + 4) + 0xd,0x4b,1,0xcd,0xb3,0xd5
                  ,0xb8,0xd4,0xbe);
    FUN_1000_af51(0x1bab,0xffff,*(byte *)(unaff_BP + 4) + 10,4,*(byte *)(unaff_BP + 4) + 0xd,0x4b,0,
                  0);
  }
  else {
    FUN_1000_4344(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6));
  }
  return;
}

