/* ev_8a441e65b3da377bd147ab12af6b25794104a1bc4125381c7885ae9c46d21958 */

uint __cdecl16near FUN_1000_e38e(int param_1)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  do {
    uVar1 = FUN_1000_e3ce(param_1);
    if (uVar1 == 0xffff) {
      return 0xffff;
    }
    uVar1 = uVar1 & 0x7f;
  } while ((uVar1 == 0) || (uVar1 == 0xd));
  if (uVar1 == 0x1a) {
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 8;
    uVar1 = 0xffff;
  }
  return uVar1;
}

