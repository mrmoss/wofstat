/*
 * Copyright © 2002-2004 Sun Microsystems, Inc.
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
 * 3. Neither the name of Sun Microsystems, Inc. nor the names of 
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * This software is provided "AS IS," without a warranty of any kind.
 *
 * ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED.
 * SUN AND ITS LICENSORS SHALL NOT BE LIABLE FOR ANY DAMAGES OR
 * LIABILITIES SUFFERED BY LICENSEE AS A RESULT OF OR RELATING TO USE,
 * MODIFICATION OR DISTRIBUTION OF THE SOFTWARE OR ITS DERIVATIVES.
 * IN NO EVENT WILL SUN OR ITS LICENSORS BE LIABLE FOR ANY LOST REVENUE,
 * PROFIT OR DATA, OR FOR DIRECT, INDIRECT, SPECIAL, CONSEQUENTIAL,
 * INCIDENTAL OR PUNITIVE DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE
 * THEORY OF LIABILITY, ARISING OUT OF THE USE OF OR INABILITY TO USE
 * SOFTWARE, EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 */

/* $Id: st.h,v 1.2 2004/04/12 05:57:26 adg Exp $ */

/**
 * @file st.h
 * @brief Standard Type Services Framework API
 * @author Alexander Gelfenbain <adg@sun.com>
 * @version 0.11
 */

#ifndef __ST_H
#define __ST_H

#include <sttypes.h>


/*
 * Coordinate system units conventions
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  There are three different coordinate systems ST uses:
 *
 *  1. User space
 *  2. Device space
 *  3. Font design space
 *
 * To translate from user space to device space you multiply your
 * affine transformation matrix by your user space point:
 *
 * |xx xy tx|   |x|
 * |yx yy ty| * |y|
 * |0  0  1 |   |1|
 *
 * That gives you a set of equations:
 *
 * x' = xx * x + xy * y + tx
 * y' = yx * x + yy * y + ty
 *
 *
 * Units of the user space coordinate system are typographic points.
 * 1 point = 1/72 inch.
 *
 * Units of the device coordinate system are device-specific and are
 * not defined by ST. That means that in general each device
 * might have its initial transformation matrix different from the unity
 * matrix.
 *
 * Font design space units are abstract units used for measuring
 * unscaled glyphs. In order to convert them to something useful
 * in either user space or device space you need to scale them,
 * using the following formula:
 *
 * scaled user-space units in points = (pointSize / 1000) * design units
 * scaled user-space units in inches = (pointSize / 72 points per inch) * (design units/1000)
 *
 * In order to translate them to device space you will need to apply your transformation matrix.
 *
 * All units are represented as floating-point numbers
 *
 * Here is a very simple rule to figure out what coordinate system does a function use:
 *
 * All STFont*() functions use font design space
 * All ST functions that contain STDevice in their list of arguments use device space
 * All other ST functions use user space
 */

/*
 * Memory management functions.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

/** @defgroup MemMgr Memory management functions
 * @{
 */


/**
 * ST memory deallocator. 
 * Several ST Client Library functions allocate memory and return pointers
 * to it to the callers. The callers are supposed to explicitly deallocate
 * this memory by calling this function.
 *
 * @param iPointer            pointer to a memory segment previously allocated
 *                            by ST Client Library
 * 
 * 
 */
STStatus STFree(void *iPointer);

/**
 * @}
 */


/*
 *        Type Environment members
 *        ~~~~~~~~~~~~~~~~~~~~~~~~
 */

/** @defgroup TypeEnv STTypeEnv methods
 * @{
 */



/**
 * A default constructor for a type environment object.
 *
 * @param oEnv                on return a pointer to the new
 *                            type environment object is stored here
 *
 * @return status
 */
STStatus STTypeEnvNew(STTypeEnv *oEnv);

/**
 * A copy constructor for a type environment object.
 *
 * @param oEnv                on return a pointer to the new type environment
 *                            is stored here
 * @param iOldEnv             original type environment
 *
 * @return status
 */
STStatus STTypeEnvNewCopy(STTypeEnv *oEnv,
                          STTypeEnv iOldEnv);

/**
 * A type environment object destructor.
 *
 * @param iEnv                type environment object
 *
 * @return status
 */
STStatus STTypeEnvDispose(STTypeEnv iEnv);

/**
 * Sets the global font fallback policy. All objects that use this
 * Type Environment object will inherit this font fallback policy.
 *
 * @param iEnv                STTypeEnv object
 * @param iPolicy             a value that indicates the font fallback policy
 *
 * @return STStatus */
STStatus STTypeEnvSetFontFallbackPolicy(STTypeEnv iEnv,
                                        STFontFallbackPolicy iPolicy);

/**
 * Queries the global font fallback policy.
 * @param iEnv                STTypeEnv object
 * @param oPolicy             a value that indicates the font fallback policy
 *			      is returned here
 *
 * @return STStatus
 */
STStatus STTypeEnvGetFontFallbackPolicy(STTypeEnv iEnv,
                                        STFontFallbackPolicy *oPolicy);


/** 
 * Sets the global default list of fallback fonts. This default setting can be
 * overridden for text objects by calling STTextSetFontFallbacks(). 
 * When some glyphs are missing from fonts set by style 
 * objects, font fallbacks list will be searched for replacement fonts.
 *
 * @param iEnv                type environment object
 * @param iFontCount          number of fonts in the font array
 * @param iFontArray          array of fonts
 *
 * @return STStatus 
 */
STStatus STTypeEnvSetFontFallbacks(STTypeEnv iEnv,
                                   STCount iFontCount,
                                   STFont *iFontArray);

/**
 * Returns the global font fallback array.
 * This function allocates memory for the array and it is the
 * responsibility of the caller to free the memory when it is no longer used.
 *
 * @param iEnv                type environment object
 * @param oFontCount          number of fonts
 * @param oFontArray          array of fonts
 *
 * @return STSTatus
 */
STStatus STTypeEnvGetFontFallbacks(STTypeEnv iEnv,
                                   STCount *oFontCount,
                                   STFont **oFontArray);



/**
 * Enumerates all font scalers available to this type environment.
 *
 * @param iEnv                type environment object
 * @param oScalerCount        returns the number of found scalers
 * @param oScalerArray        allocated array of scaler IDs
 *
 * @return STStatus
 */
STStatus STTypeEnvFindAllScalers(STTypeEnv iEnv,
                                 STCount *oScalerCount,
                                 STScaler **oScalerArray);


/**
 * Finds a scaler by its tag.
 *
 * @param iEnv                type environment object
 * @param iTag                a tag assigned to the scaler. Known tags:
 *                            iFontFusionScaler - 'FFUS' - FontFusion scaler
 *                            iFreeType1Scaler - 'FTY1' - FreeType v. 1 scaler
 *                            iFreeType2Scaler - 'FTY2' - FreeType v. 2 scaler 
 * @param oScaler             returns a scaler ID
 *
 * @return STStatus
 */
STStatus STTypeEnvFindScaler(STTypeEnv iEnv,
                             STTag iTag,
                             STScaler *oScaler);

/**
 * Enumerates all layout engines available to this type environment.
 * There is always at least one layout engine available to a type environment.
 * The first layout engine in the output array of layout engine IDs is
 * the default layout engine.
 *
 * @param iEnv                type environment object
 * @param oLECount            returns the number of layout engines
 * @param oLEArray            allocated array of layout engines IDs
 *
 * @return STStatus
 */
STStatus STTypeEnvFindAllLayoutEngines(STTypeEnv iEnv,
                                       STCount *oLECount,
                                       const STLayoutEngine **oLEArray);


/**
 * Finds a layout engine by its tag.
 *
 * @param iEnv                type environment object
 * @param iTag                a tag assigned to the layout engine
 * @param oLayoutEngine       returns a scaler ID
 *
 * @return STStatus
 */
STStatus STTypeEnvFindLayoutEngine(STTypeEnv iEnv,
                                   STTag iTag,
                                   STLayoutEngine *oLayoutEngine);



/**
 * Specifies a list of directories STSF will scan for fonts
 * in addition to pre-defined locations.
 * Setting iFolderCount to 0 makes STSF scan only pre-defined
 * font locations
 *
 *
 * @param iEnv                type environment
 * @param iFolderCount        number of directories in the iFolders array
 * @param iFolders            array of directories
 *
 * @return STStatus
 */
STStatus STTypeEnvSetFontFolders(STTypeEnv iEnv,
                                 STCount iFolderCount,
                                 char **iFolders);

/**
 * Returns a list of directories previously set with
 * STTypeEnvSetFontFolders. Memory is  allocated by STSF
 * and it is the responsibility of the caller to call
 * STFree() on all strings and then on the array.
 *
 * @param iEnv                type environment
 * @param oFolderCount        number of directories in the oFolders array
 * @param oFolders            array of directories
 *
 * @return STStatus
 */
