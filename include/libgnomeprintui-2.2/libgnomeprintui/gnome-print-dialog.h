/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print-dialog.h: A system print dialog
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public License
 *  as published by the Free Software Foundation; either version 2 of
 *  the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Authors:
 *    Michael Zucchi <notzed@helixcode.com>
 *    Chema Celorio <chema@celorio.com>
 *    Lauris Kaplinski <lauris@ximian.com>
 *    Andreas J. Guelzow <aguelzow@taliesin.ca>
 *
 *  Copyright (C) 2000-2002 Ximian Inc.
 *  Copyright (C) 2004 Andreas J. Guelzow
 *
 */

#ifndef __GNOME_PRINT_DIALOG_H__
#define __GNOME_PRINT_DIALOG_H__

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_PRINT_DIALOG         (gnome_print_dialog_get_type ())
#define GNOME_PRINT_DIALOG(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_DIALOG, GnomePrintDialog))
#define GNOME_PRINT_DIALOG_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST    ((k), GNOME_TYPE_PRINT_DIALOG, GnomePrintDialogClass))
#define GNOME_IS_PRINT_DIALOG(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_DIALOG))
#define GNOME_IS_PRINT_DIALOG_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE    ((k), GNOME_TYPE_PRINT_DIALOG))
#define GNOME_PRINT_DIALOG_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS  ((o), GNOME_TYPE_PRINT_DIALOG), GnomePrintDialogClass)

typedef struct _GnomePrintDialog      GnomePrintDialog;
typedef struct _GnomePrintDialogClass GnomePrintDialogClass;

#include <gtk/gtk.h>
#include <libgnomeprint/gnome-print-job.h>

/*
 * Used to track what type of range selection has been setup
 *
 * This is used internally and has little use for outside world
 */
typedef enum {
	GNOME_PRINT_RANGETYPE_NONE,
	GNOME_PRINT_RANGETYPE_CUSTOM,
	GNOME_PRINT_RANGETYPE_PAGES
} GnomePrintRangeType;

/*
 * Flags for creation of range widget
 */
enum GnomePrintDialogRangeFlags {
	GNOME_PRINT_RANGE_CURRENT = (1 << 0),
	GNOME_PRINT_RANGE_ALL = (1 << 1),
	GNOME_PRINT_RANGE_RANGE = (1 << 2),
	GNOME_PRINT_RANGE_SELECTION = (1 << 3),
	GNOME_PRINT_RANGE_SELECTION_UNSENSITIVE  = (1 << 4)
};

/*
 * Flags to specify, whether we want range and copies widgets
 */
enum GnomePrintDialogFlags {
	GNOME_PRINT_DIALOG_RANGE = (1 << 0),
	GNOME_PRINT_DIALOG_COPIES = (1 << 1),
	GNOME_PRINT_DIALOG_DONT_SHOW_PREVIEW_BUTTON = (1 << 2)
};

/*
 * The button numbers corresponding to the standard buttons
 * Used with the GtkDialog "clicked" signal.
 */
enum GnomePrintButtons {
	GNOME_PRINT_DIALOG_RESPONSE_PRINT = 1,
	GNOME_PRINT_DIALOG_RESPONSE_PREVIEW,
	GNOME_PRINT_DIALOG_RESPONSE_CANCEL = GTK_RESPONSE_CANCEL
};

GType gnome_print_dialog_get_type (void);

GtkWidget * gnome_print_dialog_new (GnomePrintJob *gpj, const guchar *title, gint flags);

/* For language bindings */
void gnome_print_dialog_construct (GnomePrintDialog *gpd, const guchar *title, gint flags);
void gnome_print_dialog_construct_range_custom (GnomePrintDialog *gpd, GtkWidget *custom);
void gnome_print_dialog_construct_range_any  (GnomePrintDialog *gpd, gint flags,
					      GtkWidget *range_widget,
					      const guchar *currentlabel, const guchar *rangelabel);
void gnome_print_dialog_construct_range_page (GnomePrintDialog *gpd, gint flags,
					      gint start, gint end,
					      const guchar *currentlabel, const guchar *rangelabel);

void                gnome_print_dialog_get_copies (GnomePrintDialog *gpd, gint *copies, gboolean *collate);
void                gnome_print_dialog_set_copies (GnomePrintDialog *gpd, gint copies, gint collate);
GnomePrintConfig *  gnome_print_dialog_get_config (GnomePrintDialog *gpd);
GnomePrintRangeType gnome_print_dialog_get_range  (GnomePrintDialog *gpd);
int                 gnome_print_dialog_get_range_page (GnomePrintDialog *gpd, gint *start, gint *end);

/* gnome_print_dialog_run is intended as a dropin replacement for */
/* gtk_dialog_run                                                 */
gint  gnome_print_dialog_run (GnomePrintDialog const *gpd);

G_END_DECLS

#endif /* __GNOME_PRINT_DIALOG_H__ */
