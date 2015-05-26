#ifndef __GNOME_FONT_PRIVATE_H__
#define __GNOME_FONT_PRIVATE_H__

/*
 * Private declarations for fonts
 *
 * Authors:
 *   Jody Goldberg <jody@helixcode.com>
 *   Miguel de Icaza <miguel@helixcode.com>
 *   Lauris Kaplinski <lauris@helixcode.com>
 *   Christopher James Lahey <clahey@helixcode.com>
 *   Michael Meeks <michael@helixcode.com>
 *   Morten Welinder <terra@diku.dk>
 *
 * Copyright (C) 1999-2000 Helix Code, Inc. and authors
 *
 */

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_FONT_FACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GNOME_TYPE_FONT_FACE, GnomeFontFaceClass))
#define GNOME_IS_FONT_FACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GNOME_TYPE_FONT_FACE))
#define GNOME_FONT_FACE_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_FONT_FACE, GnomeFontFaceClass))

#define GNOME_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GNOME_TYPE_FONT, GnomeFontClass))
#define GNOME_IS_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GNOME_TYPE_FONT))
#define GNOME_FONT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_FONT, GnomeFontClass))

#define GNOME_FONT_FAMILY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GNOME_TYPE_FONT_FAMILY, GnomeFontFamilyClass))
#define GNOME_IS_FONT_FAMILY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GNOME_TYPE_FONT_FAMILY))
#define GNOME_FONT_FAMILY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_FONT_FAMILY, GnomeFontFamilyClass))

typedef struct _GnomeFontFaceClass GnomeFontFaceClass;
typedef struct _GnomeFontClass GnomeFontClass;
typedef struct _GnomeFontFamilyClass GnomeFontFamilyClass;
typedef struct _GFFGlyphInfo GFFGlyphInfo;

#include <glib-object.h>
#include <ft2build.h>
#include <freetype/freetype.h>
#include "gp-fontmap.h"
#include "gnome-font.h"
#include "gnome-rfont.h"

/* Glyph info slot */
struct _GFFGlyphInfo {
	guint metrics : 1;
	ArtPoint advance;
	ArtDRect bbox;
	ArtBpath *bpath;
};

struct _GnomeFontFace {
	GObject object;

	/* Pointer to our fontmap entry */
	GPFontEntry * entry;
	/* Glyph storage */
	gint num_glyphs;
	GFFGlyphInfo * glyphs;
	/* FT -> PostScript scaling coefficent */
	gdouble ft2ps;
	/* Face bounding box */
	ArtDRect bbox;
	/* FreeType stuff */
	FT_Face ft_face;
	/* Our fonts */
	GSList *fonts;
};

struct _GnomeFontFaceClass {
	GObjectClass parent_class;
};

/* Font */

struct _GnomeFont {
	GObject object;
	/* Our parent face */
	GnomeFontFace *face;
	/* Our master size */
	gdouble size;
	/* Constified name */
	guchar *name;
	/* Hash table of glyph outlines */
	GHashTable *outlines;
};

struct _GnomeFontClass {
	GObjectClass parent_class;
};

GnomeFont *gnome_font_face_get_font_full (GnomeFontFace *face, gdouble size, gdouble *affine);

/* Embeddable PostScript object */

typedef struct _GFPSObject GFPSObject;

struct _GFPSObject {
	/* Our face (NB referenced) */
	GnomeFontFace *face;
	/* Resident face name, if any */
	guchar *residentname;
	/* Name of final font (i.e. findfont argument) */
	guchar *encodedname;
	/* 1 or 2 byte encoding
	 * This will be set according to total number of
	 * glyphs in font, as we cannot know the number
	 * of glyphs used initially */
	gint encodedbytes;
	/* Number of glyphs in face */
	gint num_glyphs;
	/* Used glyph bit array */
	guint32 *glyphs;
	/* Buffer values */
	gint bufsize;
	gint length;
	guchar *buf;
};

GFPSObject *gnome_font_face_pso_new (GnomeFontFace *face, guchar *residentname);
/* Mark glyph as used in internal bit array */
void gnome_font_face_pso_mark_glyph (GFPSObject *pso, gint glyph);
void gnome_font_face_pso_free (GFPSObject *pso);
void gnome_font_face_pso_ensure_buffer (GFPSObject *pso);

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

#define gnome_rfont_render_pgl_rgb8 gnome_pgl_render_rgb8
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

#endif

