/*
 * Copyright (c) 1995, 2012, Oracle and/or its affiliates. All rights reserved.
 */
/*
 * Copyright (c) 2012, Intel Corporation.
 * All rights reserved.
 */

#ifndef _SYS_X86_ARCHEXT_H
#define	_SYS_X86_ARCHEXT_H

#pragma ident	"@(#)x86_archext.h	1.74	12/06/29 SMI"

#if !defined(_ASM)
#include <sys/regset.h>
#include <sys/processor.h>
#include <vm/seg_enum.h>
#include <vm/page.h>
#endif	/* _ASM */

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * cpuid instruction feature flags in %edx (standard function 1)
 */

#define	CPUID_INTC_EDX_FPU	0x00000001	/* x87 fpu present */
#define	CPUID_INTC_EDX_VME	0x00000002	/* virtual-8086 extension */
#define	CPUID_INTC_EDX_DE	0x00000004	/* debugging extensions */
#define	CPUID_INTC_EDX_PSE	0x00000008	/* page size extension */
#define	CPUID_INTC_EDX_TSC	0x00000010	/* time stamp counter */
#define	CPUID_INTC_EDX_MSR	0x00000020	/* rdmsr and wrmsr */
#define	CPUID_INTC_EDX_PAE	0x00000040	/* physical addr extension */
#define	CPUID_INTC_EDX_MCE	0x00000080	/* machine check exception */
#define	CPUID_INTC_EDX_CX8	0x00000100	/* cmpxchg8b instruction */
#define	CPUID_INTC_EDX_APIC	0x00000200	/* local APIC */
						/* 0x400 - reserved */
#define	CPUID_INTC_EDX_SEP	0x00000800	/* sysenter and sysexit */
#define	CPUID_INTC_EDX_MTRR	0x00001000	/* memory type range reg */
#define	CPUID_INTC_EDX_PGE	0x00002000	/* page global enable */
#define	CPUID_INTC_EDX_MCA	0x00004000	/* machine check arch */
#define	CPUID_INTC_EDX_CMOV	0x00008000	/* conditional move insns */
#define	CPUID_INTC_EDX_PAT	0x00010000	/* page attribute table */
#define	CPUID_INTC_EDX_PSE36	0x00020000	/* 36-bit pagesize extension */
#define	CPUID_INTC_EDX_PSN	0x00040000	/* processor serial number */
#define	CPUID_INTC_EDX_CLFSH	0x00080000	/* clflush instruction */
						/* 0x100000 - reserved */
#define	CPUID_INTC_EDX_DS	0x00200000	/* debug store exists */
#define	CPUID_INTC_EDX_ACPI	0x00400000	/* monitoring + clock ctrl */
#define	CPUID_INTC_EDX_MMX	0x00800000	/* MMX instructions */
#define	CPUID_INTC_EDX_FXSR	0x01000000	/* fxsave and fxrstor */
#define	CPUID_INTC_EDX_SSE	0x02000000	/* streaming SIMD extensions */
#define	CPUID_INTC_EDX_SSE2	0x04000000	/* SSE extensions */
#define	CPUID_INTC_EDX_SS	0x08000000	/* self-snoop */
#define	CPUID_INTC_EDX_HTT	0x10000000	/* Hyper Thread Technology */
#define	CPUID_INTC_EDX_TM	0x20000000	/* thermal monitoring */
						/* 0x40000000 - reserved */
#define	CPUID_INTC_EDX_PBE	0x80000000	/* Pending Break Enable */

/*
 * cpuid instruction feature flags in %ecx (standard function 1)
 */

#define	CPUID_INTC_ECX_SSE3	0x00000001	/* Yet more SSE extensions */
#define	CPUID_INTC_ECX_PCLMULQDQ 0x00000002	/* PCLMULQDQ insn */
						/* 0x00000004 - reserved */
#define	CPUID_INTC_ECX_MON	0x00000008	/* MONITOR/MWAIT */
#define	CPUID_INTC_ECX_DSCPL	0x00000010	/* CPL-qualified debug store */
						/* 0x00000020 - reserved */
						/* 0x00000040 - reserved */
#define	CPUID_INTC_ECX_EST	0x00000080	/* enhanced SpeedStep */
#define	CPUID_INTC_ECX_TM2	0x00000100	/* thermal monitoring */
#define	CPUID_INTC_ECX_SSSE3	0x00000200	/* Supplemental SSE3 insns */
#define	CPUID_INTC_ECX_CID	0x00000400	/* L1 context ID */
						/* 0x00000800 - reserved */
