/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_MONETARY_H
#define	_MONETARY_H

#pragma ident	"@(#)monetary.h	1.2	03/12/04 SMI"

#include <sys/feature_tests.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__STDC__)
extern ssize_t	strfmon(char *_RESTRICT_KYWD, size_t,
			const char *_RESTRICT_KYWD, ...);
#else
extern ssize_t	strfmon();
#endif

#ifdef __cplusplus
}
#endif

#endif	/* _MONETARY_H */
