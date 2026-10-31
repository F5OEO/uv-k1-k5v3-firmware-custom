// ==== 080000c8  thunk_FUN_08001328  (4 bytes, 1 xrefs)

void thunk_FUN_08001328(void)

{
  (*DAT_080000cc)();
  return;
}



// ==== 080000d4  FUN_080000d4  (8 bytes, 0 xrefs)

void FUN_080000d4(void)

{
  (*DAT_080000e8)();
                    /* WARNING: Could not recover jumptable at 0x080000da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_080000ec)();
  return;
}



// ==== 080000dc  FUN_080000dc  (2 bytes, 1 xrefs)

void FUN_080000dc(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080000de  FUN_080000de  (2 bytes, 1 xrefs)

void FUN_080000de(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080000e0  FUN_080000e0  (2 bytes, 1 xrefs)

void FUN_080000e0(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080000e2  FUN_080000e2  (2 bytes, 1 xrefs)

void FUN_080000e2(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080000e4  FUN_080000e4  (2 bytes, 1 xrefs)

void FUN_080000e4(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080000e6  FUN_080000e6  (2 bytes, 1 xrefs)

void FUN_080000e6(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080000f0  FUN_080000f0  (44 bytes, 7 xrefs)

int FUN_080000f0(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar2 = 0x20;
  while (uVar3 = uVar2 - 1, 0 < (int)uVar2) {
    uVar2 = uVar3;
    if (param_2 <= param_1 >> (uVar3 & 0xff)) {
      param_1 = param_1 - (param_2 << (uVar3 & 0xff));
      iVar1 = iVar1 + (1 << (uVar3 & 0xff));
    }
  }
  return iVar1;
}



// ==== 0800011c  FUN_0800011c  (36 bytes, 14 xrefs)

void FUN_0800011c(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  while (bVar2 = param_3 != 0, param_3 = param_3 - 1, bVar2) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}



// ==== 08000140  FUN_08000140  (14 bytes, 2 xrefs)

void FUN_08000140(undefined1 *param_1,int param_2,undefined1 param_3)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}



// ==== 0800014e  FUN_0800014e  (4 bytes, 4 xrefs)

void FUN_0800014e(undefined4 param_1,undefined4 param_2)

{
  FUN_08000140(param_1,param_2,0);
  return;
}



// ==== 08000152  FUN_08000152  (18 bytes, 0 xrefs)

undefined4 FUN_08000152(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_08000140(param_1,param_3,param_2);
  return param_1;
}



// ==== 08000164  FUN_08000164  (26 bytes, 1 xrefs)

void FUN_08000164(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; (uVar1 < param_3 && (*(char *)(param_1 + uVar1) == *(char *)(param_2 + uVar1)));
      uVar1 = uVar1 + 1) {
  }
  return;
}



// ==== 0800017e  FUN_0800017e  (20 bytes, 2 xrefs)

uint FUN_0800017e(int param_1,undefined4 param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 3;
  pbVar1 = (byte *)(param_1 + 4);
  do {
    pbVar1 = pbVar1 + -1;
    param_3 = param_3 << 8 | (uint)*pbVar1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return param_3;
}



// ==== 08000192  FUN_08000192  (18 bytes, 1 xrefs)

uint FUN_08000192(uint param_1,undefined1 *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 3;
  uVar1 = param_1;
  do {
    *param_2 = (char)uVar1;
    uVar1 = uVar1 >> 8;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return param_1;
}



// ==== 080001a4  FUN_080001a4  (36 bytes, 1 xrefs)

undefined4 FUN_080001a4(void)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *extraout_r1;
  byte *pbVar4;
  int extraout_r2;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  for (puVar7 = &DAT_080020a4; puVar7 < &DAT_080020c4; puVar7 = puVar7 + 4) {
    (*(code *)puVar7[3])(*puVar7,puVar7[1],puVar7[2]);
  }
  thunk_FUN_08001328();
  pbVar3 = (byte *)0x0;
  pbVar4 = extraout_r1;
  do {
    bVar1 = *pbVar3;
    uVar6 = bVar1 & 0xf;
    pbVar2 = pbVar3 + 1;
    if ((bVar1 & 0xf) == 0) {
      uVar6 = (uint)pbVar3[1];
      pbVar2 = pbVar3 + 2;
    }
    pbVar3 = pbVar2;
    uVar5 = (uint)(bVar1 >> 4);
    if (uVar5 == 0) {
      uVar5 = (uint)*pbVar3;
      pbVar3 = pbVar3 + 1;
    }
    while (uVar6 = uVar6 - 1, uVar6 != 0) {
      *pbVar4 = *pbVar3;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    }
    while (uVar5 = uVar5 - 1, uVar5 != 0) {
      *pbVar4 = 0;
      pbVar4 = pbVar4 + 1;
    }
  } while (pbVar4 < extraout_r1 + extraout_r2);
  return 0;
}



// ==== 080001c8  FUN_080001c8  (58 bytes, 1 xrefs)

undefined4 FUN_080001c8(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = param_2 + param_3;
  do {
    bVar1 = *param_1;
    uVar4 = bVar1 & 0xf;
    pbVar2 = param_1 + 1;
    if ((bVar1 & 0xf) == 0) {
      uVar4 = (uint)param_1[1];
      pbVar2 = param_1 + 2;
    }
    param_1 = pbVar2;
    uVar3 = (uint)(bVar1 >> 4);
    if (uVar3 == 0) {
      uVar3 = (uint)*param_1;
      param_1 = param_1 + 1;
    }
    while (uVar4 = uVar4 - 1, uVar4 != 0) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    while (uVar3 = uVar3 - 1, uVar3 != 0) {
      *param_2 = 0;
      param_2 = param_2 + 1;
    }
  } while (param_2 < pbVar5);
  return 0;
}



// ==== 08000204  FUN_08000204  (46 bytes, 2 xrefs)

void FUN_08000204(int param_1)

{
  ushort *puVar1;
  int iVar2;
  
  if (param_1 == 1) {
    puVar1 = DAT_08000238;
  }
  else {
    puVar1 = DAT_08000234;
  }
  iVar2 = (uint)*puVar1 + DAT_0800023c;
  if (iVar2 == 0) {
    FUN_08000268();
    return;
  }
  if (iVar2 == 3) {
    FUN_080002a0();
    return;
  }
  if (iVar2 == 0x1a) {
    FUN_08000240();
  }
  return;
}



// ==== 08000240  FUN_08000240  (32 bytes, 1 xrefs)

void FUN_08000240(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_08000164(param_2 + 4,DAT_08000260,4);
  if ((iVar1 == 0) || (*(char *)(param_2 + 4) == '*')) {
    *(undefined1 *)(DAT_08000264 + 1) = 1;
  }
  return;
}



// ==== 08000268  FUN_08000268  (48 bytes, 1 xrefs)

void FUN_08000268(undefined4 param_1,int param_2)

{
  int iVar1;
  
  FUN_0800011c(DAT_08000298,param_2 + 4,0x68);
  iVar1 = DAT_0800029c;
  disableIRQinterrupts();
  FUN_0800059c(DAT_0800029c,1);
  FUN_08000618(iVar1,DAT_08000298,iVar1 >> 0x13);
  enableIRQinterrupts();
  FUN_08000388(param_1,0);
  return;
}



// ==== 080002a0  FUN_080002a0  (216 bytes, 1 xrefs)

void FUN_080002a0(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar3 = DAT_0800037c;
  pcVar2 = DAT_08000378;
  if (DAT_08000378[1] == '\x01') {
    if (*(short *)(param_2 + 8) == 0) {
      uVar6 = FUN_0800017e(param_2 + 4);
      *(undefined4 *)(pcVar2 + 8) = uVar6;
      *(undefined2 *)(pcVar2 + 4) = *(undefined2 *)(param_2 + 10);
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      *pcVar2 = '\x02';
      disableIRQinterrupts();
      FUN_0800059c(iVar3,0x1d8);
      enableIRQinterrupts();
    }
    else {
      if (*DAT_08000378 != '\x02') {
        return;
      }
      *(uint *)(PTR_GPIOC_08000380 + 0x14) = *(uint *)(PTR_GPIOC_08000380 + 0x14) ^ 0x2000;
      if (((uint)*(ushort *)(param_2 + 8) != *(ushort *)(pcVar2 + 2) + 1) ||
         (iVar5 = FUN_0800017e(param_2 + 4), iVar5 != *(int *)(pcVar2 + 8))) {
        FUN_080003a4(param_1,0,0,1);
        cVar4 = '\x01';
        goto LAB_08000374;
      }
    }
    FUN_0800011c(DAT_08000384,param_2 + 0x10,0x100);
    disableIRQinterrupts();
    FUN_08000618((uint)*(ushort *)(param_2 + 8) * 0x100 + iVar3,DAT_08000384,0x100);
    enableIRQinterrupts();
    uVar1 = *(undefined2 *)(param_2 + 8);
    *(undefined2 *)(pcVar2 + 2) = uVar1;
    FUN_080003a4(param_1,*(undefined4 *)(pcVar2 + 8),uVar1,0);
    if (*(ushort *)(pcVar2 + 2) + 1 == (uint)*(ushort *)(pcVar2 + 4)) {
      cVar4 = '\x03';
LAB_08000374:
      *pcVar2 = cVar4;
      return;
    }
  }
  else {
    FUN_080003a4(param_1,0,0,1);
  }
  return;
}



// ==== 08000388  FUN_08000388  (24 bytes, 1 xrefs)

void FUN_08000388(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined3 uStack_b;
  
  _local_10 = CONCAT22(4,(short)DAT_080003a0);
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),param_2);
  FUN_080003c4(param_1,&local_10,8);
  return;
}



// ==== 080003a4  FUN_080003a4  (28 bytes, 3 xrefs)

void FUN_080003a4(undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  undefined2 local_10;
  undefined1 local_e;
  undefined1 uStack_d;
  
  _local_18 = CONCAT22(8,(short)DAT_080003c0);
  uStack_d = (undefined1)((uint)param_4 >> 0x18);
  _local_10 = CONCAT12((char)param_4,param_3);
  local_14 = param_2;
  FUN_080003c4(param_1,&local_18,0xc);
  return;
}



// ==== 080003c4  FUN_080003c4  (24 bytes, 3 xrefs)

void FUN_080003c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == 1) {
    FUN_08000af0(param_2,param_3);
    return;
  }
  FUN_08000964();
  return;
}



// ==== 080003dc  FUN_080003dc  (52 bytes, 2 xrefs)

void FUN_080003dc(undefined4 param_1)

{
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined1 auStack_1c [20];
  
  local_30 = 0x518;
  local_2e = 0x20;
  local_2c = *DAT_08000410;
  uStack_28 = DAT_08000410[1];
  uStack_24 = DAT_08000410[2];
  local_20 = DAT_08000410[3];
  FUN_0800011c(auStack_1c,DAT_08000414,0x10,&local_20);
  FUN_080003c4(param_1,&local_30,0x24);
  return;
}



// ==== 08000418  thunk_FUN_08000434  (2 bytes, 6 xrefs)

void thunk_FUN_08000434(int param_1)

{
  for (; param_1 != 0; param_1 = param_1 + -1) {
  }
  return;
}



// ==== 08000434  FUN_08000434  (32 bytes, 1 xrefs)

void FUN_08000434(int param_1)

{
  for (; param_1 != 0; param_1 = param_1 + -1) {
  }
  return;
}



// ==== 0800043c  FUN_0800043c  (234 bytes, 1 xrefs)

void FUN_0800043c(void)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_10;
  uint local_8;
  
  FUN_0800014e(&local_20,0x18);
  puVar1 = PTR_RCC_08000528;
  local_28 = 0;
  local_24 = 0;
  *(uint *)(PTR_RCC_08000528 + 0x34) = *(uint *)(PTR_RCC_08000528 + 0x34) | 0x20;
  local_8 = *(uint *)(puVar1 + 0x34) & 0x20;
  *(uint *)(puVar1 + 0x34) = *(uint *)(puVar1 + 0x34) & 0xfffffff8;
  *(uint *)(puVar1 + 0x38) = *(uint *)(puVar1 + 0x38) & 0xfffffffe;
  uVar2 = DAT_0800052c;
  *(uint *)(puVar1 + 0x3c) = *(uint *)(puVar1 + 0x3c) & ~DAT_0800052c;
  *(uint *)(PTR_RCC_08000528 + 0x40) = *(uint *)(PTR_RCC_08000528 + 0x40) & 0xffffadff;
  *(uint *)(puVar1 + 0x24) = *(uint *)(puVar1 + 0x24) | 7;
  *(uint *)(puVar1 + 0x28) = *(uint *)(puVar1 + 0x28) | 1;
  *(uint *)(puVar1 + 0x2c) = *(uint *)(puVar1 + 0x2c) | uVar2;
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) | 0x5200;
  *(uint *)(DAT_08000530 + 0x10) = *(uint *)(DAT_08000530 + 0x10) & 0xfffffffe;
  local_1c = 0;
  local_10 = 0;
  local_20 = 0x360;
  FUN_08000c08(PTR_GPIOF_08000534,&local_20);
  local_28 = 0x40;
  local_24 = CONCAT13(local_24._3_1_,0x10101);
  FUN_08000b60(&local_28);
  *(uint *)(PTR_DAT_08000538 + 0x60) = *(uint *)(PTR_DAT_08000538 + 0x60) & 0xfffcffff | 0x30000;
  *(uint *)(puVar1 + 0x3c) = *(uint *)(puVar1 + 0x3c) | (int)PTR_DAT_08000538 << 0x1a;
  *(uint *)PTR_PWR_0800053c = *(uint *)PTR_PWR_0800053c & 0xfffff9ff | 0x600;
  *(uint *)PTR_PWR_0800053c = *(uint *)PTR_PWR_0800053c | (int)PTR_PWR_0800053c >> 0x10;
  *(uint *)(DAT_08000540 + 0x10) = *(uint *)(DAT_08000540 + 0x10) | 4;
  WaitForEvent();
  WaitForEvent();
  *(uint *)(DAT_08000540 + 0x10) = *(uint *)(DAT_08000540 + 0x10) & 0xfffffffb;
  DataSynchronizationBarrier(0xf);
  *(undefined4 *)(DAT_08000540 + 0xc) = DAT_08000544;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 08000548  FUN_08000548  (20 bytes, 1 xrefs)

void FUN_08000548(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0800055c;
  *param_1 = *DAT_0800055c;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  param_1[3] = puVar1[3];
  return;
}



// ==== 08000560  FUN_08000560  (54 bytes, 2 xrefs)

void FUN_08000560(byte *param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar2 = 0;
  while (uVar3 = param_2 - 1, param_2 != 0) {
    uVar2 = uVar2 ^ (uint)*param_1 << 8;
    uVar4 = 0;
    param_1 = param_1 + 1;
    do {
      if ((int)(uVar2 << 0x10) < 0) {
        uVar1 = (ushort)(uVar2 << 1) ^ (ushort)DAT_08000598;
      }
      else {
        uVar1 = (ushort)(uVar2 << 1);
      }
      uVar4 = uVar4 + 1;
      uVar2 = (uint)uVar1;
      param_2 = uVar3 & 0xffff;
    } while (uVar4 < 8);
  }
  return;
}



// ==== 0800059c  FUN_0800059c  (74 bytes, 2 xrefs)

void FUN_0800059c(int param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_08000600();
  uVar2 = DAT_080005ec;
  puVar1 = PTR_FLASH_R_080005e8;
  uVar4 = ~DAT_080005ec;
  for (uVar3 = 0; uVar3 < param_2; uVar3 = uVar3 + 1 & 0xffff) {
    *(uint *)(puVar1 + 0x14) = *(uint *)(puVar1 + 0x14) | uVar2;
    *(undefined4 *)(param_1 + uVar3 * 0x100) = 0xffffffff;
    do {
    } while (*(int *)(puVar1 + 0x10) << 0xf < 0);
    *(uint *)(puVar1 + 0x14) = *(uint *)(puVar1 + 0x14) & uVar4;
    if ((*(uint *)(puVar1 + 0x10) & 1) == 0) break;
    *(uint *)(puVar1 + 0x10) = *(uint *)(puVar1 + 0x10) | 1;
  }
  FUN_080005f0();
  return;
}



// ==== 080005f0  FUN_080005f0  (12 bytes, 2 xrefs)

void FUN_080005f0(void)

{
  *(uint *)(PTR_FLASH_R_080005fc + 0x14) =
       *(uint *)(PTR_FLASH_R_080005fc + 0x14) | (int)PTR_FLASH_R_080005fc << 0x12;
  return;
}



// ==== 08000600  FUN_08000600  (12 bytes, 2 xrefs)

void FUN_08000600(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_FLASH_R_08000610;
  *(undefined4 *)(PTR_FLASH_R_08000610 + 8) = DAT_0800060c;
  *(undefined4 *)(puVar1 + 8) = DAT_08000614;
  return;
}



// ==== 08000618  FUN_08000618  (102 bytes, 2 xrefs)

void FUN_08000618(int param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  
  FUN_08000600();
  puVar1 = PTR_FLASH_R_08000680;
  iVar4 = 0;
  for (uVar5 = 0; uVar2 = DAT_08000684, uVar5 < (param_3 & 0xffff) >> 8; uVar5 = uVar5 + 1 & 0xffff)
  {
    *(uint *)(puVar1 + 0x14) = *(uint *)(puVar1 + 0x14) | DAT_08000684;
    uVar3 = 0;
    do {
      *(undefined4 *)(param_1 + iVar4) = *(undefined4 *)(param_2 + iVar4);
      iVar4 = iVar4 + 4;
      if (uVar3 == 0x3e) {
        *(uint *)(puVar1 + 0x14) = *(uint *)(puVar1 + 0x14) | (int)uVar2 >> 5;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x40);
    do {
    } while (*(int *)(puVar1 + 0x10) << 0xf < 0);
    *(uint *)(puVar1 + 0x14) = *(uint *)(puVar1 + 0x14) & ~DAT_08000684;
    if ((*(uint *)(puVar1 + 0x10) & 1) == 0) break;
    *(uint *)(puVar1 + 0x10) = *(uint *)(puVar1 + 0x10) | 1;
  }
  FUN_080005f0();
  return;
}



// ==== 08000688  FUN_08000688  (96 bytes, 1 xrefs)

void FUN_08000688(void)

{
  undefined *puVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  FUN_0800014e(&local_30,0x18);
  puVar1 = PTR_GPIOB_080006e8;
  local_28 = 3;
  local_2c = 1;
  local_30 = 0x78;
  local_24 = 0;
  local_20 = 1;
  FUN_08000c08(PTR_GPIOB_080006e8,&local_30);
  local_30 = 0x2000;
  FUN_08000c08(PTR_GPIOC_080006ec,&local_30);
  local_30 = 0xc400;
  local_2c = 0;
  FUN_08000c08(puVar1,&local_30);
  local_30 = 0x600;
  local_2c = 2;
  local_1c = 1;
  FUN_08000c08(&GPIOA,&local_30);
  *(undefined4 *)(puVar1 + 0x28) = 0x78;
  return;
}



// ==== 080006f0  FUN_080006f0  (76 bytes, 1 xrefs)

void FUN_080006f0(void)

{
  bool bVar1;
  undefined *puVar2;
  
  puVar2 = PTR_RCC_0800073c;
  *(uint *)(PTR_RCC_0800073c + 0x3c) = *(uint *)(PTR_RCC_0800073c + 0x3c) & 0xff7fffff;
  *(uint *)(PTR_RCC_0800073c + 0x40) = *(uint *)(PTR_RCC_0800073c + 0x40) & 0xffffbfff;
  *(uint *)(puVar2 + 0x38) = *(uint *)(puVar2 + 0x38) & 0xfffffffe;
  FUN_08001130(1);
  FUN_08001130(0x1f);
  if ((*DAT_08000740 & DAT_08000744) == 0x20000000) {
    enableIRQinterrupts();
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setMainStackPointer(*DAT_08000740);
    }
    (*(code *)DAT_08000740[1])();
  }
  return;
}



// ==== 08000748  FUN_08000748  (186 bytes, 1 xrefs)

void FUN_08000748(void)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  FUN_0800014e(&local_38,0x1c);
  iVar2 = DAT_08000808;
  puVar1 = PTR_DMA1_08000804;
  *(uint *)(PTR_DMA1_08000804 + *(byte *)(DAT_08000808 + 1)) =
       *(uint *)(PTR_DMA1_08000804 + *(byte *)(DAT_08000808 + 1)) & DAT_0800080c | 0xa0;
  *(uint *)(PTR_SYSCFG_08000810 + 8) = *(uint *)(PTR_SYSCFG_08000810 + 8) & 0xffffc0ff | 0x700;
  puVar3 = PTR_USART1_08000814;
  local_38 = 0x9600;
  local_34 = 0;
  local_28 = 0xc;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  FUN_08000cf8(PTR_USART1_08000814,&local_38);
  *(uint *)(puVar3 + 0x10) = *(uint *)(puVar3 + 0x10) & 0xffffb7ff;
  *(uint *)(puVar3 + 0x14) = *(uint *)(puVar3 + 0x14) & 0xffffffd5;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 1)) = *(uint *)(puVar1 + *(byte *)(iVar2 + 1)) & 0xfffffffe;
  *(undefined4 *)(PTR_DMA1_08000804 + *(byte *)(iVar2 + 1) + 0xc) = DAT_08000818;
  *(undefined **)(PTR_DMA1_08000804 + *(byte *)(iVar2 + 1) + 8) = puVar3 + 4;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 1) + 4) =
       *(uint *)(puVar1 + *(byte *)(iVar2 + 1) + 4) & 0xffff0000 | (int)(puVar3 + 4) >> 0x13;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 1)) = *(uint *)(puVar1 + *(byte *)(iVar2 + 1)) | 1;
  *(uint *)(puVar3 + 0x14) = *(uint *)(puVar3 + 0x14) | 0x40;
  *(uint *)(puVar3 + 0xc) = *(uint *)(puVar3 + 0xc) | 0x2000;
  *(undefined4 *)(puVar3 + 4) = 0;
  return;
}



// ==== 0800081c  FUN_0800081c  (274 bytes, 1 xrefs)

undefined4 FUN_0800081c(void)

{
  ushort uVar1;
  ushort *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  undefined4 in_r3;
  uint uVar8;
  uint uVar9;
  uint extraout_r3;
  uint uVar10;
  uint uVar11;
  
  iVar6 = DAT_0800093c;
  puVar3 = PTR_DAT_08000938;
  puVar2 = DAT_08000930;
  uVar8 = (uint)*DAT_08000930;
  iVar4 = *(int *)(PTR_DAT_08000938 + *(byte *)(DAT_08000934 + 1));
  uVar11 = (int)PTR_DAT_08000938 >> 0x13;
  uVar5 = uVar11 - iVar4 & 0xffff;
  while( true ) {
    if (uVar8 == uVar5) {
      return 0xffffffff;
    }
    while ((uVar8 != uVar5 && (*(char *)(iVar6 + uVar8) != -0x55))) {
      uVar8 = uVar8 + 1 & 0x7ff;
      *puVar2 = (ushort)uVar8;
    }
    if (uVar8 == uVar5) {
      return 0xffffffff;
    }
    uVar1 = (ushort)(uVar11 - iVar4);
    if (uVar8 < uVar5) {
      uVar7 = uVar1 - (short)uVar8;
    }
    else {
      uVar7 = (uVar1 - (short)uVar8) + (short)((int)puVar3 >> 0x13);
    }
    if (uVar7 < 8) {
      return 0xffffffff;
    }
    if (*(char *)(iVar6 + (uVar8 + 1 & 0x7ff)) == -0x33) break;
    uVar8 = uVar8 + 1 & 0x7ff;
    *puVar2 = (ushort)uVar8;
  }
  uVar5 = uVar8 + 2 & 0x7ff;
  uVar8 = (uint)CONCAT11(*(undefined1 *)(iVar6 + (uVar5 + 1 & 0x7ff)),*(undefined1 *)(iVar6 + uVar5)
                        );
  if (uVar8 + 8 <= uVar11) {
    if ((uint)uVar7 < uVar8 + 8) {
      return 0xffffffff;
    }
    uVar5 = uVar5 + 2 & 0x7ff;
    uVar10 = uVar5 + uVar8 + 2 & 0x7ff;
    if ((*(char *)(iVar6 + uVar10) == -0x24) &&
       (uVar9 = uVar10 + 1 & 0x7ff, *(char *)(iVar6 + uVar9) == -0x46)) {
      if (uVar10 < uVar5) {
        FUN_0800011c(DAT_08000940,DAT_0800093c + uVar5,uVar11 - uVar5,uVar9,in_r3);
        iVar6 = (uVar11 - uVar5) + DAT_08000940;
        iVar4 = DAT_0800093c;
        uVar11 = uVar10;
        uVar9 = extraout_r3;
      }
      else {
        uVar11 = uVar10 - uVar5;
        iVar4 = DAT_0800093c + uVar5;
        iVar6 = DAT_08000940;
      }
      FUN_0800011c(iVar6,iVar4,uVar11,uVar9,in_r3);
      *puVar2 = (short)uVar10 + 2U & 0x7ff;
      iVar6 = DAT_08000940;
      iVar4 = DAT_08000934 + 8;
      for (uVar5 = 0; uVar5 < uVar8 + 2; uVar5 = uVar5 + 1 & 0xffff) {
        *(byte *)(iVar6 + uVar5) = *(byte *)(iVar6 + uVar5) ^ *(byte *)(iVar4 + (uVar5 & 0xf));
      }
      uVar1 = *(ushort *)(iVar6 + uVar8);
      uVar5 = FUN_08000560(DAT_08000940,uVar8);
      if (uVar1 == uVar5) {
        return 0;
      }
      return 0xffffffff;
    }
  }
  *puVar2 = uVar1;
  return 0xffffffff;
}



// ==== 08000944  FUN_08000944  (26 bytes, 5 xrefs)

void FUN_08000944(int param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = PTR_USART1_08000960;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
    do {
    } while (-1 < *(int *)puVar1 << 0x19);
    *(uint *)(puVar1 + 4) = (uint)*(byte *)(param_1 + uVar2);
  }
  return;
}



// ==== 08000964  FUN_08000964  (90 bytes, 1 xrefs)

void FUN_08000964(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 local_10;
  
  iVar1 = DAT_080009c0;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xffff) {
    *(byte *)(param_1 + uVar2) = *(byte *)(param_1 + uVar2) ^ *(byte *)(iVar1 + (uVar2 & 0xf));
  }
  local_10 = CONCAT13((char)(param_2 >> 8),CONCAT12((char)param_2,0xcdab));
  FUN_08000944(&local_10,4);
  FUN_08000944(param_1,param_2);
  local_10 = 0xbadcffff;
  FUN_08000944(&local_10,4);
  return;
}



// ==== 080009c4  FUN_080009c4  (16 bytes, 1 xrefs)

void FUN_080009c4(void)

{
  FUN_080011e8();
  *DAT_080009d4 = 0x80000000;
  return;
}



// ==== 080009d8  FUN_080009d8  (264 bytes, 1 xrefs)

undefined4 FUN_080009d8(void)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort uVar7;
  undefined4 in_r3;
  uint uVar8;
  uint uVar9;
  uint extraout_r3;
  uint uVar10;
  
  iVar5 = DAT_08000ae4;
  puVar2 = DAT_08000ae0;
  uVar8 = (uint)*DAT_08000ae0;
  uVar1 = DAT_08000ae0[1];
  uVar3 = (uint)uVar1;
  while( true ) {
    if (uVar8 == uVar3) {
      return 0xffffffff;
    }
    while ((uVar8 != uVar3 && (*(char *)(iVar5 + uVar8) != -0x55))) {
      uVar8 = uVar8 + 1 & 0x7ff;
      *puVar2 = (ushort)uVar8;
    }
    if (uVar8 == uVar3) {
      return 0xffffffff;
    }
    if (uVar8 < uVar3) {
      uVar7 = uVar1 - (short)uVar8;
    }
    else {
      uVar7 = (uVar1 - (short)uVar8) + 0x800;
    }
    if (uVar7 < 8) {
      return 0xffffffff;
    }
    if (*(char *)(iVar5 + (uVar8 + 1 & 0x7ff)) == -0x33) break;
    uVar8 = uVar8 + 1 & 0x7ff;
    *puVar2 = (ushort)uVar8;
  }
  uVar3 = uVar8 + 2 & 0x7ff;
  uVar8 = (uint)CONCAT11(*(undefined1 *)(iVar5 + (uVar3 + 1 & 0x7ff)),*(undefined1 *)(iVar5 + uVar3)
                        );
  if (uVar8 + 8 < 0x801) {
    if ((uint)uVar7 < uVar8 + 8) {
      return 0xffffffff;
    }
    uVar3 = uVar3 + 2 & 0x7ff;
    uVar10 = uVar3 + uVar8 + 2 & 0x7ff;
    if ((*(char *)(iVar5 + uVar10) == -0x24) &&
       (uVar9 = uVar10 + 1 & 0x7ff, *(char *)(iVar5 + uVar9) == -0x46)) {
      if (uVar10 < uVar3) {
        FUN_0800011c(DAT_08000ae8,DAT_08000ae4 + uVar3,0x800 - uVar3,uVar9,in_r3);
        iVar5 = (0x800 - uVar3) + DAT_08000ae8;
        iVar4 = DAT_08000ae4;
        uVar6 = uVar10;
        uVar9 = extraout_r3;
      }
      else {
        uVar6 = uVar10 - uVar3;
        iVar4 = DAT_08000ae4 + uVar3;
        iVar5 = DAT_08000ae8;
      }
      FUN_0800011c(iVar5,iVar4,uVar6,uVar9,in_r3);
      *puVar2 = (short)uVar10 + 2U & 0x7ff;
      iVar4 = DAT_08000aec;
      iVar5 = DAT_08000ae8;
      for (uVar3 = 0; uVar3 < uVar8 + 2; uVar3 = uVar3 + 1 & 0xffff) {
        *(byte *)(iVar5 + uVar3) = *(byte *)(iVar5 + uVar3) ^ *(byte *)(iVar4 + (uVar3 & 0xf));
      }
      uVar1 = *(ushort *)(iVar5 + uVar8);
      uVar3 = FUN_08000560(DAT_08000ae8,uVar8);
      if (uVar3 == uVar1) {
        return 0;
      }
      return 0xffffffff;
    }
  }
  *puVar2 = uVar1;
  return 0xffffffff;
}



// ==== 08000af0  FUN_08000af0  (102 bytes, 1 xrefs)

void FUN_08000af0(int param_1,uint param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  iVar1 = DAT_08000b58;
  for (uVar3 = 0; puVar2 = DAT_08000b5c, uVar3 < param_2; uVar3 = uVar3 + 1 & 0xffff) {
    *(byte *)(param_1 + uVar3) = *(byte *)(param_1 + uVar3) ^ *(byte *)(iVar1 + (uVar3 & 0xf));
  }
  *DAT_08000b5c = 0xab;
  puVar2[1] = 0xcd;
  puVar2[2] = (char)param_2;
  puVar2[3] = (char)(param_2 >> 8);
  FUN_0800011c(puVar2 + 4,param_1,param_2);
  puVar2[param_2 + 4] = *(byte *)(iVar1 + (param_2 & 0xf)) ^ 0xff;
  puVar2[param_2 + 5] = *(byte *)(iVar1 + (param_2 + 1 & 0xf)) ^ 0xff;
  puVar2[param_2 + 6] = 0xdc;
  puVar2[param_2 + 7] = 0xba;
  FUN_080018bc(0x81,puVar2,param_2 + 8);
  return;
}



// ==== 08000b60  FUN_08000b60  (162 bytes, 1 xrefs)

uint FUN_08000b60(uint *param_1)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar2 = PTR_DAT_08000c04;
  uVar4 = 0;
  uVar3 = *param_1;
  if ((char)param_1[1] == '\0') {
    *(uint *)PTR_DAT_08000c04 = *(uint *)PTR_DAT_08000c04 & ~uVar3;
    *(uint *)(puVar2 + 4) = *(uint *)(puVar2 + 4) & ~*param_1;
    return 0;
  }
  if (uVar3 == 0) {
    return 0;
  }
  cVar1 = *(char *)((int)param_1 + 5);
  if (cVar1 == '\0') {
    *(uint *)(PTR_DAT_08000c04 + 4) = *(uint *)(PTR_DAT_08000c04 + 4) & ~uVar3;
    *(uint *)puVar2 = *(uint *)puVar2 | *param_1;
  }
  else {
    if (cVar1 == '\x01') {
      uVar3 = *(uint *)PTR_DAT_08000c04 & ~uVar3;
    }
    else {
      if (cVar1 != '\x02') {
        uVar4 = 1;
        goto LAB_08000b82;
      }
      uVar3 = *(uint *)PTR_DAT_08000c04 | uVar3;
    }
    *(uint *)PTR_DAT_08000c04 = uVar3;
    *(uint *)(puVar2 + 4) = *(uint *)(puVar2 + 4) | *param_1;
  }
LAB_08000b82:
  puVar2 = PTR_DAT_08000c04;
  cVar1 = *(char *)((int)param_1 + 6);
  if (cVar1 != '\0') {
    puVar5 = (uint *)(PTR_DAT_08000c04 + -0x80);
    if (cVar1 == '\x01') {
      *(uint *)(PTR_DAT_08000c04 + -0x7c) = *(uint *)(PTR_DAT_08000c04 + -0x7c) & ~*param_1;
      *puVar5 = *puVar5 | *param_1;
    }
    else {
      if (cVar1 == '\x02') {
        uVar3 = *puVar5 & ~*param_1;
      }
      else {
        if (cVar1 != '\x03') {
          return uVar4 | 2;
        }
        uVar3 = *puVar5 | *param_1;
      }
      *puVar5 = uVar3;
      *(uint *)(puVar2 + -0x7c) = *(uint *)(puVar2 + -0x7c) | *param_1;
    }
  }
  return uVar4;
}



// ==== 08000c08  FUN_08000c08  (164 bytes, 5 xrefs)

undefined4 FUN_08000c08(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  for (uVar3 = 0; *param_2 >> (uVar3 & 0xff) != 0; uVar3 = uVar3 + 1) {
    uVar2 = *param_2 & 1 << (uVar3 & 0xff);
    if (uVar2 != 0) {
      iVar4 = uVar2 * uVar2;
      uVar1 = iVar4 * 3;
      *param_1 = *param_1 & ~uVar1 | iVar4 * param_2[1];
      if ((param_2[1] == 1) || (param_2[1] == 2)) {
        param_1[2] = param_1[2] & ~uVar1 | iVar4 * param_2[2];
      }
      param_1[3] = param_1[3] & ~uVar1 | param_2[4] * iVar4;
      if (param_2[1] == 2) {
        if (uVar2 < 0x100) {
          iVar4 = uVar2 * uVar2 * iVar4;
          param_1[8] = param_1[8] & ~(iVar4 * 0xf) | param_2[5] * iVar4;
        }
        else {
          uVar2 = uVar2 >> 8;
          iVar4 = uVar2 * uVar2 * uVar2 * uVar2;
          param_1[9] = param_1[9] & ~(iVar4 * 0xf) | param_2[5] * iVar4;
        }
      }
    }
  }
  if ((param_2[1] == 1) || (param_2[1] == 2)) {
    param_1[1] = param_1[1] & ~*param_2 | param_2[3] * *param_2;
  }
  return 0;
}



// ==== 08000cac  FUN_08000cac  (14 bytes, 3 xrefs)

undefined4 FUN_08000cac(int param_1,uint param_2)

{
  if ((param_2 & ~*(uint *)(param_1 + 0x10)) == 0) {
    return 1;
  }
  return 0;
}



// ==== 08000cba  FUN_08000cba  (24 bytes, 1 xrefs)

void FUN_08000cba(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_08000e48();
  *param_1 = uVar1;
  uVar1 = FUN_08000e08();
  param_1[1] = uVar1;
  uVar1 = FUN_08000e28();
  param_1[2] = uVar1;
  return;
}



// ==== 08000cd4  FUN_08000cd4  (16 bytes, 1 xrefs)

undefined4 FUN_08000cd4(void)

{
  return *(undefined4 *)(DAT_08000ce8 + (*(uint *)(PTR_RCC_08000ce4 + 4) >> 0xb & 0x1c));
}



// ==== 08000cec  FUN_08000cec  (6 bytes, 1 xrefs)

void FUN_08000cec(undefined4 param_1)

{
  *DAT_08000cf4 = param_1;
  return;
}



// ==== 08000cf8  FUN_08000cf8  (106 bytes, 1 xrefs)

undefined8 FUN_08000cf8(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int *piStack_20;
  undefined4 uStack_1c;
  int local_18;
  
  uVar1 = 1;
  piStack_20 = param_2;
  if (-1 < *(int *)(param_1 + 0xc) << 0x12) {
    *(uint *)(param_1 + 0xc) =
         param_2[1] | param_2[3] | param_2[4] | *(uint *)(param_1 + 0xc) & DAT_08000d64;
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffff7ff | param_2[6];
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffcfff | param_2[2];
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffcff | param_2[5];
    uStack_1c = param_3;
    local_18 = param_4;
    FUN_08000cba(&piStack_20);
    if ((local_18 != 0) && (*param_2 != 0)) {
      uVar1 = 0;
      FUN_08000d68(param_1,local_18,param_2[6]);
    }
  }
  return CONCAT44(piStack_20,uVar1);
}



// ==== 08000d68  FUN_08000d68  (116 bytes, 1 xrefs)

void FUN_08000d68(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 == 0x800) {
    iVar1 = FUN_080000f0(param_2 * 0x19,param_4 << 1);
    iVar2 = FUN_080000f0(iVar1,100);
    uVar3 = FUN_080000f0((iVar1 + iVar2 * -100) * 8 + 0x32);
    iVar1 = iVar2 * 0x10 + (uVar3 & 0xf8) * 2;
    uVar3 = uVar3 & 7;
  }
  else {
    iVar1 = FUN_080000f0(param_2 * 0x19,param_4 << 2);
    iVar2 = FUN_080000f0(iVar1,100);
    uVar3 = FUN_080000f0((iVar1 + iVar2 * -100) * 0x10 + 0x32);
    iVar1 = iVar2 * 0x10 + (uVar3 & 0xf0);
    uVar3 = uVar3 & 0xf;
  }
  *(uint *)(param_1 + 8) = iVar1 + uVar3 & 0xffff;
  return;
}



// ==== 08000ddc  FUN_08000ddc  (34 bytes, 0 xrefs)

void FUN_08000ddc(void)

{
  if ((~*(uint *)(PTR_EXTI_08000e00 + 0xc) & 0x10000) == 0) {
    *(undefined4 *)(PTR_EXTI_08000e00 + 0xc) = 0x10000;
    if (*(int *)(PTR_PWR_08000e04 + 0x14) << 0x14 < 0) {
      FUN_0800043c();
    }
  }
  return;
}



// ==== 08000e08  FUN_08000e08  (24 bytes, 1 xrefs)

uint FUN_08000e08(uint param_1)

{
  return param_1 >> (*(byte *)(DAT_08000e24 + (*(uint *)(PTR_RCC_08000e20 + 8) >> 6 & 0x3c)) & 0x1f)
  ;
}



// ==== 08000e28  FUN_08000e28  (22 bytes, 1 xrefs)

uint FUN_08000e28(uint param_1)

{
  return param_1 >>
         (*(byte *)(DAT_08000e44 + ((*(uint *)(PTR_RCC_08000e40 + 8) & 0x7fff) >> 0xc) * 4) & 0x1f);
}



// ==== 08000e48  FUN_08000e48  (68 bytes, 1 xrefs)

undefined4 FUN_08000e48(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(PTR_RCC_08000e8c + 8) & 0x38;
  if (uVar2 == 8) {
    return DAT_08000e94;
  }
  if (uVar2 == 0x10) {
    uVar1 = FUN_08000e98();
    return uVar1;
  }
  uVar1 = 0x8000;
  if ((uVar2 != 0x18) && (uVar2 != 0x20)) {
    uVar1 = FUN_080000f0(*(undefined4 *)
                          (DAT_08000e90 + (*(uint *)(PTR_RCC_08000e8c + 4) >> 0xb & 0x1c)),
                         1 << ((*(uint *)PTR_RCC_08000e8c & 0x3fff) >> 0xb));
  }
  return uVar1;
}



// ==== 08000e98  FUN_08000e98  (40 bytes, 1 xrefs)

int FUN_08000e98(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_RCC_08000ec0;
  if ((*(uint *)(PTR_RCC_08000ec0 + 0xc) & 3) == 3) {
    iVar2 = DAT_08000ec4;
  }
  else {
    iVar2 = FUN_08000cd4();
  }
  if ((*(uint *)(puVar1 + 0xc) & 0xf) >> 2 == 0) {
    return iVar2 << 1;
  }
  return iVar2 * 3;
}



// ==== 08000ec8  FUN_08000ec8  (172 bytes, 1 xrefs)

void FUN_08000ec8(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar1 = PTR_RCC_08000f74;
  uVar3 = (int)PTR_RCC_08000f74 >> 0x16;
  *(uint *)PTR_RCC_08000f74 = *(uint *)PTR_RCC_08000f74 | uVar3;
  *(uint *)(puVar1 + 4) =
       *(uint *)(puVar1 + 4) & 0xffff0000 |
       (*(ushort *)(DAT_08000f78 + 0x10) & 0x1fff) + uVar3 * 0x40;
  do {
  } while (-1 < *(int *)puVar1 << 0x15);
  *(uint *)puVar1 = *(uint *)puVar1 & 0xfeffffff;
  do {
  } while (*(int *)puVar1 << 6 < 0);
  *(uint *)(puVar1 + 0xc) = *(uint *)(puVar1 + 0xc) & 0xfffffffc | 2;
  *(uint *)(puVar1 + 0xc) = *(uint *)(puVar1 + 0xc) & 0xfffffff3 | 4;
  *(uint *)puVar1 = *(uint *)puVar1 | 0x1000000;
  puVar2 = PTR_FLASH_R_08000f7c;
  do {
  } while (-1 < *(int *)puVar1 << 6);
  *(uint *)PTR_FLASH_R_08000f7c = *(uint *)PTR_FLASH_R_08000f7c & 0xfffffffc | 1;
  do {
  } while ((*(uint *)puVar2 & 3) != 1);
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) & 0xfffff0ff;
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) & 0xfffffff8 | 2;
  do {
  } while ((*(uint *)(puVar1 + 8) & 0x38) != 0x10);
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) & 0xffff8fff;
  FUN_08000cec(DAT_08000f80);
  return;
}



// ==== 08000f84  FUN_08000f84  (40 bytes, 1 xrefs)

void FUN_08000f84(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_RCC_08000fac;
  *(uint *)(PTR_RCC_08000fac + 4) =
       *(uint *)(PTR_RCC_08000fac + 4) & 0xfe000000 | (uint)*(ushort *)(DAT_08000fb0 + 8) |
       (uint)*(ushort *)(DAT_08000fb4 + 8) << 0x10 | 0x2000;
  *(int *)(DAT_08000fb8 + 8) = (int)puVar1 << 0xf;
  return;
}



// ==== 08000fbc  FUN_08000fbc  (324 bytes, 1 xrefs)

void FUN_08000fbc(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  puVar4 = PTR_USBD_08001100;
  bVar1 = PTR_USBD_08001100[6];
  bVar2 = PTR_USBD_08001100[5];
  uVar3 = PTR_USBD_08001100[0xe];
  if ((int)((uint)(byte)PTR_USBD_08001100[4] << 0x1d) < 0) {
    FUN_0800014e(DAT_08001104,0x180);
    *(undefined4 *)(DAT_08001104 + 4) = 0x40;
    FUN_08001ad0();
    puVar4[10] = 1;
    puVar4[9] = 0;
    *DAT_08001108 = 0;
  }
  bVar1 = puVar4[10] & bVar1;
  uVar9 = (uint)bVar1;
  if ((bVar1 & 1) != 0) {
    puVar4[0xe] = 0;
    FUN_0800122c();
    uVar9 = (uint)(bVar1 >> 1) << 1;
  }
  uVar7 = 1;
  do {
    if (uVar9 == 0) {
      uVar7 = (uint)(PTR_USBD_08001100[9] & bVar2);
      uVar9 = 1;
      while (puVar4 = PTR_USBD_08001100, uVar7 != 0) {
        if ((1 << uVar9 & uVar7) != 0) {
          PTR_USBD_08001100[0xe] = (char)uVar9;
          if ((puVar4[0x19] & 1) != 0) {
            uVar10 = (uint)*(ushort *)(puVar4 + 0x1c);
            iVar8 = uVar9 * 0x14 + DAT_08001104;
            FUN_08001488(uVar9,*(undefined4 *)(iVar8 + 0xd0),uVar10);
            PTR_USBD_08001100[0x19] = PTR_USBD_08001100[0x19] & 0xfe;
            *(uint *)(iVar8 + 0xd0) = *(int *)(iVar8 + 0xd0) + uVar10;
            *(uint *)(iVar8 + 0xd8) = *(int *)(iVar8 + 0xd8) + uVar10;
            iVar5 = *(int *)(iVar8 + 0xd4) - uVar10;
            *(int *)(iVar8 + 0xd4) = iVar5;
            if ((uVar10 < *(ushort *)(iVar8 + 200)) || (iVar5 == 0)) {
              FUN_08001a68(uVar9);
            }
          }
          uVar7 = uVar7 & ~(1 << uVar9);
        }
        uVar9 = uVar9 + 1 & 0xff;
      }
      PTR_USBD_08001100[0xe] = uVar3;
      return;
    }
    if ((1 << uVar7 & uVar9) != 0) {
      puVar4[0xe] = (char)uVar7;
      if ((int)((uint)(byte)puVar4[0x15] << 0x1d) < 0) {
        puVar4[0x15] = puVar4[0x15] & 0xfb;
      }
      iVar5 = uVar7 * 0x14 + DAT_08001104;
      uVar6 = (uint)*(ushort *)(iVar5 + 0x28);
      uVar10 = *(uint *)(iVar5 + 0x34);
      if (uVar6 < uVar10) {
        iVar8 = *(int *)(iVar5 + 0x30) + uVar6;
        *(int *)(iVar5 + 0x30) = iVar8;
        *(uint *)(iVar5 + 0x38) = *(int *)(iVar5 + 0x38) + uVar6;
        uVar10 = uVar10 - uVar6;
        *(uint *)(iVar5 + 0x34) = uVar10;
        if (uVar10 == 0) goto LAB_0800107e;
        if (uVar6 <= uVar10) {
          uVar10 = uVar6;
        }
        FUN_080014a8(uVar7,iVar8,uVar10 & 0xffff);
        puVar4[0x15] = 1;
      }
      else {
        *(uint *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + uVar10;
        *(uint *)(iVar5 + 0x38) = *(int *)(iVar5 + 0x38) + uVar10;
        *(undefined4 *)(iVar5 + 0x34) = 0;
LAB_0800107e:
        FUN_08001a04(uVar7 | 0x80,*(undefined4 *)(iVar5 + 0x38));
      }
      uVar9 = uVar9 & ~(1 << uVar7);
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while( true );
}



// ==== 0800110c  FUN_0800110c  (8 bytes, 0 xrefs)

void FUN_0800110c(void)

{
  FUN_08000fbc();
  return;
}



// ==== 08001114  __ARM_common_switch8  (26 bytes, 3 xrefs)

/* WARNING: This is an inlined function */

void __ARM_common_switch8(void)

{
  uint in_r3;
  uint uVar1;
  int unaff_lr;
  
  uVar1 = (uint)*(byte *)(unaff_lr + -1);
  if (in_r3 < *(byte *)(unaff_lr + -1)) {
    uVar1 = in_r3;
  }
                    /* WARNING: Could not recover jumptable at 0x0800112c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_lr + (uint)*(byte *)(unaff_lr + uVar1) * 2))();
  return;
}



// ==== 08001130  FUN_08001130  (26 bytes, 2 xrefs)

void FUN_08001130(uint param_1)

{
  if (-1 < (int)param_1) {
    *DAT_0800114c = 1 << (param_1 & 0x1f);
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}



// ==== 0800116e  FUN_0800116e  (120 bytes, 0 xrefs)

undefined4 FUN_0800116e(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  
  uVar1 = *(undefined1 *)(param_1 + 4);
  cVar2 = *(char *)(param_1 + 1);
  puStack_18 = param_3;
  uStack_14 = param_4;
  if (cVar2 == ' ') {
    FUN_0800011c(&puStack_18,*param_2,*(undefined2 *)(param_1 + 6));
    FUN_080015ee(uVar1,&puStack_18);
  }
  else if (cVar2 == '!') {
    FUN_080015b8(uVar1,&puStack_18);
    FUN_0800011c(*param_2,&puStack_18,7);
    *param_3 = 7;
  }
  else {
    if (cVar2 != '\"') {
      return 0xffffffff;
    }
    bVar3 = *(byte *)(param_1 + 2);
    FUN_080015ec(uVar1,bVar3 & 1);
    FUN_080015f0(uVar1,(bVar3 & 3) >> 1);
  }
  return 0;
}



// ==== 080011e8  FUN_080011e8  (50 bytes, 1 xrefs)

void FUN_080011e8(void)

{
  FUN_08001694(DAT_0800121c);
  FUN_080015d4(DAT_08001220);
  FUN_08001510();
  FUN_080015d4(DAT_08001220 + 0x20);
  FUN_08001510();
  FUN_080014ec(DAT_08001224);
  FUN_080014ec(DAT_08001224 + 8);
  FUN_08001ba0();
  return;
}



// ==== 0800122c  FUN_0800122c  (58 bytes, 1 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    Instruction at (ram,0x08001426) overlaps instruction at (ram,0x08001424)


// ==== 08001318  FUN_08001318  (12 bytes, 2 xrefs)

bool FUN_08001318(void)

{
  return *(char *)(DAT_08001324 + 0x1d) != '\0';
}



// ==== 08001328  FUN_08001328  (272 bytes, 1 xrefs)

undefined4 FUN_08001328(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar2 = PTR_RCC_08001438;
  *(uint *)(PTR_RCC_08001438 + 0x34) = *(uint *)(PTR_RCC_08001438 + 0x34) | 7;
  *(uint *)(PTR_RCC_08001438 + 0x40) = *(uint *)(PTR_RCC_08001438 + 0x40) | DAT_0800143c;
  *(uint *)(puVar2 + 0x3c) = *(uint *)(puVar2 + 0x3c) | (int)puVar2 << 0xb;
  *(uint *)(puVar2 + 0x38) = *(uint *)(puVar2 + 0x38) | 1;
  FUN_08000ec8();
  FUN_08000688();
  FUN_08000748();
  FUN_08000548(DAT_08001440);
  puVar2 = PTR_GPIOB_08001444;
  iVar6 = FUN_08000cac(PTR_GPIOB_08001444,0xc000);
  pcVar4 = DAT_0800144c;
  puVar3 = PTR_GPIOC_08001448;
  if ((iVar6 != 0) && (iVar6 = FUN_08000cac(puVar2,0x400), iVar6 == 0)) {
    thunk_FUN_08000434(DAT_08001450);
    iVar6 = FUN_08000cac(puVar2,0x400);
    if (iVar6 == 0) {
      *pcVar4 = '\x01';
      FUN_080009c4();
      *(undefined4 *)(puVar3 + 0x18) = 0x2000;
    }
  }
  FUN_08000944(DAT_08001454,0xc);
  FUN_08000944(&DAT_08001458,2);
  uVar5 = DAT_0800145c;
  if (*pcVar4 == '\x01') {
    do {
      while( true ) {
        while( true ) {
          iVar6 = FUN_0800081c();
          if (iVar6 == 0) {
            FUN_08000204();
          }
          iVar6 = FUN_080009d8();
          if (iVar6 == 0) {
            disableIRQinterrupts();
            FUN_08000204(1);
            enableIRQinterrupts();
          }
          cVar1 = *pcVar4;
          if (cVar1 != '\x01') break;
          thunk_FUN_08000434(DAT_08001450);
          FUN_080003dc(0);
          thunk_FUN_08000434(uVar5);
          FUN_080003dc(1);
        }
        if (cVar1 != '\x02') break;
        thunk_FUN_08000434(DAT_08001464);
      }
    } while (cVar1 != '\x03');
    *(undefined4 *)(puVar3 + 0x28) = 0x2000;
    thunk_FUN_08000434(DAT_08001460);
  }
  thunk_FUN_08000434(uVar5);
  FUN_080006f0();
  return 0;
}



// ==== 08001468  FUN_08001468  (30 bytes, 2 xrefs)

uint FUN_08001468(uint param_1,undefined2 *param_2)

{
  uint uVar1;
  
  uVar1 = 1;
  do {
    if (param_1 <= uVar1 * 8) {
      *param_2 = (short)(uVar1 * 8);
      return uVar1;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x41);
  *param_2 = 0;
  return 1;
}



// ==== 08001488  FUN_08001488  (26 bytes, 2 xrefs)

void FUN_08001488(int param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_080014a4 + param_1 * 4;
  for (; param_3 != 0; param_3 = param_3 - 1 & 0xffff) {
    *param_2 = *puVar1;
    param_2 = param_2 + 1;
  }
  return;
}



// ==== 080014a8  FUN_080014a8  (26 bytes, 2 xrefs)

void FUN_080014a8(int param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = PTR_DAT_080014c4 + param_1 * 4;
  for (; param_3 != 0; param_3 = param_3 - 1 & 0xffff) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *puVar2 = uVar1;
  }
  return;
}



// ==== 080014c8  FUN_080014c8  (28 bytes, 1 xrefs)

undefined4 FUN_080014c8(void)

{
  undefined *puVar1;
  
  FUN_080014e8();
  puVar1 = PTR_USBD_080014e4;
  PTR_USBD_080014e4[0xe] = 0;
  *puVar1 = 0;
  puVar1[8] = 4;
  puVar1[10] = 1;
  puVar1[9] = 0;
  return 0;
}



// ==== 080014e8  FUN_080014e8  (2 bytes, 1 xrefs)

void FUN_080014e8(void)

{
  return;
}



// ==== 080014ec  FUN_080014ec  (32 bytes, 2 xrefs)

void FUN_080014ec(byte *param_1)

{
  int iVar1;
  
  iVar1 = (*param_1 & 0x7f) * 4 + DAT_0800150c;
  if ((int)((uint)*param_1 * 0x1000000) < 0) {
    *(undefined4 *)(iVar1 + 0x11c) = *(undefined4 *)(param_1 + 4);
    return;
  }
  *(undefined4 *)(iVar1 + 0x13c) = *(undefined4 *)(param_1 + 4);
  return;
}



// ==== 08001510  FUN_08001510  (32 bytes, 2 xrefs)

void FUN_08001510(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_08001530;
  *(undefined1 *)(param_1 + 7) = *(undefined1 *)(DAT_08001530 + 0x1e);
  puVar2 = DAT_08001534;
  while ((undefined4 *)*puVar2 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar2;
  }
  *puVar2 = param_1;
  *param_1 = 0;
  *(char *)(iVar1 + 0x1e) = *(char *)(iVar1 + 0x1e) + '\x01';
  return;
}



// ==== 08001538  FUN_08001538  (30 bytes, 0 xrefs)

void FUN_08001538(undefined4 param_1,uint param_2)

{
  if (((param_2 & 0x3f) == 0) && (param_2 != 0)) {
    FUN_080018bc(0x81,0);
    return;
  }
  *DAT_08001558 = 0;
  return;
}



// ==== 0800155c  FUN_0800155c  (78 bytes, 0 xrefs)

void FUN_0800155c(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  
  puVar1 = PTR_DAT_080015ac;
  uVar3 = (uint)*(ushort *)PTR_DAT_080015ac;
  puVar2 = PTR_DAT_080015b0 + uVar3;
  if (uVar3 + param_2 < 0x801) {
    puVar4 = PTR_DAT_080015b4;
    iVar5 = param_2;
  }
  else {
    FUN_0800011c(puVar2,PTR_DAT_080015b4,0x800 - uVar3);
    puVar2 = PTR_DAT_080015b0;
    puVar4 = PTR_DAT_080015b4 + (0x800 - (uint)*(ushort *)puVar1);
    iVar5 = (uint)*(ushort *)puVar1 + param_2 + -0x800;
  }
  FUN_0800011c(puVar2,puVar4,iVar5);
  *(ushort *)puVar1 = *(short *)puVar1 + (short)param_2 & 0x7ff;
  FUN_08001850(2,PTR_DAT_080015b4,0x200);
  return;
}



// ==== 080015b8  FUN_080015b8  (22 bytes, 1 xrefs)

void FUN_080015b8(undefined4 param_1,int param_2)

{
  FUN_08000192(DAT_080015d0);
  *(undefined1 *)(param_2 + 6) = 8;
  *(undefined1 *)(param_2 + 5) = 0;
  *(undefined1 *)(param_2 + 4) = 0;
  return;
}



// ==== 080015d4  FUN_080015d4  (16 bytes, 2 xrefs)

void FUN_080015d4(int param_1)

{
  *(undefined4 *)(param_1 + 4) = DAT_080015e4;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = DAT_080015e8;
  return;
}



// ==== 080015ec  FUN_080015ec  (2 bytes, 1 xrefs)

void FUN_080015ec(void)

{
  return;
}



// ==== 080015ee  FUN_080015ee  (2 bytes, 1 xrefs)

void FUN_080015ee(void)

{
  return;
}



// ==== 080015f0  FUN_080015f0  (2 bytes, 1 xrefs)

void FUN_080015f0(void)

{
  return;
}



// ==== 080015f4  FUN_080015f4  (32 bytes, 3 xrefs)

void FUN_080015f4(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = (undefined4 *)*DAT_08001614; puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if ((code *)puVar1[4] != (code *)0x0) {
      (*(code *)puVar1[4])(param_1,param_2);
    }
  }
  return;
}



// ==== 08001618  FUN_08001618  (98 bytes, 1 xrefs)

undefined4 FUN_08001618(byte *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar2 = (undefined4 *)*DAT_0800167c;
  if ((*param_1 & 3) == 1) {
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      if ((puVar2[1] != 0) && (*(byte *)(puVar2 + 7) == param_1[4])) {
        UNRECOVERED_JUMPTABLE = (code *)puVar2[1];
        goto LAB_08001668;
      }
    }
  }
  else if ((*param_1 & 3) == 2) {
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      if ((puVar2[2] != 0) && (*(byte *)(puVar2 + 7) == param_1[5])) {
        UNRECOVERED_JUMPTABLE = (code *)puVar2[2];
LAB_08001668:
                    /* WARNING: Could not recover jumptable at 0x0800166a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*UNRECOVERED_JUMPTABLE)();
        return uVar1;
      }
    }
  }
  return 0xffffffff;
}



// ==== 08001680  FUN_08001680  (16 bytes, 1 xrefs)

void FUN_08001680(void)

{
  FUN_08001850(2,DAT_08001690,0x200);
  return;
}



// ==== 08001694  FUN_08001694  (12 bytes, 1 xrefs)

void FUN_08001694(undefined4 param_1)

{
  *(undefined4 *)(DAT_080016a0 + 0x18) = param_1;
  *(undefined1 *)(DAT_080016a4 + 0x1e) = 0;
  return;
}



// ==== 080016a8  FUN_080016a8  (76 bytes, 1 xrefs)

undefined4 FUN_080016a8(uint param_1)

{
  undefined1 uVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar2 = PTR_USBD_080016f4;
  uVar1 = PTR_USBD_080016f4[0xe];
  uVar3 = param_1 & 0x7f;
  PTR_USBD_080016f4[0xe] = (char)uVar3;
  if ((int)(param_1 * 0x1000000) < 0) {
    if (uVar3 != 0) {
      puVar2[0x15] = puVar2[0x15] & 0xcf;
      puVar2[0x15] = puVar2[0x15] | 0x40;
      goto LAB_080016e6;
    }
  }
  else if (uVar3 != 0) {
    puVar2[0x19] = puVar2[0x19] & 0x9f;
    puVar2[0x19] = puVar2[0x19] | 0x80;
    goto LAB_080016e6;
  }
  puVar2[0x10] = puVar2[0x10] & 0xfb;
LAB_080016e6:
  puVar2[0xe] = uVar1;
  return 0;
}



// ==== 080016f8  FUN_080016f8  (4 bytes, 1 xrefs)

undefined4 FUN_080016f8(void)

{
  return 0;
}



// ==== 080016fc  FUN_080016fc  (48 bytes, 1 xrefs)

undefined4 FUN_080016fc(uint param_1,byte *param_2)

{
  undefined1 uVar1;
  undefined *puVar2;
  byte bVar3;
  uint uVar4;
  
  puVar2 = PTR_USBD_0800172c;
  uVar1 = PTR_USBD_0800172c[0xe];
  uVar4 = param_1 & 0x7f;
  PTR_USBD_0800172c[0xe] = (char)uVar4;
  bVar3 = 0;
  if ((int)(param_1 * 0x1000000) < 0) {
    if (uVar4 == 0) goto LAB_08001724;
    bVar3 = (byte)(((uint)(byte)puVar2[0x15] << 0x1b) >> 0x18);
  }
  else {
    if (uVar4 == 0) goto LAB_08001724;
    bVar3 = (byte)(((uint)(byte)puVar2[0x19] << 0x1a) >> 0x18);
  }
  bVar3 = bVar3 >> 7;
LAB_08001724:
  *param_2 = bVar3;
  puVar2[0xe] = uVar1;
  return 0;
}



// ==== 08001730  FUN_08001730  (204 bytes, 3 xrefs)

longlong FUN_08001730(byte *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  uint local_20;
  uint local_1c;
  undefined4 uStack_18;
  
  puVar2 = PTR_USBD_08001800;
  iVar1 = DAT_080017fc;
  local_20 = param_2 & 0xffff0000;
  uVar4 = *param_1 & 0x7f;
  bVar6 = 0;
  if ((*param_1 & 0x7f) == 0) {
    *(undefined2 *)(DAT_080017fc + 200) = 0x40;
    *(undefined1 *)(iVar1 + 0xca) = 0;
    *(undefined1 *)(iVar1 + 0xcc) = 1;
    *(undefined2 *)(iVar1 + 0x28) = 0x40;
    *(undefined1 *)(iVar1 + 0x2a) = 0;
    *(undefined1 *)(iVar1 + 0x2c) = 1;
  }
  else {
    if (7 < uVar4) {
      return CONCAT44(local_20,0xffffffff);
    }
    local_1c = (uint)(byte)PTR_USBD_08001800[0xe];
    PTR_USBD_08001800[0xe] = (char)uVar4;
    uStack_18 = param_4;
    if ((int)((uint)*param_1 << 0x18) < 0) {
      iVar5 = uVar4 * 0x14 + iVar1;
      *(undefined2 *)(iVar5 + 0x28) = *(undefined2 *)(param_1 + 2);
      *(byte *)(iVar5 + 0x2a) = param_1[1];
      *(undefined1 *)(iVar5 + 0x2c) = 1;
      puVar2[10] = puVar2[10] | (byte)(1 << uVar4);
      if (param_1[1] == 1) {
        bVar6 = 0x40;
      }
      puVar2[0x14] = bVar6 | 0x20;
      if ((int)((uint)(byte)puVar2[0x15] << 0x1e) < 0) {
        uVar3 = 0x48;
      }
      else {
        uVar3 = 0x40;
      }
      puVar2[0x15] = uVar3;
      uVar3 = FUN_08001468(*(undefined2 *)(param_1 + 2),&local_20);
      puVar2[0x16] = uVar3;
    }
    else {
      iVar5 = uVar4 * 0x14 + iVar1;
      *(undefined2 *)(iVar5 + 200) = *(undefined2 *)(param_1 + 2);
      *(byte *)(iVar5 + 0xca) = param_1[1];
      *(undefined1 *)(iVar5 + 0xcc) = 1;
      if (param_1[1] == 1) {
        bVar6 = 0x40;
      }
      puVar2[0x18] = bVar6;
      if ((puVar2[0x19] & 1) == 0) {
        uVar3 = 0x80;
      }
      else {
        uVar3 = 0x90;
      }
      puVar2[0x19] = uVar3;
      uVar3 = FUN_08001468(*(undefined2 *)(param_1 + 2),&local_20);
      puVar2[0x1a] = uVar3;
    }
    *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + (local_20 & 0xffff);
    puVar2[0xe] = (char)local_1c;
  }
  return (ulonglong)local_20 << 0x20;
}



// ==== 08001804  FUN_08001804  (66 bytes, 3 xrefs)

undefined4 FUN_08001804(uint param_1)

{
  undefined1 uVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar2 = PTR_USBD_08001848;
  uVar1 = PTR_USBD_08001848[0xe];
  uVar3 = param_1 & 0x7f;
  PTR_USBD_08001848[0xe] = (char)uVar3;
  if ((int)(param_1 * 0x1000000) < 0) {
    if (uVar3 != 0) {
      puVar2[0x15] = puVar2[0x15] | 0x10;
      goto LAB_08001836;
    }
  }
  else if (uVar3 != 0) {
    puVar2[0x19] = puVar2[0x19] | 0x20;
    goto LAB_08001836;
  }
  *DAT_0800184c = 7;
  puVar2[0x10] = puVar2[0x10] | 0x60;
LAB_08001836:
  puVar2[0xe] = uVar1;
  return 0;
}



// ==== 08001850  FUN_08001850  (96 bytes, 5 xrefs)

undefined4 FUN_08001850(uint param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_USBD_080018b4;
  param_1 = param_1 & 0x7f;
  if ((param_2 == 0) && (param_3 != 0)) {
    return 0xffffffff;
  }
  iVar3 = param_1 * 0x14 + DAT_080018b0;
  if (*(char *)(iVar3 + 0xcc) == '\0') {
    return 0xfffffffe;
  }
  uVar1 = PTR_USBD_080018b4[0xe];
  PTR_USBD_080018b4[0xe] = (char)param_1;
  *(int *)(iVar3 + 0xd4) = param_3;
  *(int *)(iVar3 + 0xd0) = param_2;
  *(undefined4 *)(iVar3 + 0xd8) = 0;
  if (param_3 == 0) {
    if (param_1 == 0) {
      *DAT_080018b8 = 0;
    }
  }
  else if (param_1 == 0) {
    *DAT_080018b8 = 3;
  }
  else {
    puVar2[9] = puVar2[9] | (byte)(1 << param_1);
  }
  puVar2[0xe] = uVar1;
  return 0;
}



// ==== 080018bc  FUN_080018bc  (160 bytes, 5 xrefs)

undefined4 FUN_080018bc(uint param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined1 uVar5;
  int iVar6;
  char cVar7;
  
  puVar3 = PTR_USBD_08001960;
  iVar2 = DAT_0800195c;
  param_1 = param_1 & 0x7f;
  if ((param_2 == 0) && (param_3 != 0)) {
    return 0xffffffff;
  }
  iVar6 = param_1 * 0x14 + DAT_0800195c;
  if (*(char *)(iVar6 + 0x2c) == '\0') {
    return 0xfffffffe;
  }
  uVar1 = PTR_USBD_08001960[0xe];
  PTR_USBD_08001960[0xe] = (char)param_1;
  if ((puVar3[0x15] & 1) != 0) {
    puVar3[0xe] = uVar1;
    return 0xfffffffd;
  }
  *(undefined4 *)(iVar6 + 0x38) = 0;
  *(uint *)(iVar6 + 0x34) = param_3;
  *(int *)(iVar6 + 0x30) = param_2;
  pcVar4 = DAT_08001964;
  if (param_3 == 0) {
    if (param_1 == 0) {
      if (*(short *)(iVar2 + 0x26) == 0) {
        cVar7 = '\x04';
      }
      else {
        cVar7 = '\x06';
      }
      *DAT_08001964 = cVar7;
      if (*pcVar4 == '\x01') goto LAB_08001954;
LAB_08001958:
      uVar5 = 2;
      goto LAB_0800193e;
    }
  }
  else {
    if (*(ushort *)(iVar6 + 0x28) <= param_3) {
      param_3 = (uint)*(ushort *)(iVar6 + 0x28);
    }
    FUN_080014a8(param_1,param_2,param_3 & 0xffff,iVar2,param_4);
    if (param_1 == 0) {
      *DAT_08001964 = '\x01';
      if (*(ushort *)(DAT_0800195c + 0x28) <= param_3) goto LAB_08001958;
LAB_08001954:
      uVar5 = 10;
LAB_0800193e:
      puVar3[0x10] = uVar5;
      goto LAB_08001940;
    }
  }
  puVar3[0x15] = 1;
LAB_08001940:
  puVar3[0xe] = uVar1;
  return 0;
}



// ==== 08001968  FUN_08001968  (150 bytes, 1 xrefs)

void FUN_08001968(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar1 = DAT_08001a00;
  FUN_0800011c(DAT_08001a00,param_1,8,param_4,param_4);
  pbVar2 = DAT_08001a00;
  uVar4 = (uint)*(ushort *)(pbVar1 + 6);
  if ((0x100 < uVar4) && (-1 < (int)((uint)*pbVar1 << 0x18))) {
LAB_080019f6:
    FUN_08001804(0x80);
    return;
  }
  pbVar5 = DAT_08001a00 + 0x1c;
  *(uint *)(DAT_08001a00 + 0xc) = uVar4;
  *(byte **)(pbVar2 + 8) = pbVar5;
  *(uint *)(pbVar2 + 0x10) = uVar4;
  pbVar2[0x14] = 0;
  if ((uVar4 == 0) || ((int)((uint)*pbVar1 << 0x18) < 0)) {
    iVar3 = FUN_08001c2a(pbVar1,DAT_08001a00 + 8);
    if (iVar3 == 0) goto LAB_080019f6;
    uVar4 = *(uint *)(pbVar2 + 0x10);
    if ((uint)*(ushort *)(pbVar1 + 6) <= *(uint *)(pbVar2 + 0x10)) {
      uVar4 = (uint)*(ushort *)(pbVar1 + 6);
    }
    *(uint *)(pbVar2 + 0xc) = uVar4;
    if ((*(uint *)(pbVar2 + 8) & 3) != 0) {
      if (0x100 < uVar4) {
        return;
      }
      FUN_0800011c(pbVar5);
      *(byte **)(pbVar2 + 8) = pbVar5;
    }
    FUN_080018bc(0x80,*(undefined4 *)(pbVar2 + 8),*(undefined4 *)(pbVar2 + 0xc));
    if ((*(uint *)(pbVar2 + 0x10) < (uint)*(ushort *)(pbVar1 + 6)) &&
       ((*(uint *)(pbVar2 + 0x10) & 0x3f) == 0)) {
      pbVar2[0x14] = 1;
      return;
    }
  }
  else {
    FUN_08001850(0,pbVar5);
  }
  return;
}



// ==== 08001a04  FUN_08001a04  (94 bytes, 1 xrefs)

void FUN_08001a04(uint param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = DAT_08001a64;
  if (param_1 != 0x80) {
    if (*(code **)(DAT_08001a64 + (param_1 & 0x7f) * 4 + 0x11c) != (code *)0x0) {
      (**(code **)(DAT_08001a64 + (param_1 & 0x7f) * 4 + 0x11c))();
    }
    return;
  }
  iVar2 = *(int *)(DAT_08001a64 + 8) + param_2;
  *(int *)(DAT_08001a64 + 8) = iVar2;
  param_2 = *(int *)(pcVar1 + 0xc) - param_2;
  *(int *)(pcVar1 + 0xc) = param_2;
  if (param_2 == 0) {
    if (pcVar1[0x14] != '\x01') {
      if (*(short *)(pcVar1 + 6) == 0) {
        return;
      }
      if (*pcVar1 < '\0') {
        FUN_08001850(0,0);
        return;
      }
      return;
    }
    pcVar1[0x14] = '\0';
    param_2 = 0;
    iVar2 = 0;
  }
  FUN_080018bc(0x80,iVar2,param_2);
  return;
}



// ==== 08001a68  FUN_08001a68  (98 bytes, 1 xrefs)

void FUN_08001a68(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  
  iVar2 = DAT_08001acc;
  if (param_1 == 0) {
    if (param_2 != 0) {
      iVar4 = *(int *)(DAT_08001acc + 8) + param_2;
      *(int *)(DAT_08001acc + 8) = iVar4;
      param_2 = *(int *)(iVar2 + 0xc) - param_2;
      *(int *)(iVar2 + 0xc) = param_2;
      iVar1 = DAT_08001acc;
      if (param_2 != 0) {
        FUN_08001850(0,iVar4);
        return;
      }
      *(int *)(iVar2 + 8) = DAT_08001acc + 0x1c;
      iVar2 = FUN_08001c2a(iVar2,iVar1 + 8,iVar1 + 0x10);
      if (iVar2 == 0) {
        FUN_08001804(0x80);
        return;
      }
      FUN_080018bc(0x80,0);
      return;
    }
  }
  else {
    pcVar3 = *(code **)((param_1 & 0x7f) * 4 + DAT_08001acc + 0x13c);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)();
    }
  }
  return;
}



// ==== 08001ad0  FUN_08001ad0  (54 bytes, 1 xrefs)

void FUN_08001ad0(void)

{
  int iVar1;
  uint in_r3;
  uint local_10;
  
  local_10 = in_r3;
  FUN_08001bdc(0);
  iVar1 = DAT_08001b08;
  *(undefined1 *)(DAT_08001b08 + 0x1c) = 0;
  *(undefined1 *)(iVar1 + 0x1d) = 0;
  local_10 = 0x400080;
  FUN_08001730(&local_10);
  local_10 = local_10 & 0xffffff00;
  FUN_08001730(&local_10);
  FUN_080015f4(1,0);
  return;
}



// ==== 08001b0c  FUN_08001b0c  (140 bytes, 0 xrefs)

undefined4 FUN_08001b0c(uint param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 *puVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = param_1 >> 8;
  if (uVar3 == 3) {
    if ((param_1 & 0xff) == 0xee) {
      puVar1 = *(undefined4 **)(DAT_08001b98 + 4);
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      *param_2 = *puVar1;
      uVar3 = (uint)*(byte *)(puVar1 + 1);
      goto LAB_08001b5a;
    }
  }
  else {
    if (uVar3 == 0xf) {
      puVar1 = *(undefined4 **)(DAT_08001b98 + 0xc);
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      *param_2 = *puVar1;
      uVar3 = puVar1[1];
LAB_08001b5a:
      *param_3 = uVar3;
      return 1;
    }
    if (((uVar3 == 4) || (uVar3 == 5)) || (5 < uVar3)) {
      return 0;
    }
  }
  pbVar2 = *(byte **)(DAT_08001b9c + 0x18);
  do {
    if (*pbVar2 == 0) {
      return 0;
    }
    if (pbVar2[1] == uVar3) {
      if (uVar4 == (param_1 & 0xff)) {
        *param_2 = pbVar2;
        if ((uVar3 == 2) || (uVar3 == 7)) {
          uVar3 = (uint)*(ushort *)(pbVar2 + 2);
        }
        else {
          uVar3 = (uint)*pbVar2;
        }
        *param_3 = uVar3;
        return 1;
      }
      uVar4 = uVar4 + 1;
    }
    pbVar2 = pbVar2 + *pbVar2;
  } while( true );
}



// ==== 08001ba0  FUN_08001ba0  (8 bytes, 1 xrefs)

void FUN_08001ba0(void)

{
  FUN_080014c8();
  return;
}



// ==== 08001ba8  FUN_08001ba8  (50 bytes, 2 xrefs)

undefined4 FUN_08001ba8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_080016f8(*(undefined1 *)(param_1 + 2));
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}



// ==== 08001bdc  FUN_08001bdc  (18 bytes, 1 xrefs)

undefined4 FUN_08001bdc(int param_1)

{
  if (param_1 == 0) {
    *PTR_USBD_08001bf0 = 0;
  }
  *DAT_08001bf4 = (char)param_1;
  return 0;
}



// ==== 08001bf8  FUN_08001bf8  (50 bytes, 2 xrefs)

undefined4 FUN_08001bf8(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  local_8._0_2_ = (ushort)*(byte *)(param_1 + 2);
  local_8 = CONCAT22(*(undefined2 *)(param_1 + 4),(ushort)local_8) & 0x7ffffff;
  local_8 = CONCAT22(local_8._2_2_,CONCAT11(*(undefined1 *)(param_1 + 3),(undefined1)local_8)) &
            0xffff03ff;
  iVar1 = FUN_08001730(&local_8);
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}



// ==== 08001c2a  FUN_08001c2a  (82 bytes, 2 xrefs)

undefined4 FUN_08001c2a(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_1;
  if ((bVar1 & 0x60) == 0) {
    if ((bVar1 & 3) == 0) {
      iVar2 = FUN_08001c7c();
    }
    else if ((bVar1 & 3) == 1) {
      iVar2 = FUN_08001de0();
    }
    else {
      if ((bVar1 & 3) != 2) {
        return 0;
      }
      iVar2 = FUN_08001d60();
    }
    if (iVar2 != 0) {
      return 1;
    }
  }
  else {
    if ((bVar1 & 0x60) == 0x20) {
      iVar2 = FUN_08001618();
    }
    else {
      if ((bVar1 & 0x60) != 0x40) {
        return 0;
      }
      iVar2 = switchD_08001e0c::caseD_68();
    }
    if (-1 < iVar2) {
      return 1;
    }
  }
  return 0;
}



// ==== 08001c7c  FUN_08001c7c  (28 bytes, 1 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    Instruction at (ram,0x08001d18) overlaps instruction at (ram,0x08001d16)


// ==== 08001d60  FUN_08001d60  (126 bytes, 1 xrefs)

undefined4 FUN_08001d60(int param_1,int *param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_24 [4];
  int iStack_20;
  int *local_1c;
  undefined4 *puStack_18;
  
  uVar1 = *(undefined1 *)(param_1 + 4);
  uVar4 = 1;
  iStack_20 = param_1;
  local_1c = param_2;
  puStack_18 = param_3;
  iVar3 = FUN_08001318();
  if (iVar3 == 0) {
    return 0;
  }
  cVar2 = *(char *)(param_1 + 1);
  if (cVar2 == '\0') {
    FUN_080016fc(uVar1,local_24);
    *(undefined1 *)*local_1c = local_24[0];
    *(undefined1 *)(*local_1c + 1) = 0;
    *param_3 = 2;
    return 1;
  }
  if (cVar2 == '\x01') {
    if (*(short *)(param_1 + 2) == 0) {
      FUN_080016a8(uVar1);
      return 1;
    }
  }
  else {
    if (cVar2 != '\x03') {
      return 0;
    }
    if (*(short *)(param_1 + 2) == 0) {
      FUN_08001804(uVar1);
      goto LAB_08001dda;
    }
  }
  uVar4 = 0;
LAB_08001dda:
  *param_3 = 0;
  return uVar4;
}



// ==== 08001de0  FUN_08001de0  (528 bytes, 1 xrefs)

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x08001e0c) */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x08001eba) overlaps instruction at (ram,0x08001eb8)
    */
/* WARNING: Removing unreachable block (ram,0x08001e0c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_08001de0(code *param_1,code *param_2,code *param_3)

{
  code cVar1;
  code cVar2;
  code *pcVar3;
  code *pcVar4;
  code *pcVar5;
  code *extraout_r2;
  code *pcVar6;
  code *pcVar7;
  code *pcVar8;
  bool bVar9;
  undefined4 in_cr1;
  undefined4 in_cr9;
  undefined4 in_cr14;
  undefined8 extraout_d7;
  undefined8 unaff_d14;
  undefined8 in_d16;
  undefined8 uVar10;
  code *local_30;
  code *local_2c;
  code *local_28;
  
  pcVar3 = (code *)(uint)(byte)param_1[3];
  pcVar8 = (code *)(uint)(byte)param_1[4];
  local_30 = (code *)0x1;
  uVar10 = FUN_08001318();
  pcVar5 = (code *)((ulonglong)uVar10 >> 0x20);
  pcVar4 = (code *)0x0;
  if ((int)uVar10 == 0) goto switchD_08001e0c_caseD_1b;
  cVar2 = param_1[1];
  pcVar4 = (code *)(uint)(byte)cVar2;
  bVar9 = pcVar4 == (code *)0x0;
  if (pcVar4 < &HardFault) {
    cVar1 = pcVar4[0x8001e11];
  }
  else {
    cVar1 = (code)0x20;
  }
  pcVar7 = (code *)((uint)(byte)cVar1 * 2);
  pcVar6 = extraout_r2;
  switch(cVar1) {
  case (code)0x0:
  case (code)0x1:
switchD_08001e0c_caseD_2:
switchD_08001e0c_caseD_3:
switchD_08001e0c_caseD_4:
switchD_08001e0c_caseD_5:
switchD_08001e0c_caseD_6:
switchD_08001e0c_caseD_7:
    pcVar5 = *(code **)param_2;
switchD_08001e0c_caseD_8:
    cVar2 = (code)0x0;
switchD_08001e0c_caseD_9:
    *pcVar5 = cVar2;
switchD_08001e0c_caseD_a:
    pcVar5 = *(code **)param_2;
switchD_08001e0c_caseD_b:
    pcVar5[1] = cVar2;
switchD_08001e0c_caseD_c:
    pcVar5 = (code *)0x2;
switchD_08001e0c_caseD_d:
switchD_08001e0c_caseD_27:
    pcVar4 = param_3;
switchD_08001e0c_caseD_28:
    *(code **)pcVar4 = pcVar5;
switchD_08001e0c_caseD_29:
switchD_08001e0c_caseD_62:
    pcVar4 = local_30;
switchD_08001e0c_caseD_63:
    break;
  case (code)0x2:
    goto switchD_08001e0c_caseD_2;
  case (code)0x3:
    goto switchD_08001e0c_caseD_3;
  case (code)0x4:
    goto switchD_08001e0c_caseD_4;
  case (code)0x5:
    goto switchD_08001e0c_caseD_5;
  case (code)0x6:
    goto switchD_08001e0c_caseD_6;
  case (code)0x7:
    goto switchD_08001e0c_caseD_7;
  case (code)0x8:
    goto switchD_08001e0c_caseD_8;
  case (code)0x9:
    goto switchD_08001e0c_caseD_9;
  case (code)0xa:
    goto switchD_08001e0c_caseD_a;
  case (code)0xb:
    goto switchD_08001e0c_caseD_b;
  case (code)0xc:
    goto switchD_08001e0c_caseD_c;
  case (code)0xd:
    goto switchD_08001e0c_caseD_d;
  case (code)0xe:
    bVar9 = pcVar3 == (code *)0x22;
  case (code)0xf:
    if (!bVar9) {
switchD_08001e0c_caseD_20:
      pcVar4 = (code *)0x0;
switchD_08001e0c_caseD_21:
      local_30 = pcVar4;
switchD_08001e0c_caseD_22:
      goto switchD_08001e0c_caseD_62;
    }
switchD_08001e0c_caseD_10:
    pcVar4 = (code *)&DAT_2000002c;
switchD_08001e0c_caseD_11:
switchD_08001e0c_caseD_1d:
    do {
      pcVar4 = *(code **)pcVar4;
switchD_08001e0c_caseD_1e:
      bVar9 = pcVar4 == (code *)0x0;
switchD_08001e0c_caseD_1f:
      if (bVar9) goto switchD_08001e0c_caseD_20;
switchD_08001e0c_caseD_12:
      pcVar5 = (code *)(uint)(byte)pcVar4[0x1c];
switchD_08001e0c_caseD_13:
      bVar9 = pcVar5 == pcVar8;
switchD_08001e0c_caseD_14:
    } while (!bVar9);
switchD_08001e0c_caseD_15:
    pcVar5 = *(code **)(pcVar4 + 0x14);
switchD_08001e0c_caseD_16:
    *(code **)param_2 = pcVar5;
switchD_08001e0c_caseD_17:
    pcVar5 = *(code **)(pcVar4 + 0x18);
switchD_08001e0c_caseD_18:
    pcVar4 = param_3;
switchD_08001e0c_caseD_19:
    *(code **)pcVar4 = pcVar5;
switchD_08001e0c_caseD_1a:
    pcVar4 = (code *)0x1;
    break;
  case (code)0x10:
    goto switchD_08001e0c_caseD_10;
  case (code)0x11:
    goto switchD_08001e0c_caseD_11;
  case (code)0x12:
    goto switchD_08001e0c_caseD_12;
  case (code)0x13:
    goto switchD_08001e0c_caseD_13;
  case (code)0x14:
    goto switchD_08001e0c_caseD_14;
  case (code)0x15:
    goto switchD_08001e0c_caseD_15;
  case (code)0x16:
    goto switchD_08001e0c_caseD_16;
  case (code)0x17:
    goto switchD_08001e0c_caseD_17;
  case (code)0x18:
    goto switchD_08001e0c_caseD_18;
  case (code)0x19:
    goto switchD_08001e0c_caseD_19;
  case (code)0x1a:
    goto switchD_08001e0c_caseD_1a;
  case (code)0x1b:
    break;
  case (code)0x1c:
    goto switchD_08001e0c_caseD_1c;
  case (code)0x1d:
    goto switchD_08001e0c_caseD_1d;
  case (code)0x1e:
    goto switchD_08001e0c_caseD_1e;
  case (code)0x1f:
    goto switchD_08001e0c_caseD_1f;
  case (code)0x20:
    goto switchD_08001e0c_caseD_20;
  case (code)0x21:
    goto switchD_08001e0c_caseD_21;
  case (code)0x22:
    goto switchD_08001e0c_caseD_22;
  case (code)0x23:
    pcVar5 = *(code **)param_2;
  case (code)0x24:
    cVar2 = (code)0x0;
switchD_08001e0c_caseD_25:
    *pcVar5 = cVar2;
switchD_08001e0c_caseD_26:
    pcVar5 = (code *)0x1;
    goto switchD_08001e0c_caseD_27;
  case (code)0x25:
    goto switchD_08001e0c_caseD_25;
  case (code)0x26:
    goto switchD_08001e0c_caseD_26;
  case (code)0x27:
    goto switchD_08001e0c_caseD_27;
  case (code)0x28:
    goto switchD_08001e0c_caseD_28;
  case (code)0x29:
    goto switchD_08001e0c_caseD_29;
  case (code)0x2a:
  case (code)0x2b:
    pcVar5 = (code *)(uint)(byte)param_1[4];
switchD_08001e0c_caseD_2c:
    cVar2 = (code)0x0;
switchD_08001e0c_caseD_2d:
    cVar2 = (code)((byte)cVar2 | (byte)pcVar5);
switchD_08001e0c_caseD_2e:
    pcVar4 = (code *)(uint)(byte)cVar2;
switchD_08001e0c_caseD_2f:
    local_28 = pcVar4;
switchD_08001e0c_caseD_30:
switchD_08001e0c_caseD_31:
    pcVar5 = (code *)(uint)(byte)param_1[2];
switchD_08001e0c_caseD_32:
    cVar2 = (code)0x0;
switchD_08001e0c_caseD_33:
    cVar2 = (code)((byte)cVar2 | (byte)pcVar5);
switchD_08001e0c_caseD_34:
    pcVar3 = (code *)(uint)(byte)cVar2;
switchD_08001e0c_caseD_35:
    pcVar4 = (code *)&DAT_20000040;
switchD_08001e0c_caseD_36:
    param_1 = *(code **)(pcVar4 + 0x18);
switchD_08001e0c_caseD_37:
    pcVar4 = (code *)0x0;
switchD_08001e0c_caseD_38:
    pcVar8 = (code *)0xff;
switchD_08001e0c_caseD_39:
    param_2 = pcVar8;
    pcVar8 = param_2;
switchD_08001e0c_caseD_3a:
    local_2c = pcVar4;
switchD_08001e0c_caseD_3b:
switchD_08001e0c_caseD_58:
    while( true ) {
      pcVar4 = (code *)(uint)(byte)*param_1;
switchD_08001e0c_caseD_59:
      bVar9 = pcVar4 == (code *)0x0;
switchD_08001e0c_caseD_5a:
      if (bVar9) break;
switchD_08001e0c_caseD_3c:
      pcVar4 = (code *)(uint)(byte)param_1[1];
switchD_08001e0c_caseD_3d:
      bVar9 = pcVar4 == (code *)&Reset;
switchD_08001e0c_caseD_3e:
      if (bVar9) {
switchD_08001e0c_caseD_42:
        param_2 = (code *)(uint)(byte)param_1[2];
switchD_08001e0c_caseD_43:
        pcVar4 = local_28;
switchD_08001e0c_caseD_44:
        pcVar8 = (code *)(uint)(byte)param_1[3];
switchD_08001e0c_caseD_45:
        bVar9 = param_2 == pcVar4;
switchD_08001e0c_caseD_46:
        if (bVar9) {
switchD_08001e0c_caseD_47:
          bVar9 = pcVar8 == pcVar3;
switchD_08001e0c_caseD_48:
          if (bVar9) {
switchD_08001e0c_caseD_49:
            local_2c = param_1;
switchD_08001e0c_caseD_4a:
          }
        }
      }
      else {
switchD_08001e0c_caseD_3f:
        bVar9 = pcVar4 == (code *)0x5;
switchD_08001e0c_caseD_40:
        if (bVar9) {
switchD_08001e0c_caseD_41:
switchD_08001e0c_caseD_4b:
          pcVar4 = local_28;
switchD_08001e0c_caseD_4c:
          bVar9 = param_2 == pcVar4;
switchD_08001e0c_caseD_4d:
          if (bVar9) {
switchD_08001e0c_caseD_4e:
            pcVar4 = param_1;
            param_1 = pcVar4;
switchD_08001e0c_caseD_4f:
            bVar9 = pcVar8 == pcVar3;
switchD_08001e0c_caseD_50:
            if (bVar9) {
switchD_08001e0c_caseD_54:
              FUN_08001bf8(pcVar4);
            }
            else {
switchD_08001e0c_caseD_51:
              FUN_08001ba8();
switchD_08001e0c_caseD_53:
            }
          }
        }
      }
switchD_08001e0c_caseD_56:
      pcVar4 = (code *)(uint)(byte)*param_1;
switchD_08001e0c_caseD_57:
      param_1 = pcVar4 + (int)param_1;
    }
switchD_08001e0c_caseD_5b:
    pcVar4 = (code *)&NMI;
switchD_08001e0c_caseD_5c:
    pcVar5 = local_2c;
switchD_08001e0c_caseD_5d:
    FUN_080015f4(pcVar4,pcVar5);
switchD_08001e0c_caseD_5f:
    pcVar5 = param_3;
switchD_08001e0c_caseD_60:
    pcVar4 = (code *)0x0;
switchD_08001e0c_caseD_61:
    *(code **)pcVar5 = pcVar4;
    goto switchD_08001e0c_caseD_62;
  case (code)0x2c:
    goto switchD_08001e0c_caseD_2c;
  case (code)0x2d:
    goto switchD_08001e0c_caseD_2d;
  case (code)0x2e:
    goto switchD_08001e0c_caseD_2e;
  case (code)0x2f:
    goto switchD_08001e0c_caseD_2f;
  case (code)0x30:
    goto switchD_08001e0c_caseD_30;
  case (code)0x31:
    goto switchD_08001e0c_caseD_31;
  case (code)0x32:
    goto switchD_08001e0c_caseD_32;
  case (code)0x33:
    goto switchD_08001e0c_caseD_33;
  case (code)0x34:
    goto switchD_08001e0c_caseD_34;
  case (code)0x35:
    goto switchD_08001e0c_caseD_35;
  case (code)0x36:
    goto switchD_08001e0c_caseD_36;
  case (code)0x37:
    goto switchD_08001e0c_caseD_37;
  case (code)0x38:
    goto switchD_08001e0c_caseD_38;
  case (code)0x39:
    goto switchD_08001e0c_caseD_39;
  case (code)0x3a:
    goto switchD_08001e0c_caseD_3a;
  case (code)0x3b:
    goto switchD_08001e0c_caseD_3b;
  case (code)0x3c:
    goto switchD_08001e0c_caseD_3c;
  case (code)0x3d:
    goto switchD_08001e0c_caseD_3d;
  case (code)0x3e:
    goto switchD_08001e0c_caseD_3e;
  case (code)0x3f:
    goto switchD_08001e0c_caseD_3f;
  case (code)0x40:
    goto switchD_08001e0c_caseD_40;
  case (code)0x41:
    goto switchD_08001e0c_caseD_41;
  case (code)0x42:
    goto switchD_08001e0c_caseD_42;
  case (code)0x43:
    goto switchD_08001e0c_caseD_43;
  case (code)0x44:
    goto switchD_08001e0c_caseD_44;
  case (code)0x45:
    goto switchD_08001e0c_caseD_45;
  case (code)0x46:
    goto switchD_08001e0c_caseD_46;
  case (code)0x47:
    goto switchD_08001e0c_caseD_47;
  case (code)0x48:
    goto switchD_08001e0c_caseD_48;
  case (code)0x49:
    goto switchD_08001e0c_caseD_49;
  case (code)0x4a:
    goto switchD_08001e0c_caseD_4a;
  case (code)0x4b:
    goto switchD_08001e0c_caseD_4b;
  case (code)0x4c:
    goto switchD_08001e0c_caseD_4c;
  case (code)0x4d:
    goto switchD_08001e0c_caseD_4d;
  case (code)0x4e:
    goto switchD_08001e0c_caseD_4e;
  case (code)0x4f:
    goto switchD_08001e0c_caseD_4f;
  case (code)0x50:
    goto switchD_08001e0c_caseD_50;
  case (code)0x51:
    goto switchD_08001e0c_caseD_51;
  case (code)0x52:
    coprocessor_function2(0,7,0,in_cr14,in_cr9,in_cr1);
    goto switchD_08001e0c_caseD_54;
  case (code)0x53:
    goto switchD_08001e0c_caseD_53;
  case (code)0x54:
    goto switchD_08001e0c_caseD_54;
  case (code)0x55:
    VectorComplexMultiplyAccumulateByElement(extraout_d7,unaff_d14,in_d16,0x5a,4);
    goto switchD_08001e0c_caseD_57;
  case (code)0x56:
    goto switchD_08001e0c_caseD_56;
  case (code)0x57:
    goto switchD_08001e0c_caseD_57;
  case (code)0x58:
    goto switchD_08001e0c_caseD_58;
  case (code)0x59:
    goto switchD_08001e0c_caseD_59;
  case (code)0x5a:
    goto switchD_08001e0c_caseD_5a;
  case (code)0x5b:
    goto switchD_08001e0c_caseD_5b;
  case (code)0x5c:
    goto switchD_08001e0c_caseD_5c;
  case (code)0x5d:
    goto switchD_08001e0c_caseD_5d;
  case (code)0x5e:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (code)0x5f:
    goto switchD_08001e0c_caseD_5f;
  case (code)0x60:
    goto switchD_08001e0c_caseD_60;
  case (code)0x61:
    goto switchD_08001e0c_caseD_61;
  case (code)0x62:
    goto switchD_08001e0c_caseD_62;
  case (code)0x63:
    goto switchD_08001e0c_caseD_63;
  case (code)0x64:
  case (code)0x65:
switchD_08001e0c_caseD_66:
switchD_08001e0c_caseD_67:
    pcVar4 = (code *)0x0;
switchD_08001e0c_caseD_68:
switchD_08001e0c_caseD_69:
    pcVar3 = pcVar5;
switchD_08001e0c_caseD_6a:
    pcVar5 = (code *)&DAT_2000002c;
switchD_08001e0c_caseD_6b:
    param_2 = pcVar4;
switchD_08001e0c_caseD_6c:
    pcVar4 = *(code **)(pcVar5 + 4);
switchD_08001e0c_caseD_6d:
    pcVar8 = extraout_r2;
switchD_08001e0c_caseD_6e:
    bVar9 = pcVar4 == (code *)0x0;
switchD_08001e0c_caseD_6f:
    if (bVar9) {
switchD_08001e0c_caseD_85:
      pcVar4 = *(code **)(pcVar5 + 8);
switchD_08001e0c_caseD_86:
      bVar9 = pcVar4 == (code *)0x0;
switchD_08001e0c_caseD_87:
      if (!bVar9) {
switchD_08001e0c_caseD_88:
        pcVar5 = (code *)(uint)(byte)param_2[1];
switchD_08001e0c_caseD_89:
        pcVar6 = (code *)(uint)(byte)pcVar4[6];
switchD_08001e0c_caseD_8a:
        bVar9 = pcVar5 == pcVar6;
switchD_08001e0c_caseD_8b:
        if (bVar9) {
switchD_08001e0c_caseD_8c:
          pcVar5 = (code *)(uint)(byte)param_2[5];
switchD_08001e0c_caseD_8d:
          pcVar6 = (code *)(uint)(byte)param_2[4];
switchD_08001e0c_caseD_8e:
          pcVar5 = (code *)((int)pcVar5 << 8);
switchD_08001e0c_caseD_8f:
          pcVar5 = (code *)((uint)pcVar5 | (uint)pcVar6);
switchD_08001e0c_caseD_90:
          bVar9 = pcVar5 == (code *)0x7;
switchD_08001e0c_caseD_91:
          if (!bVar9) goto switchD_08001e0c_caseD_a7;
switchD_08001e0c_caseD_92:
          pcVar5 = *(code **)pcVar4;
switchD_08001e0c_caseD_93:
          *(code **)pcVar3 = pcVar5;
switchD_08001e0c_caseD_94:
          pcVar4 = (code *)(uint)*(ushort *)(pcVar4 + 4);
          goto switchD_08001e0c_caseD_95;
        }
      }
switchD_08001e0c_caseD_98:
      pcVar4 = (code *)&DAT_2000002c;
switchD_08001e0c_caseD_99:
      param_1 = *(code **)pcVar4;
switchD_08001e0c_caseD_9a:
switchD_08001e0c_caseD_a5:
      while( true ) {
        bVar9 = param_1 == (code *)0x0;
switchD_08001e0c_caseD_a6:
        if (bVar9) break;
switchD_08001e0c_caseD_9b:
        pcVar7 = *(code **)(param_1 + 0xc);
switchD_08001e0c_caseD_9c:
        bVar9 = pcVar7 == (code *)0x0;
switchD_08001e0c_caseD_9d:
        if (!bVar9) {
switchD_08001e0c_caseD_9e:
switchD_08001e0c_caseD_9f:
          pcVar5 = pcVar3;
          pcVar3 = pcVar5;
switchD_08001e0c_caseD_a0:
          pcVar4 = param_2;
          param_2 = pcVar4;
switchD_08001e0c_caseD_a1:
          pcVar4 = (code *)(*pcVar7)(pcVar4,pcVar5);
switchD_08001e0c_caseD_a2:
          bVar9 = pcVar4 == (code *)0x0;
switchD_08001e0c_caseD_a3:
          if (bVar9) {
            return pcVar4;
          }
        }
switchD_08001e0c_caseD_a4:
        param_1 = *(code **)param_1;
      }
    }
    else {
switchD_08001e0c_caseD_70:
      pcVar5 = (code *)(uint)(byte)param_2[1];
switchD_08001e0c_caseD_71:
      pcVar6 = (code *)(uint)(byte)pcVar4[5];
switchD_08001e0c_caseD_72:
      bVar9 = pcVar5 == pcVar6;
switchD_08001e0c_caseD_73:
      if (!bVar9) goto switchD_08001e0c_caseD_98;
switchD_08001e0c_caseD_74:
      pcVar5 = (code *)(uint)(byte)param_2[5];
switchD_08001e0c_caseD_75:
      pcVar6 = (code *)(uint)(byte)param_2[4];
switchD_08001e0c_caseD_76:
      pcVar5 = (code *)((int)pcVar5 << 8);
switchD_08001e0c_caseD_77:
      pcVar5 = (code *)((uint)pcVar5 | (uint)pcVar6);
switchD_08001e0c_caseD_78:
      bVar9 = pcVar5 == (code *)&Reset;
switchD_08001e0c_caseD_79:
      if (bVar9) {
switchD_08001e0c_caseD_7d:
        pcVar5 = *(code **)(pcVar4 + 8);
switchD_08001e0c_caseD_7e:
        *(code **)pcVar3 = pcVar5;
switchD_08001e0c_caseD_7f:
        pcVar4 = (code *)(uint)*(ushort *)(pcVar4 + 0xc);
switchD_08001e0c_caseD_80:
switchD_08001e0c_caseD_95:
        *(code **)pcVar8 = pcVar4;
switchD_08001e0c_caseD_96:
        pcVar4 = (code *)0x0;
switchD_08001e0c_caseD_97:
        return pcVar4;
      }
switchD_08001e0c_caseD_7a:
      bVar9 = pcVar5 == (code *)0x5;
switchD_08001e0c_caseD_7b:
      if (bVar9) {
switchD_08001e0c_caseD_7c:
switchD_08001e0c_caseD_81:
        pcVar5 = *(code **)(pcVar4 + 0x10);
switchD_08001e0c_caseD_82:
        *(code **)pcVar3 = pcVar5;
switchD_08001e0c_caseD_83:
        pcVar4 = (code *)(uint)*(ushort *)(pcVar4 + 0x14);
switchD_08001e0c_caseD_84:
        goto switchD_08001e0c_caseD_95;
      }
    }
switchD_08001e0c_caseD_a7:
    pcVar4 = (code *)0x0;
switchD_08001e0c_caseD_a8:
    pcVar4 = (code *)~(uint)pcVar4;
switchD_08001e0c_caseD_a9:
    return pcVar4;
  case (code)0x66:
    goto switchD_08001e0c_caseD_66;
  case (code)0x67:
    goto switchD_08001e0c_caseD_67;
  case (code)0x68:
    goto switchD_08001e0c_caseD_68;
  case (code)0x69:
    goto switchD_08001e0c_caseD_69;
  case (code)0x6a:
    goto switchD_08001e0c_caseD_6a;
  case (code)0x6b:
    goto switchD_08001e0c_caseD_6b;
  case (code)0x6c:
    goto switchD_08001e0c_caseD_6c;
  case (code)0x6d:
    goto switchD_08001e0c_caseD_6d;
  case (code)0x6e:
    goto switchD_08001e0c_caseD_6e;
  case (code)0x6f:
    goto switchD_08001e0c_caseD_6f;
  case (code)0x70:
    goto switchD_08001e0c_caseD_70;
  case (code)0x71:
    goto switchD_08001e0c_caseD_71;
  case (code)0x72:
    goto switchD_08001e0c_caseD_72;
  case (code)0x73:
    goto switchD_08001e0c_caseD_73;
  case (code)0x74:
    goto switchD_08001e0c_caseD_74;
  case (code)0x75:
    goto switchD_08001e0c_caseD_75;
  case (code)0x76:
    goto switchD_08001e0c_caseD_76;
  case (code)0x77:
    goto switchD_08001e0c_caseD_77;
  case (code)0x78:
    goto switchD_08001e0c_caseD_78;
  case (code)0x79:
    goto switchD_08001e0c_caseD_79;
  case (code)0x7a:
    goto switchD_08001e0c_caseD_7a;
  case (code)0x7b:
    goto switchD_08001e0c_caseD_7b;
  case (code)0x7c:
    goto switchD_08001e0c_caseD_7c;
  case (code)0x7d:
    goto switchD_08001e0c_caseD_7d;
  case (code)0x7e:
    goto switchD_08001e0c_caseD_7e;
  case (code)0x7f:
    goto switchD_08001e0c_caseD_7f;
  case (code)0x80:
    goto switchD_08001e0c_caseD_80;
  case (code)0x81:
    goto switchD_08001e0c_caseD_81;
  case (code)0x82:
    goto switchD_08001e0c_caseD_82;
  case (code)0x83:
    goto switchD_08001e0c_caseD_83;
  case (code)0x84:
    goto switchD_08001e0c_caseD_84;
  case (code)0x85:
    goto switchD_08001e0c_caseD_85;
  case (code)0x86:
    goto switchD_08001e0c_caseD_86;
  case (code)0x87:
    goto switchD_08001e0c_caseD_87;
  case (code)0x88:
    goto switchD_08001e0c_caseD_88;
  case (code)0x89:
    goto switchD_08001e0c_caseD_89;
  case (code)0x8a:
    goto switchD_08001e0c_caseD_8a;
  case (code)0x8b:
    goto switchD_08001e0c_caseD_8b;
  case (code)0x8c:
    goto switchD_08001e0c_caseD_8c;
  case (code)0x8d:
    goto switchD_08001e0c_caseD_8d;
  case (code)0x8e:
    goto switchD_08001e0c_caseD_8e;
  case (code)0x8f:
    goto switchD_08001e0c_caseD_8f;
  case (code)0x90:
    goto switchD_08001e0c_caseD_90;
  case (code)0x91:
    goto switchD_08001e0c_caseD_91;
  case (code)0x92:
    goto switchD_08001e0c_caseD_92;
  case (code)0x93:
    goto switchD_08001e0c_caseD_93;
  case (code)0x94:
    goto switchD_08001e0c_caseD_94;
  case (code)0x95:
    goto switchD_08001e0c_caseD_95;
  case (code)0x96:
    goto switchD_08001e0c_caseD_96;
  case (code)0x97:
    goto switchD_08001e0c_caseD_97;
  case (code)0x98:
    goto switchD_08001e0c_caseD_98;
  case (code)0x99:
    goto switchD_08001e0c_caseD_99;
  case (code)0x9a:
    goto switchD_08001e0c_caseD_9a;
  case (code)0x9b:
    goto switchD_08001e0c_caseD_9b;
  case (code)0x9c:
    goto switchD_08001e0c_caseD_9c;
  case (code)0x9d:
    goto switchD_08001e0c_caseD_9d;
  case (code)0x9e:
    goto switchD_08001e0c_caseD_9e;
  case (code)0x9f:
    goto switchD_08001e0c_caseD_9f;
  case (code)0xa0:
    goto switchD_08001e0c_caseD_a0;
  case (code)0xa1:
    goto switchD_08001e0c_caseD_a1;
  case (code)0xa2:
    goto switchD_08001e0c_caseD_a2;
  case (code)0xa3:
    goto switchD_08001e0c_caseD_a3;
  case (code)0xa4:
    goto switchD_08001e0c_caseD_a4;
  case (code)0xa5:
    goto switchD_08001e0c_caseD_a5;
  case (code)0xa6:
    goto switchD_08001e0c_caseD_a6;
  case (code)0xa7:
    goto switchD_08001e0c_caseD_a7;
  case (code)0xa8:
    goto switchD_08001e0c_caseD_a8;
  case (code)0xa9:
    goto switchD_08001e0c_caseD_a9;
  case (code)0xaa:
  case (code)0xab:
    pcVar4 = (code *)0x0;
switchD_08001e0c_caseD_ac:
switchD_08001e0c_caseD_ad:
switchD_08001e0c_caseD_ae:
switchD_08001e0c_caseD_af:
switchD_08001e0c_caseD_b0:
switchD_08001e0c_caseD_b1:
switchD_08001e0c_caseD_b2:
switchD_08001e0c_caseD_b3:
switchD_08001e0c_caseD_b4:
switchD_08001e0c_caseD_b5:
switchD_08001e0c_caseD_b6:
switchD_08001e0c_caseD_b7:
switchD_08001e0c_caseD_b8:
switchD_08001e0c_caseD_b9:
switchD_08001e0c_caseD_ba:
switchD_08001e0c_caseD_bb:
switchD_08001e0c_caseD_bc:
    pcVar5 = pcVar4;
switchD_08001e0c_caseD_bd:
switchD_08001e0c_caseD_be:
switchD_08001e0c_caseD_bf:
switchD_08001e0c_caseD_c0:
switchD_08001e0c_caseD_c1:
switchD_08001e0c_caseD_c2:
switchD_08001e0c_caseD_c3:
switchD_08001e0c_caseD_c4:
switchD_08001e0c_caseD_c5:
switchD_08001e0c_caseD_c6:
switchD_08001e0c_caseD_c7:
switchD_08001e0c_caseD_c8:
    pcVar4 = pcVar5;
switchD_08001e0c_caseD_c9:
switchD_08001e0c_caseD_ca:
switchD_08001e0c_caseD_cb:
switchD_08001e0c_caseD_cc:
    pcVar4 = (code *)((uint)pcVar4 >> 4);
switchD_08001e0c_caseD_cd:
switchD_08001e0c_caseD_ce:
    pcVar4 = (code *)((int)pcVar4 >> 8);
switchD_08001e0c_caseD_cf:
switchD_08001e0c_caseD_d0:
switchD_08001e0c_caseD_d1:
switchD_08001e0c_caseD_d2:
    *(short *)(pcVar4 + 0x32) = (short)pcVar4;
switchD_08001e0c_caseD_d3:
switchD_08001e0c_caseD_d4:
switchD_08001e0c_caseD_d5:
switchD_08001e0c_caseD_d6:
    pcVar4 = (code *)((uint)pcVar4 >> 4);
switchD_08001e0c_caseD_d7:
switchD_08001e0c_caseD_d8:
    pcVar4 = (code *)((uint)pcVar4 >> 4);
switchD_08001e0c_caseD_d9:
switchD_08001e0c_caseD_da:
    pcVar4 = (code *)((uint)pcVar4 >> 4);
switchD_08001e0c_caseD_db:
switchD_08001e0c_caseD_dc:
switchD_08001e0c_caseD_dd:
switchD_08001e0c_caseD_de:
switchD_08001e0c_caseD_df:
switchD_08001e0c_caseD_e0:
switchD_08001e0c_caseD_e1:
switchD_08001e0c_caseD_e2:
switchD_08001e0c_caseD_e3:
switchD_08001e0c_caseD_e4:
switchD_08001e0c_caseD_e5:
switchD_08001e0c_caseD_e6:
switchD_08001e0c_caseD_e7:
switchD_08001e0c_caseD_e8:
    pcVar7 = pcVar4;
switchD_08001e0c_caseD_e9:
switchD_08001e0c_caseD_ea:
switchD_08001e0c_caseD_eb:
switchD_08001e0c_caseD_ec:
switchD_08001e0c_caseD_ed:
switchD_08001e0c_caseD_ee:
    pcVar4 = *(code **)(pcVar7 + 0x44);
switchD_08001e0c_caseD_ef:
    pcVar4 = (code *)((int)pcVar4 << 2);
switchD_08001e0c_caseD_f0:
LAB_08001c1e:
    if (pcVar4 == (code *)0x0) {
      return (code *)0x1;
    }
    return (code *)0x0;
  case (code)0xac:
    goto switchD_08001e0c_caseD_ac;
  case (code)0xad:
    goto switchD_08001e0c_caseD_ad;
  case (code)0xae:
    goto switchD_08001e0c_caseD_ae;
  case (code)0xaf:
    goto switchD_08001e0c_caseD_af;
  case (code)0xb0:
    goto switchD_08001e0c_caseD_b0;
  case (code)0xb1:
    goto switchD_08001e0c_caseD_b1;
  case (code)0xb2:
    goto switchD_08001e0c_caseD_b2;
  case (code)0xb3:
    goto switchD_08001e0c_caseD_b3;
  case (code)0xb4:
    goto switchD_08001e0c_caseD_b4;
  case (code)0xb5:
    goto switchD_08001e0c_caseD_b5;
  case (code)0xb6:
    goto switchD_08001e0c_caseD_b6;
  case (code)0xb7:
    goto switchD_08001e0c_caseD_b7;
  case (code)0xb8:
    goto switchD_08001e0c_caseD_b8;
  case (code)0xb9:
    goto switchD_08001e0c_caseD_b9;
  case (code)0xba:
    goto switchD_08001e0c_caseD_ba;
  case (code)0xbb:
    goto switchD_08001e0c_caseD_bb;
  case (code)0xbc:
    goto switchD_08001e0c_caseD_bc;
  case (code)0xbd:
    goto switchD_08001e0c_caseD_bd;
  case (code)0xbe:
    goto switchD_08001e0c_caseD_be;
  case (code)0xbf:
    goto switchD_08001e0c_caseD_bf;
  case (code)0xc0:
    goto switchD_08001e0c_caseD_c0;
  case (code)0xc1:
    goto switchD_08001e0c_caseD_c1;
  case (code)0xc2:
    goto switchD_08001e0c_caseD_c2;
  case (code)0xc3:
    goto switchD_08001e0c_caseD_c3;
  case (code)0xc4:
    goto switchD_08001e0c_caseD_c4;
  case (code)0xc5:
    goto switchD_08001e0c_caseD_c5;
  case (code)0xc6:
    goto switchD_08001e0c_caseD_c6;
  case (code)0xc7:
    goto switchD_08001e0c_caseD_c7;
  case (code)0xc8:
    goto switchD_08001e0c_caseD_c8;
  case (code)0xc9:
    goto switchD_08001e0c_caseD_c9;
  case (code)0xca:
    goto switchD_08001e0c_caseD_ca;
  case (code)0xcb:
    goto switchD_08001e0c_caseD_cb;
  case (code)0xcc:
    goto switchD_08001e0c_caseD_cc;
  case (code)0xcd:
    goto switchD_08001e0c_caseD_cd;
  case (code)0xce:
    goto switchD_08001e0c_caseD_ce;
  case (code)0xcf:
    goto switchD_08001e0c_caseD_cf;
  case (code)0xd0:
    goto switchD_08001e0c_caseD_d0;
  case (code)0xd1:
    goto switchD_08001e0c_caseD_d1;
  case (code)0xd2:
    goto switchD_08001e0c_caseD_d2;
  case (code)0xd3:
    goto switchD_08001e0c_caseD_d3;
  case (code)0xd4:
    goto switchD_08001e0c_caseD_d4;
  case (code)0xd5:
    goto switchD_08001e0c_caseD_d5;
  case (code)0xd6:
    goto switchD_08001e0c_caseD_d6;
  case (code)0xd7:
    goto switchD_08001e0c_caseD_d7;
  case (code)0xd8:
    goto switchD_08001e0c_caseD_d8;
  case (code)0xd9:
    goto switchD_08001e0c_caseD_d9;
  case (code)0xda:
    goto switchD_08001e0c_caseD_da;
  case (code)0xdb:
    goto switchD_08001e0c_caseD_db;
  case (code)0xdc:
    goto switchD_08001e0c_caseD_dc;
  case (code)0xdd:
    goto switchD_08001e0c_caseD_dd;
  case (code)0xde:
    goto switchD_08001e0c_caseD_de;
  case (code)0xdf:
    goto switchD_08001e0c_caseD_df;
  case (code)0xe0:
    goto switchD_08001e0c_caseD_e0;
  case (code)0xe1:
    goto switchD_08001e0c_caseD_e1;
  case (code)0xe2:
    goto switchD_08001e0c_caseD_e2;
  case (code)0xe3:
    goto switchD_08001e0c_caseD_e3;
  case (code)0xe4:
    goto switchD_08001e0c_caseD_e4;
  case (code)0xe5:
    goto switchD_08001e0c_caseD_e5;
  case (code)0xe6:
    goto switchD_08001e0c_caseD_e6;
  case (code)0xe7:
    goto switchD_08001e0c_caseD_e7;
  case (code)0xe8:
    goto switchD_08001e0c_caseD_e8;
  case (code)0xe9:
    goto switchD_08001e0c_caseD_e9;
  case (code)0xea:
    goto switchD_08001e0c_caseD_ea;
  case (code)0xeb:
    goto switchD_08001e0c_caseD_eb;
  case (code)0xec:
    goto switchD_08001e0c_caseD_ec;
  case (code)0xed:
    goto switchD_08001e0c_caseD_ed;
  case (code)0xee:
    goto switchD_08001e0c_caseD_ee;
  case (code)0xef:
    goto switchD_08001e0c_caseD_ef;
  case (code)0xf0:
    goto switchD_08001e0c_caseD_f0;
  case (code)0xf1:
    goto LAB_08001c1e;
  case (code)0xf2:
  case (code)0xf3:
    param_2 = (code *)((uint)param_2 & (uint)pcVar5);
switchD_08001e0c_caseD_f4:
    param_2 = param_2 + 0x21;
switchD_08001e0c_caseD_f5:
    param_2 = (code *)((uint)param_2 >> ((uint)extraout_r2 & 0xff));
switchD_08001e0c_caseD_f6:
switchD_08001e0c_caseD_f7:
    *(short *)(param_2 + 6) = (short)((ulonglong)uVar10 >> 0x20);
switchD_08001e0c_caseD_f8:
switchD_08001e0c_caseD_f9:
    pcVar4 = (code *)((int)pcVar4 << 8);
switchD_08001e0c_caseD_fa:
switchD_08001e0c_caseD_fb:
switchD_08001e0c_caseD_fc:
switchD_08001e0c_caseD_fd:
switchD_08001e0c_caseD_fe:
    pcVar4 = (code *)((int)pcVar4 << 4);
switchD_08001e0c_caseD_ff:
    *(short *)pcVar4 = (short)pcVar4;
    _UsageFault = (short)param_2;
    _MasterStackPointer = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (code)0xf4:
    goto switchD_08001e0c_caseD_f4;
  case (code)0xf5:
    goto switchD_08001e0c_caseD_f5;
  case (code)0xf6:
    goto switchD_08001e0c_caseD_f6;
  case (code)0xf7:
    goto switchD_08001e0c_caseD_f7;
  case (code)0xf8:
    goto switchD_08001e0c_caseD_f8;
  case (code)0xf9:
    goto switchD_08001e0c_caseD_f9;
  case (code)0xfa:
    goto switchD_08001e0c_caseD_fa;
  case (code)0xfb:
    goto switchD_08001e0c_caseD_fb;
  case (code)0xfc:
    goto switchD_08001e0c_caseD_fc;
  case (code)0xfd:
    goto switchD_08001e0c_caseD_fd;
  case (code)0xfe:
    goto switchD_08001e0c_caseD_fe;
  case (code)0xff:
    goto switchD_08001e0c_caseD_ff;
  }
switchD_08001e0c_caseD_1b:
switchD_08001e0c_caseD_1c:
  return pcVar4;
}



// ==== 08001ee0  caseD_68  (132 bytes, 2 xrefs)

undefined4
switchD_08001e0c::caseD_68(int param_1,undefined4 *param_2,uint *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  
  puVar4 = DAT_20000034;
  iVar2 = DAT_20000030;
  if (DAT_20000030 == 0) {
    if ((DAT_20000034 != (undefined4 *)0x0) &&
       (*(char *)(param_1 + 1) == *(char *)((int)DAT_20000034 + 6))) {
      if (*(short *)(param_1 + 4) != 7) {
        return 0xffffffff;
      }
      *param_2 = *DAT_20000034;
      uVar1 = (uint)*(ushort *)(puVar4 + 1);
      goto switchD_08001e0c_caseD_95;
    }
  }
  else if (*(char *)(param_1 + 1) == *(char *)(DAT_20000030 + 5)) {
    if (*(short *)(param_1 + 4) == 4) {
      *param_2 = *(undefined4 *)(DAT_20000030 + 8);
      uVar1 = (uint)*(ushort *)(iVar2 + 0xc);
    }
    else {
      if (*(short *)(param_1 + 4) != 5) {
        return 0xffffffff;
      }
      *param_2 = *(undefined4 *)(DAT_20000030 + 0x10);
      uVar1 = (uint)*(ushort *)(iVar2 + 0x14);
    }
switchD_08001e0c_caseD_95:
    *param_3 = uVar1;
    return 0;
  }
  puVar4 = DAT_2000002c;
  while( true ) {
    if (puVar4 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    pcVar3 = (code *)puVar4[3];
    if ((pcVar3 != (code *)0x0) &&
       (iVar2 = (*pcVar3)(param_1,param_2,param_3,pcVar3,param_4), iVar2 == 0)) break;
    puVar4 = (undefined4 *)*puVar4;
  }
  return 0;
}



// ==== 080028c8  thunk_FUN_08012508  (4 bytes, 1 xrefs)

void thunk_FUN_08012508(void)

{
  (*DAT_080028cc)();
  return;
}



// ==== 080028d4  FUN_080028d4  (8 bytes, 1 xrefs)

void FUN_080028d4(void)

{
  (*DAT_080028e8)();
                    /* WARNING: Could not recover jumptable at 0x080028da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_080028ec)();
  return;
}



// ==== 080028dc  FUN_080028dc  (2 bytes, 1 xrefs)

void FUN_080028dc(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080028de  FUN_080028de  (2 bytes, 1 xrefs)

void FUN_080028de(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080028e0  FUN_080028e0  (2 bytes, 1 xrefs)

void FUN_080028e0(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080028e2  FUN_080028e2  (2 bytes, 1 xrefs)

void FUN_080028e2(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080028e6  FUN_080028e6  (2 bytes, 1 xrefs)

void FUN_080028e6(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 080028f0  FUN_080028f0  (44 bytes, 37 xrefs)

int FUN_080028f0(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar2 = 0x20;
  while (uVar3 = uVar2 - 1, 0 < (int)uVar2) {
    uVar2 = uVar3;
    if (param_2 <= param_1 >> (uVar3 & 0xff)) {
      param_1 = param_1 - (param_2 << (uVar3 & 0xff));
      iVar1 = iVar1 + (1 << (uVar3 & 0xff));
    }
  }
  return iVar1;
}



// ==== 0800291c  FUN_0800291c  (40 bytes, 2 xrefs)

int FUN_0800291c(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = param_1 < 0;
  if (bVar2) {
    param_1 = -param_1;
  }
  bVar3 = param_2 < 0;
  if (bVar3) {
    param_2 = -param_2;
  }
  iVar1 = FUN_080028f0(param_1,param_2);
  if (bVar2 != bVar3) {
    iVar1 = -iVar1;
  }
  return iVar1;
}



// ==== 08002944  FUN_08002944  (18 bytes, 8 xrefs)

uint FUN_08002944(void)

{
  uint uVar1;
  
  uVar1 = DAT_08002960 * *DAT_0800295c + DAT_08002964;
  *DAT_0800295c = uVar1;
  return uVar1 >> 1;
}



// ==== 08002956  FUN_08002956  (6 bytes, 1 xrefs)

void FUN_08002956(undefined4 param_1)

{
  *DAT_0800295c = param_1;
  return;
}



// ==== 08002968  FUN_08002968  (36 bytes, 102 xrefs)

void FUN_08002968(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  while (bVar2 = param_3 != 0, param_3 = param_3 - 1, bVar2) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}



// ==== 0800298c  FUN_0800298c  (14 bytes, 27 xrefs)

void FUN_0800298c(undefined1 *param_1,int param_2,undefined1 param_3)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}



// ==== 0800299a  FUN_0800299a  (4 bytes, 40 xrefs)

void FUN_0800299a(undefined4 param_1,undefined4 param_2)

{
  FUN_0800298c(param_1,param_2,0);
  return;
}



// ==== 0800299e  FUN_0800299e  (18 bytes, 0 xrefs)

undefined4 FUN_0800299e(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0800298c(param_1,param_3,param_2);
  return param_1;
}



// ==== 080029b0  FUN_080029b0  (40 bytes, 13 xrefs)

char * FUN_080029b0(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  do {
    pcVar3 = param_1;
    pcVar4 = param_2;
    do {
      cVar1 = *pcVar3;
      cVar2 = *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
      if (cVar1 == '\0') break;
    } while (cVar1 == cVar2);
    if (cVar2 == '\0') {
      return param_1;
    }
    if (cVar1 == '\0') {
      return (char *)0x0;
    }
    param_1 = param_1 + 1;
  } while( true );
}



// ==== 080029d8  FUN_080029d8  (14 bytes, 5 xrefs)

int FUN_080029d8(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1 + 1;
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return (int)param_1 - (int)pcVar2;
}



// ==== 080029e6  FUN_080029e6  (28 bytes, 4 xrefs)

int FUN_080029e6(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    bVar1 = *(byte *)(param_1 + iVar2);
    if ((bVar1 != *(byte *)(param_2 + iVar2)) || (bVar1 == 0)) break;
    iVar2 = iVar2 + 1;
  }
  return (uint)bVar1 - (uint)*(byte *)(param_2 + iVar2);
}



// ==== 08002a02  FUN_08002a02  (26 bytes, 1 xrefs)

void FUN_08002a02(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; (uVar1 < param_3 && (*(char *)(param_1 + uVar1) == *(char *)(param_2 + uVar1)));
      uVar1 = uVar1 + 1) {
  }
  return;
}



// ==== 08002a1c  FUN_08002a1c  (30 bytes, 2 xrefs)

void FUN_08002a1c(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0;
      ((uVar1 < param_3 && (*(char *)(param_1 + uVar1) == *(char *)(param_2 + uVar1))) &&
      (*(char *)(param_1 + uVar1) != '\0')); uVar1 = uVar1 + 1) {
  }
  return;
}



// ==== 08002a3a  FUN_08002a3a  (20 bytes, 8 xrefs)

uint FUN_08002a3a(int param_1,undefined4 param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 3;
  pbVar1 = (byte *)(param_1 + 4);
  do {
    pbVar1 = pbVar1 + -1;
    param_3 = param_3 << 8 | (uint)*pbVar1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return param_3;
}



// ==== 08002a4e  FUN_08002a4e  (18 bytes, 1 xrefs)

uint FUN_08002a4e(uint param_1,undefined1 *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 3;
  uVar1 = param_1;
  do {
    *param_2 = (char)uVar1;
    uVar1 = uVar1 >> 8;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return param_1;
}



// ==== 08002a60  FUN_08002a60  (50 bytes, 1 xrefs)

void FUN_08002a60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *local_48 [6];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_48[0] = &uStack_8;
  local_20 = 0xffffffff;
  local_18 = 0;
  local_30 = DAT_08002a94;
  local_2c = DAT_08002a98;
  local_24 = param_1;
  local_1c = param_1;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_08002dbc(&local_24,param_2,local_48);
  return;
}



// ==== 08002a9c  FUN_08002a9c  (330 bytes, 1 xrefs)

int FUN_08002a9c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_30;
  int local_2c;
  int local_1c;
  
  uVar5 = param_4[1];
  local_2c = 0;
  iVar7 = param_4[2];
  iVar9 = -1;
  do {
    iVar8 = iVar9;
    iVar9 = iVar8 + 1;
    local_30 = (*(code *)param_4[6])(param_2);
    iVar1 = (*(code *)param_4[8])();
  } while (iVar1 != 0);
  if (local_30 == -1) {
    return -1;
  }
  uVar6 = uVar5 & 0xfffff9ff;
  iVar1 = iVar7;
  iVar2 = iVar9;
  local_1c = param_3;
  if (iVar7 < 1) {
LAB_08002b04:
    uVar5 = uVar6;
    if (param_3 != 0) goto LAB_08002b78;
    local_1c = 10;
  }
  else {
    if ((int)(uVar5 << 0x19) < 0) {
      if (local_30 != 0x2b) {
        if (local_30 != 0x2d) goto LAB_08002afe;
        uVar6 = uVar6 | 0x400;
      }
      iVar9 = iVar8 + 2;
      local_30 = (*(code *)param_4[6])(param_2);
      iVar7 = iVar7 + -1;
      iVar1 = iVar7;
      iVar2 = iVar9;
      if (iVar7 < 1) goto LAB_08002b04;
    }
LAB_08002afe:
    iVar1 = iVar7;
    iVar2 = iVar9;
    if (local_30 != 0x30) goto LAB_08002b04;
    uVar5 = uVar6 | 0x200;
    iVar1 = iVar7 + -1;
    iVar2 = iVar9 + 1;
    local_30 = (*(code *)param_4[6])(param_2);
    if ((iVar1 < 1) || ((local_30 != 0x78 && (local_30 != 0x58)))) {
      if (param_3 != 0) goto LAB_08002b78;
      local_1c = 8;
      uVar6 = uVar5;
    }
    else {
      if ((param_3 != 0) && (param_3 != 0x10)) goto LAB_08002b78;
      iVar1 = iVar7 + -2;
      iVar2 = iVar9 + 2;
      local_30 = (*(code *)param_4[6])(param_2);
      local_1c = 0x10;
    }
  }
  uVar5 = uVar6;
LAB_08002b78:
  while ((0 < iVar1 && (iVar9 = FUN_08002d92(local_30,local_1c), -1 < iVar9))) {
    iVar1 = iVar1 + -1;
    local_2c = local_1c * local_2c + iVar9;
    iVar2 = iVar2 + 1;
    local_30 = (*(code *)param_4[6])(param_2);
    uVar5 = uVar5 | 0x200;
  }
  (*(code *)param_4[7])(param_2);
  if ((int)(uVar5 << 0x16) < 0) {
    if ((uVar5 & 1) == 0) {
      if ((int)(uVar5 << 0x19) < 0) {
        if ((int)(uVar5 << 0x15) < 0) {
          local_2c = -local_2c;
        }
        puVar3 = (undefined4 *)*param_4;
        *param_4 = puVar3 + 1;
        piVar4 = (int *)*puVar3;
        if ((int)(uVar5 << 0x14) < 0) {
          *(char *)piVar4 = (char)local_2c;
        }
        else if ((int)(uVar5 << 0x1c) < 0) {
          *(short *)piVar4 = (short)local_2c;
        }
        else {
          *piVar4 = local_2c;
        }
      }
      else {
        puVar3 = (undefined4 *)*param_4;
        *param_4 = puVar3 + 1;
        piVar4 = (int *)*puVar3;
        if ((int)(uVar5 << 0x14) < 0) {
          *(char *)piVar4 = (char)local_2c;
        }
        else if ((int)(uVar5 << 0x1c) < 0) {
          *(short *)piVar4 = (short)local_2c;
        }
        else {
          *piVar4 = local_2c;
        }
      }
    }
  }
  else {
    iVar2 = -2;
  }
  return iVar2;
}



// ==== 08002be8  FUN_08002be8  (202 bytes, 15 xrefs)

void FUN_08002be8(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  
  local_20 = param_3;
  local_28 = param_1;
  if ((param_1 == 0 && (param_2 & 0x7fffffff) == 0) || (param_3 == 0 && (param_4 & 0x7fffffff) == 0)
     ) {
    return;
  }
  local_24 = param_2 & 0xfffff | 0x100000;
  local_1c = param_4 & 0xfffff | 0x100000;
  uVar3 = 0;
  uVar6 = 0;
  iVar1 = 0;
  do {
    iVar4 = iVar1;
    while( true ) {
      iVar5 = iVar4;
      for (iVar2 = iVar1 - iVar4; iVar2 <= iVar4; iVar2 = iVar2 + 1) {
        uVar7 = (uint)*(ushort *)((int)&local_20 + iVar2 * 2) *
                (uint)*(ushort *)((int)&local_28 + iVar5 * 2);
        bVar8 = CARRY4(uVar7,uVar3);
        uVar3 = uVar7 + uVar3;
        uVar6 = uVar6 + bVar8;
        iVar5 = iVar5 + -1;
      }
      *(short *)((int)&local_38 + iVar1 * 2) = (short)uVar3;
      uVar3 = uVar3 >> 0x10 | uVar6 << 0x10;
      uVar6 = uVar6 >> 0x10;
      iVar1 = iVar1 + 1;
      if (7 < iVar1) {
        FUN_08002e3a(local_30,local_2c,local_38,local_34,0,(param_2 ^ param_4) & 0x80000000,
                     ((param_2 & 0x7fffffff) >> 0x14) + ((param_4 & 0x7fffffff) >> 0x14) +
                     DAT_08002cb4);
        return;
      }
      if (iVar1 < 3) break;
      iVar4 = 3;
    }
  } while( true );
}



// ==== 08002cb8  FUN_08002cb8  (24 bytes, 11 xrefs)

void FUN_08002cb8(undefined4 param_1)

{
  FUN_08002e3a(param_1,0,0,0,0,0,DAT_08002cd0);
  return;
}



// ==== 08002cd4  FUN_08002cd4  (50 bytes, 3 xrefs)

int FUN_08002cd4(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  if ((int)uVar2 < DAT_08002d08) {
    return 0;
  }
  if (DAT_08002d08 + 0x34 < (int)uVar2) {
    return param_1 << (uVar2 + DAT_08002d0c & 0xff);
  }
  iVar1 = FUN_08002d70(param_1,param_2 & 0xfffff | 0x100000,(DAT_08002d08 + 0x34) - uVar2);
  return iVar1;
}



// ==== 08002d10  FUN_08002d10  (96 bytes, 2 xrefs)

longlong FUN_08002d10(uint param_1,int param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined8 uVar6;
  longlong lVar7;
  int local_2c;
  
  lVar1 = 0;
  iVar3 = 0x40;
  local_2c = param_2;
  while (iVar4 = iVar3 + -1, 0 < iVar3) {
    uVar6 = FUN_08002d70(param_1,local_2c,iVar4);
    uVar2 = (uint)((ulonglong)uVar6 >> 0x20);
    iVar3 = iVar4;
    if (param_4 < uVar2 || uVar2 - param_4 < (uint)(param_3 <= (uint)uVar6)) {
      uVar6 = FUN_080031c0(param_3,param_4,iVar4);
      bVar5 = param_1 < (uint)uVar6;
      param_1 = param_1 - (uint)uVar6;
      local_2c = (local_2c - (int)((ulonglong)uVar6 >> 0x20)) - (uint)bVar5;
      lVar7 = FUN_080031c0(1,0,iVar4);
      lVar1 = lVar7 + lVar1;
    }
  }
  return lVar1;
}



// ==== 08002d70  FUN_08002d70  (34 bytes, 4 xrefs)

ulonglong FUN_08002d70(uint param_1,uint param_2,uint param_3)

{
  if ((int)param_3 < 0x20) {
    return CONCAT44(param_2 >> (param_3 & 0xff),
                    param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff));
  }
  return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
}



// ==== 08002d92  FUN_08002d92  (30 bytes, 1 xrefs)

uint FUN_08002d92(uint param_1,uint param_2)

{
  if (param_1 < 0x3a) {
    param_1 = param_1 - 0x30;
  }
  if (0x40 < (param_1 & 0xffffffdf)) {
    param_1 = (param_1 & 0xffffffdf) - 0x37;
  }
  if (param_2 <= param_1) {
    param_1 = 0xffffffff;
  }
  return param_1;
}



// ==== 08002dbc  FUN_08002dbc  (24 bytes, 1 xrefs)

void FUN_08002dbc(undefined4 param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_3 + 0xc) = param_2;
  *(undefined4 *)(param_3 + 0x14) = DAT_08002dd4;
  *(undefined4 *)(param_3 + 0x20) = DAT_08002dd8;
  *(undefined4 *)(param_3 + 0x10) = 0;
  FUN_08003214(param_1,param_3);
  return;
}



// ==== 08002e20  FUN_08002e20  (26 bytes, 3 xrefs)

undefined8 FUN_08002e20(uint param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  if (param_4 < 0) {
    bVar1 = 0xfffffffe < param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + (uint)bVar1;
    if ((param_3 & 0x7fffffff) == 0 && param_4 * 2 + (uint)CARRY4(param_3,param_3) == 0) {
      param_1 = param_1 & 0xfffffffe;
    }
  }
  return CONCAT44(param_2,param_1);
}



// ==== 08002e3a  FUN_08002e3a  (164 bytes, 3 xrefs)

uint FUN_08002e3a(undefined4 param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  if (param_2 == 0) {
    iVar1 = FUN_080119d4();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = FUN_080119d4(param_2);
  }
  uVar4 = FUN_080031c0(param_1,param_2,iVar1);
  uVar2 = (uint)(uVar4 >> 0x20);
  uVar3 = (uint)uVar4;
  if (!((uVar3 == 0 && param_3 == 0) && (uVar2 == 0 && param_4 == 0))) {
    if (param_3 != 0 || param_4 != 0) {
      uVar5 = FUN_08002d70(param_3,param_4,0x40 - iVar1);
      lVar6 = FUN_080031c0(param_3,param_4,iVar1);
      uVar4 = CONCAT44(uVar2 | (uint)((ulonglong)uVar5 >> 0x20),
                       uVar3 | (uint)uVar5 | (uint)(lVar6 != 0));
    }
    uVar3 = (uint)(uVar4 >> 0xb);
    iVar1 = (param_7 - iVar1) + 10;
    if (iVar1 < 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_08002e20(uVar3 + param_5,
                           iVar1 * 0x100000 + (int)((uVar4 >> 0xb) >> 0x20) + param_6 +
                           (uint)CARRY4(uVar3,param_5),0,(int)uVar4 << 0x15);
    }
  }
  return uVar3;
}



// ==== 08002ee0  FUN_08002ee0  (326 bytes, 3 xrefs)

uint FUN_08002ee0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  iVar1 = (int)(param_2 ^ param_4) >> 0x1f;
  local_20 = -iVar1;
  uVar5 = param_3;
  uVar3 = param_4;
  if ((param_2 & 0x7fffffff) <= (param_4 & 0x7fffffff) &&
      (uint)(param_3 <= param_1) <= (param_2 & 0x7fffffff) - (param_4 & 0x7fffffff)) {
    uVar5 = param_1;
    uVar3 = param_2;
    param_2 = param_4;
    param_1 = param_3;
  }
  if (!((uVar3 & 0x7fffffff) == 0 && uVar5 == 0)) {
    local_24 = param_2 >> 0x14;
    local_1c = local_24 & 0x7ff;
    iVar2 = local_1c - ((uVar3 & 0x7fffffff) >> 0x14);
    if (iVar2 < 0x40) {
      uVar3 = uVar3 & 0xfffff | 0x100000;
      if (local_20 != 0) {
        bVar7 = uVar5 != 0;
        uVar5 = -uVar5;
        uVar3 = -(uint)bVar7 - uVar3;
      }
      uVar8 = FUN_080031c0(uVar5,uVar3,0x40 - iVar2);
      uVar6 = (uint)(uVar8 >> 0x20);
      uVar4 = (uint)uVar8;
      lVar9 = FUN_080031e0(uVar5,uVar3,iVar2,&local_24);
      lVar9 = lVar9 + CONCAT44(param_2,param_1);
      uVar5 = (uint)lVar9;
      uVar3 = (uint)((ulonglong)lVar9 >> 0x20);
      if (uVar3 >> 0x14 != local_24 || (int)local_24 < 0) {
        if (local_20 == 0) {
          uVar8 = CONCAT44((uint)((uVar8 >> 1) >> 0x20) | uVar5 * -0x80000000,(int)(uVar8 >> 1));
          lVar9 = CONCAT44((uVar3 + local_24 * -0x100000 + 0x100000 >> 1) + local_24 * 0x100000,
                           uVar5 >> 1 | uVar3 * -0x80000000);
        }
        else {
          if (iVar2 < 2) {
            uVar5 = FUN_08002e3a(uVar5,uVar3 + local_24 * -0x100000 + 0x100000,uVar4,uVar6,0,
                                 ((local_24 & 0xfff) >> 0xb) << 0x1f,local_1c);
            return uVar5;
          }
          lVar9 = CONCAT44(local_24 * -0x100000 + DAT_08003040 +
                           uVar3 * 2 + 0x200000 + (uint)CARRY4(uVar5,uVar5),
                           uVar5 * 2 | uVar6 >> 0x1f);
          uVar8 = CONCAT44(uVar6 * 2 + (uint)CARRY4(uVar4,uVar4),uVar4 * 2);
        }
      }
    }
    else {
      uVar8 = CONCAT44(-(uint)(1 < (uint)(iVar1 * -2)),iVar1 * 2 + 1);
      lVar9 = CONCAT44(param_2 - (param_1 < local_20),param_1 + iVar1);
    }
    param_1 = FUN_08002e20((int)lVar9,(int)((ulonglong)lVar9 >> 0x20),(int)uVar8,
                           (int)(uVar8 >> 0x20));
  }
  return param_1;
}



// ==== 08003044  FUN_08003044  (234 bytes, 2 xrefs)

void FUN_08003044(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  int local_28;
  
  if ((param_1 != 0 || (param_2 & 0x7fffffff) != 0) && (param_3 != 0 || (param_4 & 0x7fffffff) != 0)
     ) {
    local_28 = (((param_2 & 0x7fffffff) >> 0x14) - ((param_4 & 0x7fffffff) >> 0x14)) + DAT_08003130;
    uVar3 = param_2 & 0xfffff | 0x100000;
    uVar5 = param_4 & 0xfffff | 0x100000;
    if (uVar5 < uVar3 || uVar3 - uVar5 < (uint)(param_3 <= param_1)) {
      local_28 = local_28 + 1;
    }
    else {
      bVar8 = CARRY4(param_1,param_1);
      param_1 = param_1 * 2;
      uVar3 = uVar3 * 2 + (uint)bVar8;
    }
    if (-1 < local_28) {
      uVar2 = 0x100000;
      uVar6 = 0;
      uVar7 = 0;
      for (uVar1 = 0; uVar1 != 0 || uVar2 != 0; uVar1 = uVar1 >> 1 | uVar4) {
        if (uVar5 < uVar3 || uVar3 - uVar5 < (uint)(param_3 <= param_1)) {
          bVar8 = param_1 < param_3;
          param_1 = param_1 - param_3;
          uVar3 = (uVar3 - uVar5) - (uint)bVar8;
          uVar6 = uVar6 | uVar1;
          uVar7 = uVar7 | uVar2;
        }
        uVar4 = uVar2 << 0x1f;
        uVar2 = uVar2 >> 1;
        bVar8 = CARRY4(param_1,param_1);
        param_1 = param_1 * 2;
        uVar3 = uVar3 * 2 + (uint)bVar8;
      }
      if (param_1 != 0 || uVar3 != 0) {
        if (param_3 == param_1 && uVar3 == uVar5) {
          param_1 = 0;
          uVar3 = 0x80000000;
        }
        else if (uVar5 < uVar3 || uVar3 - uVar5 < (uint)(param_3 <= param_1)) {
          param_1 = 0xfffffffe;
          uVar3 = 0xffffffff;
        }
        else {
          param_1 = 1;
          uVar3 = 0;
        }
      }
      FUN_08002e20(uVar6,local_28 * 0x100000 + uVar7 + ((param_2 ^ param_4) & 0x80000000),param_1,
                   uVar3);
    }
  }
  return;
}



// ==== 08003134  FUN_08003134  (54 bytes, 1 xrefs)

void FUN_08003134(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 & 0xfffff | 0x100000;
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  if ((int)uVar2 < DAT_0800316c) {
    return;
  }
  if (DAT_0800316c + 0x34 < (int)uVar2) {
    FUN_080031c0(param_1,uVar1,uVar2 + DAT_08003170);
    return;
  }
  FUN_08002d70(param_1,uVar1,(DAT_0800316c + 0x34) - uVar2);
  return;
}



// ==== 08003174  FUN_08003174  (38 bytes, 1 xrefs)

int FUN_08003174(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}



// ==== 0800319c  FUN_0800319c  (36 bytes, 1 xrefs)

longlong FUN_0800319c(void)

{
  uint uVar1;
  uint extraout_r2;
  undefined4 *puVar2;
  
  for (puVar2 = &DAT_08014cc0; puVar2 < &DAT_08014ce0; puVar2 = puVar2 + 4) {
    (*(code *)puVar2[3])(*puVar2,puVar2[1],puVar2[2]);
  }
  uVar1 = thunk_FUN_08012508();
  if ((int)extraout_r2 < 0x20) {
    return CONCAT44(0 << (extraout_r2 & 0xff) | uVar1 >> (0x20 - extraout_r2 & 0xff),
                    uVar1 << (extraout_r2 & 0xff));
  }
  return (ulonglong)(uVar1 << (extraout_r2 - 0x20 & 0xff)) << 0x20;
}



// ==== 080031c0  FUN_080031c0  (32 bytes, 6 xrefs)

longlong FUN_080031c0(uint param_1,int param_2,uint param_3)

{
  if ((int)param_3 < 0x20) {
    return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                    param_1 << (param_3 & 0xff));
  }
  return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
}



// ==== 080031e0  FUN_080031e0  (38 bytes, 1 xrefs)

undefined8 FUN_080031e0(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((int)param_3 < 0x20) {
    iVar2 = (int)param_2 >> (param_3 & 0xff);
    uVar1 = param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff);
  }
  else {
    uVar1 = (int)param_2 >> (param_3 - 0x20 & 0xff);
    iVar2 = (int)(param_2 | uVar1) >> 0x1f;
  }
  return CONCAT44(iVar2,uVar1);
}



// ==== 08003206  FUN_08003206  (14 bytes, 0 xrefs)

void FUN_08003206(undefined1 param_1)

{
  FUN_0800354c(param_1,0x1e00);
  return;
}



// ==== 08003214  FUN_08003214  (812 bytes, 1 xrefs)

int FUN_08003214(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint local_4c [8];
  undefined4 *local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 *puStack_18;
  
  local_28 = 0;
  local_24 = 1;
  iVar9 = 0;
  local_2c = param_2 + 3;
  local_1c = param_1;
  puStack_18 = param_2;
LAB_0800322a:
  while( true ) {
    iVar1 = (*(code *)param_2[5])(local_2c,1);
    if (iVar1 == 0) {
      return local_28;
    }
    if (iVar1 == 0x25) break;
    iVar2 = (*(code *)param_2[8])();
    if (iVar2 == 0) {
      iVar2 = (*(code *)param_2[6])(local_1c);
      if (iVar2 != iVar1) {
        (*(code *)param_2[7])(local_1c);
        goto joined_r0x0800328c;
      }
LAB_08003280:
      iVar9 = iVar9 + 1;
    }
    else {
      do {
        (*(code *)param_2[5])(local_2c,1);
        iVar1 = (*(code *)param_2[8])();
      } while (iVar1 != 0);
      (*(code *)param_2[5])(local_2c,0xffffffff);
      while( true ) {
        (*(code *)param_2[6])(local_1c);
        iVar1 = (*(code *)param_2[8])();
        if (iVar1 == 0) break;
        iVar9 = iVar9 + 1;
      }
      (*(code *)param_2[7])(local_1c);
    }
  }
  iVar1 = 0;
  uVar8 = 0;
  iVar2 = (*(code *)param_2[5])(local_2c,0);
  if (iVar2 == 0x2a) {
    (*(code *)param_2[5])(local_2c,1);
    uVar8 = 1;
  }
  while (iVar2 = (*(code *)param_2[5])(local_2c,1), iVar2 - 0x30U < 10) {
    if (DAT_08003540 < iVar1) {
      return local_28;
    }
    iVar1 = iVar1 * 10 + iVar2 + -0x30;
    if (iVar1 < 0) {
      return local_28;
    }
    uVar8 = uVar8 | 0x10;
  }
  if (-1 < (int)(uVar8 << 0x1b)) {
    iVar1 = DAT_08003544;
  }
  if (iVar2 == 0x6c) {
    iVar2 = (*(code *)param_2[5])(local_2c,1);
    if (iVar2 == 0x6c) {
LAB_0800334c:
      uVar3 = 2;
      goto LAB_0800330a;
    }
    uVar3 = 4;
LAB_08003342:
    uVar8 = uVar8 | uVar3;
  }
  else {
    if (iVar2 == 0x4c) {
      uVar3 = 0x20;
LAB_0800330a:
      uVar8 = uVar8 | uVar3;
    }
    else {
      if (iVar2 == 0x68) {
        iVar2 = (*(code *)param_2[5])(local_2c,1);
        if (iVar2 != 0x68) {
          uVar3 = 8;
          goto LAB_08003342;
        }
        uVar3 = 0x800;
        goto LAB_0800330a;
      }
      if (iVar2 == 0x6a) goto LAB_0800334c;
      if ((iVar2 != 0x74) && (iVar2 != 0x7a)) goto LAB_08003314;
    }
    iVar2 = (*(code *)param_2[5])(local_2c,1);
  }
LAB_08003314:
  param_2[2] = iVar1;
  param_2[1] = uVar8;
  if (iVar2 == 0x65) goto LAB_080033bc;
  if (iVar2 < 0x66) {
    if (iVar2 == 0x58) {
LAB_08003442:
      param_2[1] = uVar8 | 0x40;
      if ((int)(uVar8 << 0x1e) < 0) goto LAB_08003452;
LAB_0800345e:
      uVar7 = 0x10;
LAB_08003462:
      iVar1 = FUN_08002a9c(0xfffffffe,local_1c,uVar7,param_2);
    }
    else if (iVar2 < 0x59) {
      if (iVar2 != 0x45) {
        if (iVar2 < 0x46) {
          if (iVar2 == 0x25) {
            iVar2 = (*(code *)param_2[6])(local_1c);
            if (iVar2 != 0x25) {
              (*(code *)param_2[7])(local_1c);
joined_r0x0800328c:
              if (iVar2 != -1) {
                return local_28;
              }
              if (local_28 == 0) {
                return -1;
              }
              return local_28;
            }
            goto LAB_08003280;
          }
          if (iVar2 != 0x41) {
            return local_28;
          }
        }
        else if ((iVar2 != 0x46) && (iVar2 != 0x47)) {
          return local_28;
        }
      }
LAB_080033bc:
      iVar1 = -2;
    }
    else {
      if (iVar2 != 0x5b) {
        if (iVar2 == 0x61) goto LAB_080033bc;
        if (iVar2 != 99) {
          if (iVar2 != 100) {
            return local_28;
          }
LAB_08003430:
          param_2[1] = uVar8 | 0x40;
          if (-1 < (int)(uVar8 << 0x1e)) {
            uVar7 = 10;
            goto LAB_08003462;
          }
          goto LAB_08003452;
        }
      }
LAB_0800346e:
      local_20 = 0;
      if (iVar2 == 99) {
        if (-1 < (int)(uVar8 << 0x1b)) {
          param_2[2] = 1;
        }
      }
      else if (iVar2 == 0x5b) {
        iVar1 = (*(code *)param_2[5])(local_2c,1,(code *)param_2[5],0,0);
        if (iVar1 == 0x5e) {
          local_20 = 1;
          iVar1 = (*(code *)param_2[5])(local_2c,1);
        }
        if (param_2[4] == 0) {
          iVar2 = 0;
          do {
            iVar6 = iVar2 + 1;
            local_4c[iVar2] = 0;
            iVar2 = iVar6;
          } while (iVar6 < 8);
        }
        do {
          if (iVar1 == 0) {
            return local_28;
          }
          if (param_2[4] == 0) {
            local_4c[(int)(((uint)(iVar1 >> 0x1f) >> 0x1b) + iVar1) >> 5] =
                 local_4c[(int)(((uint)(iVar1 >> 0x1f) >> 0x1b) + iVar1) >> 5] |
                 1 << (iVar1 % 0x20 & 0xffU);
          }
          iVar1 = (*(code *)param_2[5])(local_2c,1);
        } while (iVar1 != 0x5d);
        if (local_20 != 0) {
          iVar1 = 0;
          do {
            iVar2 = iVar1 + 1;
            local_4c[iVar1] = ~local_4c[iVar1];
            iVar1 = iVar2;
          } while (iVar2 < 8);
        }
      }
      iVar1 = -2;
    }
  }
  else {
    if (iVar2 == 0x6f) {
      param_2[1] = uVar8 | 0x40;
      if (-1 < (int)(uVar8 << 0x1e)) {
        uVar7 = 8;
        goto LAB_08003462;
      }
    }
    else {
      if (0x6f < iVar2) {
        if (iVar2 != 0x70) {
          if (iVar2 == 0x73) goto LAB_0800346e;
          if (iVar2 == 0x75) goto LAB_08003430;
          if (iVar2 != 0x78) {
            return local_28;
          }
          goto LAB_08003442;
        }
        param_2[1] = uVar8 & DAT_08003548;
        goto LAB_0800345e;
      }
      if ((iVar2 == 0x66) || (iVar2 == 0x67)) goto LAB_080033bc;
      if (iVar2 != 0x69) {
        if (iVar2 != 0x6e) {
          return local_28;
        }
        if ((uVar8 & 1) == 0) {
          puVar4 = (undefined4 *)*param_2;
          *param_2 = puVar4 + 1;
          piVar5 = (int *)*puVar4;
          if ((int)(uVar8 << 0x14) < 0) {
            *(char *)piVar5 = (char)iVar9;
          }
          else if ((int)(uVar8 << 0x1c) < 0) {
            *(short *)piVar5 = (short)iVar9;
          }
          else if ((int)(uVar8 << 0x1e) < 0) {
            *piVar5 = iVar9;
            piVar5[1] = iVar9 >> 0x1f;
          }
          else {
            *piVar5 = iVar9;
          }
        }
        goto LAB_0800322a;
      }
      param_2[1] = uVar8 | 0x40;
      if (-1 < (int)(uVar8 << 0x1e)) {
        uVar7 = 0;
        goto LAB_08003462;
      }
    }
LAB_08003452:
    iVar1 = -2;
  }
  if (iVar1 < 0) {
    if (iVar1 != -1) {
      return local_28;
    }
    if (local_24 == 0) {
      return local_28;
    }
    return -1;
  }
  if ((uVar8 & 1) == 0) {
    local_28 = local_28 + 1;
  }
  iVar9 = iVar9 + iVar1;
  local_24 = 0;
  goto LAB_0800322a;
}



// ==== 0800354c  FUN_0800354c  (32 bytes, 1 xrefs)

uint FUN_0800354c(uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  
  if (param_1 < 0x80) {
    bVar1 = *(byte *)(DAT_0800356c + (param_1 >> 1));
    if ((param_1 & 1) == 0) {
      bVar1 = bVar1 >> 4;
    }
    uVar2 = bVar1 & 0xf;
  }
  else {
    uVar2 = 0;
  }
  return 1 << uVar2 & param_2;
}



// ==== 08003570  FUN_08003570  (58 bytes, 2 xrefs)

undefined4 FUN_08003570(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = param_2 + param_3;
  do {
    bVar1 = *param_1;
    uVar4 = bVar1 & 0xf;
    pbVar2 = param_1 + 1;
    if ((bVar1 & 0xf) == 0) {
      uVar4 = (uint)param_1[1];
      pbVar2 = param_1 + 2;
    }
    param_1 = pbVar2;
    uVar3 = (uint)(bVar1 >> 4);
    if (uVar3 == 0) {
      uVar3 = (uint)*param_1;
      param_1 = param_1 + 1;
    }
    while (uVar4 = uVar4 - 1, uVar4 != 0) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    while (uVar3 = uVar3 - 1, uVar3 != 0) {
      *param_2 = 0;
      param_2 = param_2 + 1;
    }
  } while (param_2 < pbVar5);
  return 0;
}



// ==== 080035ac  FUN_080035ac  (156 bytes, 2 xrefs)

void FUN_080035ac(int param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xff) {
    iVar3 = uVar2 * 4;
    iVar1 = iVar3 + param_1;
    *(uint *)(param_2 + iVar3) =
         (uint)*(byte *)(iVar1 + 3) + (uint)*(byte *)(param_1 + iVar3) * 0x1000000 +
         (uint)*(byte *)(iVar1 + 1) * 0x10000 + (uint)*(byte *)(iVar1 + 2) * 0x100;
  }
  for (uVar2 = param_3; uVar2 < (param_4 * 4 + 4U & 0xff); uVar2 = uVar2 + 1 & 0xff) {
    uVar4 = *(uint *)(uVar2 * 4 + param_2 + -4);
    uVar5 = FUN_080028f0(uVar2,param_3);
    iVar1 = (int)((ulonglong)uVar5 >> 0x20);
    if (iVar1 == 0) {
      FUN_080115f8(uVar4);
      uVar4 = FUN_0801164c();
      uVar4 = uVar4 ^ *(uint *)((int)uVar5 * 4 + DAT_08003648 + -4);
    }
    else if ((6 < param_3) && (iVar1 == 4)) {
      uVar4 = FUN_0801164c(uVar4);
    }
    *(uint *)(param_2 + uVar2 * 4) = *(uint *)(param_2 + (uVar2 - param_3) * 4) ^ uVar4;
  }
  return;
}



// ==== 0800364c  FUN_0800364c  (56 bytes, 3 xrefs)

void FUN_0800364c(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  do {
    iVar3 = uVar1 * 4;
    *(byte *)(param_1 + uVar1) =
         *(byte *)(param_1 + uVar1) ^ (byte)((uint)*(undefined4 *)(param_2 + iVar3) >> 0x18);
    iVar2 = param_1 + uVar1;
    *(byte *)(iVar2 + 4) =
         *(byte *)(iVar2 + 4) ^ (byte)((uint)*(undefined4 *)(param_2 + iVar3) >> 0x10);
    *(byte *)(iVar2 + 8) =
         *(byte *)(iVar2 + 8) ^ (byte)((ushort)*(undefined2 *)(param_2 + iVar3) >> 8);
    uVar1 = uVar1 + 1 & 0xff;
    *(byte *)(iVar2 + 0xc) = *(byte *)(iVar2 + 0xc) ^ *(byte *)(param_2 + iVar3);
  } while (uVar1 < 4);
  return;
}



// ==== 08003684  FUN_08003684  (124 bytes, 1 xrefs)

void FUN_08003684(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_08003700;
  *(undefined1 *)(DAT_08003700 + 0x1a) = 0;
  *(undefined1 *)(iVar1 + 0x1b) = 0;
  *(undefined1 *)(iVar1 + 8) = 0;
  *(undefined1 *)(iVar1 + 0x8e) = 0;
  *DAT_08003704 = iVar1 + 0xb8;
  *(undefined1 *)(iVar1 + 0xe1) = 0;
  *(int *)(iVar1 + 200) = iVar1 + 0xb8;
  *(int *)(iVar1 + 0xcc) = iVar1 + 0xc0;
  *(undefined1 *)(iVar1 + 0xd7) = 0;
  *(undefined1 *)(iVar1 + 0xe8) = 0;
  *(undefined1 *)(iVar1 + 0xe7) = 0;
  *DAT_08003708 = 0;
  if (*DAT_0800370c == '\x05') {
    FUN_0800b2fc(0);
  }
  *DAT_08003710 = 1;
  uVar3 = FUN_08002a3a(param_2 + 4);
  *DAT_08003714 = uVar3;
  *(undefined4 *)(PTR_GPIOF_08003718 + 0x28) = 0x100;
  uVar3 = FUN_08002944();
  puVar2 = DAT_0800371c;
  *DAT_0800371c = uVar3;
  uVar3 = FUN_08002944();
  puVar2[1] = uVar3;
  uVar3 = FUN_08002944();
  puVar2[2] = uVar3;
  uVar3 = FUN_08002944();
  puVar2[3] = uVar3;
  FUN_08003c8c(param_1);
  return;
}



// ==== 08003720  FUN_08003720  (60 bytes, 1 xrefs)

void FUN_08003720(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_08002a3a(param_2 + 4);
  *DAT_0800375c = uVar2;
  *DAT_08003760 = 4;
  *(undefined4 *)(PTR_GPIOF_08003764 + 0x28) = 0x100;
  uVar2 = FUN_08002944();
  puVar1 = DAT_08003768;
  *DAT_08003768 = uVar2;
  uVar2 = FUN_08002944();
  puVar1[1] = uVar2;
  uVar2 = FUN_08002944();
  puVar1[2] = uVar2;
  uVar2 = FUN_08002944();
  puVar1[3] = uVar2;
  FUN_08003c8c(param_1);
  return;
}



// ==== 0800376c  FUN_0800376c  (106 bytes, 1 xrefs)

void FUN_0800376c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  
  *DAT_080037d8 = 4;
  pbVar1 = DAT_080037e4;
  _local_18 = CONCAT22(4,(short)DAT_080037dc);
  local_14 = param_4;
  if (((*DAT_080037e0 != '\x01') ||
      (iVar2 = FUN_0800429c(DAT_080037ec,DAT_080037e8,param_2 + 4), iVar3 = 0, iVar2 != 0)) &&
     (iVar3 = FUN_0800429c(DAT_080037f0,DAT_080037e8,param_2 + 4), iVar3 != 0)) {
    *pbVar1 = *pbVar1 + 1;
  }
  if (*pbVar1 < 3) {
    if (iVar3 == 0) {
      *pbVar1 = 0;
    }
  }
  else {
    *pbVar1 = 3;
    iVar3 = 1;
  }
  *DAT_080037f4 = (char)iVar3;
  local_14 = CONCAT31(local_14._1_3_,(char)iVar3);
  FUN_08003cf0(param_1,&local_18,8);
  return;
}



// ==== 080037f8  FUN_080037f8  (236 bytes, 1 xrefs)

void FUN_080037f8(undefined4 param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 local_20;
  undefined4 local_1c;
  int iStack_18;
  
  if (*DAT_080038e4 == '\x01') {
    local_1c = param_1;
    iStack_18 = param_2;
    uVar4 = FUN_08002a3a(param_2 + 4);
    uVar4 = FUN_080028f0(uVar4,10);
    piVar1 = DAT_080038e8;
    puVar6 = (undefined4 *)*DAT_080038e8;
    *puVar6 = uVar4;
    uVar5 = FUN_08002a3a(param_2 + 4);
    uVar5 = FUN_080028f0(uVar5,10);
    puVar6[2] = uVar5;
    *(undefined1 *)(puVar6 + 1) = 0;
    uVar3 = FUN_0800408c(uVar4);
    *(undefined1 *)(*piVar1 + 0x2e) = uVar3;
    FUN_08003f98();
    uVar2 = DAT_080038ec;
    if (*(ushort *)(param_2 + 8) != DAT_080038ec) {
      *(char *)(*piVar1 + 0x20) = (char)*(ushort *)(param_2 + 8);
    }
    if (*(ushort *)(param_2 + 10) != uVar2) {
      *(char *)(*piVar1 + 0x21) = (char)*(ushort *)(param_2 + 10);
    }
    if (*(ushort *)(param_2 + 0xc) != uVar2) {
      *(char *)(*piVar1 + 0x22) = (char)*(ushort *)(param_2 + 0xc);
    }
    if (*(ushort *)(param_2 + 0xe) != uVar2) {
      *(char *)(*piVar1 + 0x23) = (char)*(ushort *)(param_2 + 0xe);
    }
    if (*(ushort *)(param_2 + 0x10) != uVar2) {
      *(char *)(*piVar1 + 0x24) = (char)*(ushort *)(param_2 + 0x10);
    }
    if (*(ushort *)(param_2 + 0x12) != uVar2) {
      *(char *)(*piVar1 + 0x25) = (char)*(ushort *)(param_2 + 0x12);
    }
    FUN_0800ee64(0x3b,((int)((uint)*(byte *)(param_2 + 0x15) << 0x18) >> 0x10 |
                      (uint)*(byte *)(param_2 + 0x14)) + 0x5880 & 0xffff);
    FUN_080049a8(1);
    local_20 = 0x520;
    FUN_08003cf0(local_1c,&local_20,4);
  }
  return;
}



// ==== 080038f0  FUN_080038f0  (144 bytes, 1 xrefs)

void FUN_080038f0(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint local_20;
  undefined4 local_1c;
  int iStack_18;
  
  if (*DAT_08003980 == '\x01') {
    local_1c = param_1;
    iStack_18 = param_2;
    uVar3 = FUN_08002a3a(param_2 + 4);
    uVar3 = FUN_080028f0(uVar3,10);
    piVar1 = DAT_08003984;
    puVar5 = (undefined4 *)*DAT_08003984;
    *puVar5 = uVar3;
    uVar4 = FUN_08002a3a(param_2 + 4);
    uVar4 = FUN_080028f0(uVar4,10);
    puVar5[2] = uVar4;
    *(undefined1 *)(puVar5 + 3) = 0;
    uVar2 = FUN_0800408c(uVar3);
    *(undefined1 *)(*piVar1 + 0x2e) = uVar2;
    FUN_08003f98();
    if (*(char *)(param_2 + 8) == '\x01') {
      *(undefined1 *)(*piVar1 + 0x28) = *(undefined1 *)(param_2 + 9);
    }
    FUN_0800ee64(0x3b,((int)((uint)*(byte *)(param_2 + 0xb) << 0x18) >> 0x10 |
                      (uint)*(byte *)(param_2 + 10)) + 0x5880 & 0xffff);
    *DAT_08003988 = *piVar1;
    FUN_0800b2fc(1);
    local_20 = DAT_0800398c & 0xffff;
    FUN_08003cf0(local_1c,&local_20,4);
  }
  return;
}



// ==== 08003990  FUN_08003990  (44 bytes, 1 xrefs)

void FUN_08003990(undefined4 param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = 0x40528;
  FUN_0800e624(&local_c,(int)&local_c + 2,(int)&local_c + 3);
  FUN_08003cf0(param_1,&local_10,8);
  return;
}



// ==== 080039bc  FUN_080039bc  (40 bytes, 1 xrefs)

void FUN_080039bc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 local_18;
  undefined2 uStack_16;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = 0;
  _local_18 = CONCAT22(4,(short)DAT_080039e4);
  uStack_10 = param_4;
  FUN_0800dcfc(&local_14,&uStack_10);
  FUN_08003cf0(param_1,&local_18,8);
  return;
}



// ==== 080039e8  FUN_080039e8  (184 bytes, 1 xrefs)

/* WARNING: Removing unreachable block (ram,0x08003a6c) */

void FUN_080039e8(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 local_10c;
  short local_10a;
  undefined2 local_108;
  undefined1 local_106;
  undefined1 local_105;
  int local_84;
  undefined1 local_80 [64];
  undefined1 local_40 [36];
  undefined4 local_1c;
  int iStack_18;
  
  uVar1 = *(undefined2 *)(param_2 + 4);
  local_1c = param_1;
  iStack_18 = param_2;
  iVar2 = FUN_08002a3a(param_2 + 8);
  if (iVar2 == *DAT_08003aa0) {
    *DAT_08003aa4 = 4;
    FUN_0800299a(&local_10c,0x88);
    local_84 = *(byte *)(param_2 + 6) + 8;
    local_10c = (undefined2)DAT_08003aa8;
    local_10a = (short)local_84 + -4;
    local_108 = *(undefined2 *)(param_2 + 4);
    local_106 = *(undefined1 *)(param_2 + 6);
    local_105 = *(undefined1 *)(param_2 + 7);
    FUN_0800a21c(uVar1,*(undefined1 *)(param_2 + 6),local_80,local_40);
    FUN_08003cf0(local_1c,&local_10c,local_84);
  }
  return;
}



// ==== 08003ab4  FUN_08003ab4  (252 bytes, 1 xrefs)

void FUN_08003ab4(undefined4 param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined2 local_60;
  undefined2 uStack_5e;
  uint local_5c;
  byte local_58 [4];
  uint local_54 [8];
  ushort local_34 [8];
  uint local_24;
  undefined4 local_1c;
  int iStack_18;
  
  local_24 = (uint)CONCAT12(*(byte *)(param_2 + 7) >> 4,*(undefined2 *)(param_2 + 4));
  bVar1 = false;
  iVar6 = param_2 + 0xc;
  local_58[0] = 0;
  local_1c = param_1;
  iStack_18 = param_2;
  iVar3 = FUN_08002a3a(param_2 + 8);
  if (iVar3 == *DAT_08003bb0) {
    *DAT_08003bb4 = 4;
    _local_60 = CONCAT22(2,(short)DAT_08003bb8);
    local_5c = (uint)*(ushort *)(param_2 + 4);
    FUN_0800a21c(local_24,*(undefined1 *)(param_2 + 6),local_54,local_34,local_58,0x10);
    cVar2 = *DAT_08003bbc;
    if (cVar2 == '\x01') {
      cVar2 = *DAT_08003bc0;
    }
    if (cVar2 == '\0') {
      for (uVar7 = 0; uVar7 < local_58[0]; uVar7 = uVar7 + 1 & 0xffff) {
        uVar4 = local_54[uVar7];
        uVar5 = (uint)local_34[uVar7];
        if ((uVar4 < 0xb000) && (0x9fff < uVar4 + uVar5)) {
          if (*DAT_08003bc0 == '\0') {
            bVar1 = true;
            goto LAB_08003b58;
          }
        }
        else {
LAB_08003b58:
          if (((0x10fff < uVar4) || (uVar4 + uVar5 < 0x10000)) || (*DAT_08003bc4 == '\x01')) {
            FUN_08010050(iVar6,uVar4,uVar5,0xfffff < uVar4);
            uVar5 = (uint)local_34[uVar7];
          }
        }
        iVar6 = uVar5 + iVar6;
      }
      if (bVar1) {
        FUN_08009c7c();
      }
    }
    FUN_08003cf0(local_1c,&local_60,6);
  }
  return;
}



// ==== 08003bc8  FUN_08003bc8  (166 bytes, 4 xrefs)

void FUN_08003bc8(int param_1)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = DAT_08003c70;
  if (param_1 == 1) {
    puVar1 = DAT_08003c74;
  }
  uVar2 = (uint)*puVar1;
  iVar3 = uVar2 - DAT_08003c78;
  if (uVar2 == DAT_08003c78) {
    FUN_08003990();
    return;
  }
  if ((int)uVar2 < (int)DAT_08003c78) {
    if (uVar2 == DAT_08003c7c) {
      FUN_08003ab4();
      return;
    }
    if ((int)uVar2 < (int)DAT_08003c7c) {
      if (uVar2 + DAT_08003c80 == 0) {
        FUN_08003720();
        return;
      }
      if (uVar2 + DAT_08003c80 == 7) {
        FUN_080039e8();
      }
    }
    else {
      if (uVar2 - DAT_08003c7c == 2) {
        FUN_080037f8();
        return;
      }
      if (uVar2 - DAT_08003c7c == 4) {
        FUN_080038f0();
        return;
      }
    }
    return;
  }
  if (iVar3 == 8) {
    FUN_08003684();
    return;
  }
  if (iVar3 < 9) {
    if (iVar3 == 2) {
      FUN_080039bc();
      return;
    }
    if (iVar3 != 6) {
      return;
    }
    FUN_0800376c();
  }
  else {
    if (iVar3 == 0xb5) {
      FUN_08010a00(0);
      return;
    }
    if (iVar3 == 0xb6) {
      if (param_1 == 1) {
        FUN_080123ae(400);
      }
      DataSynchronizationBarrier(0xf);
      *(undefined4 *)(DAT_08003c88 + 0xc) = DAT_08003c84;
      DataSynchronizationBarrier(0xf);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  return;
}



// ==== 08003c8c  FUN_08003c8c  (80 bytes, 2 xrefs)

void FUN_08003c8c(undefined4 param_1)

{
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 auStack_2c [16];
  undefined1 local_1c;
  undefined1 local_1b;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_0800299a(&local_30,0x28);
  local_30 = (undefined2)DAT_08003cdc;
  local_2e = 0x24;
  FUN_08002968(auStack_2c,DAT_08003ce0,0x10);
  local_1c = *DAT_08003ce4;
  local_1b = *DAT_08003ce8;
  local_18 = *DAT_08003cec;
  local_14 = DAT_08003cec[1];
  local_10 = DAT_08003cec[2];
  local_c = DAT_08003cec[3];
  FUN_08003cf0(param_1,&local_30,0x28);
  return;
}



// ==== 08003cf0  FUN_08003cf0  (24 bytes, 8 xrefs)

void FUN_08003cf0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == 1) {
    FUN_08010b88(param_2,param_3);
    return;
  }
  FUN_08010974();
  return;
}



// ==== 08003d08  FUN_08003d08  (18 bytes, 9 xrefs)

int FUN_08003d08(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_080028f0(param_1 - param_3);
  return param_2 * iVar1 + param_3;
}



// ==== 08003d1c  FUN_08003d1c  (200 bytes, 2 xrefs)

void FUN_08003d1c(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte local_78 [4];
  undefined4 local_74 [16];
  ushort local_34 [16];
  
  iVar7 = DAT_08003de8;
  uVar2 = *DAT_08003de4;
  *(ushort *)(DAT_08003de8 + 2) = uVar2 << 6;
  FUN_0800a21c(uVar2 << 6,0x40,local_74,local_34,local_78,0x10);
  uVar9 = 0;
  iVar7 = iVar7 + 4;
  for (uVar8 = 0; iVar3 = DAT_08003de8, uVar8 < local_78[0]; uVar8 = uVar8 + 1 & 0xff) {
    FUN_0800ff84(iVar7 + uVar9,local_74[uVar8],local_34[uVar8]);
    uVar9 = local_34[uVar8] + uVar9 & 0xffff;
  }
  uVar5 = FUN_0800f5e8(DAT_08003de8 + 2,0x42);
  *(undefined2 *)(iVar3 + 0x44) = uVar5;
  iVar7 = DAT_08003dec;
  uVar8 = 0;
  do {
    iVar6 = uVar8 * 2 + iVar3;
    uVar9 = uVar8 & 7;
    uVar8 = uVar8 + 1 & 0xff;
    *(ushort *)(iVar6 + 2) = *(ushort *)(iVar6 + 2) ^ *(ushort *)(iVar7 + uVar9 * 2);
    pbVar4 = DAT_08003df0;
  } while (uVar8 < 0x22);
  bVar1 = *DAT_08003df0;
  *DAT_08003df0 = bVar1 + 1;
  if (1 < (byte)(bVar1 + 1)) {
    *pbVar4 = 0;
    uVar2 = *DAT_08003de4;
    *DAT_08003de4 = uVar2 + 1;
    if (0x77 < (ushort)(uVar2 + 1)) {
      *DAT_08003df4 = 2;
    }
  }
  FUN_08004bc4();
  FUN_0800e57c(DAT_08003de8);
  FUN_0800ea98(0);
  FUN_0800e660(1,0);
  *DAT_08003df8 = 0x1e;
  return;
}



// ==== 08003dfc  FUN_08003dfc  (62 bytes, 1 xrefs)

void FUN_08003dfc(void)

{
  *DAT_08003e3c = 0;
  DAT_50000028 = 0x100;
  *DAT_08003e40 = 0;
  if (*(char *)(DAT_08003e44 + 0x19) == '\x01') {
    FUN_0800a8f0();
    FUN_0800a980();
  }
  *DAT_08003e48 = 0x50;
  FUN_080123ae(5);
  FUN_080049a8(1);
  *DAT_08003e4c = 0;
  return;
}



// ==== 08003e50  FUN_08003e50  (28 bytes, 2 xrefs)

void FUN_08003e50(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_08003e6c;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xffff) {
    *(undefined2 *)(param_3 + uVar2 * 2) =
         *(undefined2 *)(iVar1 + (uint)*(byte *)(param_1 + uVar2) * 2);
  }
  return;
}



// ==== 08003e70  FUN_08003e70  (208 bytes, 2 xrefs)

void FUN_08003e70(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  undefined2 uVar3;
  uint uVar4;
  byte bVar5;
  char *extraout_r3;
  char *pcVar6;
  
  pbVar2 = DAT_08003f40;
  bVar1 = *DAT_08003f40;
  uVar4 = ((uint)*DAT_08003f44 + (uint)DAT_08003f44[1] +
           (uint)DAT_08003f44[2] + (uint)DAT_08003f44[3] & 0xffff) >> 2;
  if (DAT_08003f48[5] < uVar4) {
    bVar5 = 6;
  }
  else if (DAT_08003f48[4] < uVar4) {
    bVar5 = 5;
  }
  else if (DAT_08003f48[3] < uVar4) {
    bVar5 = 4;
  }
  else if (DAT_08003f48[2] < uVar4) {
    bVar5 = 3;
  }
  else {
    if (uVar4 <= DAT_08003f48[1]) {
      if (*DAT_08003f48 < uVar4) {
        *DAT_08003f40 = 1;
      }
      else {
        *DAT_08003f40 = 0;
      }
      goto LAB_08003ed2;
    }
    bVar5 = 2;
  }
  *DAT_08003f40 = bVar5;
LAB_08003ed2:
  uVar3 = FUN_080028f0(uVar4 * 0x2f8);
  *DAT_08003f4c = uVar3;
  if ((*DAT_08003f50 == '\x02') && (*DAT_08003f54 == '/')) {
    *DAT_08003f58 = 1;
  }
  pcVar6 = DAT_08003f60;
  if (*DAT_08003f5c < 0x1f5) {
    if (*DAT_08003f60 == '\x01') {
      *DAT_08003f64 = 1;
    }
    *pcVar6 = '\0';
  }
  else {
    if (*DAT_08003f60 == '\0') {
      *DAT_08003f64 = 1;
      FUN_0800904c();
      pcVar6 = extraout_r3;
    }
    *pcVar6 = '\x01';
  }
  if (bVar1 != *pbVar2) {
    if (*pbVar2 < 2) {
      *DAT_08003f68 = 1;
    }
    else {
      *DAT_08003f68 = 0;
      if (param_1 == 1) {
        FUN_0800be44();
      }
    }
    *DAT_08003f6c = 0;
  }
  return;
}



// ==== 08003f70  FUN_08003f70  (32 bytes, 3 xrefs)

uint FUN_08003f70(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = FUN_0800e8d8(*(short *)(DAT_08003f90 + param_2 * 2) + 0x800);
  if (param_1 == 3) {
    uVar1 = uVar1 ^ DAT_08003f94;
  }
  return uVar1;
}



// ==== 08003f98  FUN_08003f98  (222 bytes, 9 xrefs)

void FUN_08003f98(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  uVar2 = FUN_0800408c(**(undefined4 **)(param_1 + 0x10));
  if (uVar2 < 3) {
    iVar3 = DAT_0800407c;
  }
  else {
    iVar3 = 0x10000;
  }
  if (*(byte *)(DAT_08004078 + 0x10) == 0) {
    *(undefined1 *)(param_1 + 0x20) = 0;
    *(undefined1 *)(param_1 + 0x21) = 0x7f;
    *(undefined1 *)(param_1 + 0x22) = 0xff;
    *(undefined1 *)(param_1 + 0x23) = 0;
    *(undefined1 *)(param_1 + 0x24) = 0x7f;
    *(undefined1 *)(param_1 + 0x25) = 0xff;
  }
  else {
    iVar3 = iVar3 + (uint)*(byte *)(DAT_08004078 + 0x10);
    FUN_0800ff84((undefined1 *)(param_1 + 0x20),iVar3,1);
    FUN_0800ff84(param_1 + 0x23,iVar3 + 0x10,1);
    FUN_0800ff84(param_1 + 0x21,iVar3 + 0x20,1);
    FUN_0800ff84(param_1 + 0x24,iVar3 + 0x30,1);
    FUN_0800ff84(param_1 + 0x22,iVar3 + 0x40,1);
    FUN_0800ff84(param_1 + 0x25,iVar3 + 0x50,1);
    if (0x7f < *(byte *)(param_1 + 0x21)) {
      *(undefined1 *)(param_1 + 0x21) = 0x7f;
    }
    if (0x7f < *(byte *)(param_1 + 0x24)) {
      *(undefined1 *)(param_1 + 0x24) = 0x7f;
    }
  }
  iVar3 = FUN_0800408c(**(undefined4 **)(param_1 + 0x14));
  FUN_0800ff84(&local_1c,iVar3 * 0x10 + (uint)*(byte *)(param_1 + 0x27) * 3 + DAT_0800407c + 0x70,3)
  ;
  iVar3 = iVar3 * 4;
  uVar1 = FUN_08004128(local_1c,local_1b,local_1a,*(undefined4 *)(DAT_08004088 + iVar3),
                       *(undefined4 *)(DAT_08004084 + iVar3),*(undefined4 *)(DAT_08004080 + iVar3),
                       **(undefined4 **)(param_1 + 0x14));
  *(undefined1 *)(param_1 + 0x28) = uVar1;
  return;
}



// ==== 0800408c  FUN_0800408c  (98 bytes, 6 xrefs)

undefined4 FUN_0800408c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 5;
  if ((uint)(param_1 + DAT_080040f0) <= DAT_080040f4) {
    return 0;
  }
  if ((uint)(param_1 + DAT_080040f8) <= DAT_080040fc) {
    return 1;
  }
  if ((uint)(param_1 + DAT_08004100) <= DAT_08004104) {
    return 2;
  }
  if ((uint)(param_1 + DAT_08004108) <= DAT_0800410c) {
    return 3;
  }
  if (DAT_08004114 < (uint)(param_1 + DAT_08004110)) {
    if ((DAT_0800411c < (uint)(param_1 + DAT_08004118)) &&
       ((uint)(param_1 + DAT_08004120) <= DAT_08004124)) {
      return 6;
    }
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}



// ==== 08004128  FUN_08004128  (60 bytes, 1 xrefs)

int FUN_08004128(int param_1,int param_2,int param_3,uint param_4,uint param_5,uint param_6,
                uint param_7)

{
  int iVar1;
  
  if (param_4 < param_7) {
    if (param_7 < param_6) {
      if (param_5 < param_7) {
        iVar1 = FUN_0800291c((param_3 - param_2) * (param_7 - param_5),param_6 - param_5,
                             param_3 - param_2,param_4,param_4);
        return iVar1 + param_2;
      }
      iVar1 = FUN_0800291c((param_2 - param_1) * (param_7 - param_4),param_5 - param_4,param_3,
                           param_4,param_4);
      return iVar1 + param_1;
    }
    param_1 = param_3;
  }
  return param_1;
}



// ==== 08004164  FUN_08004164  (78 bytes, 2 xrefs)

void FUN_08004164(uint param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (uint)*(byte *)(*DAT_080041b4 + 0x2e) * 8;
  iVar2 = iVar3 + DAT_080041b8;
  if (*(ushort *)(iVar2 + 6) < param_1) {
    cVar1 = '\x06';
  }
  else if (*(ushort *)(iVar2 + 4) < param_1) {
    cVar1 = '\x04';
  }
  else if (*(ushort *)(iVar2 + 2) < param_1) {
    cVar1 = '\x02';
  }
  else if (*(ushort *)(DAT_080041b8 + iVar3) < param_1) {
    cVar1 = '\x01';
  }
  else {
    cVar1 = '\0';
  }
  if (*(char *)(DAT_080041c0 + (uint)*(byte *)(DAT_080041bc + 8)) != cVar1) {
    *(char *)(DAT_080041c0 + (uint)*(byte *)(DAT_080041bc + 8)) = cVar1;
    FUN_0800bef4();
  }
  return;
}



// ==== 080041c4  FUN_080041c4  (50 bytes, 5 xrefs)

void FUN_080041c4(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x1f);
  iVar2 = *param_1;
  if (cVar1 == '\0') {
LAB_080041e2:
    if (DAT_080041f8 <= iVar2) {
      if (DAT_080041fc < iVar2) {
        iVar2 = DAT_080041fc;
      }
      goto LAB_080041f2;
    }
  }
  else {
    if (cVar1 == '\x01') {
      iVar2 = iVar2 + param_1[6];
      goto LAB_080041e2;
    }
    if (cVar1 == '\x02') {
      iVar2 = iVar2 - param_1[6];
      goto LAB_080041e2;
    }
  }
  iVar2 = DAT_080041f8;
LAB_080041f2:
  param_1[2] = iVar2;
  return;
}



// ==== 08004200  FUN_08004200  (58 bytes, 1 xrefs)

void FUN_08004200(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_18;
  undefined4 local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  iVar4 = FUN_08005408(*PTR_DAT_0800423c,&local_14,&local_18);
  puVar2 = PTR_DAT_08004240;
  if (iVar4 == 0) {
    bVar1 = *PTR_DAT_08004240;
    bVar3 = (byte)local_14;
    if (((byte)local_14 <= bVar1) && (bVar3 = bVar1, (byte)local_18 < bVar1)) {
      bVar3 = (byte)local_18;
    }
    uVar5 = FUN_08004284(bVar3,param_1,(byte)local_14,local_18 & 0xff);
    *(undefined4 *)puVar2 = uVar5;
  }
  return;
}



// ==== 08004244  FUN_08004244  (56 bytes, 2 xrefs)

void FUN_08004244(uint *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1 + param_2 * (uint)(ushort)param_1[7];
  iVar2 = (uint)*(byte *)((int)param_1 + 0x2e) * 4;
  uVar4 = *(uint *)(*DAT_0800427c + iVar2);
  uVar3 = *(uint *)(*DAT_08004280 + iVar2);
  if (uVar4 < uVar1) {
    uVar1 = uVar3;
  }
  else if (uVar1 < uVar3) {
    uVar1 = FUN_08003d08(uVar4);
  }
  *param_1 = uVar1;
  return;
}



// ==== 08004284  FUN_08004284  (24 bytes, 5 xrefs)

uint FUN_08004284(char param_1,char param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(param_1 + param_2);
  if ((uVar1 == 0xff) || (uVar1 < param_3)) {
    uVar1 = param_4;
  }
  else if (param_4 < uVar1) {
    return param_3;
  }
  return uVar1;
}



// ==== 0800429c  FUN_0800429c  (150 bytes, 2 xrefs)

undefined4 FUN_0800429c(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_e8 [4];
  uint local_d8 [4];
  undefined1 auStack_c8 [176];
  uint local_18 [4];
  
  local_d8[0] = *param_2;
  local_d8[1] = param_2[1];
  local_d8[2] = param_2[2];
  local_d8[3] = param_2[3];
  local_e8[0] = *param_1;
  local_e8[1] = param_1[1];
  local_e8[2] = param_1[2];
  local_e8[3] = param_1[3];
  uVar2 = 0;
  do {
    uVar3 = local_e8[uVar2];
    uVar1 = uVar2 + 1 & 0xff;
    local_e8[uVar2] =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    uVar2 = uVar1;
  } while (uVar1 < 4);
  uVar2 = 0;
  do {
    uVar3 = local_d8[uVar2];
    uVar1 = uVar2 + 1 & 0xff;
    local_d8[uVar2] =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    uVar2 = uVar1;
  } while (uVar1 < 4);
  FUN_080035ac(local_e8,auStack_c8,4,10);
  FUN_08010bf8(local_d8,local_18,auStack_c8);
  uVar2 = 0;
  do {
    uVar3 = local_18[uVar2];
    uVar1 = uVar2 + 1 & 0xff;
    local_18[uVar2] =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    uVar2 = uVar1;
  } while (uVar1 < 4);
  uVar2 = 0;
  do {
    if (local_18[uVar2] != *(uint *)(param_3 + uVar2 * 4)) {
      return 1;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  return 0;
}



// ==== 08004334  FUN_08004334  (46 bytes, 1 xrefs)

uint FUN_08004334(short param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0x32;
  uVar2 = 0xff;
  uVar4 = 0;
  do {
    sVar1 = param_1 - *(short *)(DAT_08004364 + uVar4 * 2);
    uVar3 = (uint)sVar1;
    if ((int)uVar3 < 0) {
      uVar3 = (uint)-sVar1;
    }
    if ((int)uVar3 < (int)uVar5) {
      uVar5 = uVar3 & 0xffff;
      uVar2 = uVar4;
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0x32);
  return uVar2;
}



// ==== 08004368  FUN_08004368  (84 bytes, 1 xrefs)

uint FUN_08004368(uint param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = 0;
  do {
    if ((param_1 & 0xfff) >> 9 == 4) {
      uVar2 = 0;
      do {
        if (((uint)*(ushort *)(DAT_080043bc + uVar2 * 2) == (param_1 & 0x1ff)) &&
           (uVar1 = FUN_08003f70(2,uVar2), uVar1 == param_1)) {
          return uVar2;
        }
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 0x68);
    }
    uVar2 = param_1 >> 1;
    if ((param_1 & 1) != 0) {
      uVar2 = uVar2 | 0x400000;
    }
    bVar3 = bVar3 + 1;
    param_1 = uVar2;
  } while (bVar3 < 0x17);
  return 0xff;
}



// ==== 080043c0  FUN_080043c0  (86 bytes, 1 xrefs)

undefined4 FUN_080043c0(void)

{
  undefined *puVar1;
  undefined2 *puVar2;
  undefined1 uVar3;
  uint in_r3;
  uint uVar4;
  undefined4 uVar5;
  uint local_18;
  
  puVar1 = PTR_GPIOB_08004418;
  uVar5 = 0;
  uVar4 = 0;
  local_18 = in_r3;
  do {
    if ((~*(uint *)(puVar1 + 0x10) & 0x400) == 0) {
      return 0;
    }
    uVar3 = FUN_0800f900();
    *(undefined1 *)((int)&local_18 + uVar4) = uVar3;
    FUN_080123ae(0x14);
    puVar2 = DAT_08004424;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  uVar4 = local_18 & 0xff;
  if (uVar4 == (local_18 >> 8 & 0xff)) {
    *DAT_0800441c = (undefined1)local_18;
    *DAT_08004420 = (undefined1)local_18;
    *puVar2 = 2;
    if (uVar4 == 0x17) {
      uVar5 = 1;
    }
    else if (uVar4 == 0x16) {
      uVar5 = 2;
    }
  }
  return uVar5;
}



// ==== 08004428  FUN_08004428  (402 bytes, 2 xrefs)

undefined1 FUN_08004428(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  uint *puVar15;
  int iVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  uint *puVar21;
  
  iVar12 = DAT_080045c0;
  iVar2 = DAT_080045bc;
  iVar16 = DAT_080045bc + 0x40;
  puVar17 = (undefined4 *)(DAT_080045bc + 0x68);
  iVar3 = DAT_080045bc + 0xd8;
  puVar4 = (undefined4 *)(DAT_080045bc + 0x128);
  iVar5 = DAT_080045bc + 0x138;
  uVar6 = 0;
  puVar15 = (uint *)(DAT_080045bc + 0x78);
  iVar18 = DAT_080045bc + 0x88;
  do {
    puVar8 = (undefined4 *)(uVar6 * 8 + iVar12);
    iVar7 = uVar6 * 4;
    *(undefined4 *)(iVar2 + iVar7) = *puVar8;
    uVar6 = uVar6 + 1 & 0xff;
    *(undefined4 *)(iVar16 + iVar7) = puVar8[1];
  } while (uVar6 < 10);
  uVar6 = 0;
  do {
    iVar7 = uVar6 * 4;
    uVar9 = *(uint *)(iVar16 + iVar7);
    uVar6 = uVar6 + 1 & 0xff;
    *(uint *)(iVar16 + iVar7) =
         uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 | uVar9 >> 0x18;
  } while (uVar6 < 10);
  uVar6 = 0;
  do {
    iVar7 = uVar6 * 4;
    uVar6 = uVar6 + 1 & 0xff;
    *(undefined4 *)(iVar7 + iVar2 + 0x28) = *(undefined4 *)(iVar7 + iVar12 + 0x50);
  } while (uVar6 < 6);
  uVar1 = 1;
  FUN_0800f5b0(puVar4);
  puVar8 = DAT_080045c4;
  *puVar17 = *DAT_080045c4;
  *(undefined4 *)(iVar2 + 0x6c) = puVar8[1];
  *(undefined4 *)(iVar2 + 0x70) = *puVar4;
  *(undefined4 *)(iVar2 + 0x74) = *(undefined4 *)(iVar2 + 0x130);
  uVar6 = 0;
  do {
    uVar10 = puVar17[uVar6];
    uVar9 = uVar6 + 1 & 0xff;
    puVar17[uVar6] =
         uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
         uVar10 >> 0x18;
    uVar6 = uVar9;
  } while (uVar9 < 4);
  *puVar15 = puVar8[2];
  *(undefined4 *)(iVar2 + 0x7c) = puVar8[3];
  *(undefined4 *)(iVar2 + 0x80) = *(undefined4 *)(iVar2 + 300);
  *(undefined4 *)(iVar2 + 0x84) = *(undefined4 *)(iVar2 + 0x134);
  uVar6 = 0;
  do {
    uVar10 = puVar15[uVar6];
    uVar9 = uVar6 + 1 & 0xff;
    puVar15[uVar6] =
         uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
         uVar10 >> 0x18;
    uVar6 = uVar9;
  } while (uVar9 < 4);
  uVar6 = 0;
  do {
    puVar11 = (undefined4 *)(uVar6 * 0x10 + iVar2);
    uVar13 = puVar11[1];
    uVar19 = puVar11[2];
    uVar20 = puVar11[3];
    puVar8 = (undefined4 *)(uVar6 * 0x14 + iVar18);
    *puVar8 = *puVar11;
    puVar8[1] = uVar13;
    puVar8[2] = uVar19;
    puVar8[3] = uVar20;
    puVar8[4] = puVar4[uVar6];
    uVar9 = 0;
    do {
      iVar12 = (uVar6 * 5 + uVar9) * 4;
      uVar10 = *(uint *)(iVar18 + iVar12);
      uVar9 = uVar9 + 1 & 0xff;
      *(uint *)(iVar18 + iVar12) =
           uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
           uVar10 >> 0x18;
    } while (uVar9 < 5);
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 4);
  FUN_080035ac(puVar17,iVar5,4,10);
  uVar6 = 0;
  do {
    iVar7 = uVar6 * 0x10;
    *(uint *)(iVar18 + iVar7) = *(uint *)(iVar18 + iVar7) ^ *puVar15;
    iVar12 = iVar7 + iVar18;
    *(uint *)(iVar12 + 4) = *(uint *)(iVar12 + 4) ^ *(uint *)(iVar2 + 0x7c);
    *(uint *)(iVar12 + 8) = *(uint *)(iVar12 + 8) ^ *(uint *)(iVar2 + 0x80);
    *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) ^ *(uint *)(iVar2 + 0x84);
    puVar21 = (uint *)(iVar7 + iVar3);
    FUN_08010bf8(iVar12,puVar21,iVar5);
    uVar9 = puVar21[1];
    uVar10 = puVar21[2];
    uVar14 = puVar21[3];
    *puVar15 = *puVar21;
    *(uint *)(iVar2 + 0x7c) = uVar9;
    *(uint *)(iVar2 + 0x80) = uVar10;
    *(uint *)(iVar2 + 0x84) = uVar14;
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 5);
  uVar6 = 0;
  do {
    if (*(uint *)(iVar16 + uVar6 * 4) !=
        (*(uint *)(iVar3 + uVar6 * 4) ^ *(uint *)(iVar3 + (0x13 - uVar6) * 4))) {
      uVar1 = 0;
      break;
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 10);
  *DAT_080045c8 = uVar1;
  return uVar1;
}



// ==== 080045cc  FUN_080045cc  (220 bytes, 1 xrefs)

undefined4 FUN_080045cc(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (0xce < *(byte *)(param_1 + 0x1e)) {
    return 0xffffffff;
  }
  cVar1 = *DAT_080046a8;
  iVar3 = **(int **)(param_1 + 0x14);
  if (cVar1 == '\x01') {
    if ((uint)(iVar3 + DAT_080046ac) <= DAT_080046b0) {
      return 0;
    }
    iVar2 = DAT_080046d4;
LAB_08004644:
    if ((uint)(iVar3 + iVar2) <= DAT_080046dc) {
      return 0;
    }
  }
  else {
    uVar4 = DAT_080046b8;
    iVar2 = DAT_080046b4;
    if (cVar1 == '\x02') {
      if ((uint)(iVar3 + DAT_080046ac) <= DAT_080046d8) {
        return 0;
      }
    }
    else if (cVar1 == '\x03') {
      if ((uint)(iVar3 + DAT_080046ac) <= DAT_080046b0) {
        return 0;
      }
    }
    else {
      if (cVar1 == '\x04') {
        iVar2 = DAT_080046c0;
        if ((uint)(iVar3 + DAT_080046bc) <= DAT_080046c4) {
          return 0;
        }
        goto LAB_08004644;
      }
      if (cVar1 != '\x05') {
        if (cVar1 == '\x06') {
          if ((uint)(iVar3 + DAT_080046ac) <= DAT_080046b0) {
            return 0;
          }
          if (DAT_080046e0 < (uint)(iVar3 + DAT_080046b4)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((uint)(iVar3 + DAT_080046bc) <= DAT_080046c4) {
          return 0;
        }
        if ((((uint)(iVar3 + DAT_080046c8) <= DAT_080046cc) && (*DAT_080046d0 == '\x01')) &&
           (*DAT_080046e4 != '\0')) {
          return 0;
        }
        if ((uint)(iVar3 + DAT_080046c0) <= DAT_080046e8) {
          return 0;
        }
        if (((uint)(iVar3 + DAT_080046ec) <= DAT_080046f0) && (*DAT_080046f4 == '\x01')) {
          return 0;
        }
        if (DAT_080046fc < (uint)(iVar3 + DAT_080046f8)) {
          return 0xffffffff;
        }
        if (*DAT_08004700 == '\x01') {
          return 0;
        }
        return 0xffffffff;
      }
      uVar4 = DAT_080046c4;
      iVar2 = DAT_080046c0;
      if ((uint)(iVar3 + DAT_080046bc) <= DAT_080046c4) {
        return 0;
      }
    }
    if ((uint)(iVar3 + iVar2) <= uVar4) {
      return 0;
    }
  }
  return 0xffffffff;
}



// ==== 08004704  FUN_08004704  (72 bytes, 8 xrefs)

undefined4 FUN_08004704(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  
  if ((199 < param_1) || (uVar2 = (uint)*(byte *)(DAT_0800474c + param_1), 6 < (uVar2 & 0xf))) {
    return 0;
  }
  if (param_2 == 1) {
    if (param_3 == 0) {
      if (-1 < (int)(uVar2 << 0x18)) {
        return 0;
      }
      if (*(byte *)(DAT_08004750 + 2) == param_1) {
        return 0;
      }
      bVar1 = *(byte *)(DAT_08004750 + 4);
    }
    else {
      if (param_3 != 1) {
        return 1;
      }
      if (-1 < (int)(uVar2 << 0x19)) {
        return 0;
      }
      if (*(byte *)(DAT_08004750 + 3) == param_1) {
        return 0;
      }
      bVar1 = *(byte *)(DAT_08004750 + 5);
    }
    if (bVar1 == param_1) {
      return 0;
    }
  }
  return 1;
}



// ==== 08004754  FUN_08004754  (32 bytes, 2 xrefs)

undefined4 FUN_08004754(uint param_1)

{
  if ((param_1 < 0x14) && (*(ushort *)(DAT_08004774 + param_1 * 2) - 0x2f8 < 0x141)) {
    return 1;
  }
  return 0;
}



// ==== 08004778  FUN_08004778  (366 bytes, 1 xrefs)

void FUN_08004778(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined1 auStack_48 [32];
  int local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  
  local_20 = DAT_080048e8;
  FUN_08002968(auStack_48,DAT_080048e8,0x20);
  iVar2 = DAT_080048e8;
  puVar9 = (undefined1 *)(DAT_080048e8 + -0x78);
  local_1c = (uint)*(byte *)(DAT_080048e8 + -0x5e);
  local_18 = (uint)*(byte *)(DAT_080048e8 + -0x83);
  local_28 = DAT_080048e8 + -0x18;
  local_24 = (uint)*(byte *)(DAT_080048e8 + -3);
  uVar8 = 0x1000;
  do {
    if ((((0xfff < uVar8 - 0x8000) && (0x3fff < uVar8 - 0xa000)) && (0xfff < uVar8 - 0xf000)) &&
       ((param_1 == 1 ||
        ((((0xfff < uVar8 && (199 < uVar8 - 0x2000)) &&
          ((0xfff < uVar8 - 0x9000 && ((0xfff < uVar8 - 0xe000 && (0xfff < uVar8 - 0x3000)))))) &&
         (0xfff < uVar8 - 0x6000)))))) {
      FUN_0800fefc(uVar8);
    }
    uVar8 = uVar8 + 0x1000;
  } while (uVar8 < 0x10000);
  FUN_0800aa00();
  FUN_08002968(local_20,auStack_48,0x20);
  *(char *)(iVar2 + -0x5e) = (char)local_1c;
  *(char *)(DAT_080048e8 + -0x83) = (char)local_18;
  *(char *)(local_28 + 0x15) = (char)local_24;
  if (param_1 == 1) {
    *(undefined1 *)(DAT_080048e8 + -0x79) = 0;
    *puVar9 = 0;
    *(undefined1 *)(iVar2 + -0x77) = 0;
  }
  FUN_0800a67c();
  piVar3 = DAT_080048f0;
  FUN_0800a9a8(*DAT_080048f0,0xcd,5,DAT_080048ec);
  uVar8 = 0;
  do {
    uVar5 = *(undefined4 *)(DAT_080048f4 + uVar8 * 4);
    puVar6 = (undefined4 *)*piVar3;
    *puVar6 = uVar5;
    puVar6[2] = uVar5;
    *(char *)((int)puVar6 + 0x2e) = (char)uVar8;
    cVar1 = (char)uVar8 + -0x38;
    FUN_0800a570(cVar1,0,puVar6,2);
    FUN_0800a570(cVar1,1,*piVar3,2);
    iVar2 = DAT_080048f8;
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 7);
  if (param_1 == 1) {
    uVar8 = 0;
    do {
      uVar5 = *(undefined4 *)(iVar2 + uVar8 * 4);
      puVar6 = (undefined4 *)*piVar3;
      *puVar6 = uVar5;
      puVar6[2] = uVar5;
      FUN_08011998(puVar6 + 0xd,s_CH__03d_080048fc,uVar8 + 1);
      uVar4 = FUN_0800408c(uVar5);
      iVar7 = *piVar3;
      *(undefined1 *)(iVar7 + 0x2e) = uVar4;
      FUN_0800a570(uVar8,0,iVar7,2);
      uVar8 = uVar8 + 1 & 0xff;
    } while (uVar8 < 5);
  }
  iVar2 = DAT_080048e8;
  *(undefined1 *)(DAT_080048e8 + -0x98) = 0xcd;
  *(undefined1 *)(iVar2 + -0x97) = 0xcd;
  *(undefined1 *)(iVar2 + -0x94) = 0;
  *(undefined1 *)(iVar2 + -0x93) = 0;
  *(undefined1 *)(iVar2 + -0x96) = 0xcd;
  *(undefined1 *)(iVar2 + -0x95) = 0xcd;
  *(undefined1 *)(iVar2 + -0x92) = 0xcf;
  *(undefined1 *)(iVar2 + -0x91) = 0xcf;
  FUN_0800a534();
  return;
}



// ==== 08004904  FUN_08004904  (22 bytes, 1 xrefs)

void FUN_08004904(void)

{
  FUN_0800fefc(0x3000);
  FUN_0800298c(DAT_0800491c,0x28,0xff);
  return;
}



// ==== 08004920  FUN_08004920  (42 bytes, 4 xrefs)

void FUN_08004920(void)

{
  undefined *puVar1;
  
  *PTR_DAT_0800494c = 0;
  puVar1 = PTR_DAT_08004954;
  *PTR_DAT_08004950 = 0;
  *puVar1 = 0xff;
  FUN_0800298c(PTR_DAT_08004958,0x12,0xff);
  *(undefined4 *)PTR_DAT_0800495c = 0;
  *PTR_DAT_08004960 = 0;
  *PTR_DAT_08004964 = 0;
  return;
}



// ==== 08004968  FUN_08004968  (44 bytes, 2 xrefs)

void FUN_08004968(void)

{
  *DAT_08004994 = 0;
  *DAT_08004998 = 0;
  *DAT_0800499c = 0;
  DAT_50000028 = 0x100;
  *DAT_080049a0 = 0;
  FUN_0800e0fc(0,0);
  *DAT_080049a4 = 1;
  return;
}



// ==== 080049a8  FUN_080049a8  (472 bytes, 20 xrefs)

void FUN_080049a8(int param_1)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = *DAT_08004b80;
  DAT_50000028 = 0x100;
  *DAT_08004b84 = 0;
  FUN_0800e660(5,0);
  FUN_0800e660(6,0);
  FUN_0800ea98(0);
  FUN_0800e660(1,0);
  sVar5 = 200;
  do {
    uVar4 = FUN_0800e900(0xc);
    if ((uVar4 & 1) == 0) break;
    FUN_0800ee64(2,0);
    sVar5 = sVar5 + -1;
    FUN_080123ae(1);
  } while (sVar5 != 0);
  FUN_0800ee64(0x3f,0);
  cVar1 = *(char *)(iVar7 + 0x33);
  if (cVar1 == '\x01') {
    uVar3 = 3;
  }
  else {
    uVar3 = 0;
    if (*(char *)(iVar7 + 0x2b) != '\0') {
      uVar3 = 1;
    }
  }
  FUN_0800e9f0(uVar3);
  FUN_0800ee64(0x7d,*(byte *)(DAT_08004b88 + 2) | DAT_08004b8c);
  if ((*(byte *)(iVar7 + 0x1e) < 0xcf) || (*DAT_08004b90 != '\x01')) {
    uVar6 = **(undefined4 **)(iVar7 + 0x10);
  }
  else {
    uVar6 = *(undefined4 *)(DAT_08004ba0 + (uint)*DAT_08004b9c * 4);
  }
  FUN_0800ea80(uVar6);
  if (cVar1 == '\x01') {
    FUN_0800e364();
  }
  else {
    FUN_0800e48c();
  }
  FUN_08004d04(uVar6);
  FUN_0800ee64(0x48,DAT_08004b94);
  uVar4 = 0xc;
  FUN_0800ea2c(0);
  if (*(byte *)(iVar7 + 0x1e) < 0xcf) {
    if (cVar1 != '\x01') {
      cVar2 = *(char *)(*(int *)(iVar7 + 0x10) + 4);
      if ((cVar2 == '\x02') || (cVar2 == '\x03')) {
        FUN_08003f70();
        FUN_0800e9b8();
        uVar4 = 0x3cc;
      }
      else if (cVar2 == '\x01') {
        FUN_0800ea44(*(undefined2 *)(DAT_08004bac + (uint)*(byte *)(*(int *)(iVar7 + 0x10) + 5) * 2)
                    );
        FUN_0800eab8();
        uVar4 = DAT_08004bb0;
      }
      else {
        FUN_0800ea44(DAT_08004ba4);
        FUN_0800ea2c(1);
        uVar4 = 0xcc;
      }
      if ((*(char *)(iVar7 + 0x2a) == '\0') || (*DAT_08004ba8 == '\0')) {
        FUN_0800e4d8();
      }
      else {
        FUN_0800e408(*(char *)(iVar7 + 0x2a) + -1);
      }
    }
  }
  else {
    FUN_0800ea44(DAT_08004b98);
    uVar4 = 0xcc;
  }
  if ((*(char *)(DAT_08004b88 + -0x2d) == '\x01') && (*DAT_08004bb4 != '\x01')) {
    if ((*(byte *)(*DAT_08004bb8 + 0x1e) < 0xcf) && (*(char *)(*DAT_08004bb8 + 0x33) != '\x01')) {
      FUN_0800e444(*(undefined2 *)(DAT_08004b88 + -0x18),*(undefined2 *)(DAT_08004b88 + -0x16));
      uVar4 = uVar4 | 0x30;
      goto LAB_08004b22;
    }
  }
  FUN_0800e502();
  uVar4 = uVar4 & 0xffffffcf;
LAB_08004b22:
  if ((cVar1 == '\x01') || ((*(char *)(iVar7 + 0x2f) != '\x01' && (*DAT_08004bbc != '\x01')))) {
    FUN_0800e4cc();
    uVar4 = uVar4 & DAT_08004bc0;
  }
  else {
    FUN_0800e3a8();
    uVar4 = uVar4 | 0x800;
  }
  FUN_0800ee64(0x3f,uVar4);
  FUN_0800e944(*(undefined1 *)(iVar7 + 0x20),*(undefined1 *)(iVar7 + 0x23),
               *(undefined1 *)(iVar7 + 0x21),*(undefined1 *)(iVar7 + 0x24),
               *(undefined1 *)(iVar7 + 0x22),*(undefined1 *)(iVar7 + 0x25));
  FUN_0800e660(0,1);
  FUN_0800a2b8();
  if (param_1 == 1) {
    FUN_0800b2fc(0);
  }
  return;
}



// ==== 08004bc4  FUN_08004bc4  (158 bytes, 3 xrefs)

void FUN_08004bc4(void)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  
  iVar4 = *DAT_08004c64;
  uVar1 = *(undefined1 *)(iVar4 + 0x28);
  puVar5 = *(undefined4 **)(iVar4 + 0x14);
  cVar2 = *(char *)(puVar5 + 1);
  bVar3 = *(byte *)((int)puVar5 + 5);
  uVar7 = *puVar5;
  DAT_50000028 = 0x100;
  *DAT_08004c68 = 0;
  FUN_0800e660(0,0);
  FUN_0800e9f0(*(char *)(iVar4 + 0x2b) != '\0');
  FUN_0800e4cc();
  FUN_0800ea80(uVar7);
  FUN_0800ee20();
  FUN_080123ae(10);
  FUN_08004d04(uVar7);
  FUN_0800e660(1);
  FUN_080123ae(5);
  FUN_0800ea98(uVar1,uVar7);
  FUN_080123ae(10);
  if (cVar2 == '\x01') {
    FUN_0800ea44(*(undefined2 *)(DAT_08004c6c + (uint)bVar3 * 2));
    return;
  }
  if ((cVar2 == '\x02') || (cVar2 == '\x03')) {
    uVar6 = FUN_08003f70(cVar2,(uint)bVar3);
    FUN_0800e9b8(uVar6 ^ DAT_08004c70);
    return;
  }
  FUN_0800e4f6();
  return;
}



// ==== 08004c74  FUN_08004c74  (86 bytes, 7 xrefs)

void FUN_08004c74(void)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = DAT_08004ccc;
  cVar1 = *(char *)(DAT_08004ccc + 0x1b);
  if (cVar1 == '\x02') {
LAB_08004c92:
    *(undefined1 *)(DAT_08004ccc + 9) = 1;
  }
  else {
    if (cVar1 != '\x01') {
      if (*(char *)(DAT_08004ccc + 0x1a) == '\x02') goto LAB_08004c92;
      if (*(char *)(DAT_08004ccc + 0x1a) != '\x01') goto LAB_08004c98;
    }
    *(undefined1 *)(DAT_08004ccc + 9) = 0;
  }
LAB_08004c98:
  bVar3 = *(byte *)(iVar2 + 9);
  *DAT_08004cd0 = (uint)bVar3 * 0x44 + iVar2 + 0xb8;
  if (cVar1 != '\0') {
    if (bVar3 == 0) {
      bVar3 = 1;
    }
    else {
      bVar3 = 0;
    }
  }
  *(byte *)(iVar2 + 8) = bVar3;
  *DAT_08004cd4 = (uint)bVar3 * 0x44 + iVar2 + 0xb8;
  FUN_08004cd8();
  return;
}



// ==== 08004cd8  FUN_08004cd8  (30 bytes, 2 xrefs)

void FUN_08004cd8(void)

{
  int iVar1;
  
  if (*(char *)(DAT_08004cf8 + 0x1b) == '\0') {
    iVar1 = *DAT_08004d00;
  }
  else {
    iVar1 = (uint)*(byte *)(DAT_08004cf8 + 9) * 0x44 + DAT_08004cf8 + 0xb8;
  }
  *DAT_08004cfc = iVar1;
  return;
}



// ==== 08004d04  FUN_08004d04  (62 bytes, 4 xrefs)

void FUN_08004d04(uint param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 < DAT_08004d44) {
    bVar1 = true;
LAB_08004d24:
    uVar3 = 0;
  }
  else {
    bVar1 = false;
    if (param_1 == 0xffffffff) goto LAB_08004d24;
    bVar1 = false;
    uVar3 = 1;
  }
  *(bool *)DAT_08004d48 = bVar1;
  if (bVar1) {
    uVar2 = 1;
  }
  else {
    if (*DAT_08004d4c != '\0') goto LAB_08004d38;
    uVar2 = 0;
  }
  FUN_0800e660(4,uVar2);
LAB_08004d38:
  FUN_0800e660(3,uVar3);
  return;
}



// ==== 08004d50  FUN_08004d50  (40 bytes, 7 xrefs)

void FUN_08004d50(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = 7;
  bVar3 = 0;
  do {
    uVar1 = FUN_080028f0(param_1,10);
    *(char *)(param_2 + uVar2) = (char)param_1 + (char)uVar1 * -10;
    bVar3 = bVar3 + 1;
    uVar2 = uVar2 - 1 & 0xff;
    param_1 = uVar1;
  } while (bVar3 < 8);
  return;
}



// ==== 08004d78  FUN_08004d78  (40 bytes, 5 xrefs)

void FUN_08004d78(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  iVar1 = DAT_08004da0;
  do {
    if (9 < *(byte *)(param_1 + uVar2)) break;
    iVar3 = iVar1 * (uint)*(byte *)(param_1 + uVar2) + iVar3;
    iVar1 = FUN_080028f0(iVar1,10);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 8);
  *param_2 = iVar3;
  return;
}



// ==== 08004da4  FUN_08004da4  (36 bytes, 1 xrefs)

undefined4 FUN_08004da4(int param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; (uVar1 < param_2 && (*(char *)(param_1 + uVar1) != *(char *)(DAT_08004dc8 + 1)));
      uVar1 = uVar1 + 1 & 0xff) {
  }
  if (uVar1 < param_2) {
    return 1;
  }
  return 0;
}



// ==== 08004dcc  FUN_08004dcc  (70 bytes, 8 xrefs)

undefined4 FUN_08004dcc(char *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((*param_1 == -1) || (*param_1 == '\0')) {
    return 0;
  }
  uVar2 = 0;
  while( true ) {
    if (param_2 <= uVar2) {
      return 1;
    }
    uVar1 = (uint)(byte)param_1[uVar2];
    if ((uVar1 == 0) || (uVar1 == 0xff)) break;
    if ((((9 < uVar1 - 0x30) && (3 < uVar1 - 0x41)) && (uVar1 != 0x2a)) && (uVar1 != 0x23)) {
      return 0;
    }
    uVar2 = uVar2 + 1 & 0xff;
  }
  param_1[uVar2] = '\0';
  return 1;
}



// ==== 08004e14  FUN_08004e14  (48 bytes, 5 xrefs)

undefined4 FUN_08004e14(int param_1,int param_2,uint param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = *(char *)(DAT_08004e44 + 1);
  do {
    if (param_3 <= uVar2) {
      return 1;
    }
    if (*(char *)(param_1 + uVar2) != *(char *)(param_2 + uVar2)) {
      if ((param_4 != 1) || (*(char *)(param_1 + uVar2) != cVar1)) {
        return 0;
      }
      *DAT_08004e48 = 1;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}



// ==== 08004e4c  FUN_08004e4c  (12 bytes, 3 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x08004f62

// ==== 08004e88  FUN_08004e88  (80 bytes, 3 xrefs)

undefined4 FUN_08004e88(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  undefined1 auStack_28 [8];
  char local_20 [12];
  
  bVar3 = 0;
  do {
    iVar1 = FUN_08004ed8(bVar3,auStack_28);
    if (iVar1 != 1) {
      return 0;
    }
    uVar2 = 0;
    do {
      if (*(char *)(param_1 + uVar2) != local_20[uVar2]) break;
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 3);
    if (uVar2 == 3) {
      FUN_08002968(param_2,auStack_28,8);
      *(undefined1 *)(param_2 + 8) = 0;
      return 1;
    }
    bVar3 = bVar3 + 1;
    if (0xf < bVar3) {
      return 0;
    }
  } while( true );
}



// ==== 08004ed8  FUN_08004ed8  (32 bytes, 2 xrefs)

void FUN_08004ed8(int param_1,int param_2)

{
  FUN_0800ff84(param_2,param_1 * 0x10 + 0xf000,0x10);
  FUN_08004dcc(param_2 + 8,3);
  return;
}



// ==== 08004ef8  FUN_08004ef8  (24 bytes, 1 xrefs)

void FUN_08004ef8(void)

{
  FUN_0800b5c0();
  FUN_080123ae(200);
  FUN_0800a980();
  FUN_080049a8(1);
  return;
}



// ==== 08004f10  FUN_08004f10  (60 bytes, 7 xrefs)

uint FUN_08004f10(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  while( true ) {
    if (param_1 == 0xff) {
      param_1 = 199;
    }
    else if (199 < param_1) {
      param_1 = 0;
    }
    iVar1 = FUN_08004704(param_1,param_3,param_4);
    if (iVar1 == 1) break;
    bVar2 = bVar2 + 1;
    param_1 = param_1 + param_2 & 0xff;
    if (199 < bVar2) {
      return 0xff;
    }
  }
  return param_1;
}



// ==== 08004f4c  FUN_08004f4c  (52 bytes, 2 xrefs)

int FUN_08004f4c(uint param_1,int param_2)

{
  int iVar1;
  int extraout_r2;
  uint uVar2;
  int extraout_r3;
  undefined8 uVar3;
  
  uVar2 = 0;
  iVar1 = param_2;
  while( true ) {
    if (param_1 == 0xff) {
      param_1 = 0x13;
    }
    else if (0x13 < param_1) {
      param_1 = 0;
    }
    uVar3 = FUN_08004754(param_1,iVar1,param_1,uVar2);
    iVar1 = (int)((ulonglong)uVar3 >> 0x20);
    if ((int)uVar3 == 1) break;
    uVar2 = extraout_r3 + 1U & 0xff;
    param_1 = extraout_r2 + param_2 & 0xff;
    if (0x13 < uVar2) {
      return 0xff;
    }
  }
  return extraout_r2;
}



// ==== 08004f80  FUN_08004f80  (52 bytes, 4 xrefs)

undefined4 FUN_08004f80(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_08004fb4;
  *(undefined2 *)(DAT_08004fb4 + 0x30) = *(undefined2 *)(DAT_08004fb4 + 0x2c);
  if (*(char *)(iVar1 + 0x2f) == '\x01') {
    iVar2 = FUN_08004f4c(*(undefined1 *)(iVar1 + 0x2e),1);
    if (iVar2 == 0xff) {
      *(undefined1 *)(iVar1 + 0x2f) = 0;
      return 0xffffffff;
    }
    *(char *)(iVar1 + 0x2e) = (char)iVar2;
    *(undefined2 *)(iVar1 + 0x30) = *(undefined2 *)(DAT_08004fb8 + iVar2 * 2);
  }
  return 0;
}



// ==== 08004fbc  FUN_08004fbc  (344 bytes, 1 xrefs)

void FUN_08004fbc(uint param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  byte bVar7;
  uint uVar8;
  undefined1 uVar9;
  uint uVar10;
  int iVar11;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  
  pbVar3 = DAT_08005124;
  pbVar6 = DAT_0800511c;
  puVar2 = DAT_08005118;
  local_18 = (uint)*DAT_0800511c;
  uVar10 = (uint)*DAT_08005120;
  uVar8 = (uint)*DAT_08005128;
  bVar7 = (byte)(local_18 + 1);
  if (*(char *)(DAT_08005114 + 0x16) != '\0') {
    bVar1 = *DAT_0800512c;
    if ((*(char *)(DAT_08005114 + 0x16) == '\x01') && (bVar1 == 0)) {
      if ((param_1 == 0) || (param_1 == 1)) goto LAB_08005046;
    }
    else if ((param_1 == 0) || (param_1 == 1)) goto LAB_0800503a;
    *DAT_08005130 = 0;
    if ((uVar8 != 0xff) && (param_1 != uVar8)) {
      *DAT_0800511c = bVar7;
      *DAT_08005128 = 0xff;
      *pbVar3 = 0;
    }
    if (((int)(uVar10 - 1) <= (int)(uint)*DAT_0800511c) || (5 < bVar1)) {
LAB_0800503a:
      *puVar2 = 2;
      return;
    }
    iVar11 = *DAT_08005134 * 10 + param_1;
    local_20 = param_2;
    local_1c = param_3;
    iVar5 = FUN_080090bc(iVar11,&local_20,&local_1c);
    if (iVar5 != 1) goto LAB_0800503a;
    *DAT_08005154 = (undefined2)local_20;
    *DAT_08005158 = (undefined1)local_1c;
    *DAT_0800515c = 0;
    *DAT_08005160 = 0;
    FUN_08009168();
    *DAT_08005134 = iVar11;
    bVar7 = *DAT_0800512c + 1;
    pbVar6 = DAT_0800512c;
    goto LAB_08005110;
  }
LAB_08005046:
  if (uVar10 <= local_18) goto LAB_0800503a;
  *DAT_08005130 = 0;
  pbVar4 = DAT_08005128;
  if ((uVar8 != 0xff) && (param_1 != uVar8)) {
    *pbVar6 = bVar7;
    *pbVar4 = 0xff;
    *pbVar3 = 0;
    if (uVar10 <= (local_18 + 1 & 0xff)) {
      return;
    }
  }
  iVar5 = DAT_08005138;
  if (param_1 == 0) {
    if (1 < *pbVar3) {
      *pbVar3 = 0;
    }
    iVar11 = DAT_08005140;
LAB_080050aa:
    uVar9 = *(undefined1 *)(iVar11 + (uint)*pbVar3);
  }
  else {
    if (param_1 == 1) {
      if (0x21 < *pbVar3) {
        *pbVar3 = 0;
      }
      iVar11 = DAT_08005144;
      goto LAB_080050aa;
    }
    if (6 < param_1) {
      if (param_1 == 7) {
        if (8 < *pbVar3) {
          *pbVar3 = 0;
        }
        iVar11 = DAT_0800514c;
      }
      else if (param_1 == 8) {
        if (6 < *pbVar3) {
          *pbVar3 = 0;
        }
        iVar11 = DAT_08005150;
      }
      else {
        if (8 < *pbVar3) {
          *pbVar3 = 0;
        }
        iVar11 = DAT_08005148;
      }
      goto LAB_080050aa;
    }
    if (6 < *pbVar3) {
      *pbVar3 = 0;
    }
    uVar9 = *(undefined1 *)(param_1 * 7 + DAT_0800513c + (uint)*pbVar3 + -0xe);
  }
  *(undefined1 *)(iVar5 + (uint)*pbVar6) = uVar9;
  *pbVar4 = (byte)param_1;
  *pbVar3 = *pbVar3 + 1;
  bVar7 = 0x96;
  pbVar6 = DAT_08005130;
LAB_08005110:
  *pbVar6 = bVar7;
  return;
}



// ==== 08005164  FUN_08005164  (42 bytes, 1 xrefs)

void FUN_08005164(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  
  puVar3 = PTR_DAT_08005194;
  puVar2 = PTR_DAT_08005190;
  bVar1 = *PTR_DAT_08005190;
  uVar4 = (uint)bVar1;
  if (uVar4 == 0) {
    FUN_0800298c(PTR_DAT_08005194,0xf,0x2d,param_4,param_4);
    puVar3[0xe] = 0;
  }
  else if (0xd < uVar4) {
    return;
  }
  puVar3[uVar4] = param_1;
  *puVar2 = bVar1 + 1;
  return;
}



// ==== 08005198  FUN_08005198  (38 bytes, 6 xrefs)

void FUN_08005198(undefined1 param_1)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = DAT_080051c0;
  bVar1 = *DAT_080051c0;
  uVar3 = (uint)bVar1;
  if (uVar3 == 0) {
    FUN_0800298c(DAT_080051c4,0x12,10);
  }
  else if (9 < uVar3) {
    return;
  }
  *(undefined1 *)(DAT_080051c4 + uVar3) = param_1;
  *pbVar2 = bVar1 + 1;
  return;
}



// ==== 080051c8  FUN_080051c8  (556 bytes, 1 xrefs)

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x080051f4) */
/* WARNING: Instruction at (ram,0x080053b0) overlaps instruction at (ram,0x080053ae)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Removing unreachable block (ram,0x0800540c) */
/* WARNING: Removing unreachable block (ram,0x080051f4) */
/* WARNING: Removing unreachable block (ram,0x0800540c) */

void FUN_080051c8(void)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte *unaff_r5;
  byte *pbVar8;
  byte *pbVar9;
  byte bVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined4 in_cr2;
  undefined4 in_cr7;
  undefined4 *in_stack_0000013c;
  
  pbVar9 = switchD_080051f4::caseD_f2;
  puVar7 = switchD_080051f4::caseD_ee;
  bVar10 = *switchD_080051f4::caseD_ec;
  uVar11 = (uint)bVar10;
  pbVar2 = (byte *)*switchD_080051f4::caseD_f0;
  pbVar4 = switchD_080051f4::caseD_f2 + 0x80;
  pbVar5 = switchD_080051f4::caseD_f2 + 0x20;
  bVar13 = (byte *)0xffffffdf < pbVar2;
  pbVar3 = pbVar2 + 0x20;
  bVar12 = uVar11 == 0;
  uVar1 = uVar11;
  if (switchD_080051f4::caseD_0 <= uVar11) {
    uVar1 = (uint)switchD_080051f4::caseD_0;
  }
  pbVar6 = (byte *)((uint)*(byte *)(uVar1 + 0x80051f9) * 2);
  pbVar8 = switchD_080051f4::caseD_f2;
  switch(*(byte *)(uVar1 + 0x80051f9)) {
  case 0:
  case 1:
switchD_080051f4_caseD_2:
    pbVar8 = switchD_080051f4::caseD_f2 + -0x3c;
switchD_080051f4_caseD_3:
switchD_080051f4_caseD_4:
    *(byte **)(pbVar6 + 4) = unaff_r5;
switchD_080051f4_caseD_5:
    pbVar3 = (byte *)(uint)pbVar8[8];
switchD_080051f4_caseD_6:
    puVar7 = in_stack_0000013c;
switchD_080051f4_caseD_7:
    pbVar8 = (byte *)0x6d;
switchD_080051f4_caseD_8:
    pbVar5 = pbVar9 + 0x48;
switchD_080051f4_caseD_9:
    pbVar8 = pbVar8 + 0x34;
switchD_080051f4_caseD_a:
    pbVar5 = pbVar5 + -0x38;
switchD_080051f4_caseD_b:
    pbVar3[(int)unaff_r5] = (byte)puVar7;
switchD_080051f4_caseD_c:
    uVar11 = (uint)*(ushort *)(pbVar5 + (int)unaff_r5);
switchD_080051f4_caseD_d:
switchD_080051f4_caseD_e:
switchD_080051f4_caseD_f:
    puVar7 = (undefined4 *)(uint)*(ushort *)(pbVar9 + 0xbc);
switchD_080051f4_caseD_10:
    pbVar5[0x1a] = (byte)pbVar5;
switchD_080051f4_caseD_11:
    *(byte **)(uVar11 + 0x54) = pbVar3;
switchD_080051f4_caseD_12:
    pbVar4 = &LAB_080054a4;
switchD_080051f4_caseD_13:
switchD_080051f4_caseD_14:
    pbVar5 = (byte *)0x79011808;
switchD_080051f4_caseD_15:
    *(undefined4 **)(pbVar4 + (int)unaff_r5) = puVar7;
switchD_080051f4_caseD_16:
switchD_080051f4_caseD_17:
switchD_080051f4_caseD_18:
switchD_080051f4_caseD_19:
switchD_080051f4_caseD_1a:
switchD_080051f4_caseD_1b:
switchD_080051f4_caseD_1c:
    *(short *)unaff_r5 = (short)pbVar8;
switchD_080051f4_caseD_1d:
    *(short *)(pbVar3 + 0x2c) = (short)pbVar5;
switchD_080051f4_caseD_1e:
switchD_080051f4_caseD_1f:
switchD_080051f4_caseD_20:
    pbVar3 = (byte *)(uint)pbVar8[0x10];
switchD_080051f4_caseD_21:
    goto switchD_080051f4_caseD_ae;
  case 2:
    goto switchD_080051f4_caseD_2;
  case 3:
    goto switchD_080051f4_caseD_3;
  case 4:
    goto switchD_080051f4_caseD_4;
  case 5:
    goto switchD_080051f4_caseD_5;
  case 6:
    goto switchD_080051f4_caseD_6;
  case 7:
    goto switchD_080051f4_caseD_7;
  case 8:
    goto switchD_080051f4_caseD_8;
  case 9:
    goto switchD_080051f4_caseD_9;
  case 10:
    goto switchD_080051f4_caseD_a;
  case 0xb:
    goto switchD_080051f4_caseD_b;
  case 0xc:
    goto switchD_080051f4_caseD_c;
  case 0xd:
    goto switchD_080051f4_caseD_d;
  case 0xe:
    goto switchD_080051f4_caseD_e;
  case 0xf:
    goto switchD_080051f4_caseD_f;
  case 0x10:
    goto switchD_080051f4_caseD_10;
  case 0x11:
    goto switchD_080051f4_caseD_11;
  case 0x12:
    goto switchD_080051f4_caseD_12;
  case 0x13:
    goto switchD_080051f4_caseD_13;
  case 0x14:
    goto switchD_080051f4_caseD_14;
  case 0x15:
    goto switchD_080051f4_caseD_15;
  case 0x16:
    goto switchD_080051f4_caseD_16;
  case 0x17:
    goto switchD_080051f4_caseD_17;
  case 0x18:
    goto switchD_080051f4_caseD_18;
  case 0x19:
    goto switchD_080051f4_caseD_19;
  case 0x1a:
    goto switchD_080051f4_caseD_1a;
  case 0x1b:
    goto switchD_080051f4_caseD_1b;
  case 0x1c:
    goto switchD_080051f4_caseD_1c;
  case 0x1d:
    goto switchD_080051f4_caseD_1d;
  case 0x1e:
    goto switchD_080051f4_caseD_1e;
  case 0x1f:
    goto switchD_080051f4_caseD_1f;
  case 0x20:
    goto switchD_080051f4_caseD_20;
  case 0x21:
    goto switchD_080051f4_caseD_21;
  case 0x22:
    pbVar3 = (byte *)(uint)pbVar2[0x26];
  case 0x23:
    goto switchD_080051f4_caseD_ae;
  case 0x24:
    pbVar3 = (byte *)(uint)pbVar2[0x27];
  case 0x25:
    goto switchD_080051f4_caseD_ae;
  case 0x26:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x1c];
  case 0x27:
    goto switchD_080051f4_caseD_ae;
  case 0x28:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x13];
  case 0x29:
    bVar12 = pbVar3 == (byte *)0x1;
switchD_080051f4_caseD_2a:
    if (bVar12) {
switchD_080051f4_caseD_2b:
      pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x14];
switchD_080051f4_caseD_2c:
      pbVar3 = pbVar3 + 1;
switchD_080051f4_caseD_2d:
    }
    else {
switchD_080051f4_caseD_2e:
      pbVar3 = (byte *)0x0;
switchD_080051f4_caseD_2f:
    }
    goto switchD_080051f4_caseD_ae;
  case 0x2a:
    goto switchD_080051f4_caseD_2a;
  case 0x2b:
    goto switchD_080051f4_caseD_2b;
  case 0x2c:
    goto switchD_080051f4_caseD_2c;
  case 0x2d:
    goto switchD_080051f4_caseD_2d;
  case 0x2e:
    goto switchD_080051f4_caseD_2e;
  case 0x2f:
    goto switchD_080051f4_caseD_2f;
  case 0x30:
    pbVar3 = (byte *)(uint)pbVar2[0x2b];
  case 0x31:
    goto switchD_080051f4_caseD_ae;
  case 0x32:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x1d];
  case 0x33:
    goto switchD_080051f4_caseD_ae;
  case 0x34:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x1a];
  case 0x35:
    goto switchD_080051f4_caseD_ae;
  case 0x36:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x1b];
  case 0x37:
    goto switchD_080051f4_caseD_ae;
  case 0x38:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x16];
  case 0x39:
    goto switchD_080051f4_caseD_ae;
  case 0x3a:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x11];
  case 0x3b:
    goto switchD_080051f4_caseD_ae;
  case 0x3c:
    unaff_r5 = (byte *)0x0;
  case 0x3d:
switchD_080051f4_caseD_a4:
    pbVar3 = pbVar2;
switchD_080051f4_caseD_a5:
    pbVar4 = (byte *)((int)unaff_r5 << 3);
switchD_080051f4_caseD_a6:
    pbVar3 = pbVar4 + (int)pbVar3;
switchD_080051f4_caseD_a7:
    pbVar4 = (byte *)(uint)pbVar3[4];
switchD_080051f4_caseD_a8:
    pbVar3 = (byte *)(uint)pbVar3[5];
switchD_080051f4_caseD_a9:
    bVar12 = pbVar4 == (byte *)0x2;
switchD_080051f4_caseD_aa:
    if (bVar12) goto switchD_080051f4_caseD_2c;
switchD_080051f4_caseD_ab:
    bVar12 = pbVar4 == (byte *)0x3;
switchD_080051f4_caseD_ac:
    if (!bVar12) goto switchD_080051f4_caseD_2e;
switchD_080051f4_caseD_ad:
    pbVar3 = pbVar3 + 0x69;
    goto switchD_080051f4_caseD_ae;
  case 0x3e:
    unaff_r5 = (byte *)0x0;
  case 0x3f:
switchD_080051f4_caseD_c2:
    pbVar3 = pbVar2;
switchD_080051f4_caseD_c3:
    pbVar4 = (byte *)((int)unaff_r5 << 3);
switchD_080051f4_caseD_c4:
    pbVar3 = pbVar4 + (int)pbVar3;
switchD_080051f4_caseD_c5:
    pbVar4 = (byte *)(uint)pbVar3[4];
switchD_080051f4_caseD_c6:
    pbVar3 = (byte *)(uint)pbVar3[5];
switchD_080051f4_caseD_c7:
    bVar12 = pbVar4 == (byte *)0x1;
switchD_080051f4_caseD_c8:
    if (!bVar12) goto switchD_080051f4_caseD_ac;
switchD_080051f4_caseD_c9:
    goto switchD_080051f4_caseD_2c;
  case 0x40:
    unaff_r5 = (byte *)0x1;
  case 0x41:
    goto switchD_080051f4_caseD_a4;
  case 0x42:
    unaff_r5 = (byte *)0x1;
  case 0x43:
    goto switchD_080051f4_caseD_c2;
  case 0x44:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x15];
  case 0x45:
    goto switchD_080051f4_caseD_ae;
  case 0x46:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x8e];
  case 0x47:
    goto switchD_080051f4_caseD_ae;
  case 0x48:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x82];
  case 0x49:
    goto switchD_080051f4_caseD_ae;
  case 0x4a:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x83];
  case 0x4b:
    goto switchD_080051f4_caseD_ae;
  case 0x4c:
    pbVar3 = (byte *)(uint)*(ushort *)(switchD_080051f4::caseD_f2 + 0x84);
  case 0x4d:
    pbVar4 = (byte *)0xa;
switchD_080051f4_caseD_4e:
    pbVar3 = (byte *)FUN_080028f0(pbVar3,pbVar4);
switchD_080051f4_caseD_50:
    goto switchD_080051f4_caseD_ae;
  case 0x4e:
    goto switchD_080051f4_caseD_4e;
  case 0x4f:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x50:
    goto switchD_080051f4_caseD_50;
  case 0x51:
    pbVar3 = (byte *)(uint)pbVar2[0x30];
  case 0x52:
    goto switchD_080051f4_caseD_ae;
  case 0x53:
    pbVar3 = (byte *)(uint)pbVar2[0x2f];
  case 0x54:
    goto switchD_080051f4_caseD_ae;
  case 0x55:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x1e];
  case 0x56:
    goto switchD_080051f4_caseD_ae;
  case 0x57:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x17];
  case 0x58:
    goto switchD_080051f4_caseD_ae;
  case 0x59:
    pbVar3 = (byte *)(uint)pbVar2[0x31];
  case 0x5a:
    goto switchD_080051f4_caseD_ae;
  case 0x5b:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x38];
  case 0x5c:
    goto switchD_080051f4_caseD_ae;
  case 0x5d:
    pbVar3 = pbVar2;
  case 0x5e:
    pbVar3 = (byte *)(uint)pbVar3[0x1f];
switchD_080051f4_caseD_5f:
    goto switchD_080051f4_caseD_ae;
  case 0x5f:
    goto switchD_080051f4_caseD_5f;
  case 0x60:
    pbVar3 = pbVar2;
  case 0x61:
    pbVar3 = *(byte **)(pbVar3 + 0x18);
switchD_080051f4_caseD_62:
    goto switchD_080051f4_caseD_ae;
  case 0x62:
    goto switchD_080051f4_caseD_62;
  case 99:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x18];
  case 100:
    goto switchD_080051f4_caseD_ae;
  case 0x65:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x39];
  case 0x66:
    goto switchD_080051f4_caseD_ae;
  case 0x67:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x3a];
  case 0x68:
    goto switchD_080051f4_caseD_ae;
  case 0x69:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x3b];
  case 0x6a:
    goto switchD_080051f4_caseD_ae;
  case 0x6b:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x3c];
  case 0x6c:
    goto switchD_080051f4_caseD_ae;
  case 0x6d:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[4];
  case 0x6e:
    goto switchD_080051f4_caseD_ae;
  case 0x6f:
    pbVar6 = (byte *)0x0;
  case 0x70:
    pbVar5 = pbVar6;
switchD_080051f4_caseD_71:
    pbVar4 = (byte *)0x1;
switchD_080051f4_caseD_72:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[4];
switchD_080051f4_caseD_73:
    pbVar3 = (byte *)FUN_08004f10(pbVar3,pbVar4,pbVar5);
switchD_080051f4_caseD_75:
    goto switchD_080051f4_caseD_ae;
  case 0x71:
    goto switchD_080051f4_caseD_71;
  case 0x72:
    goto switchD_080051f4_caseD_72;
  case 0x73:
    goto switchD_080051f4_caseD_73;
  case 0x74:
    coprocessor_movefromRt(0,0,1,in_cr7,in_cr7);
  case 0x76:
    unaff_r5 = (byte *)0x0;
switchD_080051f4_caseD_77:
switchD_080051f4_caseD_b5:
    pbVar5 = (byte *)0xff;
switchD_080051f4_caseD_b6:
    pbVar4 = (byte *)0xca;
switchD_080051f4_caseD_b7:
    pbVar3 = &DAT_200028a6;
switchD_080051f4_caseD_b8:
    FUN_0800298c(pbVar3,pbVar4,pbVar5);
switchD_080051f4_caseD_ba:
    pbVar3 = pbVar9 + (int)unaff_r5;
switchD_080051f4_caseD_bb:
    pbVar3 = pbVar3 + 0x20;
switchD_080051f4_caseD_bc:
    pbVar4 = (byte *)(uint)*pbVar3;
switchD_080051f4_caseD_bd:
    uVar11 = 0;
switchD_080051f4_caseD_be:
    pbVar5 = &DAT_200028a6;
switchD_080051f4_caseD_bf:
    bVar12 = pbVar4 == (byte *)0x1;
switchD_080051f4_caseD_c0:
    if (bVar12) {
switchD_080051f4_caseD_ca:
      pbVar4 = (byte *)(uint)pbVar3[2];
switchD_080051f4_caseD_cb:
      bVar13 = (byte *)0xc7 < pbVar4;
switchD_080051f4_caseD_cc:
      if (!bVar13) {
switchD_080051f4_caseD_cd:
        *pbVar5 = (byte)pbVar4;
switchD_080051f4_caseD_ce:
        uVar11 = 1;
      }
switchD_080051f4_caseD_cf:
      pbVar3 = (byte *)(uint)pbVar3[4];
switchD_080051f4_caseD_d0:
      bVar13 = (byte *)0xc7 < pbVar3;
switchD_080051f4_caseD_d1:
      if (!bVar13) {
switchD_080051f4_caseD_d2:
        pbVar5[uVar11] = (byte)pbVar3;
switchD_080051f4_caseD_d3:
        uVar11 = uVar11 + 1;
      }
    }
    else {
switchD_080051f4_caseD_c1:
    }
switchD_080051f4_caseD_d4:
    pbVar3 = &DAT_2000014e;
switchD_080051f4_caseD_d5:
    pbVar9 = (byte *)0x0;
switchD_080051f4_caseD_d6:
    *pbVar3 = (byte)uVar11;
switchD_080051f4_caseD_d7:
    while( true ) {
      pbVar5 = (byte *)0x1;
switchD_080051f4_caseD_d8:
      pbVar6 = unaff_r5;
      unaff_r5 = pbVar6;
switchD_080051f4_caseD_d9:
      pbVar4 = pbVar5;
      pbVar5 = pbVar4;
switchD_080051f4_caseD_da:
      pbVar3 = pbVar9;
      pbVar9 = pbVar3;
switchD_080051f4_caseD_db:
      pbVar3 = (byte *)FUN_08004f10(pbVar3,pbVar4,pbVar5,pbVar6);
switchD_080051f4_caseD_dd:
      bVar13 = (byte *)0xc7 < pbVar3;
switchD_080051f4_caseD_de:
      if (bVar13) break;
switchD_080051f4_caseD_df:
      bVar13 = pbVar9 <= pbVar3;
switchD_080051f4_caseD_e0:
      if (!bVar13) break;
switchD_080051f4_caseD_e1:
      pbVar4 = &DAT_200028a6;
switchD_080051f4_caseD_e2:
      pbVar4[uVar11] = (byte)pbVar3;
switchD_080051f4_caseD_e3:
      bVar10 = (byte)uVar11;
      pbVar3 = pbVar3 + 1;
switchD_080051f4_caseD_e4:
      bVar10 = bVar10 + 1;
switchD_080051f4_caseD_e5:
      pbVar9 = (byte *)((uint)pbVar3 & 0xff);
switchD_080051f4_caseD_e6:
      uVar11 = (uint)bVar10;
switchD_080051f4_caseD_e7:
    }
switchD_080051f4_caseD_e8:
    bVar10 = (byte)uVar11;
    pbVar3 = &DAT_2000014d;
switchD_080051f4_caseD_e9:
    *pbVar3 = bVar10;
switchD_080051f4_caseD_ea:
    goto switchD_080051f4_caseD_2e;
  case 0x75:
    goto switchD_080051f4_caseD_75;
  case 0x77:
    goto switchD_080051f4_caseD_77;
  case 0x78:
    unaff_r5 = (byte *)0x1;
  case 0x79:
    goto switchD_080051f4_caseD_b5;
  case 0x7a:
    pbVar3 = (byte *)(uint)pbVar2[0x2a];
  case 0x7b:
    goto switchD_080051f4_caseD_ae;
  case 0x7c:
    pbVar3 = (byte *)(uint)pbVar2[0x2c];
  case 0x7d:
    goto switchD_080051f4_caseD_ae;
  case 0x7e:
    pbVar3 = (byte *)(uint)pbVar2[0x2d];
  case 0x7f:
    goto switchD_080051f4_caseD_ae;
  case 0x80:
    pbVar3 = &DAT_200000db;
  case 0x81:
    break;
  case 0x82:
    pbVar3 = &DAT_20000066;
    break;
  case 0x84:
    goto switchD_080051f4_caseD_84;
  case 0x85:
    pbVar3 = &DAT_200000dc;
  case 0x86:
    break;
  case 0x87:
    pbVar3 = &DAT_200000dd;
  case 0x88:
    break;
  case 0x89:
    pbVar3 = &DAT_200000c5;
  case 0x8a:
    pbVar3 = (byte *)(uint)*pbVar3;
switchD_080051f4_caseD_8b:
    goto switchD_080051f4_caseD_2c;
  case 0x8b:
    goto switchD_080051f4_caseD_8b;
  case 0x8c:
    pbVar3 = switchD_080051f4::caseD_f2 + 0x40;
  case 0x8d:
    pbVar3 = (byte *)(uint)pbVar3[1];
switchD_080051f4_caseD_8e:
    goto switchD_080051f4_caseD_ae;
  case 0x8e:
    goto switchD_080051f4_caseD_8e;
  case 0x8f:
    pbVar3 = switchD_080051f4::caseD_f2 + 0x40;
  case 0x90:
    pbVar3 = (byte *)(uint)pbVar3[3];
switchD_080051f4_caseD_91:
    goto switchD_080051f4_caseD_ae;
  case 0x91:
    goto switchD_080051f4_caseD_91;
  case 0x92:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x1f];
  case 0x93:
    goto switchD_080051f4_caseD_2c;
  case 0x94:
    pbVar3 = (byte *)(uint)pbVar2[0x32];
  case 0x95:
    goto switchD_080051f4_caseD_ae;
  case 0x96:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x92];
  case 0x97:
    goto switchD_080051f4_caseD_ae;
  case 0x98:
    pbVar3 = &DAT_200000de;
  case 0x99:
    break;
  case 0x9a:
    pbVar3 = &DAT_200000df;
  case 0x9b:
    break;
  case 0x9c:
    pbVar3 = pbVar2;
  case 0x9d:
    pbVar3 = (byte *)(uint)pbVar3[0x1e];
switchD_080051f4_caseD_9e:
    goto switchD_080051f4_caseD_ae;
  case 0x9e:
    goto switchD_080051f4_caseD_9e;
  case 0x9f:
    pbVar3 = (byte *)(uint)switchD_080051f4::caseD_f2[0x95];
  case 0xa0:
    goto switchD_080051f4_caseD_ae;
  case 0xa1:
    pbVar3 = (byte *)0x0;
  case 0xa2:
    bVar12 = pbVar3 == (byte *)0x0;
switchD_080051f4_caseD_a3:
    if (!bVar12) goto switchD_080051f4_caseD_a4;
switchD_080051f4_caseD_b1:
    bVar12 = pbVar3 == (byte *)0x2;
switchD_080051f4_caseD_b2:
    if (bVar12) goto switchD_080051f4_caseD_c2;
switchD_080051f4_caseD_b3:
    bVar12 = pbVar3 == (byte *)0x3;
switchD_080051f4_caseD_b4:
    if (bVar12) goto switchD_080051f4_caseD_b5;
    goto switchD_080051f4_caseD_af;
  case 0xa3:
    goto switchD_080051f4_caseD_a3;
  case 0xa4:
    goto switchD_080051f4_caseD_a4;
  case 0xa5:
    goto switchD_080051f4_caseD_a5;
  case 0xa6:
    goto switchD_080051f4_caseD_a6;
  case 0xa7:
    goto switchD_080051f4_caseD_a7;
  case 0xa8:
    goto switchD_080051f4_caseD_a8;
  case 0xa9:
    goto switchD_080051f4_caseD_a9;
  case 0xaa:
    goto switchD_080051f4_caseD_aa;
  case 0xab:
    goto switchD_080051f4_caseD_ab;
  case 0xac:
    goto switchD_080051f4_caseD_ac;
  case 0xad:
    goto switchD_080051f4_caseD_ad;
  case 0xae:
    goto switchD_080051f4_caseD_ae;
  case 0xaf:
    goto switchD_080051f4_caseD_af;
  case 0xb0:
    goto switchD_080051f4_caseD_b0;
  case 0xb1:
    goto switchD_080051f4_caseD_b1;
  case 0xb2:
    goto switchD_080051f4_caseD_b2;
  case 0xb3:
    goto switchD_080051f4_caseD_b3;
  case 0xb4:
    goto switchD_080051f4_caseD_b4;
  case 0xb5:
    goto switchD_080051f4_caseD_b5;
  case 0xb6:
    goto switchD_080051f4_caseD_b6;
  case 0xb7:
    goto switchD_080051f4_caseD_b7;
  case 0xb8:
    goto switchD_080051f4_caseD_b8;
  case 0xb9:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xba:
    goto switchD_080051f4_caseD_ba;
  case 0xbb:
    goto switchD_080051f4_caseD_bb;
  case 0xbc:
    goto switchD_080051f4_caseD_bc;
  case 0xbd:
    goto switchD_080051f4_caseD_bd;
  case 0xbe:
    goto switchD_080051f4_caseD_be;
  case 0xbf:
    goto switchD_080051f4_caseD_bf;
  case 0xc0:
    goto switchD_080051f4_caseD_c0;
  case 0xc1:
    goto switchD_080051f4_caseD_c1;
  case 0xc2:
    goto switchD_080051f4_caseD_c2;
  case 0xc3:
    goto switchD_080051f4_caseD_c3;
  case 0xc4:
    goto switchD_080051f4_caseD_c4;
  case 0xc5:
    goto switchD_080051f4_caseD_c5;
  case 0xc6:
    goto switchD_080051f4_caseD_c6;
  case 199:
    goto switchD_080051f4_caseD_c7;
  case 200:
    goto switchD_080051f4_caseD_c8;
  case 0xc9:
    goto switchD_080051f4_caseD_c9;
  case 0xca:
    goto switchD_080051f4_caseD_ca;
  case 0xcb:
    goto switchD_080051f4_caseD_cb;
  case 0xcc:
    goto switchD_080051f4_caseD_cc;
  case 0xcd:
    goto switchD_080051f4_caseD_cd;
  case 0xce:
    goto switchD_080051f4_caseD_ce;
  case 0xcf:
    goto switchD_080051f4_caseD_cf;
  case 0xd0:
    goto switchD_080051f4_caseD_d0;
  case 0xd1:
    goto switchD_080051f4_caseD_d1;
  case 0xd2:
    goto switchD_080051f4_caseD_d2;
  case 0xd3:
    goto switchD_080051f4_caseD_d3;
  case 0xd4:
    goto switchD_080051f4_caseD_d4;
  case 0xd5:
    goto switchD_080051f4_caseD_d5;
  case 0xd6:
    goto switchD_080051f4_caseD_d6;
  case 0xd7:
    goto switchD_080051f4_caseD_d7;
  case 0xd8:
    goto switchD_080051f4_caseD_d8;
  case 0xd9:
    goto switchD_080051f4_caseD_d9;
  case 0xda:
    goto switchD_080051f4_caseD_da;
  case 0xdb:
    goto switchD_080051f4_caseD_db;
  case 0xdc:
    coprocessor_store(8,in_cr2,pbVar6 + 0x8005518);
    goto switchD_080051f4_caseD_de;
  case 0xdd:
    goto switchD_080051f4_caseD_dd;
  case 0xde:
    goto switchD_080051f4_caseD_de;
  case 0xdf:
    goto switchD_080051f4_caseD_df;
  case 0xe0:
    goto switchD_080051f4_caseD_e0;
  case 0xe1:
    goto switchD_080051f4_caseD_e1;
  case 0xe2:
    goto switchD_080051f4_caseD_e2;
  case 0xe3:
    goto switchD_080051f4_caseD_e3;
  case 0xe4:
    goto switchD_080051f4_caseD_e4;
  case 0xe5:
    goto switchD_080051f4_caseD_e5;
  case 0xe6:
    goto switchD_080051f4_caseD_e6;
  case 0xe7:
    goto switchD_080051f4_caseD_e7;
  case 0xe8:
    goto switchD_080051f4_caseD_e8;
  case 0xe9:
    goto switchD_080051f4_caseD_e9;
  case 0xea:
    goto switchD_080051f4_caseD_ea;
  case 0xeb:
  case 0xec:
code_r0x080053d2:
code_r0x080053d4:
code_r0x080053d6:
code_r0x080053d8:
code_r0x080053da:
code_r0x080053dc:
code_r0x080053de:
switchD_080051f4_caseD_f4:
switchD_080051f4_caseD_f5:
switchD_080051f4_caseD_f6:
switchD_080051f4_caseD_f7:
switchD_080051f4_caseD_f8:
switchD_080051f4_caseD_f9:
switchD_080051f4_caseD_fa:
switchD_080051f4_caseD_fb:
switchD_080051f4_caseD_fc:
switchD_080051f4_caseD_fd:
switchD_080051f4_caseD_fe:
switchD_080051f4_caseD_ff:
                    /* WARNING: Could not recover jumptable at 0x0800540c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&DAT_08005410 + (uint)bRam08005411 * 2))();
    return;
  case 0xed:
    goto code_r0x080053d2;
  case 0xee:
    goto code_r0x080053d4;
  case 0xef:
    goto code_r0x080053d6;
  case 0xf0:
    goto code_r0x080053d8;
  case 0xf1:
    goto code_r0x080053da;
  case 0xf2:
    goto code_r0x080053dc;
  case 0xf3:
    goto code_r0x080053de;
  case 0xf4:
    goto switchD_080051f4_caseD_f4;
  case 0xf5:
    goto switchD_080051f4_caseD_f5;
  case 0xf6:
    goto switchD_080051f4_caseD_f6;
  case 0xf7:
    goto switchD_080051f4_caseD_f7;
  case 0xf8:
    goto switchD_080051f4_caseD_f8;
  case 0xf9:
    goto switchD_080051f4_caseD_f9;
  case 0xfa:
    goto switchD_080051f4_caseD_fa;
  case 0xfb:
    goto switchD_080051f4_caseD_fb;
  case 0xfc:
    goto switchD_080051f4_caseD_fc;
  case 0xfd:
    goto switchD_080051f4_caseD_fd;
  case 0xfe:
    goto switchD_080051f4_caseD_fe;
  case 0xff:
    goto switchD_080051f4_caseD_ff;
  }
  pbVar3 = (byte *)(uint)*pbVar3;
switchD_080051f4_caseD_84:
switchD_080051f4_caseD_ae:
  *puVar7 = pbVar3;
switchD_080051f4_caseD_af:
switchD_080051f4_caseD_b0:
  return;
}



// ==== 08005408  FUN_08005408  (8 bytes, 3 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    Instruction at (ram,0x08005576) overlaps instruction at (ram,0x08005574)


// ==== 080054d4  FUN_080054d4  (488 bytes, 1 xrefs)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080054d4(void)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  
  if (*_DAT_080056bc != '\x03') {
    bVar11 = 0;
    do {
      uVar8 = FUN_0800e900(0xc);
      if ((uVar8 & 1) == 0) {
        return;
      }
      FUN_0800ee64(2,0);
      uVar9 = FUN_0800e900(2);
      uVar12 = uVar8;
      FUN_08011368(3,s_4829_int__d__0x_04x_0x_04x_080056bf + 1,bVar11,uVar9,uVar8);
      if (uVar9 == 0) {
        FUN_080123ae(0xb4);
        uVar8 = FUN_0800e900(0xc);
        uVar9 = FUN_0800e900(2);
        FUN_08011368(2,s_4829_int_0x_04x_0x_04x_in_2nd_re_080056e0,uVar9,uVar8,uVar12);
      }
      if (((int)(uVar8 << 0x1e) < 0) && ((int)(uVar9 << 0x1c) < 0)) {
        uVar9 = uVar9 & 0xfffffff7;
        FUN_08011368(3,s_4829_int_conflict_with_status_08005708);
      }
      if ((int)(uVar9 << 0x14) < 0) {
        *DAT_08005728 = 1;
        pbVar3 = DAT_08005730;
        *DAT_0800572c = 5;
        iVar4 = DAT_08005734;
        if (0xf < *pbVar3) {
          uVar8 = 0;
          do {
            *(undefined1 *)(iVar4 + uVar8) = *(undefined1 *)(iVar4 + uVar8 + 1);
            uVar8 = uVar8 + 1 & 0xff;
          } while (uVar8 < 0xf);
          *pbVar3 = 0xf;
        }
        FUN_0800e608();
        uVar6 = FUN_08004e4c();
        bVar10 = *pbVar3;
        *(undefined1 *)(DAT_08005734 + (uint)bVar10) = uVar6;
        *pbVar3 = bVar10 + 1;
        if (*DAT_08005738 == '\x04') {
          FUN_0800b9ec();
        }
      }
      if ((int)(uVar9 << 0x15) < 0) {
        *DAT_0800573c = 1;
      }
      if ((int)(uVar9 << 0x17) < 0) {
        *DAT_08005740 = 1;
        uVar6 = FUN_0800e5fc();
        *DAT_08005744 = uVar6;
      }
      if ((int)(uVar9 << 0x16) < 0) {
        *DAT_08005740 = 0;
      }
      if ((int)(uVar9 << 0x19) < 0) {
        *DAT_08005748 = 1;
      }
      if ((int)(uVar9 << 0x18) < 0) {
        *DAT_08005748 = 0;
      }
      if ((int)(uVar9 << 0x1b) < 0) {
        *DAT_0800574c = 1;
        *DAT_08005750 = 10;
        iVar4 = DAT_08005754;
        if (*(char *)(DAT_08005754 + 0x13) == '\x01') {
          if ((*DAT_08005738 == '\x05') && (*DAT_08005758 == '\0')) {
            *DAT_0800575c = 0x14;
            *DAT_08005760 = 0;
          }
          pcVar5 = DAT_08005764;
          if ((*(char *)(iVar4 + 0x1a) != '\0') &&
             ((*DAT_08005764 == '\x01' || ((*DAT_08005764 == '\0' && (*DAT_08005768 < 0x14)))))) {
            *DAT_08005768 = 0x14;
            *pcVar5 = '\0';
          }
        }
      }
      if ((int)(uVar9 << 0x1a) < 0) {
        *DAT_0800574c = 0;
        *DAT_08005750 = 0;
      }
      if ((int)(uVar9 << 0x1d) < 0) {
        *DAT_0800576c = 1;
        FUN_0800e660(5,1);
      }
      if ((int)(uVar9 << 0x1c) < 0) {
        *DAT_0800576c = 0;
        *DAT_0800573c = 0;
        cVar1 = *DAT_08005770;
        if (((cVar1 == '\x02') || (cVar1 == '\x03')) || (cVar1 == '\0')) {
          *DAT_08005748 = 0;
        }
        FUN_0800e660(5,0);
      }
      iVar4 = DAT_0800577c;
      if ((((int)(uVar9 << 0x13) < 0) && (*_DAT_080056bc == '\x04')) &&
         ((*DAT_08005774 == '\x01' && (*DAT_08005778 == '\0')))) {
        bVar10 = 0;
        do {
          uVar7 = FUN_0800e900(0x5f);
          pbVar3 = DAT_08005780;
          bVar10 = bVar10 + 1;
          bVar2 = *DAT_08005780;
          *(undefined2 *)(iVar4 + (uint)bVar2 * 2) = uVar7;
          *pbVar3 = bVar2 + 1;
        } while (bVar10 < 4);
        FUN_0800b76c();
      }
      if (bVar11 != 0) {
        FUN_080123ae(1);
      }
      bVar11 = bVar11 + 1;
    } while (bVar11 < 0x14);
  }
  return;
}



// ==== 08005784  FUN_08005784  (1146 bytes, 7 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    Instruction at (ram,0x08005c38) overlaps instruction at (ram,0x08005c36)


// ==== 08005d10  FUN_08005d10  (332 bytes, 1 xrefs)

void FUN_08005d10(void)

{
  byte bVar1;
  char *pcVar2;
  undefined *puVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  undefined4 in_r3;
  
  pbVar4 = DAT_08005e70;
  puVar3 = PTR_GPIOB_08005e6c;
  pcVar2 = DAT_08005e68;
  if ((*DAT_08005e5c != '\x01') && ((*DAT_08005e60 != '\x04' || (*DAT_08005e64 == '\0')))) {
    if (*DAT_08005e68 == '\x01') {
      iVar7 = FUN_08010ff0(PTR_GPIOB_08005e6c,0x400,1,in_r3,in_r3);
      if (iVar7 == 1) {
        FUN_080123ae(0x14);
        iVar7 = FUN_08010ff0(puVar3,0x400);
        if (iVar7 == 1) {
          FUN_08005784(0x15,0);
          *pcVar2 = '\0';
          if (*pbVar4 != 0xff) {
            *DAT_08005e78 = 1;
          }
        }
      }
    }
    else {
      iVar7 = FUN_08010ff0(PTR_GPIOB_08005e6c,0x400,*DAT_08005e68,in_r3,in_r3);
      if (iVar7 == 0) {
        bVar1 = *DAT_08005e74;
        *DAT_08005e74 = bVar1 + 1;
        if (4 < (byte)(bVar1 + 1)) {
          *pcVar2 = '\x01';
          FUN_08005784(0x15,1,0);
        }
      }
      else {
        *DAT_08005e74 = 0;
      }
    }
    uVar8 = FUN_0800f900();
    puVar6 = DAT_08005e84;
    puVar5 = DAT_08005e80;
    if (*DAT_08005e7c != uVar8) {
      if ((*DAT_08005e7c != 0xff) && (uVar8 != 0xff)) {
        FUN_08005784(*pbVar4,0,*DAT_08005e80);
      }
      *DAT_08005e7c = (byte)uVar8;
      *DAT_08005e84 = 0;
      return;
    }
    uVar9 = *DAT_08005e84 + 1;
    *DAT_08005e84 = uVar9;
    if (uVar9 == 2) {
      if (uVar8 == 0xff) {
        if (*pbVar4 != 0xff) {
          FUN_08005784(*pbVar4,0,*puVar5);
          *pbVar4 = 0xff;
        }
      }
      else {
        *pbVar4 = (byte)uVar8;
        FUN_08005784(uVar8,1,0);
      }
      *puVar5 = 0;
    }
    else if (uVar9 == 0x80) {
      if (((((uVar8 == 0xe) || (uVar8 == 0xf)) || (uVar8 == 0x16)) ||
          ((uVar8 == 0x17 || (uVar8 == 0xb)))) || (uVar8 == 0xc)) {
        *puVar5 = 1;
        FUN_08005784(uVar8,1,1);
        return;
      }
    }
    else if (0x80 < uVar9) {
      if (((uVar8 == 0xb) || (uVar8 == 0xc)) && (*puVar5 = 1, (uVar9 & 0xf) == 0)) {
        FUN_08005784(uVar8,1);
      }
      if (*puVar6 == DAT_08005e88) {
        *puVar6 = 0x80;
        return;
      }
      return;
    }
  }
  return;
}



// ==== 08005e8c  FUN_08005e8c  (10 bytes, 1 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x08005fa2

// ==== 08005ec0  FUN_08005ec0  (76 bytes, 0 xrefs)

void FUN_08005ec0(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  byte bVar3;
  
  puVar1 = PTR_DAT_08005f0c;
  if ((param_2 == 0) && (param_1 == 1)) {
    if (*PTR_DAT_08005f0c == '\0') {
      *PTR_DAT_08005f14 = 0;
      puVar2 = PTR_DAT_08005f20;
      *(undefined2 *)PTR_DAT_08005f18 = 0;
      *(undefined2 *)PTR_DAT_08005f1c = 0;
      *(undefined2 *)puVar2 = 0xffff;
      *puVar1 = 0;
      *PTR_DAT_08005f24 = 0;
      FUN_0800e53c();
      *PTR_DAT_08005f28 = 1;
    }
    else {
      bVar3 = *PTR_DAT_08005f0c - 1;
      *PTR_DAT_08005f0c = bVar3;
      PTR_DAT_08005f10[bVar3] = 10;
    }
    *PTR_DAT_08005f2c = 4;
  }
  return;
}



// ==== 08005f30  FUN_08005f30  (64 bytes, 0 xrefs)

void FUN_08005f30(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  if ((param_2 == 0) && (param_1 == 1)) {
    *PTR_DAT_08005f70 = 0;
    *(undefined2 *)PTR_DAT_08005f74 = 0;
    uVar1 = DAT_08005f84;
    *PTR_DAT_08005f78 = 0;
    *PTR_DAT_08005f7c = 0;
    *PTR_DAT_08005f80 = 1;
    puVar2 = DAT_08005f88;
    *DAT_08005f88 = (short)uVar1;
    puVar2[1] = 0;
    DAT_08005f88[0x23] = (short)DAT_08005f8c;
    FUN_08003d1c();
    FUN_0800c2d4();
    *DAT_08005f90 = 1;
  }
  return;
}



// ==== 08005f94  FUN_08005f94  (154 bytes, 0 xrefs)

void FUN_08005f94(undefined1 param_1,int param_2,int param_3,uint param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint local_18;
  
  if ((param_3 == 0) && (param_2 == 1)) {
    local_18 = param_4;
    FUN_08005198();
    *PTR_DAT_08006030 = 4;
    if ((byte)*PTR_DAT_08006034 < 6) {
      *PTR_DAT_08006044 = param_1;
      return;
    }
    *PTR_DAT_08006034 = 0;
    FUN_08004d78(PTR_DAT_08006038,&local_18);
    uVar4 = 0;
    do {
      if ((local_18 <= *(uint *)(*(int *)PTR_DAT_0800603c + uVar4 * 4)) &&
         (*(uint *)(*(int *)PTR_DAT_08006040 + uVar4 * 4) <= local_18)) {
        if (uVar4 < 7) {
          local_18 = local_18 + 0x4b;
          *PTR_DAT_08006044 = param_1;
          puVar1 = PTR_DAT_08006048;
          *(char *)(*(int *)PTR_DAT_08006048 + 0x2e) = (char)uVar4;
          uVar2 = FUN_08003d08(local_18,*(undefined2 *)(*(int *)puVar1 + 0x1c),0);
          puVar3 = *(undefined4 **)puVar1;
          *puVar3 = uVar2;
          puVar3[2] = uVar2;
          FUN_08003f98();
          *(undefined4 *)PTR_DAT_0800604c = *(undefined4 *)puVar1;
          FUN_080049a8(1);
          FUN_0800e3c4();
          FUN_0800e518();
          return;
        }
        break;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 7);
    *PTR_DAT_08006030 = 4;
  }
  return;
}



// ==== 08006050  FUN_08006050  (122 bytes, 1 xrefs)

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x08006058) */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x08006058) */

void FUN_08006050(byte *param_1,byte *param_2,byte *param_3)

{
  undefined1 uVar1;
  undefined *puVar2;
  byte bVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined *puVar6;
  byte *pbVar8;
  uint uVar7;
  byte *pbVar9;
  undefined1 uVar10;
  byte *pbVar11;
  undefined *unaff_r6;
  int iVar12;
  undefined1 uVar13;
  undefined *unaff_r7;
  undefined4 unaff_r8;
  int unaff_r10;
  bool bVar14;
  byte **ppbVar15;
  undefined4 in_cr0;
  undefined4 in_cr8;
  undefined4 in_cr11;
  undefined4 in_cr12;
  byte *pbStack_30;
  byte *pbStack_2c;
  byte *pbStack_28;
  byte *pbStack_24;
  byte *pbStack_20;
  
  puVar6 = PTR_DAT_0800639c;
  ppbVar15 = (byte **)((int)register0x00000054 + -0x10);
  bVar14 = param_1 == (byte *)0x0;
  if (param_1 < (byte *)0x16) {
    bVar3 = param_1[0x800605d];
  }
  else {
    bVar3 = 0x2b;
  }
  uVar7 = (uint)bVar3;
  pbVar8 = (byte *)(uVar7 * 2);
  pbVar11 = param_2;
  pbVar9 = param_3;
  switch(uVar7) {
  case 0:
  case 1:
switchD_08006058_caseD_2:
switchD_08006058_caseD_3:
switchD_08006058_caseD_4:
switchD_08006058_caseD_5:
switchD_08006058_caseD_6:
switchD_08006058_caseD_7:
switchD_08006058_caseD_8:
switchD_08006058_caseD_9:
switchD_08006058_caseD_a:
switchD_08006058_caseD_b:
switchD_08006058_caseD_c:
    param_1 = param_2;
switchD_08006058_caseD_d:
    FUN_080071b4(param_1);
switchD_08006058_caseD_f:
    return;
  case 2:
    goto switchD_08006058_caseD_2;
  case 3:
    goto switchD_08006058_caseD_3;
  case 4:
    goto switchD_08006058_caseD_4;
  case 5:
    goto switchD_08006058_caseD_5;
  case 6:
    goto switchD_08006058_caseD_6;
  case 7:
    goto switchD_08006058_caseD_7;
  case 8:
    goto switchD_08006058_caseD_8;
  case 9:
    goto switchD_08006058_caseD_9;
  case 10:
    goto switchD_08006058_caseD_a;
  case 0xb:
    goto switchD_08006058_caseD_b;
  case 0xc:
    goto switchD_08006058_caseD_c;
  case 0xd:
    goto switchD_08006058_caseD_d;
  case 0xe:
  case 0x10:
    pbVar11 = param_3;
switchD_08006058_caseD_11:
    param_1 = param_2;
switchD_08006058_caseD_12:
    switchD_08006058::caseD_82(param_1,pbVar11);
switchD_08006058_caseD_14:
    return;
  case 0xf:
    goto switchD_08006058_caseD_f;
  case 0x11:
    goto switchD_08006058_caseD_11;
  case 0x12:
    goto switchD_08006058_caseD_12;
  case 0x13:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x14:
    goto switchD_08006058_caseD_14;
  case 0x15:
    pbVar11 = param_3;
  case 0x16:
    param_1 = param_2;
switchD_08006058_caseD_17:
    switchD_08006058::caseD_36(param_1,pbVar11);
switchD_08006058_caseD_19:
    return;
  case 0x17:
    goto switchD_08006058_caseD_17;
  case 0x18:
  case 0x1a:
    pbVar9 = (byte *)0x0;
switchD_08006058_caseD_1b:
    pbVar9 = (byte *)~(uint)pbVar9;
switchD_08006058_caseD_1c:
    break;
  case 0x19:
    goto switchD_08006058_caseD_19;
  case 0x1b:
    goto switchD_08006058_caseD_1b;
  case 0x1c:
    goto switchD_08006058_caseD_1c;
  case 0x1d:
    pbVar9 = (byte *)0x1;
    break;
  case 0x1f:
    goto switchD_08006058_caseD_1f;
  case 0x20:
    goto switchD_08006058_caseD_20;
  case 0x21:
  case 0x23:
    pbVar11 = param_3;
switchD_08006058_caseD_24:
    param_1 = param_2;
switchD_08006058_caseD_25:
    FUN_08007be8(param_1,pbVar11);
switchD_08006058_caseD_27:
    return;
  case 0x22:
    goto switchD_08006058_caseD_22;
  case 0x24:
    goto switchD_08006058_caseD_24;
  case 0x25:
    goto switchD_08006058_caseD_25;
  case 0x26:
    coprocessor_load(0xd,in_cr11,pbVar8 + 0x800621c);
  case 0x28:
    switchD_08006058::caseD_e8();
switchD_08006058_caseD_2a:
    return;
  case 0x27:
    goto switchD_08006058_caseD_27;
  case 0x29:
  case 0x2b:
    bVar14 = param_3 == (byte *)0x0;
switchD_08006058_caseD_2c:
    if (!bVar14) {
      return;
    }
switchD_08006058_caseD_2d:
    bVar14 = param_2 == (byte *)0x1;
switchD_08006058_caseD_2e:
    if (!bVar14) {
      return;
    }
switchD_08006058_caseD_2f:
    param_2 = &DAT_20000092;
switchD_08006058_caseD_30:
    param_1 = (byte *)0x2;
switchD_08006058_caseD_31:
    *param_2 = (byte)param_1;
switchD_08006058_caseD_32:
    return;
  case 0x2a:
    goto switchD_08006058_caseD_2a;
  case 0x2c:
    goto switchD_08006058_caseD_2c;
  case 0x2d:
    goto switchD_08006058_caseD_2d;
  case 0x2e:
    goto switchD_08006058_caseD_2e;
  case 0x2f:
    goto switchD_08006058_caseD_2f;
  case 0x30:
    goto switchD_08006058_caseD_30;
  case 0x31:
    goto switchD_08006058_caseD_31;
  case 0x32:
    goto switchD_08006058_caseD_32;
  case 0x33:
  case 0x34:
switchD_08006058_caseD_35:
    param_1 = (byte *)0x0;
code_r0x080060c8:
    pbStack_28 = pbVar8;
    pbStack_24 = param_3;
    pbStack_20 = param_2;
code_r0x080060ca:
    bVar14 = param_2 == (byte *)0x0;
code_r0x080060cc:
    if (!bVar14) {
      return;
    }
code_r0x080060ce:
    bVar14 = param_1 == (byte *)0x1;
switchD_08006058_caseD_3a:
    if (!bVar14) {
      return;
    }
switchD_08006058_caseD_3b:
    param_1 = switchD_08006058::caseD_72;
switchD_08006058_caseD_3c:
    param_3 = (byte *)0x1;
switchD_08006058_caseD_3d:
    *param_1 = (byte)param_3;
switchD_08006058_caseD_3e:
    param_1 = switchD_08006058::caseD_74;
switchD_08006058_caseD_3f:
    param_2 = switchD_08006058::caseD_76;
switchD_08006058_caseD_40:
    param_1 = (byte *)(uint)*param_1;
switchD_08006058_caseD_41:
    unaff_r6 = switchD_08006058::caseD_78;
switchD_08006058_caseD_42:
    bVar14 = param_1 == (byte *)0x0;
switchD_08006058_caseD_43:
    if (!bVar14) {
switchD_08006058_caseD_44:
      FUN_0800b1fc();
      pbVar11 = param_2;
switchD_08006058_caseD_46:
      param_2 = (byte *)0x22;
      goto switchD_08006058_caseD_47;
    }
switchD_08006058_caseD_4c:
    pbVar8 = switchD_08006058::caseD_7a;
switchD_08006058_caseD_4d:
    unaff_r7 = (undefined *)0x0;
switchD_08006058_caseD_4e:
    param_1 = (byte *)(uint)*pbVar8;
switchD_08006058_caseD_4f:
    bVar14 = param_1 == (byte *)0x0;
switchD_08006058_caseD_50:
    if (bVar14) {
switchD_08006058_caseD_62:
      param_1 = switchD_08006058::caseD_7e;
      pbVar11 = param_2;
switchD_08006058_caseD_63:
      param_2 = switchD_08006058::caseD_80;
      pbVar9 = param_3;
switchD_08006058_caseD_64:
      param_3 = (byte *)(uint)*param_1;
switchD_08006058_caseD_65:
      bVar14 = param_3 == (byte *)0x1;
switchD_08006058_caseD_66:
      if (!bVar14) {
switchD_08006058_caseD_67:
        param_3 = (byte *)(uint)*param_2;
switchD_08006058_caseD_68:
        bVar14 = param_3 == (byte *)0x1;
switchD_08006058_caseD_69:
        if (!bVar14) {
switchD_08006058_caseD_6a:
          FUN_08008d94();
switchD_08006058_caseD_6c:
          return;
        }
      }
      goto switchD_08006058_caseD_6d;
    }
switchD_08006058_caseD_51:
    param_1 = param_1 + -1;
switchD_08006058_caseD_52:
    param_1 = (byte *)((uint)param_1 & 0xff);
    pbVar9 = param_3;
switchD_08006058_caseD_53:
    param_3 = (byte *)0xa;
    pbVar11 = param_2;
switchD_08006058_caseD_54:
    param_2 = switchD_08006058::caseD_7c;
switchD_08006058_caseD_55:
    *pbVar8 = (byte)param_1;
switchD_08006058_caseD_56:
    param_2[(int)param_1] = (byte)param_3;
switchD_08006058_caseD_57:
    bVar14 = param_1 == (byte *)0x0;
switchD_08006058_caseD_58:
    if (bVar14) {
switchD_08006058_caseD_5e:
      *pbVar8 = (byte)unaff_r7;
switchD_08006058_caseD_5f:
      param_3 = pbVar9;
      goto switchD_08006058_caseD_6f;
    }
switchD_08006058_caseD_59:
    bVar14 = param_1 == (byte *)0x1;
    param_3 = pbVar9;
switchD_08006058_caseD_5a:
    if (bVar14) {
switchD_08006058_caseD_5b:
      param_1 = (byte *)(uint)*param_2;
switchD_08006058_caseD_5c:
      bVar14 = param_1 == (byte *)0x0;
switchD_08006058_caseD_5d:
      pbVar9 = param_3;
      if (bVar14) goto switchD_08006058_caseD_5e;
    }
    goto switchD_08006058_caseD_60;
  case 0x35:
    goto switchD_08006058_caseD_35;
  case 0x36:
    goto code_r0x080060c8;
  case 0x37:
    goto code_r0x080060ca;
  case 0x38:
    goto code_r0x080060cc;
  case 0x39:
    goto code_r0x080060ce;
  case 0x3a:
    goto switchD_08006058_caseD_3a;
  case 0x3b:
    goto switchD_08006058_caseD_3b;
  case 0x3c:
    goto switchD_08006058_caseD_3c;
  case 0x3d:
    goto switchD_08006058_caseD_3d;
  case 0x3e:
    goto switchD_08006058_caseD_3e;
  case 0x3f:
    goto switchD_08006058_caseD_3f;
  case 0x40:
    goto switchD_08006058_caseD_40;
  case 0x41:
    goto switchD_08006058_caseD_41;
  case 0x42:
    goto switchD_08006058_caseD_42;
  case 0x43:
    goto switchD_08006058_caseD_43;
  case 0x44:
    goto switchD_08006058_caseD_44;
  case 0x45:
    *(char *)(unaff_r10 + 0x122) = (char)param_3;
  case 0x47:
switchD_08006058_caseD_47:
    param_1 = (byte *)0x0;
switchD_08006058_caseD_48:
    FUN_08009534(param_1,param_2);
switchD_08006058_caseD_4a:
    param_1 = (byte *)0xfe;
switchD_08006058_caseD_4b:
    goto switchD_08006058_caseD_70;
  case 0x46:
    goto switchD_08006058_caseD_46;
  case 0x48:
    goto switchD_08006058_caseD_48;
  case 0x49:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x4a:
    goto switchD_08006058_caseD_4a;
  case 0x4b:
    goto switchD_08006058_caseD_4b;
  case 0x4c:
    goto switchD_08006058_caseD_4c;
  case 0x4d:
    goto switchD_08006058_caseD_4d;
  case 0x4e:
    goto switchD_08006058_caseD_4e;
  case 0x4f:
    goto switchD_08006058_caseD_4f;
  case 0x50:
    goto switchD_08006058_caseD_50;
  case 0x51:
    goto switchD_08006058_caseD_51;
  case 0x52:
    goto switchD_08006058_caseD_52;
  case 0x53:
    goto switchD_08006058_caseD_53;
  case 0x54:
    goto switchD_08006058_caseD_54;
  case 0x55:
    goto switchD_08006058_caseD_55;
  case 0x56:
    goto switchD_08006058_caseD_56;
  case 0x57:
    goto switchD_08006058_caseD_57;
  case 0x58:
    goto switchD_08006058_caseD_58;
  case 0x59:
    goto switchD_08006058_caseD_59;
  case 0x5a:
    goto switchD_08006058_caseD_5a;
  case 0x5b:
    goto switchD_08006058_caseD_5b;
  case 0x5c:
    goto switchD_08006058_caseD_5c;
  case 0x5d:
    goto switchD_08006058_caseD_5d;
  case 0x5e:
    goto switchD_08006058_caseD_5e;
  case 0x5f:
    goto switchD_08006058_caseD_5f;
  case 0x60:
    goto switchD_08006058_caseD_60;
  case 0x61:
    goto switchD_08006058_caseD_61;
  case 0x62:
    goto switchD_08006058_caseD_62;
  case 99:
    goto switchD_08006058_caseD_63;
  case 100:
    goto switchD_08006058_caseD_64;
  case 0x65:
    goto switchD_08006058_caseD_65;
  case 0x66:
    goto switchD_08006058_caseD_66;
  case 0x67:
    goto switchD_08006058_caseD_67;
  case 0x68:
    goto switchD_08006058_caseD_68;
  case 0x69:
    goto switchD_08006058_caseD_69;
  case 0x6a:
    goto switchD_08006058_caseD_6a;
  case 0x6b:
    coprocessor_movefromRt(0xd,1,7,in_cr0,in_cr8);
  case 0x6d:
switchD_08006058_caseD_6d:
    *param_1 = (byte)unaff_r7;
switchD_08006058_caseD_6e:
    *param_2 = (byte)unaff_r7;
    param_3 = pbVar9;
switchD_08006058_caseD_6f:
    param_1 = (byte *)0xd;
switchD_08006058_caseD_70:
    *pbVar11 = (byte)param_1;
switchD_08006058_caseD_71:
switchD_08006058_caseD_60:
    *unaff_r6 = (char)param_3;
switchD_08006058_caseD_61:
    return;
  case 0x6c:
    goto switchD_08006058_caseD_6c;
  case 0x6e:
    goto switchD_08006058_caseD_6e;
  case 0x6f:
    goto switchD_08006058_caseD_6f;
  case 0x70:
    goto switchD_08006058_caseD_70;
  case 0x71:
    goto switchD_08006058_caseD_71;
  case 0x72:
    param_3 = (byte *)((int)param_3 << 2);
  case 0x73:
code_r0x08006144:
    pbVar9 = (byte *)((int)param_2 << 2);
code_r0x08006146:
code_r0x08006148:
    pbVar8 = (byte *)((int)param_3 << 2);
code_r0x0800614a:
code_r0x0800614c:
    param_2 = (byte *)((int)param_3 << 2);
code_r0x0800614e:
code_r0x08006150:
code_r0x08006152:
code_r0x08006154:
code_r0x08006156:
code_r0x08006158:
code_r0x0800615a:
    pbVar11 = param_2;
code_r0x0800615c:
    param_2 = (byte *)((int)pbVar9 << 4);
code_r0x0800615e:
    param_1 = (byte *)0x0;
code_r0x08006160:
    pbStack_28 = pbVar8;
    pbStack_24 = pbVar9;
    pbStack_20 = pbVar11;
code_r0x08006162:
    bVar14 = param_2 == (byte *)0x0;
code_r0x08006164:
    if (!bVar14) {
      return;
    }
code_r0x08006166:
    bVar14 = param_1 == (byte *)0x1;
switchD_08006058_caseD_86:
    if (!bVar14) {
      return;
    }
switchD_08006058_caseD_87:
    param_2 = switchD_08006058::caseD_d0;
switchD_08006058_caseD_88:
    param_1 = (byte *)0x2;
switchD_08006058_caseD_89:
    *param_2 = (byte)param_1;
switchD_08006058_caseD_8a:
    param_1 = switchD_08006058::caseD_d2;
switchD_08006058_caseD_8b:
    param_3 = (byte *)0x1;
switchD_08006058_caseD_8c:
    *param_1 = (byte)param_3;
switchD_08006058_caseD_8d:
    param_1 = switchD_08006058::caseD_d4;
switchD_08006058_caseD_8e:
    unaff_r7 = switchD_08006058::caseD_d6;
switchD_08006058_caseD_8f:
    param_1 = (byte *)(uint)*param_1;
    pbVar9 = param_3;
switchD_08006058_caseD_90:
    param_3 = switchD_08006058::caseD_d8;
switchD_08006058_caseD_91:
    unaff_r6 = (undefined1 *)0x0;
switchD_08006058_caseD_92:
    bVar14 = param_1 == (byte *)0x0;
switchD_08006058_caseD_93:
    if (bVar14) {
switchD_08006058_caseD_9d:
      param_1 = switchD_08006058::caseD_d6;
switchD_08006058_caseD_9e:
      param_1 = param_1 + 0x20;
      pbVar11 = param_2;
switchD_08006058_caseD_9f:
      param_2 = (byte *)(uint)param_1[0xf];
switchD_08006058_caseD_a0:
      bVar14 = param_2 == (byte *)0x0;
switchD_08006058_caseD_a1:
      if (!bVar14) {
switchD_08006058_caseD_a2:
        bVar14 = param_2 == (byte *)0x1;
switchD_08006058_caseD_a3:
        if (bVar14) {
switchD_08006058_caseD_b5:
          pbVar8 = switchD_08006058::caseD_e2;
switchD_08006058_caseD_b6:
          param_2 = (byte *)(uint)*pbVar8;
switchD_08006058_caseD_b7:
          bVar14 = param_2 == (byte *)0x0;
switchD_08006058_caseD_b8:
          if (bVar14) {
switchD_08006058_caseD_bc:
            *pbVar8 = (byte)pbVar9;
switchD_08006058_caseD_bd:
            goto switchD_08006058_caseD_cb;
          }
switchD_08006058_caseD_b9:
          bVar14 = param_2 == (byte *)0x1;
switchD_08006058_caseD_ba:
          if (bVar14) {
switchD_08006058_caseD_be:
            param_1 = (byte *)(uint)param_1[0xe];
switchD_08006058_caseD_bf:
            param_2 = (byte *)0x0;
switchD_08006058_caseD_c0:
            param_2 = (byte *)~(uint)param_2;
switchD_08006058_caseD_c1:
            param_1 = (byte *)((int)param_1 << 1);
switchD_08006058_caseD_c2:
            *(short *)(param_3 + (int)param_1) = (short)param_2;
switchD_08006058_caseD_c3:
            *pbVar8 = (byte)unaff_r6;
switchD_08006058_caseD_c4:
            FUN_08004f80();
switchD_08006058_caseD_c6:
            param_1 = (byte *)(uint)*(ushort *)(unaff_r7 + 0x30);
            goto switchD_08006058_caseD_c7;
          }
switchD_08006058_caseD_bb:
        }
        else {
switchD_08006058_caseD_a4:
        }
        goto switchD_08006058_caseD_cc;
      }
switchD_08006058_caseD_a5:
      param_2 = switchD_08006058::caseD_de;
switchD_08006058_caseD_a6:
      param_1 = (byte *)(uint)*param_2;
switchD_08006058_caseD_a7:
      bVar14 = param_1 == (byte *)0x0;
switchD_08006058_caseD_a8:
      if (!bVar14) {
switchD_08006058_caseD_a9:
        bVar14 = param_1 == (byte *)0x1;
switchD_08006058_caseD_aa:
        if (!bVar14) {
switchD_08006058_caseD_ab:
          goto switchD_08006058_caseD_cc;
        }
switchD_08006058_caseD_ae:
        pbVar8 = switchD_08006058::caseD_e0;
switchD_08006058_caseD_af:
        param_1 = (byte *)(uint)*(ushort *)(unaff_r7 + 0x30);
switchD_08006058_caseD_b0:
        pbVar8 = (byte *)(uint)*pbVar8;
switchD_08006058_caseD_b1:
        pbVar8 = (byte *)((int)pbVar8 << 1);
switchD_08006058_caseD_b2:
        *(short *)(param_3 + (int)pbVar8) = (short)param_1;
switchD_08006058_caseD_b3:
        *param_2 = (byte)unaff_r6;
switchD_08006058_caseD_b4:
        goto switchD_08006058_caseD_c9;
      }
switchD_08006058_caseD_ac:
      *param_2 = (byte)pbVar9;
switchD_08006058_caseD_ad:
      goto switchD_08006058_caseD_cb;
    }
switchD_08006058_caseD_94:
    param_1 = switchD_08006058::caseD_da;
switchD_08006058_caseD_95:
    param_1 = (byte *)(uint)*param_1;
switchD_08006058_caseD_96:
    bVar14 = param_1 == (byte *)0x1;
switchD_08006058_caseD_97:
    if (!bVar14) {
switchD_08006058_caseD_98:
      param_1 = switchD_08006058::caseD_dc;
switchD_08006058_caseD_99:
      param_1 = (byte *)(uint)*param_1;
switchD_08006058_caseD_9a:
      bVar14 = param_1 == (byte *)0x1;
switchD_08006058_caseD_9b:
      pbVar11 = param_2;
      if (bVar14) goto switchD_08006058_caseD_a5;
switchD_08006058_caseD_9c:
    }
    goto switchD_08006058_caseD_cc;
  case 0x74:
    goto code_r0x08006144;
  case 0x75:
    goto code_r0x08006146;
  case 0x76:
    goto code_r0x08006148;
  case 0x77:
    goto code_r0x0800614a;
  case 0x78:
    goto code_r0x0800614c;
  case 0x79:
    goto code_r0x0800614e;
  case 0x7a:
    goto code_r0x08006150;
  case 0x7b:
    goto code_r0x08006152;
  case 0x7c:
    goto code_r0x08006154;
  case 0x7d:
    goto code_r0x08006156;
  case 0x7e:
    goto code_r0x08006158;
  case 0x7f:
    goto code_r0x0800615a;
  case 0x80:
    goto code_r0x0800615c;
  case 0x81:
    goto code_r0x0800615e;
  case 0x82:
    goto code_r0x08006160;
  case 0x83:
    goto code_r0x08006162;
  case 0x84:
    goto code_r0x08006164;
  case 0x85:
    goto code_r0x08006166;
  case 0x86:
    goto switchD_08006058_caseD_86;
  case 0x87:
    goto switchD_08006058_caseD_87;
  case 0x88:
    goto switchD_08006058_caseD_88;
  case 0x89:
    goto switchD_08006058_caseD_89;
  case 0x8a:
    goto switchD_08006058_caseD_8a;
  case 0x8b:
    goto switchD_08006058_caseD_8b;
  case 0x8c:
    goto switchD_08006058_caseD_8c;
  case 0x8d:
    goto switchD_08006058_caseD_8d;
  case 0x8e:
    goto switchD_08006058_caseD_8e;
  case 0x8f:
    goto switchD_08006058_caseD_8f;
  case 0x90:
    goto switchD_08006058_caseD_90;
  case 0x91:
    goto switchD_08006058_caseD_91;
  case 0x92:
    goto switchD_08006058_caseD_92;
  case 0x93:
    goto switchD_08006058_caseD_93;
  case 0x94:
    goto switchD_08006058_caseD_94;
  case 0x95:
    goto switchD_08006058_caseD_95;
  case 0x96:
    goto switchD_08006058_caseD_96;
  case 0x97:
    goto switchD_08006058_caseD_97;
  case 0x98:
    goto switchD_08006058_caseD_98;
  case 0x99:
    goto switchD_08006058_caseD_99;
  case 0x9a:
    goto switchD_08006058_caseD_9a;
  case 0x9b:
    goto switchD_08006058_caseD_9b;
  case 0x9c:
    goto switchD_08006058_caseD_9c;
  case 0x9d:
    goto switchD_08006058_caseD_9d;
  case 0x9e:
    goto switchD_08006058_caseD_9e;
  case 0x9f:
    goto switchD_08006058_caseD_9f;
  case 0xa0:
    goto switchD_08006058_caseD_a0;
  case 0xa1:
    goto switchD_08006058_caseD_a1;
  case 0xa2:
    goto switchD_08006058_caseD_a2;
  case 0xa3:
    goto switchD_08006058_caseD_a3;
  case 0xa4:
    goto switchD_08006058_caseD_a4;
  case 0xa5:
    goto switchD_08006058_caseD_a5;
  case 0xa6:
    goto switchD_08006058_caseD_a6;
  case 0xa7:
    goto switchD_08006058_caseD_a7;
  case 0xa8:
    goto switchD_08006058_caseD_a8;
  case 0xa9:
    goto switchD_08006058_caseD_a9;
  case 0xaa:
    goto switchD_08006058_caseD_aa;
  case 0xab:
    goto switchD_08006058_caseD_ab;
  case 0xac:
    goto switchD_08006058_caseD_ac;
  case 0xad:
    goto switchD_08006058_caseD_ad;
  case 0xae:
    goto switchD_08006058_caseD_ae;
  case 0xaf:
    goto switchD_08006058_caseD_af;
  case 0xb0:
    goto switchD_08006058_caseD_b0;
  case 0xb1:
    goto switchD_08006058_caseD_b1;
  case 0xb2:
    goto switchD_08006058_caseD_b2;
  case 0xb3:
    goto switchD_08006058_caseD_b3;
  case 0xb4:
    goto switchD_08006058_caseD_b4;
  case 0xb5:
    goto switchD_08006058_caseD_b5;
  case 0xb6:
    goto switchD_08006058_caseD_b6;
  case 0xb7:
    goto switchD_08006058_caseD_b7;
  case 0xb8:
    goto switchD_08006058_caseD_b8;
  case 0xb9:
    goto switchD_08006058_caseD_b9;
  case 0xba:
    goto switchD_08006058_caseD_ba;
  case 0xbb:
    goto switchD_08006058_caseD_bb;
  case 0xbc:
    goto switchD_08006058_caseD_bc;
  case 0xbd:
    goto switchD_08006058_caseD_bd;
  case 0xbe:
    goto switchD_08006058_caseD_be;
  case 0xbf:
    goto switchD_08006058_caseD_bf;
  case 0xc0:
    goto switchD_08006058_caseD_c0;
  case 0xc1:
    goto switchD_08006058_caseD_c1;
  case 0xc2:
    goto switchD_08006058_caseD_c2;
  case 0xc3:
    goto switchD_08006058_caseD_c3;
  case 0xc4:
    goto switchD_08006058_caseD_c4;
  case 0xc5:
    coprocessor_moveto(0xe,6,1,unaff_r8,in_cr12,in_cr8);
  case 199:
switchD_08006058_caseD_c7:
    FUN_0800e228(param_1);
switchD_08006058_caseD_c9:
    param_1 = switchD_08006058::caseD_e4;
switchD_08006058_caseD_ca:
    *param_1 = (byte)pbVar9;
switchD_08006058_caseD_cb:
    *pbVar11 = (byte)pbVar9;
switchD_08006058_caseD_cc:
    param_1 = switchD_08006058::caseD_e6;
switchD_08006058_caseD_cd:
    *param_1 = (byte)unaff_r6;
switchD_08006058_caseD_ce:
    return;
  case 0xc6:
    goto switchD_08006058_caseD_c6;
  case 200:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xc9:
    goto switchD_08006058_caseD_c9;
  case 0xca:
    goto switchD_08006058_caseD_ca;
  case 0xcb:
    goto switchD_08006058_caseD_cb;
  case 0xcc:
    goto switchD_08006058_caseD_cc;
  case 0xcd:
    goto switchD_08006058_caseD_cd;
  case 0xce:
    goto switchD_08006058_caseD_ce;
  case 0xcf:
  case 0xd0:
    param_3 = (byte *)((int)param_3 << 2);
code_r0x080061fe:
code_r0x08006200:
code_r0x08006202:
code_r0x08006204:
    pbVar9 = (byte *)((int)param_2 << 2);
code_r0x08006206:
code_r0x08006208:
code_r0x0800620a:
code_r0x0800620c:
code_r0x0800620e:
code_r0x08006210:
    param_2 = (byte *)(uVar7 << 5);
code_r0x08006212:
code_r0x08006214:
code_r0x08006216:
code_r0x08006218:
code_r0x0800621a:
code_r0x0800621c:
code_r0x0800621e:
    pbVar11 = param_2;
code_r0x08006220:
    param_2 = (byte *)((int)pbVar9 << 4);
code_r0x08006222:
code_r0x08006224:
    pbVar8 = (byte *)(uVar7 << 3);
code_r0x08006226:
code_r0x08006228:
code_r0x0800622a:
    param_1 = (byte *)0x0;
code_r0x0800622c:
    pbStack_20 = pbVar11;
    pbStack_24 = pbVar9;
    pbStack_28 = pbVar8;
    pbStack_2c = param_3;
    ppbVar15 = &pbStack_30;
    pbStack_30 = param_2;
code_r0x0800622e:
    pbVar9 = param_1;
code_r0x08006230:
    bVar14 = param_3 == (byte *)0x0;
code_r0x08006232:
    if (bVar14) {
switchD_08006058_caseD_ec:
      bVar14 = param_2 == (byte *)0x1;
switchD_08006058_caseD_ed:
      if (bVar14) {
switchD_08006058_caseD_ee:
        param_3 = PTR_DAT_08006388;
switchD_08006058_caseD_ef:
        param_1 = PTR_DAT_0800638c;
switchD_08006058_caseD_f0:
        param_2 = (byte *)(uint)*param_3;
switchD_08006058_caseD_f1:
        *(byte **)((int)ppbVar15 + 4) = param_1;
switchD_08006058_caseD_f2:
        pbVar11 = (byte *)0x0;
switchD_08006058_caseD_f3:
        unaff_r7 = (undefined *)0x2;
switchD_08006058_caseD_f4:
        param_1 = (byte *)(uint)param_1[0xf];
switchD_08006058_caseD_f5:
        bVar14 = param_2 == (byte *)0x1;
switchD_08006058_caseD_f6:
        if (!bVar14) {
switchD_08006058_caseD_f7:
          param_2 = PTR_DAT_08006390;
switchD_08006058_caseD_f8:
          param_2 = (byte *)(uint)*param_2;
switchD_08006058_caseD_f9:
          bVar14 = param_2 == (byte *)0x1;
switchD_08006058_caseD_fa:
          uVar13 = SUB41(unaff_r7,0);
          if (bVar14) goto LAB_080062ba;
switchD_08006058_caseD_fb:
          param_2 = PTR_DAT_08006394;
switchD_08006058_caseD_fc:
          param_2 = (byte *)(uint)*param_2;
switchD_08006058_caseD_fd:
          bVar14 = param_2 == (byte *)0x1;
switchD_08006058_caseD_fe:
          uVar10 = SUB41(pbVar11,0);
          uVar13 = SUB41(unaff_r7,0);
          if (bVar14) {
            iVar12 = 2;
          }
          else {
switchD_08006058_caseD_ff:
            uVar10 = SUB41(pbVar11,0);
            uVar13 = SUB41(unaff_r7,0);
            if (*PTR_DAT_08006398 != '\0') goto LAB_080062ba;
            if (param_1 == (byte *)0x1) {
              iVar12 = 1;
            }
            else {
              iVar12 = 0;
            }
          }
          FUN_08005198(pbVar9);
          *PTR_DAT_080063a4 = 1;
          puVar2 = PTR_DAT_080063ac;
          puVar6 = PTR_DAT_080063a8;
          bVar3 = *PTR_DAT_080063ac;
          uVar1 = SUB41(pbVar9,0);
          if (iVar12 == 0) {
            if (bVar3 == 1) {
              if (1 < (byte)*PTR_DAT_080063a8) {
                PTR_DAT_080063a8[1] = *PTR_DAT_080063a8;
                *puVar6 = uVar10;
                *puVar2 = uVar13;
              }
LAB_08006342:
              *PTR_DAT_080063b4 = uVar1;
              return;
            }
            if (bVar3 < 4) goto LAB_08006342;
            *PTR_DAT_080063ac = uVar10;
            FUN_08004d78(PTR_DAT_080063a8,ppbVar15);
            uVar7 = FUN_080028f0(*ppbVar15,DAT_080063b0);
            puVar6 = PTR_DAT_0800638c;
            *ppbVar15 = (byte *)uVar7;
            if ((uVar7 < *(ushort *)(PTR_DAT_0800638c + 0x14)) ||
               (*(ushort *)(PTR_DAT_0800638c + 0x16) < uVar7)) {
              *PTR_DAT_080063a4 = 1;
              goto LAB_080062ba;
            }
            uVar5 = uVar7 & 0xffff;
            *PTR_DAT_080063b4 = uVar1;
            *(short *)(puVar6 + 0xc) = (short)uVar7;
          }
          else {
            if (bVar3 != 2) goto LAB_08006342;
            *PTR_DAT_080063ac = uVar10;
            bVar3 = (*puVar6 * '\n' + puVar6[1]) - 1;
            uVar7 = (uint)bVar3;
            if (iVar12 != 1) {
              if (uVar7 < 0x14) {
                *PTR_DAT_080063bc = bVar3;
                goto LAB_08006342;
              }
LAB_080062ba:
              *PTR_DAT_0800639c = uVar13;
              return;
            }
            iVar12 = FUN_08004754(uVar7);
            puVar6 = PTR_DAT_080063c0;
            if (iVar12 != 1) goto LAB_080062ba;
            *PTR_DAT_080063b4 = uVar1;
            *(byte *)((int)ppbVar15[1] + 0xe) = bVar3;
            uVar5 = (uint)*(ushort *)(puVar6 + uVar7 * 2);
            puVar6 = PTR_DAT_0800638c;
          }
          *(short *)(puVar6 + 0x10) = (short)uVar5;
LAB_08006336:
          FUN_0800e228(uVar5);
          *PTR_DAT_080063b8 = 1;
          return;
        }
        *PTR_DAT_0800639c = 1;
        *param_3 = (byte)pbVar11;
        *PTR_DAT_080063a0 = 1;
        *PTR_DAT_080063a4 = 1;
        if (pbVar9 == (byte *)0x1) {
          *(bool *)(*(int *)((int)ppbVar15 + 4) + 0xf) = param_1 == (byte *)0x0;
          iVar12 = FUN_08004f80();
          if (iVar12 == 0) {
            uVar5 = (uint)*(ushort *)(PTR_DAT_0800638c + 0x10);
            goto LAB_08006336;
          }
        }
        else {
          if (pbVar9 == (byte *)0x2) {
            uVar4 = 1;
LAB_080062ae:
            FUN_08008ee4(uVar4);
            return;
          }
          if (pbVar9 == (byte *)0x3) {
            uVar4 = 0;
            goto LAB_080062ae;
          }
          if (pbVar9 == (byte *)0x0) {
            FUN_08008d94();
            return;
          }
        }
        *puVar6 = (char)unaff_r7;
      }
    }
    return;
  case 0xd1:
    goto code_r0x080061fe;
  case 0xd2:
    goto code_r0x08006200;
  case 0xd3:
    goto code_r0x08006202;
  case 0xd4:
    goto code_r0x08006204;
  case 0xd5:
    goto code_r0x08006206;
  case 0xd6:
    goto code_r0x08006208;
  case 0xd7:
    goto code_r0x0800620a;
  case 0xd8:
    goto code_r0x0800620c;
  case 0xd9:
    goto code_r0x0800620e;
  case 0xda:
    goto code_r0x08006210;
  case 0xdb:
    goto code_r0x08006212;
  case 0xdc:
    goto code_r0x08006214;
  case 0xdd:
    goto code_r0x08006216;
  case 0xde:
    goto code_r0x08006218;
  case 0xdf:
    goto code_r0x0800621a;
  case 0xe0:
    goto code_r0x0800621c;
  case 0xe1:
    goto code_r0x0800621e;
  case 0xe2:
    goto code_r0x08006220;
  case 0xe3:
    goto code_r0x08006222;
  case 0xe4:
    goto code_r0x08006224;
  case 0xe5:
    goto code_r0x08006226;
  case 0xe6:
    goto code_r0x08006228;
  case 0xe7:
    goto code_r0x0800622a;
  case 0xe8:
    goto code_r0x0800622c;
  case 0xe9:
    goto code_r0x0800622e;
  case 0xea:
    goto code_r0x08006230;
  case 0xeb:
    goto code_r0x08006232;
  case 0xec:
    goto switchD_08006058_caseD_ec;
  case 0xed:
    goto switchD_08006058_caseD_ed;
  case 0xee:
    goto switchD_08006058_caseD_ee;
  case 0xef:
    goto switchD_08006058_caseD_ef;
  case 0xf0:
    goto switchD_08006058_caseD_f0;
  case 0xf1:
    goto switchD_08006058_caseD_f1;
  case 0xf2:
    goto switchD_08006058_caseD_f2;
  case 0xf3:
    goto switchD_08006058_caseD_f3;
  case 0xf4:
    goto switchD_08006058_caseD_f4;
  case 0xf5:
    goto switchD_08006058_caseD_f5;
  case 0xf6:
    goto switchD_08006058_caseD_f6;
  case 0xf7:
    goto switchD_08006058_caseD_f7;
  case 0xf8:
    goto switchD_08006058_caseD_f8;
  case 0xf9:
    goto switchD_08006058_caseD_f9;
  case 0xfa:
    goto switchD_08006058_caseD_fa;
  case 0xfb:
    goto switchD_08006058_caseD_fb;
  case 0xfc:
    goto switchD_08006058_caseD_fc;
  case 0xfd:
    goto switchD_08006058_caseD_fd;
  case 0xfe:
    goto switchD_08006058_caseD_fe;
  case 0xff:
    goto switchD_08006058_caseD_ff;
  }
  pbVar11 = param_3;
switchD_08006058_caseD_1f:
  param_1 = param_2;
switchD_08006058_caseD_20:
  FUN_080063c4(param_1,pbVar11,pbVar9);
switchD_08006058_caseD_22:
  return;
}



// ==== 080060c8  caseD_36  (120 bytes, 2 xrefs)

void switchD_08006058::caseD_36(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined1 uVar6;
  byte bVar7;
  uint uVar8;
  
  if (param_2 != 0) {
    return;
  }
  if (param_1 != 1) {
    return;
  }
  *caseD_72 = 1;
  puVar5 = caseD_80;
  puVar4 = caseD_7c;
  puVar3 = caseD_7a;
  puVar2 = caseD_78;
  puVar1 = caseD_76;
  if (*caseD_74 == '\0') {
    if (*caseD_7a == '\0') {
      if ((*caseD_7e != '\x01') && (*caseD_80 != '\x01')) {
        FUN_08008d94();
        return;
      }
      *caseD_7e = 0;
      *puVar5 = 0;
    }
    else {
      bVar7 = *caseD_7a - 1;
      uVar8 = (uint)bVar7;
      *caseD_7a = bVar7;
      puVar4[uVar8] = 10;
      if ((uVar8 != 0) && ((uVar8 != 1 || (*puVar4 != '\0')))) goto switchD_08006058_caseD_60;
      *puVar3 = 0;
    }
    uVar6 = 0xd;
  }
  else {
    FUN_0800b1fc();
    FUN_08009534(0,0x22);
    uVar6 = 0xfe;
  }
  *puVar1 = uVar6;
switchD_08006058_caseD_60:
  *puVar2 = 1;
  return;
}



// ==== 08006160  caseD_82  (154 bytes, 2 xrefs)

void switchD_08006058::caseD_82(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  puVar1 = caseD_d0;
  if (param_2 != 0) {
    return;
  }
  if (param_1 != 1) {
    return;
  }
  *caseD_d0 = 2;
  *caseD_d2 = 1;
  puVar4 = caseD_e2;
  puVar3 = caseD_de;
  puVar2 = caseD_d6;
  if (*caseD_d4 == '\0') {
    if (caseD_d6[0x2f] == '\0') goto switchD_08006058_caseD_a5;
    if (caseD_d6[0x2f] != '\x01') goto switchD_08006058_caseD_cc;
    if (*caseD_e2 != '\0') {
      if (*caseD_e2 != '\x01') goto switchD_08006058_caseD_cc;
      *(undefined2 *)(caseD_d8 + (uint)(byte)caseD_d6[0x2e] * 2) = 0xffff;
      *puVar4 = 0;
      FUN_08004f80();
      FUN_0800e228(*(undefined2 *)(puVar2 + 0x30));
      goto switchD_08006058_caseD_c9;
    }
    *caseD_e2 = 1;
  }
  else {
    if ((*caseD_da == '\x01') || (*caseD_dc != '\x01')) goto switchD_08006058_caseD_cc;
switchD_08006058_caseD_a5:
    if (*caseD_de == '\0') {
      *caseD_de = 1;
    }
    else {
      if (*caseD_de != '\x01') goto switchD_08006058_caseD_cc;
      *(undefined2 *)(caseD_d8 + (uint)(byte)*caseD_e0 * 2) = *(undefined2 *)(caseD_d6 + 0x30);
      *puVar3 = 0;
switchD_08006058_caseD_c9:
      *caseD_e4 = 1;
    }
  }
  *puVar1 = 1;
switchD_08006058_caseD_cc:
  *caseD_e6 = 0;
  return;
}



// ==== 0800622c  caseD_e8  (346 bytes, 2 xrefs)

void switchD_08006058::caseD_e8(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  uint local_20;
  undefined *local_1c;
  undefined4 uStack_18;
  
  puVar4 = PTR_DAT_0800639c;
  puVar3 = PTR_DAT_0800638c;
  puVar7 = PTR_DAT_08006388;
  if ((param_3 == 0) && (param_2 == 1)) {
    local_1c = PTR_DAT_0800638c;
    cVar1 = PTR_DAT_0800638c[0xf];
    local_20 = param_2;
    uStack_18 = param_4;
    if (*PTR_DAT_08006388 != '\x01') {
      if (*PTR_DAT_08006390 == '\x01') goto LAB_080062ba;
      if (*PTR_DAT_08006394 == '\x01') {
        iVar9 = 2;
      }
      else {
        if (*PTR_DAT_08006398 != '\0') goto LAB_080062ba;
        if (cVar1 == '\x01') {
          iVar9 = 1;
        }
        else {
          iVar9 = 0;
        }
      }
      FUN_08005198(param_1);
      *PTR_DAT_080063a4 = 1;
      puVar3 = PTR_DAT_080063ac;
      puVar7 = PTR_DAT_080063a8;
      bVar5 = *PTR_DAT_080063ac;
      uVar2 = (undefined1)param_1;
      if (iVar9 == 0) {
        if (bVar5 == 1) {
          if (1 < (byte)*PTR_DAT_080063a8) {
            PTR_DAT_080063a8[1] = *PTR_DAT_080063a8;
            *puVar7 = 0;
            *puVar3 = 2;
          }
LAB_08006342:
          *PTR_DAT_080063b4 = uVar2;
          return;
        }
        if (bVar5 < 4) goto LAB_08006342;
        *PTR_DAT_080063ac = 0;
        FUN_08004d78(PTR_DAT_080063a8,&local_20);
        local_20 = FUN_080028f0(local_20,DAT_080063b0);
        puVar7 = PTR_DAT_0800638c;
        if ((local_20 < *(ushort *)(PTR_DAT_0800638c + 0x14)) ||
           (*(ushort *)(PTR_DAT_0800638c + 0x16) < local_20)) {
          *PTR_DAT_080063a4 = 1;
          goto LAB_080062ba;
        }
        uVar8 = local_20 & 0xffff;
        *PTR_DAT_080063b4 = uVar2;
        *(short *)(puVar7 + 0xc) = (short)local_20;
      }
      else {
        if (bVar5 != 2) goto LAB_08006342;
        *PTR_DAT_080063ac = 0;
        bVar5 = (*puVar7 * '\n' + puVar7[1]) - 1;
        uVar8 = (uint)bVar5;
        if (iVar9 != 1) {
          if (uVar8 < 0x14) {
            *PTR_DAT_080063bc = bVar5;
            goto LAB_08006342;
          }
LAB_080062ba:
          *PTR_DAT_0800639c = 2;
          return;
        }
        iVar9 = FUN_08004754(uVar8);
        puVar7 = PTR_DAT_080063c0;
        if (iVar9 != 1) goto LAB_080062ba;
        *PTR_DAT_080063b4 = uVar2;
        local_1c[0xe] = bVar5;
        uVar8 = (uint)*(ushort *)(puVar7 + uVar8 * 2);
        puVar7 = PTR_DAT_0800638c;
      }
      *(short *)(puVar7 + 0x10) = (short)uVar8;
LAB_08006336:
      FUN_0800e228(uVar8);
      *PTR_DAT_080063b8 = 1;
      return;
    }
    *PTR_DAT_0800639c = 1;
    *puVar7 = 0;
    *PTR_DAT_080063a0 = 1;
    *PTR_DAT_080063a4 = 1;
    if (param_1 == 1) {
      puVar3[0xf] = cVar1 == '\0';
      iVar9 = FUN_08004f80();
      if (iVar9 == 0) {
        uVar8 = (uint)*(ushort *)(PTR_DAT_0800638c + 0x10);
        goto LAB_08006336;
      }
    }
    else {
      if (param_1 == 2) {
        uVar6 = 1;
LAB_080062ae:
        FUN_08008ee4(uVar6);
        return;
      }
      if (param_1 == 3) {
        uVar6 = 0;
        goto LAB_080062ae;
      }
      if (param_1 == 0) {
        FUN_08008d94();
        return;
      }
    }
    *puVar4 = 2;
  }
  return;
}



// ==== 080063c4  FUN_080063c4  (192 bytes, 1 xrefs)

void FUN_080063c4(int param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  uint uVar8;
  
  puVar4 = PTR_DAT_0800648c;
  puVar2 = PTR_DAT_08006484;
  bVar1 = PTR_DAT_08006484[0xe];
  if ((param_2 == 0) && (param_1 == 1)) {
    if (*PTR_DAT_08006488 != '\0') goto LAB_08006408;
    *PTR_DAT_0800648c = 1;
  }
  else {
    if (*PTR_DAT_08006488 != '\0') {
      return;
    }
    if (param_1 != 1) {
      return;
    }
  }
  puVar5 = PTR_DAT_0800649c;
  puVar3 = PTR_DAT_08006484;
  if (*PTR_DAT_08006490 == '\x01') {
    uVar6 = FUN_08004284(*PTR_DAT_0800649c,param_3,0,0x13,param_4);
    *puVar5 = uVar6;
    goto LAB_0800642e;
  }
  if (*PTR_DAT_08006494 != '\0') {
    if (*PTR_DAT_08006498 != '\0') {
LAB_08006408:
      *puVar4 = 2;
      return;
    }
    FUN_0800af60(*(undefined2 *)(PTR_DAT_08006484 + 0x10),param_3,0);
    goto LAB_0800642e;
  }
  if (puVar2[0xf] == '\0') {
    uVar8 = (uint)*(ushort *)(PTR_DAT_08006484 + 0xc) + param_3;
    if (*(ushort *)(PTR_DAT_08006484 + 0x16) < uVar8) {
      uVar8 = (uint)*(ushort *)(PTR_DAT_08006484 + 0x14);
    }
    else if (uVar8 < *(ushort *)(PTR_DAT_08006484 + 0x14)) {
      uVar8 = (uint)*(ushort *)(PTR_DAT_08006484 + 0x16);
    }
    uVar7 = (undefined2)uVar8;
    *(undefined2 *)(PTR_DAT_08006484 + 0xc) = uVar7;
LAB_08006456:
    *(undefined2 *)(puVar3 + 0x10) = uVar7;
    *PTR_DAT_080064a8 = 1;
  }
  else {
    uVar8 = FUN_08004f4c((uint)bVar1 + param_3 & 0xff,param_3);
    if ((uVar8 != 0xff) && (bVar1 != uVar8)) {
      puVar2[0xe] = (char)uVar8;
      uVar7 = *(undefined2 *)(PTR_DAT_080064a4 + uVar8 * 2);
      goto LAB_08006456;
    }
  }
  FUN_0800e228(*(undefined2 *)(puVar3 + 0x10));
LAB_0800642e:
  *PTR_DAT_080064a0 = 1;
  return;
}



// ==== 080064ac  FUN_080064ac  (122 bytes, 1 xrefs)

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x080064b4) */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x08006634) overlaps instruction at (ram,0x08006632)
    */
/* WARNING: Removing unreachable block (ram,0x080064b4) */

void FUN_080064ac(byte *param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  undefined *puVar9;
  byte *pbVar10;
  byte bVar11;
  undefined1 uVar12;
  byte *pbVar13;
  byte *unaff_r6;
  byte *unaff_r7;
  int unaff_r8;
  int unaff_r9;
  char in_CY;
  char in_OV;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  
  bVar14 = (int)param_1 < 0;
  bVar15 = param_1 == (byte *)0x0;
  if (param_1 < (byte *)0x16) {
    bVar11 = param_1[0x80064b9];
  }
  else {
    bVar11 = 0x2b;
  }
  pbVar8 = (byte *)((uint)bVar11 * 2);
  bVar1 = (byte)param_2;
  pbVar13 = param_2;
  pbVar10 = param_3;
  bVar16 = bVar15;
  switch(bVar11) {
  case 0:
  case 1:
switchD_080064b4_caseD_2:
switchD_080064b4_caseD_3:
switchD_080064b4_caseD_4:
switchD_080064b4_caseD_5:
switchD_080064b4_caseD_6:
switchD_080064b4_caseD_7:
switchD_080064b4_caseD_8:
switchD_080064b4_caseD_9:
switchD_080064b4_caseD_a:
switchD_080064b4_caseD_b:
switchD_080064b4_caseD_c:
    param_1 = param_2;
switchD_080064b4_caseD_d:
    FUN_080071b4(param_1);
switchD_080064b4_caseD_f:
    return;
  case 2:
    goto switchD_080064b4_caseD_2;
  case 3:
    goto switchD_080064b4_caseD_3;
  case 4:
    goto switchD_080064b4_caseD_4;
  case 5:
    goto switchD_080064b4_caseD_5;
  case 6:
    goto switchD_080064b4_caseD_6;
  case 7:
    goto switchD_080064b4_caseD_7;
  case 8:
    goto switchD_080064b4_caseD_8;
  case 9:
    goto switchD_080064b4_caseD_9;
  case 10:
    goto switchD_080064b4_caseD_a;
  case 0xb:
    goto switchD_080064b4_caseD_b;
  case 0xc:
    goto switchD_080064b4_caseD_c;
  case 0xd:
    goto switchD_080064b4_caseD_d;
  case 0xe:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xf:
    goto switchD_080064b4_caseD_f;
  case 0x10:
    pbVar13 = param_3;
  case 0x11:
    param_1 = param_2;
switchD_080064b4_caseD_12:
    switchD_080064b4::caseD_82(param_1,pbVar13);
switchD_080064b4_caseD_14:
    return;
  case 0x12:
    goto switchD_080064b4_caseD_12;
  case 0x13:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x14:
    goto switchD_080064b4_caseD_14;
  case 0x15:
    pbVar13 = param_3;
  case 0x16:
    param_1 = param_2;
switchD_080064b4_caseD_17:
    switchD_080064b4::caseD_36(param_1,pbVar13);
switchD_080064b4_caseD_19:
    return;
  case 0x17:
    goto switchD_080064b4_caseD_17;
  case 0x18:
  case 0x1a:
    pbVar13 = param_3;
switchD_080064b4_caseD_1b:
    param_1 = param_2;
switchD_080064b4_caseD_1c:
    FUN_080068c4(param_1,pbVar13);
switchD_080064b4_caseD_1e:
    return;
  case 0x19:
    goto switchD_080064b4_caseD_19;
  case 0x1b:
    goto switchD_080064b4_caseD_1b;
  case 0x1c:
    goto switchD_080064b4_caseD_1c;
  case 0x1d:
  case 0x1f:
    pbVar10 = (byte *)0x0;
switchD_080064b4_caseD_20:
    pbVar10 = (byte *)~(uint)pbVar10;
switchD_080064b4_caseD_21:
    break;
  case 0x1e:
    goto switchD_080064b4_caseD_1e;
  case 0x20:
    goto switchD_080064b4_caseD_20;
  case 0x21:
    goto switchD_080064b4_caseD_21;
  case 0x22:
    pbVar10 = (byte *)0x1;
    break;
  case 0x24:
    goto switchD_080064b4_caseD_24;
  case 0x25:
    goto switchD_080064b4_caseD_25;
  case 0x26:
  case 0x28:
    FUN_08006838();
switchD_080064b4_caseD_2a:
    return;
  case 0x27:
    goto switchD_080064b4_caseD_27;
  case 0x29:
  case 0x2b:
    bVar15 = param_3 == (byte *)0x0;
switchD_080064b4_caseD_2c:
    if (!bVar15) {
      return;
    }
switchD_080064b4_caseD_2d:
    bVar15 = param_2 == (byte *)0x1;
switchD_080064b4_caseD_2e:
    if (!bVar15) {
      return;
    }
switchD_080064b4_caseD_2f:
    param_2 = &DAT_20000092;
switchD_080064b4_caseD_30:
    param_1 = (byte *)0x2;
switchD_080064b4_caseD_31:
    *param_2 = (byte)param_1;
switchD_080064b4_caseD_32:
    return;
  case 0x2a:
    goto switchD_080064b4_caseD_2a;
  case 0x2c:
    goto switchD_080064b4_caseD_2c;
  case 0x2d:
    goto switchD_080064b4_caseD_2d;
  case 0x2e:
    goto switchD_080064b4_caseD_2e;
  case 0x2f:
    goto switchD_080064b4_caseD_2f;
  case 0x30:
    goto switchD_080064b4_caseD_30;
  case 0x31:
    goto switchD_080064b4_caseD_31;
  case 0x32:
    goto switchD_080064b4_caseD_32;
  case 0x33:
  case 0x34:
switchD_080064b4_caseD_35:
    param_1 = (byte *)0x0;
code_r0x08006524:
code_r0x08006526:
    bVar15 = param_2 == (byte *)0x0;
code_r0x08006528:
    if (!bVar15) {
switchD_080064b4_caseD_5c:
      return;
    }
code_r0x0800652a:
    bVar15 = param_1 == (byte *)0x1;
switchD_080064b4_caseD_3a:
    if (!bVar15) {
      return;
    }
switchD_080064b4_caseD_3b:
    param_1 = switchD_080064b4::caseD_6a;
switchD_080064b4_caseD_3c:
    unaff_r6 = (byte *)0x1;
switchD_080064b4_caseD_3d:
    param_2 = switchD_080064b4::caseD_6c;
switchD_080064b4_caseD_3e:
    *param_1 = (byte)unaff_r6;
switchD_080064b4_caseD_3f:
    param_1 = (byte *)(uint)*param_2;
switchD_080064b4_caseD_40:
    param_3 = switchD_080064b4::caseD_6e;
switchD_080064b4_caseD_41:
    pbVar8 = (byte *)0xd;
switchD_080064b4_caseD_42:
    pbVar10 = switchD_080064b4::caseD_70;
switchD_080064b4_caseD_43:
    bVar15 = param_1 == (byte *)0x0;
switchD_080064b4_caseD_44:
    if (bVar15) {
switchD_080064b4_caseD_4d:
      *param_3 = bVar1;
switchD_080064b4_caseD_4e:
      param_1 = switchD_080064b4::caseD_72;
switchD_080064b4_caseD_4f:
      param_2 = switchD_080064b4::caseD_74;
switchD_080064b4_caseD_50:
      param_1 = (byte *)(uint)*param_1;
switchD_080064b4_caseD_51:
      param_2[0x1b] = (byte)param_1;
switchD_080064b4_caseD_52:
      param_1 = switchD_080064b4::caseD_76;
switchD_080064b4_caseD_53:
      param_2 = switchD_080064b4::caseD_7a;
switchD_080064b4_caseD_54:
      *param_1 = (byte)unaff_r6;
switchD_080064b4_caseD_55:
      param_1 = switchD_080064b4::caseD_78;
switchD_080064b4_caseD_56:
      *param_1 = (byte)unaff_r6;
switchD_080064b4_caseD_57:
      param_1 = (byte *)0x2;
switchD_080064b4_caseD_58:
      *param_2 = (byte)param_1;
switchD_080064b4_caseD_59:
      param_1 = switchD_080064b4::caseD_7c;
switchD_080064b4_caseD_5a:
      *param_1 = (byte)unaff_r6;
switchD_080064b4_caseD_5b:
      *pbVar10 = (byte)pbVar8;
      return;
    }
switchD_080064b4_caseD_45:
    unaff_r6 = (byte *)0x3;
switchD_080064b4_caseD_46:
    bVar15 = param_1 == (byte *)0x1;
switchD_080064b4_caseD_47:
    if (bVar15) {
switchD_080064b4_caseD_5d:
      unaff_r7 = switchD_080064b4::caseD_7e;
switchD_080064b4_caseD_5e:
      param_1 = (byte *)(uint)*unaff_r7;
switchD_080064b4_caseD_5f:
      bVar15 = param_1 == (byte *)0x0;
switchD_080064b4_caseD_60:
      if (bVar15) goto switchD_080064b4_caseD_4a;
switchD_080064b4_caseD_61:
      param_1 = param_1 + -1;
switchD_080064b4_caseD_62:
      param_1 = (byte *)((uint)param_1 & 0xff);
switchD_080064b4_caseD_63:
      pbVar8 = switchD_080064b4::caseD_80;
switchD_080064b4_caseD_64:
      *unaff_r7 = (byte)param_1;
switchD_080064b4_caseD_65:
      param_2 = (byte *)0xa;
switchD_080064b4_caseD_66:
      pbVar8[(int)param_1] = (byte)param_2;
    }
    else {
switchD_080064b4_caseD_48:
      bVar15 = param_1 == (byte *)0x2;
switchD_080064b4_caseD_49:
      if (!bVar15) {
        return;
      }
switchD_080064b4_caseD_4a:
      *param_2 = bVar1;
switchD_080064b4_caseD_4b:
      *pbVar10 = (byte)pbVar8;
switchD_080064b4_caseD_4c:
    }
switchD_080064b4_caseD_67:
    *param_3 = (byte)unaff_r6;
switchD_080064b4_caseD_68:
    return;
  case 0x35:
    goto switchD_080064b4_caseD_35;
  case 0x36:
    goto code_r0x08006524;
  case 0x37:
    goto code_r0x08006526;
  case 0x38:
    goto code_r0x08006528;
  case 0x39:
    goto code_r0x0800652a;
  case 0x3a:
    goto switchD_080064b4_caseD_3a;
  case 0x3b:
    goto switchD_080064b4_caseD_3b;
  case 0x3c:
    goto switchD_080064b4_caseD_3c;
  case 0x3d:
    goto switchD_080064b4_caseD_3d;
  case 0x3e:
    goto switchD_080064b4_caseD_3e;
  case 0x3f:
    goto switchD_080064b4_caseD_3f;
  case 0x40:
    goto switchD_080064b4_caseD_40;
  case 0x41:
    goto switchD_080064b4_caseD_41;
  case 0x42:
    goto switchD_080064b4_caseD_42;
  case 0x43:
    goto switchD_080064b4_caseD_43;
  case 0x44:
    goto switchD_080064b4_caseD_44;
  case 0x45:
    goto switchD_080064b4_caseD_45;
  case 0x46:
    goto switchD_080064b4_caseD_46;
  case 0x47:
    goto switchD_080064b4_caseD_47;
  case 0x48:
    goto switchD_080064b4_caseD_48;
  case 0x49:
    goto switchD_080064b4_caseD_49;
  case 0x4a:
    goto switchD_080064b4_caseD_4a;
  case 0x4b:
    goto switchD_080064b4_caseD_4b;
  case 0x4c:
    goto switchD_080064b4_caseD_4c;
  case 0x4d:
    goto switchD_080064b4_caseD_4d;
  case 0x4e:
    goto switchD_080064b4_caseD_4e;
  case 0x4f:
    goto switchD_080064b4_caseD_4f;
  case 0x50:
    goto switchD_080064b4_caseD_50;
  case 0x51:
    goto switchD_080064b4_caseD_51;
  case 0x52:
    goto switchD_080064b4_caseD_52;
  case 0x53:
    goto switchD_080064b4_caseD_53;
  case 0x54:
    goto switchD_080064b4_caseD_54;
  case 0x55:
    goto switchD_080064b4_caseD_55;
  case 0x56:
    goto switchD_080064b4_caseD_56;
  case 0x57:
    goto switchD_080064b4_caseD_57;
  case 0x58:
    goto switchD_080064b4_caseD_58;
  case 0x59:
    goto switchD_080064b4_caseD_59;
  case 0x5a:
    goto switchD_080064b4_caseD_5a;
  case 0x5b:
    goto switchD_080064b4_caseD_5b;
  case 0x5c:
    goto switchD_080064b4_caseD_5c;
  case 0x5d:
    goto switchD_080064b4_caseD_5d;
  case 0x5e:
    goto switchD_080064b4_caseD_5e;
  case 0x5f:
    goto switchD_080064b4_caseD_5f;
  case 0x60:
    goto switchD_080064b4_caseD_60;
  case 0x61:
    goto switchD_080064b4_caseD_61;
  case 0x62:
    goto switchD_080064b4_caseD_62;
  case 99:
    goto switchD_080064b4_caseD_63;
  case 100:
    goto switchD_080064b4_caseD_64;
  case 0x65:
    goto switchD_080064b4_caseD_65;
  case 0x66:
    goto switchD_080064b4_caseD_66;
  case 0x67:
    goto switchD_080064b4_caseD_67;
  case 0x68:
    goto switchD_080064b4_caseD_68;
  case 0x69:
  case 0x6a:
    param_3 = (byte *)((int)param_3 << 2);
code_r0x0800658e:
code_r0x08006590:
code_r0x08006592:
code_r0x08006594:
code_r0x08006596:
code_r0x08006598:
    pbVar8 = (byte *)((int)param_3 << 2);
code_r0x0800659a:
code_r0x0800659c:
    param_2 = (byte *)((int)pbVar8 << 5);
code_r0x0800659e:
code_r0x080065a0:
code_r0x080065a2:
code_r0x080065a4:
code_r0x080065a6:
code_r0x080065a8:
code_r0x080065aa:
code_r0x080065ac:
code_r0x080065ae:
code_r0x080065b0:
code_r0x080065b2:
code_r0x080065b4:
code_r0x080065b6:
code_r0x080065b8:
code_r0x080065ba:
    param_1 = (byte *)0x0;
code_r0x080065bc:
code_r0x080065be:
    unaff_r7 = PTR_DAT_080067cc;
code_r0x080065c0:
    param_3 = param_1;
code_r0x080065c2:
    param_1 = *(byte **)unaff_r7;
switchD_080064b4_caseD_86:
    bVar15 = param_2 == (byte *)0x0;
switchD_080064b4_caseD_87:
    unaff_r6 = (byte *)(uint)param_1[0x1e];
switchD_080064b4_caseD_88:
    param_1 = PTR_DAT_080067d0;
switchD_080064b4_caseD_89:
    pbVar10 = (byte *)(uint)param_1[9];
switchD_080064b4_caseD_8a:
    if (!bVar15) {
      return;
    }
switchD_080064b4_caseD_8b:
    bVar15 = param_3 == (byte *)0x1;
switchD_080064b4_caseD_8c:
    if (!bVar15) {
      return;
    }
switchD_080064b4_caseD_8d:
    param_3 = PTR_DAT_080067d4;
switchD_080064b4_caseD_8e:
    param_2 = PTR_DAT_080067d8;
switchD_080064b4_caseD_8f:
    param_1 = (byte *)(uint)*param_3;
switchD_080064b4_caseD_90:
    param_2 = (byte *)(uint)*param_2;
switchD_080064b4_caseD_91:
    pbVar8 = param_1;
switchD_080064b4_caseD_92:
    pbVar8 = (byte *)((uint)pbVar8 | (uint)param_2);
switchD_080064b4_caseD_93:
    pbVar13 = (byte *)0x2;
switchD_080064b4_caseD_94:
    bVar15 = pbVar8 == (byte *)0x0;
switchD_080064b4_caseD_95:
    do {
      while( true ) {
        uVar3 = SUB41(pbVar13,0);
        if (bVar15) goto LAB_080067a0;
switchD_080064b4_caseD_96:
        bVar15 = param_1 == (byte *)0x1;
switchD_080064b4_caseD_97:
        if (bVar15) break;
switchD_080064b4_caseD_98:
        bVar15 = param_1 == (byte *)0x3;
switchD_080064b4_caseD_99:
        if (!bVar15) goto switchD_080064b4_caseD_9a;
      }
switchD_080064b4_caseD_c6:
      bVar16 = param_2 == (byte *)0x1;
switchD_080064b4_caseD_c7:
      bVar15 = true;
    } while (bVar16);
switchD_080064b4_caseD_c8:
switchD_080064b4_caseD_9a:
    param_1 = PTR_DAT_080067dc;
switchD_080064b4_caseD_9b:
    param_3 = (byte *)0x1;
switchD_080064b4_caseD_9c:
    *param_1 = (byte)param_3;
switchD_080064b4_caseD_9d:
    param_1 = PTR_DAT_080067e0;
switchD_080064b4_caseD_9e:
    pbVar8 = PTR_DAT_080067e4;
switchD_080064b4_caseD_9f:
    param_3 = (byte *)(uint)*param_1;
switchD_080064b4_caseD_a0:
    param_1 = *(byte **)pbVar8;
switchD_080064b4_caseD_a1:
    bVar15 = param_3 == (byte *)0x0;
switchD_080064b4_caseD_a2:
    if (bVar15) {
switchD_080064b4_caseD_c9:
      bVar15 = param_2 == (byte *)0x0;
switchD_080064b4_caseD_ca:
      if (bVar15) {
switchD_080064b4_caseD_cb:
        param_3 = (byte *)0x0;
switchD_080064b4_caseD_cc:
        param_2 = (byte *)0xfa;
switchD_080064b4_caseD_cd:
        unaff_r7 = pbVar8;
switchD_080064b4_caseD_ce:
        param_1 = (byte *)FUN_08003d08(param_1,param_2,param_3);
switchD_080064b4_caseD_d0:
        pbVar10 = param_1;
        param_2 = pbVar13;
        goto switchD_080064b4_caseD_d1;
      }
      goto switchD_080064b4_caseD_f3;
    }
switchD_080064b4_caseD_a3:
    bVar15 = param_3 == (byte *)0x2;
switchD_080064b4_caseD_a4:
    if (bVar15) {
      if (param_2 == (byte *)0x0) {
        uVar6 = FUN_0800408c();
        FUN_0800a9a8(*(undefined4 *)unaff_r7,unaff_r6,uVar6,*(undefined4 *)PTR_DAT_080067e4);
        if (*PTR_DAT_08006818 == '\x01') {
          iVar5 = *(int *)unaff_r7;
          *(undefined *)(iVar5 + 4) = *PTR_DAT_08006810;
          *(undefined *)(iVar5 + 5) = *PTR_DAT_08006814;
        }
        puVar7 = *(undefined4 **)unaff_r7;
        puVar7[3] = puVar7[1];
        puVar7[2] = *puVar7;
        *(undefined *)((int)puVar7 + 0x26) = *PTR_DAT_08006804;
      }
      else {
        FUN_08009938(0,2);
        FUN_08009938(1,2);
        puVar2 = PTR_DAT_08006814;
        uVar3 = *PTR_DAT_08006810;
        iVar5 = *(int *)unaff_r7;
        *(undefined1 *)(iVar5 + 4) = uVar3;
        uVar12 = *puVar2;
        *(undefined1 *)(iVar5 + 5) = uVar12;
        *(undefined1 *)(iVar5 + 0xc) = uVar3;
        *(undefined1 *)(iVar5 + 0xd) = uVar12;
      }
      puVar2 = PTR_DAT_080067d0;
      if (unaff_r6 < (byte *)0xc8) {
        uVar3 = *PTR_DAT_08006808;
        iVar5 = *(int *)unaff_r7;
        puVar9 = PTR_DAT_080067d0 + (int)pbVar10;
        *(undefined1 *)(iVar5 + 0x1e) = uVar3;
        puVar9[4] = uVar3;
        puVar2[(int)pbVar10] = uVar3;
        puVar2 = PTR_DAT_080067fc;
        if (*PTR_DAT_080067fc == '\0') {
          FUN_0800298c(iVar5 + 0x34,0x10,0xff);
        }
        else {
          FUN_08002968(iVar5 + 0x34,PTR_DAT_080067f8,0x10);
        }
        *puVar2 = 0;
      }
      else {
        cVar4 = *(char *)(*(int *)unaff_r7 + 0x2e) + -0x38;
        *(char *)(*(int *)unaff_r7 + 0x1e) = cVar4;
        puVar2 = PTR_DAT_080067d0;
        (PTR_DAT_080067d0 + (int)pbVar10)[2] = cVar4;
        puVar2[(int)pbVar10] = cVar4;
      }
      puVar2 = PTR_DAT_080067e0;
      *PTR_DAT_0800681c = (char)pbVar13;
      *puVar2 = 0;
      uVar3 = 0x10;
      goto LAB_08006790;
    }
switchD_080064b4_caseD_a5:
    unaff_r7 = PTR_DAT_080067e0;
switchD_080064b4_caseD_a6:
    bVar15 = param_3 == (byte *)0x1;
switchD_080064b4_caseD_a7:
    if (!bVar15) {
      return;
    }
switchD_080064b4_caseD_a8:
    param_2 = PTR_DAT_080067e8;
switchD_080064b4_caseD_a9:
    unaff_r6 = PTR_DAT_080067ec;
switchD_080064b4_caseD_aa:
    param_3 = (byte *)(uint)*param_2;
switchD_080064b4_caseD_ab:
    param_1 = (byte *)(uint)*unaff_r6;
switchD_080064b4_caseD_ac:
    bVar15 = param_3 == (byte *)0x0;
switchD_080064b4_caseD_ad:
    uVar3 = SUB41(pbVar13,0);
    if (bVar15) {
      if (param_1 != (byte *)0x0) {
LAB_080067a0:
        *PTR_DAT_080067dc = uVar3;
        return;
      }
      *param_2 = 1;
      *PTR_DAT_08006828 = 10;
      FUN_08004920();
      *PTR_DAT_0800682c = 0x78;
      *PTR_DAT_08006830 = 0x78;
      *PTR_DAT_08006834 = 1;
      goto LAB_08006794;
    }
switchD_080064b4_caseD_ae:
    param_3 = (byte *)0x0;
switchD_080064b4_caseD_af:
    *param_2 = (byte)param_3;
switchD_080064b4_caseD_b0:
    param_2 = PTR_DAT_080067f0;
    pbVar10 = param_3;
switchD_080064b4_caseD_b1:
    param_3 = (byte *)(uint)*param_2;
switchD_080064b4_caseD_b2:
    bVar15 = param_3 == (byte *)0xff;
switchD_080064b4_caseD_b3:
    if (!bVar15) {
switchD_080064b4_caseD_b4:
      param_1 = param_1 + 1;
switchD_080064b4_caseD_b5:
      *unaff_r6 = (byte)param_1;
switchD_080064b4_caseD_b6:
      param_1 = (byte *)0xff;
switchD_080064b4_caseD_b7:
      *param_2 = (byte)param_1;
    }
switchD_080064b4_caseD_b8:
    param_3 = (byte *)(uint)*unaff_r6;
switchD_080064b4_caseD_b9:
    bVar15 = param_3 == (byte *)0x0;
switchD_080064b4_caseD_ba:
    bVar11 = (byte)pbVar13;
    if (!bVar15) {
switchD_080064b4_caseD_bb:
      param_2 = PTR_DAT_080067f4;
switchD_080064b4_caseD_bc:
      param_1 = PTR_DAT_080067f8;
switchD_080064b4_caseD_bd:
      FUN_08002968(param_1,param_2);
      param_3 = pbVar10;
switchD_080064b4_caseD_bf:
      param_1 = PTR_DAT_080067f8;
      goto switchD_080064b4_caseD_c0;
    }
    *PTR_DAT_080067fc = (char)pbVar10;
    goto LAB_080067c8;
  case 0x6b:
    goto code_r0x0800658e;
  case 0x6c:
    goto code_r0x08006590;
  case 0x6d:
    goto code_r0x08006592;
  case 0x6e:
    goto code_r0x08006594;
  case 0x6f:
    goto code_r0x08006596;
  case 0x70:
    goto code_r0x08006598;
  case 0x71:
    goto code_r0x0800659a;
  case 0x72:
    goto code_r0x0800659c;
  case 0x73:
    goto code_r0x0800659e;
  case 0x74:
    goto code_r0x080065a0;
  case 0x75:
    goto code_r0x080065a2;
  case 0x76:
    goto code_r0x080065a4;
  case 0x77:
    goto code_r0x080065a6;
  case 0x78:
    goto code_r0x080065a8;
  case 0x79:
    goto code_r0x080065aa;
  case 0x7a:
    goto code_r0x080065ac;
  case 0x7b:
    goto code_r0x080065ae;
  case 0x7c:
    goto code_r0x080065b0;
  case 0x7d:
    goto code_r0x080065b2;
  case 0x7e:
    goto code_r0x080065b4;
  case 0x7f:
    goto code_r0x080065b6;
  case 0x80:
    goto code_r0x080065b8;
  case 0x81:
    goto code_r0x080065ba;
  case 0x82:
    goto code_r0x080065bc;
  case 0x83:
    goto code_r0x080065be;
  case 0x84:
    goto code_r0x080065c0;
  case 0x85:
    goto code_r0x080065c2;
  case 0x86:
    goto switchD_080064b4_caseD_86;
  case 0x87:
    goto switchD_080064b4_caseD_87;
  case 0x88:
    goto switchD_080064b4_caseD_88;
  case 0x89:
    goto switchD_080064b4_caseD_89;
  case 0x8a:
    goto switchD_080064b4_caseD_8a;
  case 0x8b:
    goto switchD_080064b4_caseD_8b;
  case 0x8c:
    goto switchD_080064b4_caseD_8c;
  case 0x8d:
    goto switchD_080064b4_caseD_8d;
  case 0x8e:
    goto switchD_080064b4_caseD_8e;
  case 0x8f:
    goto switchD_080064b4_caseD_8f;
  case 0x90:
    goto switchD_080064b4_caseD_90;
  case 0x91:
    goto switchD_080064b4_caseD_91;
  case 0x92:
    goto switchD_080064b4_caseD_92;
  case 0x93:
    goto switchD_080064b4_caseD_93;
  case 0x94:
    goto switchD_080064b4_caseD_94;
  case 0x95:
    goto switchD_080064b4_caseD_95;
  case 0x96:
    goto switchD_080064b4_caseD_96;
  case 0x97:
    goto switchD_080064b4_caseD_97;
  case 0x98:
    goto switchD_080064b4_caseD_98;
  case 0x99:
    goto switchD_080064b4_caseD_99;
  case 0x9a:
    goto switchD_080064b4_caseD_9a;
  case 0x9b:
    goto switchD_080064b4_caseD_9b;
  case 0x9c:
    goto switchD_080064b4_caseD_9c;
  case 0x9d:
    goto switchD_080064b4_caseD_9d;
  case 0x9e:
    goto switchD_080064b4_caseD_9e;
  case 0x9f:
    goto switchD_080064b4_caseD_9f;
  case 0xa0:
    goto switchD_080064b4_caseD_a0;
  case 0xa1:
    goto switchD_080064b4_caseD_a1;
  case 0xa2:
    goto switchD_080064b4_caseD_a2;
  case 0xa3:
    goto switchD_080064b4_caseD_a3;
  case 0xa4:
    goto switchD_080064b4_caseD_a4;
  case 0xa5:
    goto switchD_080064b4_caseD_a5;
  case 0xa6:
    goto switchD_080064b4_caseD_a6;
  case 0xa7:
    goto switchD_080064b4_caseD_a7;
  case 0xa8:
    goto switchD_080064b4_caseD_a8;
  case 0xa9:
    goto switchD_080064b4_caseD_a9;
  case 0xaa:
    goto switchD_080064b4_caseD_aa;
  case 0xab:
    goto switchD_080064b4_caseD_ab;
  case 0xac:
    goto switchD_080064b4_caseD_ac;
  case 0xad:
    goto switchD_080064b4_caseD_ad;
  case 0xae:
    goto switchD_080064b4_caseD_ae;
  case 0xaf:
    goto switchD_080064b4_caseD_af;
  case 0xb0:
    goto switchD_080064b4_caseD_b0;
  case 0xb1:
    goto switchD_080064b4_caseD_b1;
  case 0xb2:
    goto switchD_080064b4_caseD_b2;
  case 0xb3:
    goto switchD_080064b4_caseD_b3;
  case 0xb4:
    goto switchD_080064b4_caseD_b4;
  case 0xb5:
    goto switchD_080064b4_caseD_b5;
  case 0xb6:
    goto switchD_080064b4_caseD_b6;
  case 0xb7:
    goto switchD_080064b4_caseD_b7;
  case 0xb8:
    goto switchD_080064b4_caseD_b8;
  case 0xb9:
    goto switchD_080064b4_caseD_b9;
  case 0xba:
    goto switchD_080064b4_caseD_ba;
  case 0xbb:
    goto switchD_080064b4_caseD_bb;
  case 0xbc:
    goto switchD_080064b4_caseD_bc;
  case 0xbd:
    goto switchD_080064b4_caseD_bd;
  case 0xbe:
    param_3 = (byte *)(int)*(char *)(unaff_r9 + 0x870);
  case 0xc0:
switchD_080064b4_caseD_c0:
    param_2 = (byte *)(uint)*unaff_r6;
switchD_080064b4_caseD_c1:
    param_1[(int)param_2] = (byte)param_3;
switchD_080064b4_caseD_c2:
    param_1 = PTR_DAT_080067fc;
switchD_080064b4_caseD_c3:
    param_2 = (byte *)0x1;
switchD_080064b4_caseD_c4:
    *param_1 = (byte)param_2;
switchD_080064b4_caseD_c5:
    bVar11 = (byte)pbVar13;
LAB_080067c8:
    *unaff_r7 = bVar11;
LAB_08006794:
    *PTR_DAT_08006824 = 3;
    return;
  case 0xbf:
    goto switchD_080064b4_caseD_bf;
  case 0xc1:
    goto switchD_080064b4_caseD_c1;
  case 0xc2:
    goto switchD_080064b4_caseD_c2;
  case 0xc3:
    goto switchD_080064b4_caseD_c3;
  case 0xc4:
    goto switchD_080064b4_caseD_c4;
  case 0xc5:
    goto switchD_080064b4_caseD_c5;
  case 0xc6:
    goto switchD_080064b4_caseD_c6;
  case 199:
    goto switchD_080064b4_caseD_c7;
  case 200:
    goto switchD_080064b4_caseD_c8;
  case 0xc9:
    goto switchD_080064b4_caseD_c9;
  case 0xca:
    goto switchD_080064b4_caseD_ca;
  case 0xcb:
    goto switchD_080064b4_caseD_cb;
  case 0xcc:
    goto switchD_080064b4_caseD_cc;
  case 0xcd:
    goto switchD_080064b4_caseD_cd;
  case 0xce:
    goto switchD_080064b4_caseD_ce;
  case 0xcf:
    unaff_r6 = (byte *)((longlong)unaff_r8 * (longlong)(int)param_3 + (ZEXT48(param_3) << 0x20) >>
                       0x20);
  case 0xd1:
switchD_080064b4_caseD_d1:
    param_3 = (byte *)0x0;
    pbVar13 = param_2;
switchD_080064b4_caseD_d2:
    param_2 = DAT_08006800;
switchD_080064b4_caseD_d3:
    param_1 = *(byte **)unaff_r7;
switchD_080064b4_caseD_d4:
    param_1 = (byte *)FUN_08003d08(param_1,param_2,param_3);
switchD_080064b4_caseD_d6:
    param_3 = *(byte **)unaff_r7;
switchD_080064b4_caseD_d7:
    param_2 = param_3 + -(int)pbVar10;
switchD_080064b4_caseD_d8:
    param_2 = (byte *)(int)(short)param_2;
switchD_080064b4_caseD_d9:
    in_OV = SBORROW4((int)param_2,0x7d);
    bVar14 = (int)(param_2 + -0x7d) < 0;
    bVar15 = param_2 == (byte *)0x7d;
switchD_080064b4_caseD_da:
    if (!bVar15 && bVar14 == (bool)in_OV) {
switchD_080064b4_caseD_db:
      pbVar8 = (byte *)0xfa;
switchD_080064b4_caseD_dc:
      param_2 = pbVar8 + -(int)param_2;
switchD_080064b4_caseD_dd:
      param_2 = (byte *)(int)(short)param_2;
switchD_080064b4_caseD_de:
      pbVar10 = pbVar10 + 0xfa;
    }
switchD_080064b4_caseD_df:
    param_3 = param_3 + -(int)param_1;
switchD_080064b4_caseD_e0:
    pbVar8 = (byte *)0xff;
switchD_080064b4_caseD_e1:
    param_3 = (byte *)(int)(short)param_3;
switchD_080064b4_caseD_e2:
    pbVar8 = pbVar8 + 0x39;
switchD_080064b4_caseD_e3:
    in_OV = SBORROW4((int)param_3,(int)pbVar8);
    bVar14 = (int)param_3 - (int)pbVar8 < 0;
    bVar15 = param_3 == pbVar8;
switchD_080064b4_caseD_e4:
    if (!bVar15 && bVar14 == (bool)in_OV) {
switchD_080064b4_caseD_e5:
      pbVar8 = DAT_08006800;
switchD_080064b4_caseD_e6:
      param_3 = pbVar8 + -(int)param_3;
switchD_080064b4_caseD_e7:
      param_3 = (byte *)(int)(short)param_3;
switchD_080064b4_caseD_e8:
      param_1 = param_1 + (int)pbVar8;
    }
switchD_080064b4_caseD_e9:
    in_OV = SBORROW4((int)param_2,(int)param_3);
    bVar14 = (int)param_2 - (int)param_3 < 0;
    bVar15 = param_2 == param_3;
switchD_080064b4_caseD_ea:
    if (bVar15 || bVar14 != (bool)in_OV) {
switchD_080064b4_caseD_eb:
      param_1 = PTR_DAT_08006804;
switchD_080064b4_caseD_ec:
      param_2 = (byte *)0x0;
switchD_080064b4_caseD_ed:
      *(byte **)unaff_r7 = pbVar10;
switchD_080064b4_caseD_ee:
      *param_1 = (byte)param_2;
switchD_080064b4_caseD_ef:
    }
    else {
switchD_080064b4_caseD_f0:
      *(byte **)unaff_r7 = param_1;
switchD_080064b4_caseD_f1:
      param_1 = PTR_DAT_08006804;
switchD_080064b4_caseD_f2:
      *param_1 = (byte)pbVar13;
    }
switchD_080064b4_caseD_f3:
    in_CY = (byte *)0xc7 < unaff_r6;
switchD_080064b4_caseD_f4:
    if (in_CY == '\0') {
switchD_080064b4_caseD_f8:
      param_2 = PTR_DAT_080067e0;
switchD_080064b4_caseD_f9:
      param_1 = (byte *)0x1;
switchD_080064b4_caseD_fa:
      *param_2 = (byte)param_1;
switchD_080064b4_caseD_fb:
      param_2 = PTR_DAT_080067e8;
switchD_080064b4_caseD_fc:
      param_1 = (byte *)0x0;
switchD_080064b4_caseD_fd:
      *param_2 = (byte)param_1;
switchD_080064b4_caseD_fe:
      param_1 = PTR_DAT_08006808;
switchD_080064b4_caseD_ff:
      uVar12 = SUB41(pbVar13,0);
      *param_1 = (byte)unaff_r6;
      uVar3 = FUN_08004704(unaff_r6,0);
      *PTR_DAT_0800680c = uVar3;
    }
    else {
switchD_080064b4_caseD_f5:
      param_1 = PTR_DAT_080067e0;
switchD_080064b4_caseD_f6:
      *param_1 = (byte)pbVar13;
switchD_080064b4_caseD_f7:
      uVar12 = SUB41(pbVar13,0);
    }
    *PTR_DAT_080067d4 = uVar12;
    uVar3 = 0x1c;
LAB_08006790:
    *PTR_DAT_08006820 = uVar3;
    goto LAB_08006794;
  case 0xd0:
    goto switchD_080064b4_caseD_d0;
  case 0xd2:
    goto switchD_080064b4_caseD_d2;
  case 0xd3:
    goto switchD_080064b4_caseD_d3;
  case 0xd4:
    goto switchD_080064b4_caseD_d4;
  case 0xd5:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xd6:
    goto switchD_080064b4_caseD_d6;
  case 0xd7:
    goto switchD_080064b4_caseD_d7;
  case 0xd8:
    goto switchD_080064b4_caseD_d8;
  case 0xd9:
    goto switchD_080064b4_caseD_d9;
  case 0xda:
    goto switchD_080064b4_caseD_da;
  case 0xdb:
    goto switchD_080064b4_caseD_db;
  case 0xdc:
    goto switchD_080064b4_caseD_dc;
  case 0xdd:
    goto switchD_080064b4_caseD_dd;
  case 0xde:
    goto switchD_080064b4_caseD_de;
  case 0xdf:
    goto switchD_080064b4_caseD_df;
  case 0xe0:
    goto switchD_080064b4_caseD_e0;
  case 0xe1:
    goto switchD_080064b4_caseD_e1;
  case 0xe2:
    goto switchD_080064b4_caseD_e2;
  case 0xe3:
    goto switchD_080064b4_caseD_e3;
  case 0xe4:
    goto switchD_080064b4_caseD_e4;
  case 0xe5:
    goto switchD_080064b4_caseD_e5;
  case 0xe6:
    goto switchD_080064b4_caseD_e6;
  case 0xe7:
    goto switchD_080064b4_caseD_e7;
  case 0xe8:
    goto switchD_080064b4_caseD_e8;
  case 0xe9:
    goto switchD_080064b4_caseD_e9;
  case 0xea:
    goto switchD_080064b4_caseD_ea;
  case 0xeb:
    goto switchD_080064b4_caseD_eb;
  case 0xec:
    goto switchD_080064b4_caseD_ec;
  case 0xed:
    goto switchD_080064b4_caseD_ed;
  case 0xee:
    goto switchD_080064b4_caseD_ee;
  case 0xef:
    goto switchD_080064b4_caseD_ef;
  case 0xf0:
    goto switchD_080064b4_caseD_f0;
  case 0xf1:
    goto switchD_080064b4_caseD_f1;
  case 0xf2:
    goto switchD_080064b4_caseD_f2;
  case 0xf3:
    goto switchD_080064b4_caseD_f3;
  case 0xf4:
    goto switchD_080064b4_caseD_f4;
  case 0xf5:
    goto switchD_080064b4_caseD_f5;
  case 0xf6:
    goto switchD_080064b4_caseD_f6;
  case 0xf7:
    goto switchD_080064b4_caseD_f7;
  case 0xf8:
    goto switchD_080064b4_caseD_f8;
  case 0xf9:
    goto switchD_080064b4_caseD_f9;
  case 0xfa:
    goto switchD_080064b4_caseD_fa;
  case 0xfb:
    goto switchD_080064b4_caseD_fb;
  case 0xfc:
    goto switchD_080064b4_caseD_fc;
  case 0xfd:
    goto switchD_080064b4_caseD_fd;
  case 0xfe:
    goto switchD_080064b4_caseD_fe;
  case 0xff:
    goto switchD_080064b4_caseD_ff;
  }
  pbVar13 = param_3;
switchD_080064b4_caseD_24:
  param_1 = param_2;
switchD_080064b4_caseD_25:
  FUN_080068e0(param_1,pbVar13,pbVar10);
switchD_080064b4_caseD_27:
  return;
}



// ==== 08006524  caseD_36  (102 bytes, 2 xrefs)

void switchD_080064b4::caseD_36(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  byte bVar6;
  
  puVar2 = caseD_6c;
  if ((param_2 != 0) || (param_1 != 1)) {
    return;
  }
  *caseD_6a = 1;
  puVar5 = caseD_80;
  puVar4 = caseD_70;
  puVar3 = caseD_6e;
  cVar1 = *puVar2;
  if (cVar1 == '\0') {
    *caseD_6e = 0;
    caseD_74[0x1b] = *caseD_72;
    puVar2 = caseD_7a;
    *caseD_76 = 1;
    *caseD_78 = 1;
    *puVar2 = 2;
    *caseD_7c = 1;
    *puVar4 = 0xd;
    return;
  }
  if (cVar1 == '\x01') {
    if (*caseD_7e != '\0') {
      bVar6 = *caseD_7e - 1;
      *caseD_7e = bVar6;
      puVar5[bVar6] = 10;
      goto switchD_080064b4_caseD_67;
    }
  }
  else if (cVar1 != '\x02') {
    return;
  }
  *puVar2 = 0;
  *puVar4 = 0xd;
switchD_080064b4_caseD_67:
  *puVar3 = 3;
  return;
}



// ==== 080065bc  caseD_82  (526 bytes, 2 xrefs)

void switchD_080064b4::caseD_82(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined1 uVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  short sVar14;
  short sVar15;
  uint uVar16;
  bool bVar17;
  
  puVar4 = PTR_DAT_080067cc;
  bVar1 = *(byte *)(*(int *)PTR_DAT_080067cc + 0x1e);
  uVar16 = (uint)(byte)PTR_DAT_080067d0[9];
  if (param_2 != 0) {
    return;
  }
  if (param_1 != 1) {
    return;
  }
  cVar9 = *PTR_DAT_080067d4;
  cVar2 = *PTR_DAT_080067d8;
  bVar17 = cVar9 == '\0' && cVar2 == '\0';
  do {
    while( true ) {
      if (bVar17) goto LAB_080067a0;
      if (cVar9 == '\x01') break;
      bVar17 = cVar9 == '\x03';
      if (!bVar17) goto switchD_080064b4_caseD_9a;
    }
    bVar17 = true;
  } while (cVar2 == '\x01');
switchD_080064b4_caseD_9a:
  *PTR_DAT_080067dc = 1;
  puVar7 = PTR_DAT_080067ec;
  puVar6 = PTR_DAT_080067e4;
  puVar5 = PTR_DAT_080067e0;
  cVar9 = *PTR_DAT_080067e0;
  if (cVar9 == '\0') {
    if (cVar2 == '\0') {
      iVar11 = FUN_08003d08(*(undefined4 *)PTR_DAT_080067e4,0xfa,0,PTR_DAT_080067e4,param_4);
      iVar10 = FUN_08003d08(*(undefined4 *)puVar6,DAT_08006800,0);
      puVar4 = PTR_DAT_08006804;
      sVar14 = (short)*(undefined4 *)puVar6 - (short)iVar11;
      if (0x7d < sVar14) {
        sVar14 = 0xfa - sVar14;
        iVar11 = iVar11 + 0xfa;
      }
      sVar15 = (short)*(undefined4 *)puVar6 - (short)iVar10;
      if (0x138 < sVar15) {
        sVar15 = (short)DAT_08006800 - sVar15;
        iVar10 = iVar10 + DAT_08006800;
      }
      if (sVar15 < sVar14) {
        *(int *)puVar6 = iVar10;
        *PTR_DAT_08006804 = 2;
      }
      else {
        *(int *)puVar6 = iVar11;
        *puVar4 = 0;
      }
    }
    if (bVar1 < 200) {
      *PTR_DAT_080067e0 = 1;
      *PTR_DAT_080067e8 = 0;
      *PTR_DAT_08006808 = bVar1;
      uVar8 = FUN_08004704(bVar1,0);
      *PTR_DAT_0800680c = uVar8;
    }
    else {
      *PTR_DAT_080067e0 = 2;
    }
    *PTR_DAT_080067d4 = 2;
    uVar8 = 0x1c;
  }
  else {
    if (cVar9 != '\x02') {
      if (cVar9 != '\x01') {
        return;
      }
      cVar9 = *PTR_DAT_080067ec;
      if (*PTR_DAT_080067e8 == '\0') {
        if (cVar9 != '\0') {
LAB_080067a0:
          *PTR_DAT_080067dc = 2;
          return;
        }
        *PTR_DAT_080067e8 = 1;
        *PTR_DAT_08006828 = 10;
        FUN_08004920();
        *PTR_DAT_0800682c = 0x78;
        *PTR_DAT_08006830 = 0x78;
        *PTR_DAT_08006834 = 1;
      }
      else {
        *PTR_DAT_080067e8 = 0;
        puVar4 = PTR_DAT_080067f0;
        if (*PTR_DAT_080067f0 != -1) {
          *puVar7 = cVar9 + '\x01';
          *puVar4 = 0xff;
        }
        if (*puVar7 == '\0') {
          *PTR_DAT_080067fc = 0;
        }
        else {
          FUN_08002968(PTR_DAT_080067f8,PTR_DAT_080067f4);
          PTR_DAT_080067f8[(byte)*puVar7] = 0;
          *PTR_DAT_080067fc = 1;
        }
        *puVar5 = 2;
      }
      goto LAB_08006794;
    }
    if (cVar2 == '\0') {
      uVar12 = FUN_0800408c();
      FUN_0800a9a8(*(undefined4 *)puVar4,bVar1,uVar12,*(undefined4 *)PTR_DAT_080067e4);
      if (*PTR_DAT_08006818 == '\x01') {
        iVar11 = *(int *)puVar4;
        *(undefined *)(iVar11 + 4) = *PTR_DAT_08006810;
        *(undefined *)(iVar11 + 5) = *PTR_DAT_08006814;
      }
      puVar13 = *(undefined4 **)puVar4;
      puVar13[3] = puVar13[1];
      puVar13[2] = *puVar13;
      *(undefined *)((int)puVar13 + 0x26) = *PTR_DAT_08006804;
    }
    else {
      FUN_08009938(0,2);
      FUN_08009938(1,2);
      puVar5 = PTR_DAT_08006814;
      uVar8 = *PTR_DAT_08006810;
      iVar11 = *(int *)puVar4;
      *(undefined1 *)(iVar11 + 4) = uVar8;
      uVar3 = *puVar5;
      *(undefined1 *)(iVar11 + 5) = uVar3;
      *(undefined1 *)(iVar11 + 0xc) = uVar8;
      *(undefined1 *)(iVar11 + 0xd) = uVar3;
    }
    puVar5 = PTR_DAT_080067d0;
    if (bVar1 < 200) {
      uVar8 = *PTR_DAT_08006808;
      iVar11 = *(int *)puVar4;
      *(undefined1 *)(iVar11 + 0x1e) = uVar8;
      puVar5[uVar16 + 4] = uVar8;
      puVar5[uVar16] = uVar8;
      puVar4 = PTR_DAT_080067fc;
      if (*PTR_DAT_080067fc == '\0') {
        FUN_0800298c(iVar11 + 0x34,0x10,0xff);
      }
      else {
        FUN_08002968(iVar11 + 0x34,PTR_DAT_080067f8,0x10);
      }
      *puVar4 = 0;
    }
    else {
      cVar9 = *(char *)(*(int *)puVar4 + 0x2e) + -0x38;
      *(char *)(*(int *)puVar4 + 0x1e) = cVar9;
      puVar4 = PTR_DAT_080067d0;
      PTR_DAT_080067d0[uVar16 + 2] = cVar9;
      puVar4[uVar16] = cVar9;
    }
    puVar4 = PTR_DAT_080067e0;
    *PTR_DAT_0800681c = 2;
    *puVar4 = 0;
    uVar8 = 0x10;
  }
  *PTR_DAT_08006820 = uVar8;
LAB_08006794:
  *PTR_DAT_08006824 = 3;
  return;
}



// ==== 08006838  FUN_08006838  (108 bytes, 1 xrefs)

void FUN_08006838(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 uVar4;
  uint uVar5;
  
  puVar2 = PTR_DAT_080068a8;
  if ((param_3 == 0) && (param_2 == 1)) {
    if (*PTR_DAT_080068a4 == '\x01') {
      *PTR_DAT_080068a8 = 1;
      FUN_08005198(param_1);
      *PTR_DAT_080068ac = 3;
      puVar3 = PTR_DAT_080068b4;
      if ((byte)*PTR_DAT_080068b0 < 3) {
        *PTR_DAT_080068b4 = (char)param_1;
        return;
      }
      *PTR_DAT_080068b0 = 0;
      bVar1 = PTR_DAT_080068b8[1];
      uVar5 = ((uint)(byte)*PTR_DAT_080068b8 * 100 + (uint)bVar1 * 10 +
              (uint)(byte)PTR_DAT_080068b8[2]) - 1;
      if (uVar5 < 200) {
        *puVar3 = (char)param_1;
        uVar4 = FUN_08004704(uVar5 & 0xffff,0,0,(uint)bVar1 * 10,param_4);
        *PTR_DAT_080068bc = uVar4;
        *PTR_DAT_080068c0 = (char)uVar5;
        return;
      }
    }
    *puVar2 = 2;
  }
  return;
}



// ==== 080068c4  FUN_080068c4  (18 bytes, 1 xrefs)

void FUN_080068c4(int param_1,int param_2)

{
  if ((param_2 == 0) && (param_1 == 1)) {
    *PTR_DAT_080068d8 = 1;
    *PTR_DAT_080068dc = 1;
  }
  return;
}



// ==== 080068e0  FUN_080068e0  (78 bytes, 1 xrefs)

void FUN_080068e0(int param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  
  puVar1 = PTR_DAT_08006930;
  if (param_2 == 0) {
    if (param_1 != 1) {
      return;
    }
    *PTR_DAT_08006930 = 1;
    *PTR_DAT_08006938 = 0;
  }
  else if (param_1 != 1) {
    return;
  }
  puVar2 = PTR_DAT_0800693c;
  if (*PTR_DAT_08006934 == '\x01') {
    uVar4 = FUN_08004284(*PTR_DAT_0800693c,param_3,0,199);
    *puVar2 = (char)uVar4;
    uVar3 = FUN_08004704(uVar4,0);
    *PTR_DAT_08006940 = uVar3;
    *PTR_DAT_08006944 = 3;
    return;
  }
  *puVar1 = 2;
  return;
}



// ==== 08006948  FUN_08006948  (242 bytes, 1 xrefs)

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x08006950) */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x08006950) */
/* WARNING: Removing unreachable block (ram,0x08006b84) */
/* WARNING: Removing unreachable block (ram,0x08006b94) */

void FUN_08006948(byte *param_1,byte *param_2,byte *param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  char *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *unaff_r6;
  byte *unaff_r7;
  int unaff_r9;
  undefined1 *unaff_r10;
  char in_CY;
  bool bVar8;
  byte **ppbVar9;
  undefined1 *puVar10;
  longlong lVar11;
  undefined4 in_cr14;
  byte *pbStack_30;
  byte *pbStack_2c;
  byte *pbStack_28;
  byte *pbStack_24;
  byte *pbStack_20;
  
  pcVar4 = DAT_08006bcc;
  puVar1 = DAT_08006bc8;
  ppbVar9 = (byte **)((int)register0x00000054 + -0x10);
  bVar8 = param_1 == (byte *)0x0;
  pbVar3 = param_1;
  if ((byte *)(uint)switchD_08006950::caseD_0 <= param_1) {
    pbVar3 = (byte *)(uint)switchD_08006950::caseD_0;
  }
  pbVar6 = (byte *)((uint)pbVar3[0x8006955] * 2);
  pbVar5 = param_2;
  pbVar7 = param_3;
  switch(pbVar3[0x8006955]) {
  case 0:
  case 1:
switchD_08006950_caseD_2:
switchD_08006950_caseD_3:
switchD_08006950_caseD_4:
switchD_08006950_caseD_5:
switchD_08006950_caseD_6:
    param_3 = pbVar6 + 4;
switchD_08006950_caseD_7:
    param_3 = param_3 + 0x15;
switchD_08006950_caseD_8:
    param_3 = param_3 + 0x2f;
switchD_08006950_caseD_9:
    param_3 = param_3 + 0x32;
switchD_08006950_caseD_a:
    param_3 = param_3 + 0x32;
switchD_08006950_caseD_b:
    param_3 = param_3 + 0xc;
switchD_08006950_caseD_c:
    param_1 = param_2;
switchD_08006950_caseD_d:
    FUN_080071b4(param_1,param_2,param_3);
switchD_08006950_caseD_f:
    goto switchD_08006950_caseD_22;
  case 2:
    goto switchD_08006950_caseD_2;
  case 3:
    goto switchD_08006950_caseD_3;
  case 4:
    goto switchD_08006950_caseD_4;
  case 5:
    goto switchD_08006950_caseD_5;
  case 6:
    goto switchD_08006950_caseD_6;
  case 7:
    goto switchD_08006950_caseD_7;
  case 8:
    goto switchD_08006950_caseD_8;
  case 9:
    goto switchD_08006950_caseD_9;
  case 10:
    goto switchD_08006950_caseD_a;
  case 0xb:
    goto switchD_08006950_caseD_b;
  case 0xc:
    goto switchD_08006950_caseD_c;
  case 0xd:
    goto switchD_08006950_caseD_d;
  case 0xe:
    coprocessor_store(0,in_cr14,param_2);
  case 0x10:
    pbVar5 = param_3;
switchD_08006950_caseD_11:
    param_1 = param_2;
switchD_08006950_caseD_12:
    switchD_08006950::caseD_d4(param_1,pbVar5);
switchD_08006950_caseD_14:
    goto switchD_08006950_caseD_22;
  case 0xf:
    goto switchD_08006950_caseD_f;
  case 0x11:
    goto switchD_08006950_caseD_11;
  case 0x12:
    goto switchD_08006950_caseD_12;
  case 0x13:
    param_1[0xc] = 0x55;
    param_1[0xd] = 0x69;
    param_1[0xe] = 0;
    param_1[0xf] = 8;
  case 0x15:
    pbVar5 = param_3;
switchD_08006950_caseD_16:
    param_1 = param_2;
switchD_08006950_caseD_17:
    switchD_08006950::caseD_42(param_1,pbVar5);
switchD_08006950_caseD_19:
    goto switchD_08006950_caseD_22;
  case 0x14:
    goto switchD_08006950_caseD_14;
  case 0x16:
    goto switchD_08006950_caseD_16;
  case 0x17:
    goto switchD_08006950_caseD_17;
  case 0x18:
    (unaff_r7 + unaff_r9)[0] = 0x55;
    (unaff_r7 + unaff_r9)[1] = 0x69;
  case 0x1a:
    pbVar7 = (byte *)0x0;
switchD_08006950_caseD_1b:
    pbVar7 = (byte *)~(uint)pbVar7;
switchD_08006950_caseD_1c:
    break;
  case 0x19:
    goto switchD_08006950_caseD_19;
  case 0x1b:
    goto switchD_08006950_caseD_1b;
  case 0x1c:
    goto switchD_08006950_caseD_1c;
  case 0x1d:
    pbVar7 = (byte *)0x1;
    break;
  case 0x1f:
    goto switchD_08006950_caseD_1f;
  case 0x20:
    goto switchD_08006950_caseD_20;
  case 0x21:
    puVar1 = (undefined1 *)0x320;
    puVar2 = (undefined1 *)0x328;
    lVar11 = 8;
    while( true ) {
      *puVar1 = *unaff_r10;
      puVar10 = unaff_r10 + 1;
      *puVar2 = *puVar10;
      unaff_r10 = puVar10 + 1;
      lVar11 = lVar11 + -1;
      if (lVar11 == 0) break;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    goto switchD_08006950_caseD_23;
  case 0x22:
    goto switchD_08006950_caseD_22;
  case 0x23:
    goto switchD_08006950_caseD_23;
  case 0x24:
    goto switchD_08006950_caseD_24;
  case 0x25:
    goto switchD_08006950_caseD_25;
  case 0x26:
    goto switchD_08006950_caseD_26;
  case 0x27:
    goto switchD_08006950_caseD_27;
  case 0x28:
    goto switchD_08006950_caseD_28;
  case 0x29:
    goto switchD_08006950_caseD_29;
  case 0x2a:
    goto switchD_08006950_caseD_2a;
  case 0x2b:
    goto switchD_08006950_caseD_2b;
  case 0x2c:
    FUN_08006b68();
  case 0x2e:
    goto switchD_08006950_caseD_22;
  case 0x2d:
  case 0x2f:
    FUN_08006c74();
switchD_08006950_caseD_31:
    goto switchD_08006950_caseD_22;
  case 0x30:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x31:
    goto switchD_08006950_caseD_31;
  case 0x32:
    bVar8 = param_3 == (byte *)0x0;
  case 0x33:
    if (bVar8) {
switchD_08006950_caseD_34:
      bVar8 = param_2 == (byte *)0x1;
switchD_08006950_caseD_35:
      if (bVar8) {
switchD_08006950_caseD_36:
        param_2 = &DAT_20000092;
switchD_08006950_caseD_37:
        param_1 = (byte *)0x1;
switchD_08006950_caseD_38:
        *param_2 = (byte)param_1;
switchD_08006950_caseD_39:
      }
    }
    goto switchD_08006950_caseD_22;
  case 0x34:
    goto switchD_08006950_caseD_34;
  case 0x35:
    goto switchD_08006950_caseD_35;
  case 0x36:
    goto switchD_08006950_caseD_36;
  case 0x37:
    goto switchD_08006950_caseD_37;
  case 0x38:
    goto switchD_08006950_caseD_38;
  case 0x39:
    goto switchD_08006950_caseD_39;
  case 0x3a:
    pbVar5 = (byte *)((int)unaff_r6 << 1);
  case 0x3b:
switchD_08006950_caseD_3c:
switchD_08006950_caseD_3d:
switchD_08006950_caseD_3e:
switchD_08006950_caseD_3f:
switchD_08006950_caseD_40:
    pbVar7 = (byte *)((int)param_3 << 2);
switchD_08006950_caseD_41:
    param_1 = (byte *)0x0;
code_r0x080069d8:
    ppbVar9 = &pbStack_30;
    pbStack_30 = pbVar5;
    pbStack_2c = pbVar7;
    pbStack_28 = pbVar6;
    pbStack_24 = param_3;
    pbStack_20 = param_2;
code_r0x080069da:
    bVar8 = pbVar5 == (byte *)0x0;
code_r0x080069dc:
    if (!bVar8) {
      return;
    }
code_r0x080069de:
    bVar8 = param_1 == (byte *)0x1;
switchD_08006950_caseD_46:
    if (!bVar8) {
      return;
    }
switchD_08006950_caseD_47:
    param_1 = &DAT_20000092;
switchD_08006950_caseD_48:
    param_2 = (byte *)0x1;
switchD_08006950_caseD_49:
    *param_1 = (byte)param_2;
switchD_08006950_caseD_4a:
    param_1 = &DAT_20002650;
switchD_08006950_caseD_4b:
    unaff_r7 = &DAT_2000017f;
    pbVar5 = param_2;
switchD_08006950_caseD_4c:
    param_2 = (byte *)(uint)param_1[0x16];
switchD_08006950_caseD_4d:
    param_1 = (byte *)&DAT_20000178;
switchD_08006950_caseD_4e:
    param_3 = (byte *)0x0;
switchD_08006950_caseD_4f:
    bVar8 = param_2 == (byte *)0x1;
switchD_08006950_caseD_50:
    pbVar7 = param_3;
    if (bVar8) {
switchD_08006950_caseD_51:
      param_2 = (byte *)(uint)*unaff_r7;
switchD_08006950_caseD_52:
      bVar8 = param_2 == (byte *)0x0;
switchD_08006950_caseD_53:
      pbVar7 = param_3;
      if (bVar8) goto switchD_08006950_caseD_83;
switchD_08006950_caseD_54:
      bVar8 = param_2 == (byte *)0x1;
switchD_08006950_caseD_55:
      if (!bVar8) {
switchD_08006950_caseD_56:
        unaff_r6 = param_1;
switchD_08006950_caseD_57:
        param_2 = (byte *)0xa;
switchD_08006950_caseD_58:
        param_1 = *(byte **)param_1;
switchD_08006950_caseD_59:
        param_1 = (byte *)FUN_080028f0(param_1,param_2);
        pbVar7 = param_3;
switchD_08006950_caseD_5b:
        param_3 = (byte *)((int)ppbVar9 + 8);
switchD_08006950_caseD_5c:
        param_2 = (byte *)((int)ppbVar9 + 4);
switchD_08006950_caseD_5d:
        *ppbVar9 = param_1;
switchD_08006950_caseD_5e:
        param_1 = (byte *)FUN_080090bc(param_1,param_2,param_3);
switchD_08006950_caseD_60:
        bVar8 = param_1 == (byte *)0x1;
        param_3 = pbVar7;
        param_2 = pbVar5;
        goto switchD_08006950_caseD_61;
      }
switchD_08006950_caseD_6a:
      *(byte **)param_1 = param_3;
switchD_08006950_caseD_6b:
      param_1 = &DAT_200000c9;
switchD_08006950_caseD_6c:
      *unaff_r7 = (byte)param_3;
switchD_08006950_caseD_6d:
      *param_1 = (byte)param_3;
switchD_08006950_caseD_6e:
    }
    else {
switchD_08006950_caseD_83:
      param_3 = &DAT_200000e8;
switchD_08006950_caseD_84:
      unaff_r6 = &DAT_200000e6;
switchD_08006950_caseD_85:
      param_2 = (byte *)(uint)*param_3;
switchD_08006950_caseD_86:
      bVar8 = param_2 == (byte *)0x0;
switchD_08006950_caseD_87:
      if (!bVar8) {
switchD_08006950_caseD_88:
        param_2 = (byte *)(uint)*unaff_r6;
switchD_08006950_caseD_89:
        param_2 = param_2 + 1;
switchD_08006950_caseD_8a:
        *unaff_r6 = (byte)param_2;
switchD_08006950_caseD_8b:
        *param_3 = (byte)pbVar7;
      }
switchD_08006950_caseD_8c:
      param_2 = (byte *)(uint)*unaff_r6;
switchD_08006950_caseD_8d:
      bVar8 = param_2 == (byte *)0x0;
switchD_08006950_caseD_8e:
      if (bVar8) {
switchD_08006950_caseD_a7:
        param_2 = &DAT_20000071;
switchD_08006950_caseD_a8:
        *param_2 = (byte)pbVar7;
switchD_08006950_caseD_a9:
        *(byte **)param_1 = pbVar7;
switchD_08006950_caseD_aa:
        param_1 = &DAT_200000c9;
switchD_08006950_caseD_ab:
        *unaff_r7 = (byte)pbVar7;
switchD_08006950_caseD_ac:
        *param_1 = (byte)pbVar7;
switchD_08006950_caseD_ad:
        param_1 = &DAT_2000006c;
switchD_08006950_caseD_ae:
        *param_1 = (byte)pbVar5;
      }
      else {
switchD_08006950_caseD_8f:
        param_2 = param_2 + -1;
switchD_08006950_caseD_90:
        param_1 = (byte *)((uint)param_2 & 0xff);
switchD_08006950_caseD_91:
        pbVar6 = &DAT_20002812;
switchD_08006950_caseD_92:
        *unaff_r6 = (byte)param_1;
switchD_08006950_caseD_93:
        unaff_r7 = (byte *)(uint)pbVar6[(int)param_1];
switchD_08006950_caseD_94:
        param_2 = (byte *)0xff;
switchD_08006950_caseD_95:
        in_CY = (byte *)0x7f < unaff_r7;
switchD_08006950_caseD_96:
        if (in_CY == '\0') {
switchD_08006950_caseD_97:
          pbVar6[(int)param_1] = (byte)param_2;
switchD_08006950_caseD_98:
        }
        else {
switchD_08006950_caseD_99:
          bVar8 = param_1 == (byte *)0x0;
switchD_08006950_caseD_9a:
          if (!bVar8) {
switchD_08006950_caseD_9b:
            pbVar6[(int)param_1] = (byte)param_2;
switchD_08006950_caseD_9c:
            param_1 = param_1 + -1;
switchD_08006950_caseD_9d:
            param_1 = (byte *)((uint)param_1 & 0xff);
switchD_08006950_caseD_9e:
            *unaff_r6 = (byte)param_1;
switchD_08006950_caseD_9f:
            goto switchD_08006950_caseD_97;
          }
switchD_08006950_caseD_a0:
          *pbVar6 = (byte)param_2;
        }
switchD_08006950_caseD_a1:
        param_1 = &DAT_200000e7;
switchD_08006950_caseD_a2:
        *param_1 = (byte)pbVar7;
switchD_08006950_caseD_a3:
        param_1 = &DAT_200000e9;
switchD_08006950_caseD_a4:
        *param_3 = (byte)pbVar7;
switchD_08006950_caseD_a5:
        *param_1 = (byte)param_2;
switchD_08006950_caseD_a6:
      }
    }
    goto switchD_08006950_caseD_af;
  case 0x3c:
    goto switchD_08006950_caseD_3c;
  case 0x3d:
    goto switchD_08006950_caseD_3d;
  case 0x3e:
    goto switchD_08006950_caseD_3e;
  case 0x3f:
    goto switchD_08006950_caseD_3f;
  case 0x40:
    goto switchD_08006950_caseD_40;
  case 0x41:
    goto switchD_08006950_caseD_41;
  case 0x42:
    goto code_r0x080069d8;
  case 0x43:
    goto code_r0x080069da;
  case 0x44:
    goto code_r0x080069dc;
  case 0x45:
    goto code_r0x080069de;
  case 0x46:
    goto switchD_08006950_caseD_46;
  case 0x47:
    goto switchD_08006950_caseD_47;
  case 0x48:
    goto switchD_08006950_caseD_48;
  case 0x49:
    goto switchD_08006950_caseD_49;
  case 0x4a:
    goto switchD_08006950_caseD_4a;
  case 0x4b:
    goto switchD_08006950_caseD_4b;
  case 0x4c:
    goto switchD_08006950_caseD_4c;
  case 0x4d:
    goto switchD_08006950_caseD_4d;
  case 0x4e:
    goto switchD_08006950_caseD_4e;
  case 0x4f:
    goto switchD_08006950_caseD_4f;
  case 0x50:
    goto switchD_08006950_caseD_50;
  case 0x51:
    goto switchD_08006950_caseD_51;
  case 0x52:
    goto switchD_08006950_caseD_52;
  case 0x53:
    goto switchD_08006950_caseD_53;
  case 0x54:
    goto switchD_08006950_caseD_54;
  case 0x55:
    goto switchD_08006950_caseD_55;
  case 0x56:
    goto switchD_08006950_caseD_56;
  case 0x57:
    goto switchD_08006950_caseD_57;
  case 0x58:
    goto switchD_08006950_caseD_58;
  case 0x59:
    goto switchD_08006950_caseD_59;
  case 0x5a:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x5b:
    goto switchD_08006950_caseD_5b;
  case 0x5c:
    goto switchD_08006950_caseD_5c;
  case 0x5d:
    goto switchD_08006950_caseD_5d;
  case 0x5e:
    goto switchD_08006950_caseD_5e;
  case 0x5f:
  case 0x61:
switchD_08006950_caseD_61:
    if (!bVar8) {
switchD_08006950_caseD_62:
      param_1 = &DAT_20000092;
switchD_08006950_caseD_63:
      param_2 = (byte *)0x2;
switchD_08006950_caseD_64:
      *param_1 = (byte)param_2;
switchD_08006950_caseD_65:
      *(byte **)unaff_r6 = param_3;
switchD_08006950_caseD_66:
      param_1 = &DAT_200000c9;
switchD_08006950_caseD_67:
      *unaff_r7 = (byte)param_3;
switchD_08006950_caseD_68:
      *param_1 = (byte)param_3;
switchD_08006950_caseD_69:
      return;
    }
switchD_08006950_caseD_6f:
    param_1 = (byte *)ppbVar9;
    pbVar5 = param_2;
    ppbVar9 = (byte **)param_1;
switchD_08006950_caseD_70:
    param_2 = (byte *)&DAT_2000017c;
switchD_08006950_caseD_71:
    param_1 = (byte *)(uint)*(ushort *)(param_1 + 4);
switchD_08006950_caseD_72:
    *(short *)param_2 = (short)param_1;
switchD_08006950_caseD_73:
    param_1 = (byte *)ppbVar9;
    ppbVar9 = (byte **)param_1;
switchD_08006950_caseD_74:
    param_2 = (byte *)(uint)param_1[8];
switchD_08006950_caseD_75:
    param_1 = &DAT_2000017e;
switchD_08006950_caseD_76:
    *param_1 = (byte)param_2;
switchD_08006950_caseD_77:
    param_1 = &DAT_20000180;
switchD_08006950_caseD_78:
    *param_1 = (byte)param_3;
switchD_08006950_caseD_79:
    param_1 = &DAT_20000181;
switchD_08006950_caseD_7a:
    *param_1 = (byte)param_3;
switchD_08006950_caseD_7b:
    FUN_08009168();
switchD_08006950_caseD_7d:
    param_1 = *ppbVar9;
    param_2 = pbVar5;
  case 0x7e:
switchD_08006950_caseD_7e:
    *(byte **)unaff_r6 = param_1;
switchD_08006950_caseD_7f:
    param_1 = (byte *)(uint)*unaff_r7;
switchD_08006950_caseD_80:
    param_1 = param_1 + -1;
switchD_08006950_caseD_81:
    *unaff_r7 = (byte)param_1;
    pbVar5 = param_2;
switchD_08006950_caseD_82:
switchD_08006950_caseD_af:
    param_1 = &DAT_2000006d;
switchD_08006950_caseD_b0:
    *param_1 = (byte)pbVar5;
switchD_08006950_caseD_b1:
    return;
  case 0x60:
    goto switchD_08006950_caseD_60;
  case 0x62:
    goto switchD_08006950_caseD_62;
  case 99:
    goto switchD_08006950_caseD_63;
  case 100:
    goto switchD_08006950_caseD_64;
  case 0x65:
    goto switchD_08006950_caseD_65;
  case 0x66:
    goto switchD_08006950_caseD_66;
  case 0x67:
    goto switchD_08006950_caseD_67;
  case 0x68:
    goto switchD_08006950_caseD_68;
  case 0x69:
    goto switchD_08006950_caseD_69;
  case 0x6a:
    goto switchD_08006950_caseD_6a;
  case 0x6b:
    goto switchD_08006950_caseD_6b;
  case 0x6c:
    goto switchD_08006950_caseD_6c;
  case 0x6d:
    goto switchD_08006950_caseD_6d;
  case 0x6e:
    goto switchD_08006950_caseD_6e;
  case 0x6f:
    goto switchD_08006950_caseD_6f;
  case 0x70:
    goto switchD_08006950_caseD_70;
  case 0x71:
    goto switchD_08006950_caseD_71;
  case 0x72:
    goto switchD_08006950_caseD_72;
  case 0x73:
    goto switchD_08006950_caseD_73;
  case 0x74:
    goto switchD_08006950_caseD_74;
  case 0x75:
    goto switchD_08006950_caseD_75;
  case 0x76:
    goto switchD_08006950_caseD_76;
  case 0x77:
    goto switchD_08006950_caseD_77;
  case 0x78:
    goto switchD_08006950_caseD_78;
  case 0x79:
    goto switchD_08006950_caseD_79;
  case 0x7a:
    goto switchD_08006950_caseD_7a;
  case 0x7b:
    goto switchD_08006950_caseD_7b;
  case 0x7c:
    goto switchD_08006950_caseD_7e;
  case 0x7d:
    goto switchD_08006950_caseD_7d;
  case 0x7f:
    goto switchD_08006950_caseD_7f;
  case 0x80:
    goto switchD_08006950_caseD_80;
  case 0x81:
    goto switchD_08006950_caseD_81;
  case 0x82:
    goto switchD_08006950_caseD_82;
  case 0x83:
    goto switchD_08006950_caseD_83;
  case 0x84:
    goto switchD_08006950_caseD_84;
  case 0x85:
    goto switchD_08006950_caseD_85;
  case 0x86:
    goto switchD_08006950_caseD_86;
  case 0x87:
    goto switchD_08006950_caseD_87;
  case 0x88:
    goto switchD_08006950_caseD_88;
  case 0x89:
    goto switchD_08006950_caseD_89;
  case 0x8a:
    goto switchD_08006950_caseD_8a;
  case 0x8b:
    goto switchD_08006950_caseD_8b;
  case 0x8c:
    goto switchD_08006950_caseD_8c;
  case 0x8d:
    goto switchD_08006950_caseD_8d;
  case 0x8e:
    goto switchD_08006950_caseD_8e;
  case 0x8f:
    goto switchD_08006950_caseD_8f;
  case 0x90:
    goto switchD_08006950_caseD_90;
  case 0x91:
    goto switchD_08006950_caseD_91;
  case 0x92:
    goto switchD_08006950_caseD_92;
  case 0x93:
    goto switchD_08006950_caseD_93;
  case 0x94:
    goto switchD_08006950_caseD_94;
  case 0x95:
    goto switchD_08006950_caseD_95;
  case 0x96:
    goto switchD_08006950_caseD_96;
  case 0x97:
    goto switchD_08006950_caseD_97;
  case 0x98:
    goto switchD_08006950_caseD_98;
  case 0x99:
    goto switchD_08006950_caseD_99;
  case 0x9a:
    goto switchD_08006950_caseD_9a;
  case 0x9b:
    goto switchD_08006950_caseD_9b;
  case 0x9c:
    goto switchD_08006950_caseD_9c;
  case 0x9d:
    goto switchD_08006950_caseD_9d;
  case 0x9e:
    goto switchD_08006950_caseD_9e;
  case 0x9f:
    goto switchD_08006950_caseD_9f;
  case 0xa0:
    goto switchD_08006950_caseD_a0;
  case 0xa1:
    goto switchD_08006950_caseD_a1;
  case 0xa2:
    goto switchD_08006950_caseD_a2;
  case 0xa3:
    goto switchD_08006950_caseD_a3;
  case 0xa4:
    goto switchD_08006950_caseD_a4;
  case 0xa5:
    goto switchD_08006950_caseD_a5;
  case 0xa6:
    goto switchD_08006950_caseD_a6;
  case 0xa7:
    goto switchD_08006950_caseD_a7;
  case 0xa8:
    goto switchD_08006950_caseD_a8;
  case 0xa9:
    goto switchD_08006950_caseD_a9;
  case 0xaa:
    goto switchD_08006950_caseD_aa;
  case 0xab:
    goto switchD_08006950_caseD_ab;
  case 0xac:
    goto switchD_08006950_caseD_ac;
  case 0xad:
    goto switchD_08006950_caseD_ad;
  case 0xae:
    goto switchD_08006950_caseD_ae;
  case 0xaf:
    goto switchD_08006950_caseD_af;
  case 0xb0:
    goto switchD_08006950_caseD_b0;
  case 0xb1:
    goto switchD_08006950_caseD_b1;
  case 0xb2:
  case 0xb3:
switchD_08006950_caseD_b4:
switchD_08006950_caseD_b5:
switchD_08006950_caseD_b6:
    unaff_r7 = (byte *)((int)unaff_r7 << 5);
switchD_08006950_caseD_b7:
switchD_08006950_caseD_b8:
switchD_08006950_caseD_b9:
switchD_08006950_caseD_ba:
switchD_08006950_caseD_bb:
switchD_08006950_caseD_bc:
    param_3 = (byte *)((int)unaff_r7 << 5);
switchD_08006950_caseD_bd:
switchD_08006950_caseD_be:
switchD_08006950_caseD_bf:
switchD_08006950_caseD_c0:
switchD_08006950_caseD_c1:
switchD_08006950_caseD_c2:
switchD_08006950_caseD_c3:
switchD_08006950_caseD_c4:
switchD_08006950_caseD_c5:
switchD_08006950_caseD_c6:
    unaff_r6 = (byte *)((int)param_3 << 3);
switchD_08006950_caseD_c7:
switchD_08006950_caseD_c8:
switchD_08006950_caseD_c9:
switchD_08006950_caseD_ca:
switchD_08006950_caseD_cb:
switchD_08006950_caseD_cc:
switchD_08006950_caseD_cd:
switchD_08006950_caseD_ce:
    param_2 = (byte *)((int)unaff_r6 << 1);
switchD_08006950_caseD_cf:
switchD_08006950_caseD_d0:
switchD_08006950_caseD_d1:
switchD_08006950_caseD_d2:
switchD_08006950_caseD_d3:
    param_1 = (byte *)0x0;
code_r0x08006afc:
code_r0x08006afe:
    bVar8 = param_2 == (byte *)0x0;
code_r0x08006b00:
    if (!bVar8) {
      return;
    }
code_r0x08006b02:
    bVar8 = param_1 == (byte *)0x1;
switchD_08006950_caseD_d8:
    if (!bVar8) {
      return;
    }
switchD_08006950_caseD_d9:
    param_1 = &DAT_20000092;
switchD_08006950_caseD_da:
    param_3 = (byte *)0x1;
switchD_08006950_caseD_db:
    *param_1 = (byte)param_3;
switchD_08006950_caseD_dc:
    param_1 = &DAT_20002650;
switchD_08006950_caseD_dd:
    pbVar6 = &DAT_2000017f;
switchD_08006950_caseD_de:
    param_1 = (byte *)(uint)param_1[0x16];
switchD_08006950_caseD_df:
    param_2 = &DAT_200000c9;
switchD_08006950_caseD_e0:
    bVar8 = param_1 == (byte *)0x1;
switchD_08006950_caseD_e1:
    if (bVar8) {
switchD_08006950_caseD_e2:
      param_1 = (byte *)(uint)*pbVar6;
switchD_08006950_caseD_e3:
      bVar8 = param_1 == (byte *)0x0;
switchD_08006950_caseD_e4:
      if (bVar8) goto switchD_08006950_caseD_f1;
switchD_08006950_caseD_e5:
      param_1 = (byte *)(uint)*param_2;
switchD_08006950_caseD_e6:
      bVar8 = param_1 == (byte *)0x0;
switchD_08006950_caseD_e7:
      if (bVar8) {
switchD_08006950_caseD_ef:
        param_1 = (byte *)0x1;
switchD_08006950_caseD_f0:
      }
      else {
switchD_08006950_caseD_e8:
        param_1 = (byte *)0x0;
      }
    }
    else {
switchD_08006950_caseD_f1:
      pbVar7 = &DAT_20000071;
switchD_08006950_caseD_f2:
      param_1 = (byte *)0x2;
switchD_08006950_caseD_f3:
      *pbVar7 = (byte)param_1;
switchD_08006950_caseD_f4:
      pbVar7 = (byte *)&DAT_20000178;
switchD_08006950_caseD_f5:
      param_1 = (byte *)0x0;
switchD_08006950_caseD_f6:
      *(byte **)pbVar7 = param_1;
switchD_08006950_caseD_f7:
      *pbVar6 = (byte)param_1;
switchD_08006950_caseD_f8:
    }
switchD_08006950_caseD_e9:
    *param_2 = (byte)param_1;
switchD_08006950_caseD_ea:
    param_1 = &DAT_2000006c;
switchD_08006950_caseD_eb:
    *param_1 = (byte)param_3;
switchD_08006950_caseD_ec:
    param_1 = &DAT_2000006d;
switchD_08006950_caseD_ed:
    *param_1 = (byte)param_3;
switchD_08006950_caseD_ee:
    return;
  case 0xb4:
    goto switchD_08006950_caseD_b4;
  case 0xb5:
    goto switchD_08006950_caseD_b5;
  case 0xb6:
    goto switchD_08006950_caseD_b6;
  case 0xb7:
    goto switchD_08006950_caseD_b7;
  case 0xb8:
    goto switchD_08006950_caseD_b8;
  case 0xb9:
    goto switchD_08006950_caseD_b9;
  case 0xba:
    goto switchD_08006950_caseD_ba;
  case 0xbb:
    goto switchD_08006950_caseD_bb;
  case 0xbc:
    goto switchD_08006950_caseD_bc;
  case 0xbd:
    goto switchD_08006950_caseD_bd;
  case 0xbe:
    goto switchD_08006950_caseD_be;
  case 0xbf:
    goto switchD_08006950_caseD_bf;
  case 0xc0:
    goto switchD_08006950_caseD_c0;
  case 0xc1:
    goto switchD_08006950_caseD_c1;
  case 0xc2:
    goto switchD_08006950_caseD_c2;
  case 0xc3:
    goto switchD_08006950_caseD_c3;
  case 0xc4:
    goto switchD_08006950_caseD_c4;
  case 0xc5:
    goto switchD_08006950_caseD_c5;
  case 0xc6:
    goto switchD_08006950_caseD_c6;
  case 199:
    goto switchD_08006950_caseD_c7;
  case 200:
    goto switchD_08006950_caseD_c8;
  case 0xc9:
    goto switchD_08006950_caseD_c9;
  case 0xca:
    goto switchD_08006950_caseD_ca;
  case 0xcb:
    goto switchD_08006950_caseD_cb;
  case 0xcc:
    goto switchD_08006950_caseD_cc;
  case 0xcd:
    goto switchD_08006950_caseD_cd;
  case 0xce:
    goto switchD_08006950_caseD_ce;
  case 0xcf:
    goto switchD_08006950_caseD_cf;
  case 0xd0:
    goto switchD_08006950_caseD_d0;
  case 0xd1:
    goto switchD_08006950_caseD_d1;
  case 0xd2:
    goto switchD_08006950_caseD_d2;
  case 0xd3:
    goto switchD_08006950_caseD_d3;
  case 0xd4:
    goto code_r0x08006afc;
  case 0xd5:
    goto code_r0x08006afe;
  case 0xd6:
    goto code_r0x08006b00;
  case 0xd7:
    goto code_r0x08006b02;
  case 0xd8:
    goto switchD_08006950_caseD_d8;
  case 0xd9:
    goto switchD_08006950_caseD_d9;
  case 0xda:
    goto switchD_08006950_caseD_da;
  case 0xdb:
    goto switchD_08006950_caseD_db;
  case 0xdc:
    goto switchD_08006950_caseD_dc;
  case 0xdd:
    goto switchD_08006950_caseD_dd;
  case 0xde:
    goto switchD_08006950_caseD_de;
  case 0xdf:
    goto switchD_08006950_caseD_df;
  case 0xe0:
    goto switchD_08006950_caseD_e0;
  case 0xe1:
    goto switchD_08006950_caseD_e1;
  case 0xe2:
    goto switchD_08006950_caseD_e2;
  case 0xe3:
    goto switchD_08006950_caseD_e3;
  case 0xe4:
    goto switchD_08006950_caseD_e4;
  case 0xe5:
    goto switchD_08006950_caseD_e5;
  case 0xe6:
    goto switchD_08006950_caseD_e6;
  case 0xe7:
    goto switchD_08006950_caseD_e7;
  case 0xe8:
    goto switchD_08006950_caseD_e8;
  case 0xe9:
    goto switchD_08006950_caseD_e9;
  case 0xea:
    goto switchD_08006950_caseD_ea;
  case 0xeb:
    goto switchD_08006950_caseD_eb;
  case 0xec:
    goto switchD_08006950_caseD_ec;
  case 0xed:
    goto switchD_08006950_caseD_ed;
  case 0xee:
    goto switchD_08006950_caseD_ee;
  case 0xef:
    goto switchD_08006950_caseD_ef;
  case 0xf0:
    goto switchD_08006950_caseD_f0;
  case 0xf1:
    goto switchD_08006950_caseD_f1;
  case 0xf2:
    goto switchD_08006950_caseD_f2;
  case 0xf3:
    goto switchD_08006950_caseD_f3;
  case 0xf4:
    goto switchD_08006950_caseD_f4;
  case 0xf5:
    goto switchD_08006950_caseD_f5;
  case 0xf6:
    goto switchD_08006950_caseD_f6;
  case 0xf7:
    goto switchD_08006950_caseD_f7;
  case 0xf8:
    goto switchD_08006950_caseD_f8;
  case 0xf9:
  case 0xfa:
    param_3 = (byte *)((int)param_3 << 2);
switchD_08006950_caseD_fb:
switchD_08006950_caseD_fc:
    unaff_r6 = (byte *)0x50;
switchD_08006950_caseD_fd:
switchD_08006950_caseD_fe:
switchD_08006950_caseD_ff:
    pbStack_20 = (byte *)((int)param_2 << 1);
    if ((param_3 == (byte *)0x0) && ((int)unaff_r6 * 2 == 1)) {
      *DAT_08006bc8 = 1;
      if (*pcVar4 == '\0') {
        FUN_08004fbc();
      }
      else {
        *puVar1 = 2;
      }
      *DAT_08006be8 = 1;
    }
    return;
  case 0xfb:
    goto switchD_08006950_caseD_fb;
  case 0xfc:
    goto switchD_08006950_caseD_fc;
  case 0xfd:
    goto switchD_08006950_caseD_fd;
  case 0xfe:
    goto switchD_08006950_caseD_fe;
  case 0xff:
    goto switchD_08006950_caseD_ff;
  }
  pbVar5 = param_3;
switchD_08006950_caseD_1f:
  param_1 = param_2;
switchD_08006950_caseD_20:
  FUN_08006bec(param_1,pbVar5,pbVar7);
switchD_08006950_caseD_22:
  param_1 = &DAT_20000071;
switchD_08006950_caseD_23:
  param_1 = (byte *)(uint)*param_1;
switchD_08006950_caseD_24:
  bVar8 = param_1 == (byte *)0x1;
switchD_08006950_caseD_25:
  if (bVar8) {
switchD_08006950_caseD_26:
    param_2 = &DAT_2000008f;
switchD_08006950_caseD_27:
    param_1 = (byte *)0x78;
switchD_08006950_caseD_28:
    *param_2 = (byte)param_1;
switchD_08006950_caseD_29:
    param_2 = &DAT_20000067;
switchD_08006950_caseD_2a:
    *param_2 = (byte)param_1;
  }
switchD_08006950_caseD_2b:
  return;
}



// ==== 080069d8  caseD_42  (224 bytes, 2 xrefs)

void switchD_08006950::caseD_42(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_1c;
  undefined4 local_18;
  
  if ((param_2 != 0) || (param_1 != 1)) {
    return;
  }
  DAT_20000092 = 1;
  if ((DAT_20002666 == '\x01') && (DAT_2000017f != '\0')) {
    if (DAT_2000017f == '\x01') {
      DAT_2000006d = 1;
      DAT_20000092 = 1;
      DAT_200000c9 = 0;
      DAT_20000178 = 0;
      DAT_2000017f = 0;
      return;
    }
    local_1c = param_3;
    local_18 = param_4;
    uVar1 = FUN_080028f0(DAT_20000178,10,param_3,param_4,0);
    iVar2 = FUN_080090bc(uVar1,&local_1c,&local_18);
    if (iVar2 == 1) {
      DAT_2000017c = (undefined2)local_1c;
      DAT_2000017e = (undefined1)local_18;
      DAT_20000180 = 0;
      DAT_20000181 = 0;
      FUN_08009168();
      DAT_2000006d = 1;
      DAT_20000178 = uVar1;
      DAT_2000017f = DAT_2000017f + -1;
      return;
    }
    DAT_20000092 = 2;
    DAT_200000c9 = 0;
    DAT_20000178 = 0;
    DAT_2000017f = 0;
    return;
  }
  if (DAT_200000e8 != '\0') {
    DAT_200000e6 = DAT_200000e6 + '\x01';
    DAT_200000e8 = '\0';
  }
  if (DAT_200000e6 == '\0') {
    DAT_2000006c = 1;
    DAT_2000006d = 1;
    DAT_20000071 = 0;
    DAT_20000092 = 1;
    DAT_200000c9 = 0;
    DAT_20000178 = 0;
    DAT_2000017f = 0;
    return;
  }
  DAT_200000e6 = DAT_200000e6 - 1;
  uVar3 = (uint)DAT_200000e6;
  if (0x7f < (byte)(&DAT_20002812)[uVar3]) {
    if (uVar3 == 0) {
      DAT_2000006d = 1;
      DAT_20000092 = 1;
      DAT_200000e7 = 0;
      DAT_200000e8 = 0;
      DAT_200000e9 = 0xff;
      DAT_20002812 = 0xff;
      return;
    }
    (&DAT_20002812)[uVar3] = 0xff;
    uVar4 = uVar3 - 1;
    uVar3 = uVar4 & 0xff;
    DAT_200000e6 = (byte)uVar4;
  }
  (&DAT_20002812)[uVar3] = 0xff;
  DAT_200000e9 = 0xff;
  DAT_200000e8 = 0;
  DAT_200000e7 = 0;
  DAT_2000006d = 1;
  return;
}



// ==== 08006afc  caseD_d4  (74 bytes, 2 xrefs)

void switchD_08006950::caseD_d4(int param_1,int param_2)

{
  if ((param_2 == 0) && (param_1 == 1)) {
    DAT_20000092 = 1;
    if ((DAT_20002666 == '\x01') && (DAT_2000017f != '\0')) {
      if (DAT_200000c9 == '\0') {
        DAT_200000c9 = '\x01';
      }
      else {
        DAT_200000c9 = '\0';
      }
    }
    else {
      DAT_20000071 = 2;
      DAT_200000c9 = '\0';
      DAT_20000178 = 0;
      DAT_2000017f = '\0';
    }
    DAT_2000006c = 1;
    DAT_2000006d = 1;
  }
  return;
}



// ==== 08006b68  FUN_08006b68  (96 bytes, 1 xrefs)

void FUN_08006b68(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  pcVar3 = DAT_08006bcc;
  puVar2 = DAT_08006bc8;
  if ((param_3 == 0) && (param_2 == 1)) {
    *DAT_08006bc8 = 1;
    pbVar5 = DAT_08006bdc;
    iVar4 = DAT_08006bd8;
    if (*pcVar3 == '\0') {
      FUN_08004fbc();
    }
    else if ((param_1 == 0) || (5 < param_1)) {
      *puVar2 = 2;
    }
    else {
      iVar6 = (*DAT_08006bd0 + param_1) * 2 + DAT_08006bd4;
      bVar1 = *DAT_08006bdc;
      *(undefined1 *)(DAT_08006bd8 + (uint)bVar1) = *(undefined1 *)(iVar6 + -2);
      *(undefined1 *)(iVar4 + (uint)bVar1 + 1) = *(undefined1 *)(iVar6 + -1);
      *pbVar5 = bVar1 + 2;
      *DAT_08006be0 = 0;
      *DAT_08006be4 = 0;
      *pcVar3 = '\0';
    }
    *DAT_08006be8 = 1;
  }
  return;
}



// ==== 08006bec  FUN_08006bec  (102 bytes, 1 xrefs)

void FUN_08006bec(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  byte *pbVar2;
  ushort *puVar3;
  int iVar4;
  
  puVar1 = DAT_08006c54;
  if (param_2 == 0) {
    if (param_1 != 1) {
      return;
    }
    *DAT_08006c54 = 1;
  }
  else if (param_1 != 1) {
    return;
  }
  puVar3 = DAT_08006c6c;
  pbVar2 = DAT_08006c5c;
  if (*DAT_08006c58 == '\0') {
    param_3 = (uint)*DAT_08006c64 + param_3;
    if ((-1 < param_3) && (param_3 < (int)(uint)*DAT_08006c68)) {
      *DAT_08006c64 = (byte)param_3;
      FUN_08009194((uint)*puVar3 + param_3 & 0xffff,DAT_08006c60);
      FUN_08009168();
      iVar4 = 0;
      goto LAB_08006c4a;
    }
  }
  else {
    iVar4 = param_3 * 5 + (uint)*DAT_08006c5c;
    if ((-1 < iVar4) && (iVar4 < (int)(uint)*(byte *)(DAT_08006c60 + 0xe))) {
LAB_08006c4a:
      *pbVar2 = (byte)iVar4;
      *DAT_08006c70 = 1;
      return;
    }
  }
  *puVar1 = 2;
  return;
}



// ==== 08006c74  FUN_08006c74  (84 bytes, 1 xrefs)

void FUN_08006c74(undefined4 param_1,int param_2,int param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  
  if ((param_3 == 0) && (param_2 == 1)) {
    *DAT_08006cc8 = 1;
    pcVar1 = DAT_08006cd0;
    *DAT_08006ccc = 0;
    if (*pcVar1 != -1) {
      *DAT_08006cd4 = *DAT_08006cd4 + '\x01';
      *pcVar1 = -1;
    }
    *(bool *)(DAT_08006cd8 + 0x16) = *(char *)(DAT_08006cd8 + 0x16) == '\0';
    *DAT_08006cdc = 0;
    puVar2 = DAT_08006ce0;
    *pcVar1 = -1;
    *puVar2 = 0;
    *DAT_08006ce4 = 0;
    *DAT_08006ce8 = 0;
    *DAT_08006cec = 1;
    *DAT_08006cf0 = 1;
  }
  return;
}



// ==== 08006cf4  FUN_08006cf4  (94 bytes, 1 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x08006d98

// ==== 08006dd4  FUN_08006dd4  (90 bytes, 1 xrefs)

void FUN_08006dd4(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 uVar3;
  byte bVar4;
  
  if ((param_2 != 0) || (param_1 != 1)) {
    return;
  }
  *PTR_DAT_08006e30 = 1;
  puVar2 = PTR_DAT_08006e40;
  puVar1 = PTR_DAT_08006e3c;
  if (*PTR_DAT_08006e34 == '\x01') {
    FUN_08008d94();
    return;
  }
  if (*PTR_DAT_08006e38 == '\0') {
    if (*PTR_DAT_08006e44 == '\0') {
      return;
    }
    bVar4 = *PTR_DAT_08006e44 - 1;
    *PTR_DAT_08006e44 = bVar4;
    PTR_DAT_08006e48[bVar4] = 10;
    if (bVar4 != 0) goto LAB_08006e2a;
    uVar3 = 0xd;
  }
  else {
    FUN_0800b168();
    FUN_08009534(0,0x22);
    uVar3 = 0xfe;
  }
  *puVar1 = uVar3;
LAB_08006e2a:
  *puVar2 = 0;
  return;
}



// ==== 08006e4c  FUN_08006e4c  (48 bytes, 1 xrefs)

void FUN_08006e4c(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if ((param_2 == 0) && (param_1 == 1)) {
    *PTR_DAT_08006e7c = 1;
    puVar2 = PTR_DAT_08006e84;
    cVar1 = *PTR_DAT_08006e80;
    *PTR_DAT_08006e80 = 0;
    puVar3 = PTR_DAT_08006e8c;
    if (cVar1 == '\0') {
      *PTR_DAT_08006e88 = 1;
      *puVar2 = 2;
      *puVar3 = 0x1d;
      return;
    }
    *puVar2 = 0;
  }
  return;
}



// ==== 08006e90  FUN_08006e90  (394 bytes, 0 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x08007032

// ==== 080071b4  FUN_080071b4  (308 bytes, 6 xrefs)

void FUN_080071b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  char *pcVar8;
  undefined1 uVar9;
  
  *DAT_080072ec = 0;
  pcVar8 = DAT_08007358;
  puVar6 = DAT_08007310;
  puVar5 = DAT_08007300;
  puVar4 = DAT_080072f0;
  cVar1 = *DAT_080072f4;
  cVar2 = *DAT_080072f8;
  if (param_1 == 1) {
    if (*DAT_080072fc != '\0') {
      FUN_0800b168();
LAB_08007218:
      *puVar4 = 0;
      puVar4 = DAT_0800730c;
      *puVar5 = 0;
      *puVar4 = 0;
      return;
    }
    if (*DAT_08007304 != '\0') {
      FUN_0800b1fc();
      FUN_08009534(0,0x22);
      *DAT_08007308 = 0xfe;
      *puVar4 = 1;
LAB_0800724a:
      *DAT_08007328 = 1;
      return;
    }
    if ((cVar2 == '\x02') || (cVar2 == '\x01')) goto LAB_08007218;
    if (cVar2 == '\x03') {
      *DAT_080072f0 = 0;
      *(undefined1 *)(DAT_08007314 + 0x1b) = *puVar6;
      *DAT_08007318 = 1;
      *DAT_0800731c = 1;
      *DAT_08007320 = 2;
      *DAT_08007324 = 1;
      FUN_08009534(0,0x22,2,cVar1,param_4);
      *DAT_08007308 = 0xfe;
      goto LAB_0800724a;
    }
    if ((cVar1 == '\x01') && (*DAT_0800732c == '\0')) {
      return;
    }
    *DAT_08007330 = 1;
    pbVar7 = DAT_08007338;
    if (*DAT_08007334 == '\x01') {
      if (*DAT_08007338 != 0 || *DAT_0800733c != 0) {
        if (*DAT_08007338 == 0) {
          *DAT_08007338 = *DAT_0800733c;
        }
        bVar3 = *pbVar7;
        *(undefined1 *)(DAT_08007340 + (uint)bVar3) = 0;
        if (bVar3 == 3) {
          uVar9 = FUN_08004da4(DAT_08007340);
          *DAT_08007344 = uVar9;
        }
        else {
          *DAT_08007344 = 2;
        }
        FUN_08011998(DAT_0800734c,&DAT_08007348,DAT_08007340);
        *DAT_0800733c = *pbVar7;
        *DAT_08007350 = 1;
        *DAT_08007354 = 0;
      }
      *DAT_08007334 = '\0';
      *pbVar7 = 0;
    }
    goto LAB_080072a4;
  }
  if (cVar2 != '\0') {
    return;
  }
  if (cVar1 == '\x01') {
    if (*DAT_08007358 == '\x01') {
LAB_080072d6:
      FUN_0800b2fc(0);
    }
    else {
      FUN_0800b73c();
      if (*(char *)(DAT_08007314 + 0x3c) == '\0') goto LAB_080072d6;
      *DAT_0800732c = *(char *)(DAT_08007314 + 0x3c) * '\n';
    }
    puVar5 = DAT_0800735c;
    *pcVar8 = '\0';
    *puVar5 = 0;
  }
  FUN_0800bea4(0);
LAB_080072a4:
  *puVar4 = 0;
  return;
}



// ==== 08007360  FUN_08007360  (150 bytes, 1 xrefs)

void FUN_08007360(int param_1,int param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  
  pcVar3 = DAT_08007404;
  puVar2 = DAT_08007400;
  bVar1 = *(byte *)(*DAT_080073f8 + 0x1e);
  if (*DAT_080073fc != '\0') {
    if ((param_2 == 0) && (param_1 == 1)) {
      *DAT_08007400 = 2;
    }
    return;
  }
  if ((param_2 == 0) && (param_1 == 1)) {
    *DAT_08007400 = 1;
    if (*pcVar3 != '\x01') {
      return;
    }
    *pcVar3 = '\0';
    *DAT_08007408 = 1;
    puVar5 = DAT_08007418;
    if (bVar1 < 0xcf) {
      *DAT_0800740c = 1;
      *DAT_08007410 = 1;
      iVar4 = DAT_08007414;
      *puVar5 = *(undefined1 *)(DAT_08007414 + 0x1b);
      *(undefined1 *)(iVar4 + 0x1b) = 0;
    }
    else {
      *puVar2 = 2;
    }
    *DAT_0800741c = 1;
  }
  else {
    if (param_2 != 0 || param_1 != 0) {
      if (param_2 != 1) {
        return;
      }
      if (param_1 == 1) {
        FUN_08008ee4(0);
        return;
      }
      return;
    }
    if ((*DAT_08007420 == '\0') && (bVar1 < 0xcf)) {
      *DAT_08007424 = 1;
      FUN_08002968(DAT_0800742c,DAT_08007428,0xf);
      *DAT_08007430 = 0;
      *DAT_08007434 = 0;
      return;
    }
  }
  return;
}



// ==== 08007438  FUN_08007438  (216 bytes, 1 xrefs)

void FUN_08007438(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  char cVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  puVar3 = PTR_DAT_08007514;
  uVar7 = (uint)(byte)PTR_DAT_08007510[9];
  uVar6 = (uint)(byte)PTR_DAT_08007510[uVar7];
  iVar5 = *(int *)PTR_DAT_08007514;
  if ((param_2 == 0) && (param_1 == 1)) {
    if (*PTR_DAT_08007518 != '\0') {
      *PTR_DAT_08007520 = 2;
      return;
    }
    *PTR_DAT_08007520 = 1;
  }
  else {
    if (*PTR_DAT_08007518 != '\0') {
      return;
    }
    if (param_1 != 1) {
      if (param_2 != 1) {
        return;
      }
      if (199 < uVar6) {
        return;
      }
      FUN_080096a0(0,*(byte *)(iVar5 + 0x1e) + 1);
      uVar1 = 0xfe;
      puVar3 = PTR_DAT_0800751c;
      goto LAB_08007476;
    }
  }
  if (*PTR_DAT_08007524 != '\0') {
    FUN_0800aedc(0,param_3);
    puVar3 = PTR_DAT_08007528;
LAB_080074d0:
    *puVar3 = 1;
    return;
  }
  if (uVar6 < 0xcf) {
    if (199 < uVar6) {
      FUN_08004244(iVar5,param_3);
      FUN_080041c4(*(undefined4 *)puVar3);
      puVar3 = PTR_DAT_0800752c;
      goto LAB_080074d0;
    }
    uVar4 = FUN_08004f10(uVar6 + param_3 & 0xff,param_3,0,0,param_4);
    puVar3 = PTR_DAT_08007510;
    if (uVar4 == 0xff) {
      return;
    }
    if (uVar6 == uVar4) {
      return;
    }
    PTR_DAT_08007510[uVar7 + 4] = (char)uVar4;
    puVar3[uVar7] = (char)uVar4;
    if (param_2 == 0) {
      FUN_080096a0(0,uVar4 + 1);
      *PTR_DAT_0800751c = 0xfe;
    }
  }
  else {
    cVar2 = FUN_08004284(uVar6 - 0xcf & 0xff,param_3,0,9);
    puVar3 = PTR_DAT_08007510;
    PTR_DAT_08007510[uVar7 + 6] = cVar2 + -0x31;
    puVar3[uVar7] = cVar2 + -0x31;
  }
  puVar3 = PTR_DAT_08007534;
  *PTR_DAT_08007530 = 1;
  uVar1 = 2;
LAB_08007476:
  *puVar3 = uVar1;
  return;
}



// ==== 08007538  FUN_08007538  (136 bytes, 1 xrefs)

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x08007540) */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x08007540) */

void FUN_08007538(byte *param_1,byte *param_2,byte *param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined *puVar3;
  byte bVar4;
  undefined1 uVar5;
  byte *pbVar6;
  undefined1 *puVar8;
  uint uVar7;
  byte *unaff_r6;
  undefined1 uVar9;
  byte *unaff_r7;
  int unaff_r11;
  undefined2 *puVar10;
  char in_CY;
  bool bVar11;
  bool bVar12;
  byte *pbVar13;
  longlong lVar14;
  undefined4 in_cr1;
  undefined4 in_cr9;
  undefined4 in_cr14;
  undefined2 auStack_14 [2];
  
  bVar11 = param_1 == (byte *)0x0;
  if (param_1 < (byte *)0x16) {
    bVar4 = param_1[0x8007545];
  }
  else {
    bVar4 = 0x2b;
  }
  uVar7 = (uint)bVar4;
  puVar8 = (undefined1 *)(uVar7 * 2);
  puVar10 = (undefined2 *)(puVar8 + 0x8007545);
  pbVar6 = param_2;
  pbVar13 = param_3;
  bVar12 = bVar11;
  switch(uVar7) {
  case 0:
  case 1:
switchD_08007540_caseD_2:
switchD_08007540_caseD_3:
switchD_08007540_caseD_4:
switchD_08007540_caseD_5:
switchD_08007540_caseD_6:
switchD_08007540_caseD_7:
switchD_08007540_caseD_8:
switchD_08007540_caseD_9:
switchD_08007540_caseD_a:
switchD_08007540_caseD_b:
switchD_08007540_caseD_c:
    param_1 = param_2;
switchD_08007540_caseD_d:
    FUN_080071b4(param_1);
switchD_08007540_caseD_f:
    goto switchD_08007540_caseD_32;
  case 2:
    goto switchD_08007540_caseD_2;
  case 3:
    goto switchD_08007540_caseD_3;
  case 4:
    goto switchD_08007540_caseD_4;
  case 5:
    goto switchD_08007540_caseD_5;
  case 6:
    goto switchD_08007540_caseD_6;
  case 7:
    goto switchD_08007540_caseD_7;
  case 8:
    goto switchD_08007540_caseD_8;
  case 9:
    goto switchD_08007540_caseD_9;
  case 10:
    goto switchD_08007540_caseD_a;
  case 0xb:
    goto switchD_08007540_caseD_b;
  case 0xc:
    goto switchD_08007540_caseD_c;
  case 0xd:
    goto switchD_08007540_caseD_d;
  case 0xe:
    coprocessor_function2(0,2,1,in_cr14,in_cr9,in_cr1);
  case 0x10:
    pbVar6 = param_3;
switchD_08007540_caseD_11:
    param_1 = param_2;
switchD_08007540_caseD_12:
    switchD_08007540::caseD_88(param_1,pbVar6);
switchD_08007540_caseD_14:
    goto switchD_08007540_caseD_32;
  case 0xf:
    goto switchD_08007540_caseD_f;
  case 0x11:
    goto switchD_08007540_caseD_11;
  case 0x12:
    goto switchD_08007540_caseD_12;
  case 0x13:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x14:
    goto switchD_08007540_caseD_14;
  case 0x15:
    pbVar6 = param_3;
  case 0x16:
    param_1 = param_2;
switchD_08007540_caseD_17:
    switchD_08007540::caseD_46(param_1,pbVar6);
switchD_08007540_caseD_19:
    goto switchD_08007540_caseD_32;
  case 0x17:
    goto switchD_08007540_caseD_17;
  case 0x18:
    auStack_14[(int)(unaff_r7 + 2)] = 0x7545;
  case 0x1a:
    pbVar13 = (byte *)0x0;
switchD_08007540_caseD_1b:
    pbVar13 = (byte *)~(uint)pbVar13;
switchD_08007540_caseD_1c:
    break;
  case 0x19:
    goto switchD_08007540_caseD_19;
  case 0x1b:
    goto switchD_08007540_caseD_1b;
  case 0x1c:
    goto switchD_08007540_caseD_1c;
  case 0x1d:
    pbVar13 = (byte *)0x1;
    break;
  case 0x1f:
    goto switchD_08007540_caseD_1f;
  case 0x20:
    goto switchD_08007540_caseD_20;
  case 0x21:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x22:
    goto switchD_08007540_caseD_22;
  case 0x23:
    FUN_080078b4();
  case 0x25:
    goto switchD_08007540_caseD_32;
  case 0x24:
  case 0x26:
    pbVar6 = param_3;
switchD_08007540_caseD_27:
    param_1 = param_2;
switchD_08007540_caseD_28:
    FUN_08007be8(param_1,pbVar6);
switchD_08007540_caseD_2a:
    goto switchD_08007540_caseD_32;
  case 0x27:
    goto switchD_08007540_caseD_27;
  case 0x28:
    goto switchD_08007540_caseD_28;
  case 0x29:
  case 0x2b:
    bVar11 = param_3 == (byte *)0x0;
switchD_08007540_caseD_2c:
    if (bVar11) {
switchD_08007540_caseD_2d:
      bVar11 = param_2 == (byte *)0x1;
switchD_08007540_caseD_2e:
      if (bVar11) {
switchD_08007540_caseD_2f:
        param_2 = switchD_08007540::caseD_3e;
switchD_08007540_caseD_30:
        param_1 = (byte *)0x1;
switchD_08007540_caseD_31:
        *param_2 = (byte)param_1;
      }
    }
    goto switchD_08007540_caseD_32;
  case 0x2a:
    goto switchD_08007540_caseD_2a;
  case 0x2c:
    goto switchD_08007540_caseD_2c;
  case 0x2d:
    goto switchD_08007540_caseD_2d;
  case 0x2e:
    goto switchD_08007540_caseD_2e;
  case 0x2f:
    goto switchD_08007540_caseD_2f;
  case 0x30:
    goto switchD_08007540_caseD_30;
  case 0x31:
    goto switchD_08007540_caseD_31;
  case 0x32:
    goto switchD_08007540_caseD_32;
  case 0x33:
    goto switchD_08007540_caseD_33;
  case 0x34:
    goto switchD_08007540_caseD_34;
  case 0x35:
    goto switchD_08007540_caseD_35;
  case 0x36:
    goto switchD_08007540_caseD_36;
  case 0x37:
    goto switchD_08007540_caseD_37;
  case 0x38:
    goto switchD_08007540_caseD_38;
  case 0x39:
    goto switchD_08007540_caseD_39;
  case 0x3a:
    goto switchD_08007540_caseD_3a;
  case 0x3b:
    goto switchD_08007540_caseD_3b;
  case 0x3c:
    goto switchD_08007540_caseD_3c;
  case 0x3d:
    goto switchD_08007540_caseD_3d;
  case 0x3e:
  case 0x3f:
code_r0x080075c4:
    param_2 = (byte *)(uVar7 << 4);
code_r0x080075c6:
code_r0x080075c8:
code_r0x080075ca:
code_r0x080075cc:
code_r0x080075ce:
    param_1 = (byte *)0x0;
code_r0x080075d0:
code_r0x080075d2:
    bVar11 = param_2 == (byte *)0x0;
code_r0x080075d4:
    if (!bVar11) {
switchD_08007540_caseD_59:
      return;
    }
code_r0x080075d6:
    bVar11 = param_1 == (byte *)0x1;
switchD_08007540_caseD_4a:
    if (!bVar11) {
      return;
    }
switchD_08007540_caseD_4b:
    param_1 = switchD_08007540::caseD_74;
switchD_08007540_caseD_4c:
    param_3 = (byte *)0x1;
switchD_08007540_caseD_4d:
    pbVar6 = switchD_08007540::caseD_76;
switchD_08007540_caseD_4e:
    *param_1 = (byte)param_3;
switchD_08007540_caseD_4f:
    param_1 = (byte *)(uint)*pbVar6;
switchD_08007540_caseD_50:
    puVar8 = switchD_08007540::caseD_78;
switchD_08007540_caseD_51:
    unaff_r6 = (byte *)0xd;
switchD_08007540_caseD_52:
    bVar11 = param_1 == (byte *)0x1;
switchD_08007540_caseD_53:
    pbVar13 = param_3;
    if (!bVar11) {
switchD_08007540_caseD_54:
      param_1 = switchD_08007540::caseD_7a;
switchD_08007540_caseD_55:
      *param_1 = (byte)unaff_r6;
switchD_08007540_caseD_56:
      param_1 = switchD_08007540::caseD_7c;
switchD_08007540_caseD_57:
      *puVar8 = (char)param_2;
switchD_08007540_caseD_58:
      *param_1 = (byte)param_3;
      return;
    }
switchD_08007540_caseD_5a:
    param_3 = switchD_08007540::caseD_7e;
switchD_08007540_caseD_5b:
    param_1 = (byte *)(uint)*param_3;
switchD_08007540_caseD_5c:
    bVar11 = param_1 == (byte *)0x0;
switchD_08007540_caseD_5d:
    if (bVar11) {
switchD_08007540_caseD_62:
      *pbVar6 = (byte)param_2;
switchD_08007540_caseD_63:
      param_1 = switchD_08007540::caseD_82;
switchD_08007540_caseD_64:
      *param_3 = (byte)param_2;
switchD_08007540_caseD_65:
      *param_1 = (byte)param_2;
switchD_08007540_caseD_66:
      param_1 = switchD_08007540::caseD_84;
switchD_08007540_caseD_67:
      *param_1 = (byte)pbVar13;
switchD_08007540_caseD_68:
      param_1 = switchD_08007540::caseD_7a;
switchD_08007540_caseD_69:
      *param_1 = (byte)unaff_r6;
    }
    else {
switchD_08007540_caseD_5e:
      unaff_r7 = switchD_08007540::caseD_80;
switchD_08007540_caseD_5f:
      unaff_r7 = (byte *)(uint)*unaff_r7;
switchD_08007540_caseD_60:
      bVar11 = unaff_r7 == &NMI;
switchD_08007540_caseD_61:
      if (!bVar11) goto switchD_08007540_caseD_62;
switchD_08007540_caseD_6d:
      param_1 = param_1 + -1;
switchD_08007540_caseD_6e:
      param_1 = (byte *)((uint)param_1 & 0xff);
switchD_08007540_caseD_6f:
      *param_3 = (byte)param_1;
switchD_08007540_caseD_70:
      param_3 = switchD_08007540::caseD_86;
switchD_08007540_caseD_71:
      param_2 = (byte *)0xa;
switchD_08007540_caseD_72:
      param_3[(int)param_1] = (byte)param_2;
switchD_08007540_caseD_73:
    }
switchD_08007540_caseD_6a:
    param_1 = (byte *)0x2;
switchD_08007540_caseD_6b:
    *puVar8 = (char)param_1;
switchD_08007540_caseD_6c:
    return;
  case 0x40:
    goto code_r0x080075c4;
  case 0x41:
    goto code_r0x080075c6;
  case 0x42:
    goto code_r0x080075c8;
  case 0x43:
    goto code_r0x080075ca;
  case 0x44:
    goto code_r0x080075cc;
  case 0x45:
    goto code_r0x080075ce;
  case 0x46:
    goto code_r0x080075d0;
  case 0x47:
    goto code_r0x080075d2;
  case 0x48:
    goto code_r0x080075d4;
  case 0x49:
    goto code_r0x080075d6;
  case 0x4a:
    goto switchD_08007540_caseD_4a;
  case 0x4b:
    goto switchD_08007540_caseD_4b;
  case 0x4c:
    goto switchD_08007540_caseD_4c;
  case 0x4d:
    goto switchD_08007540_caseD_4d;
  case 0x4e:
    goto switchD_08007540_caseD_4e;
  case 0x4f:
    goto switchD_08007540_caseD_4f;
  case 0x50:
    goto switchD_08007540_caseD_50;
  case 0x51:
    goto switchD_08007540_caseD_51;
  case 0x52:
    goto switchD_08007540_caseD_52;
  case 0x53:
    goto switchD_08007540_caseD_53;
  case 0x54:
    goto switchD_08007540_caseD_54;
  case 0x55:
    goto switchD_08007540_caseD_55;
  case 0x56:
    goto switchD_08007540_caseD_56;
  case 0x57:
    goto switchD_08007540_caseD_57;
  case 0x58:
    goto switchD_08007540_caseD_58;
  case 0x59:
    goto switchD_08007540_caseD_59;
  case 0x5a:
    goto switchD_08007540_caseD_5a;
  case 0x5b:
    goto switchD_08007540_caseD_5b;
  case 0x5c:
    goto switchD_08007540_caseD_5c;
  case 0x5d:
    goto switchD_08007540_caseD_5d;
  case 0x5e:
    goto switchD_08007540_caseD_5e;
  case 0x5f:
    goto switchD_08007540_caseD_5f;
  case 0x60:
    goto switchD_08007540_caseD_60;
  case 0x61:
    goto switchD_08007540_caseD_61;
  case 0x62:
    goto switchD_08007540_caseD_62;
  case 99:
    goto switchD_08007540_caseD_63;
  case 100:
    goto switchD_08007540_caseD_64;
  case 0x65:
    goto switchD_08007540_caseD_65;
  case 0x66:
    goto switchD_08007540_caseD_66;
  case 0x67:
    goto switchD_08007540_caseD_67;
  case 0x68:
    goto switchD_08007540_caseD_68;
  case 0x69:
    goto switchD_08007540_caseD_69;
  case 0x6a:
    goto switchD_08007540_caseD_6a;
  case 0x6b:
    goto switchD_08007540_caseD_6b;
  case 0x6c:
    goto switchD_08007540_caseD_6c;
  case 0x6d:
    goto switchD_08007540_caseD_6d;
  case 0x6e:
    goto switchD_08007540_caseD_6e;
  case 0x6f:
    goto switchD_08007540_caseD_6f;
  case 0x70:
    goto switchD_08007540_caseD_70;
  case 0x71:
    goto switchD_08007540_caseD_71;
  case 0x72:
    goto switchD_08007540_caseD_72;
  case 0x73:
    goto switchD_08007540_caseD_73;
  case 0x74:
  case 0x75:
code_r0x08007630:
code_r0x08007632:
code_r0x08007634:
code_r0x08007636:
code_r0x08007638:
code_r0x0800763a:
code_r0x0800763c:
code_r0x0800763e:
code_r0x08007640:
code_r0x08007642:
code_r0x08007644:
code_r0x08007646:
code_r0x08007648:
code_r0x0800764a:
code_r0x0800764c:
code_r0x0800764e:
code_r0x08007650:
code_r0x08007652:
    param_1 = (byte *)0x0;
code_r0x08007654:
code_r0x08007656:
    bVar11 = param_2 == (byte *)0x0;
code_r0x08007658:
    if (!bVar11) {
      return;
    }
code_r0x0800765a:
    bVar11 = param_1 == (byte *)0x1;
switchD_08007540_caseD_8c:
    if (!bVar11) {
      return;
    }
switchD_08007540_caseD_8d:
    puVar8 = PTR_DAT_0800785c;
switchD_08007540_caseD_8e:
    param_3 = (byte *)0x1;
switchD_08007540_caseD_8f:
    param_2 = PTR_DAT_08007860;
switchD_08007540_caseD_90:
    *puVar8 = (char)param_3;
switchD_08007540_caseD_91:
    param_1 = (byte *)0x2;
switchD_08007540_caseD_92:
    *param_2 = (byte)param_1;
switchD_08007540_caseD_93:
    pbVar6 = PTR_DAT_08007864;
switchD_08007540_caseD_94:
    param_2 = PTR_DAT_0800786c;
switchD_08007540_caseD_95:
    param_1 = (byte *)(uint)*pbVar6;
switchD_08007540_caseD_96:
    unaff_r7 = (byte *)0x78;
switchD_08007540_caseD_97:
    pbVar13 = param_3;
    unaff_r6 = PTR_DAT_08007868;
switchD_08007540_caseD_98:
    param_3 = (byte *)(uint)*param_2;
switchD_08007540_caseD_99:
    bVar11 = param_1 == (byte *)0x0;
switchD_08007540_caseD_9a:
    if (bVar11) {
switchD_08007540_caseD_b6:
      bVar11 = param_3 == (byte *)0xa;
switchD_08007540_caseD_b7:
      if (!bVar11) {
switchD_08007540_caseD_b8:
        param_1 = DAT_0800787c;
switchD_08007540_caseD_b9:
        param_2 = (byte *)(uint)param_1[(int)param_3];
switchD_08007540_caseD_ba:
        param_1 = PTR_DAT_08007880;
switchD_08007540_caseD_bb:
        *param_1 = (byte)param_2;
      }
switchD_08007540_caseD_bc:
      param_2 = (byte *)0x0;
switchD_08007540_caseD_bd:
      param_1 = PTR_DAT_08007884;
switchD_08007540_caseD_be:
      *unaff_r6 = (byte)param_2;
switchD_08007540_caseD_bf:
      *param_1 = (byte)param_2;
switchD_08007540_caseD_c0:
      bVar11 = param_3 == (byte *)0x33;
switchD_08007540_caseD_c1:
      if (bVar11) {
switchD_08007540_caseD_c7:
        *param_1 = (byte)pbVar13;
switchD_08007540_caseD_c8:
        FUN_08004920();
        param_3 = pbVar13;
switchD_08007540_caseD_ca:
        param_1 = PTR_DAT_08007888;
        goto switchD_08007540_caseD_cb;
      }
switchD_08007540_caseD_c2:
      bVar11 = param_3 == &Reserved6;
switchD_08007540_caseD_c3:
      if (bVar11) goto switchD_08007540_caseD_c7;
switchD_08007540_caseD_c4:
      bVar11 = param_3 == &HardFault;
switchD_08007540_caseD_c5:
      param_3 = pbVar13;
      if (bVar11) {
switchD_08007540_caseD_d5:
        param_2 = PTR_DAT_08007898;
switchD_08007540_caseD_d6:
        param_2 = *(byte **)param_2;
switchD_08007540_caseD_d7:
        in_CY = (byte *)0xc7 < param_2;
switchD_08007540_caseD_d8:
        if (in_CY != '\0') {
switchD_08007540_caseD_d9:
          param_1 = (byte *)0x2;
switchD_08007540_caseD_da:
          *puVar8 = (char)param_1;
switchD_08007540_caseD_db:
          param_1 = (byte *)0xff;
switchD_08007540_caseD_dc:
          param_2 = PTR_DAT_08007860;
switchD_08007540_caseD_dd:
          bVar4 = (byte)param_1;
          goto LAB_08007856;
        }
switchD_08007540_caseD_de:
        param_2 = (byte *)0x1;
switchD_08007540_caseD_df:
        *param_1 = (byte)param_2;
switchD_08007540_caseD_e0:
        FUN_08004920();
switchD_08007540_caseD_e2:
        param_2 = PTR_DAT_08007888;
        goto switchD_08007540_caseD_e3;
      }
switchD_08007540_caseD_c6:
      goto switchD_08007540_caseD_d3;
    }
switchD_08007540_caseD_9b:
    param_1 = PTR_DAT_08007870;
switchD_08007540_caseD_9c:
    param_2 = (byte *)(uint)*param_1;
switchD_08007540_caseD_9d:
    param_1 = PTR_DAT_08007874;
switchD_08007540_caseD_9e:
    param_1 = (byte *)(uint)*param_1;
switchD_08007540_caseD_9f:
    param_1 = param_1 + 1;
switchD_08007540_caseD_a0:
    param_1 = (byte *)((uint)param_1 & 0xff);
switchD_08007540_caseD_a1:
    bVar11 = param_3 == (byte *)0x37;
switchD_08007540_caseD_a2:
    uVar5 = SUB41(param_1,0);
    bVar4 = (byte)pbVar13;
    uVar9 = SUB41(unaff_r7,0);
    if (bVar11) {
LAB_08007752:
      if (*unaff_r6 != 0) {
        if (*unaff_r6 == 1) {
          *unaff_r6 = 2;
          FUN_0800d15c();
          if (*PTR_DAT_0800786c == '7') {
            FUN_08009534(0,0x10);
            FUN_08009330(1);
            FUN_0800aa8c();
            DataSynchronizationBarrier(0xf);
            *(undefined4 *)(DAT_080078b0 + 0xc) = DAT_080078ac;
            DataSynchronizationBarrier(0xf);
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          *PTR_DAT_08007878 = bVar4;
          *pbVar6 = 0;
          *unaff_r6 = 0;
        }
        goto switchD_08007540_caseD_b1;
      }
      if ((param_3 != (byte *)0xd) && (param_3 != &HardFault)) {
LAB_080077e4:
        *unaff_r6 = bVar4;
        goto switchD_08007540_caseD_b1;
      }
      if (*PTR_DAT_08007884 == '\0') {
        *PTR_DAT_08007884 = bVar4;
        FUN_08004920();
        *PTR_DAT_08007888 = 10;
        *PTR_DAT_0800788c = uVar9;
        *PTR_DAT_08007890 = uVar9;
        *PTR_DAT_08007894 = bVar4;
        goto switchD_08007540_caseD_b1;
      }
      *PTR_DAT_08007884 = 0;
      puVar3 = PTR_DAT_08007870;
      if (param_2 != (byte *)0xff) {
        *PTR_DAT_08007874 = uVar5;
        *puVar3 = 0xff;
      }
      if (*PTR_DAT_08007874 == '\0') {
        *PTR_DAT_080078a8 = 0;
      }
      else {
        FUN_08002968(PTR_DAT_080078a4,PTR_DAT_080078a0);
        PTR_DAT_080078a4[(byte)*PTR_DAT_08007874] = 0;
        *PTR_DAT_080078a8 = bVar4;
      }
      if (*PTR_DAT_0800786c != '\f') goto LAB_080077e4;
      *PTR_DAT_08007878 = bVar4;
      *pbVar6 = 0;
LAB_080077ee:
      uVar5 = 0x10;
    }
    else {
switchD_08007540_caseD_a3:
      bVar11 = param_3 == (byte *)0xd;
switchD_08007540_caseD_a4:
      uVar5 = SUB41(param_1,0);
      bVar4 = (byte)pbVar13;
      uVar9 = SUB41(unaff_r7,0);
      if (bVar11) goto LAB_08007752;
switchD_08007540_caseD_a5:
      bVar11 = param_3 == (byte *)0x36;
switchD_08007540_caseD_a6:
      uVar5 = SUB41(param_1,0);
      bVar4 = (byte)pbVar13;
      uVar9 = SUB41(unaff_r7,0);
      if (bVar11) goto LAB_08007752;
switchD_08007540_caseD_a7:
      bVar11 = param_3 == &HardFault;
switchD_08007540_caseD_a8:
      uVar5 = SUB41(param_1,0);
      bVar4 = (byte)pbVar13;
      uVar9 = SUB41(unaff_r7,0);
      if (bVar11) goto LAB_08007752;
switchD_08007540_caseD_a9:
      bVar11 = param_3 == (byte *)0x33;
switchD_08007540_caseD_aa:
      do {
        if (bVar11) {
          *PTR_DAT_08007884 = 0;
          puVar3 = PTR_DAT_08007870;
          if (param_2 != (byte *)0xff) {
            *PTR_DAT_08007874 = (char)param_1;
            *puVar3 = 0xff;
          }
          PTR_DAT_080078a0[(byte)*PTR_DAT_08007874] = 0;
          FUN_0800a864((uint)(param_3 + -0x33) & 0xff,PTR_DAT_080078a0);
          *pbVar6 = 0;
          goto switchD_08007540_caseD_b1;
        }
switchD_08007540_caseD_ab:
        bVar12 = param_3 == &Reserved6;
switchD_08007540_caseD_ac:
        bVar11 = true;
      } while (bVar12);
switchD_08007540_caseD_ad:
      param_1 = PTR_DAT_08007878;
switchD_08007540_caseD_ae:
      *param_1 = (byte)pbVar13;
switchD_08007540_caseD_af:
      param_1 = (byte *)0x0;
switchD_08007540_caseD_b0:
      *pbVar6 = (byte)param_1;
switchD_08007540_caseD_b1:
      param_1 = PTR_DAT_0800786c;
switchD_08007540_caseD_b2:
      param_1 = (byte *)(uint)*param_1;
switchD_08007540_caseD_b3:
      bVar11 = param_1 == (byte *)0xa;
switchD_08007540_caseD_b4:
      if (!bVar11) {
switchD_08007540_caseD_b5:
        goto LAB_080077ee;
      }
      if (*(int *)PTR_DAT_08007898 == 0) {
        uVar5 = 0x23;
      }
      else {
        uVar5 = 0x24;
      }
    }
    *PTR_DAT_08007880 = uVar5;
    goto LAB_08007852;
  case 0x76:
    goto code_r0x08007630;
  case 0x77:
    goto code_r0x08007632;
  case 0x78:
    goto code_r0x08007634;
  case 0x79:
    goto code_r0x08007636;
  case 0x7a:
    goto code_r0x08007638;
  case 0x7b:
    goto code_r0x0800763a;
  case 0x7c:
    goto code_r0x0800763c;
  case 0x7d:
    goto code_r0x0800763e;
  case 0x7e:
    goto code_r0x08007640;
  case 0x7f:
    goto code_r0x08007642;
  case 0x80:
    goto code_r0x08007644;
  case 0x81:
    goto code_r0x08007646;
  case 0x82:
    goto code_r0x08007648;
  case 0x83:
    goto code_r0x0800764a;
  case 0x84:
    goto code_r0x0800764c;
  case 0x85:
    goto code_r0x0800764e;
  case 0x86:
    goto code_r0x08007650;
  case 0x87:
    goto code_r0x08007652;
  case 0x88:
    goto code_r0x08007654;
  case 0x89:
    goto code_r0x08007656;
  case 0x8a:
    goto code_r0x08007658;
  case 0x8b:
    goto code_r0x0800765a;
  case 0x8c:
    goto switchD_08007540_caseD_8c;
  case 0x8d:
    goto switchD_08007540_caseD_8d;
  case 0x8e:
    goto switchD_08007540_caseD_8e;
  case 0x8f:
    goto switchD_08007540_caseD_8f;
  case 0x90:
    goto switchD_08007540_caseD_90;
  case 0x91:
    goto switchD_08007540_caseD_91;
  case 0x92:
    goto switchD_08007540_caseD_92;
  case 0x93:
    goto switchD_08007540_caseD_93;
  case 0x94:
    goto switchD_08007540_caseD_94;
  case 0x95:
    goto switchD_08007540_caseD_95;
  case 0x96:
    goto switchD_08007540_caseD_96;
  case 0x97:
    goto switchD_08007540_caseD_97;
  case 0x98:
    goto switchD_08007540_caseD_98;
  case 0x99:
    goto switchD_08007540_caseD_99;
  case 0x9a:
    goto switchD_08007540_caseD_9a;
  case 0x9b:
    goto switchD_08007540_caseD_9b;
  case 0x9c:
    goto switchD_08007540_caseD_9c;
  case 0x9d:
    goto switchD_08007540_caseD_9d;
  case 0x9e:
    goto switchD_08007540_caseD_9e;
  case 0x9f:
    goto switchD_08007540_caseD_9f;
  case 0xa0:
    goto switchD_08007540_caseD_a0;
  case 0xa1:
    goto switchD_08007540_caseD_a1;
  case 0xa2:
    goto switchD_08007540_caseD_a2;
  case 0xa3:
    goto switchD_08007540_caseD_a3;
  case 0xa4:
    goto switchD_08007540_caseD_a4;
  case 0xa5:
    goto switchD_08007540_caseD_a5;
  case 0xa6:
    goto switchD_08007540_caseD_a6;
  case 0xa7:
    goto switchD_08007540_caseD_a7;
  case 0xa8:
    goto switchD_08007540_caseD_a8;
  case 0xa9:
    goto switchD_08007540_caseD_a9;
  case 0xaa:
    goto switchD_08007540_caseD_aa;
  case 0xab:
    goto switchD_08007540_caseD_ab;
  case 0xac:
    goto switchD_08007540_caseD_ac;
  case 0xad:
    goto switchD_08007540_caseD_ad;
  case 0xae:
    goto switchD_08007540_caseD_ae;
  case 0xaf:
    goto switchD_08007540_caseD_af;
  case 0xb0:
    goto switchD_08007540_caseD_b0;
  case 0xb1:
    goto switchD_08007540_caseD_b1;
  case 0xb2:
    goto switchD_08007540_caseD_b2;
  case 0xb3:
    goto switchD_08007540_caseD_b3;
  case 0xb4:
    goto switchD_08007540_caseD_b4;
  case 0xb5:
    goto switchD_08007540_caseD_b5;
  case 0xb6:
    goto switchD_08007540_caseD_b6;
  case 0xb7:
    goto switchD_08007540_caseD_b7;
  case 0xb8:
    goto switchD_08007540_caseD_b8;
  case 0xb9:
    goto switchD_08007540_caseD_b9;
  case 0xba:
    goto switchD_08007540_caseD_ba;
  case 0xbb:
    goto switchD_08007540_caseD_bb;
  case 0xbc:
    goto switchD_08007540_caseD_bc;
  case 0xbd:
    goto switchD_08007540_caseD_bd;
  case 0xbe:
    goto switchD_08007540_caseD_be;
  case 0xbf:
    goto switchD_08007540_caseD_bf;
  case 0xc0:
    goto switchD_08007540_caseD_c0;
  case 0xc1:
    goto switchD_08007540_caseD_c1;
  case 0xc2:
    goto switchD_08007540_caseD_c2;
  case 0xc3:
    goto switchD_08007540_caseD_c3;
  case 0xc4:
    goto switchD_08007540_caseD_c4;
  case 0xc5:
    goto switchD_08007540_caseD_c5;
  case 0xc6:
    goto switchD_08007540_caseD_c6;
  case 199:
    goto switchD_08007540_caseD_c7;
  case 200:
    goto switchD_08007540_caseD_c8;
  case 0xc9:
    puVar10 = (undefined2 *)0x320;
    puVar1 = (undefined2 *)0x328;
    lVar14 = 4;
    pbVar13 = param_3;
    while( true ) {
      *puVar10 = *(undefined2 *)pbVar13;
      pbVar13 = pbVar13 + 2;
      *puVar1 = *(undefined2 *)pbVar13;
      pbVar13 = pbVar13 + 2;
      lVar14 = lVar14 + -1;
      if (lVar14 == 0) break;
      puVar10 = puVar10 + 1;
      puVar1 = puVar1 + 1;
    }
    param_3 = param_3 + unaff_r11;
  case 0xcb:
switchD_08007540_caseD_cb:
    param_2 = (byte *)0xf;
switchD_08007540_caseD_cc:
    *param_1 = (byte)param_2;
switchD_08007540_caseD_cd:
    param_1 = PTR_DAT_0800788c;
switchD_08007540_caseD_ce:
    *param_1 = (byte)unaff_r7;
switchD_08007540_caseD_cf:
    param_1 = PTR_DAT_08007890;
switchD_08007540_caseD_d0:
    *param_1 = (byte)unaff_r7;
switchD_08007540_caseD_d1:
    param_1 = PTR_DAT_08007894;
switchD_08007540_caseD_d2:
    *param_1 = (byte)param_3;
switchD_08007540_caseD_d3:
    *pbVar6 = (byte)param_3;
switchD_08007540_caseD_d4:
LAB_08007852:
    bVar4 = 0;
    param_2 = PTR_DAT_08007874;
LAB_08007856:
    *param_2 = bVar4;
    return;
  case 0xca:
    goto switchD_08007540_caseD_ca;
  case 0xcc:
    goto switchD_08007540_caseD_cc;
  case 0xcd:
    goto switchD_08007540_caseD_cd;
  case 0xce:
    goto switchD_08007540_caseD_ce;
  case 0xcf:
    goto switchD_08007540_caseD_cf;
  case 0xd0:
    goto switchD_08007540_caseD_d0;
  case 0xd1:
    goto switchD_08007540_caseD_d1;
  case 0xd2:
    goto switchD_08007540_caseD_d2;
  case 0xd3:
    goto switchD_08007540_caseD_d3;
  case 0xd4:
    goto switchD_08007540_caseD_d4;
  case 0xd5:
    goto switchD_08007540_caseD_d5;
  case 0xd6:
    goto switchD_08007540_caseD_d6;
  case 0xd7:
    goto switchD_08007540_caseD_d7;
  case 0xd8:
    goto switchD_08007540_caseD_d8;
  case 0xd9:
    goto switchD_08007540_caseD_d9;
  case 0xda:
    goto switchD_08007540_caseD_da;
  case 0xdb:
    goto switchD_08007540_caseD_db;
  case 0xdc:
    goto switchD_08007540_caseD_dc;
  case 0xdd:
    goto switchD_08007540_caseD_dd;
  case 0xde:
    goto switchD_08007540_caseD_de;
  case 0xdf:
    goto switchD_08007540_caseD_df;
  case 0xe0:
    goto switchD_08007540_caseD_e0;
  case 0xe1:
    puVar1 = (undefined2 *)0x320;
    puVar2 = (undefined2 *)0x330;
    lVar14 = 4;
    while( true ) {
      *puVar10 = *puVar1;
      puVar10[1] = *puVar2;
      puVar10 = puVar10 + 2;
      lVar14 = lVar14 + -1;
      if (lVar14 == 0) break;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
  case 0xe3:
switchD_08007540_caseD_e3:
    param_1 = (byte *)0xa;
switchD_08007540_caseD_e4:
    *param_2 = (byte)param_1;
switchD_08007540_caseD_e5:
    param_2 = PTR_DAT_0800789c;
switchD_08007540_caseD_e6:
    param_3 = (byte *)0x44;
switchD_08007540_caseD_e7:
    param_1 = (byte *)(uint)param_2[9];
switchD_08007540_caseD_e8:
    param_1 = (byte *)((int)param_3 * (int)param_1);
switchD_08007540_caseD_e9:
    param_1 = param_1 + (int)param_2;
switchD_08007540_caseD_ea:
    param_2 = (byte *)0xec;
switchD_08007540_caseD_eb:
    param_2 = (byte *)(uint)param_2[(int)param_1];
switchD_08007540_caseD_ec:
    bVar11 = param_2 == (byte *)0x0;
switchD_08007540_caseD_ed:
    if (!bVar11) {
switchD_08007540_caseD_ee:
      bVar11 = param_2 == (byte *)0xff;
switchD_08007540_caseD_ef:
      if (!bVar11) {
switchD_08007540_caseD_f0:
        param_1 = param_1 + 0xec;
switchD_08007540_caseD_f1:
        unaff_r6 = param_1;
switchD_08007540_caseD_f2:
        param_1 = (byte *)FUN_080029d8();
switchD_08007540_caseD_f4:
        param_3 = (byte *)((uint)param_1 & 0xff);
switchD_08007540_caseD_f5:
        in_CY = (byte *)0x9 < param_3;
        bVar11 = param_3 == (byte *)0xa;
switchD_08007540_caseD_f6:
        if (!(bool)in_CY || bVar11) {
switchD_08007540_caseD_f7:
          param_2 = unaff_r6;
switchD_08007540_caseD_f8:
switchD_08007540_caseD_f9:
          param_1 = PTR_DAT_080078a0;
switchD_08007540_caseD_fa:
          FUN_08002968(param_1,param_2,param_3);
switchD_08007540_caseD_fc:
          param_1 = PTR_DAT_08007874;
switchD_08007540_caseD_fd:
          *param_1 = (byte)param_3;
        }
      }
    }
switchD_08007540_caseD_fe:
    param_1 = PTR_DAT_0800788c;
switchD_08007540_caseD_ff:
    puVar3 = PTR_DAT_08007894;
    *param_1 = (byte)unaff_r7;
    *PTR_DAT_08007890 = (byte)unaff_r7;
    *puVar3 = 1;
    *pbVar6 = 1;
    return;
  case 0xe2:
    goto switchD_08007540_caseD_e2;
  case 0xe4:
    goto switchD_08007540_caseD_e4;
  case 0xe5:
    goto switchD_08007540_caseD_e5;
  case 0xe6:
    goto switchD_08007540_caseD_e6;
  case 0xe7:
    goto switchD_08007540_caseD_e7;
  case 0xe8:
    goto switchD_08007540_caseD_e8;
  case 0xe9:
    goto switchD_08007540_caseD_e9;
  case 0xea:
    goto switchD_08007540_caseD_ea;
  case 0xeb:
    goto switchD_08007540_caseD_eb;
  case 0xec:
    goto switchD_08007540_caseD_ec;
  case 0xed:
    goto switchD_08007540_caseD_ed;
  case 0xee:
    goto switchD_08007540_caseD_ee;
  case 0xef:
    goto switchD_08007540_caseD_ef;
  case 0xf0:
    goto switchD_08007540_caseD_f0;
  case 0xf1:
    goto switchD_08007540_caseD_f1;
  case 0xf2:
    goto switchD_08007540_caseD_f2;
  case 0xf3:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xf4:
    goto switchD_08007540_caseD_f4;
  case 0xf5:
    goto switchD_08007540_caseD_f5;
  case 0xf6:
    goto switchD_08007540_caseD_f6;
  case 0xf7:
    goto switchD_08007540_caseD_f7;
  case 0xf8:
    goto switchD_08007540_caseD_f8;
  case 0xf9:
    goto switchD_08007540_caseD_f9;
  case 0xfa:
    goto switchD_08007540_caseD_fa;
  case 0xfb:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xfc:
    goto switchD_08007540_caseD_fc;
  case 0xfd:
    goto switchD_08007540_caseD_fd;
  case 0xfe:
    goto switchD_08007540_caseD_fe;
  case 0xff:
    goto switchD_08007540_caseD_ff;
  }
  pbVar6 = param_3;
switchD_08007540_caseD_1f:
  param_1 = param_2;
switchD_08007540_caseD_20:
  FUN_08007a30(param_1,pbVar6,pbVar13);
switchD_08007540_caseD_22:
switchD_08007540_caseD_32:
  param_1 = switchD_08007540::caseD_40;
switchD_08007540_caseD_33:
  param_1 = (byte *)(uint)*param_1;
switchD_08007540_caseD_34:
  bVar11 = param_1 == (byte *)0x2;
switchD_08007540_caseD_35:
  if (bVar11) {
switchD_08007540_caseD_36:
    param_1 = switchD_08007540::caseD_42;
switchD_08007540_caseD_37:
    param_1 = (byte *)(uint)*param_1;
switchD_08007540_caseD_38:
    bVar11 = param_1 == (byte *)0x2f;
switchD_08007540_caseD_39:
    if (bVar11) {
switchD_08007540_caseD_3a:
      param_2 = switchD_08007540::caseD_44;
switchD_08007540_caseD_3b:
      param_1 = &Reserved2;
switchD_08007540_caseD_3c:
      *param_2 = (byte)param_1;
    }
  }
switchD_08007540_caseD_3d:
  return;
}



// ==== 080075d0  caseD_46  (92 bytes, 2 xrefs)

void switchD_08007540::caseD_46(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  
  puVar1 = caseD_76;
  if ((param_2 == 0) && (param_1 == 1)) {
    *caseD_74 = 1;
    puVar3 = caseD_7e;
    puVar2 = caseD_78;
    if (*puVar1 == '\x01') {
      if ((*caseD_7e == '\0') || (*caseD_80 != '\b')) {
        *puVar1 = 0;
        puVar1 = caseD_82;
        *puVar3 = 0;
        *puVar1 = 0;
        *caseD_84 = 1;
        *caseD_7a = 0xd;
      }
      else {
        bVar4 = *caseD_7e - 1;
        *caseD_7e = bVar4;
        caseD_86[bVar4] = 10;
      }
      *puVar2 = 2;
      return;
    }
    *caseD_7a = 0xd;
    puVar1 = caseD_7c;
    *puVar2 = 0;
    *puVar1 = 1;
  }
  return;
}



// ==== 08007654  caseD_88  (518 bytes, 2 xrefs)

void switchD_08007540::caseD_88(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  byte bVar7;
  undefined *puVar8;
  undefined1 uVar9;
  uint uVar10;
  bool bVar11;
  
  puVar4 = PTR_DAT_08007860;
  puVar8 = PTR_DAT_0800785c;
  if ((param_2 != 0) || (param_1 != 1)) {
    return;
  }
  *PTR_DAT_0800785c = 1;
  *puVar4 = 2;
  puVar5 = PTR_DAT_08007868;
  puVar4 = PTR_DAT_08007864;
  uVar10 = (uint)(byte)*PTR_DAT_0800786c;
  if (*PTR_DAT_08007864 == '\0') {
    if (uVar10 != 10) {
      *PTR_DAT_08007880 = *(undefined1 *)(DAT_0800787c + uVar10);
    }
    puVar6 = PTR_DAT_08007884;
    *puVar5 = 0;
    *puVar6 = 0;
    if ((uVar10 == 0x33) || (uVar10 == 0x34)) {
      *puVar6 = 1;
      FUN_08004920();
      *PTR_DAT_08007888 = 0xf;
      *PTR_DAT_0800788c = 0x78;
      *PTR_DAT_08007890 = 0x78;
      *PTR_DAT_08007894 = 1;
    }
    else if (uVar10 == 0xc) {
      if (*(uint *)PTR_DAT_08007898 < 200) {
        *puVar6 = 1;
        FUN_08004920();
        *PTR_DAT_08007888 = 10;
        if ((PTR_DAT_0800789c[(uint)(byte)PTR_DAT_0800789c[9] * 0x44 + 0xec] != '\0') &&
           (PTR_DAT_0800789c[(uint)(byte)PTR_DAT_0800789c[9] * 0x44 + 0xec] != -1)) {
          puVar8 = PTR_DAT_0800789c + (uint)(byte)PTR_DAT_0800789c[9] * 0x44 + 0xec;
          bVar7 = FUN_080029d8();
          if (bVar7 < 0xb) {
            FUN_08002968(PTR_DAT_080078a0,puVar8,bVar7);
            *PTR_DAT_08007874 = bVar7;
          }
        }
        puVar8 = PTR_DAT_08007894;
        *PTR_DAT_0800788c = 0x78;
        *PTR_DAT_08007890 = 0x78;
        *puVar8 = 1;
        *puVar4 = 1;
        return;
      }
      *puVar8 = 2;
      uVar9 = 0xff;
      puVar8 = PTR_DAT_08007860;
      goto LAB_08007856;
    }
    *puVar4 = 1;
  }
  else {
    cVar1 = *PTR_DAT_08007870;
    cVar2 = *PTR_DAT_08007874;
    if ((((uVar10 == 0x37) || (uVar10 == 0xd)) || (uVar10 == 0x36)) || (uVar10 == 0xc)) {
      if (*PTR_DAT_08007868 != '\0') {
        if (*PTR_DAT_08007868 == '\x01') {
          *PTR_DAT_08007868 = 2;
          FUN_0800d15c();
          if (*PTR_DAT_0800786c == '7') {
            FUN_08009534(0,0x10);
            FUN_08009330(1);
            FUN_0800aa8c();
            DataSynchronizationBarrier(0xf);
            *(undefined4 *)(DAT_080078b0 + 0xc) = DAT_080078ac;
            DataSynchronizationBarrier(0xf);
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          *PTR_DAT_08007878 = 1;
          *puVar4 = 0;
          *puVar5 = 0;
        }
        goto switchD_08007540_caseD_b1;
      }
      if ((uVar10 != 0xd) && (uVar10 != 0xc)) {
LAB_080077e4:
        *puVar5 = 1;
        goto switchD_08007540_caseD_b1;
      }
      cVar3 = *PTR_DAT_08007884;
      if (cVar3 == '\0') {
        *PTR_DAT_08007884 = 1;
        FUN_08004920();
        *PTR_DAT_08007888 = 10;
        *PTR_DAT_0800788c = 0x78;
        *PTR_DAT_08007890 = 0x78;
        *PTR_DAT_08007894 = 1;
        goto switchD_08007540_caseD_b1;
      }
      *PTR_DAT_08007884 = 0;
      puVar8 = PTR_DAT_08007870;
      if (cVar1 != -1) {
        *PTR_DAT_08007874 = cVar2 + '\x01';
        *puVar8 = 0xff;
      }
      if (*PTR_DAT_08007874 == '\0') {
        *PTR_DAT_080078a8 = 0;
      }
      else {
        FUN_08002968(PTR_DAT_080078a4,PTR_DAT_080078a0,*PTR_DAT_08007874,cVar3,param_4);
        PTR_DAT_080078a4[(byte)*PTR_DAT_08007874] = 0;
        *PTR_DAT_080078a8 = 1;
      }
      if (*PTR_DAT_0800786c != '\f') goto LAB_080077e4;
      *PTR_DAT_08007878 = 1;
      *puVar4 = 0;
LAB_080077ee:
      uVar9 = 0x10;
    }
    else {
      bVar11 = uVar10 == 0x33;
      do {
        if (bVar11) {
          *PTR_DAT_08007884 = 0;
          puVar8 = PTR_DAT_08007870;
          if (cVar1 != -1) {
            *PTR_DAT_08007874 = cVar2 + '\x01';
            *puVar8 = 0xff;
          }
          PTR_DAT_080078a0[(byte)*PTR_DAT_08007874] = 0;
          FUN_0800a864(uVar10 - 0x33 & 0xff,PTR_DAT_080078a0);
          *puVar4 = 0;
          goto switchD_08007540_caseD_b1;
        }
        bVar11 = true;
      } while (uVar10 == 0x34);
      *PTR_DAT_08007878 = 1;
      *puVar4 = 0;
switchD_08007540_caseD_b1:
      if (*PTR_DAT_0800786c != '\n') goto LAB_080077ee;
      if (*(int *)PTR_DAT_08007898 == 0) {
        uVar9 = 0x23;
      }
      else {
        uVar9 = 0x24;
      }
    }
    *PTR_DAT_08007880 = uVar9;
  }
  uVar9 = 0;
  puVar8 = PTR_DAT_08007874;
LAB_08007856:
  *puVar8 = uVar9;
  return;
}



// ==== 080078b4  FUN_080078b4  (336 bytes, 1 xrefs)

void FUN_080078b4(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 uVar4;
  int iVar5;
  char cVar6;
  undefined *puVar7;
  uint uVar8;
  int local_20;
  uint local_1c;
  undefined4 uStack_18;
  
  uVar8 = 0;
  if (param_3 != 0) {
    return;
  }
  if (param_2 != 1) {
    return;
  }
  *PTR_DAT_08007a04 = 1;
  local_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  FUN_08005198(param_1);
  *PTR_DAT_08007a08 = 2;
  puVar3 = PTR_DAT_08007a18;
  puVar2 = PTR_DAT_08007a14;
  puVar7 = PTR_DAT_08007a10;
  if (*PTR_DAT_08007a0c == '\0') {
    if (*PTR_DAT_08007a18 == '\x01') {
      uVar8 = (uint)(byte)*PTR_DAT_08007a10;
LAB_08007924:
      if ((uVar8 != 0) && (uVar8 <= (byte)*PTR_DAT_08007a1c)) {
        *puVar2 = (char)uVar8 + -1;
        uVar4 = 1;
        puVar7 = PTR_DAT_08007a20;
        goto LAB_0800793e;
      }
    }
    else if (*PTR_DAT_08007a18 == '\x02') {
      *PTR_DAT_08007a18 = 0;
      uVar8 = (uint)(byte)*puVar7 * 10 + (uint)(byte)puVar7[1];
      goto LAB_08007924;
    }
    *puVar3 = 0;
  }
  else {
    cVar6 = *PTR_DAT_08007a14;
    uVar4 = (undefined1)param_1;
    if (cVar6 == '\b') {
      if (5 < (byte)*PTR_DAT_08007a18) {
        *PTR_DAT_08007a18 = 0;
        FUN_08004d78(PTR_DAT_08007a10,&local_20);
        puVar7 = PTR_DAT_08007a28;
        *PTR_DAT_08007a24 = uVar4;
        local_20 = local_20 + 0x4b;
        uVar8 = FUN_08003d08(local_20,*(undefined2 *)(*(int *)puVar7 + 0x1c),0);
LAB_0800799a:
        *(uint *)PTR_DAT_08007a2c = uVar8;
        return;
      }
LAB_0800796c:
      *PTR_DAT_08007a24 = uVar4;
      return;
    }
    if (((cVar6 == '\r') || (cVar6 == '6')) || (cVar6 == '\x1e')) {
      if ((byte)*PTR_DAT_08007a18 < 3) goto LAB_0800796c;
      *PTR_DAT_08007a18 = 0;
      uVar8 = ((uint)(byte)*puVar7 * 100 + (uint)(byte)puVar7[1] * 10 + (uint)(byte)puVar7[2]) - 1;
      if (uVar8 < 200) {
        *PTR_DAT_08007a24 = uVar4;
        goto LAB_0800799a;
      }
    }
    else {
      iVar5 = FUN_08005408(cVar6,&uStack_18,&local_1c);
      if (iVar5 == 0) {
        local_1c = local_1c & 0xff;
        if (local_1c < 100) {
          if (local_1c < 10) {
            cVar6 = '\x01';
          }
          else {
            cVar6 = '\x02';
          }
        }
        else {
          cVar6 = '\x03';
        }
        cVar1 = *PTR_DAT_08007a18;
        if (cVar1 == '\x01') {
          uVar8 = (uint)(byte)*puVar7;
        }
        else if (cVar1 == '\x02') {
          uVar8 = (uint)(byte)*puVar7 * 10 + (uint)(byte)puVar7[1];
        }
        else if (cVar1 == '\x03') {
          uVar8 = (uint)(ushort)((ushort)(byte)*puVar7 * 100 + (ushort)(byte)puVar7[1] * 10 +
                                (ushort)(byte)puVar7[2]);
        }
        if (cVar6 == cVar1) {
          *PTR_DAT_08007a18 = 0;
        }
        if (uVar8 <= local_1c) {
          *(uint *)PTR_DAT_08007a2c = uVar8;
          return;
        }
      }
      else {
        *PTR_DAT_08007a18 = 0;
      }
    }
  }
  uVar4 = 2;
  puVar7 = PTR_DAT_08007a04;
LAB_0800793e:
  *puVar7 = uVar4;
  return;
}



// ==== 08007a30  FUN_08007a30  (154 bytes, 1 xrefs)

void FUN_08007a30(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 uVar4;
  int iVar5;
  
  puVar2 = PTR_DAT_08007ae0;
  if (param_2 == 0) {
    if (param_1 != 1) {
      return;
    }
    *PTR_DAT_08007adc = 1;
    *puVar2 = 0;
  }
  else if (param_1 != 1) {
    return;
  }
  puVar3 = PTR_DAT_08007ad4;
  puVar2 = PTR_DAT_08007ad0;
  cVar1 = *PTR_DAT_08007ad0;
  if (*PTR_DAT_08007acc == '\0') {
    uVar4 = FUN_08004284(cVar1,param_3,0,*PTR_DAT_08007ae4 + -1);
    *puVar2 = uVar4;
    *PTR_DAT_08007ae8 = 1;
    goto LAB_08007a60;
  }
  if (cVar1 == '\b') {
    iVar5 = param_3 * (uint)*(ushort *)(*(int *)PTR_DAT_08007aec + 0x1c) + *(int *)PTR_DAT_08007ad4;
    if (iVar5 < DAT_08007af0) {
      if (iVar5 < 0) {
        iVar5 = DAT_08007af0;
      }
    }
    else {
      iVar5 = 0;
    }
    iVar5 = FUN_08003d08(iVar5,(uint)*(ushort *)(*(int *)PTR_DAT_08007aec + 0x1c),0);
  }
  else {
    if ((cVar1 != '6') && (cVar1 != '\x1e')) {
      FUN_08004200(param_3);
      goto LAB_08007a60;
    }
    iVar5 = FUN_08004f10(*(int *)PTR_DAT_08007ad4 + param_3 & 0xff,param_3,0);
    if (iVar5 == 0xff) goto LAB_08007a60;
  }
  *(int *)puVar3 = iVar5;
LAB_08007a60:
  *PTR_DAT_08007ad8 = 2;
  return;
}



// ==== 08007af4  FUN_08007af4  (144 bytes, 1 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x08007ba0

// ==== 08007be8  FUN_08007be8  (158 bytes, 3 xrefs)

void FUN_08007be8(int param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  
  puVar2 = DAT_08007c94;
  puVar4 = DAT_08007c8c;
  if (*DAT_08007c88 != '\0') {
    if ((param_2 == 0) && (param_1 == 1)) {
      *DAT_08007c8c = 2;
    }
    return;
  }
  cVar1 = *DAT_08007c90;
  if ((param_2 == 0) && (param_1 == 1)) {
    *DAT_08007c8c = 1;
    if (cVar1 != '\x01') {
      return;
    }
    if (*DAT_08007ca0 == '\0') {
      return;
    }
    *puVar4 = 2;
    puVar4 = DAT_08007ca4;
  }
  else if (param_2 == 0 && param_1 == 0) {
    if (((*DAT_08007ca8 == '\x01') || (cVar1 != '\0')) && (cVar1 != '\x01')) {
      return;
    }
    cVar1 = *DAT_08007cac;
    *DAT_08007cac = cVar1 == '\0';
    if (cVar1 == '\0') {
      uVar3 = 0x2b;
    }
    else {
      uVar3 = 0xd;
    }
    *puVar2 = uVar3;
    puVar4 = DAT_08007cb0;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    if (param_1 != 1) {
      return;
    }
    if (*(char *)(DAT_08007c98 + 0x12) == '\x01') {
      *(undefined1 *)(DAT_08007c98 + 0x12) = 0;
      uVar3 = 0x27;
    }
    else {
      *(undefined1 *)(DAT_08007c98 + 0x12) = 1;
      uVar3 = 0x1a;
    }
    *puVar2 = uVar3;
    puVar4 = DAT_08007c9c;
  }
  *puVar4 = 1;
  return;
}



// ==== 08007cb4  FUN_08007cb4  (808 bytes, 1 xrefs)

void FUN_08007cb4(undefined4 param_1,uint param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  byte *pbVar4;
  char *pcVar5;
  char *pcVar6;
  short *psVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  uint local_20;
  int local_1c;
  undefined4 uStack_18;
  
  pbVar4 = DAT_08007fdc;
  *(short *)DAT_08007fdc = *(short *)DAT_08007fdc + 1;
  local_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  iVar10 = FUN_0801072c();
  if (iVar10 == 1) {
    FUN_08003bc8(0);
  }
  pcVar5 = DAT_08007fe4;
  if (*DAT_08007fe0 == '\x01') {
    return;
  }
  if (((*DAT_08007fe4 == '\x05') && (*DAT_08007fe8 != '\0')) || (FUN_080054d4(), *pcVar5 != '\x01'))
  {
    pcVar6 = DAT_08007fec;
    if (*DAT_08007fec == '\x01') {
      FUN_0800da58();
      *pcVar6 = '\0';
    }
    pcVar6 = DAT_08007ff0;
    if (*DAT_08007ff0 == '\x01') {
      FUN_0800c2d4();
      *pcVar6 = '\0';
    }
  }
  if (*DAT_08007ff4 == '\x01') {
    return;
  }
  if (*DAT_08007ff8 != '\0') {
    return;
  }
  if ((*DAT_08007ffc == '\x02') && ((*pbVar4 & 0xf) == 0)) {
    *(uint *)(PTR_GPIOC_08008000 + 0x14) = *(uint *)(PTR_GPIOC_08008000 + 0x14) ^ 0x2000;
  }
  if (*DAT_08008004 != 0) {
    *DAT_08008004 = *DAT_08008004 + -1;
  }
  if (*DAT_08008008 != 0) {
    *DAT_08008008 = *DAT_08008008 + -1;
  }
  pbVar4 = DAT_08008014;
  psVar7 = DAT_08008010;
  if (*pcVar5 == '\x01') {
    if ((*DAT_0800800c == '\x01') || (*DAT_0800800c == '\x02')) {
      *DAT_08008010 = *DAT_08008010 + 1;
      bVar1 = *pbVar4;
      *pbVar4 = bVar1 + 1;
      uVar11 = (uint)(byte)(bVar1 + 1) * 0x19 + 500;
      local_20 = CONCAT22(local_20._2_2_,(short)uVar11);
      if (DAT_08008018 < uVar11) {
        local_20 = CONCAT22(local_20._2_2_,500);
        *pbVar4 = 0;
      }
      FUN_0800e014(local_20 & 0xffff);
      pcVar5 = DAT_0800800c;
      if ((*(char *)(DAT_0800801c + 0x19) == '\x01') && (*psVar7 == 0x200)) {
        *psVar7 = 0;
        if (*pcVar5 == '\x01') {
          *pcVar5 = '\x02';
          FUN_0800a980();
          FUN_0800ea98(0);
          FUN_0800e660(1,0);
          FUN_0800ec04();
          FUN_0800e660(6,0);
          FUN_0800c2d4();
        }
        else {
          *pcVar5 = '\x01';
          FUN_0800c2d4();
          FUN_0800e660(6,1);
          FUN_08004bc4();
          FUN_0800dfb0(1,500);
          FUN_080123ae(2);
          DAT_50000018 = 0x100;
          *DAT_08008020 = 1;
          *pbVar4 = 0;
        }
      }
    }
    cVar2 = *DAT_08008024;
    if ((cVar2 != '\0') && (*DAT_08008024 = cVar2 + -1, cVar2 == '\x01')) {
      FUN_0800b2fc(0);
      *DAT_08007ff0 = '\x01';
    }
  }
  if (((*DAT_08008028 == '\x01') && (sVar3 = *DAT_0800802c, sVar3 != 0)) &&
     (*DAT_0800802c = sVar3 + -1, sVar3 == 1)) {
    FUN_08009074();
    FUN_0800b26c(1);
  }
  pbVar8 = DAT_08008040;
  pbVar4 = DAT_0800803c;
  if (*DAT_08008030 != '\x03') goto LAB_08007f74;
  if (*DAT_08008034 != '\0') {
    *DAT_08008034 = *DAT_08008034 + -1;
    goto LAB_08007fa6;
  }
  if (*DAT_08008038 != '\0') goto LAB_08007fa6;
  if (*DAT_0800803c == 0) {
    iVar10 = FUN_0800de90(&local_1c);
    if (iVar10 == 1) {
      iVar10 = *DAT_08008044;
      *DAT_08008044 = local_1c;
      iVar10 = local_1c - iVar10;
      if (iVar10 < 0) {
        iVar10 = -iVar10;
      }
      if (iVar10 < 100) {
        *pbVar8 = *pbVar8 + 1;
      }
      else {
        *pbVar8 = 0;
      }
      FUN_0800e06c();
      if (*pbVar8 < 3) {
        FUN_0800e050();
      }
      else {
        FUN_0800e038(*DAT_08008044);
        *DAT_08008048 = 0xff;
        *DAT_0800804c = -1;
        puVar9 = DAT_08008050;
        *pbVar8 = 0;
        *puVar9 = 0;
        *DAT_08008054 = 0;
        *pbVar4 = 1;
        FUN_0800b26c(3);
      }
LAB_08007ee0:
      *DAT_08008034 = '\x15';
    }
  }
  else {
    if (*DAT_0800803c != 1) goto LAB_08007fa6;
    iVar10 = FUN_0800de3c(&local_1c,&local_20);
    if (iVar10 == 0) goto LAB_08007f74;
    FUN_0800e060();
    if (iVar10 == 2) {
      iVar10 = FUN_08004368(local_1c);
      if (iVar10 == 0xff) goto LAB_08007f44;
      *DAT_08008048 = (byte)iVar10;
      *DAT_0800804c = '\x02';
      *DAT_0800803c = 2;
      *DAT_08008050 = 1;
    }
    else {
      if ((iVar10 == 1) &&
         (uVar11 = FUN_08004334(local_20 & 0xffff), pbVar4 = DAT_08008048, uVar11 != 0xff)) {
        if ((uVar11 == *DAT_08008048) && (*DAT_0800804c == '\x01')) {
          bVar1 = *pbVar8;
          *pbVar8 = bVar1 + 1;
          if (1 < (byte)(bVar1 + 1)) {
            *DAT_0800803c = 2;
            *DAT_08008050 = 1;
          }
        }
        else {
          *pbVar8 = 0;
        }
        *DAT_0800804c = '\x01';
        *pbVar4 = (byte)uVar11;
      }
LAB_08007f44:
      if (*DAT_0800803c < 2) {
        FUN_0800e038(*DAT_08008044);
        goto LAB_08007ee0;
      }
    }
    FUN_0800b26c(3);
  }
LAB_08007f74:
  if (((*DAT_08008030 == '\x04') && (*DAT_08008058 == '\x01')) &&
     ((*DAT_0800805c == '\x01' &&
      ((cVar2 = *DAT_08008060, cVar2 != '\0' && (*DAT_08008060 = cVar2 + -1, cVar2 == '\x01')))))) {
    FUN_08003d1c();
    FUN_0800c2d4();
  }
LAB_08007fa6:
  if (((*DAT_08008064 == '\x01') && (cVar2 = *DAT_08008068, cVar2 != '\0')) &&
     (*DAT_08008068 = cVar2 + -1, cVar2 == '\x01')) {
    *DAT_0800806c = *DAT_0800806c + '\x01';
    puVar9 = DAT_08008074;
    *DAT_08008070 = 0;
    *puVar9 = 0xff;
    *DAT_08007ff0 = '\x01';
  }
  FUN_08005d10();
  return;
}



// ==== 08008078  FUN_08008078  (882 bytes, 1 xrefs)

void FUN_08008078(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  byte *pbVar7;
  char *pcVar8;
  byte bVar9;
  undefined2 uVar10;
  undefined4 uVar11;
  int extraout_r1;
  
  if (*DAT_080083ec == '\0') {
    FUN_0800fda4(0xf0);
  }
  puVar5 = DAT_080083f4;
  cVar1 = *DAT_080083f0;
  if ((cVar1 != '\0') && (*DAT_080083f0 = cVar1 + -1, cVar1 == '\x01')) {
    *puVar5 = 1;
  }
  pcVar6 = DAT_0800840c;
  if (*DAT_080083f8 == '\x01') {
    return;
  }
  if (*DAT_080083fc != '\0') {
    *DAT_080083fc = *DAT_080083fc + -1;
    return;
  }
  if (*DAT_08008400 == '\x01') {
    FUN_0800dcfc(DAT_08008414,DAT_08008410);
    if ((*DAT_08008410 < 0x1f5) && (*DAT_08008414 <= *(ushort *)(DAT_08008418 + 6))) {
      return;
    }
    DataSynchronizationBarrier(0xf);
    *(undefined4 *)(DAT_08008420 + 0xc) = DAT_0800841c;
    DataSynchronizationBarrier(0xf);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar4 = *DAT_08008404;
  *DAT_08008404 = uVar4 + 1;
  *DAT_08008408 = *DAT_08008408 + 1;
  if (*pcVar6 != '\x01') {
    if ((uVar4 + 1 & 1) == 0) {
      FUN_0800dcfc((uint)*DAT_08008424 * 2 + DAT_08008428,DAT_08008410);
      pbVar7 = DAT_08008424;
      bVar9 = *DAT_08008424;
      *DAT_08008424 = bVar9 + 1;
      if (3 < (byte)(bVar9 + 1)) {
        *pbVar7 = 0;
      }
      FUN_08003e70(1);
    }
    if (*pcVar6 != '\x05') {
      uVar10 = FUN_0800e616();
      *DAT_0800842c = uVar10;
      FUN_08004164();
      if (*pcVar6 == '\x01') goto LAB_08008254;
    }
    if ((*DAT_08008430 == '\0') || (*DAT_08008434 == '\x01')) {
      cVar1 = *DAT_08008438;
      if ((cVar1 != '\0') && (*DAT_08008438 = cVar1 + -1, cVar1 == '\x01')) {
        *(undefined4 *)(PTR_GPIOF_0800843c + 0x28) = 0x100;
      }
      if (((*DAT_08008440 == '\0') && (cVar1 = *DAT_08008444, cVar1 != '\x04')) &&
         ((cVar1 != '\x03' || (1 < *DAT_08008448)))) {
        if (((*(char *)(DAT_0800844c + 0x18) == '\x01') && (cVar2 = *DAT_08008450, cVar2 != '\0'))
           && (*DAT_08008454 == '\0')) {
          *DAT_08008450 = cVar2 + -1;
          if (cVar2 == '\x01') {
            *(undefined1 *)(DAT_0800844c + -0xe) = 1;
          }
          *DAT_08008458 = 1;
        }
        cVar2 = *DAT_0800845c;
        if ((cVar2 != '\0') && (*DAT_0800845c = cVar2 + -1, cVar2 == '\x01')) {
          if ((*DAT_08008460 != '\0') || ((*DAT_08008454 == '\x01' || (cVar1 == '\x02')))) {
            FUN_080091ac(2);
          }
          if (*DAT_08008444 == '\x03') {
            FUN_0800b260();
            FUN_08009938(0,2);
            FUN_08009938(1,2);
            FUN_080049a8(1);
          }
          *DAT_08008464 = 0;
          *DAT_08008458 = 1;
          *DAT_08008460 = '\0';
          *DAT_08008454 = '\0';
          *DAT_08008468 = 0;
          *DAT_08008434 = '\0';
          *DAT_0800846c = 0;
          if ((((*DAT_08008470 == '\x01') && (cVar1 = *pcVar6, cVar1 != '\x04')) &&
              (cVar1 != '\x02')) && (cVar1 != '\x01')) {
            uVar11 = 1;
          }
          else {
            uVar11 = 0;
          }
          FUN_0800b26c(uVar11);
        }
      }
    }
  }
LAB_08008254:
  if (((*DAT_08008474 != '\x01') && (cVar1 = *DAT_08008478, cVar1 != '\0')) &&
     (*DAT_08008478 = cVar1 + -1, cVar1 == '\x01')) {
    FUN_0800bea4();
    cVar1 = *pcVar6;
    if (((cVar1 != '\x04') && (cVar1 != '\x01')) && ((cVar1 != '\x02' && (*DAT_08008470 == '\x01')))
       ) {
      FUN_08009074();
      FUN_0800b26c(1);
    }
  }
  if (*DAT_0800847c == '\x01') {
    uVar4 = *DAT_08008480;
    *DAT_08008480 = uVar4 + 1;
    *DAT_08008484 = (byte)(uVar4 + 1) & 1;
    FUN_0800be44();
    pcVar8 = DAT_08008488;
    if (*pcVar6 != '\x01') {
      if (*DAT_08008480 < 0x1e) {
        if ((*DAT_08008480 == 0x1d) && (*DAT_08008488 == '\0')) {
          FUN_080091ac(4);
        }
      }
      else {
        *DAT_08008480 = 0;
        if (*pcVar8 == '\0') {
          FUN_080091ac(4);
          FUN_08009534(0,0x1b);
          if (*DAT_0800848c == '\0') {
            FUN_08009330(1);
            *DAT_08008400 = '\x01';
            FUN_0800fda4(0);
            FUN_0800b2fc(5);
            *(undefined4 *)(PTR_GPIOF_0800843c + 0x28) = 0x100;
          }
          else {
            FUN_08009330(0);
          }
        }
      }
    }
  }
  pbVar7 = DAT_08008448;
  if (((*DAT_08008444 == '\x03') && (*DAT_08008490 == '\0')) && (bVar9 = *DAT_08008448, bVar9 < 2))
  {
    bVar3 = *DAT_08008494;
    *DAT_08008494 = bVar3 + 1;
    if (0x20 < (byte)(bVar3 + 1)) {
      if ((bVar9 == 1) && (*DAT_08008498 == '\0')) {
        bVar9 = 2;
      }
      else {
        bVar9 = 3;
      }
      *pbVar7 = bVar9;
    }
    *puVar5 = 1;
  }
  pcVar8 = DAT_0800849c;
  if (((*DAT_0800849c != '\0') && (*pcVar6 != '\x01')) && (*pcVar6 != '\x04')) {
    cVar1 = *DAT_080084a0;
    if ((cVar1 != '\0') && (*DAT_080084a0 = cVar1 + -1, cVar1 == '\x01')) {
      *pcVar8 = '\0';
      *puVar5 = 1;
    }
    pcVar6 = DAT_080084a8;
    if ((*DAT_080084a4 == '\x01') && (cVar1 = *DAT_080084a8, cVar1 != '\0')) {
      *DAT_080084a8 = cVar1 + -1;
      FUN_080028f0(cVar1 + -1,3);
      if (extraout_r1 == 0) {
        FUN_080091ac(3);
      }
      if (*pcVar6 == '\0') {
        *DAT_080084a4 = '\0';
      }
    }
  }
  pcVar6 = DAT_080084ac;
  if (((*DAT_080084ac != '\0') && (cVar1 = *DAT_080084b0, cVar1 != '\0')) &&
     (*DAT_080084b0 = cVar1 + -1, cVar1 == '\x01')) {
    *pcVar6 = '\0';
    *puVar5 = 1;
  }
  cVar1 = *DAT_080084b4;
  if ((cVar1 == '\0') || (*DAT_080084b4 = cVar1 + -1, cVar1 != '\x01')) {
    return;
  }
  *DAT_080084b8 = 0;
  FUN_0800299a(DAT_080084bc,0x10);
  return;
}



// ==== 080084c0  FUN_080084c0  (722 bytes, 1 xrefs)

void FUN_080084c0(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined2 *puVar6;
  char *pcVar7;
  char *pcVar8;
  ushort *puVar9;
  undefined2 uVar10;
  int iVar11;
  
  pcVar2 = DAT_08008794;
  if (*DAT_08008794 != '\0') {
    FUN_08009590();
  }
  pcVar3 = DAT_08008798;
  if ((*DAT_08008798 == '\x01') && (*DAT_0800879c == '\x01')) {
    *DAT_0800879c = '\0';
    *DAT_080087a0 = 1;
    FUN_0800b73c();
    FUN_080091ac(4);
    FUN_0800bea4(4);
    FUN_0800c2d4();
  }
  iVar11 = FUN_08010a48();
  if (iVar11 == 1) {
    FUN_08003bc8();
  }
  if (*DAT_080087a4 == '\x01') {
    return;
  }
  if (*pcVar3 != '\x01') {
    FUN_08008820();
  }
  pcVar4 = DAT_080087b4;
  if (*DAT_080087a8 == '\x01') {
    return;
  }
  if (*DAT_080087ac != '\0') {
    return;
  }
  if ((((*DAT_080087b0 == '\x03') || (*DAT_080087b4 == '\0')) || (*DAT_080087b8 != '\x01')) ||
     ((*DAT_080087bc == '\x01' || (*pcVar2 != '\0')))) goto LAB_08008584;
  if (*DAT_080087c0 - 200 < 7) {
    if (*pcVar3 == '\x03') {
LAB_0800858e:
      FUN_0800a36c(4);
    }
    else {
      FUN_0800bce0();
    }
  }
  else {
    if ((*DAT_080087c4 == '\0') && (*pcVar3 == '\x03')) goto LAB_0800858e;
    FUN_0800b874();
  }
  *DAT_080087c8 = 0;
  *DAT_080087cc = 0;
  *DAT_080087b8 = '\0';
LAB_08008584:
  if ((((DAT_080087d0[0x1a] == 0) && (*DAT_080087d4 == '\x01')) && (*DAT_080087d8 == '\x01')) &&
     (*pcVar2 == '\0')) {
    FUN_0800bd2c();
    FUN_080049a8(0);
    puVar6 = DAT_080087dc;
    *DAT_080087d8 = '\0';
    *puVar6 = 7;
  }
  if ((((*DAT_080087b0 != '\x03') && (DAT_080087d0[0x1a] != 0)) &&
      ((*DAT_080087e0 == '\x01' && ((*pcVar2 == '\0' && (*pcVar4 == '\0')))))) &&
     ((*DAT_080087bc != '\x01' &&
      (((*DAT_080087e4 == '\0' && (*DAT_080087e8 == '\0')) && (*pcVar3 != '\x05')))))) {
    FUN_0800b964();
    if ((*DAT_080087ec == '\x01') && (*DAT_080087b0 == '\0')) {
      FUN_0800b26c();
    }
    *DAT_080087ec = '\0';
    *DAT_080087c8 = 0;
    *DAT_080087cc = 0;
    *DAT_080087e0 = '\0';
  }
  if (((*DAT_080087f0 != '\0') && (*DAT_080087f4 == '\x01')) &&
     ((cVar1 = *pcVar3, cVar1 != '\x02' && ((cVar1 != '\x04' && (cVar1 != '\x01')))))) {
    FUN_0800bc40();
    *DAT_080087f4 = '\0';
  }
  if (DAT_080087d0[0x13] == 1) {
    FUN_0800bd44();
  }
  if (*DAT_080087f8 == '\x01') {
    if (((((((DAT_080087d0[0x1c] == 0) || (*pcVar4 != '\0')) || (*DAT_080087e4 != '\0')) ||
          ((*DAT_080087bc == '\x01' || (*DAT_080087b0 != '\0')))) || (*DAT_080087fc != '\0')) ||
        (*DAT_080087e8 != '\0')) ||
       (((0xce < *DAT_080087d0 || (0xce < DAT_080087d0[1])) && (*DAT_080087d4 == '\x01')))) {
      *DAT_08008800 = 1000;
    }
    else {
      FUN_0800b2fc(5);
    }
    *DAT_080087f8 = '\0';
  }
  pcVar8 = DAT_0800880c;
  pcVar7 = DAT_08008808;
  if (((*DAT_08008804 == '\x01') && (*pcVar3 == '\x05')) && (*pcVar2 == '\0')) {
    if (*DAT_08008808 == '\x01') {
      FUN_0800b750();
      pbVar5 = DAT_080087d0;
      if (DAT_080087d0[0x13] == 1) {
        FUN_0800e444(*(undefined2 *)(DAT_080087d0 + 0x28),*(undefined2 *)(DAT_080087d0 + 0x2a));
      }
      if ((pbVar5[0x1a] != 0) && (*pcVar4 == '\0')) {
        FUN_0800b964();
        *DAT_0800880c = '\0';
      }
      FUN_0800a2b8();
      *DAT_08008810 = 10;
      *pcVar7 = '\0';
    }
    else if (((DAT_080087d0[0x1a] == 0) || (*pcVar4 != '\0')) || (*DAT_0800880c != '\0')) {
      uVar10 = FUN_0800e616();
      *DAT_08008814 = uVar10;
      FUN_08004164();
      *DAT_08008810 = (ushort)DAT_080087d0[0x1c] * 10;
      *pcVar7 = '\x01';
      FUN_0800e502();
      FUN_0800eb00();
      FUN_0800e660(0);
      puVar9 = DAT_08008818;
      if (0x78 < *DAT_08008818) {
        iVar11 = FUN_08004428();
        *DAT_0800881c = (char)iVar11;
        *DAT_080087a8 = iVar11 == 0;
        *puVar9 = 0;
      }
    }
    else {
      FUN_0800b964();
      *pcVar8 = '\x01';
      *DAT_08008810 = 10;
    }
    *DAT_08008804 = '\0';
  }
  return;
}



// ==== 08008820  FUN_08008820  (48 bytes, 1 xrefs)

void FUN_08008820(void)

{
  char cVar1;
  
  cVar1 = *DAT_08008850;
  if (cVar1 == '\0') {
LAB_08008844:
    FUN_08008858();
    return;
  }
  if (cVar1 == '\x05') {
    if (*DAT_08008854 == '\0') goto LAB_08008844;
  }
  else {
    if (cVar1 == '\x03') {
      FUN_080088e0();
      return;
    }
    if (cVar1 == '\x04') {
      FUN_080089e0();
    }
  }
  return;
}



// ==== 08008858  FUN_08008858  (92 bytes, 1 xrefs)

void FUN_08008858(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  pcVar1 = DAT_080088bc;
  if (*DAT_080088b4 != '\x01') {
    return;
  }
  if (*DAT_080088b8 == '\0') {
    if (*(char *)(DAT_080088c0 + 0x1a) == '\0') {
      if (*DAT_080088cc == '\x01') {
        *DAT_080088d0 = 0x1e;
        *DAT_080088d4 = 0;
      }
      goto LAB_080088ac;
    }
    if (*DAT_080088bc != '\0') goto LAB_080088ac;
    *DAT_080088c4 = 100;
    puVar2 = DAT_080088c8;
  }
  else {
    if (*DAT_080088bc != '\0') goto LAB_080088ac;
    *DAT_080088d8 = 0x1e;
    puVar2 = DAT_080088dc;
  }
  *puVar2 = 0;
  *pcVar1 = '\x01';
LAB_080088ac:
  FUN_0800b2fc(3);
  return;
}



// ==== 080088e0  FUN_080088e0  (190 bytes, 1 xrefs)

void FUN_080088e0(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  char *pcVar4;
  bool bVar5;
  
  piVar3 = DAT_080089b0;
  pcVar2 = DAT_080089a4;
  if (*DAT_080089a0 == '\0') {
    FUN_0800b2fc(0);
    *DAT_080089ac = 1;
    return;
  }
  cVar1 = *DAT_080089a8;
  bVar5 = *DAT_080089a4 == '\0' && cVar1 == '\0';
  if ((0xce < *(byte *)(*DAT_080089b0 + 0x1e)) && (*DAT_080089b4 != 0)) {
    bVar5 = true;
    *DAT_080089b4 = 0;
  }
  if ((*DAT_080089b8 == '\x01') && (cVar1 == '\x01')) {
    bVar5 = true;
    *DAT_080089bc = 0;
  }
  if (((*DAT_080089c0 == '\x01') && (*DAT_080089c4 == '\x01')) &&
     ((cVar1 == '\x02' || (cVar1 == '\x03')))) {
    *DAT_080089c8 = 0;
  }
  else if (!bVar5) {
    return;
  }
  FUN_0800b9ec();
  pcVar4 = DAT_080089d4;
  if ((*pcVar2 == '\0') &&
     (((*(char *)(*piVar3 + 0x2f) == '\x01' || (*DAT_080089cc == '\x01')) && (*DAT_080089d0 == '\0')
      ))) {
    if (*DAT_080089d4 == '\x01') {
      *DAT_080089d8 = 500;
      *DAT_080089dc = 0;
      *pcVar4 = '\x02';
      return;
    }
  }
  else {
    FUN_0800a36c(4);
  }
  return;
}



// ==== 080089e0  FUN_080089e0  (360 bytes, 1 xrefs)

void FUN_080089e0(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined2 *puVar6;
  int iVar7;
  char *pcVar8;
  
  pcVar5 = DAT_08008b74;
  pcVar4 = DAT_08008b68;
  pcVar3 = DAT_08008b60;
  iVar7 = 0;
  if (*DAT_08008b48 == '\x01') goto LAB_08008b04;
  if ((*DAT_08008b4c != '\0') && (*DAT_08008b54 - 200 < 7)) {
    if (*DAT_08008b50 != '\0') {
      return;
    }
    goto LAB_08008b04;
  }
  cVar1 = *DAT_08008b58;
  if (cVar1 == '\x01') {
    if (*DAT_08008b5c == '\x01') {
      pcVar8 = DAT_08008b64;
      goto LAB_08008a38;
    }
  }
  else if (((cVar1 == '\x02') || (cVar1 == '\x03')) && (*DAT_08008b60 == '\x01')) {
    pcVar8 = DAT_08008b68;
LAB_08008a38:
    if (*pcVar8 == '\0') {
      *DAT_08008b5c = '\0';
      *pcVar3 = '\0';
      goto LAB_08008b04;
    }
  }
  if (*DAT_08008b50 == '\0') {
    iVar7 = 1;
  }
  else if ((*DAT_08008b6c == '\0') && (*(byte *)(*DAT_08008b70 + 0x1e) < 0xcf)) {
    cVar2 = *DAT_08008b74;
    if (cVar1 == '\x01') {
      if (cVar2 == '\x01') {
        *DAT_08008b5c = '\0';
      }
      else if (*DAT_08008b5c == '\0') {
        *DAT_08008b5c = '\x01';
        *DAT_08008b64 = 'd';
      }
      if (*DAT_08008b78 == '\x01') {
        iVar7 = 2;
        *DAT_08008b78 = '\0';
      }
    }
    else if (cVar1 == '\0') {
      if (*(char *)(DAT_08008b7c + 0x10) != '\0') goto LAB_08008acc;
    }
    else if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
      if ((*DAT_08008b80 == '\x01') && (*DAT_08008b84 == '\x01')) {
        *DAT_08008b60 = '\0';
      }
      else if (*DAT_08008b60 == '\0') {
        *DAT_08008b60 = '\x01';
        *pcVar4 = 'd';
      }
LAB_08008acc:
      if (cVar2 == '\x01') {
        iVar7 = 2;
        *pcVar5 = '\0';
      }
    }
  }
  *DAT_08008b88 = 0;
  puVar6 = DAT_08008b90;
  if (iVar7 != 1) {
    if ((iVar7 == 2) && (*(char *)(DAT_08008b7c + 0x18) == '\x01')) {
      DAT_50000028 = 0x100;
      *DAT_08008b8c = 0;
      *puVar6 = 0x14;
      *DAT_08008b48 = '\0';
      *DAT_08008b6c = '\x01';
      return;
    }
    return;
  }
LAB_08008b04:
  FUN_080049a8(1);
  if (0xce < *(byte *)(*DAT_08008b70 + 0x1e)) {
    *DAT_08008b94 = 800;
  }
  *DAT_08008b98 = 1;
  if (*DAT_08008b4c != '\0') {
    if (*(char *)(DAT_08008b7c + 0x1e) == '\x01') {
      *DAT_08008b9c = 0x168;
      *DAT_08008ba0 = 0;
      return;
    }
    if (*(char *)(DAT_08008b7c + 0x1e) == '\x02') {
      FUN_0800b168();
      return;
    }
  }
  return;
}



// ==== 08008ba4  FUN_08008ba4  (134 bytes, 1 xrefs)

void FUN_08008ba4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = DAT_08008c40;
  if (param_1 == 1) {
    *DAT_08008c2c = 0x38;
    *DAT_08008c34 = (uint)*DAT_08008c30;
    FUN_0800b26c(2);
    *DAT_08008c38 = 0x3e;
    *DAT_08008c3c = 1;
    return;
  }
  if (param_1 == 2) {
    *(undefined1 *)(DAT_08008c40 + 0x1a) = 0;
    *(undefined1 *)(iVar3 + 0x1c) = 0;
    *(undefined1 *)(iVar3 + 0x13) = 0;
    *(undefined1 *)(iVar3 + 0x1b) = 0;
    *(undefined1 *)(iVar3 + 0x38) = 0;
    *(undefined1 *)(iVar3 + 0x3d) = 0;
    *(undefined1 *)(iVar3 + 0x3e) = 0;
    *(undefined1 *)(iVar3 + 0x3f) = 0;
    piVar1 = DAT_08008c48;
    *(undefined1 *)(iVar3 + 0x40) = 0;
    FUN_0800a9a8(*piVar1,0xcd,5,DAT_08008c44);
    iVar3 = *piVar1;
    *(undefined1 *)(iVar3 + 0x2b) = 1;
    *(undefined1 *)(iVar3 + 0x27) = 0;
    FUN_08003f98(iVar3);
    *DAT_08008c4c = *piVar1;
    FUN_080049a8(1);
    FUN_0800e3c4();
    FUN_0800e518();
    *DAT_08008c50 = 0;
    uVar2 = 4;
  }
  else {
    uVar2 = 0;
  }
  FUN_0800b26c(uVar2);
  return;
}



// ==== 08008c54  FUN_08008c54  (228 bytes, 1 xrefs)

void FUN_08008c54(void)

{
  short sVar1;
  char *pcVar2;
  char *pcVar3;
  byte bVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int in_r3;
  int local_18;
  
  pcVar2 = DAT_08008d38;
  *DAT_08008d38 = '\x01';
  local_18 = in_r3;
  FUN_0800298c(DAT_08008d3c,0x12,10);
  pcVar3 = DAT_08008d40;
  do {
    do {
    } while (*pcVar3 != '\x01');
    uVar5 = FUN_0800f900();
    if (*DAT_08008d44 == uVar5) {
      sVar1 = *DAT_08008d48;
      *DAT_08008d48 = sVar1 + 1;
      if ((short)(sVar1 + 1) == 2) {
        if (uVar5 == 0xff) {
          *DAT_08008d4c = 0xff;
        }
        else {
          *DAT_08008d4c = (byte)uVar5;
          if (uVar5 < 10) {
            FUN_08005198();
            if (*DAT_08008d50 < 6) {
              uVar6 = 1;
            }
            else {
              *DAT_08008d50 = 0;
              FUN_08004d78(DAT_08008d3c,&local_18);
              if (*(int *)(DAT_08008d54 + 0xc) * 100 == local_18) {
                FUN_080091ac(1);
                return;
              }
              FUN_0800298c(DAT_08008d3c,0x12,10);
              uVar6 = 2;
            }
            FUN_080091ac(uVar6);
            *pcVar2 = '\x01';
          }
          else if (uVar5 == 0xd) {
            if (*DAT_08008d50 != 0) {
              bVar4 = *DAT_08008d50 - 1;
              *DAT_08008d50 = bVar4;
              *(undefined1 *)(DAT_08008d3c + (uint)bVar4) = 10;
              *pcVar2 = '\x01';
            }
            FUN_080091ac(1);
          }
        }
        *DAT_08008d58 = 0;
      }
    }
    else {
      *DAT_08008d44 = (byte)uVar5;
      *DAT_08008d48 = 0;
    }
    iVar7 = FUN_0801072c();
    if (iVar7 == 1) {
      FUN_08003bc8(0);
    }
    iVar7 = FUN_08010a48();
    if (iVar7 == 1) {
      FUN_08003bc8();
    }
    if (*pcVar2 == '\x01') {
      FUN_0800d8dc();
      *pcVar2 = '\0';
    }
    *pcVar3 = '\0';
  } while( true );
}



// ==== 08008d94  FUN_08008d94  (70 bytes, 3 xrefs)

void FUN_08008d94(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = PTR_DAT_08008de8;
  puVar1 = PTR_DAT_08008de4;
  if ((*PTR_DAT_08008ddc != '\x01') && (*PTR_DAT_08008ddc != '\x02')) {
    if (*PTR_DAT_08008de0 == '\x01') {
      FUN_08004968();
      puVar3 = PTR_DAT_08008dec;
      *puVar1 = 0;
      *(undefined2 *)puVar3 = 0x50;
      *PTR_DAT_08008df0 = 1;
      *puVar2 = 0;
      return;
    }
    FUN_08004c74();
    FUN_080049a8(1);
    FUN_08009074();
    *puVar1 = 0;
    *puVar2 = 1;
  }
  return;
}



// ==== 08008e24  FUN_08008e24  (136 bytes, 0 xrefs)

void FUN_08008e24(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_08008eb0;
  if (*PTR_DAT_08008eac != '\x02') {
    FUN_08004c74();
    if ((0xce < *(byte *)(*(int *)PTR_DAT_08008eb4 + 0x1e)) && (*puVar1 == '\x01')) {
      *PTR_DAT_08008ee0 = *(byte *)(*(int *)PTR_DAT_08008eb4 + 0x1e) + 0x31;
    }
    FUN_080049a8(1);
    FUN_0800a36c(2);
    return;
  }
  if (*PTR_DAT_08008eb8 != '\0') {
    *(undefined2 *)PTR_DAT_08008ebc = 500;
    *PTR_DAT_08008ec0 = 0;
    *PTR_DAT_08008ec4 = 1;
  }
  if ((PTR_DAT_08008ec8[0x1a] == '\0') && (*puVar1 == '\x01')) {
    *(undefined2 *)PTR_DAT_08008ecc = 500;
    *PTR_DAT_08008ed0 = 0;
  }
  FUN_080049a8(1);
  puVar1 = PTR_DAT_08008ed8;
  if (*PTR_DAT_08008ed4 == '\x01') {
    FUN_08009074();
    *puVar1 = 1;
    return;
  }
  *PTR_DAT_08008ed8 = *PTR_DAT_08008edc;
  return;
}



// ==== 08008ee4  FUN_08008ee4  (196 bytes, 2 xrefs)

void FUN_08008ee4(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  puVar3 = DAT_08008fac;
  if (*DAT_08008fa8 == '\x01') {
    cVar1 = *DAT_08008fbc;
    if (((cVar1 != '\x04') && (cVar1 != '\x02')) && (cVar1 != '\x01')) {
      FUN_0800b26c(1);
      iVar5 = DAT_08008fcc;
      puVar4 = DAT_08008fc8;
      if (*DAT_08008fc0 == '\0') {
        if (param_1 == 1) {
          *DAT_08008fc4 = 1;
          *puVar4 = 0;
          FUN_08004904();
          uVar2 = *(undefined2 *)(iVar5 + 0x34);
        }
        else {
          *DAT_08008fc4 = 0;
          *puVar4 = 0;
          uVar2 = *(undefined2 *)(iVar5 + 0x30);
        }
        FUN_0800e210(uVar2);
        FUN_0800af60(uVar2,1,param_1 == 1);
        FUN_08009534(0,0x21);
        FUN_08009330(1);
        return;
      }
      FUN_0800b1fc();
LAB_08008f58:
      FUN_08009534(0,0x22);
      *puVar3 = 0xfe;
      return;
    }
  }
  else if ((*DAT_08008fb0 != '\x03') && (FUN_08004c74(), *(byte *)(*DAT_08008fb4 + 0x1e) < 0xcf)) {
    FUN_0800b26c(0);
    if (*DAT_08008fb8 != '\0') {
      FUN_0800b168();
      goto LAB_08008f58;
    }
    FUN_08009534(0,0x21);
    FUN_08009330(1);
    FUN_0800aedc(1);
  }
  return;
}



// ==== 0800904c  FUN_0800904c  (26 bytes, 4 xrefs)

void FUN_0800904c(void)

{
  char cVar1;
  
  cVar1 = *(char *)(DAT_08009068 + 0x1d);
  if (cVar1 != '\0') {
    *(undefined4 *)(PTR_GPIOF_0800906c + 0x18) = 0x100;
    *DAT_08009070 = cVar1 * '\x02' + '\x01';
  }
  return;
}



// ==== 08009074  FUN_08009074  (46 bytes, 4 xrefs)

void FUN_08009074(void)

{
  *DAT_080090a4 = 1;
  *DAT_080090a8 = 0;
  *DAT_080090ac = 0;
  FUN_0800e0fc(*(undefined2 *)(DAT_080090b0 + 0x30),1);
  DAT_50000018 = 0x100;
  *DAT_080090b4 = 1;
  *DAT_080090b8 = 1;
  return;
}



// ==== 080090bc  FUN_080090bc  (168 bytes, 2 xrefs)

undefined4 FUN_080090bc(uint param_1,short *param_2,char *param_3)

{
  short sVar1;
  short sVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  uint uVar9;
  uint local_30;
  uint local_2c;
  uint uStack_28;
  uint uStack_24;
  uint local_20;
  short *local_1c;
  char *local_18;
  
  uVar7 = 0;
  uVar9 = 0x1e4;
  local_20 = param_1;
  local_1c = param_2;
  local_18 = param_3;
  while( true ) {
    sVar1 = (short)((int)(uVar9 - uVar7) / 2) + (short)uVar7;
    uVar6 = (uint)sVar1;
    FUN_08009194(sVar1,&local_30);
    uVar4 = local_30;
    puVar3 = DAT_08009164;
    if (local_30 == local_20) break;
    if (local_20 < local_30) {
      if (uVar6 == 0) {
        return 0;
      }
      uVar9 = uVar6 - 1 & 0xffff;
    }
    else {
      if (uVar6 == 0x1e4) {
        return 0;
      }
      uVar7 = uVar6 + 1 & 0xffff;
    }
    if (uVar9 < uVar7) {
      return 0;
    }
  }
  puVar5 = DAT_08009164 + 1;
  *DAT_08009164 = local_30;
  *puVar5 = local_2c;
  puVar3[2] = uStack_28;
  puVar3[3] = uStack_24;
  while (sVar1 = (short)uVar6, 0 < (int)uVar6) {
    sVar2 = sVar1 + -1;
    FUN_08009194(sVar2,&local_30);
    if (local_30 != uVar4) break;
    *puVar3 = local_30;
    puVar3[1] = local_2c;
    puVar3[2] = uStack_28;
    puVar3[3] = uStack_24;
    uVar6 = (uint)sVar2;
  }
  cVar8 = '\x01';
  while ((uVar6 = uVar6 + 1 & 0xffff, uVar6 < 0x1e5 &&
         (FUN_08009194(uVar6,&local_30), local_30 == uVar4))) {
    cVar8 = cVar8 + '\x01';
  }
  *local_1c = sVar1;
  *local_18 = cVar8;
  return 1;
}



// ==== 08009168  FUN_08009168  (32 bytes, 3 xrefs)

void FUN_08009168(void)

{
  int iVar1;
  
  iVar1 = (*(byte *)(DAT_08009188 + 0xe) & 0x7f) * 2;
  FUN_0800ff84(DAT_08009190,(uint)*(ushort *)(DAT_08009188 + 0xc) + DAT_0800918c,iVar1);
  *(undefined1 *)(DAT_08009190 + iVar1) = 0;
  return;
}



// ==== 08009194  FUN_08009194  (22 bytes, 5 xrefs)

void FUN_08009194(int param_1,undefined4 param_2)

{
  FUN_0800ff84(param_2,param_1 * 0x10 + 0x100000,0x10);
  return;
}



// ==== 080091ac  FUN_080091ac  (342 bytes, 13 xrefs)

void FUN_080091ac(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (((param_1 != 4) && (param_1 != 3)) && (*(char *)(DAT_08009304 + 0x16) == '\0')) {
    return;
  }
  if (*DAT_08009308 == '\x04') {
    return;
  }
  if (*DAT_0800930c == '\x04') {
    return;
  }
  if (*DAT_0800930c == '\x02') {
    return;
  }
  uVar2 = FUN_0800e900(0x71);
  DAT_50000028 = 0x100;
  if (*DAT_08009310 != '\0') {
    DAT_50000028 = 0x100;
    FUN_080123ae(5);
    FUN_0800f800();
    *DAT_08009314 = 0;
    *DAT_08009318 = 0;
    *DAT_0800931c = 0;
    FUN_080123ae(0x14);
    *DAT_08009310 = '\0';
  }
  pcVar1 = DAT_0800930c;
  if ((*DAT_0800930c == '\x05') && (*DAT_08009320 == '\x01')) {
    FUN_0800ee5c();
  }
  if (*DAT_08009324 == '\x01') {
    FUN_0800e1c8();
  }
  FUN_080123ae(0x14);
  if (param_1 == 1) {
    uVar3 = 1000;
  }
  else if ((param_1 == 2) || (param_1 == 4)) {
    uVar3 = 500;
  }
  else {
    uVar3 = 0x1b8;
  }
  FUN_0800deec(uVar3,1);
  FUN_080123ae(2);
  DAT_50000018 = 0x100;
  FUN_080123ae(0x3c);
  if (param_1 != 1) {
    if ((param_1 != 2) && (param_1 != 4)) {
      FUN_0800df50();
      uVar3 = 500;
      goto LAB_08009270;
    }
    FUN_0800df50();
    FUN_080123ae(0x3c);
    FUN_0800df60();
    FUN_080123ae(0x14);
  }
  FUN_0800df50();
  uVar3 = 0x3c;
LAB_08009270:
  FUN_080123ae(uVar3);
  FUN_0800df60();
  FUN_080123ae(0x14);
  DAT_50000028 = 0x100;
  *DAT_08009328 = 0x50;
  FUN_080123ae(5);
  FUN_0800deb8();
  FUN_080123ae(5);
  FUN_0800ee64(0x71,uVar2);
  if (*DAT_08009324 == '\x01') {
    FUN_0800e1c8(0);
    FUN_080123ae(0x1e);
  }
  if (*DAT_0800932c == '\x01') {
    DAT_50000018 = 0x100;
  }
  if ((*pcVar1 == '\x05') && (*DAT_08009320 == '\x01')) {
    FUN_0800eb00();
  }
  return;
}



// ==== 08009330  FUN_08009330  (434 bytes, 8 xrefs)

void FUN_08009330(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint *puVar4;
  ushort *puVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint local_20;
  uint local_1c;
  int local_18;
  
  pbVar6 = DAT_080094f0;
  uVar2 = DAT_080094e4;
  cVar1 = *(char *)(DAT_080094e8 + 0x15);
  if ((cVar1 == '\0') || (*DAT_080094f0 == 0)) {
    *DAT_080094ec = 0;
  }
  else {
    *DAT_080094ec = 0;
    if (cVar1 == '\x01') {
      iVar7 = 0x14c000;
    }
    else {
      iVar7 = DAT_080094f8;
    }
    local_18 = param_1;
    FUN_0800ff84(&local_20,(uint)*DAT_080094f4 * 8 + iVar7,8);
    *DAT_080094fc = local_20;
    puVar4 = DAT_08009500;
    *DAT_08009500 = local_1c;
    if ((local_20 < 0xb0001) && (local_1c < 0x19001)) {
      if ((*DAT_08009504 == '\x04') || (*DAT_08009504 == '\x02')) {
        FUN_0800e280(0);
      }
      if (*DAT_08009508 == '\x01') {
        FUN_0800e1c8();
      }
      *DAT_0800950c = 2000;
      uVar9 = *DAT_080094fc + DAT_08009510;
      *DAT_080094fc = uVar9;
      FUN_0800ff84(uVar2,uVar9,0x280);
      iVar7 = DAT_08009514;
      uVar9 = 0;
      do {
        iVar10 = uVar9 * 2;
        uVar9 = uVar9 + 1 & 0xff;
        *(undefined2 *)(iVar7 + iVar10) = 0x800;
      } while (uVar9 < 0xa0);
      FUN_08003e50(uVar2,0x1e0,DAT_08009518);
      *DAT_0800951c = 0;
      *DAT_08009520 = 3;
      *DAT_08009524 = '\x03';
      puVar5 = DAT_08009528;
      *DAT_08009528 = 3;
      FUN_0800f7a4();
      FUN_080123ae(10);
      DAT_50000018 = 0x100;
      if (local_18 != 1) {
        *DAT_0800952c = 1;
        return;
      }
      uVar9 = 0;
      do {
        if (*DAT_080094f0 <= uVar9) {
          do {
          } while (*DAT_08009524 != '\0');
          FUN_080123ae(0x1e);
          FUN_0800f800();
          if ((*DAT_08009504 == '\x04') || (*DAT_08009504 == '\x02')) {
            FUN_0800e280(1);
          }
          if (*DAT_08009508 == '\x01') {
            FUN_0800e1c8(0);
          }
          if (*DAT_08009530 == '\0') {
            DAT_50000028 = 0x100;
          }
          *DAT_080094f0 = 0;
          *DAT_080094ec = 0;
          *DAT_0800950c = 0x50;
          return;
        }
        if (uVar9 == 0) {
LAB_08009474:
          while (uVar8 = FUN_080028f0(*puVar4,0xa0), *puVar5 < uVar8) {
            FUN_08009754();
          }
        }
        else {
          if (*(char *)(DAT_080094e8 + 0x15) == '\x01') {
            iVar7 = 0x14c000;
          }
          else {
            iVar7 = DAT_080094f8;
          }
          FUN_0800ff84(&local_20,(uint)DAT_080094f4[uVar9] * 8 + iVar7,8);
          puVar3 = DAT_080094fc;
          *DAT_080094fc = local_20;
          *puVar4 = local_1c;
          if ((local_20 < 0xb0001) && (local_1c < 0x19001)) {
            *puVar3 = local_20 + DAT_08009510;
            *puVar5 = 0;
            goto LAB_08009474;
          }
        }
        uVar9 = uVar9 + 1 & 0xff;
      } while( true );
    }
    *DAT_080094ec = 0;
    pbVar6 = DAT_080094f0;
  }
  *pbVar6 = 0;
  return;
}



// ==== 08009534  FUN_08009534  (70 bytes, 15 xrefs)

void FUN_08009534(uint param_1,undefined1 param_2)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  undefined1 *puVar4;
  
  pcVar3 = DAT_08009584;
  pbVar2 = DAT_0800957c;
  if (param_1 == 0) {
    if (*DAT_08009584 != '\0') {
      DAT_50000028 = 0x100;
      FUN_0800f800();
      puVar4 = DAT_08009588;
      *pbVar2 = 0;
      *puVar4 = 0;
      *DAT_0800958c = 0;
      FUN_080123ae(0x14);
      *pcVar3 = '\0';
    }
  }
  else if (7 < param_1) {
    return;
  }
  bVar1 = *pbVar2;
  *(undefined1 *)(DAT_08009580 + (uint)bVar1) = param_2;
  *pbVar2 = bVar1 + 1;
  return;
}



// ==== 08009590  FUN_08009590  (212 bytes, 1 xrefs)

void FUN_08009590(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint *puVar4;
  undefined2 *puVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint local_20;
  uint local_1c;
  undefined4 uStack_18;
  
  puVar1 = DAT_08009664;
  local_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  uVar7 = FUN_080028f0(*DAT_08009664,0xa0);
  pbVar3 = DAT_08009674;
  pbVar2 = DAT_08009670;
  if (*DAT_08009668 < uVar7) {
    FUN_08009754();
  }
  else if (*DAT_0800966c == '\0') {
    bVar6 = *DAT_08009670 + 1;
    *DAT_08009670 = bVar6;
    if ((uint)bVar6 != (uint)*pbVar3) {
      if (*(char *)(DAT_0800967c + 0x15) != '\0') {
        if (*(char *)(DAT_0800967c + 0x15) == '\x01') {
          iVar8 = 0x14c000;
        }
        else {
          iVar8 = DAT_08009680;
        }
        FUN_0800ff84(&local_20,(uint)*(byte *)(DAT_08009678 + (uint)bVar6) * 8 + iVar8,8);
        puVar4 = DAT_08009684;
        *DAT_08009684 = local_20;
        *puVar1 = local_1c;
        if ((local_20 < 0xb0001) && (local_1c < 0x19001)) {
          *puVar4 = local_20 + DAT_0800968c;
          *DAT_08009668 = 0;
          return;
        }
        *pbVar2 = 0;
        *pbVar3 = 0;
      }
    }
    FUN_080123ae(0x1e);
    FUN_0800f800();
    if ((*DAT_08009688 == '\x04') || (*DAT_08009688 == '\x02')) {
      FUN_0800e280(1);
    }
    if (*DAT_08009690 == '\x01') {
      FUN_0800e1c8(0);
    }
    if (*DAT_08009694 == '\0') {
      DAT_50000028 = 0x100;
    }
    *pbVar3 = 0;
    puVar5 = DAT_08009698;
    *pbVar2 = 0;
    *puVar5 = 0x50;
    *DAT_0800969c = 0;
    return;
  }
  return;
}



// ==== 080096a0  FUN_080096a0  (158 bytes, 4 xrefs)

undefined8 FUN_080096a0(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  byte bVar4;
  uint extraout_r1;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uStack_20;
  
  pbVar2 = DAT_08009740;
  if ((param_1 == 0) && (*DAT_08009744 != '\0')) {
    DAT_50000028 = 0x100;
    FUN_0800f800();
    puVar3 = DAT_08009748;
    *pbVar2 = 0;
    *puVar3 = 0;
    *DAT_0800974c = 0;
    FUN_080123ae(0x14);
    *DAT_08009744 = '\0';
  }
  FUN_080028f0(param_2,1000);
  bVar7 = 99 < extraout_r1;
  uVar5 = extraout_r1;
  if (bVar7) {
    bVar4 = FUN_080028f0(extraout_r1,100);
    bVar1 = *pbVar2;
    *(byte *)(DAT_08009750 + (uint)bVar1) = bVar4;
    *pbVar2 = bVar1 + 1;
    uVar5 = extraout_r1 + (uint)bVar4 * -100 & 0xffff;
  }
  uVar6 = (uint)bVar7;
  if ((9 < uVar5) || (bVar7)) {
    bVar4 = FUN_080028f0(uVar5,10);
    bVar1 = *pbVar2;
    *(byte *)(DAT_08009750 + (uint)bVar1) = bVar4;
    *pbVar2 = bVar1 + 1;
    uVar5 = uVar5 + (uint)bVar4 * -10 & 0xffff;
    uVar6 = uVar6 + 1;
  }
  bVar1 = *pbVar2;
  *(char *)(DAT_08009750 + (uint)bVar1) = (char)uVar5;
  *pbVar2 = bVar1 + 1;
  return CONCAT44(uStack_20,uVar6 + 1);
}



// ==== 08009754  FUN_08009754  (86 bytes, 2 xrefs)

void FUN_08009754(void)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  ushort *puVar4;
  byte *pbVar5;
  undefined4 in_r3;
  
  puVar4 = DAT_080097b4;
  pbVar3 = DAT_080097b0;
  uVar2 = DAT_080097ac;
  if (*DAT_080097b0 < 4) {
    FUN_0800ff84(DAT_080097ac,(uint)*DAT_080097b4 * 0xa0 + *DAT_080097b8,0xa0,in_r3,in_r3);
    pbVar5 = DAT_080097bc;
    FUN_08003e50(uVar2,0xa0,(uint)*DAT_080097bc * 0x140 + DAT_080097c0);
    bVar1 = *pbVar5;
    *pbVar5 = bVar1 + 1;
    if (3 < (byte)(bVar1 + 1)) {
      *pbVar5 = 0;
    }
    *pbVar3 = *pbVar3 + 1;
    *puVar4 = *puVar4 + 1;
  }
  return;
}



// ==== 080097c4  FUN_080097c4  (330 bytes, 2 xrefs)

void FUN_080097c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined3 uVar1;
  ushort *puVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  iVar5 = DAT_08009914;
  local_18 = param_2;
  uStack_14 = param_3;
  local_10 = param_4;
  FUN_0800ff84(DAT_08009914,DAT_08009910,8);
  FUN_08002968(DAT_08009914 + 8,iVar5,8);
  FUN_08002968(DAT_08009914 + 0x10,iVar5,8);
  FUN_08002968(DAT_08009914 + 0x18,iVar5,8);
  FUN_0800ff84(DAT_08009914 + -0x18,DAT_08009910 + 8,8);
  FUN_08002968(DAT_08009914 + -0x10);
  FUN_08002968(DAT_08009914 + -8,DAT_08009914 + -0x18,8);
  FUN_0800ff84(DAT_08009918,DAT_08009910 + 0x80,0xc);
  puVar2 = DAT_08009918;
  if (DAT_0800991c < *DAT_08009918) {
    *DAT_08009918 = (ushort)DAT_08009920;
    puVar2[1] = 2000;
    puVar2[5] = (ushort)DAT_08009924;
  }
  iVar5 = (*(byte *)(DAT_08009928 + 0x14) & 0x7f) * 2;
  FUN_0800ff84(DAT_08009928 + 0x28,iVar5 + DAT_08009910 + 0x90,2);
  FUN_0800ff84(DAT_08009928 + 0x2a,iVar5 + DAT_08009910 + 0xa8,2);
  iVar3 = DAT_08009928;
  FUN_0800ff84(&local_18,(uint)*(byte *)(DAT_08009928 + 0x41) + DAT_08009910 + 0xc0,1);
  iVar5 = DAT_08009910;
  if (0x1f < (byte)local_18) {
    local_18 = CONCAT31(local_18._1_3_,0xf);
  }
  *(byte *)(iVar3 + 0x42) = (byte)local_18;
  FUN_0800ff84(&uStack_14,iVar5 + 200,8);
  iVar5 = DAT_08009928;
  *(short *)(DAT_08009928 + 0x90) = (short)uStack_14;
  if (DAT_08009920 + 0x65U <= (int)(short)uStack_14 + 1000U) {
    *(undefined2 *)(iVar5 + 0x90) = 0;
  }
  *DAT_0800992c = uStack_14._2_2_ & 0x1ff;
  *DAT_08009930 = (ushort)local_10 & 0x1ff;
  bVar4 = local_10._2_1_;
  if (0x3f < local_10._2_1_) {
    bVar4 = 0x3a;
  }
  uVar1 = (undefined3)((uint)local_18 >> 8);
  *(byte *)(iVar5 + 0x93) = bVar4;
  local_18 = CONCAT31(uVar1,local_10._3_1_);
  if (0xf < local_10._3_1_) {
    local_18 = CONCAT31(uVar1,8);
  }
  *(byte *)(iVar5 + 0x94) = (byte)local_18;
  FUN_0800ee64(0x3b,*(short *)(iVar5 + 0x90) + 0x5880);
  FUN_0800ee64(0x3c,DAT_08009934);
  return;
}



// ==== 08009938  FUN_08009938  (770 bytes, 12 xrefs)

void FUN_08009938(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 local_38;
  undefined4 local_34;
  uint local_28;
  int local_24;
  int iStack_1c;
  int local_18;
  
  iVar6 = DAT_08009c3c;
  iVar7 = param_1 * 0x44 + DAT_08009c3c;
  iVar10 = DAT_08009c3c + param_1;
  puVar8 = (uint *)(iVar7 + 0xb8);
  if (*DAT_08009c40 == '\0') {
    if (*(char *)(iVar10 + 2) == -0x34) {
      *(undefined1 *)(iVar10 + 2) = 0xcd;
    }
    if (*(char *)(iVar6 + param_1) == -0x34) {
      *(undefined1 *)(iVar6 + param_1) = 0xcd;
    }
  }
  uVar9 = (uint)*(byte *)(DAT_08009c3c + param_1);
  iStack_1c = param_1;
  local_18 = param_2;
  if (uVar9 < 0xd9) {
    if (0xce < uVar9) {
      FUN_0800a9a8(puVar8,uVar9,2,*(undefined4 *)(DAT_08009c44 + (uVar9 - 0xcf & 0xff) * 4));
      if (*(char *)(DAT_08009c3c + 0x1b) == '\0') {
        return;
      }
      *(undefined1 *)(DAT_08009c3c + 0x1b) = 0;
      *DAT_08009c48 = 1;
      return;
    }
    if (uVar9 < 200) {
      uVar9 = FUN_08004f10(uVar9,1,0);
      if (uVar9 == 0xff) {
        uVar9 = (uint)*(byte *)(iVar10 + 2);
        *(byte *)(DAT_08009c3c + param_1) = *(byte *)(iVar10 + 2);
      }
      else {
        *(char *)(DAT_08009c3c + param_1) = (char)uVar9;
        *(char *)(iVar10 + 4) = (char)uVar9;
      }
    }
  }
  else {
    uVar9 = 0xcd;
  }
  bVar4 = *(byte *)(DAT_08009c4c + uVar9);
  uVar2 = (uint)bVar4;
  if (uVar2 == 0xff) {
    if (uVar9 < 200) {
      uVar9 = (uint)*(byte *)(iVar10 + 2);
      *(byte *)(DAT_08009c3c + param_1) = *(byte *)(iVar10 + 2);
    }
    uVar2 = uVar9 - 200 & 0xff;
    FUN_0800a9a8(puVar8,uVar9,uVar2,*(undefined4 *)(DAT_08009c50 + uVar2 * 4));
    return;
  }
  uVar11 = uVar2 & 0xf;
  if (6 < uVar11) {
    uVar11 = 5;
  }
  iVar6 = param_1 * 0x44 + DAT_08009c3c;
  local_24 = iVar6 + 0xd8;
  if (uVar9 < 200) {
    *(char *)(iVar6 + 0xe6) = (char)uVar11;
    *(byte *)(iVar6 + 0xe4) = bVar4 >> 7;
    *(char *)(iVar6 + 0xe5) = (char)((uVar2 & 0x7f) >> 6);
  }
  else {
    bVar4 = (char)uVar9 + 0x38;
    uVar11 = (uint)bVar4;
    *(byte *)(iVar6 + 0xe6) = bVar4;
    *(undefined1 *)(iVar6 + 0xe4) = 1;
    *(undefined1 *)(iVar6 + 0xe5) = 1;
  }
  *(char *)(iVar7 + 0xd6) = (char)uVar9;
  if (uVar9 < 200) {
    local_28 = uVar9 << 4;
  }
  else {
    if (param_1 == 0) {
      iVar6 = 0x900;
    }
    else {
      iVar6 = 0x8f0;
    }
    local_28 = uVar9 * 0x20 - iVar6 & 0xffff;
  }
  if ((local_18 != 2) && (uVar9 < 200)) goto LAB_08009b4c;
  FUN_0800ff84(&local_38,local_28 + 8,8);
  bVar4 = local_38._3_1_ & 0xf;
  if (2 < bVar4) {
    bVar4 = 0;
  }
  *(byte *)(iVar7 + 0xd7) = bVar4;
  *(char *)(local_24 + 0x12) = (char)((local_38._3_1_ & 0x1f) >> 4);
  uVar2 = local_34 >> 0x10 & 0xff;
  if (6 < uVar2) {
    uVar2 = 5;
  }
  *(char *)(local_24 + 6) = (char)uVar2;
  *(undefined2 *)(iVar7 + 0xd4) = *(undefined2 *)(DAT_08009c54 + uVar2 * 2);
  bVar4 = local_34._3_1_;
  if (10 < local_34._3_1_) {
    bVar4 = 0;
  }
  *(byte *)(local_24 + 10) = bVar4;
  *(byte *)(iVar7 + 0xbc) = local_38._2_1_ & 0xf;
  *(byte *)(iVar7 + 0xc4) = local_38._2_1_ >> 4;
  cVar1 = *(char *)(iVar7 + 0xbc);
  uVar5 = (undefined1)local_38;
  if (cVar1 == '\x01') {
    if (0x31 < (local_38 & 0xff)) goto LAB_08009ad0;
  }
  else {
    if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
      if ((local_38 & 0xff) < 0x68) goto LAB_08009ad2;
    }
    else {
      *(undefined1 *)(iVar7 + 0xbc) = 0;
    }
LAB_08009ad0:
    uVar5 = 0;
  }
LAB_08009ad2:
  *(undefined1 *)(iVar7 + 0xbd) = uVar5;
  cVar1 = *(char *)(iVar7 + 0xc4);
  bVar4 = local_38._1_1_;
  if (cVar1 == '\x01') {
    if (0x31 < local_38._1_1_) goto LAB_08009af6;
  }
  else {
    if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
      if (local_38._1_1_ < 0x68) goto LAB_08009af8;
    }
    else {
      *(undefined1 *)(iVar7 + 0xc4) = 0;
    }
LAB_08009af6:
    bVar4 = 0;
  }
LAB_08009af8:
  *(byte *)(iVar7 + 0xc5) = bVar4;
  if ((local_34 & 0xff) == 0xff) {
    uVar5 = 0;
    *(undefined1 *)(local_24 + 9) = 0;
    *(undefined1 *)(local_24 + 0xb) = 0;
    *(undefined1 *)(local_24 + 7) = 2;
  }
  else {
    *(byte *)(local_24 + 9) = (byte)local_34 & 1;
    *(char *)(local_24 + 0xb) = (char)((local_34 & 3) >> 1);
    *(char *)(local_24 + 7) = (char)((local_34 & 0xf) >> 2);
    uVar5 = (undefined1)((local_34 & 0x1f) >> 4);
  }
  *(undefined1 *)(local_24 + 0x11) = uVar5;
  if (local_34._1_1_ == 0xff) {
    uVar5 = 0;
    *(undefined1 *)(local_24 + 0xf) = 0;
  }
  else {
    *(byte *)(local_24 + 0xf) = local_34._1_1_ & 1;
    uVar5 = (undefined1)((local_34._1_1_ & 7) >> 1);
  }
  *(undefined1 *)(local_24 + 0x10) = uVar5;
  FUN_0800ff84(&local_38,local_28,8);
  *puVar8 = local_38;
  if (DAT_08009c58 < local_34) {
    local_34 = DAT_08009c5c;
  }
  *(uint *)(iVar7 + 0xd0) = local_34;
LAB_08009b4c:
  local_28 = (uint)*(ushort *)(iVar7 + 0xd4);
  iVar6 = uVar11 * 4;
  uVar2 = *puVar8;
  if ((uVar2 < *(uint *)(*DAT_08009c60 + iVar6)) || (*(uint *)(*DAT_08009c64 + iVar6) < uVar2)) {
    uVar2 = *(uint *)(DAT_08009c50 + iVar6);
  }
  else if (199 < uVar9) {
    uVar2 = FUN_08003d08(uVar2,local_28);
  }
  iVar6 = DAT_08009c68;
  *puVar8 = uVar2;
  if (DAT_08009c6c < uVar2 + iVar6) {
    if (199 < uVar9) {
      uVar3 = FUN_08003d08(*(undefined4 *)(iVar7 + 0xd0),local_28,0);
      *(undefined4 *)(iVar7 + 0xd0) = uVar3;
    }
  }
  else {
    *(undefined1 *)(iVar7 + 0xd7) = 0;
  }
  FUN_080041c4(puVar8);
  *(undefined4 *)(iVar7 + 0xec) = 0;
  *(undefined4 *)(iVar7 + 0xf0) = 0;
  *(undefined4 *)(iVar7 + 0xf4) = 0;
  *(undefined4 *)(iVar7 + 0xf8) = 0;
  if (uVar9 < 200) {
    FUN_0800ff84(&local_38,uVar9 * 0x10 + 0xe000 & 0xffff,0x10);
    FUN_08002968(iVar7 + 0xec,&local_38,10);
  }
  iVar6 = param_1 * 0x44 + DAT_08009c3c + 0xc0;
  if (*(char *)(local_24 + 9) == '\x01') {
    *(uint **)(iVar7 + 0xcc) = puVar8;
    *(int *)(iVar7 + 200) = iVar6;
  }
  else {
    *(uint **)(iVar7 + 200) = puVar8;
    *(int *)(iVar7 + 0xcc) = iVar6;
  }
  if ((*DAT_08009c40 == '\0') && ((uint)(**(int **)(iVar7 + 200) + DAT_08009c70) <= DAT_08009c74)) {
    **(int **)(iVar7 + 200) = DAT_08009c78;
  }
  if ((*(char *)(local_24 + 0xe) == '\x01') && (*(char *)(local_24 + 0x12) == '\x01')) {
    *(undefined1 *)(local_24 + 0x13) = 1;
    *(undefined1 *)(local_24 + 10) = 0;
    *(undefined1 *)(local_24 + 0xf) = 0;
    *(undefined1 *)(iVar7 + 0xbc) = 0;
    *(undefined1 *)(iVar7 + 0xc4) = 0;
  }
  else {
    *(undefined1 *)(local_24 + 0x13) = 0;
  }
  FUN_08003f98(puVar8);
  return;
}



// ==== 08009c7c  FUN_08009c7c  (1262 bytes, 2 xrefs)

void FUN_08009c7c(void)

{
  byte *pbVar1;
  byte *pbVar2;
  ushort uVar3;
  ushort *puVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  byte bVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  ushort *puVar12;
  ushort *puVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  
  puVar4 = DAT_0800a060;
  FUN_0800ff84(DAT_0800a060,0x4000);
  pbVar5 = DAT_0800a064;
  if ((byte)*puVar4 < 200) {
    DAT_0800a064[3] = (byte)*puVar4;
  }
  else {
    DAT_0800a064[3] = 0;
  }
  pbVar1 = DAT_0800a064;
  pbVar16 = DAT_0800a064 + -0x40;
  if (*(byte *)((int)puVar4 + 1) < 10) {
    DAT_0800a064[-0x30] = *(byte *)((int)puVar4 + 1);
  }
  else {
    DAT_0800a064[-0x30] = 4;
  }
  bVar7 = (byte)puVar4[1];
  if (10 < bVar7) {
    bVar7 = 2;
  }
  pbVar1[-0x2f] = bVar7;
  pbVar2 = DAT_0800a064;
  bVar7 = *(byte *)((int)puVar4 + 3);
  pbVar15 = DAT_0800a064 + 0x40;
  if (1 < bVar7) {
    bVar7 = 1;
  }
  DAT_0800a064[0x52] = bVar7;
  if ((byte)puVar4[2] < 2) {
    pbVar1[-0x2e] = (byte)puVar4[2];
  }
  else {
    pbVar1[-0x2e] = 0;
  }
  if (*(byte *)((int)puVar4 + 5) < 2) {
    pbVar1[-0x2d] = *(byte *)((int)puVar4 + 5);
  }
  else {
    pbVar1[-0x2d] = 0;
  }
  bVar7 = (byte)puVar4[3];
  if (9 < bVar7) {
    bVar7 = 5;
  }
  pbVar1[-0x2c] = bVar7;
  bVar7 = *(byte *)((int)puVar4 + 7);
  if (4 < bVar7) {
    bVar7 = 2;
  }
  pbVar5[1] = bVar7;
  if (*(byte *)((int)puVar4 + 9) < 3) {
    pbVar1[-0x29] = *(byte *)((int)puVar4 + 9);
  }
  else {
    pbVar1[-0x29] = 0;
  }
  if ((byte)puVar4[5] < 3) {
    pbVar1[-0x25] = (byte)puVar4[5];
  }
  else {
    pbVar1[-0x25] = 0;
  }
  if (*(byte *)((int)puVar4 + 0xb) < 5) {
    pbVar1[-0x24] = *(byte *)((int)puVar4 + 0xb);
  }
  else {
    pbVar1[-0x24] = 4;
  }
  bVar7 = (byte)puVar4[6];
  if (2 < bVar7) {
    bVar7 = 1;
  }
  pbVar1[-0x26] = bVar7;
  bVar7 = *(byte *)((int)puVar4 + 0xd);
  if (5 < bVar7) {
    bVar7 = 5;
  }
  pbVar1[-0x23] = bVar7;
  bVar7 = (byte)puVar4[7];
  if (1 < bVar7) {
    bVar7 = 1;
  }
  pbVar1[-0x28] = bVar7;
  bVar7 = *(byte *)((int)puVar4 + 0xf);
  if (1 < bVar7) {
    bVar7 = 1;
  }
  pbVar1[-0x27] = bVar7;
  FUN_0800ff84(puVar4,0x5000,8);
  if ((byte)*puVar4 < 0xd9) {
    *pbVar16 = (byte)*puVar4;
  }
  else {
    *pbVar16 = 0xcd;
  }
  if (*(byte *)((int)puVar4 + 3) < 0xd9) {
    pbVar1[-0x3f] = *(byte *)((int)puVar4 + 3);
  }
  else {
    pbVar1[-0x3f] = 0xcd;
  }
  if (*(byte *)((int)puVar4 + 1) < 200) {
    pbVar1[-0x3c] = *(byte *)((int)puVar4 + 1);
  }
  else {
    pbVar1[-0x3c] = 0;
  }
  if ((byte)puVar4[2] < 200) {
    pbVar1[-0x3b] = (byte)puVar4[2];
  }
  else {
    pbVar1[-0x3b] = 0;
  }
  if ((byte)puVar4[1] - 200 < 7) {
    pbVar1[-0x3e] = (byte)puVar4[1];
  }
  else {
    pbVar1[-0x3e] = 0xcd;
  }
  if (*(byte *)((int)puVar4 + 5) - 200 < 7) {
    pbVar1[-0x3d] = *(byte *)((int)puVar4 + 5);
  }
  else {
    pbVar1[-0x3d] = 0xcd;
  }
  if ((byte)puVar4[3] - 0xcf < 10) {
    pbVar1[-0x3a] = (byte)puVar4[3];
  }
  else {
    pbVar1[-0x3a] = 0xcf;
  }
  if (*(byte *)((int)puVar4 + 7) - 0xcf < 10) {
    pbVar1[-0x39] = *(byte *)((int)puVar4 + 7);
  }
  else {
    pbVar1[-0x39] = 0xcf;
  }
  FUN_0800ff84(puVar4,0x6000,8);
  pbVar1[-0xffffffff0000000c] = 0xf8;
  pbVar1[-0xffffffff0000000b] = 2;
  pbVar1[-0xffffffff0000000a] = 0x38;
  pbVar16 = DAT_0800a064;
  pbVar1[-0xffffffff00000009] = 4;
  uVar3 = *puVar4;
  if ((0x438 < uVar3) || (uVar3 < 0x2f8)) {
    uVar3 = 0x2f8;
  }
  *(ushort *)(DAT_0800a064 + -0x14) = uVar3;
  pbVar16[-0x12] = (byte)puVar4[1];
  if (*(byte *)((int)puVar4 + 3) < 2) {
    pbVar16[-0x11] = *(byte *)((int)puVar4 + 3);
  }
  else {
    pbVar16[-0x11] = 0;
  }
  FUN_0800ff84(DAT_0800a068,0x3000,0x28);
  FUN_08004f80();
  FUN_0800ff84(puVar4,0x7000,0x90);
  bVar7 = (byte)*puVar4;
  if (1 < bVar7) {
    bVar7 = 1;
  }
  DAT_0800a064[-0x2a] = bVar7;
  bVar7 = *(byte *)((int)puVar4 + 1);
  if (8 < bVar7) {
    bVar7 = 3;
  }
  pbVar16[-3] = bVar7;
  bVar7 = (byte)puVar4[1];
  if (8 < bVar7) {
    bVar7 = 8;
  }
  pbVar16[-2] = bVar7;
  bVar7 = *(byte *)((int)puVar4 + 3);
  if (8 < bVar7) {
    bVar7 = 1;
  }
  pbVar16[-1] = bVar7;
  if ((byte)puVar4[2] < 9) {
    *pbVar5 = (byte)puVar4[2];
  }
  else {
    *pbVar5 = 6;
  }
  bVar7 = *(byte *)((int)puVar4 + 5);
  if (2 < bVar7) {
    bVar7 = 1;
  }
  DAT_0800a064[-0x22] = bVar7;
  if ((byte)puVar4[3] < 2) {
    pbVar16[-8] = (byte)puVar4[3];
  }
  else {
    pbVar16[-8] = 0;
  }
  bVar7 = *(byte *)((int)puVar4 + 7);
  if (3 < bVar7) {
    bVar7 = 2;
  }
  pbVar16[-6] = bVar7;
  puVar13 = puVar4 + 4;
  FUN_08002968(DAT_0800a064 + -0x34,puVar13,4);
  bVar7 = (byte)puVar4[8];
  if (2 < bVar7) {
    bVar7 = 1;
  }
  DAT_0800a064[-0x2b] = bVar7;
  bVar7 = *(byte *)((int)puVar4 + 0x11);
  if (1 < bVar7) {
    bVar7 = 1;
  }
  pbVar2[0x55] = bVar7;
  bVar7 = (byte)puVar4[0xc];
  if (1 < bVar7) {
    bVar7 = 1;
  }
  pbVar16[-7] = bVar7;
  if (*(byte *)((int)puVar4 + 0x19) < 3) {
    pbVar16[-5] = *(byte *)((int)puVar4 + 0x19);
  }
  else {
    pbVar16[-5] = 0;
  }
  if ((byte)puVar4[0xd] < 0xb) {
    pbVar16[-4] = (byte)puVar4[0xd];
  }
  else {
    pbVar16[-4] = 0;
  }
  if (*(byte *)((int)puVar4 + 0x1b) < 2) {
    DAT_0800a064[-0x37] = *(byte *)((int)puVar4 + 0x1b);
  }
  else {
    DAT_0800a064[-0x37] = 0;
  }
  FUN_08002968(DAT_0800a064 + 0x58,puVar4 + 0x10);
  bVar7 = (byte)puVar4[0x20];
  if (1 < bVar7) {
    bVar7 = 1;
  }
  pbVar2[0x4e] = bVar7;
  iVar9 = FUN_08004dcc((byte *)((int)puVar4 + 0x41),1);
  if (iVar9 == 1) {
    bVar7 = *(byte *)((int)puVar4 + 0x41);
  }
  else {
    bVar7 = 0x2a;
  }
  *pbVar15 = bVar7;
  iVar9 = FUN_08004dcc(puVar4 + 0x21,1);
  if (iVar9 == 1) {
    bVar7 = (byte)puVar4[0x21];
  }
  else {
    bVar7 = 0x23;
  }
  pbVar2[0x41] = bVar7;
  if (*(byte *)((int)puVar4 + 0x43) < 4) {
    pbVar2[0x42] = *(byte *)((int)puVar4 + 0x43);
  }
  else {
    pbVar2[0x42] = 0;
  }
  bVar7 = (byte)puVar4[0x22];
  if (0x37 < bVar7 - 5) {
    bVar7 = 5;
  }
  pbVar2[0x43] = bVar7;
  if (*(byte *)((int)puVar4 + 0x45) - 3 < 0x62) {
    sVar8 = (ushort)*(byte *)((int)puVar4 + 0x45) * 10;
  }
  else {
    sVar8 = 300;
  }
  *(short *)(pbVar2 + 0x44) = sVar8;
  if ((byte)puVar4[0x23] - 3 < 0x62) {
    *(ushort *)(pbVar2 + 0x46) = (ushort)(byte)puVar4[0x23] * 10;
  }
  else {
    pbVar2[0x46] = 100;
    pbVar2[0x47] = 0;
  }
  if (*(byte *)((int)puVar4 + 0x47) - 3 < 0x62) {
    *(ushort *)(pbVar2 + 0x48) = (ushort)*(byte *)((int)puVar4 + 0x47) * 10;
  }
  else {
    pbVar2[0x48] = 100;
    pbVar2[0x49] = 0;
  }
  if ((byte)puVar4[0x24] - 3 < 0x62) {
    *(ushort *)(pbVar2 + 0x4a) = (ushort)(byte)puVar4[0x24] * 10;
  }
  else {
    pbVar2[0x4a] = 100;
    pbVar2[0x4b] = 0;
  }
  if (*(byte *)((int)puVar4 + 0x49) - 3 < 0x62) {
    *(ushort *)(pbVar2 + 0x4c) = (ushort)*(byte *)((int)puVar4 + 0x49) * 10;
  }
  else {
    pbVar2[0x4c] = 100;
    pbVar2[0x4d] = 0;
  }
  if ((byte)puVar4[0x25] < 2) {
    pbVar2[0x4f] = (byte)puVar4[0x25];
  }
  else {
    pbVar2[0x4f] = 0;
  }
  FUN_0800ff84(puVar4,0x8000,0x38);
  iVar9 = FUN_08004dcc(puVar4,8);
  if (iVar9 == 1) {
    puVar12 = puVar4;
  }
  else {
    puVar12 = DAT_0800a06c;
  }
  FUN_08002968(DAT_0800a064 + 4,puVar12,8);
  iVar9 = FUN_08004dcc(puVar13,8);
  if (iVar9 != 1) {
    puVar13 = DAT_0800a070;
  }
  FUN_08002968(DAT_0800a064 + 0xc,puVar13,8);
  puVar13 = puVar4 + 8;
  iVar9 = FUN_08004dcc(puVar13,8);
  if (iVar9 != 1) {
    puVar13 = DAT_0800a074;
  }
  FUN_08002968(DAT_0800a064 + 0x14,puVar13,8);
  puVar13 = puVar4 + 0xc;
  iVar9 = FUN_08004dcc(puVar13,0x10);
  if (iVar9 != 1) {
    puVar13 = DAT_0800a078;
  }
  FUN_08002968(DAT_0800a064 + 0x1c,puVar13,0x10);
  puVar13 = puVar4 + 0x14;
  iVar9 = FUN_08004dcc(puVar13,0x10);
  if (iVar9 != 1) {
    puVar13 = DAT_0800a07c;
  }
  FUN_08002968(DAT_0800a064 + 0x2e,puVar13,0x10);
  FUN_0800ff84(puVar4,0x9000,8);
  puVar6 = DAT_0800a18c;
  bVar7 = (byte)*puVar4;
  if (1 < bVar7) {
    bVar7 = 0;
  }
  DAT_0800a18c[0x1f] = bVar7;
  uVar11 = 0;
  do {
    uVar14 = uVar11 * 3 + 1 & 0xff;
    if (*(byte *)((int)puVar4 + uVar14) < 2) {
      puVar6[uVar11 + 0x20] = *(byte *)((int)puVar4 + uVar14);
    }
    else {
      puVar6[uVar11 + 0x20] = 0;
    }
    puVar6[uVar11 + 0x22] = *(byte *)((int)puVar4 + uVar14 + 1);
    uVar10 = uVar11 + 1 & 0xff;
    puVar6[uVar11 + 0x24] = *(byte *)((int)puVar4 + uVar14 + 2);
    uVar11 = uVar10;
  } while (uVar10 < 2);
  FUN_0800ff84(puVar4,0xb000,8);
  pbVar5 = DAT_0800a190;
  uVar3 = *puVar4;
  *DAT_0800a190 = (byte)uVar3;
  if (6 < (byte)uVar3) {
    *pbVar5 = 0;
  }
  *DAT_0800a198 = DAT_0800a194;
  *DAT_0800a1a0 = DAT_0800a19c;
  bVar7 = *(byte *)((int)puVar4 + 1);
  if (1 < bVar7) {
    bVar7 = 1;
  }
  *DAT_0800a1a4 = bVar7;
  if ((byte)puVar4[1] < 2) {
    *DAT_0800a1a8 = (byte)puVar4[1];
  }
  else {
    *DAT_0800a1a8 = 0;
  }
  if (*(byte *)((int)puVar4 + 3) < 2) {
    *DAT_0800a1ac = *(byte *)((int)puVar4 + 3);
  }
  else {
    *DAT_0800a1ac = 0;
  }
  if ((byte)puVar4[2] < 2) {
    *DAT_0800a1b0 = (byte)puVar4[2];
  }
  else {
    *DAT_0800a1b0 = 0;
  }
  bVar7 = *(byte *)((int)puVar4 + 5);
  if (1 < bVar7) {
    bVar7 = 1;
  }
  *DAT_0800a1b4 = bVar7;
  bVar7 = (byte)puVar4[3];
  if (1 < bVar7) {
    bVar7 = 1;
  }
  *DAT_0800a1b8 = bVar7;
  if (puVar6[0x19] == '\0') {
    *puVar6 = puVar6[4];
    puVar6[1] = puVar6[5];
  }
  FUN_0800ff84(DAT_0800a1bc,0x2000,0xcf);
  FUN_0800ff84(DAT_0800a1c0,0xa000,0x10);
  puVar6 = DAT_0800a1c4;
  iVar9 = DAT_0800a1c0;
  *DAT_0800a1c4 = 0;
  uVar11 = 0;
  do {
    if (*(int *)(iVar9 + uVar11 * 4) != -1) {
      *puVar6 = 1;
      return;
    }
    uVar11 = uVar11 + 1 & 0xff;
  } while (uVar11 < 4);
  return;
}



// ==== 0800a1c8  FUN_0800a1c8  (66 bytes, 1 xrefs)

undefined4 FUN_0800a1c8(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  FUN_0800ff84(&local_10,0x11000,8);
  if ((local_10 == DAT_0800a20c) && ((short)local_c == 0x400)) {
    FUN_0800ff84(DAT_0800a214,DAT_0800a210,0x80);
    FUN_0800ff84(DAT_0800a218,DAT_0800a210 + 0x80,0x380);
    return 1;
  }
  return 0;
}



// ==== 0800a21c  FUN_0800a21c  (146 bytes, 4 xrefs)

void FUN_0800a21c(uint param_1,uint param_2,int *param_3,undefined2 *param_4,byte *param_5,
                 uint param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = param_1 + param_2;
  *param_5 = 0;
  if (uVar2 < 0x100000) {
    uVar3 = 0;
    while ((iVar4 = uVar3 * 4, param_1 < *(uint *)(DAT_0800a2b0 + iVar4) ||
           (*(uint *)(iVar4 + DAT_0800a2b0 + 4) <= param_1))) {
      uVar3 = uVar3 + 1 & 0xffff;
      if (0x10 < uVar3) {
        return;
      }
    }
    *param_5 = 1;
    *param_3 = *(int *)(DAT_0800a2b4 + uVar3 * 4) + (param_1 - *(int *)(DAT_0800a2b0 + iVar4));
    while( true ) {
      uVar3 = uVar3 + 1 & 0xffff;
      if (0x11 < uVar3) {
        return;
      }
      iVar4 = uVar3 * 4;
      if (uVar2 - 1 < *(uint *)(DAT_0800a2b0 + iVar4)) break;
      iVar1 = *(uint *)(DAT_0800a2b0 + iVar4) - param_1;
      *param_4 = (short)iVar1;
      param_2 = param_2 - iVar1 & 0xffff;
      param_1 = *(uint *)(DAT_0800a2b0 + iVar4);
      if (param_6 <= *param_5) {
        return;
      }
      param_3[1] = *(int *)(DAT_0800a2b4 + iVar4);
      param_3 = param_3 + 1;
      *param_5 = *param_5 + 1;
      param_4 = param_4 + 1;
    }
    *param_4 = (short)param_2;
  }
  return;
}



// ==== 0800a2b8  FUN_0800a2b8  (108 bytes, 2 xrefs)

void FUN_0800a2b8(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *DAT_0800a324;
  if (*(byte *)(iVar2 + 0x1e) < 0xcf) {
    if (*(char *)(iVar2 + 0x33) == '\x01') {
      *DAT_0800a328 = 0;
      goto LAB_0800a2da;
    }
    uVar1 = *(undefined1 *)(*(int *)(iVar2 + 0x10) + 4);
  }
  else {
    uVar1 = 1;
  }
  *DAT_0800a328 = uVar1;
LAB_0800a2da:
  *DAT_0800a32c = 0;
  *DAT_0800a330 = 0;
  FUN_0800299a(DAT_0800a334,0x10);
  *DAT_0800a338 = 0;
  *DAT_0800a33c = 0;
  *DAT_0800a340 = 0;
  *DAT_0800a344 = 0;
  *DAT_0800a348 = 0;
  *DAT_0800a34c = 0;
  *DAT_0800a350 = 0;
  *DAT_0800a354 = 0;
  *DAT_0800a358 = 0;
  *DAT_0800a35c = 0;
  *DAT_0800a360 = 0;
  *DAT_0800a364 = 0;
  *DAT_0800a368 = 0;
  return;
}



// ==== 0800a36c  FUN_0800a36c  (350 bytes, 3 xrefs)

void FUN_0800a36c(int param_1)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int *piVar6;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  int extraout_r3;
  
  if (*DAT_0800a4cc != '\x01') {
    if (*DAT_0800a4d0 == '\x01') {
      FUN_0800e0fc(0);
    }
    pcVar4 = DAT_0800a4d4;
    if (*DAT_0800a4d4 != '\0') {
      DAT_50000028 = 0x100;
      FUN_080123ae(5);
      FUN_0800f800();
      *DAT_0800a4d8 = 0;
      *DAT_0800a4dc = 0;
      *DAT_0800a4e0 = 0;
      FUN_080123ae(0x14);
      *pcVar4 = '\0';
    }
    *(undefined1 *)(DAT_0800a4e8 + (uint)(*(char *)(DAT_0800a4e4 + 8) == '\0')) = 0;
    DAT_50000018 = 0x100;
    *DAT_0800a4ec = 1;
    FUN_0800904c();
    pcVar4 = DAT_0800a4fc;
    puVar5 = DAT_0800a4f8;
    cVar3 = *DAT_0800a4f0;
    if (cVar3 != '\0') {
      cVar1 = *(char *)(extraout_r3 + 0x1e);
      if (cVar1 == '\0') {
        if (*DAT_0800a4fc == '\0') {
          *DAT_0800a4f4 = 500;
          *puVar5 = 0;
          *pcVar4 = '\x01';
        }
      }
      else if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
        *DAT_0800a4f4 = 0;
        *puVar5 = 0;
      }
      *DAT_0800a500 = 1;
    }
    piVar6 = DAT_0800a504;
    iVar8 = *DAT_0800a504;
    if ((0xce < *(byte *)(iVar8 + 0x1e)) && (*DAT_0800a508 == '\x01')) {
      bVar2 = *DAT_0800a50c;
      *(byte *)(iVar8 + 0x1e) = bVar2 - 0x31;
      iVar9 = (uint)bVar2 * 4;
      **(undefined4 **)(iVar8 + 0x10) = *(undefined4 *)(DAT_0800a510 + iVar9);
      **(undefined4 **)(*piVar6 + 0x14) = *(undefined4 *)(DAT_0800a510 + iVar9);
      *(undefined1 *)(extraout_r3 + (uint)*(byte *)(extraout_r3 + 8)) =
           *(undefined1 *)(*piVar6 + 0x1e);
      *DAT_0800a514 = 500;
      *DAT_0800a518 = 0;
    }
    puVar7 = DAT_0800a520;
    if ((cVar3 == '\0') && (*(char *)(extraout_r3 + 0x1a) != '\0')) {
      *DAT_0800a51c = 1;
      *puVar7 = 0x168;
      *DAT_0800a524 = 0;
    }
    if (*(char *)(*piVar6 + 0x33) == '\x01') {
      FUN_0800ee64(0x48,DAT_0800a52c);
      *DAT_0800a530 = 0;
    }
    else {
      FUN_0800ee64(0x48,(uint)*(byte *)(DAT_0800a4e4 + 0x93) * 0x10 + 0xb000 |
                        (uint)*(byte *)(DAT_0800a4e4 + 0x94));
    }
    FUN_0800e280(1);
    FUN_0800b2fc(param_1);
    if ((param_1 == 2) || (*DAT_0800a4d0 == '\x01')) {
      FUN_0800b26c(0);
      return;
    }
    *DAT_0800a528 = 1;
  }
  return;
}



// ==== 0800a534  FUN_0800a534  (54 bytes, 5 xrefs)

void FUN_0800a534(void)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  _local_10 = CONCAT13(DAT_0800a56c[1],
                       CONCAT12(DAT_0800a56c[2],CONCAT11(DAT_0800a56c[4],*DAT_0800a56c)));
  _local_c = CONCAT13(DAT_0800a56c[7],
                      CONCAT12(DAT_0800a56c[6],CONCAT11(DAT_0800a56c[3],DAT_0800a56c[5])));
  FUN_08010050(&local_10,0x5000,8,1);
  return;
}



// ==== 0800a570  FUN_0800a570  (194 bytes, 6 xrefs)

void FUN_0800a570(uint param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  byte local_1e;
  byte local_1d;
  byte local_1c;
  byte local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined4 *local_18;
  
  if (param_1 < 0xcf) {
    iVar1 = param_1 << 4;
    if (199 < param_1) {
      if (param_2 == 0) {
        iVar1 = 0x900;
      }
      else {
        iVar1 = 0x8f0;
      }
      iVar1 = param_1 * 0x20 - iVar1;
    }
    local_18 = param_3 + 0xd;
    if ((param_4 == 2) || (199 < param_1)) {
      local_28 = *param_3;
      local_24 = param_3[6];
      local_20 = *(undefined1 *)((int)param_3 + 5);
      local_1f = *(undefined1 *)((int)param_3 + 0xd);
      local_1e = *(char *)(param_3 + 3) << 4 | *(byte *)(param_3 + 1);
      local_1d = *(char *)((int)param_3 + 0x32) << 4 | *(byte *)((int)param_3 + 0x1f);
      local_1c = *(byte *)((int)param_3 + 0x29) | *(char *)((int)param_3 + 0x31) << 4 |
                 *(char *)((int)param_3 + 0x27) << 2 | *(char *)((int)param_3 + 0x2b) << 1;
      local_1b = *(char *)(param_3 + 0xc) << 1 | *(byte *)((int)param_3 + 0x2f);
      local_1a = *(undefined1 *)((int)param_3 + 0x26);
      local_19 = *(undefined1 *)((int)param_3 + 0x2a);
      FUN_08010050(&local_28,iVar1,0x10,0);
      FUN_0800a890(param_1,param_3,1);
      if (199 < param_1) {
        return;
      }
    }
    else if (param_4 != 3) {
      return;
    }
    FUN_08010050(local_18,param_1 * 0x10 + 0xe000,0x10,0);
  }
  return;
}



// ==== 0800a634  FUN_0800a634  (62 bytes, 3 xrefs)

void FUN_0800a634(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = param_3;
  uStack_c = param_4;
  FUN_0800298c(&local_10,8,0xff);
  local_10 = *(undefined4 *)(DAT_0800a674 + 0x2c);
  FUN_08010050(&local_10,0x6000,8,0);
  FUN_08010050(DAT_0800a678,0x3000,0x28,0);
  return;
}



// ==== 0800a67c  FUN_0800a67c  (450 bytes, 5 xrefs)

void FUN_0800a67c(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined4 in_r3;
  
  puVar1 = DAT_0800a840;
  FUN_0800298c(DAT_0800a840,0xb0,0xff,in_r3,in_r3);
  puVar2 = DAT_0800a844;
  *puVar1 = DAT_0800a844[3];
  puVar1[1] = puVar2[-0x30];
  puVar1[2] = puVar2[-0x2f];
  puVar1[3] = puVar2[0x52];
  puVar1[4] = puVar2[-0x2e];
  puVar1[5] = puVar2[-0x2d];
  puVar1[6] = puVar2[-0x2c];
  puVar1[7] = puVar2[1];
  puVar1[8] = 0xff;
  puVar1[9] = puVar2[-0x29];
  puVar1[10] = puVar2[-0x25];
  puVar1[0xb] = puVar2[-0x24];
  puVar1[0xc] = puVar2[-0x26];
  puVar1[0xd] = puVar2[-0x23];
  puVar1[0xe] = puVar2[-0x28];
  puVar1[0xf] = puVar2[-0x27];
  FUN_08010050(puVar1,0x4000,0x10,0);
  *puVar1 = puVar2[-0x2a];
  puVar1[1] = puVar2[-3];
  puVar1[2] = puVar2[-2];
  puVar1[3] = puVar2[-1];
  puVar1[4] = *puVar2;
  puVar1[5] = puVar2[-0x22];
  puVar1[6] = puVar2[-8];
  puVar1[7] = puVar2[-6];
  FUN_08002968(puVar1 + 8,puVar2 + -0x34,4);
  puVar1[0x10] = puVar2[-0x2b];
  puVar1[0x11] = puVar2[0x55];
  puVar1[0x18] = puVar2[-7];
  puVar1[0x19] = puVar2[-5];
  puVar1[0x1a] = puVar2[-4];
  puVar1[0x1b] = puVar2[-0x37];
  FUN_08002968(puVar1 + 0x20,puVar2 + 0x58);
  puVar1[0x40] = puVar2[0x4e];
  puVar1[0x41] = puVar2[0x40];
  puVar1[0x42] = puVar2[0x41];
  puVar1[0x43] = puVar2[0x42];
  puVar1[0x44] = puVar2[0x43];
  uVar3 = FUN_080028f0(*(undefined2 *)(puVar2 + 0x44),10);
  puVar1[0x45] = uVar3;
  uVar3 = FUN_080028f0(*(undefined2 *)(puVar2 + 0x46),10);
  puVar1[0x46] = uVar3;
  uVar3 = FUN_080028f0(*(undefined2 *)(puVar2 + 0x48),10);
  puVar1[0x47] = uVar3;
  uVar3 = FUN_080028f0(*(undefined2 *)(puVar2 + 0x4a),10);
  puVar1[0x48] = uVar3;
  uVar3 = FUN_080028f0(*(undefined2 *)(puVar2 + 0x4c),10);
  puVar1[0x49] = uVar3;
  puVar1[0x4a] = puVar2[0x4f];
  FUN_08010050(puVar1,0x7000,0x50,0);
  *puVar1 = puVar2[-0x21];
  puVar1[1] = puVar2[-0x20];
  puVar1[2] = puVar2[-0x1e];
  puVar1[3] = puVar2[-0x1c];
  puVar1[4] = puVar2[-0x1f];
  puVar1[5] = puVar2[-0x1d];
  puVar1[6] = puVar2[-0x1b];
  puVar1[7] = 0xff;
  FUN_08010050(puVar1,0x9000,8,0);
  *puVar1 = *DAT_0800a848;
  puVar1[1] = *DAT_0800a84c;
  puVar1[2] = *DAT_0800a850;
  puVar1[3] = *DAT_0800a854;
  puVar1[4] = *DAT_0800a858;
  puVar1[5] = *DAT_0800a85c;
  puVar1[6] = *DAT_0800a860;
  puVar1[7] = 0xff;
  FUN_08010050(puVar1,0xb000,8,0);
  return;
}



// ==== 0800a864  FUN_0800a864  (36 bytes, 1 xrefs)

void FUN_0800a864(int param_1,undefined4 param_2)

{
  FUN_08010050(param_2,param_1 * 0x10 + DAT_0800a888,0x10,0);
  FUN_08002968(param_1 * 0x10 + DAT_0800a88c + 0x98,param_2,0x10);
  return;
}



// ==== 0800a890  FUN_0800a890  (90 bytes, 3 xrefs)

void FUN_0800a890(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int local_20;
  int local_1c;
  undefined4 uStack_18;
  
  if (param_1 < 0xcf) {
    local_20 = param_2;
    local_1c = param_3;
    uStack_18 = param_4;
    FUN_0800ff84(&local_1c,param_1 + 0x2000,1);
    if (param_3 == 1) {
      bVar1 = *(char *)(param_2 + 0x2c) << 7 | *(char *)(param_2 + 0x2d) << 6 |
              *(byte *)(param_2 + 0x2e);
      local_20 = CONCAT31(local_20._1_3_,bVar1);
      if ((byte)local_1c == bVar1) {
        return;
      }
    }
    else {
      local_20 = CONCAT31(local_20._1_3_,0xff);
    }
    FUN_08010050(&local_20,param_1 + 0x2000,1,0);
    *(undefined1 *)(DAT_0800a8ec + param_1) = (undefined1)local_20;
  }
  return;
}



// ==== 0800a8f0  FUN_0800a8f0  (126 bytes, 2 xrefs)

void FUN_0800a8f0(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (*(char *)(DAT_0800a970 + 0x1b) == '\x01') {
    FUN_0800ed94();
  }
  else if (*(char *)(DAT_0800a970 + 0x1b) == '\x02') {
    FUN_0800ecbc();
  }
  if ((*DAT_0800a974 == '\0') &&
     ((*(char *)(*DAT_0800a978 + 0x30) == '\x02' || (*(char *)(*DAT_0800a978 + 0x30) == '\x03')))) {
    FUN_0800ec1c();
    puVar2 = DAT_0800a97c;
    iVar1 = DAT_0800a970;
    if (*(char *)(DAT_0800a970 + 0x6e) == '\x01') {
      DAT_50000018 = 0x100;
      *DAT_0800a97c = 1;
      FUN_080123ae(0x3c);
    }
    FUN_0800ec8c(*(undefined1 *)(iVar1 + 0x6e));
    FUN_0800ec2c(DAT_0800a970 + 0x4e,0,*(undefined2 *)(iVar1 + 0x66),*(undefined2 *)(iVar1 + 0x68),
                 *(undefined2 *)(iVar1 + 0x6a),*(undefined2 *)(iVar1 + 0x6c));
    DAT_50000028 = 0x100;
    *puVar2 = 0;
  }
  FUN_0800df70(1);
  return;
}



// ==== 0800a980  FUN_0800a980  (36 bytes, 4 xrefs)

void FUN_0800a980(void)

{
  char cVar1;
  
  cVar1 = *(char *)(*(int *)(*DAT_0800a9a4 + 0x14) + 4);
  if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
    FUN_0800eac8();
  }
  else {
    FUN_0800eae4();
  }
  FUN_080123ae(200);
  return;
}



// ==== 0800a9a8  FUN_0800a9a8  (78 bytes, 6 xrefs)

void FUN_0800a9a8(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_0800299a(param_1,0x44,param_3,param_4,param_4);
  *(char *)((int)param_1 + 0x2e) = (char)param_3;
  *(undefined1 *)(param_1 + 0xb) = 1;
  *(undefined1 *)((int)param_1 + 0x2d) = 1;
  *(undefined1 *)((int)param_1 + 0x26) = 5;
  *(short *)(param_1 + 7) = (short)DAT_0800a9f8;
  *(char *)((int)param_1 + 0x1e) = (char)param_2;
  *(undefined1 *)((int)param_1 + 0x29) = 0;
  *(undefined1 *)((int)param_1 + 0x27) = 2;
  *param_1 = param_4;
  param_1[2] = param_4;
  uVar1 = DAT_0800a9fc;
  param_1[4] = param_1;
  param_1[6] = uVar1;
  param_1[5] = param_1 + 2;
  if (param_2 == 0xc9) {
    *(undefined1 *)((int)param_1 + 0x32) = 1;
    *(undefined1 *)((int)param_1 + 0x33) = 1;
  }
  FUN_08003f98(param_1);
  return;
}



// ==== 0800aa00  FUN_0800aa00  (134 bytes, 1 xrefs)

void FUN_0800aa00(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 in_r3;
  
  puVar1 = DAT_0800aa88;
  puVar2 = DAT_0800aa88 + -0x40;
  DAT_0800aa88[3] = 0;
  puVar1[-0x30] = 4;
  puVar1[-0x2f] = 2;
  puVar1[0x52] = 1;
  puVar1[-0x2e] = 0;
  puVar1[-0x2d] = 0;
  puVar1[-0x2c] = 5;
  puVar1[1] = 2;
  puVar1[-0x29] = 0;
  puVar1[-0x25] = 0;
  puVar1[-0x24] = 4;
  puVar1[-0x26] = 1;
  puVar1[-0x23] = 5;
  puVar1[-0x28] = 1;
  puVar1[-0x27] = 1;
  puVar1[-0x2a] = 1;
  puVar1[-3] = 3;
  puVar1[-2] = 8;
  puVar1[-1] = 1;
  *puVar1 = 6;
  puVar1[-0x22] = 1;
  puVar1[-8] = 0;
  puVar1[-6] = 2;
  puVar1[-0x2b] = 1;
  puVar1[0x55] = 0;
  puVar1[-7] = 1;
  puVar1[-5] = 0;
  puVar1[-4] = 0;
  puVar1[-0x37] = 0;
  puVar1[0x4e] = 1;
  puVar1[0x40] = 0x2a;
  puVar1[0x41] = 0x23;
  puVar1[0x42] = 0;
  puVar1[0x43] = 5;
  *(undefined2 *)(puVar1 + 0x44) = 300;
  *(undefined2 *)(puVar1 + 0x46) = 100;
  *(undefined2 *)(puVar1 + 0x48) = 100;
  *(undefined2 *)(puVar1 + 0x4a) = 100;
  *(undefined2 *)(puVar1 + 0x4c) = 100;
  puVar1[0x4f] = 0;
  FUN_0800299a(puVar1 + 0x58,0x20,puVar2,0,in_r3);
  return;
}



// ==== 0800aa8c  FUN_0800aa8c  (80 bytes, 2 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x0800aae6

// ==== 0800ae98  FUN_0800ae98  (62 bytes, 1 xrefs)

void FUN_0800ae98(void)

{
  ushort uVar1;
  int iVar2;
  undefined1 auStack_28 [12];
  uint local_1c;
  ushort local_18 [2];
  short local_14 [2];
  undefined1 auStack_10 [8];
  
  FUN_0800f5b0(auStack_28);
  iVar2 = FUN_0800e616();
  uVar1 = *DAT_0800aed8;
  FUN_0800e64e(local_18);
  FUN_0800dcfc(local_14,auStack_10);
  local_18[0] = local_18[0] + local_14[0];
  FUN_08002956(((iVar2 + (uint)uVar1) * 0x10000 | (uint)local_18[0]) ^ local_1c);
  return;
}



// ==== 0800aedc  FUN_0800aedc  (86 bytes, 2 xrefs)

void FUN_0800aedc(int param_1,undefined1 param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  
  FUN_08004c74();
  puVar2 = (undefined4 *)*DAT_0800af34;
  bVar1 = *(byte *)((int)puVar2 + 0x1e);
  *DAT_0800af38 = bVar1;
  *DAT_0800af3c = param_2;
  *DAT_0800af40 = 0;
  if (bVar1 < 200) {
    if (param_1 == 1) {
      *DAT_0800af48 = bVar1;
    }
    FUN_0800b874();
  }
  else {
    if (param_1 == 1) {
      *DAT_0800af44 = *puVar2;
    }
    FUN_0800bce0();
  }
  *DAT_0800af4c = 0x32;
  *DAT_0800af50 = 0;
  *DAT_0800af54 = 0;
  *DAT_0800af58 = 0;
  *DAT_0800af5c = 0;
  return;
}



// ==== 0800af60  FUN_0800af60  (92 bytes, 3 xrefs)

void FUN_0800af60(ushort param_1,short param_2,int param_3)

{
  bool bVar1;
  char *pcVar2;
  undefined1 *puVar3;
  ushort uVar4;
  undefined2 uVar5;
  
  pcVar2 = DAT_0800afc0;
  DAT_50000028 = 0x100;
  *DAT_0800afbc = 0;
  if (*pcVar2 == '\0') {
    uVar5 = 0x78;
  }
  else {
    uVar5 = 10;
  }
  *DAT_0800afc4 = uVar5;
  *DAT_0800afc8 = 0;
  puVar3 = DAT_0800afcc;
  *pcVar2 = (char)param_2;
  *puVar3 = 0;
  *DAT_0800afd0 = 0;
  *DAT_0800afd4 = 0;
  if (param_3 != 1) {
    uVar4 = param_1 + param_2;
    param_1 = *(ushort *)(DAT_0800afd8 + 0x34);
    if ((uVar4 <= *(ushort *)(DAT_0800afd8 + 0x36)) &&
       (bVar1 = uVar4 < param_1, param_1 = uVar4, bVar1)) {
      param_1 = *(ushort *)(DAT_0800afd8 + 0x36);
    }
  }
  *(ushort *)(DAT_0800afd8 + 0x30) = param_1;
  FUN_0800e228();
  return;
}



// ==== 0800afdc  FUN_0800afdc  (184 bytes, 1 xrefs)

void FUN_0800afdc(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  
  FUN_0800b260();
  FUN_08004c74();
  piVar3 = DAT_0800b094;
  iVar6 = *DAT_0800b094;
  if (0xce < *(byte *)(iVar6 + 0x1e)) {
    *(undefined1 *)(iVar6 + 0x1e) = 0xcd;
  }
  uVar1 = *(undefined1 *)(iVar6 + 0x26);
  uVar2 = *(undefined2 *)(iVar6 + 0x1c);
  FUN_0800a9a8(iVar6,*(undefined1 *)(iVar6 + 0x1e),*(undefined1 *)(iVar6 + 0x2e),
               **(undefined4 **)(iVar6 + 0x10));
  iVar6 = *piVar3;
  *(undefined1 *)(iVar6 + 0x26) = uVar1;
  *(undefined2 *)(iVar6 + 0x1c) = uVar2;
  FUN_080049a8(1);
  *DAT_0800b098 = 0;
  puVar4 = DAT_0800b0a4;
  if (*DAT_0800b09c == '\x01') {
    *DAT_0800b0a0 = 1;
    puVar5 = DAT_0800b0a8;
    iVar6 = *piVar3;
    *puVar4 = **(undefined4 **)(iVar6 + 0x10);
    *puVar5 = *(undefined1 *)(iVar6 + 0x26);
    FUN_08004d04();
    FUN_0800e038(*puVar4);
  }
  else {
    *DAT_0800b0a0 = 0;
    *puVar4 = 0xffffffff;
    FUN_08004d04();
    FUN_0800e050();
  }
  *DAT_0800b0ac = 0x15;
  *DAT_0800b0b0 = 0xff;
  *DAT_0800b0b4 = 0xff;
  *DAT_0800b0b8 = 0;
  *DAT_0800b0bc = 0;
  *DAT_0800b0c0 = 0;
  *DAT_0800b0c4 = 0;
  *DAT_0800b0c8 = 0;
  *DAT_0800b0cc = 0;
  *DAT_0800b0d0 = 0;
  *DAT_0800b0d4 = 0;
  *DAT_0800b0d8 = 0;
  *DAT_0800b0dc = 0;
  *DAT_0800b0e0 = 0;
  return;
}



// ==== 0800b0e4  FUN_0800b0e4  (104 bytes, 2 xrefs)

void FUN_0800b0e4(void)

{
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  *DAT_0800b14c = 1;
  pcVar2 = DAT_0800b158;
  pcVar3 = DAT_0800b154;
  if (*(char *)(DAT_0800b150 + 0x12) != '\0') {
    if (*(char *)(DAT_0800b150 + -0x66) != '\0') {
      if (*(byte *)(DAT_0800b150 + -0x80) < 0xcf) {
        if (*(byte *)(DAT_0800b150 + -0x7f) < 0xcf) goto LAB_0800b12e;
        iVar4 = 1;
      }
      else {
        iVar4 = 0;
      }
      if (*DAT_0800b154 != '\x01') {
        *DAT_0800b158 = ((byte *)(DAT_0800b150 + -0x80))[iVar4 * 0x44 + 0xd6] + 0x31;
      }
      *pcVar3 = '\x01';
      return;
    }
    bVar1 = *(byte *)(*DAT_0800b15c + 0x1e);
    if (0xce < bVar1) {
      *DAT_0800b154 = '\x01';
      *pcVar2 = bVar1 + 0x31;
      *DAT_0800b160 = 0x32;
      pcVar3 = DAT_0800b164;
    }
  }
LAB_0800b12e:
  *pcVar3 = '\0';
  return;
}



// ==== 0800b168  FUN_0800b168  (116 bytes, 4 xrefs)

void FUN_0800b168(void)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  *DAT_0800b1dc = 0;
  piVar4 = DAT_0800b1e8;
  iVar3 = DAT_0800b1e4;
  if (*DAT_0800b1e0 != '\x01') {
    if (*DAT_0800b1ec < 200) {
      uVar5 = (uint)*(byte *)(DAT_0800b1e4 + 8);
      uVar2 = *DAT_0800b1f4;
      *(undefined1 *)(DAT_0800b1e4 + uVar5 + 4) = uVar2;
      *(undefined1 *)(iVar3 + uVar5) = uVar2;
      FUN_08009938(uVar5,2);
    }
    else {
      *(undefined4 *)*DAT_0800b1e8 = *DAT_0800b1f0;
      FUN_080041c4();
      FUN_08003f98(*piVar4);
    }
    FUN_080049a8(1);
    *DAT_0800b1f8 = 1;
    return;
  }
  bVar1 = *(byte *)(*DAT_0800b1e8 + 0x1e);
  if (bVar1 < 200) {
    FUN_0800a534();
    return;
  }
  FUN_080041c4();
  FUN_08003f98(*piVar4);
  FUN_0800a570(bVar1,*(undefined1 *)(iVar3 + 8),*piVar4,1);
  return;
}



// ==== 0800b1fc  FUN_0800b1fc  (70 bytes, 4 xrefs)

void FUN_0800b1fc(void)

{
  int iVar1;
  
  *DAT_0800b244 = 0;
  iVar1 = DAT_0800b24c;
  if (*DAT_0800b248 == '\x01') {
    *(undefined1 *)(DAT_0800b24c + 0xf) = 1;
    *(undefined1 *)(iVar1 + 0xe) = 0;
  }
  FUN_08004f80();
  FUN_0800e228(*(undefined2 *)(DAT_0800b24c + 0x10));
  FUN_0800a634();
  *DAT_0800b250 = 0;
  *DAT_0800b254 = 0;
  *DAT_0800b258 = 0;
  DAT_50000018 = 0x100;
  *DAT_0800b25c = 1;
  return;
}



// ==== 0800b260  FUN_0800b260  (12 bytes, 3 xrefs)

void FUN_0800b260(void)

{
  FUN_0800e06c();
  FUN_0800e060();
  return;
}



// ==== 0800b26c  FUN_0800b26c  (84 bytes, 17 xrefs)

void FUN_0800b26c(uint param_1)

{
  byte *pbVar1;
  
  pbVar1 = DAT_0800b2c0;
  if (param_1 != 0xff) {
    if (*DAT_0800b2c0 != param_1) {
      *DAT_0800b2c4 = 0;
      *DAT_0800b2c8 = 0;
      *DAT_0800b2cc = 0;
      *DAT_0800b2d0 = 0;
      *DAT_0800b2d4 = 0;
      *DAT_0800b2d8 = 0;
      *DAT_0800b2dc = 0;
      *DAT_0800b2e0 = 0;
      *DAT_0800b2e4 = 0;
      *DAT_0800b2e8 = 0;
      if (*DAT_0800b2ec == '\x01') {
        *DAT_0800b2ec = '\0';
        *DAT_0800b2f0 = 1;
      }
      *DAT_0800b2f4 = 0;
    }
    *pbVar1 = (byte)param_1;
    *DAT_0800b2f8 = 1;
  }
  return;
}



// ==== 0800b2fc  FUN_0800b2fc  (604 bytes, 16 xrefs)

void FUN_0800b2fc(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  ushort uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 auStack_28 [20];
  
  cVar1 = *DAT_0800b558;
  bVar8 = false;
  *DAT_0800b558 = (char)param_1;
  if (cVar1 == '\x05') {
    if (param_1 == 5) goto LAB_0800b33a;
    FUN_0800b750();
    *DAT_0800b55c = 0;
    FUN_0800da58();
  }
  puVar3 = DAT_0800b560;
  if (param_1 == 0) {
    if (*DAT_0800b570 != '\0') {
      FUN_08004ef8();
    }
    puVar6 = DAT_0800b574;
    if (cVar1 == '\x01') {
      *DAT_0800b574 = 0;
      puVar6[1] = 0;
    }
    else if ((cVar1 != '\x04') && (cVar1 != '\x01')) goto LAB_0800b54a;
    if (*DAT_0800b578 == '\x01') {
      *DAT_0800b57c = 500;
    }
    if ((*DAT_0800b580 == '\x01') || (*DAT_0800b580 == '\x02')) {
      *DAT_0800b584 = puVar3[3] * '\x02' + '\x01';
    }
    goto LAB_0800b54a;
  }
  if (param_1 != 1) {
    bVar8 = param_1 == 3;
    do {
      if (bVar8) goto LAB_0800b544;
      bVar8 = true;
    } while ((param_1 == 4) || (bVar8 = true, param_1 == 2));
    if (param_1 != 5) {
      return;
    }
LAB_0800b33a:
    *DAT_0800b564 = (ushort)(byte)DAT_0800b560[-100] * 10;
    *DAT_0800b55c = 1;
    FUN_0800e502();
    FUN_0800eb00();
    FUN_0800e660(0);
    *DAT_0800b568 = 0;
    *DAT_0800b56c = 1;
    FUN_0800b26c(0);
    return;
  }
  if (*DAT_0800b578 == '\x01') {
    FUN_0800e0fc(0);
  }
  if ((*DAT_0800b588 == '\x01') && (DAT_0800b560[-0x47] != '\x01')) {
    *DAT_0800b588 = '\x02';
    FUN_0800c2d4();
    DAT_50000028 = 0x100;
    FUN_080123ae(0x14);
    FUN_0800deec(500,0);
    FUN_080123ae(2);
    DAT_50000018 = 0x100;
    *DAT_0800b58c = 1;
    FUN_080123ae(0x3c);
    FUN_0800df50();
LAB_0800b516:
    *DAT_0800b5ac = 0;
  }
  else {
    FUN_0800c2d4();
    FUN_08004bc4();
    FUN_0800e660(6,1);
    cVar1 = *DAT_0800b570;
    puVar6 = DAT_0800b560 + -0x3c;
    if (cVar1 == '\x01') {
      bVar8 = true;
      if (*DAT_0800b590 == '\x02') {
        puVar6 = DAT_0800b594;
      }
      else {
        uVar2 = *puVar3;
        puVar7 = DAT_0800b594;
LAB_0800b472:
        bVar8 = true;
        FUN_08011998(auStack_28,s__s_c_s_0800b5a0,puVar7,uVar2,puVar6);
        puVar6 = auStack_28;
      }
    }
    else if (cVar1 == '\x02') {
      bVar8 = true;
      puVar6 = DAT_0800b598;
    }
    else {
      if (cVar1 == '\x03') {
        uVar2 = *puVar3;
        puVar7 = puVar6;
        puVar6 = DAT_0800b59c;
        goto LAB_0800b472;
      }
      puVar6 = (undefined1 *)0x1;
      if ((*DAT_0800b580 == '\0') &&
         ((*(char *)(*DAT_0800b5a8 + 0x30) == '\x01' || (*(char *)(*DAT_0800b5a8 + 0x30) == '\x03'))
         )) {
        bVar8 = true;
        puVar6 = DAT_0800b560 + -0x24;
      }
    }
    *DAT_0800b570 = '\0';
    if (bVar8) {
      FUN_0800ec1c();
      if (puVar3[0xe] == '\x01') {
        DAT_50000018 = 0x100;
        *DAT_0800b58c = 1;
        uVar4 = *(ushort *)(puVar3 + 4);
        if (uVar4 < 0x3c) {
          uVar4 = 0x3c;
        }
      }
      else {
        uVar4 = *(ushort *)(puVar3 + 4);
      }
      FUN_080123ae(uVar4);
      FUN_0800ec8c(puVar3[0xe]);
      FUN_0800ec2c(puVar6,1,*(undefined2 *)(puVar3 + 6),*(undefined2 *)(puVar3 + 8),
                   *(undefined2 *)(puVar3 + 10),*(undefined2 *)(puVar3 + 0xc));
      DAT_50000028 = 0x100;
      *DAT_0800b58c = 0;
      FUN_0800df70();
    }
    if (*DAT_0800b588 != '\0') {
      if (*DAT_0800b588 == '\x03') {
        uVar5 = DAT_0800b5b0;
      }
      else {
        uVar5 = 500;
      }
      FUN_0800dfb0(1,uVar5);
      FUN_080123ae(2);
      DAT_50000018 = 0x100;
      *DAT_0800b58c = 1;
      goto LAB_0800b516;
    }
    if ((*(char *)(*DAT_0800b5a8 + 0x2a) == '\0') || (*DAT_0800b5b4 == '\0')) {
      FUN_0800e4d8();
    }
    else {
      FUN_0800e408(*(char *)(*DAT_0800b5a8 + 0x2a) + -1);
    }
  }
LAB_0800b544:
  *DAT_0800b57c = 0;
LAB_0800b54a:
  *DAT_0800b5b8 = 0;
  *DAT_0800b5bc = 1000;
  return;
}



// ==== 0800b5c0  FUN_0800b5c0  (292 bytes, 3 xrefs)

void FUN_0800b5c0(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  
  pcVar2 = DAT_0800b6e4;
  if (*DAT_0800b6e4 != '\0') {
    DAT_50000028 = 0x100;
    FUN_080123ae(5);
    FUN_0800f800();
    *DAT_0800b6e8 = 0;
    *DAT_0800b6ec = 0;
    *DAT_0800b6f0 = 0;
    FUN_080123ae(0x14);
    *pcVar2 = '\0';
  }
  iVar3 = DAT_0800b6f4;
  if (*(char *)(DAT_0800b6f4 + 0x1a) != '\0') {
    *DAT_0800b6f8 = 0x168;
    pcVar2 = DAT_0800b700;
    *DAT_0800b6fc = 0;
    if (*pcVar2 == '\0') {
      *(byte *)(iVar3 + 8) = *(byte *)(iVar3 + 9);
      *DAT_0800b704 = (uint)*(byte *)(iVar3 + 9) * 0x44 + iVar3 + 0xb8;
    }
    *pcVar2 = '\x01';
  }
  FUN_08004cd8();
  pcVar2 = DAT_0800b708;
  cVar1 = *DAT_0800b708;
  if (((cVar1 == '\0') || (cVar1 == '\x03')) ||
     ((cVar1 == '\x01' && (*(char *)(DAT_0800b6f4 + 0x39) == '\x01')))) {
    iVar6 = FUN_080045cc(*DAT_0800b70c);
    if (iVar6 == 0) {
      if ((*(char *)(*DAT_0800b70c + 0x31) == '\x01') && (*DAT_0800b710 == '\x04')) {
        uVar7 = 1;
      }
      else if (*DAT_0800b714 == '\0') {
        uVar7 = 2;
      }
      else {
        if (*DAT_0800b714 != '\x06') goto LAB_0800b674;
        uVar7 = 6;
      }
    }
    else {
      uVar7 = 3;
    }
    FUN_0800bea4(uVar7);
    *pcVar2 = '\0';
    FUN_080091ac(2);
  }
  else {
LAB_0800b674:
    puVar5 = DAT_0800b724;
    puVar4 = DAT_0800b720;
    if (*DAT_0800b718 == '\x01') {
      if (*DAT_0800b71c == '\x02') {
        *DAT_0800b724 = 1;
        *puVar4 = 0;
        *DAT_0800b728 = 6;
      }
      else {
        *DAT_0800b720 = 1;
        *puVar5 = 0;
      }
    }
    FUN_0800b2fc(1);
    if (*pcVar2 == '\0') {
      *DAT_0800b72c = (ushort)*(byte *)(iVar3 + 0x11) * 0x78;
    }
    else {
      *DAT_0800b72c = 0;
    }
    *DAT_0800b730 = 0;
    *DAT_0800b734 = 0;
    *DAT_0800b738 = 0;
  }
  *DAT_0800b718 = '\0';
  return;
}



// ==== 0800b73c  FUN_0800b73c  (18 bytes, 3 xrefs)

void FUN_0800b73c(void)

{
  FUN_0800a8f0();
  FUN_0800a980();
  FUN_080049a8(0);
  return;
}



// ==== 0800b750  FUN_0800b750  (24 bytes, 2 xrefs)

void FUN_0800b750(void)

{
  if (*DAT_0800b768 != '\0') {
    FUN_0800e660(0,1);
    FUN_0800ee5c();
  }
  return;
}



// ==== 0800b76c  FUN_0800b76c  (222 bytes, 1 xrefs)

void FUN_0800b76c(void)

{
  ushort uVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  byte local_78 [4];
  undefined4 local_74 [16];
  ushort local_34 [16];
  
  if (0x23 < *DAT_0800b84c) {
    *DAT_0800b84c = 0;
    *DAT_0800b850 = 1;
    iVar4 = FUN_0800e900(0xb);
    FUN_0800e53c();
    iVar3 = DAT_0800b864;
    puVar7 = DAT_0800b858;
    psVar2 = DAT_0800b854;
    if (((-1 < iVar4 << 0x1b) && (*DAT_0800b858 == DAT_0800b85c)) &&
       (DAT_0800b858[0x23] == DAT_0800b860)) {
      uVar5 = 0;
      do {
        uVar6 = uVar5 + 1 & 0xff;
        puVar7[uVar5 + 1] = puVar7[uVar5 + 1] ^ *(ushort *)(iVar3 + (uVar5 & 7) * 2);
        uVar5 = uVar6;
      } while (uVar6 < 0x22);
      uVar5 = FUN_0800f5e8(puVar7 + 1,0x42);
      if ((puVar7[0x22] == uVar5) && (uVar1 = puVar7[1], uVar1 < 0x1e00)) {
        if (*DAT_0800b868 == uVar1) {
          return;
        }
        *DAT_0800b868 = uVar1;
        FUN_0800a21c(uVar1,0x40,local_74,local_34,local_78,0x10);
        puVar7 = puVar7 + 2;
        for (uVar5 = 0; uVar5 < local_78[0]; uVar5 = uVar5 + 1 & 0xff) {
          FUN_08010050(puVar7,local_74[uVar5],local_34[uVar5],0);
          puVar7 = (ushort *)((uint)local_34[uVar5] + (int)puVar7);
        }
        if (uVar1 == 0x1dc0) {
          *DAT_0800b86c = 2;
        }
        *DAT_0800b870 = *DAT_0800b870 + 1;
        return;
      }
    }
    *psVar2 = *psVar2 + 1;
  }
  return;
}



// ==== 0800b874  FUN_0800b874  (206 bytes, 2 xrefs)

void FUN_0800b874(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  
  pbVar7 = DAT_0800b94c;
  iVar6 = DAT_0800b948;
  pbVar5 = DAT_0800b944;
  bVar1 = *DAT_0800b944;
  uVar8 = (uint)*(byte *)(DAT_0800b948 + 0x1f);
  cVar2 = *(char *)(uVar8 + DAT_0800b948 + 0x20);
  bVar3 = *(byte *)(uVar8 + DAT_0800b948 + 0x22);
  bVar4 = *(byte *)(uVar8 + DAT_0800b948 + 0x24);
  if (cVar2 == '\x01') {
    if (*DAT_0800b94c == 0) {
      *DAT_0800b950 = bVar1;
      iVar9 = FUN_08004704(bVar3,0);
      if (iVar9 == 1) {
        *pbVar5 = bVar3;
        goto LAB_0800b8bc;
      }
      *pbVar7 = 1;
LAB_0800b8c2:
      iVar9 = FUN_08004704(bVar4,0);
      if (iVar9 == 1) {
        *pbVar5 = bVar4;
        goto LAB_0800b8da;
      }
      *pbVar7 = 2;
    }
    else {
LAB_0800b8bc:
      if (*pbVar7 == 1) goto LAB_0800b8c2;
LAB_0800b8da:
      if (*pbVar7 != 2) goto LAB_0800b900;
    }
    *pbVar5 = *DAT_0800b950;
  }
  iVar9 = FUN_08004f10((uint)*pbVar5 + (int)*DAT_0800b954 & 0xff,(int)*DAT_0800b954,1,
                       *(undefined1 *)(iVar6 + 0x1f));
  if (iVar9 == 0xff) {
    return;
  }
  *pbVar5 = (byte)iVar9;
LAB_0800b900:
  bVar3 = *pbVar5;
  uVar8 = (uint)*(byte *)(iVar6 + 8);
  if (bVar1 != bVar3) {
    *(byte *)(iVar6 + uVar8 + 4) = bVar3;
    *(byte *)(iVar6 + uVar8) = bVar3;
    FUN_08009938(uVar8,2);
    FUN_080049a8(1);
    *DAT_0800b958 = 1;
  }
  *DAT_0800b95c = 0x14;
  *DAT_0800b960 = 0;
  if ((cVar2 == '\x01') && (bVar1 = *pbVar7, *pbVar7 = bVar1 + 1, 2 < (byte)(bVar1 + 1))) {
    *pbVar7 = 0;
  }
  return;
}



// ==== 0800b964  FUN_0800b964  (120 bytes, 3 xrefs)

void FUN_0800b964(void)

{
  byte bVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  byte *pbVar5;
  
  puVar3 = DAT_0800b9e4;
  pbVar5 = DAT_0800b9e0;
  pcVar2 = DAT_0800b9dc;
  bVar1 = DAT_0800b9e0[8];
  if (*DAT_0800b9dc == '\x01') {
    if ((*DAT_0800b9e0 < 0xcf) || (DAT_0800b9e0[1] < 0xcf)) {
      DAT_0800b9e0[8] = bVar1 == 0;
      pbVar5 = pbVar5 + (uint)(bVar1 == 0) * 0x44 + 0xb8;
      *puVar3 = pbVar5;
    }
    else {
      DAT_0800b9e0[8] = 0;
      pbVar5 = pbVar5 + 0xb8;
      *puVar3 = pbVar5;
    }
    if (0xce < pbVar5[0x1e]) {
      FUN_0800bd2c();
    }
  }
  else {
    DAT_0800b9e0[8] = bVar1 == 0;
    *puVar3 = pbVar5 + (uint)(bVar1 == 0) * 0x44 + 0xb8;
  }
  FUN_080049a8(0);
  if (*pcVar2 == '\x01') {
    uVar4 = 7;
  }
  else {
    uVar4 = 10;
  }
  *DAT_0800b9e8 = uVar4;
  return;
}



// ==== 0800b9ec  FUN_0800b9ec  (488 bytes, 2 xrefs)

void FUN_0800b9ec(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 auStack_2c [16];
  uint local_1c;
  int local_18;
  
  if (*DAT_0800bbd8 != '\x01') {
    return;
  }
  *DAT_0800bbd8 = '\0';
  puVar4 = DAT_0800bbf0;
  iVar2 = DAT_0800bbec;
  if (*DAT_0800bbdc != '\0') {
    return;
  }
  if ((*(char *)(*DAT_0800bbe0 + 0x2f) != '\x01') && (*DAT_0800bbe4 != '\x01')) {
    return;
  }
  local_18 = DAT_0800bbec + 0x44;
  puVar5 = (undefined1 *)(DAT_0800bbec + 0x80);
  if (8 < *DAT_0800bbe8) {
    local_1c = (uint)(byte)(*DAT_0800bbe8 - 9);
    FUN_08011998(auStack_2c,s__s_c_s_0800bbf4,local_18,*puVar5,DAT_0800bbec + 0x4c);
    local_1c = DAT_0800bbfc + local_1c;
    iVar3 = FUN_08004e14(local_1c,auStack_2c,9,1);
    if (iVar3 == 1) {
      if (*(char *)(iVar2 + 0x8f) == '\x01') {
        *DAT_0800bbe4 = '\x01';
        FUN_0800a67c();
        *puVar4 = 2;
        if (*DAT_0800bc10 == '\x01') {
          FUN_08004968();
          FUN_0800b26c(0);
        }
      }
      else {
        *puVar4 = 0;
      }
    }
    else {
      FUN_08011998(auStack_2c,s__s_c_s_0800bbf4,local_18,*puVar5,iVar2 + 0x54);
      iVar3 = FUN_08004e14(local_1c,auStack_2c,9,1);
      if (iVar3 != 1) goto LAB_0800ba7e;
      *DAT_0800bbe4 = '\0';
      FUN_0800a67c();
      *puVar4 = 2;
    }
    *DAT_0800bc04 = '\0';
    *DAT_0800bc08 = 1;
    puVar4 = DAT_0800bc0c;
LAB_0800baf0:
    *puVar4 = 1;
    return;
  }
LAB_0800ba7e:
  if ((1 < *DAT_0800bbe8) &&
     (iVar3 = FUN_08004e14(DAT_0800bbfc + (uint)(byte)(*DAT_0800bbe8 - 2),DAT_0800bc00,2,1),
     iVar3 == 1)) {
    *DAT_0800bc14 = 1;
    puVar4 = DAT_0800bc08;
    goto LAB_0800baf0;
  }
  if ((*DAT_0800bc04 == '\x01') && ((*DAT_0800bc18 == '\0' && (8 < *DAT_0800bbe8)))) {
    local_1c = (uint)(byte)(*DAT_0800bbe8 - 9);
    FUN_08011998(auStack_2c,s__s_c_s_0800bbf4,DAT_0800bc20,*puVar5,DAT_0800bc1c);
    iVar3 = FUN_08004e14(DAT_0800bbfc + local_1c,auStack_2c,9,0);
    if (iVar3 == 1) {
      *DAT_0800bc14 = 2;
      *DAT_0800bc08 = 1;
    }
  }
  if (*DAT_0800bbe4 == '\x01') {
    return;
  }
  if (*DAT_0800bc04 != '\0') {
    return;
  }
  if (*DAT_0800bbe8 < 7) {
    return;
  }
  local_1c = (uint)(byte)(*DAT_0800bbe8 - 7);
  FUN_08011998(auStack_2c,&DAT_0800bc24,local_18,*puVar5);
  *DAT_0800bc2c = '\0';
  iVar6 = DAT_0800bbfc + local_1c;
  iVar3 = FUN_08004e14(iVar6,auStack_2c,4,1);
  if (iVar3 != 1) {
    return;
  }
  *DAT_0800bc04 = '\x02';
  FUN_08002968(DAT_0800bc30,iVar6,3);
  FUN_08002968(DAT_0800bc34,iVar6 + 4,3);
  *DAT_0800bc08 = 1;
  puVar5 = DAT_0800bc3c;
  cVar1 = *(char *)(iVar2 + 0x82);
  if (cVar1 == '\x03') {
    *DAT_0800bc38 = 1;
    *puVar5 = 0x14;
  }
  else if (cVar1 != '\x02') {
    if (cVar1 == '\x01') {
      *DAT_0800bc38 = 1;
      *puVar5 = 0x14;
    }
    else {
      *DAT_0800bc38 = 0;
      *puVar4 = 0;
    }
    goto LAB_0800bbba;
  }
  *puVar4 = 3;
LAB_0800bbba:
  if (*DAT_0800bc2c == '\x01') {
    *puVar4 = 0;
    return;
  }
  return;
}



// ==== 0800bc40  FUN_0800bc40  (128 bytes, 1 xrefs)

void FUN_0800bc40(void)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = DAT_0800bcc0;
  uVar1 = *(ushort *)(DAT_0800bcc0 + 0x30);
  iVar4 = FUN_0800e07c(uVar1,*(undefined2 *)(DAT_0800bcc0 + 0x34));
  pbVar3 = DAT_0800bcd4;
  if (iVar4 == 0) {
    if (*DAT_0800bcc4 != '\x01') {
      *DAT_0800bccc = 0;
      *DAT_0800bcd0 = 1;
      if (*(char *)(DAT_0800bcc0 + 0x2f) == '\0') {
        *(ushort *)(iVar2 + 0x2c) = uVar1;
      }
      DAT_50000018 = 0x100;
      *DAT_0800bcdc = 1;
      goto LAB_0800bca6;
    }
    uVar5 = (uint)*DAT_0800bcd4;
    if (uVar5 < 0x14) {
      *(ushort *)(DAT_0800bcd8 + uVar5 * 2) = uVar1;
      *pbVar3 = (byte)(uVar5 + 1);
      if ((uVar5 + 1 & 0xff) < 0x14) goto LAB_0800bc9c;
    }
LAB_0800bca2:
    FUN_0800b1fc();
  }
  else {
    if (*DAT_0800bcc4 == '\x01') {
LAB_0800bc9c:
      if (*(ushort *)(iVar2 + 0x36) <= uVar1) goto LAB_0800bca2;
    }
    FUN_0800af60(uVar1,(int)*DAT_0800bcc8);
  }
LAB_0800bca6:
  FUN_0800b26c(1);
  return;
}



// ==== 0800bce0  FUN_0800bce0  (54 bytes, 2 xrefs)

void FUN_0800bce0(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0800bd1c;
  FUN_08004244(*DAT_0800bd1c,(int)*DAT_0800bd18);
  FUN_080041c4(*puVar1);
  FUN_08003f98(*puVar1);
  FUN_080049a8(1);
  *DAT_0800bd20 = 1;
  *DAT_0800bd24 = 10;
  *DAT_0800bd28 = 0;
  return;
}



// ==== 0800bd2c  FUN_0800bd2c  (20 bytes, 2 xrefs)

void FUN_0800bd2c(void)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_0800bd40;
  bVar1 = *DAT_0800bd40;
  *DAT_0800bd40 = bVar1 + 1;
  if (9 < (byte)(bVar1 + 1)) {
    *pbVar2 = 0;
  }
  return;
}



// ==== 0800bd44  FUN_0800bd44  (196 bytes, 1 xrefs)

void FUN_0800bd44(void)

{
  char cVar1;
  short *psVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 *puVar6;
  
  pcVar3 = DAT_0800be14;
  psVar2 = DAT_0800be10;
  if (*DAT_0800be08 == '\x01') {
    return;
  }
  if (*DAT_0800be0c == 0) {
    if (*DAT_0800be10 != 0) {
      return;
    }
  }
  else {
    *DAT_0800be14 = '\0';
    *psVar2 = 0;
  }
  puVar6 = DAT_0800be28;
  pcVar5 = DAT_0800be24;
  pcVar4 = DAT_0800be18;
  cVar1 = *DAT_0800be18;
  if (cVar1 == '\x04') {
    return;
  }
  if (cVar1 == '\x02') {
    return;
  }
  if (*DAT_0800be1c != '\0') {
    return;
  }
  if (*DAT_0800be20 == '\x01') {
    return;
  }
  if (*DAT_0800be24 != '\x01') {
    if (*pcVar3 != '\x01') {
      return;
    }
    *DAT_0800be24 = '\x01';
    if (cVar1 == '\x05') {
      FUN_0800b2fc(0);
    }
    if (*pcVar4 == '\x01') {
      return;
    }
    *DAT_0800be2c = 0;
    FUN_0800b5c0();
    *puVar6 = 1;
    return;
  }
  if (*pcVar3 == '\x01') {
    *DAT_0800be30 = 100;
  }
  else if (*DAT_0800be30 == 0) {
    *DAT_0800be24 = '\0';
  }
  pcVar3 = DAT_0800be38;
  if (cVar1 != '\x01') {
    return;
  }
  if (*DAT_0800be34 == '\x01') {
    return;
  }
  if (*pcVar5 != '\0') {
    return;
  }
  if (*DAT_0800be38 != '\x01') {
    FUN_0800b73c();
    if (*(char *)(DAT_0800be3c + 0x1c) != '\0') {
      *DAT_0800be40 = *(char *)(DAT_0800be3c + 0x1c) * '\n';
      goto LAB_0800be02;
    }
  }
  FUN_0800b2fc(0);
LAB_0800be02:
  *puVar6 = 1;
  *pcVar3 = '\0';
  return;
}



// ==== 0800be44  FUN_0800be44  (86 bytes, 2 xrefs)

void FUN_0800be44(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*DAT_0800be9c != '\x01') {
    if (param_1 == 0) {
      iVar1 = 0;
      uVar2 = 1;
    }
    else if (param_1 == 1) {
      uVar2 = 0;
      iVar1 = DAT_0800bea0 + -0x48;
    }
    else if (param_1 == 2) {
      uVar2 = 0;
      iVar1 = DAT_0800bea0 + -0x36;
    }
    else if (param_1 == 3) {
      uVar2 = 0;
      iVar1 = DAT_0800bea0 + -0x24;
    }
    else {
      uVar2 = 0;
      if (param_1 == 4) {
        iVar1 = DAT_0800bea0 + -0x12;
      }
      else {
        iVar1 = DAT_0800bea0;
      }
    }
    FUN_0800fcc8(0x6e,0,0x12,iVar1,uVar2);
  }
  return;
}



// ==== 0800bea4  FUN_0800bea4  (62 bytes, 4 xrefs)

void FUN_0800bea4(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = DAT_0800bee8;
  puVar2 = DAT_0800bee4;
  if (param_1 == 0) {
    *DAT_0800bee4 = 0;
    puVar2[1] = 0;
    *puVar3 = 0;
  }
  else {
    if (param_1 == 6) {
      *DAT_0800bee4 = 6;
      puVar2[1] = 3;
    }
    else {
      if (*(char *)(DAT_0800beec + 0x1b) == '\0') {
        bVar1 = *(byte *)(DAT_0800beec + 8);
      }
      else {
        bVar1 = *(byte *)(DAT_0800beec + 9);
      }
      DAT_0800bee4[bVar1] = (char)param_1;
    }
    *puVar3 = 5;
  }
  *DAT_0800bef0 = 1;
  return;
}



// ==== 0800bef4  FUN_0800bef4  (184 bytes, 1 xrefs)

void FUN_0800bef4(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((*DAT_0800bfac != '\x01') && (*DAT_0800bfb0 == '\0')) {
    if (param_2 == 0) {
      uVar2 = 3;
      iVar1 = DAT_0800bfbc;
    }
    else {
      uVar2 = 7;
      iVar1 = DAT_0800bfb4;
    }
    FUN_0800299a(iVar1,0x17,param_3,param_4,param_4);
    if (param_1 == 0) {
      iVar1 = 0;
      uVar3 = 1;
    }
    else {
      FUN_08002968(iVar1,DAT_0800bfb8,5);
      FUN_08002968(iVar1 + 5,DAT_0800bfb8 + -0x12,3);
      if (1 < param_1) {
        FUN_08002968(iVar1 + 8,DAT_0800bfb8 + -0xf,3);
      }
      if (2 < param_1) {
        FUN_08002968(iVar1 + 0xb,DAT_0800bfb8 + -0xc,3);
      }
      if (3 < param_1) {
        FUN_08002968(iVar1 + 0xe,DAT_0800bfb8 + -9,3);
      }
      if (4 < param_1) {
        FUN_08002968(iVar1 + 0x11,DAT_0800bfb8 + -6,3);
      }
      if (5 < param_1) {
        FUN_08002968(iVar1 + 0x14,DAT_0800bfb8 + -3,3);
      }
      uVar3 = 0;
    }
    FUN_0800fcc8(0,uVar2,0x17,iVar1,uVar3);
  }
  return;
}



// ==== 0800bfc0  FUN_0800bfc0  (70 bytes, 3 xrefs)

void FUN_0800bfc0(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
  iVar1 = DAT_0800c00c;
  if (*DAT_0800c008 != '\0') {
    uVar2 = 0;
    do {
      if (*(char *)(iVar1 + uVar2) == '\n') {
        *(undefined1 *)(param_1 + uVar2) = 0x2d;
      }
      else {
        *(char *)(param_1 + uVar2) = *(char *)(iVar1 + uVar2) + '0';
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 3);
    return;
  }
  if (param_2 == 1) {
    pcVar3 = s_CH__03d_0800c018;
  }
  else {
    if (param_3 == 0xff) {
      FUN_08011998(param_1,&LAB_0800c020);
      return;
    }
    pcVar3 = &DAT_0800c010;
  }
  FUN_08011998(param_1,pcVar3,param_3 + 1);
  return;
}



// ==== 0800c028  FUN_0800c028  (64 bytes, 1 xrefs)

void FUN_0800c028(undefined1 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*DAT_0800c068 == '\0') {
    FUN_08011998(param_1,s_CH__02d_0800c070,param_2 + 1);
    return;
  }
  *param_1 = 0x43;
  param_1[1] = 0x48;
  iVar1 = DAT_0800c06c;
  param_1[2] = 0x2d;
  uVar2 = 0;
  do {
    if (*(char *)(iVar1 + uVar2) == '\n') {
      param_1[uVar2 + 3] = 0x2d;
    }
    else {
      param_1[uVar2 + 3] = *(char *)(iVar1 + uVar2) + '0';
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 2);
  return;
}



// ==== 0800c078  FUN_0800c078  (182 bytes, 5 xrefs)

void FUN_0800c078(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  param_2 = param_3 * 0x80 + DAT_0800c130 + param_2;
  iVar4 = param_2 + 0x80;
  bVar1 = false;
  uVar3 = 0;
  do {
    if (((param_4 == 1) || (bVar1)) || (*(byte *)(param_1 + uVar3) != 0)) {
      bVar1 = true;
      iVar2 = (uint)*(byte *)(param_1 + uVar3) * 0x19 + DAT_0800c134;
      FUN_08002968(uVar3 * 0xd + param_2 + 1,iVar2,0xc);
      FUN_08002968(uVar3 * 0xd + iVar4,iVar2 + 0xc,0xd);
    }
    else if (param_5 == 1) {
      iVar4 = iVar4 + -6;
      param_2 = param_2 + -6;
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 3);
  *(undefined1 *)(iVar4 + 0x27) = 0x60;
  *(undefined1 *)(iVar4 + 0x28) = 0x60;
  *(undefined1 *)(iVar4 + 0x29) = 0x60;
  uVar3 = 0;
  do {
    iVar2 = (uint)*(byte *)(param_1 + uVar3 + 3) * 0x19 + DAT_0800c134;
    FUN_08002968(uVar3 * 0xd + param_2 + 0x2b,iVar2,0xc);
    FUN_08002968(uVar3 * 0xd + iVar4 + 0x2a,iVar2 + 0xc,0xd);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 3);
  return;
}



// ==== 0800c138  FUN_0800c138  (36 bytes, 1 xrefs)

void FUN_0800c138(int param_1)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = DAT_0800c160;
  iVar1 = DAT_0800c15c;
  for (uVar3 = 0; uVar3 < *pbVar2; uVar3 = uVar3 + 1 & 0xff) {
    if (*(char *)(iVar1 + uVar3) == -1) {
      *(undefined1 *)(param_1 + uVar3) = 0x2d;
    }
    else {
      *(char *)(param_1 + uVar3) = *(char *)(iVar1 + uVar3);
    }
  }
  return;
}



// ==== 0800c164  FUN_0800c164  (54 bytes, 5 xrefs)

void FUN_0800c164(uint param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    iVar1 = param_4 * 0x80 + DAT_0800c19c;
    for (uVar2 = 0; uVar2 < param_1; uVar2 = uVar2 + 1 & 0xff) {
      FUN_08002968(uVar2 * 7 + iVar1 + param_3 + 1,
                   (uint)*(byte *)(param_2 + uVar2) * 6 + DAT_0800c1a0,6);
    }
  }
  return;
}



// ==== 0800c1a4  FUN_0800c1a4  (72 bytes, 2 xrefs)

void FUN_0800c1a4(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  
  bVar1 = FUN_080029d8(param_1);
  for (uVar3 = 0; uVar3 < bVar1; uVar3 = uVar3 + 1 & 0xff) {
    if (*(byte *)(param_1 + uVar3) < 0xa1) {
      uVar2 = *(byte *)(param_1 + uVar3) - 0x21;
      if (uVar2 < 0x5e) {
        FUN_08002968(param_2 + param_3,(uVar2 & 0xff) * 6 + DAT_0800c1ec,6);
      }
      bVar4 = (char)param_3 + 6;
    }
    else {
      uVar3 = uVar3 + 1 & 0xff;
      bVar4 = (char)param_3 + 0xc;
    }
    param_3 = (uint)bVar4;
  }
  return;
}



// ==== 0800c1f0  FUN_0800c1f0  (216 bytes, 26 xrefs)

void FUN_0800c1f0(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  
  local_24 = param_1;
  uStack_20 = param_2;
  iStack_1c = param_3;
  iStack_18 = param_4;
  bVar1 = FUN_080029d8(param_1);
  local_30 = (uint)bVar1;
  if (param_6 == 1) {
    uVar3 = (int)(((param_3 - param_2) - param_5 * local_30) + 1) / 2 + param_2 & 0xff;
  }
  else {
    uVar3 = param_2;
  }
  if (0x7f < uVar3) {
    uVar3 = param_2;
  }
  iVar5 = param_4 * 0x80 + DAT_0800c2c8;
  uVar4 = 0;
  do {
    if (local_30 <= uVar4) {
      return;
    }
    uVar2 = (uint)*(byte *)(local_24 + uVar4);
    if (uVar2 < 0xa1) {
      local_28 = uVar3 + param_5;
      if (0x80 < local_28) {
        return;
      }
      if (uVar2 - 0x21 < 0x5e) {
        local_2c = (uVar2 - 0x21 & 0xff) * 0xe + DAT_0800c2d0;
        FUN_08002968(iVar5 + uVar3,local_2c,7);
        FUN_08002968(iVar5 + 0x80 + uVar3,local_2c + 7,7);
      }
      bVar1 = (byte)local_28;
    }
    else {
      local_2c = uVar3 + 0x10;
      if (0x80 < local_2c) {
        return;
      }
      FUN_0800ff84(auStack_50,
                   ((uVar2 - 0xa1 & 0xff) * 0x5e +
                   (uint)(byte)(*(char *)(local_24 + uVar4 + 1) + 0x5f)) * 0x20 + DAT_0800c2cc,0x20)
      ;
      FUN_08002968(iVar5 + uVar3,auStack_50,0x10);
      FUN_08002968(iVar5 + 0x80 + uVar3,auStack_40,0x10);
      uVar4 = uVar4 + 1 & 0xff;
      bVar1 = (byte)local_2c;
    }
    uVar3 = (uint)bVar1;
    uVar4 = uVar4 + 1 & 0xff;
  } while( true );
}



// ==== 0800c2d4  FUN_0800c2d4  (26 bytes, 8 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x0800c3cc

// ==== 0800c31c  FUN_0800c31c  (202 bytes, 1 xrefs)

void FUN_0800c31c(void)

{
  char *pcVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  FUN_0800299a(PTR_DAT_0800c3e8,0x380);
  if (*PTR_DAT_0800c3ec == '\0') {
    pcVar1 = s_AIR_COPY_RDY__0800c408;
  }
  else if (*PTR_DAT_0800c3ec == '\x01') {
    pcVar1 = s_AIR_COPY_0800c418;
  }
  else {
    pcVar1 = s_AIR_COPY_CMP__0800c3f0;
  }
  FUN_08011998(&local_20,pcVar1);
  FUN_0800c1f0(&local_20,2,0x7f,0,8,1);
  if (*PTR_DAT_0800c400 == '\0') {
    FUN_08004d50(**(undefined4 **)PTR_DAT_0800c424,&local_20);
    FUN_0800c078(&local_20,0x10,2,0,0);
    FUN_0800c164(2,(int)&local_1c + 2,0x61,3);
  }
  else {
    FUN_0800c078(PTR_DAT_0800c404,0x10,2,1,0);
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (*PTR_DAT_0800c428 == '\0') {
    FUN_08011998(&local_20,s_RCV__d_E__d_0800c434,*(undefined2 *)PTR_DAT_0800c42c,
                 *(undefined2 *)PTR_DAT_0800c430);
  }
  else if (*PTR_DAT_0800c428 == '\x01') {
    FUN_08011998(&local_20,s_SND__d_0800c440,*(undefined2 *)PTR_DAT_0800c42c);
  }
  FUN_0800c1f0(&local_20,2,0x7f,4,8,1);
  FUN_0800fd18();
  return;
}



// ==== 0800c448  FUN_0800c448  (380 bytes, 0 xrefs)

void FUN_0800c448(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 auStack_28 [5];
  
  FUN_0800299a(DAT_0800c5c4,0x380);
  FUN_0800c1f0(&DAT_0800c5c8,0,0x7f,0,0xc,1);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  FUN_0800299a(auStack_28,0x14);
  puVar2 = PTR_DAT_0800c5e0;
  puVar1 = PTR_DAT_0800c5d0;
  bVar8 = false;
  puVar3 = &local_38;
  puVar7 = auStack_28;
  if (*PTR_DAT_0800c5cc == '\x01') {
    puVar3 = (undefined4 *)PTR_s_SAVE__0800c5fc;
  }
  else if (*PTR_DAT_0800c5d4 == '\x01') {
    puVar3 = (undefined4 *)PTR_DAT_0800c600;
  }
  else if (*PTR_DAT_0800c5d8 == '\0') {
    if (PTR_DAT_0800c5d0[0xf] == '\0') {
      uVar6 = 0;
      do {
        if (*(short *)(PTR_DAT_0800c5d0 + 0x10) == *(short *)(DAT_0800c614 + uVar6 * 2)) {
          if (uVar6 < 0x14) {
            pcVar4 = s_VFO_CH_02d__0800c618;
            goto LAB_0800c504;
          }
          break;
        }
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < 0x14);
      puVar3 = DAT_0800c624;
    }
    else {
      uVar6 = (uint)(byte)PTR_DAT_0800c5d0[0xe];
      pcVar4 = s_MR_CH_02d__0800c608;
LAB_0800c504:
      FUN_08011998(puVar3,pcVar4,uVar6 + 1);
    }
  }
  else if (*PTR_DAT_0800c5dc == '\0') {
    puVar7 = (undefined4 *)(DAT_0800c5f0 + 9);
    bVar8 = true;
    puVar3 = (undefined4 *)PTR_s_M_SCAN_0800c604;
  }
  else {
    FUN_08011998(puVar3,s_A_SCAN__d__0800c5e4,(byte)*PTR_DAT_0800c5e0 + 1);
    FUN_08011998(puVar7,s__s__d__0800c5f4,DAT_0800c5f0,(byte)*puVar2 + 1);
    bVar8 = true;
  }
  if ((PTR_DAT_0800c5d0[0x75] == '\0') && (bVar8)) {
    uVar5 = 8;
    puVar3 = puVar7;
  }
  else {
    uVar5 = 10;
  }
  FUN_0800c1f0(puVar3,0,0x7f,2,uVar5,1);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if ((*PTR_DAT_0800c5cc == '\x01') || ((puVar1[0xf] == '\x01' && (*DAT_0800c628 != '\0')))) {
    FUN_0800c028(&local_38,*PTR_DAT_0800c5e0);
  }
  else {
    if (*PTR_DAT_0800c5d4 != '\x01') {
      bVar8 = *DAT_0800c628 == '\0';
      if (bVar8) {
        FUN_08004d50(DAT_0800c638 * (uint)*(ushort *)(PTR_DAT_0800c5d0 + 0x10),&local_38);
        puVar3 = &local_38;
      }
      else {
        puVar3 = DAT_0800c62c;
      }
      FUN_0800c078(puVar3,0x17,4,!bVar8,bVar8);
      goto LAB_0800c5bc;
    }
    FUN_08011998(&local_38,s_CH__02d_0800c630,(byte)puVar1[0xe] + 1);
  }
  FUN_0800c1f0(&local_38,0,0x7f,4,10,1);
LAB_0800c5bc:
  FUN_0800fd18();
  return;
}



// ==== 0800c63c  FUN_0800c63c  (462 bytes, 0 xrefs)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800c63c(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined *local_18;
  
  FUN_0800299a(PTR_DAT_0800c80c,0x380);
  puVar2 = PTR_DAT_0800c818;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if ((*PTR_DAT_0800c810 == '\x01') ||
     ((*PTR_DAT_0800c814 != '\0' && (*PTR_DAT_0800c814 != '\x03')))) {
    uVar7 = FUN_08002cb8(*(undefined4 *)PTR_DAT_0800c818);
    uVar3 = DAT_0800c81c;
    uVar7 = FUN_08002be8((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_0800c81c,DAT_0800c820);
    FUN_08011998(&local_38,s_FREQ___5f_0800c824,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
    uVar7 = FUN_08002cb8(*(undefined4 *)puVar2);
    uVar7 = FUN_08002be8((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar3,DAT_0800c820);
    FUN_08011998(&local_28,FUN_0800c830,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  }
  else {
    FUN_08011998(&local_38,s_FREQ__________0800c83c);
    FUN_08011998(&local_28,FUN_0800c84c);
  }
  local_18 = PTR_DAT_0800c85c;
  if (PTR_DAT_0800c85c[0x15] == '\0') {
    puVar5 = &local_28;
  }
  else {
    puVar5 = &local_38;
  }
  FUN_0800c1f0(puVar5,2,0x7f,1,8,0);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  bVar1 = false;
  if (((byte)*PTR_DAT_0800c814 < 2) || (*PTR_DAT_0800c860 != '\x01')) {
    FUN_08011998(&local_38,s_CTC________0800c864);
  }
  else if (*PTR_DAT_0800c888 == '\x01') {
    uVar7 = FUN_08002cb8(*(undefined2 *)(DAT_0800c8a0 + (uint)(byte)*PTR_DAT_0800c88c * 2));
    uVar7 = FUN_08002be8((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_0800c8a4,DAT_0800c8a8);
    FUN_08011998(&local_38,s_CTC___1fHz_0800c8ac,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  }
  else {
    FUN_08011998(&local_38,s_DCS_D_03oN_0800c894,
                 *(undefined2 *)(DAT_0800c890 + (uint)(byte)*PTR_DAT_0800c88c * 2));
  }
  FUN_0800c1f0(&local_38,2,0x7f,3,8,0);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  puVar5 = &local_28;
  if (*_DAT_0800c870 == '\x02') {
    puVar6 = DAT_0800c8b8;
  }
  else {
    puVar6 = &local_38;
    if (*_DAT_0800c870 == '\x01') {
      FUN_08011998(&local_38,s_SAVE__0800c8bc);
      FUN_0800bfc0((int)&local_34 + 1,*PTR_DAT_0800c8c8,*PTR_DAT_0800c8c4);
      FUN_0800c1f0(&local_38,2,0x7f,5,8,0);
    }
    else {
      if ((byte)*PTR_DAT_0800c814 < 2) {
        FUN_08011998(&local_38,s_SCAN_0800c873 + 1);
        pbVar4 = DAT_0800c87c;
        FUN_0800298c(&local_34,(*DAT_0800c87c & 7) + 1,0x2e);
        FUN_08011998(&local_28,&DAT_0800c880);
        FUN_0800298c((int)&local_24 + 2,(*pbVar4 & 7) + 1,0x2e);
      }
      else if (*PTR_DAT_0800c814 == 2) {
        puVar6 = (undefined4 *)PTR_s_SCAN_CMP_0800c8d4;
        puVar5 = (undefined4 *)PTR_DAT_0800c8d8;
      }
      else {
        puVar6 = DAT_0800c8cc;
        puVar5 = (undefined4 *)PTR_DAT_0800c8d0;
      }
      bVar1 = true;
    }
  }
  if ((local_18[0x15] != '\0') || (!bVar1)) {
    puVar5 = puVar6;
  }
  FUN_0800c1f0(puVar5,2,0x7f,5,8,0);
  FUN_0800fd18();
  return;
}



// ==== 0800c830  FUN_0800c830  (12 bytes, 1 xrefs)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0800c830(int param_1,undefined4 param_2,int *param_3,undefined1 param_4)

{
  short unaff_r4;
  
  *(short *)(param_1 + *param_3) = unaff_r4 << 1;
  *(undefined4 *)(param_1 + 0x68) = 0x68;
  *puRam00000068 = param_4;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ==== 0800c84c  FUN_0800c84c  (16 bytes, 1 xrefs)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0800c84c(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 param_4)

{
  *(undefined1 *)*param_3 = param_4;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ==== 0800c8dc  FUN_0800c8dc  (308 bytes, 1 xrefs)

void FUN_0800c8dc(void)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  uint unaff_r6;
  uint uVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [10];
  byte local_1a;
  
  FUN_0800299a(DAT_0800ca10,0x380);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  FUN_0800c138(&local_38);
  FUN_0800c1f0(&local_38,0,0x7f,0,8,1);
  if ((uint)*DAT_0800ca18 < (uint)*DAT_0800ca14) {
    FUN_08002968((uint)*DAT_0800ca18 * 8 + (((uint)*DAT_0800ca14 * -8 + 0x80 & 0x1ff) >> 1) +
                 DAT_0800ca10 + 0x101,DAT_0800ca1c,6);
  }
  if ((*(char *)(DAT_0800ca20 + 0x16) == '\x01') && (*DAT_0800ca24 != '\0')) {
    if (*DAT_0800ca28 == '\0') {
      FUN_0800c1a4(&DAT_0800ca2c,DAT_0800ca38,0);
    }
    else {
      FUN_0800c1f0(&DAT_0800ca2c,0,0x7f,4,8,0);
    }
    uVar5 = 6;
    uVar4 = (ushort)*DAT_0800ca30;
    do {
      FUN_08009194(*DAT_0800ca34 + uVar4,auStack_28);
      if (uVar5 == 6) {
        unaff_r6 = (uint)local_1a;
      }
      iVar2 = FUN_080029d8(auStack_24);
      uVar6 = uVar5 + (iVar2 * 6 & 0xffU);
      if (0x80 < uVar6) break;
      FUN_0800c1a4(auStack_24,DAT_0800ca10 + uVar5 + 0x180,0);
      uVar4 = uVar4 + 1 & 0xff;
      uVar5 = uVar6 & 0xff;
    } while (uVar4 < *DAT_0800ca3c);
    uVar5 = (uint)*DAT_0800ca40;
    local_38 = 0;
    bVar3 = 0;
    do {
      uVar1 = local_38;
      local_38._3_1_ = SUB41(uVar1,3);
      local_38._0_3_ =
           CONCAT12(*(undefined1 *)(uVar5 * 2 + DAT_0800ca44 + 1),
                    CONCAT11(*(undefined1 *)(DAT_0800ca44 + uVar5 * 2),bVar3 + 0x31));
      FUN_0800c1f0(&local_38,bVar3 * '\x18' + '\b',0x7f,4,8,0);
      uVar5 = uVar5 + 1 & 0xff;
      if (unaff_r6 <= uVar5) break;
      bVar3 = bVar3 + 1;
    } while (bVar3 < 5);
  }
  FUN_0800fd18();
  return;
}



// ==== 0800ca48  FUN_0800ca48  (1526 bytes, 0 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    Instruction at (ram,0x0800ce14) overlaps instruction at (ram,0x0800ce12)


// ==== 0800d15c  FUN_0800d15c  (218 bytes, 2 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    Instruction at (ram,0x0800d132) overlaps instruction at (ram,0x0800d130)


// ==== 0800d8dc  FUN_0800d8dc  (108 bytes, 1 xrefs)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d8dc(void)

{
  uint uVar1;
  undefined1 local_20 [6];
  undefined1 local_1a;
  
  FUN_0800299a(DAT_0800d948,0x80);
  FUN_0800299a(_DAT_0800d94c,0x380);
  FUN_0800c1f0(s_LOCK_0800d94f + 1,0,0x7f,1,10,1);
  uVar1 = 0;
  do {
    if (*(char *)(DAT_0800d958 + uVar1) == '\n') {
      local_20[uVar1] = 0x2d;
    }
    else {
      local_20[uVar1] = 0x2a;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 6);
  local_1a = 0;
  FUN_0800c1f0(local_20,0,0x7f,3,0xc,1);
  FUN_0800fd64();
  FUN_0800fd18();
  return;
}



// ==== 0800d95c  FUN_0800d95c  (212 bytes, 1 xrefs)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d95c(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  cVar2 = *(char *)(DAT_0800da30 + 0x1a);
  FUN_0800299a(DAT_0800da34,0x80);
  FUN_0800299a(_DAT_0800da38,0x380);
  if (cVar2 == '\0') {
    FUN_0800298c(DAT_0800da34,0x80,0xff);
    FUN_0800298c(_DAT_0800da38,0x380,0xff);
  }
  else {
    if (cVar2 == '\x03') {
      iVar1 = FUN_0800a1c8();
      if (iVar1 == 1) goto LAB_0800d9fc;
      cVar2 = '\x02';
    }
    else if ((cVar2 != '\x02') && (cVar2 != '\x01')) goto LAB_0800d9fc;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    if (cVar2 == '\x02') {
      FUN_08011998(&local_30,s_VOLTAGE_0800da3b + 1);
      uVar4 = FUN_08002cb8(*DAT_0800da44);
      uVar4 = FUN_08002be8((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),DAT_0800da48,DAT_0800da4c);
      FUN_08011998(&local_20,s___2fV_0800da50,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
      uVar3 = 10;
    }
    else {
      FUN_08002968(&local_30,DAT_0800da30 + 0x78,0xf);
      FUN_08002968(&local_20,DAT_0800da30 + 0x88,0xf);
      uVar3 = 8;
    }
    FUN_0800c1f0(&local_30,0,0x7f,1,uVar3,1);
    FUN_0800c1f0(&local_20,0,0x7f,3,uVar3,1);
  }
LAB_0800d9fc:
  FUN_0800fd64();
  FUN_0800fd18();
  return;
}



// ==== 0800da58  FUN_0800da58  (348 bytes, 2 xrefs)

void FUN_0800da58(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_0800299a(DAT_0800dbb4,0x80);
  if (*DAT_0800dbb8 == '\x05') {
    FUN_08002968(DAT_0800dbb4,DAT_0800dbbc,8);
  }
  bVar1 = *DAT_0800dbc0;
  if (bVar1 < 2) {
    if (*DAT_0800dbc4 == '\x01') {
      iVar2 = DAT_0800dbbc + 0x10;
      goto LAB_0800daa2;
    }
  }
  else {
    if (bVar1 == 2) {
      iVar2 = DAT_0800dbbc + 0x22;
    }
    else if (bVar1 == 3) {
      iVar2 = DAT_0800dbbc + 0x34;
    }
    else if (bVar1 == 4) {
      iVar2 = DAT_0800dbbc + 0x46;
    }
    else {
      iVar2 = DAT_0800dbbc + 0x58;
    }
LAB_0800daa2:
    FUN_08002968(DAT_0800dbb4 + 0x6e,iVar2,0x12);
  }
  if (*DAT_0800dbc8 == '\x01') {
    FUN_08002968(DAT_0800dbb4 + 100,DAT_0800dbbc + 0xde,9);
  }
  iVar2 = DAT_0800dbcc;
  if (*(char *)(DAT_0800dbcc + 0x12) == '\x01') {
    uVar4 = 9;
    iVar3 = DAT_0800dbbc + 0xe7;
  }
  else if (*DAT_0800dbd0 == '\x01') {
    if (*(char *)(DAT_0800dbcc + 0x96) == '\x01') {
      uVar4 = 0xb;
      iVar3 = DAT_0800dbbc + 0xfb;
    }
    else {
      uVar4 = 0xb;
      iVar3 = DAT_0800dbbc + 0xf0;
    }
  }
  else {
    if (*DAT_0800dbd4 != '\x01') goto LAB_0800db1e;
    uVar4 = 10;
    iVar3 = DAT_0800dbd8;
  }
  FUN_08002968(DAT_0800dbb4 + 0x58,iVar3,uVar4);
LAB_0800db1e:
  if (*(char *)(iVar2 + 0x13) == '\x01') {
    FUN_08002968(DAT_0800dbb4 + 0x45,DAT_0800dbd8 + -0x3f,0x12);
  }
  if (*(char *)(iVar2 + 0x1b) != '\0') {
    FUN_08002968(DAT_0800dbb4 + 0x38,DAT_0800dbd8 + -0x2d,0xc);
  }
  if (*(char *)(iVar2 + 0x1a) != '\0') {
    FUN_08002968(DAT_0800dbb4 + 0x2b,DAT_0800dbd8 + -0x21,0xc);
  }
  if (*(char *)(iVar2 + 0x15) != '\0') {
    FUN_08002968(DAT_0800dbb4 + 0x20,DAT_0800dbd8 + -0x15,9);
  }
  if (*DAT_0800dbdc == '\x01') {
    FUN_0800298c(DAT_0800dbb4 + 0x13,10,0xff);
  }
  else if (*DAT_0800dbe0 == '\x01') {
    FUN_08002968(DAT_0800dbb4 + 0x13,DAT_0800dbd8 + -0xc,0xc);
  }
  if (*DAT_0800dbe4 == '\x01') {
    FUN_08002968(DAT_0800dbb4 + 5,DAT_0800dbd8 + 10,0xc);
  }
  FUN_0800fd64();
  return;
}



// ==== 0800dbe8  FUN_0800dbe8  (150 bytes, 0 xrefs)

void FUN_0800dbe8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = DAT_0800dc88;
  iVar2 = DAT_0800dc84;
  puVar1 = PTR_DMA1_0800dc80;
  if ((*(uint *)PTR_DMA1_0800dc80 & 0x7ff) >> 10 != 0) {
    *(int *)(PTR_DMA1_0800dc80 + 4) = (int)PTR_DMA1_0800dc80 >> 0x14;
    if (pbVar3[1] == 0) {
      FUN_0800299a(DAT_0800dc8c,0x140,param_3,param_4,param_4);
    }
    else {
      FUN_08002968(DAT_0800dc8c,(uint)*pbVar3 * 0x140 + iVar2,0x140);
      *pbVar3 = *pbVar3 + 1;
      if (3 < *pbVar3) {
        *pbVar3 = 0;
      }
      pbVar3[1] = pbVar3[1] - 1;
    }
  }
  if (*(int *)puVar1 << 0x16 < 0) {
    *(undefined4 *)(puVar1 + 4) = 0x200;
    if (pbVar3[1] == 0) {
      FUN_0800299a(DAT_0800dc90,0x140);
      return;
    }
    FUN_08002968(DAT_0800dc90,(uint)*pbVar3 * 0x140 + iVar2);
    *pbVar3 = *pbVar3 + 1;
    if (3 < *pbVar3) {
      *pbVar3 = 0;
    }
    pbVar3[1] = pbVar3[1] - 1;
  }
  return;
}



// ==== 0800dc94  FUN_0800dc94  (86 bytes, 0 xrefs)

void FUN_0800dc94(void)

{
  byte bVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DMA1_0800dcec;
  if ((*(int *)PTR_DMA1_0800dcec << 0x12 < 0) &&
     (bVar1 = *(byte *)(DAT_0800dcf0 + 3), *(int *)(PTR_DMA1_0800dcec + bVar1) << 0x1e < 0)) {
    *(uint *)(PTR_DMA1_0800dcec + bVar1) = *(uint *)(PTR_DMA1_0800dcec + bVar1) & 0xfffffffd;
    *(undefined4 *)(puVar2 + 4) = 0x2000;
    puVar2 = PTR_SPI2_0800dcf4;
    do {
    } while ((*(uint *)(PTR_SPI2_0800dcf4 + 8) & 0x1800) != 0);
    do {
    } while (*(int *)(PTR_SPI2_0800dcf4 + 8) << 0x18 < 0);
    do {
    } while ((*(uint *)(PTR_SPI2_0800dcf4 + 8) & 0x600) != 0);
    *(uint *)(PTR_SPI2_0800dcf4 + 4) = *(uint *)(PTR_SPI2_0800dcf4 + 4) & 0xfffffffd;
    *(uint *)(puVar2 + 4) = *(uint *)(puVar2 + 4) & 0xfffffffe;
    *DAT_0800dcf8 = 1;
  }
  return;
}



// ==== 0800dcfc  FUN_0800dcfc  (50 bytes, 6 xrefs)

void FUN_0800dcfc(undefined2 *param_1,undefined2 *param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_ADC1_0800dd34;
  if (*DAT_0800dd30 != '\x01') {
    *param_1 = 0;
    return;
  }
  *(uint *)(PTR_ADC1_0800dd34 + 8) = *(uint *)(PTR_ADC1_0800dd34 + 8) | 0x500000;
  do {
  } while (-1 < *(int *)puVar1 << 0x1e);
  *(undefined4 *)puVar1 = 0xfffffffd;
  *param_1 = (short)*(undefined4 *)(puVar1 + 0x50);
  *param_2 = 0;
  return;
}



// ==== 0800dd38  FUN_0800dd38  (242 bytes, 1 xrefs)

void FUN_0800dd38(void)

{
  undefined *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  puVar1 = PTR_RCC_0800de2c;
  *(uint *)(PTR_RCC_0800de2c + 0x34) = *(uint *)(PTR_RCC_0800de2c + 0x34) | 2;
  *(uint *)PTR_GPIOB_0800de30 = *(uint *)PTR_GPIOB_0800de30 & 0xfffffffc | 3;
  uVar8 = (int)puVar1 >> 0x15;
  puVar3 = (uint *)(PTR_RCC_0800de2c + 0x40);
  *puVar3 = *puVar3 | uVar8;
  uVar4 = *puVar3 & uVar8;
  uVar5 = uVar8 << 0xc;
  *(uint *)puVar1 = *(uint *)puVar1 & 0xff9fffff | uVar5;
  puVar1 = PTR_ADC1_0800de34;
  *(uint *)(PTR_ADC1_0800de34 + 8) = *(uint *)(PTR_ADC1_0800de34 + 8) & ~(uVar8 << 0xe);
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) & 0xfcffffff;
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) & ~((int)uVar5 >> 10);
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) & ~((int)uVar5 >> 0xd);
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) & 0xfff1ffff | 0xe0000;
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) & 0xfffffffd;
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) & ~((int)uVar5 >> 0xd);
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) & 0xff0fffff;
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) & 0xffff17ff;
  uVar5 = DAT_0800de38;
  uVar2 = 0x1f;
  uVar7 = 0x300;
  uVar6 = 0x180;
  do {
    uVar7 = uVar6 & 1 | uVar7 << 1;
    uVar2 = uVar2 - 1;
    uVar6 = uVar6 >> 1;
  } while (uVar6 != 0);
  uVar2 = FUN_080119d4(uVar7 << (uVar2 & 0xff));
  uVar2 = (uVar8 & 0x300) >> (uVar2 & 0xff);
  uVar6 = (uVar5 & 0x1f) << (uVar8 & 0x1f);
  *(uint *)(puVar1 + uVar2 * 4 + 0x30) =
       *(uint *)(puVar1 + uVar2 * 4 + 0x30) & ~(0x1f << (uVar8 & 0x1f)) | uVar6;
  FUN_08010c8c(puVar1,uVar5,5,uVar6,uVar4);
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) | 4;
  do {
  } while (*(int *)(puVar1 + 8) << 0x1d < 0);
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) | 1;
  return;
}



// ==== 0800de3c  FUN_0800de3c  (74 bytes, 1 xrefs)

undefined4 FUN_0800de3c(uint *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = FUN_0800e900(0x69);
  if (-1 < (int)(uVar2 << 0x10)) {
    uVar3 = FUN_0800e900(0x6a);
    *param_1 = (uVar2 & 0x7ff) << 0xc | uVar3 & 0xfff;
    return 2;
  }
  uVar2 = FUN_0800e900(0x68);
  if ((int)(uVar2 << 0x10) < 0) {
    return 0;
  }
  uVar1 = FUN_080028f0(DAT_0800de88 * (uVar2 & 0x1fff),DAT_0800de8c);
  *param_2 = uVar1;
  return 1;
}



// ==== 0800de90  FUN_0800de90  (38 bytes, 1 xrefs)

undefined4 FUN_0800de90(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_0800e900(0xd);
  if ((int)(uVar1 << 0x10) < 0) {
    return 0;
  }
  iVar2 = FUN_0800e900(0xe);
  *param_1 = (uVar1 & 0x7ff) * 0x10000 + iVar2;
  return 1;
}



// ==== 0800deb8  FUN_0800deb8  (42 bytes, 1 xrefs)

void FUN_0800deb8(void)

{
  FUN_0800ee64(0x70,0);
  FUN_0800e280(0);
  FUN_0800ee64(0x50,DAT_0800dee4);
  FUN_0800ee64(0x30,0);
  FUN_0800ee64(0x30,DAT_0800dee8);
  return;
}



// ==== 0800deec  FUN_0800deec  (84 bytes, 2 xrefs)

void FUN_0800deec(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  FUN_0800ee64(0x50,DAT_0800df40);
  FUN_0800e280(3);
  if (param_2 == 0) {
    uVar2 = 0xe000;
  }
  else {
    uVar2 = 0xa300;
  }
  FUN_0800ee64(0x70,uVar2);
  FUN_0800ee64(0x30,0);
  FUN_0800ee64(0x30,DAT_0800df44);
  uVar3 = FUN_08002cb8(param_1);
  FUN_08002be8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),DAT_0800df48,DAT_0800df4c);
  uVar1 = FUN_08002cd4();
  FUN_0800ee64(0x71,uVar1);
  return;
}



// ==== 0800df50  FUN_0800df50  (12 bytes, 4 xrefs)

void FUN_0800df50(void)

{
  FUN_0800ee64(0x50,DAT_0800df5c);
  return;
}



// ==== 0800df60  FUN_0800df60  (12 bytes, 2 xrefs)

void FUN_0800df60(void)

{
  FUN_0800ee64(0x50,DAT_0800df6c);
  return;
}



// ==== 0800df70  FUN_0800df70  (52 bytes, 3 xrefs)

void FUN_0800df70(int param_1)

{
  FUN_0800ee64(0x50,DAT_0800dfa4);
  FUN_0800e280(0);
  FUN_0800ee64(0x70,0);
  FUN_0800e4cc();
  FUN_0800ee64(0x30,DAT_0800dfa8);
  if (param_1 == 0) {
    FUN_0800ee64(0x50,DAT_0800dfac);
  }
  return;
}



// ==== 0800dfb0  FUN_0800dfb0  (84 bytes, 3 xrefs)

void FUN_0800dfb0(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  FUN_0800ee64(0x50,DAT_0800e004);
  FUN_0800ee64(0x70,0xc300);
  uVar3 = FUN_08002cb8(param_2);
  FUN_08002be8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),DAT_0800e008,DAT_0800e00c);
  uVar1 = FUN_08002cd4();
  FUN_0800ee64(0x71,uVar1);
  if (param_1 == 1) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  FUN_0800e280(uVar2);
  FUN_0800ec1c();
  FUN_080123ae(0x32);
  FUN_0800ee64(0x50,DAT_0800e010);
  return;
}



// ==== 0800e014  FUN_0800e014  (28 bytes, 1 xrefs)

void FUN_0800e014(void)

{
  undefined2 uVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_08002cb8();
  FUN_08002be8((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_0800e030,DAT_0800e034);
  uVar1 = FUN_08002cd4();
  FUN_0800ee64(0x71,uVar1);
  return;
}



// ==== 0800e038  FUN_0800e038  (22 bytes, 3 xrefs)

void FUN_0800e038(void)

{
  FUN_0800ea80();
  FUN_0800ee64(0x51,0x300);
  FUN_0800e994();
  return;
}



// ==== 0800e050  FUN_0800e050  (12 bytes, 2 xrefs)

void FUN_0800e050(void)

{
  FUN_0800ee64(0x32,DAT_0800e05c);
  return;
}



// ==== 0800e060  FUN_0800e060  (12 bytes, 2 xrefs)

void FUN_0800e060(void)

{
  FUN_0800ee64(0x30,0);
  return;
}



// ==== 0800e06c  FUN_0800e06c  (14 bytes, 2 xrefs)

void FUN_0800e06c(void)

{
  FUN_0800ee64(0x32,0x244);
  return;
}



// ==== 0800e07c  FUN_0800e07c  (116 bytes, 1 xrefs)

undefined4 FUN_0800e07c(uint param_1,uint param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = FUN_0800e1e4(7);
  iVar2 = DAT_0800e0f0;
  uVar1 = (undefined2)(uVar3 >> 4);
  if (((((((uVar3 & 0xf) < 2) || (uVar4 = FUN_0800e1e4(10), (int)(uVar4 << 0x13) < 0)) ||
        ((uVar4 & 0xff) < 10)) || ((uVar3 >> 4) - 0x118 <= DAT_0800e0f4)) ||
      (((param_2 < param_1 && (param_1 - *(ushort *)(iVar2 + 2) == 1)) &&
       (((int)((uint)*(ushort *)(iVar2 + 4) << 0x14) < 0 || (*(ushort *)(iVar2 + 4) < 0x14)))))) ||
     (((param_2 <= param_1 && (*(ushort *)(iVar2 + 2) - param_1 == 1)) &&
      ((-1 < (int)((uint)*(ushort *)(iVar2 + 4) << 0x14) || (DAT_0800e0f8 < *(ushort *)(iVar2 + 4)))
      )))) {
    *(short *)(iVar2 + 2) = (short)param_1;
    *(undefined2 *)(iVar2 + 4) = uVar1;
    return 0xffffffff;
  }
  *(short *)(iVar2 + 2) = (short)param_1;
  *(undefined2 *)(iVar2 + 4) = uVar1;
  return 0;
}



// ==== 0800e0fc  FUN_0800e0fc  (176 bytes, 5 xrefs)

void FUN_0800e0fc(short param_1,int param_2)

{
  undefined1 *puVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = DAT_0800e1ac;
  if (param_2 != 1) {
    FUN_0800e250(2,DAT_0800e1b0);
    *puVar1 = 0;
    if (*DAT_0800e1b4 == '\0') {
      FUN_0800e660(4,0);
    }
    return;
  }
  *DAT_0800e1ac = 1;
  FUN_0800e660(4,1);
  iVar3 = DAT_0800e1c0;
  pcVar2 = DAT_0800e1b8;
  if (*DAT_0800e1b8 == '\0') {
    uVar4 = 0;
    do {
      FUN_0800e250(uVar4 & 0xff,*(undefined2 *)(iVar3 + uVar4 * 2));
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 0x22);
    FUN_080123ae(0xfa);
    iVar3 = DAT_0800e1c4;
    FUN_0800e250(0x19,DAT_0800e1c4 + -0x80);
    FUN_0800e250(0x19,iVar3);
    FUN_080123ae(0x3c);
    *pcVar2 = '\x01';
  }
  else {
    FUN_0800e250(2,DAT_0800e1b0 + -0x40);
  }
  FUN_0800e250(5,DAT_0800e1bc);
  FUN_0800e250(3,param_1 - 0x2f8U);
  FUN_080123ae(10);
  FUN_0800e250(3,param_1 - 0x2f8U | 0x8000);
  return;
}



// ==== 0800e1c8  FUN_0800e1c8  (20 bytes, 5 xrefs)

void FUN_0800e1c8(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    uVar1 = DAT_0800e1e0;
  }
  else {
    uVar1 = DAT_0800e1dc;
  }
  FUN_0800e250(2,uVar1);
  return;
}



// ==== 0800e1e4  FUN_0800e1e4  (44 bytes, 3 xrefs)

uint FUN_0800e1e4(char param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint local_10;
  
  local_10 = param_4;
  FUN_0800fc3c();
  FUN_0800fb9c(0x80);
  FUN_0800fb9c(param_1 * '\x02' + '\x01');
  FUN_0800fac2(&local_10,2);
  FUN_0800fc70();
  return (local_10 & 0xff) << 8 | local_10 >> 8 & 0xff;
}



// ==== 0800e210  FUN_0800e210  (20 bytes, 1 xrefs)

void FUN_0800e210(undefined2 param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = FUN_0800e1e4(7);
  iVar1 = DAT_0800e224;
  *(undefined2 *)(DAT_0800e224 + 2) = param_1;
  *(short *)(iVar1 + 4) = (short)(uVar2 >> 4);
  return;
}



// ==== 0800e228  FUN_0800e228  (40 bytes, 5 xrefs)

void FUN_0800e228(short param_1)

{
  FUN_0800e250(3,param_1 - 0x2f8U);
  FUN_080123ae(10);
  FUN_0800e250(3,param_1 - 0x2f8U | 0x8000);
  return;
}



// ==== 0800e250  FUN_0800e250  (46 bytes, 11 xrefs)

void FUN_0800e250(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  
  local_10 = param_4;
  FUN_0800fc3c();
  FUN_0800fb9c(0x80);
  FUN_0800fb9c((param_1 & 0x7f) << 1);
  local_10._0_2_ = CONCAT11((char)param_2,(char)((uint)param_2 >> 8));
  FUN_0800fca4(&local_10,2);
  FUN_0800fc70();
  return;
}



// ==== 0800e280  FUN_0800e280  (16 bytes, 14 xrefs)

void FUN_0800e280(int param_1)

{
  FUN_0800ee64(0x47,param_1 << 8 | DAT_0800e290);
  return;
}



// ==== 0800e294  FUN_0800e294  (176 bytes, 2 xrefs)

void FUN_0800e294(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = DAT_0800e354;
  uVar1 = DAT_0800e350;
  uVar4 = DAT_0800e348;
  if (param_1 == 0x36) {
    uVar3 = DAT_0800e358;
    goto LAB_0800e318;
  }
  if (0x36 < param_1) {
    if (param_1 == 0x41) {
      uVar4 = DAT_0800e34c;
    }
    else {
      if (param_1 < 0x42) {
        if (param_1 == 0x37) {
          uVar2 = DAT_0800e35c;
          goto LAB_0800e30c;
        }
        if (param_1 != 0x38) {
          if (param_1 != 0x39) {
            return;
          }
          uVar3 = DAT_0800e35c;
          goto LAB_0800e318;
        }
        uVar2 = DAT_0800e35c;
        goto LAB_0800e2f8;
      }
      if (param_1 == 0x42) {
        uVar4 = DAT_0800e358;
      }
      else if (param_1 == 0x43) {
        uVar4 = DAT_0800e35c;
      }
      else {
        uVar4 = DAT_0800e344;
        if (param_1 != 0x44) {
          return;
        }
      }
    }
    FUN_0800ee64(0x71,uVar4,DAT_0800e34c,DAT_0800e358,param_4);
    uVar2 = DAT_0800e360;
    goto LAB_0800e338;
  }
  if (param_1 == 0x32) {
    uVar2 = DAT_0800e34c;
LAB_0800e2f8:
    FUN_0800ee64(0x71,uVar2,DAT_0800e34c,DAT_0800e358,param_4);
    uVar2 = uVar4;
    goto LAB_0800e338;
  }
  if (param_1 < 0x33) {
    uVar3 = DAT_0800e344;
    if (param_1 == 0x23) {
LAB_0800e318:
      FUN_0800ee64(0x71,uVar3,DAT_0800e34c,DAT_0800e358,param_4);
      goto LAB_0800e338;
    }
    uVar2 = DAT_0800e344;
    if (param_1 != 0x2a) {
      if (param_1 == 0x30) goto LAB_0800e2f8;
      if (param_1 != 0x31) {
        return;
      }
      uVar2 = DAT_0800e34c;
    }
  }
  else {
    if (param_1 == 0x33) {
      uVar3 = DAT_0800e34c;
      goto LAB_0800e318;
    }
    if (param_1 != 0x34) {
      if (param_1 != 0x35) {
        return;
      }
      uVar2 = DAT_0800e358;
      goto LAB_0800e2f8;
    }
    uVar2 = DAT_0800e358;
  }
LAB_0800e30c:
  FUN_0800ee64(0x71,uVar2,DAT_0800e34c,DAT_0800e358,param_4);
  uVar2 = uVar1;
LAB_0800e338:
  FUN_0800ee64(0x72,uVar2);
  return;
}



// ==== 0800e364  FUN_0800e364  (54 bytes, 1 xrefs)

void FUN_0800e364(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800e900(0x31);
  FUN_0800ee64(0x31,uVar1 | 1);
  FUN_0800ee64(0x42,DAT_0800e39c);
  FUN_0800ee64(0x2a,DAT_0800e3a0);
  FUN_0800ee64(0x2b,0x400);
  FUN_0800ee64(0x2f,DAT_0800e3a4);
  return;
}



// ==== 0800e3a8  FUN_0800e3a8  (22 bytes, 3 xrefs)

void FUN_0800e3a8(void)

{
  FUN_0800ee64(0x21,0x6d8);
  FUN_0800ee64(0x24,DAT_0800e3c0);
  return;
}



// ==== 0800e3c4  FUN_0800e3c4  (54 bytes, 2 xrefs)

void FUN_0800e3c4(void)

{
  FUN_0800ee64(0x70,0xc3);
  FUN_0800ee64(0x72,DAT_0800e3fc);
  FUN_0800ee64(0x58,0xc1);
  FUN_0800ee64(0x5c,DAT_0800e400);
  FUN_0800ee64(0x5d,0x4700);
  FUN_0800ee64(0x5e,DAT_0800e404);
  return;
}



// ==== 0800e408  FUN_0800e408  (56 bytes, 3 xrefs)

void FUN_0800e408(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_0800e900(0x31);
  FUN_0800ee64(0x31,uVar1 | 2);
  FUN_0800ee64(0x71,param_1 * 0x408 + DAT_0800e440 & 0xffff);
  uVar1 = FUN_0800e900(0x2b);
  FUN_0800ee64(0x2b,uVar1 | 1);
  return;
}



// ==== 0800e444  FUN_0800e444  (68 bytes, 2 xrefs)

void FUN_0800e444(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_0800e900(0x31);
  FUN_0800ee64(0x46,(param_1 & 0x7ff) + 0x6000);
  FUN_0800ee64(0x79,(param_2 & 0x7ff) + 0x1800);
  FUN_0800ee64(0x7a,DAT_0800e488);
  FUN_0800ee64(0x31,uVar1 | 4);
  return;
}



// ==== 0800e48c  FUN_0800e48c  (54 bytes, 1 xrefs)

void FUN_0800e48c(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800e900(0x31);
  FUN_0800ee64(0x31,uVar1 & 0xfffffffe);
  FUN_0800ee64(0x42,DAT_0800e4c4);
  FUN_0800ee64(0x2a,0x7400);
  FUN_0800ee64(0x2b,0);
  FUN_0800ee64(0x2f,DAT_0800e4c8);
  return;
}



// ==== 0800e4cc  FUN_0800e4cc  (12 bytes, 3 xrefs)

void FUN_0800e4cc(void)

{
  FUN_0800ee64(0x24,0);
  return;
}



// ==== 0800e4d8  FUN_0800e4d8  (30 bytes, 4 xrefs)

void FUN_0800e4d8(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800e900(0x31);
  FUN_0800ee64(0x31,uVar1 & 0xfffffffd);
  FUN_0800ee64(0x2b,0);
  return;
}



// ==== 0800e4f6  FUN_0800e4f6  (12 bytes, 1 xrefs)

void FUN_0800e4f6(void)

{
  FUN_0800ee64(0x51,0);
  return;
}



// ==== 0800e502  FUN_0800e502  (22 bytes, 3 xrefs)

void FUN_0800e502(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800e900(0x31);
  FUN_0800ee64(0x31,uVar1 & 0xfffffffb);
  return;
}



// ==== 0800e518  FUN_0800e518  (34 bytes, 4 xrefs)

void FUN_0800e518(void)

{
  FUN_0800ee64(0x3f,0);
  FUN_0800ee64(0x59,0x68);
  FUN_080123ae(0x1e);
  FUN_0800ee64(0x30,0);
  return;
}



// ==== 0800e53c  FUN_0800e53c  (54 bytes, 2 xrefs)

void FUN_0800e53c(void)

{
  FUN_0800e518();
  FUN_0800ee64(2,0);
  FUN_0800ee64(0x3f,0);
  FUN_0800e994();
  FUN_0800ee64(0x3f,0x3000);
  FUN_0800ee64(0x59,DAT_0800e574);
  FUN_0800ee64(0x59,DAT_0800e578);
  return;
}



// ==== 0800e57c  FUN_0800e57c  (118 bytes, 1 xrefs)

void FUN_0800e57c(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = -0x38;
  FUN_080123ae(0x1e);
  FUN_0800ee64(0x3f,0x8000);
  FUN_0800ee64(0x59,DAT_0800e5f4);
  FUN_0800ee64(0x59,0x68);
  uVar1 = 0;
  do {
    FUN_0800ee64(0x5f,*(undefined2 *)(param_1 + uVar1 * 2));
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x24);
  FUN_080123ae(0x14);
  FUN_0800ee64(0x59,DAT_0800e5f8);
  while ((cVar2 != '\0' && (uVar1 = FUN_0800e900(0xc), (uVar1 & 1) == 0))) {
    FUN_080123ae(5);
    cVar2 = cVar2 + -1;
  }
  FUN_0800ee64(2,0);
  FUN_080123ae(0x1e);
  FUN_0800e518();
  return;
}



// ==== 0800e5fc  FUN_0800e5fc  (12 bytes, 1 xrefs)

uint FUN_0800e5fc(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800e900(0xc);
  return uVar1 >> 0xe;
}



// ==== 0800e608  FUN_0800e608  (14 bytes, 1 xrefs)

uint FUN_0800e608(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800e900(0xb);
  return (uVar1 & 0xfff) >> 8;
}



// ==== 0800e616  FUN_0800e616  (14 bytes, 3 xrefs)

uint FUN_0800e616(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800e900(0x67);
  return uVar1 & 0x1ff;
}



// ==== 0800e624  FUN_0800e624  (42 bytes, 1 xrefs)

void FUN_0800e624(ushort *param_1,byte *param_2,undefined1 *param_3)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  
  uVar3 = FUN_0800e900(0x67);
  *param_1 = uVar3 & 0x1ff;
  bVar1 = FUN_0800e900(0x65);
  *param_2 = bVar1 & 0x7f;
  uVar2 = FUN_0800e900(99);
  *param_3 = uVar2;
  return;
}



// ==== 0800e64e  FUN_0800e64e  (18 bytes, 1 xrefs)

void FUN_0800e64e(ushort *param_1)

{
  ushort uVar1;
  
  uVar1 = FUN_0800e900(100);
  *param_1 = uVar1 & 0x7fff;
  return;
}



// ==== 0800e660  FUN_0800e660  (34 bytes, 20 xrefs)

void FUN_0800e660(uint param_1,int param_2)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = DAT_0800e684;
  uVar1 = (ushort)(0x40 >> (param_1 & 0xff));
  if (param_2 == 1) {
    *DAT_0800e684 = uVar1 | *DAT_0800e684;
  }
  else {
    *DAT_0800e684 = *DAT_0800e684 & ~uVar1;
  }
  FUN_0800ee64(0x33,*puVar2);
  return;
}



// ==== 0800e688  FUN_0800e688  (450 bytes, 1 xrefs)

void FUN_0800e688(void)

{
  undefined *puVar1;
  
  *(undefined4 *)(PTR_GPIOF_0800e84c + 0x18) = 0x200;
  puVar1 = PTR_GPIOB_0800e850;
  *(undefined4 *)(PTR_GPIOB_0800e850 + 0x18) = 0x100;
  *(undefined4 *)(puVar1 + 0x18) = 0x200;
  FUN_0800ee64(0,0x8000);
  FUN_0800ee64(0);
  FUN_0800ee64(0x37,DAT_0800e854);
  FUN_0800ee64(0x36,0x22);
  FUN_0800ee64(0x10,0x318);
  FUN_0800ee64(0x11,DAT_0800e858);
  FUN_0800ee64(0x12,DAT_0800e858 + 0xa1);
  FUN_0800ee64(0x13,DAT_0800e858 + 0xa5);
  FUN_0800ee64(0x14,0x210);
  FUN_0800ee64(0x49,DAT_0800e85c);
  FUN_0800ee64(0x7b,DAT_0800e860);
  FUN_0800ee64(0x7d,DAT_0800e864);
  FUN_0800ee64(0x48,DAT_0800e868);
  FUN_0800ee64(0x40,DAT_0800e86c);
  FUN_0800ee64(9,0x6f);
  FUN_0800ee64(9,DAT_0800e870);
  FUN_0800ee64(9,DAT_0800e874);
  FUN_0800ee64(9,DAT_0800e878);
  FUN_0800ee64(9,DAT_0800e87c);
  FUN_0800ee64(9,DAT_0800e880);
  FUN_0800ee64(9,DAT_0800e884);
  FUN_0800ee64(9,DAT_0800e888);
  FUN_0800ee64(9,DAT_0800e88c);
  FUN_0800ee64(9,DAT_0800e890);
  FUN_0800ee64(9,DAT_0800e894);
  FUN_0800ee64(9,DAT_0800e898);
  FUN_0800ee64(9,DAT_0800e89c);
  FUN_0800ee64(9,DAT_0800e8a0);
  FUN_0800ee64(9,DAT_0800e8a4);
  FUN_0800ee64(9,DAT_0800e8a8);
  FUN_0800ee64(0x1c,0x7c0);
  FUN_0800ee64(0x1d,DAT_0800e8ac);
  FUN_0800ee64(0x1e,DAT_0800e8b0);
  FUN_0800ee64(0x1f,DAT_0800e8b4);
  FUN_0800ee64(0x3e,DAT_0800e8b8);
  FUN_0800ee64(0x73,DAT_0800e8bc);
  FUN_0800ee64(0x77,DAT_0800e8c0);
  FUN_0800ee64(0x19,DAT_0800e870 + -0x2a);
  FUN_0800ee64(0x28,0xb40);
  FUN_0800ee64(0x29,0xaa00);
  FUN_0800ee64(0x2a,0x6600);
  FUN_0800ee64(0x2c,DAT_0800e8c4);
  FUN_0800ee64(0x2f,DAT_0800e8c8);
  FUN_0800ee64(0x53,DAT_0800e874 + -0x3f);
  FUN_0800ee64(0x7e,DAT_0800e878 + -0x24);
  FUN_0800ee64(0x46,DAT_0800e884 + -0x30);
  FUN_0800ee64(0x4a,DAT_0800e8cc);
  FUN_0800ee64(7,DAT_0800e8d0);
  *DAT_0800e8d4 = 0x9000;
  FUN_0800ee64(0x33);
  FUN_0800ee64(0x3f,0);
  return;
}



// ==== 0800e8d8  FUN_0800e8d8  (36 bytes, 1 xrefs)

uint FUN_0800e8d8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = 0;
  uVar1 = param_1;
  do {
    uVar2 = (uVar1 & 0x7fff) << 1;
    if ((int)(uVar1 << 0x14) < 0) {
      uVar2 = uVar2 ^ DAT_0800e8fc;
    }
    bVar3 = bVar3 + 1;
    uVar1 = uVar2;
  } while (bVar3 < 0xc);
  return param_1 | ((uVar2 & 0xfff) >> 1) << 0xc;
}



// ==== 0800e900  FUN_0800e900  (60 bytes, 29 xrefs)

undefined4 FUN_0800e900(uint param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar1 = PTR_GPIOF_0800e93c;
  *(undefined4 *)(PTR_GPIOF_0800e93c + 0x18) = 0x200;
  puVar2 = PTR_GPIOB_0800e940;
  *(undefined4 *)(PTR_GPIOB_0800e940 + 0x28) = 0x100;
  thunk_FUN_0800f48a(5);
  *(undefined4 *)(puVar1 + 0x28) = 0x200;
  FUN_0800eb74(param_1 | 0x80);
  uVar3 = FUN_0800eb18();
  *(undefined4 *)(puVar1 + 0x18) = 0x200;
  thunk_FUN_0800f48a(5);
  *(undefined4 *)(puVar2 + 0x18) = 0x100;
  *(undefined4 *)(puVar2 + 0x18) = 0x200;
  return uVar3;
}



// ==== 0800e944  FUN_0800e944  (78 bytes, 1 xrefs)

void FUN_0800e944(int param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6)

{
  FUN_0800ee64(0x70,0,param_3,param_4,param_4);
  FUN_0800ee64(0x4d,param_5 + 0xa000);
  FUN_0800ee64(0x4e,param_6 + 0x6f00);
  FUN_0800ee64(0x4f,param_4 << 8 | param_3);
  FUN_0800ee64(0x78,param_1 << 8 | param_2);
  FUN_0800e280(0);
  FUN_0800e994();
  return;
}



// ==== 0800e994  FUN_0800e994  (28 bytes, 4 xrefs)

void FUN_0800e994(void)

{
  FUN_0800ee64(0x37,DAT_0800e9b0);
  FUN_0800ee64(0x30,0);
  FUN_0800ee64(0x30,DAT_0800e9b4);
  return;
}



// ==== 0800e9b8  FUN_0800e9b8  (48 bytes, 2 xrefs)

void FUN_0800e9b8(uint param_1)

{
  FUN_0800ee64(0x51,DAT_0800e9e8);
  FUN_0800ee64(7,DAT_0800e9ec);
  FUN_0800ee64(8,param_1 & 0xfff);
  FUN_0800ee64(8,((param_1 & 0xffffff) >> 0xc) + 0x8000);
  return;
}



// ==== 0800e9f0  FUN_0800e9f0  (8 bytes, 2 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    Instruction at (ram,0x0800ebda) overlaps instruction at (ram,0x0800ebd8)


// ==== 0800ea2c  FUN_0800ea2c  (20 bytes, 2 xrefs)

void FUN_0800ea2c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = DAT_0800ea40;
  }
  else {
    uVar1 = 0x8f;
  }
  FUN_0800ee64(0x52,uVar1);
  return;
}



// ==== 0800ea44  FUN_0800ea44  (44 bytes, 4 xrefs)

void FUN_0800ea44(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  if (param_1 == DAT_0800ea70) {
    uVar2 = DAT_0800ea74;
  }
  else {
    uVar2 = DAT_0800ea78;
  }
  FUN_0800ee64(0x51,uVar2);
  uVar1 = FUN_080028f0(param_1 * DAT_0800ea7c,1000);
  FUN_0800ee64(7,uVar1);
  return;
}



// ==== 0800ea80  FUN_0800ea80  (22 bytes, 3 xrefs)

void FUN_0800ea80(uint param_1)

{
  FUN_0800ee64(0x38,param_1 & 0xffff);
  FUN_0800ee64(0x39,param_1 >> 0x10);
  return;
}



// ==== 0800ea98  FUN_0800ea98  (28 bytes, 4 xrefs)

void FUN_0800ea98(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < DAT_0800eab4) {
    uVar1 = 8;
  }
  else {
    uVar1 = 0x22;
  }
  FUN_0800ee64(0x36,param_1 * 0x100 + 0x80U | uVar1);
  return;
}



// ==== 0800eab8  FUN_0800eab8  (12 bytes, 1 xrefs)

void FUN_0800eab8(void)

{
  FUN_0800ee64(7,DAT_0800eac4);
  return;
}



// ==== 0800eac8  FUN_0800eac8  (20 bytes, 1 xrefs)

void FUN_0800eac8(void)

{
  FUN_0800ee64(0x52,DAT_0800eadc);
  FUN_0800ee64(0x51,DAT_0800eae0);
  return;
}



// ==== 0800eae4  FUN_0800eae4  (20 bytes, 1 xrefs)

void FUN_0800eae4(void)

{
  FUN_0800ee64(7,DAT_0800eaf8);
  FUN_0800ee64(0x51,DAT_0800eafc);
  return;
}



// ==== 0800eb00  FUN_0800eb00  (22 bytes, 3 xrefs)

void FUN_0800eb00(void)

{
  FUN_0800ee64(0x30,0);
  FUN_0800ee64(0x37,0x1d00);
  return;
}



// ==== 0800eb18  FUN_0800eb18  (86 bytes, 1 xrefs)

uint FUN_0800eb18(void)

{
  undefined *puVar1;
  undefined4 in_r3;
  byte bVar2;
  uint uVar3;
  
  puVar1 = PTR_GPIOB_0800eb70;
  uVar3 = 0;
  FUN_08011012(PTR_GPIOB_0800eb70,0x200,0,in_r3,in_r3);
  thunk_FUN_0800f48a(5);
  bVar2 = 0;
  do {
    *(undefined4 *)(puVar1 + 0x18) = 0x100;
    uVar3 = (uint)((~*(uint *)(puVar1 + 0x10) & 0x200) == 0) | (uVar3 & 0x7fff) << 1;
    *(undefined4 *)(puVar1 + 0x28) = 0x100;
    thunk_FUN_0800f48a(5);
    bVar2 = bVar2 + 1;
  } while (bVar2 < 0x10);
  FUN_08011012(puVar1,0x200,1);
  return uVar3;
}



// ==== 0800eb74  FUN_0800eb74  (56 bytes, 4 xrefs)

void FUN_0800eb74(uint param_1)

{
  undefined *puVar1;
  byte bVar2;
  
  puVar1 = PTR_GPIOB_0800ebac;
  *(undefined4 *)(PTR_GPIOB_0800ebac + 0x28) = 0x100;
  bVar2 = 0;
  do {
    if ((int)(param_1 << 0x18) < 0) {
      *(undefined4 *)(puVar1 + 0x18) = DAT_0800ebb0;
    }
    else {
      *(undefined4 *)(puVar1 + 0x28) = DAT_0800ebb0;
    }
    thunk_FUN_0800f48a(5);
    *(undefined4 *)(puVar1 + 0x18) = 0x100;
    thunk_FUN_0800f48a(5);
    *(undefined4 *)(puVar1 + 0x28) = 0x100;
    bVar2 = bVar2 + 1;
    param_1 = (param_1 & 0x7f) << 1;
  } while (bVar2 < 8);
  return;
}



// ==== 0800ebb4  FUN_0800ebb4  (66 bytes, 1 xrefs)

void FUN_0800ebb4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_0800e3a8();
  FUN_0800ee64(0x50,DAT_0800ebf8);
  if (param_1 == 1) {
    uVar1 = 3;
  }
  else {
    uVar1 = 0;
  }
  FUN_0800e280(uVar1);
  FUN_0800ee64(0x70,DAT_0800ebfc);
  FUN_0800ec1c();
  FUN_080123ae(0x32);
  FUN_0800e294(param_2);
  FUN_0800ee64(0x50,DAT_0800ec00);
  return;
}



// ==== 0800ec04  FUN_0800ec04  (20 bytes, 1 xrefs)

void FUN_0800ec04(void)

{
  FUN_0800ee64(0x30,0);
  FUN_0800ee64(0x30,DAT_0800ec18);
  return;
}



// ==== 0800ec1c  FUN_0800ec1c  (12 bytes, 5 xrefs)

void FUN_0800ec1c(void)

{
  FUN_0800ee64(0x30,DAT_0800ec28);
  return;
}



// ==== 0800ec2c  FUN_0800ec2c  (88 bytes, 2 xrefs)

void FUN_0800ec2c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  uint uVar2;
  
  for (uVar2 = 0; *(char *)(param_1 + uVar2) != '\0'; uVar2 = uVar2 + 1 & 0xff) {
    FUN_0800e294();
    FUN_0800ee64(0x50,DAT_0800ec84);
    if ((param_2 == 1) && (uVar2 == 0)) {
      uVar1 = param_3;
    }
    else if ((*(char *)(param_1 + uVar2) == '*') || (*(char *)(param_1 + uVar2) == '#')) {
      uVar1 = param_4;
    }
    else {
      uVar1 = param_5;
    }
    FUN_080123ae(uVar1);
    FUN_0800ee64(0x50,DAT_0800ec88);
    FUN_080123ae(param_6);
  }
  return;
}



// ==== 0800ec8c  FUN_0800ec8c  (40 bytes, 2 xrefs)

void FUN_0800ec8c(int param_1)

{
  undefined4 uVar1;
  
  FUN_0800e3a8();
  FUN_0800ee64(0x50,DAT_0800ecb4);
  if (param_1 == 1) {
    uVar1 = 3;
  }
  else {
    uVar1 = 0;
  }
  FUN_0800e280(uVar1);
  FUN_0800ee64(0x70,DAT_0800ecb8);
  return;
}



// ==== 0800ecbc  FUN_0800ecbc  (152 bytes, 1 xrefs)

void FUN_0800ecbc(void)

{
  int iVar1;
  uint uVar2;
  
  FUN_0800e280(0);
  FUN_0800ee64(0x58,DAT_0800ed54);
  FUN_0800ee64(0x72,DAT_0800ed58);
  FUN_0800ee64(0x70,0xc3);
  FUN_0800ee64(0x5d,0xd00);
  FUN_0800ee64(0x59,DAT_0800ed5c);
  FUN_0800ee64(0x59,0x68);
  FUN_0800ee64(0x5a,DAT_0800ed60);
  FUN_0800ee64(0x5b,DAT_0800ed60 + 0x55);
  FUN_0800ee64(0x5c,DAT_0800ed64);
  iVar1 = DAT_0800ed68;
  uVar2 = 0;
  do {
    FUN_0800ee64(0x5f,*(undefined2 *)(iVar1 + uVar2 * 2));
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 7);
  FUN_080123ae(0x14);
  FUN_0800ee64(0x59,DAT_0800ed6c);
  FUN_080123ae(0xb4);
  FUN_0800ee64(0x59,0x68);
  FUN_0800ee64(0x70,0);
  FUN_0800ee64(0x58,0);
  return;
}



// ==== 0800ed70  FUN_0800ed70  (28 bytes, 1 xrefs)

void FUN_0800ed70(void)

{
  FUN_0800ee64(0x37,DAT_0800ed8c);
  FUN_0800ee64(0x30,0);
  FUN_0800ee64(0x30,DAT_0800ed90);
  return;
}



// ==== 0800ed94  FUN_0800ed94  (118 bytes, 1 xrefs)

void FUN_0800ed94(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_0800ee0c;
  FUN_0800ee64(0x50,DAT_0800ee0c);
  FUN_0800e280(0);
  FUN_0800ee64(0x70,0xc300);
  FUN_0800ec1c();
  FUN_080123ae(0x32);
  FUN_0800ee64(0x71,DAT_0800ee10);
  uVar2 = DAT_0800ee14;
  FUN_0800ee64(0x50,DAT_0800ee14);
  FUN_080123ae(0x50);
  FUN_0800ee64(0x50,uVar1);
  FUN_0800ee64(0x71,DAT_0800ee18);
  FUN_0800ee64(0x50,uVar2);
  FUN_080123ae(0x50);
  FUN_0800ee64(0x50,uVar1);
  FUN_0800ee64(0x70,0);
  FUN_0800ee64(0x30,DAT_0800ee1c);
  return;
}



// ==== 0800ee20  FUN_0800ee20  (46 bytes, 1 xrefs)

void FUN_0800ee20(void)

{
  FUN_0800e280(0);
  FUN_0800ee64(0x7e,DAT_0800ee50);
  FUN_0800ee64(0x50,DAT_0800ee54);
  FUN_0800ee64(0x36,0);
  FUN_0800ee64(0x52,DAT_0800ee58);
  FUN_0800ed70();
  return;
}



// ==== 0800ee5c  FUN_0800ee5c  (8 bytes, 2 xrefs)

void FUN_0800ee5c(void)

{
  FUN_0800e994();
  return;
}



// ==== 0800ee64  FUN_0800ee64  (74 bytes, 204 xrefs)

void FUN_0800ee64(undefined4 param_1,uint param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_GPIOF_0800eeb0;
  *(undefined4 *)(PTR_GPIOF_0800eeb0 + 0x18) = 0x200;
  puVar2 = PTR_GPIOB_0800eeb4;
  *(undefined4 *)(PTR_GPIOB_0800eeb4 + 0x28) = 0x100;
  thunk_FUN_0800f48a(5);
  *(undefined4 *)(puVar1 + 0x28) = 0x200;
  FUN_0800eb74(param_1);
  thunk_FUN_0800f48a(5);
  FUN_0800eb74(param_2 >> 8);
  FUN_0800eb74(param_2 & 0xff);
  thunk_FUN_0800f48a(5);
  *(undefined4 *)(puVar1 + 0x18) = 0x200;
  thunk_FUN_0800f48a(5);
  *(undefined4 *)(puVar2 + 0x18) = 0x100;
  *(undefined4 *)(puVar2 + 0x18) = 0x200;
  return;
}



// ==== 0800eeb8  FUN_0800eeb8  (146 bytes, 1 xrefs)

void FUN_0800eeb8(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_30 [36];
  
  iVar2 = FUN_080029e6(param_1,s_version_0800ef4c);
  if (iVar2 == 0) {
    FUN_08011368(1,s_version___s__s_0800ef98,s_Sep_19_2025_0800ef8c,s_17_17_06_0800ef80);
  }
  else {
    iVar2 = FUN_080029e6(param_1,s_spi2writedma_0800ef54);
    if (iVar2 == 0) {
      FUN_0800298c(auStack_30,8,0x5a);
      FUN_080104c0(auStack_30,8);
      pcVar3 = s_spi2writedma_cmp_0800efac;
    }
    else {
      iVar2 = FUN_080029e6(param_1,s_spi2readdma_0800ef64);
      if (iVar2 == 0) {
        FUN_0800298c(auStack_30,0x20,0x5a);
        puVar1 = PTR_GPIOC_0800efc0;
        *(undefined4 *)(PTR_GPIOC_0800efc0 + 0x18) = 0x2000;
        FUN_080103fc(auStack_30,8);
        *(undefined4 *)(puVar1 + 0x28) = 0x2000;
        pcVar3 = &DAT_0800efc4;
      }
      else {
        iVar2 = FUN_080029e6(param_1,s_spi2writeread_0800ef70);
        if (iVar2 != 0) {
          FUN_0800efec(param_1);
          return;
        }
        FUN_08010584(0x5a);
        pcVar3 = s_spi2writeread_cmp_0800efd8;
      }
    }
    FUN_08011368(1,pcVar3);
  }
  return;
}



// ==== 0800efec  FUN_0800efec  (736 bytes, 1 xrefs)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800efec(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  char *pcVar4;
  uint uVar5;
  uint *local_38;
  uint local_34 [3];
  undefined1 local_28 [20];
  
  local_38 = (uint *)0x0;
  local_34[0] = 0;
  local_34[1] = 0;
  local_34[2] = 0;
  iVar1 = FUN_080029b0(param_1,s_readnor_0800f2cc);
  if (iVar1 != 0) {
    iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,1,iVar1);
    if (iVar1 == 0) {
      FUN_0800ff84(local_28,local_38,0x10);
      uVar5 = 0;
      do {
        FUN_08011368(1,s__02x_0800f2d4,local_28[uVar5]);
        uVar5 = uVar5 + 1 & 0xffff;
      } while (uVar5 < 0x10);
      FUN_08011368(1,&DAT_0800f2dc);
      pcVar4 = s_readnor_0x_04x_end_0800f2e0;
      goto LAB_0800f0ce;
    }
LAB_0800f0f8:
    FUN_08011368(1,s_Para_error_0800f348);
    return;
  }
  iVar1 = FUN_080029b0(param_1,s_writenor_0800f2f8);
  if (iVar1 != 0) {
    iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,2,iVar1);
    if (iVar1 == 0) {
      FUN_0800298c(local_28,0x10,local_34[0]);
      FUN_08010050(local_28,local_38,0x10,0);
      pcVar4 = s_writenor_0x_04x_0x_02x_end_0800f304;
      puVar3 = local_38;
      param_1 = local_34[0];
      goto LAB_0800f2b2;
    }
    goto LAB_0800f0f8;
  }
  iVar1 = FUN_080029b0(param_1,s_readnor_0800f2cc);
  if (iVar1 != 0) {
    iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,1,iVar1);
    if (iVar1 != 0) {
      return;
    }
    FUN_0800ff84(local_28,local_38,0x10);
    uVar5 = 0;
    do {
      FUN_08011368(1,s__02x_0800f2d4,local_28[uVar5]);
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 0x10);
    pcVar4 = s_readnor_0x_08x_cmp_0800f324;
LAB_0800f0ce:
    FUN_08011368(1,pcVar4,local_38);
    return;
  }
  iVar1 = FUN_080029b0(param_1,s_erasenor_0800f33c);
  if (iVar1 != 0) {
    iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,1,iVar1);
    if (iVar1 != 0) goto LAB_0800f0f8;
    FUN_0800fefc(local_38);
    pcVar4 = s_erasenor_0x_04x_end_0800f358;
    goto LAB_0800f0ce;
  }
  iVar1 = FUN_080029b0(param_1,s_memread4_0800f370);
  if (iVar1 != 0) {
    iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,2,iVar1);
    if (iVar1 != 0) {
      return;
    }
    local_38 = (uint *)(((int)local_38 / 4) * 4);
    local_34[0] = (int)(((uint)((int)(local_34[0] + 3) >> 0x1f) >> 0x1e) + local_34[0] + 3) >> 2;
    for (uVar5 = 0; (int)uVar5 < (int)local_34[0]; uVar5 = uVar5 + 1 & 0xffff) {
      uVar2 = *local_38;
      FUN_08011978(s__02X__02X__02X__02X_0800f37c,uVar2 & 0xff,(uVar2 & 0xffff) >> 8,
                   (uVar2 & 0xffffff) >> 0x10,uVar2 >> 0x18);
      local_38 = local_38 + 1;
    }
    FUN_08011978(&DAT_0800f2dc);
    return;
  }
  iVar1 = FUN_080029b0(param_1,s_memwrite1_0800f394);
  if (iVar1 == 0) {
    iVar1 = FUN_080029b0(param_1,s_memwrite2_0800f3a0);
    if (iVar1 != 0) {
      iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,2,iVar1);
      if (iVar1 != 0) {
        return;
      }
      *(ushort *)local_38 = (ushort)local_34[0];
      param_1 = (uint)(ushort)*local_38;
      pcVar4 = s_memwrite2_0x_x_0x_x_0800f3ac;
      puVar3 = local_38;
      goto LAB_0800f2b2;
    }
    iVar1 = FUN_080029b0(param_1,s_memwrite4_0800f3c4);
    if (iVar1 == 0) {
      iVar1 = FUN_080029b0(param_1,s_print_0800f3e8);
      if (iVar1 != 0) {
        iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,1,iVar1);
        if (iVar1 == 0) {
          *_DAT_0800f3f0 = (char)local_38;
          return;
        }
        return;
      }
      iVar1 = FUN_080029b0(param_1,s_setuartmode_0800f3f3 + 1);
      if (iVar1 == 0) {
        iVar1 = FUN_080029b0(param_1,s_setkey_0800f414);
        if (iVar1 == 0) {
          iVar1 = FUN_080029b0(param_1,s_read4829_0800f430);
          if (iVar1 == 0) {
            *(undefined1 *)(param_1 + 0x3f) = 0;
            puVar3 = (uint *)FUN_080029d8(param_1);
            pcVar4 = s_len____d_err_command___s___0800f458;
          }
          else {
            iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,1,iVar1);
            if (iVar1 != 0) {
              return;
            }
            param_1 = FUN_0800e900((uint)local_38 & 0xff);
            pcVar4 = s_read4829__02x__04x_cmp_0800f43c;
            puVar3 = local_38;
          }
          goto LAB_0800f2b2;
        }
        iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,1,iVar1);
        if (iVar1 != 0) {
          return;
        }
        *_DAT_0800f41c = (char)local_38;
        pcVar4 = s_setkey__d_cmp_0800f41f + 1;
      }
      else {
        iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,1,iVar1);
        if (iVar1 != 0) {
          return;
        }
        FUN_08010a00((uint)local_38 & 0xff);
        pcVar4 = s_setuartmode__d_0800f400;
      }
      goto LAB_0800f0ce;
    }
    iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,2,iVar1);
    if (iVar1 != 0) {
      return;
    }
    *local_38 = local_34[0];
    param_1 = *local_38;
  }
  else {
    iVar1 = FUN_080113e8(&local_38,local_34,local_34 + 1,local_34 + 2,2,iVar1);
    if (iVar1 != 0) {
      return;
    }
    *(byte *)local_38 = (byte)local_34[0];
    param_1 = (uint)(byte)*local_38;
  }
  pcVar4 = s_memwrite1_0x_x_0x_x_0800f3d0;
  puVar3 = local_38;
LAB_0800f2b2:
  FUN_08011368(1,pcVar4,puVar3,param_1);
  return;
}



// ==== 0800f47c  thunk_FUN_0800f48a  (2 bytes, 10 xrefs)

void thunk_FUN_0800f48a(int param_1)

{
  for (; param_1 != 0; param_1 = param_1 + -1) {
  }
  return;
}



// ==== 0800f48a  FUN_0800f48a  (18 bytes, 1 xrefs)

void FUN_0800f48a(int param_1)

{
  for (; param_1 != 0; param_1 = param_1 + -1) {
  }
  return;
}



// ==== 0800f490  FUN_0800f490  (254 bytes, 1 xrefs)

void FUN_0800f490(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_10;
  uint local_8;
  
  FUN_0800299a(&local_20,0x18);
  puVar1 = PTR_RCC_0800f590;
  local_28 = 0;
  local_24 = 0;
  *(uint *)(PTR_RCC_0800f590 + 0x34) = *(uint *)(PTR_RCC_0800f590 + 0x34) | 0x20;
  local_8 = *(uint *)(puVar1 + 0x34) & 0x20;
  *(uint *)(puVar1 + 0x34) = *(uint *)(puVar1 + 0x34) & 0xfffffff8;
  *(uint *)(puVar1 + 0x38) = *(uint *)(puVar1 + 0x38) & 0xfffffffe;
  *(uint *)(puVar1 + 0x3c) = *(uint *)(puVar1 + 0x3c) & ~DAT_0800f594;
  *(uint *)(PTR_RCC_0800f590 + 0x40) = *(uint *)(PTR_RCC_0800f590 + 0x40) & 0xffffadff;
  *(uint *)(puVar1 + 0x24) = *(uint *)(puVar1 + 0x24) | 7;
  *(uint *)(puVar1 + 0x28) = *(uint *)(puVar1 + 0x28) | 1;
  *(uint *)(puVar1 + 0x2c) = *(uint *)(puVar1 + 0x2c) | DAT_0800f594;
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) | 0x5200;
  *(uint *)(DAT_0800f598 + 0x10) = *(uint *)(DAT_0800f598 + 0x10) & 0xfffffffe;
  puVar2 = PTR_GPIOF_0800f59c;
  local_20 = 800;
  local_1c = 0;
  local_10 = 0;
  FUN_08010f30(PTR_GPIOF_0800f59c,&local_20);
  local_1c = 0;
  local_10 = 0;
  local_20 = 0x40;
  FUN_08010f30(puVar2,&local_20);
  local_28 = 0x40;
  local_24 = CONCAT13(local_24._3_1_,0x10101);
  FUN_08010e88(&local_28);
  *(uint *)(PTR_DAT_0800f5a0 + 0x60) = *(uint *)(PTR_DAT_0800f5a0 + 0x60) & 0xfffcffff | 0x30000;
  *(uint *)(puVar1 + 0x3c) = *(uint *)(puVar1 + 0x3c) | (int)PTR_DAT_0800f5a0 << 0x1a;
  *(uint *)PTR_PWR_0800f5a4 = *(uint *)PTR_PWR_0800f5a4 & 0xfffff9ff | 0x600;
  *(uint *)PTR_PWR_0800f5a4 = *(uint *)PTR_PWR_0800f5a4 | (int)PTR_PWR_0800f5a4 >> 0x10;
  *(uint *)(DAT_0800f5a8 + 0x10) = *(uint *)(DAT_0800f5a8 + 0x10) | 4;
  WaitForEvent();
  WaitForEvent();
  *(uint *)(DAT_0800f5a8 + 0x10) = *(uint *)(DAT_0800f5a8 + 0x10) & 0xfffffffb;
  DataSynchronizationBarrier(0xf);
  *(undefined4 *)(DAT_0800f5a8 + 0xc) = DAT_0800f5ac;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==== 0800f5b0  FUN_0800f5b0  (20 bytes, 2 xrefs)

void FUN_0800f5b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0800f5c4;
  *param_1 = *DAT_0800f5c4;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  param_1[3] = puVar1[3];
  return;
}



// ==== 0800f5c8  FUN_0800f5c8  (32 bytes, 1 xrefs)

void FUN_0800f5c8(void)

{
  FUN_0800f854();
  FUN_0800dd38();
  FUN_0800f734();
  FUN_0800fdd0();
  FUN_0800fac0();
  FUN_0800ff74();
  FUN_08010a0c();
  return;
}



// ==== 0800f5e8  FUN_0800f5e8  (54 bytes, 4 xrefs)

void FUN_0800f5e8(byte *param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar2 = 0;
  while (uVar3 = param_2 - 1, param_2 != 0) {
    uVar2 = uVar2 ^ (uint)*param_1 << 8;
    uVar4 = 0;
    param_1 = param_1 + 1;
    do {
      if ((int)(uVar2 << 0x10) < 0) {
        uVar1 = (ushort)(uVar2 << 1) ^ (ushort)DAT_0800f620;
      }
      else {
        uVar1 = (ushort)(uVar2 << 1);
      }
      uVar4 = uVar4 + 1;
      uVar2 = (uint)uVar1;
      param_2 = uVar3 & 0xffff;
    } while (uVar4 < 8);
  }
  return;
}



// ==== 0800f624  FUN_0800f624  (234 bytes, 1 xrefs)

void FUN_0800f624(void)

{
  undefined *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined *puVar6;
  
  *(uint *)(PTR_RCC_0800f710 + 0x38) = *(uint *)(PTR_RCC_0800f710 + 0x38) | 1;
  puVar3 = (uint *)(PTR_RCC_0800f710 + 0x40);
  *puVar3 = *puVar3 | 1;
  uVar4 = *puVar3;
  *(uint *)(PTR_SYSCFG_0800f714 + 8) = *(uint *)(PTR_SYSCFG_0800f714 + 8) & 0xffc0ffff | 0x10000;
  iVar2 = DAT_0800f71c;
  puVar1 = PTR_DMA1_0800f718;
  *(uint *)(PTR_DMA1_0800f718 + *(byte *)(DAT_0800f71c + 2)) =
       *(uint *)(PTR_DMA1_0800f718 + *(byte *)(DAT_0800f71c + 2)) & DAT_0800f720 | 0x10;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) =
       *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) & 0xffffcfff | 0x2000;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) =
       *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) & 0xffffffdf | 0x20;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) = *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) & 0xffffffbf;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) =
       *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) & 0xffffff7f | 0x80;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) =
       *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) & 0xfffffcff | 0x100;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) =
       *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) & 0xfffff3ff | 0x400;
  puVar6 = puVar1 + 4;
  *(uint *)(puVar6 + *(byte *)(iVar2 + 2)) =
       *(uint *)(puVar6 + *(byte *)(iVar2 + 2)) & 0xffff0000 | 0x140;
  uVar5 = FUN_08010e2c(puVar1,3,0x140,puVar6,uVar4 & 1);
  FUN_08010d54(puVar1,3,DAT_0800f728,PTR_DAT_0800f724,uVar5);
  *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) = *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) | 2;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) = *(uint *)(puVar1 + *(byte *)(iVar2 + 2)) | 4;
  FUN_08010de8(puVar1,3);
  *DAT_0800f72c = *DAT_0800f72c & 0xff00ffff;
  *DAT_0800f730 = 0x400;
  return;
}



// ==== 0800f734  FUN_0800f734  (100 bytes, 1 xrefs)

void FUN_0800f734(void)

{
  int iVar1;
  undefined *puVar2;
  
  FUN_0800f624();
  *(uint *)(PTR_RCC_0800f798 + 0x34) = *(uint *)(PTR_RCC_0800f798 + 0x34) | 1;
  GPIOA = GPIOA & 0xfffffcff | 0x300;
  FUN_08010d14(0x20000000);
  puVar2 = PTR_DAC1_0800f7a0;
  iVar1 = DAT_0800f79c;
  *(uint *)PTR_DAC1_0800f7a0 = *(uint *)PTR_DAC1_0800f7a0 & 0xffffffc7;
  *(uint *)puVar2 = *(uint *)puVar2 & 0xfffffffd;
  *(uint *)puVar2 = *(uint *)puVar2 | iVar1 << 0xc;
  FUN_08010d44(puVar2);
  FUN_080123bc(0xf);
  FUN_0800f82c();
  *(uint *)puVar2 = *(uint *)puVar2 | 4;
  return;
}



// ==== 0800f7a4  FUN_0800f7a4  (72 bytes, 1 xrefs)

void FUN_0800f7a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  FUN_08010d44(PTR_DAC1_0800f7f0,DAT_0800f7ec,param_3,param_4,param_4);
  puVar1 = PTR_TIM6_0800f7f4;
  *(uint *)PTR_TIM6_0800f7f4 = *(uint *)PTR_TIM6_0800f7f4 & 0xfffffffe;
  puVar2 = PTR_DMA1_0800f7f8;
  FUN_08010db8(PTR_DMA1_0800f7f8,3);
  uVar3 = FUN_08010e2c(puVar2,3);
  FUN_08010d54(puVar2,3,DAT_0800f7fc,PTR_DAC1_0800f7f0 + 8,uVar3);
  FUN_08010de8(puVar2,3);
  *(uint *)puVar1 = *(uint *)puVar1 | 1;
  return;
}



// ==== 0800f800  FUN_0800f800  (32 bytes, 7 xrefs)

void FUN_0800f800(void)

{
  *(uint *)PTR_TIM6_0800f820 = *(uint *)PTR_TIM6_0800f820 & 0xfffffffe;
  FUN_08010db8(PTR_DMA1_0800f824,3);
  *(uint *)PTR_DAC1_0800f828 = *(uint *)PTR_DAC1_0800f828 & 0xfffffffe;
  return;
}



// ==== 0800f82c  FUN_0800f82c  (32 bytes, 1 xrefs)

void FUN_0800f82c(void)

{
  undefined *puVar1;
  
  FUN_08010d14(0x10);
  puVar1 = PTR_TIM6_0800f84c;
  *(undefined4 *)(PTR_TIM6_0800f84c + 0x28) = 3;
  *(undefined4 *)(puVar1 + 0x2c) = DAT_0800f850;
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) & 0xffffff8f | 0x20;
  return;
}



// ==== 0800f854  FUN_0800f854  (160 bytes, 1 xrefs)

void FUN_0800f854(void)

{
  undefined *puVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  FUN_0800299a(&local_30,0x18);
  FUN_08011028(1);
  FUN_08011028(2);
  FUN_08011028(4);
  FUN_08011028(0x20);
  puVar1 = PTR_GPIOB_0800f8f4;
  *(undefined4 *)(PTR_GPIOB_0800f8f4 + 0x18) = 4;
  DAT_50000018 = 0x40;
  *(undefined4 *)(puVar1 + 0x28) = 0x10;
  local_30 = 0x148;
  local_28 = 3;
  local_2c = 1;
  local_24 = 0;
  local_20 = 1;
  FUN_08010f30(&GPIOA,&local_30);
  local_30 = 0x6000;
  FUN_08010f30(&GPIOA,&local_30);
  local_30 = 0x37c;
  FUN_08010f30(puVar1,&local_30);
  local_30 = 0xf400;
  local_2c = 0;
  FUN_08010f30(puVar1,&local_30);
  local_30 = 0x2000;
  local_2c = 1;
  FUN_08010f30(PTR_GPIOC_0800f8f8,&local_30);
  local_30 = 0x360;
  local_2c = 1;
  FUN_08010f30(PTR_GPIOF_0800f8fc,&local_30);
  return;
}



// ==== 0800f900  FUN_0800f900  (436 bytes, 3 xrefs)

char FUN_0800f900(void)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = PTR_GPIOB_0800fabc;
  cVar2 = *DAT_0800fab8;
  if (cVar2 == -1) {
    *(undefined4 *)(PTR_GPIOB_0800fabc + 0x18) = 0x40;
    *(undefined4 *)(puVar1 + 0x18) = 0x20;
    *(undefined4 *)(puVar1 + 0x18) = 0x10;
    *(undefined4 *)(puVar1 + 0x18) = 8;
    FUN_080123bc(1);
    iVar5 = (int)puVar1 << 5;
    iVar3 = FUN_08010fd4(puVar1,iVar5);
    if (iVar3 == 0) {
      cVar2 = '\x17';
    }
    else {
      iVar3 = FUN_08010fd4(puVar1,(int)puVar1 << 4);
      if (iVar3 == 0) {
        cVar2 = '\x16';
      }
      else {
        *(undefined4 *)(puVar1 + 0x28) = 0x40;
        FUN_080123bc(1);
        iVar3 = FUN_08010fd4(puVar1,iVar5);
        if (iVar3 == 0) {
          cVar2 = '\n';
        }
        else {
          iVar3 = FUN_08010fd4(puVar1,(int)puVar1 << 4);
          if (iVar3 == 0) {
            cVar2 = '\x01';
          }
          else {
            iVar4 = iVar5 >> 2;
            iVar3 = FUN_08010fd4(puVar1,iVar4);
            if (iVar3 == 0) {
              cVar2 = '\x04';
            }
            else {
              iVar5 = iVar5 >> 3;
              iVar3 = FUN_08010fd4(puVar1,iVar5);
              if (iVar3 == 0) {
                cVar2 = '\a';
              }
              else {
                *(undefined4 *)(puVar1 + 0x28) = 0x20;
                FUN_080123bc(1);
                *(undefined4 *)(puVar1 + 0x18) = 0x40;
                FUN_080123bc(1);
                iVar3 = FUN_08010fd4(puVar1,(int)puVar1 << 5);
                if (iVar3 == 0) {
                  cVar2 = '\v';
                }
                else {
                  iVar3 = FUN_08010fd4(puVar1,(int)puVar1 << 4);
                  if (iVar3 == 0) {
                    cVar2 = '\x02';
                  }
                  else {
                    iVar3 = FUN_08010fd4(puVar1,iVar4);
                    if (iVar3 == 0) {
                      cVar2 = '\x05';
                    }
                    else {
                      iVar3 = FUN_08010fd4(puVar1,iVar5);
                      if (iVar3 == 0) {
                        cVar2 = '\b';
                      }
                      else {
                        *(undefined4 *)(puVar1 + 0x28) = 0x10;
                        FUN_080123bc(1);
                        *(undefined4 *)(puVar1 + 0x18) = 0x20;
                        FUN_080123bc(1);
                        iVar3 = FUN_08010fd4(puVar1,(int)puVar1 << 5);
                        if (iVar3 == 0) {
                          cVar2 = '\f';
                        }
                        else {
                          iVar3 = FUN_08010fd4(puVar1,(int)puVar1 << 4);
                          if (iVar3 == 0) {
                            cVar2 = '\x03';
                          }
                          else {
                            iVar3 = FUN_08010fd4(puVar1,iVar4);
                            if (iVar3 == 0) {
                              cVar2 = '\x06';
                            }
                            else {
                              iVar3 = FUN_08010fd4(puVar1,iVar5);
                              if (iVar3 == 0) {
                                cVar2 = '\t';
                              }
                              else {
                                *(undefined4 *)(puVar1 + 0x28) = 8;
                                FUN_080123bc(1);
                                *(undefined4 *)(puVar1 + 0x18) = 0x10;
                                FUN_080123bc(1);
                                iVar3 = FUN_08010fd4(puVar1,(int)puVar1 << 5);
                                if (iVar3 == 0) {
                                  cVar2 = '\r';
                                }
                                else {
                                  iVar3 = FUN_08010fd4(puVar1,(int)puVar1 << 4);
                                  if (iVar3 == 0) {
                                    cVar2 = '\x0e';
                                  }
                                  else {
                                    iVar3 = FUN_08010fd4(puVar1,iVar4);
                                    if (iVar3 == 0) {
                                      cVar2 = '\0';
                                    }
                                    else {
                                      iVar3 = FUN_08010fd4(puVar1,iVar5);
                                      cVar2 = -1;
                                      if (iVar3 == 0) {
                                        cVar2 = '\x0f';
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    *(undefined4 *)(puVar1 + 0x18) = 0x40;
    *(undefined4 *)(puVar1 + 0x18) = 0x20;
    *(undefined4 *)(puVar1 + 0x28) = 0x10;
    *(undefined4 *)(puVar1 + 0x18) = 8;
  }
  return cVar2;
}



// ==== 0800fac0  FUN_0800fac0  (2 bytes, 1 xrefs)

void FUN_0800fac0(void)

{
  return;
}



// ==== 0800fac2  FUN_0800fac2  (72 bytes, 1 xrefs)

uint FUN_0800fac2(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  uint uVar2;
  
  if (param_2 == 1) {
    uVar1 = FUN_0800fb0c(1);
    *param_1 = uVar1;
    return 1;
  }
  uVar2 = 0;
  for (; 1 < param_2; param_2 = param_2 - 1 & 0xff) {
    FUN_080123bc(1);
    uVar1 = FUN_0800fb0c(0);
    param_1[uVar2] = uVar1;
    uVar2 = uVar2 + 1 & 0xff;
  }
  FUN_080123bc(1);
  uVar1 = FUN_0800fb0c(1);
  param_1[uVar2] = uVar1;
  return uVar2 + 1 & 0xff;
}



// ==== 0800fb0c  FUN_0800fb0c  (138 bytes, 3 xrefs)

uint FUN_0800fb0c(int param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  
  puVar1 = PTR_GPIOF_0800fb98;
  FUN_08010ffe(PTR_GPIOF_0800fb98,0x40,0);
  uVar3 = 0;
  uVar4 = 0;
  do {
    *(undefined4 *)(puVar1 + 0x28) = 0x20;
    FUN_080123bc(1);
    *(undefined4 *)(puVar1 + 0x18) = 0x20;
    FUN_080123bc(1);
    uVar3 = (uVar3 & 0x7f) << 1;
    FUN_080123bc(1);
    iVar2 = FUN_08010fe2(puVar1,0x40);
    if (iVar2 != 0) {
      uVar3 = uVar3 | 1;
    }
    *(undefined4 *)(puVar1 + 0x28) = 0x20;
    FUN_080123bc(1);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 8);
  FUN_08010ffe(puVar1,0x40,1);
  if (param_1 == 0) {
    *(undefined4 *)(puVar1 + 0x28) = 0x40;
  }
  else {
    *(undefined4 *)(puVar1 + 0x18) = 0x40;
  }
  FUN_080123bc(1);
  *(undefined4 *)(puVar1 + 0x18) = 0x20;
  FUN_080123bc(1);
  *(undefined4 *)(puVar1 + 0x28) = 0x20;
  FUN_080123bc(1);
  return uVar3;
}



// ==== 0800fb9c  FUN_0800fb9c  (156 bytes, 5 xrefs)

undefined4 FUN_0800fb9c(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar4;
  
  puVar1 = PTR_GPIOF_0800fc38;
  *(undefined4 *)(PTR_GPIOF_0800fc38 + 0x28) = 0x20;
  FUN_080123bc(1);
  uVar3 = 0;
  do {
    if ((int)(param_1 << 0x18) < 0) {
      *(undefined4 *)(puVar1 + 0x18) = 0x40;
    }
    else {
      *(undefined4 *)(puVar1 + 0x28) = 0x40;
    }
    param_1 = (param_1 & 0x7f) << 1;
    FUN_080123bc(1);
    *(undefined4 *)(puVar1 + 0x18) = 0x20;
    FUN_080123bc(1);
    *(undefined4 *)(puVar1 + 0x28) = 0x20;
    FUN_080123bc(1);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  FUN_08010ffe(puVar1,0x40,0);
  *(undefined4 *)(puVar1 + 0x18) = 0x40;
  FUN_080123bc(1);
  *(undefined4 *)(puVar1 + 0x18) = 0x20;
  FUN_080123bc(1);
  uVar3 = 0;
  do {
    iVar2 = FUN_08010fe2(puVar1,0x40);
    if (iVar2 == 0) {
      uVar4 = 0;
      break;
    }
    uVar3 = uVar3 + 1;
    uVar4 = 0xff;
  } while (uVar3 < 0xff);
  *(undefined4 *)(puVar1 + 0x28) = 0x20;
  FUN_080123bc(1);
  FUN_08010ffe(puVar1,0x40,1);
  *(undefined4 *)(puVar1 + 0x18) = 0x40;
  return uVar4;
}



// ==== 0800fc3c  FUN_0800fc3c  (46 bytes, 2 xrefs)

void FUN_0800fc3c(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_GPIOF_0800fc6c;
  *(undefined4 *)(PTR_GPIOF_0800fc6c + 0x18) = 0x40;
  FUN_080123bc(1);
  *(undefined4 *)(puVar1 + 0x18) = 0x20;
  FUN_080123bc(1);
  *(undefined4 *)(puVar1 + 0x28) = 0x40;
  FUN_080123bc(1);
  *(undefined4 *)(puVar1 + 0x28) = 0x20;
  FUN_080123bc(1);
  return;
}



// ==== 0800fc70  FUN_0800fc70  (46 bytes, 2 xrefs)

void FUN_0800fc70(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_GPIOF_0800fca0;
  *(undefined4 *)(PTR_GPIOF_0800fca0 + 0x28) = 0x40;
  FUN_080123bc(1);
  *(undefined4 *)(puVar1 + 0x28) = 0x20;
  FUN_080123bc(1);
  *(undefined4 *)(puVar1 + 0x18) = 0x20;
  FUN_080123bc(1);
  *(undefined4 *)(puVar1 + 0x18) = 0x40;
  FUN_080123bc(1);
  return;
}



// ==== 0800fca4  FUN_0800fca4  (36 bytes, 1 xrefs)

undefined4 FUN_0800fca4(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  while( true ) {
    if (param_2 == 0) {
      return 0;
    }
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    iVar2 = FUN_0800fb9c(uVar1);
    if (iVar2 != 0) break;
    param_2 = param_2 - 1 & 0xff;
  }
  return 0xff;
}



// ==== 0800fcc8  FUN_0800fcc8  (74 bytes, 2 xrefs)

void FUN_0800fcc8(char param_1,undefined4 param_2,uint param_3,int param_4,int param_5)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = PTR_GPIOB_0800fd14;
  *(undefined4 *)(PTR_GPIOB_0800fd14 + 0x28) = 4;
  FUN_0800fe6c(param_1 + '\x04');
  DAT_50000018 = 0x40;
  uVar2 = 0;
  if (param_5 == 0) {
    for (; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xffff) {
      FUN_08010300(*(undefined1 *)(param_4 + uVar2));
    }
  }
  else {
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xffff) {
      FUN_08010300(0);
    }
  }
  *(undefined4 *)(puVar1 + 0x18) = 4;
  return;
}



// ==== 0800fd18  FUN_0800fd18  (68 bytes, 9 xrefs)

void FUN_0800fd18(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  puVar1 = PTR_GPIOB_0800fd5c;
  *(undefined4 *)(PTR_GPIOB_0800fd5c + 0x28) = 4;
  FUN_0800fe92(0x40);
  uVar3 = 0;
  do {
    FUN_0800fe6c(4,uVar3 + 1 & 0xff);
    DAT_50000018 = 0x40;
    uVar2 = 0;
    iVar4 = uVar3 * 0x80 + DAT_0800fd60;
    do {
      FUN_08010300(*(undefined1 *)(iVar4 + uVar2));
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < 0x80);
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 7);
  *(undefined4 *)(puVar1 + 0x18) = 4;
  return;
}



// ==== 0800fd64  FUN_0800fd64  (54 bytes, 4 xrefs)

void FUN_0800fd64(void)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = PTR_GPIOB_0800fd9c;
  *(undefined4 *)(PTR_GPIOB_0800fd9c + 0x28) = 4;
  FUN_0800fe92(0x40);
  FUN_0800fe6c(4,0);
  iVar2 = DAT_0800fda0;
  DAT_50000018 = 0x40;
  uVar3 = 0;
  do {
    FUN_08010300(*(undefined1 *)(iVar2 + uVar3));
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 0x80);
  *(undefined4 *)(puVar1 + 0x18) = 4;
  return;
}



// ==== 0800fda4  FUN_0800fda4  (38 bytes, 3 xrefs)

void FUN_0800fda4(undefined4 param_1)

{
  FUN_0800298c(DAT_0800fdcc,0x80,param_1);
  FUN_0800298c(DAT_0800fdcc + 0x80,0x380,param_1);
  FUN_0800fd64();
  FUN_0800fd18();
  return;
}



// ==== 0800fdd0  FUN_0800fdd0  (150 bytes, 1 xrefs)

void FUN_0800fdd0(void)

{
  undefined *puVar1;
  
  FUN_08010264();
  puVar1 = PTR_GPIOB_0800fe68;
  *(undefined4 *)(PTR_GPIOB_0800fe68 + 0x28) = 4;
  FUN_0800fe92(0xe2);
  FUN_080123ae(0x78);
  FUN_0800fe92(0xa2);
  FUN_0800fe92(0xc0);
  FUN_0800fe92(0xa1);
  FUN_0800fe92(0xa6);
  FUN_0800fe92(0xa4);
  FUN_0800fe92(0x24);
  FUN_0800fe92(0x81);
  FUN_0800fe92(0x1f);
  FUN_0800fe92(0x2b);
  FUN_080123ae(1);
  FUN_0800fe92(0x2e);
  FUN_080123ae(1);
  FUN_0800fe92(0x2f);
  FUN_0800fe92(0x2f);
  FUN_0800fe92(0x2f);
  FUN_0800fe92(0x2f);
  FUN_080123ae(0x28);
  FUN_0800fe92(0x40);
  FUN_0800fe92(0xaf);
  *(undefined4 *)(puVar1 + 0x18) = 4;
  FUN_0800fda4(0);
  return;
}



// ==== 0800fe6c  FUN_0800fe6c  (38 bytes, 3 xrefs)

void FUN_0800fe6c(uint param_1,char param_2)

{
  DAT_50000028 = 0x40;
  FUN_08010300(param_2 + -0x50);
  FUN_08010300((param_1 >> 4) + 0x10);
  FUN_08010300(param_1 & 0xf);
  return;
}



// ==== 0800fe92  FUN_0800fe92  (16 bytes, 19 xrefs)

void FUN_0800fe92(void)

{
  DAT_50000028 = 0x40;
  FUN_08010300();
  return;
}



// ==== 0800fea4  FUN_0800fea4  (68 bytes, 1 xrefs)

void FUN_0800fea4(uint param_1)

{
  FUN_08011368(0x1e,s_Erase_Sector__08x_0800fee8,param_1);
  FUN_0801018c();
  FUN_08010030();
  DAT_50000028 = 8;
  FUN_08010584(0x20);
  FUN_08010584((param_1 & 0xffffff) >> 0x10);
  FUN_08010584((param_1 & 0xffff) >> 8);
  FUN_08010584(param_1 & 0xff);
  DAT_50000018 = 8;
  FUN_08010030();
  return;
}



// ==== 0800fefc  FUN_0800fefc  (92 bytes, 3 xrefs)

void FUN_0800fefc(uint param_1)

{
  FUN_08011368(0x1e,s_Erase_Sector__08x_0800ff58,param_1);
  FUN_0801018c();
  FUN_08010030();
  DAT_50000028 = 8;
  FUN_08010584(0x20);
  FUN_08010584((param_1 & 0xffffff) >> 0x10);
  FUN_08010584((param_1 & 0xffff) >> 8);
  FUN_08010584(param_1 & 0xff);
  DAT_50000018 = 8;
  FUN_08010030();
  if ((param_1 & 0xfffff000) == *DAT_0800ff6c) {
    FUN_0800298c(DAT_0800ff70,0x1000,0xff);
  }
  return;
}



// ==== 0800ff74  FUN_0800ff74  (16 bytes, 1 xrefs)

void FUN_0800ff74(void)

{
  DAT_50000018 = 8;
  FUN_0801031c();
  return;
}



// ==== 0800ff84  FUN_0800ff84  (96 bytes, 45 xrefs)

void FUN_0800ff84(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  
  FUN_08011368(0x1e,s_Read_Norflash_0x_08x__d_0800ffe4,param_2,param_3,param_4);
  DAT_50000028 = 8;
  FUN_08010584(3);
  FUN_08010584((param_2 & 0xffffff) >> 0x10);
  FUN_08010584((param_2 & 0xffff) >> 8);
  FUN_08010584(param_2 & 0xff);
  if (param_3 < 0x10) {
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xffff) {
      uVar1 = FUN_08010584(0xff);
      *(undefined1 *)(param_1 + uVar2) = uVar1;
    }
  }
  else {
    FUN_080103fc(param_1,param_3);
  }
  DAT_50000018 = 8;
  return;
}



// ==== 08010000  FUN_08010000  (48 bytes, 1 xrefs)

void FUN_08010000(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 1) {
    if (param_1 == 2) {
      uVar1 = 0x35;
      goto LAB_08010018;
    }
    if (param_1 == 3) {
      uVar1 = 0x15;
      goto LAB_08010018;
    }
  }
  uVar1 = 5;
LAB_08010018:
  DAT_50000028 = 8;
  FUN_08010584(uVar1);
  FUN_08010584(0xff);
  DAT_50000018 = 8;
  return;
}



// ==== 08010030  FUN_08010030  (28 bytes, 5 xrefs)

void FUN_08010030(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = DAT_0801004c;
  while ((uVar1 = FUN_08010000(1), (uVar1 & 1) != 0 && (iVar2 = iVar2 + -1, iVar2 != 0))) {
    FUN_080123bc(10);
  }
  return;
}



// ==== 08010050  FUN_08010050  (266 bytes, 14 xrefs)

void FUN_08010050(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint local_28;
  int local_24;
  uint local_20;
  
  FUN_08011368(0x1e,s_Write_Norflash_0x_08x__d_append___0801015c,param_2,param_3,param_4);
  iVar1 = DAT_08010184;
  local_28 = param_2 >> 0xc;
  uVar5 = param_2 & 0xfff;
  uVar4 = 0x1000 - uVar5;
  local_24 = param_1;
  local_20 = param_2;
  if (uVar4 < param_3) goto LAB_08010080;
  do {
    uVar4 = param_3;
    param_3 = uVar4;
LAB_08010080:
    do {
      iVar2 = local_28 << 0xc;
      iVar6 = iVar2;
      if (*DAT_08010188 != iVar2) {
        FUN_0800ff84(iVar1,iVar2,0x1000);
        *DAT_08010188 = iVar2;
      }
      iVar2 = FUN_08002a02(iVar1 + uVar5,local_24,uVar4);
      if (iVar2 != 0) {
        for (uVar3 = 0; (uVar3 < uVar4 && (*(char *)(iVar1 + uVar5 + uVar3) == -1));
            uVar3 = uVar3 + 1 & 0xffff) {
        }
        if (uVar3 < uVar4) {
          FUN_0800fea4(iVar6);
          for (uVar3 = 0; uVar3 < uVar4; uVar3 = uVar3 + 1 & 0xffff) {
            *(undefined1 *)(iVar1 + uVar3 + uVar5) = *(undefined1 *)(local_24 + uVar3);
          }
          if (param_4 == 1) {
            FUN_080101a2(iVar1,iVar6,uVar5 + uVar4 & 0xffff);
            FUN_0800298c(uVar5 + uVar4 + iVar1,(0x1000 - uVar5) - uVar4,0xff);
          }
          else {
            FUN_080101a2(iVar1,iVar6,0x1000);
          }
        }
        else {
          FUN_080101a2(local_24,local_20,uVar4);
          FUN_08002968(iVar1 + uVar5,local_24,uVar4);
        }
      }
      if (param_3 == uVar4) {
        return;
      }
      uVar5 = 0;
      local_28 = local_28 + 1;
      local_24 = local_24 + uVar4;
      local_20 = local_20 + uVar4;
      param_3 = param_3 - uVar4 & 0xffff;
      uVar4 = 0x1000;
    } while (0x1000 < param_3);
  } while( true );
}



// ==== 0801018c  FUN_0801018c  (22 bytes, 3 xrefs)

void FUN_0801018c(void)

{
  DAT_50000028 = 8;
  FUN_08010584(6);
  DAT_50000018 = 8;
  return;
}



// ==== 080101a2  FUN_080101a2  (58 bytes, 3 xrefs)

void FUN_080101a2(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0x100 - (param_2 & 0xff);
  if (param_3 <= uVar1) {
    uVar1 = param_3;
  }
  while (FUN_080101dc(param_1,param_2,uVar1), param_3 != uVar1) {
    param_1 = param_1 + uVar1;
    param_2 = param_2 + uVar1;
    param_3 = param_3 - uVar1 & 0xffff;
    uVar1 = 0x100;
    if (param_3 < 0x101) {
      uVar1 = param_3;
    }
  }
  return;
}



// ==== 080101dc  FUN_080101dc  (102 bytes, 1 xrefs)

void FUN_080101dc(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  FUN_08011368(0x1e,s_Write_Norflash_Page_0x_08x__d_08010244,param_2,param_3,param_4);
  FUN_0801018c();
  DAT_50000028 = 8;
  FUN_08010584(2);
  FUN_08010584((param_2 & 0xffffff) >> 0x10);
  FUN_08010584((param_2 & 0xffff) >> 8);
  FUN_08010584(param_2 & 0xff);
  if (param_3 < 0x10) {
    for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
      FUN_08010584(*(undefined1 *)(param_1 + uVar1));
    }
  }
  else {
    FUN_080104c0(param_1,param_3);
  }
  DAT_50000018 = 8;
  FUN_08010030();
  return;
}



// ==== 08010264  FUN_08010264  (148 bytes, 1 xrefs)

void FUN_08010264(void)

{
  undefined *puVar1;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  
  FUN_0800299a(&local_58,0x28);
  FUN_0800299a(&local_30,0x18);
  *(uint *)PTR_DAT_080102f8 = *(uint *)PTR_DAT_080102f8 | 0x1000;
  puVar1 = PTR_DAT_080102f8;
  *(uint *)(PTR_DAT_080102f8 + -0xc) = *(uint *)(PTR_DAT_080102f8 + -0xc) | 1;
  local_18 = *(uint *)(puVar1 + -0xc) & 1;
  local_1c = 0;
  local_20 = 1;
  local_30 = 0x20;
  local_2c = 2;
  local_24 = 0;
  local_28 = 2;
  FUN_08010f30(&GPIOA,&local_30);
  local_30 = 0x80;
  local_20 = 0;
  FUN_08010f30(&GPIOA,&local_30);
  puVar1 = PTR_SPI1_080102fc;
  local_58 = 0;
  local_54 = 0x104;
  uStack_50 = 0;
  uStack_4c = 2;
  uStack_48 = 1;
  local_44 = 0x200;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_40 = 0x38;
  FUN_08011070(PTR_SPI1_080102fc,&local_58);
  *(uint *)puVar1 = *(uint *)puVar1 | 0x40;
  return;
}



// ==== 08010300  FUN_08010300  (24 bytes, 8 xrefs)

undefined4 FUN_08010300(undefined1 param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_SPI1_08010318;
  do {
  } while (-1 < *(int *)(PTR_SPI1_08010318 + 8) << 0x1e);
  PTR_SPI1_08010318[0xc] = param_1;
  do {
  } while (-1 < *(int *)(puVar1 + 8) << 0x1f);
  return *(undefined4 *)(puVar1 + 0xc);
}



// ==== 0801031c  FUN_0801031c  (204 bytes, 1 xrefs)

void FUN_0801031c(void)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  
  FUN_0800299a(&local_58,0x28);
  FUN_0800299a(&local_30,0x18);
  puVar1 = PTR_RCC_080103e8;
  *(uint *)(PTR_RCC_080103e8 + 0x3c) = *(uint *)(PTR_RCC_080103e8 + 0x3c) | 0x4000;
  *(uint *)(puVar1 + 0x38) = *(uint *)(puVar1 + 0x38) | 1;
  *(uint *)(puVar1 + 0x34) = *(uint *)(puVar1 + 0x34) | 1;
  local_18 = *(uint *)(puVar1 + 0x34) & 1;
  local_2c = 2;
  local_30 = 1;
  local_20 = 1;
  local_1c = 8;
  local_28 = 2;
  local_24 = 0;
  FUN_08010f30(&GPIOA,&local_30);
  local_30 = 6;
  local_1c = 9;
  FUN_08010f30(&GPIOA,&local_30);
  puVar1 = PTR_DMA1_080103ec;
  FUN_080110dc(PTR_DMA1_080103ec,4,5);
  FUN_080110dc(puVar1,5,6);
  uVar2 = (int)DAT_080103f0 << 0x1b;
  *DAT_080103f0 = *DAT_080103f0 & 0xffffff | uVar2;
  *DAT_080103f4 = (int)uVar2 >> 0x13;
  puVar1 = PTR_SPI2_080103f8;
  local_48 = 1;
  local_58 = 0;
  local_54 = 0x104;
  uStack_50 = 0;
  uStack_4c = 2;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_44 = (int)uVar2 >> 0x15;
  FUN_08011070(PTR_SPI2_080103f8,&local_58);
  *(uint *)puVar1 = *(uint *)puVar1 | 0x40;
  return;
}



// ==== 080103fc  FUN_080103fc  (184 bytes, 2 xrefs)

void FUN_080103fc(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  char *pcVar4;
  
  puVar1 = PTR_SPI2_080104b4;
  *(uint *)PTR_SPI2_080104b4 = *(uint *)PTR_SPI2_080104b4 & 0xffffffbf;
  puVar2 = PTR_DMA1_080104b8;
  FUN_08010da0(PTR_DMA1_080104b8,4);
  FUN_08010da0(puVar2,5);
  *(int *)(puVar2 + 4) = (int)puVar1 >> 0x12;
  FUN_08010d80(puVar2,4,0x80);
  FUN_08010d80(puVar2,5,0x10);
  FUN_08010e60(puVar2,4,param_1);
  puVar3 = PTR_SPI2_080104b4 + 0xc;
  FUN_08010e74(puVar2,4,puVar3);
  FUN_08010e44(puVar2,4,param_2);
  FUN_08010e60(puVar2,5,DAT_080104bc);
  FUN_08010e74(puVar2,5,puVar3);
  FUN_08010e44(puVar2,5,param_2);
  pcVar4 = (char *)(DAT_080104bc + -1);
  *pcVar4 = '\0';
  FUN_08010e00(puVar2,4);
  FUN_08010dd0(puVar2,4);
  FUN_08010dd0(puVar2,5);
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | 1;
  *(uint *)puVar1 = *(uint *)puVar1 | 0x40;
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | 2;
  do {
  } while (*pcVar4 != '\x01');
  return;
}



// ==== 080104c0  FUN_080104c0  (182 bytes, 2 xrefs)

void FUN_080104c0(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  char *pcVar4;
  
  puVar1 = PTR_SPI2_08010578;
  *(uint *)PTR_SPI2_08010578 = *(uint *)PTR_SPI2_08010578 & 0xffffffbf;
  puVar2 = PTR_DMA1_0801057c;
  FUN_08010da0(PTR_DMA1_0801057c,4);
  FUN_08010da0(puVar2,5);
  *(int *)(puVar2 + 4) = (int)puVar1 >> 0x12;
  FUN_08010d80(puVar2,4,0);
  FUN_08010d80(puVar2,5,0x90);
  FUN_08010e60(puVar2,4,DAT_08010580);
  puVar3 = PTR_SPI2_08010578 + 0xc;
  FUN_08010e74(puVar2,4,puVar3);
  FUN_08010e44(puVar2,4,param_2);
  FUN_08010e60(puVar2,5,param_1);
  FUN_08010e74(puVar2,5,puVar3);
  FUN_08010e44(puVar2,5,param_2);
  pcVar4 = (char *)(DAT_08010580 + -1);
  *pcVar4 = '\0';
  FUN_08010e00(puVar2,4);
  FUN_08010dd0(puVar2,4);
  FUN_08010dd0(puVar2,5);
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | 1;
  *(uint *)puVar1 = *(uint *)puVar1 | 0x40;
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | 2;
  do {
  } while (*pcVar4 != '\x01');
  return;
}



// ==== 08010584  FUN_08010584  (22 bytes, 22 xrefs)

uint FUN_08010584(undefined1 param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_SPI2_0801059c;
  do {
  } while (-1 < *(int *)(PTR_SPI2_0801059c + 8) << 0x1e);
  PTR_SPI2_0801059c[0xc] = param_1;
  do {
  } while ((*(uint *)(puVar1 + 8) & 1) == 0);
  return *(uint *)(puVar1 + 0xc) & 0xff;
}



// ==== 080105a0  FUN_080105a0  (62 bytes, 1 xrefs)

void FUN_080105a0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = *DAT_080105e0;
  iVar3 = FUN_080028f0(uVar2,100);
  iVar1 = DAT_080105e8;
  if (iVar3 - 1U <= DAT_080105e4) {
    *(uint *)(DAT_080105e8 + 0x14) = iVar3 - 1U;
    *(uint *)(DAT_080105ec + 0x1c) = *(uint *)(DAT_080105ec + 0x1c) & 0xffffff | iVar1 << 0x11;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 7;
  }
  uVar2 = FUN_080028f0(uVar2,DAT_080105f0);
  *(undefined4 *)(DAT_080105f4 + 0x24) = uVar2;
  return;
}



// ==== 080105f8  FUN_080105f8  (280 bytes, 1 xrefs)

void FUN_080105f8(void)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  
  FUN_0800299a(&local_34,0x18);
  FUN_0800299a(&local_50,0x1c);
  puVar1 = PTR_RCC_08010710;
  *(uint *)(PTR_RCC_08010710 + 0x34) = *(uint *)(PTR_RCC_08010710 + 0x34) | 1;
  local_1c = *(uint *)(puVar1 + 0x34) & 1;
  FUN_08010d2c(0x4000);
  *(uint *)(puVar1 + 0x38) = *(uint *)(puVar1 + 0x38) | 1;
  local_1c = *(uint *)(puVar1 + 0x38) & 1;
  FUN_08010d2c(1);
  local_34 = 0x600;
  local_30 = 2;
  local_2c = 3;
  local_24 = 1;
  local_28 = 0;
  local_20 = 1;
  FUN_08010f30(&GPIOA,&local_34);
  iVar2 = DAT_08010718;
  puVar1 = PTR_DMA1_08010714;
  *(uint *)(PTR_DMA1_08010714 + *(byte *)(DAT_08010718 + 1)) =
       *(uint *)(PTR_DMA1_08010714 + *(byte *)(DAT_08010718 + 1)) & DAT_0801071c | 0xa0;
  *(uint *)(PTR_SYSCFG_08010720 + 8) = *(uint *)(PTR_SYSCFG_08010720 + 8) & 0xffffc0ff | 0x700;
  puVar3 = PTR_USART1_08010724;
  FUN_08011120(PTR_USART1_08010724);
  local_50 = 0x9600;
  local_4c = 0;
  local_40 = 0xc;
  local_48 = 0;
  local_44 = 0;
  local_3c = 0;
  local_38 = 0;
  FUN_08011188(puVar3,&local_50);
  *(uint *)(puVar3 + 0x10) = *(uint *)(puVar3 + 0x10) & 0xffffb7ff;
  *(uint *)(puVar3 + 0x14) = *(uint *)(puVar3 + 0x14) & 0xffffffd5;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 1)) = *(uint *)(puVar1 + *(byte *)(iVar2 + 1)) & 0xfffffffe;
  *(undefined4 *)(PTR_DMA1_08010714 + *(byte *)(iVar2 + 1) + 0xc) = DAT_08010728;
  *(undefined **)(PTR_DMA1_08010714 + *(byte *)(iVar2 + 1) + 8) = puVar3 + 4;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 1) + 4) =
       *(uint *)(puVar1 + *(byte *)(iVar2 + 1) + 4) & 0xffff0000 | (int)(puVar3 + 4) >> 0x16;
  *(uint *)(puVar1 + *(byte *)(iVar2 + 1)) = *(uint *)(puVar1 + *(byte *)(iVar2 + 1)) | 1;
  *(uint *)(puVar3 + 0x14) = *(uint *)(puVar3 + 0x14) | 0x40;
  *(uint *)(puVar3 + 0xc) = *(uint *)(puVar3 + 0xc) | 0x2000;
  *(undefined4 *)(puVar3 + 4) = 0;
  return;
}



// ==== 0801072c  FUN_0801072c  (516 bytes, 2 xrefs)

longlong FUN_0801072c(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  short sVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  uint extraout_r3;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  
  iVar5 = DAT_08010938;
  pcVar4 = DAT_08010930;
  uVar15 = (int)PTR_DMA1_08010934 >> 0x16;
  uVar13 = (uint)*(ushort *)(DAT_08010930 + 2);
  if (*DAT_08010930 == '\0') {
    iVar6 = FUN_08010e18(PTR_DMA1_08010934,2);
    param_2 = 0x100U - iVar6 & 0xffff;
    bVar2 = false;
    iVar6 = DAT_08010938;
    while (uVar13 != param_2) {
      cVar1 = *(char *)(iVar6 + uVar13);
      if ((((cVar1 != '\r') && (cVar1 != '\n')) && (cVar1 != '\0')) || (bVar2)) {
        bVar2 = true;
        if (((cVar1 == '\r') || (cVar1 == '\n')) || (cVar1 == '\0')) {
          uVar11 = *(ushort *)(pcVar4 + 2);
          uVar15 = (uint)uVar11;
          if (uVar13 < uVar15) {
            sVar3 = 0x100 - uVar11;
          }
          else {
            sVar3 = -uVar11;
          }
          if (uVar13 < uVar15) {
            FUN_08002968(DAT_0801093c,iVar5 + uVar15,0x100 - uVar15);
            puVar9 = (ushort *)((0x100 - (uint)*(ushort *)(pcVar4 + 2)) + (int)DAT_0801093c);
            iVar10 = DAT_08010938;
            uVar7 = uVar13;
          }
          else {
            uVar7 = uVar13 - uVar15;
            iVar10 = iVar5 + uVar15;
            puVar9 = DAT_0801093c;
          }
          FUN_08002968(puVar9,iVar10,uVar7);
          puVar9 = DAT_0801093c;
          *(undefined1 *)((int)DAT_0801093c + (uint)(ushort)(sVar3 + (short)uVar13)) = 0;
          FUN_08011368(1,&DAT_08010940,puVar9);
          FUN_0800eeb8(DAT_0801093c);
          bVar2 = false;
          *(short *)(pcVar4 + 2) = (short)uVar13 + 1;
        }
        uVar13 = uVar13 + 1 & 0xff;
      }
      else {
        uVar13 = (uint)(byte)(pcVar4[2] + 1U);
        *(ushort *)(pcVar4 + 2) = (ushort)(byte)(pcVar4[2] + 1U);
      }
    }
  }
  else {
    iVar6 = FUN_08010e18(PTR_DMA1_08010934,2);
    uVar7 = uVar15 - iVar6 & 0xffff;
    while (pcVar4 = DAT_08010930, uVar13 != uVar7) {
      while ((uVar13 != uVar7 && (*(char *)(iVar5 + uVar13) != -0x55))) {
        cVar1 = pcVar4[2];
        *(ushort *)(pcVar4 + 2) = (ushort)(byte)(cVar1 + 1U);
        uVar13 = (uint)(byte)(cVar1 + 1U);
      }
      if (uVar13 == uVar7) break;
      sVar3 = (short)(uVar15 - iVar6);
      if (uVar13 < uVar7) {
        uVar11 = sVar3 - (short)uVar13;
      }
      else {
        uVar11 = (sVar3 - (short)uVar13) + 0x100;
      }
      if (uVar11 < 8) break;
      if (*(char *)(iVar5 + (uVar13 + 1 & 0xff)) == -0x33) {
        uVar13 = uVar13 + 2 & 0xff;
        uVar7 = (uint)CONCAT11(*(undefined1 *)(iVar5 + (uVar13 + 1 & 0xff)),
                               *(undefined1 *)(iVar5 + uVar13));
        if (uVar7 + 8 <= uVar15) {
          if ((uint)uVar11 < uVar7 + 8) break;
          uVar13 = uVar13 + 2 & 0xff;
          uVar14 = uVar13 + uVar7 + 2 & 0xff;
          if ((*(char *)(iVar5 + uVar14) == -0x24) &&
             (uVar12 = uVar14 + 1 & 0xff, *(char *)(iVar5 + uVar12) == -0x46)) {
            if (uVar14 < uVar13) {
              param_2 = uVar15 - uVar13;
              FUN_08002968(DAT_0801093c,iVar5 + uVar13,param_2,uVar12,param_2,param_3,param_4);
              puVar9 = (ushort *)(param_2 + (int)DAT_0801093c);
              iVar6 = DAT_08010938;
              uVar8 = uVar14;
              uVar12 = extraout_r3;
            }
            else {
              uVar8 = uVar14 - uVar13;
              iVar6 = iVar5 + uVar13;
              puVar9 = DAT_0801093c;
            }
            FUN_08002968(puVar9,iVar6,uVar8,uVar12,param_2,param_3,param_4);
            uVar13 = (uint)*(ushort *)(DAT_08010930 + 2);
            uVar14 = uVar14 + 2 & 0xff;
            if (uVar14 < uVar13) {
              FUN_0800299a(iVar5 + uVar13,uVar15 - uVar13);
              FUN_0800299a(DAT_08010938,uVar14);
            }
            else {
              FUN_0800299a(iVar5 + uVar13,uVar14 - uVar13);
            }
            uVar13 = DAT_08010948;
            pcVar4 = DAT_08010930;
            *(short *)(DAT_08010930 + 2) = (short)uVar14;
            puVar9 = DAT_0801093c;
            if (*DAT_0801093c == uVar13) {
              pcVar4[1] = '\0';
              goto LAB_08010916;
            }
            if (*DAT_0801093c == DAT_0801094c) {
              pcVar4[1] = '\x01';
            }
            else if (pcVar4[1] != '\x01') goto LAB_08010916;
            iVar5 = DAT_08010950;
            for (uVar13 = 0; uVar13 < uVar7 + 2; uVar13 = uVar13 + 1 & 0xffff) {
              *(byte *)((int)puVar9 + uVar13) =
                   *(byte *)((int)puVar9 + uVar13) ^ *(byte *)(iVar5 + (uVar13 & 0xf));
            }
LAB_08010916:
            uVar11 = *(ushort *)((int)puVar9 + uVar7);
            uVar13 = FUN_0800f5e8(DAT_0801093c,uVar7);
            if (uVar13 == uVar11) {
              return CONCAT44(param_2,1);
            }
            break;
          }
        }
        *(short *)(DAT_08010930 + 2) = sVar3;
        break;
      }
      cVar1 = pcVar4[2];
      *(ushort *)(pcVar4 + 2) = (ushort)(byte)(cVar1 + 1U);
      uVar13 = (uint)(byte)(cVar1 + 1U);
    }
  }
  return (ulonglong)param_2 << 0x20;
}



// ==== 08010954  FUN_08010954  (26 bytes, 3 xrefs)

void FUN_08010954(int param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = PTR_USART1_08010970;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
    do {
    } while (-1 < *(int *)puVar1 << 0x19);
    *(uint *)(puVar1 + 4) = (uint)*(byte *)(param_1 + uVar2);
  }
  return;
}



// ==== 08010974  FUN_08010974  (132 bytes, 1 xrefs)

void FUN_08010974(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_r5;
  ushort local_18;
  undefined1 local_16;
  undefined1 local_15;
  
  iVar2 = DAT_080109fc;
  iVar1 = DAT_080109f8;
  if (*(char *)(DAT_080109f8 + 1) == '\x01') {
    for (uVar3 = 0; unaff_r5 = iVar2, uVar3 < param_2; uVar3 = uVar3 + 1 & 0xffff) {
      *(byte *)(param_1 + uVar3) = *(byte *)(param_1 + uVar3) ^ *(byte *)(iVar2 + (uVar3 & 0xf));
    }
  }
  _local_18 = CONCAT12((char)param_2,0xcdab);
  _local_18 = CONCAT13((char)(param_2 >> 8),_local_18);
  FUN_08010954(&local_18,4);
  FUN_08010954(param_1,param_2);
  if (*(char *)(iVar1 + 1) == '\x01') {
    local_18 = CONCAT11(*(undefined1 *)(unaff_r5 + (param_2 + 1 & 0xf)),
                        *(undefined1 *)(unaff_r5 + (param_2 & 0xf))) ^ 0xffff;
  }
  else {
    local_18 = 0xffff;
  }
  _local_18 = CONCAT12(0xdc,local_18);
  _local_18 = CONCAT13(0xba,_local_18);
  FUN_08010954(&local_18,4);
  return;
}



// ==== 08010a00  FUN_08010a00  (6 bytes, 3 xrefs)

void FUN_08010a00(undefined1 param_1)

{
  *DAT_08010a08 = param_1;
  return;
}



// ==== 08010a0c  FUN_08010a0c  (50 bytes, 1 xrefs)

void FUN_08010a0c(void)

{
  *(uint *)PTR_DAT_08010a40 = *(uint *)PTR_DAT_08010a40 | 1;
  *(uint *)(PTR_DAT_08010a40 + -4) = *(uint *)(PTR_DAT_08010a40 + -4) | 0x800000;
  FUN_0801236c();
  *DAT_08010a44 = 0x80000000;
  return;
}



// ==== 08010a48  FUN_08010a48  (304 bytes, 2 xrefs)

undefined4 FUN_08010a48(void)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  int in_r3;
  uint uVar9;
  uint extraout_r3;
  uint uVar10;
  uint uVar11;
  
  iVar5 = DAT_08010b7c;
  puVar2 = DAT_08010b78;
  uVar4 = (uint)*DAT_08010b78;
  uVar1 = DAT_08010b78[1];
  uVar9 = (uint)uVar1;
  while( true ) {
    if (uVar4 == uVar9) {
      return 0;
    }
    while ((iVar3 = DAT_08010b7c, uVar4 != uVar9 && (*(char *)(iVar5 + uVar4) != -0x55))) {
      uVar4 = uVar4 + 1 & 0x1ff;
      *puVar2 = (ushort)uVar4;
    }
    if (uVar4 == uVar9) {
      return 0;
    }
    if (uVar4 < uVar9) {
      uVar7 = uVar1 - (short)uVar4;
    }
    else {
      uVar7 = (uVar1 - (short)uVar4) + 0x200;
    }
    if (uVar7 < 8) {
      return 0;
    }
    if (*(char *)(iVar5 + (uVar4 + 1 & 0x1ff)) == -0x33) break;
    uVar4 = uVar4 + 1 & 0x1ff;
    *puVar2 = (ushort)uVar4;
  }
  uVar4 = uVar4 + 2 & 0x1ff;
  uVar10 = (uint)CONCAT11(*(undefined1 *)(iVar5 + (uVar4 + 1 & 0x1ff)),
                          *(undefined1 *)(iVar5 + uVar4));
  if (uVar10 + 8 < 0x201) {
    if ((uint)uVar7 < uVar10 + 8) {
      return 0;
    }
    uVar4 = uVar4 + 2 & 0x1ff;
    uVar11 = uVar4 + uVar10 + 2 & 0x1ff;
    if ((*(char *)(iVar5 + uVar11) == -0x24) && (*(char *)(iVar5 + (uVar11 + 1 & 0x1ff)) == -0x46))
    {
      if (uVar11 < uVar4) {
        in_r3 = 0x200 - uVar4;
        FUN_08002968(DAT_08010b80,DAT_08010b7c + uVar4);
        iVar5 = in_r3 + DAT_08010b80;
        iVar6 = iVar3;
        uVar8 = uVar11;
        uVar9 = extraout_r3;
      }
      else {
        uVar8 = uVar11 - uVar4;
        iVar6 = DAT_08010b7c + uVar4;
        iVar5 = DAT_08010b80;
      }
      FUN_08002968(iVar5,iVar6,uVar8,uVar9,in_r3);
      uVar9 = (uint)*puVar2;
      uVar4 = uVar11 + 2 & 0x1ff;
      if (uVar4 < uVar9) {
        FUN_0800299a(iVar3 + uVar9,0x200 - uVar9);
        FUN_0800299a(DAT_08010b7c,uVar4);
      }
      else {
        FUN_0800299a(iVar3 + uVar9,uVar4 - uVar9);
      }
      *puVar2 = (ushort)uVar4;
      iVar3 = DAT_08010b84;
      iVar5 = DAT_08010b80;
      for (uVar9 = 0; uVar9 < uVar10 + 2; uVar9 = uVar9 + 1 & 0xffff) {
        *(byte *)(iVar5 + uVar9) = *(byte *)(iVar5 + uVar9) ^ *(byte *)(iVar3 + (uVar9 & 0xf));
      }
      uVar1 = *(ushort *)(iVar5 + uVar10);
      uVar9 = FUN_0800f5e8(DAT_08010b80,uVar10);
      if (uVar9 == uVar1) {
        return 1;
      }
      return 0;
    }
  }
  *puVar2 = uVar1;
  return 0;
}



// ==== 08010b88  FUN_08010b88  (102 bytes, 1 xrefs)

void FUN_08010b88(int param_1,uint param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  iVar1 = DAT_08010bf0;
  for (uVar3 = 0; puVar2 = DAT_08010bf4, uVar3 < param_2; uVar3 = uVar3 + 1 & 0xffff) {
    *(byte *)(param_1 + uVar3) = *(byte *)(param_1 + uVar3) ^ *(byte *)(iVar1 + (uVar3 & 0xf));
  }
  *DAT_08010bf4 = 0xab;
  puVar2[1] = 0xcd;
  puVar2[2] = (char)param_2;
  puVar2[3] = (char)(param_2 >> 8);
  FUN_08002968(puVar2 + 4,param_1,param_2);
  puVar2[param_2 + 4] = *(byte *)(iVar1 + (param_2 & 0xf)) ^ 0xff;
  puVar2[param_2 + 5] = *(byte *)(iVar1 + (param_2 + 1 & 0xf)) ^ 0xff;
  puVar2[param_2 + 6] = 0xdc;
  puVar2[param_2 + 7] = 0xba;
  FUN_08012b18(0x81,puVar2,param_2 + 8);
  return;
}



// ==== 08010bf8  FUN_08010bf8  (142 bytes, 2 xrefs)

void FUN_08010bf8(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = DAT_08010c88;
  uVar5 = 0;
  do {
    uVar4 = 0;
    do {
      iVar2 = uVar5 * 4 + uVar4;
      iVar3 = uVar4 * 4 + iVar1;
      uVar4 = uVar4 + 1 & 0xff;
      *(undefined1 *)(iVar3 + uVar5) = *(undefined1 *)(param_1 + iVar2);
    } while (uVar4 < 4);
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 4);
  FUN_0800364c(DAT_08010c88,param_3,iVar3,uVar4,param_1,param_2,param_3);
  uVar5 = 1;
  do {
    FUN_08011618(DAT_08010c88);
    FUN_080115fe(DAT_08010c88);
    FUN_0801126c(DAT_08010c88);
    FUN_0800364c(DAT_08010c88,uVar5 * 0x10 + param_3);
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 10);
  FUN_08011618(DAT_08010c88);
  FUN_080115fe(DAT_08010c88);
  FUN_0800364c(DAT_08010c88,param_3 + 0xa0);
  uVar5 = 0;
  do {
    uVar4 = 0;
    do {
      iVar2 = uVar4 * 4;
      iVar3 = uVar5 * 4 + uVar4;
      uVar4 = uVar4 + 1 & 0xff;
      *(undefined1 *)(param_2 + iVar3) = *(undefined1 *)(iVar2 + iVar1 + uVar5);
    } while (uVar4 < 4);
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 4);
  return;
}



// ==== 08010c8c  FUN_08010c8c  (134 bytes, 1 xrefs)

void FUN_08010c8c(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar3 = 0x1f;
  uVar1 = 0x6000000;
  uVar2 = 0x3000000;
  do {
    uVar1 = uVar1 << 1 | uVar2 & 1;
    uVar3 = uVar3 - 1;
    uVar2 = uVar2 >> 1;
  } while (uVar2 != 0);
  uVar1 = FUN_080119d4(uVar1 << (uVar3 & 0xff));
  uVar4 = 0x1f;
  uVar6 = 0xf80000;
  uVar2 = 0x1f00000;
  uVar3 = 0xf80000;
  puVar5 = (uint *)(((param_2 & 0x6000000) >> (uVar1 & 0xff)) * 4 + param_1 + 0xc);
  do {
    uVar2 = uVar2 << 1 | uVar3 & 1;
    uVar4 = uVar4 - 1;
    uVar3 = uVar3 >> 1;
  } while (uVar3 != 0);
  uVar1 = FUN_080119d4(uVar2 << (uVar4 & 0xff));
  uVar4 = *puVar5;
  uVar3 = 0x1f;
  uVar2 = 0x1f00000;
  do {
    uVar2 = uVar6 & 1 | uVar2 << 1;
    uVar3 = uVar3 - 1;
    uVar6 = uVar6 >> 1;
  } while (uVar6 != 0);
  uVar2 = FUN_080119d4(uVar2 << (uVar3 & 0xff));
  *puVar5 = uVar4 & ~(7 << ((param_2 & 0x1f00000) >> (uVar1 & 0xff) & 0xff)) |
            param_3 << ((param_2 & 0x1f00000) >> (uVar2 & 0xff) & 0xff);
  return;
}



// ==== 08010d14  FUN_08010d14  (18 bytes, 2 xrefs)

void FUN_08010d14(uint param_1)

{
  *(uint *)(PTR_RCC_08010d28 + 0x3c) = *(uint *)(PTR_RCC_08010d28 + 0x3c) | param_1;
  return;
}



// ==== 08010d2c  FUN_08010d2c  (18 bytes, 2 xrefs)

void FUN_08010d2c(uint param_1)

{
  *(uint *)PTR_DAT_08010d40 = *(uint *)PTR_DAT_08010d40 | param_1;
  return;
}



// ==== 08010d44  FUN_08010d44  (16 bytes, 2 xrefs)

void FUN_08010d44(uint *param_1,uint param_2)

{
  *param_1 = *param_1 | 1 << (param_2 & 0x10);
  return;
}



// ==== 08010d54  FUN_08010d54  (38 bytes, 2 xrefs)

void FUN_08010d54(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  param_2 = DAT_08010d7c + param_2;
  if (param_5 == 0x10) {
    *(undefined4 *)((uint)*(byte *)(param_2 + -1) + param_1 + 0xc) = param_3;
    *(undefined4 *)((uint)*(byte *)(param_2 + -1) + param_1 + 8) = param_4;
    return;
  }
  *(undefined4 *)((uint)*(byte *)(param_2 + -1) + param_1 + 8) = param_3;
  *(undefined4 *)((uint)*(byte *)(param_2 + -1) + param_1 + 0xc) = param_4;
  return;
}



// ==== 08010d80  FUN_08010d80  (22 bytes, 4 xrefs)

void FUN_08010d80(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(DAT_08010d98 + param_2 + -1);
  *(uint *)(param_1 + uVar1) = *(uint *)(param_1 + uVar1) & DAT_08010d9c | param_3;
  return;
}



// ==== 08010da0  FUN_08010da0  (18 bytes, 4 xrefs)

void FUN_08010da0(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(DAT_08010db4 + param_2 + -1);
  *(uint *)(param_1 + uVar1) = *(uint *)(param_1 + uVar1) & 0xfffffffe;
  return;
}



// ==== 08010db8  FUN_08010db8  (18 bytes, 2 xrefs)

void FUN_08010db8(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(DAT_08010dcc + param_2 + -1);
  *(uint *)(param_1 + uVar1) = *(uint *)(param_1 + uVar1) & 0xfffffffe;
  return;
}



// ==== 08010dd0  FUN_08010dd0  (18 bytes, 4 xrefs)

void FUN_08010dd0(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(DAT_08010de4 + param_2 + -1);
  *(uint *)(param_1 + uVar1) = *(uint *)(param_1 + uVar1) | 1;
  return;
}



// ==== 08010de8  FUN_08010de8  (18 bytes, 2 xrefs)

void FUN_08010de8(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(DAT_08010dfc + param_2 + -1);
  *(uint *)(param_1 + uVar1) = *(uint *)(param_1 + uVar1) | 1;
  return;
}



// ==== 08010e00  FUN_08010e00  (18 bytes, 2 xrefs)

void FUN_08010e00(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(DAT_08010e14 + param_2 + -1);
  *(uint *)(param_1 + uVar1) = *(uint *)(param_1 + uVar1) | 2;
  return;
}



// ==== 08010e18  FUN_08010e18  (16 bytes, 2 xrefs)

uint FUN_08010e18(int param_1,int param_2)

{
  return *(uint *)((uint)*(byte *)(DAT_08010e28 + param_2 + -1) + param_1 + 4) & 0xffff;
}



// ==== 08010e2c  FUN_08010e2c  (16 bytes, 2 xrefs)

uint FUN_08010e2c(int param_1,int param_2)

{
  return *(uint *)(param_1 + (uint)*(byte *)(DAT_08010e3c + param_2 + -1)) & DAT_08010e40;
}



// ==== 08010e44  FUN_08010e44  (22 bytes, 4 xrefs)

void FUN_08010e44(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(DAT_08010e5c + param_2 + -1);
  *(uint *)(uVar1 + param_1 + 4) = *(uint *)(uVar1 + param_1 + 4) & 0xffff0000 | param_3;
  return;
}



// ==== 08010e60  FUN_08010e60  (14 bytes, 4 xrefs)

void FUN_08010e60(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)((uint)*(byte *)(DAT_08010e70 + param_2 + -1) + param_1 + 0xc) = param_3;
  return;
}



// ==== 08010e74  FUN_08010e74  (14 bytes, 4 xrefs)

void FUN_08010e74(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)((uint)*(byte *)(DAT_08010e84 + param_2 + -1) + param_1 + 8) = param_3;
  return;
}



// ==== 08010e88  FUN_08010e88  (162 bytes, 1 xrefs)

uint FUN_08010e88(uint *param_1)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar2 = PTR_DAT_08010f2c;
  uVar4 = 0;
  uVar3 = *param_1;
  if ((char)param_1[1] == '\0') {
    *(uint *)PTR_DAT_08010f2c = *(uint *)PTR_DAT_08010f2c & ~uVar3;
    *(uint *)(puVar2 + 4) = *(uint *)(puVar2 + 4) & ~*param_1;
    return 0;
  }
  if (uVar3 == 0) {
    return 0;
  }
  cVar1 = *(char *)((int)param_1 + 5);
  if (cVar1 == '\0') {
    *(uint *)(PTR_DAT_08010f2c + 4) = *(uint *)(PTR_DAT_08010f2c + 4) & ~uVar3;
    *(uint *)puVar2 = *(uint *)puVar2 | *param_1;
  }
  else {
    if (cVar1 == '\x01') {
      uVar3 = *(uint *)PTR_DAT_08010f2c & ~uVar3;
    }
    else {
      if (cVar1 != '\x02') {
        uVar4 = 1;
        goto LAB_08010eaa;
      }
      uVar3 = *(uint *)PTR_DAT_08010f2c | uVar3;
    }
    *(uint *)PTR_DAT_08010f2c = uVar3;
    *(uint *)(puVar2 + 4) = *(uint *)(puVar2 + 4) | *param_1;
  }
LAB_08010eaa:
  puVar2 = PTR_DAT_08010f2c;
  cVar1 = *(char *)((int)param_1 + 6);
  if (cVar1 != '\0') {
    puVar5 = (uint *)(PTR_DAT_08010f2c + -0x80);
    if (cVar1 == '\x01') {
      *(uint *)(PTR_DAT_08010f2c + -0x7c) = *(uint *)(PTR_DAT_08010f2c + -0x7c) & ~*param_1;
      *puVar5 = *puVar5 | *param_1;
    }
    else {
      if (cVar1 == '\x02') {
        uVar3 = *puVar5 & ~*param_1;
      }
      else {
        if (cVar1 != '\x03') {
          return uVar4 | 2;
        }
        uVar3 = *puVar5 | *param_1;
      }
      *puVar5 = uVar3;
      *(uint *)(puVar2 + -0x7c) = *(uint *)(puVar2 + -0x7c) | *param_1;
    }
  }
  return uVar4;
}



// ==== 08010f30  FUN_08010f30  (164 bytes, 13 xrefs)

undefined4 FUN_08010f30(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  for (uVar3 = 0; *param_2 >> (uVar3 & 0xff) != 0; uVar3 = uVar3 + 1) {
    uVar2 = *param_2 & 1 << (uVar3 & 0xff);
    if (uVar2 != 0) {
      iVar4 = uVar2 * uVar2;
      uVar1 = iVar4 * 3;
      *param_1 = *param_1 & ~uVar1 | iVar4 * param_2[1];
      if ((param_2[1] == 1) || (param_2[1] == 2)) {
        param_1[2] = param_1[2] & ~uVar1 | iVar4 * param_2[2];
      }
      param_1[3] = param_1[3] & ~uVar1 | param_2[4] * iVar4;
      if (param_2[1] == 2) {
        if (uVar2 < 0x100) {
          iVar4 = uVar2 * uVar2 * iVar4;
          param_1[8] = param_1[8] & ~(iVar4 * 0xf) | param_2[5] * iVar4;
        }
        else {
          uVar2 = uVar2 >> 8;
          iVar4 = uVar2 * uVar2 * uVar2 * uVar2;
          param_1[9] = param_1[9] & ~(iVar4 * 0xf) | param_2[5] * iVar4;
        }
      }
    }
  }
  if ((param_2[1] == 1) || (param_2[1] == 2)) {
    param_1[1] = param_1[1] & ~*param_2 | param_2[3] * *param_2;
  }
  return 0;
}



// ==== 08010fd4  FUN_08010fd4  (14 bytes, 18 xrefs)

undefined4 FUN_08010fd4(int param_1,uint param_2)

{
  if ((param_2 & ~*(uint *)(param_1 + 0x10)) == 0) {
    return 1;
  }
  return 0;
}



// ==== 08010fe2  FUN_08010fe2  (14 bytes, 2 xrefs)

undefined4 FUN_08010fe2(int param_1,uint param_2)

{
  if ((param_2 & ~*(uint *)(param_1 + 0x10)) == 0) {
    return 1;
  }
  return 0;
}



// ==== 08010ff0  FUN_08010ff0  (14 bytes, 3 xrefs)

undefined4 FUN_08010ff0(int param_1,uint param_2)

{
  if ((param_2 & ~*(uint *)(param_1 + 0x10)) == 0) {
    return 1;
  }
  return 0;
}



// ==== 08010ffe  FUN_08010ffe  (20 bytes, 4 xrefs)

void FUN_08010ffe(uint *param_1,int param_2,int param_3)

{
  *param_1 = *param_1 & ~(param_2 * param_2 * 3) | param_3 * param_2 * param_2;
  return;
}



// ==== 08011012  FUN_08011012  (20 bytes, 2 xrefs)

void FUN_08011012(uint *param_1,int param_2,int param_3)

{
  *param_1 = *param_1 & ~(param_2 * param_2 * 3) | param_3 * param_2 * param_2;
  return;
}



// ==== 08011028  FUN_08011028  (18 bytes, 4 xrefs)

void FUN_08011028(uint param_1)

{
  *(uint *)(PTR_RCC_0801103c + 0x34) = *(uint *)(PTR_RCC_0801103c + 0x34) | param_1;
  return;
}



// ==== 08011040  FUN_08011040  (24 bytes, 1 xrefs)

void FUN_08011040(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_08011548();
  *param_1 = uVar1;
  uVar1 = FUN_08011508();
  param_1[1] = uVar1;
  uVar1 = FUN_08011528();
  param_1[2] = uVar1;
  return;
}



// ==== 08011058  FUN_08011058  (16 bytes, 1 xrefs)

undefined4 FUN_08011058(void)

{
  return *(undefined4 *)(DAT_0801106c + (*(uint *)(PTR_RCC_08011068 + 4) >> 0xb & 0x1c));
}



// ==== 08011070  FUN_08011070  (102 bytes, 2 xrefs)

undefined4 FUN_08011070(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (-1 < (int)(*param_1 << 0x19)) {
    *param_1 = *param_2 | param_2[1] | param_2[2] | param_2[3] | param_2[4] | param_2[5] |
               param_2[6] | param_2[7] | param_2[8] | *param_1 & DAT_080110d8;
    param_1[1] = param_1[1] & 0xfffffffb | param_2[5] >> 0x10;
    if (param_2[8] == 0x2000) {
      param_1[4] = (uint)(ushort)param_2[9];
    }
    uVar1 = 0;
  }
  param_1[7] = param_1[7] & 0xfffff7ff;
  return uVar1;
}



// ==== 080110dc  FUN_080110dc  (50 bytes, 2 xrefs)

void FUN_080110dc(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 - 1;
  if (uVar2 < 4) {
    iVar1 = (uVar2 & 3) << 3;
    *(uint *)(PTR_SYSCFG_08011110 + 8) =
         *(uint *)(PTR_SYSCFG_08011110 + 8) & ~(0x3f << iVar1) | param_3 << iVar1;
    return;
  }
  iVar1 = (uVar2 & 3) << 3;
  *(uint *)(PTR_SYSCFG_08011110 + 0xc) =
       *(uint *)(PTR_SYSCFG_08011110 + 0xc) & ~(0x3f << iVar1) | param_3 << iVar1;
  return;
}



// ==== 08011114  FUN_08011114  (6 bytes, 1 xrefs)

void FUN_08011114(undefined4 param_1)

{
  *DAT_0801111c = param_1;
  return;
}



// ==== 08011120  FUN_08011120  (82 bytes, 1 xrefs)

undefined4 FUN_08011120(undefined *param_1)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = PTR_RCC_08011178;
  if (param_1 == PTR_USART1_08011174) {
    *(uint *)(PTR_RCC_08011178 + 0x30) = *(uint *)(PTR_RCC_08011178 + 0x30) | 0x4000;
    *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) & 0xffffbfff;
  }
  else {
    if (param_1 == PTR_USART2_0801117c) {
      uVar2 = 0x20000;
    }
    else if (param_1 == PTR_USART3_08011180) {
      uVar2 = 0x40000;
    }
    else {
      if (param_1 != PTR_USART4_08011184) {
        return 1;
      }
      uVar2 = 0x80000;
    }
    *(uint *)(PTR_RCC_08011178 + 0x2c) = *(uint *)(PTR_RCC_08011178 + 0x2c) | uVar2;
    *(uint *)(puVar1 + 0x2c) = *(uint *)(puVar1 + 0x2c) & ~uVar2;
  }
  return 0;
}



// ==== 08011188  FUN_08011188  (106 bytes, 1 xrefs)

undefined8 FUN_08011188(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int *piStack_20;
  undefined4 uStack_1c;
  int local_18;
  
  uVar1 = 1;
  piStack_20 = param_2;
  if (-1 < *(int *)(param_1 + 0xc) << 0x12) {
    *(uint *)(param_1 + 0xc) =
         param_2[1] | param_2[3] | param_2[4] | *(uint *)(param_1 + 0xc) & DAT_080111f4;
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffff7ff | param_2[6];
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffcfff | param_2[2];
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffcff | param_2[5];
    uStack_1c = param_3;
    local_18 = param_4;
    FUN_08011040(&piStack_20);
    if ((local_18 != 0) && (*param_2 != 0)) {
      uVar1 = 0;
      FUN_080111f8(param_1,local_18,param_2[6]);
    }
  }
  return CONCAT44(piStack_20,uVar1);
}



// ==== 080111f8  FUN_080111f8  (116 bytes, 1 xrefs)

void FUN_080111f8(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 == 0x800) {
    iVar1 = FUN_080028f0(param_2 * 0x19,param_4 << 1);
    iVar2 = FUN_080028f0(iVar1,100);
    uVar3 = FUN_080028f0((iVar1 + iVar2 * -100) * 8 + 0x32);
    iVar1 = iVar2 * 0x10 + (uVar3 & 0xf8) * 2;
    uVar3 = uVar3 & 7;
  }
  else {
    iVar1 = FUN_080028f0(param_2 * 0x19,param_4 << 2);
    iVar2 = FUN_080028f0(iVar1,100);
    uVar3 = FUN_080028f0((iVar1 + iVar2 * -100) * 0x10 + 0x32);
    iVar1 = iVar2 * 0x10 + (uVar3 & 0xf0);
    uVar3 = uVar3 & 0xf;
  }
  *(uint *)(param_1 + 8) = iVar1 + uVar3 & 0xffff;
  return;
}



// ==== 0801126c  FUN_0801126c  (174 bytes, 1 xrefs)

void FUN_0801126c(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  
  uVar7 = 0;
  do {
    bVar5 = *(byte *)(param_1 + uVar7);
    iVar8 = param_1 + uVar7;
    bVar1 = *(byte *)(iVar8 + 4);
    bVar2 = *(byte *)(iVar8 + 8);
    bVar6 = *(byte *)(iVar8 + 0xc);
    bVar3 = FUN_0801131a(bVar5,2);
    bVar4 = FUN_0801131a(bVar1,3);
    *(byte *)(param_1 + uVar7) = bVar3 ^ bVar4 ^ bVar2 ^ bVar6;
    bVar3 = FUN_0801131a(bVar1,2);
    bVar4 = FUN_0801131a(bVar2,3);
    *(byte *)(iVar8 + 4) = bVar3 ^ bVar4 ^ bVar5 ^ bVar6;
    bVar3 = FUN_0801131a(bVar2,2);
    bVar4 = FUN_0801131a(bVar6,3);
    *(byte *)(iVar8 + 8) = bVar3 ^ bVar4 ^ bVar5 ^ bVar1;
    bVar5 = FUN_0801131a(bVar5,3);
    bVar6 = FUN_0801131a(bVar6,2);
    uVar7 = uVar7 + 1 & 0xff;
    *(byte *)(iVar8 + 0xc) = bVar5 ^ bVar6 ^ bVar1 ^ bVar2;
  } while (uVar7 < 4);
  return;
}



// ==== 0801131a  FUN_0801131a  (78 bytes, 8 xrefs)

uint FUN_0801131a(uint param_1,uint param_2)

{
  uint uVar1;
  uint extraout_r2;
  uint uVar2;
  uint extraout_r3;
  uint uVar3;
  
  uVar2 = 7;
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0;
  }
  if (param_1 < param_2) {
    uVar1 = param_2;
    param_2 = param_1;
  }
  else {
    uVar1 = param_1;
  }
  uVar3 = 0;
  if ((param_2 & 1) != 0) {
    uVar3 = uVar1;
  }
  for (; param_2 >> uVar2 == 0; uVar2 = uVar2 - 1 & 0xff) {
  }
  uVar1 = 1;
  while (uVar1 <= uVar2) {
    uVar2 = switchD_08013068::caseD_ac();
    if ((param_2 >> (extraout_r2 & 0xff) & 1) != 0) {
      uVar3 = uVar3 ^ uVar2;
    }
    uVar2 = extraout_r3;
    uVar1 = extraout_r2 + 1 & 0xff;
  }
  return uVar3;
}



// ==== 08011368  FUN_08011368  (70 bytes, 17 xrefs)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08011368(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*DAT_080113b0 < param_1) {
    return;
  }
  uStack_8 = param_3;
  uStack_4 = param_4;
  if (1 < param_1) {
    if (param_1 == 2) {
      pcVar1 = s_MAJOR___d__080113c4;
    }
    else if (param_1 == 3) {
      pcVar1 = s_TRACE___d__080113d0;
    }
    else {
      if (param_1 != 0x1e) {
        FUN_08011978(s_UNKNOWN__080113b7 + 1,*_DAT_080113b4);
        goto LAB_0801138e;
      }
      pcVar1 = s_DATA___d__080113dc;
    }
    FUN_08011978(pcVar1,*_DAT_080113b4);
  }
LAB_0801138e:
  FUN_080119c0(param_2,&uStack_8);
  return;
}



// ==== 080113e8  FUN_080113e8  (130 bytes, 12 xrefs)

undefined4
FUN_080113e8(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            uint param_5,char *param_6)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_38 [5];
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  uVar4 = 0;
  local_38[3] = 0;
  local_24 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  FUN_080029b0(param_6,&DAT_0801146c);
  if (param_6 == (char *)0x0) {
LAB_0801143e:
    uVar3 = 0xffffffff;
  }
  else {
    for (; uVar4 < param_5; uVar4 = uVar4 + 1 & 0xff) {
      for (; (cVar1 = *param_6, cVar1 != ' ' && (cVar1 != '\t')); param_6 = param_6 + 1) {
        if (cVar1 == '\0') goto LAB_0801143e;
      }
      do {
        do {
          cVar1 = param_6[1];
          param_6 = param_6 + 1;
        } while (cVar1 == ' ');
      } while (cVar1 == '\t');
      if ((cVar1 == '\0') || (iVar2 = FUN_08011470(param_6,local_38 + uVar4), iVar2 != 0))
      goto LAB_0801143e;
    }
    *local_24 = local_38[0];
    *local_20 = local_38[1];
    *local_1c = local_38[2];
    *local_18 = local_38[3];
    uVar3 = 0;
  }
  return uVar3;
}



// ==== 08011470  FUN_08011470  (88 bytes, 1 xrefs)

undefined4 FUN_08011470(char *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  
  *param_2 = 0;
  for (; (*param_1 == ' ' || (*param_1 == '\t')); param_1 = param_1 + 1) {
  }
  iVar1 = FUN_08002a1c(param_1,&DAT_080114c8,2);
  if (iVar1 == 0) {
    puVar2 = &DAT_080114d4;
  }
  else {
    iVar1 = FUN_08002a1c(param_1,&DAT_080114cc,1);
    if (iVar1 == 0) {
      puVar2 = &DAT_080114d8;
    }
    else {
      puVar2 = &DAT_080114d0;
    }
  }
  iVar1 = FUN_08002a60(param_1,puVar2,param_2);
  if (iVar1 == 1) {
    return 0;
  }
  return 0xffffffff;
}



// ==== 080114dc  FUN_080114dc  (34 bytes, 0 xrefs)

void FUN_080114dc(void)

{
  if ((~*(uint *)(PTR_EXTI_08011500 + 0xc) & 0x10000) == 0) {
    *(undefined4 *)(PTR_EXTI_08011500 + 0xc) = 0x10000;
    if (*(int *)(PTR_PWR_08011504 + 0x14) << 0x14 < 0) {
      FUN_0800f490();
    }
  }
  return;
}



// ==== 08011508  FUN_08011508  (24 bytes, 1 xrefs)

uint FUN_08011508(uint param_1)

{
  return param_1 >> (*(byte *)(DAT_08011524 + (*(uint *)(PTR_RCC_08011520 + 8) >> 6 & 0x3c)) & 0x1f)
  ;
}



// ==== 08011528  FUN_08011528  (22 bytes, 1 xrefs)

uint FUN_08011528(uint param_1)

{
  return param_1 >>
         (*(byte *)(DAT_08011544 + ((*(uint *)(PTR_RCC_08011540 + 8) & 0x7fff) >> 0xc) * 4) & 0x1f);
}



// ==== 08011548  FUN_08011548  (68 bytes, 1 xrefs)

undefined4 FUN_08011548(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(PTR_RCC_0801158c + 8) & 0x38;
  if (uVar2 == 8) {
    return DAT_08011594;
  }
  if (uVar2 == 0x10) {
    uVar1 = FUN_08011598();
    return uVar1;
  }
  uVar1 = 0x8000;
  if ((uVar2 != 0x18) && (uVar2 != 0x20)) {
    uVar1 = FUN_080028f0(*(undefined4 *)
                          (DAT_08011590 + (*(uint *)(PTR_RCC_0801158c + 4) >> 0xb & 0x1c)),
                         1 << ((*(uint *)PTR_RCC_0801158c & 0x3fff) >> 0xb));
  }
  return uVar1;
}



// ==== 08011598  FUN_08011598  (40 bytes, 1 xrefs)

int FUN_08011598(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_RCC_080115c0;
  if ((*(uint *)(PTR_RCC_080115c0 + 0xc) & 3) == 3) {
    iVar2 = DAT_080115c4;
  }
  else {
    iVar2 = FUN_08011058();
  }
  if ((*(uint *)(puVar1 + 0xc) & 0xf) >> 2 == 0) {
    return iVar2 << 1;
  }
  return iVar2 * 3;
}



// ==== 080115c8  FUN_080115c8  (48 bytes, 1 xrefs)

void FUN_080115c8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_18;
  
  if ((param_2 != 0) && (param_2 < 4)) {
    uStack_18 = param_4;
    FUN_08002968(&uStack_18,param_1,param_2);
    FUN_08002968(param_1,param_1 + param_2);
    FUN_08002968((4 - param_2) + param_1,&uStack_18,param_2);
  }
  return;
}



// ==== 080115f8  FUN_080115f8  (6 bytes, 1 xrefs)

uint FUN_080115f8(uint param_1)

{
  return param_1 >> 0x18 | param_1 << 8;
}



// ==== 080115fe  FUN_080115fe  (26 bytes, 2 xrefs)

void FUN_080115fe(int param_1)

{
  uint uVar1;
  
  uVar1 = 1;
  do {
    FUN_080115c8(uVar1 * 4 + param_1,uVar1);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 4);
  return;
}



// ==== 08011618  FUN_08011618  (46 bytes, 2 xrefs)

void FUN_08011618(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = DAT_08011648;
  uVar4 = 0;
  do {
    uVar3 = 0;
    do {
      iVar5 = uVar3 * 4 + param_1;
      bVar1 = *(byte *)(iVar5 + uVar4);
      uVar3 = uVar3 + 1 & 0xff;
      *(undefined1 *)(iVar5 + uVar4) =
           *(undefined1 *)((uint)(bVar1 >> 4) * 0x10 + iVar2 + (bVar1 & 0xf));
    } while (uVar3 < 4);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  return;
}



// ==== 0801164c  FUN_0801164c  (78 bytes, 2 xrefs)

undefined4 FUN_0801164c(uint param_1)

{
  return CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                     ((param_1 >> 0x1c) * 0x10 + DAT_0801169c +
                                     (param_1 >> 0x18 & 0xf)),
                                    *(undefined1 *)
                                     (((param_1 & 0xffffff) >> 0x14) * 0x10 + DAT_0801169c +
                                     ((param_1 & 0xffffff) >> 0x10 & 0xf))),
                           *(undefined1 *)
                            (((param_1 & 0xffff) >> 0xc) * 0x10 + DAT_0801169c +
                            ((param_1 & 0xffff) >> 8 & 0xf))),
                  *(undefined1 *)((param_1 & 0xf0) + DAT_0801169c + (param_1 & 0xf)));
}



// ==== 080116a0  FUN_080116a0  (326 bytes, 0 xrefs)

void FUN_080116a0(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined1 *puVar4;
  uint uVar5;
  int extraout_r1;
  
  puVar4 = DAT_080117e8;
  uVar5 = *(int *)(DAT_080117e8 + 0x28) + 1;
  *(uint *)(DAT_080117e8 + 0x28) = uVar5;
  *puVar4 = 1;
  FUN_080028f0(uVar5,0x32);
  if (extraout_r1 == 0) {
    puVar4[1] = 1;
    sVar2 = *(short *)(puVar4 + 0x14);
    if ((sVar2 != 0) && (*(short *)(puVar4 + 0x14) = sVar2 + -1, sVar2 == 1)) {
      puVar4[4] = 1;
    }
  }
  if ((uVar5 & 3) == 0) {
    puVar4[0xc] = 1;
  }
  if (*(short *)(puVar4 + 0x1a) != 0) {
    *(short *)(puVar4 + 0x1a) = *(short *)(puVar4 + 0x1a) + -1;
  }
  if (puVar4[0xb] != '\0') {
    puVar4[0xb] = puVar4[0xb] + -1;
  }
  if (puVar4[10] != '\0') {
    puVar4[10] = puVar4[10] + -1;
  }
  sVar2 = *(short *)(puVar4 + 0x1a);
  cVar1 = *DAT_080117ec;
  if (((cVar1 == '\0' && sVar2 == 0) && (sVar3 = *(short *)(puVar4 + 0xe), sVar3 != 0)) &&
     (*(short *)(puVar4 + 0xe) = sVar3 + -1, sVar3 == 1)) {
    puVar4[7] = 1;
  }
  if (((cVar1 == '\x05') && (sVar3 = *(short *)(puVar4 + 0x1e), sVar3 != 0)) &&
     (*(short *)(puVar4 + 0x1e) = sVar3 + -1, sVar3 == 1)) {
    puVar4[8] = 1;
  }
  if (*DAT_080117f0 == '\0') {
    if (*(char *)(DAT_080117f4 + 0x1a) == '\0') {
      if (((*DAT_080117f8 == '\x01') && (cVar1 != '\x02')) &&
         (((cVar1 != '\x01' &&
           (((cVar1 != '\x04' && (sVar2 == 0)) && (sVar2 = *(short *)(puVar4 + 0x1c), sVar2 != 0))))
          && (*(short *)(puVar4 + 0x1c) = sVar2 + -1, sVar2 == 1)))) {
        puVar4[6] = 1;
      }
    }
    else if (((cVar1 != '\x02') && (cVar1 != '\x01')) &&
            (((cVar1 != '\x04' && ((sVar2 == 0 && (sVar2 = *(short *)(puVar4 + 0x12), sVar2 != 0))))
             && (*(short *)(puVar4 + 0x12) = sVar2 + -1, sVar2 == 1)))) {
      puVar4[3] = 1;
    }
  }
  else if ((((cVar1 != '\x02') && (cVar1 != '\x01')) &&
           (sVar2 = *(short *)(puVar4 + 0x10), sVar2 != 0)) &&
          (*(short *)(puVar4 + 0x10) = sVar2 + -1, sVar2 == 1)) {
    puVar4[2] = 1;
  }
  sVar2 = *(short *)(puVar4 + 0x20);
  if ((sVar2 != 0) && (*(short *)(puVar4 + 0x20) = sVar2 + -1, sVar2 == 1)) {
    puVar4[9] = 1;
  }
  if (((*DAT_080117fc != '\0') && (cVar1 != '\x02')) &&
     ((cVar1 != '\x01' &&
      (((cVar1 != '\x04' && (sVar2 = *(short *)(puVar4 + 0x16), sVar2 != 0)) &&
       (*(short *)(puVar4 + 0x16) = sVar2 + -1, sVar2 == 1)))))) {
    puVar4[5] = 1;
  }
  if (*(short *)(puVar4 + 0x18) != 0) {
    *(short *)(puVar4 + 0x18) = *(short *)(puVar4 + 0x18) + -1;
  }
  return;
}



// ==== 08011800  FUN_08011800  (10 bytes, 1 xrefs)

void FUN_08011800(void)

{
  FUN_08011114(DAT_0801180c);
  return;
}



// ==== 08011810  FUN_08011810  (8 bytes, 1 xrefs)

void FUN_08011810(void)

{
  *(undefined4 *)(DAT_0801181c + 8) = DAT_08011818;
  return;
}



// ==== 08011820  FUN_08011820  (324 bytes, 1 xrefs)

void FUN_08011820(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  puVar4 = PTR_USBD_08011964;
  bVar1 = PTR_USBD_08011964[6];
  bVar2 = PTR_USBD_08011964[5];
  uVar3 = PTR_USBD_08011964[0xe];
  if ((int)((uint)(byte)PTR_USBD_08011964[4] << 0x1d) < 0) {
    FUN_0800299a(DAT_08011968,0x180);
    *(undefined4 *)(DAT_08011968 + 4) = 0x40;
    FUN_08012d2c();
    puVar4[10] = 1;
    puVar4[9] = 0;
    *DAT_0801196c = 0;
  }
  bVar1 = puVar4[10] & bVar1;
  uVar9 = (uint)bVar1;
  if ((bVar1 & 1) != 0) {
    puVar4[0xe] = 0;
    FUN_0801240c();
    uVar9 = (uint)(bVar1 >> 1) << 1;
  }
  uVar7 = 1;
  do {
    if (uVar9 == 0) {
      uVar7 = (uint)(PTR_USBD_08011964[9] & bVar2);
      uVar9 = 1;
      while (puVar4 = PTR_USBD_08011964, uVar7 != 0) {
        if ((1 << uVar9 & uVar7) != 0) {
          PTR_USBD_08011964[0xe] = (char)uVar9;
          if ((puVar4[0x19] & 1) != 0) {
            uVar10 = (uint)*(ushort *)(puVar4 + 0x1c);
            iVar8 = uVar9 * 0x14 + DAT_08011968;
            FUN_080126e4(uVar9,*(undefined4 *)(iVar8 + 0xd0),uVar10);
            PTR_USBD_08011964[0x19] = PTR_USBD_08011964[0x19] & 0xfe;
            *(uint *)(iVar8 + 0xd0) = *(int *)(iVar8 + 0xd0) + uVar10;
            *(uint *)(iVar8 + 0xd8) = *(int *)(iVar8 + 0xd8) + uVar10;
            iVar5 = *(int *)(iVar8 + 0xd4) - uVar10;
            *(int *)(iVar8 + 0xd4) = iVar5;
            if ((uVar10 < *(ushort *)(iVar8 + 200)) || (iVar5 == 0)) {
              FUN_08012cc4(uVar9);
            }
          }
          uVar7 = uVar7 & ~(1 << uVar9);
        }
        uVar9 = uVar9 + 1 & 0xff;
      }
      PTR_USBD_08011964[0xe] = uVar3;
      return;
    }
    if ((1 << uVar7 & uVar9) != 0) {
      puVar4[0xe] = (char)uVar7;
      if ((int)((uint)(byte)puVar4[0x15] << 0x1d) < 0) {
        puVar4[0x15] = puVar4[0x15] & 0xfb;
      }
      iVar5 = uVar7 * 0x14 + DAT_08011968;
      uVar6 = (uint)*(ushort *)(iVar5 + 0x28);
      uVar10 = *(uint *)(iVar5 + 0x34);
      if (uVar6 < uVar10) {
        iVar8 = *(int *)(iVar5 + 0x30) + uVar6;
        *(int *)(iVar5 + 0x30) = iVar8;
        *(uint *)(iVar5 + 0x38) = *(int *)(iVar5 + 0x38) + uVar6;
        uVar10 = uVar10 - uVar6;
        *(uint *)(iVar5 + 0x34) = uVar10;
        if (uVar10 == 0) goto LAB_080118e2;
        if (uVar6 <= uVar10) {
          uVar10 = uVar6;
        }
        FUN_08012704(uVar7,iVar8,uVar10 & 0xffff);
        puVar4[0x15] = 1;
      }
      else {
        *(uint *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + uVar10;
        *(uint *)(iVar5 + 0x38) = *(int *)(iVar5 + 0x38) + uVar10;
        *(undefined4 *)(iVar5 + 0x34) = 0;
LAB_080118e2:
        FUN_08012c60(uVar7 | 0x80,*(undefined4 *)(iVar5 + 0x38));
      }
      uVar9 = uVar9 & ~(1 << uVar7);
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while( true );
}



// ==== 08011970  FUN_08011970  (8 bytes, 0 xrefs)

void FUN_08011970(void)

{
  FUN_08011820();
  return;
}



// ==== 08011978  FUN_08011978  (24 bytes, 4 xrefs)

void FUN_08011978(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_08011bb0(param_1,&uStack_c,DAT_08011994,DAT_08011990);
  return;
}



// ==== 08011998  FUN_08011998  (36 bytes, 39 xrefs)

undefined4 FUN_08011998(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  local_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = FUN_08011bb0(param_2,&uStack_8,&uStack_10,DAT_080119bc);
  FUN_080122e8(0,&uStack_10);
  return uVar1;
}



// ==== 080119c0  FUN_080119c0  (12 bytes, 1 xrefs)

void FUN_080119c0(undefined4 param_1,undefined4 param_2)

{
  FUN_08011bb0(param_1,param_2,DAT_080119d0,DAT_080119cc);
  return;
}



// ==== 080119d4  FUN_080119d4  (46 bytes, 6 xrefs)

int FUN_080119d4(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x20;
  if (param_1 >> 0x10 != 0) {
    iVar1 = 0x10;
    param_1 = param_1 >> 0x10;
  }
  if (param_1 >> 8 != 0) {
    iVar1 = iVar1 + -8;
    param_1 = param_1 >> 8;
  }
  if (param_1 >> 4 != 0) {
    iVar1 = iVar1 + -4;
    param_1 = param_1 >> 4;
  }
  if (param_1 >> 2 != 0) {
    iVar1 = iVar1 + -2;
    param_1 = param_1 >> 2;
  }
  if (param_1 >> 1 == 0) {
    return iVar1 - param_1;
  }
  return iVar1 + -2;
}



// ==== 08011a02  __ARM_common_switch8  (26 bytes, 20 xrefs)

/* WARNING: This is an inlined function */

void __ARM_common_switch8(void)

{
  uint in_r3;
  uint uVar1;
  int unaff_lr;
  
  uVar1 = (uint)*(byte *)(unaff_lr + -1);
  if (in_r3 < *(byte *)(unaff_lr + -1)) {
    uVar1 = in_r3;
  }
                    /* WARNING: Could not recover jumptable at 0x08011a1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_lr + (uint)*(byte *)(unaff_lr + uVar1) * 2))();
  return;
}



// ==== 08011a3c  FUN_08011a3c  (344 bytes, 3 xrefs)

int * FUN_08011a3c(int *param_1,int param_2,int param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  char extraout_r2;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  undefined1 uVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar1 = 0;
  if (param_3 == 0 && param_4 == 0) {
    if (param_6 == 1) {
      uVar1 = ~param_5;
    }
    param_1[2] = 1;
    *param_1 = (int)&DAT_08011ba4;
    param_1[3] = param_6;
    param_1[1] = uVar1;
  }
  else {
    iVar5 = (int)(DAT_08011b98 * ((param_4 >> 0x14) + DAT_08011b94)) >> 0x10;
    do {
      while( true ) {
        if (param_6 == 1) {
          uVar1 = -param_5;
        }
        else {
          uVar1 = (iVar5 - param_5) + 1;
        }
        lVar9 = (ulonglong)DAT_08011b9c << 0x20;
        lVar11 = (ulonglong)DAT_08011ba0 << 0x20;
        if ((int)uVar1 < 0) {
          uVar3 = -uVar1;
        }
        else {
          uVar3 = uVar1;
        }
        iVar4 = uVar3 * 0x100000 + DAT_08011ba0;
        while( true ) {
          uVar6 = (undefined4)((ulonglong)lVar9 >> 0x20);
          local_3c = (undefined4)((ulonglong)lVar11 >> 0x20);
          local_40 = (undefined4)lVar11;
          if (uVar3 == 0) break;
          if ((uVar3 & 1) != 0) {
            lVar11 = FUN_08002be8(local_40,local_3c,(int)lVar9,uVar6);
          }
          lVar9 = FUN_08002be8((int)lVar9,uVar6);
          uVar3 = (int)uVar3 >> 1;
        }
        uVar8 = 1;
        if ((int)uVar1 < 0) {
          uVar10 = FUN_08002be8();
          uVar10 = FUN_08002be8((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),local_40,local_3c);
        }
        else {
          uVar10 = FUN_08003044(param_3,param_4,0,iVar4);
          uVar10 = FUN_08003044((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),local_40,local_3c);
        }
        bVar7 = true;
        FUN_08003174();
        if ((bool)uVar8 && !bVar7) {
          FUN_08002ee0((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,DAT_08011bac);
          lVar11 = FUN_08003134();
        }
        else {
          lVar11 = -1;
        }
        iVar4 = 0x10;
        while( true ) {
          if ((lVar11 == 0) || (iVar4 < 0)) break;
          lVar11 = FUN_08002d10((int)lVar11,(int)((ulonglong)lVar11 >> 0x20),10,0);
          *(char *)(param_2 + iVar4) = extraout_r2 + '0';
          iVar4 = iVar4 + -1;
        }
        iVar2 = 0x11 - (iVar4 + 1);
        if (param_6 != 1) break;
        if (lVar11 == 0) {
          iVar5 = (iVar2 - param_5) + -1;
          goto LAB_08011b88;
        }
        param_5 = 0x11;
        param_6 = 0;
      }
      bVar7 = true;
      if ((lVar11 == 0) && (iVar2 <= (int)param_5)) {
        if (iVar2 < (int)param_5) {
          bVar7 = false;
          iVar5 = iVar5 + -1;
        }
      }
      else {
        bVar7 = false;
        iVar5 = iVar5 + 1;
      }
    } while (!bVar7);
LAB_08011b88:
    param_1[2] = iVar2;
    param_1[3] = param_6;
    *param_1 = param_2 + iVar4 + 1;
    param_1[1] = iVar5;
    param_1 = param_1 + 2;
  }
  return param_1;
}



// ==== 08011bb0  FUN_08011bb0  (1710 bytes, 3 xrefs)

/* WARNING: Type propagation algorithm not settling */

int FUN_08011bb0(byte *param_1,uint *param_2,undefined4 param_3,code *param_4)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined1 **ppuVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 uVar8;
  char extraout_r1;
  int *piVar9;
  int iVar10;
  uint *puVar11;
  undefined4 *puVar12;
  int extraout_r2;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  byte *pbVar17;
  undefined1 *puVar18;
  char *pcVar19;
  uint uVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  longlong lVar24;
  undefined1 **in_stack_ffffff80;
  undefined1 *in_stack_ffffff84;
  undefined1 *local_78;
  undefined4 local_74;
  uint local_70;
  undefined1 *local_6c;
  char local_63 [2];
  undefined4 local_61;
  undefined4 *******local_4c;
  char *local_48;
  char *local_40;
  uint local_3c;
  undefined1 **local_38;
  undefined1 *local_34;
  int local_30;
  uint local_2c;
  byte *pbStack_24;
  uint *local_20;
  undefined4 local_1c;
  code *local_18;
  
  local_18 = param_4;
  local_1c = param_3;
  pbStack_24 = param_1;
  iVar16 = 0;
  local_20 = param_2;
LAB_08011fec:
  uVar5 = (uint)*param_1;
  if (uVar5 == 0) {
    return iVar16;
  }
  if (uVar5 == 0x25) {
    uVar15 = 0;
    puVar18 = (undefined1 *)0x0;
    local_70 = 0;
    pbVar17 = param_1;
    while( true ) {
      param_1 = pbVar17 + 1;
      uVar5 = 1 << (*param_1 - 0x20 & 0xff);
      if ((uVar5 & DAT_08011fb8) == 0) break;
      uVar15 = uVar15 | uVar5;
      pbVar17 = param_1;
    }
    if (*param_1 == 0x2a) {
      local_70 = *local_20;
      local_20 = local_20 + 1;
      if ((int)local_70 < 0) {
        uVar15 = uVar15 | 0x2000;
        local_70 = -local_70;
      }
      uVar15 = uVar15 | 2;
      param_1 = pbVar17 + 2;
    }
    else {
      for (; *param_1 - 0x30 < 10; param_1 = param_1 + 1) {
        local_70 = (uint)*param_1 + local_70 * 10 + -0x30;
        uVar15 = uVar15 | 2;
      }
    }
    if (*param_1 == 0x2e) {
      uVar15 = uVar15 | 4;
      if (param_1[1] == 0x2a) {
        param_1 = param_1 + 2;
        puVar18 = (undefined1 *)*local_20;
        local_20 = local_20 + 1;
      }
      else {
        while( true ) {
          param_1 = param_1 + 1;
          if (9 < *param_1 - 0x30) break;
          puVar18 = (undefined1 *)((uint)*param_1 + (int)puVar18 * 10 + -0x30);
        }
      }
    }
    bVar1 = *param_1;
    if (bVar1 == 0x6c) {
      uVar5 = 0x100000;
LAB_08011c7a:
      uVar15 = uVar15 | uVar5;
      if (param_1[1] == bVar1) {
        uVar15 = uVar15 + 0x100000;
        param_1 = param_1 + 1;
      }
    }
    else if (bVar1 < 0x6d) {
      if (bVar1 != 0x4c) {
        if (bVar1 == 0x68) {
          uVar5 = 0x300000;
          goto LAB_08011c7a;
        }
        if (bVar1 != 0x6a) goto LAB_08011c8c;
        uVar15 = uVar15 | 0x200000;
      }
    }
    else if ((bVar1 != 0x74) && (bVar1 != 0x7a)) goto LAB_08011c8c;
    param_1 = param_1 + 1;
LAB_08011c8c:
    uVar5 = (uint)*param_1;
    local_3c = uVar5;
    bVar23 = SBORROW4(uVar5,0x66);
    bVar21 = (int)(uVar5 - 0x66) < 0;
    bVar22 = uVar5 == 0x66;
LAB_08011c92:
    while (!bVar22) {
      if (bVar21 == bVar23) {
        if (uVar5 == 0x70) {
          iVar7 = 0x10;
          uVar15 = uVar15 | 4;
          puVar18 = &NMI;
        }
        else if (uVar5 < 0x71) {
          if (uVar5 == 0x67) break;
          if (uVar5 == 0x69) goto LAB_08011dc4;
          if (uVar5 == 0x6e) {
            uVar5 = (uVar15 & 0x7fffff) >> 0x14;
            if (uVar5 == 2) {
              piVar9 = (int *)*local_20;
              *piVar9 = iVar16;
              piVar9[1] = iVar16 >> 0x1f;
            }
            else if (uVar5 == 3) {
              *(short *)*local_20 = (short)iVar16;
            }
            else if (uVar5 == 4) {
              *(char *)*local_20 = (char)iVar16;
            }
            else {
              *(int *)*local_20 = iVar16;
            }
            local_20 = local_20 + 1;
            goto LAB_08011fea;
          }
          if (uVar5 != 0x6f) goto LAB_08011ce2;
          iVar7 = 8;
        }
        else {
          if (uVar5 == 0x73) {
            in_stack_ffffff80 = (undefined1 **)*local_20;
            iVar7 = -1;
            goto LAB_08011d44;
          }
          if (uVar5 != 0x75) {
            if (uVar5 == 0x78) goto LAB_08011e38;
            goto LAB_08011ce2;
          }
          iVar7 = 10;
        }
LAB_08011e54:
        uVar14 = (uVar15 & 0x7fffff) >> 0x14;
        if (uVar14 == 2) {
          puVar11 = (uint *)((uint)((int)local_20 + 7) & 0xfffffff8);
          uVar3 = *puVar11;
          uVar20 = puVar11[1];
          local_20 = puVar11 + 2;
        }
        else {
          uVar3 = *local_20;
          local_20 = local_20 + 1;
          uVar20 = 0;
          if (uVar14 == 3) {
            uVar3 = uVar3 & 0xffff;
          }
          if (uVar14 == 4) {
            uVar3 = uVar3 & 0xff;
          }
        }
        local_78 = (undefined1 *)0x0;
        if ((int)(uVar15 << 0x1c) < 0) {
          if (uVar5 == 0x70) {
            local_74 = (undefined1 **)CONCAT31(local_74._1_3_,0x40);
            local_78 = (undefined1 *)0x1;
LAB_08011ebc:
          }
          else if ((iVar7 == 0x10) && (uVar20 != 0 || uVar3 != 0)) {
            local_74._0_2_ = CONCAT11(*param_1,0x30);
            local_78 = (undefined1 *)0x2;
            goto LAB_08011ebc;
          }
          if ((iVar7 == 8) && ((uVar20 != 0 || uVar3 != 0 || ((int)(uVar15 << 0x1d) < 0)))) {
            local_74 = (undefined1 **)CONCAT31(local_74._1_3_,0x30);
            puVar18 = puVar18 + -1;
            local_78 = (undefined1 *)0x1;
          }
        }
LAB_08011ee0:
        lVar24 = CONCAT44(uVar20,uVar3);
        uVar13 = 0;
        if (uVar5 == 0x58) {
          local_48 = s_0123456789ABCDEF_08011fd0;
        }
        else {
          local_48 = s_0123456789abcdef_08011fbc;
        }
        local_4c = &local_4c;
        while( true ) {
          if (lVar24 == 0) break;
          lVar24 = FUN_08002d10((int)lVar24,(int)((ulonglong)lVar24 >> 0x20),iVar7,uVar13);
          local_4c = (undefined4 *******)((int)local_4c + -1);
          *(char *)local_4c = local_48[extraout_r2];
        }
        puVar6 = (undefined1 *)((int)&local_4c - (int)local_4c);
        if ((int)(uVar15 << 0x1d) < 0) {
          uVar15 = uVar15 & 0xfffeffff;
        }
        else {
          puVar18 = (undefined1 *)0x1;
        }
        if ((int)puVar6 < (int)puVar18) {
          ppuVar4 = (undefined1 **)(puVar18 + -(int)puVar6);
        }
        else {
          ppuVar4 = (undefined1 **)0x0;
        }
        local_70 = local_70 - (int)((undefined1 *)((int)ppuVar4 + (int)puVar6) + (int)local_78);
        if (-1 < (int)(uVar15 << 0xf)) {
          iVar7 = FUN_080122bc(local_70,uVar15,local_1c,local_18);
          iVar16 = iVar7 + iVar16;
        }
        for (iVar7 = 0; iVar7 < (int)local_78; iVar7 = iVar7 + 1) {
          (*local_18)(local_63[iVar7 + -0x11],local_1c);
          iVar16 = iVar16 + 1;
        }
        if ((int)(uVar15 << 0xf) < 0) {
          iVar7 = FUN_080122bc(local_70,uVar15,local_1c,local_18);
          iVar16 = iVar7 + iVar16;
        }
        while (in_stack_ffffff80 = (undefined1 **)((int)ppuVar4 + -1), 0 < (int)ppuVar4) {
          (*local_18)(0x30,local_1c);
          iVar16 = iVar16 + 1;
          ppuVar4 = in_stack_ffffff80;
        }
        while (in_stack_ffffff84 = puVar6 + -1, 0 < (int)puVar6) {
          cVar2 = *(char *)local_4c;
          local_4c = (undefined4 *******)((int)local_4c + 1);
          (*local_18)(cVar2,local_1c);
          iVar16 = iVar16 + 1;
          puVar6 = in_stack_ffffff84;
        }
        goto LAB_08012280;
      }
      if (uVar5 == 0x58) {
LAB_08011e38:
        iVar7 = 0x10;
        goto LAB_08011e54;
      }
      if (0x58 < uVar5) {
        if (uVar5 == 99) {
          local_78._0_2_ = (ushort)(byte)*local_20;
          in_stack_ffffff80 = &local_78;
          iVar7 = 1;
LAB_08011d44:
          local_20 = local_20 + 1;
          if ((int)(uVar15 << 0x1d) < 0) {
            for (iVar10 = 0;
                (iVar10 < (int)puVar18 &&
                ((iVar10 < iVar7 || (*(char *)((int)in_stack_ffffff80 + iVar10) != '\0'))));
                iVar10 = iVar10 + 1) {
            }
          }
          else {
            for (iVar10 = 0;
                (iVar10 < iVar7 || (*(char *)((int)in_stack_ffffff80 + iVar10) != '\0'));
                iVar10 = iVar10 + 1) {
            }
          }
          uVar5 = local_70 - iVar10;
          iVar7 = FUN_080122bc(uVar5,uVar15,local_1c,local_18);
          iVar16 = iVar7 + iVar16 + iVar10;
          while (iVar7 = iVar10 + -1, iVar10 != 0) {
            uVar8 = *(undefined1 *)in_stack_ffffff80;
            in_stack_ffffff80 = (undefined1 **)((int)in_stack_ffffff80 + 1);
            (*local_18)(uVar8,local_1c);
            iVar10 = iVar7;
          }
          in_stack_ffffff84 = (undefined1 *)0xffffffff;
          goto LAB_08011fe4;
        }
        if (uVar5 == 100) {
LAB_08011dc4:
          iVar7 = 10;
          uVar14 = (uVar15 & 0x7fffff) >> 0x14;
          if (uVar14 == 2) {
            puVar11 = (uint *)((uint)((int)local_20 + 7) & 0xfffffff8);
            uVar3 = *puVar11;
            uVar20 = puVar11[1];
            local_20 = puVar11 + 2;
          }
          else {
            uVar3 = *local_20;
            local_20 = local_20 + 1;
            if (uVar14 == 3) {
              uVar3 = (uint)(short)uVar3;
            }
            uVar20 = (int)uVar3 >> 0x1f;
            if (uVar14 == 4) {
              uVar3 = (uint)(char)uVar3;
              uVar20 = (int)uVar3 >> 0x1f;
            }
          }
          if ((int)uVar20 < 0) {
            bVar22 = uVar3 != 0;
            uVar3 = -uVar3;
            uVar20 = -(uint)bVar22 - uVar20;
            uVar8 = 0x2d;
LAB_08011e20:
            local_74 = (undefined1 **)CONCAT31(local_74._1_3_,uVar8);
            local_78 = (undefined1 *)0x1;
          }
          else {
            if ((int)(uVar15 << 0x14) < 0) {
              uVar8 = 0x2b;
              goto LAB_08011e20;
            }
            local_78 = (undefined1 *)0x0;
            if ((uVar15 & 1) != 0) {
              uVar8 = 0x20;
              goto LAB_08011e20;
            }
          }
          goto LAB_08011ee0;
        }
        if (uVar5 != 0x65) goto LAB_08011ce2;
        break;
      }
      if (uVar5 == 0) {
        return iVar16;
      }
      bVar23 = SBORROW4(uVar5,0x45);
      bVar21 = (int)(uVar5 - 0x45) < 0;
      bVar22 = uVar5 == 0x45;
      if (!bVar22) goto code_r0x08011ca4;
    }
    goto LAB_08011ffa;
  }
  goto LAB_08011ce2;
code_r0x08011ca4:
  bVar23 = SBORROW4(uVar5,0x46);
  bVar21 = (int)(uVar5 - 0x46) < 0;
  bVar22 = uVar5 == 0x46;
  if (!bVar22) goto code_r0x08011ca8;
  goto LAB_08011c92;
code_r0x08011ca8:
  if (uVar5 != 0x47) {
LAB_08011ce2:
    (*local_18)(uVar5,local_1c);
    iVar16 = iVar16 + 1;
    goto LAB_08011fea;
  }
LAB_08011ffa:
  if (-1 < (int)(uVar15 << 0x1d)) {
    puVar18 = (undefined1 *)0x6;
  }
  puVar12 = (undefined4 *)((uint)((int)local_20 + 7) & 0xfffffff8);
  uVar13 = *puVar12;
  local_20 = puVar12 + 2;
  if ((puVar12[1] & 0x80000000) == 0) {
    if ((int)(uVar15 << 0x14) < 0) {
      local_40 = &DAT_08012290;
    }
    else if ((uVar15 & 1) == 0) {
      local_40 = &DAT_08012298;
    }
    else {
      local_40 = &DAT_08012294;
    }
  }
  else {
    local_40 = &DAT_0801228c;
  }
  uVar14 = puVar12[1] & 0x7fffffff;
  if (uVar5 == 0x65) {
LAB_08012054:
    if ((int)puVar18 < 0x11) {
      puVar6 = puVar18 + 1;
    }
    else {
      puVar6 = (undefined1 *)0x11;
    }
    FUN_08011a3c(&local_3c,(int)&local_61 + 1,uVar13,uVar14,puVar6,0);
    local_6c = local_34;
    local_2c = local_3c;
    in_stack_ffffff84 = puVar18 + 1;
LAB_08012122:
    in_stack_ffffff80 = (undefined1 **)0x0;
    local_78 = (undefined1 *)0x1;
    local_74 = local_38;
LAB_08012154:
    local_6c = local_34;
    local_3c = local_2c;
  }
  else {
    if (uVar5 < 0x66) {
      if (uVar5 == 0x45) goto LAB_08012054;
      if (uVar5 != 0x46) {
        if (uVar5 == 0x47) goto LAB_080120ce;
        goto LAB_08012156;
      }
    }
    else if (uVar5 != 0x66) {
      if (uVar5 == 0x67) {
LAB_080120ce:
        if ((int)puVar18 < 1) {
          puVar18 = (undefined1 *)0x1;
        }
        if ((int)puVar18 < 0x12) {
          puVar6 = puVar18;
        }
        else {
          puVar6 = (undefined1 *)0x11;
        }
        FUN_08011a3c(&local_3c,(int)&local_61 + 1,uVar13,uVar14,puVar6,0);
        local_6c = local_34;
        local_2c = local_3c;
        in_stack_ffffff80 = (undefined1 **)0x0;
        in_stack_ffffff84 = puVar18;
        if (-1 < (int)(uVar15 << 0x1c)) {
          in_stack_ffffff84 = local_34;
          if ((int)puVar18 <= (int)local_34) {
            in_stack_ffffff84 = puVar18;
          }
          for (; (1 < (int)in_stack_ffffff84 && (in_stack_ffffff84[local_3c - 1] == '0'));
              in_stack_ffffff84 = in_stack_ffffff84 + -1) {
          }
        }
        if (((int)puVar18 <= (int)local_38) || ((int)local_38 < -4)) goto LAB_08012122;
        if ((int)local_38 < 1) {
          puVar18 = in_stack_ffffff84 + -(int)local_38;
          in_stack_ffffff80 = local_38;
LAB_08012146:
          in_stack_ffffff84 = puVar18;
        }
        else {
          puVar18 = (undefined1 *)((int)local_38 + 1);
          if ((int)in_stack_ffffff84 < (int)puVar18) goto LAB_08012146;
        }
        local_78 = (undefined1 *)((int)local_38 + (1 - (int)in_stack_ffffff80));
        local_74 = (undefined1 **)0x80000000;
        goto LAB_08012154;
      }
      goto LAB_08012156;
    }
    local_74 = (undefined1 **)0x80000000;
    FUN_08011a3c(&local_3c,(int)&local_61 + 1,uVar13,uVar14,puVar18,1);
    local_6c = local_34;
    in_stack_ffffff80 = (undefined1 **)0x0;
    local_2c = local_3c;
    if (local_30 == 0) {
      in_stack_ffffff84 = (undefined1 *)((int)local_38 + (int)(puVar18 + 1));
    }
    else {
      in_stack_ffffff84 = local_34;
    }
    if (-1 < (int)puVar18 - (int)in_stack_ffffff84) {
      in_stack_ffffff80 = (undefined1 **)(-1 - ((int)puVar18 - (int)in_stack_ffffff84));
      in_stack_ffffff84 = puVar18 + 1;
    }
    local_78 = in_stack_ffffff84 + -(int)puVar18;
  }
LAB_08012156:
  if ((-1 < (int)(uVar15 << 0x1c)) && ((int)in_stack_ffffff84 <= (int)local_78)) {
    local_78 = (undefined1 *)0xffffffff;
  }
  local_61._0_1_ = '\0';
  pcVar19 = (char *)&local_61;
  if (local_74 != (undefined1 **)0x80000000) {
    local_3c = 2;
    local_38 = (undefined1 **)0x2b;
    if ((int)local_74 < 0) {
      local_74 = (undefined1 **)-(int)local_74;
      local_38 = (undefined1 **)0x2d;
    }
    while ((uVar5 = local_3c, local_3c = local_3c - 1, 0 < (int)uVar5 ||
           (local_74 != (undefined1 **)0x0))) {
      local_74 = (undefined1 **)FUN_080028f0(local_74,10);
      pcVar19 = pcVar19 + -1;
      *pcVar19 = extraout_r1 + '0';
    }
    pcVar19[-1] = (char)local_38;
    pcVar19 = pcVar19 + -2;
    *pcVar19 = (*param_1 & 0x20) + 0x45;
  }
  local_74 = (undefined1 **)(local_63 + (2 - (int)pcVar19));
  local_70 = (local_70 -
             (int)(in_stack_ffffff84 + ((int)local_78 >> 0x1f) + (uint)(*local_40 != '\0') +
                  (int)local_74)) - 1;
  if (-1 < (int)(uVar15 << 0xf)) {
    iVar7 = FUN_080122bc(local_70,uVar15,local_1c,local_18);
    iVar16 = iVar7 + iVar16;
  }
  if (*local_40 != '\0') {
    (*local_18)(*local_40,local_1c);
    iVar16 = iVar16 + 1;
  }
  iVar7 = iVar16;
  puVar18 = in_stack_ffffff84;
  if ((int)(uVar15 << 0xf) < 0) {
    iVar7 = FUN_080122bc(local_70,uVar15,local_1c,local_18);
    iVar7 = iVar7 + iVar16;
    puVar18 = in_stack_ffffff84;
  }
  while( true ) {
    iVar16 = iVar7;
    in_stack_ffffff84 = puVar18 + -1;
    if ((int)puVar18 < 1) break;
    if (((int)in_stack_ffffff80 < 0) || ((int)local_6c <= (int)in_stack_ffffff80)) {
      uVar8 = 0x30;
    }
    else {
      uVar8 = *(undefined1 *)(local_2c + (int)in_stack_ffffff80);
    }
    (*local_18)(uVar8,local_1c);
    in_stack_ffffff80 = (undefined1 **)((int)in_stack_ffffff80 + 1);
    local_78 = local_78 + -1;
    iVar7 = iVar16 + 1;
    puVar18 = in_stack_ffffff84;
    if (local_78 == (undefined1 *)0x0) {
      (*local_18)(0x2e,local_1c);
      iVar7 = iVar16 + 2;
      puVar18 = in_stack_ffffff84;
    }
  }
  while (ppuVar4 = local_74, local_74 = (undefined1 **)((int)local_74 + -1), 0 < (int)ppuVar4) {
    cVar2 = *pcVar19;
    pcVar19 = pcVar19 + 1;
    (*local_18)(cVar2,local_1c);
    iVar16 = iVar16 + 1;
  }
LAB_08012280:
  uVar5 = local_70;
LAB_08011fe4:
  iVar7 = FUN_0801229c(uVar5,uVar15,local_1c,local_18);
  iVar16 = iVar7 + iVar16;
LAB_08011fea:
  param_1 = param_1 + 1;
  goto LAB_08011fec;
}



// ==== 0801229c  FUN_0801229c  (32 bytes, 1 xrefs)

int FUN_0801229c(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 << 0x12 < 0) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      (*param_4)(0x20,param_3);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}



// ==== 080122bc  FUN_080122bc  (44 bytes, 5 xrefs)

int FUN_080122bc(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0;
  if (param_2 << 0xf < 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0x20;
  }
  if (-1 < param_2 << 0x12) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      (*param_4)(uVar2,param_3);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}



// ==== 080122e8  FUN_080122e8  (10 bytes, 1 xrefs)

void FUN_080122e8(undefined1 param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_2;
  *param_2 = puVar1 + 1;
  *puVar1 = param_1;
  return;
}



// ==== 080122f2  FUN_080122f2  (120 bytes, 0 xrefs)

undefined4 FUN_080122f2(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  
  uVar1 = *(undefined1 *)(param_1 + 4);
  cVar2 = *(char *)(param_1 + 1);
  puStack_18 = param_3;
  uStack_14 = param_4;
  if (cVar2 == ' ') {
    FUN_08002968(&puStack_18,*param_2,*(undefined2 *)(param_1 + 6));
    FUN_0801284a(uVar1,&puStack_18);
  }
  else if (cVar2 == '!') {
    FUN_08012814(uVar1,&puStack_18);
    FUN_08002968(*param_2,&puStack_18,7);
    *param_3 = 7;
  }
  else {
    if (cVar2 != '\"') {
      return 0xffffffff;
    }
    bVar3 = *(byte *)(param_1 + 2);
    FUN_08012848(uVar1,bVar3 & 1);
    FUN_0801284c(uVar1,(bVar3 & 3) >> 1);
  }
  return 0;
}



// ==== 0801236c  FUN_0801236c  (50 bytes, 1 xrefs)

void FUN_0801236c(void)

{
  FUN_080128f0(DAT_080123a0);
  FUN_08012830(DAT_080123a4);
  FUN_0801276c();
  FUN_08012830(DAT_080123a4 + 0x20);
  FUN_0801276c();
  FUN_08012748(DAT_080123a8);
  FUN_08012748(DAT_080123a8 + 8);
  FUN_08012dfc();
  return;
}



// ==== 080123ae  FUN_080123ae  (14 bytes, 64 xrefs)

void FUN_080123ae(int param_1)

{
  FUN_080123bc(param_1 * 1000);
  return;
}



// ==== 080123bc  FUN_080123bc  (44 bytes, 35 xrefs)

void FUN_080123bc(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  uVar2 = *(uint *)(DAT_080123e8 + 0x18);
  do {
    do {
      uVar1 = *(uint *)(DAT_080123e8 + 0x18);
    } while (uVar1 == uVar2);
    if (uVar1 < uVar2) {
      iVar4 = -uVar1;
    }
    else {
      iVar4 = *(int *)(DAT_080123e8 + 0x14) - uVar1;
    }
    uVar3 = uVar2 + iVar4 + uVar3;
    uVar2 = uVar1;
  } while (uVar3 < (uint)(*(int *)(DAT_080123ec + 0x24) * param_1));
  return;
}



// ==== 0801240c  FUN_0801240c  (58 bytes, 1 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x080125ce

// ==== 080124f8  FUN_080124f8  (12 bytes, 2 xrefs)

bool FUN_080124f8(void)

{
  return *(char *)(DAT_08012504 + 0x1d) != '\0';
}



// ==== 08012508  FUN_08012508  (376 bytes, 1 xrefs)

void FUN_08012508(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  
  *(uint *)PTR_DAT_08012680 = *(uint *)PTR_DAT_08012680 | 1;
  *(uint *)(PTR_DAT_08012680 + -4) = *(uint *)(PTR_DAT_08012680 + -4) | 0x10000000;
  FUN_08011800();
  FUN_080105a0();
  FUN_0800f5c8();
  FUN_080105f8();
  FUN_08010a00(1);
  FUN_08004428();
  FUN_0800299a(DAT_08012684,0x140);
  FUN_0800298c(DAT_08012688,0xf,0x2d);
  *(undefined1 *)(DAT_08012688 + 0xe) = 0;
  FUN_0800e688();
  FUN_0800e0fc(0);
  FUN_080123ae(0x32);
  FUN_0800dcfc(DAT_08012690,DAT_0801268c);
  FUN_08009c7c();
  FUN_080097c4();
  FUN_08009938(0,2);
  FUN_08009938(1,2);
  FUN_08004c74();
  FUN_080049a8(1);
  FUN_0800ae98();
  iVar3 = DAT_08012694;
  uVar6 = 0;
  do {
    FUN_0800dcfc(uVar6 * 2 + iVar3,DAT_0801268c);
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 4);
  FUN_08003e70(0);
  if (*DAT_08012698 == '\0' && *DAT_0801269c == '\0') {
    FUN_0800b2fc(5);
    *(undefined4 *)(PTR_GPIOF_080126b4 + 0x28) = 0x100;
    *DAT_080126b8 = 1;
    pcVar1 = DAT_080126c0;
    pcVar2 = DAT_080126bc;
  }
  else {
    FUN_0800d95c();
    FUN_0800904c();
    FUN_080123ae(2000);
    *DAT_080126a0 = 0x38;
    uVar5 = FUN_080043c0();
    puVar4 = DAT_080126a8;
    iVar3 = DAT_08012684;
    if (*(uint *)(DAT_08012684 + 0xc) <= DAT_080126a4) {
      *DAT_080126a8 = 1;
      FUN_08008c54();
      *puVar4 = 0;
    }
    FUN_08008ba4(uVar5);
    *(undefined4 *)(PTR_GPIOB_080126ac + 0x28) = 0x10;
    *DAT_080126b0 = 1;
    FUN_08009534(0,0x2a);
    uVar6 = (uint)(byte)(*(char *)(iVar3 + (uint)*(byte *)(iVar3 + 9)) + 1);
    if (uVar6 < 0xc9) {
      FUN_08009534(1,0xf);
      FUN_080096a0(2,uVar6);
    }
    else if (uVar6 - 0xc9 < 7) {
      FUN_08009534(1,0x16);
    }
    FUN_08009330(0);
    FUN_0800b0e4();
    pcVar1 = DAT_080126c0;
    pcVar2 = DAT_080126bc;
  }
  do {
    FUN_080084c0();
    if (*pcVar2 == '\x01') {
      FUN_08007cb4();
      *pcVar2 = '\0';
    }
    if (*pcVar1 == '\x01') {
      FUN_08008078();
      *pcVar1 = '\0';
    }
  } while( true );
}



// ==== 080126c4  FUN_080126c4  (30 bytes, 2 xrefs)

uint FUN_080126c4(uint param_1,undefined2 *param_2)

{
  uint uVar1;
  
  uVar1 = 1;
  do {
    if (param_1 <= uVar1 * 8) {
      *param_2 = (short)(uVar1 * 8);
      return uVar1;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x41);
  *param_2 = 0;
  return 1;
}



// ==== 080126e4  FUN_080126e4  (26 bytes, 2 xrefs)

void FUN_080126e4(int param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_08012700 + param_1 * 4;
  for (; param_3 != 0; param_3 = param_3 - 1 & 0xffff) {
    *param_2 = *puVar1;
    param_2 = param_2 + 1;
  }
  return;
}



// ==== 08012704  FUN_08012704  (26 bytes, 2 xrefs)

void FUN_08012704(int param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = PTR_DAT_08012720 + param_1 * 4;
  for (; param_3 != 0; param_3 = param_3 - 1 & 0xffff) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *puVar2 = uVar1;
  }
  return;
}



// ==== 08012724  FUN_08012724  (28 bytes, 1 xrefs)

undefined4 FUN_08012724(void)

{
  undefined *puVar1;
  
  FUN_08012744();
  puVar1 = PTR_USBD_08012740;
  PTR_USBD_08012740[0xe] = 0;
  *puVar1 = 0;
  puVar1[8] = 4;
  puVar1[10] = 1;
  puVar1[9] = 0;
  return 0;
}



// ==== 08012744  FUN_08012744  (2 bytes, 1 xrefs)

void FUN_08012744(void)

{
  return;
}



// ==== 08012748  FUN_08012748  (32 bytes, 2 xrefs)

void FUN_08012748(byte *param_1)

{
  int iVar1;
  
  iVar1 = (*param_1 & 0x7f) * 4 + DAT_08012768;
  if ((int)((uint)*param_1 * 0x1000000) < 0) {
    *(undefined4 *)(iVar1 + 0x11c) = *(undefined4 *)(param_1 + 4);
    return;
  }
  *(undefined4 *)(iVar1 + 0x13c) = *(undefined4 *)(param_1 + 4);
  return;
}



// ==== 0801276c  FUN_0801276c  (32 bytes, 2 xrefs)

void FUN_0801276c(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_0801278c;
  *(undefined1 *)(param_1 + 7) = *(undefined1 *)(DAT_0801278c + 0x1e);
  puVar2 = DAT_08012790;
  while ((undefined4 *)*puVar2 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar2;
  }
  *puVar2 = param_1;
  *param_1 = 0;
  *(char *)(iVar1 + 0x1e) = *(char *)(iVar1 + 0x1e) + '\x01';
  return;
}



// ==== 08012794  FUN_08012794  (30 bytes, 0 xrefs)

void FUN_08012794(undefined4 param_1,uint param_2)

{
  if (((param_2 & 0x3f) == 0) && (param_2 != 0)) {
    FUN_08012b18(0x81,0);
    return;
  }
  *DAT_080127b4 = 0;
  return;
}



// ==== 080127b8  FUN_080127b8  (78 bytes, 0 xrefs)

void FUN_080127b8(undefined4 param_1,int param_2)

{
  ushort *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  
  puVar1 = DAT_08012808;
  uVar3 = (uint)*DAT_08012808;
  puVar2 = PTR_DAT_0801280c + uVar3;
  if (uVar3 + param_2 < 0x201) {
    puVar4 = PTR_DAT_08012810;
    iVar5 = param_2;
  }
  else {
    FUN_08002968(puVar2,PTR_DAT_08012810,0x200 - uVar3);
    puVar2 = PTR_DAT_0801280c;
    puVar4 = PTR_DAT_08012810 + (0x200 - (uint)*puVar1);
    iVar5 = (uint)*puVar1 + param_2 + -0x200;
  }
  FUN_08002968(puVar2,puVar4,iVar5);
  *puVar1 = *puVar1 + (short)param_2 & 0x1ff;
  FUN_08012aac(2,PTR_DAT_08012810,0x100);
  return;
}



// ==== 08012814  FUN_08012814  (22 bytes, 1 xrefs)

void FUN_08012814(undefined4 param_1,int param_2)

{
  FUN_08002a4e(DAT_0801282c);
  *(undefined1 *)(param_2 + 6) = 8;
  *(undefined1 *)(param_2 + 5) = 0;
  *(undefined1 *)(param_2 + 4) = 0;
  return;
}



// ==== 08012830  FUN_08012830  (16 bytes, 2 xrefs)

void FUN_08012830(int param_1)

{
  *(undefined4 *)(param_1 + 4) = DAT_08012840;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = DAT_08012844;
  return;
}



// ==== 08012848  FUN_08012848  (2 bytes, 1 xrefs)

void FUN_08012848(void)

{
  return;
}



// ==== 0801284a  FUN_0801284a  (2 bytes, 1 xrefs)

void FUN_0801284a(void)

{
  return;
}



// ==== 0801284c  FUN_0801284c  (2 bytes, 1 xrefs)

void FUN_0801284c(void)

{
  return;
}



// ==== 08012850  FUN_08012850  (32 bytes, 3 xrefs)

void FUN_08012850(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = (undefined4 *)*DAT_08012870; puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if ((code *)puVar1[4] != (code *)0x0) {
      (*(code *)puVar1[4])(param_1,param_2);
    }
  }
  return;
}



// ==== 08012874  FUN_08012874  (98 bytes, 1 xrefs)

undefined4 FUN_08012874(byte *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar2 = (undefined4 *)*DAT_080128d8;
  if ((*param_1 & 3) == 1) {
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      if ((puVar2[1] != 0) && (*(byte *)(puVar2 + 7) == param_1[4])) {
        UNRECOVERED_JUMPTABLE = (code *)puVar2[1];
        goto LAB_080128c4;
      }
    }
  }
  else if ((*param_1 & 3) == 2) {
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      if ((puVar2[2] != 0) && (*(byte *)(puVar2 + 7) == param_1[5])) {
        UNRECOVERED_JUMPTABLE = (code *)puVar2[2];
LAB_080128c4:
                    /* WARNING: Could not recover jumptable at 0x080128c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*UNRECOVERED_JUMPTABLE)();
        return uVar1;
      }
    }
  }
  return 0xffffffff;
}



// ==== 080128dc  FUN_080128dc  (16 bytes, 1 xrefs)

void FUN_080128dc(void)

{
  FUN_08012aac(2,DAT_080128ec,0x100);
  return;
}



// ==== 080128f0  FUN_080128f0  (12 bytes, 1 xrefs)

void FUN_080128f0(undefined4 param_1)

{
  *(undefined4 *)(DAT_080128fc + 0x18) = param_1;
  *(undefined1 *)(DAT_08012900 + 0x1e) = 0;
  return;
}



// ==== 08012904  FUN_08012904  (76 bytes, 1 xrefs)

undefined4 FUN_08012904(uint param_1)

{
  undefined1 uVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar2 = PTR_USBD_08012950;
  uVar1 = PTR_USBD_08012950[0xe];
  uVar3 = param_1 & 0x7f;
  PTR_USBD_08012950[0xe] = (char)uVar3;
  if ((int)(param_1 * 0x1000000) < 0) {
    if (uVar3 != 0) {
      puVar2[0x15] = puVar2[0x15] & 0xcf;
      puVar2[0x15] = puVar2[0x15] | 0x40;
      goto LAB_08012942;
    }
  }
  else if (uVar3 != 0) {
    puVar2[0x19] = puVar2[0x19] & 0x9f;
    puVar2[0x19] = puVar2[0x19] | 0x80;
    goto LAB_08012942;
  }
  puVar2[0x10] = puVar2[0x10] & 0xfb;
LAB_08012942:
  puVar2[0xe] = uVar1;
  return 0;
}



// ==== 08012954  FUN_08012954  (4 bytes, 1 xrefs)

undefined4 FUN_08012954(void)

{
  return 0;
}



// ==== 08012958  FUN_08012958  (48 bytes, 1 xrefs)

undefined4 FUN_08012958(uint param_1,byte *param_2)

{
  undefined1 uVar1;
  undefined *puVar2;
  byte bVar3;
  uint uVar4;
  
  puVar2 = PTR_USBD_08012988;
  uVar1 = PTR_USBD_08012988[0xe];
  uVar4 = param_1 & 0x7f;
  PTR_USBD_08012988[0xe] = (char)uVar4;
  bVar3 = 0;
  if ((int)(param_1 * 0x1000000) < 0) {
    if (uVar4 == 0) goto LAB_08012980;
    bVar3 = (byte)(((uint)(byte)puVar2[0x15] << 0x1b) >> 0x18);
  }
  else {
    if (uVar4 == 0) goto LAB_08012980;
    bVar3 = (byte)(((uint)(byte)puVar2[0x19] << 0x1a) >> 0x18);
  }
  bVar3 = bVar3 >> 7;
LAB_08012980:
  *param_2 = bVar3;
  puVar2[0xe] = uVar1;
  return 0;
}



// ==== 0801298c  FUN_0801298c  (204 bytes, 3 xrefs)

longlong FUN_0801298c(byte *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  uint local_20;
  uint local_1c;
  undefined4 uStack_18;
  
  puVar2 = PTR_USBD_08012a5c;
  iVar1 = DAT_08012a58;
  local_20 = param_2 & 0xffff0000;
  uVar4 = *param_1 & 0x7f;
  bVar6 = 0;
  if ((*param_1 & 0x7f) == 0) {
    *(undefined2 *)(DAT_08012a58 + 200) = 0x40;
    *(undefined1 *)(iVar1 + 0xca) = 0;
    *(undefined1 *)(iVar1 + 0xcc) = 1;
    *(undefined2 *)(iVar1 + 0x28) = 0x40;
    *(undefined1 *)(iVar1 + 0x2a) = 0;
    *(undefined1 *)(iVar1 + 0x2c) = 1;
  }
  else {
    if (7 < uVar4) {
      return CONCAT44(local_20,0xffffffff);
    }
    local_1c = (uint)(byte)PTR_USBD_08012a5c[0xe];
    PTR_USBD_08012a5c[0xe] = (char)uVar4;
    uStack_18 = param_4;
    if ((int)((uint)*param_1 << 0x18) < 0) {
      iVar5 = uVar4 * 0x14 + iVar1;
      *(undefined2 *)(iVar5 + 0x28) = *(undefined2 *)(param_1 + 2);
      *(byte *)(iVar5 + 0x2a) = param_1[1];
      *(undefined1 *)(iVar5 + 0x2c) = 1;
      puVar2[10] = puVar2[10] | (byte)(1 << uVar4);
      if (param_1[1] == 1) {
        bVar6 = 0x40;
      }
      puVar2[0x14] = bVar6 | 0x20;
      if ((int)((uint)(byte)puVar2[0x15] << 0x1e) < 0) {
        uVar3 = 0x48;
      }
      else {
        uVar3 = 0x40;
      }
      puVar2[0x15] = uVar3;
      uVar3 = FUN_080126c4(*(undefined2 *)(param_1 + 2),&local_20);
      puVar2[0x16] = uVar3;
    }
    else {
      iVar5 = uVar4 * 0x14 + iVar1;
      *(undefined2 *)(iVar5 + 200) = *(undefined2 *)(param_1 + 2);
      *(byte *)(iVar5 + 0xca) = param_1[1];
      *(undefined1 *)(iVar5 + 0xcc) = 1;
      if (param_1[1] == 1) {
        bVar6 = 0x40;
      }
      puVar2[0x18] = bVar6;
      if ((puVar2[0x19] & 1) == 0) {
        uVar3 = 0x80;
      }
      else {
        uVar3 = 0x90;
      }
      puVar2[0x19] = uVar3;
      uVar3 = FUN_080126c4(*(undefined2 *)(param_1 + 2),&local_20);
      puVar2[0x1a] = uVar3;
    }
    *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + (local_20 & 0xffff);
    puVar2[0xe] = (char)local_1c;
  }
  return (ulonglong)local_20 << 0x20;
}



// ==== 08012a60  FUN_08012a60  (66 bytes, 3 xrefs)

undefined4 FUN_08012a60(uint param_1)

{
  undefined1 uVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar2 = PTR_USBD_08012aa4;
  uVar1 = PTR_USBD_08012aa4[0xe];
  uVar3 = param_1 & 0x7f;
  PTR_USBD_08012aa4[0xe] = (char)uVar3;
  if ((int)(param_1 * 0x1000000) < 0) {
    if (uVar3 != 0) {
      puVar2[0x15] = puVar2[0x15] | 0x10;
      goto LAB_08012a92;
    }
  }
  else if (uVar3 != 0) {
    puVar2[0x19] = puVar2[0x19] | 0x20;
    goto LAB_08012a92;
  }
  *DAT_08012aa8 = 7;
  puVar2[0x10] = puVar2[0x10] | 0x60;
LAB_08012a92:
  puVar2[0xe] = uVar1;
  return 0;
}



// ==== 08012aac  FUN_08012aac  (96 bytes, 5 xrefs)

undefined4 FUN_08012aac(uint param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_USBD_08012b10;
  param_1 = param_1 & 0x7f;
  if ((param_2 == 0) && (param_3 != 0)) {
    return 0xffffffff;
  }
  iVar3 = param_1 * 0x14 + DAT_08012b0c;
  if (*(char *)(iVar3 + 0xcc) == '\0') {
    return 0xfffffffe;
  }
  uVar1 = PTR_USBD_08012b10[0xe];
  PTR_USBD_08012b10[0xe] = (char)param_1;
  *(int *)(iVar3 + 0xd4) = param_3;
  *(int *)(iVar3 + 0xd0) = param_2;
  *(undefined4 *)(iVar3 + 0xd8) = 0;
  if (param_3 == 0) {
    if (param_1 == 0) {
      *DAT_08012b14 = 0;
    }
  }
  else if (param_1 == 0) {
    *DAT_08012b14 = 3;
  }
  else {
    puVar2[9] = puVar2[9] | (byte)(1 << param_1);
  }
  puVar2[0xe] = uVar1;
  return 0;
}



// ==== 08012b18  FUN_08012b18  (160 bytes, 5 xrefs)

undefined4 FUN_08012b18(uint param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined1 uVar5;
  int iVar6;
  char cVar7;
  
  puVar3 = PTR_USBD_08012bbc;
  iVar2 = DAT_08012bb8;
  param_1 = param_1 & 0x7f;
  if ((param_2 == 0) && (param_3 != 0)) {
    return 0xffffffff;
  }
  iVar6 = param_1 * 0x14 + DAT_08012bb8;
  if (*(char *)(iVar6 + 0x2c) == '\0') {
    return 0xfffffffe;
  }
  uVar1 = PTR_USBD_08012bbc[0xe];
  PTR_USBD_08012bbc[0xe] = (char)param_1;
  if ((puVar3[0x15] & 1) != 0) {
    puVar3[0xe] = uVar1;
    return 0xfffffffd;
  }
  *(undefined4 *)(iVar6 + 0x38) = 0;
  *(uint *)(iVar6 + 0x34) = param_3;
  *(int *)(iVar6 + 0x30) = param_2;
  pcVar4 = DAT_08012bc0;
  if (param_3 == 0) {
    if (param_1 == 0) {
      if (*(short *)(iVar2 + 0x26) == 0) {
        cVar7 = '\x04';
      }
      else {
        cVar7 = '\x06';
      }
      *DAT_08012bc0 = cVar7;
      if (*pcVar4 == '\x01') goto LAB_08012bb0;
LAB_08012bb4:
      uVar5 = 2;
      goto LAB_08012b9a;
    }
  }
  else {
    if (*(ushort *)(iVar6 + 0x28) <= param_3) {
      param_3 = (uint)*(ushort *)(iVar6 + 0x28);
    }
    FUN_08012704(param_1,param_2,param_3 & 0xffff,iVar2,param_4);
    if (param_1 == 0) {
      *DAT_08012bc0 = '\x01';
      if (*(ushort *)(DAT_08012bb8 + 0x28) <= param_3) goto LAB_08012bb4;
LAB_08012bb0:
      uVar5 = 10;
LAB_08012b9a:
      puVar3[0x10] = uVar5;
      goto LAB_08012b9c;
    }
  }
  puVar3[0x15] = 1;
LAB_08012b9c:
  puVar3[0xe] = uVar1;
  return 0;
}



// ==== 08012bc4  FUN_08012bc4  (150 bytes, 1 xrefs)

void FUN_08012bc4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar1 = DAT_08012c5c;
  FUN_08002968(DAT_08012c5c,param_1,8,param_4,param_4);
  pbVar2 = DAT_08012c5c;
  uVar4 = (uint)*(ushort *)(pbVar1 + 6);
  if ((0x100 < uVar4) && (-1 < (int)((uint)*pbVar1 << 0x18))) {
LAB_08012c52:
    FUN_08012a60(0x80);
    return;
  }
  pbVar5 = DAT_08012c5c + 0x1c;
  *(uint *)(DAT_08012c5c + 0xc) = uVar4;
  *(byte **)(pbVar2 + 8) = pbVar5;
  *(uint *)(pbVar2 + 0x10) = uVar4;
  pbVar2[0x14] = 0;
  if ((uVar4 == 0) || ((int)((uint)*pbVar1 << 0x18) < 0)) {
    iVar3 = FUN_08012e86(pbVar1,DAT_08012c5c + 8);
    if (iVar3 == 0) goto LAB_08012c52;
    uVar4 = *(uint *)(pbVar2 + 0x10);
    if ((uint)*(ushort *)(pbVar1 + 6) <= *(uint *)(pbVar2 + 0x10)) {
      uVar4 = (uint)*(ushort *)(pbVar1 + 6);
    }
    *(uint *)(pbVar2 + 0xc) = uVar4;
    if ((*(uint *)(pbVar2 + 8) & 3) != 0) {
      if (0x100 < uVar4) {
        return;
      }
      FUN_08002968(pbVar5);
      *(byte **)(pbVar2 + 8) = pbVar5;
    }
    FUN_08012b18(0x80,*(undefined4 *)(pbVar2 + 8),*(undefined4 *)(pbVar2 + 0xc));
    if ((*(uint *)(pbVar2 + 0x10) < (uint)*(ushort *)(pbVar1 + 6)) &&
       ((*(uint *)(pbVar2 + 0x10) & 0x3f) == 0)) {
      pbVar2[0x14] = 1;
      return;
    }
  }
  else {
    FUN_08012aac(0,pbVar5);
  }
  return;
}



// ==== 08012c60  FUN_08012c60  (94 bytes, 1 xrefs)

void FUN_08012c60(uint param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = DAT_08012cc0;
  if (param_1 != 0x80) {
    if (*(code **)(DAT_08012cc0 + (param_1 & 0x7f) * 4 + 0x11c) != (code *)0x0) {
      (**(code **)(DAT_08012cc0 + (param_1 & 0x7f) * 4 + 0x11c))();
    }
    return;
  }
  iVar2 = *(int *)(DAT_08012cc0 + 8) + param_2;
  *(int *)(DAT_08012cc0 + 8) = iVar2;
  param_2 = *(int *)(pcVar1 + 0xc) - param_2;
  *(int *)(pcVar1 + 0xc) = param_2;
  if (param_2 == 0) {
    if (pcVar1[0x14] != '\x01') {
      if (*(short *)(pcVar1 + 6) == 0) {
        return;
      }
      if (*pcVar1 < '\0') {
        FUN_08012aac(0,0);
        return;
      }
      return;
    }
    pcVar1[0x14] = '\0';
    param_2 = 0;
    iVar2 = 0;
  }
  FUN_08012b18(0x80,iVar2,param_2);
  return;
}



// ==== 08012cc4  FUN_08012cc4  (98 bytes, 1 xrefs)

void FUN_08012cc4(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  
  iVar2 = DAT_08012d28;
  if (param_1 == 0) {
    if (param_2 != 0) {
      iVar4 = *(int *)(DAT_08012d28 + 8) + param_2;
      *(int *)(DAT_08012d28 + 8) = iVar4;
      param_2 = *(int *)(iVar2 + 0xc) - param_2;
      *(int *)(iVar2 + 0xc) = param_2;
      iVar1 = DAT_08012d28;
      if (param_2 != 0) {
        FUN_08012aac(0,iVar4);
        return;
      }
      *(int *)(iVar2 + 8) = DAT_08012d28 + 0x1c;
      iVar2 = FUN_08012e86(iVar2,iVar1 + 8,iVar1 + 0x10);
      if (iVar2 == 0) {
        FUN_08012a60(0x80);
        return;
      }
      FUN_08012b18(0x80,0);
      return;
    }
  }
  else {
    pcVar3 = *(code **)((param_1 & 0x7f) * 4 + DAT_08012d28 + 0x13c);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)();
    }
  }
  return;
}



// ==== 08012d2c  FUN_08012d2c  (54 bytes, 1 xrefs)

void FUN_08012d2c(void)

{
  int iVar1;
  uint in_r3;
  uint local_10;
  
  local_10 = in_r3;
  FUN_08012e38(0);
  iVar1 = DAT_08012d64;
  *(undefined1 *)(DAT_08012d64 + 0x1c) = 0;
  *(undefined1 *)(iVar1 + 0x1d) = 0;
  local_10 = 0x400080;
  FUN_0801298c(&local_10);
  local_10 = local_10 & 0xffffff00;
  FUN_0801298c(&local_10);
  FUN_08012850(1,0);
  return;
}



// ==== 08012d68  FUN_08012d68  (140 bytes, 0 xrefs)

undefined4 FUN_08012d68(uint param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 *puVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = param_1 >> 8;
  if (uVar3 == 3) {
    if ((param_1 & 0xff) == 0xee) {
      puVar1 = *(undefined4 **)(DAT_08012df4 + 4);
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      *param_2 = *puVar1;
      uVar3 = (uint)*(byte *)(puVar1 + 1);
      goto LAB_08012db6;
    }
  }
  else {
    if (uVar3 == 0xf) {
      puVar1 = *(undefined4 **)(DAT_08012df4 + 0xc);
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      *param_2 = *puVar1;
      uVar3 = puVar1[1];
LAB_08012db6:
      *param_3 = uVar3;
      return 1;
    }
    if (((uVar3 == 4) || (uVar3 == 5)) || (5 < uVar3)) {
      return 0;
    }
  }
  pbVar2 = *(byte **)(DAT_08012df8 + 0x18);
  do {
    if (*pbVar2 == 0) {
      return 0;
    }
    if (pbVar2[1] == uVar3) {
      if (uVar4 == (param_1 & 0xff)) {
        *param_2 = pbVar2;
        if ((uVar3 == 2) || (uVar3 == 7)) {
          uVar3 = (uint)*(ushort *)(pbVar2 + 2);
        }
        else {
          uVar3 = (uint)*pbVar2;
        }
        *param_3 = uVar3;
        return 1;
      }
      uVar4 = uVar4 + 1;
    }
    pbVar2 = pbVar2 + *pbVar2;
  } while( true );
}



// ==== 08012dfc  FUN_08012dfc  (8 bytes, 1 xrefs)

void FUN_08012dfc(void)

{
  FUN_08012724();
  return;
}



// ==== 08012e04  FUN_08012e04  (50 bytes, 2 xrefs)

undefined4 FUN_08012e04(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_08012954(*(undefined1 *)(param_1 + 2));
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}



// ==== 08012e38  FUN_08012e38  (18 bytes, 1 xrefs)

undefined4 FUN_08012e38(int param_1)

{
  if (param_1 == 0) {
    *PTR_USBD_08012e4c = 0;
  }
  *DAT_08012e50 = (char)param_1;
  return 0;
}



// ==== 08012e54  FUN_08012e54  (50 bytes, 2 xrefs)

undefined4 FUN_08012e54(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  local_8._0_2_ = (ushort)*(byte *)(param_1 + 2);
  local_8 = CONCAT22(*(undefined2 *)(param_1 + 4),(ushort)local_8) & 0x7ffffff;
  local_8 = CONCAT22(local_8._2_2_,CONCAT11(*(undefined1 *)(param_1 + 3),(undefined1)local_8)) &
            0xffff03ff;
  iVar1 = FUN_0801298c(&local_8);
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}



// ==== 08012e86  FUN_08012e86  (82 bytes, 2 xrefs)

undefined4 FUN_08012e86(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_1;
  if ((bVar1 & 0x60) == 0) {
    if ((bVar1 & 3) == 0) {
      iVar2 = FUN_08012ed8();
    }
    else if ((bVar1 & 3) == 1) {
      iVar2 = FUN_0801303c();
    }
    else {
      if ((bVar1 & 3) != 2) {
        return 0;
      }
      iVar2 = FUN_08012fbc();
    }
    if (iVar2 != 0) {
      return 1;
    }
  }
  else {
    if ((bVar1 & 0x60) == 0x20) {
      iVar2 = FUN_08012874();
    }
    else {
      if ((bVar1 & 0x60) != 0x40) {
        return 0;
      }
      iVar2 = switchD_08013068::caseD_68();
    }
    if (-1 < iVar2) {
      return 1;
    }
  }
  return 0;
}



// ==== 08012ed8  FUN_08012ed8  (28 bytes, 1 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x08012f18

// ==== 08012fbc  FUN_08012fbc  (126 bytes, 1 xrefs)

undefined4 FUN_08012fbc(int param_1,int *param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_24 [4];
  int iStack_20;
  int *local_1c;
  undefined4 *puStack_18;
  
  uVar1 = *(undefined1 *)(param_1 + 4);
  uVar4 = 1;
  iStack_20 = param_1;
  local_1c = param_2;
  puStack_18 = param_3;
  iVar3 = FUN_080124f8();
  if (iVar3 == 0) {
    return 0;
  }
  cVar2 = *(char *)(param_1 + 1);
  if (cVar2 == '\0') {
    FUN_08012958(uVar1,local_24);
    *(undefined1 *)*local_1c = local_24[0];
    *(undefined1 *)(*local_1c + 1) = 0;
    *param_3 = 2;
    return 1;
  }
  if (cVar2 == '\x01') {
    if (*(short *)(param_1 + 2) == 0) {
      FUN_08012904(uVar1);
      return 1;
    }
  }
  else {
    if (cVar2 != '\x03') {
      return 0;
    }
    if (*(short *)(param_1 + 2) == 0) {
      FUN_08012a60(uVar1);
      goto LAB_08013036;
    }
  }
  uVar4 = 0;
LAB_08013036:
  *param_3 = 0;
  return uVar4;
}



// ==== 0801303c  FUN_0801303c  (448 bytes, 1 xrefs)

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x08013068) */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x08013116) overlaps instruction at (ram,0x08013114)
    */
/* WARNING: Removing unreachable block (ram,0x08013068) */

code * FUN_0801303c(code *param_1,code *param_2,code *param_3)

{
  code cVar1;
  code cVar2;
  code *pcVar3;
  code *pcVar4;
  code *pcVar5;
  code *extraout_r2;
  code *pcVar6;
  code *pcVar7;
  code *pcVar8;
  bool bVar9;
  bool bVar10;
  undefined4 in_cr1;
  undefined4 in_cr9;
  undefined4 in_cr14;
  undefined8 extraout_d7;
  undefined8 unaff_d14;
  undefined8 in_d16;
  undefined8 uVar11;
  code *local_30;
  code *local_2c;
  code *local_28;
  
  pcVar3 = (code *)(uint)(byte)param_1[3];
  pcVar8 = (code *)(uint)(byte)param_1[4];
  local_30 = (code *)0x1;
  uVar11 = FUN_080124f8();
  pcVar5 = (code *)((ulonglong)uVar11 >> 0x20);
  pcVar4 = (code *)0x0;
  if ((int)uVar11 == 0) goto switchD_08013068_caseD_1b;
  cVar2 = param_1[1];
  pcVar4 = (code *)(uint)(byte)cVar2;
  bVar10 = pcVar4 == (code *)0x0;
  bVar9 = false;
  if (pcVar4 < &HardFault) {
    cVar1 = pcVar4[0x801306d];
  }
  else {
    cVar1 = (code)0x20;
  }
  pcVar7 = (code *)((uint)(byte)cVar1 * 2);
  pcVar6 = extraout_r2;
  switch(cVar1) {
  case (code)0x0:
  case (code)0x1:
switchD_08013068_caseD_2:
switchD_08013068_caseD_3:
switchD_08013068_caseD_4:
switchD_08013068_caseD_5:
switchD_08013068_caseD_6:
switchD_08013068_caseD_7:
    pcVar5 = *(code **)param_2;
switchD_08013068_caseD_8:
    cVar2 = (code)0x0;
switchD_08013068_caseD_9:
    *pcVar5 = cVar2;
switchD_08013068_caseD_a:
    pcVar5 = *(code **)param_2;
switchD_08013068_caseD_b:
    pcVar5[1] = cVar2;
switchD_08013068_caseD_c:
    pcVar5 = (code *)0x2;
switchD_08013068_caseD_d:
switchD_08013068_caseD_27:
    pcVar4 = param_3;
switchD_08013068_caseD_28:
    *(code **)pcVar4 = pcVar5;
switchD_08013068_caseD_29:
switchD_08013068_caseD_62:
    pcVar4 = local_30;
switchD_08013068_caseD_63:
    break;
  case (code)0x2:
    goto switchD_08013068_caseD_2;
  case (code)0x3:
    goto switchD_08013068_caseD_3;
  case (code)0x4:
    goto switchD_08013068_caseD_4;
  case (code)0x5:
    goto switchD_08013068_caseD_5;
  case (code)0x6:
    goto switchD_08013068_caseD_6;
  case (code)0x7:
    goto switchD_08013068_caseD_7;
  case (code)0x8:
    goto switchD_08013068_caseD_8;
  case (code)0x9:
    goto switchD_08013068_caseD_9;
  case (code)0xa:
    goto switchD_08013068_caseD_a;
  case (code)0xb:
    goto switchD_08013068_caseD_b;
  case (code)0xc:
    goto switchD_08013068_caseD_c;
  case (code)0xd:
    goto switchD_08013068_caseD_d;
  case (code)0xe:
    bVar10 = pcVar3 == (code *)0x22;
  case (code)0xf:
    if (!bVar10) {
switchD_08013068_caseD_20:
      pcVar4 = (code *)0x0;
switchD_08013068_caseD_21:
      local_30 = pcVar4;
switchD_08013068_caseD_22:
      goto switchD_08013068_caseD_62;
    }
switchD_08013068_caseD_10:
    pcVar4 = (code *)&DAT_20000184;
switchD_08013068_caseD_11:
switchD_08013068_caseD_1d:
    do {
      pcVar4 = *(code **)pcVar4;
switchD_08013068_caseD_1e:
      bVar10 = pcVar4 == (code *)0x0;
switchD_08013068_caseD_1f:
      if (bVar10) goto switchD_08013068_caseD_20;
switchD_08013068_caseD_12:
      pcVar5 = (code *)(uint)(byte)pcVar4[0x1c];
switchD_08013068_caseD_13:
      bVar10 = pcVar5 == pcVar8;
switchD_08013068_caseD_14:
    } while (!bVar10);
switchD_08013068_caseD_15:
    pcVar5 = *(code **)(pcVar4 + 0x14);
switchD_08013068_caseD_16:
    *(code **)param_2 = pcVar5;
switchD_08013068_caseD_17:
    pcVar5 = *(code **)(pcVar4 + 0x18);
switchD_08013068_caseD_18:
    pcVar4 = param_3;
switchD_08013068_caseD_19:
    *(code **)pcVar4 = pcVar5;
switchD_08013068_caseD_1a:
    pcVar4 = (code *)0x1;
    break;
  case (code)0x10:
    goto switchD_08013068_caseD_10;
  case (code)0x11:
    goto switchD_08013068_caseD_11;
  case (code)0x12:
    goto switchD_08013068_caseD_12;
  case (code)0x13:
    goto switchD_08013068_caseD_13;
  case (code)0x14:
    goto switchD_08013068_caseD_14;
  case (code)0x15:
    goto switchD_08013068_caseD_15;
  case (code)0x16:
    goto switchD_08013068_caseD_16;
  case (code)0x17:
    goto switchD_08013068_caseD_17;
  case (code)0x18:
    goto switchD_08013068_caseD_18;
  case (code)0x19:
    goto switchD_08013068_caseD_19;
  case (code)0x1a:
    goto switchD_08013068_caseD_1a;
  case (code)0x1b:
    break;
  case (code)0x1c:
    goto switchD_08013068_caseD_1c;
  case (code)0x1d:
    goto switchD_08013068_caseD_1d;
  case (code)0x1e:
    goto switchD_08013068_caseD_1e;
  case (code)0x1f:
    goto switchD_08013068_caseD_1f;
  case (code)0x20:
    goto switchD_08013068_caseD_20;
  case (code)0x21:
    goto switchD_08013068_caseD_21;
  case (code)0x22:
    goto switchD_08013068_caseD_22;
  case (code)0x23:
    pcVar5 = *(code **)param_2;
  case (code)0x24:
    cVar2 = (code)0x0;
switchD_08013068_caseD_25:
    *pcVar5 = cVar2;
switchD_08013068_caseD_26:
    pcVar5 = (code *)0x1;
    goto switchD_08013068_caseD_27;
  case (code)0x25:
    goto switchD_08013068_caseD_25;
  case (code)0x26:
    goto switchD_08013068_caseD_26;
  case (code)0x27:
    goto switchD_08013068_caseD_27;
  case (code)0x28:
    goto switchD_08013068_caseD_28;
  case (code)0x29:
    goto switchD_08013068_caseD_29;
  case (code)0x2a:
  case (code)0x2b:
    pcVar5 = (code *)(uint)(byte)param_1[4];
switchD_08013068_caseD_2c:
    cVar2 = (code)0x0;
switchD_08013068_caseD_2d:
    cVar2 = (code)((byte)cVar2 | (byte)pcVar5);
switchD_08013068_caseD_2e:
    pcVar4 = (code *)(uint)(byte)cVar2;
switchD_08013068_caseD_2f:
    local_28 = pcVar4;
switchD_08013068_caseD_30:
switchD_08013068_caseD_31:
    pcVar5 = (code *)(uint)(byte)param_1[2];
switchD_08013068_caseD_32:
    cVar2 = (code)0x0;
switchD_08013068_caseD_33:
    cVar2 = (code)((byte)cVar2 | (byte)pcVar5);
switchD_08013068_caseD_34:
    pcVar3 = (code *)(uint)(byte)cVar2;
switchD_08013068_caseD_35:
    pcVar4 = (code *)&DAT_2000019c;
switchD_08013068_caseD_36:
    param_1 = *(code **)(pcVar4 + 0x18);
switchD_08013068_caseD_37:
    pcVar4 = (code *)0x0;
switchD_08013068_caseD_38:
    pcVar8 = (code *)0xff;
switchD_08013068_caseD_39:
    param_2 = pcVar8;
    pcVar8 = param_2;
switchD_08013068_caseD_3a:
    local_2c = pcVar4;
switchD_08013068_caseD_3b:
switchD_08013068_caseD_58:
    while( true ) {
      pcVar4 = (code *)(uint)(byte)*param_1;
switchD_08013068_caseD_59:
      bVar10 = pcVar4 == (code *)0x0;
switchD_08013068_caseD_5a:
      if (bVar10) break;
switchD_08013068_caseD_3c:
      pcVar4 = (code *)(uint)(byte)param_1[1];
switchD_08013068_caseD_3d:
      bVar10 = pcVar4 == (code *)&Reset;
switchD_08013068_caseD_3e:
      if (bVar10) {
switchD_08013068_caseD_42:
        param_2 = (code *)(uint)(byte)param_1[2];
switchD_08013068_caseD_43:
        pcVar4 = local_28;
switchD_08013068_caseD_44:
        pcVar8 = (code *)(uint)(byte)param_1[3];
switchD_08013068_caseD_45:
        bVar10 = param_2 == pcVar4;
switchD_08013068_caseD_46:
        if (bVar10) {
switchD_08013068_caseD_47:
          bVar10 = pcVar8 == pcVar3;
switchD_08013068_caseD_48:
          if (bVar10) {
switchD_08013068_caseD_49:
            local_2c = param_1;
switchD_08013068_caseD_4a:
          }
        }
      }
      else {
switchD_08013068_caseD_3f:
        bVar10 = pcVar4 == (code *)0x5;
switchD_08013068_caseD_40:
        if (bVar10) {
switchD_08013068_caseD_41:
switchD_08013068_caseD_4b:
          pcVar4 = local_28;
switchD_08013068_caseD_4c:
          bVar10 = param_2 == pcVar4;
switchD_08013068_caseD_4d:
          if (bVar10) {
switchD_08013068_caseD_4e:
            pcVar4 = param_1;
            param_1 = pcVar4;
switchD_08013068_caseD_4f:
            bVar10 = pcVar8 == pcVar3;
switchD_08013068_caseD_50:
            if (bVar10) {
switchD_08013068_caseD_54:
              FUN_08012e54(pcVar4);
            }
            else {
switchD_08013068_caseD_51:
              FUN_08012e04();
switchD_08013068_caseD_53:
            }
          }
        }
      }
switchD_08013068_caseD_56:
      pcVar4 = (code *)(uint)(byte)*param_1;
switchD_08013068_caseD_57:
      param_1 = pcVar4 + (int)param_1;
    }
switchD_08013068_caseD_5b:
    pcVar4 = (code *)&NMI;
switchD_08013068_caseD_5c:
    pcVar5 = local_2c;
switchD_08013068_caseD_5d:
    FUN_08012850(pcVar4,pcVar5);
switchD_08013068_caseD_5f:
    pcVar5 = param_3;
switchD_08013068_caseD_60:
    pcVar4 = (code *)0x0;
switchD_08013068_caseD_61:
    *(code **)pcVar5 = pcVar4;
    goto switchD_08013068_caseD_62;
  case (code)0x2c:
    goto switchD_08013068_caseD_2c;
  case (code)0x2d:
    goto switchD_08013068_caseD_2d;
  case (code)0x2e:
    goto switchD_08013068_caseD_2e;
  case (code)0x2f:
    goto switchD_08013068_caseD_2f;
  case (code)0x30:
    goto switchD_08013068_caseD_30;
  case (code)0x31:
    goto switchD_08013068_caseD_31;
  case (code)0x32:
    goto switchD_08013068_caseD_32;
  case (code)0x33:
    goto switchD_08013068_caseD_33;
  case (code)0x34:
    goto switchD_08013068_caseD_34;
  case (code)0x35:
    goto switchD_08013068_caseD_35;
  case (code)0x36:
    goto switchD_08013068_caseD_36;
  case (code)0x37:
    goto switchD_08013068_caseD_37;
  case (code)0x38:
    goto switchD_08013068_caseD_38;
  case (code)0x39:
    goto switchD_08013068_caseD_39;
  case (code)0x3a:
    goto switchD_08013068_caseD_3a;
  case (code)0x3b:
    goto switchD_08013068_caseD_3b;
  case (code)0x3c:
    goto switchD_08013068_caseD_3c;
  case (code)0x3d:
    goto switchD_08013068_caseD_3d;
  case (code)0x3e:
    goto switchD_08013068_caseD_3e;
  case (code)0x3f:
    goto switchD_08013068_caseD_3f;
  case (code)0x40:
    goto switchD_08013068_caseD_40;
  case (code)0x41:
    goto switchD_08013068_caseD_41;
  case (code)0x42:
    goto switchD_08013068_caseD_42;
  case (code)0x43:
    goto switchD_08013068_caseD_43;
  case (code)0x44:
    goto switchD_08013068_caseD_44;
  case (code)0x45:
    goto switchD_08013068_caseD_45;
  case (code)0x46:
    goto switchD_08013068_caseD_46;
  case (code)0x47:
    goto switchD_08013068_caseD_47;
  case (code)0x48:
    goto switchD_08013068_caseD_48;
  case (code)0x49:
    goto switchD_08013068_caseD_49;
  case (code)0x4a:
    goto switchD_08013068_caseD_4a;
  case (code)0x4b:
    goto switchD_08013068_caseD_4b;
  case (code)0x4c:
    goto switchD_08013068_caseD_4c;
  case (code)0x4d:
    goto switchD_08013068_caseD_4d;
  case (code)0x4e:
    goto switchD_08013068_caseD_4e;
  case (code)0x4f:
    goto switchD_08013068_caseD_4f;
  case (code)0x50:
    goto switchD_08013068_caseD_50;
  case (code)0x51:
    goto switchD_08013068_caseD_51;
  case (code)0x52:
    coprocessor_function2(0,7,0,in_cr14,in_cr9,in_cr1);
    goto switchD_08013068_caseD_54;
  case (code)0x53:
    goto switchD_08013068_caseD_53;
  case (code)0x54:
    goto switchD_08013068_caseD_54;
  case (code)0x55:
    VectorComplexMultiplyAccumulateByElement(extraout_d7,unaff_d14,in_d16,0x5a,4);
    goto switchD_08013068_caseD_57;
  case (code)0x56:
    goto switchD_08013068_caseD_56;
  case (code)0x57:
    goto switchD_08013068_caseD_57;
  case (code)0x58:
    goto switchD_08013068_caseD_58;
  case (code)0x59:
    goto switchD_08013068_caseD_59;
  case (code)0x5a:
    goto switchD_08013068_caseD_5a;
  case (code)0x5b:
    goto switchD_08013068_caseD_5b;
  case (code)0x5c:
    goto switchD_08013068_caseD_5c;
  case (code)0x5d:
    goto switchD_08013068_caseD_5d;
  case (code)0x5e:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (code)0x5f:
    goto switchD_08013068_caseD_5f;
  case (code)0x60:
    goto switchD_08013068_caseD_60;
  case (code)0x61:
    goto switchD_08013068_caseD_61;
  case (code)0x62:
    goto switchD_08013068_caseD_62;
  case (code)0x63:
    goto switchD_08013068_caseD_63;
  case (code)0x64:
  case (code)0x65:
switchD_08013068_caseD_66:
switchD_08013068_caseD_67:
    pcVar4 = (code *)0x0;
switchD_08013068_caseD_68:
switchD_08013068_caseD_69:
    pcVar3 = pcVar5;
switchD_08013068_caseD_6a:
    pcVar5 = (code *)&DAT_20000184;
switchD_08013068_caseD_6b:
    param_2 = pcVar4;
switchD_08013068_caseD_6c:
    pcVar4 = *(code **)(pcVar5 + 4);
switchD_08013068_caseD_6d:
    pcVar8 = extraout_r2;
switchD_08013068_caseD_6e:
    bVar10 = pcVar4 == (code *)0x0;
switchD_08013068_caseD_6f:
    if (bVar10) {
switchD_08013068_caseD_85:
      pcVar4 = *(code **)(pcVar5 + 8);
switchD_08013068_caseD_86:
      bVar10 = pcVar4 == (code *)0x0;
switchD_08013068_caseD_87:
      if (!bVar10) {
switchD_08013068_caseD_88:
        pcVar5 = (code *)(uint)(byte)param_2[1];
switchD_08013068_caseD_89:
        pcVar6 = (code *)(uint)(byte)pcVar4[6];
switchD_08013068_caseD_8a:
        bVar10 = pcVar5 == pcVar6;
switchD_08013068_caseD_8b:
        if (bVar10) {
switchD_08013068_caseD_8c:
          pcVar5 = (code *)(uint)(byte)param_2[5];
switchD_08013068_caseD_8d:
          pcVar6 = (code *)(uint)(byte)param_2[4];
switchD_08013068_caseD_8e:
          pcVar5 = (code *)((int)pcVar5 << 8);
switchD_08013068_caseD_8f:
          pcVar5 = (code *)((uint)pcVar5 | (uint)pcVar6);
switchD_08013068_caseD_90:
          bVar10 = pcVar5 == (code *)0x7;
switchD_08013068_caseD_91:
          if (!bVar10) goto switchD_08013068_caseD_a7;
switchD_08013068_caseD_92:
          pcVar5 = *(code **)pcVar4;
switchD_08013068_caseD_93:
          *(code **)pcVar3 = pcVar5;
switchD_08013068_caseD_94:
          pcVar4 = (code *)(uint)*(ushort *)(pcVar4 + 4);
          goto switchD_08013068_caseD_95;
        }
      }
switchD_08013068_caseD_98:
      pcVar4 = (code *)&DAT_20000184;
switchD_08013068_caseD_99:
      param_1 = *(code **)pcVar4;
switchD_08013068_caseD_9a:
switchD_08013068_caseD_a5:
      while( true ) {
        bVar10 = param_1 == (code *)0x0;
switchD_08013068_caseD_a6:
        if (bVar10) break;
switchD_08013068_caseD_9b:
        pcVar7 = *(code **)(param_1 + 0xc);
switchD_08013068_caseD_9c:
        bVar10 = pcVar7 == (code *)0x0;
switchD_08013068_caseD_9d:
        if (!bVar10) {
switchD_08013068_caseD_9e:
switchD_08013068_caseD_9f:
          pcVar5 = pcVar3;
          pcVar3 = pcVar5;
switchD_08013068_caseD_a0:
          pcVar4 = param_2;
          param_2 = pcVar4;
switchD_08013068_caseD_a1:
          pcVar4 = (code *)(*pcVar7)(pcVar4,pcVar5);
switchD_08013068_caseD_a2:
          bVar10 = pcVar4 == (code *)0x0;
switchD_08013068_caseD_a3:
          if (bVar10) {
            return pcVar4;
          }
        }
switchD_08013068_caseD_a4:
        param_1 = *(code **)param_1;
      }
    }
    else {
switchD_08013068_caseD_70:
      pcVar5 = (code *)(uint)(byte)param_2[1];
switchD_08013068_caseD_71:
      pcVar6 = (code *)(uint)(byte)pcVar4[5];
switchD_08013068_caseD_72:
      bVar10 = pcVar5 == pcVar6;
switchD_08013068_caseD_73:
      if (!bVar10) goto switchD_08013068_caseD_98;
switchD_08013068_caseD_74:
      pcVar5 = (code *)(uint)(byte)param_2[5];
switchD_08013068_caseD_75:
      pcVar6 = (code *)(uint)(byte)param_2[4];
switchD_08013068_caseD_76:
      pcVar5 = (code *)((int)pcVar5 << 8);
switchD_08013068_caseD_77:
      pcVar5 = (code *)((uint)pcVar5 | (uint)pcVar6);
switchD_08013068_caseD_78:
      bVar10 = pcVar5 == (code *)&Reset;
switchD_08013068_caseD_79:
      if (bVar10) {
switchD_08013068_caseD_7d:
        pcVar5 = *(code **)(pcVar4 + 8);
switchD_08013068_caseD_7e:
        *(code **)pcVar3 = pcVar5;
switchD_08013068_caseD_7f:
        pcVar4 = (code *)(uint)*(ushort *)(pcVar4 + 0xc);
switchD_08013068_caseD_80:
switchD_08013068_caseD_95:
        *(code **)pcVar8 = pcVar4;
switchD_08013068_caseD_96:
        pcVar4 = (code *)0x0;
switchD_08013068_caseD_97:
        return pcVar4;
      }
switchD_08013068_caseD_7a:
      bVar10 = pcVar5 == (code *)0x5;
switchD_08013068_caseD_7b:
      if (bVar10) {
switchD_08013068_caseD_7c:
switchD_08013068_caseD_81:
        pcVar5 = *(code **)(pcVar4 + 0x10);
switchD_08013068_caseD_82:
        *(code **)pcVar3 = pcVar5;
switchD_08013068_caseD_83:
        pcVar4 = (code *)(uint)*(ushort *)(pcVar4 + 0x14);
switchD_08013068_caseD_84:
        goto switchD_08013068_caseD_95;
      }
    }
switchD_08013068_caseD_a7:
    pcVar4 = (code *)0x0;
switchD_08013068_caseD_a8:
    pcVar4 = (code *)~(uint)pcVar4;
switchD_08013068_caseD_a9:
    return pcVar4;
  case (code)0x66:
    goto switchD_08013068_caseD_66;
  case (code)0x67:
    goto switchD_08013068_caseD_67;
  case (code)0x68:
    goto switchD_08013068_caseD_68;
  case (code)0x69:
    goto switchD_08013068_caseD_69;
  case (code)0x6a:
    goto switchD_08013068_caseD_6a;
  case (code)0x6b:
    goto switchD_08013068_caseD_6b;
  case (code)0x6c:
    goto switchD_08013068_caseD_6c;
  case (code)0x6d:
    goto switchD_08013068_caseD_6d;
  case (code)0x6e:
    goto switchD_08013068_caseD_6e;
  case (code)0x6f:
    goto switchD_08013068_caseD_6f;
  case (code)0x70:
    goto switchD_08013068_caseD_70;
  case (code)0x71:
    goto switchD_08013068_caseD_71;
  case (code)0x72:
    goto switchD_08013068_caseD_72;
  case (code)0x73:
    goto switchD_08013068_caseD_73;
  case (code)0x74:
    goto switchD_08013068_caseD_74;
  case (code)0x75:
    goto switchD_08013068_caseD_75;
  case (code)0x76:
    goto switchD_08013068_caseD_76;
  case (code)0x77:
    goto switchD_08013068_caseD_77;
  case (code)0x78:
    goto switchD_08013068_caseD_78;
  case (code)0x79:
    goto switchD_08013068_caseD_79;
  case (code)0x7a:
    goto switchD_08013068_caseD_7a;
  case (code)0x7b:
    goto switchD_08013068_caseD_7b;
  case (code)0x7c:
    goto switchD_08013068_caseD_7c;
  case (code)0x7d:
    goto switchD_08013068_caseD_7d;
  case (code)0x7e:
    goto switchD_08013068_caseD_7e;
  case (code)0x7f:
    goto switchD_08013068_caseD_7f;
  case (code)0x80:
    goto switchD_08013068_caseD_80;
  case (code)0x81:
    goto switchD_08013068_caseD_81;
  case (code)0x82:
    goto switchD_08013068_caseD_82;
  case (code)0x83:
    goto switchD_08013068_caseD_83;
  case (code)0x84:
    goto switchD_08013068_caseD_84;
  case (code)0x85:
    goto switchD_08013068_caseD_85;
  case (code)0x86:
    goto switchD_08013068_caseD_86;
  case (code)0x87:
    goto switchD_08013068_caseD_87;
  case (code)0x88:
    goto switchD_08013068_caseD_88;
  case (code)0x89:
    goto switchD_08013068_caseD_89;
  case (code)0x8a:
    goto switchD_08013068_caseD_8a;
  case (code)0x8b:
    goto switchD_08013068_caseD_8b;
  case (code)0x8c:
    goto switchD_08013068_caseD_8c;
  case (code)0x8d:
    goto switchD_08013068_caseD_8d;
  case (code)0x8e:
    goto switchD_08013068_caseD_8e;
  case (code)0x8f:
    goto switchD_08013068_caseD_8f;
  case (code)0x90:
    goto switchD_08013068_caseD_90;
  case (code)0x91:
    goto switchD_08013068_caseD_91;
  case (code)0x92:
    goto switchD_08013068_caseD_92;
  case (code)0x93:
    goto switchD_08013068_caseD_93;
  case (code)0x94:
    goto switchD_08013068_caseD_94;
  case (code)0x95:
    goto switchD_08013068_caseD_95;
  case (code)0x96:
    goto switchD_08013068_caseD_96;
  case (code)0x97:
    goto switchD_08013068_caseD_97;
  case (code)0x98:
    goto switchD_08013068_caseD_98;
  case (code)0x99:
    goto switchD_08013068_caseD_99;
  case (code)0x9a:
    goto switchD_08013068_caseD_9a;
  case (code)0x9b:
    goto switchD_08013068_caseD_9b;
  case (code)0x9c:
    goto switchD_08013068_caseD_9c;
  case (code)0x9d:
    goto switchD_08013068_caseD_9d;
  case (code)0x9e:
    goto switchD_08013068_caseD_9e;
  case (code)0x9f:
    goto switchD_08013068_caseD_9f;
  case (code)0xa0:
    goto switchD_08013068_caseD_a0;
  case (code)0xa1:
    goto switchD_08013068_caseD_a1;
  case (code)0xa2:
    goto switchD_08013068_caseD_a2;
  case (code)0xa3:
    goto switchD_08013068_caseD_a3;
  case (code)0xa4:
    goto switchD_08013068_caseD_a4;
  case (code)0xa5:
    goto switchD_08013068_caseD_a5;
  case (code)0xa6:
    goto switchD_08013068_caseD_a6;
  case (code)0xa7:
    goto switchD_08013068_caseD_a7;
  case (code)0xa8:
    goto switchD_08013068_caseD_a8;
  case (code)0xa9:
    goto switchD_08013068_caseD_a9;
  case (code)0xaa:
  case (code)0xab:
    pcVar4 = (code *)0x0;
switchD_08013068_caseD_ac:
    pcVar5 = (code *)((int)pcVar4 << 0x18);
switchD_08013068_caseD_ad:
    cVar2 = SUB41((int)pcVar4 << 1,0);
switchD_08013068_caseD_ae:
    bVar9 = (int)pcVar5 < 0;
switchD_08013068_caseD_af:
    if (bVar9) {
switchD_08013068_caseD_b0:
      pcVar5 = (code *)0x1b;
switchD_08013068_caseD_b1:
      cVar2 = (code)((byte)cVar2 ^ (byte)pcVar5);
    }
switchD_08013068_caseD_b2:
    pcVar4 = (code *)(uint)(byte)cVar2;
switchD_08013068_caseD_b3:
    return pcVar4;
  case (code)0xac:
    goto switchD_08013068_caseD_ac;
  case (code)0xad:
    goto switchD_08013068_caseD_ad;
  case (code)0xae:
    goto switchD_08013068_caseD_ae;
  case (code)0xaf:
    goto switchD_08013068_caseD_af;
  case (code)0xb0:
    goto switchD_08013068_caseD_b0;
  case (code)0xb1:
    goto switchD_08013068_caseD_b1;
  case (code)0xb2:
    goto switchD_08013068_caseD_b2;
  case (code)0xb3:
    goto switchD_08013068_caseD_b3;
  case (code)0xb4:
  case (code)0xb5:
switchD_08013068_caseD_b6:
switchD_08013068_caseD_b7:
switchD_08013068_caseD_b8:
switchD_08013068_caseD_b9:
switchD_08013068_caseD_ba:
switchD_08013068_caseD_bb:
switchD_08013068_caseD_bc:
switchD_08013068_caseD_bd:
switchD_08013068_caseD_be:
switchD_08013068_caseD_bf:
switchD_08013068_caseD_c0:
switchD_08013068_caseD_c1:
switchD_08013068_caseD_c2:
switchD_08013068_caseD_c3:
switchD_08013068_caseD_c4:
    pcVar5 = pcVar4;
switchD_08013068_caseD_c5:
switchD_08013068_caseD_c6:
switchD_08013068_caseD_c7:
switchD_08013068_caseD_c8:
switchD_08013068_caseD_c9:
switchD_08013068_caseD_ca:
switchD_08013068_caseD_cb:
switchD_08013068_caseD_cc:
switchD_08013068_caseD_cd:
switchD_08013068_caseD_ce:
switchD_08013068_caseD_cf:
switchD_08013068_caseD_d0:
    pcVar4 = pcVar5;
switchD_08013068_caseD_d1:
switchD_08013068_caseD_d2:
switchD_08013068_caseD_d3:
switchD_08013068_caseD_d4:
    pcVar4 = (code *)((uint)pcVar4 >> 4);
switchD_08013068_caseD_d5:
switchD_08013068_caseD_d6:
    pcVar4 = (code *)((int)pcVar4 >> 8);
switchD_08013068_caseD_d7:
switchD_08013068_caseD_d8:
switchD_08013068_caseD_d9:
switchD_08013068_caseD_da:
    *(short *)(pcVar4 + 0x32) = (short)pcVar4;
switchD_08013068_caseD_db:
switchD_08013068_caseD_dc:
switchD_08013068_caseD_dd:
switchD_08013068_caseD_de:
    pcVar4 = (code *)((uint)pcVar4 >> 4);
switchD_08013068_caseD_df:
switchD_08013068_caseD_e0:
    pcVar4 = (code *)((uint)pcVar4 >> 4);
switchD_08013068_caseD_e1:
switchD_08013068_caseD_e2:
    pcVar4 = (code *)((uint)pcVar4 >> 4);
switchD_08013068_caseD_e3:
switchD_08013068_caseD_e4:
switchD_08013068_caseD_e5:
switchD_08013068_caseD_e6:
switchD_08013068_caseD_e7:
switchD_08013068_caseD_e8:
switchD_08013068_caseD_e9:
switchD_08013068_caseD_ea:
switchD_08013068_caseD_eb:
switchD_08013068_caseD_ec:
switchD_08013068_caseD_ed:
switchD_08013068_caseD_ee:
    pcVar6 = pcVar4;
switchD_08013068_caseD_ef:
switchD_08013068_caseD_f0:
    pcVar7 = pcVar4;
switchD_08013068_caseD_f1:
switchD_08013068_caseD_f2:
    param_1 = pcVar4;
switchD_08013068_caseD_f3:
switchD_08013068_caseD_f4:
switchD_08013068_caseD_f5:
switchD_08013068_caseD_f6:
switchD_08013068_caseD_f7:
switchD_08013068_caseD_f8:
switchD_08013068_caseD_f9:
    pcVar3 = (code *)((uint)pcVar7 >> 8);
switchD_08013068_caseD_fa:
switchD_08013068_caseD_fb:
    pcVar3 = (code *)((int)pcVar3 << 0xb);
switchD_08013068_caseD_fc:
    pcVar5 = (code *)(uint)*(ushort *)(pcVar6 + (int)param_1);
switchD_08013068_caseD_fd:
switchD_08013068_caseD_fe:
switchD_08013068_caseD_ff:
    *(code **)(param_1 + ((int)pcVar3 >> 0xf)) = pcVar5 + 0x97;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (code)0xb6:
    goto switchD_08013068_caseD_b6;
  case (code)0xb7:
    goto switchD_08013068_caseD_b7;
  case (code)0xb8:
    goto switchD_08013068_caseD_b8;
  case (code)0xb9:
    goto switchD_08013068_caseD_b9;
  case (code)0xba:
    goto switchD_08013068_caseD_ba;
  case (code)0xbb:
    goto switchD_08013068_caseD_bb;
  case (code)0xbc:
    goto switchD_08013068_caseD_bc;
  case (code)0xbd:
    goto switchD_08013068_caseD_bd;
  case (code)0xbe:
    goto switchD_08013068_caseD_be;
  case (code)0xbf:
    goto switchD_08013068_caseD_bf;
  case (code)0xc0:
    goto switchD_08013068_caseD_c0;
  case (code)0xc1:
    goto switchD_08013068_caseD_c1;
  case (code)0xc2:
    goto switchD_08013068_caseD_c2;
  case (code)0xc3:
    goto switchD_08013068_caseD_c3;
  case (code)0xc4:
    goto switchD_08013068_caseD_c4;
  case (code)0xc5:
    goto switchD_08013068_caseD_c5;
  case (code)0xc6:
    goto switchD_08013068_caseD_c6;
  case (code)0xc7:
    goto switchD_08013068_caseD_c7;
  case (code)0xc8:
    goto switchD_08013068_caseD_c8;
  case (code)0xc9:
    goto switchD_08013068_caseD_c9;
  case (code)0xca:
    goto switchD_08013068_caseD_ca;
  case (code)0xcb:
    goto switchD_08013068_caseD_cb;
  case (code)0xcc:
    goto switchD_08013068_caseD_cc;
  case (code)0xcd:
    goto switchD_08013068_caseD_cd;
  case (code)0xce:
    goto switchD_08013068_caseD_ce;
  case (code)0xcf:
    goto switchD_08013068_caseD_cf;
  case (code)0xd0:
    goto switchD_08013068_caseD_d0;
  case (code)0xd1:
    goto switchD_08013068_caseD_d1;
  case (code)0xd2:
    goto switchD_08013068_caseD_d2;
  case (code)0xd3:
    goto switchD_08013068_caseD_d3;
  case (code)0xd4:
    goto switchD_08013068_caseD_d4;
  case (code)0xd5:
    goto switchD_08013068_caseD_d5;
  case (code)0xd6:
    goto switchD_08013068_caseD_d6;
  case (code)0xd7:
    goto switchD_08013068_caseD_d7;
  case (code)0xd8:
    goto switchD_08013068_caseD_d8;
  case (code)0xd9:
    goto switchD_08013068_caseD_d9;
  case (code)0xda:
    goto switchD_08013068_caseD_da;
  case (code)0xdb:
    goto switchD_08013068_caseD_db;
  case (code)0xdc:
    goto switchD_08013068_caseD_dc;
  case (code)0xdd:
    goto switchD_08013068_caseD_dd;
  case (code)0xde:
    goto switchD_08013068_caseD_de;
  case (code)0xdf:
    goto switchD_08013068_caseD_df;
  case (code)0xe0:
    goto switchD_08013068_caseD_e0;
  case (code)0xe1:
    goto switchD_08013068_caseD_e1;
  case (code)0xe2:
    goto switchD_08013068_caseD_e2;
  case (code)0xe3:
    goto switchD_08013068_caseD_e3;
  case (code)0xe4:
    goto switchD_08013068_caseD_e4;
  case (code)0xe5:
    goto switchD_08013068_caseD_e5;
  case (code)0xe6:
    goto switchD_08013068_caseD_e6;
  case (code)0xe7:
    goto switchD_08013068_caseD_e7;
  case (code)0xe8:
    goto switchD_08013068_caseD_e8;
  case (code)0xe9:
    goto switchD_08013068_caseD_e9;
  case (code)0xea:
    goto switchD_08013068_caseD_ea;
  case (code)0xeb:
    goto switchD_08013068_caseD_eb;
  case (code)0xec:
    goto switchD_08013068_caseD_ec;
  case (code)0xed:
    goto switchD_08013068_caseD_ed;
  case (code)0xee:
    goto switchD_08013068_caseD_ee;
  case (code)0xef:
    goto switchD_08013068_caseD_ef;
  case (code)0xf0:
    goto switchD_08013068_caseD_f0;
  case (code)0xf1:
    goto switchD_08013068_caseD_f1;
  case (code)0xf2:
    goto switchD_08013068_caseD_f2;
  case (code)0xf3:
    goto switchD_08013068_caseD_f3;
  case (code)0xf4:
    goto switchD_08013068_caseD_f4;
  case (code)0xf5:
    goto switchD_08013068_caseD_f5;
  case (code)0xf6:
    goto switchD_08013068_caseD_f6;
  case (code)0xf7:
    goto switchD_08013068_caseD_f7;
  case (code)0xf8:
    goto switchD_08013068_caseD_f8;
  case (code)0xf9:
    goto switchD_08013068_caseD_f9;
  case (code)0xfa:
    goto switchD_08013068_caseD_fa;
  case (code)0xfb:
    goto switchD_08013068_caseD_fb;
  case (code)0xfc:
    goto switchD_08013068_caseD_fc;
  case (code)0xfd:
    goto switchD_08013068_caseD_fd;
  case (code)0xfe:
    goto switchD_08013068_caseD_fe;
  case (code)0xff:
    goto switchD_08013068_caseD_ff;
  }
switchD_08013068_caseD_1b:
switchD_08013068_caseD_1c:
  return pcVar4;
}



// ==== 0801313c  caseD_68  (132 bytes, 2 xrefs)

undefined4
switchD_08013068::caseD_68(int param_1,undefined4 *param_2,uint *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  
  puVar4 = DAT_2000018c;
  iVar2 = DAT_20000188;
  if (DAT_20000188 == 0) {
    if ((DAT_2000018c != (undefined4 *)0x0) &&
       (*(char *)(param_1 + 1) == *(char *)((int)DAT_2000018c + 6))) {
      if (*(short *)(param_1 + 4) != 7) {
        return 0xffffffff;
      }
      *param_2 = *DAT_2000018c;
      uVar1 = (uint)*(ushort *)(puVar4 + 1);
      goto switchD_08013068_caseD_95;
    }
  }
  else if (*(char *)(param_1 + 1) == *(char *)(DAT_20000188 + 5)) {
    if (*(short *)(param_1 + 4) == 4) {
      *param_2 = *(undefined4 *)(DAT_20000188 + 8);
      uVar1 = (uint)*(ushort *)(iVar2 + 0xc);
    }
    else {
      if (*(short *)(param_1 + 4) != 5) {
        return 0xffffffff;
      }
      *param_2 = *(undefined4 *)(DAT_20000188 + 0x10);
      uVar1 = (uint)*(ushort *)(iVar2 + 0x14);
    }
switchD_08013068_caseD_95:
    *param_3 = uVar1;
    return 0;
  }
  puVar4 = DAT_20000184;
  while( true ) {
    if (puVar4 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    pcVar3 = (code *)puVar4[3];
    if ((pcVar3 != (code *)0x0) &&
       (iVar2 = (*pcVar3)(param_1,param_2,param_3,pcVar3,param_4), iVar2 == 0)) break;
    puVar4 = (undefined4 *)*puVar4;
  }
  return 0;
}



// ==== 080131c4  caseD_ac  (16 bytes, 2 xrefs)

byte switchD_08013068::caseD_ac(int param_1)

{
  byte bVar1;
  
  bVar1 = (byte)(param_1 << 1);
  if (param_1 * 0x1000000 < 0) {
    bVar1 = bVar1 ^ 0x1b;
  }
  return bVar1;
}



// ==== 08013686  FUN_08013686  (50 bytes, 0 xrefs)

/* WARNING: Control flow encountered bad instruction data */

undefined8 FUN_08013686(int param_1,undefined4 param_2,undefined4 *param_3,undefined2 param_4)

{
  int iVar1;
  int unaff_r5;
  char in_OV;
  undefined4 in_cr2;
  undefined4 in_cr6;
  undefined4 in_cr11;
  
  coprocessor_function(5,0xb,6,in_cr11,in_cr2,in_cr6);
  if (-1 < param_1) {
    *(undefined2 *)(param_1 + unaff_r5) = param_4;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar1 = param_3[2] << 3;
  if ((param_3[2] & 0x20000000) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (iVar1 == 0 || iVar1 < 0 != (bool)in_OV) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return CONCAT44(*param_3,param_1);
}



// ==== 080136cc  FUN_080136cc  (14 bytes, 0 xrefs)

undefined8 FUN_080136cc(int param_1)

{
  return CONCAT44(0x8013a00,param_1 << 3);
}



// ==== 0801374a  FUN_0801374a  (46 bytes, 0 xrefs)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0801374a(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 unaff_r10;
  int unaff_r11;
  undefined4 in_r12;
  undefined4 in_cr12;
  
  uVar4 = *param_3;
  coprocessor_load(0xc,in_cr12,in_r12);
  *(undefined4 *)(unaff_r11 + 0x8b6) = unaff_r10;
  puVar2 = *(undefined4 **)(param_1 + 4);
  uVar1 = *puVar2;
  uVar3 = puVar2[1];
  iVar5 = puVar2[2];
  uVar6 = puVar2[3];
  uVar7 = puVar2[4];
  uVar8 = puVar2[5];
  *(int *)iVar5 = iVar5;
  *(undefined4 *)(iVar5 + 4) = uVar6;
  *(undefined4 *)(iVar5 + 8) = uVar8;
  if (uVar3 < 0xffffff18) {
    *(undefined4 *)(uVar3 + 0xe8) = uVar1;
    *(undefined4 *)(uVar3 + 0xec) = uVar7;
    *(undefined4 *)(uVar3 + 0xf0) = uVar8;
    *(uint *)(uVar3 + 0xf4) = uVar3 + 0xf4;
    *(undefined4 *)(uVar3 + 0xf8) = uVar4;
    *(undefined4 *)(uVar3 + 0xfc) = uVar7;
    *(undefined4 *)(uVar3 + 0x100) = uVar8;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ==== 08013860  FUN_08013860  (116 bytes, 0 xrefs)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013860(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  int iVar1;
  undefined4 in_cr12;
  
  iVar1 = param_4[2];
  if (param_3 == 0) {
    _Reserved4 = 0;
    uRam00000006 = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  software_bkpt(0xc9);
  coprocessor_load(5,in_cr12,*param_4 + 0x340);
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 8) = unaff_r4;
  *(undefined4 *)(param_1 + 0xc) = unaff_r5;
  *(int *)(param_1 + 0x10) = iVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ==== 08013880  FUN_08013880  (26 bytes, 0 xrefs)

/* WARNING: Control flow encountered bad instruction data */

void FUN_08013880(undefined4 param_1,undefined4 param_2,int param_3)

{
  int unaff_r7;
  char in_ZR;
  
  if ((in_ZR == '\0') && (param_3 == 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x073c963c(param_1,unaff_r7 << 2);
  return;
}



// ==== 08013934  FUN_08013934  (96 bytes, 0 xrefs)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013934(int param_1,short param_2,int param_3,int param_4)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  char in_ZR;
  byte in_CY;
  
  iVar1 = iRam08013a1c;
  if (in_ZR != '\0') {
    *(short *)((param_1 >> 0x20) * 0x10 + 0x18) = param_2 << 3;
    _MasterStackPointer = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(char *)(param_1 * 2) = (char)param_1;
  *(char *)(param_3 + iVar1) = (char)uRam08013a38;
  *(short *)(param_1 + iVar1) = (short)iVar1;
                    /* WARNING: Could not recover jumptable at 0x08013928. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0x46,iVar1,param_3,param_4 + param_3 + (uint)in_CY);
  return;
}



// ==== 08013958  FUN_08013958  (54 bytes, 0 xrefs)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x080132d6) */
/* WARNING: Removing unreachable block (ram,0x47004e00) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013958(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 unaff_r4;
  undefined4 *unaff_r5;
  undefined4 unaff_r6;
  int unaff_r7;
  code *UNRECOVERED_JUMPTABLE;
  char in_ZR;
  byte in_CY;
  
  if (in_ZR != '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_r5 = unaff_r4;
  unaff_r5[1] = unaff_r6;
  unaff_r5[2] = unaff_r7;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 8) = unaff_r4;
  *(undefined4 **)(param_1 + 0xc) = unaff_r5 + 3;
  *(int *)(param_1 + 0x10) = unaff_r7;
  iVar1 = iRam08013a1c;
  if (unaff_r7 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(char *)(param_1 * 2) = (char)param_1;
  *(char *)(param_3 + iVar1) = (char)uRam08013a38;
  *(short *)(param_1 + iVar1) = (short)iVar1;
                    /* WARNING: Could not recover jumptable at 0x08013928. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0x46,iVar1,param_3,param_4 + param_3 + (uint)in_CY);
  return;
}



// ==== 080139c2  FUN_080139c2  (88 bytes, 0 xrefs)

void FUN_080139c2(uint param_1,undefined2 *param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *unaff_r4;
  uint unaff_r6;
  uint unaff_r7;
  undefined4 unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  uint unaff_lr;
  int unaff_pc;
  undefined4 in_cr15;
  
  do {
    *(uint *)((int)register0x00000054 + -4) = unaff_lr;
    *(uint *)((int)register0x00000054 + -8) = unaff_r7;
    *(uint *)((int)register0x00000054 + -0xc) = unaff_r6;
    *(uint **)((int)register0x00000054 + -0x10) = param_3;
    register0x00000054 = (BADSPACEBASE *)((int)register0x00000054 + -0x14);
    *(uint *)register0x00000054 = param_1;
    do {
      uVar1 = DAT_08013ae4;
      uVar2 = param_1 >> (param_1 & 0x1f) | param_1 << 0x20 - (param_1 & 0x1f);
      if (uVar2 == 0) {
        uVar2 = param_4 << 3;
      }
      else {
        *(uint *)((int)register0x00000054 + -4) = unaff_lr;
        *(uint *)((int)register0x00000054 + -8) = unaff_r7;
        *(uint *)((int)register0x00000054 + -0xc) = unaff_r6;
        *(uint **)((int)register0x00000054 + -0x10) = param_3;
        register0x00000054 = (BADSPACEBASE *)((int)register0x00000054 + -0x14);
        *(uint *)register0x00000054 = uVar2;
      }
      param_3 = (uint *)((int)register0x00000054 + 0x2fc);
      if (uVar2 != 0) {
        *unaff_r4 = param_2;
        unaff_r4[1] = param_3;
        unaff_r4[2] = param_4;
        unaff_r4[3] = unaff_r8;
        unaff_r4[4] = 0xd0d60000;
                    /* WARNING: Could not recover jumptable at 0x080139ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)();
        return;
      }
      *param_2 = (short)param_2;
      unaff_pc = unaff_pc + 0x2d0;
      coprocessor_load(8,in_cr15,unaff_pc);
      if ((int)param_3 * 2 < 0) {
        *(int *)((int)register0x00000054 + -4) = (int)param_3 * 2;
        *(uint *)((int)register0x00000054 + -8) = uVar1;
        *(uint *)((int)register0x00000054 + -0xc) = param_4;
        *(uint **)((int)register0x00000054 + -0x10) = param_3;
        register0x00000054 = (BADSPACEBASE *)((int)register0x00000054 + -0x14);
        *(uint *)register0x00000054 = 0;
      }
      param_2 = (undefined2 *)
                (((int)param_2 +
                 (uint)(((int)param_3 * 0x10 & 0x80000000U) != 0) + (int)param_3 * 0x10) * 2);
      unaff_r7 = -param_4;
      param_1 = DAT_08013ac4;
      if (DAT_08013ac4 == 0) {
        param_1 = param_4 << 3;
      }
      unaff_r6 = DAT_08013abc;
    } while (param_1 == 0);
  } while( true );
}



// ==== 08013a40  FUN_08013a40  (54 bytes, 1 xrefs)

/* WARNING: Control flow encountered bad instruction data */

void FUN_08013a40(uint param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int unaff_r4;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 unaff_lr;
  undefined1 auStack_28 [16];
  undefined1 auStack_14 [8];
  
  puVar7 = auStack_14;
  iVar3 = *param_3;
  iVar5 = param_3[1];
  iVar6 = param_3[2];
  if (param_1 != 0) {
    puVar7 = auStack_28;
  }
  uVar1 = (ushort)((param_1 & 0xff) << 8) | (ushort)(param_1 >> 8) & 0xff;
  iVar2 = (int)(short)uVar1;
  piVar4 = (int *)(iVar2 * 8);
  *piVar4 = unaff_r4;
  piVar4[1] = iVar5;
  piVar4[2] = iVar6;
  *(int *)iVar2 = iVar2;
  *(int **)(iVar2 + 4) = param_3 + 3;
  *(int *)(iVar2 + 8) = unaff_r4;
  *(int **)(iVar2 + 0xc) = piVar4 + 3;
  *(int *)(iVar2 + 0x10) = iVar6;
  *(ushort *)(iVar2 + unaff_r4) = uVar1;
  *(char *)(iVar3 * 2) = (char)iVar3;
  if (iVar2 != 0) {
    *(undefined4 *)(puVar7 + -4) = unaff_lr;
    *(undefined4 *)(puVar7 + -8) = s_9DCBA_08013bbe._2_4_;
    *(int *)(puVar7 + -0xc) = iVar2 << 1;
    *(int *)(puVar7 + -0x10) = unaff_r4;
    *(undefined4 *)(puVar7 + -0x14) = param_4;
    *(int **)(puVar7 + -0x18) = param_3 + 3;
    *(int *)(puVar7 + -0x1c) = iVar3;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ==== 08013a9c  FUN_08013a9c  (62 bytes, 0 xrefs)
// DECOMPILATION FAILED: Low-level Error: Bad instruction count exceeded:
    ...
    No pcode could be generated at address: r0x08013afa

// ==== 08014c2c  FUN_08014c2c  (966 bytes, 0 xrefs)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08014c2c(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 extraout_r2;
  uint uVar4;
  undefined4 *extraout_r3;
  undefined4 *unaff_r5;
  int unaff_r6;
  uint uVar5;
  undefined4 in_cr2;
  undefined8 uVar6;
  undefined1 auStack_7ffffffe [2147483638];
  
  *(undefined1 *)(unaff_r6 + 4) = 0xa4;
  *(undefined4 *)(unaff_r6 + (int)unaff_r5) = 0x4444487f;
  *unaff_r5 = 0;
  uRam04100470 = 0x70;
  *(undefined1 *)(uint)UsageFault = 0;
  bRam0000001a = MemManage_1;
  DAT_08014af4 = 0xfffffff8;
  uVar4 = (uint)MemManage_1;
  uVar5 = (uint)HardFault_1;
  _MasterStackPointer = 0x2e;
  _Reset = 0;
  _NMI = _SysTick;
  _MemManage = 0;
  do {
  } while (!SBORROW4(uVar4,0x67));
  _BusFault = _SysTick << 0x10;
  _HardFault = uVar4;
  uVar6 = func_0x08c5c3cc(0,(char)((uint)_SysTick >> 8),*(undefined4 *)(uVar5 * 2));
  puVar2 = (undefined4 *)uVar6;
  *puVar2 = (int)((ulonglong)uVar6 >> 0x20);
  puVar2[1] = 0x8014ce8;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2 = puRam08014d00;
  iVar1 = iRam08014cfc;
  coprocessor_load(6,in_cr2,(int)register0x00000054 + 0x4c4);
  uVar3 = func_0x089f9b68(uRam08014ce8,uRam08014cec,uRam08014cf0);
  *puVar2 = extraout_r2;
  *extraout_r3 = uVar3;
  extraout_r3[1] = iVar1 >> 0x14;
  extraout_r3[2] = 0x8014b54;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



