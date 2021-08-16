__int64 __fastcall Ipv6pHandleRouterAdvertisement(__int64 a1, _QWORD *a2, _DWORD *a3)
{
  __int64 v3; // rax
  IN6_ADDR *v5; // r10
  UINT AlignOffset; // er11
  _NET_BUFFER *v9; // r14
  __int64 v10; // rax
  __int64 v11; // rsi
  __int64 v12; // rdx
  __int64 v13; // rax
  unsigned __int64 v14; // rcx
  __int64 v15; // rax
  __int64 result; // rax
  UCHAR v17; // r8
  int v18; // eax
  IN6_ADDR *v19; // rcx
  __int64 v20; // rcx
  char v21; // r8
  KSPIN_LOCK *v22; // rax
  PMDL v23; // rcx
  ULONG v24; // er12
  KSPIN_LOCK *v25; // r15
  unsigned int v26; // edx
  unsigned __int8 v27; // bl
  KIRQL v28; // r13
  int v29; // ecx
  unsigned int v30; // edx
  KIRQL *v31; // rax
  unsigned __int16 v32; // r15
  char v33; // al
  unsigned __int8 v34; // cl
  unsigned int v35; // ecx
  unsigned int v36; // edx
  ULONG v37; // eax
  ULONG v38; // eax
  _QWORD *v39; // rdi
  __int64 v40; // rax
  _QWORD *v41; // rax
  char v42; // r10
  bool v43; // zf
  __int64 v44; // rax
  __int64 v45; // r15
  __int64 v46; // rcx
  size_t v47; // r13
  unsigned int v48; // eax
  unsigned int v49; // edi
  PRTL_DYNAMIC_HASH_TABLE_ENTRY v50; // rax
  __int64 v51; // rcx
  __int64 v52; // r14
  _LIST_ENTRY **v53; // rdi
  char v54; // al
  __int64 v55; // rax
  __int64 v56; // rdi
  __int64 v57; // r9
  __int64 *v58; // rcx
  unsigned int v59; // edx
  __int64 v60; // rdx
  __int64 v61; // r8
  bool v62; // di
  char v63; // r15
  char v64; // r12
  char v65; // r13
  __int64 v66; // rcx
  __int64 v67; // rdx
  unsigned __int64 v68; // rcx
  unsigned int v69; // edx
  unsigned __int64 v70; // rcx
  int v71; // er15
  _QWORD *v72; // rax
  _QWORD *v73; // rdi
  int v74; // ecx
  PKSPIN_LOCK v75; // rcx
  char v76; // al
  unsigned int v77; // er8
  unsigned __int32 v78; // er8
  unsigned __int64 v79; // rcx
  unsigned int v80; // er12
  __int64 v81; // r13
  int v82; // ecx
  __int64 v83; // r15
  __int64 v84; // rbx
  PNET_BUFFER v85; // r14
  int v86; // edx
  _DWORD *v87; // rcx
  __int64 v88; // rbx
  PMDL v89; // rax
  __int64 v90; // rdx
  ULONG v91; // ebx
  unsigned int v92; // ecx
  bool v93; // cf
  _BYTE *v94; // rax
  unsigned __int16 N_length; // cx
  ULONG v96; // er15
  char v97; // bl
  unsigned __int32 v98; // ecx
  unsigned int v99; // edi
  _BYTE *v100; // rbx
  unsigned __int8 v101; // di
  unsigned __int8 v102; // r9
  unsigned __int32 v103; // edx
  char *v104; // r11
  unsigned int v105; // er15
  unsigned __int32 v106; // ecx
  unsigned int v107; // edx
  char *v108; // rcx
  int v109; // eax
  __int64 v110; // r8
  int v111; // er9
  unsigned int i; // eax
  char v113; // dl
  char v114; // cl
  unsigned int v115; // eax
  int v116; // edi
  __int64 v117; // rbx
  int v118; // edx
  _DWORD *v119; // rcx
  __int64 v120; // rbx
  unsigned __int8 v121; // r12
  const UCHAR *v122; // r13
  __int64 v123; // rdx
  __int64 v124; // r8
  unsigned int v125; // eax
  char v126; // r9
  PKSPIN_LOCK v127; // r15
  UCHAR *v128; // r8
  unsigned int v129; // er9
  UCHAR *v130; // rbx
  unsigned __int64 v131; // rdi
  char v132; // r14
  char v133; // r15
  unsigned int v134; // ecx
  unsigned int v135; // eax
  int v136; // ecx
  unsigned int v137; // eax
  unsigned int v138; // edx
  unsigned int v139; // eax
  unsigned int v140; // edx
  int v141; // ecx
  volatile signed __int32 *v142; // r12
  __int64 v143; // r13
  __int64 v144; // rdi
  char *v145; // rax
  char *v146; // r15
  __int64 v147; // r8
  int v148; // ebx
  char v149; // al
  char *v150; // rax
  __int64 v151; // r8
  __int128 v152; // xmm0
  unsigned int v153; // edi
  int v154; // er8
  unsigned __int8 v155; // bl
  ULONG v156; // ecx
  ULONG v157; // eax
  _QWORD *v158; // rbx
  _QWORD *v159; // rax
  int v160; // er12
  unsigned int v161; // ecx
  unsigned int v162; // edx
  int v163; // eax
  char v164; // cl
  unsigned __int8 v165; // [rsp+60h] [rbp-A0h]
  unsigned __int8 v166; // [rsp+61h] [rbp-9Fh]
  char v167; // [rsp+61h] [rbp-9Fh]
  char v168; // [rsp+62h] [rbp-9Eh] BYREF
  KIRQL NewIrql; // [rsp+63h] [rbp-9Dh]
  ULONG v170; // [rsp+64h] [rbp-9Ch]
  char v171; // [rsp+68h] [rbp-98h]
  int v172; // [rsp+6Ch] [rbp-94h]
  ULONG v173; // [rsp+70h] [rbp-90h]
  unsigned int v174; // [rsp+74h] [rbp-8Ch]
  unsigned __int32 v175; // [rsp+78h] [rbp-88h]
  unsigned int v176; // [rsp+7Ch] [rbp-84h]
  __int64 v177; // [rsp+80h] [rbp-80h]
  void *Buf2; // [rsp+88h] [rbp-78h]
  UCHAR *v179; // [rsp+90h] [rbp-70h]
  const UCHAR *v180; // [rsp+98h] [rbp-68h]
  _LIST_ENTRY *v181; // [rsp+A0h] [rbp-60h]
  __int16 v182[2]; // [rsp+A8h] [rbp-58h] BYREF
  __int16 v183; // [rsp+ACh] [rbp-54h] BYREF
  _QWORD *v184; // [rsp+B0h] [rbp-50h]
  _QWORD *v185; // [rsp+B8h] [rbp-48h]
  PNET_BUFFER NetBuffer; // [rsp+C0h] [rbp-40h]
  PKSPIN_LOCK SpinLock; // [rsp+C8h] [rbp-38h]
  char *v188; // [rsp+D0h] [rbp-30h]
  unsigned __int64 v189; // [rsp+D8h] [rbp-28h]
  struct _KLOCK_QUEUE_HANDLE LockHandle; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v191; // [rsp+F8h] [rbp-8h] BYREF
  __int64 v192; // [rsp+100h] [rbp+0h] BYREF
  UCHAR *v193; // [rsp+108h] [rbp+8h]
  __int64 v194; // [rsp+110h] [rbp+10h] BYREF
  __int64 v195[3]; // [rsp+118h] [rbp+18h] BYREF
  __int64 v196; // [rsp+130h] [rbp+30h] BYREF
  int v197; // [rsp+138h] [rbp+38h]
  int v198; // [rsp+13Ch] [rbp+3Ch]
  __m128i v199; // [rsp+140h] [rbp+40h]
  __int64 v200; // [rsp+150h] [rbp+50h] BYREF
  unsigned int v201; // [rsp+158h] [rbp+58h]
  unsigned __int32 v202; // [rsp+15Ch] [rbp+5Ch]
  __m128i v203; // [rsp+160h] [rbp+60h]
  struct _KLOCK_QUEUE_HANDLE v204; // [rsp+170h] [rbp+70h] BYREF
  struct _KLOCK_QUEUE_HANDLE v205; // [rsp+188h] [rbp+88h] BYREF
  struct _KLOCK_QUEUE_HANDLE v206; // [rsp+1A0h] [rbp+A0h] BYREF
  struct _KLOCK_QUEUE_HANDLE v207; // [rsp+1B8h] [rbp+B8h] BYREF
  struct _KLOCK_QUEUE_HANDLE v208; // [rsp+1D0h] [rbp+D0h] BYREF
  struct _KLOCK_QUEUE_HANDLE v209; // [rsp+1E8h] [rbp+E8h] BYREF
  struct _KLOCK_QUEUE_HANDLE v210; // [rsp+200h] [rbp+100h] BYREF
  struct _RTL_DYNAMIC_HASH_TABLE_CONTEXT Context; // [rsp+218h] [rbp+118h] BYREF
  __int128 v212; // [rsp+230h] [rbp+130h] BYREF
  __int128 v213; // [rsp+240h] [rbp+140h] BYREF
  int v214[2]; // [rsp+250h] [rbp+150h] BYREF
  __int64 v215; // [rsp+258h] [rbp+158h]
  __int128 v216; // [rsp+260h] [rbp+160h]
  IN6_ADDR a; // [rsp+270h] [rbp+170h] BYREF
  __int64 v218[2]; // [rsp+280h] [rbp+180h] BYREF
  __int64 Storage[2]; // [rsp+290h] [rbp+190h] BYREF
  __int64 v220[3]; // [rsp+2A0h] [rbp+1A0h] BYREF
  __int64 v221[5]; // [rsp+2B8h] [rbp+1B8h] BYREF
  char v222[32]; // [rsp+2E0h] [rbp+1E0h] BYREF
  char v223[32]; // [rsp+300h] [rbp+200h] BYREF
  __m128i v224; // [rsp+320h] [rbp+220h]
  __m128i v225; // [rsp+330h] [rbp+230h]
  char v226[32]; // [rsp+340h] [rbp+240h] BYREF

  v3 = a2[1];
  v5 = (IN6_ADDR *)a2[3];
  AlignOffset = 0;
  v184 = a2;
  Buf2 = v5;
  v9 = *(_NET_BUFFER **)(v3 + 8);
  v10 = a2[0x1A];
  NetBuffer = v9;
  v180 = 0i64;
  v174 = 0;
  v11 = *(_QWORD *)(v10 + 8);
  Storage[0] = 0i64;
  Storage[1] = 0i64;
  v185 = 0i64;
  v166 = *(_BYTE *)(*(_QWORD *)(v11 + 0x28) + 0xAi64);
  v168 = 0;
  v12 = (MEMORY[0xFFFFF78000000008] / 0x2710ui64 * (unsigned __int128)0x624DD2F1A9FBE77ui64) >> 0x40;
  v205.LockQueue.Next = 0i64;
  v205.LockQueue.Lock = 0i64;
  *(_QWORD *)&v205.OldIrql = 0i64;
  v13 = a2[0x1B];
  v14 = (v12 + ((MEMORY[0xFFFFF78000000008] / 0x2710ui64 - v12) >> 1)) >> 8;
  *a3 = 0x1C;
  v181 = (_LIST_ENTRY *)v13;
  v15 = a2[0x22];
  v189 = v14;
  LockHandle.LockQueue.Next = 0i64;
  LockHandle.LockQueue.Lock = 0i64;
  *(_QWORD *)&LockHandle.OldIrql = 0i64;
  if ( *(_BYTE *)(v15 + 7) != 0xFF )
  {
    result = a2[1];
    *(_DWORD *)(result + 0x8C) = 0xC000021B;
    *a3 = 0x11;
    return result;
  }
  if ( *(_BYTE *)(a1 + 1) )
  {
    result = a2[1];
    *(_DWORD *)(result + 0x8C) = 0xC000021B;
    *a3 = 0x12;
    return result;
  }
  v17 = v5->u.Byte[0];
  if ( v5->u.Byte[0] == 0xFF )
  {
    v18 = v5->u.Byte[1] & 0xF;
  }
  else
  {
    v19 = v5;
    a = (IN6_ADDR)0i64;
    if ( ((unsigned __int8)v5 & 1) != 0 )
    {
      v19 = &a;
      a = *v5;
      v17 = a.u.Byte[0];
    }
    if ( v17 == 0xFE && (v19->u.Byte[1] & 0xC0) == 0x80 || IN6_IS_ADDR_LOOPBACK(v19) )
    {
      v18 = 2;
    }
    else if ( v21 == (char)0xFE && (*(_BYTE *)(v20 + 1) & 0xC0) == 0xC0 )
    {
      v18 = 5;
    }
    else
    {
      v18 = 0xE;
    }
  }
  if ( v18 != 2 )
  {
    result = a2[1];
    *(_DWORD *)(result + 0x8C) = 0xC000021B;
    *a3 = 0x13;
    return result;
  }
  if ( v9->DataLength < 0x10 )
  {
    result = a2[1];
    *(_DWORD *)(result + 0x8C) = 0xC000021B;
    *a3 = 0x14;
    return result;
  }
  v22 = (KSPIN_LOCK *)NdisGetDataBuffer(v9, 0x10u, Storage, 1u, AlignOffset);
  v23 = v9->CurrentMdl;
  v24 = 0x10;
  v25 = v22;
  v26 = v9->CurrentMdlOffset + 0x10;
  SpinLock = v22;
  if ( v26 >= v23->ByteCount )
  {
    NdisAdvanceNetBufferDataStart(v9, 0x10u, 0, 0i64);
  }
  else
  {
    v9->DataOffset += 0x10;
    v9->DataLength -= 0x10;
    v9->CurrentMdlOffset = v26;
  }
  v27 = *((_BYTE *)v25 + 5);
  v28 = NewIrql;
  v29 = (unsigned __int16)__ROR2__(*((_WORD *)v25 + 3), 8);
  v175 = _byteswap_ulong(*((_DWORD *)v25 + 2));
  v176 = v29;
  while ( 1 )
  {
    v30 = v9->DataLength;
    v182[0] = 0;
    if ( v30 < 2 )
      break;
    v31 = (KIRQL *)NdisGetDataBuffer(v9, 2u, v182, 1u, 0);
    v30 = v9->DataLength;
    v32 = 8 * v31[1];
    if ( v32 && v32 <= v30 )
    {
      v28 = *v31;
      v33 = 1;
    }
    else
    {
      v33 = 0;
    }
    if ( !v33 )
      break;
    switch ( v28 )
    {
      case 1u:
        if ( (*(_DWORD *)(*(_QWORD *)(v11 + 0x28) + 0x24i64) & 0x210) == 0x10 )
        {
          if ( v32 != v166 + 2i64 )
          {
            *a3 = 0x15;
            goto LABEL_70;
          }
          v35 = v9->CurrentMdlOffset + 2;
          if ( v35 >= *(_DWORD *)(v9->Link.Region + 0x28) )
          {
            NdisAdvanceNetBufferDataStart(v9, 2u, 0, 0i64);
          }
          else
          {
            v9->DataOffset += 2;
            v9->DataLength = v30 - 2;
            v9->CurrentMdlOffset = v35;
          }
          v32 -= 2;
          v24 += 2;
          v180 = (const UCHAR *)NdisGetDataBuffer(v9, v32, v226, 1u, 0);
        }
        break;
      case 3u:
        memset(v222, 0, sizeof(v222));
        if ( v32 != 0x20 || *((_BYTE *)NdisGetDataBuffer(v9, 0x20u, v222, 1u, 0) + 2) > 0x80u )
        {
          *a3 = 0x17;
          goto LABEL_70;
        }
        break;
      case 5u:
        v194 = 0i64;
        if ( v32 != 8 )
        {
          *a3 = 0x16;
          goto LABEL_70;
        }
        v174 = _byteswap_ulong(*((_DWORD *)NdisGetDataBuffer(v9, 8u, &v194, 1u, 0) + 1));
        break;
      case 0x18u:
        v220[0] = 0i64;
        v220[1] = 0i64;
        v220[2] = 0i64;
        if ( v32 > 0x18u
          || (v34 = *((_BYTE *)NdisGetDataBuffer(v9, v32, v220, 1u, 0) + 2), v34 > 0x80u)
          || v34 > 0x40u && v32 < 0x18u
          || v34 && v32 < 0x10u )
        {
          *a3 = 0x18;
          goto LABEL_70;
        }
        break;
      case 0x19u:
        if ( (*(_BYTE *)(v11 + 0x194) & 0x40) != 0 && (v32 < 0x18u || (((_BYTE)v32 - 8) & 0xF) != 0) )
          *a3 = 0x19;
        break;
      default:
        if ( v28 == 0x1F && (*(_BYTE *)(v11 + 0x194) & 0x40) != 0 && v32 < 0x10u )
        {
          *a3 = 0x1A;
LABEL_70:
          v30 = v9->DataLength;
          goto LABEL_71;
        }
        break;
    }
    if ( *a3 != 0x1C )
      goto LABEL_70;
    if ( v32 )
    {
      v36 = v32 + v9->CurrentMdlOffset;
      if ( v36 >= *(_DWORD *)(v9->Link.Region + 0x28) )
      {
        NdisAdvanceNetBufferDataStart(v9, v32, 0, 0i64);
      }
      else
      {
        v9->DataOffset += v32;
        v9->DataLength -= v32;
        v9->CurrentMdlOffset = v36;
      }
    }
    v24 += v32;
  }
LABEL_71:
  v37 = v9->CurrentMdlOffset;
  if ( v37 < v24 )
  {
    NdisRetreatNetBufferDataStart(v9, v24, 0, NetioAllocateMdl);
    v38 = v9->DataLength;
  }
  else
  {
    v9->DataOffset -= v24;
    v9->CurrentMdlOffset = v37 - v24;
    v38 = v30 + v24;
    v9->DataLength = v30 + v24;
  }
  if ( v38 != v24 )
  {
    if ( *a3 == 0x1C )
      *a3 = 0x1B;
    result = v184[1];
    *(_DWORD *)(result + 0x8C) = 0xC000021B;
    return result;
  }
  v39 = v184;
  if ( (BYTE5(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Flink) & 2) != 0 )
    IppTraceNeighborDiscovery((_BYTE *)v11, (__int128 *)Buf2, **(__int128 ***)(v184[0x1A] + 0x10i64), 0x12);
  KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &LockHandle);
  while ( *(_DWORD *)(v11 + 0x188) )
    ;
  if ( (*(_BYTE *)(v11 + 0x190) & 2) != 0 || (*(_BYTE *)(v11 + 0x191) & 8) == 0 )
    goto LABEL_359;
  v40 = *(_QWORD *)(v11 + 0x28);
  *(_BYTE *)(v11 + 0x1E8) = 1;
  if ( (*(_DWORD *)(v40 + 0x24) & 2) == 0 )
  {
    v41 = Ipv6pFindPotentialRouterUnderLock(v11, (_QWORD *)v39[0x20]);
    if ( v41 )
    {
      v43 = *((_DWORD *)v41 + 6) == 5;
      v179 = (UCHAR *)(v41 + 2);
      *((_BYTE *)v41 + 0x1C) = v42;
      if ( !v43 )
      {
        *((_DWORD *)v41 + 6) = 5;
        Ipv6NotifyPotentialRouterChange(v11, (__int64)v41);
      }
      goto LABEL_89;
    }
LABEL_359:
    KeReleaseInStackQueuedSpinLock(&LockHandle);
    result = v39[1];
    *(_DWORD *)(result + 0x8C) = 0;
    return result;
  }
  v179 = (UCHAR *)(v11 + 0x1E0);
