/* bonobo-dock.h

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

#ifndef _BONOBO_DOCK_H
#define _BONOBO_DOCK_H

#include <glib-object.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_DOCK            (bonobo_dock_get_type ())
#define BONOBO_DOCK(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BONOBO_TYPE_DOCK, BonoboDock))
#define BONOBO_DOCK_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BONOBO_TYPE_DOCK, BonoboDockClass))
#define BONOBO_IS_DOCK(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BONOBO_TYPE_DOCK))
#define BONOBO_IS_DOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BONOBO_TYPE_DOCK))
#define BONOBO_DOCK_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), BONOBO_TYPE_DOCK, BonoboDockClass))

typedef enum
{
  BONOBO_DOCK_TOP,
  BONOBO_DOCK_RIGHT,
  BONOBO_DOCK_BOTTOM,
  BONOBO_DOCK_LEFT,
  BONOBO_DOCK_FLOATING
} BonoboDockPlacement;

typedef struct _BonoboDock BonoboDock;
typedef struct _BonoboDockPrivate BonoboDockPrivate;
typedef struct _BonoboDockClass BonoboDockClass;

#include <bonobo/bonobo-dock-band.h>
#include <bonobo/bonobo-dock-layout.h>

struct _BonoboDock
{
  GtkContainer container;

  GtkWidget *client_area;

  /* BonoboDockBands associated with this dock.  */
  GList *top_bands;
  GList *bottom_bands;
  GList *right_bands;
  GList *left_bands;

  /* Children that are currently not docked.  */
  GList *floating_children;     /* GtkWidget */

  /* Client rectangle before drag.  */
  GtkAllocation client_rect;

  guint floating_items_allowed : 1;

  /*< private >*/
  BonoboDockPrivate *_priv;
};

struct _BonoboDockClass
{
  GtkContainerClass parent_class;

  void (* layout_changed) (BonoboDock *dock);

  gpointer dummy[4];
};

GtkWidget     *bonobo_dock_new               (void);
GtkType        bonobo_dock_get_type          (void) G_GNUC_CONST;

void           bonobo_dock_allow_floating_items
                                            (BonoboDock *dock,
                                             gboolean enable);
                                            
void           bonobo_dock_add_item          (BonoboDock             *dock,
                                             BonoboDockItem         *item,
                                             BonoboDockPlacement  placement,
                                             guint                  band_num,
                                             gint                   position,
                                             guint                  offset,
                                             gboolean               in_new_band);

void           bonobo_dock_add_floating_item (BonoboDock *dock,
                                             BonoboDockItem *widget,
                                             gint x, gint y,
                                             GtkOrientation orientation);
          
void             bonobo_dock_set_client_area   (BonoboDock             *dock,
						GtkWidget             *widget);

GtkWidget       *bonobo_dock_get_client_area   (BonoboDock             *dock);
  
BonoboDockItem  *bonobo_dock_get_item_by_name  (BonoboDock *dock,
						const gchar *name,
						BonoboDockPlacement *placement_return,
						guint *num_band_return,
						guint *band_position_return,
						guint *offset_return);

BonoboDockLayout *bonobo_dock_get_layout      (BonoboDock *dock);

gboolean          bonobo_dock_add_from_layout (BonoboDock *dock,
					       BonoboDockLayout *layout);

/* protected */
#ifdef BONOBO_UI_INTERNAL
gint _bonobo_dock_handle_key_nav (BonoboDock     *dock,
				  BonoboDockBand *band,
				  BonoboDockItem *item,
				  GdkEventKey    *event);
#endif /* BONOBO_UI_INTERNAL */

G_END_DECLS

#endif
