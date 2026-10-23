/* ev_da65846c754ca8751dfa9c49ab2eadfab79f8dbc206b597899eb48c49f9dc4e3 */

uint __cdecl16near FUN_1000_f858(void)

{
  uint in_AX;
  byte bVar1;
  
  bVar1 = (byte)(in_AX >> 8);
  if ((char)in_AX != '\0') {
    return in_AX & 0xff;
  }
  if (bVar1 != 0) {
    if (bVar1 == 3) {
      return 0;
    }
    return bVar1 | 0x80;
  }
  return 0xfffe;
}

