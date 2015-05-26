/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000-2001 CodeFactory AB
   Copyright (C) 2000-2001 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2000-2001 Anders Carlsson <andersca@codefactory.se>
   
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

#ifndef __HTMLSTREAM_H__
#define __HTMLSTREAM_H__

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

typedef struct _HtmlStream HtmlStream;
typedef struct _HtmlStreamClass HtmlStreamClass;
typedef void (* HtmlStreamCloseFunc) (HtmlStream *stream,
				      gpointer user_data);

typedef void (* HtmlStreamWriteFunc) (HtmlStream *stream,
				      const gchar *buffer,
				      guint size,
				      gpointer user_data);

typedef void (* HtmlStreamCancelFunc) (HtmlStream *stream,
				      gpointer user_data,
				      gpointer cancel_data);


#define HTML_TYPE_STREAM (html_stream_get_type ())
#define HTML_STREAM(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_STREAM, HtmlStream))
#define HTML_STREAM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_STREAM, HtmlStreamClass))
#define HTML_IS_STREAM(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_STREAM))
#define HTML_IS_STREAM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_STREAM))
#define HTML_STREAM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), HTML_TYPE_STREAM, HtmlStreamClass))

struct _HtmlStream {
	GObject parent_object;
	HtmlStreamWriteFunc write_func;
	HtmlStreamCloseFunc close_func;
	HtmlStreamCancelFunc cancel_func;
	gpointer user_data, cancel_data;
	gint written;
	char *mime_type;
};

struct _HtmlStreamClass {
	GObjectClass parent_class;
};

GType html_stream_get_type (void);

HtmlStream *html_stream_new (HtmlStreamWriteFunc write_func,
			     HtmlStreamCloseFunc close_func,
			     gpointer user_data);

void html_stream_write (HtmlStream *stream,
			const gchar *buffer,
			guint size);

void html_stream_close       (HtmlStream *stream);
void html_stream_destroy     (HtmlStream *stream);
gint html_stream_get_written (HtmlStream *stream);

void html_stream_cancel          (HtmlStream *stream);
void html_stream_set_cancel_func (HtmlStream *stream,
				 HtmlStreamCancelFunc abort_func,
				 gpointer cancel_data);

const char *html_stream_get_mime_type (HtmlStream *stream);
void        html_stream_set_mime_type (HtmlStream *stream, const char *mime_type);


G_END_DECLS

#endif /* __HTMLSTREAM_H__ */
