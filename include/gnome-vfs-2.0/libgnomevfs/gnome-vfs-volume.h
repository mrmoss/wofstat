/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/* gnome-vfs-volume.h - Handling of volumes for the GNOME Virtual File System.

   Copyright (C) 2003 Red Hat, Inc

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

   Author: Alexander Larsson <alexl@redhat.com>
*/

#ifndef GNOME_VFS_VOLUME_H
#define GNOME_VFS_VOLUME_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glib-object.h>

G_BEGIN_DECLS

#define GNOME_VFS_TYPE_VOLUME        (gnome_vfs_volume_get_type ())
#define GNOME_VFS_VOLUME(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_VFS_TYPE_VOLUME, GnomeVFSVolume))
#define GNOME_VFS_VOLUME_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), GNOME_VFS_TYPE_VOLUME, GnomeVFSVolumeClass))
#define GNOME_IS_VFS_VOLUME(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_VFS_TYPE_VOLUME))
#define GNOME_IS_VFS_VOLUME_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_VFS_TYPE_VOLUME))

typedef struct _GnomeVFSVolumePrivate GnomeVFSVolumePrivate;

typedef enum {
	GNOME_VFS_DEVICE_TYPE_UNKNOWN,
	GNOME_VFS_DEVICE_TYPE_AUDIO_CD,
	GNOME_VFS_DEVICE_TYPE_VIDEO_DVD,
	GNOME_VFS_DEVICE_TYPE_HARDDRIVE, 
	GNOME_VFS_DEVICE_TYPE_CDROM,
	GNOME_VFS_DEVICE_TYPE_FLOPPY,
	GNOME_VFS_DEVICE_TYPE_ZIP,
	GNOME_VFS_DEVICE_TYPE_JAZ,
	GNOME_VFS_DEVICE_TYPE_NFS,
	GNOME_VFS_DEVICE_TYPE_AUTOFS,
	GNOME_VFS_DEVICE_TYPE_CAMERA,
	GNOME_VFS_DEVICE_TYPE_MEMORY_STICK,
	GNOME_VFS_DEVICE_TYPE_SMB,
	GNOME_VFS_DEVICE_TYPE_APPLE,
	GNOME_VFS_DEVICE_TYPE_MUSIC_PLAYER,
	GNOME_VFS_DEVICE_TYPE_WINDOWS, 
	GNOME_VFS_DEVICE_TYPE_LOOPBACK, 
	GNOME_VFS_DEVICE_TYPE_NETWORK 
} GnomeVFSDeviceType;

typedef enum {
	GNOME_VFS_VOLUME_TYPE_MOUNTPOINT,
	GNOME_VFS_VOLUME_TYPE_VFS_MOUNT,
	GNOME_VFS_VOLUME_TYPE_CONNECTED_SERVER
} GnomeVFSVolumeType;

typedef struct _GnomeVFSVolume GnomeVFSVolume;

struct _GnomeVFSVolume {
	GObject parent;

        GnomeVFSVolumePrivate *priv;
};

typedef struct _GnomeVFSVolumeClass GnomeVFSVolumeClass;

struct _GnomeVFSVolumeClass {
	GObjectClass parent_class;
};

typedef void (*GnomeVFSVolumeOpCallback) (gboolean succeeded,
					  char *error,
					  char *detailed_error,
					  gpointer data);


/* Need to declare this here due to cross use in gnome-vfs-drive.h */
typedef struct _GnomeVFSDrive GnomeVFSDrive;

#include <libgnomevfs/gnome-vfs-drive.h>

GType gnome_vfs_volume_get_type (void) G_GNUC_CONST;

GnomeVFSVolume *gnome_vfs_volume_ref   (GnomeVFSVolume *volume);
void            gnome_vfs_volume_unref (GnomeVFSVolume *volume);

gulong             gnome_vfs_volume_get_id              (GnomeVFSVolume *volume);
GnomeVFSVolumeType gnome_vfs_volume_get_volume_type     (GnomeVFSVolume *volume);
GnomeVFSDeviceType gnome_vfs_volume_get_device_type     (GnomeVFSVolume *volume);
GnomeVFSDrive *    gnome_vfs_volume_get_drive           (GnomeVFSVolume *volume);
char *             gnome_vfs_volume_get_device_path     (GnomeVFSVolume *volume);
char *             gnome_vfs_volume_get_activation_uri  (GnomeVFSVolume *volume);
char *             gnome_vfs_volume_get_filesystem_type (GnomeVFSVolume *volume);
char *             gnome_vfs_volume_get_display_name    (GnomeVFSVolume *volume);
char *             gnome_vfs_volume_get_icon            (GnomeVFSVolume *volume);
gboolean           gnome_vfs_volume_is_user_visible     (GnomeVFSVolume *volume);
gboolean           gnome_vfs_volume_is_read_only        (GnomeVFSVolume *volume);
gboolean           gnome_vfs_volume_is_mounted          (GnomeVFSVolume *volume);
gboolean           gnome_vfs_volume_handles_trash       (GnomeVFSVolume *volume);

gint               gnome_vfs_volume_compare             (GnomeVFSVolume *a,
							 GnomeVFSVolume *b);


void gnome_vfs_volume_unmount    (GnomeVFSVolume           *volume,
				  GnomeVFSVolumeOpCallback  callback,
				  gpointer                  user_data);
void gnome_vfs_volume_eject      (GnomeVFSVolume           *volume,
				  GnomeVFSVolumeOpCallback  callback,
				  gpointer                  user_data);
void gnome_vfs_connect_to_server (char                     *uri,
				  char                     *display_name,
				  char                     *icon);

G_END_DECLS

#endif /* GNOME_VFS_VOLUME_H */
