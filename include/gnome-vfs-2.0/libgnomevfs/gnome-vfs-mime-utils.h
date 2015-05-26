/*
 * Copyright (C) 1997-2001 Free Software Foundation
 * Copyright (C) 2000, 2001 Eazel, Inc.
 * All rights reserved.
 *
 * This file is part of the Gnome Library.
 *
 * The Gnome Library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * The Gnome Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with the Gnome Library; see the file COPYING.LIB.  If not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef GNOME_VFS_MIME_UTILS_H
#define GNOME_VFS_MIME_UTILS_H

#include <glib/gtypes.h>

G_BEGIN_DECLS

/**
 * GNOME_VFS_MIME_TYPE_UNKNOWN:
 *
 * The value returned for the MIME type when a file did
 * not match any entries in the MIME database. May be
 * treated as a file of an unknown type.
 **/
#define GNOME_VFS_MIME_TYPE_UNKNOWN "application/octet-stream"

const char  *gnome_vfs_get_mime_type_for_data (gconstpointer data,
					       int           data_size);

char        *gnome_vfs_get_mime_type           (const char  *text_uri);

G_END_DECLS

#endif
