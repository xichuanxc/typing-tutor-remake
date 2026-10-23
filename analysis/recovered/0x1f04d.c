/* ev_d6050d71c32be0c4351737cd78451b788dff0f92067bdbcbfdfbb1b3ad542267 */

int __cdecl16near FUN_1000_f04d(void)

{
  int iVar1;
  int in_DX;
  int in_BX;
  bool bVar2;
  
  bVar2 = in_DX < 0;
  if (in_BX < 0) {
    bVar2 = !bVar2;
  }
  iVar1 = FUN_1000_f0a7();
  if (bVar2) {
    iVar1 = -iVar1;
  }
  return iVar1;
}

