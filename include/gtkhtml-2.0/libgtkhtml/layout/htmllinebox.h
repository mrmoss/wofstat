/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000 CodeFactory AB
   Copyright (C) 2000 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2000 Anders Carlsson <andersca@codefactory.se>
   
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

#ifndef __HTMLLINEBOX_H__
#define __HTMLLINEBOX_H__

#include <glib.h>

typedef struct _HtmlLineBox HtmlLineBox;

typedef enum {
	HTML_INLINE_LINE_BOX_TYPE,
	HTML_BLOCK_LINE_BOX_TYPE
} HtmlLineBoxType;

typedef enum {
	HTML_LINE_BOX_FULL = 0,
	HTML_LINE_BOX_NOT_FULL,
	HTML_LINE_BOX_DOES_NOT_FIT
} HtmlLineBoxState;

struct _HtmlLineBox {
	HtmlLineBoxType type; /* What type of line is it? */

	gint width, height;

	GSList *item_list; /* A list of the boxes on this line */

	HtmlLineBox *next; /* A pointer to the next line */

	gint full_width;
};

void html_line_box_destroy (HtmlLineBox *line);
HtmlLineBox *html_line_box_new (HtmlLineBoxType type);

void html_line_box_init (HtmlLineBox *line);
void html_line_box_close (HtmlLineBox *line, HtmlBox *parent, gint left_margin, gint max_width, gint boxwidth);
HtmlLineBoxState html_line_box_add_inlines (HtmlLineBox *line, HtmlRelayout *relayout, HtmlBox *box, HtmlBox **next_box, HtmlBox *parent, GSList **iterator, 
					    gint y, gint left_margin, gint max_width, GSList **float_list, gint boxwidth);

void html_line_box_add_block (HtmlLineBox *line, HtmlRelayout *relayout, HtmlBox *box, gint y, gboolean force_relayout, gint *old_margin, gint boxwidth);

#endif /* __HTMLLINEBOX_H__ */










