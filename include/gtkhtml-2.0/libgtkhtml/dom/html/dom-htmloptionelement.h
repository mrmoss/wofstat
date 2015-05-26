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

#ifndef __DOM_HTML_OPTION_ELEMENT_H__
#define __DOM_HTML_OPTION_ELEMENT_H__

#include <libgtkhtml/dom/dom-types.h>

#include <libgtkhtml/dom/html/dom-htmlformelement.h>

#define DOM_TYPE_HTML_OPTION_ELEMENT             (dom_html_option_element_get_type ())
#define DOM_HTML_OPTION_ELEMENT(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_HTML_OPTION_ELEMENT, DomHTMLOptionElement))
#define DOM_HTML_OPTION_ELEMENT_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_HTML_ELEMENT, DomHTMLOptionElementClass))
#define DOM_IS_HTML_OPTION_ELEMENT(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_HTML_OPTION_ELEMENT))
#define DOM_IS_HTML_OPTION_ELEMENT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_HTML_OPTION_ELEMENT))
#define DOM_HTML_OPTION_ELEMENT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_HTML_OPTION_ELEMENT, DomHTMLOptionElementClass))

struct _DomHTMLOptionElement {
	DomHTMLElement parent;
};

struct _DomHTMLOptionElementClass {
	DomHTMLElementClass parent_class;
};

GType dom_html_option_element_get_type (void);

DomHTMLFormElement *dom_HTMLOptionElement__get_form (DomHTMLOptionElement *element);

DomBoolean dom_HTMLOptionElement__get_defaultSelected  (DomHTMLOptionElement *element);
DomBoolean dom_HTMLOptionElement__get_disabled  (DomHTMLOptionElement *element);
DomBoolean dom_HTMLOptionElement__get_selected  (DomHTMLOptionElement *element);
DomString *dom_HTMLOptionElement__get_text  (DomHTMLOptionElement *element);
DomString *dom_HTMLOptionElement__get_value  (DomHTMLOptionElement *element);
DomString *dom_HTMLOptionElement__get_label  (DomHTMLOptionElement *element);
glong dom_HTMLOptionElement__get_index  (DomHTMLOptionElement *element);

void dom_HTMLOptionElement__set_defaultSelected  (DomHTMLOptionElement *element, DomBoolean defaultSelected);
void dom_HTMLOptionElement__set_disabled  (DomHTMLOptionElement *element, DomBoolean defaultSelected);
void dom_HTMLOptionElement__set_label      (DomHTMLOptionElement *element, const DomString *label);
void dom_HTMLOptionElement__set_value      (DomHTMLOptionElement *element, const DomString *value);
void dom_HTMLOptionElement__set_selected   (DomHTMLOptionElement *element, DomBoolean selected);

void dom_html_option_element_new_character_data (DomHTMLOptionElement *option);

#endif /* __DOM_HTML_OPTION_ELEMENT_H__ */