#define	CPUID_INTC_ECX_FMA	0x00001000	/* FMA instruction support */
#define	CPUID_INTC_ECX_CX16	0x00002000	/* CMPXCHG16B */
#define	CPUID_INTC_ECX_XTPR	0x00004000	/* disable task pri messages */
#define	CPUID_INTC_ECX_SSE4_1	0x00080000	/* SSE4.1 insns */
#define	CPUID_INTC_ECX_SSE4_2	0x00100000	/* SSE4.2 insns */
#define	CPUID_INTC_ECX_X2APIC	0x00200000	/* X2Apic */
#define	CPUID_INTC_ECX_POPCNT	0x00800000	/* POPCNT insn */
#define	CPUID_INTC_ECX_AES	0x02000000	/* AES insns */
#define	CPUID_INTC_ECX_XSAVE	0x04000000	/* XSAVE/XRESTOR insns */
#define	CPUID_INTC_ECX_OSXSAVE	0x08000000	/* OS supports XSAVE insns */
#define	CPUID_INTC_ECX_AVX	0x10000000	/* AVX supported */
#define	CPUID_INTC_ECX_F16C	0x20000000	/* F16C (CVT16) */
#define	CPUID_INTC_ECX_RDRAND	0x40000000	/* RDRAND supported */
						/* 0x80000000 - reserved */
/*
 * cpuid instruction feature flags in %ebx (standard function 7)
 */
#define	CPUID_INTC_EBX_FSGSBASE	0x00000001	/* FSGSBASE */
#define	CPUID_INTC_EBX_BMI1	0x00000008	/* BMI1	*/
#define	CPUID_INTC_EBX_EFS	0x000000200	/* Enhanced fast string */

/*
 * cpuid instruction feature flags in %edx (extended function 0x80000001)
 */

#define	CPUID_AMD_EDX_FPU	0x00000001	/* x87 fpu present */
#define	CPUID_AMD_EDX_VME	0x00000002	/* virtual-8086 extension */
#define	CPUID_AMD_EDX_DE	0x00000004	/* debugging extensions */
#define	CPUID_AMD_EDX_PSE	0x00000008	/* page size extensions */
#define	CPUID_AMD_EDX_TSC	0x00000010	/* time stamp counter */
#define	CPUID_AMD_EDX_MSR	0x00000020	/* rdmsr and wrmsr */
#define	CPUID_AMD_EDX_PAE	0x00000040	/* physical addr extension */
#define	CPUID_AMD_EDX_MCE	0x00000080	/* machine check exception */
#define	CPUID_AMD_EDX_CX8	0x00000100	/* cmpxchg8b instruction */
#define	CPUID_AMD_EDX_APIC	0x00000200	/* local APIC */
						/* 0x00000400 - sysc on K6m6 */
#define	CPUID_AMD_EDX_SYSC	0x00000800	/* AMD: syscall and sysret */
#define	CPUID_AMD_EDX_MTRR	0x00001000	/* memory type and range reg */
#define	CPUID_AMD_EDX_PGE	0x00002000	/* page global enable */
#define	CPUID_AMD_EDX_MCA	0x00004000	/* machine check arch */
#define	CPUID_AMD_EDX_CMOV	0x00008000	/* conditional move insns */
#define	CPUID_AMD_EDX_PAT	0x00010000	/* page attribute table */
#define	CPUID_AMD_EDX_PSE36	0x00020000	/* 36-bit pagesize extension */
						/* 0x00040000 - reserved */
						/* 0x00080000 - reserved */
#define	CPUID_AMD_EDX_NX	0x00100000	/* AMD: no-execute page prot */
						/* 0x00200000 - reserved */
#define	CPUID_AMD_EDX_MMXamd	0x00400000	/* AMD: MMX extensions */
#define	CPUID_AMD_EDX_MMX	0x00800000	/* MMX instructions */
#define	CPUID_AMD_EDX_FXSR	0x01000000	/* fxsave and fxrstor */
						/* 0x02000000 - reserved */
#define	CPUID_AMD_EDX_1GPG	0x04000000	/* 1GB page */
#define	CPUID_AMD_EDX_TSCP	0x08000000	/* rdtscp instruction */
						/* 0x10000000 - reserved */
#define	CPUID_AMD_EDX_LM	0x20000000	/* AMD: long mode */
#define	CPUID_AMD_EDX_3DNowx	0x40000000	/* AMD: extensions to 3DNow! */
#define	CPUID_AMD_EDX_3DNow	0x80000000	/* AMD: 3DNow! instructions */

/*
 * cpuid instruction feature flags in %ecx (extended function 0x80000001)
 */
#define	CPUID_AMD_ECX_AHF64	0x00000001	/* LAHF and SAHF in long mode */
#define	CPUID_AMD_ECX_CMP_LEGACY 0x00000002	/* AMD: multi-core chip */
						/* 0x00000004 - reserved */
						/* 0x00000008 - reserved */
						/* 0x00000010 - reserved */
