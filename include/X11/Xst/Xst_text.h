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

/* @(#)Xst_text.h	1.27 04/07/27 SMI */

#ifndef _XSTTEXT_H
#define _XSTTEXT_H

#include "Xst_typedef.h"
#include "Xst_line.h"
#include "Xst_font.h"
#include "Xst_style.h"

/********************************* XSTText General Defines **************************/

/******************************* XSTText Function Prototypes ************************/

/** @defgroup text XSTText functions
 * @{
 */

/**
 * Creates a new STText - Text object and returns an XSTText XID refering to it. 
 * STText is an opaque object that represents a unit of text and styles associated 
 * with it.
 *
 * STText object does not duplicate source text, instead it stores pointer to it. It 
 * is the user's responsibility to maintain the source text buffer, insert and remove
 * text from it and notify STText of it by calling XSTTextChangeText.
 *
 * STText uses coordinates relative to the upper-left corner of its typographic 
 * bounding box.
 *
 * STText consists of one or more lines of text (STLine object.) A line of text is an 
 * atomic displayable unit of text in ST.
 *
 * Styles (STStyle object) are assigned to STText. If none are assigned a default 
 * style is taken from STTypeEnv.
 *
 * STText has several  attributes:
 *        - Width
 *        - Global Direction
 *        - Justification
 *        - Alignment
 *        - Locale
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 *
 * @return XSTText XID
 */
XSTText XSTTextNewEmpty(Display   *dpy, 
			XSTTypeEnv iEnv);


/**
 * Creates a new STText and assign text to it. Return the XSTText XID value. If the 
 * iEnc parameter is XST_ENCODING_NOENCODING or XST_ENCODING_DEFAULT, then it uses 
 * the value retrieved from setlocale() to find the associated encoding.
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iChars		a pointer to the beginning of a paragraph of text
 * @param iCharCount		number of characters in a paragraph of text
 * @param iEnc		        Encoding of text characters
 *
 * @return XSTText XID
 */
XSTText	XSTTextNew(Display     *dpy, 
		   XSTTypeEnv   iEnv, 
		   XSTString   *iChars, 
		   XSTCount     iCharCount, 
		   XSTEncoding  iEnc);


/**
 * Duplicates an existing STText. Returns the XSTText XID referring to the new STText.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 *
 * @return XSTText XID
 */
XSTText	XSTTextNewCopy(Display *dpy, 
		       XSTText  iText);


/**
 * Destroys an existing STText object and frees the XSTText XID associated with it.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to free
 *
 * @return none
 */
void XSTTextDispose(Display *dpy, 
		    XSTText  iText);


/**
 * Restores the state of the STText to its initial state -
 *	- removes all assigned text
 * 	- removes all layout attributes
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to clear
 *
 * @return none
 */
void XSTTextClear(Display *dpy, 
		  XSTText  iText);


/**
 * Sets one or more STText metrics attributes. STText itself does not use any of these
 * attributes but all lines derived from an STText object inherit them.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iMask                 indicates which metrics to set
 * @param iLineMetrics		line metrics imposed on lines of text or NULL
 * @param iBaselineMask         indicates which baselines are set in the array
 * @param iBaselines		baselines imposed on lines of text or NULL
 *
 * @return none
 */
void XSTTextSetMetrics(Display           *dpy, 
		       XSTText            iText, 
                       XSTTextMask        iMask,
		       XSTExtLineMetrics *iLineMetrics, 
                       XSTBaselineMask    iBaselineMask,
		       double            *iBaselines);


/**
 * Returns the metrics previously set for the STText object. This function allocates 
 * memory for the returned metrics and baseline structures. It is the callers  
 * responsiblity to free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param oMask                 indicates which metrics have been set
 * @param oBaselineMask         indicates which baselines are set in the array
 * @param oBaselines		baselines imposed on lines of text
 *
 * @return XSTExtLineMetrics structure
 */
XSTExtLineMetrics *XSTTextGetMetrics(Display         *dpy, 
				     XSTText          iText, 
                                     XSTTextMask     *oMask,
                                     XSTBaselineMask *oBaselineMask,
				     double         **oBaselines);


/**
 * Sets one or more STText controls. The iMask parameter is used to specify which of 
 * the controls to set.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iMask			set of bitflags OR'ed together showing which fields 
 *                                to set
 * @param iDirection		specifies text directionality
 * @param iJustification	specifies text justification
 * @param iFlushFactor		specifies text alignment
 * @param iLocale		specifies text language
 * @param iPolicy		specifies font fallback policy
 *
 * @return none
 */
void XSTTextSetControls(Display              *dpy, 
			XSTText               iText, 
			XSTTextMask           iMask,
			XSTDirection          iDirection, 
			XSTJustification      iJustification, 
			XSTFlushFactor        iFlushFactor, 
			XSTLocale             iLocale, 
			XSTFontFallbackPolicy iPolicy);


