/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _PCTYPES_H
#define	_PCTYPES_H

#pragma ident	"@(#)pctypes.h	1.15	04/09/28 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * PCMCIA General Types
 */

typedef int irq_t;		/* IRQ level */
typedef unsigned char *baseaddr_t; /* memory base address */
#if defined(__i386) || defined(__amd64)
typedef uint32_t ioaddr_t;
#elif defined(__sparc)
typedef caddr_t ioaddr_t;
#endif

typedef uint32_t (*intrfunc_t)(void *);

/*
 * Data access handle definitions for common access functions
 */
typedef void * acc_handle_t;

#if defined(_BIG_ENDIAN)
#define	leshort(a)	((((a) & 0xFF) << 8) | (((a) >> 8) & 0xFF))
#define	lelong(a)	(leshort((a) >> 16) | (leshort(a) << 16))
#else
#define	leshort(a)	(a)
#define	lelong(a)	(a)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _PCTYPES_H */