#define	CPUID_AMD_ECX_LZCNT	0x00000020	/* AMD: LZCNT insn */
#define	CPUID_AMD_ECX_SSE4A	0x00000040	/* AMD: SSE4A insns */
#define	CPUID_AMD_ECX_MAS	0x00000080	/* AMD: MisAlignSse mnode */
#define	CPUID_AMD_ECX_3DNP	0x00000100	/* AMD: 3DNowPrefectch */
#define	CPUID_AMD_ECX_OSVW	0x00000200	/* AMD: OSVW */
#define	CPUID_AMD_ECX_IBS	0x00000400	/* AMD: IBS */
#define	CPUID_AMD_ECX_XOP	0x00000800	/* AMD: XOP */
#define	CPUID_AMD_ECX_SKINIT	0x00001000	/* AMD: SKINIT */
#define	CPUID_AMD_ECX_WDT	0x00002000	/* AMD: WDT */
						/* 0x00004000 - reserved */
#define	CPUID_AMD_ECX_LWP	0x00008000	/* AMD: LightWeight Profiling */
#define	CPUID_AMD_ECX_FMA4	0x00010000	/* AMD: FMA4 */
#define	CPUID_AMD_ECX_TCE	0x00020000	/* AMD: Translation Cache Ext */
						/* 0x00040000 - reserved */
#define	CPUID_AMD_ECX_NID_MSR	0x00080000	/* AMD: NodeID */
						/* 0x00100000 - reserved */
#define	CPUID_AMD_ECX_TBM	0x00200000	/* AMD: TBM */
#define	CPUID_AMD_ECX_TOPO_EXT	0x00400000	/* AMD: TopologyExtentions */
#define	CPUID_AMD_ECX_PCEXCORE	0x00800000	/* AMD: core perf counter ext */
#define	CPUID_AMD_ECX_PCEXNB	0x01000000	/* AMD: NB perf counter ext */
						/* 0x02000000 - reserved */
						/* 0x04000000 - reserved */
						/* 0x08000000 - reserved */
						/* 0x10000000 - reserved */
						/* 0x20000000 - reserved */
						/* 0x40000000 - reserved */
						/* 0x80000000 - reserved */


#define	P5_MCHADDR	0x0
#define	P5_CESR		0x11
#define	P5_CTR0		0x12
#define	P5_CTR1		0x13

#define	K5_MCHADDR	0x0
#define	K5_MCHTYPE	0x01
#define	K5_TSC		0x10
#define	K5_TR12		0x12

#define	REG_MTRRCAP		0xfe
#define	REG_MTRRDEF		0x2ff
#define	REG_MTRR64K		0x250
#define	REG_MTRR16K1		0x258
#define	REG_MTRR16K2		0x259
#define	REG_MTRR4K1		0x268
#define	REG_MTRR4K2		0x269
#define	REG_MTRR4K3		0x26a
#define	REG_MTRR4K4		0x26b
#define	REG_MTRR4K5		0x26c
#define	REG_MTRR4K6		0x26d
#define	REG_MTRR4K7		0x26e
#define	REG_MTRR4K8		0x26f
#define	REG_MTRRPAT		0x277

#define	REG_MTRRPHYSBASE0	0x200
#define	REG_MTRRPHYSMASK7	0x20f
#define	REG_MC0_CTL		0x400
#define	REG_MC5_MISC		0x417
#define	REG_PERFCTR0		0xc1
#define	REG_PERFCTR1		0xc2

#define	REG_PERFEVNT0		0x186
#define	REG_PERFEVNT1		0x187

#define	REG_TSC			0x10	/* timestamp counter */
#define	REG_APIC_BASE_MSR	0x1b
#define	REG_X2APIC_BASE_MSR	0x800	/* The MSR address offset of x2APIC */

/*
 * AMD C1E
 */
#define	MSR_AMD_INT_PENDING_CMP_HALT	0xC0010055
#define	AMD_ACTONCMPHALT_SHIFT		27
#define	AMD_ACTONCMPHALT_MASK		3

#define	MSR_DEBUGCTL		0x1d9

#define	DEBUGCTL_LBR		0x01
#define	DEBUGCTL_BTF		0x02

/* Intel P6, AMD */
#define	MSR_LBR_FROM		0x1db
#define	MSR_LBR_TO		0x1dc
#define	MSR_LEX_FROM		0x1dd
#define	MSR_LEX_TO		0x1de

/* Intel P4 (pre-Prescott, non P4 M) */
#define	MSR_P4_LBSTK_TOS	0x1da
#define	MSR_P4_LBSTK_0		0x1db
#define	MSR_P4_LBSTK_1		0x1dc
#define	MSR_P4_LBSTK_2		0x1dd
#define	MSR_P4_LBSTK_3		0x1de

/* Intel Pentium M */
#define	MSR_P6M_LBSTK_TOS	0x1c9
#define	MSR_P6M_LBSTK_0		0x040
#define	MSR_P6M_LBSTK_1		0x041
#define	MSR_P6M_LBSTK_2		0x042
#define	MSR_P6M_LBSTK_3		0x043
#define	MSR_P6M_LBSTK_4		0x044
#define	MSR_P6M_LBSTK_5		0x045
#define	MSR_P6M_LBSTK_6		0x046
#define	MSR_P6M_LBSTK_7		0x047

