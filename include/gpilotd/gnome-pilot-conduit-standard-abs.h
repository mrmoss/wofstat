/* gnome-pilot-conduit-standard-abs.h
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
 * Authors: Johnathan Blandford
 *          Eskil Heyn Olsen
 *          Vadim Strizhevsky
 *
 */

#ifndef __GNOME_PILOT_CONDUIT_STANDARD_ABS_H__
#define __GNOME_PILOT_CONDUIT_STANDARD_ABS_H__

#include <gnome.h>
#include "gnome-pilot-conduit-standard.h"

#ifdef __cplusplus
extern "C" {
#pragma }
#endif /* __cplusplus */

#define GNOME_TYPE_PILOT_CONDUIT_STANDARD_ABS			(gnome_pilot_conduit_standard_abs_get_type ())
#define GNOME_PILOT_CONDUIT_STANDARD_ABS(obj)			(GTK_CHECK_CAST ((obj), GNOME_TYPE_PILOT_CONDUIT_STANDARD_ABS, GnomePilotConduitStandardAbs))
#define GNOME_PILOT_CONDUIT_STANDARD_ABS_CLASS(klass)		(GTK_CHECK_CLASS_CAST ((klass), GNOME_TYPE_PILOT_CONDUIT_STANDARD_ABS, GnomePilotConduitStandardAbsClass))
#define GNOME_IS_PILOT_CONDUIT_STANDARD_ABS(obj)			(GTK_CHECK_TYPE ((obj), GNOME_TYPE_PILOT_CONDUIT_STANDARD_ABS))
#define GNOME_IS_PILOT_CONDUIT_STANDARD_ABS_CLASS(klass)		(GTK_CHECK_CLASS_TYPE ((obj), GNOME_TYPE_PILOT_CONDUIT_STANDARD_ABS))

enum
{
	GnomePilotRecordNothing,
	GnomePilotRecordNew,
	GnomePilotRecordDeleted,
	GnomePilotRecordModified,
	GnomePilotRecordPending
};

typedef struct _PilotRecord PilotRecord;
struct _PilotRecord {
	recordid_t ID;
	int attr;
	int archived;
	int secret;
	int length;
	int category;
	unsigned char * record;
};

typedef struct _LocalRecord LocalRecord;
struct _LocalRecord {
	int attr;
	int archived;
	int secret;
	recordid_t ID;
};

typedef struct _GnomePilotConduitStandardAbs       GnomePilotConduitStandardAbs;
typedef struct _GnomePilotConduitStandardAbsClass  GnomePilotConduitStandardAbsClass;

struct _GnomePilotConduitStandardAbs
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

	/* This is set by the conduit implementation. Determines how to open the
	   db, used for gaining access to secret records */
	gint db_open_mode;
};
struct _GnomePilotConduitStandardAbsClass
{
	GnomePilotConduitStandardClass parent_class;

	/* Signals go here */
	int (*match_record)	(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord **local,
				 PilotRecord *remote);
	int (*free_match)	(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord **local);
	int (*archive_local)	(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord *local);
	int (*archive_remote)	(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord *local,
				 PilotRecord *remote);
	int (*store_remote)	(GnomePilotConduitStandardAbs *conduit,
				 PilotRecord *remote);
	int (*iterate)		(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord **local);
	int (*iterate_specific)	(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord **local,
				 gint flag,
				 gint archived);
	int (*purge)		(GnomePilotConduitStandardAbs *conduit);
	int (*set_status)	(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord *local,
				 gint status);
	int (*set_pilot_id)	(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord *local,
				 guint32 ID);
	int (*compare)		(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord *local,
				 PilotRecord *remote);
	int (*compare_backup)	(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord *local,
				 PilotRecord *remote);
	int (*free_transmit)	(GnomePilotConduitStandardAbs *conduit,
				 LocalRecord *local,
				 PilotRecord **remote);
	int (*delete_all)	(GnomePilotConduitStandardAbs *conduit);
	int (*transmit)         (GnomePilotConduitStandardAbs *conduit,
				 LocalRecord *local,
				 PilotRecord **);
	int (*pre_sync)         (GnomePilotConduitStandardAbs *conduit,
				 GnomePilotDBInfo  *dbinfo);
};

