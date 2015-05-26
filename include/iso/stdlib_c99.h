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

#ifndef _ISO_STDLIB_C99_H
#define	_ISO_STDLIB_C99_H

#pragma ident	"@(#)stdlib_c99.h	1.2	04/03/29 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * The following have been added as a result of the ISO/IEC 9899:1999
 * standard. For a strictly conforming C application, visibility is
 * contingent on the value of __STDC_VERSION__ (see sys/feature_tests.h).
 * For non-strictly conforming C applications, there are no restrictions
 * on the C namespace.
 */

#if defined(_LONGLONG_TYPE)
typedef struct {
	long long	quot;
	long long	rem;
} lldiv_t;
#endif  /* defined(_LONGLONG_TYPE) */

#ifdef __STDC__

#if (!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX)) || \
	defined(_STDC_C99) || defined(__EXTENSIONS__)

extern void _Exit(int);
extern float strtof(const char *_RESTRICT_KYWD, char **_RESTRICT_KYWD);
extern long double strtold(const char *_RESTRICT_KYWD, char **_RESTRICT_KYWD);

#if defined(_LONGLONG_TYPE)
extern long long atoll(const char *);
extern long long llabs(long long);
extern lldiv_t lldiv(long long, long long);
extern long long strtoll(const char *_RESTRICT_KYWD, char **_RESTRICT_KYWD,
	int);
extern unsigned long long strtoull(const char *_RESTRICT_KYWD,
	char **_RESTRICT_KYWD, int);
#endif /* defined(_LONGLONG_TYPE) */

#endif  /* (!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX)) ... */

#else /* __STDC__ */

#if !defined(__XOPEN_OR_POSIX) || defined(_XPG6) || defined(__EXTENSIONS__)

extern void _Exit();
extern float strtof();
extern long double strtold();

#if defined(_LONGLONG_TYPE)
extern long long atoll();
extern long long llabs();
extern lldiv_t lldiv();
extern long long strtoll();
extern unsigned long long strtoull();
#endif /* defined(_LONGLONG_TYPE) */

#endif /* !defined(__XOPEN_OR_POSIX) || defined(_XPG6)... */

#endif /* __STDC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _ISO_STDLIB_C99_H */
