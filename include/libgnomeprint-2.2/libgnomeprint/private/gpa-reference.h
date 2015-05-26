/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-reference.h:
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

#ifndef __GPA_REFERENCE_H__
#define __GPA_REFERENCE_H__

#include <glib.h>

G_BEGIN_DECLS

#define GPA_TYPE_REFERENCE         (gpa_reference_get_type ())
#define GPA_REFERENCE(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_REFERENCE, GPAReference))
#define GPA_IS_REFERENCE(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_REFERENCE))

#define GPA_REFERENCE_REFERENCE(r) ((r) ? GPA_REFERENCE (r)->ref : NULL)

typedef struct _GPAReference      GPAReference;
typedef struct _GPAReferenceClass GPAReferenceClass;

#include "gpa-node-private.h"

struct _GPAReference {
	GPANode node;
	GPANode *ref;
};

struct _GPAReferenceClass {
	GPANodeClass node_class;
};

GType     gpa_reference_get_type (void);

GPAReference * gpa_reference_new (GPANode *node, const guchar *id);
GPAReference * gpa_reference_new_emtpy (const guchar *id);
gboolean       gpa_reference_set_reference (GPAReference *reference, GPANode *node);

G_END_DECLS

#endif /* __GPA_REFERENCE_H__ */

