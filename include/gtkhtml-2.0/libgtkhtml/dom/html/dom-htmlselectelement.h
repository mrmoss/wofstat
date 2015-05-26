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

#ifndef __DOM_HTML_SELECT_ELEMENT_H__
#define __DOM_HTML_SELECT_ELEMENT_H__

#include <gtk/gtk.h>
#include <libgtkhtml/dom/dom-types.h>

#include <libgtkhtml/dom/html/dom-htmlformelement.h>

#define DOM_TYPE_HTML_SELECT_ELEMENT             (dom_html_select_element_get_type ())
#define DOM_HTML_SELECT_ELEMENT(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_HTML_SELECT_ELEMENT, DomHTMLSelectElement))
#define DOM_HTML_SELECT_ELEMENT_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_HTML_ELEMENT, DomHTMLSelectElementClass))
#define DOM_IS_HTML_SELECT_ELEMENT(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_HTML_SELECT_ELEMENT))
#define DOM_IS_HTML_SELECT_ELEMENT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_HTML_SELECT_ELEMENT))
#define DOM_HTML_SELECT_ELEMENT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_HTML_SELECT_ELEMENT, DomHTMLSelectElementClass))

struct _DomHTMLSelectElement {
	DomHTMLElement parent;
	GSList *options;
	GtkListStore *list_store;

	/* Not implemented:
           attribute DOMString        value;
  readonly attribute long             length;
  readonly attribute HTMLCollection   options;
           attribute boolean          disabled;
           attribute long             tabIndex;
  void               blur();
  void               focus();

*/

};

struct _DomHTMLSelectElementClass {
	DomHTMLElementClass parent_class;
};

GType dom_html_select_element_get_type (void);

DomHTMLFormElement *dom_HTMLSelectElement__get_form (DomHTMLSelectElement *element);

DomString *dom_HTMLSelectElement__get_type  (DomHTMLSelectElement *element);
DomString *dom_HTMLSelectElement__get_name  (DomHTMLSelectElement *element);
glong dom_HTMLSelectElement__get_selectedIndex  (DomHTMLSelectElement *element);
glong dom_HTMLSelectElement__get_size           (DomHTMLSelectElement *element);
DomBoolean dom_HTMLSelectElement__get_multiple  (DomHTMLSelectElement *element);

void dom_HTMLSelectElement__set_selectedIndex  (DomHTMLSelectElement *element, glong selectedIndex);
void dom_HTMLSelectElement__set_multiple       (DomHTMLSelectElement *element, DomBoolean multiple);
void dom_HTMLSelectElement__set_name           (DomHTMLSelectElement *element, const DomString *name);
void dom_HTMLSelectElement__set_size           (DomHTMLSelectElement *element, glong size);

void dom_HTMLSelectElement_add (DomHTMLSelectElement *select, DomHTMLElement *element, DomHTMLElement *before, DomException *exception);
void dom_HTMLSelectElement_remove (DomHTMLSelectElement *select, glong index);

GtkTreeModel *dom_html_select_element_get_tree_model (DomHTMLSelectElement *select);
void dom_html_select_element_update_option_data (DomHTMLSelectElement *select, DomHTMLOptionElement *element);

#endif /* __DOM_HTML_SELECT_ELEMENT_H__ */