/**
 * Retrieves previously set STText controls. Returns a bitmask indicating which of the
 * fields was previously set.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param oDirection		specifies text directionality
 * @param oJustification	specifies text justification
 * @param oFlushFactor		specifies text alignment
 * @param oLocale		specifies text language/locale/script
 * @param oPolicy		specifies font fallback policy
 *
 * @return XSTTextMask value
 */
XSTTextMask XSTTextGetControls(Display               *dpy, 
			       XSTText                iText, 
			       XSTDirection          *oDirection, 
			       XSTJustification      *oJustification, 
			       XSTFlushFactor        *oFlushFactor, 
			       XSTLocale             *oLocale,
			       XSTFontFallbackPolicy *oPolicy);


/**
 * Specifies a list of fonts for displaying characters missing from fonts set by Style
 * objects for the STText object. The order of fonts in the list matters: the search 
 * starts from the first font in the list and continues until all missing characters 
 * are found. 
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iFontCount		number of fonts in the array
 * @param iFontArray		array of font IDs
 *
 * @return none
 */
void XSTTextSetFontFallbacks(Display *dpy, 
			     XSTText  iText, 
			     XSTCount iFontCount, 
			     XSTFont *iFontArray);


/**
 * Returns a list of substitution fonts set for this text layout object. This function
 * allocates memory for the returned font array. It is the callers responsiblity to 
 * free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param oFontCount		number of fonts in the array
 *
 * @return XSTFont ID array
 */
XSTFont	*XSTTextGetFontFallbacks(Display  *dpy, 
				 XSTText   iText, 
				 XSTCount *oFontCount);


/**
 * Copies specified attributes set by XSTTextSetMetrics() and XSTTextSetControls() and
 * the font fallback list from one STText object to another.
 *
 * @param dpy                   X Display value
 * @param iToText		XSTText XID referring to the destination STText to use
 * @param iMask			set of bitflags OR'ed together showing which fields 
 *                                to copy
 * @param iFromText		XSTText XID referring to the source STText to use
 *
 * @return none
 */
void XSTTextCopyAttributes(Display    *dpy, 
			   XSTText     iToText, 
			   XSTTextMask iMask,
			   XSTText     iFromText);


/**
 * Restores specified attributes to empty unset values.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to reset
 * @param iMask			set of bitflags OR'ed together showing which fields to set
 *
 * @return none
 */
void XSTTextRemoveAttributes(Display    *dpy, 
			     XSTText     iText, 
			     XSTTextMask iMask);


/**
 * Restores specified attributes to default values.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to reset
 * @param iMask			set of bitflags OR'ed together showing which fields 
 *                                to set
 *
 * @return none
 */
void XSTTextResetAttributes(Display    *dpy, 
			    XSTText     iText, 
			    XSTTextMask iMask);


/**
 * Assigns text to an STText object. STText object does not create a private copy of 
 * this text, it keeps a pointer to it, so  it is responsibility of the caller to 
 * maintain the text buffer, insert and delete text from it, etc. 
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iChars		a pointer to the beginning of a paragraph of text
 * @param iCharCount		number of characters in a paragraph of text
 * @param iEnc		        encoding of text characters
 *
 * @return none
 */
void XSTTextSetText(Display     *dpy, 
		    XSTText      iText, 
		    XSTString   *iChars, 
		    XSTCount     iCharCount, 
		    XSTEncoding  iEnc);

/**
 * Retrieves source text from the STText object. The value of iEnc is used to convert
 * the encoding of the string from UTF-16 into the local encoding. This function 
 * allocates memory for the returned string. It is the callers responsiblity to free 
 * up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param oCharCount		number of characters in a paragraph of text
 * @param iEnc			encoding of text characters returned
 *
 * @return text string
 */
XSTString *XSTTextGetText(Display     *dpy, 
			  XSTText      iText, 
			  XSTEncoding  iEnc,
			  XSTCount    *oCharCount); 


/**
 * Informs the STText object that the text has been inserted or deleted.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iChange		indicates whether characters were inserted or removed
 * @param iTextOffset		position where text has been inserted or removed
 * @param iTextLength		number of added or removed characters
 *
 * @return none
 */
void XSTTextUpdate(Display           *dpy, 
		   XSTText            iText, 
		   XSTTextChangedType iChange, 
		   XSTPosition        iTextOffset, 
		   XSTCount           iTextLength);


/**
 * Takes the supplied Style and modifies all styles covered in the supplied range.
 * The function will break styles as necessary. Any attributes that are present in
 * the supplied Style are added or replaced in the iText styles. STText creates a copy
 * of the Style by calling its copy constructor, that it deallocates when STText's 
 * destructor is called.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iStyle		XSTStyle XID referring to the STStyle to use
 * @param iFirstChar		the first character that iStyle applies to
 * @param iCharCount		number of characters iStyle applies to
 *
 * @return none
 */
