/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-rfont.h: grid fitted font
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
 *  Copyright (C) 2000-2001 Ximian Inc. and authors
 */

#ifndef __GNOME_RFONT_H__
#define __GNOME_RFONT_H__

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_RFONT         (gnome_rfont_get_type ())
#define GNOME_RFONT(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_RFONT, GnomeRFont))
#define GNOME_RFONT_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_RFONT, GnomeRFontClass))
#define GNOME_IS_RFONT(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_RFONT))
#define GNOME_IS_RFONT_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_RFONT))
#define GNOME_RFONT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_RFONT, GnomeRFontClass))

#define gnome_rfont_ref(o)   g_object_ref (G_OBJECT (o))
#define gnome_rfont_unref(o) g_object_unref (G_OBJECT (o))
#define gnome_rfont_render_pgl_rgb8  gnome_pgl_render_rgb8
#define gnome_rfont_render_pgl_rgba8 gnome_pgl_render_rgba8
#define GNOME_RFONT_RENDER_DEFAULT 0

typedef struct _GnomeRFont GnomeRFont;
typedef struct _GnomeRFontClass GnomeRFontClass;

#include <libart_lgpl/art_svp.h>
#include <libgnomeprint/gnome-font.h>
#include <libgnomeprint/gnome-pgl.h>

GType        gnome_rfont_get_type (void);
GnomeRFont * gnome_font_get_rfont (GnomeFont *font, const gdouble *t);

GnomeFont *     gnome_rfont_get_font   (const GnomeRFont *rfont);
GnomeFontFace * gnome_rfont_get_face   (const GnomeRFont *rfont);
gdouble *       gnome_rfont_get_matrix (const GnomeRFont *rfont, gdouble *matrix);

ArtPoint * gnome_rfont_get_glyph_stdadvance (GnomeRFont *rfont, gint glyph, ArtPoint *advance);
ArtDRect * gnome_rfont_get_glyph_stdbbox (GnomeRFont *rfont, gint glyph, ArtDRect *bbox);
ArtPoint * gnome_rfont_get_glyph_stdkerning (GnomeRFont *rfont, gint glyph0, gint glyph1, ArtPoint *kerning);

/*
 * I am not sure, whether these should be stdoutline and stdsvp (Lauris)
 */
const ArtBpath * gnome_rfont_get_glyph_bpath (GnomeRFont * rfont, gint glyph);
const ArtSVP *   gnome_rfont_get_glyph_svp   (GnomeRFont * rfont, gint glyph);

/*
 * These are somewhat tricky, as you cannot do arbitrarily transformed
 * fonts with Pango. So be cautious and try to figure out the best
 * solution.
 */
PangoFont *            gnome_rfont_get_closest_pango_font (const GnomeRFont *rfont, PangoFontMap *map);
PangoFontDescription * gnome_rfont_get_pango_description  (const GnomeRFont *rfont);

G_END_DECLS

#endif /* __GNOME_RFONT_H__ */


