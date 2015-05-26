/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*
 * An application should not include this header directly.  Instead it
 * should be included only through the inclusion of <ctype.h>.
 *
 * The contents of this header is limited to identifiers specified in
 * the C99 standard and in conflict with the C++ implementation of the
 * standard header.  The C++ standard may adopt the C99 standard at
 * which point it is expected that the symbols included here will
 * become part of the C++ std namespace.
 */

#ifndef _ISO_CTYPE_C99_H
#define	_ISO_CTYPE_C99_H

#pragma ident	"@(#)ctype_c99.h	1.2	04/09/28 SMI"

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

#if defined(__STDC__)

#if (!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX)) || \
	defined(_XPG6) || defined(_STDC_C99) || defined(__EXTENSIONS__)
extern int isblank(int);
#endif

#if !defined(__lint)

#if (!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX)) || \
	defined(_XPG6) || defined(_STDC_C99) || \
	defined(__XPG4_CHAR_CLASS__) || defined(__EXTENSIONS__)
#define	isblank(c)	(__ctype_mask[(int)(c)] & _ISBLANK)
#endif

#endif	/* !defined(__lint) */

#else	/* defined(__STDC__) */

#if !defined(__lint)

#define	isblank(c)	((_ctype + 1)[(int)(c)] & _B)

#endif	/* !defined(__lint) */

#endif	/* defined(__STDC__) */

#ifdef	__cplusplus
}
#endif

#endif	/* _ISO_CTYPE_C99_H */
