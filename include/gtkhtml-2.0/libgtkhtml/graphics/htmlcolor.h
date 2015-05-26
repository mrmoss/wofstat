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

#ifndef __HTMLCOLOR_H__
#define __HTMLCOLOR_H__

#include <glib.h>

G_BEGIN_DECLS

typedef struct _HtmlColor HtmlColor;

struct _HtmlColor {
	gint refcount;
	
	gushort red;
	gushort green;
	gushort blue;
	gushort transparent;
};

HtmlColor* html_color_ref (HtmlColor *color);
void html_color_unref (HtmlColor *color);

HtmlColor *html_color_new_from_name (const gchar *color_name);
HtmlColor *html_color_new_from_rgb (gushort red, gushort green, gushort blue);
void html_color_destroy (HtmlColor *color);
gboolean html_color_equal (HtmlColor *color1, HtmlColor *color2);
HtmlColor *html_color_transform (HtmlColor *color, gfloat ratio);
HtmlColor *html_color_dup (HtmlColor *color);
HtmlColor *html_color_transparent_new (void);
void html_color_set_linkblue (gushort red, gushort green);

G_END_DECLS

#endif /* __HTMLCOLOR_H__ */
