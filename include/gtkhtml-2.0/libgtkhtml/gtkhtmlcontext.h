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

#ifndef __GTKHTMLCONTEXT_H__
#define __GTKHTMLCONTEXT_H__

typedef struct _GtkHtmlContext GtkHtmlContext;
typedef struct _GtkHtmlContextClass GtkHtmlContextClass;

#include <gtk/gtk.h>
#include <libgtkhtml/util/htmlatomlist.h>

G_BEGIN_DECLS

#define GTK_HTML_CONTEXT_TYPE            (gtk_html_context_get_type ())
#define GTK_HTML_CONTEXT(obj)            (GTK_CHECK_CAST ((obj), GTK_HTML_CONTEXT_TYPE, GtkHtmlContext))
#define GTK_HTML_CONTEXT_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), GTK_HTML_CONTEXT_TYPE, GtkHtmlContextClass))
#define GTK_HTML_IS_CONTEXT(obj)         (GTK_CHECK_TYPE ((obj), GTK_HTML_CONTEXT_TYPE))
#define GTK_HTML_IS_CONTEXT_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GTK_HTML_CONTEXT_TYPE))

struct _GtkHtmlContext {
	GObject parent;

	/* List of documents */
	GSList *documents;

#if 0	/* FIXME: Use these */
	/* Standard font */
	HtmlFontSpecification *standard_font;

	/* Standard fixed width font */
	HtmlFontSpecification *fixed_font;
#endif

	gboolean debug_painting;
};

struct _GtkHtmlContextClass {
	GObjectClass parent;
};

GType    gtk_html_context_get_type (void);
GtkHtmlContext *gtk_html_context_get (void);

G_END_DECLS

#endif /* __GTKHTMLCONTEXT_H__ */