/* Intel P4 (Prescott) */
#define	MSR_PRP4_LBSTK_TOS	0x1da
#define	MSR_PRP4_LBSTK_FROM_0	0x680
#define	MSR_PRP4_LBSTK_FROM_1	0x681
#define	MSR_PRP4_LBSTK_FROM_2	0x682
#define	MSR_PRP4_LBSTK_FROM_3	0x683
#define	MSR_PRP4_LBSTK_FROM_4	0x684
#define	MSR_PRP4_LBSTK_FROM_5	0x685
#define	MSR_PRP4_LBSTK_FROM_6	0x686
#define	MSR_PRP4_LBSTK_FROM_7	0x687
#define	MSR_PRP4_LBSTK_FROM_8 	0x688
#define	MSR_PRP4_LBSTK_FROM_9	0x689
#define	MSR_PRP4_LBSTK_FROM_10	0x68a
#define	MSR_PRP4_LBSTK_FROM_11 	0x68b
#define	MSR_PRP4_LBSTK_FROM_12	0x68c
#define	MSR_PRP4_LBSTK_FROM_13	0x68d
#define	MSR_PRP4_LBSTK_FROM_14	0x68e
#define	MSR_PRP4_LBSTK_FROM_15	0x68f
#define	MSR_PRP4_LBSTK_TO_0	0x6c0
#define	MSR_PRP4_LBSTK_TO_1	0x6c1
#define	MSR_PRP4_LBSTK_TO_2	0x6c2
#define	MSR_PRP4_LBSTK_TO_3	0x6c3
#define	MSR_PRP4_LBSTK_TO_4	0x6c4
#define	MSR_PRP4_LBSTK_TO_5	0x6c5
#define	MSR_PRP4_LBSTK_TO_6	0x6c6
#define	MSR_PRP4_LBSTK_TO_7	0x6c7
#define	MSR_PRP4_LBSTK_TO_8	0x6c8
#define	MSR_PRP4_LBSTK_TO_9 	0x6c9
#define	MSR_PRP4_LBSTK_TO_10	0x6ca
#define	MSR_PRP4_LBSTK_TO_11	0x6cb
#define	MSR_PRP4_LBSTK_TO_12	0x6cc
#define	MSR_PRP4_LBSTK_TO_13	0x6cd
#define	MSR_PRP4_LBSTK_TO_14	0x6ce
#define	MSR_PRP4_LBSTK_TO_15	0x6cf

#define	MCI_CTL_VALUE		0xffffffff

#define	MTRRTYPE_MASK		0xff

#define	MTRRCAP_FIX		0x100
#define	MTRRCAP_VCNTMASK	0xff
#define	MTRRCAP_USWC		0x400

#define	MTRRDEF_E		0x800
#define	MTRRDEF_FE		0x400

#define	MTRRPHYSMASK_V		0x800

#define	MTRR_TYPE_UC		0
#define	MTRR_TYPE_WC		1
#define	MTRR_TYPE_WT		4
#define	MTRR_TYPE_WP		5
#define	MTRR_TYPE_WB		6

/*
 * Page attribute table is setup in the following way
 * PAT0	Write-BACK
 * PAT1	Write-Through
 * PAT2	Unchacheable
 * PAT3	Uncacheable
 * PAT4 Uncacheable
 * PAT5	Write-Protect
 * PAT6	Write-Combine
 * PAT7 Uncacheable
 */
#define	PAT_DEFAULT_ATTRIBUTE \
	((uint64_t)MTRR_TYPE_WC << 48)|((uint64_t)MTRR_TYPE_WP << 40)| \
	(MTRR_TYPE_WT << 8)|(MTRR_TYPE_WB)


#define	MTRR_SETTYPE(a, t)	((a &= (uint64_t)~0xff),\
				    (a |= ((t) & 0xff)))
#define	MTRR_SETVINVALID(a)	((a) &= ~MTRRPHYSMASK_V)


#define	MTRR_SETVBASE(a, b, t)	((a) =\
					((((uint64_t)(b)) & 0xffffff000)|\
					(((uint32_t)(t)) & 0xff)))

#define	MTRR_SETVMASK(a, s, v) ((a) =\
				((~(((uint64_t)(s)) - 1) & 0xffffff000)|\
					(((uint32_t)(v)) << 11)))

#define	MTRR_GETVBASE(a)	(((uint64_t)(a)) & 0xffffff000)
#define	MTRR_GETVTYPE(a)	(((uint64_t)(a)) & 0xff)
#define	MTRR_GETVSIZE(a)	((~((uint64_t)(a)) + 1) & 0xffffff000)


#define	MAX_MTRRVAR	8

#if !defined(_ASM)
typedef	struct	mtrrvar {
	uint64_t	mtrrphys_base;
	uint64_t	mtrrphys_mask;
} mtrrvar_t;
#endif	/* _ASM */

#define	X86FSET_LARGEPAGE	0
#define	X86FSET_TSC		1
#define	X86FSET_MSR		2
#define	X86FSET_MTRR		3
#define	X86FSET_PGE		4
				/* 5 reserved */
