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

/* @(#)Xst_glyph.h	1.6 04/07/27 SMI */

#ifndef _XSTGLYPH_H
#define _XSTGLYPH_H

#include "Xst_typedef.h"

/***************************** XSTGlyphVector General Defines **********************/

/* ************************* XSTGlyphVector Function Prototypes ********************/

/** @defgroup GlyphVector XSTGlyphVector functions
 * @{
 */

/**
 * Creates a new STGlyphVector object and returns the XSTGlyphVector XID referring to
 * it. An STGlyphVector is an array of styled glyphs and positions.
 *
 * @param dpy		X Display pointer
 * @param iEnv		an XSTTypeEnv XID.
 * @param iGlyphs	XSTStyledGlyph array
 * @param iGlyphCount	Number of items in the array.
 *
 * @return XSTGlyphVector XID
 */
XSTGlyphVector XSTGlyphVectorNew(Display        *dpy, 
				 XSTTypeEnv      iEnv, 
				 XSTStyledGlyph *iGlyphs, 
				 XSTCount        iGlyphCount);


/**
 * Creates a copy of the STGlyphVector and returns the new XSTGlyphVector XID 
 * referring to it.
 *
 * @param dpy		X Display pointer
 * @param iGlyph	an XSTGlyphVector XID.
 *
 * @return XSTGlyphVector XID
 */
XSTGlyphVector XSTGlyphVectorNewCopy(Display       *dpy, 
				     XSTGlyphVector iGlyph);


/**
 * Destroys the STGlyphVector and frees the XSTGlyphVector XID.
 *
 * @param dpy		X Display pointer
 * @param iGlyph	an GlyphVector XID.
 *
 * @return none
 *
 */
void XSTGlyphVectorDispose(Display *dpy, 
			   XSTGlyphVector iGlyph);


/**
 * Sets the array of glyphs associated with the STGlyphVector. This will effectively
 * delete any other glyphs previously associated with the vector.
 *
 * @param dpy	 	X Display pointer
 * @param iGlyph	an GlyphVector XID.
 * @param iGlyphs	Glyph array
 * @param iGlyphCount	Number of glyphs in the array
 *
 * @return none
 */
void XSTGlyphVectorSetGlyphs(Display        *dpy, 
			     XSTGlyphVector  iGlyph, 
			     XSTStyledGlyph *iGlyphs,
		             XSTCount        iGlyphCount);


/**
 * Returns the list of styled glyphs associated with the STGlyphVector. This function
 * allocates space for the array of styled glyphs. It is the users responsibility to
 * free this array using XSTFree().
 *
 * @param dpy	 	X Display pointer
 * @param iGlyph	an XSTGlyphVector XID.
 * @param iFirstGlyph	Index position of first glyph to get.
 * @param ioGlyphCount	Number of glyphs to get and number in the returned array.
 *
 * @return XSTStyledGlyph array
 */
XSTStyledGlyph *XSTGlyphVectorGetGlyphs(Display       *dpy, 
					XSTGlyphVector iGlyph, 
		                        XSTPosition    iFirstGlyph,
					XSTCount      *ioGlyphCount);


/**
 * Replaces a specified range of glyphs with a supplied array of styled glyphs.
 *
 * @param dpy			X Display pointer
 * @param iGlyph		an GlyphVector XID. 
 * @param iFirstGlyph		Index position of first glyph to replace.
 * @param iGlyphCount		Number of glyphs in vector to replace.
 * @param iGlyphs		Array of glyphs to use as replacements.
 * @param iGlyphArrayCount	Number of glyphs in new array.
 *
 * @return none
 */
void XSTGlyphVectorReplaceGlyphs(Display        *dpy, 
				 XSTGlyphVector  iGlyph, 
				 XSTPosition     iFirstGlyph, 
				 XSTCount        iGlyphCount, 
				 XSTStyledGlyph *iGlyphs, 
				 XSTCount        iGlyphArrayCount);



/**
 * Changes the positions of a specified range of glyphs by moving them by an amount
 * equal to the x and y values in the XSTPoint structure.
 *
 * @param dpy		X Display pointer
 * @param iGlyph	an GlyphVector XID. 
 * @param iFirstGlyph	Index position of first glyph to adjust.
 * @param iGlyphCount	Number of glyphs in vector to adjust
 * @param iDelta	Delta to change each specified glyph by.
 *
 * @return none
 */
void XSTGlyphVectorAdjustPositions(Display       *dpy, 
				   XSTGlyphVector iGlyph, 
				   XSTPosition    iFirstGlyph,
				   XSTCount       iGlyphCount, 
				   XSTPoint       iDelta);


/**
 * Returns the rectangular box containing the specified glyphs.
 *
 * @param dpy		X Display pointer
 * @param iGlyph	an GlyphVector XID.
 * @param iFirstGlyph	Index position of first glyph to measure
 * @param iGlyphCount	Number of glyphs in vector to measure
 *
 * @return XSTRectangle
 */
XSTRectangle *XSTGlyphVectorMeasure(Display       *dpy, 
				    XSTGlyphVector iGlyph, 
				    XSTPosition    iFirstGlyph, 
				    XSTCount       iGlyphCount);



/**
 * Returns an array of XSTTrapezoids containing bounding information for the specified
 * glyphs.
 *
 * @param dpy			X Display pointer
 * @param gc			X Graphics Context
 * @param iGlyph		an GlyphVector XID. 
 * @param iFirstGlyph		Index position for first glyph to get bounds for
 * @param iGlyphCount		Number of glyphs to include in bounds
 * @param iMaxBoundsCount	Maximum number of trapezoids that can be output.
 * @param iBoundsType		Specifies the type of origin used
 * @param oBoundsCount		The number of trapezoids returned.
 *
 * @return XSTTrapezoid array
 */
XSTTrapezoid *XSTGlyphVectorGetBounds(Display       *dpy, 
				      GC             gc, 
				      XSTGlyphVector iGlyph,
				      XSTPosition    iFirstGlyph, 
				      XSTCount       iGlyphCount, 
				      XSTCount       iMaxBoundsCount,
				      STBounds       iBoundsType, 
				      XSTCount      *oBoundsCount);



/**
 * Draws the glyphs on the specified drawable.
 *
 * @param dpy:		X Display pointer
 * @param d		Drawable to draw on.
 * @param gc:		X GC pointer
 * @param iGlyph:	an GlyphVector XID. 
 * @param iFirstGlyph:	Index position for first glyph to draw
 * @param iGlyphCount:	Number of glyphs to draw
 *
 * @return none
 */
void XSTGlyphVectorRender(Display       *dpy, 
			  Drawable       d, 
			  GC             gc, 
			  XSTGlyphVector iGlyph, 
			  XSTPosition    iFirstGlyph, 
			  XSTCount       iGlyphCount);

/**
 * @}
 */
#endif

