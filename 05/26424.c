__int64 __fastcall Ipv6pHandleRouterAdvertisement(__int64 ICMPv6Header, _QWORD *a2, _DWORD *a3)
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
  __int64 ipv6Header; // rax
  __int64 result; // rax
  UCHAR v17; // r8
  int v18; // eax
  IN6_ADDR *v19; // rcx
  __int64 v20; // rcx
  char v21; // r8
  KSPIN_LOCK *N_buffer00; // rax
  PMDL v23; // rcx
  unsigned __int16 v24; // r12
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
  unsigned int v36; // er8
  unsigned int v37; // eax
  unsigned int v38; // eax
  _QWORD *v39; // rdi
  __int64 v40; // rax
  _QWORD *v41; // rax
  char v42; // r10
  _DWORD *v43; // rax
  __int64 v44; // r15
  __int64 v45; // rcx
  size_t v46; // r13
  unsigned int v47; // eax
  unsigned int v48; // edi
  PRTL_DYNAMIC_HASH_TABLE_ENTRY v49; // rax
  __int64 v50; // rcx
  __int64 v51; // r14
  _LIST_ENTRY **v52; // rdi
  char v53; // al
  __int64 v54; // rax
  __int64 v55; // rdi
  __int64 v56; // r9
  __int64 *v57; // rcx
  unsigned int v58; // edx
  __int64 v59; // rdx
  __int64 v60; // r8
  bool v61; // di
  char v62; // r15
  char v63; // r12
  char v64; // r13
  __int64 v65; // rcx
  __int64 v66; // rdx
  unsigned __int64 v67; // rcx
  unsigned int v68; // edx
  unsigned __int64 v69; // rcx
  int v70; // er15
  _QWORD *v71; // rax
  _QWORD *v72; // rdi
  int v73; // ecx
  PKSPIN_LOCK v74; // rcx
  char v75; // al
  unsigned int v76; // er8
  unsigned __int32 v77; // er8
  unsigned __int64 v78; // rcx
  unsigned int v79; // er12
  __int64 v80; // r13
  int v81; // ecx
  __int64 v82; // r15
  __int64 v83; // rbx
  PNET_BUFFER v84; // r14
  int v85; // edx
  _DWORD *v86; // rcx
  __int64 v87; // rbx
  unsigned __int16 v88; // bx
  unsigned int v89; // ecx
  _BYTE *N_buffer01; // rax
  unsigned __int16 N_length; // cx
  unsigned __int16 v92; // r15
  unsigned __int8 *N_buffer02; // rdx
  char v94; // bl
  unsigned __int32 v95; // ecx
  unsigned int v96; // edi
  _BYTE *v97; // rbx
  unsigned __int8 v98; // di
  unsigned __int8 v99; // r9
  unsigned __int32 v100; // edx
  char *v101; // r11
  unsigned int v102; // er15
  unsigned __int32 v103; // ecx
  unsigned int v104; // edx
  char *v105; // rcx
  int v106; // eax
  __int64 v107; // r8
  int v108; // er9
  unsigned int i; // eax
  char v110; // dl
  char v111; // dl
  bool v112; // zf
  unsigned int v113; // ecx
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
  int v147; // ebx
  char v148; // al
  char *v149; // rax
  __int128 v150; // xmm0
  unsigned int v151; // edi
  int v152; // er8
  unsigned __int8 v153; // bl
  unsigned int v154; // eax
  __int64 v155; // rdx
  _QWORD *v156; // rbx
  _QWORD *v157; // rax
  int v158; // er12
  unsigned int v159; // ecx
  unsigned int v160; // edx
  int v161; // eax
  char v162; // cl
  unsigned __int8 v163; // [rsp+60h] [rbp-A0h]
  unsigned __int16 v164; // [rsp+62h] [rbp-9Eh]
  unsigned __int8 v165; // [rsp+64h] [rbp-9Ch]
  char v166; // [rsp+64h] [rbp-9Ch]
  __int16 v167; // [rsp+66h] [rbp-9Ah]
  char v168; // [rsp+68h] [rbp-98h] BYREF
  KIRQL NewIrql; // [rsp+69h] [rbp-97h]
  char v170; // [rsp+6Ah] [rbp-96h]
  int v171; // [rsp+6Ch] [rbp-94h]
  unsigned __int32 v172; // [rsp+70h] [rbp-90h]
  unsigned int v173; // [rsp+74h] [rbp-8Ch]
  unsigned int v174; // [rsp+78h] [rbp-88h]
  __int64 v175; // [rsp+80h] [rbp-80h]
  void *Buf2; // [rsp+88h] [rbp-78h]
  UCHAR *v177; // [rsp+90h] [rbp-70h]
  const UCHAR *v178; // [rsp+98h] [rbp-68h]
  _LIST_ENTRY *v179; // [rsp+A0h] [rbp-60h]
  __int16 v180[2]; // [rsp+A8h] [rbp-58h] BYREF
  __int16 v181; // [rsp+ACh] [rbp-54h] BYREF
  _QWORD *v182; // [rsp+B0h] [rbp-50h]
  _QWORD *v183; // [rsp+B8h] [rbp-48h]
  PNET_BUFFER NetBuffer; // [rsp+C0h] [rbp-40h]
  PKSPIN_LOCK SpinLock; // [rsp+C8h] [rbp-38h]
  char *v186; // [rsp+D0h] [rbp-30h]
  unsigned __int64 v187; // [rsp+D8h] [rbp-28h]
  struct _KLOCK_QUEUE_HANDLE LockHandle; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v189; // [rsp+F8h] [rbp-8h] BYREF
  __int64 v190; // [rsp+100h] [rbp+0h] BYREF
  UCHAR *v191; // [rsp+108h] [rbp+8h]
  __int64 v192; // [rsp+110h] [rbp+10h] BYREF
  __int64 v193[3]; // [rsp+118h] [rbp+18h] BYREF
  __int64 v194; // [rsp+130h] [rbp+30h] BYREF
  int v195; // [rsp+138h] [rbp+38h]
  int v196; // [rsp+13Ch] [rbp+3Ch]
  __m128i v197; // [rsp+140h] [rbp+40h]
  __int64 v198; // [rsp+150h] [rbp+50h] BYREF
  unsigned int v199; // [rsp+158h] [rbp+58h]
  unsigned __int32 v200; // [rsp+15Ch] [rbp+5Ch]
  __m128i v201; // [rsp+160h] [rbp+60h]
  struct _KLOCK_QUEUE_HANDLE v202; // [rsp+170h] [rbp+70h] BYREF
  struct _KLOCK_QUEUE_HANDLE v203; // [rsp+188h] [rbp+88h] BYREF
  struct _KLOCK_QUEUE_HANDLE v204; // [rsp+1A0h] [rbp+A0h] BYREF
  struct _KLOCK_QUEUE_HANDLE v205; // [rsp+1B8h] [rbp+B8h] BYREF
  struct _KLOCK_QUEUE_HANDLE v206; // [rsp+1D0h] [rbp+D0h] BYREF
  struct _KLOCK_QUEUE_HANDLE v207; // [rsp+1E8h] [rbp+E8h] BYREF
  struct _KLOCK_QUEUE_HANDLE v208; // [rsp+200h] [rbp+100h] BYREF
  struct _RTL_DYNAMIC_HASH_TABLE_CONTEXT Context; // [rsp+218h] [rbp+118h] BYREF
  __int128 v210; // [rsp+230h] [rbp+130h] BYREF
  __int128 v211; // [rsp+240h] [rbp+140h] BYREF
  int v212[2]; // [rsp+250h] [rbp+150h] BYREF
  __int64 v213; // [rsp+258h] [rbp+158h]
  __int128 v214; // [rsp+260h] [rbp+160h]
  IN6_ADDR a; // [rsp+270h] [rbp+170h] BYREF
  __int64 v216[2]; // [rsp+280h] [rbp+180h] BYREF
  __int64 Storage[2]; // [rsp+290h] [rbp+190h] BYREF
  __int64 v218[3]; // [rsp+2A0h] [rbp+1A0h] BYREF
  __int64 v219[5]; // [rsp+2B8h] [rbp+1B8h] BYREF
  char v220[32]; // [rsp+2E0h] [rbp+1E0h] BYREF
  char v221[32]; // [rsp+300h] [rbp+200h] BYREF
  __m128i v222; // [rsp+320h] [rbp+220h]
  __m128i v223; // [rsp+330h] [rbp+230h]
  char v224[32]; // [rsp+340h] [rbp+240h] BYREF

  v3 = a2[1];
  v5 = (IN6_ADDR *)a2[3];
  AlignOffset = 0;
  v182 = a2;
  Buf2 = v5;
  v9 = *(_NET_BUFFER **)(v3 + 8);
  v10 = a2[26];
  NetBuffer = v9;
  v178 = 0i64;
  v173 = 0;
  v11 = *(_QWORD *)(v10 + 8);
  Storage[0] = 0i64;
  Storage[1] = 0i64;
  v183 = 0i64;
  v165 = *(_BYTE *)(*(_QWORD *)(v11 + 0x28) + 0xAi64);
  v168 = 0;
  v12 = (MEMORY[0xFFFFF78000000008] / 0x2710ui64 * (unsigned __int128)0x624DD2F1A9FBE77ui64) >> 0x40;
  v203.LockQueue.Next = 0i64;
  v203.LockQueue.Lock = 0i64;
  *(_QWORD *)&v203.OldIrql = 0i64;
  v13 = a2[0x1B];
  v14 = (v12 + ((MEMORY[0xFFFFF78000000008] / 0x2710ui64 - v12) >> 1)) >> 8;
  *a3 = 0x1C;
  v179 = (_LIST_ENTRY *)v13;
  ipv6Header = a2[0x22];
  v187 = v14;
  LockHandle.LockQueue.Next = 0i64;
  LockHandle.LockQueue.Lock = 0i64;
  *(_QWORD *)&LockHandle.OldIrql = 0i64;


  if ( *(_BYTE *)(ipv6Header + 7) != 0xFF )
  {
    result = a2[1];
    *(_DWORD *)(result + 0x8C) = 0xC000021B;
    *a3 = 0x11;
    return result;
  }

  if ( *(_BYTE *)(ICMPv6Header + 1) )
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


  N_buffer00 = (KSPIN_LOCK *)NdisGetDataBuffer(v9, 0x10u, Storage, 1u, AlignOffset);
  v23 = v9->CurrentMdl;
  v24 = 0x10;
  v25 = N_buffer00;
  v26 = v9->CurrentMdlOffset + 0x10;
  SpinLock = N_buffer00;


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
  v172 = _byteswap_ulong(*((_DWORD *)v25 + 2));
  v174 = v29;
  while ( 1 )
  {
    v30 = v9->DataLength;
    v180[0] = 0;

    if ( v30 < 2 )
      break;
    v31 = (KIRQL *)NdisGetDataBuffer(v9, 2u, v180, 1u, 0);
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
          if ( v32 != v165 + 2i64 )
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
          v178 = (const UCHAR *)NdisGetDataBuffer(v9, v32, v224, 1u, 0);
        }
        break;
      case 3u:
        memset(v220, 0, sizeof(v220));
        if ( v32 != 0x20 || *((_BYTE *)NdisGetDataBuffer(v9, 0x20u, v220, 1u, 0) + 2) > 0x80u )
        {
          *a3 = 0x17;
          goto LABEL_70;
        }
        break;
      case 5u:
        v192 = 0i64;
        if ( v32 != 8 )
        {
          *a3 = 0x16;
          goto LABEL_70;
        }
        v173 = _byteswap_ulong(*((_DWORD *)NdisGetDataBuffer(v9, 8u, &v192, 1u, 0) + 1));
        break;
      case 0x18u:
        v218[0] = 0i64;
        v218[1] = 0i64;
        v218[2] = 0i64;
        if ( v32 > 0x18u
          || (v34 = *((_BYTE *)NdisGetDataBuffer(v9, v32, v218, 1u, 0) + 2), v34 > 0x80u)
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
    v38 = v24 + v30;
    v9->DataLength = v38;
  }


  if ( v38 != v24 )
  {
    if ( *a3 == 0x1C )
      *a3 = 0x1B;
    result = v182[1];
    *(_DWORD *)(result + 0x8C) = 0xC000021B;
    return result;
  }


  v39 = v182;
  if ( (BYTE5(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Flink) & 2) != 0 )
    IppTraceNeighborDiscovery(v11, (__int128 *)Buf2, **(__int128 ***)(v182[0x1A] + 0x10i64), 0x12);
  KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &LockHandle);
  while ( *(_DWORD *)(v11 + 0x188) )
    ;
  if ( (*(_BYTE *)(v11 + 0x190) & 2) != 0 || (*(_BYTE *)(v11 + 0x191) & 8) == 0 )
    goto LABEL_360;
  v40 = *(_QWORD *)(v11 + 0x28);
  *(_BYTE *)(v11 + 0x1E8) = 1;


  if ( (*(_DWORD *)(v40 + 0x24) & 2) == 0 )
  {
    v41 = Ipv6pFindPotentialRouterUnderLock(v11, (_QWORD *)v39[0x20]);
    if ( v41 )
    {
      v112 = *((_DWORD *)v41 + 6) == 5;
      v177 = (UCHAR *)(v41 + 2);
      *((_BYTE *)v41 + 0x1C) = v42;
      if ( !v112 )
      {
        *((_DWORD *)v41 + 6) = 5;
        Ipv6NotifyPotentialRouterChange(v11, (__int64)v41);
      }
      goto LABEL_89;
    }
LABEL_360:

    KeReleaseInStackQueuedSpinLock(&LockHandle);
    result = v39[1];
    *(_DWORD *)(result + 0x8C) = 0;
    return result;
  }
  v177 = (UCHAR *)(v11 + 0x1E0);
