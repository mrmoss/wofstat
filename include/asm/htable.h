/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ASM_HTABLE_H
#define	_ASM_HTABLE_H

#pragma ident	"@(#)htable.h	1.1	04/09/28 SMI"

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(__lint) && defined(__GNUC__)

#if defined(__i386) || defined(__amd64)

/*
 * This set of atomic operations are designed primarily
 * for some ia32 hat layer operations.
 */

extern __inline__ void atomic_orb(uint8_t *addr, uint8_t value)
{
	__asm__ __volatile__(
	    "lock; orb %%dl,%0"
	    : "=m" (*addr)
	    : "d" (value), "m" (*addr)
	    : "cc");
}

extern __inline__ void atomic_andb(uint8_t *addr, uint8_t value)
{
	__asm__ __volatile__(
	    "lock; andb %%dl,%0"
	    : "=m" (*addr)
	    : "d" (value), "m" (*addr)
	    : "cc");
}

extern __inline__ void atomic_inc16(uint16_t *addr)
{
	__asm__ __volatile__(
	    "lock; incw %0"
	    : "=m" (*addr)
	    : "m" (*addr)
	    : "cc");
}

extern __inline__ void atomic_dec16(uint16_t *addr)
{
	__asm__ __volatile__(
	    "lock; decw %0"
	    : "=m" (*addr)
	    : "m" (*addr)
	    : "cc");
}

extern __inline__ void mmu_tlbflush_entry(caddr_t addr)
{
	__asm__ __volatile__(
	    "invlpg %0"
	    : "=m" (*addr)
	    : "m" (*addr));
}

#endif	/* __i386 || __amd64 */

#endif	/* !__lint && __GNUC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _ASM_HTABLE_H */
