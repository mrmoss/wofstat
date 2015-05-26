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

/* @(#)Xst_style.h	1.19 04/07/27 SMI */

#ifndef _XSTSTYLE_H
#define _XSTSTYLE_H

#include "Xst_typedef.h"
#include "Xst_font.h"

/********************************* XSTStyle General Defines *************************/

/******************************* XSTStyle Function Prototypes ***********************/

/** @defgroup Style XSTStyle functions
 * @{
 */

/**
 * Creates a new empty Style and returns an XID referring to the new STStyle object. 
 * Style is a unit of formatting information applied to a sequence of characters in 
 * an STText object. It has several attributes that can be set and copied from one 
 * Style to another.
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 *
 * @return XSTStyle XID
 */
XSTStyle XSTStyleNewEmpty(Display   *dpy, 
                          XSTTypeEnv iEnv);


/**
 * Creates a new Style with the attributes set to default values and returns an XID 
 * referring to the new STStyle object. 
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 *
 * @return XSTStyle XID
 */
XSTStyle XSTStyleNewDefault(Display   *dpy, 
                            XSTTypeEnv iEnv);


/**
 * Creates a new Style and copies the attributes from an existing STStyle. It returns
 * an XID referring to the new STStyle object. 
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 *
 * @return XSTStyle XID
 */
XSTStyle XSTStyleNewCopy(Display *dpy, 
                         XSTStyle iStyle);


/**
 * Delete the STStyle and free the XSTStyle XID.
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 *
 * @return XSTStyle XID
 */
void XSTStyleDispose(Display *dpy, 
                     XSTStyle iStyle);


/**
 * Compare two STStyle objects
 *
 * @param dpy                   X Display value
 * @param iLhs                  XSTStyle XID of the first STStyle object to use
 * @param iMask                 mask of attributes to include in comparison
 * @param iRhs                  XSTStyle XID of the second STStyle object to use
 *
 * @return XSTStyleComparison value
 */
XSTStyleComparison XSTStyleCompare(Display     *dpy, 
                                   XSTStyle     iLhs, 
                                   XSTStyleMask iMask, 
                                   XSTStyle     iRhs);


/**
 * Checks if an STStyle is empty. IE. no attributes were assigned to it.
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 *
 * @return Bool value
 */
Bool XSTStyleIsEmpty(Display *dpy, 
                     XSTStyle iStyle);


/**
 * Sets font-related attributes of the STStyle. The iMask parameter indicates which 
 * of the attributes are to be set.
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param iMask                 a set of XSTStyleMasks values OR'ed together or 
 *                                ST_SM_ALL to change all values
 * @param iFont                 font ID
 * @param iSize                 font size measured in typographic points
 * @param iLocale               Locale/Language/Script of the style
 * @param iBaseline             The dominant baseline for this style
 *
 * @return none
 */
void XSTStyleSetFont(Display           *dpy, 
                     XSTStyle           iStyle, 
                     XSTStyleMask       iMask,
                     XSTFont            iFont, 
                     double             iSize, 
                     XSTLocale          iLocale, 
                     XSTBaselineFlag    iBaseline);


/**
 * Gets font-related attributes of the STStyle. The iMask parameter indicates which 
 * of the attributes have been previously set. 
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param oMask                 a set of XSTStyleMasks values OR'ed together 
 * @param oSize                 font size measured in typographic points
 * @param oLocale               Locale/Language/Script of the style
 * @param oBaseline             The dominant baseline for this style
 *
 * @return XSTFont XID
 */
XSTFont XSTStyleGetFont(Display            *dpy, 
                        XSTStyle            iStyle, 
                        XSTStyleMask       *oMask,
                        double             *oSize, 
                        XSTLocale          *oLocale,
                        XSTBaselineFlag    *oBaseline);


/**
 * Sets scaler and its parameters for this STStyle object.
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param iMask                 a set of XSTStyleMasks values OR'ed together or 
 *                                ST_SM_ALL change all values
 * @param iScaler               XSTScaler XID of the STScaler object to use
 * @param iHints                Specifies if the scaler should use hints
 * @param iSbits                Specifies if the scaler should use embedded bitmaps
 *
 * @return none
 */
void XSTStyleSetScaler(Display       *dpy, 
                       XSTStyle       iStyle, 
                       XSTStyleMask   iMask,
                       XSTScaler      iScaler, 
                       XSTHintingMode iHints, 
                       XSTSbitsMode   iSbits);


