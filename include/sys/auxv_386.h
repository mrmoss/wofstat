/*
 * Copyright (c) 2004, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_AUXV_386_H
#define	_SYS_AUXV_386_H

#pragma ident	"@(#)auxv_386.h	1.11	12/06/03 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Flags used in AT_SUN_CAP_HW* elements to describe various userland
 * instruction set extensions available on different processors.
 * The basic assumption is that of the i386 ABI; that is, i386 plus i387
 * floating point.
 *
 * Note that if a given bit is set; the implication is that the kernel
 * provides all the underlying architectural support for the correct
 * functioning of the extended instruction(s).
 */
#define	AV_386_FPU		0x00001	/* x87-style floating point */
#define	AV_386_TSC		0x00002	/* rdtsc insn */
#define	AV_386_CX8		0x00004	/* cmpxchg8b insn */
#define	AV_386_SEP		0x00008	/* sysenter and sysexit */
#define	AV_386_AMD_SYSC		0x00010	/* AMD's syscall and sysret */
#define	AV_386_CMOV		0x00020	/* conditional move insns */
#define	AV_386_MMX		0x00040	/* MMX insns */
#define	AV_386_AMD_MMX		0x00080	/* AMD's MMX insns */
#define	AV_386_AMD_3DNow	0x00100	/* AMD's 3Dnow! insns */
#define	AV_386_AMD_3DNowx	0x00200	/* AMD's 3Dnow! extended insns */
#define	AV_386_FXSR		0x00400	/* fxsave and fxrstor */
#define	AV_386_SSE		0x00800	/* SSE insns and regs */
#define	AV_386_SSE2		0x01000	/* SSE2 insns and regs */
					/* 0x02000 withdrawn - do not assign */
#define	AV_386_SSE3		0x04000	/* SSE3 insns and regs */
					/* 0x08000 withdrawn - do not assign */
#define	AV_386_CX16		0x10000	/* cmpxchg16b insn */
#define	AV_386_AHF		0x20000	/* lahf/sahf insns */
#define	AV_386_TSCP		0x40000	/* rdtscp instruction */
#define	AV_386_AMD_SSE4A	0x80000	/* AMD's SSE4A insns */
#define	AV_386_POPCNT		0x100000 /* POPCNT insn */
#define	AV_386_AMD_LZCNT	0x200000 /* AMD's LZCNT insn */
#define	AV_386_SSSE3		0x400000 /* Intel SSSE3 insns */
#define	AV_386_SSE4_1		0x800000 /* Intel SSE4.1 insns */
#define	AV_386_SSE4_2		0x1000000 /* Intel SSE4.2 insns */
#define	AV_386_MOVBE		0x2000000 /* Intel MOVBE insns */
#define	AV_386_AES		0x4000000 /* Intel AES insns */
#define	AV_386_PCLMULQDQ	0x8000000 /* Intel PCLMULQDQ insn */
#define	AV_386_XSAVE		0x10000000 /* Intel XSAVE/XRSTOR insns */
#define	AV_386_AVX		0x20000000 /* Intel AVX insns */
#define	AV_386_AMD_XOP		0x40000000 /* AMD XOP insns */
#define	AV_386_AMD_FMA4		0x80000000 /* AMD FMA4 insns */

#define	FMT_AV_386_HW1							\
	"\20"								\
	"\40amd_fma4\37amd_xop"						\
	"\36avx\35xsave"						\
	"\34pclmulqdq\33aes"						\
	"\32movbe\31sse4.2"						\
	"\30sse4.1\27ssse3\26amd_lzcnt\25popcnt"			\
	"\24amd_sse4a\23tscp\22ahf\21cx16"				\
	"\17sse3\15sse2\14sse\13fxsr\12amd3dx\11amd3d"	\
	"\10amdmmx\7mmx\6cmov\5amdsysc\4sep\3cx8\2tsc\1fpu"

#define	FMT_AV_386_HW2							\
	"\20"								\
	"\6fsgsbase\5bmi1\4amd_tbm\3f16c\2fma\1rdrand"

/*
 * Flags used in AT_SUN_CAP_HW2 elements.
 */
#define	AV2_386_RDRAND		0x00001 /* Intel RDRAND insns */
#define	AV2_386_FMA		0x00002 /* Intel FMA insn */
#define	AV2_386_F16C		0x00004 /* IEEE half precn(float) insn */
#define	AV2_386_AMD_TBM		0x00008 /* AMD TBM insn */
#define	AV2_386_BMI1		0x00010 /* Intel BMI1 insn */
#define	AV2_386_FSGSBASE	0x00020	/* Intel RD/WR FS/GSBASE insn */

#ifdef __cplusplus
}
#endif

#endif	/* !_SYS_AUXV_386_H */
