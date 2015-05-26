#ifndef __GNOME_PRINT_PRIVATE_H__
#define __GNOME_PRINT_PRIVATE_H__

/*
 * Abstract base class for drivers
 *
 * Authors:
 *   Raph Levien (raph@acm.org)
 *   Miguel de Icaza (miguel@kernel.org)
 *   Lauris Kaplinski <lauris@ximian.com>
 *   Chema Celorio (chema@celorio.com)
 *
 * Copyright (C) 1999-2001 Ximian, Inc. and authors
 *
 * Released under GNU Lesser General Public License.
 *
 */

#include <glib.h>

G_BEGIN_DECLS

/*
 * WARNING
 *
 * The API here can change at any moment without notice.
 *
 * It is not installed for user applications, but solely for libgnomeprintui
 *
 * WARNING
 *
 */

#ifndef WE_ARE_LIBGNOMEPRINT_UI
#error You should not be using this header, do so at your own risk.
#endif

#include <libart_lgpl/art_svp.h>
#include <libart_lgpl/art_svp_wind.h>
#include <libgnomeprint/gp-gc.h>
#include <libgnomeprint/gnome-print-config.h>
#include <libgnomeprint/gnome-print.h>

#define dontALLOW_BROKEN_PGL

#define GNOME_PRINT_CONTEXT_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_PRINT_CONTEXT, GnomePrintContextClass))
#define GNOME_IS_PRINT_CONTEXT_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_PRINT_CONTEXT))
#define GNOME_PRINT_CONTEXT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PRINT_CONTEXT, GnomePrintContextClass))

typedef struct _GnomePrintContextClass GnomePrintContextClass;

typedef struct _GnomePrintTransport GnomePrintTransport;

struct _GnomePrintContext {
	GObject object;

	GnomePrintConfig *config;
	GnomePrintTransport *transport;

	GPGC * gc;
	gboolean haspage;
};

struct _GnomePrintContextClass {
	GObjectClass parent_class;

	gint (* construct) (GnomePrintContext *ctx);

	gint (* beginpage) (GnomePrintContext *pc, const guchar *name);
	gint (* showpage) (GnomePrintContext *pc);

	gint (* gsave) (GnomePrintContext *pc);
	gint (* grestore) (GnomePrintContext *pc);

	gint (* clip) (GnomePrintContext *pc, const ArtBpath *bpath, ArtWindRule rule);
	gint (* fill) (GnomePrintContext *pc, const ArtBpath *bpath, ArtWindRule rule);
	gint (* stroke) (GnomePrintContext *pc, const ArtBpath *bpath);

	gint (* image) (GnomePrintContext *pc, const gdouble *affine, const guchar *px, gint w, gint h, gint rowstride, gint ch);

	gint (* glyphlist) (GnomePrintContext * pc, const gdouble *affine, GnomeGlyphList *gl);

	gint (* close) (GnomePrintContext *pc);

	gint (* page) (GnomePrintContext *pc, const guchar *name,
		       gpointer pagedata, gpointer docdata, GClosure *callback);
};

gint gnome_print_callback_closure_invoke (GnomePrintContext *ctx,
					  gpointer pagedata,
					  gpointer docdata,
					  GClosure *closure);

gint gnome_print_context_construct (GnomePrintContext *ctx, GnomePrintConfig *config);

gint gnome_print_context_create_transport (GnomePrintContext *ctx);

gint gnome_print_clip_bpath_rule (GnomePrintContext *pc, const ArtBpath *bpath, ArtWindRule rule);
gint gnome_print_fill_bpath_rule (GnomePrintContext *pc, const ArtBpath *bpath, ArtWindRule rule);
gint gnome_print_stroke_bpath (GnomePrintContext *pc, const ArtBpath *bpath);
gint gnome_print_image_transform (GnomePrintContext *pc, const gdouble *affine, const guchar *px, gint w, gint h, gint rowstride, gint ch);
gint gnome_print_glyphlist_transform (GnomePrintContext *pc, const gdouble *affine, GnomeGlyphList *gl);

typedef struct _GnomePrintLayout GnomePrintLayout;
typedef struct _GnomePrintLayoutPage GnomePrintLayoutPage;
typedef struct _GnomePrintLayoutData GnomePrintLayoutData;
typedef struct _GnomePrintLayoutPageData GnomePrintLayoutPageData;

struct _GnomePrintLayout {
	/* physical page -> printed area matrix */
	gdouble PP2PA[6];
	/* printed area width and height */
	gdouble PAW, PAH;
	/* logical page -> layout matrix */
	gdouble LP2LY[6];
	/* layout dimensions */
	gdouble LYW, LYH;
	/* logical dimensions */
	gdouble LW, LH;
	/* number of layout pages */
	gint NLY;
	/* layout pages */
	GnomePrintLayoutPage *LYP;
};

struct _GnomePrintLayoutPage {
	gdouble matrix[6];
};

struct _GnomePrintLayoutData {
	/* Physical width and height */
	gdouble pw, ph;
	/* Physical orientation */
	gdouble porient[6];
	/* Logical orientation */
	gdouble lorient[6];
	/* Layout width and height */
	gdouble lyw, lyh;
	/* Number of pages */
	gint num_pages;
	/* Pages */
	GnomePrintLayoutPageData *pages;
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

/* This method first appeared in 1.109 CVS */
gboolean gnome_print_config_get_transform (GnomePrintConfig *config, const guchar *key, gdouble *transform);

G_END_DECLS

#endif /* __GNOME_PRINT_PRIVATE_H__ */
