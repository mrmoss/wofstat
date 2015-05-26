/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*
 * An application should not include this header directly.  Instead it
 * should be included only through the inclusion of other Sun headers.
 *
 * The contents of this header is limited to identifiers specified in
 * the C99 standard and in conflict with the C++ implementation of the
 * standard header.  The C++ standard may adopt the C99 standard at
 * which point it is expected that the symbols included here will
 * become part of the C++ std namespace.
 */

#ifndef	_ISO_WCHAR_C99_H
#define	_ISO_WCHAR_C99_H

#pragma ident	"@(#)wchar_c99.h	1.3	04/03/29 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/* Introduced in ISO/IEC 9899:1999 standard */

#if !defined(_LP64) && !defined(_LONGLONG_TYPE)
#ifdef __PRAGMA_REDEFINE_EXTNAME
#pragma	redefine_extname vfwscanf	_vfwscanf_c89
#pragma	redefine_extname vswscanf	_vswscanf_c89
#pragma	redefine_extname vwscanf	_vwscanf_c89
#else
#define	vfwscanf	_vfwscanf_c89
#define	vswscanf	_vswscanf_c89
#define	vwscanf		_vwscanf_c89
#endif
#endif /* !defined(_LP64) && !defined(_LONGLONG_TYPE) */

#ifdef __STDC__

#if defined(_STDC_C99) || \
	(!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX)) || \
	defined(_XPG6) || defined(__EXTENSIONS__)
extern int vfwscanf(__FILE *_RESTRICT_KYWD, const wchar_t *_RESTRICT_KYWD,
		__va_list);
extern int vswscanf(const wchar_t *_RESTRICT_KYWD,
		const wchar_t *_RESTRICT_KYWD, __va_list);
extern int vwscanf(const wchar_t *_RESTRICT_KYWD, __va_list);
extern float wcstof(const wchar_t *_RESTRICT_KYWD,
		wchar_t **_RESTRICT_KYWD);
#if defined(_LONGLONG_TYPE)
extern long double wcstold(const wchar_t *_RESTRICT_KYWD,
		wchar_t **_RESTRICT_KYWD);
extern long long wcstoll(const wchar_t *_RESTRICT_KYWD,
		wchar_t **_RESTRICT_KYWD, int);
extern unsigned long long wcstoull(const wchar_t *_RESTRICT_KYWD,
		wchar_t **_RESTRICT_KYWD, int);
#endif /* defined(_LONGLONG_TYPE) */

#endif /* defined(_STDC_C99) || (!defined(_STRICT_STDC)... */

#else /* __STDC__ */

#if !defined(__XOPEN_OR_POSIX) || defined(_XPG6) || defined(__EXTENSIONS__)
extern int 	vfwscanf();
extern int 	vswscanf();
extern int 	vwscanf();
extern float 	wcstof();
extern long double wcstold();
extern long int wcstoll();
extern long int wcstoull();
#endif /* !defined(__XOPEN_OR_POSIX) || defined(_XPG6) ... */

#endif /* __STDC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _ISO_WCHAR_C99_H */
