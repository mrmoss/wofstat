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

#ifndef __DOM_HTML_INPUT_ELEMENT_H__
#define __DOM_HTML_INPUT_ELEMENT_H__

#include <libgtkhtml/dom/dom-types.h>

#include <libgtkhtml/dom/html/dom-htmlformelement.h>

#define DOM_TYPE_HTML_INPUT_ELEMENT             (dom_html_input_element_get_type ())
#define DOM_HTML_INPUT_ELEMENT(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_HTML_INPUT_ELEMENT, DomHTMLInputElement))
#define DOM_HTML_INPUT_ELEMENT_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_HTML_ELEMENT, DomHTMLInputElementClass))
#define DOM_IS_HTML_INPUT_ELEMENT(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_HTML_INPUT_ELEMENT))
#define DOM_IS_HTML_INPUT_ELEMENT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_HTML_INPUT_ELEMENT))
#define DOM_HTML_INPUT_ELEMENT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_HTML_INPUT_ELEMENT, DomHTMLInputElementClass))

struct _DomHTMLInputElement {
	DomHTMLElement parent;
	gint checked:2;
	guint active:1;
	gchar *str_value;
	/* FIXME: Not implemented:
	  attribute DOMString        accept;
	  attribute DOMString        accessKey;
	  attribute DOMString        align;
	  attribute DOMString        alt;
	  attribute DOMString        src;
	  attribute long             tabIndex;
	  // Modified in DOM Level 2:
	  attribute DOMString        type;
	  attribute DOMString        useMap;
	  void               blur();
	  void               focus();
	  void               select();
	  void               click();
	*/
};

struct _DomHTMLInputElementClass {
	DomHTMLElementClass parent_class;
	void (*widget_toggled) (DomHTMLInputElement *input, gboolean checked);
	void (*widget_text_changed) (DomHTMLInputElement *input);
};

GType dom_html_input_element_get_type (void);

DomString *dom_HTMLInputElement__get_name  (DomHTMLInputElement *element);
DomString *dom_HTMLInputElement__get_value (DomHTMLInputElement *element);
DomString *dom_HTMLInputElement__get_defaultValue (DomHTMLInputElement *element);
DomString *dom_HTMLInputElement__get_size  (DomHTMLInputElement *element);
DomBoolean dom_HTMLInputElement__get_checked  (DomHTMLInputElement *element);
DomBoolean dom_HTMLInputElement__get_defaultChecked  (DomHTMLInputElement *element);
DomBoolean dom_HTMLInputElement__get_readOnly (DomHTMLInputElement *element);
DomBoolean dom_HTMLInputElement__get_disabled (DomHTMLInputElement *element);
gint dom_HTMLInputElement__get_maxLength (DomHTMLInputElement *element);
DomHTMLFormElement *dom_HTMLInputElement__get_form (DomHTMLInputElement *element);

void dom_HTMLInputElement__set_name      (DomHTMLInputElement *element, const DomString *name);
void dom_HTMLInputElement__set_value     (DomHTMLInputElement *element, const DomString *value);
void dom_HTMLInputElement__set_defaultValue     (DomHTMLInputElement *element, const DomString *value);
void dom_HTMLInputElement__set_checked   (DomHTMLInputElement *element, DomBoolean checked);
void dom_HTMLInputElement__set_defaultChecked   (DomHTMLInputElement *element, DomBoolean checked);
void dom_HTMLInputElement__set_readOnly  (DomHTMLInputElement *element, DomBoolean readonly);
void dom_HTMLInputElement__set_disabled  (DomHTMLInputElement *element, DomBoolean disabled);
void dom_HTMLInputElement__set_maxLength (DomHTMLInputElement *element, gint maxLength);
void dom_HTMLInputElement__set_size      (DomHTMLInputElement *element, const DomString *size);

void dom_html_input_element_widget_toggled (DomHTMLInputElement *input, gboolean checked);
void dom_html_input_element_widget_text_changed (DomHTMLInputElement *input);

DomString *dom_html_input_element_encode (DomHTMLInputElement *input);
void       dom_html_input_element_reset  (DomHTMLInputElement *input);

#endif /* __DOM_HTML_INPUT_ELEMENT_H__ */
