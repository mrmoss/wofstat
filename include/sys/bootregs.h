/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_BOOTREGS_H
#define	_SYS_BOOTREGS_H

#pragma ident	"@(#)bootregs.h	1.1	04/07/16 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_KERNEL) || defined(_BOOT)

/*
 *  This structure is used by bootops to save/restore registers when
 *  transferring between protected and realmode code.
 *
 *  NOTE: The following macros require an ANSI compiler!
 */

#define	i8080reg(r) union {  /* 8080-like "general purpose" registers */\
	uint32_t e ## r ## x;					\
	struct { uint16_t r ## x; } word;				\
	struct { uint8_t  r ## l, r ## h; } byte;			\
}

#define	i8086reg(r) union { /* 16/32-bit "special purpose" registers  */\
	uint32_t e ## r;						\
	struct { uint16_t r; } word;				\
}

struct bop_regs {
	/*
	 *  Machine state structure for realmode <-> protected mode callout
	 *  operations:
	 */

	i8080reg(a) eax;	/* The so-called "general purpose" registers */
	i8080reg(d) edx;
	i8080reg(c) ecx;
	i8080reg(b) ebx;

	i8086reg(bp) ebp;	/* 16/32-bit "pointer" registers */
	i8086reg(si) esi;
	i8086reg(di) edi;

	uint16_t ds;	/* Segment registers */
	uint16_t es;
	uint16_t fs;
	uint16_t gs;

	uint32_t eflags;
};

#undef	i8080reg
#undef	i8086reg
#endif	/* _KERNEL || _BOOT */

#ifdef __cplusplus
}
#endif

#endif	/* _SYS_BOOTREGS_H */
