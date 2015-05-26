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

#ifndef _HTMLIFRAME_H_
#define _HTMLIFRAME_H_

#include "htmlembedded.h"

#define HTML_IFRAME(x) ((HTMLIFrame *)(x))
#define HTML_IFRAME_CLASS(x) ((HTMLIFrameClass *)(x))
#define HTML_IS_IFRAME(x) (HTML_CHECK_TYPE ((x), HTML_TYPE_IFRAME))

struct _HTMLIFrame {
	HTMLEmbedded embedded;
	
	char *url;
	GtkWidget *scroll;
	GtkWidget *html;
	HTMLPainter *gdk_painter;
	gint width;
	gint height;
	gboolean frameborder;
};

struct _HTMLIFrameClass {
	HTMLEmbeddedClass embedded_class;
};

void           html_iframe_type_init             (void);

void           html_iframe_class_init            (HTMLIFrameClass *klass,
						  HTMLType           type,
						  guint              object_size);

void           html_iframe_init                  (HTMLIFrame        *iframe,
						  HTMLIFrameClass   *klass,
						  GtkWidget         *parent,
						  char              *url,
						  gint               width,
						  gint               height,
						  gboolean           border);

HTMLObject *   html_iframe_new                   (GtkWidget *parent,
						  char *src,
						  gint width,
						  gint height,
						  gboolean border);

void           html_iframe_set_scrolling         (HTMLIFrame *iframe, GtkPolicyType scroll);

void           html_iframe_set_margin_width      (HTMLIFrame *iframe,
						 gint margin);
void           html_iframe_set_margin_height     (HTMLIFrame *iframe,
						 gint margin);
						  
#endif


