/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/**
 * bonobo-ui-toolbar.h
 *
 * Author:
 *    Ettore Perazzoli
 *
 * Copyright (C) 2000 Helix Code, Inc.
 */

#ifndef _BONOBO_UI_TOOLBAR_H_
#define _BONOBO_UI_TOOLBAR_H_

#include <glib/gmacros.h>
#include <gtk/gtkcontainer.h>
#include "bonobo-ui-toolbar-item.h"

#ifndef BONOBO_UI_DISABLE_DEPRECATED

G_BEGIN_DECLS

#define BONOBO_TYPE_UI_TOOLBAR            (bonobo_ui_toolbar_get_type ())
#define BONOBO_UI_TOOLBAR(obj)            (GTK_CHECK_CAST ((obj), BONOBO_TYPE_UI_TOOLBAR, BonoboUIToolbar))
#define BONOBO_UI_TOOLBAR_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), BONOBO_TYPE_UI_TOOLBAR, BonoboUIToolbarClass))
#define BONOBO_IS_UI_TOOLBAR(obj)         (GTK_CHECK_TYPE ((obj), BONOBO_TYPE_UI_TOOLBAR))
#define BONOBO_IS_UI_TOOLBAR_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), BONOBO_TYPE_UI_TOOLBAR))

typedef enum {
	BONOBO_UI_TOOLBAR_STYLE_PRIORITY_TEXT,
	BONOBO_UI_TOOLBAR_STYLE_ICONS_AND_TEXT,
	BONOBO_UI_TOOLBAR_STYLE_ICONS_ONLY,
	BONOBO_UI_TOOLBAR_STYLE_TEXT_ONLY
} BonoboUIToolbarStyle;

typedef struct _BonoboUIToolbarPrivate BonoboUIToolbarPrivate;

typedef struct {
	GtkContainer parent;

	BonoboUIToolbarPrivate *priv;
} BonoboUIToolbar;

typedef struct {
	GtkContainerClass parent_class;

	void (* set_orientation) (BonoboUIToolbar *toolbar,
				  GtkOrientation orientation);
	void (* style_changed)   (BonoboUIToolbar *toolbar);

	gpointer dummy[4];
} BonoboUIToolbarClass;

GtkType               bonobo_ui_toolbar_get_type         (void) G_GNUC_CONST;
void                  bonobo_ui_toolbar_construct        (BonoboUIToolbar      *toolbar);
GtkWidget            *bonobo_ui_toolbar_new              (void);

void                  bonobo_ui_toolbar_set_orientation  (BonoboUIToolbar      *toolbar,
							  GtkOrientation        orientation);
GtkOrientation        bonobo_ui_toolbar_get_orientation  (BonoboUIToolbar      *toolbar);

BonoboUIToolbarStyle  bonobo_ui_toolbar_get_style        (BonoboUIToolbar      *toolbar);

void                  bonobo_ui_toolbar_set_hv_styles    (BonoboUIToolbar      *toolbar,
							  BonoboUIToolbarStyle  hstyle,
							  BonoboUIToolbarStyle  vstyle);

void                  bonobo_ui_toolbar_insert           (BonoboUIToolbar      *toolbar,
							  BonoboUIToolbarItem  *item,
							  int                   position);

GtkTooltips          *bonobo_ui_toolbar_get_tooltips     (BonoboUIToolbar      *toolbar);
void                  bonobo_ui_toolbar_show_tooltips    (BonoboUIToolbar      *toolbar,
							  gboolean              show_tips);


GList                *bonobo_ui_toolbar_get_children     (BonoboUIToolbar      *toolbar);

G_END_DECLS

#endif

#endif /* _BONOBO_UI_TOOLBAR_H_ */

