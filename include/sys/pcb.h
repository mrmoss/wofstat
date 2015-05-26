/*
 * Copyright (c) 1992, 2010, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_PCB_H
#define	_SYS_PCB_H

#pragma ident	"@(#)pcb.h	1.26	10/11/19 SMI"

#include <sys/regset.h>
#include <sys/segments.h>

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef _ASM
typedef struct fpu_ctx {
	kfpu_t		fpu_regs;	/* kernel save area for FPU */
	uint64_t	fpu_xsave_mask;	/* xsave mask for FPU/SSE/AVX */
#if defined(__i386)
	uint64_t	fpu_padding;	/* fix 32bit libmicro regression */
#endif
	uint_t		fpu_flags;	/* FPU state flags */
} fpu_ctx_t;

typedef struct pcb {
	fpu_ctx_t	pcb_fpu;	/* fpu state */
	uint_t		pcb_flags;	/* state flags; cleared on fork */
	greg_t		pcb_drstat;	/* status debug register (%dr6) */
	unsigned char	pcb_instr;	/* /proc: instruction at stop */
#if defined(__amd64)
	unsigned char	pcb_rupdate;	/* new register values in pcb -> regs */
	uintptr_t	pcb_fsbase;
	uintptr_t	pcb_gsbase;
	selector_t	pcb_ds;
	selector_t	pcb_es;
	selector_t	pcb_fs;
	selector_t	pcb_gs;
#endif /* __amd64 */
	user_desc_t	pcb_fsdesc;	/* private per-lwp %fs descriptors */
	user_desc_t	pcb_gsdesc;	/* private per-lwp %gs descriptors */
} pcb_t;

#endif /* ! _ASM */

/* pcb_flags */
#define	DEBUG_PENDING	0x02	/* single-step of lcall for a sys call */
#define	PRSTOP_CALLED	0x04	/* prstop() has been called for this lwp */
#define	INSTR_VALID	0x08	/* value in pcb_instr is valid (/proc) */
#define	NORMAL_STEP	0x10	/* normal debugger-requested single-step */
#define	WATCH_STEP	0x20	/* single-stepping in watchpoint emulation */
#define	CPC_OVERFLOW	0x40	/* performance counters overflowed */
#define	RUPDATE_PENDING	0x80	/* new register values in the pcb -> regs */
#define	REQUEST_STEP	0x100	/* request pending to single-step this lwp */
#define	REQUEST_NOSTEP	0x200	/* request pending to disable single-step */
#define	ASYNC_HWERR	0x400	/* hardware error has corrupted context  */

/* fpu_flags */
#define	FPU_EN		0x1	/* flag signifying fpu in use */
#define	FPU_VALID	0x2	/* fpu_regs has valid fpu state */
#define	FPU_MODIFIED	0x4	/* fpu_regs is modified (/proc) */

#define	FPU_INVALID	0x0	/* fpu context is not in use */

/* fpu_flags */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_PCB_H */
