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

/* @(#)Xst_private.h	1.10 04/07/27 SMI */

#ifndef _XSTPRIV_H
#define _XSTPRIV_H

#ifdef LONG64
#define XREAD32TYPE long *
#else
#define XREAD32TYPE char *
#endif

#include "Xst_typedef.h"

/**
 * Finds a font by its name. If the font name (iName) is NULL, it returns the first
 * available font. The iNameID parameter indicates the name ID of the name, as 
 * defined in TrueType/OpenType specs. A special value of iNameID (ST_NAME_ANY) 
 * indicates that ST will search for the specified font name among all names. 
 * Standard name ID values are defined in sttags.h header file. If the iEnc 
 * parameter is XST_ENCODING_NOENCODING or XST_ENCODING_DEFAULT, then it uses the 
 * value retrieved from setlocale() to find the associated encoding.
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iName                 a native encoded string that specifies the name
 * @param iNameLength           number of characters in the name
 * @param iEnc                  encoding of name characters
 * @param iNameID               meaning of the name
 *
 * @return XSTFont ID
 */
XSTFont XSTTypeEnvFindFont(Display     *dpy,
                           XSTTypeEnv   iEnv,
                           XSTString   *iName,
                           XSTCount     iNameLength,
                           XSTEncoding  iEnc,
                           uint16_t     iNameID);

/**
 * Finds all fonts by their Unicode name and returns an array of font IDs. See
 * XSTTypeEnvFindFont() for more information. This function allocates memory for the 
 * array of font IDs returned. It is the callers responsiblity to free up this memory
 * using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iName                 a native encoded string that specifies the name
 * @param iNameLength           number of characters in the name
 * @param iEnc                  encoding of the name characters
 * @param iNameID               meaning of the name
 * @param oFontCount            number of XSTFont IDs returned
 *
 * @return XSTFont ID array
 */
XSTFont *XSTTypeEnvFindAllFonts(Display     *dpy,
                                XSTTypeEnv   iEnv,
                                XSTString   *iName,
                                XSTCount     iNameLength,
                                XSTEncoding  iEnc,
                                uint16_t     iNameID,
                                XSTCount    *oFontCount);

/**
 * Finds a font by its platform-specific name and returns the font ID. 
 * Platform-specific names are defined in TrueType/OpenType specs. STSF synthesizes 
 * TrueType-compliant names for non-TrueType fonts. iPlatformID, iEncodingID, 
 * iLanguageID, and iNameID have special values of ST_PLATFORM_ANY, ST_ENCODING_ANY, 
 * ST_LANGUAGE_ANY, and ST_NAME_ANY that indicate that their values do not matter. 
 * If the font name is NULL, the first font that satisfies the search criterion is 
 * returned.
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iName                 a byte encoded string that specifies the name
 * @param iNameLength           number of characters in the name
 * @param iPlatformID           platform ID
 * @param iEncodingID           platform-specific encoding ID
 * @param iLanguageID           language ID
 * @param iNameID               meaning of the name
 *
 * @return XSTFont ID
 */
XSTFont XSTTypeEnvFindFontByPlatformName(Display   *dpy,
                                         XSTTypeEnv iEnv,
                                         byte      *iName,
                                         XSTCount   iNameLength,
                                         uint16_t   iPlatformID,
                                         uint16_t   iEncodingID,
                                         uint16_t   iLanguageID,
                                         uint16_t   iNameID);

/**
 * Finds all fonts by their Platform name and returns an array of font IDs. See
 * XSTTypeEnvFindFontByPlatformName() for more information. This function allocates 
 * memory for the returned array of font IDs. It is the callers responsiblity to free
 * up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iName                 a byte encoded string that specifies the name
 * @param iNameLength           number of characters in the name
 * @param iPlatformID           platform ID
 * @param iEncodingID           platform-specific encoding ID
 * @param iLanguageID           language ID
 * @param iNameID               meaning of the name
 * @param oFontCount            number of font IDs returned
 *
 * @return XSTFont ID array
 */
XSTFont *XSTTypeEnvFindAllFontsByPlatformName(Display   *dpy,
                                              XSTTypeEnv iEnv,
                                              byte      *iName,
                                              XSTCount   iNameLength,
                                              uint16_t   iPlatformID,
                                              uint16_t   iEncodingID,
                                              uint16_t   iLanguageID,
                                              uint16_t   iNameID,
                                              XSTCount  *oFontCount);


/**
 * Creates one or more new fonts from the binary data supplied by the client, and 
 * returns an array of font IDs. Some font formats - like TTC - allow several logical
 * fonts within one binary font file, but most other font formats contain one logical
 * font per binary file. These newly created fonts are not searchable unless they are
 * permanently installed with XSTInstallFont(). This function allocates memory for 
 * the returned array of font IDs. It is the callers responsiblity to free up this 
 * memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iDataCount            number of binary data blocks
 * @param iData                 array of binary data blocks
 * @param iDataLength           array of binary data block lengths
 * @param oFontCount            number of font IDs returned
 *
 * @return XSTFont ID array
 */
