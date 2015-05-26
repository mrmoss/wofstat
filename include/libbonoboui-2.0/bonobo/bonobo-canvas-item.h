/**
 * bonobo-canvas-item.h: Canvas item implementation for embedding remote 
 * 			 canvas-items
 *
 * Author:
 *     Miguel de Icaza (miguel@kernel.org)
 *
 * (C) 1999, 2000 Helix Code, Inc.
 */
#ifndef _BONOBO_CANVAS_ITEM_H_
#define _BONOBO_CANVAS_ITEM_H_

#include <glib/gmacros.h>
#include <libgnomecanvas/gnome-canvas.h>

#ifndef BONOBO_UI_DISABLE_DEPRECATED

G_BEGIN_DECLS

#define BONOBO_TYPE_CANVAS_ITEM          (bonobo_canvas_item_get_type ())
#define BONOBO_CANVAS_ITEM(obj)          (GTK_CHECK_CAST((obj), bonobo_canvas_item_get_type (), BonoboCanvasItem))
#define BONOBO_CANVAS_ITEM_CLASS(k)      (GTK_CHECK_CLASS_CAST ((k), bonobo_canvas_item_get_type (), BonoboCanvasItemClass))
#define BONOBO_IS_CANVAS_ITEM(o)         (GTK_CHECK_TYPE((o), bonobo_canvas_item_get_type ()))

typedef struct _BonoboCanvasItemPrivate BonoboCanvasItemPrivate;
typedef struct _BonoboCanvasItem        BonoboCanvasItem;

struct _BonoboCanvasItem {
	GnomeCanvasItem         canvas_item;
	BonoboCanvasItemPrivate *priv;
};

typedef struct {
	GnomeCanvasItemClass parent_class;
} BonoboCanvasItemClass;

GType bonobo_canvas_item_get_type   (void) G_GNUC_CONST;
void  bonobo_canvas_item_set_bounds (BonoboCanvasItem *item,
				     double x1, double y1,
				     double x2, double y2);

G_END_DECLS

#endif /* BONOBO_UI_DISABLE_DEPRECATED */

#endif /* _BONOBO_CANVAS_ITEM_H_ */

