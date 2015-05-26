/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/**
 * Bonobo control frame object.
 *
 * Authors:
 *   Nat Friedman    (nat@helixcode.com)
 *   Miguel de Icaza (miguel@kernel.org)
 *
 * Copyright 1999, 2000 Helix Code, Inc.
 */
#ifndef _BONOBO_CONTROL_FRAME_H_
#define _BONOBO_CONTROL_FRAME_H_

#include <glib/gmacros.h>
#include <gtk/gtkwidget.h>
#include <bonobo/bonobo-object.h>
#include <bonobo/bonobo-ui-component.h>
#include <bonobo/bonobo-property-bag-client.h>

typedef struct _BonoboControlFrame BonoboControlFrame;

#include <bonobo/bonobo-socket.h>

G_BEGIN_DECLS
 
#define BONOBO_TYPE_CONTROL_FRAME        (bonobo_control_frame_get_type ())
#define BONOBO_CONTROL_FRAME(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), BONOBO_TYPE_CONTROL_FRAME, BonoboControlFrame))
#define BONOBO_CONTROL_FRAME_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST ((k), BONOBO_TYPE_CONTROL_FRAME, BonoboControlFrameClass))
#define BONOBO_IS_CONTROL_FRAME(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), BONOBO_TYPE_CONTROL_FRAME))
#define BONOBO_IS_CONTROL_FRAME_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BONOBO_TYPE_CONTROL_FRAME))

typedef struct _BonoboControlFramePrivate BonoboControlFramePrivate;

struct _BonoboControlFrame {
	BonoboObject base;
	BonoboControlFramePrivate *priv;
};

typedef struct {
	BonoboObjectClass parent_class;

	POA_Bonobo_ControlFrame__epv epv;

	gpointer dummy[4];

	/* Signals. */
	void (*activated)           (BonoboControlFrame *control_frame, gboolean state);
	void (*activate_uri)        (BonoboControlFrame *control_frame, const char *uri, gboolean relative);
} BonoboControlFrameClass;

#define BONOBO_CONTROL_FRAME_TOPLEVEL_PROP "bonobo:toplevel"

/* Object construction stuff */
GType                         bonobo_control_frame_get_type                  (void) G_GNUC_CONST;
BonoboControlFrame           *bonobo_control_frame_construct                 (BonoboControlFrame  *control_frame,
									      Bonobo_UIContainer   ui_container,
									      CORBA_Environment   *ev);
BonoboControlFrame           *bonobo_control_frame_new                       (Bonobo_UIContainer   ui_container);

GtkWidget                    *bonobo_control_frame_get_widget                (BonoboControlFrame  *frame);

/* This is only allowed when the Control is deactivated */
void                          bonobo_control_frame_set_ui_container          (BonoboControlFrame  *control_frame,
									      Bonobo_UIContainer   uic,
									      CORBA_Environment   *ev);

/* Activating remote controls */
void                          bonobo_control_frame_control_activate          (BonoboControlFrame  *control_frame);
void                          bonobo_control_frame_control_deactivate        (BonoboControlFrame  *control_frame);
void                          bonobo_control_frame_set_autoactivate          (BonoboControlFrame  *control_frame,
									      gboolean             autoactivate);
gboolean                      bonobo_control_frame_get_autoactivate          (BonoboControlFrame  *control_frame);

/* Remote properties */
Bonobo_PropertyBag            bonobo_control_frame_get_control_property_bag  (BonoboControlFrame  *control_frame,
									      CORBA_Environment   *opt_ev);

/* Ambient properties */
void                          bonobo_control_frame_set_propbag               (BonoboControlFrame  *control_frame,
									      BonoboPropertyBag   *propbag);
BonoboPropertyBag            *bonobo_control_frame_get_propbag               (BonoboControlFrame  *control_frame);

/* Widget state proxying */
void                          bonobo_control_frame_control_set_state         (BonoboControlFrame  *control_frame,
									      GtkStateType         state);
void                          bonobo_control_frame_set_autostate             (BonoboControlFrame  *control_frame,
									      gboolean             autostate);
gboolean                      bonobo_control_frame_get_autostate             (BonoboControlFrame  *control_frame);

/* Connecting to the remote control */
void                          bonobo_control_frame_bind_to_control           (BonoboControlFrame  *control_frame,
									      Bonobo_Control       control,
									      CORBA_Environment   *opt_ev);

Bonobo_Control                bonobo_control_frame_get_control               (BonoboControlFrame  *control_frame);

Bonobo_UIContainer            bonobo_control_frame_get_ui_container          (BonoboControlFrame  *control_frame);

BonoboUIComponent            *bonobo_control_frame_get_popup_component       (BonoboControlFrame  *control_frame,
									      CORBA_Environment   *opt_ev);
    
G_END_DECLS

#endif /* _BONOBO_CONTROL_FRAME_H_ */
