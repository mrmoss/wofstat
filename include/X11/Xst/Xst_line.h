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

/* @(#)Xst_line.h	1.24 04/07/27 SMI */

#ifndef _XSTLINE_H
#define _XSTLINE_H

#include "Xst_typedef.h"
#include "Xst_text.h"

/********************************* XSTLine General Defines **************************/

/******************************* XSTLine Function Prototypes ************************/

/** @defgroup Line XSTLine functions
 * @{
 */

/**
 * Creates a new STLine object and returns the XSTLine XID referring to it. STLine is
 * a unit of displayable text. It is derived from STText object and refers its text. A
 * line-breaking algorithm can be implemented by sequentually adding characters to the
 * STLine object and measuring its typographic bounds.
 *
 * @param dpy                   X Display value
 * @param iText			an XSTText XID referring to the STText object to use
 * @param iFirstChar		an offset from the first character of the STText 
 *                                object
 * @param iCharCount		number of characters to add to the line. A special 
 *                                value of ST_CHARCOUNT_TOEND adds all STText 
 *                                characters to this STLine object
 * @param oCharCount		actual number of added characters is stored here. If
 *                                NULL is passed, then no response is given.
 *
 * @return XSTLine XID
 */
XSTLine XSTLineNew(Display    *dpy, 
		   XSTText     iText, 
		   XSTPosition iFirstChar, 
		   XSTCount    iCharCount, 
		   XSTCount   *oCharCount);


/**
 * Creates a new STLine object with as many characters as can fit within the width
 * specified by iWidth and returns the XSTLine XID referring to it.
 *
 * @param dpy                   X Display value
 * @param iText			an XSTText XID referring to the STText object to use
 * @param iFirstChar		an offset from the first character of the STText 
 *                                object
 * @param iWidth		text width of the line in typographic points. 
 * @param oCharCount		actual number of added characters is stored here. If
 *                                NULL is passed, then no response is given.
 *
 * @return XSTLine XID
 */
XSTLine XSTLineNewForWidth(Display    *dpy, 
			   XSTText     iText, 
			   XSTPosition iFirstChar, 
			   Rational    iWidth, 
			   XSTCount   *oCharCount);


/**
 * Destroys the STLine and frees the XSTLine XID.
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to 
 *                                delete
 *
 * @return none
 */
void XSTLineDispose(Display *dpy, 
		    XSTLine  iLine);


/**
 * Adds characters to the beginning or to the end of the line. This function is used 
 * for creating customized line-break algorithms.
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iAppend		true if characters are appended, false if prepended
 * @param iCharCount		specifies the number of added characters
 *
 * @return none
 */
void XSTLineGrow(Display *dpy, 
		 XSTLine  iLine, 
		 Bool     iAppend, 
		 XSTCount iCharCount);


/**
 * Removes characters to the beginning or to the end of the line. This function is 
 * used for creating customized line-break algorithms.
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iFromEnd		true if characters are removed from line end, false if
 * 				  from line start
 * @param iCharCount		specifies the number of added characters
 *
 * @return none
 */
void XSTLineShrink(Display *dpy, 
		   XSTLine  iLine, 
		   Bool     iFromEnd, 
		   XSTCount iCharCount);


/**
 * Returns the line position within the STText object.
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param oCharCount		returns a number of characters in the line
 *
 * @return the first character offset of the line within the STText
 */
XSTPosition XSTLineGetPosition(Display  *dpy, 
		               XSTLine   iLine, 
		               XSTCount *oCharCount);


/**
 * Imposes metrics on a line.
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iMask                 indicates which metric values to set
 * @param iLineMetrics		sets ascent, descent and width or use NULL pointer to
 *                                use the value derived from its parent STText object
 * @param iBaselineMask         indicates which baseline values are set in the array
 * @param iBaselines		baselines of this line of text or NULL pointer to use
 *                                the value derived from its parent STText object
 *
 * @return none
 */
void XSTLineSetMetrics(Display           *dpy, 
		       XSTLine            iLine, 
                       XSTTextMask        iMask,
		       XSTExtLineMetrics *iLineMetrics, 
                       XSTBaselineMask    iBaselineMask,
		       double            *iBaselines);


/**
 * Returns metrics previously imposed on a line. This function allocates memory for 
 * the returned metrics and baseline structures. It is the callers responsiblity to 
 * free up this memory using XSTFree(). The default metrics are not set.
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iMask                 indicates which metric values have been set
 * @param oBaselineMask         indicates which baseline values are set in the array
 * @param oBaselines		baselines of this line of text. If NULL is passed,
 *                                then no baselines are returned.
 *
 * @return XSTExtLineMetrics struct
 */
