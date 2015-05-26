/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-root.h:
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

#ifndef __GPA_ROOT_H__
#define __GPA_ROOT_H__

#include <glib.h>

G_BEGIN_DECLS

#include "gpa-list.h"

#define GPA_TYPE_ROOT         (gpa_root_get_type ())
#define GPA_ROOT(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_ROOT, GPARoot))
#define GPA_IS_ROOT(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_ROOT))

typedef struct _GPARoot      GPARoot;
struct _GPARoot {
	GPANode node;
	GPANode *globals;
	GPANode *printers;
};

GType     gpa_root_get_type (void);

extern GPARoot *gpa_root;

GPAList * gpa_get_printers (void);
gboolean  gpa_init (void);
gboolean  gpa_initialized (void);
void      gpa_shutdown (void);

G_END_DECLS

#endif /* __GPA_ROOT_H__ */
