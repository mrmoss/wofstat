/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

#ifndef __GNOME_PRINT_UNIT_SELECTOR_H__
#define __GNOME_PRINT_UNIT_SELECTOR_H__

/*
 *  gnome-print-unit-selector.h: Unit selector
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public License
 *  as published by the Free Software Foundation; either version 2 of
 *  the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Authors:
 *    James Henstridge <james@daa.com.au>
 *    FIXME: Add real authors, i think Andreas did it (Chema)
 *
 *  Copyright (C) 1998 James Henstridge <james@daa.com.au>
 *
 */

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_PRINT_UNIT_SELECTOR         (gnome_print_unit_selector_get_type ())
#define GNOME_PRINT_UNIT_SELECTOR(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_UNIT_SELECTOR, GnomePrintUnitSelector))
#define GNOME_PRINT_UNIT_SELECTOR_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST ((k),    GNOME_TYPE_PRINT_UNIT_SELECTOR, GnomePrintUnitSelectorClass))
#define GNOME_IS_PRINT_UNIT_SELECTOR(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_UNIT_SELECTOR))
#define GNOME_IS_PRINT_UNIT_SELECTOR_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k),    GNOME_TYPE_PRINT_UNIT_SELECTOR))
#define GNOME_PRINT_UNIT_SELECTOR_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o),  GNOME_TYPE_PRINT_UNIT_SELECTOR, GnomePrintUnitSelectorClass))

typedef struct _GnomePrintUnitSelector      GnomePrintUnitSelector;
typedef struct _GnomePrintUnitSelectorClass GnomePrintUnitSelectorClass;

#include <libgnomeprint/gnome-print-paper.h>

GType       gnome_print_unit_selector_get_type (void);
GtkWidget * gnome_print_unit_selector_new (guint bases);

void gnome_print_unit_selector_set_bases         (GnomePrintUnitSelector *selector, guint bases);
void gnome_print_unit_selector_set_unit          (GnomePrintUnitSelector *selector, const GnomePrintUnit *unit);
void gnome_print_unit_selector_add_adjustment    (GnomePrintUnitSelector *selector, GtkAdjustment *adjustment);
void gnome_print_unit_selector_remove_adjustment (GnomePrintUnitSelector *selector, GtkAdjustment *adjustment);

const GnomePrintUnit * gnome_print_unit_selector_get_unit (GnomePrintUnitSelector *selector);

G_END_DECLS

#endif /* __GNOME_PRINT_UNIT_SELECTOR__ */
