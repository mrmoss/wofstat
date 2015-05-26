/*
 * Copyright (c) 2001 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef _NBMLOCK_H
#define	_NBMLOCK_H

#pragma ident	"@(#)nbmlock.h	1.1	01/04/07 SMI"

/*
 * Non-blocking mandatory locking support.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/vnode.h>
#include <sys/rwlock.h>
#include <sys/cred.h>

/*
 * Type of operation; used when checking for lock/share conflict.
 * NBL_READWRITE is used for checking for a conflict with an exclusive lock
 * (F_WRLCK) or a read-write mmap request.  For checking an actual I/O
 * request, use NBL_READ or NBL_WRITE.
 */
typedef enum {NBL_READ, NBL_WRITE, NBL_RENAME, NBL_REMOVE,
	    NBL_READWRITE} nbl_op_t;

/* critical region primitives */
extern void nbl_start_crit(vnode_t *, krw_t);
extern void nbl_end_crit(vnode_t *);
extern int nbl_in_crit(vnode_t *);

/* conflict checking */
extern int nbl_need_check(vnode_t *);
extern int nbl_conflict(vnode_t *, nbl_op_t, u_offset_t, ssize_t, int);
extern int nbl_share_conflict(vnode_t *, nbl_op_t);
extern int nbl_lock_conflict(vnode_t *, nbl_op_t, u_offset_t, ssize_t, int);
extern int nbl_svmand(vnode_t *, cred_t *, int *);

extern nbl_op_t nbl_lock_to_op(int);

#ifdef __cplusplus
}
#endif

#endif /* _NBMLOCK_H */
