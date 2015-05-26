/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-glyphlist-private.h: device independent rich text representation system
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public License
 *  as published by the Free Software Foundation; either version 2 of
 *  the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Authors:
 *    Lauris Kaplinski <lauris@ximian.com>
 *
 *  Copyright 2000-2003 Ximian, Inc. and authors
 */

#ifndef __GNOME_GLYPHLIST_PRIVATE_H__
#define __GNOME_GLYPHLIST_PRIVATE_H__

#include <glib.h>

G_BEGIN_DECLS

#include <libgnomeprint/gnome-glyphlist.h>

#define GGL_GLYPH_BLOCK_SIZE 32
#define GGL_RULE_BLOCK_SIZE  4

typedef struct _GGLRule GGLRule;

struct _GnomeGlyphList {
	gint refcount;
	gint * glyphs;
	gint g_length, g_size;
	GGLRule * rules;
	gint r_length, r_size;
};

typedef enum {
	GGL_POSITION,     /* Glyph position for following rules */

	/* Absolute positioning */
	GGL_MOVETOX,      /* Set pen to absolute X */
	GGL_MOVETOY,      /* Set pen to absolute Y */
	GGL_RMOVETOX,     /* Advance pen X by distance */
	GGL_RMOVETOY,     /* Advance pen Y by distance */

	/* Typesetting rules */
	GGL_ADVANCE,      /* Forces glyph to advance pen by stdadvance */
	GGL_LETTERSPACE,  /* Forces given point distance to be added for every advance */
	GGL_KERNING,      /* Forces given % of interglyph kerning to be added */
	GGL_FONT,         /* Font to use for following glyphs */
	GGL_COLOR         /* Color to use for following glyphs */
} GGLInfoType;

struct _GGLRule {
	guint8 code;
	union {
		gint ival;
		gdouble dval;
		gboolean bval;
		GnomeFont * font;
		guint32 color;
	} value;
};

G_END_DECLS

#endif /* __GNOME_GLYPHLIST_PRIVATE_H__ */
