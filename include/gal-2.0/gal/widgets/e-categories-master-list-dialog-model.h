/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-categories-master-list-dialog-model.h
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

#ifndef _E_CATEGORIES_MASTER_LIST_DIALOG_MODEL_H_
#define _E_CATEGORIES_MASTER_LIST_DIALOG_MODEL_H_

#include <gal/e-table/e-table-model.h>
#include <gal/widgets/e-categories-master-list.h>

#define E_CATEGORIES_MASTER_LIST_DIALOG_MODEL_TYPE        (e_categories_master_list_dialog_model_get_type ())
#define E_CATEGORIES_MASTER_LIST_DIALOG_MODEL(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), E_CATEGORIES_MASTER_LIST_DIALOG_MODEL_TYPE, ECategoriesMasterListDialogModel))
#define E_CATEGORIES_MASTER_LIST_DIALOG_MODEL_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), E_CATEGORIES_MASTER_LIST_DIALOG_MODEL_TYPE, ECategoriesMasterListDialogModelClass))
#define E_IS_CATEGORIES_MASTER_LIST_DIALOG_MODEL(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), E_CATEGORIES_MASTER_LIST_DIALOG_MODEL_TYPE))
#define E_IS_CATEGORIES_MASTER_LIST_DIALOG_MODEL_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), E_CATEGORIES_MASTER_LIST_DIALOG_MODEL_TYPE))

typedef struct ECategoriesMasterListDialogModelPriv  ECategoriesMasterListDialogModelPriv;

typedef struct ECategoriesMasterListDialogModel      ECategoriesMasterListDialogModel;
typedef struct ECategoriesMasterListDialogModelClass ECategoriesMasterListDialogModelClass;

struct ECategoriesMasterListDialogModel {
	ETableModel parent;

	ECategoriesMasterListDialogModelPriv *priv;
};


struct ECategoriesMasterListDialogModelClass {
	ETableModelClass parent_class;
};


GtkType      e_categories_master_list_dialog_model_get_type  (void);
ETableModel *e_categories_master_list_dialog_model_new       (void);

#endif /* _E_CATEGORIES_MASTER_LIST_DIALOG_MODEL_H_ */
