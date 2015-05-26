/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* eel-preferences.c - Preference peek/poke/notify interface.

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

   Authors: Ramiro Estrugo <ramiro@eazel.com>
*/

#ifndef EEL_PREFERENCES_H
#define EEL_PREFERENCES_H

#include <glib.h>
#include <gtk/gtkobject.h>
#include <eel/eel-string-list.h>
#include <eel/eel-gconf-extensions.h>

G_BEGIN_DECLS

/*
 * A callback which you can register to to be notified when a particular
 * preference changes.
 */
typedef void (*EelPreferencesCallback) (gpointer callback_data);

/* Preferences getters and setters */
gboolean       eel_preferences_get_boolean                     (const char              *name);
void           eel_preferences_set_boolean                     (const char              *name,
								gboolean                 boolean_value);
int            eel_preferences_get_integer                     (const char              *name);
void           eel_preferences_set_integer                     (const char              *name,
								int                      int_value);
int            eel_preferences_get_enum                        (const char              *name);
void           eel_preferences_set_enum                        (const char              *name,
								int                      int_value);
char *         eel_preferences_get                             (const char              *name);
void           eel_preferences_set                             (const char              *name,
								const char              *string_value);
EelStringList *eel_preferences_get_string_list                 (const char              *name);
void           eel_preferences_set_string_list                 (const char              *name,
								const EelStringList     *string_list_value);

GList         *eel_preferences_get_string_glist                 (const char              *name);
void           eel_preferences_set_string_glist                 (const char              *name,
								 const GList             *string_list_value);

void           eel_preferences_unset                            (const char              *name);

/* Writability of a key */
gboolean       eel_preferences_key_is_writable                 (const char              *name);

/* Callbacks */
void           eel_preferences_add_callback                    (const char              *name,
								EelPreferencesCallback   callback,
								gpointer                 callback_data);
void           eel_preferences_add_callback_while_alive        (const char              *name,
								EelPreferencesCallback   callback,
								gpointer                 callback_data,
								GObject                 *alive_object);
void           eel_preferences_remove_callback                 (const char              *name,
								EelPreferencesCallback   callback,
								gpointer                 callback_data);

/* Variables that are automatically updated (lightweight "callbacks") */
void           eel_preferences_add_auto_string                 (const char              *name,
								const char             **storage);
void           eel_preferences_add_auto_string_list            (const char              *name,
								const EelStringList    **storage);
void           eel_preferences_add_auto_string_glist           (const char              *name,
								const GList            **storage);
void           eel_preferences_add_auto_integer                (const char              *name,
								int                     *storage);
void           eel_preferences_add_auto_enum                   (const char              *name,
								int                     *storage);
void           eel_preferences_add_auto_boolean                (const char              *name,
								gboolean                *storage);
void           eel_preferences_remove_auto_string              (const char              *name,
								const char             **storage);
void           eel_preferences_remove_auto_string_list         (const char              *name,
								const EelStringList    **storage);
void           eel_preferences_remove_auto_integer             (const char              *name,
								int                     *storage);
void           eel_preferences_remove_auto_boolean             (const char              *name,
								int                     *storage);

/* Preferences attributes */

gboolean       eel_preferences_get_is_invisible                (const char              *name);
void           eel_preferences_set_is_invisible                (const char              *name,
								gboolean                 invisible);
char *         eel_preferences_get_description                 (const char              *name);
void           eel_preferences_set_description                 (const char              *name,
								const char              *description);
char *         eel_preferences_get_enumeration_id              (const char              *name);
void           eel_preferences_set_enumeration_id              (const char              *name,
								const char              *enumeration_id);

void        eel_preferences_set_emergency_fallback_string      (const char    *name,
								const char    *value);
void        eel_preferences_set_emergency_fallback_integer     (const char    *name,
								int            value);
void        eel_preferences_set_emergency_fallback_boolean     (const char    *name,
								gboolean       value);
void        eel_preferences_set_emergency_fallback_string_list (const char    *name,
								EelStringList *list);
GConfValue *eel_preferences_get_emergency_fallback             (const char    *name);


gboolean       eel_preferences_monitor_directory               (const char              *directory);
gboolean       eel_preferences_is_visible                      (const char              *name);
void           eel_preferences_init                      (const char              *storage_path);

G_END_DECLS

#endif /* EEL_PREFERENCES_H */
