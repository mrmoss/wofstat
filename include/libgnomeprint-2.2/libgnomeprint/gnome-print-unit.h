/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print-unit.h: Unit utility functios
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
 *    Dirk Luetjens <dirk@luedi.oche.de>
 *    Yves Arrouye <Yves.Arrouye@marin.fdn.fr>
 *    Lauris Kaplinski <lauris@ximian.com>
 *
 *  Copyright (C) 1998 The Free Software Foundation and 2001-2202 Ximian, Inc.
 */

#ifndef __GNOME_PRINT_UNIT_H__
#define __GNOME_PRINT_UNIT_H__

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

/*
 * Units and conversion methods used by libgnomeprint.
 *
 * You need those for certain config keys (like paper size), if you are
 * interested in using these (look at gnome-print-config.h for discussion,
 * why you may NOT be interested in paper size).
 *
 * Unit bases define set of mutually unrelated measuring systems (numbers,
 * paper, screen and dimesionless user coordinates). Still, you can convert
 * between those, specifying scaling factors explicitly.
 *
 * Paper (i.e. output) coordinates are taken as absolute real world units.
 * It has some justification, because screen unit (pixel) size changes,
 * if you change screen resolution, while you cannot change output on paper
 * as easily (unless you have thermally contracting paper, of course).
 *
 */

typedef struct _GnomePrintUnit GnomePrintUnit;

/*
 * The base absolute unit is 1/72th of an inch (we are gnome PRINT, so sorry SI)
 */

typedef enum {
	GNOME_PRINT_UNIT_DIMENSIONLESS = (1 << 0), /* For percentages and like */
	GNOME_PRINT_UNIT_ABSOLUTE = (1 << 1),      /* Real world distances - i.e. mm, cm... */
	GNOME_PRINT_UNIT_DEVICE = (1 << 2),        /* Semi-real device-dependent distances i.e. pixels */
	GNOME_PRINT_UNIT_USERSPACE = (1 << 3)      /* Mathematical coordinates */
} GnomePrintUnitBase;

/*
 * Notice, that for correct menus etc. you have to use
 * ngettext method family yourself. For that reason we
 * do not provide translations in unit names.
 * I also do not know, whether to allow user-created units,
 * because this would certainly confuse textdomain.
 */

struct _GnomePrintUnit {
	guint version : 8; /* Has to be 0 at moment */
	guint base : 8; /* Base */
	gdouble unittobase;
	/* I am not absolutely sure, but seems that gettext can do the magic */
	guchar *name;
	guchar *abbr;
	guchar *plural;
	guchar *abbr_plural;
};

/* Base units are the ones used by gnome-print and paper descriptions */

#define GNOME_TYPE_PRINT_UNIT (gnome_print_unit_get_type ())
#define GNOME_PRINT_PS_UNIT   (gnome_print_unit_get_identity (GNOME_PRINT_UNIT_ABSOLUTE))
#define GNOME_PRINT_UNITS_ALL (GNOME_PRINT_UNIT_DIMENSIONLESS | GNOME_PRINT_UNIT_ABSOLUTE | GNOME_PRINT_UNIT_DEVICE | GNOME_PRINT_UNIT_USERSPACE)

GType                 gnome_print_unit_get_type (void);

const GnomePrintUnit *gnome_print_unit_get_identity (guint base);
const GnomePrintUnit *gnome_print_unit_get_default (void);
const GnomePrintUnit *gnome_print_unit_get_by_name (const guchar *name);
const GnomePrintUnit *gnome_print_unit_get_by_abbreviation (const guchar *abbreviation);

GList * gnome_print_unit_get_list (guint bases);
void    gnome_print_unit_free_list (GList *units);

/* Utility */
gboolean gnome_print_convert_distance      (gdouble *distance, const GnomePrintUnit *from, const GnomePrintUnit *to);
gboolean gnome_print_convert_distance_full (gdouble *distance, const GnomePrintUnit *from, const GnomePrintUnit *to,
					    gdouble ctmscale, gdouble devicescale);

#ifdef GNOME_PRINT_UNSTABLE_API
gchar * gnome_print_unit_get_name (const GnomePrintUnit *unit, gboolean plural, gboolean abbreviation, gint flags);
#endif

G_END_DECLS

#endif /* __GNOME_PRINT_UNIT_H__ */
