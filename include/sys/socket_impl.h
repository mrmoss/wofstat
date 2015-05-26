/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any	*/
/*	actual or intended publication of such source code.	*/

/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *		PROPRIETARY NOTICE (Combined)
 *
 * This source code is unpublished proprietary information
 * constituting, or derived under license from AT&T's UNIX(r) System V.
 * In addition, portions of such source code were derived from Berkeley
 * 4.3 BSD under license from the Regents of the University of
 * California.
 *
 *		Copyright Notice
 *
 * Notice of copyright on this source code product does not indicate
 * publication.
 *
 *	(c) 1986,1987,1988,1989  Sun Microsystems, Inc
 *	(c) 1983,1984,1985,1986,1987,1988,1989  AT&T.
 *		All rights reserved.
 */

#ifndef	_SYS_SOCKET_IMPL_H
#define	_SYS_SOCKET_IMPL_H

#pragma ident	"@(#)socket_impl.h	1.1	05/08/02 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef	_SA_FAMILY_T
#define	_SA_FAMILY_T
typedef uint16_t	sa_family_t;
#endif

/*
 * Structure used by kernel to store most
 * addresses.
 */
struct sockaddr {
	sa_family_t	sa_family;	/* address family */
	char		sa_data[14];	/* up to 14 bytes of direct address */
};

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
#include <sys/un.h>
#include <net/if_dl.h>
#endif	/* !defined(_XPG4_2) || defined(__EXTENSIONS__) */

#if !defined(_XPG4_2) || defined(_XPG6) || defined(__EXTENSIONS__)
/*
 * sockaddr_storage:
 * Common superset of at least AF_INET, AF_INET6 and AF_LINK sockaddr
 * structures. Has sufficient size and alignment for those sockaddrs.
 */

/*
 * Desired maximum size, alignment size and related types.
 */
#define	_SS_MAXSIZE	256	/* Implementation specific max size */

/*
 * To represent desired sockaddr max alignment for platform, a
 * type is chosen which may depend on implementation platform architecture.
 * Type chosen based on alignment size restrictions from <sys/isa_defs.h>.
 * We desire to force up to (but no more than) 64-bit (8 byte) alignment,
 * on platforms where it is possible to do so. (e.g not possible on ia32).
 * For all currently supported platforms by our implementation
 * in <sys/isa_defs.h>, (i.e. sparc, sparcv9, ia32, ia64)
 * type "double" is suitable for that intent.
 *
 * Note: Type "double" is chosen over the more obvious integer type int64_t.
 *   int64_t is not a valid type for strict ANSI/ISO C compilation on ILP32.
 */
typedef	double		sockaddr_maxalign_t;

#define	_SS_ALIGNSIZE	(sizeof (sockaddr_maxalign_t))

/*
 * Definitions used for sockaddr_storage structure paddings design.
 */
#define	_SS_PAD1SIZE	(_SS_ALIGNSIZE - sizeof (sa_family_t))
#define	_SS_PAD2SIZE	(_SS_MAXSIZE - (sizeof (sa_family_t)+ \
			_SS_PAD1SIZE + _SS_ALIGNSIZE))

struct sockaddr_storage {
	sa_family_t	ss_family;	/* Address family */
	/* Following fields are implementation specific */
	char		_ss_pad1[_SS_PAD1SIZE];
	sockaddr_maxalign_t _ss_align;
	char		_ss_pad2[_SS_PAD2SIZE];
};
#endif	/* !defined(_XPG4_2) || defined(_XPG6) || defined(__EXTENSIONS__) */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SOCKET_IMPL_H */
