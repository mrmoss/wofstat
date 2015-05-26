/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
#ifndef _BONOBO_APPLICATION_H_
#define _BONOBO_APPLICATION_H_

#include <bonobo/bonobo-object.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_APPLICATION        (bonobo_application_get_type ())
#define BONOBO_APPLICATION(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o),\
				        BONOBO_TYPE_APPLICATION, BonoboApplication))
#define BONOBO_APPLICATION_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k),\
                                        BONOBO_TYPE_APPLICATION, BonoboApplicationClass))
#define BONOBO_IS_APPLICATION(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o),\
				        BONOBO_TYPE_APPLICATION))
#define BONOBO_IS_APPLICATION_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k),\
					BONOBO_TYPE_APPLICATION))
#define BONOBO_APPLICATION_GET_CLASS(o)(G_TYPE_INSTANCE_GET_CLASS ((o),\
				        BONOBO_TYPE_APPLICATION, BonoboApplicationClass))

typedef struct _BonoboApplication      BonoboApplication;
typedef struct _BonoboApplicationClass BonoboApplicationClass;

typedef void (*BonoboAppHookFunc) (BonoboApplication *app, gpointer data);


#include <bonobo/bonobo-app-client.h>


struct _BonoboApplication {
	BonoboObject  parent;
	GSList       *message_list;
	gchar        *name;
	GHashTable   *closure_hash;
};

struct _BonoboApplicationClass {
	BonoboObjectClass parent_class;

	GValue* (*message)      (BonoboApplication *app, const char *name, GValueArray *args);
	gint    (*new_instance) (BonoboApplication *app, gint argc, gchar *argv[]);

	gpointer unimplemented[8];

	POA_Bonobo_Application__epv epv;
};


GType                     bonobo_application_get_type            (void) G_GNUC_CONST;
BonoboApplication*        bonobo_application_new                 (const char         *name);
void                      bonobo_application_register_message    (BonoboApplication  *app,
								  const gchar        *name,
								  const gchar        *description,
								  GClosure           *opt_closure,
								  GType               return_type,
								  GType               first_arg_type,
								  ...);
void                      bonobo_application_register_message_va (BonoboApplication  *app,
								  const gchar        *name,
								  const gchar        *description,
								  GClosure           *opt_closure,
								  GType               return_type,
								  GType               first_arg_type,
								  va_list             var_args);
void                      bonobo_application_register_message_v  (BonoboApplication  *app,
								  const gchar        *name,
								  const gchar        *description,
								  GClosure           *opt_closure,
								  GType               return_type,
								  GType const         arg_types[]);
gchar *                   bonobo_application_create_serverinfo   (BonoboApplication  *app,
								  gchar const        *envp[]);
Bonobo_RegistrationResult bonobo_application_register_unique     (BonoboApplication  *app,
								  gchar const        *serverinfo,
								  BonoboAppClient   **client);
void                      bonobo_application_add_hook            (BonoboAppHookFunc   func,
								  gpointer            data);
void                      bonobo_application_remove_hook         (BonoboAppHookFunc   func,
								  gpointer            data);
gint                      bonobo_application_new_instance        (BonoboApplication  *app,
								  gint                argc,
								  gchar              *argv[]);

G_END_DECLS

#endif /* _BONOBO_APPLICATION_H_ */

