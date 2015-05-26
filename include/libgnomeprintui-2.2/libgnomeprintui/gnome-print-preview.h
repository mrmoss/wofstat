/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

#ifndef __GNOME_PRINT_PREVIEW_H__
#define __GNOME_PRINT_PREVIEW_H__

/*
 *  gnome-print-preview.h: print preview driver
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
 *    Miguel de Icaza <miguel@ximian.com>
 *    Lauris Kaplinski <lauris@ximian.com>
 *
 *  Copyright (C) 1999-2002 Ximian Inc. and authors
 *
 */

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_PRINT_PREVIEW         (gnome_print_preview_get_type ())
#define GNOME_PRINT_PREVIEW(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_PREVIEW, GnomePrintPreview))
#define GNOME_PRINT_PREVIEW_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST ((k),    GNOME_TYPE_PRINT_PREVIEW, GnomePrintPreviewClass))
#define GNOME_IS_PRINT_PREVIEW(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_PREVIEW))
#define GNOME_IS_PRINT_PREVIEW_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k),    GNOME_TYPE_PRINT_PREVIEW))
#define GNOME_PRINT_PREVIEW_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o),  GNOME_TYPE_PRINT_PREVIEW, GnomePrintPreviewClass))

typedef struct _GnomePrintPreview      GnomePrintPreview;
typedef struct _GnomePrintPreviewClass GnomePrintPreviewClass;

#include <libgnomecanvas/libgnomecanvas.h>
#include <libgnomeprint/gnome-print-paper.h>
#include <libgnomeprint/gnome-print.h>

GType gnome_print_preview_get_type  (void);

GnomePrintContext * gnome_print_preview_new      (GnomePrintConfig *config, GnomeCanvas *canvas);
GnomePrintContext * gnome_print_preview_new_full (GnomePrintConfig *config, GnomeCanvas *canvas,
						  const gdouble *transform, const ArtDRect *region);

G_END_DECLS

#endif /* __GNOME_PRINT_PREVIEW_H__ */

