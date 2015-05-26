/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-pgl.h: device adjusted rich text representation system
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
 *  Copyright (C) 2000-2003 Ximian Inc. and authors
 */

#ifndef __GNOME_PGL_H__
#define __GNOME_PGL_H__

#include <glib.h>

G_BEGIN_DECLS

/*
 * This is device-adjusted counterpart of GnomeGlyphList, suitable
 * for fast rendering. All glyphs have been anchored to final
 * positions, according to specified rules in the GlyphList.
 *
 */
typedef struct _GnomePosGlyphList GnomePosGlyphList;

#include <libgnomeprint/gnome-glyphlist.h>

/*
 * GlyphList -> PGL conversion flags
 *
 * In most cases using DEAULT should do, what you want
 *
 */

enum {
	GNOME_PGL_RENDER_DEFAULT = 0,
	GNOME_PGL_RENDER_EXACT = (1 << 8)
};

/* Constructor */

GnomePosGlyphList *gnome_pgl_from_gl (const GnomeGlyphList *gl, const gdouble *transform, guint flags);

/* Destructor */

void gnome_pgl_destroy (GnomePosGlyphList *pgl);

/* Find ink dimensions */
ArtDRect *gnome_pgl_bbox (const GnomePosGlyphList *pgl, ArtDRect *bbox);

/* Test, whether given point is covered by ink */
gboolean gnome_pgl_test_point (const GnomePosGlyphList *pgl, gdouble x, gdouble y);

void gnome_pgl_render_rgba8 (const GnomePosGlyphList * pgl, gdouble x, gdouble y, guchar * buf,
			     gint width, gint height, gint rowstride, guint flags);
void gnome_pgl_render_rgb8  (const GnomePosGlyphList * pgl, gdouble x, gdouble y, guchar * buf,
			     gint width, gint height, gint rowstride, guint flags);

G_END_DECLS

#endif /* __GNOME_PGL_H__ */
