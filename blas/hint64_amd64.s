//+build !noasm !appengine
// AUTO-GENERATED BY C2GOASM -- DO NOT EDIT

TEXT ·_hsum_int64(SB), $0-24

	MOVQ input+0(FP), DI
	MOVQ result+8(FP), SI
	MOVQ info+16(FP), DX

	LONG $0x0006c748; WORD $0x0000; BYTE $0x00 // mov    qword [rsi], 0
	WORD $0x8948; BYTE $0xd0                   // mov    rax, rdx
	LONG $0x20e8c148                           // shr    rax, 32
	JNE  LBB0_2
	WORD $0xc031                               // xor    eax, eax
	WORD $0x3145; BYTE $0xc0                   // xor    r8d, r8d
	WORD $0x3941; BYTE $0xd0                   // cmp    r8d, edx
	JB   LBB0_10
	JMP  LBB0_13

LBB0_2:
	WORD $0xfa83; BYTE $0x04 // cmp    edx, 4
	JAE  LBB0_4
	WORD $0xc031             // xor    eax, eax
	JMP  LBB0_8

LBB0_4:
	WORD $0x8949; BYTE $0xd0     // mov    r8, rdx
	LONG $0x02e8c149             // shr    r8, 2
	WORD $0x8944; BYTE $0xc0     // mov    eax, r8d
	LONG $0xffffff25; BYTE $0x3f // and    eax, 1073741823
	LONG $0x01e08341             // and    r8d, 1
	LONG $0x01f88348             // cmp    rax, 1
	JNE  LBB0_14
	WORD $0xc031                 // xor    eax, eax
	WORD $0x3145; BYTE $0xd2     // xor    r10d, r10d
	JMP  LBB0_6

LBB0_14:
	WORD $0x894d; BYTE $0xc1 // mov    r9, r8
	WORD $0x2949; BYTE $0xc1 // sub    r9, rax
	WORD $0x3145; BYTE $0xd2 // xor    r10d, r10d
	WORD $0xc031             // xor    eax, eax

LBB0_15:
	LONG $0x6f7aa1c4; WORD $0xd744; BYTE $0x10 // vmovdqu    xmm0, oword [rdi + 8*r10 + 16]
	LONG $0xd479a1c4; WORD $0xd704             // vpaddq    xmm0, xmm0, oword [rdi + 8*r10]
	LONG $0xc870f9c5; BYTE $0xee               // vpshufd    xmm1, xmm0, 238
	LONG $0xc1d4f9c5                           // vpaddq    xmm0, xmm0, xmm1
	LONG $0x7ef9e1c4; BYTE $0xc1               // vmovq    rcx, xmm0
	WORD $0x0148; BYTE $0xc1                   // add    rcx, rax
	WORD $0x8948; BYTE $0x0e                   // mov    qword [rsi], rcx
	LONG $0x6f7aa1c4; WORD $0xd744; BYTE $0x30 // vmovdqu    xmm0, oword [rdi + 8*r10 + 48]
	LONG $0xd479a1c4; WORD $0xd744; BYTE $0x20 // vpaddq    xmm0, xmm0, oword [rdi + 8*r10 + 32]
	LONG $0xc870f9c5; BYTE $0xee               // vpshufd    xmm1, xmm0, 238
	LONG $0xc1d4f9c5                           // vpaddq    xmm0, xmm0, xmm1
	LONG $0x7ef9e1c4; BYTE $0xc0               // vmovq    rax, xmm0
	WORD $0x0148; BYTE $0xc8                   // add    rax, rcx
	WORD $0x8948; BYTE $0x06                   // mov    qword [rsi], rax
	LONG $0x08c28349                           // add    r10, 8
	LONG $0x02c18349                           // add    r9, 2
	JNE  LBB0_15

