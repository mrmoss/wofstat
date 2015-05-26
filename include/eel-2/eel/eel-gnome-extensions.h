/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* eel-gnome-extensions.h - interface for new functions that operate on
                                 gnome classes. Perhaps some of these should be
  			         rolled into gnome someday.

   Copyright (C) 1999, 2000, 2001 Eazel, Inc.

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

   Authors: Darin Adler <darin@eazel.com>
*/

#ifndef EEL_GNOME_EXTENSIONS_H
#define EEL_GNOME_EXTENSIONS_H

#include <glade/glade.h>
#include <gtk/gtkwindow.h>
#include <bonobo/bonobo-property-bag-client.h>

/* icon selection callback function. */
typedef void (* EelIconSelectionFunction) (const char *icon_path, gpointer callback_data);


/* Return a command string containing the path to a terminal on this system. */
char *        eel_gnome_make_terminal_command                         (const char               *command);

/* Open up a new terminal, optionally passing in a command to execute */
void          eel_gnome_open_terminal                                 (const char               *command);
void          eel_gnome_open_terminal_on_screen                       (const char               *command,
								       GdkScreen                *screen);

/* Create an icon selection dialog */
GtkWidget *   eel_gnome_icon_selector_new                             (const char               *title,
								       const char               *icon_directory,
								       GtkWindow                *owner,
								       EelIconSelectionFunction  selected,
								       gpointer                  callback_data);
									 
/* Execute a command. To be used in place of the exec family commands. This function
 * protects against creating zombie processes.
 */
void          eel_gnome_shell_execute                                 (const char               *command);
void          eel_gnome_shell_execute_on_screen                       (const char               *command,
								       GdkScreen                *screen);

char         *eel_bonobo_make_registration_id                         (const char               *iid);

GladeXML     *eel_glade_get_file                                      (const char               *filename,
								       const char               *root,
								       const char               *domain,
								       const char               *first_required_widget,
								       ...);

#endif /* EEL_GNOME_EXTENSIONS_H */
