/*
 * Copyright © 2001, 2002, Sun Microsystems, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Sun Microsystems, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * This software is provided "AS IS," without a warranty of any kind.
 *
 * ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED.
 * SUN AND ITS LICENSORS SHALL NOT BE LIABLE FOR ANY DAMAGES OR
 * LIABILITIES  SUFFERED BY LICENSEE AS A RESULT OF  OR RELATING TO USE,
 * MODIFICATION OR DISTRIBUTION OF THE SOFTWARE OR ITS DERIVATIVES.
 * IN NO EVENT WILL SUN OR ITS LICENSORS BE LIABLE FOR ANY LOST REVENUE,
 * PROFIT OR DATA, OR FOR DIRECT, INDIRECT, SPECIAL, CONSEQUENTIAL,
 * INCIDENTAL OR PUNITIVE DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE
 * THEORY OF LIABILITY, ARISING OUT OF THE USE OF OR INABILITY TO USE
 * SOFTWARE, EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 */

/* @(#)Xst_space.h	1.11 04/07/27 SMI */

#ifndef _XSTSPACE_H
#define _XSTSPACE_H

#include "Xst_typedef.h"
#include "Xst_env.h"
#include "Xst_line.h"

/******************************** XSTSpace General Defines **************************/

#define XST_USER_TO_DEVICE	1
#define XST_DEVICE_TO_USER	2

/****************************** XSTSpace Function Prototypes ************************/

/** @defgroup Space XSTConvert functions
 * @{
 */

/**
 * Converts a user space coordinate into a device space coordinate by applying the 
 * affine transform held in the gc to the specified coordinate.
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param iFunc                 direction to perform transformation
 * @param iX			user space X value
 * @param iY			user space Y value
 * @param oX			returned device space X value
 * @param oY			returned device space Y value
 *
 * @return none 
 */
void XSTTransformSpace(Display *dpy, 
		       GC       gc, 
		       int      iFunc,
		       double   iX, 
		       double   iY,
		       double  *oX, 
		       double  *oY);


/**
 * Converts a device space coordinate into a user space distance
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param iX			device space X value
 * @param iY			device space Y value
 *
 * @return distance value
 */
double XSTTransformAndMeasure(Display *dpy, 
			      GC       gc, 
			      double   iX, 
			      double   iY);


/**
 * Gets the smallest rectangular that contains the supplied trapezoid. This function
 * allocates memory for the returned XSTRectangle structure. It is the callers 
 * responsiblity to free up this memory using XSTFree().
 *
 * @param iTrap			trapezoid
 *
 * @return XSTRectangle structure
 */
XSTRectangle *XSTGetBoundingRectangle(XSTTrapezoid *iTrap);


/**
 * Converts a user space trapezoid into a device space trapezoid by applying the 
 * affine transform. This function allocates memory for the returned XSTRectangle 
 * structure. It is the callers responsiblity to free up this memory using XSTFree().
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param iFunc			transformation direction to perform
 * @param iTrap			user space trapezoid
 *
 * @return XSTTrapezoid structure
 */
XSTTrapezoid *XSTTransformTrapezoid(Display      *dpy, 
				    GC            gc, 
				    int           iFunc,
				    XSTTrapezoid *iTrap);


/** 
 * @} 
 */
#endif
