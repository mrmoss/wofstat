/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-categories-master-list.h
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

#ifndef _E_CATEGORIES_MASTER_LIST_H_
#define _E_CATEGORIES_MASTER_LIST_H_

#include <gtk/gtkobject.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define E_CATEGORIES_MASTER_LIST_TYPE        (e_categories_master_list_get_type ())
#define E_CATEGORIES_MASTER_LIST(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), E_CATEGORIES_MASTER_LIST_TYPE, ECategoriesMasterList))
#define E_CATEGORIES_MASTER_LIST_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), E_CATEGORIES_MASTER_LIST_TYPE, ECategoriesMasterListClass))
#define E_IS_CATEGORIES_MASTER_LIST(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), E_CATEGORIES_MASTER_LIST_TYPE))
#define E_IS_CATEGORIES_MASTER_LIST_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), E_CATEGORIES_MASTER_LIST_TYPE))
#define E_CATEGORIES_MASTER_LIST_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), E_CATEGORIES_MASTER_LIST_TYPE, ECategoriesMasterListClass))


typedef struct {
	GObject   base;
} ECategoriesMasterList;

typedef struct {
	GObjectClass parent_class;

	/*
	 * Virtual methods
	 */
	int         (*count)    (ECategoriesMasterList *etm);
	const char *(*nth)      (ECategoriesMasterList *etm, int n);
	const char *(*nth_icon) (ECategoriesMasterList *etm, int n);
	const char *(*nth_color)(ECategoriesMasterList *etm, int n);
	void        (*append)   (ECategoriesMasterList *etm, const char *category,
				 const char *color, const char *icon_file);
	void        (*delete)   (ECategoriesMasterList *etm, int n);
	void        (*commit)   (ECategoriesMasterList *etm);

	void        (*reset)    (ECategoriesMasterList *etm);

	/* Signals */
	void        (*changed) (ECategoriesMasterList *etm);
} ECategoriesMasterListClass;

GType       e_categories_master_list_get_type  (void);

/**/
int         e_categories_master_list_count     (ECategoriesMasterList *ecml);
const char *e_categories_master_list_nth       (ECategoriesMasterList *ecml,
						int                    n);
const char *e_categories_master_list_nth_icon  (ECategoriesMasterList *ecml,
						int                    n);
const char *e_categories_master_list_nth_color (ECategoriesMasterList *ecml,
						int                    n);

/* Modification functions.  You have to commit after doing any series of these for them to take affect. */
void        e_categories_master_list_append    (ECategoriesMasterList *ecml,
						const char            *category,
						const char            *color,
						const char            *icon_file);
void        e_categories_master_list_delete    (ECategoriesMasterList *ecml,
						int                    n);
void        e_categories_master_list_commit    (ECategoriesMasterList *ecml);

/* Reset doesn't require a commit. */
void        e_categories_master_list_reset     (ECategoriesMasterList *ecml);
	
/* Routines for emitting signals on the list */
void        e_categories_master_list_changed   (ECategoriesMasterList *ecml);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _E_CATEGORIES_MASTER_LIST_H_ */