/**
 * Returns the scaler and its parameters for this STStyle object. The oMask parameter
 * indicates which fields were previously set
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param oMask                 a set of XSTStyleMasks values OR'ed together 
 * @param oHints                Specifies if the scaler should use hints
 * @param oSbits                Specifies if the scaler should use embedded bitmaps
 *
 * @return XSTScaler value
 */
XSTScaler XSTStyleGetScaler(Display        *dpy, 
                            XSTStyle        iStyle, 
                            XSTStyleMask   *oMask,
                            XSTHintingMode *oHints, 
                            XSTSbitsMode   *oSbits);


/**
 * Sets some effects related attributes for the STStyle object
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param iMask                 a set of XSTStyleMasks values OR'ed together or 
 *                                ST_SM_ALL to change all values
 * @param iStyleEffects         a set of STStyleEffects values OR'ed together
 * @param iStrikeThroughEffects a set of STStrikeThrough values OR'ed together
 * @param iUnderlineEffects     a set of STUnderline values OR'ed together
 *
 * @return none
 */
void XSTStyleSetEffects(Display                *dpy, 
                        XSTStyle                iStyle, 
                        XSTStyleMask            iMask,
                        XSTStyleEffects         iStyleEffects,
                        XSTStrikeThroughEffects iStrikeThroughEffects,
                        XSTUnderlineEffects     iUnderlineEffects);


/**
 * Retrieves some effects related attributes for the STStyle object. The oMask 
 * parameter indicates which of the fields has been previously changed.
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param oMask                 a set of XSTStyleMasks values OR'ed together 
 * @param oStyleEffects         a set of STStyleEffects values OR'ed together
 * @param oStrikeThroughEffects a set of STStrikeThrough values OR'ed together
 * @param oUnderlineEffects     a set of STUnderline values OR'ed together
 *
 * @return none
 */
void XSTStyleGetEffects(Display                 *dpy, 
                        XSTStyle                 iStyle, 
                        XSTStyleMask            *oMask,
                        XSTStyleEffects         *oStyleEffects,
                        XSTStrikeThroughEffects *oStrikeThroughEffects,
                        XSTUnderlineEffects     *oUnderlineEffects);


/**
 * Remove specified attributes from an STStyle.
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param iMask                 a set of XSTStyleMasks values OR'ed together or 
 *                                ST_SM_ALL to clear all values
 *
 * @return none
 */
void XSTStyleRemoveAttributes(Display     *dpy, 
                              XSTStyle     iStyle,
                              XSTStyleMask iMask);


/**
 * Resets specified STStyle attributes to their default values
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param iMask                 a set of XSTStyleMasks values OR'ed together or 
 *                                ST_SM_ALL to reset all values
 *
 * @return none
 */
void XSTStyleResetAttributes(Display     *dpy, 
                             XSTStyle     iStyle, 
                             XSTStyleMask iMask);


/**
 * Copies specified attributes set in the source STStyle object to the destination 
 * STStyle object. Attributes not set in the source object are unset in the 
 * destination object.
 *
 * @param dpy                   X Display value
 * @param iToStyle              XSTStyle XID of the STStyle object to copy to
 * @param iMask                 a set of XSTStyleMasks values OR'ed together or 
 *                                ST_SM_ALL to copy all values
 * @param iFromStyle            XSTStyle XID of the STStyle object to copy from
 *
 * @return none
 */
void XSTStyleCopyAttributes(Display     *dpy, 
                            XSTStyle     iToStyle, 
                            XSTStyleMask iMask, 
                            XSTStyle     iFromStyle);


/**
 * Copies specified attributes set in the source STStyle object to the destination 
 * STStyle object. Attributes must both be in the iMask and be set in both the source
 * and destination objects to be copied. 
 *
 * @param dpy                   X Display value
 * @param iToStyle              XSTStyle XID of the STStyle object to copy to
 * @param iMask                 a set of XSTStyleMasks values OR'ed together or 
 *                                ST_SM_ALL to copy all values
 * @param iFromStyle            XSTStyle XID of the STStyle object to copy from
 *
 * @return none
 */
void XSTStyleOverwriteAttributes(Display     *dpy, 
                                 XSTStyle     iToStyle, 
                                 XSTStyleMask iMask, 
                                 XSTStyle     iFromStyle);


