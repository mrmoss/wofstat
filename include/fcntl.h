/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef	_FCNTL_H
#define	_FCNTL_H

#pragma ident	"@(#)fcntl.h	1.17	06/03/10 SMI"	/* SVr4.0 1.6.1.7 */

#include <sys/feature_tests.h>
#if defined(__EXTENSIONS__) || defined(_XPG4)
#include <sys/stat.h>
#endif
#include <sys/types.h>
#include <sys/fcntl.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if defined(__EXTENSIONS__) || defined(_XPG4)

/* Symbolic constants for the "lseek" routine. */

#ifndef	SEEK_SET
#define	SEEK_SET	0	/* Set file pointer to "offset" */
#endif

#ifndef	SEEK_CUR
#define	SEEK_CUR	1	/* Set file pointer to current plus "offset" */
#endif

#ifndef	SEEK_END
#define	SEEK_END	2	/* Set file pointer to EOF plus "offset" */
#endif
#endif /* defined(__EXTENSIONS__) || defined(_XPG4) */

#if !defined(__XOPEN_OR_POSIX) || defined(__EXTENSIONS__)
#ifndef	SEEK_DATA
#define	SEEK_DATA	3	/* Set file pointer to next data past offset */
#endif

#ifndef	SEEK_HOLE
#define	SEEK_HOLE	4	/* Set file pointer to next hole past offset */
#endif
#endif /* !defined(__XOPEN_OR_POSIX) || defined(__EXTENSIONS__) */

/* large file compilation environment setup */
#if !defined(_LP64) && _FILE_OFFSET_BITS == 64
#ifdef __PRAGMA_REDEFINE_EXTNAME
#pragma redefine_extname	open	open64
#pragma redefine_extname	creat	creat64
#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) || \
	defined(_ATFILE_SOURCE)
#pragma redefine_extname	openat	openat64
#pragma	redefine_extname	attropen attropen64
#endif /* defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) ... */
#else
#define	open			open64
#define	creat			creat64
#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) || \
	defined(_ATFILE_SOURCE)
#define	openat			openat64
#define	attropen		attropen64
#endif /* defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) ... */
#endif
#endif	/* !_LP64 && _FILE_OFFSET_BITS == 64 */

#if defined(_LP64) && defined(_LARGEFILE64_SOURCE)
#ifdef __PRAGMA_REDEFINE_EXTNAME
#pragma	redefine_extname	open64	open
#pragma	redefine_extname	creat64	creat
#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) || \
	defined(_ATFILE_SOURCE)
#pragma	redefine_extname	openat64	openat
#pragma	redefine_extname	attropen64	attropen
#endif /* defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) ... */
#else
#define	open64				open
#define	creat64				creat
#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) || \
	defined(_ATFILE_SOURCE)
#define	openat64			openat
#define	attropen64			attropen
#endif /* defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) ... */
#endif
#endif	/* _LP64 && _LARGEFILE64_SOURCE */

#if defined(__STDC__)

extern int fcntl(int, int, ...);
extern int open(const char *, int, ...);
extern int creat(const char *, mode_t);
#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) || \
	defined(_ATFILE_SOURCE)
extern int openat(int, const char *, int, ...);
extern int attropen(const char *, const char *, int, ...);
#endif /* defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) ... */
#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX)
extern int directio(int, int);
#endif

/* transitional large file interface versions */
#if	defined(_LARGEFILE64_SOURCE) && !((_FILE_OFFSET_BITS == 64) && \
	    !defined(__PRAGMA_REDEFINE_EXTNAME))
extern int open64(const char *, int, ...);
extern int creat64(const char *, mode_t);
#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) || \
	defined(_ATFILE_SOURCE)
extern int openat64(int, const char *, int, ...);
extern int attropen64(const char *, const char *, int, ...);
#endif /* defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) ... */
#endif

#else	/* defined(__STDC__) */

extern int fcntl();
extern int open();
extern int creat();
#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) || \
	defined(_ATFILE_SOURCE)
extern int openat();
extern int attropen();
#endif /* defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) ... */

#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX)
extern int directio();
#endif

/* transitional large file interface versions */
#if	defined(_LARGEFILE64_SOURCE) && !((_FILE_OFFSET_BITS == 64) && \
	    !defined(__PRAGMA_REDEFINE_EXTNAME))
extern int open64();
extern int creat64();
#if defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) || \
	defined(_ATFILE_SOURCE)
extern int openat64();
extern int attropen64();
#endif /* defined(__EXTENSIONS__) || !defined(__XOPEN_OR_POSIX) ... */
#endif

#endif	/* defined(__STDC__) */

#ifdef	__cplusplus
}
#endif

#endif	/* _FCNTL_H */
