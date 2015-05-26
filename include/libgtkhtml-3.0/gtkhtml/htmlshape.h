/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library.
    
   Copyright (C) 2001, Ximian, Inc.

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

#ifndef HTML_SHAPE_H_
#define HTML_SHAPE_H_

typedef enum {
	HTML_SHAPE_DEFAULT,
	HTML_SHAPE_RECT,
	HTML_SHAPE_CIRCLE,
	HTML_SHAPE_POLY
} HTMLShapeType;

typedef enum {
	HTML_LENGTH_TYPE_PERCENT,
	HTML_LENGTH_TYPE_PIXELS,
	HTML_LENGTH_TYPE_FRACTION
} HTMLLengthType;

typedef struct _HTMLLength HTMLLength;
struct _HTMLLength {
	gint           val;
	HTMLLengthType type;
};

typedef struct _HTMLShape HTMLShape;

void         html_length_array_parse   (GPtrArray *array, char *str);
void         html_length_array_destroy (GPtrArray *array);

HTMLShape *  html_shape_new      (char *type, char *coords, char *href, char *target);
gboolean     html_shape_point    (HTMLShape *shape, gint x, gint y);
char *       html_shape_get_url  (HTMLShape *shape);
void         html_shape_destroy  (HTMLShape *shape);

#endif /* HTML_SHAPE_H_ */