LABEL_89:
  KeAcquireInStackQueuedSpinLockAtDpcLevel((PKSPIN_LOCK)(v11 + 0x120), &v205);
  while ( *(_DWORD *)(v11 + 0x128) )
    ;
  v44 = *(_QWORD *)v11;
  v45 = *(_QWORD *)(v11 + 0x150);
  Context.Signature = 0i64;
  v46 = *(_QWORD *)(v44 + 0x28);
  v188 = (char *)v45;
  v47 = *(unsigned __int16 *)(*(_QWORD *)(v46 + 0x10) + 6i64);
  v177 = 0i64;
  v48 = RtlCompute37Hash((unsigned int)g_37HashSeed, Buf2, v47);
  v49 = RtlCompute37Hash(v48, v11 + 8, 4i64) | 0x80000000;
  v204.LockQueue.Next = 0i64;
  v204.LockQueue.Lock = 0i64;
  *(_QWORD *)&v204.OldIrql = 0i64;
  *(_OWORD *)&Context.ChainHead = 0i64;
  _InterlockedAdd((volatile signed __int32 *)(v45 + 8), 1u);
  if ( !KeTestSpinLock((PKSPIN_LOCK)v45) )
  {
    _InterlockedDecrement((volatile signed __int32 *)(v45 + 8));
    KeAcquireInStackQueuedSpinLockAtDpcLevel((PKSPIN_LOCK)v45, &v204);
    _InterlockedAdd((volatile signed __int32 *)(v45 + 8), 1u);
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&v204);
  }
  v50 = RtlLookupEntryHashTable((PRTL_DYNAMIC_HASH_TABLE)(v45 + 0x10), v49, &Context);
  v51 = 0i64;
  if ( v50 )
  {
    v52 = 0i64;
    do
    {
      v53 = &v50[0xFFFFFFFE].Linkage.Blink;
      if ( v50[0xFFFFFFFEi64].Signature == v11
        && (!v181 || v53[2] == v181)
        && !memcmp(v53 + 0x11, Buf2, v47)
        && (!v52 || *((_DWORD *)v53 + 0x10) > *(_DWORD *)(v52 + 0x40)) )
      {
        v52 = (__int64)v53;
      }
      v50 = RtlGetNextEntryHashTable((PRTL_DYNAMIC_HASH_TABLE)(v45 + 0x10), &Context);
    }
    while ( v50 );
    v45 = (__int64)v188;
    v177 = v52;
    v51 = v52;
    if ( v52 )
    {
      if ( *(_DWORD *)(v52 + 4) == 1 )
      {
        v54 = *(_BYTE *)(v52 + 0x45);
        if ( (v54 & 1) == 0 && (v54 & 8) != 0 )
        {
          _InterlockedDecrement((volatile signed __int32 *)(v11 + 0x134));
          _InterlockedDecrement((volatile signed __int32 *)(*(_QWORD *)(v11 + 0x150) + 0x38i64));
          if ( *(int *)(v11 + 0x134) < 0 )
            *(_DWORD *)(v11 + 0x134) = 0;
          v55 = *(_QWORD *)(v11 + 0x150);
          if ( *(int *)(v55 + 0x38) < 0 )
            *(_DWORD *)(v55 + 0x38) = 0;
        }
      }
      _InterlockedAdd((volatile signed __int32 *)(v52 + 4), 1u);
    }
  }
  _InterlockedDecrement((volatile signed __int32 *)(v45 + 8));
  v56 = (__int64)v181;
  if ( v51 || (v177 = IppCreateAndInitializeNeighbor(v11, (__int64)v181, (__int64)Buf2, 1u), (v51 = v177) != 0) )
  {
    *(_BYTE *)(v51 + 0x45) |= 2u;
    v185 = (_QWORD *)IppUpdateNeighbor(v51, v180, 0, 1, 0);
  }
  v57 = *(_QWORD *)(v56 + 8);
  if ( v174 >= 0x500 && v174 <= *(_DWORD *)(*(_QWORD *)(v56 + 0x28) + 8i64) )
  {
    *(_DWORD *)(v56 + 0x54) = v174;
    v58 = *(__int64 **)(v57 + 0x168);
    v59 = 0;
    while ( v58 != (__int64 *)(v57 + 0x168) )
    {
      if ( !v59 || *((_DWORD *)v58 + 5) < v59 )
        v59 = *((_DWORD *)v58 + 5);
      v58 = (__int64 *)*v58;
    }
    *(_DWORD *)(v57 + 0x178) = v59;
  }
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&v205);
  LOBYTE(v61) = *(_BYTE *)(v11 + 0x191);
  if ( (v61 & 4) != 0 )
  {
    *(_BYTE *)(v11 + 0x191) = v61 & 0xFB;
    Ipv6pResetAutoConfiguredSettings(v11, 8u);
    LOBYTE(v61) = *(_BYTE *)(v11 + 0x191);
  }
  v62 = (v27 & 0x40) != 0;
  v63 = 0;
  v64 = 0;
  if ( v27 >> 7 != (v61 & 1) )
  {
    if ( (v27 & 0x80u) != 0 )
    {
      v63 = 1;
      LOBYTE(v61) = (v27 >> 7) | v61 & 0xFE;
      *(_BYTE *)(v11 + 0x191) = v61;
      if ( *((_DWORD *)&MICROSOFT_TCPIP_PROVIDER_Context + 9) == 1
        && ((__int64)WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Blink & 4) != 0 )
      {
        McTemplateK0qsqqqq(
          (PMCGEN_TRACE_CONTEXT)&MICROSOFT_TCPIP_PROVIDER_Context,
          *(_QWORD *)v11,
          v61 & 1,
          *(_DWORD *)(v11 + 8),
          (__int64)"ManagedAddressConfiguration",
          v61 & 1,
          0,
          **(_DWORD **)v11,
          *(_WORD *)(*(_QWORD *)(*(_QWORD *)v11 + 0x28i64) + 0x1Ci64));
      }
    }
    *(_DWORD *)(*(_QWORD *)v11 + 0x8Ci64) = 1;
  }
  v65 = v63;
  if ( v62 != ((*(_BYTE *)(v11 + 0x191) & 2) != 0) )
  {
    if ( (v27 & 0x40) != 0 )
    {
      v64 = 1;
      LOBYTE(v61) = *(_BYTE *)(v11 + 0x191) & 0xFD | (2 * v62);
      v63 = 1;
      *(_BYTE *)(v11 + 0x191) = v61;
      if ( *((_DWORD *)&MICROSOFT_TCPIP_PROVIDER_Context + 9) == 1
        && ((__int64)WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Blink & 4) != 0 )
      {
        McTemplateK0qsqqqq(
          (PMCGEN_TRACE_CONTEXT)&MICROSOFT_TCPIP_PROVIDER_Context,
          *(_QWORD *)v11,
          ((unsigned __int8)v61 >> 1) & 1,
          *(_DWORD *)(v11 + 8),
          (__int64)"OtherStatefulConfiguration",
          (v61 & 2) != 0,
          0,
          **(_DWORD **)v11,
          *(_WORD *)(*(_QWORD *)(*(_QWORD *)v11 + 0x28i64) + 0x1Ci64));
      }
    }
    *(_DWORD *)(*(_QWORD *)v11 + 0x8Ci64) = 1;
  }
  v66 = 0i64;
  v221[3] = 0i64;
  v221[4] = 0i64;
  if ( *(_QWORD *)(v11 + 0x398) || *(_QWORD *)(v11 + 0x3A0) )
  {
    if ( (v27 & 0x40) != 0 && v64 )
    {
      v212 = *(_OWORD *)(v11 + 0x398);
      IppLocalitySetOtherStatefulAddressConfig(&v212);
    }
    if ( (v27 & 0x80u) != 0 && v65 )
    {
      v213 = *(_OWORD *)(v11 + 0x398);
      IppLocalitySetManagedAddressConfig(&v213);
    }
  }
  if ( v63 )
  {
    v67 = (MEMORY[0xFFFFF78000000008] / 0x2710ui64 * (unsigned __int128)0x624DD2F1A9FBE77ui64) >> 0x40;
    v68 = v67 + ((MEMORY[0xFFFFF78000000008] / 0x2710ui64 - v67) >> 1);
    v69 = 1;
    v70 = v68 >> 8;
    if ( (_DWORD)v70 != 0xFFFFFFFF )
      v69 = v70 + 1;
    IppTimerUpdateNextExpirationTick(v70, v69);
    IppNotifyInterfaceChange(v11, 0, 0, 0i64, 3);
  }
  v71 = v176;
  if ( v176 || (v66 = *(unsigned int *)(*(_QWORD *)(v11 + 0x28) + 0x24i64), (v66 & 2) == 0) )
  {
    if ( *(_DWORD *)v179 < 3u )
      *(_QWORD *)v179 = 0i64;
  }
  if ( (unsigned __int8)NetioNcmFastCheckIsAoAcCapable(v66, v60, v61) )
  {
    if ( *(_DWORD *)(*(_QWORD *)(v11 + 0x28) + 0x14i64) != 0x83 )
    {
      v72 = ExAllocatePoolWithTag((POOL_TYPE)0x200, 0x30ui64, 0x676E7049u);
      v73 = v72;
      if ( v72 )
      {
        memset(v72, 0, 0x30ui64);
        _InterlockedAdd((volatile signed __int32 *)(v11 + 0x90), 1u);
        v73[2] = v11;
        v73[1] = IppActiveReferenceWorker;
        *((_BYTE *)v73 + 0x18) = 1;
        *((_DWORD *)v73 + 7) = 1;
        *((_DWORD *)v73 + 8) = 2;
        v73[5] = 0i64;
        NetioInsertWorkQueue(v11 + 0xF0, v73);
      }
    }
  }
  if ( v175 && v175 != *(_DWORD *)(v11 + 0x1B8) )
  {
    v74 = v175;
    *(_DWORD *)(v11 + 0x1B8) = v175;
    *(_DWORD *)(v11 + 0x1BC) = IppNeighborReachableTicks(v74);
  }
  KeReleaseInStackQueuedSpinLock(&LockHandle);
  if ( v185 )
    IppFragmentPackets((__int64)Ipv6Global, v185);
  v75 = SpinLock;
  v76 = *((_BYTE *)SpinLock + 4);
  if ( v76 )
    *(_BYTE *)(v11 + 0x1C8) = v76;
  v77 = *((_DWORD *)v75 + 3);
  if ( v77 )
  {
    v78 = _byteswap_ulong(v77);
    v79 = 2 * (unsigned __int64)v78 / 0x3E8;
    if ( !(_DWORD)v79 )
      LODWORD(v79) = v78 != 0;
    *(_DWORD *)(v11 + 0x1C0) = v79;
  }
  v80 = 2 * v71;
  v81 = v177;
  v224 = _mm_load_si128((const __m128i *)&_xmm);
  v197 = v71;
  HIDWORD(v196) = v71;
  v199 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  v82 = v224.m128i_i32[((unsigned __int64)v27 >> 3) & 3];
  if ( v82 == 0xFFFFFFFF )
    v82 = 0x100;
  v175 = v82;
  v198 = v82;
  LODWORD(v196) = 0xFFFFFFFF;
  v83 = 0i64;
  if ( v177 )
    v83 = *(_QWORD *)(v177 + 0x10);
  v84 = *(_QWORD *)v11;
  v207.LockQueue.Next = 0i64;
  v207.LockQueue.Lock = 0i64;
  *(_QWORD *)&v207.OldIrql = 0i64;
  v206.LockQueue.Next = 0i64;
  v206.LockQueue.Lock = 0i64;
  *(_QWORD *)&v206.OldIrql = 0i64;
  KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &v207);
  while ( *(_DWORD *)(v11 + 0x188) )
    ;
  KeAcquireInStackQueuedSpinLockAtDpcLevel((PKSPIN_LOCK)(v84 + 0xC0), &v206);
  v85 = NetBuffer;
  v86 = 0;
  if ( *(int *)(v84 + 0xC8) >= 0 )
  {
    v87 = (_DWORD *)(v84 + 0x100);
    do
    {
      while ( *v87 )
        ;
      ++v86;
      v87 += 0x10;
    }
    while ( v86 <= *(_DWORD *)(v84 + 0xC8) );
    v81 = v177;
  }
  v88 = *(_QWORD *)v11;
  if ( (int)IppValidateSetAllRouteParameters(
              3 - (unsigned int)(v80 != 0),
              v11,
              v83,
              (__int64)&in6addr_any,
              0,
              0i64,
              0,
              3,
              (__int64)&v196,
              Buf2,
              0i64,
              (__int64)&v191) >= 0 )
    IppCommitSetAllRouteParameters(3 - (v80 != 0), v88, v191, (char *)&v196);
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&v206);
  KeReleaseInStackQueuedSpinLock(&v207);
  v89 = v85->CurrentMdl;
  v90 = 0x10i64;
  v91 = 0x10;
  v92 = v85->CurrentMdlOffset + 0x10;
  v170 = 0x10;
  if ( v92 >= v89->ByteCount )
  {
    NdisAdvanceNetBufferDataStart(v85, 0x10u, 0, 0i64);
  }
  else
  {
    v85->DataOffset += 0x10;
    v85->DataLength -= 0x10;
    v85->CurrentMdlOffset = v92;
  }
  while ( 1 )
  {
    v93 = v85->DataLength < 2;
    v183 = 0;
    if ( v93 )
      break;
    v94 = NdisGetDataBuffer(v85, 2u, &v183, 1u, 0);
    N_length = 8 * (unsigned __int8)v94[1];
    if ( !N_length )
      break;
    v96 = N_length;
    v173 = N_length;
    if ( N_length > v85->DataLength )
      break;
    switch ( *v94 )
    {
      case 3:
        memset(v223, 0, sizeof(v223));
        *(_QWORD *)v214 = 0i64;
        v215 = 0i64;
        v188 = (char *)NdisGetDataBuffer(v85, v96, v223, 1u, 0);
        v100 = v188;
        v102 = v188[2];
        v103 = _byteswap_ulong(*((_DWORD *)v188 + 1));
        v104 = v188 + 0x10;
        v167 = v102;
        v101 = v102;
        LODWORD(v185) = v102;
        v105 = 2 * v103;
        v106 = _byteswap_ulong(*((_DWORD *)v188 + 2));
        if ( (2 * v103) >> 1 != v103 )
          v105 = 0xFFFFFFFF;
        v176 = v105;
        v107 = 2 * v106;
        v43 = (2 * v106) >> 1 == v106;
        v108 = v188 + 0x10;
        if ( !v43 )
          v107 = 0xFFFFFFFF;
        v174 = v107;
        v109 = v107;
        if ( v80 <= v107 )
          v109 = v80;
        v110 = v102 >> 3;
        v111 = v102 & 7;
        v172 = v109;
        v80 = v109;
        for ( i = 0; i < 0x10; ++i )
        {
          if ( i >= (unsigned int)v110 )
            v113 = 0;
          else
            v113 = *v108;
          (v108++)[(char *)v214 - v104] = v113;
        }
        v81 = v177;
        if ( v111 )
          *((_BYTE *)v214 + v110) = v104[v110] & (0xFF << (8 - v111));
        v90 = *(_QWORD *)v214;
        if ( LOBYTE(v214[0]) == 0xFE )
        {
          if ( (BYTE1(v214[0]) & 0xC0) == 0x80 )
            goto LABEL_326;
        }
        else if ( LOBYTE(v214[0]) == 0xFF )
        {
LABEL_326:
          v96 = v173;
LABEL_327:
          v91 = v170;
          break;
        }
        v114 = v100[3];
        if ( v114 < 0 && ((*(_BYTE *)(v11 + 0x194) & 1) == 0 || v167 != 0x40) )
        {
          v203 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
          v115 = 0xFFFFFFFF;
          v116 = 3 - (v105 != 0);
          LODWORD(v200) = 0xFFFFFFFF;
          if ( v105 != 0xFFFFFFFF )
            v115 = v105 >> 1;
          v117 = *(_QWORD *)v11;
          v201 = v115;
          HIDWORD(v200) = v115;
          v202 = v175;
          v209.LockQueue.Next = 0i64;
          v209.LockQueue.Lock = 0i64;
          *(_QWORD *)&v209.OldIrql = 0i64;
          v208.LockQueue.Next = 0i64;
          v208.LockQueue.Lock = 0i64;
          *(_QWORD *)&v208.OldIrql = 0i64;
          KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &v209);
          while ( *(_DWORD *)(v11 + 0x188) )
            ;
          KeAcquireInStackQueuedSpinLockAtDpcLevel((PKSPIN_LOCK)(v117 + 0xC0), &v208);
          v85 = NetBuffer;
          v118 = 0;
          if ( *(int *)(v117 + 0xC8) >= 0 )
          {
            v119 = (_DWORD *)(v117 + 0x100);
            do
            {
              while ( *v119 )
                ;
              ++v118;
              v119 += 0x10;
            }
            while ( v118 <= *(_DWORD *)(v117 + 0xC8) );
            v85 = NetBuffer;
          }
          v120 = *(_QWORD *)v11;
          if ( (int)IppValidateSetAllRouteParameters(
                      v116,
                      v11,
                      0i64,
                      (__int64)v214,
                      v167,
                      0i64,
                      0,
                      3,
                      (__int64)&v200,
                      0i64,
                      0i64,
                      (__int64)&v192) >= 0 )
            IppCommitSetAllRouteParameters(v116, v120, v192, (char *)&v200);
          KeReleaseInStackQueuedSpinLockFromDpcLevel(&v208);
          KeReleaseInStackQueuedSpinLock(&v209);
          v100 = v188;
          v90 = *(_QWORD *)v214;
          v101 = v167;
          v114 = v188[3];
        }
        if ( (v114 & 1) != 0 )
        {
          IppUpdateAutoConfiguredRoute((__int64 *)v11, (__int64)Buf2, v81, (int)v214, v101, v105, v175);
          v114 = v100[3];
          v90 = *(_QWORD *)v214;
        }
        if ( (_BYTE)v90 != 0xFE || (BYTE1(v214[0]) & 0xC0) != 0xC0 )
        {
          if ( (v114 & 0x10) != 0 )
          {
            v121 = v100[0xF];
            goto LABEL_242;
          }
          if ( (v114 & 0x40) != 0 )
          {
            v121 = *(_BYTE *)(v11 + 0x1CA);
LABEL_242:
            v165 = v121;
          }
          else
          {
            v121 = 0;
            v165 = 0;
          }
          if ( v121 && v121 <= v101 )
          {
            v122 = *(const UCHAR **)v11;
            v123 = 0i64;
            v216 = 0ui64;
            v124 = v121 >> 3;
            v171 = 1;
            v125 = 0;
            v180 = v122;
            do
            {
              if ( v125 >= (unsigned int)v124 )
                v126 = 0;
              else
                v126 = *((_BYTE *)v214 + v123);
              *((_BYTE *)&v216 + v123) = v126;
              ++v125;
              ++v123;
            }
            while ( v125 < 0x10 );
            if ( (v121 & 7) != 0 )
              *((_BYTE *)&v216 + v124) = *((_BYTE *)v214 + v124) & (0xFF << (8 - (v121 & 7)));
            v127 = (PKSPIN_LOCK)(v122 + 0x280);
            SpinLock = (PKSPIN_LOCK)(v122 + 0x280);
            NewIrql = KeAcquireSpinLockRaiseToDpc((PKSPIN_LOCK)v122 + 0x50);
            v128 = (UCHAR *)(v122 + 0x288);
            v129 = 0;
            v179 = (UCHAR *)(v122 + 0x288);
            v130 = (UCHAR *)*((_QWORD *)v122 + 0x51);
            v131 = MEMORY[0xFFFFF78000000008] / 0x2710ui64 / 0x1F4;
            v181 = (_LIST_ENTRY *)v131;
            if ( v130 == v122 + 0x288 )
            {
LABEL_296:
              v148 = v176;
              if ( v176 )
              {
                v149 = *(_BYTE *)(*(_QWORD *)(*(_QWORD *)v11 + 0x28i64) + 0x44D2i64) == (_BYTE)v129 ? (_BYTE)v129 : *(_DWORD *)(v11 + 0x208) >= 0xAu;
                if ( !v149 )
                {
                  v150 = (char *)ExAllocatePoolWithTag((POOL_TYPE)0x200, 0x40ui64, 0x676E7049u);
                  if ( v150 )
                  {
                    _InterlockedIncrement((volatile signed __int32 *)(v11 + 0x90));
                    v152 = v216;
                    *((_DWORD *)v150 + 8) = v174;
                    *((_DWORD *)v150 + 0xE) = 0;
                    *(_OWORD *)(v150 + 0x26) = v152;
                    *((_QWORD *)v150 + 2) = v11;
                    *((_DWORD *)v150 + 6) = v131;
                    *((_DWORD *)v150 + 7) = v148;
                    v150[0x24] = v121;
                    IppAddSitePrefixEntry((__int64)v127, (__int64)v150);
                  }
                  else if ( *((_DWORD *)&MICROSOFT_TCPIP_PROVIDER_Context + 9) == 1
                         && (BYTE3(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Flink) & 8) != 0 )
                  {
                    McTemplateK0z(
                      (PMCGEN_TRACE_CONTEXT)&MICROSOFT_TCPIP_PROVIDER_Context,
                      &TCPIP_MEMORY_FAILURES,
                      v151,
                      L"site prefix entry (IPNG)");
                  }
                }
              }
            }
            else
            {
              v132 = v171;
              do
              {
                v133 = v129;
                v193 = *(UCHAR **)v130;
                if ( *((_QWORD *)v130 + 2) == v11
                  && *(_OWORD *)(v130 + 0x26) == v216
                  && v130[0x24] == v121
                  && *((_DWORD *)v130 + 0xE) == v129 )
                {
                  v132 = v129;
                  *((_DWORD *)v130 + 7) = v176;
                  v133 = 1;
                  *((_DWORD *)v130 + 8) = v174;
                  *((_DWORD *)v130 + 6) = v131;
                }
                v134 = *((_DWORD *)v130 + 7);
                if ( v134 == 0xFFFFFFFF )
                {
                  v136 = 0xFFFFFFFF;
                }
                else
                {
                  v135 = v131 - *((_DWORD *)v130 + 6);
                  if ( v135 < v134 )
                    v136 = v134 - v135;
                  else
                    v136 = v129;
                }
                v137 = *((_DWORD *)v130 + 8);
                *((_DWORD *)v130 + 7) = v136;
                if ( v137 == 0xFFFFFFFF )
                {
                  v139 = 0xFFFFFFFF;
                }
                else
                {
                  v138 = v131 - *((_DWORD *)v130 + 6);
                  if ( v138 < v137 )
                    v139 = v137 - v138;
                  else
                    v139 = v129;
                }
                *((_DWORD *)v130 + 6) = v131;
                if ( v139 > v136 )
                  v139 = v136;
                *((_DWORD *)v130 + 8) = v139;
                if ( v136 )
                {
                  v140 = v136 + v131;
                  if ( v136 > 0 )
                  {
                    if ( v140 )
                    {
                      v141 = *((_DWORD *)v122 + 0xA8);
                      if ( !v141 || (int)(v140 - v141) < 0 )
                      {
                        *((_DWORD *)v122 + 0xA8) = v140;
                        IppTimerUpdateNextExpirationTick(v131, v140);
                        v128 = v179;
                        v129 = 0;
                      }
                    }
                  }
                  if ( v133 )
                  {
                    v142 = (volatile signed __int32 *)*((_QWORD *)v130 + 2);
                    v143 = *(_QWORD *)(*(_QWORD *)v142 + 0x28i64);
                    if ( *((_DWORD *)v130 + 0xE) == 1 && RoReferenceEx((volatile signed __int32 *)(v143 + 0x4418)) )
                    {
                      v144 = *(_QWORD *)(v143 + 0x4410);
                      if ( RoReferenceEx((volatile signed __int32 *)(v144 + 0x130)) )
                      {
                        v145 = (char *)ExAllocatePoolWithTag((POOL_TYPE)0x200, 0x78ui64, 0x746E5049u);
                        v146 = v145;
                        if ( v145 )
                        {
                          memset(v145, 0, 0x38ui64);
                          *((_QWORD *)v146 + 1) = IppNotifySitePrefixChangeAtPassive;
                          *((_QWORD *)v146 + 2) = v146 + 0x38;
                          *((_DWORD *)v146 + 6) = 0;
                          _InterlockedIncrement(v142 + 0x24);
                          *(_OWORD *)(v146 + 0x38) = *(_OWORD *)v130;
                          *(_OWORD *)(v146 + 0x48) = *((_OWORD *)v130 + 1);
                          *(_OWORD *)(v146 + 0x58) = *((_OWORD *)v130 + 2);
                          *(_OWORD *)(v146 + 0x68) = *((_OWORD *)v130 + 3);
                          NetioInsertWorkQueue(*(_QWORD *)v142 + 0x50i64, v146);
                        }
                        else
                        {
                          if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v144 + 0x130), 0xFFFFFFFE) == 3 )
                            KeSetEvent((PRKEVENT)(v144 + 0x138), 0, 0);
                          IppDereferenceNsiClientContext(v143);
                          if ( *((_DWORD *)&MICROSOFT_TCPIP_PROVIDER_Context + 9) == 1
                            && (BYTE3(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Flink) & 8) != 0 )
                          {
                            McTemplateK0z(
                              (PMCGEN_TRACE_CONTEXT)&MICROSOFT_TCPIP_PROVIDER_Context,
                              &TCPIP_MEMORY_FAILURES,
                              v147,
                              L"site prefix change notify workitem (IPNG)");
                          }
                        }
                      }
                      else
                      {
                        IppDereferenceNsiClientContext(v143);
                      }
                      v128 = v179;
                      v129 = 0;
                      LODWORD(v131) = (_DWORD)v181;
                    }
                    v122 = v180;
                    v121 = v165;
                  }
                }
                else
                {
                  IppRemoveSitePrefixEntry(v130);
                  v128 = v179;
                  v129 = 0;
                }
                v130 = v193;
              }
              while ( v193 != v128 );
              v43 = v132 == 0;
              v85 = NetBuffer;
              if ( !v43 )
              {
                v127 = SpinLock;
                goto LABEL_296;
              }
            }
            KeReleaseSpinLock(SpinLock, NewIrql);
            v81 = v177;
            v105 = v176;
            v114 = v188[3];
          }
          v80 = v172;
        }
        if ( (v114 & 0x40) != 0 )
        {
          v153 = v174;
          if ( v174 <= v105 )
          {
            v154 = *(unsigned __int8 *)(*(_QWORD *)(v11 + 0x28) + 0xBi64);
            if ( v154 + (_DWORD)v185 == 0x80 )
            {
              v155 = (unsigned __int8)v185;
              if ( (*(_BYTE *)(v11 + 0x194) & 1) != 0 && (_BYTE)v185 == 0x40 )
              {
                Ipv6pUpdateSitePrefix(1, (__int64 *)v11, v214, 0x40u, v105, v174);
              }
              else
              {
                v210.LockQueue.Next = 0i64;
                v210.LockQueue.Lock = 0i64;
                *(_QWORD *)&v210.OldIrql = 0i64;
                KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &v210);
                while ( *(_DWORD *)(v11 + 0x188) )
                  ;
                Ipv6pUpdateAutoConfiguredAddressesUnderLock(v11, (char *)v214, v155, v105, v153, 0, Buf2);
                KeReleaseInStackQueuedSpinLock(&v210);
              }
            }
            else if ( WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                   && BYTE1(WPP_GLOBAL_Control->Timer) >= 3u
                   && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x40) != 0 )
            {
              WPP_SF_Dd(
                WPP_GLOBAL_Control->AttachedDevice,
                0xBi64,
                &WPP_7f49f6ec16883d4b2ce7b6b90c474a20_Traceguids,
                (unsigned int)v185,
                v154);
            }
          }
          else if ( WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                 && BYTE1(WPP_GLOBAL_Control->Timer) >= 3u
                 && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x40) != 0 )
          {
            WPP_SF_(WPP_GLOBAL_Control->AttachedDevice, 0xAi64, &WPP_7f49f6ec16883d4b2ce7b6b90c474a20_Traceguids);
          }
          v80 = v172;
        }
        goto LABEL_326;
      case 0x18:
        v221[0] = 0i64;
        v221[1] = 0i64;
        v221[2] = 0i64;
        v218[0] = 0i64;
        v218[1] = 0i64;
        v90 = (__int64)NdisGetDataBuffer(v85, N_length, v221, 1u, 0);
        v225 = _mm_load_si128((const __m128i *)&_xmm);
        v175 = v225.m128i_u32[((unsigned __int64)*(unsigned __int8 *)(v90 + 3) >> 3) & 3];
        if ( v175 == 0xFFFFFFFF )
          break;
        v97 = *(_BYTE *)(v90 + 2);
        v98 = _byteswap_ulong(*(_DWORD *)(v90 + 4));
        v99 = 2 * v98;
        if ( (2 * v98) >> 1 != v98 )
          v99 = 0xFFFFFFFF;
        CopyPrefix((__int64)v218, (_BYTE *)(v90 + 8), *(unsigned __int8 *)(v90 + 2), 0x10u);
        IppUpdateAutoConfiguredRoute((__int64 *)v11, (__int64)Buf2, v81, (int)v218, v97, v99, v175);
        if ( v80 <= v99 )
          v99 = v80;
        v80 = v99;
        goto LABEL_327;
      case 0x19:
        if ( (*(_BYTE *)(v11 + 0x194) & 0x40) != 0 )
        {
          Ipv6pUpdateRDNSS(v11, v85, (__int64)Buf2, v189, &v168);
          goto LABEL_332;
        }
        break;
      default:
        if ( *v94 == 0x1F && (*(_BYTE *)(v11 + 0x194) & 0x40) != 0 )
        {
          Ipv6pUpdateDNSSL(v11, v85, Buf2, v189, &v168);
          goto LABEL_332;
        }
        break;
    }


    if ( v96 )
    {
      v156 = v96 + v85->CurrentMdlOffset;
      if ( v156 >= *(_DWORD *)(v85->Link.Region + 0x28) )
      {
        NdisAdvanceNetBufferDataStart(v85, v96, 0, 0i64);
      }
      else
      {
        v85->DataOffset += v96;
        v85->DataLength -= v96;
        v85->CurrentMdlOffset = v156;
      }
    }
