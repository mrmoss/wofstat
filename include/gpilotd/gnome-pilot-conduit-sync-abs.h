/* gnome-pilot-conduit-sync-abs.h
 * Copyright (C) 1999  Free Software Foundation
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
 * Authors: JP Rosevear
 *          Johnathan Blandford
 *          Eskil Heyn Olsen
 *          Vadim Strizhevsky
 *
 */

#ifndef __GNOME_PILOT_CONDUIT_SYNC_ABS_H__
#define __GNOME_PILOT_CONDUIT_SYNC_ABS_H__

#include <gnome.h>
#include <pi-sync.h>
#include "gnome-pilot-conduit-standard.h"

#ifdef __cplusplus
extern "C" {
#pragma }
#endif /* __cplusplus */

#define GNOME_TYPE_PILOT_CONDUIT_SYNC_ABS			(gnome_pilot_conduit_sync_abs_get_type ())
#define GNOME_PILOT_CONDUIT_SYNC_ABS(obj)			(GTK_CHECK_CAST ((obj), GNOME_TYPE_PILOT_CONDUIT_SYNC_ABS, GnomePilotConduitSyncAbs))
#define GNOME_PILOT_CONDUIT_SYNC_ABS_CLASS(klass)		(GTK_CHECK_CLASS_CAST ((klass), GNOME_TYPE_PILOT_CONDUIT_SYNC_ABS, GnomePilotConduitSyncAbsClass))
#define GNOME_IS_PILOT_CONDUIT_SYNC_ABS(obj)			(GTK_CHECK_TYPE ((obj), GNOME_TYPE_PILOT_CONDUIT_SYNC_ABS))
#define GNOME_IS_PILOT_CONDUIT_SYNC_ABS_CLASS(klass)		(GTK_CHECK_CLASS_TYPE ((obj), GNOME_TYPE_PILOT_CONDUIT_SYNC_ABS))

typedef enum
{
	GnomePilotRecordNothing,
	GnomePilotRecordNew,
	GnomePilotRecordModified,
	GnomePilotRecordDeleted
} GnomePilotStatus;

typedef struct _GnomePilotRecord GnomePilotRecord;
struct _GnomePilotRecord {
	recordid_t ID;
	int category;
	gboolean archived;
	gboolean secret;
	GnomePilotStatus attr;
	unsigned char *record;
	int length;
};

typedef struct _GnomePilotDesktopRecord GnomePilotDesktopRecord;
struct _GnomePilotDesktopRecord {
	DesktopRecord dr;
	recordid_t ID;
	int category;
	gboolean archived;
	gboolean secret;
	GnomePilotStatus attr;
};

typedef struct _GnomePilotConduitSyncAbs       GnomePilotConduitSyncAbs;
typedef struct _GnomePilotConduitSyncAbsClass  GnomePilotConduitSyncAbsClass;

struct _GnomePilotConduitSyncAbs
{
	GnomePilotConduitStandard parent;

	/* Private data */
	GSList *record_ids_to_ignore; /* these are records added to the pilot during sync,
					 which sync_record should ignore */
	gint total_records; /* this is the total number of records to be traversed 
			       depending on the sync, used for progress bars
			    */
	
	/* These are set by the conduit implementation, used for the progress
	   bar. If the conduit does not set them, they default to the number
	   of records in the base, but causes unrealistic progress bars */
	gint num_local_records;
	gint num_updated_local_records;
	gint num_new_local_records;
	gint num_deleted_local_records;

	gint progress;
	gint total_progress;
};

struct _GnomePilotConduitSyncAbsClass
{
	GnomePilotConduitStandardClass parent_class;

	/* Signals go here */
	int (*pre_sync)          (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotDBInfo  *dbinfo);
	int (*post_sync)         (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotDBInfo  *dbinfo);

	int (*set_pilot_id)	 (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotDesktopRecord *dr,
				  guint32 ID);
	int (*set_status_cleared)(GnomePilotConduitSyncAbs *conduit,
				  GnomePilotDesktopRecord *dr);

	int (*for_each)		 (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotDesktopRecord **dr);
	int (*for_each_modified) (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotDesktopRecord **dr);
	int (*compare)		 (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotDesktopRecord *dr,
				  GnomePilotRecord *pr);

	int (*add_record)	 (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotRecord *pr);
	int (*replace_record)	 (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotDesktopRecord *dr,
				  GnomePilotRecord *pr);
	int (*delete_record)	 (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotDesktopRecord *dr);
	int (*archive_record)    (GnomePilotConduitSyncAbs *conduit,
				  GnomePilotRecord *pr,
				  gboolean archive);

	int (*match)	        (GnomePilotConduitSyncAbs *conduit,
				 GnomePilotDesktopRecord **dr,
				 GnomePilotRecord *pr);
	int (*free_match)	(GnomePilotConduitSyncAbs *conduit,
				 GnomePilotDesktopRecord **dr);

	int (*prepare)          (GnomePilotConduitSyncAbs *conduit,
				 GnomePilotDesktopRecord *dr,
				 GnomePilotRecord *pr);
};

GtkType    gnome_pilot_conduit_sync_abs_get_type (void);
GtkObject *gnome_pilot_conduit_sync_abs_new (char *db_name,
					     guint32 creator_id);

void gnome_pilot_conduit_sync_abs_set_num_local_records (GnomePilotConduitSyncAbs *conduit,
							 gint num);
void gnome_pilot_conduit_sync_abs_set_num_updated_local_records (GnomePilotConduitSyncAbs *conduit,
								 gint num);
void gnome_pilot_conduit_sync_abs_set_num_new_local_records (GnomePilotConduitSyncAbs *conduit,
							     gint num);
void gnome_pilot_conduit_sync_abs_set_num_deleted_local_records (GnomePilotConduitSyncAbs *conduit,
								 gint num);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __GNOME_PILOT_CONDUIT_SYNC_ABS_H__ */
