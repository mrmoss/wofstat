/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_PSW_H
#define	_SYS_PSW_H

#pragma ident	"@(#)psw.h	1.20	04/09/28 SMI"

#if defined(__i386) || defined(__amd64)

#include <ia32/sys/psw.h>	/* XX64 x86/sys/psw.h */

#elif defined(__ia64)

#include <ia64/sys/psw.h>

#endif

#endif	/* _SYS_PSW_H */
