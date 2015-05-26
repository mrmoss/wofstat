/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-font-face.h: unscaled typeface
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
 *    Jody Goldberg <jody@ximian.com>
 *    Miguel de Icaza <miguel@ximian.com>
 *    Lauris Kaplinski <lauris@ximian.com>
 *    Christopher James Lahey <clahey@ximian.com>
 *    Michael Meeks <michael@ximian.com>
 *    Morten Welinder <terra@diku.dk>
 *
 *  Copyright (C) 2000-2003 Ximian Inc. and authors
 *
 */

#ifndef __GNOME_FONT_FACE_H__
#define __GNOME_FONT_FACE_H__

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_FONT_FACE  (gnome_font_face_get_type ())
#define GNOME_FONT_FACE(o)    (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_FONT_FACE, GnomeFontFace))
#define GNOME_IS_FONT_FACE(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_FONT_FACE))

#include <libart_lgpl/art_rect.h>
#include <libart_lgpl/art_bpath.h>
#include <pango/pango-font.h>
#include <libgnomeprint/gnome-font.h>

#define gnome_font_face_ref(f)   g_object_ref (G_OBJECT (f))
#define gnome_font_face_unref(f) g_object_unref (G_OBJECT (f))

GType gnome_font_face_get_type (void);

/*
 * Finding
 */
GnomeFontFace *gnome_font_face_find         (const guchar *name);
GnomeFontFace *gnome_font_face_find_closest (const guchar *name);
GnomeFontFace *gnome_font_face_find_closest_from_weight_slant (const guchar *family, GnomeFontWeight weight, gboolean italic);
GnomeFontFace *gnome_font_face_find_closest_from_pango_font        (PangoFont *pfont);
GnomeFontFace *gnome_font_face_find_closest_from_pango_description (const PangoFontDescription *desc);
GnomeFontFace *gnome_font_face_find_from_family_and_style (const guchar *family, const guchar *style);
GnomeFontFace *gnome_font_face_find_from_filename (const guchar *filename, gint index_);

/*
 * Create font
 *
 * Those allow one to get sized font object from given typeface. Theoretically
 * GnomeFont should be optimized for certain resolution (resx, resy). If that
 * resolution is not known, get_font_default should give reasonably well-
 * looking font for most occasions
 */
GnomeFont *gnome_font_face_get_font (GnomeFontFace *face, gdouble size, gdouble xres, gdouble yres);
GnomeFont *gnome_font_face_get_font_default (GnomeFontFace *face, gdouble size);

/*
 * Naming
 *
 * gnome_font_face_get_name () should return one "true" name for font, that
 * does not have to be its PostScript name.
 * In future those names can be possibly localized (except ps_name)
 */
const guchar * gnome_font_face_get_name         (const GnomeFontFace *face);
const guchar * gnome_font_face_get_ps_name      (const GnomeFontFace *face);
const guchar * gnome_font_face_get_family_name  (const GnomeFontFace *face);
const guchar * gnome_font_face_get_species_name (const GnomeFontFace *face);

/*
 * Get glyph number from unicode char
 *
 * In future there can probably be several different unicode to glyph
 * character mappings per font (for different languages), current function
 * uses the default one :)
 */
gint gnome_font_face_lookup_default (GnomeFontFace *face, gint unicode);


/*
 * Metrics
 *
 * Currently those return standard values for left to right, horizontal script
 * The prefix std means, that there (a) will hopefully be methods to extract
 * different metric values and (b) for given face one text direction can
 * be defined as "default"
 * All face metrics are given in 0.001 em units
 */
const ArtDRect *gnome_font_face_get_stdbbox (GnomeFontFace *face);
ArtDRect       *gnome_font_face_get_glyph_stdbbox (GnomeFontFace *face, gint glyph, ArtDRect * bbox);
ArtPoint       *gnome_font_face_get_glyph_stdadvance (GnomeFontFace *face, gint glyph, ArtPoint * advance);
const ArtBpath *gnome_font_face_get_glyph_stdoutline (GnomeFontFace *face, gint glyph);
ArtPoint       *gnome_font_face_get_glyph_stdkerning (GnomeFontFace *face, gint glyph0, gint glyph1, ArtPoint *kerning);


/*
 * Give (possibly localized) demonstration text for given face
 * Most usually this tells about quick fox and lazy dog...
 */
const guchar * gnome_font_face_get_sample (GnomeFontFace *face);


/*
 * Convenience methods
 * NB! Unlike in gnome 1, descender is negative for "normal" fonts (like in afm)
 * Use with caution for international fonts
 */
GnomeFontWeight gnome_font_face_get_weight_code (GnomeFontFace *face);
gboolean        gnome_font_face_is_italic       (GnomeFontFace *face);
gboolean        gnome_font_face_is_fixed_width  (GnomeFontFace *face);

gdouble         gnome_font_face_get_ascender  (GnomeFontFace *face);
gdouble         gnome_font_face_get_descender (GnomeFontFace *face);
gdouble         gnome_font_face_get_underline_position  (GnomeFontFace *face);
gdouble         gnome_font_face_get_underline_thickness (GnomeFontFace *face);

gint            gnome_font_face_get_num_glyphs    (GnomeFontFace *face);

gdouble         gnome_font_face_get_glyph_width   (GnomeFontFace *face, gint glyph);
gdouble         gnome_font_face_get_glyph_kerning (GnomeFontFace *face, gint glyph1, gint glyph2);
const guchar   *gnome_font_face_get_glyph_ps_name (GnomeFontFace *face, gint glyph);

G_END_DECLS

#endif /* __GNOME_FONT_FACE_H__ */