LBB0_6:
	WORD $0x854d; BYTE $0xc0                   // test    r8, r8
	JE   LBB0_8
	LONG $0x6f7aa1c4; WORD $0xd744; BYTE $0x10 // vmovdqu    xmm0, oword [rdi + 8*r10 + 16]
	LONG $0xd479a1c4; WORD $0xd704             // vpaddq    xmm0, xmm0, oword [rdi + 8*r10]
	LONG $0xc870f9c5; BYTE $0xee               // vpshufd    xmm1, xmm0, 238
	LONG $0xc1d4f9c5                           // vpaddq    xmm0, xmm0, xmm1
	LONG $0x7ef9e1c4; BYTE $0xc1               // vmovq    rcx, xmm0
	WORD $0x0148; BYTE $0xc8                   // add    rax, rcx
	WORD $0x8948; BYTE $0x06                   // mov    qword [rsi], rax

LBB0_8:
	WORD $0x8941; BYTE $0xd0 // mov    r8d, edx
	LONG $0xfce08341         // and    r8d, -4
	WORD $0x3941; BYTE $0xd0 // cmp    r8d, edx
	JAE  LBB0_13

LBB0_10:
	WORD $0x6349; BYTE $0xc8 // movsxd    rcx, r8d
	WORD $0xf741; BYTE $0xd0 // not    r8d
	WORD $0x0141; BYTE $0xd0 // add    r8d, edx
	WORD $0x8941; BYTE $0xd1 // mov    r9d, edx
	LONG $0x03e18341         // and    r9d, 3
	JE   LBB0_12

LBB0_11:
	LONG $0xcf040348         // add    rax, qword [rdi + 8*rcx]
	WORD $0x8948; BYTE $0x06 // mov    qword [rsi], rax
	LONG $0x01c18348         // add    rcx, 1
	LONG $0xffc18341         // add    r9d, -1
	JNE  LBB0_11

LBB0_12:
	LONG $0x03f88341 // cmp    r8d, 3
	JB   LBB0_13

LBB0_16:
	LONG $0xcf040348             // add    rax, qword [rdi + 8*rcx]
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	LONG $0xcf440348; BYTE $0x08 // add    rax, qword [rdi + 8*rcx + 8]
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	LONG $0xcf440348; BYTE $0x10 // add    rax, qword [rdi + 8*rcx + 16]
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	LONG $0xcf440348; BYTE $0x18 // add    rax, qword [rdi + 8*rcx + 24]
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	LONG $0x04c18348             // add    rcx, 4
	WORD $0xd139                 // cmp    ecx, edx
	JB   LBB0_16

LBB0_13:
	RET

TEXT ·_hmax_int64(SB), $0-24

	MOVQ input+0(FP), DI
	MOVQ result+8(FP), SI
	MOVQ info+16(FP), DX

	WORD $0x8b4c; BYTE $0x17     // mov    r10, qword [rdi]
	WORD $0x894c; BYTE $0x16     // mov    qword [rsi], r10
	WORD $0x8948; BYTE $0xd0     // mov    rax, rdx
	LONG $0x20e8c148             // shr    rax, 32
	WORD $0x3145; BYTE $0xc0     // xor    r8d, r8d
	WORD $0xf883; BYTE $0x02     // cmp    eax, 2
	JNE  LBB1_8
	WORD $0xfa83; BYTE $0x04     // cmp    edx, 4
	JB   LBB1_7
	WORD $0x8949; BYTE $0xd0     // mov    r8, rdx
	LONG $0x02e8c149             // shr    r8, 2
	WORD $0x8944; BYTE $0xc0     // mov    eax, r8d
	LONG $0xffffff25; BYTE $0x3f // and    eax, 1073741823
	LONG $0x01e08341             // and    r8d, 1
	LONG $0x01f88348             // cmp    rax, 1
	JNE  LBB1_15
	WORD $0xc931                 // xor    ecx, ecx

LBB1_4:
	WORD $0x854d; BYTE $0xc0       // test    r8, r8
	JE   LBB1_7
	LONG $0x046ffac5; BYTE $0xcf   // vmovdqu    xmm0, oword [rdi + 8*rcx]
	QUAD $0x01cf443d08fdf262       // vpmaxsq    xmm0, xmm0, oword [rdi + 8*rcx + 16]
	LONG $0xc870f9c5; BYTE $0x4e   // vpshufd    xmm1, xmm0, 78
	LONG $0x08fdf262; WORD $0xc13d // vpmaxsq    xmm0, xmm0, xmm1
	LONG $0x7ef9e1c4; BYTE $0xc0   // vmovq    rax, xmm0
	WORD $0x394c; BYTE $0xd0       // cmp    rax, r10
	JLE  LBB1_7
	WORD $0x8948; BYTE $0x06       // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2       // mov    r10, rax

