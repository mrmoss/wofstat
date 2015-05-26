/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.

    Copyright (C) 2000, 2001 Helix Code, Inc.
    Authors:                 Radek Doulik (rodo@helixcode.com)

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

#ifndef HTML_ENGINE_EDIT_CUT_AND_PASTE
#define HTML_ENGINE_EDIT_CUT_AND_PASTE

#include "htmltypes.h"

void  html_engine_copy                    (HTMLEngine  *e);
void  html_engine_copy_object             (HTMLEngine  *e,
					   HTMLObject **o,
					   guint       *len);
gint  html_engine_cut                     (HTMLEngine  *e);
void  html_engine_cut_line                (HTMLEngine  *e);
void  html_engine_delete                  (HTMLEngine  *e);
void  html_engine_paste                   (HTMLEngine  *e);
void  html_engine_paste_object            (HTMLEngine  *e,
					   HTMLObject  *o,
					   guint        len);
void  html_engine_paste_text              (HTMLEngine  *e,
					   const gchar *text,
					   guint        len);
void  html_engine_paste_text_with_extra_attributes   (HTMLEngine     *e,
						      const gchar    *text,
						      guint           len,
						      PangoAttrList  *attrs);
void  html_engine_insert_text             (HTMLEngine  *e,
					   const gchar *text,
					   guint        len);
void  html_engine_insert_text_with_extra_attributes  (HTMLEngine     *e,
						      const gchar    *text,
						      guint           len,
						      PangoAttrList  *attrs);
void  html_engine_insert_object           (HTMLEngine  *e,
					   HTMLObject  *o,
					   guint        len,
					   gint         level);
void  html_engine_append_object           (HTMLEngine  *e,
					   HTMLObject  *o,
					   guint        len);
void  html_engine_append_flow             (HTMLEngine  *e,
					   HTMLObject  *o,
					   guint        len);
void  html_engine_edit_set_link           (HTMLEngine  *e,
					   const gchar *url,
					   const gchar *target);
void  html_engine_insert_empty_paragraph  (HTMLEngine  *e);
void  html_engine_delete_n                (HTMLEngine  *e,
					   guint        len,
					   gboolean     forward);
void  html_engine_delete_container        (HTMLEngine  *e);
void  html_engine_set_insertion_link      (HTMLEngine  *e,
					   const gchar *url,
					   const gchar *target);
#endif
