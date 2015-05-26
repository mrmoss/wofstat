/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * gpa-node.h: This file is part of libgnomeprint
 *
 * Libgnomeprint is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * Libgnomeprint is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with the libgnomeprint; see the file COPYING.LIB.  If not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Authors :
 *   Lauris Kaplinski <lauris@ximian.com>
 *   Chema Celorio <chema@ximian.com>
 *
 * Copyright (C) 2001-2003 Ximian, Inc. and authors
 *
 */

#ifndef __GPA_NODE_H__
#define __GPA_NODE_H__

#include <glib.h>

G_BEGIN_DECLS
 
#ifndef WE_ARE_LIBGNOMEPRINT_INTERNALS
#error You should not be using this header, do so at your own risk.
#endif

#define GPA_TYPE_NODE         (gpa_node_get_type ())
#define GPA_NODE(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_NODE, GPANode))
#define GPA_NODE_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST ((k),    GPA_TYPE_NODE, GPANodeClass))
#define GPA_IS_NODE(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_NODE))
#define GPA_IS_NODE_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k),    GPA_TYPE_NODE))
#define GPA_NODE_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o),  GPA_TYPE_NODE, GPANodeClass))

typedef struct _GPANode      GPANode;
typedef struct _GPANodeClass GPANodeClass;

#include <glib-object.h>

GType gpa_node_get_type (void);

GPANode *gpa_node_ref   (GPANode *node);
GPANode *gpa_node_unref (GPANode *node);

const guchar *gpa_node_id (GPANode *node);

/* These return referenced node or NULL */
GPANode *gpa_node_get_parent (GPANode *node);
GPANode *gpa_node_get_child  (GPANode *node, GPANode *previous_child);
GPANode *gpa_node_get_child_from_path (GPANode *node, const guchar *path);

/* Basic value manipulation */
guchar * gpa_node_get_value (GPANode *node);
gboolean gpa_node_set_value (GPANode *node, const guchar *value);
guchar * gpa_node_get_path_value (GPANode *node, const guchar *path);
gboolean gpa_node_set_path_value (GPANode *node, const guchar *path, const guchar *value);

/* Attach and detach */
GPANode *gpa_node_attach (GPANode *parent, GPANode *child);
void     gpa_node_reverse_children (GPANode *node);

void     gpa_node_detach (GPANode *node);
GPANode *gpa_node_detach_unref (GPANode *child);
void     gpa_node_detach_unref_children (GPANode *node);

/* Convenience stuff */
gboolean gpa_node_get_int_path_value    (GPANode *node, const guchar *path, gint *value);
gboolean gpa_node_get_length_path_value (GPANode *node, const guchar *path, gdouble *value);

G_END_DECLS

#endif /* __GPA_NODE_H__ */