STStatus STTypeEnvGetFontFolders(STTypeEnv iEnv,
                                 STCount *oFolderCount,
                                 char ***oFolders);

/**
 * @}
 */

/** @defgroup Scaler Scaler and LayoutEngine object methods
 * @{
 */

/**
 * Retrieves general information from the scaler.
 *
 * @param iEnv                type environment object
 * @param iScaler             scaler ID
 * @param oTag                scaler tag. Well known tags are defined in sttags.h
 * @param oVersion            scaler version
 * @param oSFlags             scaler flags
 * @param oFFlags             font types supported by the scaler
 * @param oShortName          short name of the scaler that can be used in selection menues
 * @param oLongName           free-form scaler name
 * @param oNotice             free-form copyright notice
 *
 * @return STStatus
 */
STStatus STScalerGetInfo(STTypeEnv iEnv,
                         STScaler iScaler,
                         STTag *oTag,
                         uint32_t *oVersion,
                         const char **oShortName,
                         const char **oLongName,
                         const char **oNotice,
                         STScalerFlags *oSFlags,
                         STFontMask *oFFlags);

/**
 * Scaler ioctl - exchange control information with the scaler.
 *
 * @param iEnv                type environment object
 * @param iScaler             STStyle object
 * @param iToScaler           this data is sent to the scaler
 * @param iToByteCount        number of bytes in iToScaler
 * @param oFromScaler         if scaler returns any data the pointer to an
 *                            allocated buffer that holds this data is 
 *			      stored here
 * @param oFromByteCount      number of bytes returned from the scaler
 *
 * @return STStatus
 */
STStatus STScalerControl(STTypeEnv iEnv,
                         STScaler iScaler,
                         void *iToScaler,
                         STSize iToByteCount,
                         const void **oFromScaler,
                         STSize *oFromByteCount);

/**
 * Retrieves general information from the layout engine..
 *
 * @param iEnv                type environment object
 * @param iLayoutEngine       layout engine ID
 * @param oTag                layout engine tag. Well known tags are defined in sttypes.h (ST_LAYOUTENGINE_* constants)
 * @param oVersion            layout engine version
 * @param oLEFlags             layout engine flags
 * @param oShortName          short name (for user menues)
 * @param oLongName           free-form name of the layout engine
 * @param oNotice             free-form copyright notice
 *
 * @return STStatus
 */
STStatus STLayoutEngineGetInfo(STTypeEnv iEnv,
                               STLayoutEngine iLayoutEngine,
                               STTag *oTag,
                               uint32_t *oVersion,
                               const char **oShortName,
                               const char **oLongName,
                               const char **oNotice,
                               STLayoutEngineFlags *oLEFlags);

/**
 * Layout Engine ioctl - exchange control information with the layout engine.
 *
 * @param iEnv                type environment object
 * @param iLayoutEngine       STLayoutEngine object
 * @param iToLayoutEngine     this data is sent to the scaler
 * @param iToByteCount        number of bytes in iToLayoutEngine
 * @param oFromLayoutEngine   if the layout engine returns any data the pointer to an
 *                            allocated buffer that holds this data is 
 *			      stored here
 * @param oFromByteCount      number of bytes returned from the layout engine
 *
 * @return STStatus
 */
STStatus STLayoutEngineControl(STTypeEnv iEnv,
                               STLayoutEngine iLayoutEngine,
                               void *iToLayoutEngine,
                               STSize iToByteCount,
                               const void **oFromLayoutEngine,
                               STSize *oFromByteCount);

/**
 * @}
 */


/*
 * Font methods.
 * They require a type environment object as their first argument.
 */

/** @defgroup Font Font methods
 * @{
 */



/**
 * Extracts a string specified by the name ID from the font and normalizes
 * it to Unicode.
 *
 * @param iEnv                type environment object
 * @param iFont               font ID
 * @param iNameID             named ID
 * @param ioLanguage          requested language. If STSF does not find the requested
 *                            language and substitutes it with a different language,
 *                            stores it in *ioLanguage and returns ST_LANGUAGE_CHANGED status code
 * @param oCharCount          the length of the resulting string is stored here
 * @param oStringData         address of a pointer that on return will point 
 *			      to memory allocated by this function that holds
 *			      name string data.
 * @return STStatus
 */
STStatus STFontGetUnicodeName(STTypeEnv iEnv,
                              STFont iFont,
                              uint16_t iNameID,
                              STLanguage *ioLanguage,
                              STCharCount *oCharCount,
                              const utf16 **oStringData);


/**
 * Reads binary data from the font file. STSF synthesizes sfnt-style
 * tables for all fonts. 
 *
 * @param iEnv                type environment object
 * @param iFont               font ID
 * @param iTable              sfnt table tag. A special tag of 0x00000000 denotes 
 *                            the entire font file the way it is stored in
 *                            the filesystem.
 * @param oByteCount          points to a variable that contains numbert of bytes
 *                            in the returned buffer.
 * @param oRawData            a pointer to the variable that points to an allocated
 *                            by the function memory area that contains the requested
 *                            binary font file data.
 * 
 */
STStatus STFontGetData(STTypeEnv iEnv,
                       STFont iFont,
                       STTag iTable,
                       STSize  *oByteCount,
                       const byte **oRawData);
                             

/**
 * Retrieves extended font information from a font. Any of the output parameters can be
 * NULL pointers, in that case ST will skip over them when returning values.
 *
 * @param iEnv                type environment object
 * @param iFont               a fontID
 * @param oFontName 	      ST allocates memory and copies the "C" locale 
 * 			      font name to it and stores a pointer to the 
 * 			      newly allocated memory there
 * @param oPSName             ST allocates memory and copies the PostScript
 *			      name of the font to it and stores a pointer to 
 *			      the newly allocated memory there
 * @param oType               STFontServer - specific font type
 * @param oFlags              an OR-ed mask of font flags
 * @param oSbitCount          the number of the embedded bitmaps the font has
 * @param oSbitArray          array of sbit sizes allocated by ST
 * @param oFontMetrics        font metric information
 * @param oFontURI            the URI of the font is stored here
 *
 * @return STStatus
 * */
STStatus STFontGetInfo(STTypeEnv iEnv,
                       STFont iFont,
                       STFontType *oType,
                       const char **oFontName,
                       const char **oPSName,
                       STFontInfoFlags *oFlags,
                       int *oSbitCount,
                       const int **oSbitArray,
                       STFontMetrics *oFontMetrics,
                       const char **oFontURI);


/** @} */

/** @defgroup FontFamily Font family methods
 * @{
 */


/**
 * Finds a font family by its name.
 *
 * @param iEnv                type environment object
 * @param iName               a UTF-16 string that specifies the name
 * @param iNameLength         number of UTF-16 characters in the name
 * @param ioLanguage          requested language. If STSF does not find the requested
 *                            language and substitutes it with a different language,
 *                            the new language is stored here
 * @param oFontFamily         a pointer to STFont variable where on
 *                            return the resulting font ID is stored
 *
 * @return STStatus
 */
STStatus STTypeEnvFindFontFamily(STTypeEnv iEnv,
                                 const utf16 *iName,
                                 STCharCount iNameLength,
                                 STLanguage *ioLanguage,
                                 STFontFamily *oFontFamily);

/**
 * Finds all font families.
 * 
 *
 * @param iEnv                type environment object
 * @param oFontFamilyCount    a pointer to a variable where on return
 *                            the number of returned fontIDs is stored
 * @param oFontFamily         a pointer to an array of STFont variables where
 *                            the resulting font IDs are stored on return.
 *                            If this pointer is NULL the function just counts
 *                            all fonts with the name iName.
 *                            The array is allocated inside this function,
 *                            and the caller is responsible for freeing up
 *                            the memory.
 *                            
 *
 * @return STStatus
 */
STStatus STTypeEnvFindAllFontFamilies(STTypeEnv iEnv,
                                      STCount *oFontFamilyCount,
                                      STFontFamily **oFontFamily);

/**
 * Enumerate all fonts that a member of a font family and
 * return their IDs.
 *
 * @param iEnv                a type environment object
 * @param iFontFamily         a font family ID
 * @param oFontCount          returns the number of fonts in the font family
 * @param oFontArray          returns an array of  font IDs of the member fonts
 *
 * @return STStatus
 *
 */
STStatus STFontFamilyGetFonts(STTypeEnv iEnv,
                              STFontFamily iFontFamily,
                              STCount *oFontCount,
                              STFont **oFontArray);

/**
 * Return a Unicode font family name for a specified language.
 *
 * @param iEnv                a type environment object
 * @param iFontFamily         a font family ID
 * @param ioLanguage          requested language. If STSF does not find the requested
 *                            language and substitutes it with a different language,
 *                            the new language is stored here
 * @param oCharCount          number of characters in the name
 * @param oStringData         UTF-16 name of the font family
 *
 * @return STError
 */
