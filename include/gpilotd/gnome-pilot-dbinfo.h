/* gnome-pilot-conduit.h
 * Copyright (C) 1999  Red Hat Inc.,
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Authors: Johnathan Blandford
 *           Eskil Olsen
 *
 * $Id: gnome-pilot-dbinfo.h,v 1.1.1.1 2005/08/02 07:46:35 sunop Exp $
 */

#ifndef __GNOME_PILOT_DBINFO_H__
#define __GNOME_PILOT_DBINFO_H__

#include <glib.h>
#include <pi-source.h>
#include <pi-dlp.h>

#include "gnome-pilot-structures.h"

/*
  GnomePilotDBInfo is the structured used between manager.c and gnome-pilot-conduits
  to let the conduit have access to essential data reg. the current connection.
  Such as pilot information, file descriptors and database info.
 */

/* WARNING:  This is not really a Gtk Object. */
/* Do not treat it as such. */
#define PI_DBINFO(obj)				((struct DBInfo *) obj)
#define GNOME_PILOT_DBINFO(obj)			((GnomePilotDBInfo *) obj)

typedef struct _GnomePilotDBInfo     GnomePilotDBInfo;

struct _GnomePilotDBInfo
{
	/* Structure from pilot-link, see below */
	struct DBInfo pisock_dbinfo;
	/* Structure from pilot-link, see below */
	struct PilotUser *pu;

	/* The pilot identification structure */
	GPilotPilot *pilotInfo;
	
	/* This is "filedescriptor" used for pi_ calls */
	gint   pilot_socket;

	/* This is "filedescriptor" used for dlp_ calls */
        gint   db_handle;

	/* internal to the gpilotd conduit manager */
	void  *manager_data;
};

/* This is what the DBInfo and PilotUser struct looks like.  It is here for reference
 * purposes only */

/*
struct DBInfo {
	int more;
	unsigned int flags;
	unsigned int miscFlags;
	pi_uint32 type,creator;
	unsigned int version;
	pi_uint32 modnum;
	time_t createDate,modifyDate,backupDate;
	unsigned int index;
	char name[34];
};

struct PilotUser {
  unsigned long userID, viewerID, lastSyncPC;
  time_t successfulSyncDate, lastSyncDate;
  char username[128];
  int passwordLength;
  char password[128];
};

*/

#endif
