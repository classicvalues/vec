//+build !noasm !appengine
// AUTO-GENERATED BY C2GOASM -- DO NOT EDIT

TEXT ·_populate_positions_ctz(SB), $0-24

	MOVQ input+0(FP), DI
	MOVQ out+8(FP), SI
	MOVQ count+16(FP), DX

	LONG $0xb80f4cf3; BYTE $0xc7 // popcnt    r8, rdi
	JE   LBB0_7
	LONG $0x01f88341             // cmp    r8d, 1
	JNE  LBB0_3
	WORD $0xc931                 // xor    ecx, ecx
	JMP  LBB0_5

LBB0_3:
	WORD $0x8945; BYTE $0xc1 // mov    r9d, r8d
	LONG $0xfee18341         // and    r9d, -2
	WORD $0xc931             // xor    ecx, ecx

LBB0_4:
	LONG $0xc7bc0f48         // bsf    rax, rdi
	WORD $0x0489; BYTE $0x8e // mov    dword [rsi + 4*rcx], eax
	LONG $0xff478d48         // lea    rax, [rdi - 1]
	WORD $0x2148; BYTE $0xf8 // and    rax, rdi
	LONG $0xf8bc0f48         // bsf    rdi, rax
	LONG $0x048e7c89         // mov    dword [rsi + 4*rcx + 4], edi
	LONG $0x02c18348         // add    rcx, 2
	LONG $0xff788d48         // lea    rdi, [rax - 1]
	WORD $0x2148; BYTE $0xc7 // and    rdi, rax
	WORD $0x3949; BYTE $0xc9 // cmp    r9, rcx
	JNE  LBB0_4

LBB0_5:
	LONG $0x01c0f641         // test    r8b, 1
	JE   LBB0_7
	LONG $0xc7bc0f48         // bsf    rax, rdi
	WORD $0x0489; BYTE $0x8e // mov    dword [rsi + 4*rcx], eax

LBB0_7:
	WORD $0x8944; BYTE $0x02 // mov    dword [rdx], r8d
	RET
