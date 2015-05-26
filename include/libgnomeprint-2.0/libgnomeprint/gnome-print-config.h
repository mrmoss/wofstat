/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print-config.c: And frontend abstraction to whatever config system we eventually have
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
 *    Lauris Kaplinski <lauris@helixcode.com>
 *
 *  Copyright 2001 Ximian, Inc.
 *
 */

#ifndef __GNOME_PRINT_CONFIG_H__
#define __GNOME_PRINT_CONFIG_H__

/*
 * And frontend abstraction to whatever config system we eventually have
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Authors:
 *   Lauris Kaplinski <lauris@helixcode.com>
 *
 * Copyright 2001 Ximian, Inc.
 *
 */

#include <glib.h>

G_BEGIN_DECLS

/*
 * NOTES
 *
 * This is all-in-one printer configuration object
 *
 * It allows several fancy tricks, and more can be implemented in future
 *
 * Most basic usage is:
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
 * Paper size or PhysicaSize referes strictly to the
 * real-world paper size in printer, similarly PhysicalOrientation
 * marks, which paper side goes first into printer input tray.
 * Page size or LogicaSize refers to imaging area available to
 * application. This can conincide with physical paper size,
 * but does not have to. Take an example:
 *   Physical A4 has always size W 210mm and H 297mm
 *   It can be fed into printer 4 different ways (PhysicalOrientations)
 *   - whatever you choose, does not affect available page
 *     size. If paper is fed in rotated way, printing subsystem
 *     rotates printed page accordingly.
 *   Having Plain (1:1) layout and Landscape LOGICAL orientation
 *     changes available imaging area to W 297mm H 210mm.
 *     I.e. logical layout/orientation specifies, how your actual
 *     printed page is transferred to physical paper.
 *   Having multipage layouts make things even more complex,
 *     as your total page area may be different from paper size
 * How actual layout is calculated, is quite complex, and you
 * probably want to avoid doing that in application programs.
 * There are helper methods in GnomePrintMaster, that give you
 * the only real important values needed - available imaging
 * area width and height.
 * Also - only GnomePrintMaster parses layouts and rearranges
 * printout. Plain print contexts are one step lower-level, and
 * transfer printout directly to specified Physicalpage. You
 * are safe to use these, if you are 100% sure that you do not
 * want to allow multipage layouts and automatic feed orinetation
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
 * specified as fraction of target size in given dimension - i.e.
 * they can be either width or height, dpending on rotation used.
 *
 * 14/12/2001
 * Lauris Kaplinski
 */

typedef struct _GnomePrintConfig GnomePrintConfig;

#include <libgnomeprint/gnome-print-unit.h>

/*
 * Get default print config objects
 */

GnomePrintConfig *gnome_print_config_default (void);

GnomePrintConfig *gnome_print_config_ref (GnomePrintConfig *config);
GnomePrintConfig *gnome_print_config_unref (GnomePrintConfig *config);
GnomePrintConfig *gnome_print_config_dup (GnomePrintConfig *config);

/*
 * Get/Set key value pairs
 *
 * All methods except gnome_print_config_get return TRUE on sucess (given
 * key exists and/or its value can be changed to new value), FALSE otherwise.
 * gnome_print_config_get just returns NULL, if given key does not exist.
 *
 */

guchar  *gnome_print_config_get (GnomePrintConfig *config, const guchar *key);
gboolean gnome_print_config_set (GnomePrintConfig *config, const guchar *key, const guchar *value);

gboolean gnome_print_config_get_boolean (GnomePrintConfig *config, const guchar *key, gboolean *val);
gboolean gnome_print_config_get_int (GnomePrintConfig *config, const guchar *key, gint *val);
gboolean gnome_print_config_get_double (GnomePrintConfig *config, const guchar *key, gdouble *val);
gboolean gnome_print_config_get_length (GnomePrintConfig *config, const guchar *key, gdouble *val, const GnomePrintUnit **unit);

gboolean gnome_print_config_set_boolean (GnomePrintConfig *config, const guchar *key, gboolean val);
gboolean gnome_print_config_set_int (GnomePrintConfig *config, const guchar *key, gint val);
gboolean gnome_print_config_set_double (GnomePrintConfig *config, const guchar *key, gdouble val);
gboolean gnome_print_config_set_length (GnomePrintConfig *config, const guchar *key, gdouble val, const GnomePrintUnit *unit);

/*
 * Debugging
 */

void gnome_print_config_dump (GnomePrintConfig *gpc);

/*
 * Convenience keys
 */

/*
 * Paper size
 *
 * NB - this is NOT necessarily the actual page size you want to use in application
 * NB - If using multipage layouts, actual size is calculated from paper size,
 *      page orientation and layout.
 *
 */

