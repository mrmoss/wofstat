/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_ISO646_H
#define	_ISO646_H

#pragma ident	"@(#)iso646.h	1.2	04/05/03 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Introduced in ISO/IEC 9899:1990/Ammendment 1:1995 (C Standard).
 * In ISO/IEC 14882:1998 (C++ Standard), these tokens are keywords
 * rather than macro names.
 */

#if !defined(__cplusplus) || __cplusplus < 199711L
#define	and	&&
#define	and_eq	&=
#define	bitand	&
#define	bitor	|
#define	compl	~
#define	not	!
#define	not_eq	!=
#define	or	||
#define	or_eq	|=
#define	xor	^
#define	xor_eq	^=
#endif	/* !defined(__cplusplus) || __cplusplus < 199711 */

#ifdef	__cplusplus
}
#endif

#endif	/* _ISO646_H */
