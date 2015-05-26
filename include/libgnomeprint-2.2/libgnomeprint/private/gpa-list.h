/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-list.h: 
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
 *    Chema Celorio <chema@ximian.com>
 *    Lauris Kaplinski <lauris@ximian.com>
 *
 *  Copyright (C) 2000-2003 Ximian, Inc.
 *
 */

#ifndef __GPA_LIST_H__
#define __GPA_LIST_H__

#include <glib.h>

G_BEGIN_DECLS

#define GPA_TYPE_LIST         (gpa_list_get_type ())
#define GPA_LIST(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_LIST, GPAList))
#define GPA_IS_LIST(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_LIST))

#include "gpa-node-private.h"
#include "gpa-reference.h"

#define gpa_list_ref(l)       ((GPAList *)gpa_node_ref   (GPA_NODE (l)))
#define gpa_list_unref(l)     ((GPAList *)gpa_node_unref (GPA_NODE (l)))
#define gpa_list_prepend(l,c) ((GPAList *) gpa_node_attach (GPA_NODE (l), GPA_NODE (c)))
#define gpa_list_reverse(l)   (gpa_node_reverse_children (GPA_NODE (l)))

typedef struct _GPAList      GPAList;

struct _GPAList {
	GPANode node;
	GType childtype;              /* The node type of the list children */
	guint can_have_default : 1;   /* TRUE if this list can have a deafult child */
	GPAReference *def;            /* A GPAReference to the default value */
};

GType     gpa_list_get_type (void);

GPAList * gpa_list_new (GType childtype, const gchar *list_name, gboolean can_have_default);

gboolean  gpa_list_set_default (GPAList *list, GPANode *def);
GPANode * gpa_list_get_default (GPAList *list);

G_END_DECLS

#endif /* __GPA_LIST_H__ */
