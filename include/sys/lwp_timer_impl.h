/*
 * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_LWP_TIMER_IMPL_H
#define	_SYS_LWP_TIMER_IMPL_H

#pragma ident	"@(#)lwp_timer_impl.h	1.3	09/06/02 SMI"

#include <sys/types.h>
#include <sys/thread.h>
#include <sys/lwp.h>
#include <sys/time.h>
#include <sys/systm.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct {
	kthread_t	*lwpt_thread;
	timespec_t	*lwpt_tsp;
	timespec_t	lwpt_rqtime;
	int		lwpt_timecheck;
	uint_t		lwpt_imm_timeout;
	int		lwpt_time_error;
	callout_id_t	lwpt_id;
} lwp_timer_t;

#ifdef _KERNEL
extern	int	lwp_timer_copyin(lwp_timer_t *, timespec_t *);
extern	int	lwp_timer_enqueue(lwp_timer_t *);
extern	clock_t	lwp_timer_dequeue(lwp_timer_t *);
extern	int	lwp_timer_copyout(lwp_timer_t *, int);
#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_LWP_TIMER_IMPL_H */
