/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_LWP_H
#define	_SYS_LWP_H

#pragma ident	"@(#)lwp.h	1.34	04/09/28 SMI"

#include <sys/synch.h>
#include <sys/ucontext.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * lwp create flags
 */
#define	LWP_DAEMON	0x00000020
#define	LWP_DETACHED	0x00000040
#define	LWP_SUSPENDED	0x00000080

/*
 * Definitions for user programs calling into the _lwp interface.
 */
struct lwpinfo {
	timestruc_t lwp_utime;
	timestruc_t lwp_stime;
	long	    lwpinfo_pad[64];
};

#if defined(_SYSCALL32)

/* Kernel's view of user ILP32 lwpinfo structure */

struct lwpinfo32 {
	timestruc32_t	lwp_utime;
	timestruc32_t	lwp_stime;
	int32_t		lwpinfo_pad[64];
};

#endif	/* _SYSCALL32 */

#define	_LWP_FSBASE	0
#define	_LWP_GSBASE	1

#define	_LWP_SETPRIVATE	0
#define	_LWP_GETPRIVATE	1

#ifndef _KERNEL

typedef uint_t lwpid_t;

int		_lwp_kill(lwpid_t, int);
int		_lwp_info(struct lwpinfo *);
lwpid_t		_lwp_self(void);
int		_lwp_suspend(lwpid_t);
int		_lwp_continue(lwpid_t);
#if defined(__i386) || defined(__amd64)
int		_lwp_private(int, int, void *);
#endif	/* __i386 || __amd64 */

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_LWP_H */
