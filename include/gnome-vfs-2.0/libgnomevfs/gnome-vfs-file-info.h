/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/* gnome-vfs-file-info.h - Handling of file information for the GNOME
   Virtual File System.

   Copyright (C) 1999,2001 Free Software Foundation
   Copyright (C) 2002 Seth Nickell

   The Gnome Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Gnome Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Gnome Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Author: Ettore Perazzoli <ettore@comm2000.it> 
           Seth Nickell <snickell@stanford.edu>
*/

#ifndef GNOME_VFS_FILE_INFO_H
#define GNOME_VFS_FILE_INFO_H

#include <libgnomevfs/gnome-vfs-file-size.h>
#include <libgnomevfs/gnome-vfs-result.h>
#include <libgnomevfs/gnome-vfs-uri.h>
#include <libgnomevfs/gnome-vfs-acl.h>
#include <sys/stat.h>
#include <sys/types.h>

G_BEGIN_DECLS

/**
 * GnomeVFSInodeNumber:
 *
 * Represents the i-node of a file, this is a low level data structure
 * that the operating system uses to hold information about a file.
 **/

typedef GnomeVFSFileSize GnomeVFSInodeNumber;

/**
 * GnomeVFSFileFlags:
 * @GNOME_VFS_FILE_FLAGS_NONE: no flags
 * @GNOME_VFS_FILE_FLAGS_SYMLINK: whether the file is a symlink.
 * @GNOME_VFS_FILE_FLAGS_LOCAL: whether the file is on a local filesystem
 *
 * Packed boolean bitfield representing special
 * flags a #GnomeVFSFileInfo struct can have.
 **/
typedef enum {
	GNOME_VFS_FILE_FLAGS_NONE = 0,
	GNOME_VFS_FILE_FLAGS_SYMLINK = 1 << 0,
	GNOME_VFS_FILE_FLAGS_LOCAL = 1 << 1
} GnomeVFSFileFlags;

/**
 * GnomeVFSFileType:
 * @GNOME_VFS_FILE_TYPE_UNKNOWN:
 * @GNOME_VFS_FILE_TYPE_REGULAR:
 * @GNOME_VFS_FILE_TYPE_DIRECTORY:
 * @GNOME_VFS_FILE_TYPE_FIFO:
 * @GNOME_VFS_FILE_TYPE_SOCKET:
 * @GNOME_VFS_FILE_TYPE_CHARACTER_DEVICE:
 * @GNOME_VFS_FILE_TYPE_BLOCK_DEVICE:
 * @GNOME_VFS_FILE_TYPE_SYMBOLIC_LINK:
 *
 * Identifies the kind of file represented by a #GnomeVFSFileInfo struct. (note,
 * use of MIME types is preferred as this field may eventually disappear)
 **/

typedef enum {
	GNOME_VFS_FILE_TYPE_UNKNOWN,
	GNOME_VFS_FILE_TYPE_REGULAR,
	GNOME_VFS_FILE_TYPE_DIRECTORY,
	GNOME_VFS_FILE_TYPE_FIFO,
	GNOME_VFS_FILE_TYPE_SOCKET,
	GNOME_VFS_FILE_TYPE_CHARACTER_DEVICE,
	GNOME_VFS_FILE_TYPE_BLOCK_DEVICE,
	GNOME_VFS_FILE_TYPE_SYMBOLIC_LINK
} GnomeVFSFileType;

/**
 * GnomeVFSFileInfoFields:
 * @GNOME_VFS_FILE_INFO_FIELDS_NONE: No fields are valid
 * @GNOME_VFS_FILE_INFO_FIELDS_TYPE: Type field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_PERMISSIONS: Permissions field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_FLAGS: Flags field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_DEVICE: Device field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_INODE: Inode field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_LINK_COUNT: Link count field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_SIZE: Size field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_BLOCK_COUNT: Block count field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_IO_BLOCK_SIZE: I/O Block Size field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_ATIME: Access time field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_MTIME: Modification time field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_CTIME: Creating time field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_SYMLINK_NAME: Symlink name field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_MIME_TYPE: Mime type field is valid
 * @GNOME_VFS_FILE_INFO_FIELDS_ACCESS: Access bits of the permissions
 * bitfield are valid
 *
 * Flags indicating what fields in a GnomeVFSFileInfo struct are valid. 
 * Name is always assumed valid (how else would you have gotten a
 * FileInfo struct otherwise?)
 **/

