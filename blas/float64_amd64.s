//+build !noasm !appengine
// AUTO-GENERATED BY C2GOASM -- DO NOT EDIT

TEXT ·_add_float64(SB), $0-32

	MOVQ input1+0(FP), DI
	MOVQ input2+8(FP), SI
	MOVQ output+16(FP), DX
	MOVQ info+24(FP), CX

	WORD $0x8948; BYTE $0xc8                   // mov    rax, rcx
	LONG $0x20e8c148                           // shr    rax, 32
	WORD $0x3145; BYTE $0xc0                   // xor    r8d, r8d
	WORD $0xf883; BYTE $0x01                   // cmp    eax, 1
	JNE  LBB0_8
	WORD $0xf983; BYTE $0x04                   // cmp    ecx, 4
	JB   LBB0_7
	WORD $0x8949; BYTE $0xc8                   // mov    r8, rcx
	LONG $0x02e8c149                           // shr    r8, 2
	WORD $0x8945; BYTE $0xc1                   // mov    r9d, r8d
	LONG $0xffe18141; WORD $0xffff; BYTE $0x3f // and    r9d, 1073741823
	LONG $0xff418d49                           // lea    rax, [r9 - 1]
	LONG $0x03e08341                           // and    r8d, 3
	LONG $0x03f88348                           // cmp    rax, 3
	JAE  LBB0_11
	WORD $0x3145; BYTE $0xd2                   // xor    r10d, r10d
	JMP  LBB0_4

LBB0_11:
	WORD $0x294d; BYTE $0xc1     // sub    r9, r8
	LONG $0x000060b8; BYTE $0x00 // mov    eax, 96
	WORD $0x3145; BYTE $0xd2     // xor    r10d, r10d

LBB0_12:
	LONG $0x4410fdc5; WORD $0xa006 // vmovupd    ymm0, yword [rsi + rax - 96]
	LONG $0x4458fdc5; WORD $0xa007 // vaddpd    ymm0, ymm0, yword [rdi + rax - 96]
	LONG $0x4411fdc5; WORD $0xa002 // vmovupd    yword [rdx + rax - 96], ymm0
	LONG $0x4410fdc5; WORD $0xc006 // vmovupd    ymm0, yword [rsi + rax - 64]
	LONG $0x4458fdc5; WORD $0xc007 // vaddpd    ymm0, ymm0, yword [rdi + rax - 64]
	LONG $0x4411fdc5; WORD $0xc002 // vmovupd    yword [rdx + rax - 64], ymm0
	LONG $0x4410fdc5; WORD $0xe006 // vmovupd    ymm0, yword [rsi + rax - 32]
	LONG $0x4458fdc5; WORD $0xe007 // vaddpd    ymm0, ymm0, yword [rdi + rax - 32]
	LONG $0x4411fdc5; WORD $0xe002 // vmovupd    yword [rdx + rax - 32], ymm0
	LONG $0x0410fdc5; BYTE $0x06   // vmovupd    ymm0, yword [rsi + rax]
	LONG $0x0458fdc5; BYTE $0x07   // vaddpd    ymm0, ymm0, yword [rdi + rax]
	LONG $0x0411fdc5; BYTE $0x02   // vmovupd    yword [rdx + rax], ymm0
	LONG $0x04c28349               // add    r10, 4
	LONG $0x80e88348               // sub    rax, -128
	WORD $0x394d; BYTE $0xd1       // cmp    r9, r10
	JNE  LBB0_12

LBB0_4:
	WORD $0x854d; BYTE $0xc0 // test    r8, r8
	JE   LBB0_7
	LONG $0x05e2c149         // shl    r10, 5
	LONG $0x160c8d4e         // lea    r9, [rsi + r10]
	LONG $0x171c8d4a         // lea    rbx, [rdi + r10]
	WORD $0x0149; BYTE $0xd2 // add    r10, rdx
	LONG $0x05e0c149         // shl    r8, 5
	WORD $0xc031             // xor    eax, eax

LBB0_6:
	LONG $0x107dc1c4; WORD $0x0104 // vmovupd    ymm0, yword [r9 + rax]
	LONG $0x0458fdc5; BYTE $0x03   // vaddpd    ymm0, ymm0, yword [rbx + rax]
	LONG $0x117dc1c4; WORD $0x0204 // vmovupd    yword [r10 + rax], ymm0
	LONG $0x20c08348               // add    rax, 32
	WORD $0x3949; BYTE $0xc0       // cmp    r8, rax
	JNE  LBB0_6

LBB0_7:
	WORD $0x8941; BYTE $0xc8 // mov    r8d, ecx
	LONG $0xfce08341         // and    r8d, -4

LBB0_8:
	WORD $0x3941; BYTE $0xc8 // cmp    r8d, ecx
	JAE  LBB0_21
	WORD $0x634d; BYTE $0xc8 // movsxd    r9, r8d
	WORD $0xf741; BYTE $0xd0 // not    r8d
	WORD $0x0141; BYTE $0xc8 // add    r8d, ecx
	LONG $0x0ff88341         // cmp    r8d, 15
	JAE  LBB0_13
	WORD $0x894c; BYTE $0xc8 // mov    rax, r9
	JMP  LBB0_20

