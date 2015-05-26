/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_VA_LIST_H
#define	_SYS_VA_LIST_H

#pragma ident	"@(#)va_list.h	1.15	04/11/19 SMI"

/*
 * An application should not include this header directly.  Instead it
 * should be included only through the inclusion of other Sun headers.
 *
 * The purpose of this header is to provide the type definitions for
 * the va_list argument used by a number of printf and printf like
 * functions. The headers that define these various function prototypes
 * #include this header directly. These include but are not necessarily
 * limited to <stdio.h>, <stdio_iso.h>, <wchar_iso.h>, <strlog.h> and
 * <syslog.h>. The type definitions included in this header are for
 * the benefit of consumers of va_list.
 *
 * Any application that accepts variable argument lists must as documented,
 * include either <varargs.h> or the preferred <stdarg.h>. Doing so will
 * pull in the appropriate compiler protocols defined in <sys/va_impl.h>
 * which is in turn is included by <varargs.h> and <stdarg.h>. See comments
 * in <sys/va_impl.h> for more detailed information regarding implementation
 * and compiler specific protocols.
 */

/*
 * The common definitions exported by this header or compilers using
 * this header are:
 *
 * the identifier __builtin_va_alist for the variable list pseudo parameter
 * the type __va_alist_type for the variable list pseudo parameter
 * the type __va_list defining the type of the variable list iterator
 *
 * The feature macros (e.g. __BUILTIN_VA_STRUCT) and compiler macros
 * (__GNUC__) and processor macros (e.g. __amd64) are intended to be
 * defined by the compilation system, not the user of the system.
 */

#include <sys/isa_defs.h> 	/* sys/isa_defs needed for _LP64. */

#ifdef	__cplusplus
extern "C" {
#endif

#if defined(_LP64)
#define	__va_alist_type long
#else
#define	__va_alist_type int
#endif

#if defined(__STDC__) /* source language is ISO C or C++ */

#define	__va_void(expr)	((void)expr)
#define	__va_ptr_base	void

#else /* source language is K&R C */

#define	__va_void(expr)	expr
#define	__va_ptr_base	char

#endif /* __STDC__ */

#if defined(__BUILTIN_VA_STRUCT) && !defined(__lint)	/* -------- protocol */

#if defined(__amd64)	/* processor */

typedef struct __va_list_element {
	unsigned int __va_gp_offset;
	unsigned int __va_fp_offset;
	void *__va_overflow_arg_area;
	void *__va_reg_sve_area;
} __va_list[1];

/* Other ISA __va_list structures added here under #elif */

#else	/* processor */

#error("No __va_list structure defined for ISA")

#endif	/* processor */

#elif (defined(__GNUC__) && ((__GNUC__ == 2 && __GNUC_MINOR >= 96) || \
	(__GNUC__ >= 3))) && !defined(__lint)	/* ---------------- protocol */

#define	__GNUC_VA_LIST

typedef __builtin_va_list __gnuc_va_list;
/*
 * XX64 This seems unnecessary .. but is needed because vcmn_err is
 *	defined with __va_list instead of plain old va_list.
 *	Perhaps that should be fixed!
 */
typedef	__builtin_va_list __va_list;

#else  /* default */				/* ---------------- protocol */

typedef __va_ptr_base *__va_list;

#endif  /* -------------------------------------------------------- protocol */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_VA_LIST_H */
