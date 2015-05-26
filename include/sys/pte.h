/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_PTE_H
#define	_SYS_PTE_H

#pragma ident	"@(#)pte.h	1.3	04/09/28 SMI"

#if defined(__i386) || defined(__amd64)

#include <ia32/sys/pte.h>	/* XX64 x86/sys/pte.h */

#elif defined(__ia64)

#include <ia64/sys/pte.h>

#endif

#endif	/* _SYS_PTE_H */