#define	X86FSET_CMOV		6
#define	X86FSET_MMX 		7
#define	X86FSET_MCA		8
#define	X86FSET_PAE		9
#define	X86FSET_CX8		10
#define	X86FSET_PAT		11
#define	X86FSET_SEP		12
#define	X86FSET_SSE		13
#define	X86FSET_SSE2		14
#define	X86FSET_HTT		15
#define	X86FSET_ASYSC		16
#define	X86FSET_NX		17
#define	X86FSET_SSE3		18
#define	X86FSET_CX16		19
#define	X86FSET_CMP		20
#define	X86FSET_TSCP		21
#define	X86FSET_MWAIT		22
#define	X86FSET_SSE4A		23
#define	X86FSET_CPUID		24
#define	X86FSET_SSSE3		25
#define	X86FSET_SSE4_1		26
#define	X86FSET_SSE4_2		27
#define	X86FSET_1GPG		28
#define	X86FSET_CLFSH		29
				/* 30 reserved */
#define	X86FSET_AES		31
#define	X86FSET_PCLMULQDQ	32
#define	X86FSET_XSAVE		33
#define	X86FSET_AVX		34
				/* 35 reserved */
#define	X86FSET_RDRAND		36
#define	X86FSET_EFS		37

/*
 * The X86_* #defines are kept here only for compatibility with modules
 * that have not been updated to use the is_x86_feature() routines.
 */
#define	X86_LARGEPAGE		0x00000001
#define	X86_TSC			0x00000002
#define	X86_MSR			0x00000004
#define	X86_MTRR		0x00000008
#define	X86_PGE			0x00000010
#define	X86_CMOV		0x00000040
#define	X86_MMX			0x00000080
#define	X86_MCA			0x00000100
#define	X86_PAE			0x00000200
#define	X86_CX8			0x00000400
#define	X86_PAT			0x00000800
#define	X86_SEP			0x00001000
#define	X86_SSE			0x00002000
#define	X86_SSE2		0x00004000
#define	X86_HTT			0x00008000
#define	X86_ASYSC		0x00010000
#define	X86_NX			0x00020000
#define	X86_SSE3		0x00040000
#define	X86_CX16		0x00080000
#define	X86_CMP			0x00100000
#define	X86_TSCP		0x00200000
#define	X86_MWAIT		0x00400000
#define	X86_SSE4A		0x00800000
#define	X86_CPUID		0x01000000
#define	X86_SSSE3		0x02000000
#define	X86_SSE4_1		0x04000000
#define	X86_SSE4_2		0x08000000
#define	X86_1GPG		0x10000000
#define	X86_CLFSH		0x20000000
#define	X86_AES			0x80000000

/*
 * flags to patch tsc_read routine.
 */
#define	X86_NO_TSC		0x0
#define	X86_HAVE_TSCP		0x1
#define	X86_TSC_MFENCE		0x2
#define	X86_TSC_LFENCE		0x4

/*
 * Intel and AMD Deep C-State invariant TSC in leaf 0x80000007.
 */
#define	CPUID_TSC_CSTATE_INVARIANCE	(0x100)

/*
 * Intel Deep C-state always-running local APIC timer
 */
#define	CPUID_CSTATE_ARAT		(0x4)

/*
 * Intel ENERGY_PERF_BIAS MSR indicated by feature bit CPUID.6.EAX[2].
 */
#define	CPUID_EPB_SUPPORT		(1 << 3)

/*
 * x86_type is a legacy concept; this is supplanted
 * for most purposes by x86_featureset; modern CPUs
 * should be X86_TYPE_OTHER
 */
#define	X86_TYPE_OTHER		0
#define	X86_TYPE_486		1
#define	X86_TYPE_P5		2
#define	X86_TYPE_P6		3
#define	X86_TYPE_CYRIX_486	4
#define	X86_TYPE_CYRIX_6x86L	5
#define	X86_TYPE_CYRIX_6x86	6
#define	X86_TYPE_CYRIX_GXm	7
#define	X86_TYPE_CYRIX_6x86MX	8
#define	X86_TYPE_CYRIX_MediaGX	9
#define	X86_TYPE_CYRIX_MII	10
#define	X86_TYPE_VIA_CYRIX_III	11
#define	X86_TYPE_P4		12

/*
 * x86_vendor allows us to select between
 * implementation features and helps guide
 * the interpretation of the cpuid instruction.
 */
#define	X86_VENDOR_Intel	0	/* GenuineIntel */
#define	X86_VENDOR_IntelClone	1	/* (an Intel clone) */
#define	X86_VENDOR_AMD		2	/* AuthenticAMD */
#define	X86_VENDOR_Cyrix	3	/* CyrixInstead */
#define	X86_VENDOR_UMC		4	/* UMC UMC UMC  */
#define	X86_VENDOR_NexGen	5	/* NexGenDriven */
#define	X86_VENDOR_Centaur	6	/* CentaurHauls */
#define	X86_VENDOR_Rise		7	/* RiseRiseRise */
#define	X86_VENDOR_SiS		8	/* SiS SiS SiS  */
#define	X86_VENDOR_TM		9	/* GenuineTMx86 */
#define	X86_VENDOR_NSC		10	/* Geode by NSC */

