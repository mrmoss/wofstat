/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_PORT_H
#define	_PORT_H

#pragma ident	"@(#)port.h	1.1	03/10/16 SMI"

#include <sys/types.h>
#include <sys/port.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * ports API
 */

int	port_create(void);
int	port_associate(int, int, uintptr_t, int, void *);
int	port_dissociate(int, int, uintptr_t);
int	port_send(int, int, void *);
int	port_sendn(int [], int [], uint_t, int, void *);
int	port_get(int, port_event_t *, struct timespec *);
int	port_getn(int, port_event_t [], uint_t, uint_t *, struct timespec *);
int	port_alert(int, int, int, void *);

#ifdef	__cplusplus
}
#endif

#endif	/* _PORT_H */
