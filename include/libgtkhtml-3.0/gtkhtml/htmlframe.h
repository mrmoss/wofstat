/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library.
   
   Copyright (C) 2000 Helix Code, Inc.

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

#ifndef _HTMLFRAME_H_
#define _HTMLFRAME_H_

#include "htmlembedded.h"

#define HTML_FRAME(x) ((HTMLFrame *)(x))
#define HTML_FRAME_CLASS(x) ((HTMLFrameClass *)(x))
#define HTML_IS_FRAME(x) (HTML_CHECK_TYPE ((x), HTML_TYPE_FRAME))

struct _HTMLFrame {
	HTMLEmbedded embedded;
	
	char *url;
	GtkWidget *scroll;
	GtkWidget *html;
	HTMLPainter *gdk_painter;
	gint width;
	gint height;
	gboolean frameborder;
};

struct _HTMLFrameClass {
	HTMLEmbeddedClass embedded_class;
};

void           html_frame_type_init             (void);

void           html_frame_class_init            (HTMLFrameClass *klass,
						 HTMLType        type,
						 guint            object_size);

void           html_frame_set_size              (HTMLFrame *frame,
						 gint       width,
						 gint       heght);

void           html_frame_set_margin_width      (HTMLFrame *frame,
						 gint margin);
void           html_frame_set_margin_height     (HTMLFrame *frame,
						 gint margin);

void           html_frame_set_scrolling         (HTMLFrame *frame,
						 GtkPolicyType scroll);

void           html_frame_init                  (HTMLFrame        *frame,
						 HTMLFrameClass   *klass,
						 GtkWidget         *parent,
						 char              *url,
						 gint               width,
						 gint               height,
						 gboolean           border);

HTMLObject *   html_frame_new                   (GtkWidget *parent,
						 char *src,
						 gint width,
						 gint height,
						 gboolean border);

						  
						  
#endif


