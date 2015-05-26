/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library.

   Copyright (C) 2001 Helix Code, Inc.
   
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

#ifndef _HTMLFRAMESET_H_
#define _HTMLFRAMESET_H_

#include "htmlobject.h"
#define HTML_FRAMESET(x) ((HTMLFrameset *)(x))
#define HTML_FRAMESET_CLASS(x) ((HTMLFramesetClass *)(x))

struct _HTMLFrameset {
	HTMLObject object;
	
	GtkHTML *parent;

	GPtrArray *cols;
	GPtrArray *rows;
	GPtrArray *frames;
};

struct _HTMLFramesetClass {
	HTMLObjectClass object_class;
};



HTMLObject   *html_frameset_new        (GtkHTML *parent, char *rows, char *cols);
void          html_frameset_init       (HTMLFrameset *set, GtkHTML *parent, char *rows, char *cols);
void          html_frameset_class_init (HTMLFramesetClass *klass, HTMLType type, guint object_size);
gboolean      html_frameset_append     (HTMLFrameset *set, HTMLObject *o);
void          html_frameset_type_init  (void);
#endif /* _HTMLTABLE_H_ */






