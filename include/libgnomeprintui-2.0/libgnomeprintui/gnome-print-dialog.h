#ifndef __GNOME_PRINT_DIALOG__
#define __GNOME_PRINT_DIALOG__

/*
 *  Copyright (C) 2000 Helix Code Inc.
 *
 *  Authors: Michael Zucchi <notzed@helixcode.com>
 *
 *  A system print dialogue.
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
 */

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_PRINT_DIALOG (gnome_print_dialog_get_type ())
#define GNOME_PRINT_DIALOG(obj) GTK_CHECK_CAST (obj, gnome_print_dialog_get_type (), GnomePrintDialog)
#define GNOME_PRINT_DIALOG_CLASS(klass) GTK_CHECK_CLASS_CAST (klass, gnome_print_dialog_get_type (), GnomePrintDialogClass)
#define GNOME_IS_PRINT_DIALOG(obj) GTK_CHECK_TYPE (obj, gnome_print_dialog_get_type ())

typedef struct _GnomePrintDialog GnomePrintDialog;
typedef struct _GnomePrintDialogClass GnomePrintDialogClass;

#include <sys/types.h>
#include <gtk/gtkwidget.h>
#include <libgnomeprint/gnome-print-master.h>

/*
 * Used to track what type of range selector has been setup
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
	GNOME_PRINT_RANGE_SELECTION_UNSENSITIVE  = (1 << 4),
};

/*
 * Flags to specify, whether we want range and copies widgets
 */

enum GnomePrintDialogFlags {
	GNOME_PRINT_DIALOG_RANGE = (1 << 0),
	GNOME_PRINT_DIALOG_COPIES = (1 << 1)
};

/**
 * The button numbers corresponding to the standard buttons
 * Used with the GnomeDialog "clicked" signal.
 */

enum GnomePrintButtons {
	GNOME_PRINT_DIALOG_RESPONSE_PRINT = 1,
	GNOME_PRINT_DIALOG_RESPONSE_PREVIEW,
	GNOME_PRINT_DIALOG_RESPONSE_CANCEL = -6 /* Same as GTK_RESPONSE_CANCEL */
};

GType gnome_print_dialog_get_type (void);

GtkWidget *gnome_print_dialog_new (const guchar *title, gint flags);
GtkWidget *gnome_print_dialog_new_from_master (GnomePrintMaster *gpm,
									  const guchar *title, gint flags);

/* for language bindings */
void gnome_print_dialog_construct (GnomePrintDialog *dialog, const guchar *title, gint flags);

void gnome_print_dialog_construct_range_custom (GnomePrintDialog *dialog, GtkWidget *custom);
void gnome_print_dialog_construct_range_any (GnomePrintDialog *dialog, gint flags,
					     GtkWidget *range_widget,
					     const guchar *currentlabel, const guchar *rangelabel);
void gnome_print_dialog_construct_range_page (GnomePrintDialog *gpd, gint flags,
					      gint start, gint end,
					      const guchar *currentlabel, const guchar *rangelabel);

GnomePrintRangeType gnome_print_dialog_get_range (GnomePrintDialog *gpd);
int gnome_print_dialog_get_range_page (GnomePrintDialog *gpd, gint *start, gint *end);

void gnome_print_dialog_get_copies (GnomePrintDialog *gpd, gint *copies, gint *collate);
void gnome_print_dialog_set_copies (GnomePrintDialog *gpd, gint copies, gint collate);

GnomePrintConfig *gnome_print_dialog_get_config (GnomePrintDialog *gpd);

G_END_DECLS

#endif /* ! _GNOME_PRINT_DIALOG */
