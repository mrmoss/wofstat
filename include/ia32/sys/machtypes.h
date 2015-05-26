/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _IA32_SYS_MACHTYPES_H
#define	_IA32_SYS_MACHTYPES_H

#pragma ident	"@(#)machtypes.h	1.2	04/09/28 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Machine dependent types:
 *
 *	intel ia32 Version
 */

#if (!defined(_POSIX_C_SOURCE) && !defined(_XOPEN_SOURCE)) || \
	defined(__EXTENSIONS__)

#if defined(__amd64)
typedef	struct	_label_t { long val[8]; } label_t;
#else
typedef	struct	_label_t { long val[6]; } label_t;
#endif

#endif /* !defined(_POSIX_C_SOURCE)... */

typedef	unsigned char	lock_t;		/* lock work for busy wait */

#ifdef	__cplusplus
}
#endif

#endif	/* _IA32_SYS_MACHTYPES_H */
