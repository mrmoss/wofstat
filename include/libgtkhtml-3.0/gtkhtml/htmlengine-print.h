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

#ifndef _HTMLENGINE_PRINT_H
#define _HTMLENGINE_PRINT_H

#include <libgnomeprint/gnome-print.h>
#include "htmlengine.h"

void  html_engine_print                     (HTMLEngine           *e,
					     GnomePrintContext    *print_context);
void  html_engine_print_with_header_footer  (HTMLEngine           *e,
					     GnomePrintContext    *print_context,
					     gdouble               header_height,
					     gdouble               footer_height,
					     GtkHTMLPrintCallback  header_print,
					     GtkHTMLPrintCallback  footer_print,
					     gpointer              user_data);
gint  html_engine_print_get_pages_num       (HTMLEngine           *e,
					     GnomePrintContext    *print_context,
					     gdouble               header_height,
					     gdouble               footer_height);
void  html_engine_print_set_min_split_index (HTMLEngine           *e,
					     gdouble               idx);
#endif
