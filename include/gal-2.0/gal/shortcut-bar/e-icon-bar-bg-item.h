/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-icon-bar-bg-item.h
 * Copyright 1999, 2000, 2001, Ximian, Inc.
 *
 * Authors:
 *   Damon Chaplin <damon@ximian.com>
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

/*
 * EIconBarBgItem - A GnomeCanvasItem which covers the entire EIconBar.
 * It paints the rectangles around items when the mouse moves over them, and
 * the lines between items when dragging.
 */

#ifndef _E_ICON_BAR_BG_ITEM_H_
#define _E_ICON_BAR_BG_ITEM_H_

#include <libgnomecanvas/gnome-canvas.h>

#include "e-icon-bar.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define E_ICON_BAR_BG_ITEM(obj)          (G_TYPE_CHECK_INSTANCE_CAST((obj), e_icon_bar_bg_item_get_type (), EIconBarBgItem))
#define E_ICON_BAR_BG_ITEM_CLASS(k)      (G_TYPE_CHECK_CLASS_CAST ((k), e_icon_bar_bg_item_get_type (), EIconBarBgItemClass))
#define E_IS_ICON_BAR_BG_ITEM(o)         (G_TYPE_CHECK_INSTANCE_TYPE((o), e_icon_bar_bg_item_get_type ()))


typedef struct _EIconBarBgItem       EIconBarBgItem;
typedef struct _EIconBarBgItemClass  EIconBarBgItemClass;

struct _EIconBarBgItem
{
	GnomeCanvasItem canvas_item;

	/* The parent EIconBar widget. */
	EIconBar *icon_bar;
};


struct _EIconBarBgItemClass
{
	GnomeCanvasItemClass parent_class;
};

GtkType e_icon_bar_bg_item_get_type (void);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _E_ICON_BAR_BG_ITEM_H_ */