LBB0_13:
	LONG $0xca148d4e         // lea    r10, [rdx + 8*r9]
	LONG $0x081c8d4b         // lea    rbx, [r8 + r9]
	LONG $0xda048d48         // lea    rax, [rdx + 8*rbx]
	LONG $0x08c08348         // add    rax, 8
	LONG $0xcf1c8d4e         // lea    r11, [rdi + 8*r9]
	LONG $0xdf348d4c         // lea    r14, [rdi + 8*rbx]
	LONG $0x08c68349         // add    r14, 8
	LONG $0xce3c8d4e         // lea    r15, [rsi + 8*r9]
	LONG $0xde1c8d48         // lea    rbx, [rsi + 8*rbx]
	LONG $0x08c38348         // add    rbx, 8
	WORD $0x394d; BYTE $0xf2 // cmp    r10, r14
	LONG $0xc6920f41         // setb    r14b
	WORD $0x3949; BYTE $0xc3 // cmp    r11, rax
	LONG $0xc3920f41         // setb    r11b
	WORD $0x3949; BYTE $0xda // cmp    r10, rbx
	WORD $0x920f; BYTE $0xc3 // setb    bl
	WORD $0x3949; BYTE $0xc7 // cmp    r15, rax
	WORD $0x920f; BYTE $0xc0 // setb    al
	WORD $0x8445; BYTE $0xde // test    r14b, r11b
	JNE  LBB0_14
	WORD $0xc320             // and    bl, al
	JNE  LBB0_16
	LONG $0x01c08349         // add    r8, 1
	WORD $0x894d; BYTE $0xc2 // mov    r10, r8
	LONG $0xf0e28349         // and    r10, -16
	LONG $0x0a048d4b         // lea    rax, [r10 + r9]
	LONG $0xcf1c8d4e         // lea    r11, [rdi + 8*r9]
	LONG $0x60c38349         // add    r11, 96
	LONG $0xce348d4e         // lea    r14, [rsi + 8*r9]
	LONG $0x60c68349         // add    r14, 96
	LONG $0xca0c8d4e         // lea    r9, [rdx + 8*r9]
	LONG $0x60c18349         // add    r9, 96
	WORD $0xdb31             // xor    ebx, ebx

LBB0_18:
	LONG $0x107dc1c4; WORD $0xde44; BYTE $0xa0 // vmovupd    ymm0, yword [r14 + 8*rbx - 96]
	LONG $0x107dc1c4; WORD $0xde4c; BYTE $0xc0 // vmovupd    ymm1, yword [r14 + 8*rbx - 64]
	LONG $0x107dc1c4; WORD $0xde54; BYTE $0xe0 // vmovupd    ymm2, yword [r14 + 8*rbx - 32]
	LONG $0x107dc1c4; WORD $0xde1c             // vmovupd    ymm3, yword [r14 + 8*rbx]
	LONG $0x587dc1c4; WORD $0xdb44; BYTE $0xa0 // vaddpd    ymm0, ymm0, yword [r11 + 8*rbx - 96]
	LONG $0x5875c1c4; WORD $0xdb4c; BYTE $0xc0 // vaddpd    ymm1, ymm1, yword [r11 + 8*rbx - 64]
	LONG $0x586dc1c4; WORD $0xdb54; BYTE $0xe0 // vaddpd    ymm2, ymm2, yword [r11 + 8*rbx - 32]
	LONG $0x5865c1c4; WORD $0xdb1c             // vaddpd    ymm3, ymm3, yword [r11 + 8*rbx]
	LONG $0x117dc1c4; WORD $0xd944; BYTE $0xa0 // vmovupd    yword [r9 + 8*rbx - 96], ymm0
	LONG $0x117dc1c4; WORD $0xd94c; BYTE $0xc0 // vmovupd    yword [r9 + 8*rbx - 64], ymm1
	LONG $0x117dc1c4; WORD $0xd954; BYTE $0xe0 // vmovupd    yword [r9 + 8*rbx - 32], ymm2
	LONG $0x117dc1c4; WORD $0xd91c             // vmovupd    yword [r9 + 8*rbx], ymm3
	LONG $0x10c38348                           // add    rbx, 16
	WORD $0x3949; BYTE $0xda                   // cmp    r10, rbx
	JNE  LBB0_18
	WORD $0x394d; BYTE $0xd0                   // cmp    r8, r10
	JNE  LBB0_20
	JMP  LBB0_21

LBB0_14:
	WORD $0x894c; BYTE $0xc8 // mov    rax, r9
	JMP  LBB0_20

LBB0_16:
	WORD $0x894c; BYTE $0xc8 // mov    rax, r9

