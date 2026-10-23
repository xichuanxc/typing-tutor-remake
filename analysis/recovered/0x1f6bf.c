/* ev_f03a3d0a4804afad64c05d6ba2be4df1bc4dd06769c4df50697d75ee598aeb4e */

int __cdecl16near FUN_1000_f6bf(int param_1,uint param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined2 *)0x8f42;
  *(uint *)0x8f42 = param_1 << 4 | param_2;
  if (param_4 == 0) {
    *(uint *)0x8f42 = *(uint *)0x8f42 & 0x7f;
  }
  else {
    *(uint *)0x8f42 = *(uint *)0x8f42 | 0x80;
  }
  if (param_3 == 0) {
    *(uint *)0x8f42 = *(uint *)0x8f42 & 0xf7;
  }
  else {
    *(uint *)0x8f42 = *(uint *)0x8f42 | 8;
  }
  *(uint *)0x8f42 = *(uint *)0x8f42 & 0xff;
  return (int)(char)uVar1;
}

