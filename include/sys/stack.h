/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_STACK_H
#define	_SYS_STACK_H

#pragma ident	"@(#)stack.h	1.12	04/09/28 SMI"

#if defined(__i386) || defined(__amd64)

#include <ia32/sys/stack.h>	/* XX64 x86/sys/stack.h */

#elif defined(__ia64)

#include <ia64/sys/stack.h>

#endif

#endif	/* _SYS_STACK_H */