LBB0_20:
	LONG $0x0410fbc5; BYTE $0xc6 // vmovsd    xmm0, qword [rsi + 8*rax]
	LONG $0x0458fbc5; BYTE $0xc7 // vaddsd    xmm0, xmm0, qword [rdi + 8*rax]
	LONG $0x0411fbc5; BYTE $0xc2 // vmovsd    qword [rdx + 8*rax], xmm0
	LONG $0x01c08348             // add    rax, 1
	WORD $0xc839                 // cmp    eax, ecx
	JB   LBB0_20

LBB0_21:
	VZEROUPPER
	RET

TEXT ·_sub_float64(SB), $0-32

	MOVQ input1+0(FP), DI
	MOVQ input2+8(FP), SI
	MOVQ output+16(FP), DX
	MOVQ info+24(FP), CX

	WORD $0x8948; BYTE $0xc8                   // mov    rax, rcx
	LONG $0x20e8c148                           // shr    rax, 32
	WORD $0x3145; BYTE $0xc0                   // xor    r8d, r8d
	WORD $0xf883; BYTE $0x01                   // cmp    eax, 1
	JNE  LBB1_8
	WORD $0xf983; BYTE $0x04                   // cmp    ecx, 4
	JB   LBB1_7
	WORD $0x8949; BYTE $0xc8                   // mov    r8, rcx
	LONG $0x02e8c149                           // shr    r8, 2
	WORD $0x8945; BYTE $0xc1                   // mov    r9d, r8d
	LONG $0xffe18141; WORD $0xffff; BYTE $0x3f // and    r9d, 1073741823
	LONG $0xff418d49                           // lea    rax, [r9 - 1]
	LONG $0x03e08341                           // and    r8d, 3
	LONG $0x03f88348                           // cmp    rax, 3
	JAE  LBB1_11
	WORD $0x3145; BYTE $0xd2                   // xor    r10d, r10d
	JMP  LBB1_4

LBB1_11:
	WORD $0x294d; BYTE $0xc1     // sub    r9, r8
	LONG $0x000060b8; BYTE $0x00 // mov    eax, 96
	WORD $0x3145; BYTE $0xd2     // xor    r10d, r10d

LBB1_12:
	LONG $0x4410fdc5; WORD $0xa007 // vmovupd    ymm0, yword [rdi + rax - 96]
	LONG $0x445cfdc5; WORD $0xa006 // vsubpd    ymm0, ymm0, yword [rsi + rax - 96]
	LONG $0x4411fdc5; WORD $0xa002 // vmovupd    yword [rdx + rax - 96], ymm0
	LONG $0x4410fdc5; WORD $0xc007 // vmovupd    ymm0, yword [rdi + rax - 64]
	LONG $0x445cfdc5; WORD $0xc006 // vsubpd    ymm0, ymm0, yword [rsi + rax - 64]
	LONG $0x4411fdc5; WORD $0xc002 // vmovupd    yword [rdx + rax - 64], ymm0
	LONG $0x4410fdc5; WORD $0xe007 // vmovupd    ymm0, yword [rdi + rax - 32]
	LONG $0x445cfdc5; WORD $0xe006 // vsubpd    ymm0, ymm0, yword [rsi + rax - 32]
	LONG $0x4411fdc5; WORD $0xe002 // vmovupd    yword [rdx + rax - 32], ymm0
	LONG $0x0410fdc5; BYTE $0x07   // vmovupd    ymm0, yword [rdi + rax]
	LONG $0x045cfdc5; BYTE $0x06   // vsubpd    ymm0, ymm0, yword [rsi + rax]
	LONG $0x0411fdc5; BYTE $0x02   // vmovupd    yword [rdx + rax], ymm0
	LONG $0x04c28349               // add    r10, 4
	LONG $0x80e88348               // sub    rax, -128
	WORD $0x394d; BYTE $0xd1       // cmp    r9, r10
	JNE  LBB1_12

LBB1_4:
	WORD $0x854d; BYTE $0xc0 // test    r8, r8
	JE   LBB1_7
	LONG $0x05e2c149         // shl    r10, 5
	LONG $0x160c8d4e         // lea    r9, [rsi + r10]
	LONG $0x171c8d4a         // lea    rbx, [rdi + r10]
	WORD $0x0149; BYTE $0xd2 // add    r10, rdx
	LONG $0x05e0c149         // shl    r8, 5
	WORD $0xc031             // xor    eax, eax

LBB1_6:
	LONG $0x0410fdc5; BYTE $0x03   // vmovupd    ymm0, yword [rbx + rax]
	LONG $0x5c7dc1c4; WORD $0x0104 // vsubpd    ymm0, ymm0, yword [r9 + rax]
	LONG $0x117dc1c4; WORD $0x0204 // vmovupd    yword [r10 + rax], ymm0
	LONG $0x20c08348               // add    rax, 32
	WORD $0x3949; BYTE $0xc0       // cmp    r8, rax
	JNE  LBB1_6

LBB1_7:
	WORD $0x8941; BYTE $0xc8 // mov    r8d, ecx
	LONG $0xfce08341         // and    r8d, -4

