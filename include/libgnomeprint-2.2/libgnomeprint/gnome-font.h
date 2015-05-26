/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-font.c: basic user visible handle to scaled typeface
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
 *  Copyright (C) 2000-2001 Ximian Inc. and authors
 */

#ifndef __GNOME_FONT_H__
#define __GNOME_FONT_H__

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_FONT    (gnome_font_get_type ())
#define GNOME_FONT(obj)    (G_TYPE_CHECK_INSTANCE_CAST ((obj), GNOME_TYPE_FONT, GnomeFont))
#define GNOME_IS_FONT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GNOME_TYPE_FONT))

#define gnome_font_ref(f)   g_object_ref   (G_OBJECT (f))
#define gnome_font_unref(f) g_object_unref (G_OBJECT (f))

typedef struct _GnomeFont     GnomeFont;
typedef struct _GnomeFontFace GnomeFontFace;


/*
 * These numbers are very loosely adapted from the Univers numbering
 * convention. I've had to insert some to accomodate all the
 * distinctions in the Adobe font catalog.
 * Removed offseting and gaps (Lauris)
 * Multiplied by 100, so it matches with Pango weight (Lauris)
 */
typedef enum {
	GNOME_FONT_LIGHTEST = 100,
	GNOME_FONT_EXTRA_LIGHT = 100,
	GNOME_FONT_THIN = 200,
	GNOME_FONT_LIGHT = 300,
	GNOME_FONT_BOOK = 400,
	GNOME_FONT_REGULAR = 400,
	GNOME_FONT_MEDIUM = 500,
	GNOME_FONT_SEMI = 600,
	GNOME_FONT_DEMI = 600,
	GNOME_FONT_BOLD = 700,
	GNOME_FONT_HEAVY = 900,
	GNOME_FONT_EXTRABOLD = 900,
	GNOME_FONT_BLACK = 1000,
	GNOME_FONT_EXTRABLACK = 1100,
	GNOME_FONT_HEAVIEST = 1100
} GnomeFontWeight;

#include <pango/pango-fontmap.h>
#include <libgnomeprint/gnome-font-face.h>

/*
 * Methods
 *
 * Look into gnome-font-face for explanations
 */

GType gnome_font_get_type (void);

const guchar   *gnome_font_get_name         (const GnomeFont *font);
const guchar   *gnome_font_get_family_name  (const GnomeFont *font);
const guchar   *gnome_font_get_species_name (const GnomeFont *font);
const guchar   *gnome_font_get_ps_name      (const GnomeFont *font);

gdouble         gnome_font_get_size         (const GnomeFont *font);
GnomeFontFace  *gnome_font_get_face         (const GnomeFont *font);

ArtPoint       *gnome_font_get_glyph_stdadvance (GnomeFont *font, gint glyph, ArtPoint *advance);
ArtDRect       *gnome_font_get_glyph_stdbbox    (GnomeFont *font, gint glyph, ArtDRect *bbox);
const ArtBpath *gnome_font_get_glyph_stdoutline (GnomeFont *font, gint glyph);
ArtPoint       *gnome_font_get_glyph_stdkerning (GnomeFont *font, gint glyph0, gint glyph1, ArtPoint *kerning);

gdouble         gnome_font_get_glyph_width      (GnomeFont *font, gint glyph);
gdouble         gnome_font_get_glyph_kerning    (GnomeFont *font, gint glyph1, gint glyph2);

/* Unicode -> glyph translation */
gint gnome_font_lookup_default (GnomeFont *font, gint unicode);

/*
 * Backward compatibility and convenience methods
 *
 * NB! Those usually do not scale for international fonts, so use with
 * caution.
 */
#define gnome_font_get_weight_code(f) gnome_font_face_get_weight_code (gnome_font_get_face (f))
#define gnome_font_is_italic(f)       gnome_font_face_is_italic       (gnome_font_get_face (f))
#define gnome_font_is_fixed_width(f)  gnome_font_face_is_fixed_width  (gnome_font_get_face (f))

guchar   *gnome_font_get_full_name           (GnomeFont *font);
gdouble   gnome_font_get_ascender            (GnomeFont *font);
gdouble   gnome_font_get_descender           (GnomeFont *font);
gdouble   gnome_font_get_underline_position  (GnomeFont *font);
gdouble   gnome_font_get_underline_thickness (GnomeFont *font);

/* Find the closest face matching the family name, weight, and italic */
/* This is not very intelligent, so use with caution (Lauris) */

/* Font fetching */
GnomeFont *gnome_font_find                           (const guchar *name, gdouble size);
GnomeFont *gnome_font_find_closest                   (const guchar *name, gdouble size);
GnomeFont *gnome_font_find_from_full_name            (const guchar *string);
GnomeFont *gnome_font_find_from_filename             (const guchar *filename, gint index_, gdouble size);
GnomeFont *gnome_font_find_closest_from_full_name    (const guchar *string);
GnomeFont *gnome_font_find_closest_from_weight_slant (const guchar *family, GnomeFontWeight weight, gboolean italic, gdouble size);


/* Lists */
GList  *gnome_font_list (void);
void    gnome_font_list_free (GList *fontlist);

GList  *gnome_font_family_list (void);
void    gnome_font_family_list_free (GList *fontlist);

GList  *gnome_font_style_list (const guchar *family);
void    gnome_font_style_list_free (GList *styles);


/*
 * These are somewhat tricky, as you cannot do arbitrarily transformed
 * fonts with Pango. So be cautious and try to figure out the best
 * solution.
 */
PangoFont            *gnome_font_get_closest_pango_font (const GnomeFont *font, PangoFontMap *map, gdouble dpi);
PangoFontDescription *gnome_font_get_pango_description (const GnomeFont *font, gdouble dpi);


#ifndef BREAK_COMPATIBILITY
/*
 * We keep these at moment, but in future better go with Pango/glyphlists
 */
/* Normal utf8 functions */
/* These are still crap, as you cannot expect ANYTHING about layouting rules */
double gnome_font_get_width_utf8       (GnomeFont *font, const char *s);
double gnome_font_get_width_utf8_sized (GnomeFont *font, const char *s, int n);
#endif

G_END_DECLS

#endif /* __GNOME_FONT_H__ */



