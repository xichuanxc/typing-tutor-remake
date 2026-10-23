/* ev_39631a153c859ce8e5c4974d1d83dcedb0fcf6a57f8d7cf72d7c91258cf0b39c */

ulong __cdecl16near FUN_1000_f0a7(void)

{
  ulong uVar1;
  bool bVar2;
  uint in_AX;
  uint in_CX;
  int iVar3;
  uint in_DX;
  int in_BX;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if (in_BX == 0) {
    if (in_CX <= in_DX) {
      return CONCAT22(in_DX / in_CX,
                      (int)(((ulong)in_DX % (ulong)in_CX << 0x10 | (ulong)in_AX) / (ulong)in_CX));
    }
    return CONCAT22(in_DX,in_AX) / (ulong)in_CX & 0xffff;
  }
  iVar4 = 0;
  iVar5 = 0;
  iVar3 = 0x20;
  do {
    uVar1 = (ulong)CONCAT12((int)in_AX < 0,in_DX) << 1;
    in_DX = (uint)uVar1 | (uint)((int)in_AX < 0);
    bVar2 = (uVar1 & 0x10000) != 0;
    uVar1 = (ulong)CONCAT12(bVar2,iVar5) << 1;
    uVar6 = (uint)uVar1 | (uint)bVar2;
    iVar5 = uVar6 - in_CX;
    for (iVar4 = ((iVar4 << 1 | (uint)((uVar1 & 0x10000) != 0)) - in_BX) - (uint)(uVar6 < in_CX);
        in_AX = in_AX * 2, iVar4 < 0;
        iVar4 = (iVar4 << 1 | (uint)((uVar1 & 0x10000) != 0)) + in_BX + (uint)CARRY2(uVar6,in_CX)) {
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) goto LAB_1000_f0ff;
      uVar1 = (ulong)CONCAT12((int)in_AX < 0,in_DX) << 1;
      in_DX = (uint)uVar1 | (uint)((int)in_AX < 0);
      bVar2 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar2,iVar5) << 1;
      uVar6 = (uint)uVar1 | (uint)bVar2;
      iVar5 = uVar6 + in_CX;
    }
    in_AX = in_AX + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
LAB_1000_f0ff:
  return CONCAT22(in_DX,in_AX);
}

