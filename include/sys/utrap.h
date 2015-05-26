/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _UTRAP_H
#define	_UTRAP_H

#pragma ident	"@(#)utrap.h	1.1	03/04/21 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * This file contains definitions for user-level traps.
 */

#ifndef _ASM

/*
 * This architecture does not support install_utrap() (yet).
 */

#define	UTH_NOCHANGE ((utrap_handler_t)(-1))
#define	UTRAP_UTH_NOCHANGE	UTH_NOCHANGE

typedef int utrap_entry_t;
typedef void *utrap_handler_t;	/* user trap handler entry point */

#endif /* ASM */

#ifdef	__cplusplus
}
#endif

#endif	/* _UTRAP_H */
