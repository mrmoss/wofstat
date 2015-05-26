/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_OBJFS_H
#define	_OBJFS_H

#pragma ident	"@(#)objfs.h	1.1	04/08/29 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Root directory of the object filesystem
 */
#define	OBJFS_ROOT	"/system/object"

/*
 * Given an inode number, return the module ID for the given node.  When given
 * the root inode, the results are undefined.
 */
#define	OBJFS_MODID(ino)	\
	((ino) & 0xffffffff)

/*
 * Private data structure found in '.info' section
 */
typedef struct objfs_info {
	int		objfs_info_primary;
} objfs_info_t;

#ifdef	__cplusplus
}
#endif

#endif	/* _OBJFS_H */
