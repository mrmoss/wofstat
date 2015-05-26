#ifndef __GNOME_PRINT_MASTER_PREVIEW_H__
#define __GNOME_PRINT_MASTER_PREVIEW_H__

/*
 *  Copyright (C) 2000-2001 Ximian Inc.
 *
 *  Authors: Michael Zucchi <notzed@ximian.com>
 *           Miguel de Icaza (miguel@gnu.org)
 *
 *  A system print interface.
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

#define GNOME_TYPE_PRINT_MASTER_PREVIEW (gnome_print_master_preview_get_type ())
#define GNOME_PRINT_MASTER_PREVIEW(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_MASTER_PREVIEW, GnomePrintMasterPreview))
#define GNOME_PRINT_MASTER_PREVIEW_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_PRINT_MASTER_PREVIEW, GnomePrintMasterPreviewClass))
#define GNOME_IS_PRINT_MASTER_PREVIEW(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_MASTER_PREVIEW))
#define GNOME_IS_PRINT_MASTER_PREVIEW_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_PRINT_MASTER_PREVIEW))
#define GNOME_PRINT_MASTER_PREVIEW_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PRINT_MASTER_PREVIEW, GnomePrintMasterPreviewClass))

typedef struct _GnomePrintMasterPreview GnomePrintMasterPreview;
typedef struct _GnomePrintMasterPreviewClass GnomePrintMasterPreviewClass;

#include <gtk/gtkwindow.h>
#include <libgnomeprint/gnome-print-master.h>
#include <libgnomeprintui/gnome-print-preview.h>

GtkType gnome_print_master_preview_get_type (void);

GtkWidget *gnome_print_master_preview_new (GnomePrintMaster *gpm, const guchar *title);

G_END_DECLS

#endif /* GNOME_PRINT_MASTER_PREVIEW_H */