STStatus STFontFamilyGetName(STTypeEnv iEnv,
                             STFontFamily iFontFamily,
                             STLanguage *ioLanguage,
                             STCharCount *oCharCount,
                             utf16 **oStringData);
/**
 * Returns a font family that the font belongs to.
 * Each font belongs to only one font family.
 * To query font family name of the font call
 * STFontFamilyGetName() after retrieving the font family
 * of the font with this function.
 *
 * @param iEnv                a type environment object
 * @param iFont               a font ID
 * @param oFontFamily         the font family iFont belongs to is stored here
 *
 * @return STError
 */
STStatus STFontGetFontFamily(STTypeEnv iEnv,
                             STFont iFont,
                             STFontFamily *oFontFamily);

/**
 * Returns a typeface name and classification of the font.
 * The typeface name  is always relative to the font family
 * the font belongs to.
 *
 * For example, in a "Times New Roman" font family
 * there are four typefaces "Regular", "Italic",
 * "Bold", and "Bold Italic". That's what this function returns.
 *
 * STFontGetNameString() will return "Times New Roman" for the
 * font that this function returns "Regular"
 *
 * Some of all output parameters (oStringData, oWidth, oWeight, oStyle)
 * can be NULL pointers.
 *
 * @param iEnv                a type environment object
 * @param iFont               a font ID
 * @param ioLanguage          requested language. If STSF does not find the requested
 *                            language and substitutes it with a different language,
 *                            the new language is stored here
 * @param oCharCount          number of characters in the name
 * @param oStringData         UTF-16 name of the typeface
 * @param oWeight             font weight
 * @param oWidth              font width 
 * @param oStyle              font style
 *
 * @return STError
 */
 
STStatus STFontGetTypefaceName(STTypeEnv iEnv,
                               STFont iFont,
                               STLanguage *ioLanguage,
                               STCharCount *oCharCount,
                               utf16 **oStringData,
                               STFontWeightClass *oWeight,
                               STFontWidthClass *oWidth,
                               STFontStyle *oStyle);

/**
 * @}
 */

/*
 * STGraphics & STDevice methods
 */

/** @defgroup Graphics Graphics environment methods
 * @{
 */

/**
 * Creates a new graphics environment. A graphics environment contains
 * an output device and rendering parameters.
 *
 * @param oGraphics           STGraphics object
 *
 */
STStatus STGraphicsNewEmpty(STGraphics *oGraphics);

/**
 * Creates a new graphics environment and assigns an output device
 * and rendering parameters to it.
 *
 * @param oGraphics           STGraphics object
 * @param iDevice             STDevice object
 * @param iOutputMode         specifies an output mode of this graphics
 *			      environment
 * @param iColorMask          defines how many and which colors are included
 *                            in the iColors array
 * @param iColors             array of RGBA colors that contain as many elements
 *                            as there are "on" bits in iColorMask
 *                            This array defines colors in the same order
 *                            as bits in STGraphicsColorMask are defined.
 *                            For example, to set just text and strikethrough colors
 *                            set iColorMask to ST_GM_COLOR_TEXT | ST_GM_COLOR_ST
 *                            and pass array of two colors in iColors argument, such
 *                            as iColors[0] is the desired text color and iColors[1]
 *                            is the desired strikethrough color
 *
 * @return STStatus
 */
STStatus STGraphicsNew(STGraphics *oGraphics,
                       STDevice iDevice,
                       STOutputMode iOutputMode,
                       STGraphicsColorMask iColorMask,
                       STRGBAColor *iColors);

/**
 * Graphics environment copy constructor.
 *
 * @param oGraphics           STGraphics  object
 * @param iOldGraphics        graphics environment being cloned
 *
 * @return STStatus
 */
STStatus STGraphicsNewCopy(STGraphics *oGraphics,
                           STGraphics iOldGraphics);

/**
 * Graphics environment destructor.
 *
 * @param iGraphics           STGraphics object
 *
 * @return STStatus
 */
STStatus STGraphicsDispose(STGraphics iGraphics);

/**
 * Sets device and the output mode.
 *
 * @param iGraphics           STGraphics object
 * @param iDevice             STDevice object
 * @param iOutputMode         specifies rendering mode
 *
 * @return STStatus
 */
STStatus STGraphicsSetDevice(STGraphics iGraphics,
                             STDevice iDevice,
                             STOutputMode iOutputMode);
/**
 * Queries previously set device and the output mode.
 *
 * @param iGraphics           STGraphics object
 * @param oDevice             STDevice object
 * @param oOutputMode         specifies rendering mode
 *
 * @return STStatus
 */
STStatus STGraphicsGetDevice(STGraphics iGraphics,
                             STDevice *oDevice,
                             STOutputMode *oOutputMode);

/**
 * Sets graphics colors.
 *
 * @param iGraphics           STGraphics object
 * @param iColorMask          defines how many and which colors are included
 *                            in the iColors array
 * @param iColors             array of RGBA colors that contain as many elements
 *                            as there are "on" bits in iColorMask
 *                            This array defines colors in the same order
 *                            as bits in STGraphicsColorMask are defined.
 *                            For example, to set just text and strikethrough colors
 *                            set iColorMask to ST_GM_COLOR_TEXT | ST_GM_COLOR_ST
 *                            and pass array of two colors in iColors argument, such
 *                            as iColors[0] is the desired text color and iColors[1]
 *                            is the desired strikethrough color
 *
 * @return STStatus
 */
STStatus STGraphicsSetColors(STGraphics iGraphics,
                             STGraphicsColorMask iColorMask,
                             STRGBAColor *iColors);


/**
 * Queries graphics colors.
 *
 * @param iGraphics           STGraphics object
 *
 * @param oColorMask          address of the bitmask that on return defines how many and which 
 *                            colors are included in the oColors array
 * @param oColors             address of the array of RGBA colors allocated by this function
 *                            that contain as many elements as there are "on" bits in oColorMask
 *                            This array defines colors in the same order
 *
 * @return STStatus
 */
STStatus STGraphicsGetColors(STGraphics iGraphics,
                             STGraphicsColorMask *oColorMask,
                             STRGBAColor **oColors);

/**
 * Resets one or more colors to their default values.
 *
 * @param iGraphics          STGraphics object
 * @param iColorMask         specifies which colors to reset
 *
 * @return STStatus
 */

STStatus STGraphicsResetColors(STGraphics iGraphics,
                               STGraphicsColorMask iColorMask);

/**
 * Returns the current transformation matrix of an STDevice object.
 *
 * @param iDevice             STDevice object
 * @param oMatrix             transformation matrix is stored there
 *
 * @return STStatus
 */
STStatus STGraphicsGetMatrix(STGraphics iGraphics,
                             STMatrix *oMatrix);
/**
 * Replaces the current transformation matrix with a new one.
 *
 * @param iDevice             STDevice object
 * @param iMatrix             new transformation matrix
 *
 * @return STStatus
 */
STStatus STGraphicsSetMatrix(STGraphics iGraphics,
                             STMatrix iMatrix);

/**
 * Concatenates the current transformation matrix with the new one.
 *
 * @param iDevice             STDevice object
 * @param iMatrix             transformation matrix
 *
 * @return STStatus
 */
STStatus STGraphicsConcatMatrix(STGraphics iGraphics,
                                STMatrix iMatrix);

/**
 * Concatenates the current transformation matrix with a translate transform.
 *
 * @param iDevice             STDevice object
 * @param tx                  x offset
 * @param ty                  y offset
 *
 * @return STStatus
 */
STStatus STGraphicsTranslate(STGraphics iGraphics,
                             double tx,
                             double ty);
/**
 * Concatenates the current transformation matrix with a scale transform.
 *
 * @param iDevice             STDevice object
 * @param sx                  x scale factor
 * @param sy                  y scale factor
 *
 * @return STStatus
 */
STStatus STGraphicsScale(STGraphics iGraphics,
                         double sx,
                         double sy);

/**
 * Concatenates the current transformation matrix with a rotate transform.
 *
 * @param iDevice             STDevice object
 * @param theta               the rotation angle in radians
 *
 * @return STStatus
 */
STStatus STGraphicsRotate(STGraphics iGraphics,
                          double theta);

/**
 * Concatenates the current transformation matrix with a shear transform.
 *
 * @param iDevice             STDevice object
 * @param shx                 x shear factor
 * @param shy                 y shear factor
 *
 * @return STStatus
 */
STStatus STGraphicsShear(STGraphics iGraphics,
                         double shx,
                         double shy);

/** @} */

/*
 *  Style
 */

/** @defgroup Style Style methods
 * @{
 */

/**
 * Creates a new empty Style. Style is a unit of formatting
 * information applied to a sequence of characters in an STText
 * object. It has several attributes that can be set and copied from
 * one Style to another.
 *
 * @param oStyle              pointer to the newly created Style is stored here
 * @param iEnv                a pointer to the TypeEnv
 *
 * @return STStatus */
