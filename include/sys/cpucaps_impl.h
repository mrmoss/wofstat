/*
 * Copyright (c) 2007, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_CPUCAPS_IMPL_H
#define	_SYS_CPUCAPS_IMPL_H

#pragma ident	"@(#)cpucaps_impl.h	1.3	11/10/14 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef _KERNEL

#include <sys/kstat.h>
#include <sys/cpucaps.h>
#include <sys/list.h>
#include <sys/time.h>
#include <sys/waitq.h>

/*
 * When resource control framework sets the cap to NOCAP value the cap
 * is disabled.
 */
#define	NOCAP	MAXCAP

/*
 * Maximum value for the cap usage. Should be the maximum value for hrtime_t
 */
#if defined(_LP64)
#define	MAX_USAGE LONG_MAX
#else
#define	MAX_USAGE 9223372036854775807LL
#endif


/*
 * Most of the per-project or per-zone state related to CPU caps is kept in the
 * cpucap_t structure.
 */
typedef struct cpucap {
	list_node_t	cap_link;	/* next/prev capped entity	*/
	struct kproject	*cap_project;	/* project for the cap		*/
	struct zone	*cap_zone;	/* zone for the cap		*/
	waitq_t		cap_waitq;	/* waitq for capped threads	*/
	kstat_t		*cap_kstat;	/* cpucaps specific kstat	*/
	int64_t		cap_lbolt;	/* zone cap specific 		*/
	hrtime_t	cap_value;	/* scaled CPU usage cap		*/
	volatile uint64_t	cap_usage;	/* current CPU usage	*/
	/*
	 * Per cap statistics.
	 */
	hrtime_t	cap_maxusage;	/* maximum cap usage		*/
	u_longlong_t	cap_below;	/* # of ticks spend below the cap */
	u_longlong_t	cap_above;	/* # of ticks spend above the cap */
} cpucap_t;

/*
 * Wrapper macros for checking cap state.
 */
#define	CAP_ENABLED(cap) ((cap)->cap_value != 0)
#define	CAP_DISABLED(cap) (!CAP_ENABLED(cap))

#define	PROJECT_IS_CAPPED(project) \
	(((project)->kpj_cpucap != NULL) && \
	CAP_ENABLED((project)->kpj_cpucap))

#define	ZONE_IS_CAPPED(zone) \
	(((zone)->zone_cpucap != NULL) && \
	CAP_ENABLED((zone)->zone_cpucap))

#define	THREAD_IS_CAPPED(tp) \
	(PROJECT_IS_CAPPED(ttoproj(tp)) || ZONE_IS_CAPPED(ttozone(tp)))

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_CPUCAPS_IMPL_H */
