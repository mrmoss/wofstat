/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ISO_STDARG_C99_H
#define	_ISO_STDARG_C99_H

#pragma ident	"@(#)stdarg_c99.h	1.2	04/09/28 SMI" /* SVr4.0 1.8 */

/*
 * An application should not include this header directly.  Instead it
 * should be included only through the inclusion of other Sun headers.
 *
 * This header defines the va_copy variable argument macro, which is
 * new in ISO C 1999, and thus not present in ISO C 1989 and ISO C++
 * 1998.  Because this macro is a long-standing Solaris extension, it
 * is also permitted in other contexts.
 *
 * The varargs definitions within this header are defined in terms of
 * implementation definitions.  These implementation definitions reside
 * in <sys/va_list.h>.  This organization enables protected use of
 * the implementation by other standard headers without introducing
 * names into the users' namespace.
 */

#include <sys/feature_tests.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * va_copy was initially a Solaris extension to provide a portable
 * way to perform a variable argument list ``bookmarking'' function.
 * It is now specified in the ISO/IEC 9899:1999 standard.
 */
#if defined(__EXTENSIONS__) || defined(_STDC_C99) || \
	(!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX)) || \
	defined(_XPG6)

#define	va_copy(to, from)	__va_copy(to, from)

#endif	/* defined(__EXTENSIONS__) || defined(_STDC_C99)... */

#ifdef	__cplusplus
}
#endif

#endif	/* _ISO_STDARG_C99_H */
