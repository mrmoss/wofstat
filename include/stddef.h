/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _STDDEF_H
#define	_STDDEF_H

#pragma ident	"@(#)stddef.h	1.18	04/09/28 SMI"

#include <sys/isa_defs.h>
#include <iso/stddef_iso.h>

/*
 * Allow global visibility for symbols defined in
 * C++ "std" namespace in <iso/stddef_iso.h>.
 */
#if __cplusplus >= 199711L
using std::ptrdiff_t;
using std::size_t;
#endif

#ifdef	__cplusplus
extern "C" {
#endif

/* wchar_t is a built-in type in standard C++ */
#if !defined(__cplusplus) || __cplusplus < 199711L
#ifndef _WCHAR_T
#define	_WCHAR_T
#if !defined(__GNUG__)		/* g++ has wchar_t as a built-in type */
#if defined(_LP64)
typedef int	wchar_t;
#else
typedef long    wchar_t;
#endif
#endif	/* !__GNUG__ */
#endif  /* !_WCHAR_T */
#endif	/* !defined(__cplusplus) || __cplusplus < 199711L */

#ifdef	__cplusplus
}
#endif

#endif	/* _STDDEF_H */
