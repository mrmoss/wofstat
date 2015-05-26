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

#ifndef __HTMLPARSER_H__
#define __HTMLPARSER_H__

#include <gtk/gtk.h>
#include <libxml/parser.h>
#include <libxml/HTMLparser.h>

#include <libgtkhtml/css/cssparser.h>
#include <libgtkhtml/document/htmldocument.h>
#include <libgtkhtml/dom/core/dom-document.h>
#include <libgtkhtml/dom/views/dom-abstractview.h>
#include <libgtkhtml/dom/events/dom-eventlistener.h>
#include <libgtkhtml/util/htmlstream.h>

G_BEGIN_DECLS

#define HTML_PARSER_TYPE         (html_parser_get_type ())
#define HTML_PARSER(obj)         (GTK_CHECK_CAST ((obj), HTML_PARSER_TYPE, HtmlParser))
#define HTML_PARSER_CLASS(klass) (GTK_CHECK_CLASS_CAST ((klass), HTML_PARSER_TYPE, HtmlParserClass))
#define HTML_IS_PARSER(obj)      (GTK_CHECK_TYPE ((obj), HTML_PARSER_TYPE))

enum _HtmlParserType {
	HTML_PARSER_TYPE_HTML,
	HTML_PARSER_TYPE_XML
};
typedef enum _HtmlParserType HtmlParserType;

struct _HtmlParser {
	GObject parent;

	HtmlParserType parser_type;
	
	HtmlDocument *document;
	HtmlStream *stream;

	/* Used by libxml */
	xmlParserCtxtPtr xmlctxt;
	int res;
	char chars[10];

	gboolean blocking;
	DomNode *blocking_node;
};
typedef struct _HtmlParser HtmlParser;

struct _HtmlParserClass {
	GtkObjectClass parent;

	void (* done_parsing) (HtmlParser *parser);
	void (* new_node) (HtmlParser *parser, DomNode *node);
	void (* parsed_document_node) (HtmlParser *parser, DomDocument *document);
};
typedef struct _HtmlParserClass HtmlParserClass;

GType html_parser_get_type (void);
HtmlParser *html_parser_new (HtmlDocument *document, HtmlParserType parser_type);

G_END_DECLS

#endif /* __HTMLPARSER_H__ */
