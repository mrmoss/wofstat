/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright (c) 1992, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_UCONTEXT_H
#define	_SYS_UCONTEXT_H

#pragma ident	"@(#)ucontext.h	1.12	11/02/11 SMI"

#include <sys/feature_tests.h>

#include <sys/types.h>
#include <sys/regset.h>
#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
#include <sys/signal.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Inclusion of <sys/signal.h> for sigset_t and stack_t definitions
 * breaks XPG4v2 namespace.  Therefore we must duplicate the defines
 * for these types here when _XPG4_2 is defined.
 */

#if defined(_XPG4_2) && !defined(__EXTENSIONS__)
#ifndef	_SIGSET_T
#define	_SIGSET_T
typedef	struct {	/* signal set type */
	unsigned long	__sigbits[4];
} sigset_t;
#endif /* _SIGSET_T */

#ifndef	_STACK_T
#define	_STACK_T
typedef	struct {
	void	*ss_sp;
	size_t	ss_size;
	int	ss_flags;
} stack_t;
#endif /* _STACK_T */
#endif /* defined(_XPG4_2) && !defined(__EXTENSIONS__) */

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
typedef	struct ucontext ucontext_t;
#else
typedef	struct __ucontext ucontext_t;
#endif /* !defined(_XPG4_2) || defined(__EXTENSIONS__) */

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
struct	ucontext {
#else
struct	__ucontext {
#endif
	unsigned long	uc_flags;
	ucontext_t	*uc_link;
	sigset_t   	uc_sigmask;
	stack_t 	uc_stack;
	mcontext_t 	uc_mcontext;
#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
	xrs_t		uc_xrs;
#else
	xrs_t		__uc_xrs;
#endif
	long		uc_filler[3];	/* see ABI spec for Intel386 */
};

#if defined(_SYSCALL32)

/* Kernel view of user ILP32 ucontext structure */

typedef struct ucontext32 {
	uint32_t	uc_flags;
	caddr32_t	uc_link;
	sigset32_t	uc_sigmask;
	stack32_t	uc_stack;
	mcontext32_t	uc_mcontext;
	xrs32_t		uc_xrs;
	int32_t		uc_filler[3];
} ucontext32_t;

#if defined(_KERNEL)
extern void ucontext_nto32(const ucontext_t *src, ucontext32_t *dest);
extern void ucontext_32ton(const ucontext32_t *src, ucontext_t *dest);
#endif

#endif	/* _SYSCALL32 */

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
#define	GETCONTEXT	0
#define	SETCONTEXT	1
#define	GETUSTACK	2
#define	SETUSTACK	3

/*
 * values for uc_flags
 * these are implementation dependent flags, that should be hidden
 * from the user interface, defining which elements of ucontext
 * are valid, and should be restored on call to setcontext
 */

#define	UC_SIGMASK	0x01
#define	UC_STACK	0x02
#define	UC_CPU		0x04
#define	UC_MAU		0x08
#define	UC_XREGS	0x10
#define	UC_FPU		UC_MAU

#define	UC_MCONTEXT	(UC_CPU|UC_FPU)

/*
 * UC_ALL specifies the default context
 */

#define	UC_ALL		(UC_SIGMASK|UC_STACK|UC_MCONTEXT)
#endif /* !defined(_XPG4_2) || defined(__EXTENSIONS__) */

#ifdef _KERNEL
void savecontext(ucontext_t *, k_sigset_t);
void restorecontext(ucontext_t *);

#ifdef _SYSCALL32
extern void savecontext32(ucontext32_t *ucp, k_sigset_t mask);
#endif
#endif

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_UCONTEXT_H */