#define	X86_VENDOR_STRLEN	13	/* vendor string max len + \0 */

/*
 * Some vendor/family/model/stepping ranges are commonly grouped under
 * a single identifying banner by the vendor.  The following encode
 * that "revision" in a uint32_t with the 8 most significant bits
 * identifying the vendor with X86_VENDOR_*, the next 8 identifying the
 * family, and the remaining 16 typically forming a bitmask of revisions
 * within that family with more significant bits indicating "later" revisions.
 */

#define	_X86_CHIPREV_VENDOR_MASK	0xff000000u
#define	_X86_CHIPREV_VENDOR_SHIFT	24
#define	_X86_CHIPREV_FAMILY_MASK	0x00ff0000u
#define	_X86_CHIPREV_FAMILY_SHIFT	16
#define	_X86_CHIPREV_REV_MASK		0x0000ffffu

#define	_X86_CHIPREV_VENDOR(x) \
	(((x) & _X86_CHIPREV_VENDOR_MASK) >> _X86_CHIPREV_VENDOR_SHIFT)
#define	_X86_CHIPREV_FAMILY(x) \
	(((x) & _X86_CHIPREV_FAMILY_MASK) >> _X86_CHIPREV_FAMILY_SHIFT)
#define	_X86_CHIPREV_REV(x) \
	((x) & _X86_CHIPREV_REV_MASK)

/* True if x matches in vendor and family and if x matches the given rev mask */
#define	X86_CHIPREV_MATCH(x, mask) \
	(_X86_CHIPREV_VENDOR(x) == _X86_CHIPREV_VENDOR(mask) && \
	_X86_CHIPREV_FAMILY(x) == _X86_CHIPREV_FAMILY(mask) && \
	((_X86_CHIPREV_REV(x) & _X86_CHIPREV_REV(mask)) != 0))

/* True if x matches in vendor and family, and rev is at least minx */
#define	X86_CHIPREV_ATLEAST(x, minx) \
	(_X86_CHIPREV_VENDOR(x) == _X86_CHIPREV_VENDOR(minx) && \
	_X86_CHIPREV_FAMILY(x) == _X86_CHIPREV_FAMILY(minx) && \
	_X86_CHIPREV_REV(x) >= _X86_CHIPREV_REV(minx))

#define	_X86_CHIPREV_MKREV(vendor, family, rev) \
	((uint32_t)(vendor) << _X86_CHIPREV_VENDOR_SHIFT | \
	(family) << _X86_CHIPREV_FAMILY_SHIFT | (rev))

/* True if x matches in vendor, and family is at least minx */
#define	X86_CHIPFAM_ATLEAST(x, minx) \
	(_X86_CHIPREV_VENDOR(x) == _X86_CHIPREV_VENDOR(minx) && \
	_X86_CHIPREV_FAMILY(x) >= _X86_CHIPREV_FAMILY(minx))

/* Revision default */
#define	X86_CHIPREV_UNKNOWN	0x0

/*
 * Definitions for AMD Family 0xf and AMD Family 0x10.  Minor revisions C0 and
 * CG are sufficiently different that we will distinguish them; in all other
 * case we will identify the major revision.
 */
#define	X86_CHIPREV_AMD_F_REV_B _X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0xf, 0x0001)
#define	X86_CHIPREV_AMD_F_REV_C0 _X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0xf, 0x0002)
#define	X86_CHIPREV_AMD_F_REV_CG _X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0xf, 0x0004)
#define	X86_CHIPREV_AMD_F_REV_D _X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0xf, 0x0008)
#define	X86_CHIPREV_AMD_F_REV_E _X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0xf, 0x0010)
#define	X86_CHIPREV_AMD_F_REV_F _X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0xf, 0x0020)
#define	X86_CHIPREV_AMD_F_REV_G _X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0xf, 0x0040)

/*
 * Definitions for AMD Family 0x10.  Rev A was Engineering Samples only.
 */
#define	X86_CHIPREV_AMD_10_REV_A \
	_X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0x10, 0x0001)
#define	X86_CHIPREV_AMD_10_REV_B \
	_X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0x10, 0x0002)
#define	X86_CHIPREV_AMD_10_REV_C \
	_X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0x10, 0x0004)
#define	X86_CHIPREV_AMD_10_REV_D \
	_X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0x10, 0x0008)
#define	X86_CHIPREV_AMD_10_REV_E \
	_X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0x10, 0x0010)

/*
 * Definitions for AMD Family 0x15.
 */
#define	X86_CHIPREV_AMD_15_REV_A \
	_X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0x15, 0x0001)
