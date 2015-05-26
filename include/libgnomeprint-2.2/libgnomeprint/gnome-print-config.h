/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print-config.h: A frontend abstraction to whatever config system we
 *  will eventually have.
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU Library General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or (at your
 *  option) any later version.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
 *  License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this program; see the file COPYING.LIB. If not, write to the
 *  Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 *  MA  02111-1307  USA
 *
 *  Authors:
 *    Lauris Kaplinski <lauris@helixcode.com>
 *    Chema Celorio <chema@ximian.com>
 *
 *  Copyright 2001-2003 Ximian, Inc.
 */

#ifndef __GNOME_PRINT_CONFIG_H__
#define __GNOME_PRINT_CONFIG_H__

#include <glib.h>

G_BEGIN_DECLS

/*
 * NOTES
 *
 * This is an all-in-one printer configuration object.
 *
 * It allows several fancy tricks, and more can be implemented in future.
 *
 * The most basic usage is:
 *   config = gnome_print_config_default ();
 *   - set/get values in config
 *   - create libgnomeprintui dialogs from that config
 *   - create all print [context/master] from that config
 *   - do printing
 *   gnome_print_config_unref ();
 *
 * In addition to printer specific information, it can store some more
 * generic data, that application may, or may not, be interested in,
 * like page layout and margins.
 *
 * IMPORTANT
 *
 * Paper/Page size has been broken into different configuration
 * values.
 * Paper size or PhysicalSize refers strictly to the
 * real-world paper size in printer, similarly PhysicalOrientation
 * marks, which paper side goes first into printer input tray.
 * Page size or Logical Size refers to imaging area available to
 * application. This can coincide with the physical paper size,
 * but does not have to. Take an example:
 *   Physical A4 has always size W 210mm and H 297mm
 *   It can be fed into a printer in 4 different ways (PhysicalOrientations)
 *   - whatever you choose, does not affect the available page
 *     size. If paper is fed in rotated way, the printing subsystem
 *     rotates the printed page accordingly.
 *   Having Plain (1:1) layout and Landscape LOGICAL orientation
 *     changes available imaging area to W 297mm H 210mm.
 *     I.e. logical layout/orientation specifies, how your actual
 *     printed page is transferred to physical paper.
 *   Having multipage layouts make things even more complex,
 *     as your total page area may be different from paper size
 * How the actual layout is calculated, is quite complex, and you
 * probably want to avoid doing that in application programs.
 * There are helper methods in GnomePrintMaster, that give you
 * the only real important values needed - available imaging
 * area width and height.
 * Also - only GnomePrintMaster parses layouts and rearranges
 * printout. Plain print contexts are one step lower-level, and
 * transfer printout directly to specified Physicalpage. You
 * are safe to use these, if you are 100% sure that you do not
 * want to allow multipage layouts and automatic feed orientation
 * compensation.
 *
 * ALSO
 *
 * Depending on key, its value can not be trivial. Most importantly
 * paper dimensions are given as metric strings (i.e. '210mm', '8in')
 * Consult with individual key descriptions about the format used.
 *
 * Matrixes are specified as transform (a0 a1 a2 a3 a4 a5), and used
 *
 * X' = X * A0 + Y * A2 + A4
 * Y' = X * A1 + Y * A3 + A5
 *
 * But be careful with orientation matrixes, as A4 and A5 values are
 * specified as fractions of the target size in the given dimension - i.e.
 * they can be either width or height, depending on the rotation used.
 *
 * 14/12/2001
 * Lauris Kaplinski
 */

typedef struct _GnomePrintConfig GnomePrintConfig;

#include <glib-object.h>
#include <libgnomeprint/gnome-print-unit.h>

#define GNOME_TYPE_PRINT_CONFIG         (gnome_print_config_get_type ())
#define GNOME_PRINT_CONFIG(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_CONFIG, GnomePrintConfig))
#define GNOME_IS_PRINT_CONFIG(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_CONFIG))

GType             gnome_print_config_get_type (void);

GnomePrintConfig *gnome_print_config_default (void);

GnomePrintConfig *gnome_print_config_ref   (GnomePrintConfig *config);
GnomePrintConfig *gnome_print_config_unref (GnomePrintConfig *config);
GnomePrintConfig *gnome_print_config_dup   (GnomePrintConfig *config);

