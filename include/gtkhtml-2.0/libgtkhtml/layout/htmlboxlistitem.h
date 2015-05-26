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

#ifndef __HTMLBOXLISTITEM_H__
#define __HTMLBOXLISTITEM_H__

#include "htmlboxblock.h"

G_BEGIN_DECLS

#define HTML_TYPE_BOX_LIST_ITEM (html_box_list_item_get_type ())
#define HTML_BOX_LIST_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_LIST_ITEM, HtmlBoxListItem))
#define HTML_BOX_LIST_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_LIST_ITEM, HtmlBoxListItemClass))
#define HTML_IS_BOX_LIST_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_LIST_ITEM))
#define HTML_IS_BOX_LIST_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_LIST_ITEM))

typedef struct _HtmlBoxListItem HtmlBoxListItem;
typedef struct _HtmlBoxListItemClass HtmlBoxListItemClass;

struct _HtmlBoxListItem {
	HtmlBoxBlock parent_object;
	gint counter;
	HtmlBox *label;
	gchar *str;
};

struct _HtmlBoxListItemClass {
	HtmlBoxBlockClass parent_class;
};

static char * toRoman (long decimal);

GType    html_box_list_item_get_type (void);

HtmlBox *html_box_list_item_new      (void);

G_END_DECLS

#endif /* __HTMLBOXLIST_ITEM_H__ */