STStatus STStyleNewEmpty(STStyle *oStyle,
                         STTypeEnv iEnv);
                         
/**
 * Creates a new Style with the attributes set to default values.
 *
 * @param oStyle              pointer to the newly created Style is stored here
 * @param iEnv                a pointer to the TypeEnv
 *
 * @return STStatus
 */
STStatus STStyleNewDefault(STStyle *oStyle,
                           STTypeEnv iEnv);
                         

/**  
 * Creates a copy of iOldStyle.
 *
 * @param oNewStyle           pointer to the newly created Style is stored here
 * @param iOldStyle           a Style that is duplicated
 *
 * @return STStatus
 */
STStatus STStyleNewCopy(STStyle *oNewStyle,
                        STStyle iOldStyle);
                        

/**
 * A Style destructor.
 *
 * @param iStyle              Style object being deallocated
 *
 * @return STStatus
 */
STStatus STStyleDispose(STStyle iStyle);

/**
 * Compare two STStyle objects.
 *
 * @param iLhs                a left hand side of the comparison
 * @param iMask		      mask of attributes to include in comparsion
 * @param iRhs                a right hand side of the comparison
 * @param oResult             the result of the comparison is stored here
 *
 * @return STStatus
 */
STStatus STStyleCompare(STStyle iLhs,
                        STStyleMask iMask,
                        STStyle iRhs,
                        STStyleComparison *oResult);

/**
 * Checks if a Style is empty, i.e. no attributes were assigned to it.
 *
 * @param iStyle              a Style object
 * @param oResult             the result is stored there
 *
 * @return STStatus
 */
STStatus STStyleIsEmpty(STStyle iStyle,
                        STBoolean *oResult);

/**
 * Removes specified attributes from a Style.
 *
 * @param iStyle              a Style object
 * @param iMask		      a set of STStyleMasks values, or'ed together
 *			      or ST_SM_ALL to clear all values
 *
 * @return STStatus
 */
STStatus STStyleRemoveAttributes(STStyle iStyle,
                                 STStyleMask iMask);

/**
 * Resets all Style attributes to their default values.
 *
 * @param iStyle              a Style object
 * @param iMask		      set of bitflags OR'ed together to indicate which
 *	       		      fields in the STStyle object are to be reset
 *
 * @return STStatus
 */
STStatus STStyleResetAttributes(STStyle iStyle,
                                STStyleMask iMask);

/**
 * Copies attributes set in the source Style object to the destination Style 
 * object.  Attributes not set in the source object are unset in the
 * destination object.
 *
 * @param iToStyle            destination style object
 * @param iMask               bitmask of attributes to copy
 * @param iFromStyle          source style object
 *
 * @return STStatus
 *
 */
STStatus STStyleCopyAttributes(STStyle iToStyle,
                               STStyleMask iMask,
                               STStyle iFromStyle);

/**
 * Copies only those attributes from the source style object that are also
 * set in the destination Style object.
 *
 * @param iToStyle            destination Style object
 * @param iMask               bitmask of attributes to copy
 * @param iFromStyle          source style object
 *
 * @return STStatus
 *
 */
STStatus STStyleOverwriteAttributes(STStyle iToStyle,
                                    STStyleMask iMask,
                                    STStyle iFromStyle);

/**
 * Copies only those attributes from the source Style object that are
 * not set in the destination Style object.
 *
 * @param iToStyle            destination Style object
 * @param iMask               bitmask of attributes to copy
 * @param iFromStyle          source Style object
 *
 * @return STStatus
 *
 */
STStatus STStyleUnderwriteAttributes(STStyle iToStyle,
                                     STStyleMask iMask,
                                     STStyle iFromStyle);



/**
 * Sets font-related attributes of the STStyle. If some of the attributes
 * set by this function are not to be changed, a special value of the
 * corresponding parameter is used.
 * 
 * @param iStyle              a STSTyle object
 * @param iMask		      set of bitflags OR'ed together to indicate which
 *			      fields in the STStyle object are to be set
 *			      to the values of the following parameters
 * @param iFont               font ID 
 * @param iSize               font size measured in typographic points
 * @param iLanguage           language of the style
 * @param iBaseline           the dominant baseline for this style
 *
 * @return STStatus
 *
 */
STStatus STStyleSetFont(STStyle iStyle,
                        STStyleMask iMask,
                        STFont iFont,
                        double iSize,
                        STLanguage iLanguage,
                        STBaselineFlag iBaseline);

/**
 * Retrieves font-related attributes from the STStyle object.
 * If some of the attributes are of no interest to the caller, a NULL
 * pointer may be passed instead of an address of a variable.
 *
 * @param iStyle              an STStyle object
 * @param oMask		      Pointer to bitmask which will be set to the
 *			      OR'ed together bit flags indicating which
 *			      fields in the STStyle object have been
 *			      set by the client application
 * @param oFont               a font ID 
 * @param oSize               font size measured in typographic points
 * @param oLanguage           language of the style
 * @param oBaseline           a dominant baseline for this style
 *
 * @return STStatus
 */
STStatus STStyleGetFont(STStyle iStyle,
                        STStyleMask *oMask,
                        STFont *oFont,
			double *oSize,
                        STLanguage *oLanguage,
                        STBaselineFlag *oBaseline);

/**
 * Sets scaler and its parameters for the STStyle object
 *
 * @param iStyle              STStyle object
 * @param iMask               a bitmask that indicates what paramaeters are set
 * @param iScaler             STScaler object
 * @param iHints              specifies if the scaler should use hints 
 * @param iSbits              specifies if the scaler should use 
 *			      embedded bitmaps
 *
 * @return STStatus
 */
STStatus STStyleSetScaler(STStyle iStyle,
                          STStyleMask iMask,
                          STScaler iScaler,
                          STHintingMode iHints,
                          STSbitsMode iSbits);


/**
 * Retrieves scaler and its parameters from the STStyle object
 *
 * @param iStyle              STStyle object
 * @param oMask		      Pointer to bitmask which will be set to the
 *			      OR'ed together bitflags indicating which
 *			      fields in the STStyle object have been
 *			      set by the client application
 * @param oScaler             STScaler object
 * @param oHints              specifies if the scaler should use hints
 * @param oSbits              specifies if the scaler should use 
 *			      embedded bitmaps
 *
 * @return STStatus
 */
STStatus STStyleGetScaler(STStyle iStyle,
                          STStyleMask *oMask,
                          STScaler *oScaler,
                          STHintingMode *oHints,
                          STSbitsMode *oSbits);



                            
/**
 * Sets some effects-related attributes for the STStyle object.
 *
 * @param iStyle              an STStyle object
 * @param iMask		      set of bitflags OR'ed together to indicate which
 *			      fields in the STStyle object are to be set
 *			      to the values of the following parameters
 * @param iStyleEffects       an ORed mask of STStyleEffects values
 * @param iStrikeThrough      an ORed mask of STStrikeThrough values
 * @param iUnderline          an ORed mask of STUnderline values 
 *				
 *
 *
 * @return STStatus
 */

STStatus STStyleSetEffects(STStyle iStyle,
                           STStyleMask iMask,
                           STStyleEffects iStyleEffects,
                           STStrikeThrough iStrikeThrough,
                           STUnderline iUnderline);

/**
 * Retrieves previously set effects-related attributes. If a caller wants to
 * query only some of the attributes, the other parameters may be set to NULL.
 *
 * @param iStyle              an STStyle object
 * @param oMask		      Pointer to bitmask which will be set to the
 *				OR'ed together bitflags indicating which
 *				fields in the STStyle object have been
 *				set by the client application
 * @param oStyleEffects       an ORed mask of STStyleEffects values
 *				or fStyleEffectsNotSet constant
 * @param oStrikeThrough an ORed mask of STStrikeThroughEffects values
 *				or fStrikeThroughEffectsNotSet constant
 * @param oUnderline   an ORed mask of STUnderlineEffects values
 *				or fUnderlineEffectsNotSet constant
 *
 * @return STStatus
 */
STStatus STStyleGetEffects(STStyle iStyle,
                           STStyleMask *oMask,
                           STStyleEffects *oStyleEffects,
                           STStrikeThrough *oStrikeThrough,
                           STUnderline *oUnderline);


/**
 * Sets additional style options.
 *
 * @param iStyle              a style object
 * @param iMask		      set of bitflags OR'ed together to indicate which
 *			      fields in the STStyle object are to be set
 *			      to the values of the following parameters
 * @param iImposeWidth        weight factor for font-defined glyph widths
 * @param iBeforeWithStreamShift weight factor for with-stream shift
 *                            applied before each glyph
 * @param iAfterWithStreamShift weight factor for with-stream shift
 *                            applied after each glyph
 * @param iCrossStreamShift   cross-stream shift weight factor
 * @param iHangingInhibitFactor hanging glyph weight factor
 * @param iKerningInhibitFactor kerning weight factor
 * @param iDecompositionInhibitFactor ligature decomposition weight factor
 *
 * @return STStatus
 */
