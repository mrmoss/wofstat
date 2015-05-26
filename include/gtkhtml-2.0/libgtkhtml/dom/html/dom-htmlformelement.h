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

#ifndef __DOM_HTML_FORM_ELEMENT_H__
#define __DOM_HTML_FORM_ELEMENT_H__

#include <libgtkhtml/dom/dom-types.h>

#include <libgtkhtml/dom/html/dom-htmlelement.h>
#include <libgtkhtml/dom/html/dom-htmlcollection.h>

#define DOM_TYPE_HTML_FORM_ELEMENT             (dom_html_form_element_get_type ())
#define DOM_HTML_FORM_ELEMENT(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_HTML_FORM_ELEMENT, DomHTMLFormElement))
#define DOM_HTML_FORM_ELEMENT_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_HTML_ELEMENT, DomHTMLFormElementClass))
#define DOM_IS_HTML_FORM_ELEMENT(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_HTML_FORM_ELEMENT))
#define DOM_IS_HTML_FORM_ELEMENT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_HTML_FORM_ELEMENT))
#define DOM_HTML_FORM_ELEMENT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_HTML_FORM_ELEMENT, DomHTMLFormElementClass))

struct _DomHTMLFormElement {
	DomHTMLElement parent;
};

struct _DomHTMLFormElementClass {
	DomHTMLElementClass parent_class;
};

GType dom_html_form_element_get_type (void);

gulong dom_HTMLFormElement__get_length ( DomHTMLFormElement *element);
DomString *dom_HTMLFormElement__get_name (DomHTMLFormElement *element);
DomString *dom_HTMLFormElement__get_acceptCharset (DomHTMLFormElement *element);
DomString *dom_HTMLFormElement__get_action (DomHTMLFormElement *element);
DomString *dom_HTMLFormElement__get_enctype (DomHTMLFormElement *element);
DomString *dom_HTMLFormElement__get_method (DomHTMLFormElement *element);
DomString *dom_HTMLFormElement__get_target (DomHTMLFormElement *element);
DomHTMLCollection *dom_HTMLFormElement__get_elements ( DomHTMLFormElement *element);

void dom_HTMLFormElement__set_name (DomHTMLFormElement *element, const DomString *str);
void dom_HTMLFormElement__set_acceptCharset (DomHTMLFormElement *element, const DomString *str);
void dom_HTMLFormElement__set_action (DomHTMLFormElement *element, const DomString *str);
void dom_HTMLFormElement__set_enctype (DomHTMLFormElement *element, const DomString *str);
void dom_HTMLFormElement__set_method (DomHTMLFormElement *element, const DomString *str);
void dom_HTMLFormElement__set_target (DomHTMLFormElement *element, const DomString *str);

void dom_HTMLFormElement_submit (DomHTMLFormElement *form);
void dom_HTMLFormElement_reset  (DomHTMLFormElement *form);

/* gtkhtml2 specific function */
gchar *dom_HTMLFormElement__get_encoding (DomHTMLFormElement *form);

#endif /* __DOM_HTML_FORM_ELEMENT_H__ */