LABEL_89:
  KeAcquireInStackQueuedSpinLockAtDpcLevel((PKSPIN_LOCK)(v11 + 0x120), &v203);
  while ( *(_DWORD *)(v11 + 0x128) )
    ;
  v43 = *(_DWORD **)v11;
  v44 = *(_QWORD *)(v11 + 0x150);
  Context.Signature = 0i64;
  v45 = *((_QWORD *)v43 + 5);
  v186 = (char *)v44;
  v46 = *(unsigned __int16 *)(*(_QWORD *)(v45 + 0x10) + 6i64);
  v175 = 0i64;
  v47 = RtlCompute37Hash((unsigned int)g_37HashSeed, Buf2, v46);
  v48 = RtlCompute37Hash(v47, v11 + 8, 4i64) | 0x80000000;
  v202.LockQueue.Next = 0i64;
  v202.LockQueue.Lock = 0i64;
  *(_QWORD *)&v202.OldIrql = 0i64;
  *(_OWORD *)&Context.ChainHead = 0i64;
  _InterlockedAdd((volatile signed __int32 *)(v44 + 8), 1u);

  if ( !KeTestSpinLock((PKSPIN_LOCK)v44) )
  {
    _InterlockedDecrement((volatile signed __int32 *)(v44 + 8));
    KeAcquireInStackQueuedSpinLockAtDpcLevel((PKSPIN_LOCK)v44, &v202);
    _InterlockedAdd((volatile signed __int32 *)(v44 + 8), 1u);
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&v202);
  }

  v49 = RtlLookupEntryHashTable((PRTL_DYNAMIC_HASH_TABLE)(v44 + 0x10), v48, &Context);
  v50 = 0i64;

  if ( v49 )
  {
    v51 = 0i64;
    do
    {
      v52 = &v49[0xFFFFFFFE].Linkage.Blink;
      if ( v49[0xFFFFFFFEi64].Signature == v11
        && (!v179 || v52[2] == v179)
        && !memcmp(v52 + 0x11, Buf2, v46)
        && (!v51 || *((_DWORD *)v52 + 0x10) > *(_DWORD *)(v51 + 0x40)) )
      {
        v51 = (__int64)v52;
      }
      v49 = RtlGetNextEntryHashTable((PRTL_DYNAMIC_HASH_TABLE)(v44 + 0x10), &Context);
    }
    while ( v49 );
    v44 = (__int64)v186;
    v175 = v51;
    v50 = v51;
    if ( v51 )
    {
      if ( *(_DWORD *)(v51 + 4) == 1 )
      {
        v53 = *(_BYTE *)(v51 + 0x45);
        if ( (v53 & 1) == 0 && (v53 & 8) != 0 )
        {
          _InterlockedDecrement((volatile signed __int32 *)(v11 + 0x134));
          _InterlockedDecrement((volatile signed __int32 *)(*(_QWORD *)(v11 + 0x150) + 0x38i64));
          if ( *(int *)(v11 + 0x134) < 0 )
            *(_DWORD *)(v11 + 0x134) = 0;
          v54 = *(_QWORD *)(v11 + 0x150);
          if ( *(int *)(v54 + 0x38) < 0 )
            *(_DWORD *)(v54 + 0x38) = 0;
        }
      }
      _InterlockedAdd((volatile signed __int32 *)(v51 + 4), 1u);
    }
  }


  _InterlockedDecrement((volatile signed __int32 *)(v44 + 8));
  v55 = (__int64)v179;
  if ( v50 || (v175 = IppCreateAndInitializeNeighbor(v11, (__int64)v179, (__int64)Buf2, 1u), (v50 = v175) != 0) )
  {
    *(_BYTE *)(v50 + 0x45) |= 2u;
    v183 = (_QWORD *)IppUpdateNeighbor(v50, v178, 0, 1, 0);
  }

  v56 = *(_QWORD *)(v55 + 8);
  if ( v173 >= 0x500 && v173 <= *(_DWORD *)(*(_QWORD *)(v55 + 0x28) + 8i64) )
  {
    *(_DWORD *)(v55 + 0x54) = v173;
    v57 = *(__int64 **)(v56 + 0x168);
    v58 = 0;
    while ( v57 != (__int64 *)(v56 + 0x168) )
    {
      if ( !v58 || *((_DWORD *)v57 + 5) < v58 )
        v58 = *((_DWORD *)v57 + 5);
      v57 = (__int64 *)*v57;
    }
    *(_DWORD *)(v56 + 0x178) = v58;
  }


  KeReleaseInStackQueuedSpinLockFromDpcLevel(&v203);
  LOBYTE(v60) = *(_BYTE *)(v11 + 0x191);
  if ( (v60 & 4) != 0 )
  {
    *(_BYTE *)(v11 + 0x191) = v60 & 0xFB;
    Ipv6pResetAutoConfiguredSettings(v11, 8u);
    LOBYTE(v60) = *(_BYTE *)(v11 + 0x191);
  }

  v61 = (v27 & 0x40) != 0;
  v62 = 0;
  v63 = 0;

  if ( v27 >> 7 != (v60 & 1) )
  {
    if ( (v27 & 0x80u) != 0 )
    {
      v62 = 1;
      LOBYTE(v60) = (v27 >> 7) | v60 & 0xFE;
      *(_BYTE *)(v11 + 0x191) = v60;
      if ( *((_DWORD *)&MICROSOFT_TCPIP_PROVIDER_Context + 9) == 1
        && ((__int64)WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Blink & 4) != 0 )
      {
        McTemplateK0qsqqqq(
          (PMCGEN_TRACE_CONTEXT)&MICROSOFT_TCPIP_PROVIDER_Context,
          (__int64)"ManagedAddressConfiguration",
          v60 & 1,
          0,
          **(_DWORD **)v11,
          *(_WORD *)(*(_QWORD *)(*(_QWORD *)v11 + 0x28i64) + 0x1Ci64));
      }
    }
    *(_DWORD *)(*(_QWORD *)v11 + 0x8Ci64) = 1;
  }


  v64 = v62;
  if ( v61 != ((*(_BYTE *)(v11 + 0x191) & 2) != 0) )
  {
    if ( (v27 & 0x40) != 0 )
    {
      v63 = 1;
      LOBYTE(v60) = *(_BYTE *)(v11 + 0x191) & 0xFD | (2 * v61);
      v62 = 1;
      *(_BYTE *)(v11 + 0x191) = v60;
      if ( *((_DWORD *)&MICROSOFT_TCPIP_PROVIDER_Context + 9) == 1
        && ((__int64)WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Blink & 4) != 0 )
      {
        McTemplateK0qsqqqq(
          (PMCGEN_TRACE_CONTEXT)&MICROSOFT_TCPIP_PROVIDER_Context,
          (__int64)"OtherStatefulConfiguration",
          (v60 & 2) != 0,
          0,
          **(_DWORD **)v11,
          *(_WORD *)(*(_QWORD *)(*(_QWORD *)v11 + 0x28i64) + 0x1Ci64));
      }
    }
    *(_DWORD *)(*(_QWORD *)v11 + 0x8Ci64) = 1;
  }


  v65 = 0i64;
  v219[3] = 0i64;
  v219[4] = 0i64;

  if ( *(_QWORD *)(v11 + 0x398) || *(_QWORD *)(v11 + 0x3A0) )
  {
    if ( (v27 & 0x40) != 0 && v63 )
    {
      v210 = *(_OWORD *)(v11 + 0x398);
      IppLocalitySetOtherStatefulAddressConfig(&v210);
    }
    if ( (v27 & 0x80u) != 0 && v64 )
    {
      v211 = *(_OWORD *)(v11 + 0x398);
      IppLocalitySetManagedAddressConfig(&v211);
    }
  }


  if ( v62 )
  {
    v66 = (MEMORY[0xFFFFF78000000008] / 0x2710ui64 * (unsigned __int128)0x624DD2F1A9FBE77ui64) >> 0x40;
    v67 = v66 + ((MEMORY[0xFFFFF78000000008] / 0x2710ui64 - v66) >> 1);
    v68 = 1;
    v69 = v67 >> 8;
    if ( (_DWORD)v69 != 0xFFFFFFFF )
      v68 = v69 + 1;
    IppTimerUpdateNextExpirationTick(v69, v68);
    IppNotifyInterfaceChange(v11, 0, 0, 0i64, 3);
  }

  v70 = v174;
  if ( v174 || (v65 = *(unsigned int *)(*(_QWORD *)(v11 + 0x28) + 0x24i64), (v65 & 2) == 0) )
  {
    if ( *(_DWORD *)v177 < 3u )
      *(_QWORD *)v177 = 0i64;
  }


  if ( (unsigned __int8)NetioNcmFastCheckIsAoAcCapable(v65, v59, v60) )
  {
    if ( *(_DWORD *)(*(_QWORD *)(v11 + 0x28) + 0x14i64) != 0x83 )
    {
      v71 = ExAllocatePoolWithTag((POOL_TYPE)0x200, 0x30ui64, 0x676E7049u);
      v72 = v71;
      if ( v71 )
      {
        memset(v71, 0, 0x30ui64);
        _InterlockedAdd((volatile signed __int32 *)(v11 + 0x90), 1u);
        v72[2] = v11;
        v72[1] = IppActiveReferenceWorker;
        *((_BYTE *)v72 + 0x18) = 1;
        *((_DWORD *)v72 + 7) = 1;
        *((_DWORD *)v72 + 8) = 2;
        v72[5] = 0i64;
        NetioInsertWorkQueue(v11 + 0xF0, v72);
      }
    }
  }


  if ( v172 && v172 != *(_DWORD *)(v11 + 0x1B8) )
  {
    v73 = v172;
    *(_DWORD *)(v11 + 0x1B8) = v172;
    *(_DWORD *)(v11 + 0x1BC) = IppNeighborReachableTicks(v73);
  }

  KeReleaseInStackQueuedSpinLock(&LockHandle);
  if ( v183 )
    IppFragmentPackets((__int64)Ipv6Global, v183);
  v74 = SpinLock;
  v75 = *((_BYTE *)SpinLock + 4);
  if ( v75 )
    *(_BYTE *)(v11 + 0x1C8) = v75;
  v76 = *((_DWORD *)v74 + 3);

  if ( v76 )
  {
    v77 = _byteswap_ulong(v76);
    v78 = 2 * (unsigned __int64)v77 / 0x3E8;
    if ( !(_DWORD)v78 )
      LODWORD(v78) = v77 != 0;
    *(_DWORD *)(v11 + 0x1C0) = v78;
  }

  v79 = 2 * v70;
  v80 = v175;
  v222 = _mm_load_si128((const __m128i *)&_xmm);
  v195 = v70;
  HIDWORD(v194) = v70;
  v197 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  v81 = v222.m128i_i32[((unsigned __int64)v27 >> 3) & 3];
  if ( v81 == 0xFFFFFFFF )
    v81 = 0x100;
  v172 = v81;
  v196 = v81;
  LODWORD(v194) = 0xFFFFFFFF;
  LODWORD(v82) = 0;
  if ( v175 )
    v82 = *(_QWORD *)(v175 + 0x10);
  v83 = *(_QWORD *)v11;
  v205.LockQueue.Next = 0i64;
  v205.LockQueue.Lock = 0i64;
  *(_QWORD *)&v205.OldIrql = 0i64;
  v204.LockQueue.Next = 0i64;
  v204.LockQueue.Lock = 0i64;
  *(_QWORD *)&v204.OldIrql = 0i64;
  KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &v205);
  while ( *(_DWORD *)(v11 + 0x188) )
    ;
  KeAcquireInStackQueuedSpinLockAtDpcLevel((PKSPIN_LOCK)(v83 + 0xC0), &v204);
  v84 = NetBuffer;
  v85 = 0;

  if ( *(int *)(v83 + 0xC8) >= 0 )
  {
    v86 = (_DWORD *)(v83 + 0x100);
    do
    {
      while ( *v86 )
        ;
      ++v85;
      v86 += 0x10;
    }
    while ( v85 <= *(_DWORD *)(v83 + 0xC8) );
    v80 = v175;
  }


  v87 = *(_QWORD *)v11;
  if ( (int)IppValidateSetAllRouteParameters(
              3 - (unsigned int)(v79 != 0),
              v11,
              v82,
              (int)&in6addr_any,
              0,
              0i64,
              0,
              3,
              (__int64)&v194,
              Buf2,
              0i64,
              (__int64)&v189) >= 0 )
    IppCommitSetAllRouteParameters(3 - (v79 != 0), v87, v189, (char *)&v194);
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&v204);
  KeReleaseInStackQueuedSpinLock(&v205);
  v88 = 0x10;
  v89 = v84->CurrentMdlOffset + 0x10;
  v167 = 0x10;


  if ( v89 >= *(_DWORD *)(v84->Link.Region + 0x28) )
  {
    NdisAdvanceNetBufferDataStart(v84, 0x10u, 0, 0i64);
  }
  else
  {
    v84->DataOffset += 0x10;
    v84->DataLength -= 0x10;
    v84->CurrentMdlOffset = v89;
  }

  while ( 1 )
  {
    v181 = 0;
    if ( v84->DataLength < 2 )
      break;
    N_buffer01 = NdisGetDataBuffer(v84, 2u, &v181, 1u, 0);// 从 NET_BUFFER 访问一个连续的数据块
    N_length = 8 * (unsigned __int8)N_buffer01[1];
    v164 = N_length;
    if ( !N_length || N_length > v84->DataLength )
      break;
    switch ( *N_buffer01 )
    {
      case 3:
        memset(v221, 0, sizeof(v221));
        *(_QWORD *)v212 = 0i64;
        v213 = 0i64;
        v186 = (char *)NdisGetDataBuffer(v84, v164, v221, 1u, 0);
        v97 = v186;
        v99 = v186[2];
        v100 = _byteswap_ulong(*((_DWORD *)v186 + 1));
        v101 = v186 + 0x10;
        v166 = v99;
        v98 = v99;
        LODWORD(v183) = v99;
        v102 = 2 * v100;
        v103 = _byteswap_ulong(*((_DWORD *)v186 + 2));
        if ( (2 * v100) >> 1 != v100 )
          v102 = 0xFFFFFFFF;
        v174 = v102;
        v104 = 2 * v103;
        v112 = (2 * v103) >> 1 == v103;
        v105 = v186 + 0x10;
        if ( !v112 )
          v104 = 0xFFFFFFFF;
        v173 = v104;
        v106 = v104;
        if ( v79 <= v104 )
          v106 = v79;
        v107 = v99 >> 3;
        v108 = v99 & 7;
        v79 = v106;
        v171 = v106;
        for ( i = 0; i < 0x10; ++i )
        {
          if ( i >= (unsigned int)v107 )
            v110 = 0;
          else
            v110 = *v105;
          (v105++)[(char *)v212 - v101] = v110;
        }
        v80 = v175;
        if ( v108 )
          *((_BYTE *)v212 + v107) = v101[v107] & (0xFF << (8 - v108));
        v111 = v212[0];
        if ( LOBYTE(v212[0]) == 0xFE )
          v112 = (BYTE1(v212[0]) & 0xC0) == 0x80;
        else
          v112 = LOBYTE(v212[0]) == 0xFF;
        if ( v112 )
          goto LABEL_219;
        v114 = v97[3];
        if ( v114 < 0 && ((*(_BYTE *)(v11 + 0x194) & 1) == 0 || v166 != 0x40) )
        {
          v201 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
          v115 = 0xFFFFFFFF;
          v116 = 3 - (v102 != 0);
          LODWORD(v198) = 0xFFFFFFFF;
          if ( v102 != 0xFFFFFFFF )
            v115 = v102 >> 1;
          v117 = *(_QWORD *)v11;
          v199 = v115;
          HIDWORD(v198) = v115;
          v200 = v172;
          v207.LockQueue.Next = 0i64;
          v207.LockQueue.Lock = 0i64;
          *(_QWORD *)&v207.OldIrql = 0i64;
          v206.LockQueue.Next = 0i64;
          v206.LockQueue.Lock = 0i64;
          *(_QWORD *)&v206.OldIrql = 0i64;
          KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &v207);
          while ( *(_DWORD *)(v11 + 0x188) )
            ;
          KeAcquireInStackQueuedSpinLockAtDpcLevel((PKSPIN_LOCK)(v117 + 0xC0), &v206);
          v84 = NetBuffer;
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
            v84 = NetBuffer;
          }
          v120 = *(_QWORD *)v11;
          if ( (int)IppValidateSetAllRouteParameters(
                      v116,
                      v11,
                      0,
                      (int)v212,
                      v166,
                      0i64,
                      0,
                      3,
                      (__int64)&v198,
                      0i64,
                      0i64,
                      (__int64)&v190) >= 0 )
            IppCommitSetAllRouteParameters(v116, v120, v190, (char *)&v198);
          KeReleaseInStackQueuedSpinLockFromDpcLevel(&v206);
          KeReleaseInStackQueuedSpinLock(&v207);
          v97 = v186;
          v111 = v212[0];
          v98 = v166;
          v114 = v186[3];
        }




        if ( (v114 & 1) != 0 )
        {
          IppUpdateAutoConfiguredRoute((__int64 *)v11, (__int64)Buf2, v80, (int)v212, v98, v102, v172);
          v114 = v97[3];
          v111 = v212[0];
        }
        if ( v111 != (char)0xFE || (BYTE1(v212[0]) & 0xC0) != 0xC0 )
        {
          if ( (v114 & 0x10) != 0 )
          {
            v121 = v97[0xF];
            goto LABEL_248;
          }
          if ( (v114 & 0x40) != 0 )
          {
            v121 = *(_BYTE *)(v11 + 0x1CA);
LABEL_248:
            v163 = v121;
          }
          else
          {
            v121 = 0;
            v163 = 0;
          }
          if ( v121 && v121 <= v98 )
          {
            v122 = *(const UCHAR **)v11;
            v123 = 0i64;
            v214 = 0ui64;
            v124 = v121 >> 3;
            v170 = 1;
            v125 = 0;
            v178 = v122;
            do
            {
              if ( v125 >= (unsigned int)v124 )
                v126 = 0;
              else
                v126 = *((_BYTE *)v212 + v123);
              *((_BYTE *)&v214 + v123) = v126;
              ++v125;
              ++v123;
            }
            while ( v125 < 0x10 );
            if ( (v121 & 7) != 0 )
              *((_BYTE *)&v214 + v124) = *((_BYTE *)v212 + v124) & (0xFF << (8 - (v121 & 7)));
            v127 = (PKSPIN_LOCK)(v122 + 0x280);
            SpinLock = (PKSPIN_LOCK)(v122 + 0x280);
            NewIrql = KeAcquireSpinLockRaiseToDpc((PKSPIN_LOCK)v122 + 0x50);
            v128 = (UCHAR *)(v122 + 0x288);
            v129 = 0;
            v177 = (UCHAR *)(v122 + 0x288);
            v130 = (UCHAR *)*((_QWORD *)v122 + 0x51);
            v131 = MEMORY[0xFFFFF78000000008] / 0x2710ui64 / 0x1F4;
            v179 = (_LIST_ENTRY *)v131;
            if ( v130 == v122 + 0x288 )
            {
LABEL_302:
              v147 = v174;
              if ( v174 )
              {
                v148 = *(_BYTE *)(*(_QWORD *)(*(_QWORD *)v11 + 0x28i64) + 0x44D2i64) == (_BYTE)v129 ? (_BYTE)v129 : *(_DWORD *)(v11 + 0x208) >= 0xAu;
                if ( !v148 )
                {
                  v149 = (char *)ExAllocatePoolWithTag((POOL_TYPE)0x200, 0x40ui64, 0x676E7049u);
                  if ( v149 )
                  {
                    _InterlockedIncrement((volatile signed __int32 *)(v11 + 0x90));
                    v150 = v214;
                    *((_DWORD *)v149 + 8) = v173;
                    *((_DWORD *)v149 + 0xE) = 0;
                    *(_OWORD *)(v149 + 0x26) = v150;
                    *((_QWORD *)v149 + 2) = v11;
                    *((_DWORD *)v149 + 6) = v131;
                    *((_DWORD *)v149 + 7) = v147;
                    v149[0x24] = v121;
                    IppAddSitePrefixEntry((__int64)v127, (__int64)v149);
                  }
                  else if ( *((_DWORD *)&MICROSOFT_TCPIP_PROVIDER_Context + 9) == 1
                         && (BYTE3(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Flink) & 8) != 0 )
                  {
                    McTemplateK0z((PMCGEN_TRACE_CONTEXT)&MICROSOFT_TCPIP_PROVIDER_Context);
                  }
                }
              }
            }
            else
            {
              v132 = v170;
              do
              {
                v133 = v129;
                v191 = *(UCHAR **)v130;
                if ( *((_QWORD *)v130 + 2) == v11
                  && *(_OWORD *)(v130 + 0x26) == v214
                  && v130[0x24] == v121
                  && *((_DWORD *)v130 + 0xE) == v129 )
                {
                  v132 = v129;
                  *((_DWORD *)v130 + 7) = v174;
                  v133 = 1;
                  *((_DWORD *)v130 + 8) = v173;
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
                        v128 = v177;
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
                            McTemplateK0z((PMCGEN_TRACE_CONTEXT)&MICROSOFT_TCPIP_PROVIDER_Context);
                          }
                        }
                      }
                      else
                      {
                        IppDereferenceNsiClientContext(v143);
                      }
                      v128 = v177;
                      v129 = 0;
                      LODWORD(v131) = (_DWORD)v179;
                    }
                    v122 = v178;
                    v121 = v163;
                  }
                }
                else
                {
                  IppRemoveSitePrefixEntry(v130);
                  v128 = v177;
                  v129 = 0;
                }
                v130 = v191;
              }
              while ( v191 != v128 );
              v112 = v132 == 0;
              v84 = NetBuffer;
              if ( !v112 )
              {
                v127 = SpinLock;
                goto LABEL_302;
              }
            }
            KeReleaseSpinLock(SpinLock, NewIrql);
            v80 = v175;
            v102 = v174;
            v114 = v186[3];
          }
          v79 = v171;
        }
        if ( (v114 & 0x40) != 0 )
        {
          v151 = v173;
          if ( v173 <= v102 )
          {
            v152 = *(unsigned __int8 *)(*(_QWORD *)(v11 + 0x28) + 0xBi64);
            if ( v152 + (_DWORD)v183 == 0x80 )
            {
              v153 = (unsigned __int8)v183;
              if ( (*(_BYTE *)(v11 + 0x194) & 1) != 0 && (_BYTE)v183 == 0x40 )
              {
                Ipv6pUpdateSitePrefix(1, (__int64 *)v11, v212, 0x40u, v102, v173);
              }
              else
              {
                v208.LockQueue.Next = 0i64;
                v208.LockQueue.Lock = 0i64;
                *(_QWORD *)&v208.OldIrql = 0i64;
                KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &v208);
                while ( *(_DWORD *)(v11 + 0x188) )
                  ;
                Ipv6pUpdateAutoConfiguredAddressesUnderLock(v11, (char *)v212, v153, v102, v151, 0, Buf2);
                KeReleaseInStackQueuedSpinLock(&v208);
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
                (unsigned int)v183,
                v152);
            }
          }
          else if ( WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                 && BYTE1(WPP_GLOBAL_Control->Timer) >= 3u
                 && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x40) != 0 )
          {
            WPP_SF_(WPP_GLOBAL_Control->AttachedDevice, 0xAi64, &WPP_7f49f6ec16883d4b2ce7b6b90c474a20_Traceguids);
          }
          v79 = v171;
        }