XSTExtLineMetrics *XSTLineGetMetrics(Display         *dpy, 
				     XSTLine          iLine,
                                     XSTTextMask     *oMask,
				     XSTBaselineMask *oBaselineMask,
				     double         **oBaselines);


/**
 * Retrieves design metrics for the line based on scaled font design metrics. Returned
 * metrics is in user space. This function allocates memory for the returned metrics 
 * structure. It is the callers responsiblity to free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 *
 * @return XSTExtLineMetrics struct
 */
XSTExtLineMetrics *XSTLineGetDesignMetrics(Display *dpy, 
					   XSTLine iLine);


/**
 * Calculates a typographic bounding rectangle in user space of a line ignoring all 
 * imposed metrics and attributes. If the gc parameter is specified, then the affine
 * transform is applied to the rectangular bounding box and the resulting trapezoid is
 * returned. If not, then the rectangle is returned in the trapezoid structure with 
 * all four of its vetices specified. This function allocates memory for the returned 
 * trapezoid structure. It is the callers responsiblity to free up this memory using
 * XSTFree().
 *
 * @param dpy                   X Display value
 * @param gc			Graphics Context
 * @param iLine			an XSTLine XID referring to the STLine object to use
 *
 * @return XSTTrapezoid struct
 */
XSTTrapezoid *XSTLineMeasureText(Display *dpy, 
				 GC       gc, 
				 XSTLine  iLine);


/**
 * Calculates a standard bounding rectangle of a laid-out line of text after all 
 * attributes ((justification, alignment, etc.) have been applied in user space.
 * If the gc parameter is specified, then the affine transform is applied to the 
 * rectangular bounding box and the resulting trapezoid is returned. If not, then the 
 * rectangle is returned in the trapezoid structure with all four of its vetices 
 * specified. This function allocates memory for the returned trapezoid structure. It
 * is the callers responsiblity to free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param gc			Graphics Context
 * @param iLine			an XSTLine XID referring to the STLine object to use
 *
 * @return XSTTrapezoid struct
 */
XSTTrapezoid *XSTLineMeasureTextImage(Display *dpy, 
				      GC       gc, 
				      XSTLine  iLine);


/**
 * Calculates a boundaries of glyphs of a final laid-out line in device coordinates.
 * The array of trapezoidal bounding boxes corresponds to text regions within the 
 * line. This function allocates memory for the returned trapezoid structure. It is  
 * the callers responsiblity to free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param gc			Graphics Context
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iMaxBoundsCount	specifies the precision of the output - the maximal  
 *                                number of trapezoids the function can allocate to 
 *                                store glyph bounds.  Set it to 1 if only one 
 *                                trapezoid for the entire line is requested
 * @param iBounds		specifies the type of origin used for calculating 
 *                                bounds
 * @param oBoundsCount		number of trapezoids in the returned array
 *
 * @return XSTTrapezoid struct
 */
XSTTrapezoid *XSTLineGetGlyphBounds(Display  *dpy, 
				    GC        gc, 
				    XSTLine   iLine, 
				    XSTCount  iMaxBoundsCount, 
				    XSTBounds iBounds, 
				    XSTCount *oBoundsCount);

/**
 * Converts a pair of coordinates to the logical character offset. If the gc 
 * parameter is specified, then the affine transform is applied in reverse to change 
 * the iX and iY values from device coordinates to user coordinates. 
 *
 * @param dpy                   X Display value
 * @param gc			Graphics Context
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iX			X coordinate relative to the UL corner of the line 
 *				  bounding rectangle
 * @param iY			Y coordinate relative to the UL corner of the line
 *				  bounding rectangle
 * @param oPrimaryOffset	logical offset of the glyph closest to (iX, iY) 
 *				  coordinates
 * @param oSecondaryOffset	if (iX, iY) are on a line direction boundary this 
 *                                gives the second logical offset.
 *
 * @return is hit leading or trailing value
 */
Bool XSTLineHitTest(Display *dpy, 
		    GC       gc, 
		    XSTLine  iLine, 
		    Rational iX, 
		    Rational iY, 
		    int     *oPrimaryOffset, 
		    int     *oSecondaryOffset);


