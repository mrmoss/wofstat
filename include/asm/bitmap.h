/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ASM_BITMAP_H
#define	_ASM_BITMAP_H

#pragma ident	"@(#)bitmap.h	1.1	04/09/28 SMI"

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(__lint) && defined(__GNUC__)

extern __inline__ int
highbit(ulong_t i)
{
	long __value = -1l;

#if defined(__amd64)
	__asm__(
		"bsrq	%1,%0"
		: "+r" (__value)
		: "r" (i)
		: "cc");
#elif defined(__i386)
	__asm__(
		"bsrl	%1,%0"
		: "+r" (__value)
		: "r" (i)
		: "cc");
#else
#error	"port me"
#endif
	return ((int)(__value + 1));
}

extern __inline__ int
lowbit(ulong_t i)
{
	long __value = -1l;

#if defined(__amd64)
	__asm__(
		"bsfq	%1,%0"
		: "+r" (__value)
		: "r" (i)
		: "cc");
#elif defined(__i386)
	__asm__(
		"bsfl	%1,%0"
		: "+r" (__value)
		: "r" (i)
		: "cc");
#else
#error	"port me"
#endif
	return ((int)(__value + 1));
}

extern __inline__ uint_t
atomic_btr32(uint32_t *memory, uint_t bitnum)
{
	uint8_t __value;

#if defined(__amd64)
	__asm__ __volatile__(
		"lock;"
		"btrl %2, (%0);"
		"setc %1"
		: "+r" (memory), "+r" (__value)
		: "ir" (bitnum)
		: "cc");
#elif defined(__i386)
	__asm__ __volatile__(
		"lock;"
		"btrl %2, (%0);"
		"setc %1"
		: "+r" (memory), "=r" (__value)
		: "ir" (bitnum)
		: "cc")
#else
#error	"port me"
#endif
	return ((uint_t)__value);
}

#endif	/* !__lint && __GNUC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _ASM_BITMAP_H */
