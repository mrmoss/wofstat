/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.

    Copyright (C) 2000 Helix Code, Inc.
    Copyright (C) 2001 Ximian, Inc.
    Authors: Radek Doulik

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef _HTMLENGINE_EDIT_TABLES_H
#define _HTMLENGINE_EDIT_TABLES_H

#include "htmltypes.h"
#include "htmlenums.h"

void           html_engine_insert_table            (HTMLEngine         *e,
						    gint                cols,
						    gint                rows,
						    gint                width,
						    gint                percent,
						    gint                padding,
						    gint                spacing,
						    gint                border);
void           html_engine_insert_table_1_1        (HTMLEngine         *e);
void           html_engine_insert_table_column     (HTMLEngine         *e,
						    gboolean            after);
void           html_engine_delete_table_column     (HTMLEngine         *e);
void           html_engine_insert_table_row        (HTMLEngine         *e,
						    gboolean            after);
void           html_engine_delete_table_row        (HTMLEngine         *e);
void           html_engine_table_set_border_width  (HTMLEngine         *e,
						    HTMLTable          *t,
						    gint                border_width,
						    gboolean            relative);
void           html_engine_table_set_bg_color      (HTMLEngine         *e,
						    HTMLTable          *t,
						    GdkColor           *c);
void           html_engine_table_set_bg_pixmap     (HTMLEngine         *e,
						    HTMLTable          *t,
						    gchar              *url);
void           html_engine_table_set_spacing       (HTMLEngine         *e,
						    HTMLTable          *t,
						    gint                spacing,
						    gboolean            relative);
void           html_engine_table_set_padding       (HTMLEngine         *e,
						    HTMLTable          *t,
						    gint                padding,
						    gboolean            relative);
void           html_engine_table_set_align         (HTMLEngine         *e,
						    HTMLTable          *t,
						    HTMLHAlignType      align);
void           html_engine_table_set_width         (HTMLEngine         *e,
						    HTMLTable          *t,
						    gint                width,
						    gboolean            percent);
void           html_engine_table_set_cols          (HTMLEngine         *e,
						    gint                cols);
void           html_engine_table_set_rows          (HTMLEngine         *e,
						    gint                rows);
HTMLTable     *html_engine_get_table               (HTMLEngine         *e);
gboolean       html_engine_goto_table_0            (HTMLEngine         *e,
						    HTMLTable          *table);
gboolean       html_engine_goto_table              (HTMLEngine         *e,
						    HTMLTable          *table,
						    gint                row,
						    gint                col);
gboolean       html_engine_table_goto_col          (HTMLEngine         *e,
						    HTMLTable          *table,
						    gint                col);
gboolean       html_engine_table_goto_row          (HTMLEngine         *e,
						    HTMLTable          *table,
						    gint                row);
void           html_engine_delete_table            (HTMLEngine         *e);
HTMLTableCell *html_engine_new_cell                (HTMLEngine         *e,
						    HTMLTable          *table);
void           html_table_insert_row               (HTMLTable          *table,
						    HTMLEngine         *e,
						    gint                row,
						    HTMLTableCell     **row_cells,
						    HTMLUndoDirection   dir);
void           html_table_insert_column            (HTMLTable          *table,
						    HTMLEngine         *e,
						    gint                col,
						    HTMLTableCell     **column,
						    HTMLUndoDirection   dir);
void           html_table_delete_column            (HTMLTable          *t,
						    HTMLEngine         *e,
						    gint                col,
						    HTMLUndoDirection   dir);
void           html_table_delete_row               (HTMLTable          *t,
						    HTMLEngine         *e,
						    gint                row,
						    HTMLUndoDirection   dir);

#endif
