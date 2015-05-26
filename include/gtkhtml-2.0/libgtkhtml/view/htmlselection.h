/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2001 CodeFactory AB
   Copyright (C) 2001 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2001 Anders Carlsson <andersca@codefactory.se>
   
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

#ifndef __HTMLSELECTION_H__
#define __HTMLSELECTION_H__

#include <gtk/gtk.h>
#include <libgtkhtml/view/htmlview.h>

G_BEGIN_DECLS

void html_selection_start  (HtmlView *view, GdkEventButton *event);
void html_selection_end    (HtmlView *view, GdkEventButton *event);
void html_selection_update (HtmlView *view, GdkEventMotion *event);
void html_selection_clear  (HtmlView *view);
void html_selection_set    (HtmlView *view, DomNode *start, int offset, int len);
void html_selection_extend (HtmlView *view, HtmlBox *start, int start_offset, int len);
gchar *html_selection_get_text (HtmlView *view);

G_END_DECLS

#endif /* __HTMLSELECTION_H__ */
