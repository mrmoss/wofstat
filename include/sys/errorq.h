/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_ERRORQ_H
#define	_ERRORQ_H

#pragma ident	"@(#)errorq.h	1.2	04/03/17 SMI"

#include <sys/types.h>
#include <sys/time.h>
#include <sys/nvpair.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct errorq errorq_t;
typedef struct errorq_elem errorq_elem_t;
typedef void (*errorq_func_t)(void *, const void *, const errorq_elem_t *);

/*
 * Public flags for errorq_create(): bit range 0-15
 */
#define	ERRORQ_VITAL	0x0001	/* drain queue automatically on system reset */

/*
 * Public flags for errorq_dispatch():
 */
#define	ERRORQ_ASYNC	0	/* schedule async queue drain for caller */
#define	ERRORQ_SYNC	1	/* do not schedule drain; caller will drain */

#ifdef	_KERNEL

extern errorq_t *errorq_create(const char *, errorq_func_t, void *,
    ulong_t, size_t, uint_t, uint_t);

extern errorq_t *errorq_nvcreate(const char *, errorq_func_t, void *,
    ulong_t, size_t, uint_t, uint_t);

extern void errorq_destroy(errorq_t *);
extern void errorq_dispatch(errorq_t *, const void *, size_t, uint_t);
extern void errorq_drain(errorq_t *);
extern void errorq_init(void);
extern void errorq_panic(void);
extern errorq_elem_t *errorq_reserve(errorq_t *);
extern void errorq_commit(errorq_t *, errorq_elem_t *, uint_t);
extern void errorq_cancel(errorq_t *, errorq_elem_t *);
extern nvlist_t *errorq_elem_nvl(errorq_t *, const errorq_elem_t *);
extern nv_alloc_t *errorq_elem_nva(errorq_t *, const errorq_elem_t *);
extern void errorq_dump();

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _ERRORQ_H */
