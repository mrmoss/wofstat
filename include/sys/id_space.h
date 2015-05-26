/*
 * Copyright (c) 2004, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_ID_SPACE_H
#define	_ID_SPACE_H

#pragma ident	"@(#)id_space.h	1.7	11/03/04 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/param.h>
#include <sys/types.h>
#include <sys/mutex.h>
#include <sys/vmem.h>

#ifdef _KERNEL

typedef vmem_t id_space_t;

id_space_t *id_space_create(const char *, id_t, id_t);
void id_space_destroy(id_space_t *);
void id_space_extend(id_space_t *, id_t, id_t);
id_t id_alloc(id_space_t *);
id_t id_alloc_nosleep(id_space_t *);
id_t id_allocff(id_space_t *);
id_t id_allocff_nosleep(id_space_t *);
void id_free(id_space_t *, id_t);

#endif /* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _ID_SPACE_H */
