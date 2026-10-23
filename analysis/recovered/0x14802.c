/* ev_a796fc8693ab39d2342e6fbb6d80277b4a5d4435c21aa45e4521a76e964ee112 */

void __cdecl16near FUN_1000_4802(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_b1f3(0,2,7);
  if (*(char *)0x906a == '\0') {
    FUN_1000_ae2b(*(byte *)(unaff_BP + 4) - 2,*(byte *)(unaff_BP + 6) - 2,
                  (uint)*(byte *)(unaff_BP + 8) * 3 + (uint)*(byte *)(unaff_BP + 4),
                  0x51 - (uint)*(byte *)(unaff_BP + 6),*(char *)(unaff_BP + 6) != '\x03',0xcd,0xb3,
                  0xd5,0xb8,0xd4,0xbe);
  }
  else {
    FUN_1000_ae2b(*(byte *)(unaff_BP + 4) - 2,*(byte *)(unaff_BP + 6) - 2,
                  (uint)*(byte *)(unaff_BP + 8) * 3 + (uint)*(byte *)(unaff_BP + 4),
                  0x51 - (uint)*(byte *)(unaff_BP + 6),1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  }
  return;
}

