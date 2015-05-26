/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_SIGNAL_TYPES_H
#define	_MLIB_SIGNAL_TYPES_H

#pragma ident	"@(#)mlib_signal_types.h	9.1	05/11/23 SMI"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	MLIB_DTW_ITAKURA = 0
} mlib_dtw_local;

typedef enum
{
	MLIB_DTW_NONE = 0
} mlib_dtw_slope;

typedef enum
{
	MLIB_DTW_L1NORM = 0,
	MLIB_DTW_L2NORM = 1
} mlib_dtw_norm;

#ifdef __cplusplus
}
#endif

#endif /* _MLIB_SIGNAL_TYPES_H */
