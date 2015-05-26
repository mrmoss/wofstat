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

#ifndef _HTMLPLAINPAINTER_H
#define _HTMLPLAINPAINTER_H

#include "htmlpainter.h"
#include "htmlfontmanager.h"
#include "htmlgdkpainter.h"

typedef struct _HTMLPlainPainterClass HTMLPlainPainterClass;
typedef struct _HTMLPlainPainter HTMLPlainPainter;


#define HTML_TYPE_PLAIN_PAINTER                 (html_plain_painter_get_type ())
#define HTML_PLAIN_PAINTER(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), HTML_TYPE_PLAIN_PAINTER, HTMLPlainPainter))
#define HTML_PLAIN_PAINTER_CLASS(klass)         (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_PLAIN_PAINTER, HTMLPlainPainterClass))
#define HTML_IS_PLAIN_PAINTER(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HTML_TYPE_PLAIN_PAINTER))
#define HTML_IS_PLAIN_PAINTER_CLASS(klass)      (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_PLAIN_PAINTER))

struct _HTMLPlainPainter {
	HTMLGdkPainter base;
};

struct _HTMLPlainPainterClass {
	HTMLGdkPainterClass base;
};

GtkType      html_plain_painter_get_type (void);
HTMLPainter *html_plain_painter_new      (GtkWidget *widget, gboolean double_buffer);

#endif /* _HTMLPLAINPAINTER_H */
