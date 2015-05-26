/* 
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 * Copytight (C) 2000 Helix Code, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * Modified by the GTK+ Team and others 1997-1999.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/. 
 */
#ifndef __BONOBO_SOCKET_H__
#define __BONOBO_SOCKET_H__

#include <glib/gmacros.h>
#include <gtk/gtksocket.h>

typedef struct _BonoboSocket BonoboSocket;

#include <bonobo/bonobo-control-frame.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_SOCKET          (bonobo_socket_get_type ())
#define BONOBO_SOCKET(obj)          GTK_CHECK_CAST (obj, bonobo_socket_get_type (), BonoboSocket)
#define BONOBO_SOCKET_CLASS(klass)  GTK_CHECK_CLASS_CAST (klass, bonobo_socket_get_type (), BonoboSocketClass)
#define BONOBO_IS_SOCKET(obj)       GTK_CHECK_TYPE (obj, bonobo_socket_get_type ())

struct _BonoboSocket {
	GtkSocket           socket;

	BonoboControlFrame *frame;
	gpointer            priv;
};

typedef struct {
	GtkSocketClass parent_class;

	gpointer dummy[4];
} BonoboSocketClass;


GType               bonobo_socket_get_type          (void);
GtkWidget*          bonobo_socket_new               (void);

G_END_DECLS

#endif /* __BONOBO_SOCKET_H__ */
