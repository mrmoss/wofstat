/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* eel-preferences-glade.h - Some functions to connect a Glade-file to gconf keys.

   Copyright (C) 2002 Jan Arne Petersen

   The Gnome Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Gnome Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Gnome Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Authors: Jan Arne Petersen <jpetersen@uni-bonn.de>
*/

#ifndef EEL_PREFERENCES_GLADE_H
#define EEL_PREFERENCES_GLADE_H

#include <glade/glade.h>

G_BEGIN_DECLS

void eel_preferences_glade_connect_bool				 (GladeXML    *dialog,
								  const char  *component,
								  const char  *key);
void eel_preferences_glade_connect_bool_slave			 (GladeXML    *dialog,
								  const char  *component,
								  const char  *key);
void eel_preferences_glade_connect_string_enum_option_menu	 (GladeXML    *dialog,
								  const char  *component,
								  const char  *key,
								  const char **values);
void eel_preferences_glade_connect_string_enum_option_menu_slave (GladeXML    *dialog,
								  const char  *component,
								  const char  *key);
void eel_preferences_glade_connect_int_enum			 (GladeXML    *dialog,
								  const char  *component,
								  const char  *key,
								  const int   *values);
void eel_preferences_glade_connect_string_enum_radio_button	 (GladeXML    *dialog,
								  const char **components,
								  const char  *key,
								  const char **values);
void eel_preferences_glade_connect_list_enum			 (GladeXML    *dialog,
						   		  const char **components,
								  const char  *key,
								  const char **values);

G_END_DECLS

#endif /* EEL_PREFERENCES_GLADE */
