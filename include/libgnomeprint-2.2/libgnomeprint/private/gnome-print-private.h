/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print-private.h: 
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
 *  Copyright (C) 1999-2003 Ximian Inc. and authors
 */

#ifndef __GNOME_PRINT_PRIVATE_H__
#define __GNOME_PRINT_PRIVATE_H__

#include <glib.h>

G_BEGIN_DECLS

#ifndef WE_ARE_LIBGNOMEPRINT_INTERNALS
#error You should not be using this header, do so at your own risk.
#endif

#include <libart_lgpl/art_svp.h>
#include <libart_lgpl/art_svp_wind.h>
#include <libgnomeprint/gp-gc.h>
#include <libgnomeprint/gnome-print-config.h>
#include <libgnomeprint/gnome-print.h>

#define GNOME_PRINT_CONTEXT_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST ((k),   GNOME_TYPE_PRINT_CONTEXT, GnomePrintContextClass))
#define GNOME_IS_PRINT_CONTEXT_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k),   GNOME_TYPE_PRINT_CONTEXT))
#define GNOME_PRINT_CONTEXT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PRINT_CONTEXT, GnomePrintContextClass))

#define NEEDED_SUBSETTING(font) ((font)->face->entry->type == GP_FONT_ENTRY_TRUETYPE)

typedef struct _GnomePrintContextClass GnomePrintContextClass;
typedef struct _GnomePrintTransport      GnomePrintTransport;

struct _GnomePrintContext {
	   GObject object;

	   GnomePrintConfig *config;
	   GnomePrintTransport *transport;

	   GPGC * gc;
	   gboolean haspage;
	   gint pages;
};

struct _GnomePrintContextClass {
	GObjectClass parent_class;

	gint (* construct) (GnomePrintContext *pc);

	gint (* beginpage) (GnomePrintContext *pc, const guchar *name);
	gint (* showpage)  (GnomePrintContext *pc);
	gint (* end_doc)  (GnomePrintContext *pc);

	gint (* gsave)     (GnomePrintContext *pc);
	gint (* grestore)  (GnomePrintContext *pc);

	gint (* clip)      (GnomePrintContext *pc, const ArtBpath *bpath, ArtWindRule rule);
	gint (* fill)      (GnomePrintContext *pc, const ArtBpath *bpath, ArtWindRule rule);
	gint (* stroke)    (GnomePrintContext *pc, const ArtBpath *bpath);

	gint (* image)     (GnomePrintContext *pc, const gdouble *affine, const guchar *px, gint w, gint h, gint rowstride, gint ch);
	gint (* glyphlist) (GnomePrintContext *pc, const gdouble *affine, GnomeGlyphList *gl);

	gint (* close)     (GnomePrintContext *pc);
};

gint gnome_print_context_construct (GnomePrintContext *ctx, GnomePrintConfig *config);
gint gnome_print_context_create_transport (GnomePrintContext *ctx);

gint gnome_print_clip_bpath_rule     (GnomePrintContext *pc, const ArtBpath *bpath, ArtWindRule rule);
gint gnome_print_fill_bpath_rule     (GnomePrintContext *pc, const ArtBpath *bpath, ArtWindRule rule);
gint gnome_print_stroke_bpath        (GnomePrintContext *pc, const ArtBpath *bpath);
gint gnome_print_image_transform     (GnomePrintContext *pc, const gdouble *affine, const guchar *px, gint w, gint h, gint rowstride, gint ch);
gint gnome_print_glyphlist_transform (GnomePrintContext *pc, const gdouble *affine, GnomeGlyphList *gl);

typedef struct _GnomePrintLayout         GnomePrintLayout;
typedef struct _GnomePrintLayoutPage     GnomePrintLayoutPage;
typedef struct _GnomePrintLayoutData     GnomePrintLayoutData;
typedef struct _GnomePrintLayoutPageData GnomePrintLayoutPageData;

struct _GnomePrintLayout {
	   gdouble PP2PA[6];	/* physical page -> printed area matrix */
	   gdouble PAW, PAH;	/* printed area width and height */
	   gdouble LP2LY[6];	/* logical page -> layout matrix */
	   gdouble LYW, LYH;	/* layout dimensions */
	   gdouble LW, LH;	     /* logical dimensions */
	   gint NLY;	          /* number of layout pages */
	   GnomePrintLayoutPage *LYP;	/* layout pages */
};

struct _GnomePrintLayoutPage {
	   gdouble matrix[6];
};

struct _GnomePrintLayoutData {
	   gdouble pw, ph;                  /* Physical width and height */
	   gdouble porient[6];              /* Physical orientation */
	   gdouble lorient[6];              /* Logical orientation */
	   gdouble lyw, lyh;                /* Layout width and height */
	   gint num_pages;                  /* Number of pages */
	   GnomePrintLayoutPageData *pages; /* Pages */
};

struct _GnomePrintLayoutPageData {
	   gdouble matrix[6];
};

/* All keys can be NULL */
GnomePrintLayoutData *gnome_print_config_get_layout_data (GnomePrintConfig *config,
							  const guchar *pagekey,
							  const guchar *porientkey,
							  const guchar *lorientkey,
							  const guchar *layoutkey);
void gnome_print_layout_data_free (GnomePrintLayoutData *layoutdata);

GnomePrintLayout *gnome_print_layout_new_from_data (const GnomePrintLayoutData *layoutdata);
void gnome_print_layout_free (GnomePrintLayout *layout);



/* I'm putting this util funcs here for the mean time, find
 * the right plance for them (Chema) */
typedef struct _GnomePrintBuffer GnomePrintBuffer;
struct _GnomePrintBuffer {
	   guchar *buf;
	   gint buf_size;
};
void gnome_print_buffer_munmap (GnomePrintBuffer *b);
gint gnome_print_buffer_mmap   (GnomePrintBuffer *b, const guchar *file_name);
gboolean gnome_print_parse_transform (guchar *str, gdouble *transform);
/* End */

G_END_DECLS

#endif /* __GNOME_PRINT_PRIVATE_H__ */
