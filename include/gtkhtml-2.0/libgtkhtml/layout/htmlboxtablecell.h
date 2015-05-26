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

#ifndef __HTMLBOXTABLECELL_H__
#define __HTMLBOXTABLECELL_H__

#include <gdk/gdk.h>
#include "htmlboxblock.h"

G_BEGIN_DECLS

typedef struct _HtmlBoxTableCell HtmlBoxTableCell;
typedef struct _HtmlBoxTableCellClass HtmlBoxTableCellClass;

#define HTML_TYPE_BOX_TABLE_CELL (html_box_table_cell_get_type ())
#define HTML_BOX_TABLE_CELL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_TABLE_CELL, HtmlBoxTableCell))
#define HTML_BOX_TABLE_CELL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_TABLE_CELL, HtmlBoxTableCellClasss))
#define HTML_IS_BOX_TABLE_CELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_TABLE_CELL))
#define HTML_IS_BOX_TABLE_CELL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_TABLE_CELL))

struct _HtmlBoxTableCell {
	HtmlBoxBlock parent_object;
	HtmlBoxTable *table;
	gint width, height;
	gint rowspan, colspan;
};

struct _HtmlBoxTableCellClass {
	HtmlBoxBlockClass parent_class;
};

GType html_box_table_cell_get_type (void);
HtmlBox *html_box_table_cell_new (void);

gint html_box_table_cell_get_colspan (HtmlBoxTableCell *cell);
gint html_box_table_cell_get_rowspan (HtmlBoxTableCell *cell);

gint html_box_table_cell_get_min_width (HtmlBoxTableCell *cell, HtmlRelayout *relayout);
gint html_box_table_cell_get_max_width (HtmlBoxTableCell *cell, HtmlRelayout *relayout);

void html_box_table_cell_relayout_width (HtmlBoxTableCell *cell, HtmlRelayout *relayout, gint width);
void html_box_table_cell_do_valign      (HtmlBoxTableCell *cell, gint height);

G_END_DECLS

#endif /* __HTMLBOXTABLECELL_H__ */