LBB1_8:
	WORD $0x3941; BYTE $0xc8 // cmp    r8d, ecx
	JAE  LBB1_21
	WORD $0x634d; BYTE $0xc8 // movsxd    r9, r8d
	WORD $0xf741; BYTE $0xd0 // not    r8d
	WORD $0x0141; BYTE $0xc8 // add    r8d, ecx
	LONG $0x0ff88341         // cmp    r8d, 15
	JAE  LBB1_13
	WORD $0x894c; BYTE $0xc8 // mov    rax, r9
	JMP  LBB1_20

LBB1_13:
	LONG $0xca148d4e         // lea    r10, [rdx + 8*r9]
	LONG $0x081c8d4b         // lea    rbx, [r8 + r9]
	LONG $0xda048d48         // lea    rax, [rdx + 8*rbx]
	LONG $0x08c08348         // add    rax, 8
	LONG $0xcf1c8d4e         // lea    r11, [rdi + 8*r9]
	LONG $0xdf348d4c         // lea    r14, [rdi + 8*rbx]
	LONG $0x08c68349         // add    r14, 8
	LONG $0xce3c8d4e         // lea    r15, [rsi + 8*r9]
	LONG $0xde1c8d48         // lea    rbx, [rsi + 8*rbx]
	LONG $0x08c38348         // add    rbx, 8
	WORD $0x394d; BYTE $0xf2 // cmp    r10, r14
	LONG $0xc6920f41         // setb    r14b
	WORD $0x3949; BYTE $0xc3 // cmp    r11, rax
	LONG $0xc3920f41         // setb    r11b
	WORD $0x3949; BYTE $0xda // cmp    r10, rbx
	WORD $0x920f; BYTE $0xc3 // setb    bl
	WORD $0x3949; BYTE $0xc7 // cmp    r15, rax
	WORD $0x920f; BYTE $0xc0 // setb    al
	WORD $0x8445; BYTE $0xde // test    r14b, r11b
	JNE  LBB1_14
	WORD $0xc320             // and    bl, al
	JNE  LBB1_16
	LONG $0x01c08349         // add    r8, 1
	WORD $0x894d; BYTE $0xc2 // mov    r10, r8
	LONG $0xf0e28349         // and    r10, -16
	LONG $0x0a048d4b         // lea    rax, [r10 + r9]
	LONG $0xcf1c8d4e         // lea    r11, [rdi + 8*r9]
	LONG $0x60c38349         // add    r11, 96
	LONG $0xce348d4e         // lea    r14, [rsi + 8*r9]
	LONG $0x60c68349         // add    r14, 96
	LONG $0xca0c8d4e         // lea    r9, [rdx + 8*r9]
	LONG $0x60c18349         // add    r9, 96
	WORD $0xdb31             // xor    ebx, ebx

LBB1_18:
	LONG $0x107dc1c4; WORD $0xdb44; BYTE $0xa0 // vmovupd    ymm0, yword [r11 + 8*rbx - 96]
	LONG $0x107dc1c4; WORD $0xdb4c; BYTE $0xc0 // vmovupd    ymm1, yword [r11 + 8*rbx - 64]
	LONG $0x107dc1c4; WORD $0xdb54; BYTE $0xe0 // vmovupd    ymm2, yword [r11 + 8*rbx - 32]
	LONG $0x107dc1c4; WORD $0xdb1c             // vmovupd    ymm3, yword [r11 + 8*rbx]
	LONG $0x5c7dc1c4; WORD $0xde44; BYTE $0xa0 // vsubpd    ymm0, ymm0, yword [r14 + 8*rbx - 96]
	LONG $0x5c75c1c4; WORD $0xde4c; BYTE $0xc0 // vsubpd    ymm1, ymm1, yword [r14 + 8*rbx - 64]
	LONG $0x5c6dc1c4; WORD $0xde54; BYTE $0xe0 // vsubpd    ymm2, ymm2, yword [r14 + 8*rbx - 32]
	LONG $0x5c65c1c4; WORD $0xde1c             // vsubpd    ymm3, ymm3, yword [r14 + 8*rbx]
	LONG $0x117dc1c4; WORD $0xd944; BYTE $0xa0 // vmovupd    yword [r9 + 8*rbx - 96], ymm0
	LONG $0x117dc1c4; WORD $0xd94c; BYTE $0xc0 // vmovupd    yword [r9 + 8*rbx - 64], ymm1
	LONG $0x117dc1c4; WORD $0xd954; BYTE $0xe0 // vmovupd    yword [r9 + 8*rbx - 32], ymm2
	LONG $0x117dc1c4; WORD $0xd91c             // vmovupd    yword [r9 + 8*rbx], ymm3
	LONG $0x10c38348                           // add    rbx, 16
	WORD $0x3949; BYTE $0xda                   // cmp    r10, rbx
	JNE  LBB1_18
	WORD $0x394d; BYTE $0xd0                   // cmp    r8, r10
	JNE  LBB1_20
	JMP  LBB1_21

