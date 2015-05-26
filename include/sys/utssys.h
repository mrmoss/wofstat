/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_UTSSYS_H
#define	_SYS_UTSSYS_H

#pragma ident	"@(#)utssys.h	1.12	03/10/10 SMI"	/* SVr4.0 1.1 */

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Definitions related to the utssys() system call.
 */

/*
 * "commands" of utssys
 */
#define	UTS_UNAME	0x0	/* obsolete */
#define	UTS_USTAT	0x2	/* 1 was umask */
#define	UTS_FUSERS	0x3

/*
 * Flags to UTS_FUSERS
 */
#define	F_FILE_ONLY	0x01
#define	F_CONTAINED	0x02
#define	F_NBMANDLIST	0x04	/* Only NBMAND locks users */
#define	F_DEVINFO	0x08	/* get device usage info for a dip instead */
				/* of a minor node */
#define	F_KINFO_COUNT	0x10	/* get the current number of kernel */
				/* device consumers */

/*
 * structures yielded by UTS_FUSERS
 */
typedef struct f_user {
	int	fu_flags;	/* see below */
	union {
		struct {
			pid_t	u_pid;
			uid_t	u_uid;
		} u_info;
		struct {
			int	k_modid;
			int	k_instance;
			int	k_minor;
		} k_info;
	} fu_info;
} f_user_t;

typedef struct fu_data {
	int		fud_user_max;
	int		fud_user_count;
	struct f_user	fud_user[1];
} fu_data_t;

/*
 * defines to simplify access to members of the f_user_t structure
 */
#define	fu_pid		fu_info.u_info.u_pid
#define	fu_uid		fu_info.u_info.u_uid

#define	fu_modid	fu_info.k_info.k_modid
#define	fu_instance	fu_info.k_info.k_instance
#define	fu_minor	fu_info.k_info.k_minor

#define	fu_data_size(x)	(sizeof (fu_data_t) - sizeof (f_user_t) + \
				((x) * sizeof (f_user_t)))

/*
 * fu_flags values
 */
#define	F_CDIR		0x1
#define	F_RDIR		0x2
#define	F_TEXT		0x4
#define	F_MAP		0x8
#define	F_OPEN		0x10
#define	F_TRACE		0x20
#define	F_TTY		0x40
#define	F_NBM		0x80	/* NBMAND lock in place */
#define	F_KERNEL	0x80000000

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_UTSSYS_H */
