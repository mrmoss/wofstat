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

#ifndef __DOM_NODE_ITERATOR_H__
#define __DOM_NODE_ITERATOR_H__

#include <libgtkhtml/dom/dom-types.h>
#include <libgtkhtml/dom/core/dom-node.h>
#include <libgtkhtml/dom/traversal/dom-nodefilter.h>

#define DOM_TYPE_NODE_ITERATOR             (dom_node_iterator_get_type ())
#define DOM_NODE_ITERATOR(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_NODE_ITERATOR, DomNodeIterator))
#define DOM_NODE_ITERATOR_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_NODE_ITERATOR, DomNodeIteratorClass))
#define DOM_IS_NODE_ITERATOR(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_NODE_ITERATOR))
#define DOM_IS_NODE_ITERATOR_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_NODE_ITERATOR))
#define DOM_NODE_ITERATOR_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_NODE_ITERATOR, DomNodeIteratorClass))

struct _DomNodeIterator {
	GObject parent;

	DomNode *root;
	gulong whatToShow;
	DomNodeFilter *filter;
	gboolean expandEntityReferences;

	gboolean detached;
	gboolean forward_direction;
	
	DomNode *reference_node;

	DomDocument *document;
};

struct _DomNodeIteratorClass {
	GObjectClass parent_class;
};

#define DOM_SHOW_ALL                    0xffffffff
#define DOM_SHOW_ELEMENT                0x00000001
#define DOM_SHOW_ATTRIBUTE              0x00000002
#define DOM_SHOW_TEXT                   0x00000004
#define DOM_SHOW_CDATA_SECTION          0x00000008
#define DOM_SHOW_ENTITY_REFERENCE       0x00000010
#define DOM_SHOW_ENTITY                 0x00000020
#define DOM_SHOW_PROCESSING_INSTRUCTION 0x00000040
#define DOM_SHOW_COMMENT                0x00000080
#define DOM_SHOW_DOCUMENT               0x00000100
#define DOM_SHOW_DOCUMENT_TYPE          0x00000200
#define DOM_SHOW_DOCUMENT_FRAGMENT      0x00000400
#define DOM_SHOW_NOTATION               0x00000800

GType dom_node_iterator_get_type (void);

DomNode *dom_NodeIterator__get_root (DomNodeIterator *iterator);
gulong dom_NodeIterator__get_whatToShow (DomNodeIterator *iterator);
DomNodeFilter *dom_NodeIterator__get_nodeFilter (DomNodeIterator *iterator);
gboolean dom_NodeIterator__get_expandEntityReferences (DomNodeIterator *iterator);
DomNode *dom_NodeIterator_nextNode (DomNodeIterator *iterator, DomException *exc);
DomNode *dom_NodeIterator_previousNode (DomNodeIterator *iterator, DomException *exc);
void dom_NodeIterator_detach (DomNodeIterator *iterator);

void dom_NodeIterator_removeNode (DomNodeIterator *iterator, DomNode *node);
#endif /* __DOM_NODE_DATA_H__ */
