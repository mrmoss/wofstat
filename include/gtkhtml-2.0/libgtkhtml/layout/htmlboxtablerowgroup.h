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

#ifndef __HTMLBOXTABLE_ROW_GROUP_H__
#define __HTMLBOXTABLE_ROW_GROUP_H__

#include <gdk/gdk.h>
#include "htmlbox.h"

G_BEGIN_DECLS

typedef struct _HtmlBoxTableRowGroup HtmlBoxTableRowGroup;
typedef struct _HtmlBoxTableRowGroupClass HtmlBoxTableRowGroupClass;

#define HTML_TYPE_BOX_TABLE_ROW_GROUP (html_box_table_row_group_get_type ())
#define HTML_BOX_TABLE_ROW_GROUP(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_TABLE_ROW_GROUP, HtmlBoxTableRowGroup))
#define HTML_BOX_TABLE_ROW_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_TABLE_ROW_GROUP, HtmlBoxTableRowGroupClasss))
#define HTML_IS_BOX_TABLE_ROW_GROUP(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_TABLE_ROW_GROUP))
#define HTML_IS_BOX_TABLE_ROW_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_TABLE_ROW_GROUP))

struct _HtmlBoxTableRowGroup {
	HtmlBox parent_object;
	HtmlDisplayType type;
};

struct _HtmlBoxTableRowGroupClass {
	HtmlBoxClass parent_class;
};

GType    html_box_table_row_group_get_type (void);
HtmlBox *html_box_table_row_group_new      (HtmlDisplayType type);

G_END_DECLS

#endif /* __HTMLBOXTABLE_ROW_GROUP_H__ */
