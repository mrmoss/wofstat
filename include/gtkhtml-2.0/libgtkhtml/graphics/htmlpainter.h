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

#ifndef __HTMLPAINTER_H__
#define __HTMLPAINTER_H__

typedef struct _HtmlPainter HtmlPainter;
typedef struct _HtmlPainterClass HtmlPainterClass;

#include <gtk/gtk.h>
#include <libgtkhtml/layout/htmlstyle.h>
#include <libgtkhtml/graphics/htmlfontspecification.h>
#include <libgtkhtml/graphics/htmlimagefactory.h>

G_BEGIN_DECLS

#define HTML_PAINTER_TYPE         (html_painter_get_type ())
#define HTML_PAINTER(obj)         (G_TYPE_CHECK_INSTANCE_CAST ((obj), HTML_PAINTER_TYPE, HtmlPainter))
#define HTML_IS_PAINTER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HTML_PAINTER_TYPE, HtmlPainter))
#define HTML_PAINTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_PAINTER_TYPE, HtmlPainterClass))
#define HTML_PAINTER_GET_CLASS(klass) (G_TYPE_INSTANCE_GET_CLASS ((klass), HTML_PAINTER_TYPE, HtmlPainterClass))

struct _HtmlPainter {
	GObject parent;
	
	/* FIXME: This should be removed when debugging is no longer needed /ac */
	gboolean debug;
	
	/* Images used */
	GdkPixbuf *loading_picture;
	GdkPixbuf *broken_picture;
};

struct _HtmlPainterClass {
	GObjectClass parent;
	
	void (* set_clip_rectangle) (HtmlPainter *painter, gint x, gint y, gint width, gint height);
	void (* set_foreground_color) (HtmlPainter *painter, HtmlColor *color);
	
	void (* draw_rectangle) (HtmlPainter *painter, GdkRectangle *area, gint x, gint y, gint width, gint height);
	void (* fill_rectangle) (HtmlPainter *painter, GdkRectangle *area, gint x, gint y, gint width, gint height);
	
	void (* draw_arc) (HtmlPainter *painter, GdkRectangle *area, gint x, gint y, gint width, gint height, gint angle1, gint angle2, gboolean fill);
	void (* draw_line) (HtmlPainter *painter, gint x1, gint y1, gint x2, gint y2);
	void (* draw_glyphs) (HtmlPainter *painter, gint x, gint y, PangoFont *font, PangoGlyphString *glyphs);
	void (* draw_layout) (HtmlPainter *painter, gint x, gint y, PangoLayout *layout);
	void (* draw_polygon) (HtmlPainter *painter, gboolean filled, GdkPoint *points, gint npoints);
	void (* draw_pixbuf) (HtmlPainter *painter, GdkRectangle *area, GdkPixbuf *pixbuf, gint src_x, gint src_y,
			      gint dest_x, gint dest_y, gint width, gint height);
};

GType html_painter_get_type (void);

void html_painter_set_clip_rectangle (HtmlPainter *painter, gint x, gint y, gint width, gint height);
void html_painter_set_foreground_color (HtmlPainter *painter, HtmlColor *color);

void html_painter_draw_arc (HtmlPainter *painter, GdkRectangle *area, gint x, gint y, gint width, gint height, gint angle1, gint angle2, gboolean fill);

void html_painter_draw_rectangle (HtmlPainter *painter, GdkRectangle *area, gint x, gint y, gint width, gint height);
void html_painter_fill_rectangle (HtmlPainter *painter, GdkRectangle *area, gint x, gint y, gint width, gint height);
void html_painter_draw_line (HtmlPainter *painter, gint x1, gint y1, gint x2, gint y2);
void html_painter_draw_glyphs (HtmlPainter *painter, gint x, gint y, PangoFont *font, PangoGlyphString *glyphs);
void html_painter_draw_layout (HtmlPainter *painter, gint x, gint y, PangoLayout *layout);
void html_painter_draw_polygon (HtmlPainter *painter, gboolean filled, GdkPoint *points, gint npoints);
void html_painter_draw_pixbuf (HtmlPainter *painter, GdkRectangle *area, GdkPixbuf *pixbuf, gint src_x, gint src_y,
			       gint dest_x, gint dest_y, gint width, gint height);
G_END_DECLS

#endif /* __HTMLPAINTER_H__ */
