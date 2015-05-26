/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_ICONV_H
#define	_ICONV_H

#pragma ident	"@(#)iconv.h	1.3	03/12/04 SMI"

#include <sys/feature_tests.h>
#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct _iconv_info *iconv_t;

#if defined(__STDC__)
extern iconv_t	iconv_open(const char *, const char *);
#ifdef _XPG6
extern size_t	iconv(iconv_t, char **_RESTRICT_KYWD,
		size_t *_RESTRICT_KYWD, char **_RESTRICT_KYWD,
		size_t *_RESTRICT_KYWD);
#else
extern size_t	iconv(iconv_t, const char **_RESTRICT_KYWD,
		size_t *_RESTRICT_KYWD, char **_RESTRICT_KYWD,
		size_t *_RESTRICT_KYWD);
#endif
extern int	iconv_close(iconv_t);
#else /* __STDC__ */
extern iconv_t	iconv_open();
extern size_t	iconv();
extern int	iconv_close();
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _ICONV_H */
