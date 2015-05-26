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

#ifndef __DOM_HTML_COLLECTION_H__
#define __DOM_HTML_COLLECTION_H__

#include "libgtkhtml/dom/core/dom-node.h"

#define DOM_TYPE_HTML_COLLECTION             (dom_html_collection_get_type ())
#define DOM_HTML_COLLECTION(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_HTML_COLLECTION, DomHTMLCollection))
#define DOM_HTML_COLLECTION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_HTML_COLLECTION, DomHTMLCollectionClass))
#define DOM_IS_HTML_COLLECTION(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_HTML_COLLECTION))
#define DOM_IS_HTML_COLLECTION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_HTML_COLLECTION))
#define DOM_HTML_COLLECTION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_HTML_COLLECTION, DomHTMLCollectionClass))

struct _DomHTMLCollection {
	GObject parent;

	gulong (* length) (DomHTMLCollection *collection);
	DomNode *(* item) (DomHTMLCollection *collection, gulong index);
	DomNode *(* namedItem) (DomHTMLCollection *collection, const DomString *name);

	DomNode *node;
};

struct _DomHTMLCollectionClass {
	GObjectClass parent_class;
};

GType dom_html_collection_get_type (void);

gulong dom_HTMLCollection__get_length (DomHTMLCollection *list);
DomNode *dom_HTMLCollection__get_item (DomHTMLCollection *list, gulong index);
DomNode *dom_HTMLCollection__get_namedItem (DomHTMLCollection *list, const DomString *name);

#endif /* __DOM_HTML_COLLECTION_H__ */
