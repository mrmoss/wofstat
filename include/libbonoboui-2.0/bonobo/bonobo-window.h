/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * bonobo-win.c: The Bonobo Window implementation.
 *
 * Author:
 *	Michael Meeks (michael@helixcode.com)
 *
 * Copyright 2000 Helix Code, Inc.
 */
#ifndef _BONOBO_WINDOW_H_
#define _BONOBO_WINDOW_H_

#include <gtk/gtkmenu.h>
#include <gtk/gtkwindow.h>
#include <bonobo/bonobo-object.h>
#include <bonobo/bonobo-ui-engine.h>
#include <bonobo/bonobo-ui-container.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_WINDOW        (bonobo_window_get_type ())
#define BONOBO_WINDOW(o)          (GTK_CHECK_CAST ((o), BONOBO_TYPE_WINDOW, BonoboWindow))
#define BONOBO_WINDOW_CLASS(k)    (GTK_CHECK_CLASS_CAST((k), BONOBO_TYPE_WINDOW, BonoboWindowClass))
#define BONOBO_IS_WINDOW(o)       (GTK_CHECK_TYPE ((o), BONOBO_TYPE_WINDOW))
#define BONOBO_IS_WINDOW_CLASS(k) (GTK_CHECK_CLASS_TYPE ((k), BONOBO_TYPE_WINDOW))

typedef struct _BonoboWindowPrivate BonoboWindowPrivate;
typedef struct _BonoboWindow        BonoboWindow;

struct _BonoboWindow {
	GtkWindow             parent;
	
	BonoboWindowPrivate  *priv;
};

typedef struct {
	GtkWindowClass    parent_class;

	gpointer dummy[4];
} BonoboWindowClass;

GtkType              bonobo_window_get_type                       (void) G_GNUC_CONST;

GtkWidget           *bonobo_window_construct                      (BonoboWindow      *win,
								   BonoboUIContainer *ui_container,
								   const char        *win_name,
								   const char        *title);

GtkWidget           *bonobo_window_new                            (const char        *win_name,
								   const char        *title);

void                 bonobo_window_set_contents                   (BonoboWindow      *win,
								   GtkWidget         *contents);
GtkWidget           *bonobo_window_get_contents                   (BonoboWindow      *win);


BonoboUIEngine      *bonobo_window_get_ui_engine                  (BonoboWindow      *win);
BonoboUIContainer   *bonobo_window_get_ui_container               (BonoboWindow      *win);

void                 bonobo_window_set_name                       (BonoboWindow      *win,
								   const char        *win_name);

char                *bonobo_window_get_name                       (BonoboWindow      *win);

GtkAccelGroup       *bonobo_window_get_accel_group                (BonoboWindow      *win);

void                 bonobo_window_add_popup                      (BonoboWindow      *win,
								   GtkMenu           *popup,
								   const char        *path);

/*
 * NB. popups are automaticaly removed on destroy, you probably don't
 * want to use this.
 */
void                 bonobo_window_remove_popup                   (BonoboWindow      *win,
								   const char        *path);

G_END_DECLS

#endif /* _BONOBO_WINDOW_H_ */
