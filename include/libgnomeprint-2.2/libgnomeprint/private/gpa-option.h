/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-option.h: 
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


#ifndef __GPA_OPTION_H__
#define __GPA_OPTION_H__

#include <glib.h>

G_BEGIN_DECLS

#include <libxml/tree.h>

#define GPA_TYPE_OPTION         (gpa_option_get_type ())
#define GPA_OPTION(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_OPTION, GPAOption))
#define GPA_IS_OPTION(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_OPTION))

#define GPA_OPTION_IS_NODE(o)   (GPA_OPTION (o)->type == GPA_OPTION_TYPE_NODE)
#define GPA_OPTION_IS_NONE(o)   (GPA_OPTION (o)->type == GPA_OPTION_TYPE_NONE)
#define GPA_OPTION_IS_LIST(o)   (GPA_OPTION (o)->type == GPA_OPTION_TYPE_LIST)
#define GPA_OPTION_IS_ITEM(o)   (GPA_OPTION (o)->type == GPA_OPTION_TYPE_ITEM)
#define GPA_OPTION_IS_KEY(o)    (GPA_OPTION (o)->type == GPA_OPTION_TYPE_KEY)
#define GPA_OPTION_IS_STRING(o) (GPA_OPTION (o)->type == GPA_OPTION_TYPE_STRING)

typedef struct _GPAOption      GPAOption;
typedef struct _GPAOptionClass GPAOptionClass;

typedef enum {
	GPA_OPTION_TYPE_NONE,
	GPA_OPTION_TYPE_NODE,
	GPA_OPTION_TYPE_KEY,
	GPA_OPTION_TYPE_LIST,
	GPA_OPTION_TYPE_ITEM,
	GPA_OPTION_TYPE_STRING,
	GPA_OPTION_TYPE_ROOT
} GPAOptionType;

struct _GPAOption {
	GPANode node;
	GPAOptionType type;
	guchar *value;
};

GType gpa_option_get_type (void);

GPANode * gpa_option_new_from_tree      (xmlNodePtr tree, GPANode *parent);
GPANode * gpa_option_node_new_from_tree (xmlNodePtr tree, GPANode *parent, const guchar *id);

GPANode *gpa_option_create_key (GPAOption *option, GPANode *parent);

GPANode *gpa_option_get_child_by_id (GPAOption *option, const guchar *id);

GPANode * gpa_option_node_new   (GPANode *parent, const guchar *id);
GPANode * gpa_option_list_new   (GPANode *parent, const guchar *id, const guchar *value);
GPANode * gpa_option_item_new   (GPANode *parent, const guchar *id, const guchar *value);
GPANode * gpa_option_key_new    (GPANode *parent, const guchar *id, const guchar *value);
GPANode * gpa_option_string_new (GPANode *parent, const guchar *id, const guchar *value);

gboolean  gpa_option_append_child (GPAOption *option, GPAOption *child);

gchar *   gpa_option_get_name (GPANode *node);

#define gpa_option_prepend_child(o,c)  gpa_node_attach(o,c)
#define gpa_option_reverse_children(o) gpa_node_reverse_children(o)

G_END_DECLS

#endif /* __GPA_OPTION_H__ */