STStatus STStyleSetOptions(STStyle iStyle,
                           STStyleMask iMask,
                           int iImposeWidth,
                           int iBeforeWithStreamShift,
                           int iAfterWithStreamShift,
                           int iCrossStreamShift,
                           int iHangingInhibitFactor,
                           int iKerningInhibitFactor,
                           int iDecompositionInhibitFactor);

/**
 * Retrieves additional style options.
 *
 * @param iStyle              a style object
 * @param oMask		      set of bitflags OR'ed together to indicate which
 *			      fields in the STStyle object are to be set
 *			      to the values of the following parameters
 * @param oImposeWidth        weight factor for font-defined glyph widths
 * @param oBeforeWithStreamShift weight factor for with-stream shift
 *                            applied before each glyph
 * @param oAfterWithStreamShift weight factor for with-stream shift
 *                            applied after each glyph
 * @param oTracking           tracking weight factor
 * @param oCrossStreamShift   cross-stream shift weight factor
 * @param oHangingInhibitFactor hanging glyph weight factor
 * @param oKerningInhibitFactor kerning weight factor
 * @param oDecompositionInhibitFactor ligature decomposition weight factor
 *
 * @return STStatus
 */

STStatus STStyleGetOptions(STStyle iStyle,
                           STStyleMask *oMask,
                           int *oImposeWidth,
                           int *oBeforeWithStreamShift,
                           int *oAfterWithStreamShift,
                           int *oCrossStreamShift,
                           int *oTracking,
                           int *oHangingInhibitFactor,
                           int *oKerningInhibitFactor,
                           int *oDecompositionInhibitFactor);


/**
 * Retrieves baselines position for a style. Baseline positions are
 * measured as offsets from the baseline specified by iBaseline.
 * This function stores the value of the baselines in the array of
 * STBaseline values it allocates.
 *
 * @param iStyle              Style object
 * @param iBaseline           baseline from which offsets are measured
 * @param oBaselineMask       indicates which and how many baselines are returned in the 
 *                            oBaselines array. 
 * @param oBaselines          pointer to the array where the result is stored. The array
 *                            is allocated by the function and contains as many entries
 *                            as there are "on" bits in oBaselineMask (up to 32)
 *
 * @return STStatus
 */
STStatus STStyleCalculateBaselines(STStyle iStyle,
                                   STBaselineFlag iBaseline,
                                   STBaselineMask *oBaselineMask,
                                   STBaseline **oBaselines);

/**
 * Retrieves design metrics for the style based on scaled font design metrics.
 * Returned metrics is in user space.
 *
 * @param iStyle              Style object
 * @param oMetrics            style metrics is stored there
 * @return STStatus
 */
STStatus STStyleGetDesignMetrics(STStyle iStyle,
                                 STLineMetrics *oMetrics);

/**
 * Sets a client private value into the Style data space
 *
 * @param iStyle              Style object
 * @param iData               client private data to set
 * @return STStatus
 */
STStatus STStyleSetPrivateData(STStyle iStyle,
                               STPointer iData);

/**
 * Gets the client private value into the Style data space
 *
 * @param iStyle              Style object
 * @param oData               client private data returned
 * @return STStatus
 */
STStatus STStyleGetPrivateData(STStyle iStyle,
                               STPointer *oData);
/** @} */


/*
 *        Text object
 */

/** @defgroup g5 STText methods
 * @{
 */

/**
 * Creates a new STText - Text object. STText is an opaque object
 * that represents a unit of text and styles associated with it.
 *
 * STText object does not duplicate source text, instead it stores
 * pointer to it.  It is the user's responsibility to maintain the source
 * text buffer, insert and remove text from it and notify STText of it
 * by calling STTextChangeText.
 *
 * STText uses coordinates relative to the upper-left corner of its
 * typographic bounding box.
 *
 * STText consists of one or more lines of text (STLine object.)
 * A line of text is an atomic displayable unit of text in ST.
 *
 * Styles (STStyle object) are assigned to STText. If none are assigned
 * a default style is taken from STTypeEnv.
 *
 * STText has several  attributes:
 *        - Width
 *        - Global Direction
 *        - Justification
 *        - Alignment
 *        - Language
 *
 *
 * @param oText               pointer to the newly created STText is
 *                            stored there
 * @param iEnv                STTypeEnv object
 *
 */
STStatus STTextNewEmpty(STText *oText,
                        STTypeEnv iEnv);

/**
 * Creates a new STText and assign text to it.
 *
 * @param oText               points to the newly created STText object
 * @param iEnv                STTypeEnv object
 * @param iChars              a pointer to the beginning of a paragraph of text
 * @param iCharCount          number of characters in a paragraph of text
 */
STStatus STTextNew(STText *oText,
                   STTypeEnv iEnv,
                   utf16 *iChars,
                   STCharCount iCharCount);

/**
 * Duplicates an existing STText
 *
 * @param oText               points to the newly created STText object
 * @param iOldText            original STText object
 *
 */
STStatus STTextNewCopy(STText *oText,
                       STText iOldText);

/**
 * Destroys an existing STText object
 *
 * @param iText               STText object to be destroyed
 *
 */
STStatus STTextDispose(STText iText);


/**
 * Restores the state of the STText to its initial state -
 *        - removes all assigned text
 *        - removes all layout attributes
 *
 * @param iText               STText to be cleared
 *
 * @return STStatus
 *
 */
STStatus STTextClear(STText iText);


/**
 * Sets one or more STText metrics attributes. STText itself does not use any
 * of these attributes but all lines derived from an STText object inherit
 * them.
 *
 * @param iText               STText object
 * @param iMask               set of OR'ed bitflags that indicates which metric values 
 *                            (memebers of iLineMetrics structure) a user wants to set
 * @param iLineMetrics        line metrics imposed on lines of text or NULL
 * @param iBaselineMask       indicates which and how many baselines are in the iBaselines array
 * @param iBaselines          baselines imposed on lines of text or NULL
 *
 * @return STStatus
 *
 */
STStatus STTextSetMetrics(STText iText,
                          STTextMask iMask,
                          STExtLineMetrics *iLineMetrics,
                          STBaselineMask iBaselineMask,
                          STBaseline *iBaselines);

/**
 * Retrieves previously set STText metrics attributes.
 *
 * @param iText               STText object
 * @param oMask               set of OR'ed bitflags that indicates which metric values 
 *                            (memebers of iLineMetrics structure) a user has previously set
 * @param oLineMetrics        returns a pointer to previously set line metrics
 *			      structure or NULL if none was set
 * @param oBaselineMask       returns a bitmask that indicates which and how many
 *                            baselines were previously set by STTextSetMetrics()
 * @param oBaselines          returns a pointer to previously set baselines
 *			      array or NULL if none was set
 *
 * @return STStatus
 */
STStatus STTextGetMetrics(STText iText,
                          STTextMask *oMask,
                          STExtLineMetrics *oLineMetrics,
                          STBaselineMask *oBaselineMask,
                          STBaseline **oBaselines);

/**
 * Sets one or more STText controls
 *
 * @param iText               STText object
 * @param iMask		      set of bitflags OR'ed together to indicate which
 *				fields in the STText object are to be set
 *				to the values of the following parameters
 * @param iDirection          specifies text directionality or CDirectionNotSet
 * @param iJustification      specifies text justification
 *			      	or CJustificationNotSet
 * @param iFlushFactor        specifies text alignment or CFlushFactorNotSet
 * @param iLanguage           specifies text language or CLanguageNotSet
 * @param iPolicy             specifies font fallback policy 
 *				or CFontFallbackPolicyNotSet
 *
 * @return STStatus
 */
STStatus STTextSetControls(STText iText,
                           STTextMask iMask,
                           STDirection iDirection,
                           STJustification iJustification,
                           STFlushFactor iFlushFactor,
                           STLanguage iLanguage,
                           STFontFallbackPolicy iPolicy);

/**
 * Retrieves previously set STText controls
 *
 * @param iText               STText object
 * @param oMask		      Pointer to bitmask which will be set to the
 *			      OR'ed together bitflags indicating which
 *			      fields in the STText object have been
 *			      set by the client application
 * @param oDirection          text directionality
 * @param oJustification      text justification
 * @param oFlushFactor        text alignment
 * @param oLanguage           text language
 * @param oPolicy             font fallback policy
 *
 * @return STStatus
 */
STStatus STTextGetControls(STText iText,
                           STTextMask *oMask,
                           STDirection *oDirection,
                           STJustification *oJustification,
                           STFlushFactor *oFlushFactor,
                           STLanguage *oLanguage,
                           STFontFallbackPolicy *oPolicy);