XSTFont *XSTTypeEnvCreateFonts(Display   *dpy,
                               XSTTypeEnv iEnv,
                               XSTCount   iDataCount,
                               byte     **iData,
                               XSTCount  *iDataLength,
                               XSTCount  *oFontCount);

/**
 * Creates one or more new fonts from the file id supplied by the client, and 
 * returns an array of font IDs. Some font formats - like TTC - allow several logical
 * fonts within one binary font file, but most other font formats contain one logical
 * font per binary file. These newly created fonts are not searchable unless they are
 * permanently installed with XSTInstallFont(). This function allocates memory for 
 * the returned array of font IDs. It is the callers responsiblity to free up this 
 * memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iFile                 file id of font to create
 * @param oFontCount            number of font IDs returned
 *
 * @return XSTFont ID array
 */
XSTFont *XSTTypeEnvCreateFontsFromStream(Display   *dpy,
                                         XSTTypeEnv iEnv,
                                         int        iFile,
					 int       *oFontCount);

/**
 * Disposes of a font previously created with XSTCreateFonts(). This function will 
 * return an error code if an attempt is made to destroy a font that was not 
 * previously created with XSTCreateFonts(). All fonts that have not been explicitly 
 * destroyed will be destroyed when the Type Environment object from which they were 
 * created is destroyed.
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iFont                 font ID of a previously created font
 *
 * @return none
 */
void XSTTypeEnvDestroyFont(Display   *dpy,
                           XSTTypeEnv iEnv,
                           XSTFont    iFont);


/**
 * Returns the font ID associated with a particular signature value.
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iSignature            pointer to a buffer that contains the signature
 *
 * @return XSTFont ID
 */
XSTFont XSTTypeEnvFindFontBySignature(Display    *dpy,
				      XSTTypeEnv  iEnv,
				      const byte *iSignature);



/**
 * Returns an array of folder names (path names) indicating the user defined folders
 * to search for fonts. This function allocates memory for the returned array of
 * strings. It is the callers responsiblity to free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param oFolderCount          number of font folders returned
 *
 * @return array of strings
 */
char **XSTTypeEnvGetFontFolders(Display   *dpy,
                                XSTTypeEnv iEnv,
                                XSTCount  *oFolderCount);


/**
 * Sets the array of folder names (path names) to search for fonts.
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iFolderCount          number of font folders
 * @param iFolders              array of font folders
 *
 * @return none
 */
void XSTTypeEnvSetFontFolders(Display   *dpy,
                              XSTTypeEnv iEnv,
                              XSTCount   iFolderCount,
                              char     **iFolders);



/**
 * Sets the location mask indicating which areas to search for fonts
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iMask                 bitmask indicating which areas to search for fonts
 *
 * @return none
 */
void XSTTypeEnvSetLocations(Display            *dpy,
                            XSTTypeEnv          iEnv,
                            XSTFontLocationMask iMask);


/**
 * Returns the location mask indicating which areas to search for fonts
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 *
 * @return XSTFontLocationMask bitmask
 */
XSTFontLocationMask XSTTypeEnvGetLocations(Display   *dpy,
                                           XSTTypeEnv iEnv);

/**
 * Returns the set of font ids associated with a set of URLs.
 *
 * @param dpy                   X display pointer
 * @param iEnv                  TypeEnv XID (this is added to protocol message)
 * @param iURL                  URL string
 * @param oFontCount            number of XSTFont ids returned

 * @return an array of XSTFont
 */
XSTFont *XSTTypeEnvFindFontsByURL(Display   *dpy,
                                  XSTTypeEnv iEnv,
                                  char      *iURL,
                                  XSTCount  *oFontCount);


/**
 * Returns the set of font ids associated with a set of URLs.
 *
 * @param dpy                   X display pointer
 * @param iEnv                  TypeEnv XID (this is added to protocol message)
 * @param iURLCount             number of URL strings in iURL
 * @param iURL                  array of URL strings
 * @param oFontCount            number of XSTFont ids returned

 * @return an array of XSTFont
 */
XSTFont *XSTTypeEnvCreateFontsFromURL(Display   *dpy,
                                      XSTTypeEnv iEnv,
                                      XSTCount   iURLCount,
                                      char     **iURL,
                                      XSTCount  *oFontCount);








/**
 * Returns an array of name tag values extracted from a specified font. This function
 * allocates memory for the array of name tags returned. It is the callers 
 * responsiblity to free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFont                 font ID
 * @param oNameCount            number of retrieved string tags is stored here
 *
 * @return XSTNameTag array
 */
XSTNameTag XSTFontGetNameTags(Display   *dpy,
                              XSTTypeEnv iEnv,
                              XSTFont    iFont,
                              XSTCount  *oNameCount);


/**
 * Returns an array of bytes containing the name of the specified font. This function
 * allocates memory for the returned string. It is the callers responsiblity to free 
 * up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFont                 font ID
 * @param iNameTag              NameTag that specifies the string
 * @param oStringLength         number of bytes in the string
 *
 * @return byte array
 */
