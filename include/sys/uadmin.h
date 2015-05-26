/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef _SYS_UADMIN_H
#define	_SYS_UADMIN_H

#pragma ident	"@(#)uadmin.h	1.31	07/01/14 SMI"

#if !defined(_ASM)
#include <sys/types.h>
#include <sys/cred.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#define	A_REBOOT	1
#define	A_SHUTDOWN	2
#define	A_FREEZE	3	/* For freeze and thaw */
#define	A_REMOUNT	4
#define	A_DUMP		5
#define	A_FTRACE	15
#define	A_SWAPCTL	16
/*			17-21	   reserved for obsolete interface */

#define	AD_HALT		0	/* halt the processor */
#define	AD_BOOT		1	/* multi-user reboot */
#define	AD_IBOOT	2	/* multi-user reboot, ask for name of file */
#define	AD_SBOOT	3	/* single-user reboot */
#define	AD_SIBOOT	4	/* single-user reboot, ask for name of file */
#define	AD_POWEROFF	6	/* software poweroff */
#define	AD_NOSYNC	7	/* do not sync filesystems on next A_DUMP */

/*
 * Functions reserved for A_FREEZE (may not be available on all platforms)
 */
#define	AD_COMPRESS	0	/* store state file compressed during CPR */
#define	AD_FORCE	1	/* force to do AD_COMPRESS */
#define	AD_CHECK	2	/* test if CPR module is available */
/*
 * NOTE: the following defines comprise an Unstable interface.  Their semantics
 * may change or they may be removed completely in a later release
 */
#define	AD_REUSEINIT	3	/* prepare for AD_REUSABLE */
#define	AD_REUSABLE	4	/* create reusable statefile */
#define	AD_REUSEFINI	5	/* revert to normal CPR mode (not reusable) */

#define	AD_FTRACE_START	1
#define	AD_FTRACE_STOP	2

/*
 * When 'mdep' (the second argument to uadmin(2)) is initialized for A_REBOOT,
 * A_SHUTDOWN or A_DUMP, it represents the boot arguments string of at most
 * 256 characters.
 */
#define	BOOTARGS_MAX	256

#if !defined(_ASM)

#if defined(_KERNEL)
extern kmutex_t ualock;
extern boolean_t mdboot_invoke_cb;
extern void mdboot(int, int, char *);
extern void mdpreboot(int, int, char *);
extern int kadmin(int, int, void *, cred_t *);
extern void killall(zoneid_t);
#endif

#if defined(__STDC__)
extern int uadmin(int, int, uintptr_t);
#else
extern int uadmin();
#endif

#endif	/* _ASM */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_UADMIN_H */
