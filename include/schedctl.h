/*
 * Copyright 1996-2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SCHEDCTL_H
#define	_SCHEDCTL_H

#pragma ident	"@(#)schedctl.h	1.2	03/05/17 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/schedctl.h>

typedef sc_public_t schedctl_t;

extern void yield(void);

#define	schedctl_start(p)					\
		(void) (((p) == NULL)? 0 :			\
		((((schedctl_t *)(p))->sc_nopreempt = 1), 0))

#define	schedctl_stop(p)					\
		(void) (((p) == NULL)? 0 :			\
		((((schedctl_t *)(p))->sc_nopreempt = 0),	\
		(((schedctl_t *)(p))->sc_yield? (yield(), 0) : 0)))

/*
 * libsched API
 */
#if	defined(__STDC__)
schedctl_t	*schedctl_init(void);
schedctl_t	*schedctl_lookup(void);
void		schedctl_exit(void);
#else
schedctl_t	*schedctl_init();
schedctl_t	*schedctl_lookup();
void		schedctl_exit();
#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#endif	/* _SCHEDCTL_H */