gchar *           gnome_print_config_to_string (GnomePrintConfig *gpc, guint flags);
GnomePrintConfig *gnome_print_config_from_string (const gchar *str, guint flags);

/*
 * Get/Set key value pairs
 *
 * All methods except gnome_print_config_get return TRUE on success (given
 * key exists and/or its value can be changed to new value), FALSE otherwise.
 * gnome_print_config_get just returns NULL, if the given key does not exist.
 *
 */
guchar  *gnome_print_config_get         (GnomePrintConfig *config, const guchar *key);
gboolean gnome_print_config_set         (GnomePrintConfig *config, const guchar *key, const guchar *value);

gboolean gnome_print_config_get_boolean (GnomePrintConfig *config, const guchar *key, gboolean *val);
gboolean gnome_print_config_get_int     (GnomePrintConfig *config, const guchar *key, gint *val);
gboolean gnome_print_config_get_double  (GnomePrintConfig *config, const guchar *key, gdouble *val);
gboolean gnome_print_config_get_length  (GnomePrintConfig *config, const guchar *key, gdouble *val, const GnomePrintUnit **unit);

gboolean gnome_print_config_set_boolean (GnomePrintConfig *config, const guchar *key, gboolean val);
gboolean gnome_print_config_set_int     (GnomePrintConfig *config, const guchar *key, gint val);
gboolean gnome_print_config_set_double  (GnomePrintConfig *config, const guchar *key, gdouble val);
gboolean gnome_print_config_set_length  (GnomePrintConfig *config, const guchar *key, gdouble val, const GnomePrintUnit *unit);
gboolean gnome_print_config_get_transform (GnomePrintConfig *config, const guchar *key, gdouble *transform);

/*
 * Convenience
 */
gboolean  gnome_print_config_get_page_size (GnomePrintConfig *config, gdouble *width, gdouble *height);

/*
 * Debugging
 */
void gnome_print_config_dump (GnomePrintConfig *gpc);

/*
 * Add nodes to the configuration object, experimental
 */
#ifdef GNOME_PRINT_UNSTABLE_API
typedef struct _GnomePrintConfigOption GnomePrintConfigOption;
struct _GnomePrintConfigOption {
	const gchar *id;
	const gchar *description;
	gint index;
};

gboolean gnome_print_config_insert_boolean (GnomePrintConfig *config, const guchar *key,
					    gboolean def);
gboolean gnome_print_config_insert_options (GnomePrintConfig *config, const guchar *key,
					    GnomePrintConfigOption *options, const gchar *def);

gboolean gnome_print_config_get_option (GnomePrintConfig *config, const guchar *key,
					GnomePrintConfigOption *options, gint *);
#endif

/*
 * Paper size
 *
 * NB - this is NOT necessarily the actual page size you want to use in application
 * NB - If using multipage layouts, actual size is calculated from paper size,
 *      page orientation and layout.
 *
 */

/*
 * Convenience keys
 */
#define GNOME_PRINT_KEY_PAPER_SIZE               "Settings.Output.Media.PhysicalSize" /* Paper name, such as A4 or Letter */
#define GNOME_PRINT_KEY_PAPER_WIDTH              "Settings.Output.Media.PhysicalSize.Width" /* Arbitrary units - use conversion */
#define GNOME_PRINT_KEY_PAPER_HEIGHT             "Settings.Output.Media.PhysicalSize.Height" /* Arbitrary units - use conversion */
#define GNOME_PRINT_KEY_PAPER_ORIENTATION        "Settings.Output.Media.PhysicalOrientation" /* R0, R90, R180, R270 */
#define GNOME_PRINT_KEY_PAPER_ORIENTATION_MATRIX "Settings.Output.Media.PhysicalOrientation.Paper2PrinterTransform" /* 3x2 abstract matrix */

#define GNOME_PRINT_KEY_PAGE_ORIENTATION        "Settings.Document.Page.LogicalOrientation" /* R0, R90, R180, R270 */
#define GNOME_PRINT_KEY_PAGE_ORIENTATION_MATRIX "Settings.Document.Page.LogicalOrientation.Page2LayoutTransform" /* 3x2 abstract matrix */

/* Just a reminder - application is only interested in logical orientation */
#define GNOME_PRINT_KEY_ORIENTATION GNOME_PRINT_KEY_PAGE_ORIENTATION