LABEL_219:
        v88 = v167;
        break;
      case 0x18:
        v92 = 8 * (unsigned __int8)N_buffer01[1];// ?
        v219[0] = 0i64;
        v219[1] = 0i64;
        v219[2] = 0i64;
        v216[0] = 0i64;
        v216[1] = 0i64;
        N_buffer02 = (unsigned __int8 *)NdisGetDataBuffer(v84, N_length, v219, 1u, 0);
        v223 = _mm_load_si128((const __m128i *)&_xmm);
        v172 = v223.m128i_u32[((unsigned __int64)N_buffer02[3] >> 3) & 3];
        if ( v172 != 0xFFFFFFFF )
        {
          v94 = N_buffer02[2];
          v95 = _byteswap_ulong(*((_DWORD *)N_buffer02 + 1));
          v96 = 2 * v95;
          if ( (2 * v95) >> 1 != v95 )
            v96 = 0xFFFFFFFF;
          CopyPrefix((__int64)v216, N_buffer02 + 8, N_buffer02[2], 0x10u);
          IppUpdateAutoConfiguredRoute((__int64 *)v11, (__int64)Buf2, v80, (int)v216, v94, v96, v172);
          v88 = v167;
          if ( v79 <= v96 )
            v96 = v79;
          v79 = v96;
        }
        goto LABEL_221;
      case 0x19:
        if ( (*(_BYTE *)(v11 + 0x194) & 0x40) != 0 )
        {
          Ipv6pUpdateRDNSS(v11, v84, (__int64)Buf2, v187, &v168);
          goto LABEL_194;
        }
        break;
      default:
        if ( *N_buffer01 == 0x1F && (*(_BYTE *)(v11 + 0x194) & 0x40) != 0 )
        {
          Ipv6pUpdateDNSSL(v11, v84, Buf2, v187, &v168);
LABEL_194:
          v92 = v164;
          goto LABEL_333;
        }
        break;
    }


    v92 = v164;