typedef enum {
	GNOME_VFS_FILE_INFO_FIELDS_NONE = 0,
	GNOME_VFS_FILE_INFO_FIELDS_TYPE = 1 << 0,
	GNOME_VFS_FILE_INFO_FIELDS_PERMISSIONS = 1 << 1,
	GNOME_VFS_FILE_INFO_FIELDS_FLAGS = 1 << 2,
	GNOME_VFS_FILE_INFO_FIELDS_DEVICE = 1 << 3,
	GNOME_VFS_FILE_INFO_FIELDS_INODE = 1 << 4,
	GNOME_VFS_FILE_INFO_FIELDS_LINK_COUNT = 1 << 5,
	GNOME_VFS_FILE_INFO_FIELDS_SIZE = 1 << 6,
	GNOME_VFS_FILE_INFO_FIELDS_BLOCK_COUNT = 1 << 7,
	GNOME_VFS_FILE_INFO_FIELDS_IO_BLOCK_SIZE = 1 << 8,
	GNOME_VFS_FILE_INFO_FIELDS_ATIME = 1 << 9,
	GNOME_VFS_FILE_INFO_FIELDS_MTIME = 1 << 10,
	GNOME_VFS_FILE_INFO_FIELDS_CTIME = 1 << 11,
	GNOME_VFS_FILE_INFO_FIELDS_SYMLINK_NAME = 1 << 12,
	GNOME_VFS_FILE_INFO_FIELDS_MIME_TYPE = 1 << 13,
	GNOME_VFS_FILE_INFO_FIELDS_ACCESS = 1 << 14,
	GNOME_VFS_FILE_INFO_FIELDS_ACL = 1 << 16
} GnomeVFSFileInfoFields;	


/* FIXME: It's silly to use the symbolic constants for POSIX here.
 * This is supposed to be a virtual file system, so it makes no
 * sense to use the values of the POSIX-required constants on the
 * particular machine this code is compiled on. These should all be changed
 * to use numeric constants like GNOME_VFS_PERM_STICKY does now. However,
 * be careful in making such a change, since some existing code might
 * wrongly assume these equivalencies.
 */

/**
 * GnomeVFSFilePermissions:
 * @GNOME_VFS_PERM_SUID: UID bit
 * @GNOME_VFS_PERM_SGID: GID bit
 * @GNOME_VFS_PERM_STICKY: Sticky bit.
 * @GNOME_VFS_PERM_USER_READ: Owner has read permission
 * @GNOME_VFS_PERM_USER_WRITE: Owner has write permission
 * @GNOME_VFS_PERM_USER_EXEC: Owner has execution permission
 * @GNOME_VFS_PERM_USER_ALL: Owner has all permissions
 * @GNOME_VFS_PERM_GROUP_READ: Group has read permission
 * @GNOME_VFS_PERM_GROUP_WRITE: Group has write permission
 * @GNOME_VFS_PERM_GROUP_EXEC: Group has execution permission
 * @GNOME_VFS_PERM_GROUP_ALL: Group has all permissions
 * @GNOME_VFS_PERM_OTHER_READ: Others have read permission
 * @GNOME_VFS_PERM_OTHER_WRITE: Others have write permission
 * @GNOME_VFS_PERM_OTHER_EXEC: Others have execution permission
 * @GNOME_VFS_PERM_OTHER_ALL: Others have all permissions
 * @GNOME_VFS_PERM_ACCESS_READABLE:
 * @GNOME_VFS_PERM_ACCESS_WRITABLE:
 * @GNOME_VFS_PERM_ACCESS_EXECUTABLE:
 *
 * File permissions. These are the same as the Unix ones, but we wrap them
 * into a nicer VFS-like enum.  
 **/
