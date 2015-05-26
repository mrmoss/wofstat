/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/**
 * Bonobo control object
 *
 * Author:
 *   Nat Friedman (nat@helixcode.com)
 *   Miguel de Icaza (miguel@helixcode.com)
 *
 * Copyright 1999, 2000 Helix Code, Inc.
 */
#ifndef _BONOBO_CONTROL_H_
#define _BONOBO_CONTROL_H_

#include <glib/gmacros.h>
#include <gtk/gtkobject.h>
#include <gtk/gtkwidget.h>
#include <gtk/gtkwindow.h>
#include <gtk/gtkmenu.h>

typedef struct _BonoboControl BonoboControl;

#include <bonobo/bonobo-plug.h>
#include <bonobo/bonobo-object.h>
#include <bonobo/bonobo-ui-container.h>
#include <bonobo/bonobo-ui-component.h>


G_BEGIN_DECLS
 
#define BONOBO_TYPE_CONTROL        (bonobo_control_get_type ())
#define BONOBO_CONTROL(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), BONOBO_TYPE_CONTROL, BonoboControl))
#define BONOBO_CONTROL_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST ((k), BONOBO_TYPE_CONTROL, BonoboControlClass))
#define BONOBO_IS_CONTROL(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), BONOBO_TYPE_CONTROL))
#define BONOBO_IS_CONTROL_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BONOBO_TYPE_CONTROL))

typedef struct _BonoboControlPrivate BonoboControlPrivate;

struct _BonoboControl {
	BonoboObject base;

	BonoboControlPrivate *priv;
};

typedef struct {
	BonoboObjectClass      parent_class;

	POA_Bonobo_Control__epv epv;

	gpointer dummy[2];

	/* Signals. */
	void (*plug_created)   (BonoboControl *control);
	void (*disconnected)   (BonoboControl *control);
	void (*set_frame)      (BonoboControl *control);
	void (*activate)       (BonoboControl *control, gboolean state);
} BonoboControlClass;

/* The main API */
BonoboControl              *bonobo_control_new                     (GtkWidget     *widget);
GtkWidget                  *bonobo_control_get_widget              (BonoboControl *control);
void                        bonobo_control_set_automerge           (BonoboControl *control,
								    gboolean       automerge);
gboolean                    bonobo_control_get_automerge           (BonoboControl *control);

void                        bonobo_control_set_property            (BonoboControl       *control,
								    CORBA_Environment   *opt_ev,
								    const char          *first_prop,
								    ...);
void                        bonobo_control_get_property            (BonoboControl       *control,
								    CORBA_Environment   *opt_ev,
								    const char          *first_prop,
								    ...);

void                        bonobo_control_set_transient_for       (BonoboControl       *control,
								    GtkWindow           *window,
								    CORBA_Environment   *opt_ev);
void                        bonobo_control_unset_transient_for     (BonoboControl       *control,
								    GtkWindow           *window,
								    CORBA_Environment   *opt_ev);

/* "Internal" stuff */
GType                       bonobo_control_get_type                (void) G_GNUC_CONST;
BonoboControl              *bonobo_control_construct               (BonoboControl       *control,
								    GtkWidget           *widget);
BonoboPlug                 *bonobo_control_get_plug                (BonoboControl       *control);
BonoboUIComponent          *bonobo_control_get_ui_component        (BonoboControl       *control);
void                        bonobo_control_set_ui_component        (BonoboControl       *control,
								    BonoboUIComponent   *component);
Bonobo_UIContainer          bonobo_control_get_remote_ui_container (BonoboControl       *control,
								    CORBA_Environment   *opt_ev);
void                        bonobo_control_set_control_frame       (BonoboControl       *control,
								    Bonobo_ControlFrame  control_frame,
								    CORBA_Environment   *opt_ev);
Bonobo_ControlFrame         bonobo_control_get_control_frame       (BonoboControl       *control,
								    CORBA_Environment   *opt_ev);
void                        bonobo_control_set_properties          (BonoboControl       *control,
								    Bonobo_PropertyBag   pb,
								    CORBA_Environment   *opt_ev);
Bonobo_PropertyBag          bonobo_control_get_properties          (BonoboControl       *control);
Bonobo_PropertyBag          bonobo_control_get_ambient_properties  (BonoboControl       *control,
								    CORBA_Environment   *opt_ev);
void                        bonobo_control_activate_notify         (BonoboControl       *control,
								    gboolean             activated,
								    CORBA_Environment   *opt_ev);
Bonobo_Gdk_WindowId         bonobo_control_window_id_from_x11      (guint32              x11_id);
guint32                     bonobo_control_x11_from_window_id      (const CORBA_char    *id);
#define                     bonobo_control_windowid_from_x11(a) \
			    bonobo_control_window_id_from_x11(a)

/* Popup API */
#define                     BONOBO_CONTROL_POPUP_BUTTON1           "/popups/button1"
#define                     BONOBO_CONTROL_POPUP_BUTTON2           "/popups/button2"
#define                     BONOBO_CONTROL_POPUP_BUTTON3           "/popups/button3"

BonoboUIContainer          *bonobo_control_get_popup_ui_container  (BonoboControl       *control);
BonoboUIComponent          *bonobo_control_get_popup_ui_component  (BonoboControl       *control);
void                        bonobo_control_set_popup_ui_container  (BonoboControl       *control,
								    BonoboUIContainer   *ui_container);
gboolean                    bonobo_control_do_popup                (BonoboControl       *control,
								    guint                button,
								    guint32              activate_time);
gboolean                    bonobo_control_do_popup_full           (BonoboControl       *control,
								    GtkWidget           *parent_menu_shell,
								    GtkWidget           *parent_menu_item,
								    GtkMenuPositionFunc  func,
								    gpointer             data,
								    guint                button,
								    guint32              activate_time);
gboolean                    bonobo_control_do_popup_path           (BonoboControl       *control,
								    GtkWidget           *parent_menu_shell,
								    GtkWidget           *parent_menu_item,
								    GtkMenuPositionFunc  func,
								    gpointer             data,
								    guint                button,
								    const char          *popup_path,
								    guint32              activate_time);

/* Simple lifecycle helpers - using the 'disconnected' signal */
typedef void (*BonoboControlLifeCallback) (void);
void bonobo_control_life_set_purge    (long                      ms);
void bonobo_control_life_set_callback (BonoboControlLifeCallback all_dead_callback);
void bonobo_control_life_instrument   (BonoboControl            *control);
int  bonobo_control_life_get_count    (void);

G_END_DECLS

#endif /* _BONOBO_CONTROL_H_ */
