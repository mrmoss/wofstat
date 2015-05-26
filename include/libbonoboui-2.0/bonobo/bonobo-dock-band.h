/* bonobo-dock-band.h

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

#ifndef _BONOBO_DOCK_BAND_H
#define _BONOBO_DOCK_BAND_H

#include <glib-object.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_DOCK_BAND            (bonobo_dock_band_get_type ())
#define BONOBO_DOCK_BAND(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BONOBO_TYPE_DOCK_BAND, BonoboDockBand))
#define BONOBO_DOCK_BAND_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BONOBO_TYPE_DOCK_BAND, BonoboDockBandClass))
#define BONOBO_IS_DOCK_BAND(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BONOBO_TYPE_DOCK_BAND))
#define BONOBO_IS_DOCK_BAND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BONOBO_TYPE_DOCK_BAND))
#define BONOBO_DOCK_BAND_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), BONOBO_TYPE_DOCK_BAND, BonoboDockBandClass))

typedef struct _BonoboDockBand BonoboDockBand;
typedef struct _BonoboDockBandPrivate BonoboDockBandPrivate;
typedef struct _BonoboDockBandClass BonoboDockBandClass;
typedef struct _BonoboDockBandChild BonoboDockBandChild;

#include <bonobo/bonobo-dock.h>
#include <bonobo/bonobo-dock-item.h>
#include <bonobo/bonobo-dock-layout.h>

struct _BonoboDockBand
{
  GtkContainer container;

  GList *children;              /* BonoboDockBandChild */

  GList *floating_child;        /* BonoboDockBandChild */

  /* This used to remember the allocation before the drag begin: it is
     necessary to do so because we actually decide what docking action
     happens depending on it, instead of using the current allocation
     (which might be constantly changing while the user drags things
     around).  */
  GtkAllocation drag_allocation;

  guint tot_offsets;

  guint max_space_requisition : 16;
  guint num_children : 8;
  guint new_for_drag : 1;
  guint doing_drag : 1;
  guint orientation : 1;

  /*< private >*/
  BonoboDockBandPrivate *_priv;
};

struct _BonoboDockBandClass
{
  GtkContainerClass parent_class;

  gpointer dummy[2];
};

struct _BonoboDockBandChild
{
  GtkWidget *widget;

  GtkAllocation drag_allocation;

  /* Maximum (requested) offset from the previous child.  */
  guint16 offset;

  /* Actual offset.  */
  guint16 real_offset;

  guint16 drag_offset;

  guint16 prev_space, foll_space;
  guint16 drag_prev_space, drag_foll_space;

  guint16 max_space_requisition;
};

GtkWidget     *bonobo_dock_band_new              (void);
GtkType        bonobo_dock_band_get_type         (void) G_GNUC_CONST;
   
void           bonobo_dock_band_set_orientation  (BonoboDockBand *band,
                                                 GtkOrientation orientation);
GtkOrientation bonobo_dock_band_get_orientation  (BonoboDockBand *band);
   
gboolean       bonobo_dock_band_insert           (BonoboDockBand *band,
                                                 GtkWidget *child,
                                                 guint offset,
                                                 gint position);
gboolean       bonobo_dock_band_prepend          (BonoboDockBand *band,
                                                 GtkWidget *child,
                                                 guint offset);
gboolean       bonobo_dock_band_append           (BonoboDockBand *band,
                                                 GtkWidget *child,
                                                 guint offset);
    
void           bonobo_dock_band_set_child_offset (BonoboDockBand *band,
                                                 GtkWidget *child,
                                                 guint offset);
guint          bonobo_dock_band_get_child_offset (BonoboDockBand *band,
                                                 GtkWidget *child); 
void           bonobo_dock_band_move_child       (BonoboDockBand *band,
                                                 GList *old_child,
                                                 guint new_num);
   
guint          bonobo_dock_band_get_num_children (BonoboDockBand *band);
    
void           bonobo_dock_band_drag_begin       (BonoboDockBand *band,
                                                 BonoboDockItem *item);
gboolean       bonobo_dock_band_drag_to          (BonoboDockBand *band,
                                                 BonoboDockItem *item,
                                                 gint x, gint y);
void           bonobo_dock_band_drag_end         (BonoboDockBand *band,
                                                 BonoboDockItem *item);
   
BonoboDockItem *bonobo_dock_band_get_item_by_name (BonoboDockBand *band,
                                                 const char *name,
                                                 guint *position_return,
                                                 guint *offset_return);

void           bonobo_dock_band_layout_add       (BonoboDockBand *band,
                                                 BonoboDockLayout *layout,
                                                 BonoboDockPlacement placement,
                                                 guint band_num);

#ifdef BONOBO_UI_INTERNAL
gint _bonobo_dock_band_handle_key_nav (BonoboDockBand *band,
				      BonoboDockItem *item,
				      GdkEventKey    *event);
#endif /* BONOBO_UI_INTERNAL */

G_END_DECLS

#endif
