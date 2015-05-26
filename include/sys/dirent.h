/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_DIRENT_H
#define	_SYS_DIRENT_H

#pragma ident	"@(#)dirent.h	1.36	04/09/28 SMI"	/* SVr4.0 11.11 */

#include <sys/feature_tests.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * File-system independent directory entry.
 */
typedef struct dirent {
	ino_t		d_ino;		/* "inode number" of entry */
	off_t		d_off;		/* offset of disk directory entry */
	unsigned short	d_reclen;	/* length of this record */
	char		d_name[1];	/* name of file */
} dirent_t;

#if defined(_SYSCALL32)

/* kernel's view of user ILP32 dirent */

typedef	struct dirent32 {
	ino32_t		d_ino;		/* "inode number" of entry */
	off32_t		d_off;		/* offset of disk directory entry */
	uint16_t	d_reclen;	/* length of this record */
	char		d_name[1];	/* name of file */
} dirent32_t;

#endif	/* _SYSCALL32 */

#ifdef	_LARGEFILE64_SOURCE

/*
 * transitional large file interface version AND kernel internal version
 */
typedef struct dirent64 {
	ino64_t		d_ino;		/* "inode number" of entry */
	off64_t		d_off;		/* offset of disk directory entry */
	unsigned short	d_reclen;	/* length of this record */
	char		d_name[1];	/* name of file */
} dirent64_t;

#endif	/* _LARGEFILE64_SOURCE */

#if !defined(__XOPEN_OR_POSIX) || defined(__EXTENSIONS__)
#if defined(_KERNEL)
#define	DIRENT64_RECLEN(namelen)	\
	((offsetof(dirent64_t, d_name[0]) + 1 + (namelen) + 7) & ~ 7)
#define	DIRENT64_NAMELEN(reclen)	\
	((reclen) - (offsetof(dirent64_t, d_name[0])))
#define	DIRENT32_RECLEN(namelen)	\
	((offsetof(dirent32_t, d_name[0]) + 1 + (namelen) + 3) & ~ 3)
#define	DIRENT32_NAMELEN(reclen)	\
	((reclen) - (offsetof(dirent32_t, d_name[0])))
#endif

#if !defined(_KERNEL)

/*
 * large file compilation environment setup
 *
 * In the LP64 compilation environment, map large file interfaces
 * back to native versions where possible. (This only works because
 * a 'struct dirent' == 'struct dirent64').
 */

#if !defined(_LP64) && _FILE_OFFSET_BITS == 64
#ifdef	__PRAGMA_REDEFINE_EXTNAME
#pragma redefine_extname	getdents	getdents64
#else
#define	getdents		getdents64
#endif
#endif	/* !_LP64 && _FILE_OFFSET_BITS == 64 */

#if defined(_LP64) && defined(_LARGEFILE64_SOURCE)
#ifdef	__PRAGMA_REDEFINE_EXTNAME
#pragma	redefine_extname	getdents64	getdents
#else
#define	getdents64		getdents
#define	dirent64		dirent
#define	dirent64_t		dirent_t
#endif
#endif	/* _LP64 && _LARGEFILE64_SOURCE */

#if defined(__STDC__)
extern int getdents(int, struct dirent *, size_t);
#else
extern int getdents();
#endif

/* N.B.: transitional large file interface version deliberately not provided */

#endif /* !defined(_KERNEL) */
#endif /* !defined(__XOPEN_OR_POSIX) || defined(__EXTENSIONS__) */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DIRENT_H */
