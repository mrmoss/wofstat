/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-categories.h
 * Copyright 2000, 2001, Ximian, Inc.
 *
 * Authors:
 *   Chris Lahey <clahey@ximian.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License, version 2, as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef __E_CATEGORIES_H__
#define __E_CATEGORIES_H__

#include <glib.h>
#include <gtk/gtktypeutils.h>
#include <gtk/gtkwidget.h>
#include <gtk/gtkdialog.h>
#include <glade/glade.h>
#include <gal/e-table/e-table-model.h>

#ifdef __cplusplus
extern "C" {
#pragma }
#endif /* __cplusplus */

/* ECategories - A dialog displaying information about a contact.
 *
 * The following arguments are available:
 *
 * name		type		read/write	description
 * --------------------------------------------------------------------------------
 */

#define E_CATEGORIES_TYPE			(e_categories_get_type ())
#define E_CATEGORIES(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), E_CATEGORIES_TYPE, ECategories))
#define E_CATEGORIES_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), E_CATEGORIES_TYPE, ECategoriesClass))
#define E_IS_CATEGORIES(obj)		        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), E_CATEGORIES_TYPE))
#define E_IS_CATEGORIES_CLASS(klass)	        (G_TYPE_CHECK_CLASS_TYPE ((obj), E_CATEGORIES_TYPE))


typedef struct _ECategories       ECategories;
typedef struct _ECategoriesClass  ECategoriesClass;
typedef struct _ECategoriesPriv   ECategoriesPriv;

struct _ECategories
{
	GtkDialog parent;

	ECategoriesPriv *priv;
};

struct _ECategoriesClass
{
	GtkDialogClass parent_class;
};


GType      e_categories_get_type   (void);
GtkWidget *e_categories_new        (const char  *categories);
void       e_categories_construct  (ECategories *categories,
				    const char  *initial_category_list);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __E_CATEGORIES_H__ */
