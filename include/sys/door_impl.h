/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_DOOR_IMPL_H
#define	_SYS_DOOR_IMPL_H

#pragma ident	"@(#)door_impl.h	1.1	04/05/15 SMI"

/*
 * Common definitions for <sys/door.h> and <sys/proc.h>.
 */

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/condvar.h>

typedef struct door_pool {
	struct _kthread *dp_threads;
	kcondvar_t	dp_cv;
} door_pool_t;

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DOOR_IMPL_H */
