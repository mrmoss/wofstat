/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library

   Copyright (C) 2000 Helix Code, Inc.
   Authors:           Radek Doulik (rodo@helixcode.com)

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHcANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef _GTK_HTML_PROPERTIES_H_
#define _GTK_HTML_PROPERTIES_H_

#define GTK_HTML_GCONF_DIR "/GNOME/Documents/HTML_Editor"
#define GTK_HTML_GNOME_CONFIG_PREFIX "/gtkhtml/Settings/"

#include <glib.h>
#include <gdk/gdktypes.h>

#include <gconf/gconf-client.h>

#include <gtk/gtkobject.h>
#include "gtkhtml-types.h"
#include "gtkhtml.h"

#define GTK_HTML_PROPERTY(w,p)         (GTK_HTML_CLASS (GTK_WIDGET_GET_CLASS (w))->properties-> p)

struct _GtkHTMLClassProperties {
	/* viewer */
	gchar    *font_var_print;
	guint     font_var_size_print;
	gboolean  font_var_print_points;
	gchar    *font_fix_print;
	guint     font_fix_size_print;
	gboolean  font_fix_print_points;

	/* editor */
	gchar    *language;
};

GtkHTMLClassProperties * gtk_html_class_properties_new       (GtkWidget *widget);
void                     gtk_html_class_properties_destroy   (GtkHTMLClassProperties *p);
void                     gtk_html_class_properties_copy      (GtkHTMLClassProperties *p1,
							      GtkHTMLClassProperties *p2);
void                     gtk_html_class_properties_load      (GtkHTMLClassProperties *p,
							      GConfClient *client);
void                     gtk_html_class_properties_update    (GtkHTMLClassProperties *p,
							      GConfClient *client,
							      GtkHTMLClassProperties *old);

/* enum types */

#define GTK_TYPE_HTML_CURSOR_SKIP     (gtk_html_cursor_skip_get_type ())
#define GTK_TYPE_HTML_COMMAND         (gtk_html_command_get_type ())

GtkType gtk_html_cursor_skip_get_type (void);
GtkType gtk_html_command_get_type     (void);

#endif
