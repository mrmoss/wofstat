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

#ifndef __HTMLDOCUMENT_H__
#define __HTMLDOCUMENT_H__

typedef struct _HtmlDocument HtmlDocument;
typedef struct _HtmlDocumentClass HtmlDocumentClass;

#include <gtk/gtk.h>

#include <libgtkhtml/dom/dom-types.h>
#include <libgtkhtml/document/htmlparser.h>
#include <libgtkhtml/util/htmlstream.h>
#include <libgtkhtml/layout/htmlstyle.h>
#include <libgtkhtml/graphics/htmlimagefactory.h>

G_BEGIN_DECLS

#define HTML_TYPE_DOCUMENT         (html_document_get_type ())
#define HTML_DOCUMENT(obj)         (GTK_CHECK_CAST ((obj), HTML_TYPE_DOCUMENT, HtmlDocument))
#define HTML_DOCUMENT_CLASS(klass) (GTK_CHECK_CLASS_CAST ((klass), HTML_TYPE_DOCUMENT, HtmlDocumentClass))
#define HTML_IS_DOCUMENT(obj)      (GTK_CHECK_TYPE ((obj), HTML_TYPE_DOCUMENT))

typedef enum {
	HTML_DOCUMENT_STATE_DONE,
	HTML_DOCUMENT_STATE_PARSING
} HtmlDocumentState;

struct _HtmlDocument {
	GObject parent_instance;
	
	DomDocument *dom_document;
	
	GSList *stylesheets;

	HtmlParser *parser;
	HtmlStream *current_stream;

	HtmlImageFactory *image_factory;

	HtmlDocumentState state;

	DomNode *hover_node;
	DomNode *active_node;
	DomElement *focus_element;
};

struct _HtmlDocumentClass {
	GObjectClass parent_class;

	void (*request_url) (HtmlDocument *document, const gchar *url, HtmlStream *stream);
	void (*link_clicked) (HtmlDocument *document, const gchar *url);
	void (*set_base) (HtmlDocument *document, const gchar *url);
	void (*title_changed) (HtmlDocument *document, const gchar *new_title);
	void (*submit) (HtmlDocument *document, const gchar *method, const gchar *url, const gchar *encoding);

	/* DOM change events */
	void (*node_inserted) (HtmlDocument *document, DomNode *node);
	void (*node_removed) (HtmlDocument *document, DomNode *node);
	void (*text_updated) (HtmlDocument *document, DomNode *node);
	void (*style_updated) (HtmlDocument *document, DomNode *node, HtmlStyleChange style_change);

	/* View notifications */
	void (*relayout_node) (HtmlDocument *document, DomNode *node);
	void (*repaint_node) (HtmlDocument *document, DomNode *node);

	/* DOM events */
	gboolean (*dom_mouse_down) (HtmlDocument *document, DomEvent *event);
	gboolean (*dom_mouse_up) (HtmlDocument *document, DomEvent *event);
	gboolean (*dom_mouse_click) (HtmlDocument *document, DomEvent *event);
	gboolean (*dom_mouse_over) (HtmlDocument *document, DomEvent *event);
	gboolean (*dom_mouse_out) (HtmlDocument *document, DomEvent *event);
};


GType html_document_get_type (void);

HtmlDocument *html_document_new          (void);
gboolean      html_document_open_stream  (HtmlDocument *document, const gchar *mime_type);
void          html_document_write_stream (HtmlDocument *document, const gchar *buffer, gint len);
void          html_document_close_stream (HtmlDocument *document);
void          html_document_clear        (HtmlDocument *document);


void     html_document_update_hover_node    (HtmlDocument *document, DomNode *node);
void     html_document_update_active_node   (HtmlDocument *document, DomNode *node);
void     html_document_update_focus_element (HtmlDocument *document, DomElement *element);
DomNode *html_document_find_anchor          (HtmlDocument *doc, const gchar *anchor);

G_END_DECLS

#endif /* __HTMLDOCUMENT_H__ */
