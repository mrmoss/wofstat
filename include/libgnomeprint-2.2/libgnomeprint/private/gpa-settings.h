/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-settings.h: 
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
 *  Authors :
 *    Jose M. Celorio <chema@ximian.com>
 *    Lauris Kaplinski <lauris@ximian.com>
 *
 *  Copyright (C) 2000-2003 Ximian, Inc.
 *
 */

#ifndef __GPA_SETTINGS_H__
#define __GPA_SETTINGS_H__

#include <glib.h>

G_BEGIN_DECLS

#define GPA_TYPE_SETTINGS         (gpa_settings_get_type ())
#define GPA_SETTINGS(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_SETTINGS, GPASettings))
#define GPA_IS_SETTINGS(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_SETTINGS))

typedef struct _GPASettings GPASettings;

#include <libxml/tree.h>
#include "gpa-model.h"

struct _GPASettings {
	GPANode node;

	gchar *name;      /* User visible name, "Default", "Photographs", "Drafts", etc */

	GPAReference *model;   /* A GPAReference to the model of the printer (eqv to printer->settings) */
	GPAReference *printer; /* A GPAReference to the printer */
};


GType gpa_settings_get_type (void);

GPANode *  gpa_settings_new                     (GPAModel *model, const guchar *name, const guchar *id);
GPANode *  gpa_settings_new_empty               (const guchar *name, const guchar *id);
GPANode *  gpa_settings_new_from_model_and_tree (GPANode *model, xmlNodePtr tree);

gboolean   gpa_settings_copy  (GPASettings *dst, GPASettings *src);
xmlNodePtr gpa_settings_to_tree (GPASettings *settings);

G_END_DECLS

#endif /* __GPA_SETTINGS_H__ */
