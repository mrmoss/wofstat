/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000,2001 CodeFactory AB
   Copyright (C) 2000,2001 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2000,2001 Anders Carlsson <andersca@codefactory.se>
   
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

#ifndef __HTMLRELAYOUT_H__
#define __HTMLRELAYOUT_H__

#include <libgtkhtml/graphics/htmlpainter.h>

typedef struct _HtmlFloatBox HtmlFloatBox;
typedef struct _HtmlRelayout HtmlRelayout;

typedef enum {
	HTML_RELAYOUT_FULL,
	HTML_RELAYOUT_INCREMENTAL
} HtmlRelayoutType;

struct _HtmlRelayout {
	HtmlRelayoutType type;

	HtmlPainter *painter;

	HtmlBox *root;

	gboolean get_min_width; /* This flag is TRUE when we want to
				   know the box min size */
	gboolean get_max_width; /* This flag is TRUE when we want to
				   know the box max size */

	gint max_width; /* This variable is used to specify the maximum desired width,
			 * currently only used by html_box_line and html_box_text */

	gboolean preserve_leading_space;
	gboolean line_is_empty;
	gint line_offset;      /* The current character position for this line,
			        * used when calculating the tab position 
				*/
	gint text_item_length; /* almost always == text->length, unless
				* the text contains tabs. We keep it here
				* instead of in the HtmlBoxText struct to
				* save some memory 
				*/

	gdouble magnification;
	gboolean magnification_modified;
};

HtmlRelayout *html_relayout_new (void);
void html_relayout_destroy (HtmlRelayout *relayout);

void html_relayout_make_fit_left  (HtmlBox *parent, HtmlRelayout *relayout, HtmlBox *box, gint width, gint y);
void html_relayout_make_fit_right (HtmlBox *parent, HtmlRelayout *relayout, HtmlBox *box, gint width, gint y);

gint html_relayout_get_left_margin (HtmlRelayout *relayout, HtmlBox *self, gint width, gint height, gint y);
gint html_relayout_get_left_margin_ignore (HtmlRelayout *relayout, HtmlBox *self, gint width, gint height, gint y, HtmlBox *ignore);
gint html_relayout_get_max_width (HtmlRelayout *relayout, HtmlBox *box, gint width, gint height, gint y);
gint html_relayout_get_max_width_ignore (HtmlRelayout *relayout, HtmlBox *box, gint width, gint height, gint y, HtmlBox *ignore);
gint html_relayout_next_float_offset (HtmlRelayout *relayout, HtmlBox *box, gint y, gint width, gint height);

#endif /* __HTMLRELAYOUT_H__ */