#define GNOME_PRINT_KEY_PAPER_SIZE "Settings.Output.Media.PhysicalSize" /* Paper name, such as A4 or Letter */
#define GNOME_PRINT_KEY_PAPER_WIDTH "Settings.Output.Media.PhysicalSize.Width" /* Arbitrary units - use conversion */
#define GNOME_PRINT_KEY_PAPER_HEIGHT "Settings.Output.Media.PhysicalSize.Height" /* Arbitrary units - use conversion */
#define GNOME_PRINT_KEY_PAPER_HEIGHT "Settings.Output.Media.PhysicalSize.Height" /* Arbitrary units - use conversion */
#define GNOME_PRINT_KEY_PAPER_ORIENTATION "Settings.Output.Media.PhysicalOrientation" /* R0, R90, R180, R270 */
#define GNOME_PRINT_KEY_PAPER_ORIENTATION_MATRIX "Settings.Output.Media.PhysicalOrientation.Paper2PrinterTransform" /* 3x2 abstract matrix */

#define GNOME_PRINT_KEY_PAGE_ORIENTATION "Settings.Document.Page.LogicalOrientation" /* R0, R90, R180, R270 */
#define GNOME_PRINT_KEY_PAGE_ORIENTATION_MATRIX "Settings.Document.Page.LogicalOrientation.Page2LayoutTransform" /* 3x2 abstract matrix */

/* Just a reminder - application is only interested in logical orientation */
#define GNOME_PRINT_KEY_ORIENTATION GNOME_PRINT_KEY_PAGE_ORIENTATION

#define GNOME_PRINT_KEY_LAYOUT "Settings.Document.Page.Layout" /* Id of layout ('Plain' is always no-special-layout) */
#define GNOME_PRINT_KEY_LAYOUT_WIDTH "Settings.Document.Page.Layout.Width" /* Double value */
#define GNOME_PRINT_KEY_LAYOUT_HEIGHT "Settings.Document.Page.Layout.Height" /* Double value */

/* Master resolution, i.e. ink dots for color printer RGB resolution is usually smaller */
#define GNOME_PRINT_KEY_RESOLUTION "Settings.Output.Resolution" /* String value, like 300x300 or 300dpi */
#define GNOME_PRINT_KEY_RESOLUTION_DPI "Settings.Output.Resolution.DPI" /* Numeric value, like 300, if meaningful */
#define GNOME_PRINT_KEY_RESOLUTION_DPI_X "Settings.Output.Resolution.DPI.X" /* Numeric value */
#define GNOME_PRINT_KEY_RESOLUTION_DPI_Y "Settings.Output.Resolution.DPI.Y" /* Numeric value */

/* These belong to 'Output' because PGL may implement multiple copies itself */
#define GNOME_PRINT_KEY_NUM_COPIES "Settings.Output.Job.NumCopies" /* Number of copies */
#define GNOME_PRINT_KEY_COLLATE "Settings.Output.Job.Collate" /* Boolean (true|yes|1 false|no|0) */

/* These are ignored by libgnomeprint, but you may want to get/set/inspect these */
/* Libgnomeprintui uses these for displaying margin symbols */
#define GNOME_PRINT_KEY_PAGE_MARGIN_LEFT "Settings.Document.Page.Margins.Left" /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAGE_MARGIN_RIGHT "Settings.Document.Page.Margins.Right" /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAGE_MARGIN_TOP "Settings.Document.Page.Margins.Top" /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAGE_MARGIN_BOTTOM "Settings.Document.Page.Margins.Bottom" /* Length, i.e. use conversion */

/* These are ignored by libgnomeprint, and you most probably cannot change these too */
/* Also - these are relative to ACTUAL PAGE IN PRINTER - not physicalpage */
/* Libgnomeprintui uses these for displaying margin symbols */
#define GNOME_PRINT_KEY_PAPER_MARGIN_LEFT "Settings.Output.Media.Margins.Left" /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAPER_MARGIN_RIGHT "Settings.Output.Media.Margins.Right" /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAPER_MARGIN_TOP "Settings.Output.Media.Margins.Top" /* Length, i.e. use conversion */
#define GNOME_PRINT_KEY_PAPER_MARGIN_BOTTOM "Settings.Output.Media.Margins.Bottom" /* Length, i.e. use conversion */

/* More handy keys */
#define GNOME_PRINT_KEY_OUTPUT_FILENAME "Settings.Transport.Backend.FileName" /* Filename used when printing to file. Don't assume that if
																 it isn't NULL printing to file is disabled it can contain
																 a filename and not print to file	
															    */
#define GNOME_PRINT_KEY_DOCUMENT_NAME  "Settings.Document.Name" /* The name of the document 'Cash flow 2002', `Grandma cockie recipies',
													* 'Untitled 1', etc.
													*/
#define GNOME_PRINT_KEY_PREFERED_UNIT "Settings.Document.PreferedUnit" /* Abbreviation for the preferred unit cm, in,... */

G_END_DECLS

#endif






