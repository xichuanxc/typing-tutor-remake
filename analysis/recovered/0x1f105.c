/* ev_c022696e21b3fbb362d48f7646e9f45ab212d531b76b9184acf083b6c9508340 */

undefined2 __cdecl16near FUN_1000_f105(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  iVar3 = 0x7fff;
  do {
    pbVar1 = param_1;
    param_1 = param_1 + 1;
    bVar2 = *pbVar1;
    pbVar1 = param_2;
    param_2 = param_2 + 1;
    if (bVar2 != *pbVar1) {
      if (*pbVar1 <= bVar2) {
        return 1;
      }
      return 0xffff;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0 && bVar2 != 0);
  return 0;
}

