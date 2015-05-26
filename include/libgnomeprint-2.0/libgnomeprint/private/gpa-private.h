/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

#ifndef __GPA_PRIVATE_H__
#define __GPA_PRIVATE_H__

/*
 * GPANode
 *
 * Opaque handle to gnome-print configuration tree
 *
 * Authors:
 *   Lauris Kaplinski <lauris@ximian.com>
 *
 * Copyright (C) 2001 Ximian, Inc.
 *
 * Licensed under GNU Lesser General Public License
 *
 */

#include <glib.h>

G_BEGIN_DECLS

/*
 * WARNING
 *
 * The API here can change at any moment without notice.
 *
 * It is not installed for user applications, but solely for libgnomeprintui
 *
 * WARNING
 *
 */
 
#ifndef WE_ARE_LIBGNOMEPRINT_UI
#error You should not be using this header, do so at your own risk.
#endif

#define GPA_TYPE_NODE (gpa_node_get_type ())
#define GPA_NODE(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GPA_TYPE_NODE, GPANode))
#define GPA_NODE_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GPA_TYPE_NODE, GPANodeClass))
#define GPA_IS_NODE(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GPA_TYPE_NODE))
#define GPA_IS_NODE_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GPA_TYPE_NODE))
#define GPA_NODE_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GPA_TYPE_NODE, GPANodeClass))

typedef struct _GPANode GPANode;
typedef struct _GPANodeClass GPANodeClass;

#include <glib-object.h>
#include "../gnome-print-config.h"

#define GNOME_PRINT_CONFIG_NODE(c) gnome_print_config_get_node (c)
GPANode *gnome_print_config_get_node (GnomePrintConfig *config);

/* Pure GPA stuff follows */

GType gpa_node_get_type (void);

GPANode *gpa_node_ref (GPANode *node);
GPANode *gpa_node_unref (GPANode *node);

guchar *gpa_node_id (GPANode *node);

/* These return referenced node or NULL */
GPANode *gpa_node_get_parent (GPANode *node);
GPANode *gpa_node_get_child (GPANode *node, GPANode *ref);
GPANode *gpa_node_get_path_node (GPANode *node, const guchar *path);

/* Basic value manipulation */
guchar *gpa_node_get_value (GPANode *node);
gboolean gpa_node_set_value (GPANode *node, const guchar *value);
guchar *gpa_node_get_path_value (GPANode *node, const guchar *path);
gboolean gpa_node_set_path_value (GPANode *node, const guchar *path, const guchar *value);

/* Convenience stuff */
gboolean gpa_node_get_bool_path_value (GPANode *node, const guchar *path, gint *value);
gboolean gpa_node_get_int_path_value (GPANode *node, const guchar *path, gint *value);
gboolean gpa_node_get_double_path_value (GPANode *node, const guchar *path, gdouble *value);
gboolean gpa_node_set_bool_path_value (GPANode *node, const guchar *path, gint value);
gboolean gpa_node_set_int_path_value (GPANode *node, const guchar *path, gint value);
gboolean gpa_node_set_double_path_value (GPANode *node, const guchar *path, gdouble value);
gboolean gpa_node_get_length_path_value (GPANode *node, const guchar *path, gdouble *value);

/* Gives you default Settings node */

GPANode *gpa_defaults (void);

#ifdef GNOME_PRINT_UNSTABLE_API
guchar *gpa_node_get_localized_name (guchar *name);
#endif

G_END_DECLS

#endif

