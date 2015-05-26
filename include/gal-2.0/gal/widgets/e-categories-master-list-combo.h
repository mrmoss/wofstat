/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-categories-master-list-combo.h
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

#ifndef _E_CATEGORIES_MASTER_LIST_COMBO_H_
#define _E_CATEGORIES_MASTER_LIST_COMBO_H_

#include <gal/widgets/e-categories-master-list.h>
#include <gtk/gtkcombo.h>

G_BEGIN_DECLS

#define E_CATEGORIES_MASTER_LIST_COMBO_TYPE        (e_categories_master_list_combo_get_type ())
#define E_CATEGORIES_MASTER_LIST_COMBO(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), E_CATEGORIES_MASTER_LIST_COMBO_TYPE, ECategoriesMasterListCombo))
#define E_CATEGORIES_MASTER_LIST_COMBO_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), E_CATEGORIES_MASTER_LIST_COMBO_TYPE, ECategoriesMasterListComboClass))
#define E_IS_CATEGORIES_MASTER_LIST_COMBO(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), E_CATEGORIES_MASTER_LIST_COMBO_TYPE))
#define E_IS_CATEGORIES_MASTER_LIST_COMBO_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), E_CATEGORIES_MASTER_LIST_COMBO_TYPE))

typedef struct ECategoriesMasterListComboPriv ECategoriesMasterListComboPriv;

typedef struct {
	GtkCombo parent;

	ECategoriesMasterListComboPriv *priv;
} ECategoriesMasterListCombo;

typedef struct {
	GtkComboClass parent_class;
} ECategoriesMasterListComboClass;

GtkType    e_categories_master_list_combo_get_type   (void);
GtkWidget *e_categories_master_list_combo_new        (ECategoriesMasterList      *ecml);
GtkWidget *e_categories_master_list_combo_construct  (ECategoriesMasterListCombo *ecmlc,
						      ECategoriesMasterList      *ecml);

G_END_DECLS

#endif /* _E_CATEGORIES_MASTER_LIST_COMBO_H */
