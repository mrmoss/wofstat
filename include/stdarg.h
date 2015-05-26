/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _STDARG_H
#define	_STDARG_H

#pragma ident	"@(#)stdarg.h	1.47	04/09/28 SMI"	/* SVr4.0 1.8	*/

/*
 * This header defines the ISO C 1989, ISO C++ 1998, and ISO C 1999
 * variable argument definitions.  For legacy support, it also defines
 * the pre-standard variable argument definitions.
 *
 * The varargs definitions within this header are defined in terms of
 * implementation definitions.  These implementation definitions reside
 * in <sys/va_list.h>.  This organization enables protected use of
 * the implementation by other standard headers without introducing
 * names into the users' namespace.
 */

#if defined(__STDC__)

#include <iso/stdarg_iso.h>
#include <iso/stdarg_c99.h>

/*
 * Allow global visibility for symbols defined in
 * C++ "std" namespace in <iso/stdarg_iso.h>.
 */
#if __cplusplus >= 199711L
using std::va_list;
#endif

#else	/* __STDC__ */

#include <varargs.h>

#endif	/* __STDC__ */

#endif	/* _STDARG_H */
