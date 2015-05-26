/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_LIST_IMPL_H
#define	_SYS_LIST_IMPL_H

#pragma ident	"@(#)list_impl.h	1.1	03/02/05 SMI"

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

struct list_node {
	struct list_node *list_next;
	struct list_node *list_prev;
};

struct list {
	size_t	list_size;
	size_t	list_offset;
	struct list_node list_head;
};

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_LIST_IMPL_H */
