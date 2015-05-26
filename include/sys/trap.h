/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_TRAP_H
#define	_SYS_TRAP_H

#pragma ident	"@(#)trap.h	1.11	04/09/28 SMI"

#if defined(__i386) || defined(__amd64)

#include <ia32/sys/trap.h>	/* XX64	x86/sys/trap.h */

#elif defined(__ia64)

#include <ia64/sys/trap.h>

#endif

#endif	/* _SYS_TRAP_H */
