/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * unctrl.h
 *
 */

#ifndef	_UNCTRL_H
#define	_UNCTRL_H

#pragma ident	"@(#)unctrl.h	1.8	03/05/02 SMI"	/* SVr4.0 1.3	*/

#ifdef	__cplusplus
extern "C" {
#endif

extern char	*_unctrl[];

#if	!defined(NOMACROS) && !defined(__lint)

#define	unctrl(ch)	(_unctrl[(unsigned)ch])

#endif	/* NOMACROS && __lint */

#ifdef	__cplusplus
}
#endif

#endif	/* _UNCTRL_H */
