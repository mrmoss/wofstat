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

#ifndef __HTMLBOXEMBEDDED_H__
#define __HTMLBOXEMBEDDED_H__

typedef struct _HtmlBoxEmbedded HtmlBoxEmbedded;
typedef struct _HtmlBoxEmbeddedClass HtmlBoxEmbeddedClass;

#include <glib.h>

#include <libgtkhtml/graphics/htmlpainter.h>
#include <libgtkhtml/layout/htmlbox.h>
#include <libgtkhtml/layout/html/htmlboxform.h>
#include <libgtkhtml/view/htmlview.h>

G_BEGIN_DECLS

#define HTML_TYPE_BOX_EMBEDDED (html_box_embedded_get_type ())
#define HTML_BOX_EMBEDDED(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_EMBEDDED, HtmlBoxEmbedded))
#define HTML_BOX_EMBEDDED_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_EMBEDDED, HtmlBoxEmbeddedClass))
#define HTML_IS_BOX_EMBEDDED(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_EMBEDDED))
#define HTML_IS_BOX_EMBEDDED_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_EMBEDDED))
#define HTML_BOX_EMBEDDED_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), HTML_TYPE_BOX_EMBEDDED, HtmlBoxEmbeddedClass))

struct _HtmlBoxEmbedded {
	HtmlBox parent_object;
	GtkWidget *widget;

	gint abs_x, abs_y;
	gint descent;

	HtmlBoxForm *form;

	HtmlView *view;
};

struct _HtmlBoxEmbeddedClass {
	HtmlBoxClass parent_class;
};

GType    html_box_embedded_get_type (void);
HtmlBox *html_box_embedded_new      (void);

gint html_box_embedded_get_descent (HtmlBoxEmbedded *embeddded);
void html_box_embedded_set_descent (HtmlBoxEmbedded *embeddded, gint descent);
void html_box_embedded_set_view    (HtmlBoxEmbedded *embedded, HtmlView *view);
void html_box_embedded_set_widget  (HtmlBoxEmbedded *embedded, GtkWidget *widget);

G_END_DECLS

#endif /* __HTMLBOXEMBEDDED_H__ */
