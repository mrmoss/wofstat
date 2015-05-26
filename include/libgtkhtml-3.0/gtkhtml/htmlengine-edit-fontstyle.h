/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library

   Copyright (C) 2000 Helix Code, Inc.
   
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

#ifndef HTMLENGINE_EDIT_FONTSTYLE_H
#define HTMLENGINE_EDIT_FONTSTYLE_H

#include "htmlengine.h"
#include "gtkhtmlfontstyle.h"

/* font style */
gboolean           html_engine_update_insertion_font_style       (HTMLEngine       *engine);
GtkHTMLFontStyle   html_engine_get_font_style                    (HTMLEngine       *engine);
GtkHTMLFontStyle   html_engine_get_document_font_style           (HTMLEngine       *engine);
gboolean           html_engine_set_font_style                    (HTMLEngine       *engine,
								  GtkHTMLFontStyle  and_mask,
								  GtkHTMLFontStyle  or_mask);
gboolean           html_engine_toggle_font_style                 (HTMLEngine       *engine,
								  GtkHTMLFontStyle  style);
void               html_engine_font_size_inc_dec                 (HTMLEngine       *e,
								  gboolean          inc);

/* colors */
gboolean           html_engine_update_insertion_color            (HTMLEngine       *engine);
gboolean           html_engine_set_color                         (HTMLEngine       *engine,
								  HTMLColor        *color);
HTMLColor *        html_engine_get_color                         (HTMLEngine       *engine);
HTMLColor *        html_engine_get_document_color                (HTMLEngine       *engine);

gboolean           html_engine_update_insertion_url_and_target   (HTMLEngine       *engine);
const gchar *      html_engine_get_url                           (HTMLEngine       *e);
void               html_engine_set_url                           (HTMLEngine       *e,
								  const gchar      *url);
const gchar *      html_engine_get_target                        (HTMLEngine       *e);
void               html_engine_set_target                        (HTMLEngine       *e,
								  const gchar      *url);
const gchar *      html_engine_get_document_url                  (HTMLEngine       *e);
const gchar *      html_engine_get_document_target               (HTMLEngine       *e);

#endif
