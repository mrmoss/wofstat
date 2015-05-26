/*
 *  Copyright (C) 2000 Helix Code Inc.
 *
 *  Authors: Michael Zucchi <notzed@helixcode.com>
 *
 *  An embedded html widget.
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
 */

#ifndef _GTK_HTML_EMBEDDED_H
#define _GTK_HTML_EMBEDDED_H

#include <gtk/gtkbin.h>

#include "gtkhtml-types.h"

#define GTK_TYPE_HTML_EMBEDDED         (gtk_html_embedded_get_type ())
#define GTK_HTML_EMBEDDED(obj)         GTK_CHECK_CAST (obj, GTK_TYPE_HTML_EMBEDDED, GtkHTMLEmbedded)
#define GTK_HTML_EMBEDDED_CLASS(klass) GTK_CHECK_CLASS_CAST (klass, GTK_TYPE_HTML_EMBEDDED, GtkHTMLEmbeddedClass)
#define GTK_IS_HTML_EMBEDDED(obj)      GTK_CHECK_TYPE (obj, GTK_TYPE_HTML_EMBEDDED)

struct _GtkHTMLEmbedded {
	GtkBin bin;

	/* class id of this object */
	char *classid;
	char *name;
        char *type;
        char *data;

	/* parameters to class */
	int width, height;
	GHashTable *params;

	GtkHTMLEmbeddedPrivate *priv;

	int descent;
};

struct _GtkHTMLEmbeddedClass {
        GtkBinClass parent_class;

        void (*changed)(GtkHTMLEmbedded *);
        void (*draw_gdk)(GtkHTMLEmbedded *, GdkPixmap *, GdkGC *,
                         gint, gint);
        void (*draw_print)(GtkHTMLEmbedded *, GnomePrintContext *);
};

/* FIXME: There needs to be a way for embedded objects in forms to encode
   themselves for a form */

GType	 	 gtk_html_embedded_get_type	(void);
GtkWidget	*gtk_html_embedded_new (char *classid, char *name, char *type, char *data, int width, int height);

void gtk_html_embedded_set_parameter (GtkHTMLEmbedded *ge, char *param, char *value);
char *gtk_html_embedded_get_parameter (GtkHTMLEmbedded *ge, char *param);
void gtk_html_embedded_set_descent (GtkHTMLEmbedded *ge, int descent);

#endif /* ! _GTK_HTML_EMBEDDED_H */
