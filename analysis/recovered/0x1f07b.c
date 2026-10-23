/* ev_95e17a81bd0c40281cf1cc7cd104a00cce0e773deac97cf81496f6324def0abf */

undefined4 __cdecl16near FUN_1000_f07b(void)

{
  int in_CX;
  int in_DX;
  int in_BX;
  bool bVar1;
  
  if (in_BX < 0) {
    bVar1 = in_CX != 0;
    in_CX = -in_CX;
    in_BX = -(uint)bVar1 - in_BX;
  }
  FUN_1000_f0a7();
  if (in_DX < 0) {
    bVar1 = in_CX != 0;
    in_CX = -in_CX;
    in_BX = -(uint)bVar1 - in_BX;
  }
  return CONCAT22(in_BX,in_CX);
}

