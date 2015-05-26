/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/* gnome-vfs-directory.h - Directory handling for the GNOME Virtual
   File System.

   Copyright (C) 1999 Free Software Foundation

   The Gnome Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Gnome Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Gnome Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Author: Ettore Perazzoli <ettore@comm2000.it> */

#ifndef GNOME_VFS_DIRECTORY_H
#define GNOME_VFS_DIRECTORY_H

#include <glib/gmacros.h>
#include <libgnomevfs/gnome-vfs-file-info.h>

G_BEGIN_DECLS

typedef struct GnomeVFSDirectoryHandle GnomeVFSDirectoryHandle;

/**
 * GnomeVFSDirectoryVisitOptions:
 * @GNOME_VFS_DIRECTORY_VISIT_DEFAULT: 
 * @GNOME_VFS_DIRECTORY_VISIT_SAMEFS: Visit only directories on the same 
 * file system as the parent
 * @GNOME_VFS_DIRECTORY_VISIT_LOOPCHECK: Loop prevention
 *
 * This options control the way in which directories are visited.
 **/

typedef enum {
	GNOME_VFS_DIRECTORY_VISIT_DEFAULT = 0,
	GNOME_VFS_DIRECTORY_VISIT_SAMEFS = 1 << 0,
	GNOME_VFS_DIRECTORY_VISIT_LOOPCHECK = 1 << 1
} GnomeVFSDirectoryVisitOptions;

typedef gboolean (* GnomeVFSDirectoryVisitFunc)	 (const gchar *rel_path,
						  GnomeVFSFileInfo *info,
						  gboolean recursing_will_loop,
						  gpointer data,
						  gboolean *recurse);

GnomeVFSResult	gnome_vfs_directory_open
					(GnomeVFSDirectoryHandle **handle,
					 const gchar              *text_uri,
					 GnomeVFSFileInfoOptions   options);
GnomeVFSResult	gnome_vfs_directory_open_from_uri
					(GnomeVFSDirectoryHandle **handle,
					 GnomeVFSURI              *uri,
					 GnomeVFSFileInfoOptions   options);
GnomeVFSResult	gnome_vfs_directory_read_next
					(GnomeVFSDirectoryHandle  *handle,
					 GnomeVFSFileInfo         *file_info);
GnomeVFSResult	gnome_vfs_directory_close
					(GnomeVFSDirectoryHandle  *handle);


GnomeVFSResult  gnome_vfs_directory_visit
					(const gchar *uri,
					 GnomeVFSFileInfoOptions info_options,
					 GnomeVFSDirectoryVisitOptions visit_options,
					 GnomeVFSDirectoryVisitFunc callback,
					 gpointer data);

GnomeVFSResult  gnome_vfs_directory_visit_uri
					(GnomeVFSURI *uri,
					 GnomeVFSFileInfoOptions info_options,
					 GnomeVFSDirectoryVisitOptions visit_options,
					 GnomeVFSDirectoryVisitFunc callback,
					 gpointer data);

GnomeVFSResult	gnome_vfs_directory_visit_files
					(const gchar *text_uri,
					 GList *file_list,
					 GnomeVFSFileInfoOptions info_options,
					 GnomeVFSDirectoryVisitOptions visit_options,
					 GnomeVFSDirectoryVisitFunc callback,
					 gpointer data);

GnomeVFSResult	gnome_vfs_directory_visit_files_at_uri
					(GnomeVFSURI *uri,
					 GList *file_list,
					 GnomeVFSFileInfoOptions info_options,
					 GnomeVFSDirectoryVisitOptions visit_options,
					 GnomeVFSDirectoryVisitFunc callback,
					 gpointer data);

GnomeVFSResult gnome_vfs_directory_list_load
					(GList **list,
				         const gchar *text_uri,
				         GnomeVFSFileInfoOptions options);

G_END_DECLS

#endif
