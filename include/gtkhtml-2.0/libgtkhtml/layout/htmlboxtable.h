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

#ifndef __HTMLBOXTABLE_H__
#define __HTMLBOXTABLE_H__

#include <gdk/gdk.h>
#include "htmlbox.h"
#include "htmlboxtablerow.h"
#include "htmlboxtablecaption.h"

G_BEGIN_DECLS

typedef struct _HtmlBoxTable HtmlBoxTable;
typedef struct _HtmlBoxTableClass HtmlBoxTableClass;

#define HTML_TYPE_BOX_TABLE (html_box_table_get_type ())
#define HTML_BOX_TABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_TABLE, HtmlBoxTable))
#define HTML_BOX_TABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_TABLE, HtmlBoxTableClasss))
#define HTML_IS_BOX_TABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_TABLE))
#define HTML_IS_BOX_TABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_TABLE))

typedef struct {
	HtmlLength style_width;	
	gint min;
	gint max;
	gint width;
} ColumnInfo;


struct _HtmlBoxTable {
	HtmlBox parent_object;

	/* Lists containing the rows */
	GSList *body_list;
	GSList *header_list;
	GSList *footer_list;
	/* The number of rows and cols in this table */
	gint rows, cols;
	/* An array with pointers to all cells in this table */
	HtmlBox **cells;
	/* The max and min width of each cell */
	gint *min_width, *max_width;
	/* The height of each row in the table*/
	gint *row_height;
	/* Info about the columns*/
	ColumnInfo *col_info;
	/* The table caption if any */
	HtmlBoxTableCaption *caption;
	/* FALSE if the info cache has to be updated */
	gboolean up_to_date:1;

	gboolean cell_border:1;
	gint16 cell_padding;
};

struct _HtmlBoxTableClass {
	HtmlBoxClass parent_class;
};

GType html_box_table_get_type (void);
HtmlBox *html_box_table_new (void);

void html_box_table_remove_row     (HtmlBoxTable *table, HtmlBoxTableRow *row);
void html_box_table_remove_caption (HtmlBoxTable *table, HtmlBoxTableCaption *caption);

void html_box_table_add_thead (HtmlBoxTable *table, HtmlBoxTableRow *row);
void html_box_table_add_tbody (HtmlBoxTable *table, HtmlBoxTableRow *row);
void html_box_table_add_tfoot (HtmlBoxTable *table, HtmlBoxTableRow *row);

gint html_box_table_get_top_offset    (HtmlBoxTable *table, gint boxwidth);
gint html_box_table_get_bottom_offset (HtmlBoxTable *table, gint boxwidth);

void html_box_table_cell_added (HtmlBoxTable *table);

G_END_DECLS

#endif /* __HTMLBOXTABLE_H__ */
