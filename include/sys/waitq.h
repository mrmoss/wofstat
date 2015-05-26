/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_WAITQ_H
#define	_SYS_WAITQ_H

#pragma ident	"@(#)waitq.h	1.1	07/09/26 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	_KERNEL

#include <sys/types.h>
#include <sys/machlock.h>
#include <sys/thread.h>

typedef struct waitq {
	disp_lock_t	wq_lock;	/* protects all fields */
	kthread_t	*wq_first;	/* first thread on the queue */
	int		wq_count;	/* number of threads on the queue */
	boolean_t	wq_blocked;	/* True if threads can't be enqueued */
} waitq_t;

extern void		waitq_init(waitq_t *);
extern void		waitq_fini(waitq_t *);

/*
 * Place the thread on the wait queue. An attempt to enqueue a thread onto a
 * blocked queue fails and returns zero. Successful enqueue returns non-zero
 * value.
 */
extern int		waitq_enqueue(waitq_t *, kthread_t *);

/*
 * Take thread off its wait queue and make it runnable.
 */
extern void		waitq_setrun(kthread_t *t);

/*
 * Change priority for the thread on wait queue.
 */
extern void		waitq_change_pri(kthread_t *, pri_t);

/*
 * Take the first thread off the wait queue and make it runnable.
 */
extern void		waitq_runone(waitq_t *);

/*
 * Return True if there are no threads on the queue.
 */
extern boolean_t	waitq_isempty(waitq_t *);

/*
 * Prevent and allow placing new threads on wait queue.
 */
extern void		waitq_block(waitq_t *);
extern void		waitq_unblock(waitq_t *);

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_WAITQ_H */