LBB1_7:
	WORD $0x8941; BYTE $0xd0 // mov    r8d, edx
	LONG $0xfce08341         // and    r8d, -4

LBB1_8:
	WORD $0x3941; BYTE $0xd0 // cmp    r8d, edx
	JAE  LBB1_14
	WORD $0x6349; BYTE $0xc8 // movsxd    rcx, r8d
	WORD $0xf741; BYTE $0xd0 // not    r8d
	WORD $0x0141; BYTE $0xd0 // add    r8d, edx
	WORD $0xd089             // mov    eax, edx
	WORD $0xe083; BYTE $0x03 // and    eax, 3
	JNE  LBB1_10

LBB1_13:
	LONG $0x03f88341 // cmp    r8d, 3
	JAE  LBB1_21

LBB1_14:
	RET

LBB1_12:
	LONG $0x01c18348         // add    rcx, 1
	WORD $0xc083; BYTE $0xff // add    eax, -1
	JE   LBB1_13

LBB1_10:
	LONG $0xcf0c8b4c         // mov    r9, qword [rdi + 8*rcx]
	WORD $0x394d; BYTE $0xd1 // cmp    r9, r10
	JLE  LBB1_12
	WORD $0x894c; BYTE $0x0e // mov    qword [rsi], r9
	WORD $0x894d; BYTE $0xca // mov    r10, r9
	JMP  LBB1_12

LBB1_29:
	LONG $0x04c18348 // add    rcx, 4
	WORD $0xd139     // cmp    ecx, edx
	JAE  LBB1_14

LBB1_21:
	LONG $0xcf048b48             // mov    rax, qword [rdi + 8*rcx]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JG   LBB1_22
	LONG $0xcf448b48; BYTE $0x08 // mov    rax, qword [rdi + 8*rcx + 8]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JG   LBB1_24

LBB1_25:
	LONG $0xcf448b48; BYTE $0x10 // mov    rax, qword [rdi + 8*rcx + 16]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JG   LBB1_26

LBB1_27:
	LONG $0xcf448b48; BYTE $0x18 // mov    rax, qword [rdi + 8*rcx + 24]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JLE  LBB1_29
	JMP  LBB1_28

LBB1_22:
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2     // mov    r10, rax
	LONG $0xcf448b48; BYTE $0x08 // mov    rax, qword [rdi + 8*rcx + 8]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JLE  LBB1_25

LBB1_24:
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2     // mov    r10, rax
	LONG $0xcf448b48; BYTE $0x10 // mov    rax, qword [rdi + 8*rcx + 16]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JLE  LBB1_27

LBB1_26:
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2     // mov    r10, rax
	LONG $0xcf448b48; BYTE $0x18 // mov    rax, qword [rdi + 8*rcx + 24]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JLE  LBB1_29

LBB1_28:
	WORD $0x8948; BYTE $0x06 // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2 // mov    r10, rax
	JMP  LBB1_29

LBB1_15:
	WORD $0x894d; BYTE $0xc1 // mov    r9, r8
	WORD $0x2949; BYTE $0xc1 // sub    r9, rax
	WORD $0xc931             // xor    ecx, ecx
	JMP  LBB1_16

LBB1_20:
	LONG $0x08c18348 // add    rcx, 8
	LONG $0x02c18349 // add    r9, 2
	JE   LBB1_4

LBB1_16:
	LONG $0x046ffac5; BYTE $0xcf   // vmovdqu    xmm0, oword [rdi + 8*rcx]
	QUAD $0x01cf443d08fdf262       // vpmaxsq    xmm0, xmm0, oword [rdi + 8*rcx + 16]
	LONG $0xc870f9c5; BYTE $0x4e   // vpshufd    xmm1, xmm0, 78
	LONG $0x08fdf262; WORD $0xc13d // vpmaxsq    xmm0, xmm0, xmm1
	LONG $0x7ef9e1c4; BYTE $0xc0   // vmovq    rax, xmm0
	WORD $0x394c; BYTE $0xd0       // cmp    rax, r10
	JLE  LBB1_18
	WORD $0x8948; BYTE $0x06       // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2       // mov    r10, rax

