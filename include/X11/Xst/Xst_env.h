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

/* @(#)Xst_env.h	1.17 04/07/27 SMI */

#ifndef _XSTENV_H
#define _XSTENV_H

#include "Xst_typedef.h"

#include "Xst_private.h"

/******************************** XSTTypeEnv General Defines ************************/

/****************************** XSTTypeEnv Function Prototypes **********************/

/** @defgroup TypeEnv XSTTypeEnv functions
 * @{
 */

/**
 * Create a default STTypeEnv and return an XID of type XSTTypeEnv
 *
 * @param dpy			X Display value
 *
 * @return XSTTypeEnv XID
 */
XSTTypeEnv XSTTypeEnvNew(Display *dpy);


/**
 * Copy an existing STTypeEnv and return the new XID of the copied STTypeEnv
 *
 * @param dpy			X Display value
 * @param iEnv			original XSTTypeEnv XID of the STTypeEnv object to 
 *                                copy
 *
 * @return XSTTypeEnv XID
 */
XSTTypeEnv XSTTypeEnvNewCopy(Display *dpy, 
			     XSTTypeEnv iEnv);


/**
 * Call the STTypeEnv destructor. Free the XSTTypeEnv XID.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to delete
 *
 * @return none
 */
void XSTTypeEnvDispose(Display   *dpy, 
		       XSTTypeEnv iEnv);


/**
 * Returns the global font fallback policy.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 *
 * @return XSTFontFallbackPolicy value
 */
XSTFontFallbackPolicy XSTTypeEnvGetFontFallbackPolicy(Display   *dpy, 
						      XSTTypeEnv iEnv);


/**
 * Sets the global font fallback policy. All objects that use this STTypeEnv object 
 * will inherit this font fallback policy.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param iPolicy		a value that indicates the font fallback policy
 *
 * @return none
 */
void XSTTypeEnvSetFontFallbackPolicy(Display              *dpy, 
				     XSTTypeEnv            iEnv, 
				     XSTFontFallbackPolicy iPolicy);


/**
 * Returns the global font fallback array. This function allocates memory for the 
 * array and it is the responsiblity of the caller to free the memory when it is no 
 * longer used by calling XSTFree().
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param oFontCount		number of fonts in array
 *
 * @return XSTFont ID array
 */
XSTFont	*XSTTypeEnvGetFontFallbacks(Display   *dpy, 
				    XSTTypeEnv iEnv, 
				    XSTCount  *oFontCount);


/**
 * Sets the global font fallback array. This default setting can be overridden for the
 * text objects by calling XSTTextSetFontFallbacks(). When some glyphs are missing 
 * from fonts set by style objects, font fallbacks list will be searched for 
 * replacement fonts.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param iFontCount		number of fonts in array
 * @param iFontArray		array of XSTFont IDs.
 *
 * @return none
 */
void XSTTypeEnvSetFontFallbacks(Display   *dpy, 
				XSTTypeEnv iEnv,
				XSTCount   iFontCount, 
				XSTFont   *iFontArray);


/**
 * Finds a font family by its Unicode name and returns the first matching font family
 * ID. If the font famliy name (iName) is NULL, it returns the first available font 
 * family. If the iEnc parameter is XST_ENCODING_NOENCODING or XST_ENCODING_DEFAULT, 
 * then it uses the value retrieved from setlocale() and the assocated encoding. The
 * language ID is the requested language support of the font family. If the requested
 * language for the font is not available, then the language of the family name 
 * returned will be returned.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param iName			a byte encoded string that specifies the name
 * @param iNameLength		number of characters in the name
 * @param iEnc		        encoding format to return
 * @param ioLocale    		language requested and returned
 *
 * @return XSTFontFamily ID
 */
XSTFontFamily XSTTypeEnvFindFontFamily(Display     *dpy, 
				       XSTTypeEnv   iEnv,
				       XSTString   *iName, 
				       XSTCount     iNameLength,
				       XSTEncoding  iEnc, 
				       XSTLocale   *ioLocale);

/**
 * Finds all font families available to the Type Environment and returns an array of 
 * font family IDs. This function allocates memory for the returned array of font 
 * family IDs. It is the callers responsiblity to free up this memory using XSTFree().
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param oFontFamilyCount	number of font family IDs returned
 *
 * @return XSTFontFamily ID array
 */
XSTFontFamily *XSTTypeEnvFindAllFontFamilies(Display   *dpy, 
					     XSTTypeEnv iEnv,
					     XSTCount  *oFontFamilyCount);


/**
 * Returns an array of all font scalers available to this type environment. This 
 * function allocates memory for the returned array of scaler IDs. It is the callers 
 * responsiblity to free up this memory using XSTFree().
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param oScalerCount		number of scalers returned
 *
 * @return XSTScaler ID array
 */
XSTScaler *XSTTypeEnvFindAllScalers(Display   *dpy, 
				    XSTTypeEnv iEnv,
				    XSTCount  *oScalerCount);


/**
 * Returns a scaler ID based on its tag.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param iScalerTag		a tag assigned to the scaler. Known tags:
 *				iFontFusionScaler - 'FFUS' - FontFusion scaler
 *				iFreeType1Scaler - 'FTY1' - FreeType v. 1 scaler
 *				iFreeType2Scaler - 'FTY2' - FreeType v. 2 scaler
 *
 * @return XSTScaler ID
 */
XSTScaler XSTTypeEnvFindScaler(Display   *dpy, 
			       XSTTypeEnv iEnv,
			       XSTTag     iScalerTag);


/**
 * Returns a ST_LANGUAGE_* ST_LOCALE_* pair based on the iLocale value. If the 
 * iLocale parameter is NULL, then it uses the value retrieved from setlocale(). An 
 * example of a proper iLocale string would be: "en_US.UTF-8".
 *
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param iLocale		locale string 
 *
 * @return XSTLocale  
 */
XSTLocale XSTTypeEnvGetLocale(XSTTypeEnv iEnv, 
                	      char      *iLocale);


/**
 * Returns an array of all layout engines available to this type environment. This 
 * function allocates memory for the returned array of layout engine IDs. It is the 
 * callers responsiblity to free up this memory using XSTFree().
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param oLECount		number of layout engines returned
 *
 * @return XSTLayoutEngine ID array
 */
XSTLayoutEngine *XSTTypeEnvFindAllLayoutEngines(Display   *dpy, 
				                XSTTypeEnv iEnv,
				                XSTCount  *oLECount);


/**
 * Returns a scaler ID based on its tag.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param iLETag		a tag assigned to the layout engine.
 *
 * @return XSTLayoutEngine ID
 */
XSTLayoutEngine XSTTypeEnvFindLayoutEngine(Display   *dpy, 
			                   XSTTypeEnv iEnv,
			                   XSTTag     iLETag);


/**
 * @}
 */
#endif
