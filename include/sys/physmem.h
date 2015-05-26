/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_PHYSMEM_H
#define	_PHYSMEM_H

#pragma ident	"@(#)physmem.h	1.1	07/02/14 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * THIS IS NOT A SUPPORTED INTERFACE.
 * THIS DRIVER IS USED BY SUN INTERNAL DIAGNOSTIC PROGRAMS ONLY.
 * ANY OTHER USE MAY HAVE A HARMFUL IMPACT ON THE SYSTEM.
 */

/* ioctl values */
#define	PHYSMEM_SETUP 1
#define	PHYSMEM_MAP 2
#define	PHYSMEM_DESTROY 3

/* flags values */
#define	PHYSMEM_CAGE	(1 << 0)
#define	PHYSMEM_RETIRED	(1 << 1)

struct physmem_setup_param {
	uint64_t req_paddr;	/* requested physical address */
	uint64_t len;		/* length of memory to be allocated */
	uint64_t user_va;	/* VA to associate with req_paddr */
	uint64_t cookie;	/* cookie returned for destroy function */
};

struct physmem_map_param {
	uint64_t req_paddr;	/* requested physical address */
	uint64_t ret_va;	/* VA which mapped req_paddr */
	uint32_t flags;		/* flags for cage or retired pages */
};

#ifdef	__cplusplus
}
#endif

#endif	/* _PHYSMEM_H */
