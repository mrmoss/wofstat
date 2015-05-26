/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of GtkHTML.

   Copyright (C) 1997 Martin Jones (mjones@kde.org)
   Copyright (C) 1997 Torben Weis (weis@kde.org)
   Copyright (C) 2000 Helix Code, Inc.
   
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

#ifndef _HTMLTABLECELL_H_
#define _HTMLTABLECELL_H_

#include <gdk/gdkcolor.h>

#include "htmlcluev.h"
#include "htmlimage.h"

#define HTML_TABLE_CELL(x) ((HTMLTableCell *)(x))
#define HTML_TABLE_CELL_CLASS(x) ((HTMLTableCellClass *)(x))
#define HTML_IS_TABLE_CELL(x) (HTML_OBJECT_TYPE (x) == HTML_TYPE_TABLECELL)

struct _HTMLTableCell {
	HTMLClueV cluev;

	gint fixed_width;
	gint fixed_height;
	gboolean percent_width  : 1;
	gboolean percent_height : 1;
	gboolean no_wrap;
	gboolean heading;

	gint rspan;
	gint cspan;
	gint row;
	gint col;

	GdkColor bg;
	guint have_bg : 1;
	guint bg_allocated : 1;

	HTMLImagePointer *bgPixmap;
	gboolean have_bgPixmap;
};

struct _HTMLTableCellClass {
	HTMLClueVClass cluev_class;
};

extern HTMLTableCellClass html_table_cell_class;

void        html_table_cell_type_init         (void);
void        html_table_cell_class_init        (HTMLTableCellClass *klass,
					       HTMLType            type,
					       guint               object_size);
void        html_table_cell_init              (HTMLTableCell      *cell,
					       HTMLTableCellClass *klass,
					       gint                rs,
					       gint                cs,
					       gint                pad);
HTMLObject *html_table_cell_new               (gint                rs,
					       gint                cs,
					       gint                pad);
void        html_table_cell_set_fixed_width   (HTMLTableCell      *cell,
					       gint                width,
					       gboolean            percented);
void        html_table_cell_set_fixed_height  (HTMLTableCell      *cell,
					       gint                height,
					       gboolean            percented);
void        html_table_cell_set_bg_pixmap     (HTMLTableCell      *cell,
					       HTMLImagePointer   *imagePtr);
void        html_table_cell_set_position      (HTMLTableCell      *cell,
					       gint                row,
					       gint                col);
gint        html_table_cell_get_fixed_width   (HTMLTableCell      *cell,
					       HTMLPainter        *painter);
gboolean    html_table_cell_is_empty          (HTMLTableCell      *cell);

#endif /* _HTMLTABLECELL_H_ */
