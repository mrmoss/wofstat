/*
 * Copyright 1996-2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/


#ifndef _SYS_IPC_H
#define	_SYS_IPC_H

#pragma ident	"@(#)ipc.h	1.23	03/02/05 SMI"

#include <sys/isa_defs.h>
#include <sys/feature_tests.h>
#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

/* Common IPC access structure */

struct ipc_perm {
	uid_t		uid;	/* owner's user id */
	gid_t		gid;	/* owner's group id */
	uid_t		cuid;	/* creator's user id */
	gid_t		cgid;	/* creator's group id */
	mode_t		mode;	/* access modes */
	uint_t		seq;	/* slot usage sequence number */
	key_t		key;	/* key */
#if !defined(_LP64)
	int		pad[4]; /* reserve area */
#endif
};


/* Common IPC definitions */

/* Mode bits */
#define	IPC_ALLOC	0100000		/* entry currently allocated */
#define	IPC_CREAT	0001000		/* create entry if key doesn't exist */
#define	IPC_EXCL	0002000		/* fail if key exists */
#define	IPC_NOWAIT	0004000		/* error if request must wait */

/* Keys */
#define	IPC_PRIVATE	(key_t)0	/* private key */


/* Common IPC control commands */
#define	IPC_RMID	10	/* remove identifier */
#define	IPC_SET		11	/* set options */
#define	IPC_STAT	12	/* get options */


#if (!defined(_KERNEL) && !defined(_XOPEN_SOURCE)) || defined(_XPG4_2) || \
	defined(__EXTENSIONS__)
#if defined(__STDC__)
key_t ftok(const char *, int);
#else
key_t ftok();
#endif /* defined(__STDC__) */
#endif /* (!defined(_KERNEL) && !defined(_XOPEN_SOURCE))... */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_IPC_H */
