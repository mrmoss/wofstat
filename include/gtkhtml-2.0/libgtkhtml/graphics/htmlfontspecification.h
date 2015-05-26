/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000 CodeFactory AB
   Copyright (C) 2000 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2000 Anders Carlsson <andersca@codefactory.se>
   Copyright (C) 2000 Red Hat Software
   
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
#ifndef __HTMLFONTDESCRIPTION_H__
#define __HTMLFONTDESCRIPTION_H__

#include <pango/pango-font.h>
#include <pango/pango-attributes.h>
#include <gtk/gtk.h>

typedef struct _HtmlFontSpecification HtmlFontSpecification;

typedef enum {
	HTML_FONT_STYLE_NORMAL = 0,
	HTML_FONT_STYLE_ITALIC,
	HTML_FONT_STYLE_OBLIQUE
} HtmlFontStyleType;

typedef enum {
	HTML_FONT_VARIANT_NORMAL = 0,
	HTML_FONT_VARIANT_SMALL_CAPS
} HtmlFontVariantType;

#define HTML_FONT_WEIGHT_NORMAL HTML_FONT_WEIGHT_400
#define HTML_FONT_WEIGHT_BOLD HTML_FONT_WEIGHT_700

typedef enum {
	HTML_FONT_WEIGHT_100,
	HTML_FONT_WEIGHT_200,
	HTML_FONT_WEIGHT_300,
	HTML_FONT_WEIGHT_400,
	HTML_FONT_WEIGHT_500,
	HTML_FONT_WEIGHT_600,
	HTML_FONT_WEIGHT_700,
	HTML_FONT_WEIGHT_800,
	HTML_FONT_WEIGHT_900
} HtmlFontWeightType;

typedef enum {
	HTML_FONT_STRETCH_NORMAL = 0,
	HTML_FONT_STRETCH_ULTRA_CONDENSED,
	HTML_FONT_STRETCH_EXTRA_CONDENSED,
	HTML_FONT_STRETCH_CONDENSED,
	HTML_FONT_STRETCH_SEMI_CONDENSED,
	HTML_FONT_STRETCH_SEMI_EXPANDED,
	HTML_FONT_STRETCH_EXPANDED,
	HTML_FONT_STRETCH_EXTRA_EXPANDED,
	HTML_FONT_STRETCH_ULTRA_EXPANDED
} HtmlFontStretchType;

typedef enum {
	HTML_FONT_DECORATION_NONE = 0, 
	HTML_FONT_DECORATION_UNDERLINE = 1 << 0,
	HTML_FONT_DECORATION_OVERLINE = 1 << 1,
	HTML_FONT_DECORATION_LINETHROUGH = 1 << 2
} HtmlFontDecorationType;

struct _HtmlFontSpecification {
	gchar *family; /* Comma separated list of family names */
	gfloat size;
	guint weight : 4;
	guint style : 2;
	guint variant : 2;
	guint stretch : 4;
	guint decoration : 3;
};

HtmlFontSpecification *html_font_specification_new (gchar *family,
						    HtmlFontStyleType style, 
						    HtmlFontVariantType variant,
						    HtmlFontWeightType weight,
						    HtmlFontStretchType stretch, 
						    HtmlFontDecorationType decoration,
						    gfloat size);

HtmlFontSpecification * html_font_specification_ref (HtmlFontSpecification *spec);
void html_font_specification_unref (HtmlFontSpecification *spec);

HtmlFontSpecification * html_font_specification_dup (HtmlFontSpecification *spec);

gboolean html_font_description_equal (HtmlFontSpecification *a, HtmlFontSpecification *b);

PangoFontDescription *html_font_specification_get_pango_font_description (HtmlFontSpecification *spec);

void html_font_specification_get_extra_attributes (HtmlFontSpecification *spec,
						   PangoAttrList *attrs,
						   gint start_index, gint end_index);
void html_font_specification_get_all_attributes (HtmlFontSpecification *spec,
						 PangoAttrList *attrs,
						 gint start_index, gint end_index,
						 gdouble magnification);
gint html_font_specification_get_html_size (HtmlFontSpecification *spec);
gfloat html_font_description_html_size_to_pt (gint font_size);

#endif /* __HTMLFONTSPECIFICATION_H__ */