#define	X86_CHIPREV_AMD_15_REV_B \
	_X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0x15, 0x0002)
#define	X86_CHIPREV_AMD_15_REV_C \
	_X86_CHIPREV_MKREV(X86_VENDOR_AMD, 0x15, 0x0004)


/*
 * Various socket/package types, extended as the need to distinguish
 * a new type arises.  The top 8 byte identfies the vendor and the
 * remaining 24 bits describe 24 socket types.
 */

#define	_X86_SOCKET_VENDOR_SHIFT	24
#define	_X86_SOCKET_VENDOR(x)	((x) >> _X86_SOCKET_VENDOR_SHIFT)
#define	_X86_SOCKET_TYPE_MASK	0x00ffffff
#define	_X86_SOCKET_TYPE(x)		((x) & _X86_SOCKET_TYPE_MASK)

#define	_X86_SOCKET_MKVAL(vendor, bitval) \
	((uint32_t)(vendor) << _X86_SOCKET_VENDOR_SHIFT | (bitval))

#define	X86_SOCKET_MATCH(s, mask) \
	(_X86_SOCKET_VENDOR(s) == _X86_SOCKET_VENDOR(mask) && \
	(_X86_SOCKET_TYPE(s) & _X86_SOCKET_TYPE(mask)) != 0)

#define	X86_SOCKET_UNKNOWN 0x0
	/*
	 * AMD socket types
	 */
#define	X86_SOCKET_754		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000001)
#define	X86_SOCKET_939		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000002)
#define	X86_SOCKET_940		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000004)
#define	X86_SOCKET_S1g1		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000008)
#define	X86_SOCKET_AM2		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000010)
#define	X86_SOCKET_F1207	_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000020)
#define	X86_SOCKET_S1g2		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000040)
#define	X86_SOCKET_S1g3		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000080)
#define	X86_SOCKET_AM		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000100)
#define	X86_SOCKET_AM2R2	_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000200)
#define	X86_SOCKET_AM3		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000400)
#define	X86_SOCKET_G34		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x000800)
#define	X86_SOCKET_ASB2		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x001000)
#define	X86_SOCKET_C32		_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x002000)
#define	X86_SOCKET_AM3R2	_X86_SOCKET_MKVAL(X86_VENDOR_AMD, 0x004000)

/*
 * xgetbv/xsetbv support
 */

#define	XFEATURE_ENABLED_MASK	0x0
/*
 * XFEATURE_ENABLED_MASK values (eax)
 */
#define	XFEATURE_LEGACY_FP	0x1
#define	XFEATURE_SSE		0x2
#define	XFEATURE_AVX		0x4
#define	XFEATURE_MAX		XFEATURE_AVX
#define	XFEATURE_FP_ALL 	(XFEATURE_LEGACY_FP|XFEATURE_SSE|XFEATURE_AVX)

#if !defined(_ASM)

#if defined(_KERNEL) || defined(_KMEMUSER)

#define	NUM_X86_FEATURES	38
extern uchar_t x86_featureset[];

extern boolean_t is_x86_feature(void *featureset, uint_t feature);
extern void add_x86_feature(void *featureset, uint_t feature);
extern void remove_x86_feature(void *featureset, uint_t feature);
extern boolean_t compare_x86_featureset(void *setA, void *setB);
extern void print_x86_featureset(void *featureset);

extern uint_t x86_feature;
extern uint_t x86_type;
extern uint_t x86_vendor;
extern uint_t x86_clflush_size;

extern ulong_t cr4_value;
extern uint_t pentiumpro_bug4046376;
extern uint_t pentiumpro_bug4064495;

extern uint_t enable486;

extern uint64_t xsave_bv_all;	/* Software copy of xcr0 */

extern const char CyrixInstead[];

#endif

#if defined(_KERNEL)

/*
 * This structure is used to pass arguments and get return values back
 * from the CPUID instruction in __cpuid_insn() routine.
 */
struct cpuid_regs {
	uint32_t	cp_eax;
	uint32_t	cp_ebx;
	uint32_t	cp_ecx;
	uint32_t	cp_edx;
};

/*
 * Utility functions to get/set extended control registers (XCR)
 * Initial use is to get/set the contents of the XFEATURE_ENABLED_MASK.
 */
extern uint64_t get_xcr(uint_t);
extern void set_xcr(uint_t, const uint64_t);

extern uint64_t rdmsr(uint_t, uint64_t *);
extern void wrmsr(uint_t, const uint64_t *);
extern uint64_t xrdmsr(uint_t);
extern void xwrmsr(uint_t, const uint64_t);
extern int checked_rdmsr(uint_t, uint64_t *);
extern int checked_wrmsr(uint_t, uint64_t);
extern void invalidate_cache(void);
extern ulong_t getcr4(void);
extern void setcr4(ulong_t);
extern void mtrr_sync(void);

extern void cpu_fast_syscall_enable(void *);
extern void cpu_fast_syscall_disable(void *);

struct cpu;

