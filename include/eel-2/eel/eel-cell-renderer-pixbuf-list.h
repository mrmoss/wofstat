/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* eel-cell-renderer-pixbuf-list.h - A cell renderer for pixbuf lists 

   Copyright (C) 2002 Anders Carlsson <andersca@gnu.org>

   The Gnome Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Gnome Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Gnome Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Author: Anders Carlsson <andersca@gnu.org>
*/

#ifndef EEL_CELL_RENDERER_PIXBUF_LIST_H
#define EEL_CELL_RENDERER_PIXBUF_LIST_H

#include <gtk/gtkcellrenderer.h>

G_BEGIN_DECLS

#define EEL_TYPE_CELL_RENDERER_PIXBUF_LIST         (eel_cell_renderer_pixbuf_list_get_type ())
#define EEL_CELL_RENDERER_PIXBUF_LIST(obj)         (GTK_CHECK_CAST ((obj), EEL_TYPE_CELL_RENDERER_PIXBUF_LIST, EelCellRendererPixbufList))
#define EEL_CELL_RENDERER_PIXBUF_LIST_CLASS(klass) (GTK_CHECK_CLASS_CAST ((klass), EEL_TYPE_CELL_RENDERER_PIXBUF_LIST, EelCellRendererPixbufListClass))
#define EEL_IS_CELL_RENDERER_PIXBUF_LIST(obj)      (GTK_CHECK_TYPE ((obj), EEL_TYPE_CELL_RENDERER_PIXBUF_LIST))

typedef struct EelCellRendererPixbufList        EelCellRendererPixbufList;
typedef struct EelCellRendererPixbufListClass   EelCellRendererPixbufListClass;
typedef struct EelCellRendererPixbufListDetails EelCellRendererPixbufListDetails;

struct EelCellRendererPixbufList
{
	GtkCellRenderer parent_instance;

	EelCellRendererPixbufListDetails *details;
};

struct EelCellRendererPixbufListClass
{
	GtkCellRendererClass parent_class;
};

GtkType          eel_cell_renderer_pixbuf_list_get_type (void);
GtkCellRenderer *eel_cell_renderer_pixbuf_list_new      (void);

G_END_DECLS

#endif /* EEL_CELL_RENDERER_PIXBUF_LIST_H */
