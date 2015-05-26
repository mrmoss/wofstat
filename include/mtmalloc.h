/*
 * Copyright (c) 1998, 2010, Oracle and/or its affiliates. All rights reserved.
 */


#ifndef _MTMALLOC_H
#define	_MTMALLOC_H

#pragma ident	"@(#)mtmalloc.h	1.2	10/10/18 SMI"

/*
 * Public interface for multi-threadead malloc user land library
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

/* commands for mallocctl(int cmd, long value) */

#define	MTDOUBLEFREE	1	/* core dumps on double free */
#define	MTDEBUGPATTERN	2	/* write misaligned data after free. */
#define	MTINITBUFFER	4	/* write misaligned data at allocation */
#define	MTEXCLUSIVE	5	/* Use exclusive BINs for low numbered thrs */
#define	MTREALFREE	6	/* Use madvise to free large allocations */
#define	MTCHUNKSIZE	32	/* How much to alloc when backfilling caches. */

void mallocctl(int, long);

#ifdef __cplusplus
}
#endif


#endif /* _MTMALLOC_H */