typedef enum {
	GNOME_VFS_PERM_SUID = S_ISUID,
	GNOME_VFS_PERM_SGID = S_ISGID,	
	GNOME_VFS_PERM_STICKY = 01000,	/* S_ISVTX not defined on all systems */
	GNOME_VFS_PERM_USER_READ = S_IRUSR,
	GNOME_VFS_PERM_USER_WRITE = S_IWUSR,
	GNOME_VFS_PERM_USER_EXEC = S_IXUSR,
	GNOME_VFS_PERM_USER_ALL = S_IRUSR | S_IWUSR | S_IXUSR,
	GNOME_VFS_PERM_GROUP_READ = S_IRGRP,
	GNOME_VFS_PERM_GROUP_WRITE = S_IWGRP,
	GNOME_VFS_PERM_GROUP_EXEC = S_IXGRP,
	GNOME_VFS_PERM_GROUP_ALL = S_IRGRP | S_IWGRP | S_IXGRP,
	GNOME_VFS_PERM_OTHER_READ = S_IROTH,
	GNOME_VFS_PERM_OTHER_WRITE = S_IWOTH,
	GNOME_VFS_PERM_OTHER_EXEC = S_IXOTH,
	GNOME_VFS_PERM_OTHER_ALL = S_IROTH | S_IWOTH | S_IXOTH,
	GNOME_VFS_PERM_ACCESS_READABLE   = 1 << 16,
	GNOME_VFS_PERM_ACCESS_WRITABLE   = 1 << 17,
	GNOME_VFS_PERM_ACCESS_EXECUTABLE = 1 << 18
} GnomeVFSFilePermissions;


/**
 * GnomeVFSFileInfo:
 * 
 * The GnomeVFSFileInfo structure contains information about a file.
 **/
typedef struct {
	/* Base name of the file (no path).  */
	char *name;

	/* Fields which are actually valid in this structure. */
	GnomeVFSFileInfoFields valid_fields;

	/* File type (i.e. regular, directory, block device...).  */
	GnomeVFSFileType type;

	/* File permissions.  */
	GnomeVFSFilePermissions permissions;

	/* Flags for this file.  */
	GnomeVFSFileFlags flags;

	/* These are only valid if `is_local' is TRUE (see below).  */
	dev_t device;
	GnomeVFSInodeNumber inode;

	/* Link count.  */
	guint link_count;

	/* UID, GID.  */
	guint uid;
	guint gid;

	/* Size in bytes.  */
	GnomeVFSFileSize size;

	/* Size measured in units of 512-byte blocks.  */
	GnomeVFSFileSize block_count;

	/* Optimal buffer size for reading/writing the file.  */
	guint io_block_size;

	/* Access, modification and change times.  */
	time_t atime;
	time_t mtime;
	time_t ctime;

	/* If the file is a symlink (see `flags'), this specifies the file the
           link points to.  */
	char *symlink_name;

	/* MIME type.  -- ascii string */
	char *mime_type;

	guint refcount;

	/* File ACLs */
	GnomeVFSACL *acl;

	/* Reserved for future expansions to GnomeVFSFileInfo without having
	   to break ABI compatibility */
	void *reserved1;
	void *reserved2;
	void *reserved3;
	void *reserved4;
} GnomeVFSFileInfo;

/**
 * GnomeVFSFileInfoOptions:
 * @GNOME_VFS_FILE_INFO_DEFAULT: default flags
 * @GNOME_VFS_FILE_INFO_GET_MIME_TYPE: detect the MIME type
 * @GNOME_VFS_FILE_INFO_FORCE_FAST_MIME_TYPE: only use fast MIME type 
 * detection (extensions)
 * @GNOME_VFS_FILE_INFO_FORCE_SLOW_MIME_TYPE: force slow MIME type 
 * detection where available (sniffing, algorithmic detection, etc)
 * @GNOME_VFS_FILE_INFO_FOLLOW_LINKS: automatically follow symbolic 
 * links and retrieve the properties of their target (recommended)
 * @GNOME_VFS_FILE_INFO_GET_ACCESS_RIGHTS: tries to get data similar 
 * to what would return access(2) on a local file system (ie is the 
 * file readable, writable and/or executable). Can be really slow on 
 * remote file systems
 *
 * Packed boolean bitfield representing options that can
 * be passed into a gnome_vfs_get_file_info() call (or other
 * related calls that return file info) and affect the operation
 * of get_file_info.
 **/

