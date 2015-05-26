/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * gnome-storage.h: Storage manipulation.
 *
 * Author:
 *   Miguel de Icaza (miguel@gnu.org).
 *
 * Copyright 1999 Helix Code, Inc.
 */

/*
 * Deprecation Warning: this object should not be used
 * directly. Instead, use a moniker-based approach. For example,
 * bonobo_get_object("file:/tmp", "IDL:Bonobo/Storate:1.0", &ev) will
 * return a Bonobo_Storage for directory /tmp.
 */
#ifndef _BONOBO_STORAGE_H_
#define _BONOBO_STORAGE_H_

#include <bonobo/bonobo-object.h>

G_BEGIN_DECLS

#ifndef BONOBO_DISABLE_DEPRECATED

/* For backwards compatibility */
#define BonoboStream BonoboObject
#define BONOBO_STREAM(o)       ((BonoboStream *)(o))
#define BONOBO_STREAM_CLASS(k) ((BonoboObjectClass *)(k))

#define BonoboStorage BonoboObject
#define BONOBO_STORAGE(o)          ((BonoboStorage *)(o))
#define BONOBO_STORAGE_CLASS(k)    ((BonoboObjectClass *)(k))

#endif /* BONOBO_DISABLE_DEPRECATED */


/* The 1 useful impl. in here */
void bonobo_storage_copy_to (Bonobo_Storage     src,
			     Bonobo_Storage     dest,
			     CORBA_Environment *ev);

G_END_DECLS

#endif /* _BONOBO_STORAGE_H_ */

