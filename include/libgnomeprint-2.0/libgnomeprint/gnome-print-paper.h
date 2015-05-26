#ifndef __GNOME_PRINT_PAPER_H__
#define __GNOME_PRINT_PAPER_H__

/*
 * GnomePrintPaper
 *
 * It is pure convenience stuff, that hopefully meakes the life
 * easier for someone
 *
 * Copyright (C) 1998 the Free Software Foundation and Ximian, Inc.
 *
 * Authors:
 *   Dirk Luetjens <dirk@luedi.oche.de>
 *   Yves Arrouye <Yves.Arrouye@marin.fdn.fr>
 *   Lauris Kaplinski <lauris@ximian.com>
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
 * Foundation, Inc.,  59 Temple Place - Suite 330, Cambridge, MA 02139, USA.
 */

#include <glib.h>

G_BEGIN_DECLS

/*
 * Papers used by gnome-print.
 *
 * Beware of these, as given printer may not support all paper sizes.
 *
 * Also, depending on layout, actual paper size may, or may not be
 * the same as effective imaging area available to application.
 * If unsure, better use GnomePrintMaster and libgnomeprintui widgets.
 *
 */

typedef struct _GnomePrintPaper GnomePrintPaper;

#include <libgnomeprint/gnome-print-unit.h>

struct _GnomePrintPaper {
	guint version : 8; /* Has to be 0 at moment */
	guchar *name; /* Name such as A4 */
	gdouble width, height;
};

/* Returned papers are const, but lists have to be freed */
/* All distances are in GNOME_PRINT_PS_UNIT */

const GnomePrintPaper *gnome_print_paper_get_default (void);
const GnomePrintPaper *gnome_print_paper_get_by_name (const guchar *name);
const GnomePrintPaper *gnome_print_paper_get_by_size (gdouble width, gdouble height);
const GnomePrintPaper *gnome_print_paper_get_closest_by_size (gdouble width, gdouble height, gboolean mustfit);

GList *gnome_print_paper_get_list (void);
void gnome_print_paper_free_list (GList *papers);

G_END_DECLS

#endif 