typedef enum {
	GNOME_VFS_FILE_INFO_DEFAULT = 0,
	GNOME_VFS_FILE_INFO_GET_MIME_TYPE = 1 << 0,
	GNOME_VFS_FILE_INFO_FORCE_FAST_MIME_TYPE = 1 << 1,
	GNOME_VFS_FILE_INFO_FORCE_SLOW_MIME_TYPE = 1 << 2,
	GNOME_VFS_FILE_INFO_FOLLOW_LINKS = 1 << 3,
	GNOME_VFS_FILE_INFO_GET_ACCESS_RIGHTS = 1 << 4,
	GNOME_VFS_FILE_INFO_GET_ACL = 1 << 5
} GnomeVFSFileInfoOptions;

/**
 * GnomeVFSSetFileInfoMask:
 * @GNOME_VFS_SET_FILE_INFO_NONE: don't set any file info fields
 * @GNOME_VFS_SET_FILE_INFO_NAME: change the name
 * @GNOME_VFS_SET_FILE_INFO_PERMISSIONS: change the permissions
 * @GNOME_VFS_SET_FILE_INFO_OWNER: change the file's owner
 * @GNOME_VFS_SET_FILE_INFO_TIME: change the file's time stamp(s)
 *
 * Packed boolean bitfield representing the aspects of the file
 * to be changed in a gnome_vfs_set_file_info() call.
 **/

typedef enum {
	GNOME_VFS_SET_FILE_INFO_NONE = 0,
	GNOME_VFS_SET_FILE_INFO_NAME = 1 << 0,
	GNOME_VFS_SET_FILE_INFO_PERMISSIONS = 1 << 1,
	GNOME_VFS_SET_FILE_INFO_OWNER = 1 << 2,
	GNOME_VFS_SET_FILE_INFO_TIME = 1 << 3,
	GNOME_VFS_SET_FILE_INFO_ACL = 1 << 4
} GnomeVFSSetFileInfoMask;

typedef struct {
	GnomeVFSURI *uri;
	GnomeVFSResult result;
	GnomeVFSFileInfo *file_info;
} GnomeVFSGetFileInfoResult;

/**
 * GNOME_VFS_FILE_INFO_SYMLINK:
 * @info: GnomeVFSFileInfo struct
 *
 * Determines whether a file is a symbolic link given @info.
 */
#define GNOME_VFS_FILE_INFO_SYMLINK(info)		\
	((info)->flags & GNOME_VFS_FILE_FLAGS_SYMLINK)

/**
 * GNOME_VFS_FILE_INFO_SET_SYMLINK:
 * @info: GnomeVFSFileInfo struct
 * @value: if %TRUE, @info is set to indicate the file is a symbolic link
 *
 * Set the symbolic link field in @info to @value.
 */
#define GNOME_VFS_FILE_INFO_SET_SYMLINK(info, value)			\
	(value ? ((info)->flags |= GNOME_VFS_FILE_FLAGS_SYMLINK)	\
	       : ((info)->flags &= ~GNOME_VFS_FILE_FLAGS_SYMLINK))

/**
 * GNOME_VFS_FILE_INFO_LOCAL:
 * @info: GnomeVFSFileInfo struct
 *
 * Determines whether a file is local given @info.
 */
#define GNOME_VFS_FILE_INFO_LOCAL(info)			\
	((info)->flags & GNOME_VFS_FILE_FLAGS_LOCAL)

/**
 * GNOME_VFS_FILE_INFO_SET_LOCAL:
 * @info: GnomeVFSFileInfo struct
 * @value: if %TRUE, @info is set to indicate the file is local
 *
 * Set the "local file" field in @info to @value.
 */
