/*
 * Copyright (c) 1989, 2011, Oracle and/or its affiliates. All rights reserved.
 */

/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef	_SHADOW_H
#define	_SHADOW_H

#pragma ident	"@(#)shadow.h	1.19	11/04/08 SMI"	/* SVr4.0 1.2	*/

#ifdef	__cplusplus
extern "C" {
#endif

#define	PASSWD 		"/etc/passwd"
#define	SHADOW		"/etc/shadow"
#define	OPASSWD		"/etc/opasswd"
#define	OSHADOW 	"/etc/oshadow"
#define	PASSTEMP	"/etc/ptmp"
#define	SHADTEMP	"/etc/stmp"

#define	DAY		(24L * 60 * 60) /* 1 day in seconds */
#define	DAY_NOW		(time_t)time((time_t *)0) / DAY
			/* The above timezone variable is set by a call to */
			/* any ctime(3c) routine.  Programs using the DAY_NOW */
			/* macro must call one of the ctime routines, */
			/* e.g. tzset(), BEFORE referencing DAY_NOW */

#define	LOCKSTRING	"*LK*"	/* prefix to/string in sp_pwdp to lock acct */
#define	NOLOGINSTRING	"NP"	/* sp_pwdp for no-login accounts */
#define	UNINITPW	"UP"	/* sp_pwdp for uninitialized password */

/*
 * The spwd structure is used in the retreval of information from
 * /etc/shadow.  It is used by routines in the libos library.
 */
struct spwd {
	char *sp_namp;	/* user name */
	char *sp_pwdp;	/* user password */
	int sp_lstchg;	/* password lastchanged date */
	int sp_min;	/* minimum number of days between password changes */
	int sp_max;	/* number of days password is valid */
	int sp_warn;	/* number of days to warn user to change passwd */
	int sp_inact;	/* number of days the login may be inactive */
	int sp_expire;	/* date when the login is no longer valid */
	unsigned int sp_flag;	/* currently low 4 bits are used */

	/* low 4 bits of sp_flag for counting failed login attempts */
#define	FAILCOUNT_MASK 0xF
};

#if defined(__STDC__)

#ifndef _STDIO_H
#include <stdio.h>
#endif

/* Declare all shadow password functions */

extern struct spwd *getspnam_r(const char *,  struct spwd *, char *, int);
extern struct spwd *getspent_r(struct spwd *, char *, int);
extern struct spwd *fgetspent_r(FILE *, struct spwd *, char *, int);

extern void	setspent(void);
extern void	endspent(void);
extern struct spwd	*getspent(void);			/* MT-unsafe */
extern struct spwd	*fgetspent(FILE *);			/* MT-unsafe */
extern struct spwd	*getspnam(const char *);	/* MT-unsafe */

extern int	putspent(const struct spwd *, FILE *);
extern int	lckpwdf(void);
extern int	ulckpwdf(void);

#else

/* Declare all shadow password functions */

struct spwd	*getspent_r(), *fgetspent_r(), *getspnam_r();
void		setspent(), endspent();
struct spwd	*getspent(), *fgetspent(), *getspnam(); /* MT-unsafe */
int		putspent(), lckpwdf(), ulckpwdf();

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SHADOW_H */
