/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2000-2001 CodeFactory AB
 * Copyright (C) 2000-2001 Anders Carlsson <andersca@codefactory.se>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __DOM_ABSTRACTVIEW_H__
#define __DOM_ABSTRACTVIEW_H__

#include <glib-object.h>

typedef struct _DomAbstractView DomAbstractView;
typedef struct _DomAbstractViewIface DomAbstractViewIface;

#include "dom-documentview.h"

#define DOM_TYPE_ABSTRACT_VIEW             (dom_abstract_view_get_type ())
#define DOM_ABSTRACT_VIEW(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_ABSTRACT_VIEW, DomAbstractView))
#define DOM_ABSTRACT_VIEW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_ABSTRACT_VIEW, DomAbstractViewClass))
#define DOM_IS_ABSTRACT_VIEW(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_ABSTRACT_VIEW))
#define DOM_IS_ABSTRACT_VIEW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_ABSTRACT_VIEW))
#define DOM_ABSTRACT_VIEW_GET_IFACE(obj)  ((DomAbstractViewIface *)g_type_interface_peek (((GTypeInstance *)DOM_ABSTRACT_VIEW (obj))->g_class, DOM_TYPE_ABSTRACT_VIEW))


struct _DomAbstractViewIface {
	GTypeInterface g_iface;

	DomDocumentView * (*_get_document) (DomAbstractView *view);
};

GType dom_abstract_view_get_type (void);

DomDocumentView *dom_AbstractView__get_document (DomAbstractView *view);

#endif /* __DOM_ABSTRACTVIEW_H__ */
