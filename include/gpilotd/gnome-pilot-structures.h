/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- *//* 
 * Copyright (C) 1998-2000 Free Software Foundation
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Authors: Eskil Heyn Olsen
 *          Manish Vachharajani
 *          Dave Camp
 *
 */

#ifndef _GPILOT_STRUCTURES_H_
#define _GPILOT_STRUCTURES_H_

#include <glib.h>

typedef enum {
	GnomePilotConduitSyncTypeCustom,
	GnomePilotConduitSyncTypeSynchronize,
	GnomePilotConduitSyncTypeCopyFromPilot,
	GnomePilotConduitSyncTypeCopyToPilot,
	GnomePilotConduitSyncTypeMergeFromPilot,
	GnomePilotConduitSyncTypeMergeToPilot,
	GnomePilotConduitSyncTypeNotSet
} GnomePilotConduitSyncType;

gint         gnome_pilot_conduit_sync_type_str_to_int(const gchar *s);
const gchar* gnome_pilot_conduit_sync_type_int_to_str(GnomePilotConduitSyncType e);

struct _GPilotSyncOpt {
	GnomePilotConduitSyncType default_sync_action; /* Unused, but exists for bin compat */
	gchar *basedir;
	gchar *old_basedir;  /* Restore the original value if users set an invalid base directory */
	gchar *pilot_charset; /* Restore the charset of pilot */

};
typedef struct _GPilotSyncOpt GPilotSyncOpt;

struct GPilotUser {
	gchar *username;  /* We can get the real name from getpwent */
};
typedef struct GPilotUser GPilotUser;

GPilotUser *gpilot_user_new (void);
void gpilot_user_free (GPilotUser *user);

struct _GPilotContext {
	gboolean paused;
	GList *devices;
	GList *pilots;
	GPilotUser *user; /* Null in master global gpilotd */
	guint32 sync_PC_Id; /* Different for every gpilotd instance */
	gint progress_stepping;

#ifdef WITH_USB_VISOR
	/* For checking for visor devices */
	int visor_fd;
	GIOChannel *visor_io;
	guint visor_in_handle;
	guint visor_err_handle;
#endif
};
typedef struct _GPilotContext GPilotContext;

GPilotContext *gpilot_context_new (void);
void gpilot_context_init_user (GPilotContext *context);
void gpilot_context_free (GPilotContext *context);

typedef enum GPilotDeviceType {
	PILOT_DEVICE_SERIAL=0,
	PILOT_DEVICE_USB_VISOR=1,
	PILOT_DEVICE_IRDA=2,
	PILOT_DEVICE_NETWORK=4
} GPilotDeviceType;

struct _GPilotDevice {
	gchar *name; /* symbolic name */
	gchar *port; /* device */
	gchar *old_port; /* restore old value when an invalid port is set */
	guint speed; /* speed (for serial) */

	/* These are used for network (man c++ is soo much cooler) */
	gchar *ip;
	gchar *host;
	gchar *netmask;

	/* These are used at runtime, to associate 
	   an opened file with the device */
	int fd;
	GIOChannel *io;    /* the g_io_channel is used for the polling */
	guint in_handle;   /* these two handles are used to be able to */
	guint err_handle;  /* pause the daemon's polling by g_source_remove */
	
	gchar *lock_file;

	gint timeout;
	GPilotDeviceType type;
	GPilotDeviceType old_type; /* restore old value when an invalid type is set */
	gboolean device_exists : 1;  /* whether the usb cradle is active */
};
typedef struct _GPilotDevice GPilotDevice;

GPilotDevice *gpilot_device_new (void);
void gpilot_device_free (GPilotDevice *device);
gint gpilot_device_init (GPilotDevice *device);
void gpilot_device_deinit (GPilotDevice *device);
gint gpilot_device_load (GPilotDevice *device, gint i);

#define GPILOT_DEVICE(s) ((GPilotDevice*)(s))

struct _GPilotPilot {
	/* The pilots name */
	gchar *name;
	/* The userspecified password for the pilot */
	gchar *passwd;
        /* To look up conduits file */
	int number; 
	/* Pilot owners name */
	gchar *pilot_username;
	/* Pilots ID number */
	guint32 pilot_id;

	/* Majick numbers to id when restoring a pilot with id = 0 */
	unsigned long creation, romversion;

      /* list of gchar* unix usernames that may operate on the pilot (not implemented) */
	GList *trusted_users;  
	GPilotSyncOpt sync_options;
};
typedef struct _GPilotPilot GPilotPilot;

GPilotPilot *gpilot_pilot_new (void);
void gpilot_pilot_init (GPilotPilot *pilot, gint i);
void gpilot_pilot_free (GPilotPilot *pilot);

GPilotPilot* gpilot_find_pilot_by_name(gchar*,GList*);
GPilotPilot* gpilot_find_pilot_by_id(guint32, GList*);

#define GPILOT_PILOT(s) ((GPilotPilot*)(s))
#define GPILOT_USER(s) ((GPilotUser*)(s))

#endif /* _GPILOT_STRUCTURES_H_ */