#define GNOME_PRINT_KEY_LAYOUT        "Settings.Document.Page.Layout"        /* Id of layout ('Plain' is always no-special-layout) */
#define GNOME_PRINT_KEY_LAYOUT_WIDTH  "Settings.Document.Page.Layout.Width"  /* Double value */
#define GNOME_PRINT_KEY_LAYOUT_HEIGHT "Settings.Document.Page.Layout.Height" /* Double value */

#define GNOME_PRINT_KEY_PAPER_SOURCE  "Settings.Output.PaperSource"          /* String value, like "Tray 1" */

/* Master resolution, i.e. ink dots for color printer RGB resolution is usually smaller */
#define GNOME_PRINT_KEY_RESOLUTION       "Settings.Output.Resolution"       /* String value, like 300x300 or 300dpi */
#define GNOME_PRINT_KEY_RESOLUTION_DPI   "Settings.Output.Resolution.DPI"   /* Numeric value, like 300, if meaningful */
#define GNOME_PRINT_KEY_RESOLUTION_DPI_X "Settings.Output.Resolution.DPI.X" /* Numeric value */
#define GNOME_PRINT_KEY_RESOLUTION_DPI_Y "Settings.Output.Resolution.DPI.Y" /* Numeric value */

/* These belong to 'Output' because PGL may implement multiple copies itself */
#define GNOME_PRINT_KEY_NUM_COPIES "Settings.Output.Job.NumCopies" /* Number of copies */
#define GNOME_PRINT_KEY_NONCOLLATED_COPIES_IN_HW "Settings.Output.Job.NonCollatedCopiesHW"
#define GNOME_PRINT_KEY_COLLATED_COPIES_IN_HW "Settings.Output.Job.CollatedCopiesHW"

#define GNOME_PRINT_KEY_COLLATE    "Settings.Output.Job.Collate"   /* Boolean (true|yes|1 false|no|0) */
#define GNOME_PRINT_KEY_DUPLEX    "Settings.Output.Job.Duplex"   /* Boolean (true|yes|1 false|no|0) */
#define GNOME_PRINT_KEY_TUMBLE    "Settings.Output.Job.Tumble"   /* Boolean (true|yes|1 false|no|0) */
#define GNOME_PRINT_KEY_HOLD    "Settings.Output.Job.Hold"   /* String value, like no-hold|indefinite|day-time|evening|night|weekend|second-shift|third-shift*/

/* These are ignored by libgnomeprint, but you may want to get/set/inspect these */
/* Libgnomeprintui uses these for displaying margin symbols */
#define GNOME_PRINT_KEY_PAGE_MARGIN_LEFT   "Settings.Document.Page.Margins.Left"   /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAGE_MARGIN_RIGHT  "Settings.Document.Page.Margins.Right"  /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAGE_MARGIN_TOP    "Settings.Document.Page.Margins.Top"    /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAGE_MARGIN_BOTTOM "Settings.Document.Page.Margins.Bottom" /* Length, i.e. use conversion */

/* These are ignored by libgnomeprint, and you most probably cannot change these too */
/* Also - these are relative to ACTUAL PAGE IN PRINTER - not physicalpage */
/* Libgnomeprintui uses these for displaying margin symbols */
#define GNOME_PRINT_KEY_PAPER_MARGIN_LEFT   "Settings.Output.Media.Margins.Left"   /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAPER_MARGIN_RIGHT  "Settings.Output.Media.Margins.Right"  /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAPER_MARGIN_TOP    "Settings.Output.Media.Margins.Top"    /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAPER_MARGIN_BOTTOM "Settings.Output.Media.Margins.Bottom" /* Length, i.e. use conversion */

/* More handy keys */
#define GNOME_PRINT_KEY_OUTPUT_FILENAME "Settings.Output.Job.FileName"          /* Filename used when printing to file. */
#define GNOME_PRINT_KEY_DOCUMENT_NAME   "Settings.Document.Name"                /* The name of the document 'Cash flow 2002', `Grandma cookie recipies' */
#define GNOME_PRINT_KEY_PREFERED_UNIT   "Settings.Document.PreferedUnit"        /* Abbreviation for the preferred unit cm, in,... */


G_END_DECLS

#endif /* __GNOME_PRINT_CONFIG_H__ */

