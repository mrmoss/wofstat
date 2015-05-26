/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _INET_LED_H
#define	_INET_LED_H

#pragma ident	"@(#)led.h	1.36	06/01/05 SMI"

/*
 * WARNING: This file contains implementation-specific constants, typedefs
 *	    and macros which may change from release to release.
 *
 * WARNING: This file has nothing to do with things that blink.
 */

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/types.h>

/*
 * x86 can handle unaligned access. However, the checksum routine
 * assumes that the source is 16 bit aligned so we always make sure
 * that packet headers are 16 bit aligned.
 */
#define	OK_16PTR(p)	(!((uintptr_t)(p) & 0x1))
#if defined(__x86)
#define	OK_32PTR(p)	OK_16PTR(p)
#else
#define	OK_32PTR(p)	(!((uintptr_t)(p) & 0x3))
#endif

#ifdef _KERNEL

typedef	char		*IDP;
typedef	struct msgb	*MBLKP;

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _INET_LED_H */
