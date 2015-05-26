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

#ifndef __DOM_ATTR_H__
#define __DOM_ATTR_H__

#include "dom-node.h"

#define DOM_TYPE_ATTR             (dom_attr_get_type ())
#define DOM_ATTR(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_ATTR, DomAttr))
#define DOM_ATTR_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_ATTR, DomAttrClass))
#define DOM_IS_ATTR(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_ATTR))
#define DOM_IS_ATTR_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_ATTR))
#define DOM_ATTR_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_ATTR, DomAttrClass))

struct _DomAttr {
	DomNode parent;
};

struct _DomAttrClass {
	DomNodeClass parent_class;
};

GType dom_attr_get_type (void);

DomString *dom_Attr__get_name (DomAttr *attr);
DomString *dom_Attr__get_value (DomAttr *attr);
void dom_Attr__set_value (DomAttr *attr, const DomString *value, DomException *exc);
DomBoolean dom_Attr_get_specified (DomAttr *attr);
DomElement *dom_Attr__get_ownerElement (DomAttr *attr);

#endif /* __DOM_ATTR_H__ */
