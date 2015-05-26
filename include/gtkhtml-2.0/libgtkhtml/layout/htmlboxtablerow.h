/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000 CodeFactory AB
   Copyright (C) 2000 Jonas Borgstr\366m <jonas@codefactory.se>
   Copyright (C) 2000 Anders Carlsson <andersca@codefactory.se>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef __HTMLBOXTABLE_ROW_H__
#define __HTMLBOXTABLE_ROW_H__

#include <gdk/gdk.h>
#include "htmlbox.h"

G_BEGIN_DECLS

typedef struct _HtmlBoxTableRow HtmlBoxTableRow;
typedef struct _HtmlBoxTableRowClass HtmlBoxTableRowClass;

#define HTML_TYPE_BOX_TABLE_ROW (html_box_table_row_get_type ())
#define HTML_BOX_TABLE_ROW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_TABLE_ROW, HtmlBoxTableRow))
#define HTML_BOX_TABLE_ROW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_TABLE_ROW, HtmlBoxTableRowClasss))
#define HTML_IS_BOX_TABLE_ROW(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_TABLE_ROW))
#define HTML_IS_BOX_TABLE_ROW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_TABLE_ROW))

struct _HtmlBoxTableRow {
	HtmlBox parent_object;
};

struct _HtmlBoxTableRowClass {
	HtmlBoxClass parent_class;
};

GType html_box_table_row_get_type (void);
HtmlBox *html_box_table_row_new (void);

gint html_box_table_row_get_num_cols     (HtmlBox *self, gint rownum);
gint html_box_table_row_update_spaninfo  (HtmlBoxTableRow *row, gint *spaninfo);
gint html_box_table_row_fill_cells_array (HtmlBox *self, HtmlBox **cells, gint *spaninfo);

G_END_DECLS

#endif /* __HTMLBOXTABLE_ROW_H__ */
