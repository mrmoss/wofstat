/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ASM_CPU_H
#define	_ASM_CPU_H

#pragma ident	"@(#)cpu.h	1.2	10/01/08 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(__lint) && defined(__GNUC__)

#if defined(__i386) || defined(__amd64)

extern __inline__ void ht_pause(void)
{
	__asm__ __volatile__(
	    "pause");
}

extern __inline__ void cli(void)
{
	__asm__ __volatile__(
	    "cli" : : : "memory");
}

extern __inline__ void sti(void)
{
	__asm__ __volatile__(
	    "sti");
}

extern __inline__ void i86_halt(void)
{
	__asm__ __volatile__(
	    "sti; hlt");
}

/*
 * prefetch 64 bytes
 *
 * prefetch is an SSE extension which is not supported on
 * older 32-bit processors, so define this as a no-op for now
 */

extern __inline__ void
prefetch_read_many(void *addr)
{
#if defined(__amd64)
	__asm__(
	    "prefetcht0 (%0);"
	    "prefetcht0 32(%0);"
	    : /* no output */
	    : "r" (addr));
#endif	/* __amd64 */
}

extern __inline__ void
prefetch_read_once(void *addr)
{
#if defined(__amd64)
	__asm__(
	    "prefetchnta (%0);"
	    "prefetchnta 32(%0);"
	    : /* no output */
	    : "r" (addr));
#endif	/* __amd64 */
}

extern __inline__ void
prefetch_write_many(void *addr)
{
#if defined(__amd64)
	__asm__(
	    "prefetcht0 (%0);"
	    "prefetcht0 32(%0);"
	    : /* no output */
	    : "r" (addr));
#endif	/* __amd64 */
}

extern __inline__ void
prefetch_write_once(void *addr)
{
#if defined(__amd64)
	__asm__(
	    "prefetcht0 (%0);"
	    "prefetcht0 32(%0);"
	    : /* no output */
	    : "r" (addr));
#endif	/* __amd64 */
}

#endif	/* __i386 || defined(__amd64) */

#endif	/* !__lint && __GNUC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _ASM_CPU_H */
