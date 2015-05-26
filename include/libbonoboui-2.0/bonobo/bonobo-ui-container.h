/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * bonobo-ui-container.h: The server side CORBA impl. for BonoboWindow.
 *
 * Author:
 *	Michael Meeks (michael@helixcode.com)
 *
 * Copyright 2000 Helix Code, Inc.
 */
#ifndef _BONOBO_UI_CONTAINER_H_
#define _BONOBO_UI_CONTAINER_H_

#include <glib/gmacros.h>

G_BEGIN_DECLS

typedef struct _BonoboUIContainer BonoboUIContainer;

#include <bonobo/bonobo-ui-engine.h>

#define BONOBO_TYPE_UI_CONTAINER        (bonobo_ui_container_get_type ())
#define BONOBO_UI_CONTAINER(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), BONOBO_TYPE_UI_CONTAINER, BonoboUIContainer))
#define BONOBO_UI_CONTAINER_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST ((k), BONOBO_TYPE_UI_CONTAINER, BonoboUIContainerClass))
#define BONOBO_IS_UI_CONTAINER(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), BONOBO_TYPE_UI_CONTAINER))
#define BONOBO_IS_UI_CONTAINER_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BONOBO_TYPE_UI_CONTAINER))

typedef struct _BonoboUIContainerPrivate BonoboUIContainerPrivate;

struct _BonoboUIContainer {
	BonoboObject base;

	BonoboUIContainerPrivate *priv;
};

typedef struct {
	BonoboObjectClass parent;

	POA_Bonobo_UIContainer__epv epv;

	gpointer dummy[2];
} BonoboUIContainerClass;

GType                        bonobo_ui_container_get_type            (void) G_GNUC_CONST;
BonoboUIContainer           *bonobo_ui_container_new                 (void);

void                         bonobo_ui_container_set_engine          (BonoboUIContainer  *container,
								      BonoboUIEngine     *engine);
BonoboUIEngine              *bonobo_ui_container_get_engine          (BonoboUIContainer  *container);

G_END_DECLS

#endif /* _BONOBO_UI_CONTAINER_H_ */
