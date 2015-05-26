/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-config.h:
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
 *  Copyright (C) 2000-2003 Ximian, Inc.
 *
 */

#ifndef __GPA_CONFIG_H__
#define __GPA_CONFIG_H__

#include <glib.h>

G_BEGIN_DECLS

#include "gpa-node-private.h"
#include "gpa-printer.h"
#include "gpa-settings.h"

#define GPA_TYPE_CONFIG         (gpa_config_get_type ())
#define GPA_CONFIG(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_CONFIG, GPAConfig))
#define GPA_IS_CONFIG(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_CONFIG))

typedef struct _GPAConfig      GPAConfig;
struct _GPAConfig {
	GPANode node;
	GPANode *printer;
	GPANode *settings;
};

GType     gpa_config_get_type (void);

GPAConfig * gpa_config_new (void);
GPAConfig * gpa_config_new_full (GPAPrinter *printer, GPASettings * settings);

gchar *    gpa_config_to_string (GPAConfig *config, guint flags);
GPAConfig* gpa_config_from_string (const gchar *string, guint flags);

G_END_DECLS

#endif /* __GPA_CONFIG_H__ */
