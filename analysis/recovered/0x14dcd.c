/* ev_0340147478a186543e443cb3be69f86b6b8a9d9bd83e37c9c182da741ae2628f */

void __cdecl16near FUN_1000_4dcd(char param_1,char param_2,int param_3)

{
  undefined2 unaff_DS;
  
  if (param_1 == param_2) {
    if (*(char *)0x9d51 == '\0') {
      FUN_1000_4f6c((int)param_2,1);
    }
  }
  else {
    *(undefined1 *)((*(int *)0x9d70 - param_3) + 0x8ff) = 1;
    FUN_1000_b1f3(0,2,4);
    FUN_1000_4e79(*(int *)0x9d6c + -2,*(int *)0x9d6e + -1,0x19);
    FUN_1000_b1f3(0,2,7);
    FUN_1000_7e47(5);
    if (*(char *)0x9d4f == '\0') {
      FUN_1000_07c9(0x40,0);
    }
    else {
      FUN_1000_07c9(0x20,1);
    }
    if (*(char *)0x9d51 == '\0') {
      FUN_1000_4f6c((int)param_2,0);
    }
  }
  return;
}

