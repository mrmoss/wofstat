/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2001 CodeFactory AB
   Copyright (C) 2001 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2001 Anders Carlsson <andersca@codefactory.se>
   
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

#ifndef __HTMLEMBEDDED_H__
#define __HTMLEMBEDDED_H__

typedef struct _HtmlEmbedded HtmlEmbedded;
typedef struct _HtmlEmbeddedClass HtmlEmbeddedClass;

#include <gtk/gtk.h>
#include <libgtkhtml/dom/core/dom-node.h>
#include <libgtkhtml/layout/html/htmlboxembedded.h>

G_BEGIN_DECLS

#define HTML_TYPE_EMBEDDED (html_embedded_get_type ())
#define HTML_EMBEDDED(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_EMBEDDED, HtmlEmbedded))
#define HTML_EMBEDDED_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_EMBEDDED, HtmlEmbeddedClasss))
#define HTML_IS_EMBEDDED(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_EMBEDDED))
#define HTML_IS_EMBEDDED_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_EMBEDDED))

struct _HtmlEmbedded {
	GtkBin parent_object;
	DomNode *node;
	HtmlBoxEmbedded *box_embedded;
};

struct _HtmlEmbeddedClass {
	GtkBinClass parent_class;
};

GType    html_embedded_get_type     (void);
DomNode *html_embedded_get_dom_node (HtmlEmbedded *embedded);
void     html_embedded_set_descent  (HtmlEmbedded *embedded, gint descent);
gint     html_embedded_get_descent  (HtmlEmbedded *embedded);

GtkWidget *html_embedded_new (DomNode *node, HtmlBoxEmbedded *box_embedded);

G_END_DECLS

#endif /* __HTMLEMBEDDED_H__ */
