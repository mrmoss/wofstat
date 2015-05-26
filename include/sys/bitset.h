/*
 * Copyright (c) 2007, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_BITSET_H
#define	_BITSET_H

#pragma ident	"@(#)bitset.h	1.5	11/10/14 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#if (defined(_KERNEL) || defined(_KMEMUSER))
#include <sys/bitmap.h>
#include <sys/types.h>

typedef struct bitset {
	ulong_t	*bs_set;
	uint_t	bs_words;
	uint_t	bs_fanout;
} bitset_t;

/*
 * Bitset initialiation / teardown
 */
void		bitset_init(bitset_t *);
void		bitset_init_fanout(bitset_t *, uint_t);
void		bitset_fini(bitset_t *);

/*
 * Resize / query a bitset's holding capacity
 */
void		bitset_resize(bitset_t *, uint_t);
uint_t		bitset_capacity(bitset_t *);

/*
 * Set / clear a bit in the set
 */
void		bitset_add(bitset_t *, uint_t);
void		bitset_del(bitset_t *, uint_t);

/*
 * Atomic operations
 */
void		bitset_atomic_add(bitset_t *, uint_t);
void		bitset_atomic_del(bitset_t *, uint_t);
int		bitset_atomic_test_and_add(bitset_t *, uint_t);
int		bitset_atomic_test_and_del(bitset_t *, uint_t);

/*
 * Bitset queries
 */
int		bitset_in_set(bitset_t *, uint_t);
int		bitset_is_null(bitset_t *);
uint_t		bitset_find(bitset_t *);

/*
 * Bitset computations
 */
int		bitset_and(bitset_t *, bitset_t *, bitset_t *);
int		bitset_or(bitset_t *, bitset_t *, bitset_t *);
int		bitset_xor(bitset_t *, bitset_t *, bitset_t *);

/*
 * Miscellaneous bitset operations
 */
void		bitset_zero(bitset_t *);
void		bitset_copy(bitset_t *, bitset_t *);
int		bitset_match(bitset_t *, bitset_t *);
int		bitset_contains(bitset_t *, bitset_t *);

#endif	/* !_KERNEL && !_KMEMUSER */

#ifdef	__cplusplus
}
#endif

#endif /* _BITSET_H */
