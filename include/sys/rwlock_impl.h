/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_RWLOCK_IMPL_H
#define	_SYS_RWLOCK_IMPL_H

#pragma ident	"@(#)rwlock_impl.h	1.5	04/11/22 SMI"

/*
 * Implementation-private definitions for readers/writer locks.
 */

#ifndef _ASM

#include <sys/rwlock.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct rwlock_impl {
	uintptr_t	rw_wwwh;	/* waiters, write wanted, hold count */
} rwlock_impl_t;

#endif	/* _ASM */

#define	RW_HAS_WAITERS		1
#define	RW_WRITE_WANTED		2
#define	RW_WRITE_LOCKED		4
#define	RW_READ_LOCK		8
#define	RW_WRITE_LOCK(thread)	((uintptr_t)(thread) | RW_WRITE_LOCKED)
#define	RW_HOLD_COUNT		(-RW_READ_LOCK)
#define	RW_HOLD_COUNT_SHIFT	3		/* log2(RW_READ_LOCK) */
#define	RW_READ_COUNT		RW_HOLD_COUNT
#define	RW_OWNER		RW_HOLD_COUNT
#define	RW_LOCKED		RW_HOLD_COUNT
#define	RW_WRITE_CLAIMED	(RW_WRITE_LOCKED | RW_WRITE_WANTED)
#define	RW_DOUBLE_LOCK		(RW_WRITE_LOCK(0) | RW_READ_LOCK)

/*
 * These macros are used by both the implementation of rw_*() routines and
 * by the implementation of the rwlock-related DTrace subroutines.  (DTrace
 * cannot make calls into the rw_*() routines; it must use the macros.)
 */
#define	_RW_READ_HELD(rwlp, tmp)					\
	((((tmp) = ((rwlock_impl_t *)(rwlp))->rw_wwwh) & RW_LOCKED) &&	\
	!((tmp) & RW_WRITE_LOCKED))

#define	_RW_WRITE_HELD(rwlp)						\
	((((rwlock_impl_t *)(rwlp))->rw_wwwh &				\
	(RW_OWNER | RW_WRITE_LOCKED)) == RW_WRITE_LOCK(curthread))

#define	_RW_LOCK_HELD(rwlp)						\
	((((rwlock_impl_t *)(rwlp))->rw_wwwh & RW_LOCKED) ? 1 : 0)

#define	_RW_ISWRITER(rwlp)						\
	((((rwlock_impl_t *)(rwlp))->rw_wwwh & RW_WRITE_CLAIMED) ? 1 : 0)

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_RWLOCK_IMPL_H */
