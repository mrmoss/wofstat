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

#ifndef __HTMLBOXTABLE_CAPTION_H__
#define __HTMLBOXTABLE_CAPTION_H__

#include <gdk/gdk.h>
#include "htmlboxblock.h"

G_BEGIN_DECLS

typedef struct _HtmlBoxTableCaption HtmlBoxTableCaption;
typedef struct _HtmlBoxTableCaptionClass HtmlBoxTableCaptionClass;

#define HTML_TYPE_BOX_TABLE_CAPTION (html_box_table_caption_get_type ())
#define HTML_BOX_TABLE_CAPTION(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_TABLE_CAPTION, HtmlBoxTableCaption))
#define HTML_BOX_TABLE_CAPTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_TABLE_CAPTION, HtmlBoxTableCaptionClasss))
#define HTML_IS_BOX_TABLE_CAPTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_TABLE_CAPTION))
#define HTML_IS_BOX_TABLE_CAPTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_TABLE_CAPTION))

struct _HtmlBoxTableCaption {
	HtmlBoxBlock parent_object;
	gint width, height;
};

struct _HtmlBoxTableCaptionClass {
	HtmlBoxBlockClass parent_class;
};

GType html_box_table_caption_get_type (void);
HtmlBox *html_box_table_caption_new (void);

void html_box_table_caption_relayout_width (HtmlBoxTableCaption *caption, HtmlRelayout *relayout, gint width);

G_END_DECLS

#endif /* __HTMLBOXTABLE_CAPTION_H__ */





