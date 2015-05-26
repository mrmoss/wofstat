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

/* @(#)Xst_font.h	1.18 04/07/27 SMI */

#ifndef _XSTFONT_H
#define _XSTFONT_H

#include "X11/Xmd.h"
#include "Xst_typedef.h"
#include "Xst_env.h"

/********************************* XSTFont General Defines **************************/

/******************************* XSTFont Function Prototypes ************************/

/** @defgroup Font XSTFont functions
 * @{
 */

/**
 * Returns an array of characters containing the name of the specified font. 
 * The iEnc parameter specifies the encoding format to use for the returned 
 * font name.  The ioLocale parameter allows the application to specify the desired 
 * language to return. If this language is not available, then the language of the  
 * returned string is returned in this space. This function allocates memory for the 
 * returned string. It is the callers responsiblity to free up this memory using
 * XSTFree(). Note that encodings other than unicode and glyph encodings may be
 * converted indecipherably by ICU.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFont			font ID
 * @param iEnc			encoding format to return
 * @param iNameID		NameTag that specifies the string
 * @param ioLocale		Locale/Language/Script of string
 * @param oCharCount		number of bytes in the string
 *
 * @return character array
 */
XSTString *XSTFontGetName(Display    *dpy, 
			  XSTTypeEnv  iEnv, 
			  XSTFont     iFont, 
			  XSTEncoding iEnc,
			  uint16_t    iNameID, 
			  XSTLocale  *ioLocale, 
			  XSTCount   *oCharCount);


/**
 * Returns the type of the font along with extended font information from a font. Any
 * of the output parameters can be NULL pointers, in that case ST will skip over them
 * when returning values. This function allocates memory for the name strings, uri, 
 * and the sbit array. It is the callers responsiblity to free up this memory by 
 * calling XSTFree(). 
 * Passing NULL for any of the output items results in that item not being returned.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFont			font ID
 * @param oFontName		Copy of the "C" locale font name
 * @param oPSName		Copy of the PostScript name of the font
 * @param oFlags		an OR-ed mask of font flags
 * @param oSbitCount		the number of the embedded bitmaps the font has
 * @param oSbitArray		array of sbit sizes
 * @param oFontMetrics		font metric information
 * @param oFontURL              uri name for the font
 *
 * @return XSTFontType value
 */
XSTFontType XSTFontGetInfo(Display          *dpy, 
			   XSTTypeEnv        iEnv, 
			   XSTFont           iFont, 
			   const char      **oFontName,
			   const char      **oPSName, 
			   XSTFontInfoFlags *oFlags, 
			   XSTCount         *oSbitCount, 
			   int             **oSbitArray, 
			   XSTFontMetrics   *oFontMetrics,
			   char            **oFontURL );

/** @} */

/** @defgroup FontFamily XSTFontFamily functions
 * @{
 */

/**
 * Returns an array of XSTFont IDs that are members of the font family. This function 
 * allocates memory for the XSTFont array. It is the callers responsiblity to free up 
 * this memory.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFontFamily		font family ID
 * @param oFontCount		number of fonts in the font family
 *
 * @return XSTFont ID array
 */
XSTFont *XSTFontFamilyGetFonts(Display      *dpy, 
			       XSTTypeEnv    iEnv,
			       XSTFontFamily iFontFamily,
			       XSTCount     *oFontCount);


/**
 * Returns a XSTFontFamily ID that the specified XSTFont (iFont) is a member. 
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFont			font ID
 *
 * @return XSTFontFamily ID 
 */
XSTFontFamily XSTFontGetFontFamily(Display   *dpy, 
				   XSTTypeEnv iEnv, 
				   XSTFont    iFont);


/**
 * Returns the Typeface name of the font. Examples of this would be Regular, Bold, 
 * etc.  The iEnc parameter specifies the encoding format to use for the 
 * returned font name. The ioLocale parameter allows the application to specify the 
 * desired language to return. If this language is not available, then the language  
 * of the returned string is returned in this space. This function allocates memory 
 * for the returned string. It is the callers responsiblity to free up this memory
 * using XSTFree(). Note that encodings other than unicode and glyph encodings may be
 * converted indecipherably by ICU.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFont			font ID
 * @param iEnc			encoding format to use for returned string
 * @param ioLocale		Locale/Language/Script of string
 * @param oCharCount		number of characters in the returned string
 * @param oWeight		font wieght
 * @param oWidth		font width
 * @param oStyle		font style
 *
 * @return string
 */
XSTString *XSTFontGetTypefaceName(Display            *dpy, 
				  XSTTypeEnv          iEnv,
				  XSTFont             iFont, 
				  XSTEncoding         iEnc, 
				  XSTLocale          *ioLocale, 
				  XSTCount           *oCharCount, 
				  XSTFontWeightClass *oWeight,
				  XSTFontWidthClass  *oWidth,
				  XSTFontStyle       *oStyle);

/**
 * Returns an array of characters containing the name of the specified font 
 * family. The iEnc parameter specifies the encoding format to use for the 
 * returned font name. The ioLocale parameter allows the application to specify the 
 * desired language to return. If this language is not available, then the language 
 * of the returned string is returned in this space. This function allocates memory 
 * for the returned string. It is allocates memory for the XSTFont array. It is the 
 * callers responsiblity to free up this memory using XSTFree(). Note that encodings 
 * other than unicode and glyph encodings may be converted indecipherably by ICU.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFontFamily		font family ID
 * @param iEnc			encoding format to use for returned string
 * @param ioLocale		Locale/Language/Script of string
 * @param oCharCount		number of characters in the returned string
 *
 * @return string
 */
XSTString *XSTFontFamilyGetName(Display       *dpy, 
				XSTTypeEnv     iEnv,
				XSTFontFamily  iFontFamily, 
				XSTEncoding    iEnc, 
				XSTLocale     *ioLocale,
				XSTCount      *oCharCount);

/**
 * @}
 */

#endif
