/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.

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

#ifndef _HTMLENGINE_EDIT_TABLE_CELL_H
#define _HTMLENGINE_EDIT_TABLE_CELL_H

#include "htmltypes.h"
#include "htmlenums.h"

void           html_engine_table_cell_set_bg_color     (HTMLEngine     *e,
							HTMLTableCell  *t,
							GdkColor       *c);
void           html_engine_table_cell_set_bg_pixmap    (HTMLEngine     *e,
							HTMLTableCell  *t,
							gchar          *url);
void           html_engine_table_cell_set_halign       (HTMLEngine     *e,
							HTMLTableCell  *cell,
							HTMLHAlignType  halign);
void           html_engine_table_cell_set_valign       (HTMLEngine     *e,
							HTMLTableCell  *cell,
							HTMLVAlignType  valign);
void           html_engine_table_cell_set_no_wrap      (HTMLEngine     *e,
							HTMLTableCell  *cell,
							gboolean        no_wrap);
void           html_engine_table_cell_set_heading      (HTMLEngine     *e,
							HTMLTableCell  *cell,
							gboolean        heading);
void           html_engine_table_cell_set_width        (HTMLEngine     *e,
							HTMLTableCell  *cell,
							gint            width,
							gboolean        percent);
HTMLTableCell *html_engine_get_table_cell              (HTMLEngine     *e);
void           html_engine_delete_table_cell_contents  (HTMLEngine     *e);			       
void           html_engine_set_cspan                   (HTMLEngine     *e,
							gint            cspan);
void           html_engine_set_rspan                   (HTMLEngine     *e,
							gint            rspan);
gboolean       html_engine_cspan_delta                 (HTMLEngine     *e,
							gint            delta);
gboolean       html_engine_rspan_delta                 (HTMLEngine     *e,
							gint            delta);

#endif
