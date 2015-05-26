/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ASM_MMU_H
#define	_ASM_MMU_H

#pragma ident	"@(#)mmu.h	1.1	04/09/28 SMI"

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(__lint) && defined(__GNUC__)

#if defined(__i386)

extern __inline__ ulong_t getcr3(void)
{
	uint32_t value;

	__asm__ __volatile__(
		"mov %%cr3, %0"
		: "+r" (value));
	return (value);
}

extern __inline__ void setcr3(ulong_t value)
{
	__asm__ __volatile__(
		"mov %0, %%cr3"
		: /* no output */
		: "r" (value));
}

extern __inline__ void reload_cr3(void)
{
	setcr3(getcr3());
}

#endif /* __i386 */

#endif /* !__lint && __GNUC__ */

#ifdef __cplusplus
}
#endif

#endif	/* _ASM_MMU_H */
