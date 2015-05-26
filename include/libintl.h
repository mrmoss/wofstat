/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/* Libintl is a library of advanced internationalization functions. */

#ifndef	_LIBINTL_H
#define	_LIBINTL_H

#pragma ident	"@(#)libintl.h	1.16	04/09/28 SMI"

#include <sys/isa_defs.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * wchar_t is a built-in type in standard C++ and as such is not
 * defined here when using standard C++. However, the GNU compiler
 * fixincludes utility nonetheless creates it's own version of this
 * header for use by gcc and g++. In that version it adds a redundant
 * guard for __cplusplus. To avoid the creation of a gcc/g++ specific
 * header we need to include the following magic comment:
 *
 * we must use the C++ compiler's type
 *
 * The above comment should not be removed or changed until GNU
 * gcc/fixinc/inclhack.def is updated to bypass this header.
 */
#if !defined(__cplusplus) || __cplusplus < 199711L
#ifndef _WCHAR_T
#define	_WCHAR_T
#if !defined(__GNUG__)		/* g++ has wchar_t as a built-in type */
#if defined(_LP64)
typedef int	wchar_t;
#else
typedef long	wchar_t;
#endif
#endif	/* !__GNUG__ */
#endif	/* !_WCHAR_T */
#endif	/* !defined(__cplusplus) || __cplusplus < 199711L */

#define	TEXTDOMAINMAX	256

#ifdef __STDC__
extern char *dcgettext(const char *, const char *, const int);
extern char *dgettext(const char *, const char *);
extern char *gettext(const char *);
extern char *textdomain(const char *);
extern char *bindtextdomain(const char *, const char *);

/*
 * LI18NUX 2000 Globalization Specification Version 1.0
 * with Amendment 2
 */
extern char *dcngettext(const char *, const char *,
	const char *, unsigned long int, int);
extern char *dngettext(const char *, const char *,
	const char *, unsigned long int);
extern char *ngettext(const char *, const char *, unsigned long int);
extern char *bind_textdomain_codeset(const char *, const char *);

/* Word handling functions --- requires dynamic linking */
/* Warning: these are experimental and subject to change. */
extern int wdinit(void);
extern int wdchkind(wchar_t);
extern int wdbindf(wchar_t, wchar_t, int);
extern wchar_t *wddelim(wchar_t, wchar_t, int);
extern wchar_t mcfiller(void);
extern int mcwrap(void);

#else
extern char *dcgettext();
extern char *dgettext();
extern char *gettext();
extern char *textdomain();
extern char *bindtextdomain();

/*
 * LI18NUX 2000 Globalization Specification Version 1.0
 * with Amendment 2
 */
extern char *dcngettext();
extern char *dngettext();
extern char *ngettext();
extern char *bind_textdomain_codeset();

/* Word handling functions --- requires dynamic linking */
/* Warning: these are experimental and subject to change. */
extern int wdinit();
extern int wdchkind();
extern int wdbindf();
extern wchar_t *wddelim();
extern wchar_t mcfiller();
extern int mcwrap();

#endif

#ifdef	__cplusplus
}
#endif

#endif /* _LIBINTL_H */
