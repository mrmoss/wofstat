/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ASM_CPUVAR_H
#define	_ASM_CPUVAR_H

#pragma ident	"@(#)cpuvar.h	1.1	04/09/28 SMI"

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(__lint) && defined(__GNUC__)

struct cpu;

extern __inline__ struct cpu *curcpup(void)
{
	struct cpu *__value;

#if defined(__amd64)
	__asm__ __volatile__(
	    "movq %%gs:0x10,%0"		/* CPU_SELF */
	    : "=r" (__value));
#elif defined(__i386)
	__asm__ __volatile__(
	    "movl %%gs:0xc,%0"		/* CPU_SELF */
	    : "=r" (__value));
#else
#error	"port me"
#endif
	return (__value);
}

#endif	/* !__lint && __GNUC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _ASM_CPUVAR_H */
