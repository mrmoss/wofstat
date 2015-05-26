/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print-job.h: A print job interface
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

#ifndef __GNOME_PRINT_JOB_H__
#define __GNOME_PRINT_JOB_H__

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_PRINT_JOB (gnome_print_job_get_type ())
#define GNOME_PRINT_JOB(o)    (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_JOB, GnomePrintJob))
#define GNOME_IS_PRINT_JOB(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_JOB))

typedef struct _GnomePrintJob      GnomePrintJob;

#include <libgnomeprint/gnome-print.h>

GType gnome_print_job_get_type (void);

GnomePrintJob *      gnome_print_job_new (GnomePrintConfig *config);

/* Note: Remember to unref the GnomePrintConfig returned by: */
GnomePrintConfig *   gnome_print_job_get_config  (GnomePrintJob *job);

/* Note: Remember to unref the GnomePrintContext returned by: */
GnomePrintContext *  gnome_print_job_get_context (GnomePrintJob *job);

gint     gnome_print_job_close (GnomePrintJob *job);
gint     gnome_print_job_print (GnomePrintJob *job);

#ifdef GNOME_PRINT_UNSTABLE_API
void     gnome_print_job_set_file (GnomePrintJob *job, gchar *input);
#endif

gint     gnome_print_job_render      (GnomePrintJob *job, GnomePrintContext *ctx);
gint     gnome_print_job_render_page (GnomePrintJob *job, GnomePrintContext *ctx, gint page, gboolean pageops);
gint     gnome_print_job_get_pages   (GnomePrintJob *job);

gint     gnome_print_job_print_to_file (GnomePrintJob *job, gchar *output);
gboolean gnome_print_job_get_page_size (GnomePrintJob *job, gdouble *width, gdouble *height);

/* Deprecated, use gnome_print_config_get_page_size */
gboolean gnome_print_job_get_page_size_from_config (GnomePrintConfig *config, gdouble *width, gdouble *height);

G_END_DECLS

#endif /* __GNOME_PRINT_JOB_H__ */
