/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/**
 * bonobo-widget.h: Bonobo Widget object.
 *
 * Authors:
 *   Nat Friedman    (nat@nat.org)
 *   Michael Meeks   (michael@ximian.com)
 *
 * Copyright 1999-2001 Ximian, Inc.
 */
#ifndef _BONOBO_WIDGET_H_
#define _BONOBO_WIDGET_H_

#include <glib/gmacros.h>
#include <gtk/gtkbin.h>
#include <bonobo/Bonobo.h>
#include <bonobo/bonobo-object.h>

G_BEGIN_DECLS
 
#define BONOBO_TYPE_WIDGET        (bonobo_widget_get_type ())
#define BONOBO_WIDGET(o)          (GTK_CHECK_CAST ((o), BONOBO_TYPE_WIDGET, BonoboWidget))
#define BONOBO_WIDGET_CLASS(k)    (GTK_CHECK_CLASS_CAST((k), BONOBO_TYPE_WIDGET, BonoboWidgetClass))
#define BONOBO_IS_WIDGET(o)       (GTK_CHECK_TYPE ((o), BONOBO_TYPE_WIDGET))
#define BONOBO_IS_WIDGET_CLASS(k) (GTK_CHECK_CLASS_TYPE ((k), BONOBO_TYPE_WIDGET))

struct _BonoboWidget;
typedef struct _BonoboWidget BonoboWidget;

#include <bonobo/bonobo-control-frame.h>

struct _BonoboWidgetPrivate;
typedef struct _BonoboWidgetPrivate BonoboWidgetPrivate;

struct _BonoboWidget {
	GtkBin		          bin;

	BonoboWidgetPrivate *priv;
};

typedef struct {
	GtkBinClass	 bin_class;

	gpointer dummy[4];
} BonoboWidgetClass;

GtkType             bonobo_widget_get_type                 (void) G_GNUC_CONST;
Bonobo_Unknown      bonobo_widget_get_objref               (BonoboWidget      *bw);

/*
 * BonoboWidget for Controls.
 */
GtkWidget          *bonobo_widget_new_control              (const char        *moniker,
							    Bonobo_UIContainer uic);
GtkWidget          *bonobo_widget_new_control_from_objref  (Bonobo_Control     control,
							    Bonobo_UIContainer uic);
BonoboControlFrame *bonobo_widget_get_control_frame        (BonoboWidget      *bw);

Bonobo_UIContainer  bonobo_widget_get_ui_container         (BonoboWidget      *bw);

typedef void      (*BonoboWidgetAsyncFn)                   (BonoboWidget       *widget,
							    CORBA_Environment  *ev,
							    gpointer            user_data);

GtkWidget          *bonobo_widget_new_control_async        (const char         *moniker,
							    Bonobo_UIContainer  uic,
							    BonoboWidgetAsyncFn fn,
							    gpointer            user_data);

/*
 * Constructors (for derivation and wrapping only)
 */
BonoboWidget       *bonobo_widget_construct_control_from_objref (BonoboWidget      *bw,
								 Bonobo_Control     control,
								 Bonobo_UIContainer uic,
								 CORBA_Environment *ev);
BonoboWidget       *bonobo_widget_construct_control             (BonoboWidget      *bw,
								 const char        *moniker,
								 Bonobo_UIContainer uic,
								 CORBA_Environment *ev);
/*
 * Setting properties on a Control's Property Bag,
 * These take Name, TypeCode, Value triplets.
 */
void                 bonobo_widget_set_property             (BonoboWidget       *control,
							     const char         *first_prop,
							     ...);
void                 bonobo_widget_get_property             (BonoboWidget       *control,
							     const char         *first_prop,
							     ...);

/* Compat */
#define bonobo_widget_get_uih(w) bonobo_widget_get_ui_container (w)

G_END_DECLS

#endif
