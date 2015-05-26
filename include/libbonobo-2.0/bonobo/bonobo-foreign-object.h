/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
#ifndef _BONOBO_FOREIGN_OBJECT_H_
#define _BONOBO_FOREIGN_OBJECT_H_

#include <bonobo/bonobo-object.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_FOREIGN_OBJECT         (bonobo_foreign_object_get_type ())

#define BONOBO_FOREIGN_OBJECT(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o),\
                                            BONOBO_TYPE_FOREIGN_OBJECT,\
                                            BonoboForeignObject))

#define BONOBO_FOREIGN_OBJECT_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k),\
                                            BONOBO_TYPE_FOREIGN_OBJECT,\
                                            BonoboForeignObjectClass))

#define BONOBO_IS_FOREIGN_OBJECT(o)    	   (G_TYPE_CHECK_INSTANCE_TYPE ((o),\
                                            BONOBO_TYPE_FOREIGN_OBJECT))

#define BONOBO_IS_FOREIGN_OBJECT_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k),\
                                            BONOBO_TYPE_FOREIGN_OBJECT))

#define BONOBO_FOREIGN_OBJECT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o),\
					    BONOBO_TYPE_FOREIGN_OBJECT,\
                                            BonoboForeignObjectClass))


typedef struct _BonoboForeignObject BonoboForeignObject;


struct _BonoboForeignObject {
	BonoboObject base;
};

typedef struct {
	BonoboObjectClass parent_class;
} BonoboForeignObjectClass;

GType         bonobo_foreign_object_get_type (void) G_GNUC_CONST;
BonoboObject* bonobo_foreign_object_new      (CORBA_Object corba_objref);

G_END_DECLS

#endif
