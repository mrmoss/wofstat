/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library

   Copyright (C) 2000 Helix Code, Inc.
   Authors:           Radek Doulik (rodo@helixcode.com)

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHcANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef _HTML_COLOR_H_
#define _HTML_COLOR_H_

#include <gdk/gdktypes.h>
#include <gdk/gdkcolor.h>
#include "htmltypes.h"

struct _HTMLColor {
	GdkColor color;
	gboolean allocated;
	guint refcount;
};

HTMLColor * html_color_new                (void);
HTMLColor * html_color_new_from_gdk_color (const GdkColor *color);
HTMLColor * html_color_new_from_rgb       (gushort red, gushort green, gushort blue);

void        html_color_ref                (HTMLColor *color);
void        html_color_unref              (HTMLColor *color);

void        html_color_alloc              (HTMLColor *color, HTMLPainter *painter);
void        html_color_free               (HTMLColor *color, HTMLPainter *painter);

gboolean    html_color_equal              (HTMLColor *color1, HTMLColor *color2);

void        html_color_set                (HTMLColor *color, GdkColor *c);

#endif
