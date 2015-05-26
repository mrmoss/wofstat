/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-print-config-private.h:
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
 *    Lauris Kaplinski <lauris@ximian.com>
 *    Chema Celorio <chema@ximian.com>
 *
 *  Copyright 2001-2003 Ximian, Inc.
 *
 */

#ifndef __GNOME_PRINT_CONFIG_PRIVATE_H__
#define __GNOME_PRINT_CONFIG_PRIVATE_H__

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_PRINT_CONFIG_NODE(c) gnome_print_config_get_node (c)

GPANode * gnome_print_config_get_node (GnomePrintConfig *config);

G_END_DECLS

#endif /*  __GNOME_PRINT_CONFIG_PRIVATE_H__ */

