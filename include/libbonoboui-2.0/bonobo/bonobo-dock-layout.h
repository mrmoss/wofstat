/* bonobo-dock-layout.c

   Copyright (C) 1998 Free Software Foundation

   All rights reserved.

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

   Author: Ettore Perazzoli <ettore@comm2000.it>
*/
/*
  @NOTATION@
*/

#ifndef _BONOBO_DOCK_LAYOUT_H
#define _BONOBO_DOCK_LAYOUT_H



G_BEGIN_DECLS

#define BONOBO_TYPE_DOCK_LAYOUT            (bonobo_dock_layout_get_type ())
#define BONOBO_DOCK_LAYOUT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BONOBO_TYPE_DOCK_LAYOUT, BonoboDockLayout))
#define BONOBO_DOCK_LAYOUT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BONOBO_TYPE_DOCK_LAYOUT, BonoboDockLayoutClass))
#define BONOBO_IS_DOCK_LAYOUT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BONOBO_TYPE_DOCK_LAYOUT))
#define BONOBO_IS_DOCK_LAYOUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BONOBO_TYPE_DOCK_LAYOUT))
#define BONOBO_DOCK_LAYOUT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), BONOBO_TYPE_DOCK_LAYOUT, BonoboDockLayoutClass))

typedef struct _BonoboDockLayoutItem    BonoboDockLayoutItem;
typedef struct _BonoboDockLayoutClass   BonoboDockLayoutClass;
typedef struct _BonoboDockLayout        BonoboDockLayout;
typedef struct _BonoboDockLayoutPrivate BonoboDockLayoutPrivate;

#include <bonobo/bonobo-dock.h>
#include <bonobo/bonobo-dock-item.h>

struct _BonoboDockLayoutItem
{
  BonoboDockItem *item;

  BonoboDockPlacement placement;

  union
  {
    struct
    {
      gint x;
      gint y;
      GtkOrientation orientation;
    } floating;

    struct
    {
      gint band_num;
      gint band_position;
      gint offset;
    } docked;

  } position;
};

struct _BonoboDockLayout
{
  GObject object;

  GList *items;                 /* BonoboDockLayoutItem */

  /*< private >*/
  BonoboDockLayoutPrivate *_priv;
};

struct _BonoboDockLayoutClass
{
  GObjectClass parent_class;

  gpointer dummy[4];
};

BonoboDockLayout     *bonobo_dock_layout_new      (void);
GType                 bonobo_dock_layout_get_type (void) G_GNUC_CONST;
   
gboolean             bonobo_dock_layout_add_item (BonoboDockLayout *layout,
                                                 BonoboDockItem *item,
                                                 BonoboDockPlacement placement,
                                                 gint band_num,
                                                 gint band_position,
                                                 gint offset);
   
gboolean             bonobo_dock_layout_add_floating_item
                                                (BonoboDockLayout *layout,
                                                 BonoboDockItem *item,
                                                 gint x, gint y,
                                                 GtkOrientation orientation);

BonoboDockLayoutItem *bonobo_dock_layout_get_item (BonoboDockLayout *layout,
                                                 BonoboDockItem *item);
BonoboDockLayoutItem *bonobo_dock_layout_get_item_by_name
                                                (BonoboDockLayout *layout,
                                                 const gchar *name);

gboolean             bonobo_dock_layout_remove_item
                                                (BonoboDockLayout *layout,
                                                 BonoboDockItem *item);
gboolean             bonobo_dock_layout_remove_item_by_name
                                                (BonoboDockLayout *layout,
                                                 const gchar *name);

gchar               *bonobo_dock_layout_create_string
                                                (BonoboDockLayout *layout);
gboolean             bonobo_dock_layout_parse_string
                                                (BonoboDockLayout *layout,
                                                 const gchar *string);

gboolean             bonobo_dock_layout_add_to_dock
                                                (BonoboDockLayout *layout,
                                                 BonoboDock *dock);

G_END_DECLS

#endif
