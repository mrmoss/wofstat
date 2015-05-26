/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-categories-master-list-array.h
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

#ifndef _E_CATEGORIES_MASTER_LIST_ARRAY_H_
#define _E_CATEGORIES_MASTER_LIST_ARRAY_H_

#include <gal/widgets/e-categories-master-list.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define E_CATEGORIES_MASTER_LIST_ARRAY_TYPE        (e_categories_master_list_array_get_type ())
#define E_CATEGORIES_MASTER_LIST_ARRAY(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), E_CATEGORIES_MASTER_LIST_ARRAY_TYPE, ECategoriesMasterListArray))
#define E_CATEGORIES_MASTER_LIST_ARRAY_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), E_CATEGORIES_MASTER_LIST_ARRAY_TYPE, ECategoriesMasterListArrayClass))
#define E_IS_CATEGORIES_MASTER_LIST_ARRAY(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), E_CATEGORIES_MASTER_LIST_ARRAY_TYPE))
#define E_IS_CATEGORIES_MASTER_LIST_ARRAY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), E_CATEGORIES_MASTER_LIST_ARRAY_TYPE))

typedef struct _ECategoriesMasterListArrayPriv ECategoriesMasterListArrayPriv;

typedef struct {
	ECategoriesMasterList           base;
	ECategoriesMasterListArrayPriv *priv;
} ECategoriesMasterListArray;

typedef struct {
	ECategoriesMasterListClass parent_class;
} ECategoriesMasterListArrayClass;

GtkType                e_categories_master_list_array_get_type     (void);
ECategoriesMasterList *e_categories_master_list_array_new          (void);

char                  *e_categories_master_list_array_to_string    (ECategoriesMasterListArray *ecmla);
void                   e_categories_master_list_array_from_string  (ECategoriesMasterListArray *ecmla,
								    const char                 *string);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _E_CATEGORIES_MASTER_LIST_ARRAY_H_ */
