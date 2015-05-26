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

/* @(#)Xst_gc.h	1.18 04/07/27 SMI */

#ifndef _XSTGC_H
#define _XSTGC_H

#include "Xst_typedef.h"
#include "Xst_ext.h"

/********************************** XSTGC General Defines ***************************/

/**
 *  A box
 */
typedef struct {
    short x1, x2, y1, y2;
} Box, *BoxPtr;

/**
 *  A rectangle
 */
typedef struct {
    short x, y, width, height;
} Rectangle, *RectanglePtr;

/**
 *  A clipping region
 */
typedef struct _XRegion {
    long size;
    long numRects;
    Box *rects;
    Box extents;
} REGION;

/******************************** XSTGC Function Prototypes *************************/

/** @defgroup Graphics XSTGC functions
 * @{
 */

/**
 * Sets graphics colors. See Xst_colors.h for a list of color positions
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param iMask			set of bitflags OR'ed together for which colors to 
 *                                change
 * @param iColors		array of colors
 *
 * @return none
 */
void XSTGCSetColors(Display             *dpy, 
		    GC                   gc, 
		    XSTGraphicsColorMask iMask, 
		    XSTRGBAColor        *iColors);

/**
 * Returns an array of graphics colors. Defaults for colors are TBD.
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param oMask			set of bitflags OR'ed together for which colors have 
 *                                been 
 * 				previously set
 *
 * @return XSTRGBAColor array
 */
XSTRGBAColor *XSTGCGetColors(Display              *dpy, 
			     GC                    gc, 
			     XSTGraphicsColorMask *oMask);


/**
 * Returns a mask of the alpha values that have been previously set. Any XSTAlpha with
 * a pointer to NULL will not be returned.
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param oTextAlpha		Contains the min and max alpha values for the text
 * @param oHighlightAlpha	Contains the min and max alpha values for Highlight
 * @param oUnderline1Alpha	Contains the min and max alpha values for Underline1
 * @param oUnderline2Alpha	Contains the min and max alpha values for Underline2
 * @param oStrikeThroughAlpha	Contains the min and max alpha values for 
 *                                StrikeThrough
 *
 * @return XSTAlphaMask bitmask
 */
XSTAlphaMask XSTGCGetAlphaRange(Display  *dpy, 
				GC        gc, 
				XSTAlpha *oTextAlpha, 
				XSTAlpha *oHighlightAlpha,
				XSTAlpha *oUnderline1Alpha, 
				XSTAlpha *oUnderline2Alpha, 
				XSTAlpha *oStrikeThroughAlpha);


/**
 * Sets the min and max alpha ranges. The iMask value is a bitmask OR'ed together to
 * indicate which of the alpha ranges to set. Any XSTAlpha parameter that is NULL 
 * will not be set.
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param iMask			bitmask of alpha ranges to set
 * @param iTextAlpha		Contains the min and max alpha values for the text
 * @param iHighlightAlpha	Contains the min and max alpha values for Highlight
 * @param iUnderline1Alpha	Contains the min and max alpha values for Underline1
 * @param iUnderline2Alpha	Contains the min and max alpha values for Underline2
 * @param iStrikeThroughAlpha	Contains the min and max alpha values for 
 *                                StrikeThrough
 *
 * @return none
 */
void XSTGCSetAlphaRange(Display     *dpy, 
			GC           gc, 
			XSTAlphaMask iMask, 
			XSTAlpha     iTextAlpha, 
			XSTAlpha     iHighlightAlpha, 
			XSTAlpha     iUnderline1Alpha, 
			XSTAlpha     iUnderline2Alpha, 
			XSTAlpha     iStrikeThroughAlpha);


/**
 * Set the output type and mode. The type refers to the type of monitor hooked up to 
 * the system, or format of the output to display. The mode refers to the output 
 * being raster or vector based.
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param iType			Type of output (B&W, Grayscale, LCD Optimized)
 * @param iMode			Output mode (raster, vector)
 *
 * @return none
 */
void XSTGCSetOutputFormat(Display      *dpy, 
			  GC            gc, 
			  XSTOutputType iType, 
			  XSTOutputMode iMode);


/**
 * Get the output type and mode. The type refers to the type of monitor hooked up to 
 * the system, or format of the output to display. The mode refers to the output 
 * being raster or vector based. The default for the output mode is XST_RASTER_OUTPUT,
 * and the default for the output type is Black and White.
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param oType			Type of output (B&W, Grayscale, LCD Optimized)
 *
 * @return XSTOutputMode value
 */
XSTOutputMode XSTGCGetOutputFormat(Display       *dpy, 
				   GC             gc, 
				   XSTOutputType *oType);

/**
 * Replaces the current transformation matrix with a new one.
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param iMatrix		new transformation matrix
 *
 * @return none
 */
void XSTGCSetMatrix(Display   *dpy, 
		    GC         gc, 
		    XSTMatrix *iMatrix);


/**
 * Return the current transformation matrix. This function allocates memory for the 
 * array of font IDs returned. It is the callers responsiblity to free up this memory
 * using XSTFree(). The default matrix is the identity matrix.
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 *
 * @return XSTMatrix
 */
XSTMatrix *XSTGCGetMatrix(Display *dpy, 
			  GC gc);


/**
 * Concat the current transformation matrix with another one. 
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param iMatrix		transformation matrix to concat with current one.
 *
 * @return none
 */
void XSTGCConcatMatrix(Display   *dpy, 
		       GC         gc, 
		       XSTMatrix *iMatrix);


/**
 * Translate the current transformation matrix 
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param tx			X translate value
 * @param ty			Y translate value
 *
 * @return none
 */
void XSTGCTranslate(Display *dpy, 
		    GC       gc, 
		    double   tx, 
		    double   ty);


/**
 * Scale the current transformation matrix 
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param sx			X factor to scale by
 * @param sy			Y factor to scale by
 *
 * @return none
 */
void XSTGCScale(Display *dpy, 
		GC       gc, 
		double   sx, 
		double   sy);


/**
 * Rotate the current transformation matrix 
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param theta			value to rotate the matrix
 *
 * @return none
 */
void XSTGCRotate(Display *dpy, 
		 GC       gc, 
		 double   theta);


/**
 * Shear the current transformation matrix 
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param shx			X amount to shear matrix
 * @param shy			Y amount to shear matrix
 *
 * @return none
 */
void XSTGCShear(Display *dpy, 
		GC       gc, 
		double   shx, 
		double   shy);

/**
 * Set the clipping region for the gc
 *
 * @param dpy			X Display value
 * @param gc			Graphics Context
 * @param r			This is the region to clip
 *
 * @return none
 */
void XSTGCSetRegion(Display *dpy, 
		    GC       gc, 
		    REGION  *r);

/**
 * @}
 */
#endif

