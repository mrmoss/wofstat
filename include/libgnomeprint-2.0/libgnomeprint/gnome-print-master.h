/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print-master.c: A system print interface.
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
 *    Michael Zucchi <notzed@ximian.com>
 *    Lauris Kaplinski <lauris@ximian.com>
 *
 *  Copyright (C) 2000-2001 Ximian Inc.
 */

#ifndef __GNOME_PRINT_MASTER_H__
#define __GNOME_PRINT_MASTER_H__

#include <glib.h>

G_BEGIN_DECLS

/*
 * GnomePrintMaster is frontend to GnomePrintContext creation and
 * printing. Unlike contexts themselves, master cares about layout,
 * number of copies and collate values. So it is usually safe bet to
 * use it always.
 *
 * Notice, that page number(s) used by master are already adjusted
 * to layout. I.e. if you print 2 pages per sheet, and invoke
 * beginpage/showpage 4 times, gnome_print_master_get_pages gives
 * you value 2.
 *
 * Also, if you wonder, what page dimensions you should be using in
 * your application, use gnome_print_master_get_page_size_from_config.
 *
 */

#define GNOME_TYPE_PRINT_MASTER (gnome_print_master_get_type ())
#define GNOME_PRINT_MASTER(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_MASTER, GnomePrintMaster))
#define GNOME_PRINT_MASTER_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_PRINT_MASTER, GnomePrintMasterClass))
#define GNOME_IS_PRINT_MASTER(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_MASTER))
#define GNOME_IS_PRINT_MASTER_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_PRINT_MASTER))
#define GNOME_PRINT_MASTER_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PRINT_MASTER, GnomePrintMasterClass))

typedef struct _GnomePrintMaster      GnomePrintMaster;
typedef struct _GnomePrintMasterClass GnomePrintMasterClass;

#include <libgnomeprint/gnome-print.h>

GType gnome_print_master_get_type (void);

/* Creates new GnomePrintMaster */

GnomePrintMaster *gnome_print_master_new (void);
GnomePrintMaster *gnome_print_master_new_from_config (GnomePrintConfig *config);

/* Get REFERENCED configuration */
GnomePrintConfig *gnome_print_master_get_config (GnomePrintMaster *gpm);

/* Get REFERNCED context for actual printing */
GnomePrintContext *gnome_print_master_get_context (GnomePrintMaster *gpm);

/* Signal GnomePrintMaster, that application has finished job */
/* You should not close context given you by master, but use this instead */
gint gnome_print_master_close (GnomePrintMaster *gpm);

/* Send printout to printer, as defined by config */
gint gnome_print_master_print (GnomePrintMaster *gpm);
/* Renders printout to specified context (with layout, ignoring copies) */
gint gnome_print_master_render (GnomePrintMaster *gpm, GnomePrintContext *ctx);
/* Renders specified page (with layout) */
gint gnome_print_master_render_page (GnomePrintMaster *gpm, GnomePrintContext *ctx, gint page, gboolean pageops);

/* Get number of real output pages (0 if master is not closed) */
gint gnome_print_master_get_pages (GnomePrintMaster *gpm);

/* Get imaging area size available to application (TRUE sucess, FALSE error) */
/* This takes config for argument, as you may not want to create master yet */
/* Sizes are given in PS points (GNOME_PRINT_PS_UNIT) */
gboolean gnome_print_master_get_page_size_from_config (GnomePrintConfig *config, gdouble *width, gdouble *height);


/* This are convenience functions for common stuff that could be accomplished with gnome_print_config
 * calls but will require deeper knowledge when GnomePrintConfig trees get complex */
gint gnome_print_master_print_to_file (GnomePrintMaster *gpm, gchar *output);
 
G_END_DECLS

#endif /* GNOME_PRINT_MASTER_H */
