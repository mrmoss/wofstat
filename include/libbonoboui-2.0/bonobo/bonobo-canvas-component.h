/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/**
 * bonobo-canvas-component.h: implements the CORBA interface for
 * the Bonobo::Canvas:Item interface used in Bonobo::Views.
 *
 * Author:
 *   Miguel de Icaza (miguel@kernel.org)
 *
 * (C) 1999 Helix Code, Inc.
 */
#ifndef _BONOBO_CANVAS_COMPONENT_H_
#define _BONOBO_CANVAS_COMPONENT_H_

#include <glib/gmacros.h>
#include <gdk/gdk.h>
#include <bonobo/bonobo-object.h>
#include <libgnomecanvas/gnome-canvas.h>

#ifndef BONOBO_UI_DISABLE_DEPRECATED

G_BEGIN_DECLS
 
#define BONOBO_TYPE_CANVAS_COMPONENT        (bonobo_canvas_component_get_type ())
#define BONOBO_CANVAS_COMPONENT(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), BONOBO_TYPE_CANVAS_COMPONENT, BonoboCanvasComponent))
#define BONOBO_CANVAS_COMPONENT_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), BONOBO_TYPE_CANVAS_COMPONENT_, BonoboCanvasComponentClass))
#define BONOBO_IS_CANVAS_COMPONENT(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), BONOBO_TYPE_CANVAS_COMPONENT))
#define BONOBO_IS_CANVAS_COMPONENT_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BONOBO_TYPE_CANVAS_COMPONENT))

typedef struct _BonoboCanvasComponentPrivate BonoboCanvasComponentPrivate;

typedef struct {
	BonoboObject base;
	BonoboCanvasComponentPrivate *priv;
} BonoboCanvasComponent;

typedef struct {
	BonoboObjectClass parent_class;
	
	POA_Bonobo_Canvas_Component__epv epv;

	/* Signals */
	void (*set_bounds) (BonoboCanvasComponent *component,
			    Bonobo_Canvas_DRect   *bbox,
			    CORBA_Environment     *ev);
	
	gboolean (*event)  (BonoboCanvasComponent *component,
			    GdkEvent              *event);
} BonoboCanvasComponentClass;

GType                   bonobo_canvas_component_get_type         (void) G_GNUC_CONST;
BonoboCanvasComponent  *bonobo_canvas_component_construct        (BonoboCanvasComponent *comp,
								  GnomeCanvasItem       *item);
BonoboCanvasComponent  *bonobo_canvas_component_new              (GnomeCanvasItem       *item);
GnomeCanvasItem        *bonobo_canvas_component_get_item         (BonoboCanvasComponent *comp);
void		        bonobo_canvas_component_grab		 (BonoboCanvasComponent *comp,
								  guint                  mask,
								  GdkCursor             *cursor,
								  guint32                time,
								  CORBA_Environment     *opt_ev);
void		        bonobo_canvas_component_ungrab		 (BonoboCanvasComponent *comp,
								  guint32                time,
								  CORBA_Environment     *opt_ev);
Bonobo_UIContainer      bonobo_canvas_component_get_ui_container (BonoboCanvasComponent *comp,
								  CORBA_Environment     *opt_ev);
					  
/* This is a helper function for creating a canvas with the root item replaced
 * by a proxy to the client side proxy.
 */
GnomeCanvas *bonobo_canvas_new (gboolean                     is_aa,
				Bonobo_Canvas_ComponentProxy proxy);


/* Sets up a callback to be invoked when the container activates the object.
 * Creating the component factory will do nothing until the container connects.
 */
typedef BonoboCanvasComponent *(*GnomeItemCreator) 
   (GnomeCanvas *canvas, void *user_data);

BonoboObject *bonobo_canvas_component_factory_new(GnomeItemCreator item_factory,
      void *data);

G_END_DECLS

#endif /* BONOBO_UI_DISABLE_DEPRECATED */

#endif /* */
