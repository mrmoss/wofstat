/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-option-menu.h
 * Copyright 2000, 2001, Ximian, Inc.
 *
 * Authors:
 *   Chris Lahey <clahey@ximian.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License, version 2, as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef __E_OPTION_MENU_H__
#define __E_OPTION_MENU_H__

#include <gtk/gtkoptionmenu.h>

#ifdef __cplusplus
extern "C" {
#pragma }
#endif /* __cplusplus */

/* EOptionMenu - A class derived from OptionMenu for the purpose of adding
 * OptionMenu hacks.
 */

#define E_OPTION_MENU_TYPE			(e_option_menu_get_type ())
#define E_OPTION_MENU(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), E_OPTION_MENU_TYPE, EOptionMenu))
#define E_OPTION_MENU_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), E_OPTION_MENU_TYPE, EOptionMenuClass))
#define E_IS_OPTION_MENU(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), E_OPTION_MENU_TYPE))
#define E_IS_OPTION_MENU_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((obj), E_OPTION_MENU_TYPE))

typedef struct _EOptionMenu       EOptionMenu;
typedef struct _EOptionMenuClass  EOptionMenuClass;

struct _EOptionMenu
{
	GtkOptionMenu parent;

	gint          value;
};

struct _EOptionMenuClass
{
	GtkOptionMenuClass parent_class;
};


GtkType    e_option_menu_get_type                (void);

/* All functions are NULL terminated. */
GtkWidget *e_option_menu_new                     (const char   *first_label,
						  ...);
GtkWidget *e_option_menu_new_from_array          (const char  **labels);
GtkWidget *e_option_menu_construct_from_array    (EOptionMenu  *option_menu,
						  const char  **labels);

/* Set the strings in the option menu. */
void       e_option_menu_set_strings             (EOptionMenu  *option_menu,
						  const char   *first_label,
						  ...);
void       e_option_menu_set_strings_from_array  (EOptionMenu  *option_menu,
						  const char  **labels);

/* Last activated menu item */
gint       e_option_menu_get_value               (EOptionMenu  *option_menu);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __E_OPTION_MENU_H__ */