LBB1_14:
	WORD $0x894c; BYTE $0xc8 // mov    rax, r9
	JMP  LBB1_20

LBB1_16:
	WORD $0x894c; BYTE $0xc8 // mov    rax, r9

LBB1_20:
	LONG $0x0410fbc5; BYTE $0xc7 // vmovsd    xmm0, qword [rdi + 8*rax]
	LONG $0x045cfbc5; BYTE $0xc6 // vsubsd    xmm0, xmm0, qword [rsi + 8*rax]
	LONG $0x0411fbc5; BYTE $0xc2 // vmovsd    qword [rdx + 8*rax], xmm0
	LONG $0x01c08348             // add    rax, 1
	WORD $0xc839                 // cmp    eax, ecx
	JB   LBB1_20

LBB1_21:
	VZEROUPPER
	RET

TEXT ·_mul_float64(SB), $0-32

	MOVQ input1+0(FP), DI
	MOVQ input2+8(FP), SI
	MOVQ output+16(FP), DX
	MOVQ info+24(FP), CX

	WORD $0x8948; BYTE $0xc8                   // mov    rax, rcx
	LONG $0x20e8c148                           // shr    rax, 32
	WORD $0x3145; BYTE $0xc0                   // xor    r8d, r8d
	WORD $0xf883; BYTE $0x01                   // cmp    eax, 1
	JNE  LBB2_8
	WORD $0xf983; BYTE $0x04                   // cmp    ecx, 4
	JB   LBB2_7
	WORD $0x8949; BYTE $0xc8                   // mov    r8, rcx
	LONG $0x02e8c149                           // shr    r8, 2
	WORD $0x8945; BYTE $0xc1                   // mov    r9d, r8d
	LONG $0xffe18141; WORD $0xffff; BYTE $0x3f // and    r9d, 1073741823
	LONG $0xff418d49                           // lea    rax, [r9 - 1]
	LONG $0x03e08341                           // and    r8d, 3
	LONG $0x03f88348                           // cmp    rax, 3
	JAE  LBB2_11
	WORD $0x3145; BYTE $0xd2                   // xor    r10d, r10d
	JMP  LBB2_4

LBB2_11:
	WORD $0x294d; BYTE $0xc1     // sub    r9, r8
	LONG $0x000060b8; BYTE $0x00 // mov    eax, 96
	WORD $0x3145; BYTE $0xd2     // xor    r10d, r10d

LBB2_12:
	LONG $0x4410fdc5; WORD $0xa006 // vmovupd    ymm0, yword [rsi + rax - 96]
	LONG $0x4459fdc5; WORD $0xa007 // vmulpd    ymm0, ymm0, yword [rdi + rax - 96]
	LONG $0x4411fdc5; WORD $0xa002 // vmovupd    yword [rdx + rax - 96], ymm0
	LONG $0x4410fdc5; WORD $0xc006 // vmovupd    ymm0, yword [rsi + rax - 64]
	LONG $0x4459fdc5; WORD $0xc007 // vmulpd    ymm0, ymm0, yword [rdi + rax - 64]
	LONG $0x4411fdc5; WORD $0xc002 // vmovupd    yword [rdx + rax - 64], ymm0
	LONG $0x4410fdc5; WORD $0xe006 // vmovupd    ymm0, yword [rsi + rax - 32]
	LONG $0x4459fdc5; WORD $0xe007 // vmulpd    ymm0, ymm0, yword [rdi + rax - 32]
	LONG $0x4411fdc5; WORD $0xe002 // vmovupd    yword [rdx + rax - 32], ymm0
	LONG $0x0410fdc5; BYTE $0x06   // vmovupd    ymm0, yword [rsi + rax]
	LONG $0x0459fdc5; BYTE $0x07   // vmulpd    ymm0, ymm0, yword [rdi + rax]
	LONG $0x0411fdc5; BYTE $0x02   // vmovupd    yword [rdx + rax], ymm0
	LONG $0x04c28349               // add    r10, 4
	LONG $0x80e88348               // sub    rax, -128
	WORD $0x394d; BYTE $0xd1       // cmp    r9, r10
	JNE  LBB2_12

LBB2_4:
	WORD $0x854d; BYTE $0xc0 // test    r8, r8
	JE   LBB2_7
	LONG $0x05e2c149         // shl    r10, 5
	LONG $0x160c8d4e         // lea    r9, [rsi + r10]
	LONG $0x171c8d4a         // lea    rbx, [rdi + r10]
	WORD $0x0149; BYTE $0xd2 // add    r10, rdx
	LONG $0x05e0c149         // shl    r8, 5
	WORD $0xc031             // xor    eax, eax

LBB2_6:
	LONG $0x107dc1c4; WORD $0x0104 // vmovupd    ymm0, yword [r9 + rax]
	LONG $0x0459fdc5; BYTE $0x03   // vmulpd    ymm0, ymm0, yword [rbx + rax]
	LONG $0x117dc1c4; WORD $0x0204 // vmovupd    yword [r10 + rax], ymm0
	LONG $0x20c08348               // add    rax, 32
	WORD $0x3949; BYTE $0xc0       // cmp    r8, rax
	JNE  LBB2_6

