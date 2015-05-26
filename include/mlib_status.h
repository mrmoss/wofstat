/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_STATUS_H
#define	_MLIB_STATUS_H

#pragma ident	"@(#)mlib_status.h	9.1	05/11/23 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum
{
	MLIB_SUCCESS = 0,
	MLIB_FAILURE = 1,
	MLIB_NULLPOINTER = 2,
	MLIB_OUTOFRANGE = 3
} mlib_status;

#ifdef	__cplusplus
}
#endif

#endif /* _MLIB_STATUS_H */
