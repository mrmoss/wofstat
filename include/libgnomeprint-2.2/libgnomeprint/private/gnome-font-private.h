/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-font-private.h: Private declarations for fonts
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
 *    Jody Goldberg <jody@helixcode.com>
 *    Miguel de Icaza <miguel@helixcode.com>
 *    Lauris Kaplinski <lauris@helixcode.com>
 *    Christopher James Lahey <clahey@helixcode.com>
 *    Michael Meeks <michael@helixcode.com>
 *    Morten Welinder <terra@diku.dk>
 *
 *  Copyright (C) 2000-2003 Ximian Inc. and authors
 *
 */

#ifndef __GNOME_FONT_PRIVATE_H__
#define __GNOME_FONT_PRIVATE_H__

#include <glib.h>

G_BEGIN_DECLS

typedef struct _GnomeFontClass       GnomeFontClass;
typedef struct _GnomeFontFaceClass   GnomeFontFaceClass;
typedef struct _GnomeFontFamilyClass GnomeFontFamilyClass;
typedef struct _GFFGlyphInfo GFFGlyphInfo;

#include <glib-object.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "gnome-fontmap.h"
#include <libgnomeprint/gnome-font.h>
#include <libgnomeprint/gnome-rfont.h>

/* Glyph info slot */
struct _GFFGlyphInfo {
	guint metrics : 1;
	ArtPoint advance;
	ArtDRect bbox;
	ArtBpath *bpath;
};

struct _GnomeFontFace {
	GObject object;

	GPFontEntry * entry;   /* Pointer to our fontmap entry */
	gint num_glyphs;       /* Glyph storage */
	GFFGlyphInfo * glyphs;
	
	gdouble ft2ps;         /* FT -> PostScript scaling coefficent */
	ArtDRect bbox;         /* Face bounding box */
	FT_Face ft_face;       /* FreeType stuff */
	GSList *fonts;         /* Our fonts */
	gchar *psname;         /* The postscript name of the font */
};

struct _GnomeFontFaceClass {
	GObjectClass parent_class;
};

/* Font */

struct _GnomeFont {
	GObject object;

	GnomeFontFace *face;	/* Our parent face */
	gdouble size;           /* Our master size */
	guchar *name;	        /* Constified name */
	GHashTable *outlines;	/* Hash table of glyph outlines */
};

struct _GnomeFontClass {
	GObjectClass parent_class;
};

GnomeFont *gnome_font_face_get_font_full (GnomeFontFace *face, gdouble size, gdouble *affine);

/* Embeddable PostScript object */

typedef struct _GnomeFontPsObject GnomeFontPsObject;

struct _GnomeFontPsObject {
	GnomeFontFace *face; 	/* Our face (NB referenced) */
	guchar *residentname;	/* Resident face name, if any */
	guchar *encodedname;	/* Name of the font in output (i.e. GnomeUni-LuxiSans_001) */

	gint encodedbytes;	/* 1 or 2 byte encoding
				 * This will be set according to total number of
				 * glyphs in font, as we cannot know the number
				 * of glyphs used initially */
	
	gint num_glyphs;	/* Number of glyphs in face */
	guint32 *glyphs;	/* Used glyph bit array */

	gint bufsize;	        /* Buffer values */
	gint length;
	guchar *buf;
};

GnomeFontPsObject *gnome_font_face_pso_new (GnomeFontFace *face, guchar *residentname, gint instance);
/* Mark glyph as used in internal bit array */
void gnome_font_face_pso_mark_glyph (GnomeFontPsObject *pso, gint glyph);
void gnome_font_face_pso_free (GnomeFontPsObject *pso);
void gnome_font_face_ps_embed (GnomeFontPsObject *pso);

/* Private face loader */

gboolean gff_load (GnomeFontFace *face);

#define GFF_LOADED(f) ((f)->ft_face || gff_load ((GnomeFontFace *) f))


/*
 * Returns PostScript name for glyph
 */

const guchar *gnome_font_unsized_get_glyph_name (const GnomeFontFace *face);


/* ---- gnome-rfont-stuff --- */
/*
 * Rendering flags
 *
 * Look into gnome-pgl.h for more meaningful definitions
 */

#define GNOME_RFONT_RENDER_DEFAULT 0

#define gnome_rfont_render_pgl_rgb8  gnome_pgl_render_rgb8
#define gnome_rfont_render_pgl_rgba8 gnome_pgl_render_rgba8


void gnome_rfont_render_glyph_rgba8 (GnomeRFont *rfont, gint glyph,
							  guint32 rgba,
							  gdouble x, gdouble y,
							  guchar * buf,
							  gint width, gint height, gint rowstride,
							  guint flags);

void gnome_rfont_render_glyph_rgb8 (GnomeRFont *rfont, gint glyph,
							 guint32 rgba,
							 gdouble x, gdouble y,
							 guchar * buf,
							 gint width, gint height, gint rowstride,
							 guint flags);

G_END_DECLS

#endif /* __GNOME_FONT_PRIVATE_H__ */
