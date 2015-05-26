/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * gal-combo-stack.h - A combo box for displaying stacks (useful for Undo lists)
 *
 * Copyright (C) 2000 ÉRDI Gergõ <cactus@cactus.rulez.org>
 *
 * Authors:
 *   ÉRDI Gergõ <cactus@cactus.rulez.org>
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

#ifndef _GAL_COMBO_STACK_H
#define _GAL_COMBO_STACK_H

#include <gtk/gtkwidget.h>
#include "gal-combo-box.h"

G_BEGIN_DECLS

#define GAL_COMBO_STACK_TYPE         (gal_combo_stack_get_type ())
#define GAL_COMBO_STACK(obj)	     G_TYPE_CHECK_INSTANCE_CAST (obj, gal_combo_stack_get_type (), GalComboStack)
#define GAL_COMBO_STACK_CLASS(klass) G_TYPE_CHECK_CLASS_CAST (klass, gal_combo_stack_get_type (), GalComboTextClass)
#define GAL_IS_COMBO_STACK(obj)      G_TYPE_CHECK_INSTANCE_TYPE (obj, gal_combo_stack_get_type ())

typedef struct _GalComboStack	     GalComboStack;
typedef struct _GalComboStackPrivate GalComboStackPrivate;
typedef struct _GalComboStackClass   GalComboStackClass;

struct _GalComboStack {
	GalComboBox parent;

	GalComboStackPrivate *priv;
};

struct _GalComboStackClass {
	GalComboBoxClass parent_class;
};


GtkType    gal_combo_stack_get_type  (void);
GtkWidget *gal_combo_stack_new       (const gchar *stock_name,
				      gboolean const is_scrolled);

void       gal_combo_stack_push_item (GalComboStack *combo_stack,
				      const gchar *item);

void       gal_combo_stack_remove_top (GalComboStack *combo_stack,
				       gint num);
void       gal_combo_stack_pop       (GalComboStack *combo_stack,
				      gint num);
void       gal_combo_stack_clear     (GalComboStack *combo_stack);
void       gal_combo_stack_truncate  (GalComboStack *combo, int n);

G_END_DECLS

#endif
