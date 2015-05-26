/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000-2001 CodeFactory AB
   Copyright (C) 2000-2001 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2000-2001 Anders Carlsson <andersca@codefactory.se>
   
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

#ifndef __HTMLVIEW_H__
#define __HTMLVIEW_H__

typedef struct _HtmlView HtmlView;
typedef struct _HtmlViewClass HtmlViewClass;

#include <gtk/gtk.h>

#include <libgtkhtml/document/htmldocument.h>
#include <libgtkhtml/document/htmlparser.h>
#include <libgtkhtml/layout/htmlbox.h>
#include <libgtkhtml/layout/html/htmlembedded.h>
#include <libgtkhtml/util/htmlstream.h>

G_BEGIN_DECLS

#define HTML_TYPE_VIEW         (html_view_get_type ())
#define HTML_VIEW(obj)         (GTK_CHECK_CAST ((obj), HTML_TYPE_VIEW, HtmlView))
#define HTML_VIEW_CLASS(klass) (GTK_CHECK_CLASS_CAST ((klass), HTML_TYPE_VIEW, HtmlViewClass))
#define HTML_IS_VIEW(obj)      (GTK_CHECK_TYPE ((obj), HTML_TYPE_VIEW))

typedef enum {
	HTML_VIEW_SCROLL_TO_TOP,
	HTML_VIEW_SCROLL_TO_BOTTOM
} HtmlViewScrollToType;

struct _HtmlView {
	GtkLayout parent;


	HtmlDocument *document;

	HtmlBox *root;
	
	GHashTable *node_table;

	HtmlPainter *painter;

	guint relayout_idle_id;
	guint relayout_timeout_id;

	gint mouse_down_x, mouse_down_y;
	gint mouse_detail;

	/* Begin selection */
	HtmlBox *sel_start;
	gint     sel_start_ypos;
	gint     sel_start_index;

	HtmlBox *sel_end;
	gint     sel_end_ypos;
	gint     sel_end_index;

	gboolean sel_flag;
	gboolean sel_backwards;
	gboolean sel_start_found;

	GSList *sel_list;
	/* End selection */

	/* Anchor jumping */
	gchar   *jump_to_anchor;

	gdouble magnification;
	gboolean magnification_modified;
	gboolean on_url;
};

struct _HtmlViewClass {
	GtkLayoutClass parent;

	/* move insertion point */
	void (* move_cursor) (HtmlView       *html_view,
			      GtkMovementStep step,
			      gint            count,
			      gboolean        extend_selection);

	gboolean (* request_object) (HtmlView *html_view, HtmlEmbedded *widget);
	void (*on_url) (HtmlView *html_view, const gchar *url);
	void (*activate) (HtmlView *html_view);
	void (* move_focus_out) (HtmlView         *html_view,
				 GtkDirectionType  direction);
};

GType html_view_get_type (void);

GtkWidget *html_view_new               (void);
void       html_view_set_document      (HtmlView *view, HtmlDocument *document);
void       html_view_jump_to_anchor    (HtmlView *view, const gchar *anchor);

gdouble    html_view_get_magnification (HtmlView *view);
void       html_view_set_magnification (HtmlView *view,
					gdouble magnification);

void       html_view_zoom_in           (HtmlView *view);
void       html_view_zoom_out          (HtmlView *view);
void       html_view_zoom_reset        (HtmlView *view);

HtmlBox *  html_view_find_layout_box   (HtmlView *view, DomNode *node, gboolean find_parent);

void       html_view_scroll_to_node    (HtmlView *view, DomNode *node, HtmlViewScrollToType type);


G_END_DECLS

#endif /* __HTMLVIEW_H__ */
