/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-glyphlist.h: Device independent rich text representation system
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
 *
 */

#ifndef __GNOME_GLYPHLIST_H__
#define __GNOME_GLYPHLIST_H__

#include <glib.h>

G_BEGIN_DECLS

/*
 * Although marked as experimental, this is used extensively by
 * libgnomeprint internals. So it should be stable enough for
 * everyone.
 *
 * The idea of glyphlist is to store text as:
 * - glyphs of certain font
 * - rules determining glyph interconnections
 *
 * There are 2 extreme cases:
 * - glyphs are just stored as sequential string, and placed
 *   sequentially (like trivial text outputting methods do)
 * - each glyph has x,y coordinates and is placed individually
 *   (like they are in PangoGlyphString)
 *
 * The real power comes from the fact, that one can generate
 * custom intermediate versions - for example - let all glyphs
 * of a word to flow sequentially, but set word starting points
 * exactly - or whatever else.
 *
 * NB - we are dealing exclusively with glyph here, except
 * _text_dumb methods - so application has to do language
 * dependent character->glyph conversion and logical placement
 * itself.
 *
 * The important feature is, that glyphlists can be transfromed,
 * without losing logical connection between glyphs (scaled,
 * rotated etc.). Thus if final renderer is smart enough, it
 * can still do fine grid-fitting of glyph metrics, thus minimizing
 * visual artefacts.
 *
 */

#define GNOME_TYPE_GLYPHLIST (gnome_glyphlist_get_type())
#define GNOME_IS_GLYPHLIST(g) gnome_glyphlist_check (g, FALSE)

typedef struct _GnomeGlyphList GnomeGlyphList;

#include <libgnomeprint/gnome-font.h>

GType            gnome_glyphlist_get_type (void);
GnomeGlyphList * gnome_glyphlist_new (void);

GnomeGlyphList * gnome_glyphlist_ref       (GnomeGlyphList *gl);
GnomeGlyphList * gnome_glyphlist_unref     (GnomeGlyphList *gl);
GnomeGlyphList * gnome_glyphlist_duplicate (GnomeGlyphList *gl);

gboolean         gnome_glyphlist_check (const GnomeGlyphList *gl, gboolean rules);
ArtDRect *       gnome_glyphlist_bbox  (const GnomeGlyphList *gl, const gdouble *transform, gint flags, ArtDRect *bbox);

void gnome_glyphlist_advance     (GnomeGlyphList *gl, gboolean advance);
void gnome_glyphlist_kerning     (GnomeGlyphList *gl, gdouble kerning);
void gnome_glyphlist_letterspace (GnomeGlyphList *gl, gdouble letterspace);
void gnome_glyphlist_font        (GnomeGlyphList *gl, GnomeFont *font);
void gnome_glyphlist_color       (GnomeGlyphList *gl, guint32 color);
void gnome_glyphlist_moveto      (GnomeGlyphList *gl, gdouble x, gdouble y);
void gnome_glyphlist_rmoveto     (GnomeGlyphList *gl, gdouble x, gdouble y);
void gnome_glyphlist_glyph       (GnomeGlyphList *gl, gint glyph);
void gnome_glyphlist_glyphs      (GnomeGlyphList *gl, gint *glyphs, gint num_glyphs);


void gnome_glyphlist_text_dumb       (GnomeGlyphList *gl, const guchar *text);
void gnome_glyphlist_text_sized_dumb (GnomeGlyphList *gl, const guchar *text, gint length);

GnomeGlyphList *gnome_glyphlist_from_text_dumb       (GnomeFont *font, guint32 color,
						      gdouble kerning, gdouble letterspace,
						      const guchar *text);
GnomeGlyphList *gnome_glyphlist_from_text_sized_dumb (GnomeFont *font, guint32 color,
						      gdouble kerning, gdouble letterspace,
						      const guchar *text, gint length);

G_END_DECLS

#endif /* __GNOME_GLYPHLIST_H__ */

