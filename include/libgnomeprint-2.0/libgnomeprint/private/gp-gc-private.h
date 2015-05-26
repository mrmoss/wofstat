#ifndef __GP_GC_PRIVATE_H__
#define __GP_GC_PRIVATE_H__

/*
 * Gnome Print Graphic Context
 *
 * Authors:
 *   Lauris Kaplinski <lauris@ximian.com>
 *
 * Copyright (C) 2001 Ximian, Inc.
 *
 * Licensed under GNU Lesser General Public License
 *
 */

#include <glib.h>

G_BEGIN_DECLS

/*
 * GPGC - an opaque object, holding current drawing parameters.
 *
 * Return value 0 for set methods indicates success, any other is error.
 *
 * We use very primitive tagging here, but it is suitable for libgnomeprint:
 * CTM, line, dash, color and font can be tagged as unset, clear or changed. It is
 * convenient way for print context to mark, whether they need to specify
 * style attributes for next serialized drawing call.
 * GC can also include single data value, which is used by libgnomeprintui
 * to store pointer to current GnomeCanvasGroup. It does not do any reference
 * handling, so it can be used only if we really know, what we are doing.
 *
 */

#include <libart_lgpl/art_vpath.h>
#include <libart_lgpl/art_svp.h>
#include <libart_lgpl/art_vpath_dash.h>
#include <libart_lgpl/art_svp_vpath_stroke.h>
#include <libgnomeprint/gnome-font.h>
#include <libgnomeprint/gp-gc.h>

#define GP_GC_FLAG_UNSET 0
#define GP_GC_FLAG_CHANGED 1
#define GP_GC_FLAG_CLEAR 2

GPGC * gp_gc_new (void);
void gp_gc_ref (GPGC * gc);
void gp_gc_unref (GPGC * gc);
void gp_gc_reset (GPGC * gc);

/* Stack manipulation */
gint gp_gc_gsave (GPGC * gc);
gint gp_gc_grestore (GPGC * gc);

/* CTM */
gint gp_gc_setmatrix (GPGC * gc, const gdouble * matrix);
gint gp_gc_concat (GPGC * gc, const gdouble * matrix);
const gdouble * gp_gc_get_ctm (GPGC * gc);
gint gp_gc_set_ctm_flag (GPGC * gc, gint flag);
gint gp_gc_get_ctm_flag (GPGC * gc);

/* Color */
gint gp_gc_set_rgbcolor (GPGC * gc, gdouble r, gdouble g, gdouble b);
gint gp_gc_set_opacity (GPGC * gc, gdouble opacity);
guint32 gp_gc_get_rgba (GPGC * gc);
gdouble gp_gc_get_red (GPGC * gc);
gdouble gp_gc_get_green (GPGC * gc);
gdouble gp_gc_get_blue (GPGC * gc);
gdouble gp_gc_get_opacity (GPGC * gc);
gint gp_gc_set_color_flag (GPGC * gc, gint flag);
gint gp_gc_get_color_flag (GPGC * gc);

/* Line attributes */
gint gp_gc_set_linewidth (GPGC * gc, gdouble width);
gint gp_gc_set_miterlimit (GPGC * gc, gdouble limit);
gint gp_gc_set_linejoin (GPGC * gc, ArtPathStrokeJoinType join);
gint gp_gc_set_linecap (GPGC * gc, ArtPathStrokeCapType cap);
gdouble gp_gc_get_linewidth (GPGC * gc);
gdouble gp_gc_get_miterlimit (GPGC * gc);
ArtPathStrokeJoinType gp_gc_get_linejoin (GPGC * gc);
ArtPathStrokeCapType gp_gc_get_linecap (GPGC * gc);
gint gp_gc_set_line_flag (GPGC * gc, gint flag);
gint gp_gc_get_line_flag (GPGC * gc);
gint gp_gc_set_dash (GPGC * gc, int num_values, const gdouble * values, gdouble offset);
const ArtVpathDash * gp_gc_get_dash (GPGC * gc);
gint gp_gc_set_dash_flag (GPGC * gc, gint flag);
gint gp_gc_get_dash_flag (GPGC * gc);


/* Font */
gint gp_gc_set_font (GPGC * gc, GnomeFont * font);
const GnomeFont * gp_gc_get_font (GPGC * gc);
gint gp_gc_set_font_flag (GPGC * gc, gint flag);
gint gp_gc_get_font_flag (GPGC * gc);

/* Currentpath */
gint gp_gc_newpath (GPGC * gc);
gint gp_gc_moveto (GPGC * gc, gdouble x, gdouble y);
gint gp_gc_lineto (GPGC * gc, gdouble x, gdouble y);
gint gp_gc_curveto (GPGC * gc, gdouble x1, gdouble y1, gdouble x2, gdouble y2, gdouble x3, gdouble y3);
gint gp_gc_closepath (GPGC * gc);

gint gp_gc_close_all (GPGC * gc);

gint gp_gc_strokepath (GPGC * gc);

gboolean gp_gc_has_currentpath (GPGC * gc);
gboolean gp_gc_has_currentpoint (GPGC * gc);
gboolean gp_gc_currentpath_all_closed (GPGC * gc);
gboolean gp_gc_currentpath_all_open (GPGC * gc);
gint gp_gc_currentpath_points (GPGC * gc);

const ArtPoint *gp_gc_get_currentpoint (GPGC *gc);
const ArtBpath *gp_gc_get_currentpath (GPGC *gc);

/* Clipping */

gint gp_gc_clip (GPGC * gc);
gint gp_gc_eoclip (GPGC * gc);

gboolean gp_gc_has_clipsvp (GPGC * gc);

const ArtSVP * gp_gc_get_clipsvp (GPGC * gc);

/* Useful for PrintPreview */

gint gp_gc_set_data (GPGC * gc, gpointer data);

gpointer gp_gc_get_data (GPGC * gc);


G_END_DECLS

#endif /* __GP_GC_PRIVATE__ */


