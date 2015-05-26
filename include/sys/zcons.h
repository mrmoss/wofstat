/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_ZCONS_H
#define	_SYS_ZCONS_H

#pragma ident	"@(#)zcons.h	1.1	03/12/09 SMI"

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Minor node name of the global zone side (often called the "master" side)
 * of the zcons driver.
 *
 */
#define	ZCONS_MASTER_NAME	"masterconsole"

/*
 * Minor node name of the non-global zone side (often called the "slave"
 * side) of the zcons driver.  We name it "zoneconsole" since that nameo
 * will show up in 'ps' output, and will make some sense to the global zone
 * user.  Inside the zone, it will simply show up as "console" due to the
 * links we create.
 */
#define	ZCONS_SLAVE_NAME	"zoneconsole"

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_ZCONS_H */
