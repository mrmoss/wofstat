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

#ifndef __HTMLIMAGEFACTORY_H__
#define __HTMLIMAGEFACTORY_H__

typedef struct _HtmlImageFactory HtmlImageFactory;
typedef struct _HtmlImageFactoryClass HtmlImageFactoryClass;

#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk-pixbuf/gdk-pixbuf-loader.h>
#include <libgtkhtml/util/htmlstream.h>
#include <libgtkhtml/graphics/htmlimage.h>

G_BEGIN_DECLS

#define HTML_TYPE_IMAGE_FACTORY (html_image_factory_get_type ())
#define HTML_IMAGE_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), HTML_TYPE_IMAGE_FACTORY, HtmlImageFactory))
#define HTML_IMAGE_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_IMAGE_FACTORY, HtmlImageFactoryClass))
#define HTML_IMAGE_FACTORY_GET_CLASS(klass) (G_TYPE_INSTANCE_GET_CLASS ((klass), HTML_TYPE_IMAGE_FACTORY, HtmlImageFactoryClass))

struct _HtmlImageFactory {
	GObject parent;
	GHashTable *image_hash;
};

struct _HtmlImageFactoryClass {
	GObjectClass parent_class;

	void (*request_image) (HtmlImageFactory *image_factory, const gchar *url, HtmlStream *stream);
};


HtmlImageFactory *html_image_factory_new (void);
GType html_image_factory_get_type (void);
HtmlImage *html_image_factory_get_image (HtmlImageFactory *image_factory, const gchar *uri);

G_END_DECLS

#endif /* __HTMLIMAGEFACTORY_H__ */




