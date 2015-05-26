/* WARNING ____ IMMATURE API ____ liable to change */

/* bonobo-dock-item.h
 *
 * Copyright (C) 1998 Ettore Perazzoli
 * Copyright (C) 1998 Elliot Lee
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
/*
  @NOTATION@
*/

#ifndef _BONOBO_DOCK_ITEM_H
#define _BONOBO_DOCK_ITEM_H

#include <gdk/gdk.h>
#include <gtk/gtkbin.h>
#include <gtk/gtkenums.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_DOCK_ITEM            (bonobo_dock_item_get_type())
#define BONOBO_DOCK_ITEM(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BONOBO_TYPE_DOCK_ITEM, BonoboDockItem))
#define BONOBO_DOCK_ITEM_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BONOBO_TYPE_DOCK_ITEM, BonoboDockItemClass))
#define BONOBO_IS_DOCK_ITEM(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BONOBO_TYPE_DOCK_ITEM))
#define BONOBO_IS_DOCK_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BONOBO_TYPE_DOCK_ITEM))
#define BONOBO_DOCK_ITEM_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), BONOBO_TYPE_DOCK_ITEM, BonoboDockItemClass))

typedef enum
{
  BONOBO_DOCK_ITEM_BEH_NORMAL = 0,
  BONOBO_DOCK_ITEM_BEH_EXCLUSIVE = 1 << 0,
  BONOBO_DOCK_ITEM_BEH_NEVER_FLOATING = 1 << 1,
  BONOBO_DOCK_ITEM_BEH_NEVER_VERTICAL = 1 << 2,
  BONOBO_DOCK_ITEM_BEH_NEVER_HORIZONTAL = 1 << 3,
  BONOBO_DOCK_ITEM_BEH_LOCKED = 1 << 4
  /* MAINT: Update the size of the bit field in the BonoboDockItem structure if you add items to this */
} BonoboDockItemBehavior;

/* obsolete, for compatibility; don't use */
#define BONOBO_DOCK_ITEM_BEH_NEVER_DETACH BONOBO_DOCK_ITEM_BEH_NEVER_FLOATING

#define BONOBO_DOCK_ITEM_NOT_LOCKED(x) (! (BONOBO_DOCK_ITEM(x)->behavior \
                                          & BONOBO_DOCK_ITEM_BEH_LOCKED))

typedef struct _BonoboDockItem        BonoboDockItem;
typedef struct _BonoboDockItemPrivate BonoboDockItemPrivate;
typedef struct _BonoboDockItemClass   BonoboDockItemClass;

struct _BonoboDockItem
{
  GtkBin bin;

  gchar                *name;

  GdkWindow            *bin_window; /* parent window for children */
  GdkWindow            *float_window;
  GtkShadowType         shadow_type;

  /* Start drag position (wrt widget->window).  */
  gint16                  dragoff_x, dragoff_y;

  /* Position of the floating window.  */
  gint16                  float_x, float_y;

  guint                 behavior : 5;
  guint                 orientation : 1;

  guint                 float_window_mapped : 1;
  guint                 is_floating : 1;
  guint                 in_drag : 1;
  /* If TRUE, the pointer must be grabbed on "map_event".  */
  guint                 grab_on_map_event : 1;

  /*< private >*/
  BonoboDockItemPrivate *_priv;
};

struct _BonoboDockItemClass
{
  GtkBinClass parent_class;

  void (* dock_drag_begin) (BonoboDockItem *item);
  void (* dock_drag_motion) (BonoboDockItem *item, gint x, gint y);
  void (* dock_drag_end) (BonoboDockItem *item);
  void (* dock_detach) (BonoboDockItem *item);
  void (* orientation_changed) (BonoboDockItem *item, GtkOrientation new_orientation);

  gpointer dummy[4];
};

/* Public methods.  */
GtkType        bonobo_dock_item_get_type        (void) G_GNUC_CONST;
GtkWidget     *bonobo_dock_item_new             (const gchar *name,
                                                BonoboDockItemBehavior behavior);
void           bonobo_dock_item_construct       (BonoboDockItem *new_dock_item,
						const gchar *name,
						BonoboDockItemBehavior behavior);

GtkWidget     *bonobo_dock_item_get_child       (BonoboDockItem *dock_item);

char          *bonobo_dock_item_get_name        (BonoboDockItem *dock_item);

void           bonobo_dock_item_set_shadow_type (BonoboDockItem *dock_item,
                                                GtkShadowType type);

GtkShadowType  bonobo_dock_item_get_shadow_type (BonoboDockItem *dock_item);
 
gboolean       bonobo_dock_item_set_orientation (BonoboDockItem *dock_item,
                                                GtkOrientation orientation);

GtkOrientation bonobo_dock_item_get_orientation (BonoboDockItem *dock_item);

BonoboDockItemBehavior
               bonobo_dock_item_get_behavior    (BonoboDockItem *dock_item);

/* Private methods.  */
#ifdef BONOBO_UI_INTERNAL
void           bonobo_dock_item_set_locked      (BonoboDockItem *dock_item,
						 gboolean        locked);
gboolean       bonobo_dock_item_detach          (BonoboDockItem *item,
						 gint x, gint y);
                                               
void           bonobo_dock_item_attach          (BonoboDockItem *item,
						 GtkWidget *parent,
						 gint x, gint y);
void           bonobo_dock_item_unfloat         (BonoboDockItem *item);

void           bonobo_dock_item_grab_pointer    (BonoboDockItem *item);
                                               
void           bonobo_dock_item_drag_floating   (BonoboDockItem *item,
						 gint x, gint y);

void           bonobo_dock_item_handle_size_request
                                               (BonoboDockItem *item,
                                                GtkRequisition *requisition);

void           bonobo_dock_item_get_floating_position
                                               (BonoboDockItem *item,
                                                gint *x, gint *y);
GtkWidget     *bonobo_dock_item_get_grip       (BonoboDockItem *item);

#endif /* BONOBO_UI_INTERNAL */

G_END_DECLS

#endif /* _BONOBO_DOCK_ITEM_H */