LBB2_7:
	WORD $0x8941; BYTE $0xc8 // mov    r8d, ecx
	LONG $0xfce08341         // and    r8d, -4

LBB2_8:
	WORD $0x3941; BYTE $0xc8 // cmp    r8d, ecx
	JAE  LBB2_21
	WORD $0x634d; BYTE $0xc8 // movsxd    r9, r8d
	WORD $0xf741; BYTE $0xd0 // not    r8d
	WORD $0x0141; BYTE $0xc8 // add    r8d, ecx
	LONG $0x0ff88341         // cmp    r8d, 15
	JAE  LBB2_13
	WORD $0x894c; BYTE $0xc8 // mov    rax, r9
	JMP  LBB2_20

LBB2_13:
	LONG $0xca148d4e         // lea    r10, [rdx + 8*r9]
	LONG $0x081c8d4b         // lea    rbx, [r8 + r9]
	LONG $0xda048d48         // lea    rax, [rdx + 8*rbx]
	LONG $0x08c08348         // add    rax, 8
	LONG $0xcf1c8d4e         // lea    r11, [rdi + 8*r9]
	LONG $0xdf348d4c         // lea    r14, [rdi + 8*rbx]
	LONG $0x08c68349         // add    r14, 8
	LONG $0xce3c8d4e         // lea    r15, [rsi + 8*r9]
	LONG $0xde1c8d48         // lea    rbx, [rsi + 8*rbx]
	LONG $0x08c38348         // add    rbx, 8
	WORD $0x394d; BYTE $0xf2 // cmp    r10, r14
	LONG $0xc6920f41         // setb    r14b
	WORD $0x3949; BYTE $0xc3 // cmp    r11, rax
	LONG $0xc3920f41         // setb    r11b
	WORD $0x3949; BYTE $0xda // cmp    r10, rbx
	WORD $0x920f; BYTE $0xc3 // setb    bl
	WORD $0x3949; BYTE $0xc7 // cmp    r15, rax
	WORD $0x920f; BYTE $0xc0 // setb    al
	WORD $0x8445; BYTE $0xde // test    r14b, r11b
	JNE  LBB2_14
	WORD $0xc320             // and    bl, al
	JNE  LBB2_16
	LONG $0x01c08349         // add    r8, 1
	WORD $0x894d; BYTE $0xc2 // mov    r10, r8
	LONG $0xf0e28349         // and    r10, -16
	LONG $0x0a048d4b         // lea    rax, [r10 + r9]
	LONG $0xcf1c8d4e         // lea    r11, [rdi + 8*r9]
	LONG $0x60c38349         // add    r11, 96
	LONG $0xce348d4e         // lea    r14, [rsi + 8*r9]
	LONG $0x60c68349         // add    r14, 96
	LONG $0xca0c8d4e         // lea    r9, [rdx + 8*r9]
	LONG $0x60c18349         // add    r9, 96
	WORD $0xdb31             // xor    ebx, ebx

LBB2_18:
	LONG $0x107dc1c4; WORD $0xde44; BYTE $0xa0 // vmovupd    ymm0, yword [r14 + 8*rbx - 96]
	LONG $0x107dc1c4; WORD $0xde4c; BYTE $0xc0 // vmovupd    ymm1, yword [r14 + 8*rbx - 64]
	LONG $0x107dc1c4; WORD $0xde54; BYTE $0xe0 // vmovupd    ymm2, yword [r14 + 8*rbx - 32]
	LONG $0x107dc1c4; WORD $0xde1c             // vmovupd    ymm3, yword [r14 + 8*rbx]
	LONG $0x597dc1c4; WORD $0xdb44; BYTE $0xa0 // vmulpd    ymm0, ymm0, yword [r11 + 8*rbx - 96]
	LONG $0x5975c1c4; WORD $0xdb4c; BYTE $0xc0 // vmulpd    ymm1, ymm1, yword [r11 + 8*rbx - 64]
	LONG $0x596dc1c4; WORD $0xdb54; BYTE $0xe0 // vmulpd    ymm2, ymm2, yword [r11 + 8*rbx - 32]
	LONG $0x5965c1c4; WORD $0xdb1c             // vmulpd    ymm3, ymm3, yword [r11 + 8*rbx]
	LONG $0x117dc1c4; WORD $0xd944; BYTE $0xa0 // vmovupd    yword [r9 + 8*rbx - 96], ymm0
	LONG $0x117dc1c4; WORD $0xd94c; BYTE $0xc0 // vmovupd    yword [r9 + 8*rbx - 64], ymm1
	LONG $0x117dc1c4; WORD $0xd954; BYTE $0xe0 // vmovupd    yword [r9 + 8*rbx - 32], ymm2
	LONG $0x117dc1c4; WORD $0xd91c             // vmovupd    yword [r9 + 8*rbx], ymm3
	LONG $0x10c38348                           // add    rbx, 16
	WORD $0x3949; BYTE $0xda                   // cmp    r10, rbx
	JNE  LBB2_18
	WORD $0x394d; BYTE $0xd0                   // cmp    r8, r10
	JNE  LBB2_20
	JMP  LBB2_21