GtkType    gnome_pilot_conduit_standard_abs_get_type (void);
GtkObject *gnome_pilot_conduit_standard_abs_new (char *db_name,
						 guint32 creator_id);
gint gnome_pilot_conduit_standard_abs_match_record (GnomePilotConduitStandardAbs *conduit,
						    LocalRecord **local,
						    PilotRecord *remote);
gint gnome_pilot_conduit_standard_abs_free_match (GnomePilotConduitStandardAbs *conduit,
						  LocalRecord **local);
gint gnome_pilot_conduit_standard_abs_archive_local (GnomePilotConduitStandardAbs *conduit,
						     LocalRecord *local);
gint gnome_pilot_conduit_standard_abs_archive_remote (GnomePilotConduitStandardAbs *conduit,
						      LocalRecord *local,
						      PilotRecord *remote);
gint gnome_pilot_conduit_standard_abs_store_remote (GnomePilotConduitStandardAbs *conduit,
						    PilotRecord *remote);
gint gnome_pilot_conduit_standard_abs_iterate (GnomePilotConduitStandardAbs *conduit,
					       LocalRecord **local);
gint gnome_pilot_conduit_standard_abs_iterate_specific (GnomePilotConduitStandardAbs *conduit,
							LocalRecord **local,
							gint flag,
							gint archived);
gint gnome_pilot_conduit_standard_abs_purge (GnomePilotConduitStandardAbs *conduit);
gint gnome_pilot_conduit_standard_abs_set_status (GnomePilotConduitStandardAbs *conduit,
						  LocalRecord *local,
						  gint status);
gint gnome_pilot_conduit_standard_abs_set_pilot_id (GnomePilotConduitStandardAbs *conduit,
						    LocalRecord *local,
						    guint32 id);
gint gnome_pilot_conduit_standard_abs_compare (GnomePilotConduitStandardAbs *conduit,
						      LocalRecord *local,
						      PilotRecord *remote);
gint gnome_pilot_conduit_standard_abs_compare_backup (GnomePilotConduitStandardAbs *conduit,
						      LocalRecord *local,
						      PilotRecord *remote);
gint gnome_pilot_conduit_standard_abs_free_transmit (GnomePilotConduitStandardAbs *conduit,
						      LocalRecord *local,
						      PilotRecord **remote);
gint gnome_pilot_conduit_standard_abs_delete_all (GnomePilotConduitStandardAbs *conduit);
gint gnome_pilot_conduit_standard_abs_pre_sync   (GnomePilotConduitStandardAbs *conduit,
						  GnomePilotDBInfo  *dbinfo);
gint gnome_pilot_conduit_standard_abs_transmit (GnomePilotConduitStandardAbs *conduit,
						LocalRecord *local,
						PilotRecord **remote);

/* FIXME: This could, perhaps should be done with the GTK+ argument system,
   but untill I port to gob, that's not going to happen... */
void gnome_pilot_conduit_standard_abs_set_num_local_records (GnomePilotConduitStandardAbs *conduit,
							     gint num);
void gnome_pilot_conduit_standard_abs_set_num_updated_local_records (GnomePilotConduitStandardAbs *conduit,
								     gint num);
void gnome_pilot_conduit_standard_abs_set_num_new_local_records (GnomePilotConduitStandardAbs *conduit,
								 gint num);
void gnome_pilot_conduit_standard_abs_set_num_deleted_local_records (GnomePilotConduitStandardAbs *conduit,
								     gint num);
void gnome_pilot_conduit_standard_abs_set_db_open_mode (GnomePilotConduitStandardAbs *conduit,
							gint mode);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __GNOME_PILOT_CONDUIT_STANDARD_ABS_H__ */