LABEL_332:
    v91 += v96;
    v170 = v91;
  }
  v157 = v85->CurrentMdlOffset;
  if ( v157 < v91 )
  {
    NdisRetreatNetBufferDataStart(v85, v91, 0, NetioAllocateMdl);
  }
  else
  {
    v85->DataOffset -= v91;
    v85->DataLength += v91;
    v85->CurrentMdlOffset = v157 - v91;
  }
  if ( v168 )
  {
    v195[2] = 0i64;
    v195[0] = 1i64;
    v195[1] = 0i64;
    Ipv6pNotifyRouterInformationChange(v11, v90, (__int64)v195);
  }
  KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &LockHandle);
  while ( *(_DWORD *)(v11 + 0x188) )
    ;
  v158 = v184;
  if ( (*(_BYTE *)(v11 + 0x190) & 2) == 0 && (*(_DWORD *)(*(_QWORD *)(v11 + 0x28) + 0x24i64) & 2) == 0 )
  {
    v159 = Ipv6pFindPotentialRouterUnderLock(v11, (_QWORD *)v184[0x20]);
    if ( v159 )
    {
      if ( !*((_DWORD *)v159 + 5) )
      {
        *((_DWORD *)v159 + 4) = 3;
        if ( v80 >= 0xE10 )
          v160 = v80 >> 1;
        else
          v160 = 0x708;
        v161 = v189;
        v162 = v160 + v189;
        *((_DWORD *)v159 + 5) = v160 + v189;
        if ( !v162 )
        {
          *((_DWORD *)v159 + 5) = 1;
          v162 = 1;
        }
        IppTimerUpdateNextExpirationTick(v161, v162);
      }
    }
  }
  KeReleaseInStackQueuedSpinLock(&LockHandle);
  result = v158[1];
  *(_DWORD *)(result + 0x8C) = 0;
  if ( v81 )
  {
    v163 = *(_DWORD *)(v81 + 4);
    if ( v163 == 2 )
    {
      v164 = *(_BYTE *)(v81 + 0x45);
      if ( (v164 & 1) == 0 && (v164 & 8) != 0 )
      {
        _InterlockedAdd((volatile signed __int32 *)(*(_QWORD *)(v81 + 8) + 0x134i64), 1u);
        _InterlockedAdd((volatile signed __int32 *)(*(_QWORD *)(*(_QWORD *)(v81 + 8) + 0x150i64) + 0x38i64), 1u);
        v163 = *(_DWORD *)(v81 + 4);
      }
    }
    if ( v163 <= 0 )
      KeBugCheck(0x1Cu);
    result = (unsigned int)_InterlockedExchangeAdd((volatile signed __int32 *)(v81 + 4), 0xFFFFFFFF);
    if ( (_DWORD)result == 1 )
      result = IppCleanupNeighbor(v81);
  }
  return result;
}