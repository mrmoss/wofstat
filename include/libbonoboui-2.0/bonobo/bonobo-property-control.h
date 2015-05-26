/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/**
 * bonobo-property-control.h: Property control implementation.
 *
 * Author:
 *      Iain Holmes  <iain@helixcode.com>
 *
 * Copyright 2000, Helix Code, Inc.
 */
#ifndef _BONOBO_PROPERTY_CONTROL_H_
#define _BONOBO_PROPERTY_CONTROL_H_

#include <bonobo/bonobo-control.h>
#include <bonobo/bonobo-event-source.h>

G_BEGIN_DECLS

typedef struct _BonoboPropertyControl        BonoboPropertyControl;
typedef struct _BonoboPropertyControlPrivate BonoboPropertyControlPrivate;

#define BONOBO_PROPERTY_CONTROL_CHANGED "Bonobo::PropertyControl_changed"

#define BONOBO_TYPE_PROPERTY_CONTROL        (bonobo_property_control_get_type ())
#define BONOBO_PROPERTY_CONTROL(o)          (GTK_CHECK_CAST ((o), BONOBO_TYPE_PROPERTY_CONTROL, BonoboPropertyControl))
#define BONOBO_PROPERTY_CONTROL_CLASS(k)    (GTK_CHECK_CLASS_CAST((k), BONOBO_TYPE_PROPERTY_CONTROL, BonoboPropertyControlClass))
#define BONOBO_IS_PROPERTY_CONTROL(o)       (GTK_CHECK_TYPE ((o), BONOBO_TYPE_PROPERTY_CONTROL))
#define BONOBO_IS_PROPERTY_CONTROL_CLASS(k) (GTK_CHECK_CLASS_TYPE ((k), BONOBO_TYPE_PROPERTY_CONTROL))

typedef BonoboControl *(* BonoboPropertyControlGetControlFn) (BonoboPropertyControl *control,
							      int page_number,
							      void *closure);

struct _BonoboPropertyControl {
        BonoboObject		object;

	BonoboPropertyControlPrivate *priv;
};

typedef struct {
	BonoboObjectClass parent_class;

	POA_Bonobo_PropertyControl__epv epv;

	gpointer dummy[4];

	void (* action) (BonoboPropertyControl *property_control, 
			 Bonobo_PropertyControl_Action action);
} BonoboPropertyControlClass;

GtkType bonobo_property_control_get_type (void) G_GNUC_CONST;

BonoboPropertyControl *bonobo_property_control_construct (BonoboPropertyControl *property_control,
							  BonoboEventSource     *event_source,
							  BonoboPropertyControlGetControlFn get_fn,
							  int                    num_pages,
							  void                  *closure);
BonoboPropertyControl *bonobo_property_control_new_full  (BonoboPropertyControlGetControlFn get_fn,
							  int                    num_pages,
							  BonoboEventSource     *event_source,
							  void                  *closure);
BonoboPropertyControl *bonobo_property_control_new       (BonoboPropertyControlGetControlFn get_fn,
							  int                    num_pages,
							  void                  *closure);
void                   bonobo_property_control_changed   (BonoboPropertyControl *property_control,
							  CORBA_Environment     *opt_ev);
BonoboEventSource *bonobo_property_control_get_event_source (BonoboPropertyControl *property_control);

G_END_DECLS

#endif /* _BONOBO_PROPERTY_CONTROL_H_ */

