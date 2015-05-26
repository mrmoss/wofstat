/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef _SYS_SELECT_H
#define	_SYS_SELECT_H

#pragma ident	"@(#)select.h	1.19	04/01/28 SMI"	/* SVr4.0 1.2 */

#include <sys/feature_tests.h>

#ifndef _KERNEL
#if !defined(__XOPEN_OR_POSIX) || defined(_XPG6) || defined(__EXTENSIONS__)
#include <sys/time_impl.h>
#endif
#include <sys/time.h>
#endif /* _KERNEL */

#ifdef	__cplusplus
extern "C" {
#endif


#if !defined(__XOPEN_OR_POSIX) || defined(_XPG6) || defined(__EXTENSIONS__)
/*
 * The sigset_t type is defined in <sys/signal.h> and duplicated
 * in <sys/ucontext.h> as a result of XPG4v2 requirements. XPG6
 * now allows the visibility of signal.h in this header, however
 * an order of inclusion problem occurs as a result of inclusion
 * of <sys/select.h> in <signal.h> under certain conditions.
 * Rather than include <sys/signal.h> here, we've duplicated
 * the sigset_t type instead. This type is required for the XPG6
 * introduced pselect() function also declared in this header.
 */
#ifndef	_SIGSET_T
#define	_SIGSET_T
typedef struct {		/* signal set type */
	unsigned int	__sigbits[4];
} sigset_t;

#if defined(_SYSCALL32)

/* Kernel view of the ILP32 user sigset_t structure */

typedef struct {
	uint32_t	__sigbits[4];
} sigset32_t;

#endif  /* _SYSCALL32 */
#endif  /* _SIGSET_T */

#endif /* #if !defined(__XOPEN_OR_POSIX) || defined(_XPG6) ... */

/*
 * Select uses bit masks of file descriptors in longs.
 * These macros manipulate such bit fields.
 * FD_SETSIZE may be defined by the user, but the default here
 * should be >= NOFILE (param.h).
 */
#ifndef	FD_SETSIZE
#ifdef _LP64
#define	FD_SETSIZE	65536
#else
#define	FD_SETSIZE	1024
#endif	/* _LP64 */
#elif FD_SETSIZE > 1024 && !defined(_LP64)
#ifdef __PRAGMA_REDEFINE_EXTNAME
#pragma	redefine_extname	select	select_large_fdset
#if !defined(__XOPEN_OR_POSIX) || defined(_XPG6) || defined(__EXTENSIONS__)
#pragma	redefine_extname	pselect	pselect_large_fdset
#endif
#else	/* __PRAGMA_REDEFINE_EXTNAME */
#define	select	select_large_fdset
#if !defined(__XOPEN_OR_POSIX) || defined(_XPG6) || defined(__EXTENSIONS__)
#define	pselect	pselect_large_fdset
#endif
#endif	/* __PRAGMA_REDEFINE_EXTNAME */
#endif	/* FD_SETSIZE */

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
typedef	long	fd_mask;
#endif
typedef	long	fds_mask;

/*
 *  The value of _NBBY needs to be consistant with the value
 *  of NBBY in <sys/param.h>.
 */
#define	_NBBY 8
#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
#ifndef NBBY		/* number of bits per byte */
#define	NBBY _NBBY
#endif
#endif /* !defined(_XPG4_2) || defined(__EXTENSIONS__) */

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
#define	NFDBITS		(sizeof (fd_mask) * NBBY)	/* bits per mask */
#endif
#define	FD_NFDBITS	(sizeof (fds_mask) * _NBBY)	/* bits per mask */

#define	__howmany(__x, __y)	(((__x)+((__y)-1))/(__y))
#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
#ifndef	howmany
#define	howmany(x, y)	(((x)+((y)-1))/(y))
#endif
#endif /* !defined(_XPG4_2) || defined(__EXTENSIONS__) */

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
typedef	struct fd_set {
#else
typedef	struct __fd_set {
#endif
	long	fds_bits[__howmany(FD_SETSIZE, FD_NFDBITS)];
} fd_set;

#define	FD_SET(__n, __p)	((__p)->fds_bits[(__n)/FD_NFDBITS] |= \
				    (1ul << ((__n) % FD_NFDBITS)))

#define	FD_CLR(__n, __p)	((__p)->fds_bits[(__n)/FD_NFDBITS] &= \
				    ~(1ul << ((__n) % FD_NFDBITS)))

#define	FD_ISSET(__n, __p)	(((__p)->fds_bits[(__n)/FD_NFDBITS] & \
				    (1ul << ((__n) % FD_NFDBITS))) != 0l)

#ifdef _KERNEL
#define	FD_ZERO(p)	bzero((p), sizeof (*(p)))
#else
#define	FD_ZERO(__p)    (void) memset((__p), 0, sizeof (*(__p)))
#endif /* _KERNEL */

#ifndef	_KERNEL
#ifdef	__STDC__
extern int select(int, fd_set *_RESTRICT_KYWD, fd_set *_RESTRICT_KYWD,
	fd_set *_RESTRICT_KYWD, struct timeval *_RESTRICT_KYWD);

#if !defined(__XOPEN_OR_POSIX) || defined(_XPG6) || defined(__EXTENSIONS__)
extern int pselect(int, fd_set *_RESTRICT_KYWD, fd_set *_RESTRICT_KYWD,
	fd_set *_RESTRICT_KYWD, const struct timespec *_RESTRICT_KYWD,
	const sigset_t *_RESTRICT_KYWD);
#endif

#else
extern int select();
#if !defined(__XOPEN_OR_POSIX) || defined(_XPG6) || defined(__EXTENSIONS__)
extern int pselect();
#endif
#endif	/* __STDC__ */
#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SELECT_H */
