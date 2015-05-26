/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _UCONTEXT_H
#define	_UCONTEXT_H

#pragma ident	"@(#)ucontext.h	1.22	04/09/28 SMI"

#include <sys/ucontext.h>

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
#include <sys/siginfo.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef __sparc
#ifdef __PRAGMA_REDEFINE_EXTNAME
#pragma	redefine_extname	makecontext	__makecontext_v2
#else
#define	makecontext	__makecontext_v2
#endif
#endif

#if defined(__STDC__)

extern int getcontext(ucontext_t *);
#pragma unknown_control_flow(getcontext)
extern int setcontext(const ucontext_t *) __NORETURN;
extern int swapcontext(ucontext_t *_RESTRICT_KYWD,
		const ucontext_t *_RESTRICT_KYWD);
extern void makecontext(ucontext_t *, void(*)(), int, ...);
#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
extern int walkcontext(const ucontext_t *, int (*)(uintptr_t, int, void *),
    void *);
extern int printstack(int);

extern int getustack(stack_t **);
extern int setustack(stack_t *);

extern int stack_getbounds(stack_t *);
extern int stack_setbounds(const stack_t *);
extern int stack_inbounds(void *);
extern int stack_violation(int, const siginfo_t *, const ucontext_t *);

extern void *_stack_grow(void *);
#endif
#else

extern int getcontext();
#pragma unknown_control_flow(getcontext)
extern int setcontext();
extern int swapcontext();
extern void makecontext();
#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
extern int walkcontext();
extern int printstack();

extern int getustack();
extern int setustack();

extern int stack_getbounds();
extern int stack_setbounds();
extern int stack_inbounds();
extern int stack_violation();

extern void *_stack_grow();
#endif
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _UCONTEXT_H */
