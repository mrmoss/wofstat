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

#ifndef __DOM_NODE_H__
#define __DOM_NODE_H__

#include <libxml/tree.h>

#include <libgtkhtml/dom/dom-types.h>
#include <libgtkhtml/dom/core/dom-namednodemap.h>
#include <libgtkhtml/layout/htmlstyle.h>

#define DOM_TYPE_NODE             (dom_node_get_type ())
#define DOM_NODE(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_NODE, DomNode))
#define DOM_NODE_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_NODE, DomNodeClass))
#define DOM_IS_NODE(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_NODE))
#define DOM_IS_NODE_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_NODE))
#define DOM_NODE_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_NODE, DomNodeClass))

struct _DomNode {
	GObject parent;

	xmlNode *xmlnode;

	HtmlStyle *style;
};


struct _DomNodeClass {
	GObjectClass parent_class;

	DomString *(* _get_nodeName) (DomNode *node);
	
	DomString *(* _get_nodeValue) (DomNode *node, DomException *exc);
	DomString *(* _set_nodeValue) (DomNode *node, const DomString *value, DomException *exc);
};

#include <libgtkhtml/dom/core/dom-documenttype.h>
#include <libgtkhtml/dom/core/dom-document.h>
#include <libgtkhtml/dom/core/dom-nodelist.h>

GType dom_node_get_type (void);
DomNode *dom_Node_mkref (xmlNode *node);

DomNodeList *dom_Node__get_childNodes (DomNode *node);
DomNode *dom_Node_removeChild (DomNode *node, DomNode *oldChild, DomException *exc);
DomString *dom_Node__get_nodeValue (DomNode *node, DomException *exc);
DomNode *dom_Node__get_firstChild (DomNode *node);
DomString *dom_Node__get_nodeName (DomNode *node);
DomNamedNodeMap *dom_Node__get_attributes (DomNode *node);
DomDocumentType *dom_Document__get_doctype (DomDocument *doc);
DomBoolean dom_Node_hasChildNodes (DomNode *node);
DomNode *dom_Node__get_parentNode (DomNode *node);
DomNode *dom_Node__get_nextSibling (DomNode *node);
gushort dom_Node__get_nodeType (DomNode *node);
DomBoolean dom_Node_hasAttributes (DomNode *node);
DomNode *dom_Node_cloneNode (DomNode *node, DomBoolean deep);
DomNode *dom_Node_appendChild (DomNode *node, DomNode *newChild, DomException *exc);
DomString *dom_Node__get_localName (DomNode *node);
DomString *dom_Node__get_namespaceURI (DomNode *node);
DomNode *dom_Node__get_previousSibling (DomNode *node);
DomNode *dom_Node__get_lastChild (DomNode *node);
void dom_Node__set_nodeValue (DomNode *node, const DomString *value, DomException *exc);
DomDocument *dom_Node__get_ownerDocument (DomNode *node);
gboolean dom_Node_hasAttributes (DomNode *node);
#endif /* __DOM_NODE_H__ */
