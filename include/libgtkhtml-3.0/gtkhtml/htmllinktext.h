/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the KDE libraries
    Copyright (C) 1997 Martin Jones (mjones@kde.org)
              (C) 1997 Torben Weis (weis@kde.org)
	      (C) 1999, 2000 Helix Code, Inc.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef _HTMLLINKTEXT_H_
#define _HTMLLINKTEXT_H_

#include "htmltext.h"

#define HTML_LINK_TEXT(x) ((HTMLLinkText *)(x))
#define HTML_LINK_TEXT_CLASS(x) ((HTMLLinkTextClass *)(x))
#define HTML_IS_LINK_TEXT(x) (HTML_CHECK_TYPE ((x), HTML_TYPE_LINKTEXT))

struct _HTMLLinkText {
	HTMLText text;

	gchar *url;
	gchar *target;
};

struct _HTMLLinkTextClass {
	HTMLTextClass text_class;
};

extern HTMLLinkTextClass html_link_text_class;

void        html_link_text_type_init     (void);
void        html_link_text_class_init    (HTMLLinkTextClass *klass,
					  HTMLType           type,
					  guint              object_size);
void        html_link_text_init          (HTMLLinkText      *link_text_,
					  HTMLLinkTextClass *klass,
					  const gchar       *text,
					  gint               len,
					  GtkHTMLFontStyle   font_style,
					  HTMLColor         *color,
					  const gchar       *url,
					  const gchar       *target);
HTMLObject *html_link_text_new           (const gchar       *text,
					  GtkHTMLFontStyle   font_style,
					  HTMLColor         *color,
					  const gchar       *url,
					  const gchar       *target);
HTMLObject *html_link_text_new_with_len  (const gchar       *text,
					  gint               len,
					  GtkHTMLFontStyle   font_style,
					  HTMLColor         *color,
					  const gchar       *url,
					  const gchar       *target);
HTMLObject *html_link_text_to_text       (HTMLLinkText      *link,
					  HTMLEngine        *engine);
void        html_link_text_set_url       (HTMLLinkText      *link,
					  gchar             *url,
					  gchar             *target);
					  
#endif /* _HTMLLINKTEXT_H_ */
