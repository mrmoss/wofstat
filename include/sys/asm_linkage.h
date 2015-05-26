/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_ASM_LINKAGE_H
#define	_SYS_ASM_LINKAGE_H

#pragma ident	"@(#)asm_linkage.h	1.12	04/09/28 SMI"

#if defined(__i386) || defined(__amd64)

#include <ia32/sys/asm_linkage.h>	/* XX64	x86/sys/asm_linkage.h */

#elif defined(__ia64)

#include <ia64/sys/asm_linkage.h>

#endif

#endif	/* _SYS_ASM_LINKAGE_H */