LBB2_14:
	WORD $0x894c; BYTE $0xc8 // mov    rax, r9
	JMP  LBB2_20

LBB2_16:
	WORD $0x894c; BYTE $0xc8 // mov    rax, r9

LBB2_20:
	LONG $0x0410fbc5; BYTE $0xc6 // vmovsd    xmm0, qword [rsi + 8*rax]
	LONG $0x0459fbc5; BYTE $0xc7 // vmulsd    xmm0, xmm0, qword [rdi + 8*rax]
	LONG $0x0411fbc5; BYTE $0xc2 // vmovsd    qword [rdx + 8*rax], xmm0
	LONG $0x01c08348             // add    rax, 1
	WORD $0xc839                 // cmp    eax, ecx
	JB   LBB2_20

LBB2_21:
	VZEROUPPER
	RET

TEXT ·_div_float64(SB), $0-32

	MOVQ input1+0(FP), DI
	MOVQ input2+8(FP), SI
	MOVQ output+16(FP), DX
	MOVQ info+24(FP), CX

	WORD $0x8948; BYTE $0xc8     // mov    rax, rcx
	LONG $0x20e8c148             // shr    rax, 32
	WORD $0x3145; BYTE $0xc0     // xor    r8d, r8d
	WORD $0xf883; BYTE $0x01     // cmp    eax, 1
	JNE  LBB3_7
	WORD $0xf983; BYTE $0x04     // cmp    ecx, 4
	JB   LBB3_6
	WORD $0x8949; BYTE $0xc8     // mov    r8, rcx
	LONG $0x02e8c149             // shr    r8, 2
	WORD $0x8944; BYTE $0xc0     // mov    eax, r8d
	LONG $0xffffff25; BYTE $0x3f // and    eax, 1073741823
	LONG $0x01e08341             // and    r8d, 1
	LONG $0x01f88348             // cmp    rax, 1
	JNE  LBB3_13
	WORD $0xc031                 // xor    eax, eax
	JMP  LBB3_4

LBB3_13:
	WORD $0x894c; BYTE $0xc3 // mov    rbx, r8
	WORD $0x2948; BYTE $0xc3 // sub    rbx, rax
	WORD $0xc031             // xor    eax, eax

LBB3_14:
	LONG $0x0410fdc5; BYTE $0xc7   // vmovupd    ymm0, yword [rdi + 8*rax]
	LONG $0x045efdc5; BYTE $0xc6   // vdivpd    ymm0, ymm0, yword [rsi + 8*rax]
	LONG $0x0411fdc5; BYTE $0xc2   // vmovupd    yword [rdx + 8*rax], ymm0
	LONG $0x4410fdc5; WORD $0x20c7 // vmovupd    ymm0, yword [rdi + 8*rax + 32]
	LONG $0x445efdc5; WORD $0x20c6 // vdivpd    ymm0, ymm0, yword [rsi + 8*rax + 32]
	LONG $0x4411fdc5; WORD $0x20c2 // vmovupd    yword [rdx + 8*rax + 32], ymm0
	LONG $0x08c08348               // add    rax, 8
	LONG $0x02c38348               // add    rbx, 2
	JNE  LBB3_14

LBB3_4:
	WORD $0x854d; BYTE $0xc0     // test    r8, r8
	JE   LBB3_6
	LONG $0x0410fdc5; BYTE $0xc7 // vmovupd    ymm0, yword [rdi + 8*rax]
	LONG $0x045efdc5; BYTE $0xc6 // vdivpd    ymm0, ymm0, yword [rsi + 8*rax]
	LONG $0x0411fdc5; BYTE $0xc2 // vmovupd    yword [rdx + 8*rax], ymm0

LBB3_6:
	WORD $0x8941; BYTE $0xc8 // mov    r8d, ecx
	LONG $0xfce08341         // and    r8d, -4

LBB3_7:
	WORD $0x3941; BYTE $0xc8 // cmp    r8d, ecx
	JAE  LBB3_22
	WORD $0x6349; BYTE $0xc0 // movsxd    rax, r8d
	WORD $0xf741; BYTE $0xd0 // not    r8d
	WORD $0x0141; BYTE $0xc8 // add    r8d, ecx
	LONG $0x03f88341         // cmp    r8d, 3
	JAE  LBB3_9

LBB3_21:
	LONG $0x0410fbc5; BYTE $0xc7 // vmovsd    xmm0, qword [rdi + 8*rax]
	LONG $0x045efbc5; BYTE $0xc6 // vdivsd    xmm0, xmm0, qword [rsi + 8*rax]
	LONG $0x0411fbc5; BYTE $0xc2 // vmovsd    qword [rdx + 8*rax], xmm0
	LONG $0x01c08348             // add    rax, 1
	WORD $0xc839                 // cmp    eax, ecx
	JB   LBB3_21

