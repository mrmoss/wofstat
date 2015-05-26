/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-node.h:
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
 *    Lauris Kaplinski <lauris@ximian.com>
 *    Jose M. Celorio <chema@ximian.com>
 *
 *  Copyright (C) 2000-2003 Ximian, Inc.
 *
 */


#ifndef __GPA_NODE_PRIVATE_H__
#define __GPA_NODE_PRIVATE_H__

#include <glib.h>

G_BEGIN_DECLS

#include <glib-object.h>
#include "gpa-utils.h"

#define GPA_NODE_FLAGS(n)         (GPA_NODE(n)->flags)
#define GPA_NODE_SET_FLAGS(n,f)   (GPA_NODE(n)->flags |= f)
#define GPA_NODE_UNSET_FLAGS(n,f) (GPA_NODE(n)->flags &= (~f))

#define GPA_NODE_ID(n)           (n ? g_quark_to_string (GPA_NODE (n)->qid) : NULL)
#define GPA_NODE_ID_COMPARE(n,s) ((s) && (g_quark_try_string (s) == GPA_NODE (n)->qid))
#define GPA_NODE_PARENT(n)       (GPA_NODE (n)->parent)

typedef enum {
	NODE_FLAG_LOCKED = 1 << 4 /* Used for options when an option can't change from the default */
} GPANodeFlags;

struct _GPANode {
	GObject object;
	guint32 flags;  /* Future use */
	GQuark qid;     /* quark id of the node */

	/* Tree structure links*/
	GPANode *parent;
	GPANode *next;
	GPANode *children;
};

struct _GPANodeClass {
	GObjectClass object_class;

	guchar * (* get_value)  (GPANode *node);
	gboolean (* set_value)  (GPANode *node, const guchar *value);

	GPANode * (* duplicate) (GPANode *node);
	gboolean  (* verify)    (GPANode *node);
	
	/* Signal that the node value has changed */
	void     (* modified)   (GPANode *node, gint flags);
};

GType     gpa_node_get_type (void);
GPANode * gpa_node_new (GType type, const guchar *id);

gboolean  gpa_node_verify    (GPANode *node);
GPANode * gpa_node_duplicate (GPANode *node);
GPANode * gpa_node_lookup    (GPANode *node, const guchar *path);

void      gpa_node_emit_modified    (GPANode *node);

G_END_DECLS

#endif /* __GPA_NODE_PRIVATE_H__ */
