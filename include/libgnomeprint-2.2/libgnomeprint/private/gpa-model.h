/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-model.h: 
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

#ifndef __GPA_MODEL_H__
#define __GPA_MODEL_H__

#include <glib.h>

G_BEGIN_DECLS

#define GPA_TYPE_MODEL         (gpa_model_get_type ())
#define GPA_MODEL(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_MODEL, GPAModel))
#define GPA_IS_MODEL(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_MODEL))

typedef struct _GPAModel      GPAModel;
typedef struct _GPAModelClass GPAModelClass;

#include <libxml/tree.h>
#include "gpa-list.h"

struct _GPAModel {
	GPANode node;
	
	gchar *name;
	GPANode *options;
};

struct _GPAModelClass {
	GPANodeClass node_class;
};

GType     gpa_model_get_type (void);

GPANode * gpa_model_get_by_id (const guchar *id, gboolean quiet);
GPANode * gpa_model_new_from_tree (xmlNodePtr tree);

void      gpa_model_hash_insert (GPAModel *model);
GPANode * gpa_model_hash_lookup (const gchar *id);

G_END_DECLS

#endif /* __GPA_MODEL_H__ */