LBB1_18:
	LONG $0x446ffac5; WORD $0x20cf // vmovdqu    xmm0, oword [rdi + 8*rcx + 32]
	QUAD $0x03cf443d08fdf262       // vpmaxsq    xmm0, xmm0, oword [rdi + 8*rcx + 48]
	LONG $0xc870f9c5; BYTE $0x4e   // vpshufd    xmm1, xmm0, 78
	LONG $0x08fdf262; WORD $0xc13d // vpmaxsq    xmm0, xmm0, xmm1
	LONG $0x7ef9e1c4; BYTE $0xc0   // vmovq    rax, xmm0
	WORD $0x394c; BYTE $0xd0       // cmp    rax, r10
	JLE  LBB1_20
	WORD $0x8948; BYTE $0x06       // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2       // mov    r10, rax
	JMP  LBB1_20

TEXT ·_hmin_int64(SB), $0-24

	MOVQ input+0(FP), DI
	MOVQ result+8(FP), SI
	MOVQ info+16(FP), DX

	WORD $0x8b4c; BYTE $0x17     // mov    r10, qword [rdi]
	WORD $0x894c; BYTE $0x16     // mov    qword [rsi], r10
	WORD $0x8948; BYTE $0xd0     // mov    rax, rdx
	LONG $0x20e8c148             // shr    rax, 32
	WORD $0x3145; BYTE $0xc0     // xor    r8d, r8d
	WORD $0xf883; BYTE $0x02     // cmp    eax, 2
	JNE  LBB2_8
	WORD $0xfa83; BYTE $0x04     // cmp    edx, 4
	JB   LBB2_7
	WORD $0x8949; BYTE $0xd0     // mov    r8, rdx
	LONG $0x02e8c149             // shr    r8, 2
	WORD $0x8944; BYTE $0xc0     // mov    eax, r8d
	LONG $0xffffff25; BYTE $0x3f // and    eax, 1073741823
	LONG $0x01e08341             // and    r8d, 1
	LONG $0x01f88348             // cmp    rax, 1
	JNE  LBB2_15
	WORD $0xc931                 // xor    ecx, ecx

LBB2_4:
	WORD $0x854d; BYTE $0xc0       // test    r8, r8
	JE   LBB2_7
	LONG $0x046ffac5; BYTE $0xcf   // vmovdqu    xmm0, oword [rdi + 8*rcx]
	QUAD $0x01cf443908fdf262       // vpminsq    xmm0, xmm0, oword [rdi + 8*rcx + 16]
	LONG $0xc870f9c5; BYTE $0x4e   // vpshufd    xmm1, xmm0, 78
	LONG $0x08fdf262; WORD $0xc139 // vpminsq    xmm0, xmm0, xmm1
	LONG $0x7ef9e1c4; BYTE $0xc0   // vmovq    rax, xmm0
	WORD $0x394c; BYTE $0xd0       // cmp    rax, r10
	JGE  LBB2_7
	WORD $0x8948; BYTE $0x06       // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2       // mov    r10, rax

LBB2_7:
	WORD $0x8941; BYTE $0xd0 // mov    r8d, edx
	LONG $0xfce08341         // and    r8d, -4

LBB2_8:
	WORD $0x3941; BYTE $0xd0 // cmp    r8d, edx
	JAE  LBB2_14
	WORD $0x6349; BYTE $0xc8 // movsxd    rcx, r8d
	WORD $0xf741; BYTE $0xd0 // not    r8d
	WORD $0x0141; BYTE $0xd0 // add    r8d, edx
	WORD $0xd089             // mov    eax, edx
	WORD $0xe083; BYTE $0x03 // and    eax, 3
	JNE  LBB2_10

LBB2_13:
	LONG $0x03f88341 // cmp    r8d, 3
	JAE  LBB2_21

LBB2_14:
	RET

LBB2_12:
	LONG $0x01c18348         // add    rcx, 1
	WORD $0xc083; BYTE $0xff // add    eax, -1
	JE   LBB2_13

