/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print-config-dialog.h: A dialog to configure specific 
 *  printer settings.
 *
 *  NOTE: This interface is considered private and should not be used by 
 *  applications directly!
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
 *      Andreas J. Guelzow <aguelzow@taliesin.ca>
 *
 *  Copyright (C) 2003  Andreas J. Guelzow
 *
 */

#ifndef __GNOME_PRINT_CONFIG_DIALOG_H__
#define __GNOME_PRINT_CONFIG_DIALOG_H__

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_PRINT_CONFIG_DIALOG         (gnome_print_config_dialog_get_type ())
#define GNOME_PRINT_CONFIG_DIALOG(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_CONFIG_DIALOG, GnomePrintConfigDialog))
#define GNOME_PRINT_CONFIG_DIALOG_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST    ((k), GNOME_TYPE_PRINT_CONFIG_DIALOG, GnomePrintConfigDialogClass))
#define GNOME_IS_PRINT_CONFIG_DIALOG(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_CONFIG_DIALOG))
#define GNOME_IS_PRINT_CONFIG_DIALOG_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE    ((o), GNOME_TYPE_PRINT_CONFIG_DIALOG))
#define GNOME_PRINT_CONFIG_DIALOG_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS  ((o), GNOME_TYPE_PRINT_CONFIG_DIALOG), GnomePrintConfigDialogClass)

typedef struct _GnomePrintConfigDialog      GnomePrintConfigDialog;
typedef struct _GnomePrintConfigDialogClass GnomePrintConfigDialogClass;

#include <gtk/gtk.h>
#include <libgnomeprint/gnome-print-job.h>

GType gnome_print_config_dialog_get_type (void);

GtkWidget * gnome_print_config_dialog_new (GnomePrintConfig *gpc);

/* For language bindings */
void gnome_print_config_dialog_construct (GnomePrintConfigDialog *gpd);

G_END_DECLS

#endif /* __GNOME_PRINT_CONFIG_DIALOG_H__ */
