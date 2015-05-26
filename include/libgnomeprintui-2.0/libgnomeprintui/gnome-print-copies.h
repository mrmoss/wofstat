#ifndef _GNOME_PRINT_COPIES_H_
#define _GNOME_PRINT_COPIES_H_

/*
 *  Copyright (C) 2000 Helix Code Inc.
 *
 *  Authors: Michael Zucchi <notzed@helixcode.com>
 *           Lauris Kaplinski <lauris@helixcode.com>
 *
 *  A system print-copies widget.
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

#define GNOME_TYPE_PRINT_COPIES_SELECTION (gnome_print_copies_selection_get_type ())
#define GNOME_PRINT_COPIES_SELECTION(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_COPIES_SELECTION, GnomePrintCopiesSelection))
#define GNOME_PRINT_COPIES_SELECTION_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_PRINT_COPIES_SELECTION, GnomePrintCopiesSelectionClass))
#define GNOME_IS_PRINT_COPIES_SELECTION(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_COPIES_SELECTION))
#define GNOME_IS_PRINT_COPIES_SELECTION_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_PRINT_COPIES_SELECTION))
#define GNOME_PRINT_COPIES_SELECTION_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PRINT_COPIES_SELECTION, GnomePrintCopiesSelectionClass))

typedef struct _GnomePrintCopiesSelection GnomePrintCopiesSelection;
typedef struct _GnomePrintCopiesSelectionClass GnomePrintCopiesSelectionClass;

#include <gtk/gtkwidget.h>

/*
 * We implement single signal at moment:
 *
 * void (*copies_set) (GnomePrintCopies *gpc, gint copies, gboolean collate);
 *
 * Notice, that this is not bound to GnomePrintConfig, so if you want
 * print master to handle copies, you either should use GnomePrintDialog,
 * or set the config key GNOME_PRINT_KEY_NUM_COPIES in signal handler
 *
 */

GtkType gnome_print_copies_selection_get_type (void);

GtkWidget *gnome_print_copies_selection_new (void);

void gnome_print_copies_selection_set_copies (GnomePrintCopiesSelection *gpc, gint copies, gboolean collate);

gint gnome_print_copies_selection_get_copies (GnomePrintCopiesSelection *gpc);
gboolean gnome_print_copies_selection_get_collate (GnomePrintCopiesSelection *gpc);

G_END_DECLS

#endif /* ! _GNOME_PRINT_COPIES_H */
