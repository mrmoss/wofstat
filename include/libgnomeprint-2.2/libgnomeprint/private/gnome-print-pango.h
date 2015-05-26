/* 
 * gnome-print-pango.h
 *
 * Copyright (C) 2003
 *
 * Developed by Jean Bréfort <jean.brefort@ac-dijon.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the 
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA  02111-1307, USA.
 */

#ifndef GNOME_PRINT_PANGO_H
#define GNOME_PRINT_PANGO_H

#include <libgnomeprint/gnome-print.h>
#include <pango/pango.h>

G_BEGIN_DECLS

void gnome_print_pango_layout_print (GnomePrintContext *gpc, PangoLayout* pl);

G_END_DECLS

#endif
