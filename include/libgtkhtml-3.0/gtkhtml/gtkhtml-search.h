/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.

    Copyright 1999, 2000 Helix Code, Inc.
    Authors:             Radek Doulik (rodo@helixcode.com)
    
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

#ifndef _GTK_HTML_SEARCH_
#define _GTK_HTML_SEARCH_

#include "gtkhtml.h"

void      gtk_html_isearch                    (GtkHTML     *html,
					       gboolean     forward);
gboolean  gtk_html_engine_search              (GtkHTML     *html,
					       const gchar *text,
					       gboolean     case_sensitive,
					       gboolean     forward,
					       gboolean     regular);

void      gtk_html_engine_search_set_forward  (GtkHTML     *html,
					       gboolean forward);

gboolean  gtk_html_engine_search_next         (GtkHTML     *html);
gboolean  gtk_html_engine_search_incremental  (GtkHTML     *html,
					       const gchar *text,
					       gboolean     forward);

#endif
