/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gpa-utils.h:
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

#ifndef __GPA_UTILS_H__
#define __GPA_UTILS_H__

#include <glib.h>

G_BEGIN_DECLS

#include <libxml/tree.h>
#include "gpa-node.h"

/* Lazy.. */
#define my_xmlFreeDoc(d) if(d) xmlFreeDoc(d)
#define my_xmlFree(x) if(x) xmlFree(x)
#define my_g_free(x)  if(x) g_free(x)
#define my_gpa_node_unref(n) if(n)gpa_node_unref (GPA_NODE (n))

xmlChar *   gpa_xml_node_get_name (xmlNodePtr node);
xmlNodePtr  gpa_xml_node_get_child (xmlNodePtr node, const guchar *name);

/* Dumps the node and all nodes below it to the console */
void gpa_utils_dump_tree (GPANode *node, gint follow_references);

#ifndef __GNUC__
#define __PRETTY_FUNCTION__ ""
#endif

#define gpa_return_false_if_fail(expr)	G_STMT_START{			\
     if (expr) { } else							\
       {								\
	 g_log (G_LOG_DOMAIN,						\
		G_LOG_LEVEL_CRITICAL,					\
		"file %s: line %d (%s): assertion `%s' failed",		\
		__FILE__,						\
		__LINE__,						\
		__PRETTY_FUNCTION__,					\
		#expr);							\
	 return (FALSE);						\
       };				}G_STMT_END

#endif /* __GPA_UTILS_H__ */
