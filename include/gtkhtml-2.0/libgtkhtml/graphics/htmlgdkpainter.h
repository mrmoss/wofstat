/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000 CodeFactory AB
   Copyright (C) 2000 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2000 Anders Carlsson <andersca@codefactory.se>
   
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

#ifndef __HTMLGDKPAINTER_H__
#define __HTMLGDKPAINTER_H__

#include <gtk/gtk.h>
#include <graphics/htmlpainter.h>
#include <view/htmlview.h>

#define HTML_GDK_PAINTER_TYPE         (html_gdk_painter_get_type ())
#define HTML_GDK_PAINTER(obj)         (G_TYPE_CHECK_INSTANCE_CAST ((obj), HTML_GDK_PAINTER_TYPE, HtmlGdkPainter))
#define HTML_IS_GDK_PAINTER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HTML_GDK_PAINTER_TYPE, HtmlGdkPainter))
#define HTML_GDK_PAINTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_GDK_PAINTER_TYPE, HtmlGdkPainterClass))
#define HTML_GDK_PAINTER_GET_CLASS(klass) (G_TYPE_INSTANCE_GET_CLASS ((klass), HTML_GDK_PAINTER_TYPE, HtmlGdkPainterClass))

typedef struct _HtmlGdkPainter HtmlGdkPainter;
typedef struct _HtmlGdkPainterClass HtmlGdkPainterClass;

struct _HtmlGdkPainter {
	HtmlPainter parent;

	/* Window to draw on */
	GdkWindow *window;

	/* The style used */
	GtkStyle *style;
	
	/* The current gc */
	GdkGC *gc;
};

struct _HtmlGdkPainterClass {
	HtmlPainterClass parent;
};

GType html_gdk_painter_get_type (void);
HtmlPainter *html_gdk_painter_new (void);

void html_gdk_painter_set_window (HtmlGdkPainter *painter, GdkWindow *window);
/*
  void html_painter_set_style (HtmlPainter *painter, GtkStyle *style);*/

#endif /* __HTMLGDKPAINTER_H__ */













