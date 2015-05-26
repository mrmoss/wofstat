/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library.

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

#ifndef _HTML_FONT_MANAGER_H_
#define _HTML_FONT_MANAGER_H_

#define HTML_FONT_MANAGER(x) ((HTMLFontManager *)x)

#include "htmltypes.h"
#include "gtkhtml-enums.h"
#include "gtkhtmlfontstyle.h"

struct _HTMLFont {
	gpointer data;
	guint    space_width;
	guint    nbsp_width;
	guint    tab_width;
	guint    indent_width;
	guint    cite_width;
	gint     ref_count;
};

struct _HTMLFontSet {
	HTMLFont *font [GTK_HTML_FONT_STYLE_MAX_FONT];
	gint      ref_count;
	gchar    *face;
};

struct _HTMLFontManager {
	HTMLPainter *painter;

	GHashTable *font_sets;
	HTMLFontSet variable;
	HTMLFontSet fixed;

	gint var_size;
	gint fix_size;
	gboolean var_points;
	gboolean fix_points;

	gdouble magnification;
};

void                html_font_manager_init                    (HTMLFontManager *manager,
							       HTMLPainter *painter);
void                html_font_manager_finalize                (HTMLFontManager *manager);

void                html_font_manager_set_default             (HTMLFontManager *manager,
							       gchar *variable,
							       gchar *fixed,
							       gint var_size,
							       gboolean var_points,
							       gint fix_size,
							       gboolean fix_points);
HTMLFont           *html_font_manager_get_font                (HTMLFontManager *manager,
							       gchar *face,
							       GtkHTMLFontStyle style);
void                html_font_manager_clear_font_cache        (HTMLFontManager *manager);
void                html_font_manager_set_magnification       (HTMLFontManager *manager,
							       gdouble          magnification);
gchar *             html_font_manager_get_attr                (gchar           *font_name,
							       gint             n);
/*
 * HTMLFont
 */
HTMLFont *html_font_new      (gpointer     data,
			      guint        space_width,
			      guint        nbsp_width,
			      guint        tab_width,
			      guint        indent_width,
			      guint        cite_width);
void      html_font_destroy  (HTMLFont    *font);
void      html_font_ref      (HTMLFont    *font,
			      HTMLPainter *painter);
void      html_font_unref    (HTMLFont    *font,
			      HTMLPainter *painter);

#endif
