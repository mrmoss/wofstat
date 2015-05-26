/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
#ifndef __BONOBO_APP_CLIENT_H__
#define __BONOBO_APP_CLIENT_H__

#include <glib-object.h>
#include <bonobo/Bonobo.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_APP_CLIENT            (bonobo_app_client_get_type ())
#define BONOBO_APP_CLIENT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj),\
                                           BONOBO_TYPE_APP_CLIENT, BonoboAppClient))
#define BONOBO_APP_CLIENT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),\
                                           BONOBO_TYPE_APP_CLIENT, BonoboAppClientClass))
#define BONOBO_IS_APP_CLIENT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj),\
                                           BONOBO_TYPE_APP_CLIENT))
#define BONOBO_IS_APP_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),\
                                           BONOBO_TYPE_APP_CLIENT))
#define BONOBO_APP_CLIENT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),\
                                           BONOBO_TYPE_APP_CLIENT, BonoboAppClientClass))

typedef struct _BonoboAppClient	       BonoboAppClient;
typedef struct _BonoboAppClientClass   BonoboAppClientClass;
typedef struct _BonoboAppClientMsgDesc BonoboAppClientMsgDesc;


struct _BonoboAppClientMsgDesc {
	gchar *name;
	GType  return_type;
	GType *types;		/* G_TYPE_NONE-terminated array */
	gchar *description;
};


struct _BonoboAppClient
{
	GObject                 parent_instance;
	  /*< private >*/
	Bonobo_Application      app_server;
	BonoboAppClientMsgDesc *msgdescs;
};

struct _BonoboAppClientClass
{
	GObjectClass parent_class;
  
};


GType	         bonobo_app_client_get_type        (void) G_GNUC_CONST;
BonoboAppClient* bonobo_app_client_new             (Bonobo_Application  app_server);
GValue *         bonobo_app_client_msg_send_argv   (BonoboAppClient    *app_client,
						    const char         *message,
						    const GValue       *argv[],
						    CORBA_Environment  *opt_env);
GValue*          bonobo_app_client_msg_send_valist (BonoboAppClient    *app_client,
						    const char         *message,
						    CORBA_Environment  *opt_env,
						    GType               first_arg_type,
						    va_list             var_args);
GValue*          bonobo_app_client_msg_send        (BonoboAppClient    *app_client,
						    const char         *message,
						    CORBA_Environment  *opt_env,
						    GType               first_arg_type,
						    ...);
gint             bonobo_app_client_new_instance    (BonoboAppClient    *app_client,
						    int                 argc,
						    char               *argv[],
						    CORBA_Environment  *opt_env);
BonoboAppClientMsgDesc const *
                 bonobo_app_client_msg_list        (BonoboAppClient    *app_client);

G_END_DECLS

#endif /* __BONOBO_APP_CLIENT_H__ */
