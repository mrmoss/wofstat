/*
 * Copyright (c) 1988, 2010, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_DEBUG_H
#define	_SYS_DEBUG_H

#pragma ident	"@(#)debug.h	1.29	10/09/13 SMI"

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved	*/

#include <sys/isa_defs.h>
#include <sys/types.h>
#include <sys/note.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * ASSERT(ex) causes a panic or debugger entry if expression ex is not
 * true.  ASSERT() is included only for debugging, and is a no-op in
 * production kernels.  VERIFY(ex), on the other hand, behaves like
 * ASSERT and is evaluated on both debug and non-debug kernels.
 */

#if defined(__STDC__)
extern int assfail(const char *, const char *, int);
#define	VERIFY(EX) ((void)((EX) || assfail(#EX, __FILE__, __LINE__)))
#if DEBUG
#define	ASSERT(EX) ((void)((EX) || assfail(#EX, __FILE__, __LINE__)))
#else
#define	ASSERT(x)  ((void)0)
#endif
#else	/* defined(__STDC__) */
extern int assfail();
#define	VERIFY(EX) ((void)((EX) || assfail("EX", __FILE__, __LINE__)))
#if DEBUG
#define	ASSERT(EX) ((void)((EX) || assfail("EX", __FILE__, __LINE__)))
#else
#define	ASSERT(x)  ((void)0)
#endif
#endif	/* defined(__STDC__) */

/*
 * Assertion variants sensitive to the compilation data model
 */
#if defined(_LP64)
#define	ASSERT64(x)	ASSERT(x)
#define	ASSERT32(x)
#else
#define	ASSERT64(x)
#define	ASSERT32(x)	ASSERT(x)
#endif

/*
 * IMPLY and EQUIV are assertions of the form:
 *
 *	if (a) then (b)
 * and
 *	if (a) then (b) *AND* if (b) then (a)
 *	i.e. both a and b should be true or false at the same time
 */
#if DEBUG
#define	IMPLY(A, B) \
	((void)(((!(A)) || (B)) || \
	    assfail("(" #A ") implies (" #B ")", __FILE__, __LINE__)))
#define	EQUIV(A, B) \
	((void)((!!(A) == !!(B)) || \
	    assfail("(" #A ") is equivalent to (" #B ")", __FILE__, __LINE__)))
#else
#define	IMPLY(A, B) ((void)0)
#define	EQUIV(A, B) ((void)0)
#endif

/*
 * ASSERT3() behaves like ASSERT() except that it is an explicit conditional,
 * and prints out the values of the left and right hand expressions as part of
 * the panic message to ease debugging.  The three variants imply the type
 * of their arguments.  ASSERT3S() is for signed data types, ASSERT3U() is
 * for unsigned, and ASSERT3P() is for pointers.  The VERIFY3*() macros
 * have the same relationship as above.
 */
extern void assfail3(const char *, uintmax_t, const char *, uintmax_t,
    const char *, int);
#define	VERIFY3_IMPL(LEFT, OP, RIGHT, TYPE) do { \
	const TYPE __left = (TYPE)(LEFT); \
	const TYPE __right = (TYPE)(RIGHT); \
	if (!(__left OP __right)) \
		assfail3(#LEFT " " #OP " " #RIGHT, \
			(uintmax_t)__left, #OP, (uintmax_t)__right, \
			__FILE__, __LINE__); \
_NOTE(CONSTCOND) } while (0)

#define	VERIFY3S(x, y, z)	VERIFY3_IMPL(x, y, z, int64_t)
#define	VERIFY3U(x, y, z)	VERIFY3_IMPL(x, y, z, uint64_t)
#define	VERIFY3P(x, y, z)	VERIFY3_IMPL(x, y, z, uintptr_t)
#if DEBUG
#define	ASSERT3S(x, y, z)	VERIFY3_IMPL(x, y, z, int64_t)
#define	ASSERT3U(x, y, z)	VERIFY3_IMPL(x, y, z, uint64_t)
#define	ASSERT3P(x, y, z)	VERIFY3_IMPL(x, y, z, uintptr_t)
#else
#define	ASSERT3S(x, y, z)	((void)0)
#define	ASSERT3U(x, y, z)	((void)0)
#define	ASSERT3P(x, y, z)	((void)0)
#endif

#ifdef	_KERNEL

extern void abort_sequence_enter(char *);
extern void debug_enter(char *);

#endif	/* _KERNEL */

#if defined(DEBUG) && !defined(__sun)
/* CSTYLED */
#define	STATIC
#else
/* CSTYLED */
#define	STATIC static
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DEBUG_H */
