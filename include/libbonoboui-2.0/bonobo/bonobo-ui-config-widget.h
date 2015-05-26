/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/**
 * bonobo-ui-config-widget.h: Bonobo Component UIConfig
 *
 * Author:
 *   Michael Meeks (michael@helixcode.com)
 *
 * Copyright  2000 Helix Code, Inc.
 */
#ifndef BONOBO_UI_CONFIG_WIDGET_H
#define BONOBO_UI_CONFIG_WIDGET_H

/* Should be purely internal */
#ifndef BONOBO_UI_DISABLE_DEPRECATED

#include <gtk/gtk.h>
#include <bonobo/bonobo-ui-engine.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_UI_CONFIG_WIDGET            (bonobo_ui_config_widget_get_type ())
#define BONOBO_UI_CONFIG_WIDGET(obj)		GTK_CHECK_CAST(obj,  bonobo_ui_config_widget_get_type (), BonoboUIConfigWidget)
#define BONOBO_UI_CONFIG_WIDGET_CLASS(klass)	GTK_CHECK_CLASS_CAST (klass, bonobo_ui_config_widget_get_type (), BonoboUIConfigWidgetClass)
#define BONOBO_IS_UI_CONFIG_WIDGET(obj)		GTK_CHECK_TYPE (obj, bonobo_ui_config_widget_get_type ())

typedef struct _BonoboUIConfigWidgetPrivate BonoboUIConfigWidgetPrivate;

typedef struct {
	GtkVBox parent;

	BonoboUIEngine *engine;

	BonoboUIConfigWidgetPrivate *priv;
} BonoboUIConfigWidget;

typedef struct {
	GtkVBoxClass parent_class;

	gpointer dummy[2];
} BonoboUIConfigWidgetClass;

GtkType	   bonobo_ui_config_widget_get_type  (void) G_GNUC_CONST;

GtkWidget *bonobo_ui_config_widget_construct (BonoboUIConfigWidget *config,
					      BonoboUIEngine       *engine,
					      GtkAccelGroup        *accel_group);

GtkWidget *bonobo_ui_config_widget_new       (BonoboUIEngine       *engine,
					      GtkAccelGroup        *accel_group);

G_END_DECLS

#endif /* BONOBO_UI_DISABLE_DEPRECATED */

#endif /* BONOBO_UI_CONFIG_WIDGET_H */