/**
 * Specifies a list of fonts for displaying characters missing from
 * fonts set by Style objects for the STText object. The order of
 * fonts in the list matters: the search starts from the first font in
 * the list and continues until all missing characters are found.
 *
 *
 * @param iText               STText object
 * @param iFontCount          number of fonts in the array
 * @param iFontArray          array of font IDs
 *
 * @return STStatus
 */
STStatus STTextSetFontFallbacks(STText iText,
                                STCount iFontCount,
                                STFont *iFontArray);

/**
 * Returns a list of substitution fonts set for this text layout object. This
 * function allocates memory for the array of font IDs, and the caller is 
 * supposed to free it.
 *
 * @param iText               STText object
 * @param oFontCount          number of fonts
 * @param oFontArray          font IDs are stored in this array
 *
 * @return STStatus
 */
STStatus STTextGetFontFallbacks(STText iText,
                                STCount *oFontCount,
                                STFont **oFontArray);


/**
 * Copies attributes set by STTextSetMetrics() and STTextSetControls() 
 * and the font fallback list from one STText to another.
 *
 * @param iTo                 destination STText
 * @param iMask               bitmask of attributes to copy
 * @param iFrom               source STText
 *
 * return STStatus
 */
STStatus STTextCopyAttributes(STText iTo,
                              STTextMask iMask,
                              STText iFrom);

/**
 * Restores default STText attributes. Attributes include all properties
 * of STText objects that have a correspoding bit in STTextMask mask:
 * metrics, baselines, controls and the fallback policy.
 * The only two properties of STText objects that are not 'attributes'
 * are text and styles.
 *
 * @param iText               STText
 * @param iMask               bitmask of attributes to copy
 *
 * return STStatus
 */
STStatus STTextResetAttributes(STText iText,
                               STTextMask iMask);


/**
 * Removes previously set text attributes. For example removing
 * the fallback attribute causes the STText object to use the
 * value inherited from the parent STTypeEnv object.
 *
 * @param iText               STText
 * @param iMask               bitmask of attributes to copy
 *
 * return STStatus
 */
STStatus STTextRemoveAttributes(STText iText,
                                STTextMask iMask);



/**
 * Assigns text to an STText object. STText object does not create a private
 * copy of this text, it keeps a pointer to it, so  it is responsibility of 
 * the caller to maintain the text buffer, insert and delete text from it,
 * etc.
 *
 * @param iText               STText object
 * @param iChars              a pointer to the beginning of a paragraph of text
 * @param iCharCount          number of characters in a paragraph of text
 *
 * return STStatus
 */
STStatus STTextSetText(STText iText,
                       utf16 *iChars,
                       STCharCount iCharCount);

/**
 * Retrieves source text information from the STText object.
 *
 * @param iText               STText object
 * @param oChars              pointer to the character array
 * @param oCharCount          number of characters
 *
 * return STStatus
 */
STStatus STTextGetText(STText iText,
                       utf16 **oChars,
                       STCharCount *oCharCount);


/**
 * Retrieves an array of styled glyphs that correspond to a range of
 * logical text from a text object. ST allocates an array of styled
 * glyphs and it is the responsibility of the caller to free the memory.
 * This function also returns an array of style objects. The caller
 * is responsible for disposing of the style objects.
 *
 *
 * @param iText               a text object
 * @param iStartFrom          index of the first character or ST_BEGINNING
 * @param iCharCount          number of characters in the range or ST_ALL
 * @param oGlyphCount         number of styled glyphs
 * @param oGlyphs             array of styled glyphs
 * @param oStyleCount         number of elements in the array of style objects
 * @param oStyles             array of pointers to style objects
 *
 * @return STStatus
 */

STStatus STTextGetStyledGlyphs(STText iText,
                               STPosition iStartFrom,
                               STCharCount iCharCount,
                               STCount *oGlyphCount,
                               STStyledGlyph **oGlyphs,
                               STCount *oStyleCount,
                               STStyle ***oStyles);
                               

/**
 * Informs the STText object that the text has been inserted or deleted.
 *
 * @param iText               STText object
 * @param iChange             notifies STText whether characters were
 *				inserted or removed
 * @param iStartFrom          position where text has been inserted or deleted
 * @param iCharCount         number of added or removed characters
 *
 * return STStatus
 */
STStatus STTextUpdate(STText iText,
                      STTextChanged iChange,
                      STPosition iStartFrom,
                      STCharCount iCharCount);


/**
 * Assigns a Style to a sequence of characters of an STText object.
 * STText creates a copy of the Style by calling its copy constructor,
 * that it deallocates when STText's destructor is called.
 *
 * @param iText               STText object
 * @param iStyle              Style object
 * @param iStartFrom          the first character that iStyle applies to
 * @param iCharCount          number of characters iStyle applies to
 *
 * return STStatus
 */
 
STStatus STTextSetStyle(STText iText,
                        STStyle iStyle,
                        STPosition iStartFrom,
                        STCharCount iCharCount);

/**
 * Returns a copy of a Style object assigned to character at offset
 * iTextOffset in the STText object.  The caller is responsible for calling
 * the Style's destructor when it is no longer needed.
 *
 * @param iText               STText
 * @param iPosition           offset of the character being queried
 * @param oStyle              pointer to the Style object returned here
 * @param oStartFrom          offset of the first character belonging to
 *				the Style
 * @param oCharCount          number of character in the Style
 *
 * return STStatus
 */
STStatus STTextGetStyle(STText iText,
                        STPosition iPosition,
                        STStyle *oStyle,
                        STPosition *oStartFrom,
                        STCharCount *oCharCount);

/**
 * Creates a new Style object that represents all common style characteristics
 * of a set of characters in an STText
 * @param iText               STText
 * @param iStartFrom          offset of the character being queried
 * @param iCharCount          number of characters being queried
 * @param oStyle              pointer to the Style object is returned here
 *
 * return STStatus
 */
STStatus STTextGetCommonStyle(STText iText,
                              STPosition iStartFrom,
                              STCharCount iCharCount,
                              STStyle *oStyle);


/**
 * Attributes in the styles assigned to the iText object from iStartFrom to 
 * iStartFrom + iCharCount are replaced if present, or added if not, with 
 * style attributes set in the iStyle object. If necessary iText styles 
 * are split and new styles created and assigned to the text object.
 *
 * @param iText               a text object
 * @param iStartFrom          offset of the first character
 * @param iCharCount          number of characters
 * @param iStyle              style attributes from this style are used
 */
STStatus STTextAugmentStyle(STText iText,
                            STPosition iStartFrom,
                            STCharCount iCharCount,
                            STStyle iStyle);

/**
 * All attributes set in the styles assigned to the iText object from
 * iStartFrom to iStartFrom + iCharCount that are also set in the iStyle
 * object are replaced with style attributes from iStyle object.
 * If necessary iText styles are split and new styles created and assigned
 * to the text object.
 *
 * @param iText               a text object
 * @param iStartFrom          offset of the first character
 * @param iCharCount          number of characters
 * @param iStyle              style attributes from this style are used
 */
STStatus STTextOverwriteStyle(STText iText,
                              STPosition iStartFrom,
                              STCharCount iCharCount,
                              STStyle iStyle);
/**
 * All attributes not set in the styles assigned to the iText object from
 * iStartFrom to iStartFrom + iCharCount but  set in the iStyle
 * object are replaced with style attributes from iStyle object.
 * If necessary iText styles are split and new styles created and assigned
 * to the text object.
 *
 * @param iText               a text object
 * @param iStartFrom          offset of the first character
 * @param iCharCount          number of characters
 * @param iStyle              style attributes from this style are used
 */
STStatus STTextUnderwriteStyle(STText iText,
                               STPosition iStartFrom,
                               STCharCount iCharCount,
                               STStyle iStyle);

/**
 * Finds all text segments that contain missing characters and returns
 * font IDs for the substituted fonts used to render these segments.
 * This function allocates memory for three arrays (oSegOffset,
 * oSegLength, and oFontArray) and the caller is supposed to free it.
 *
 * @param iText               STText object
 * @param oSegCount           number of segments with missing characters
 *			       is stored here
 *                            oSegOffset, oSegLength, and oFontArray arrays
 *			       contain oSegCount elements
 * @param oSegOffset          array of offsets to first characters in segments
 *				with missing characters
 * @param oSegLength          number of characters in each segment
 * @param oFontArray          array of font IDs that were substituted for the
 *				default fonts 
 *
 * @return STStatus 
 */
STStatus STTextFindMissingChars(STText iText,
                                STCount *oSegCount,
                                STPosition **oSegOffset,
                                STCharCount **oSegLength,
                                STFont **oFontArray);

/** @} */

/** @defgroup Line Line methods
 * @{
 */

