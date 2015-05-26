/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gp-gc.c: An opaque object, holding current drawing state
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
 *
 *  Copyright (C) 2000-2002 Ximian, Inc. and authors
 *
 */

#ifndef __GP_GC_H__
#define __GP_GC_H__

#include <glib.h>

G_BEGIN_DECLS

typedef struct _GPGC GPGC;

/*
 * GPGC - an opaque object, holding current drawing parameters.
 *
 * Return value 0 for set methods indicates success, any other is error.
 *
 * We use very primitive tagging here, but it is suitable for libgnomeprint:
 * CTM, line, dash, color and font can be tagged as unset, clear or changed. It is
 * convenient way for print context to mark, whether they need to specify
 * style attributes for next serialized drawing call.
 * GC can also include single data value, which is used by libgnomeprintui
 * to store pointer to current GnomeCanvasGroup. It does not do any reference
 * handling, so it can be used only if we really know, what we are doing.
 *
 */


G_END_DECLS

#endif