void XSTTextAugmentStyle(Display    *dpy, 
		         XSTText     iText, 
		         XSTStyle    iStyle, 
		         XSTPosition iFirstChar, 
		         XSTCount    iCharCount);


/**
 * Takes the supplied Style and modifies all styles covered in the supplied range.
 * The function will break styles as necessary. Any attributes that are present in
 * both the supplied style and the iText style are replaced. STText creates a copy 
 * of the Style by calling its copy constructor, that it deallocates when STText's 
 * destructor is called.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iStyle		XSTStyle XID referring to the STStyle to use
 * @param iFirstChar		the first character that iStyle applies to
 * @param iCharCount		number of characters iStyle applies to
 *
 * @return none
 */
void XSTTextOverwriteStyle(Display    *dpy, 
		           XSTText     iText, 
		           XSTStyle    iStyle, 
		           XSTPosition iFirstChar, 
		           XSTCount    iCharCount);


/**
 * Takes the supplied Style and modifies all styles covered in the supplied range.
 * The function will break styles as necessary. Any attributes that are present in
 * the supplied style, but not in the iText style are added. STText creates a copy 
 * of the Style by calling its copy constructor, that it deallocates when STText's 
 * destructor is called.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iStyle		XSTStyle XID referring to the STStyle to use
 * @param iFirstChar		the first character that iStyle applies to
 * @param iCharCount		number of characters iStyle applies to
 *
 * @return none
 */
void XSTTextUnderwriteStyle(Display    *dpy, 
		            XSTText     iText, 
		            XSTStyle    iStyle, 
		            XSTPosition iFirstChar, 
		            XSTCount    iCharCount);


/**
 * Assigns a Style to a sequence of characters of an STText object. STText creates a 
 * copy of the Style by calling its copy constructor, that it deallocates when 
 * STText's destructor is called.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iStyle		XSTStyle XID referring to the STStyle to use
 * @param iFirstChar		the first character that iStyle applies to
 * @param iCharCount		number of characters iStyle applies to
 *
 * @return none
 */
void XSTTextSetStyle(Display    *dpy, 
		     XSTText     iText, 
		     XSTStyle    iStyle, 
		     XSTPosition iFirstChar, 
		     XSTCount    iCharCount);


/**
 * Returns an XID of a copy of the STStyle object assigned to character at offset
 * iTextOffset in the STText object. The caller is responsible for calling the 
 * Style's destructor when it is no longer needed.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iFirstChar		offset of the character being queried
 * @param oFirstChar		offset of the first character belonging to the Style
 * @param oCharCount		number of characters in the Style
 *
 * @return XSTStyle XID
 */
XSTStyle XSTTextGetStyle(Display     *dpy, 
			 XSTText      iText, 
			 XSTPosition  iFirstChar, 
			 XSTPosition *oFirstChar, 
			 XSTCount    *oCharCount);


/**
 * Returns an XID of a new STStyle object that represents all common style 
 * characteristics of a set of characters in an STText. The caller is responsible for
 * calling the Style's destructor when it is no longer needed.
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iFirstChar		offset of the character being queried
 * @param iCharCount		number of characters being queried
 *
 * @return XSTStyle XID
 */
XSTStyle XSTTextGetCommonStyle(Display    *dpy, 
			       XSTText     iText, 
			       XSTPosition iFirstChar, 
			       XSTCount    iCharCount);


/**
 * Finds all text segments that contain missing characters and returns font IDs for 
 * the substituted fonts used to render these segments. This function allocates 
 * memory for three arrays (oSegOffset, oSegLength, and the returned array of font 
 * IDs) which the caller is required to free using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param oSegCount		number of segments with missing characters. 
 *                                oSegOffset, oSegLength, and the returned font ID 
 *                                array all contain oSegCount elements
 * @param oSegOffset		array of offsets to first characters in segments with
 *				  missing characters
 * @param oSegLength		number of characters in each segment
 *
 * @return XSTFont XID array
 */
XSTFont	*XSTTextFindMissingChars(Display      *dpy, 
				 XSTText       iText, 
				 XSTCount     *oSegCount, 
				 XSTPosition **oSegOffset, 
				 XSTCount    **oSegLength);

/**
 * Retrives an array of styled glyphs that correspond to a range of logical text from
 * a text object. XST allocates an array of styled glyphs and it is the responsiblity
 * of the caller to free the memory using XSTFree(). 
 *
 * @param dpy			X Display value
 * @param iText			XSTText XID referring to the STText to use
 * @param iStartFrom            index of the first character
 * @param iCharCount            number of characters in the range
 * @param oGlyphCount           number of styled glyphs
 *
 * @return XSTStyledGlyph *     array of styled glyphs
 */
XSTStyledGlyph *XSTTextGetStyledGlyphs(Display     *dpy,
				       XSTText      iText,
				       XSTPosition  iStartFrom,
				       XSTCount     iCharCount,
				       XSTCount    *oGlyphCount);
/** 
 * @} 
 */

#endif
