/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

#ifndef __GNOME_PRINT_PAPER_SELECTOR_H__
#define __GNOME_PRINT_PAPER_SELECTOR_H__

/*
 *  gnome-print-paper-selector.h: Paper preview Canvas item
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
 *
 *  Copyright (C) 1998 James Henstridge <james@daa.com.au>
 *
 */

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_PAPER_SELECTOR         (gnome_paper_selector_get_type ())
#define GNOME_PAPER_SELECTOR(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_PAPER_SELECTOR, GnomePaperSelector))
#define GNOME_PAPER_SELECTOR_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST    ((k), GNOME_TYPE_PAPER_SELECTOR, GnomePaperSelectorClass))
#define GNOME_IS_PAPER_SELECTOR(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_PAPER_SELECTOR))
#define GNOME_IS_PAPER_SELECTOR_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE    ((k), GNOME_TYPE_PAPER_SELECTOR))
#define GNOME_PAPER_SELECTOR_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS  ((o), GNOME_TYPE_PAPER_SELECTOR, GnomePaperSelectorClass))

typedef struct _GnomePaperSelector      GnomePaperSelector;
typedef struct _GnomePaperSelectorClass GnomePaperSelectorClass;

#include <glib-object.h>
#include <libgnomeprint/gnome-print-config.h>

enum GnomePaperSelectorFlags {
	GNOME_PAPER_SELECTOR_MARGINS = (1 << 0),
	GNOME_PAPER_SELECTOR_FEED_ORIENTATION = (1 << 1)
};

GType       gnome_paper_selector_get_type (void);
GtkWidget * gnome_paper_selector_new (GnomePrintConfig *config);
GtkWidget * gnome_paper_selector_new_with_flags (GnomePrintConfig *config, gint flags);

G_END_DECLS

#endif  /* __GNOME_PRINT_PAPER_SELECTOR_H__ */

