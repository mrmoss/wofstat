/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-categories-master-list-dialog.h
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

#ifndef _E_CATEGORIES_MASTER_LIST_DIALOG_H_
#define _E_CATEGORIES_MASTER_LIST_DIALOG_H_

#include <gal/widgets/e-categories-master-list.h>

G_BEGIN_DECLS

#define E_CATEGORIES_MASTER_LIST_DIALOG_TYPE        (e_categories_master_list_dialog_get_type ())
#define E_CATEGORIES_MASTER_LIST_DIALOG(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), E_CATEGORIES_MASTER_LIST_DIALOG_TYPE, ECategoriesMasterListDialog))
#define E_CATEGORIES_MASTER_LIST_DIALOG_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), E_CATEGORIES_MASTER_LIST_DIALOG_TYPE, ECategoriesMasterListDialogClass))
#define E_IS_CATEGORIES_MASTER_LIST_DIALOG(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), E_CATEGORIES_MASTER_LIST_DIALOG_TYPE))
#define E_IS_CATEGORIES_MASTER_LIST_DIALOG_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), E_CATEGORIES_MASTER_LIST_DIALOG_TYPE))

typedef struct ECategoriesMasterListDialogPriv ECategoriesMasterListDialogPriv;

typedef struct {
	GtkObject parent;

	ECategoriesMasterListDialogPriv *priv;
} ECategoriesMasterListDialog;

typedef struct {
	GtkObjectClass parent_class;
} ECategoriesMasterListDialogClass;

GtkType                      e_categories_master_list_dialog_get_type   (void);
ECategoriesMasterListDialog *e_categories_master_list_dialog_new        (ECategoriesMasterList       *ecml);
ECategoriesMasterListDialog *e_categories_master_list_dialog_construct  (ECategoriesMasterListDialog *ecmld,
									 ECategoriesMasterList       *ecml);
void                         e_categories_master_list_dialog_raise      (ECategoriesMasterListDialog *ecmld);

G_END_DECLS

#endif /* _E_CATEGORIES_MASTER_LIST_DIALOG_H */
