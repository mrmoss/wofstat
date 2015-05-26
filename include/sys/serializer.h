/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_SERIALIZER_H
#define	_SYS_SERIALIZER_H

#pragma ident	"@(#)serializer.h	1.1	04/08/26 SMI"

/*
 * This file is used for building Solaris kernel. It does not provide any public
 * interface, its content is unstable and subject to change without notice at
 * any time.
 */

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef _KERNEL

#include <sys/stream.h>
#include <sys/kmem.h>

struct serializer_s;
typedef struct serializer_s serializer_t;

typedef void (srproc_t)(mblk_t *, void *);

extern void serializer_init(void);
extern serializer_t *serializer_create(int);
extern void serializer_enter(serializer_t *, srproc_t, mblk_t *, void *);
extern void serializer_wait(serializer_t *);
extern void serializer_destroy(serializer_t *);

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SERIALIZER_H */
