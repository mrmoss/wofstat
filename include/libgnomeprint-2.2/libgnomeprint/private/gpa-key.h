/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-key.h: 
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

#ifndef __GPA_KEY_H__
#define __GPA_KEY_H__

#include <glib.h>
#include <libxml/tree.h>
#include "gpa-node.h"

G_BEGIN_DECLS

#define GPA_TYPE_KEY         (gpa_key_get_type ())
#define GPA_KEY(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_KEY, GPAKey))
#define GPA_IS_KEY(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_KEY))

#define GPA_KEY_ID(k)         (GPA_KEY (k)->id)
#define GPA_KEY_HAS_OPTION(k) ((k) && GPA_KEY (k)->option)
#define GPA_KEY_OPTION(k)     ((k) && GPA_KEY (k)->option ? GPA_OPTION (GPA_KEY (k)->option) : NULL)

typedef struct _GPAKey      GPAKey;
typedef struct _GPAKeyClass GPAKeyClass;

struct _GPAKey {
	GPANode node;

	GPANode *option;
	guchar *value;
};

struct _GPAKeyClass {
	GPANodeClass node_class;
};

GType gpa_key_get_type (void);

gboolean   gpa_key_merge_from_tree (GPANode *key, xmlNodePtr tree);
gboolean   gpa_key_merge_from_key  (GPAKey *dst, GPAKey *src);
xmlNodePtr gpa_key_to_tree (GPAKey *key);

gboolean   gpa_key_insert (GPANode *parent, const guchar *path, const guchar *value);

G_END_DECLS

#endif /* __GPA_KEY_H__ */
