/* ev_aef19ddf1b68e693f7ce20b01337f90c137220bcde16fe40296248fd77259b9b */

int __cdecl16near FUN_1000_0e3f(void)

{
  int iVar1;
  int unaff_BP;
  uint uVar2;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x1c9,0x843);
  FUN_1000_0128();
  iVar1 = FUN_1000_0f47();
  *(int *)(unaff_BP + -2) = iVar1;
  if (7 < iVar1) {
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + -1;
  }
  iVar3 = 0;
  if (0 < *(int *)(unaff_BP + -2)) {
    iVar3 = FUN_1000_b21d(*(int *)(unaff_BP + -2) + 1,0x1a,(uint)(7 < iVar1) * 2 + 0x6d5,0,0,0x962);
  }
  if (iVar3 == -1) {
    return -1;
  }
  if (7 < iVar1 != 0) {
    iVar3 = iVar3 + 1;
  }
  if (iVar3 == 0) {
    iVar3 = FUN_1000_0ddc(*(undefined2 *)(unaff_BP + -2));
    if (iVar3 == -1) {
      return -1;
    }
  }
  else {
    iVar3 = iVar3 + -1;
    FUN_1000_e247(*(undefined2 *)0x9070,iVar3 * 0x7cc,0,0);
    FUN_1000_e1f4(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    *(undefined2 *)0x9d34 = 0;
    if ((*(char *)0x90a8 != '\0') && (iVar1 = FUN_1000_5b4d(0x90a8), iVar1 == -1)) {
      return -1;
    }
  }
  if (*(char *)0x90ad == '\0') {
    FUN_1000_7c0a();
  }
  *(undefined2 *)0x9d36 = 0;
  for (uVar2 = 0; uVar2 < *(byte *)0x90ae + 4; uVar2 = uVar2 + 1) {
    iVar1 = FUN_1000_722b((int)*(char *)(uVar2 + 0x7aee));
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar1 + -0x6f45);
  }
  return iVar3;
}

