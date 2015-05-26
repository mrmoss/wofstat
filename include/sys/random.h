/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_RANDOM_H
#define	_SYS_RANDOM_H

#pragma ident	"@(#)random.h	1.5	08/10/21 SMI"

#include <sys/types.h>
#include <sys/atomic.h>

#ifdef	__cplusplus
extern "C" {
#endif

/* stats for the random number devices, /dev/random and /dev/urandom. */
typedef struct rnd_stats {
	uint64_t	rs_rndOut;	/* Bytes generated for /dev/random */
	uint64_t	rs_rndcOut;	/* Bytes read from /dev/random cache */
	uint64_t	rs_urndOut;	/* Bytes generated for /dev/urandom */
} rnd_stats_t;

/* stats for the kernel random number provider, swrand. */
typedef struct swrand_stats {
	uint32_t	ss_entEst;	/* Entropy estimate in bits */
	uint64_t	ss_entIn;	/* Entropy bits added to pool */
	uint64_t	ss_entOut;	/* Entropy bits extracted from pool */
	uint64_t	ss_bytesIn;	/* Total data bytes added to pool */
	uint64_t	ss_bytesOut;	/* Total data bytes extracted from */
					/* the pool */
} swrand_stats_t;

#ifdef	_KERNEL

#define	BUMP_CPU_RND_STATS(rm, x, v)    (((rm)->rm_stats).x += (v))
#define	BUMP_RND_STATS(x, v)	atomic_add_64(&(rnd_stats).x, (v))
#define	BUMP_SWRAND_STATS(x, v)	atomic_add_64(&(swrand_stats).x, (v))

extern int random_add_entropy(uint8_t *, size_t, uint_t);
extern int random_get_bytes(uint8_t *, size_t);
extern int random_get_pseudo_bytes(uint8_t *, size_t);

#endif /* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_RANDOM_H */