LBB2_10:
	LONG $0xcf0c8b4c         // mov    r9, qword [rdi + 8*rcx]
	WORD $0x394d; BYTE $0xd1 // cmp    r9, r10
	JGE  LBB2_12
	WORD $0x894c; BYTE $0x0e // mov    qword [rsi], r9
	WORD $0x894d; BYTE $0xca // mov    r10, r9
	JMP  LBB2_12

LBB2_29:
	LONG $0x04c18348 // add    rcx, 4
	WORD $0xd139     // cmp    ecx, edx
	JAE  LBB2_14

LBB2_21:
	LONG $0xcf048b48             // mov    rax, qword [rdi + 8*rcx]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JL   LBB2_22
	LONG $0xcf448b48; BYTE $0x08 // mov    rax, qword [rdi + 8*rcx + 8]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JL   LBB2_24

LBB2_25:
	LONG $0xcf448b48; BYTE $0x10 // mov    rax, qword [rdi + 8*rcx + 16]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JL   LBB2_26

LBB2_27:
	LONG $0xcf448b48; BYTE $0x18 // mov    rax, qword [rdi + 8*rcx + 24]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JGE  LBB2_29
	JMP  LBB2_28

LBB2_22:
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2     // mov    r10, rax
	LONG $0xcf448b48; BYTE $0x08 // mov    rax, qword [rdi + 8*rcx + 8]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JGE  LBB2_25

LBB2_24:
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2     // mov    r10, rax
	LONG $0xcf448b48; BYTE $0x10 // mov    rax, qword [rdi + 8*rcx + 16]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JGE  LBB2_27

LBB2_26:
	WORD $0x8948; BYTE $0x06     // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2     // mov    r10, rax
	LONG $0xcf448b48; BYTE $0x18 // mov    rax, qword [rdi + 8*rcx + 24]
	WORD $0x394c; BYTE $0xd0     // cmp    rax, r10
	JGE  LBB2_29

LBB2_28:
	WORD $0x8948; BYTE $0x06 // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2 // mov    r10, rax
	JMP  LBB2_29

LBB2_15:
	WORD $0x894d; BYTE $0xc1 // mov    r9, r8
	WORD $0x2949; BYTE $0xc1 // sub    r9, rax
	WORD $0xc931             // xor    ecx, ecx
	JMP  LBB2_16

LBB2_20:
	LONG $0x08c18348 // add    rcx, 8
	LONG $0x02c18349 // add    r9, 2
	JE   LBB2_4

LBB2_16:
	LONG $0x046ffac5; BYTE $0xcf   // vmovdqu    xmm0, oword [rdi + 8*rcx]
	QUAD $0x01cf443908fdf262       // vpminsq    xmm0, xmm0, oword [rdi + 8*rcx + 16]
	LONG $0xc870f9c5; BYTE $0x4e   // vpshufd    xmm1, xmm0, 78
	LONG $0x08fdf262; WORD $0xc139 // vpminsq    xmm0, xmm0, xmm1
	LONG $0x7ef9e1c4; BYTE $0xc0   // vmovq    rax, xmm0
	WORD $0x394c; BYTE $0xd0       // cmp    rax, r10
	JGE  LBB2_18
	WORD $0x8948; BYTE $0x06       // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2       // mov    r10, rax

LBB2_18:
	LONG $0x446ffac5; WORD $0x20cf // vmovdqu    xmm0, oword [rdi + 8*rcx + 32]
	QUAD $0x03cf443908fdf262       // vpminsq    xmm0, xmm0, oword [rdi + 8*rcx + 48]
	LONG $0xc870f9c5; BYTE $0x4e   // vpshufd    xmm1, xmm0, 78
	LONG $0x08fdf262; WORD $0xc139 // vpminsq    xmm0, xmm0, xmm1
	LONG $0x7ef9e1c4; BYTE $0xc0   // vmovq    rax, xmm0
	WORD $0x394c; BYTE $0xd0       // cmp    rax, r10
	JGE  LBB2_20
	WORD $0x8948; BYTE $0x06       // mov    qword [rsi], rax
	WORD $0x8949; BYTE $0xc2       // mov    r10, rax
	JMP  LBB2_20
