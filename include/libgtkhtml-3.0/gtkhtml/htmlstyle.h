/* "a -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.

    Copyright (C) 2002, Ximian Inc.

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

#ifndef __HTML_STYLE_H__
#define __HTML_STYLE_H__
#include "gtkhtml-enums.h"
#include "htmltypes.h"
#include "htmlcolor.h"

typedef struct _HTMLStyle HTMLStyle;
struct _HTMLStyle {
	HTMLColor          *color;
	HTMLFontFace       *face;
	GtkHTMLFontStyle    settings;
	GtkHTMLFontStyle    mask;		

	/* Block Level */
	HTMLHAlignType      text_align;

	/* Cell Level */
	HTMLVAlignType      text_valign;
	
	/* bg settings */
	char     *bg_image;
	GdkColor *bg_color;
};	


HTMLStyle *html_style_new                  (void);
HTMLStyle *html_style_unset_decoration     (HTMLStyle *style, GtkHTMLFontStyle decoration);
HTMLStyle *html_style_set_decoration       (HTMLStyle *style, GtkHTMLFontStyle decoration);
HTMLStyle *html_style_set_font_size        (HTMLStyle *style, GtkHTMLFontStyle decoration);
HTMLStyle *html_style_set_size             (HTMLStyle *style, GtkHTMLFontStyle size);
HTMLStyle *html_style_add_text_align       (HTMLStyle *style, HTMLHAlignType type);
HTMLStyle *html_style_add_text_valign       (HTMLStyle *style, HTMLVAlignType type);
HTMLStyle *html_style_add_font_face        (HTMLStyle *style, const HTMLFontFace *face);
HTMLStyle *html_style_add_color            (HTMLStyle *style, HTMLColor *face);
HTMLStyle *html_style_add_attribute        (HTMLStyle *style, const char *attr);
HTMLStyle *html_style_add_background_image (HTMLStyle *style, const char *url);
HTMLStyle *html_style_add_background_color (HTMLStyle *style, GdkColor *color);
void       html_style_free                 (HTMLStyle *style);

#endif /* __HTML_COLOR_H__ */
