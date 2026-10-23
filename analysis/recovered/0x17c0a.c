/* ev_d4d3dbd713e670a681a9c2587e6228d216468d90cf32912b2766c31dfff785d9 */

undefined2 __cdecl16near FUN_1000_7c0a(void)

{
  undefined2 unaff_DS;
  bool bVar1;
  
  FUN_1000_7d49();
  bVar1 = false;
  if (*(int *)0x8f46 == 0) {
    bVar1 = *(int *)0x8f44 == 0;
  }
  if (!bVar1) {
    FUN_1000_81ff(0x1c,*(undefined2 *)0x8f44,*(undefined2 *)0x8f46);
    *(undefined2 *)0x8f46 = 0;
    *(undefined2 *)0x8f44 = 0;
  }
  bVar1 = false;
  if (*(int *)0x8f4a == 0) {
    bVar1 = *(int *)0x8f48 == 0;
  }
  if (!bVar1) {
    FUN_1000_81ff(8,*(undefined2 *)0x8f48,*(undefined2 *)0x8f4a);
    *(undefined2 *)0x8f4a = 0;
    *(undefined2 *)0x8f48 = 0;
  }
  FUN_1000_81ff(0x60,0,0);
  FUN_1000_81ff(0x61,0,0);
  *(undefined2 *)0x8f50 = 0;
  return 0;
}

