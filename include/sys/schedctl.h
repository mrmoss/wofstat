/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*
 * The enclosed is a private interface between system libraries and
 * the kernel.  It should not be used in any other way.  It may be
 * changed without notice in a minor release of Solaris.
 */

#ifndef	_SYS_SCHEDCTL_H
#define	_SYS_SCHEDCTL_H

#pragma ident	"@(#)schedctl.h	1.10	07/09/26 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(_ASM)

#include <sys/types.h>
#include <sys/processor.h>
#ifdef	_KERNEL
#include <sys/mutex.h>
#include <sys/thread.h>
#include <sys/vnode.h>
#include <sys/cpuvar.h>
#include <sys/door.h>
#endif	/* _KERNEL */

/*
 * This "public" portion of the sc_shared data is used by libsched/libc.
 */
typedef struct sc_public {
	volatile short	sc_nopreempt;
	volatile short	sc_yield;
} sc_public_t;

/*
 * The private portion of the sc_shared data is for
 * use by user-level threading support code in libc.
 */
typedef struct sc_shared {
	volatile ushort_t sc_state;	/* current LWP state */
	volatile char	sc_sigblock;	/* all signals blocked */
	volatile char	sc_park;	/* calling lwp_park() */
	volatile processorid_t sc_cpu;	/* last CPU on which LWP ran */
	int		sc_pad;
	sc_public_t	sc_preemptctl;	/* preemption control data */
} sc_shared_t;

/*
 * Possible state settings.  These are same as the kernel thread states
 * except there is no zombie state.
 */
#define	SC_FREE		0x00
#define	SC_SLEEP	0x01
#define	SC_RUN		0x02
#define	SC_ONPROC	0x04
#define	SC_STOPPED	0x10
#define	SC_WAIT		0x20

/* preemption control settings */
#define	SC_MAX_TICKS	2		/* max time preemption can be blocked */

#ifdef	_KERNEL
caddr_t	schedctl(void);
void	schedctl_init(void);
void	schedctl_lwp_cleanup(kthread_t *);
void	schedctl_proc_cleanup(void);
int	schedctl_get_nopreempt(kthread_t *);
void	schedctl_set_nopreempt(kthread_t *, short);
void	schedctl_set_yield(kthread_t *, short);
int	schedctl_sigblock(kthread_t *);
void	schedctl_finish_sigblock(kthread_t *);
int	schedctl_is_park(void);
void	schedctl_set_park(void);
void	schedctl_unpark(void);
#endif	/* _KERNEL */

#endif	/* !defined(_ASM) */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SCHEDCTL_H */
