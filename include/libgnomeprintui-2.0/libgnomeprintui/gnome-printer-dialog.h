#ifndef __GNOME_PRINTER_DIALOG_H__
#define __GNOME_PRINTER_DIALOG_H__

/*
 *  Copyright (C) 1999-2001 Ximian Inc. and authors
 *
 *  Authors:
 *    Raph Levien (raph@acm.org)
 *    Miguel de Icaza (miguel@kernel.org)
 *    Lauris Kaplinski <lauris@ximian.com>
 *    Chema Celorio (chema@celorio.com)
 *
 *  Printer selection widget and dialog
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

#define GNOME_TYPE_PRINTER_SELECTION (gnome_printer_selection_get_type ())
#define GNOME_PRINTER_SELECTION(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINTER_SELECTION, GnomePrinterSelection))
#define GNOME_PRINTER_SELECTION_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_PRINTER_SELECTION, GnomePrinterSelectionClass))
#define GNOME_IS_PRINTER_SELECTION(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINTER_SELECTION))
#define GNOME_IS_PRINTER_SELECTION_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_PRINTER_SELECTION))
#define GNOME_PRINTER_SELECTION_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PRINTER_SELECTION, GnomePrinterSelectionClass))

#define GNOME_TYPE_PRINTER_DIALOG (gnome_printer_dialog_get_type ())
#define GNOME_PRINTER_DIALOG(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINTER_DIALOG, GnomePrinterDialog))
#define GNOME_PRINTER_DIALOG_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_PRINTER_DIALOG, GnomePrinterDialogClass))
#define GNOME_IS_PRINTER_DIALOG(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINTER_DIALOG))
#define GNOME_IS_PRINTER_DIALOG_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_PRINTER_DIALOG))
#define GNOME_PRINTER_DIALOG_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PRINTER_DIALOG, GnomePrinterDialogClass))

typedef struct _GnomePrinterSelection GnomePrinterSelection;
typedef struct _GnomePrinterSelectionClass GnomePrinterSelectionClass;

typedef struct _GnomePrinterDialog GnomePrinterDialog;
typedef struct _GnomePrinterDialogClass GnomePrinterDialogClass;

#include <libgnomeprint/gnome-print-config.h>

GtkType gnome_printer_selection_get_type (void);

GtkWidget *gnome_printer_selection_new_default (void);
GtkWidget *gnome_printer_selection_new (GnomePrintConfig *config);

GnomePrintConfig *gnome_printer_selection_get_config (GnomePrinterSelection *psel);

/*
 * GnomePrinterDialog is GtkDialog, with 2 buttons (OK and Cancel)
 *
 * You can run it, values returned are default gtk responses
 */

GtkType gnome_printer_dialog_get_type (void);

GtkWidget *gnome_printer_dialog_new_default (void);
GtkWidget *gnome_printer_dialog_new (GnomePrintConfig *config);

GnomePrintConfig *gnome_printer_dialog_get_config (GnomePrinterDialog *dialog);

G_END_DECLS

#endif /* __GNOME_PRINTER_DIALOG_H__ */
