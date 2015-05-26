/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/**
 * bonobo-selector-widget.h: Bonobo Component Selector
 *
 * Author:
 *   Michael Meeks (michael@helixcode.com)
 *
 * Copyright  2000 Helix Code, Inc.
 */
#ifndef BONOBO_SELECTOR_WIDGET_H
#define BONOBO_SELECTOR_WIDGET_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_SELECTOR_WIDGET             (bonobo_selector_widget_get_type ())
#define BONOBO_SELECTOR_WIDGET(obj)		GTK_CHECK_CAST(obj,  bonobo_selector_widget_get_type (), BonoboSelectorWidget)
#define BONOBO_SELECTOR_WIDGET_CLASS(klass)	GTK_CHECK_CLASS_CAST (klass, bonobo_selector_widget_get_type (), BonoboSelectorWidgetClass)
#define BONOBO_IS_SELECTOR_WIDGET(obj)		GTK_CHECK_TYPE (obj, bonobo_selector_widget_get_type ())

typedef struct _BonoboSelectorWidgetPrivate BonoboSelectorWidgetPrivate;

typedef struct {
	GtkVBox parent;

	BonoboSelectorWidgetPrivate *priv;
} BonoboSelectorWidget;

typedef struct {
	GtkVBoxClass parent_class;

	/* Virtual methods */
	gchar *(* get_id)          (BonoboSelectorWidget *sel);
	gchar *(* get_name)        (BonoboSelectorWidget *sel);
	gchar *(* get_description) (BonoboSelectorWidget *sel);
	void   (* set_interfaces)  (BonoboSelectorWidget *sel,
				    const gchar         **interfaces);

	/* User select */
	void   (* final_select)    (BonoboSelectorWidget *sel);

	gpointer dummy[2];
} BonoboSelectorWidgetClass;

GtkType	   bonobo_selector_widget_get_type (void) G_GNUC_CONST;

GtkWidget *bonobo_selector_widget_new      (void);

void	   bonobo_selector_widget_set_interfaces  (BonoboSelectorWidget *sel,
						   const gchar **interfaces_required);

gchar	  *bonobo_selector_widget_get_id          (BonoboSelectorWidget *sel);
gchar     *bonobo_selector_widget_get_name        (BonoboSelectorWidget *sel);
gchar     *bonobo_selector_widget_get_description (BonoboSelectorWidget *sel);


G_END_DECLS

#endif /* BONOBO_SELECTOR_H */

