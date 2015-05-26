/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.

    Copyright 1999, 2000 Helix Code, Inc.
    
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef _GTKHTML_STREAM_H
#define _GTKHTML_STREAM_H

#include <sys/types.h>
#include "gtkhtml-types.h"

struct _GtkHTMLStream {
	GtkHTMLStreamWriteFunc write_func;
	GtkHTMLStreamCloseFunc close_func;
	GtkHTMLStreamTypesFunc types_func;
	gpointer user_data;
};


GtkHTMLStream *gtk_html_stream_new       (GtkHTML                *html,
					  GtkHTMLStreamTypesFunc  type_func,
					  GtkHTMLStreamWriteFunc  write_func,
					  GtkHTMLStreamCloseFunc  close_func,
					  gpointer                user_data);
void           gtk_html_stream_write     (GtkHTMLStream          *stream,
					  const gchar            *buffer,
					  size_t                  size);
void           gtk_html_stream_destroy   (GtkHTMLStream          *stream);
void           gtk_html_stream_close     (GtkHTMLStream          *stream,
					  GtkHTMLStreamStatus     status);
char **        gtk_html_stream_get_types (GtkHTMLStream *stream);

GtkHTMLStream *gtk_html_stream_log_new   (GtkHTML *html, GtkHTMLStream *stream);

int            gtk_html_stream_vprintf   (GtkHTMLStream *stream, 
					  const char *format, 
					  va_list ap);
int            gtk_html_stream_printf    (GtkHTMLStream *stream, 
					  const char *format, 
					  ...);

#endif /* _GTKHTML_STREAM_H */






