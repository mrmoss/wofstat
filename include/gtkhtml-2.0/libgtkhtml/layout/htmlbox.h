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

#ifndef __HTMLBOX_H__
#define __HTMLBOX_H__

typedef struct _HtmlBox HtmlBox;
typedef struct _HtmlBoxClass HtmlBoxClass;

#include <libgtkhtml/dom/core/dom-node.h>
#include <libgtkhtml/layout/htmlstyle.h>
#include <libgtkhtml/layout/htmlrelayout.h>

G_BEGIN_DECLS

#define HTML_TYPE_BOX (html_box_get_type ())
#define HTML_BOX(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX, HtmlBox))
#define HTML_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX, HtmlBoxClass))
#define HTML_IS_BOX(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX))
#define HTML_IS_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX))
#define HTML_BOX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), HTML_TYPE_BOX, HtmlBoxClass))
#define HTML_BOX_GET_STYLE(box) (box->dom_node ? box->dom_node->style : box->style)

struct _HtmlBox {
	GObject parent_object;

	gboolean is_relayouted:1;

	gint x, y;
	gint width, height;

	DomNode *dom_node;
	
	HtmlBox *next;
	HtmlBox *prev;
	HtmlBox *children;
	HtmlBox *parent;

	HtmlStyle *style;
};

struct _HtmlBoxClass {
	GObjectClass parent_class;

	void (*relayout) (HtmlBox *self, HtmlRelayout *relayout);
	void (*paint) (HtmlBox *self, HtmlPainter *painter, GdkRectangle *area, gint tx, gint ty);
	gint (*get_ascent) (HtmlBox *self);
	gint (*get_descent) (HtmlBox *self);
	gint (*get_bidi_level) (HtmlBox *self);
	void (*append_child) (HtmlBox *self, HtmlBox *child);
	gint (*top_mbp_sum) (HtmlBox *box, gint width);
	gint (*bottom_mbp_sum) (HtmlBox *box, gint width);
	gint (*left_mbp_sum) (HtmlBox *box, gint width);
	gint (*right_mbp_sum) (HtmlBox *box, gint width);
	void (*remove) (HtmlBox *box);
	gboolean (*should_paint) (HtmlBox *box, GdkRectangle *area, gint tx, gint ty);
  
	gboolean (*handles_events) (HtmlBox *self);
	
	void (*handle_html_properties) (HtmlBox *self, xmlNode *node);
};

GType html_box_get_type (void);

void html_box_append_child (HtmlBox *self, HtmlBox *child);
void html_box_remove       (HtmlBox *self);
void html_box_insert_after (HtmlBox *self, HtmlBox *box);

gint html_box_horizontal_mbp_sum         (HtmlBox *box);
gint html_box_vertical_mbp_sum           (HtmlBox *box);
gint html_box_top_mbp_sum                (HtmlBox *box, gint width);
gint html_box_bottom_mbp_sum             (HtmlBox *box, gint width);
gint html_box_left_mbp_sum               (HtmlBox *box, gint width);
gint html_box_right_mbp_sum              (HtmlBox *box, gint width);
gint html_box_get_absolute_x             (HtmlBox *box);
gint html_box_get_absolute_y             (HtmlBox *box);
void html_box_check_min_max_width_height (HtmlBox *self, gint *boxwidth, gint *boxheight);
void html_box_set_style                  (HtmlBox *box, HtmlStyle *style);

void html_box_relayout (HtmlBox *self, HtmlRelayout *relayout);
void html_box_paint    (HtmlBox *self, HtmlPainter *painter, GdkRectangle *area, gint tx, gint ty);

gint       html_box_get_ascent            (HtmlBox *self);
gint       html_box_get_descent           (HtmlBox *self);
HtmlStyle *html_box_get_style             (HtmlBox *self);
gint       html_box_get_bidi_level        (HtmlBox *self);
void       html_box_set_unrelayouted_up   (HtmlBox *self);
void       html_box_set_unrelayouted_down (HtmlBox *self);

gint html_box_get_containing_block_width  (HtmlBox *box);
gint html_box_get_containing_block_height (HtmlBox *box);

void html_box_apply_positioned_offset (HtmlBox *box, gint *tx, gint *ty);

gint html_box_left_margin         (HtmlBox *box, gint width);
gint html_box_left_padding        (HtmlBox *box, gint width);
gint html_box_left_border_width   (HtmlBox *box);
gint html_box_top_margin          (HtmlBox *box, gint width);
gint html_box_top_padding         (HtmlBox *box, gint width);
gint html_box_top_border_width    (HtmlBox *box);
gint html_box_right_margin        (HtmlBox *box, gint width);
gint html_box_right_padding       (HtmlBox *box, gint width);
gint html_box_right_border_width  (HtmlBox *box);
gint html_box_bottom_padding      (HtmlBox *box, gint width);
gint html_box_bottom_margin       (HtmlBox *box, gint width);
gint html_box_bottom_border_width (HtmlBox *box);

gboolean html_box_is_parent (HtmlBox *self, HtmlBox *parent);

gboolean html_box_handles_events         (HtmlBox *self);
void     html_box_handle_html_properties (HtmlBox *box, xmlNode *n);
HtmlBox *html_box_get_containing_block   (HtmlBox *box);

HtmlBox *html_box_get_after    (HtmlBox *box);
HtmlBox *html_box_get_before   (HtmlBox *box);
void     html_box_set_after    (HtmlBox *box, HtmlBox *before);
void     html_box_set_before   (HtmlBox *box, HtmlBox *before);
gboolean html_box_should_paint (HtmlBox *box, GdkRectangle *area, gint tx, gint ty);

G_END_DECLS

#endif /* __HTMLBOX_H__ */
