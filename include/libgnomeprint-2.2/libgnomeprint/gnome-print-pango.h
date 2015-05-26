/* 
 * gnome-print-pango.h
 *
 * Copyright (C) 2003 Jean BrÃfort <jean brefort ac-dijon fr>
 * Copyright (C) 2004 Red Hat, Inc.
 *
 * Developed by Jean Bréfort <jean.brefort@ac-dijon.fr>
 * Rewritten by Owen Taylor <otaylor redhat com>
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

PangoFontMap *gnome_print_pango_font_map_new         (void);
PangoFontMap *gnome_print_pango_get_default_font_map (void);
PangoContext *gnome_print_pango_create_context       (PangoFontMap      *fontmap);
void          gnome_print_pango_update_context       (PangoContext      *context,
						      GnomePrintContext *gpc);
PangoLayout  *gnome_print_pango_create_layout        (GnomePrintContext *gpc);

void gnome_print_pango_glyph_string (GnomePrintContext *gpc, PangoFont *font, PangoGlyphString *glyphs);
void gnome_print_pango_layout_line (GnomePrintContext *gpc, PangoLayoutLine *line);
void gnome_print_pango_layout      (GnomePrintContext *gpc, PangoLayout *layout);


/* Deprecated interface
 */
void gnome_print_pango_layout_print (GnomePrintContext *gpc, PangoLayout* pl);

G_END_DECLS

#endif