LBB3_22:
	VZEROUPPER
	RET

LBB3_9:
	LONG $0xc20c8d4c         // lea    r9, [rdx + 8*rax]
	LONG $0x001c8d49         // lea    rbx, [r8 + rax]
	LONG $0xda148d4c         // lea    r10, [rdx + 8*rbx]
	LONG $0x08c28349         // add    r10, 8
	LONG $0xc71c8d4c         // lea    r11, [rdi + 8*rax]
	LONG $0xdf348d4c         // lea    r14, [rdi + 8*rbx]
	LONG $0x08c68349         // add    r14, 8
	LONG $0xc63c8d4c         // lea    r15, [rsi + 8*rax]
	LONG $0xde1c8d48         // lea    rbx, [rsi + 8*rbx]
	LONG $0x08c38348         // add    rbx, 8
	WORD $0x394d; BYTE $0xf1 // cmp    r9, r14
	LONG $0xc6920f41         // setb    r14b
	WORD $0x394d; BYTE $0xd3 // cmp    r11, r10
	LONG $0xc3920f41         // setb    r11b
	WORD $0x3949; BYTE $0xd9 // cmp    r9, rbx
	WORD $0x920f; BYTE $0xc3 // setb    bl
	WORD $0x394d; BYTE $0xd7 // cmp    r15, r10
	LONG $0xc1920f41         // setb    r9b
	WORD $0x8445; BYTE $0xde // test    r14b, r11b
	JNE  LBB3_21
	WORD $0x2044; BYTE $0xcb // and    bl, r9b
	JNE  LBB3_21
	LONG $0x01c08349         // add    r8, 1
	WORD $0x894d; BYTE $0xc1 // mov    r9, r8
	LONG $0xfce18349         // and    r9, -4
	LONG $0xfc598d49         // lea    rbx, [r9 - 4]
	WORD $0x8949; BYTE $0xda // mov    r10, rbx
	LONG $0x02eac149         // shr    r10, 2
	LONG $0x01c28349         // add    r10, 1
	WORD $0x8548; BYTE $0xdb // test    rbx, rbx
	JE   LBB3_12
	LONG $0xc2348d4c         // lea    r14, [rdx + 8*rax]
	LONG $0x20c68349         // add    r14, 32
	LONG $0xc63c8d4c         // lea    r15, [rsi + 8*rax]
	LONG $0x20c78349         // add    r15, 32
	LONG $0xc7248d4c         // lea    r12, [rdi + 8*rax]
	LONG $0x20c48349         // add    r12, 32
	WORD $0x894c; BYTE $0xd3 // mov    rbx, r10
	LONG $0xfee38348         // and    rbx, -2
	WORD $0xf748; BYTE $0xdb // neg    rbx
	WORD $0x3145; BYTE $0xdb // xor    r11d, r11d

LBB3_16:
	LONG $0x107d81c4; WORD $0xdc44; BYTE $0xe0 // vmovupd    ymm0, yword [r12 + 8*r11 - 32]
	LONG $0x5e7d81c4; WORD $0xdf44; BYTE $0xe0 // vdivpd    ymm0, ymm0, yword [r15 + 8*r11 - 32]
	LONG $0x117d81c4; WORD $0xde44; BYTE $0xe0 // vmovupd    yword [r14 + 8*r11 - 32], ymm0
	LONG $0x107d81c4; WORD $0xdc04             // vmovupd    ymm0, yword [r12 + 8*r11]
	LONG $0x5e7d81c4; WORD $0xdf04             // vdivpd    ymm0, ymm0, yword [r15 + 8*r11]
	LONG $0x117d81c4; WORD $0xde04             // vmovupd    yword [r14 + 8*r11], ymm0
	LONG $0x08c38349                           // add    r11, 8
	LONG $0x02c38348                           // add    rbx, 2
	JNE  LBB3_16
	LONG $0x01c2f641                           // test    r10b, 1
	JE   LBB3_19

LBB3_18:
	WORD $0x0149; BYTE $0xc3       // add    r11, rax
	LONG $0x107da1c4; WORD $0xdf04 // vmovupd    ymm0, yword [rdi + 8*r11]
	LONG $0x5e7da1c4; WORD $0xde04 // vdivpd    ymm0, ymm0, yword [rsi + 8*r11]
	LONG $0x117da1c4; WORD $0xda04 // vmovupd    yword [rdx + 8*r11], ymm0

LBB3_19:
	WORD $0x394d; BYTE $0xc8 // cmp    r8, r9
	JE   LBB3_22
	WORD $0x014c; BYTE $0xc8 // add    rax, r9
	JMP  LBB3_21

LBB3_12:
	WORD $0x3145; BYTE $0xdb // xor    r11d, r11d
	LONG $0x01c2f641         // test    r10b, 1
	JNE  LBB3_18
	JMP  LBB3_19
