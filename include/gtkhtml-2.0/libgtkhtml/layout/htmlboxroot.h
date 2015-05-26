/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000 CodeFactory AB
   Copyright (C) 2000 Jonas Borgstr\366m <jonas@codefactory.se>
   Copyright (C) 2000 Anders Carlsson <andersca@codefactory.se>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef __HTMLBOXROOT_H__
#define __HTMLBOXROOT_H__

#include "htmlboxblock.h"

G_BEGIN_DECLS

#define HTML_TYPE_BOX_ROOT (html_box_root_get_type ())
#define HTML_BOX_ROOT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_ROOT, HtmlBoxRoot))
#define HTML_BOX_ROOT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_ROOT, HtmlBoxRootClass))
#define HTML_IS_BOX_ROOT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_ROOT))
#define HTML_IS_BOX_ROOT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_ROOT))

typedef struct _HtmlBoxRoot HtmlBoxRoot;
typedef struct _HtmlBoxRootClass HtmlBoxRootClass;

struct _HtmlBoxRoot {
	HtmlBoxBlock parent_object;

	GSList *float_left_list;
	GSList *float_right_list;
	GSList *positioned_list;

	gint min_width, min_height;
};

struct _HtmlBoxRootClass {
	HtmlBoxBlockClass parent_class;
};

GType html_box_root_get_type (void);

HtmlBox *html_box_root_new (void);

GSList *html_box_root_get_float_left_list      (HtmlBoxRoot *root);
GSList *html_box_root_get_float_right_list     (HtmlBoxRoot *root);
GSList *html_box_root_get_positioned_list      (HtmlBoxRoot *root);
void    html_box_root_clear_float_left_list    (HtmlBoxRoot *root);
void    html_box_root_clear_float_right_list   (HtmlBoxRoot *root);
void    html_box_root_clear_positioned_list    (HtmlBoxRoot *root);
void    html_box_root_add_float                (HtmlBoxRoot *root, HtmlBox *box);
void    html_box_root_add_positioned           (HtmlBoxRoot *root, HtmlBox *box);
void    html_box_root_mark_floats_relayouted   (HtmlBoxRoot *root, HtmlBox *box);
void    html_box_root_mark_floats_unrelayouted (HtmlBoxRoot *root, HtmlBox *box);
void    html_box_root_paint_fixed_list         (HtmlPainter *painter, HtmlBox *root, gint tx, gint ty, GSList *list);

G_END_DECLS

#endif /* __HTMLBOXROOT_H__ */
