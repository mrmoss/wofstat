/*
 * COPYRIGHT NOTICE
 * Copyright (c) 1990, 1991, 1992, 1993 Open Software Foundation, Inc.
 * ALL RIGHTS RESERVED (MOTIF).  See the file named COPYRIGHT.MOTIF
 * for the full copyright text.
 * 
 */
/*
 * HISTORY
 */
/*   $XConsortium: MrmosI.h /main/6 1995/07/14 10:42:09 drk $ */
#ifndef _MrmosI_h
#define _MrmosI_h

#ifdef __cplusplus
extern "C" {
#endif

/********    Private Function Declarations    ********/

extern void _MrmOSHostFloatToIEEE(float *val);
extern void _MrmOSHostDoubleToIEEE(double *val);
extern void _MrmOSIEEEFloatToHost(float *val);
extern void _MrmOSIEEEDoubleToHost(double *val);
extern String _MrmOSSetLocale(String locale);

/********    End Private Function Declarations    ********/

#ifdef __cplusplus
}  /* Close scope of 'extern "C"' declaration which encloses file. */
#endif

#endif /* _MrmosI_h */
/* DON'T ADD ANYTHING AFTER THIS #endif */