/**
 * Creates a new STLine object. STLine is a unit of displayable
 * text. It is derived from STText object and refers its text. A
 * line-breaking algorithm can be implemented by sequentually adding
 * characters to the STLine object and measuring its typographic
 * bounds.
 *
 * @param oLine               pointer to the constructed STLine object
 * @param iText               STText object being broken into lines
 * @param iStartFrom          an offset from the first character of the 
 *		       	      STText object
 * @param iCharCount          number of characters to add to the line. A 
 *				special value of ST_CHARCOUNT_TOEND adds all STText
 *				characters to this STLine object
 * @param oCharCount          actual number of added characters is stored here
 *
 * @return STStatus */
STStatus STLineNew(STLine *oLine,
                   STText iText,
                   STPosition iStartFrom,
                   STCharCount iCharCount,
                   STCharCount *oCharCount);

/**
 * Creates a new STLine object with as many characters as can fit within 
 * the width specified by iWidth.
 *
 * @param oLine               pointer to the constructed STLine object
 * @param iText               STText object being broken into lines
 * @param iStartFrom           an offset from the first character of the 
 *                            STText object
 * @param iWidth              text width of the line in typographic points.
 *                            To use text width set for the parent STText
 *			      object use the value of 0
 *                            
 * @param oCharCount          actual number of added characters is stored here
 *
 * @return STStatus
 */
STStatus STLineNewForWidth(STLine *oLine,
                           STText iText,
                           STPosition iStartFrom,
                           double iWidth,
                           STCharCount *oCharCount);

/**
 * STLine destructor
 *
 * @param iLine               STLine object
 *
 * @return STStatus
 */
STStatus STLineDispose(STLine iLine);


/**
 * Adds characters to the beginning or to the end of the line. This function is
 * used for creating customized line-break algorithms.
 *
 * @param iLine               STLine object
 * @param iAppend             true if characters are appended,
 *			      false if prepended
 * @param iCharCount          specifies the number of added characters.
 *                            The negative number indicates that line shrinks
 *                            instead of growing.
 *
 * @return STStatus
 */
STStatus STLineGrow(STLine iLine,
                    STBoolean iAppend,
                    STCharCount iCharCount);


/**
 * Queries line position within STText object
 *
 * @param iLine               STLine object
 * @param oStartFrom           returns a first character offset of the line
 *				within STText
 * @param oCharCount          returns a number of characters in the line
 *
 * @return STStatus
 */
STStatus STLineGetPosition(STLine iLine,
                           STPosition *oStartFrom,
                           STCharCount *oCharCount);

/**
 * Retrieves design metrics for the line based on scaled font design metrics.
 * Returned metrics is in user space.
 *
 * @param iLine              Line object
 * @param oMetrics            metrics is stored there
 * @return STStatus
 */
STStatus STLineGetDesignMetrics(STLine iLine,
                                STExtLineMetrics *oMetrics);


/**
 * Imposes metrics on a line.
 *
 * @param iLine               STLine
 * @param iMask               set of OR'ed bitflags that indicates which metric values 
 *                            (memebers of iLineMetrics structure) a user wants to set
 * @param iLineMetrics        sets ascent and descent or NULL pointer to use
 *				the value derived from its parent STText object
 * @param iBaselineMask       indicates how many and which baselines are set in the 
 *                            iBaselines array
 * @param iBaselines          baselines of this line of text or NULL pointer
 *				to use the value derived from its parent
 *				STText object
 *
 * @return STStatus
 */
STStatus STLineSetMetrics(STLine iLine,
                          STTextMask iMask,
                          STExtLineMetrics *iLineMetrics,
                          STBaselineMask iBaselineMask,
                          STBaseline *iBaselines);

/**
 * Queries metrics previously imposed on a line.
 *
 * @param iLine               STLine
 * @param oLineMetrics        address of the structure whre previously set
 *                            line metric values are stored
 *			      structure or NULL if none was set
 * @param oLineMetrics        ascent and descent
 * @param oBaselineMask       baseline mask
 * @param oBaselines          array of baselines, allocated by the function
 *
 * @return STStatus
 */
STStatus STLineGetMetrics(STLine iLine,
                          STTextMask *oMask,
                          STExtLineMetrics *oLineMetrics,
                          STBaselineMask *oBaselineMask,
                          STBaseline **oBaselines);

/**
 * Calculates a typographic bounding rectangle in user space of a line
 * ignoring all imposed metrics and attributes.
 *
 * @param iLine               STLine object
 * @param oBBox               bounding box values are stored here on return
 *
 * @return STStatus
 */
STStatus STLineMeasureText(STLine iLine,
                           STRectanglePtr oBBox);

/**
 * Calculates a standard bounding rectangle of a laid-out line of text after
 * all attributes (justification, alignment, etc.) have been applied in user
 * space.
 *
 * @param iLine               STLine object
 * @param iGraphics           STGraphics object that includes either a raster
 *				or an outline device
 * @param oBBox               bounding box values are stored in this
 *				structure on return
 */
 
STStatus STLineMeasureTextImage(STLine iLine,
				STGraphics iGraphics,
                                STRectanglePtr oBBox);

/**
 * Calculates boundaries of glyphs of a final laid-out line in device 
 * coordinates.
 *
 * @param iLine               STLine object
 * @param iGraphics           STGraphics object that includes either a raster
 *				or an outline device
 * @param iMaxBoundsCount     specifies the precision of the output - the 
 *				maximal number of trapezoids the
 *				function can allocate to store glyph
 *				bounds.  Set it to 1 if only one
 *				trapezoid for the entire line is
 *				requested
 * @param iBounds                specifies the type of origin used for 
 *				calculating bounds
 * @param oBoundsCount        number of trapezoids in the oBounds array
 * @param oBounds             array of bounding trapezoids
 *                            
 *
 */
STStatus STLineGetGlyphBounds(STLine iLine,
                              STGraphics iGraphics,
                              int iMaxBoundsCount,
                              STBounds iBounds,
                              int *oBoundsCount,
                              STTrapezoidPtr *oBounds);
                                  

/**
 * Converts a pair of coordinates to the logical character offset.
 *
 * @param iLine               STLine object
 * @param iX                  X coordinate relative to the UL corner of the
 *				line bounding rectangle
 * @param iY                  Y coordinate relative to the UL corner of the
 *				line bounding rectangle
 * @param oPrimaryOffset      logical offset of the glyph closest to 
 *				(iX, iY) coordinates
 * @param oIsLeading          is hit leading or trailing
 * @param oSecondaryOffset    if (iX, iY) are on a line direction boundary
 *				this gives the second logical offset.
 */
STStatus STLineHitTest(STLine iLine,
                       double iX,
                       double iY,
                       STPosition *oPrimaryOffset,
                       STBoolean *oIsLeading,
                       STPosition *oSecondaryOffset);

/**
 * Returns one or two carets (strong and weak) for a specified logical
 * character position
 *
 * @param iLine               STLine object
 * @param iCharOffset         logical offset of the character within STLine's
 *		       	      parent STText object
 * @param iIsLeading          matters only if character at iOffset is at line
 *				direction boundary
 * @param oStrongCaret        denotes primary (or main if oSplitCaret is 
 *				false) caret
 * @param oWeakCaret          denotes secondary (or main if oSplitCaret is
 *				false) caret
 * @param oSplitCaret         indicates if character at iOffsets is at line
 *				direction boundary
 *
 */
STStatus STLinePositionToCaret(STLine iLine,
                               STPosition iCharOffset,
                               STBoolean iIsLeading,
                               STCaret *oStrongCaret,
                               STCaret *oWeakCaret,
                               STBoolean *oSplitCaret);

/**
 * Calculates a new position of the caret. The caret can be moved by
 * characters, words or Unicode clusters. Direction can be previous,
 * next, left or right. When the initial position of the caret is on a
 * line direction boundary, this function calculates the new position
 * of the primary caret. Inside an LTR text and not on the direction
 * boundary "next" is equivalent to "right," and "previous" is
 * equivalent to "left." Inside an RTL text "next" is equivalent to
 * "left" and "previous" is equivalent to "right."  For vertical text
 * "left" is "top" and "right" is "bottom"
 *
 * @param iLine               STLine object
 * @param iOffset             initial caret position
 * @param iDirection          specifies direction - left, right, next,
 *				or previous
 * @param iMovementType       specifies movement type - character, word, 
 *				or cluster
 * @param oOffset             new caret position
 *
 * @return STStatus 
 */
STStatus STLineMoveCaret(STLine iLine,
                         STPosition iOffset,
                         STCaretDirection iDirection,
                         STCaretMovement iMovementType,
                         STPosition *oOffset);
                            