extern int cpuid_checkpass(struct cpu *, int);
extern uint32_t cpuid_insn(struct cpu *, struct cpuid_regs *);
extern uint32_t __cpuid_insn(struct cpuid_regs *);
extern int cpuid_getbrandstr(struct cpu *, char *, size_t);
extern int cpuid_getidstr(struct cpu *, char *, size_t);
extern const char *cpuid_getvendorstr(struct cpu *);
extern uint_t cpuid_getvendor(struct cpu *);
extern uint_t cpuid_getfamily(struct cpu *);
extern uint_t cpuid_getmodel(struct cpu *);
extern uint_t cpuid_getstep(struct cpu *);
extern uint_t cpuid_getsig(struct cpu *);
extern uint_t cpuid_get_ncpu_per_chip(struct cpu *);
extern uint_t cpuid_get_ncore_per_chip(struct cpu *);
extern uint_t cpuid_get_ncpu_sharing_last_cache(struct cpu *);
extern id_t cpuid_get_last_lvl_cacheid(struct cpu *);
extern int cpuid_get_chipid(struct cpu *);
extern id_t cpuid_get_coreid(struct cpu *);
extern int cpuid_get_pkgcoreid(struct cpu *);
extern int cpuid_get_clogid(struct cpu *);
extern uint32_t cpuid_get_apicid(struct cpu *);
extern uint_t cpuid_get_procnodeid(struct cpu *cpu);
extern uint_t cpuid_get_procnodes_per_pkg(struct cpu *cpu);
extern int cpuid_get_cacheid(struct cpu *);
extern int cpuid_is_cmt(struct cpu *);
extern int cpuid_syscall32_insn(struct cpu *);
extern int getl2cacheinfo(struct cpu *, int *, int *, int *);
extern uint_t cpuid_is_fpu_shared(struct cpu *);
extern uint_t cpuid_get_cuid(struct cpu *);
extern uint_t cpuid_get_ncore_per_cu(struct cpu *);

extern uint32_t cpuid_getchiprev(struct cpu *);
extern const char *cpuid_getchiprevstr(struct cpu *);
extern uint32_t cpuid_getsockettype(struct cpu *);

extern int cpuid_opteron_erratum(struct cpu *, uint_t);

struct cpuid_info;

extern void setx86isalist(void);
extern void cpuid_pass1(struct cpu *, uchar_t *);
extern void cpuid_pass2(struct cpu *);
extern void cpuid_pass3(struct cpu *);
extern void cpuid_pass4(struct cpu *, uint_t *, int);
extern void add_cpunode2devtree(processorid_t, struct cpuid_info *);

extern void cpuid_get_addrsize(struct cpu *, uint_t *, uint_t *);
extern uint_t cpuid_get_dtlb_nent(struct cpu *, size_t);

extern int cpuid_x2apic_supported(void);

struct cpu_ucode_info;

extern void ucode_alloc_space(struct cpu *);
extern void ucode_free_space(struct cpu *);
extern void ucode_check(struct cpu *);
extern void ucode_cleanup();

extern uint32_t *cpuid_mwait_alloc(struct cpu *);
extern void cpuid_mwait_free(struct cpu *);
extern int cpuid_amd_deep_cstates_supported(struct cpu *);
extern int cpuid_deep_cstates_supported(void);
extern int cpuid_arat_supported(void);
extern int cpuid_iepb_supported(struct cpu *);
extern int vmware_platform(void);

extern	char _tsc_mfence_start;
extern	char _tsc_mfence_end;
extern	char _tscp_start;
extern	char _tscp_end;
extern	char _no_rdtsc_start;
extern	char _no_rdtsc_end;
extern	char _tsc_lfence_start;
extern	char _tsc_lfence_end;
extern void bcopy_patch_nhm();
extern void bcopy_patch_ivb();
extern void bzero_patch_ivb();

extern void post_startup_cpu_fixups(void);

extern uint_t workaround_errata(struct cpu *);

#if defined(__amd64)
extern void patch_rip_check(uint_t);
#endif	/* __amd64 */

#if defined(OPTERON_ERRATUM_93)
extern int opteron_erratum_93;
#endif

#if defined(OPTERON_ERRATUM_91)
extern int opteron_erratum_91;
#endif

#if defined(OPTERON_ERRATUM_100)
extern int opteron_erratum_100;
#endif

#if defined(OPTERON_ERRATUM_121)
extern int opteron_erratum_121;
#endif

extern void xsave_setup_msr(struct cpu *);

extern int get_hwenv(void);
/*
 * Defined hardware environments
 */
#define	HW_NATIVE	0x00	/* Running on bare metal */
#define	HW_XEN_PV	0x01	/* Running on Xen Hypervisor paravirutualized */
#define	HW_XEN_HVM	0x02	/* Running on Xen hypervisor HVM */
#define	HW_VMWARE	0x03	/* Running on VMware hypervisor */

#endif	/* _KERNEL */

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_X86_ARCHEXT_H */