#define GNOME_VFS_FILE_INFO_SET_LOCAL(info, value)			\
	(value ? ((info)->flags |= GNOME_VFS_FILE_FLAGS_LOCAL)		\
	       : ((info)->flags &= ~GNOME_VFS_FILE_FLAGS_LOCAL))


/**
 * GNOME_VFS_FILE_INFO_SUID:
 * @info: GnomeVFSFileInfo struct
 *
 * Determines whether a file belongs to the super user.
 */
#define GNOME_VFS_FILE_INFO_SUID(info)			\
	((info)->permissions & GNOME_VFS_PERM_SUID)

/**
 * GNOME_VFS_FILE_INFO_SGID:
 * @info: GnomeVFSFileInfo struct
 *
 * Determines whether a file belongs to the super user's group.
 */
#define GNOME_VFS_FILE_INFO_SGID(info)			\
	((info)->permissions & GNOME_VFS_PERM_SGID)

/**
 * GNOME_VFS_FILE_INFO_STICKY:
 * @info: GnomeVFSFileInfo struct
 *
 * Determines whether a file has the sticky bit set, given @info
 */
#define GNOME_VFS_FILE_INFO_STICKY(info)		\
	((info)->permissions & GNOME_VFS_PERM_STICKY)

/**
 * GNOME_VFS_FILE_INFO_SET_SUID:
 * @info: GnomeVFSFileInfo struct
 * @value: if %TRUE, @info is set to indicate the file belongs to the super user
 *
 * Set the SUID field in @info to @value.
 */
#define GNOME_VFS_FILE_INFO_SET_SUID(info, value)		\
	(value ? ((info)->permissions |= GNOME_VFS_PERM_SUID)	\
	       : ((info)->permissions &= ~GNOME_VFS_PERM_SUID))

/**
 * GNOME_VFS_FILE_INFO_SET_SGID:
 * @info: GnomeVFSFileInfo struct
 * @value: if %TRUE, @info is set to indicate the file belongs to the super user's group
 *
 * Set the SGID field in @info to @value.
 */
#define GNOME_VFS_FILE_INFO_SET_SGID(info, value)		\
	(value ? ((info)->permissions |= GNOME_VFS_PERM_SGID)	\
	       : ((info)->permissions &= ~GNOME_VFS_PERM_SGID))
/**
 * GNOME_VFS_FILE_INFO_SET_STICKY:
 * @info: GnomeVFSFileInfo struct
 * @value: if %TRUE, @info is set to indicate the file has the sticky bit set
 *
 * Set the sticky bit in @info to @value.
 */
#define GNOME_VFS_FILE_INFO_SET_STICKY(info, value)			\
	(value ? ((info)->permissions |= GNOME_VFS_PERM_STICKY)		\
	       : ((info)->permissions &= ~GNOME_VFS_PERM_STICKY))



GnomeVFSFileInfo *gnome_vfs_file_info_new           (void);
void              gnome_vfs_file_info_unref         (GnomeVFSFileInfo       *info);
void              gnome_vfs_file_info_ref           (GnomeVFSFileInfo       *info);
void              gnome_vfs_file_info_clear         (GnomeVFSFileInfo       *info);
const char *      gnome_vfs_file_info_get_mime_type (GnomeVFSFileInfo       *info);
void              gnome_vfs_file_info_copy          (GnomeVFSFileInfo       *dest,
						     const GnomeVFSFileInfo *src);
GnomeVFSFileInfo *gnome_vfs_file_info_dup           (const GnomeVFSFileInfo *orig);
gboolean          gnome_vfs_file_info_matches       (const GnomeVFSFileInfo *a,
						     const GnomeVFSFileInfo *b);
GList *           gnome_vfs_file_info_list_ref      (GList                  *list);
GList *           gnome_vfs_file_info_list_unref    (GList                  *list);
GList *           gnome_vfs_file_info_list_copy     (GList                  *list);
void              gnome_vfs_file_info_list_free     (GList                  *list);

G_END_DECLS

#endif /* GNOME_VFS_FILE_INFO_H */
