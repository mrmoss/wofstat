/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 1997-2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MON_H
#define	_MON_H

#pragma ident	"@(#)mon.h	1.16	03/05/20 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Inclusion of <sys/types.h> will break SVID namespace, hence only
 * the size_t type is defined in this header.
 */
#if !defined(_SIZE_T) || __cplusplus >= 199711L
#define	_SIZE_T
#if defined(_LP64) || defined(_I32LPx)
typedef unsigned long size_t;	/* size of something in bytes */
#else
typedef unsigned int  size_t;	/* (historical version) */
#endif
#endif  /* _SIZE_T */

struct hdr {
	char	*lpc;
	char	*hpc;
	size_t	nfns;
};

struct cnt {
	char	*fnpc;
	long	mcnt;
};

typedef unsigned short WORD;

#define	MON_OUT	"mon.out"
#define	MPROGS0	(150 * sizeof (WORD))	/* 300 for pdp11, 600 for 32-bits */
#define	MSCALE0	4

#ifndef NULL
#if defined(_LP64)
#define	NULL	0L
#else
#define	NULL	0
#endif
#endif

#if defined(__STDC__)
extern void monitor(int (*)(void), int (*)(void), WORD *, size_t, size_t);
#else
extern void monitor();
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _MON_H */
