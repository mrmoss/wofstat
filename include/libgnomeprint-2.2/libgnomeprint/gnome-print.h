/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print.h: drawing functions api
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
 *    Raph Levien <raph@acm.org>
 *    Miguel de Icaza <miguel@kernel.org>
 *    Lauris Kaplinski <lauris@ximian.com>
 *    Chema Celorio <chema@celorio.com>
 *
 *  Copyright (C) 1999-2001 Ximian Inc. and authors
 *
 */

#ifndef __GNOME_PRINT_H__
#define __GNOME_PRINT_H__

#include <glib.h>

G_BEGIN_DECLS

/*
 * Notes
 *
 * GnomePrintContexts are both actual drivers and various frontends to
 * further job-processing objects. The API is always the same. Output
 * area is not constrained, so applications has to decide the effective
 * page size. The job may or may not be clipped to the effective page
 * size in the printing pipeline, so in multipage layouts your output
 * may be run out of component page area. If unsure, clip full page
 * manually, as the first graphic operation.
 *
 * All graphic operators have to be invoked between beginpage/showpage
 * pairs, doing otherwise the given method is ignored.
 *
 * If printing is completed, print context should be closed (to flush
 * all data). Closing does not unref print context, so if you have
 * obtained reference to it, release that after closing. Destroying
 * unclosed context discards all printed data (think about it as
 * canceling print a job).
 */

#include <glib-object.h>
#include <libgnomeprint/gnome-print-config.h>
#include <libgnomeprint/gnome-font.h>
#include <libgnomeprint/gnome-glyphlist.h>
#include <libart_lgpl/art_vpath.h>
#include <libart_lgpl/art_bpath.h>

/*
 * Result (error) codes
 *
 * These are the currently defined values for gnome_print functions
 * results feel free to add more, if it makes sense.
 * The rule is, that errors have to be negative, as several
 * methods return num bytes written, >= 0 has to be interpreted
 * as success.
 *
 */
typedef enum {
	GNOME_PRINT_OK = 0,
	GNOME_PRINT_ERROR_UNKNOWN        = -1,
	GNOME_PRINT_ERROR_BADVALUE       = -2,
	GNOME_PRINT_ERROR_NOCURRENTPOINT = -3,
	GNOME_PRINT_ERROR_NOCURRENTPATH  = -4,
	GNOME_PRINT_ERROR_TEXTCORRUPT    = -5,
	GNOME_PRINT_ERROR_BADCONTEXT     = -6,
	GNOME_PRINT_ERROR_NOPAGE         = -7,
	GNOME_PRINT_ERROR_NOMATCH        = -8
} GnomePrintReturnCode;

#define GNOME_TYPE_PRINT_CONTEXT  (gnome_print_context_get_type ())
#define GNOME_PRINT_CONTEXT(o)    (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_CONTEXT, GnomePrintContext))
#define GNOME_IS_PRINT_CONTEXT(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_CONTEXT))

typedef struct _GnomePrintContext GnomePrintContext;

GType               gnome_print_context_get_type (void);

GnomePrintContext * gnome_print_context_new (GnomePrintConfig *config);
gint                gnome_print_context_close (GnomePrintContext *pc);
gint                gnome_print_context_create_transport (GnomePrintContext *ctx);

/*
 * Drawing methods
 *
 * These behave similarly to standard PostScript operators, with some
 * slight differences. Most importantly ALL path output operations
 * (fill, stroke, clip) clear the currentpath.
 */

/* Path manipulation */
gint gnome_print_newpath    (GnomePrintContext *pc);
gint gnome_print_moveto     (GnomePrintContext *pc, gdouble x, gdouble y);
gint gnome_print_lineto     (GnomePrintContext *pc, gdouble x, gdouble y);
gint gnome_print_curveto    (GnomePrintContext *pc, gdouble x1, gdouble y1, gdouble x2, gdouble y2, gdouble x3, gdouble y3);
gint gnome_print_closepath  (GnomePrintContext *pc);
gint gnome_print_strokepath (GnomePrintContext *pc);
gint gnome_print_bpath      (GnomePrintContext *pc, const ArtBpath *bpath, gboolean append);
gint gnome_print_vpath      (GnomePrintContext *pc, const ArtVpath *vpath, gboolean append);
gint gnome_print_arcto      (GnomePrintContext *pc, gdouble x, gdouble y, gdouble radius, gdouble angle1, gdouble angle2, gint direction);

/* Graphic state manipulation */
gint gnome_print_setrgbcolor   (GnomePrintContext *pc, gdouble r, gdouble g, gdouble b);
gint gnome_print_setopacity    (GnomePrintContext *pc, gdouble opacity);
gint gnome_print_setlinewidth  (GnomePrintContext *pc, gdouble width);
gint gnome_print_setmiterlimit (GnomePrintContext *pc, gdouble limit);
gint gnome_print_setlinejoin   (GnomePrintContext *pc, gint jointype);
gint gnome_print_setlinecap    (GnomePrintContext *pc, gint captype);
gint gnome_print_setdash       (GnomePrintContext *pc, gint n_values, const gdouble *values, gdouble offset);
gint gnome_print_setfont       (GnomePrintContext *pc, const GnomeFont *font);
gint gnome_print_clip          (GnomePrintContext *pc);
gint gnome_print_eoclip        (GnomePrintContext *pc);

/* CTM manipulation */
gint gnome_print_concat    (GnomePrintContext *pc, const gdouble *matrix);
gint gnome_print_scale     (GnomePrintContext *pc, gdouble sx, gdouble sy);
gint gnome_print_rotate    (GnomePrintContext *pc, gdouble theta);
gint gnome_print_translate (GnomePrintContext *pc, gdouble x, gdouble y);

/* Stack */
gint gnome_print_gsave    (GnomePrintContext *pc);
gint gnome_print_grestore (GnomePrintContext *pc);

/* Painting */
gint gnome_print_fill   (GnomePrintContext *pc);
gint gnome_print_eofill (GnomePrintContext *pc);
gint gnome_print_stroke (GnomePrintContext *pc);

/* Text drawing */
gint gnome_print_show       (GnomePrintContext *pc, const guchar *text);
gint gnome_print_show_sized (GnomePrintContext *pc, const guchar *text, gint bytes);
gint gnome_print_glyphlist  (GnomePrintContext *pc, GnomeGlyphList *glyphlist);

/* Images */
gint gnome_print_grayimage (GnomePrintContext *pc, const guchar *data, gint width, gint height, gint rowstride);
gint gnome_print_rgbimage  (GnomePrintContext *pc, const guchar *data, gint width, gint height, gint rowstride);
gint gnome_print_rgbaimage (GnomePrintContext *pc, const guchar *data, gint width, gint height, gint rowstride);

/* Page */
gint gnome_print_beginpage (GnomePrintContext *pc, const guchar *name);
gint gnome_print_showpage (GnomePrintContext *pc);
gint gnome_print_end_doc (GnomePrintContext *pc);

/*
 * Convenience methods for printing straight lines and rectangles.
 */
gint gnome_print_line_stroked (GnomePrintContext *pc, gdouble x0, gdouble y0, gdouble x1, gdouble y1);
gint gnome_print_rect_stroked (GnomePrintContext *pc, gdouble x, gdouble y, gdouble width, gdouble height);
gint gnome_print_rect_filled  (GnomePrintContext *pc, gdouble x, gdouble y, gdouble width, gdouble height);

G_END_DECLS

#endif /* __GNOME_PRINT_H__ */

