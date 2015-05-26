/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_VARARGS_H
#define	_SYS_VARARGS_H

#pragma ident	"@(#)varargs.h	1.51	04/11/19 SMI"	/* UCB 4.1 83/05/03 */

/*
 * This header defines the Solaris system definitions for variable
 * argument lists.  For the most part, it follows the definitions of
 * ISO C 1999.  It does not follow the namespace rules for ISO C++
 * 1998.  For legacy support, it also defines the pre-standard variable
 * argument definitions.
 *
 * The varargs definitions within this header are defined in terms of
 * implementation definitions.  These implementation definitions reside
 * in <sys/va_impl.h>.  This organization enables protected use of
 * the implementation by other standard headers without introducing
 * names into the users' namespace.
 */

#include <sys/va_impl.h>

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef	_VA_LIST
#define	_VA_LIST
typedef __va_list va_list;
#endif

#if defined(__STDC__)
/*
 * When __STDC__ is defined, this file provides stdarg semantics despite
 * the name of the file.
 */

#define	va_start(list, name)	__va_start(list, name)
#define	va_arg(list, type)	__va_arg(list, type)
#define	va_copy(to, from)	__va_copy(to, from)
#define	va_end(list)		__va_end(list)

#else	/* ! __STDC__ */
/*
 * In the absence of __STDC__, this file provides traditional varargs
 * semantics.
 */

#define	va_alist		__builtin_va_alist
#define	va_dcl			__va_alist_type va_alist;
#define	va_start(list)		__va_start(list, va_alist)
#define	va_arg(list, type)	__va_arg(list, type)
#define	va_copy(to, from)	__va_copy(to, from)
#define	va_end(list)		__va_end(list)

#endif	/* __STDC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_VARARGS_H */