/**
 * Copies specified attributes set in the source STStyle object to the destination 
 * STStyle object. Attributes must both be in the iMask and must not be set in the 
 * destination object in order to be copied.
 *
 * @param dpy                   X Display value
 * @param iToStyle              XSTStyle XID of the STStyle object to copy to
 * @param iMask                 a set of XSTStyleMasks values OR'ed together or ST_SM_ALL
 *                                to copy all values
 * @param iFromStyle            XSTStyle XID of the STStyle object to copy from
 *
 * @return none
 */
void XSTStyleUnderwriteAttributes(Display     *dpy, 
                                  XSTStyle     iToStyle, 
                                  XSTStyleMask iMask, 
                                  XSTStyle     iFromStyle);


/**
 * Retrieves baselines position for a style. Baseline positions are measured as 
 * offsets from the baseline specified by iBaseline. The function allocates memory 
 * for the array of baselines returned. It is the callers responsiblity to free up 
 * this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param iBaseline             baseline from which offsets are measured
 * @param oBaselineMask         indicates which baselines are set in the array
 *
 * @return double array
 */
double *XSTStyleCalculateBaselines(Display         *dpy, 
                                   XSTStyle         iStyle, 
                                   XSTBaselineFlag  iBaseline,
				   XSTBaselineMask *oBaselineMask);


/**
 * Retrieves design metrics for the style based on scaled font design metrics. 
 * Returned metrics are in users space. The function allocates memory for the 
 * returned metrics. It is the callers responsiblity to free up this memory.
 * using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 *
 * @return XSTLineMetrics structure
 */
XSTLineMetrics *XSTStyleGetDesignMetrics(Display *dpy, 
                                         XSTStyle iStyle);


/**
 * Sets additional style options.
 *
 * @param dpy                           X Display value
 * @param iStyle                        XSTStyle XID of the STStyle object to use
 * @param iMask                         a set of XSTStyleMasks values OR'ed together 
 *                                        or ST_SM_ALL to copy all values
 * @param iImposeWidth                  weight factor for font-defined glyph widths
 * @param iBeforeWithStreamShift        weight factor for with-stream shift applied 
 *                                        before each glyph 
 * @param iAfterWithStreamShift         weight factor for with-stream shift applied 
 *                                        after each glyph 
 * @param iCrossStreamShift             cross-stream shift weight factor 
 * @param iHangingInhibitFactor         hanging glyph weight factor
 * @param iKerningInhibitFactor         kerning weight factor
 * @param iDecompositionInhibitFactor   ligature decomposition weight factor
 *
 * @return none
 */
void XSTStyleSetOptions(Display     *dpy, 
                        XSTStyle     iStyle,
                        XSTStyleMask iMask, 
                        int          iImposeWidth,
                        int          iBeforeWithStreamShift,
                        int          iAfterWithStreamShift,
                        int          iCrossStreamShift,
                        int          iHangingInhibitFactor,
                        int          iKerningInhibitFactor,
                        int          iDecompositionInhibitFactor);


/**
 * Retrieves additional style options. Returns the mask of style options that have 
 * been previously set.
 *
 * @param dpy                           X Display value
 * @param iStyle                        XSTStyle XID of the STStyle object to use
 * @param oImposeWidth                  weight factor for font-defined glyph widths
 * @param oBeforeWithStreamShift        weight factor for with-stream shift applied 
 *                                        before each glyph 
 * @param oAfterWithStreamShift         weight factor for with-stream shift applied 
 *                                        after each glyph 
 * @param oCrossStreamShift             cross-stream shift weight factor 
 * @param oTracking                     weither factor for distance between glyphs
 * @param oHangingInhibitFactor         hanging glyph weight factor
 * @param oKerningInhibitFactor         kerning weight factor
 * @param oDecompositionInhibitFactor   ligature decomposition weight factor
 *
 * @return XSTStyleMask value
 */
XSTStyleMask XSTStyleGetOptions(Display *dpy, 
                                XSTStyle iStyle,
                                int     *oImposeWidth,
                                int     *oBeforeWithStreamShift,
                                int     *oAfterWithStreamShift,
                                int     *oCrossStreamShift,
                                int     *oTracking,
                                int     *oHangingInhibitFactor,
                                int     *oKerningInhibitFactor,
                                int     *oDecompositionInhibitFactor);


/** 
 * @} 
 */

#endif