LABEL_221:
    if ( v92 )
    {
      v113 = v92 + v84->CurrentMdlOffset;
      if ( v113 >= *(_DWORD *)(v84->Link.Region + 0x28) )
      {
        NdisAdvanceNetBufferDataStart(v84, v92, 0, 0i64);// 释放由 NdisRetreatNetBufferDataStart 函数添加的被使用的数据空间
      }
      else
      {
        v84->DataOffset += v92;
        v84->DataLength -= v92;
        v84->CurrentMdlOffset = v113;
      }
    }
LABEL_333:
    v88 += v92;
    v167 = v88;
  }




  v154 = v84->CurrentMdlOffset;
  v155 = v88;
  if ( v154 < v88 )
  {
    NdisRetreatNetBufferDataStart(v84, v88, 0, NetioAllocateMdl);// 访问 Net_Buffer 结构的 MDL 链中更多被使用的数据空间
  }
  else
  {
    v84->DataOffset -= v88;
    v84->DataLength += v88;
    v84->CurrentMdlOffset = v154 - v88;
  }


  if ( v168 )
  {
    v193[2] = 0i64;
    v193[0] = 1i64;
    v193[1] = 0i64;
    Ipv6pNotifyRouterInformationChange(v11, v155, (__int64)v193);
  }
  KeAcquireInStackQueuedSpinLock((PKSPIN_LOCK)(v11 + 0x180), &LockHandle);
  while ( *(_DWORD *)(v11 + 0x188) )
    ;
  v156 = v182;


  if ( (*(_BYTE *)(v11 + 0x190) & 2) == 0 && (*(_DWORD *)(*(_QWORD *)(v11 + 0x28) + 0x24i64) & 2) == 0 )
  {
    v157 = Ipv6pFindPotentialRouterUnderLock(v11, (_QWORD *)v182[0x20]);
    if ( v157 )
    {
      if ( !*((_DWORD *)v157 + 5) )
      {
        *((_DWORD *)v157 + 4) = 3;
        if ( v79 >= 0xE10 )
          v158 = v79 >> 1;
        else
          v158 = 0x708;
        v159 = v187;
        v160 = v158 + v187;
        *((_DWORD *)v157 + 5) = v158 + v187;
        if ( !v160 )
        {
          *((_DWORD *)v157 + 5) = 1;
          v160 = 1;
        }
        IppTimerUpdateNextExpirationTick(v159, v160);
      }
    }
  }
  KeReleaseInStackQueuedSpinLock(&LockHandle);
  result = v156[1];
  *(_DWORD *)(result + 0x8C) = 0;


  if ( v80 )
  {
    v161 = *(_DWORD *)(v80 + 4);
    if ( v161 == 2 )
    {
      v162 = *(_BYTE *)(v80 + 0x45);
      v161 = 2;
      if ( (v162 & 1) == 0 && (v162 & 8) != 0 )
      {
        _InterlockedAdd((volatile signed __int32 *)(*(_QWORD *)(v80 + 8) + 0x134i64), 1u);
        _InterlockedAdd((volatile signed __int32 *)(*(_QWORD *)(*(_QWORD *)(v80 + 8) + 0x150i64) + 0x38i64), 1u);
        v161 = *(_DWORD *)(v80 + 4);
      }
    }
    if ( v161 <= 0 )
      KeBugCheck(0x1Cu);
    result = (unsigned int)_InterlockedExchangeAdd((volatile signed __int32 *)(v80 + 4), 0xFFFFFFFF);
    if ( (_DWORD)result == 1 )
      result = IppCleanupNeighbor(v80);
  }
  return result;
}