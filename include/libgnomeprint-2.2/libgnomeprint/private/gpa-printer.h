/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-printer.h:
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
 *    Jose M. Celorio <chema@ximian.com>
 *    Lauris Kaplinski <lauris@ximian.com>
 *
 *  Copyright 2001-2003 Ximian, Inc.
 *
 */

#ifndef __GPA_PRINTER_H__
#define __GPA_PRINTER_H__

#include <glib.h>

G_BEGIN_DECLS

#include "gpa-model.h"
#include "gpa-settings.h"

#define GPA_TYPE_PRINTER         (gpa_printer_get_type ())
#define GPA_PRINTER(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_PRINTER, GPAPrinter))
#define GPA_IS_PRINTER(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_PRINTER))

typedef struct _GPAPrinter      GPAPrinter;
struct _GPAPrinter {
	GPANode node;

	gchar *name;

	/* is_complete indicates whether the model and settings are set.   */
	gboolean is_complete;
	gchar *module_path;

	GPANode *model;    /* of type GPAReference which points to a GPAModel */
	GPANode *settings; /* of type GPAList, with childs of type GPASettings */
};


GType     gpa_printer_get_type (void);

GPANode * gpa_printer_new (const gchar *id, const gchar *name,
			   GPAModel *model, GPASettings *settings);
GPANode * gpa_printer_new_stub (const gchar *id, const gchar *name,
				const gchar *);
gboolean  gpa_printer_complete_stub (GPAPrinter *printer, 
				     GPAModel *model, GPASettings *settings);

GPAList * gpa_printer_list_load (void);

GPANode * gpa_printer_get_default (void);
GPANode * gpa_printer_get_by_id (const guchar *id);

GPANode * gpa_printer_get_default_settings (GPAPrinter *printer);
GPANode * gpa_printer_get_settings_by_id (GPAPrinter *printer, const guchar *id);

G_END_DECLS

#endif /* __GPA_PRINTER_H__ */
