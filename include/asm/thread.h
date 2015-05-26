/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ASM_THREAD_H
#define	_ASM_THREAD_H

#pragma ident	"@(#)thread.h	1.1	04/09/28 SMI"

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(__lint) && defined(__GNUC__)

struct _kthread;

/*
 * 0x10 is offsetof(struct cpu, cpu_thread)
 * 0x18 is the same thing for the _LP64 version.
 * (It's also the value of CPU_THREAD in assym.h)
 * Yuck.
 */

extern __inline__ struct _kthread *threadp(void)
{
	void *__value;

#if defined(__amd64)
	__asm__ __volatile__(
	    "movq %%gs:0x18,%0"		/* CPU_THREAD */
	    : "=r" (__value));
#elif defined(__i386)
	__asm__ __volatile__(
	    "movl %%gs:0x10,%0"		/* CPU_THREAD */
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

#endif	/* _ASM_THREAD_H */
