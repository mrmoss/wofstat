/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_TOPO_LIST_H
#define	_TOPO_LIST_H

#pragma ident	"@(#)topo_list.h	1.1	06/03/19 SMI"

#include <fm/libtopo.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct topo_list {
	struct topo_list *l_prev;
	struct topo_list *l_next;
} topo_list_t;

#define	topo_list_prev(elem)	((void *)(((topo_list_t *)(elem))->l_prev))
#define	topo_list_next(elem)	((void *)(((topo_list_t *)(elem))->l_next))

extern void topo_list_append(topo_list_t *, void *);
extern void topo_list_prepend(topo_list_t *, void *);
extern void topo_list_insert_before(topo_list_t *, void *, void *);
extern void topo_list_insert_after(topo_list_t *, void *, void *);
extern void topo_list_delete(topo_list_t *, void *);

/* Helpers for child/sibling lists */
extern tnode_t *topo_child_first(tnode_t *);
extern tnode_t *topo_child_next(tnode_t *, tnode_t *);
extern topo_list_t *topo_sibling_list(tnode_t *);

#ifdef	__cplusplus
}
#endif

#endif	/* _TOPO_LIST_H */
