/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_STROPTS_H
#define	_STROPTS_H

#pragma ident	"@(#)stropts.h	1.10	03/12/04 SMI"	/* SVr4.0 1.6	*/

/*
 * Streams user options definitions.
 */

#include <sys/feature_tests.h>
#include <sys/stropts.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if defined(__STDC__)

extern int isastream(int);

extern int getmsg(int, struct strbuf *_RESTRICT_KYWD,
		struct strbuf *_RESTRICT_KYWD, int *_RESTRICT_KYWD);
extern int putmsg(int, const struct strbuf *, const struct strbuf *, int);

extern int getpmsg(int, struct strbuf *_RESTRICT_KYWD,
		struct strbuf *_RESTRICT_KYWD, int *_RESTRICT_KYWD,
		int *_RESTRICT_KYWD);
extern int putpmsg(int, const struct strbuf *, const struct strbuf *, int, int);

/*
 * These three routines are duplicated in unistd.h; duplication necessitated
 * by XPG4.2 compliance/namespace issues.
 */
extern int ioctl(int, int, ...);
extern int fattach(int, const char *);
extern int fdetach(const char *);

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _STROPTS_H */
