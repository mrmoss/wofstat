/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 1999-2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */


#ifndef _ERRNO_H
#define	_ERRNO_H

#pragma ident	"@(#)errno.h	1.17	03/01/03 SMI"	/* SVr4.0 1.4.1.5 */

/*
 * Error codes
 */

#include <sys/errno.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if defined(_LP64)
/*
 * The symbols _sys_errlist and _sys_nerr are not visible in the
 * LP64 libc.  Use strerror(3C) instead.
 */
#endif /* _LP64 */

#if defined(_REENTRANT) || defined(_TS_ERRNO) || _POSIX_C_SOURCE - 0 >= 199506L
extern int *___errno();
#define	errno (*(___errno()))
#else
extern int errno;
/* ANSI C++ requires that errno be a macro */
#if __cplusplus >= 199711L
#define	errno errno
#endif
#endif	/* defined(_REENTRANT) || defined(_TS_ERRNO) */

#ifdef	__cplusplus
}
#endif

#endif	/* _ERRNO_H */