byte *XSTFontGetNameString(Display   *dpy,
                           XSTTypeEnv iEnv,
                           XSTFont    iFont,
                           XSTNameTag iNameTag,
                           XSTCount  *oStringLength);

/**
 * Returns the offsets of all baselines defined in the font from the Roman baseline.
 * This function allocates memory for the baselines. It is the callers responsiblity 
 * to free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFont                 font ID
 *
 * @return double array 
 */
double *XSTFontGetBaselines(Display         *dpy,
                            XSTTypeEnv       iEnv,
                            XSTFont          iFont,
			    XSTBaselineMask *oMask);

/**
 * Returns an array of features available in the font. This function allocates memory
 * for the feature array. It is the callers responsiblity to free up this memory.
 * using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to delete
 * @param iFont                 font ID
 * @param oFeatureCount         number of features in the returned array
 *
 * @return XSTFeatureTag array
 */
XSTFeatureTag *XSTFontGetFeatures(Display   *dpy,
                                  XSTTypeEnv iEnv,
                                  XSTFont    iFont,
                                  XSTCount  *oFeatureCount);


/**
 * Calculates a cryptographically-secure font signature and copies it to an allocated 
 * buffer pointed
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iFont                 font ID
 *
 * @return oSignature           a pointer to the allocated signature buffer
 *                              is stored there
 */
byte *XSTFontGetSignature(Display   *dpy,
                          XSTTypeEnv iEnv,
                          XSTFont    iFont);




/**
 * Sets layout engine and its parameters for this STStyle object.
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param iMask                 a set of XSTStyleMasks values OR'ed together or 
 *                                ST_SM_ALL change all values
 * @param iLayoutEngine         XSTLayoutEngine XID of the STLayoutEngine object to 
 *                                use
 *
 * @return none
 */
void XSTStyleSetLayoutEngine(Display        *dpy,
                             XSTStyle        iStyle,
                             XSTStyleMask    iMask,
                             XSTLayoutEngine iLayoutEngine);

/**
 * Returns the layout engine and its parameters for this STStyle object. The oMask 
 * parameter indicates which fields were previously set
 *
 * @param dpy                   X Display value
 * @param iStyle                XSTStyle XID of the STStyle object to use
 * @param oMask                 a set of XSTStyleMasks values OR'ed together
 *
 * @return XSTLayoutEngine value
 */
XSTLayoutEngine XSTStyleGetLayoutEngine(Display        *dpy,
                                        XSTStyle        iStyle,
                                        XSTStyleMask   *oMask);



/**
 * Returns the number of bytes in character prior to the one beginning at iBytePos
 *
 * @param iString               pointer to string of characters
 * @param iEnc                  Encoding of string. see Xst_enum.h for encoding types
 * @param iBytePos              Byte position of the start of character in the string
 *
 * @return number of bytes
 */
XSTCount XSTStringGetPrevCharacterSize(char       *iString,
                                       XSTPosition iBytePos,
                                       XSTEncoding iEnc);


/**
 * Returns the number of bytes in character after the one beginning at iBytePos
 *
 * @param iString               pointer to string of characters
 * @param iEnc                  Encoding of string. see Xst_enum.h for encoding types
 * @param iBytePos              Byte position of the start of a character in the string
 *
 * @return number of bytes
 */
XSTCount XSTStringGetNextCharacterSize(char       *iString,
                                       XSTPosition iBytePos,
                                       XSTEncoding iEnc);


/**
 * Returns the characters between bytes position iBytePosX and iBytePosY
 *
 * @param iString               pointer to string of characters
 * @param iEnc                  Encoding of string. see Xst_enum.h for encoding types
 * @param iBytePosX             Byte position of the start of character in the string
 * @param iBytePosY             Byte position of the start of character in the string
 *
 * @return number of characters
 */
XSTCount XSTStringCountCharactersFromXtoY(char       *iString,
                                          XSTPosition iBytePosX,
                                          XSTPosition iBytePosY,
                                          XSTEncoding iEnc);



/**
 * Returns the bytes between character position iCharacterPosX and iCharacterPosY
 *
 * @param iString               pointer to string of characters
 * @param iEnc                  Encoding of string. see Xst_enum.h for encoding types
 * @param iCharacterPosX        Character position of to begin at
 * @param iCharacterPosY        Character position of to end at
 *
 * @return number of bytes
 */
XSTCount XSTStringCountBytesFromXtoY(char       *iString,
                                     XSTPosition iCharacterPosX,
                                     XSTPosition iCharacterPosY,
                                     XSTEncoding iEnc);


/**
 * Returns the number of bytes used by the string
 *
 * @param iString               pointer to string of characters
 * @param iEnc                  Encoding of string. see Xst_enum.h for encoding types
 *
 * @return number of bytes
 */
XSTCount XSTStringLength(char       *iString,
                         XSTEncoding iEnc);

#endif