/**
 * Retrieves an array of styled glyphs that correspond to a range of
 * logical text from a line object. ST allocates an array of styled
 * glyphs and it is the responsibility of the caller to free the memory.
 * This function also returns an array of style objects. The caller
 * is responsible for disposing of the style objects.
 *
 * @param iLine               a text object
 * @param iStartFrom          index of the first character or ST_BEGINNING
 * @param iCharCount          number of characters in the range or ST_ALL
 * @param oGlyphCount         number of styled glyphs
 * @param oGlyphs             array of styled glyphs
 * @param oStyleCount         number of elements in the array of style objects
 * @param oStyles             array of pointers to style objects
 *
 * @return STStatus
 */
STStatus STLineGetStyledGlyphs(STLine iLine,
                               STPosition iStartFrom,
                               STCharCount iCharCount,
                               STCount *oGlyphCount,
                               STStyledGlyph **oGlyphs,
                               STCount *oStyleCount,
                               STStyle ***oStyles);


/**
 * Renders text represented by an STLine object on an STRastderDevice.
 * 
 *
 * @param iLine               STLine object
 * @param iGraphics           STGraphics object
 *
 * @return STStatus
 */
STStatus STLineRender(STLine iLine,
                      STGraphics iGraphics);


/**
 * Adds a highlighted region identified by the first character and the number
 * of characters to an STLine object. STLineRender() needs to be called to 
 * display it.
 *
 * @param iLine               STLine object
 * @param iStartFrom         first character to highlight
 * @param iCharCount          number of characters in the highlighted region.
 *
 * @return STStatus
 */
STStatus STLineAddHighlight(STLine iLine,
                            STPosition iStartFrom,
                            STCharCount iCharCount);

/**
 * Removes a highlighted region from the text layout.
 *
 * @param iLine               STLine object
 * @param iStartFrom         offset to the first character to remove
 *				highlighting from
 * @param iCharCount          number of characters in the region
 *
 * @return STStatus
 */
STStatus STLineRemoveHighlight(STLine iLine,
                               STPosition iStartFrom,
                               STCharCount iCharCount);

/**
 * Queries currently defined highlighted regions.
 *
 * @param iLine               a line object
 * @param oRegionCount        number of highlighted regions
 * @param oStartFrom         array of first first character offsets of
 *                            highlighted regions
 * @param oCharCount          array of lengths of highlighted regions
 *
 * @return STStatus
 */
STStatus STLineGetHighlights(STLine iLine,
                             STCount *oRegionCount,
                             STPosition **oStartFrom,
                             STCharCount **oCharCount);

/** @} */


/** @defgroup GlyphVector Glyph vector methods
 * @{
 */


/**
 * Creates a new glyph vector. A glyph vector is a dynamic array of
 * positioned attributed glyphs (styled glyphs.) 
 * All postprocessed text can be represented as a glyph vector.
 *
 * @param oGlyphVector        a glyph vector
 * @param iEnv                a type environment object
 * @param iSource             an array of styled glyphs
 * @param iGlyphCount         number of styled glyphs in the source array
 *
 * @return STStatus
 */
STStatus STGlyphVectorNew(STGlyphVector *oGlyphVector,
                          STTypeEnv iEnv,
                          STStyledGlyph *iSource,
                          STCount iGlyphCount);

/**
 * Creates a copy of a glyph vector.
 *
 * @param oGlyphVector        on return a newly allocated glyph vector is stored there
 * @param iOldGlyphVector     a glyph vector
 *
 * @return STStatus
 */
STStatus STGlyphVectorNewCopy(STGlyphVector *oGlyphVector,
                              STGlyphVector iOldGlyphVector);

/**
 * Deallocates a glyph vector.
 *
 * @param iGlyphVector
 *
 * @return STStatus
 */
STStatus STGlyphVectorDispose(STGlyphVector iGlyphVector);


/**
 * Assigns styled glyphs to a glyph vector replacing existing
 * styled glyphs.
 *
 * @param iGlyphVector        a glyph vector
 * @param iGlyphs             an array of styled glyphs
 * @param iGlyphCount         number of styled glyphs in the glyph array
 *
 * @return STStatus
 */
STStatus STGlyphVectorSetGlyphs(STGlyphVector iGlyphVector,
                                STStyledGlyph *iGlyphs,
                                STCount iGlyphCount);
 
/**
 * Retrieves an array of styled glyphs from a glyph vector.
 * Memory is allocated by ST and the caller is responsible for
 * deallocating it.
 *
 * @param iGlyphVector        a glyph vector
 * @param iStartFrom          the first glyph
 * @param ioGlyphCount        number of glyphs request, on return contains the number
 *                            of glyphs in the output array
 * @param oGlyphs             an array of styled glyphs
 * @param oStyleCount         number of styles returned
 * @param oStyleArray         address of an array of pointers to STStyle objects referenced
 *                            by the returned styled glyphs
 *
 * @return STStatus
 */
STStatus STGlyphVectorGetGlyphs(STGlyphVector iGlyphVector,
                                STPosition iStartFrom,
                                STCount *ioGlyphCount,
                                STStyledGlyph **oGlyphs,
                                STCount *oStyleCount,
                                STStyle ***oStyleArray);

/**
 * Replaces some styled glyphs in a glyph vector with new
 * glyphs. The number of new glyphs and the number of replaced
 * glyphs do not have to be the same.
 *
 * @param iGlyphVector        a glyph vector
 * @param iStartFrom          first glyph to replace
 * @param iGlyphCount         the number of glyphs to replace. If this number is 0,
 *                            new glyphs are inserted after glyph iStartFrom
 * @param iGlyphArray         an array of styled glyphs or NULL.
 * @param iGlyphArraySize     number of glyphs in the iGlyphArray. If iGlyphArray is NULL,
 *                            this number has to be 0.
 *                            If iGlyphArraySize is 0 and iGlyphCount is greater than 0,
 *                            iGlyphCount glyphs are removed from the glyph vecrot.
 * @return STStatus
 */
STStatus STGlyphVectorReplaceGlyphs(STGlyphVector iGlyphVector,
                                    STPosition iStartFrom,
                                    STCount iGlyphCount,
                                    STStyledGlyph *iGlyphArray,
                                    STCount iGlyphArraySize);

/**
 * Adjust X and Y positions of a range of glyphs in a glyph vector by the same
 * amount.
 *
 * @param iGlyphVector        a glyph vector
 * @param iStartFrom          first glyph in the range or ST_BEGINNING
 * @param iGlyphCount         number of glyphs in the range or ST_ALL
 * @param iDelta              a value which the that glyphs positions are adjusted by
 *
 * @return STStatus
 */
STStatus STGlyphVectorAdjustPositions(STGlyphVector iGlyphVector,
                                      STPosition iStartFrom,
                                      STCount iGlyphCount,
                                      STPoint iDelta);

/**
 * Calculates a typographic bounding rectangle of a range of glyphs of the
 * glyph vector in user space.
 *
 * @param iGlyphVector        a glyph vector
 * @param iStartFrom          first glyph in the range or ST_BEGINNING 
 * @param iGlyphCount         number of glyphs in the range or ST_ALL 
 * @param oBBox               returned bounding box values
 *
 * @return STStatus
 */
STStatus STGlyphVectorMeasure(STGlyphVector iGlyphVector,
                              STPosition iStartFrom,
                              STCount iGlyphCount,
                              STRectangle *oBBox);
                              

/**
 * Calculates boundaries of a range of glyphs of a glyph vector in device space.
 *
 * @param iGlyphVector        a glyph vector
 * @param iStartFrom          first glyph in the range or ST_BEGINNING 
 * @param iGlyphCount         number of glyphs in the range or ST_ALL 
 * @param iGraphics           a graphics object -  a raster or an outline device
 * @param iMaxBoundsCount     specifies the precision of the output - the 
 *			      maximal number of trapezoids the
 *			      function can allocate to store glyph
 *			      bounds.  Set it to 1 if only one
 *			      trapezoid for the entire line is
 *			      requested
 * @param iBounds             specifies the type of origin used for 
 *			      calculating bounds
 * @param oBoundsCount        number of trapezoids in the oBounds array
 * @param oBounds             array of bounding trapezoids
 *                            
 * @return STStatus
 */
STStatus STGlyphVectorGetBounds(STGlyphVector iGlyphVector,
                                STPosition iStartFrom,
                                STCount iGlyphCount,
                                STGraphics iGraphics,
                                int iMaxBoundsCount,
                                STBounds iBounds,
                                int *oBoundsCount,
                                STTrapezoidPtr *oBounds);

/**
 * Renders a range of glyphs of a glyph vector on an output device.
 *
 * @param iGlyphVector        a glyph vector
 * @param iStartFrom          first glyph in the range or ST_BEGINNING 
 * @param iGlyphCount         number of glyphs in the range or ST_ALL 
 * @param iGraphics           a graphics object -  a raster or an outline device
 *
 * @return STStatus
 */
STStatus STGlyphVectorRender(STGlyphVector iGlyphVector,
                             STPosition iStartFrom,
                             STCount iGlyphCount,
                             STGraphics iGraphics);


                             


/** @} */


#endif /* __ST_H */
