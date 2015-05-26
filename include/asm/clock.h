/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ASM_CLOCK_H
#define	_ASM_CLOCK_H

#pragma ident	"@(#)clock.h	1.2	08/05/05 SMI"

#include <sys/types.h>
#include <sys/time.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(__lint) && defined(__GNUC__)

#include <sys/machlock.h>

extern __inline__ void unlock_hres_lock(void)
{
	__asm__ __volatile__(
	    "lock; incl %0"
	    : /* no output */
	    : "m" (hres_lock)
	    : "cc");
}

#endif	/* !__lint && __GNUC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _ASM_CLOCK_H */
