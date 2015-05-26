/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef _SYS_FILIO_H
#define	_SYS_FILIO_H

#pragma ident	"@(#)filio.h	1.38	08/06/06 SMI"	/* SVr4.0 1.4	*/

/*	filio.h 1.3 88/02/08 SMI; from UCB ioctl.h 7.1 6/4/86	*/

/*
 *		PROPRIETARY NOTICE (Combined)
 *
 *  This source code is unpublished proprietary information
 *  constituting, or derived under license from AT&T's Unix(r) System V.
 *  In addition, portions of such source code were derived from Berkeley
 *  4.3 BSD under license from the Regents of the University of
 *  California.
 *
 *
 *
 *		Copyright Notice
 *
 *  Notice of copyright on this source code product does not indicate
 *  publication.
 *
 *	(c) 1983,1984,1985,1986,1987,1988,1989  AT&T.
 *		All rights reserved.
 */

/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*
 * General file ioctl definitions.
 */

#include <sys/ioccom.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	FIOCLEX		_IO('f', 1)		/* set exclusive use on fd */
#define	FIONCLEX	_IO('f', 2)		/* remove exclusive use */
/* another local */
#define	FIONREAD	_IOR('f', 127, int)	/* get # bytes to read */
#define	FIONBIO		_IOW('f', 126, int)	/* set/clear non-blocking i/o */
#define	FIOASYNC	_IOW('f', 125, int)	/* set/clear async i/o */
#define	FIOSETOWN	_IOW('f', 124, int)	/* set owner */
#define	FIOGETOWN	_IOR('f', 123, int)	/* get owner */

/*
 * ioctl's for Online: DiskSuite.
 * WARNING - the support for these ioctls may be withdrawn
 * in future OS releases.
 */
#define	_FIOLFS		_IO('f', 64)		/* file system lock */
#define	_FIOLFSS	_IO('f', 65)		/* file system lock status */
#define	_FIOFFS		_IO('f', 66)		/* file system flush */
#define	_FIOAI		_FIOOBSOLETE67		/* get allocation info is */
#define	_FIOOBSOLETE67	_IO('f', 67)		/* obsolete and unsupported */
#define	_FIOSATIME	_IO('f', 68)		/* set atime */
#define	_FIOSDIO	_IO('f', 69)		/* set delayed io */
#define	_FIOGDIO	_IO('f', 70)		/* get delayed io */
#define	_FIOIO		_IO('f', 71)		/* inode open */
#define	_FIOISLOG	_IO('f', 72)		/* disksuite/ufs protocol */
#define	_FIOISLOGOK	_IO('f', 73)		/* disksuite/ufs protocol */
#define	_FIOLOGRESET	_IO('f', 74)		/* disksuite/ufs protocol */

/*
 * Contract-private ioctl()
 */
#define	_FIOISBUSY	_IO('f', 75)		/* networker/ufs protocol */
#define	_FIODIRECTIO	_IO('f', 76)		/* directio */
#define	_FIOTUNE	_IO('f', 77)		/* tuning */

/*
 * WARNING: These 'f' ioctls are also defined in sys/fs/cachefs_fs.h
 * It currently defines 78-86.
 */

/*
 * Internal Logging UFS
 */
#define	_FIOLOGENABLE	_IO('f', 87)		/* logging/ufs protocol */
#define	_FIOLOGDISABLE	_IO('f', 88)		/* logging/ufs protocol */

/*
 * File system snapshot ioctls (see sys/fs/ufs_snap.h)
 * (there is another snapshot ioctl, _FIOSNAPSHOTCREATE_MULTI,
 * defined farther down in this file.)
 */
#define	_FIOSNAPSHOTCREATE	_IO('f', 89)	/* create a snapshot */
#define	_FIOSNAPSHOTDELETE	_IO('f', 90)	/* delete a snapshot */

/*
 * Return the current superblock of size SBSIZE
 */
#define	_FIOGETSUPERBLOCK	_IO('f', 91)

/*
 * Contract private ioctl
 */
#define	_FIOGETMAXPHYS		_IO('f', 92)

/*
 * TSufs support
 */
#define	_FIO_SET_LUFS_DEBUG	_IO('f', 93) /* set lufs_debug */
#define	_FIO_SET_LUFS_ERROR	_IO('f', 94) /* set a lufs error */
#define	_FIO_GET_TOP_STATS	_IO('f', 95) /* get lufs tranaction stats */

/*
 * create a snapshot with multiple backing files
 */
#define	_FIOSNAPSHOTCREATE_MULTI	_IO('f', 96)

/*
 * handle lseek SEEK_DATA and SEEK_HOLE for holey file knowledge
 */
#define	_FIO_SEEK_DATA		_IO('f', 97) /* SEEK_DATA */
#define	_FIO_SEEK_HOLE		_IO('f', 98) /* SEEK_HOLE */

/*
 * boot archive compression
 */
#define	_FIO_COMPRESSED		_IO('f', 99) /* mark file as compressed */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_FILIO_H */
