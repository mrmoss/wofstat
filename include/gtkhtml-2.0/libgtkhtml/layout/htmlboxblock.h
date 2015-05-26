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

#ifndef __HTMLBOXBLOCK_H__
#define __HTMLBOXBLOCK_H__

#include <gdk/gdk.h>
#include <libgtkhtml/layout/htmlbox.h>
#include <libgtkhtml/layout/htmllinebox.h>

G_BEGIN_DECLS

typedef struct _HtmlBoxBlock HtmlBoxBlock;
typedef struct _HtmlBoxBlockClass HtmlBoxBlockClass;

#define HTML_TYPE_BOX_BLOCK (html_box_block_get_type ())
#define HTML_BOX_BLOCK(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_BLOCK, HtmlBoxBlock))
#define HTML_BOX_BLOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_BLOCK, HtmlBoxBlockClasss))
#define HTML_IS_BOX_BLOCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_BLOCK))
#define HTML_IS_BOX_BLOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_BLOCK))
#define HTML_BOX_BLOCK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), HTML_TYPE_BOX_BLOCK, HtmlBoxBlockClass))

struct _HtmlBoxBlock {
	HtmlBox parent_object;
	HtmlLineBox *line;
	gboolean force_relayout:1;
	gboolean last_was_min_max:1;

	gint float_magic_value;
	gint full_width;
	gint containing_width;
};

struct _HtmlBoxBlockClass {
	HtmlBoxClass parent_class;
	void (*get_boundaries) (HtmlBox *self, HtmlRelayout *relayout, gint *boxwidth, gint *boxheight);
	void (*update_geometry) (HtmlBox *self, HtmlRelayout *relayout, HtmlLineBox *line, gint *y, gint *boxwidth, gint *boxheight);
};

GType    html_box_block_get_type (void);
HtmlBox *html_box_block_new      (void);

gint html_box_block_calculate_float_magic (HtmlBox *self, HtmlRelayout *relayout);
gint html_box_block_get_containing_width  (HtmlBoxBlock *self);

G_END_DECLS

#endif /* __HTMLBOXBLOCK_H__ */
