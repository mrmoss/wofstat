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

#ifndef __DOM_DOCUMENT_H__
#define __DOM_DOCUMENT_H__

#include <libgtkhtml/dom/dom-types.h>
#include <libgtkhtml/dom/core/dom-node.h>

#define DOM_TYPE_DOCUMENT             (dom_document_get_type ())
#define DOM_DOCUMENT(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_DOCUMENT, DomDocument))
#define DOM_DOCUMENT_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_DOCUMENT, DomDocumentClass))
#define DOM_IS_DOCUMENT(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_DOCUMENT))
#define DOM_IS_DOCUMENT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_DOCUMENT))
#define DOM_DOCUMENT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_DOCUMENT, DomDocumentClass))

struct _DomDocument {
	DomNode parent;

	GSList *iterators;
};

struct _DomDocumentClass {
	DomNodeClass parent_class;
};

GType dom_document_get_type (void);

DomElement *dom_Document__get_documentElement (DomDocument *doc);
DomElement *dom_Document_createElement (DomDocument *doc, const DomString *tagName);
DomText *dom_Document_createTextNode (DomDocument *doc, const DomString *data);
DomComment *dom_Document_createComment (DomDocument *doc, const DomString *data);
DomNode *dom_Document_importNode (DomDocument *doc, DomNode *importedNode, DomBoolean deep, DomException *exc);

#endif /* __DOM_DOCUMENT_H__ */