/**
 * Returns one or two carets (strong and weak) for a specified logical character 
 * position If the gc parameter is specified, then the affine transform is applied to
 * the caret and the resulting device space caret is returned. If not, then the caret
 * is returned in user space coordinates.
 *
 * @param dpy                   X Display value
 * @param gc			Graphics Context
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iFirstChar		logical offset of the character within STLine's parent
 *				  STText object
 * @param iIsLeading		matters only if character at iOffset is at line 
 *                                direction boundary
 * @param oStrongCaret		denotes primary (or main if oSplitCaret is false) 
 *                                caret
 * @param oWeakCaret		denotes secondary (or main if oSplitCaret is false) 
 *                                caret
 *
 * @return if character at iOffsets is at line direction boundary
 */
Bool XSTLinePositionToCaret(Display    *dpy, 
			    GC          gc, 
			    XSTLine     iLine, 
			    XSTPosition iFirstChar, 
			    Bool        iIsLeading, 
			    XSTCaret   *oStrongCaret, 
			    XSTCaret   *oWeakCaret);


/**
 * Calculates a new position of the caret. The caret can be moved by characters, 
 * words or Unicode clusters. Direction can be previous, next, left or right. When 
 * the initial position of the caret is on a line direction boundary, this function 
 * calculates the new position of the primary caret. Inside an LTR text and not on 
 * the direction boundary "next" is equivalent to "right," and "previous" is 
 * equivalent to "left." Inside an RTL text "next" is equivalent to "left" and 
 * "previous" is equivalent to "right." For vertical text "left" is "top" and "right"
 * is "bottom"
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iFirstChar		initial caret position
 * @param iDirection		specifies direction - left, right, next, or previous
 * @param iMovement		specifies movement type - character, word, or cluster
 *
 * @return new caret position
 */
XSTPosition XSTLineMoveCaret(Display          *dpy, 
		             XSTLine           iLine, 
		             XSTPosition       iFirstChar, 
		             XSTCaretDirection iDirection, 
		             XSTCaretMovement  iMovement);


/**
 * Renders text represented by an STLine object onto the Drawable
 *
 * @param dpy                   X Display value
 * @param d			Drawable (pixmap or window)
 * @param gc			Graphics Context
 * @param iLine			an XSTLine XID referring to the STLine object to use
 *
 * @return none
 */
void XSTLineRender(Display *dpy, 
		   Drawable d, 
		   GC       gc, 
		   XSTLine  iLine);


/**
 * Adds a highlighted region identified by the first character and the number of
 * characters to an STLine object. STLineRender() needs to be called to display it.
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iFirstChar		first character to highlight
 * @param iCharCount		number of characters in the highlighted region.
 *
 * @return none
 */
void XSTLineAddHighlight(Display    *dpy, 
			 XSTLine     iLine, 
			 XSTPosition iFirstChar, 
			 XSTCount    iCharCount);


/**
 * Removes highlighting from a region of characters in an STLine object. 
 * STLineRender() needs to be called to display the removed highlight.
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param iFirstChar		first character to remove highlighting from
 * @param iCharCount		number of characters in the region.
 *
 * @return none
 */
void XSTLineRemoveHighlight(Display    *dpy, 
			    XSTLine     iLine, 
			    XSTPosition iFirstChar, 
			    XSTCount    iCharCount); 


/**
 * Queries the currently defined highlighted regions. This function allocates memory 
 * for the returned position and count arrays. It is the callers responsiblity to 
 * free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iLine			an XSTLine XID referring to the STLine object to use
 * @param oRegionCount		number of highlighted regions
 * @param oFirstChar		array of first first character offsets of highlighted 
 *				  regions
 * @param oCharCount		array of lengths of highlighted regions
 *
 * @return none
 */
void XSTLineGetHighlights(Display      *dpy, 
			  XSTLine       iLine, 
			  XSTCount     *oRegionCount,
			  XSTPosition **oFirstChar, 
			  XSTCount    **oCharCount);

/**
 * Returns an array of styled glyphs associated with the line. This function 
 * allocates memory for the returned array. It is the callers responsibility to free
 * up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iLine                 an XSTLine XID referring to the STLine object to use
 * @param iFirstChar            character position within line to start glyph array
 * @param iCharCount            number of characters to include in glyph array
 * @param oGlyphCount           number of glyphs returned in array
 *
 * @return XSTStyledGlyph array
 */
XSTStyledGlyph *XSTLineGetStyledGlyphs(Display    *dpy,
                                       XSTLine     iLine,
                                       XSTPosition iFirstChar,
                                       XSTCount    iCharCount,
                                       XSTCount   *oGlyphCount);
/** 
 * @} 
 */
#endif
