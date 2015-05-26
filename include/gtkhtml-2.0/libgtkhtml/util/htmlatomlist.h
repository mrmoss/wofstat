/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000-2001 CodeFactory AB
   Copyright (C) 2000-2001 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2000-2001 Anders Carlsson <andersca@codefactory.se>
   
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

#ifndef __HTMLATOMLIST_H__
#define __HTMLATOMLIST_H__

#include <glib.h>

G_BEGIN_DECLS

typedef struct _HtmlAtomList HtmlAtomList;
typedef gint HtmlAtom;

extern HtmlAtomList *html_atom_list;

struct _HtmlAtomList {
	gchar **data;
	GHashTable *table;
	gint len;
};

HtmlAtomList *html_atom_list_new             (void);
gchar *       html_atom_list_get_string      (HtmlAtomList *al, gint atom);
HtmlAtom      html_atom_list_get_atom        (HtmlAtomList *al, const gchar *str);
HtmlAtom      html_atom_list_get_atom_length (HtmlAtomList *al, const gchar *str, gint len);

void html_atom_list_set_atom   (HtmlAtomList *al, gint atom, gchar *str);
void html_atom_list_dump       (HtmlAtomList *atomlist);
void html_atom_list_initialize (void);

G_END_DECLS

#endif /*__HTMLATOMLIST_H__ */
