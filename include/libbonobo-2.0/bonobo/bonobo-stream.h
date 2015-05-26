/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * bonobo-stream.h: Stream manipulation, abstract class
 *
 * Author:
 *     Miguel de Icaza (miguel@gnu.org).
 *
 * Copyright 1999, 2000 Helix Code, Inc.
 */

/*
 * Deprecation Warning: this object should not be used
 * directly. Instead, use a moniker-based approach. For example,
 * bonobo_get_object("file:/tmp/foo.txt", "IDL:Bonobo/Stream:1.0", &ev)
 * will return a Bonobo_Stream for file /tmp/foo.txt, for *reading* only!
 * To obtain a Bonobo_Stream for *writing*, you have to:
 *   1. Get a Bonobo_Storage for the directory containing the file you
 * wish to write (see comment in bonobo-storage.h for how to do this)
 *   2. Use the openStream method of the Bonobo_Storage, with a
 * Bonobo_Storage_WRITE or Bonobo_Storage_CREATE flag. The 'path'
 * argument should be filename only, without directories. If the file
 * already exists, you may need to call store.erase(filename) first.
 */
#ifndef _BONOBO_STREAM_H_
#define _BONOBO_STREAM_H_

G_BEGIN_DECLS

#include <bonobo/bonobo-storage.h>

G_END_DECLS

#endif /* _BONOBO_STREAM_H_ */

