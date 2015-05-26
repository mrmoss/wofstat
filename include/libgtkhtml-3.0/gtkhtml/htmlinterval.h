/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library

   Copyright (C) 2000 Helix Code, Inc.
   Authors:           Radek Doulik (rodo@helixcode.com)

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

#ifndef _HTML_INTERVAL_H_
#define _HTML_INTERVAL_H_

#include "htmltypes.h"

struct _HTMLPoint {
	HTMLObject *object;
	guint       offset;
};

HTMLPoint  *html_point_new               (HTMLObject      *o,
					  guint            off);
void        html_point_construct         (HTMLPoint       *p,
					  HTMLObject      *o,
					  guint            off);
void        html_point_destroy           (HTMLPoint       *p);
HTMLPoint  *html_point_max               (HTMLPoint       *a,
					  HTMLPoint       *b);
HTMLPoint  *html_point_min               (HTMLPoint       *a,
					  HTMLPoint       *b);
gboolean    html_point_eq                (const HTMLPoint *a,
					  const HTMLPoint *b);
gboolean    html_point_cursor_object_eq  (HTMLPoint       *p,
					  HTMLPoint       *c);
void        html_point_next_cursor       (HTMLPoint       *p);

struct _HTMLInterval {
	HTMLPoint from;
	HTMLPoint to;
};

HTMLInterval *html_interval_new              (HTMLObject            *from,
					      HTMLObject            *to,
					      guint                  from_offset,
					      guint                  to_offset);
HTMLInterval *html_interval_new_from_cursor  (HTMLCursor            *a,
					      HTMLCursor            *b);
HTMLInterval *html_interval_new_from_points  (HTMLPoint             *from,
					      HTMLPoint             *to);
void          html_interval_validate         (HTMLInterval          *i);
HTMLInterval *html_interval_flat             (HTMLInterval          *i);
void          html_interval_destroy          (HTMLInterval          *i);
guint         html_interval_get_length       (HTMLInterval          *i,
					      HTMLObject            *obj);
guint         html_interval_get_bytes        (HTMLInterval          *i,
					      HTMLObject            *obj);
guint         html_interval_get_start        (HTMLInterval          *i,
					      HTMLObject            *obj);
guint         html_interval_get_start_index  (HTMLInterval          *i,
					      HTMLObject            *obj);
HTMLObject   *html_interval_get_head         (HTMLInterval          *i,
					      HTMLObject            *o);
void          html_interval_select           (HTMLInterval          *i,
					      HTMLEngine            *e);
void          html_interval_unselect         (HTMLInterval          *i,
					      HTMLEngine            *e);
gint          html_interval_get_from_index   (HTMLInterval          *i);
gint          html_interval_get_to_index     (HTMLInterval          *i);
void          html_interval_forall           (HTMLInterval          *i,
					      HTMLEngine            *e,
					      HTMLObjectForallFunc   f,
					      gpointer               data);
gboolean      html_interval_eq               (const HTMLInterval    *a,
					      const HTMLInterval    *b);
HTMLInterval *html_interval_intersection     (HTMLInterval          *a,
					      HTMLInterval          *b);
void         *html_interval_substract        (HTMLInterval          *a,
					      HTMLInterval          *b,
					      HTMLInterval         **s1,
					      HTMLInterval         **s2);
#endif
