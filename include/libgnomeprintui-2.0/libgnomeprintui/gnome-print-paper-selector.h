#ifndef __GNOME_PRINT_PAPER_SELECTOR_H__
#define __GNOME_PRINT_PAPER_SELECTOR_H__

/*
 * GNOME Paper Selector
 *
 * Copyright (C) 1999 James Henstridge <james@daa.com.au>
 * All rights reserved.
 *
 * This replaces the paper selector by Dirk Luetjens.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Cambridge, MA 02139, USA.
 */

#include <glib.h>

G_BEGIN_DECLS

/* Paper preview Widget */

#define GNOME_TYPE_PAPER_PREVIEW (gnome_paper_preview_get_type ())
#define GNOME_PAPER_PREVIEW(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PAPER_PREVIEW, GnomePaperPreview))
#define GNOME_PAPER_PREVIEW_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_PAPER_PREVIEW, GnomePaperPreviewClass))
#define GNOME_IS_PAPER_PREVIEW(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PAPER_PREVIEW))
#define GNOME_IS_PAPER_PREVIEW_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_PAPER_PREVIEW))
#define GNOME_PAPER_PREVIEW_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PAPER_PREVIEW, GnomePaperPreviewClass))

typedef struct _GnomePaperPreview GnomePaperPreview;
typedef struct _GnomePaperPreviewClass GnomePaperPreviewClass;

/* Paper selector Widget */

#define GNOME_TYPE_PAPER_SELECTOR (gnome_paper_selector_get_type ())
#define GNOME_PAPER_SELECTOR(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PAPER_SELECTOR, GnomePaperSelector))
#define GNOME_PAPER_SELECTOR_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_PAPER_SELECTOR, GnomePaperSelectorClass))
#define GNOME_IS_PAPER_SELECTOR(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PAPER_SELECTOR))
#define GNOME_IS_PAPER_SELECTOR_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_PAPER_SELECTOR))
#define GNOME_PAPER_SELECTOR_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PAPER_SELECTOR, GnomePaperSelectorClass))

typedef struct _GnomePaperSelector GnomePaperSelector;
typedef struct _GnomePaperSelectorClass GnomePaperSelectorClass;

/* Unit selector Widget */

#define GNOME_TYPE_PRINT_UNIT_SELECTOR (gnome_print_unit_selector_get_type ())
#define GNOME_PRINT_UNIT_SELECTOR(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PRINT_UNIT_SELECTOR, GnomePrintUnitSelector))
#define GNOME_PRINT_UNIT_SELECTOR_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_PRINT_UNIT_SELECTOR, GnomePrintUnitSelectorClass))
#define GNOME_IS_PRINT_UNIT_SELECTOR(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PRINT_UNIT_SELECTOR))
#define GNOME_IS_PRINT_UNIT_SELECTOR_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_PRINT_UNIT_SELECTOR))
#define GNOME_PRINT_UNIT_SELECTOR_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_PRINT_UNIT_SELECTOR, GnomePrintUnitSelectorClass))

typedef struct _GnomePrintUnitSelector GnomePrintUnitSelector;
typedef struct _GnomePrintUnitSelectorClass GnomePrintUnitSelectorClass;

#include <glib-object.h>
#include <libgnomeprint/gnome-print-config.h>

enum GnomePaperSelectorFlags {
	GNOME_PAPER_SELECTOR_MARGINS = (1 << 0),
	GNOME_PAPER_SELECTOR_FEED_ORIENTATION = (1 << 1)
};

GType gnome_paper_preview_get_type (void);

GtkWidget *gnome_paper_preview_new (GnomePrintConfig *config);

GType gnome_paper_selector_get_type (void);
GtkWidget *gnome_paper_selector_new (GnomePrintConfig *config);
GtkWidget *gnome_paper_selector_new_with_flags (GnomePrintConfig *config, gint flags);

GType gnome_print_unit_selector_get_type (void);

GtkWidget *gnome_print_unit_selector_new (guint bases);

const GnomePrintUnit *gnome_print_unit_selector_get_unit (GnomePrintUnitSelector *selector);

void gnome_print_unit_selector_set_bases (GnomePrintUnitSelector *selector, guint bases);
void gnome_print_unit_selector_set_unit (GnomePrintUnitSelector *selector, const GnomePrintUnit *unit);
void gnome_print_unit_selector_add_adjustment (GnomePrintUnitSelector *selector, GtkAdjustment *adjustment);
void gnome_print_unit_selector_remove_adjustment (GnomePrintUnitSelector *selector, GtkAdjustment *adjustment);

G_END_DECLS

#endif

