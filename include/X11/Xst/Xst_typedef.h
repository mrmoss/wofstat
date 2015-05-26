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

/* @(#)Xst_typedef.h	1.27 04/07/27 SMI */

/*
 * This should be a reference to sttypes.h
 */

#ifndef _XST_TYPEDEF
#define _XST_TYPEDEF

#include <X11/Xlib.h>
#include <X11/Xproto.h>

#include "st.h"
#include "sttypes.h"
#include <inttypes.h>
#include "stprivate.h"

#include "Xst_alpha.h"

#ifndef __STTYPES_H

typedef unsigned char 		byte;
typedef unsigned char		utf8;
typedef unsigned short		utf16;

#ifdef _LP64
typedef int64_t			F32Dot32;
#endif

typedef int32_t			F16Dot16;           /**< fixed 16.16 */
typedef int32_t			F24Dot8;            /**< fixed 24.8 */
typedef int16_t			F2Dot14;            /**< fixed: 2.14 */

typedef F16Dot16		Fixed;

typedef void *          	Pointer;
#endif

/*#ifdef USE_FLOATS*/
typedef double			Rational;
/*
#else
typedef Fixed			Rational;
#endif
*/

/*************************************** XST Typedefs *******************************/

/** @defgroup typedef General typedefs
 * @{
 */

typedef STCount         XSTCount;        /**< Number of items                      */
typedef STPosition      XSTPosition;     /**< Index position                       */
typedef unsigned int    XSTVersionID;    /**< Version number                       */
typedef STBaseline      XSTBaseline;

/*********************************** XST TypeEnv Typedefs ***************************/

typedef XID		XSTTypeEnv;      /**< XID for STTypeEnv object             */
typedef unsigned int    XSTFont;         /**< STFont value                         */
typedef unsigned int    XSTScaler;       /**< STScaler value                       */
typedef unsigned int    XSTLayoutEngine; /**< STLayoutEngine value                 */
/**
 *  A Tag assigned to the scaler. Scaler values are:
 */
typedef unsigned int    XSTTag;
typedef unsigned int    XSTFontFamily;   /**< STFontFamily value                   */

/************************************* XST Font Typedefs ****************************/

/**
 * XSTNameTagStruct is a structure containing the four elements that comprise a 
 * TrueType name tag.
 */
typedef struct {
    uint16_t platformID;   /**< TrueType platformID. See TT_PLATFORM_* in sttypes.h */
    uint16_t encodingID;   /**< TrueType encodingID. See TT_ENCODING_* in sttypes.h */
    uint16_t languageID;   /**< TrueType languageID. See TT_LANGUAGE_* in sttypes.h */
    uint16_t nameID;       /**< TrueType nameID. See TT_NAME_* in sttypes.h */
} XSTNameTagStruct;

typedef XSTNameTagStruct *XSTNameTag;       /**< pointer to structure, allows NULLs */
typedef uint32_t          XSTFeatureTag;    /**< OpenType/TrueTypeGX features       */

/**
 * Fallback Policy to use globally for Type Environment or locally for Text. See
 * STFontFallbackPolicy for information on values to use.
 */
typedef STFontFallbackPolicy XSTFontFallbackPolicy;

/**
 * Contains the type of the Font. See STFontType in sttypes.h for more information on
 * the valid values of XSTFontType.
 */
typedef STFontType XSTFontType;

/**
 * Contains which of the standard baselines to use. See STBaselineFlag for more 
 * information on the valid values of XSTBaselineFlag.
 */
typedef STBaselineFlag       XSTBaselineFlag;

/**
 * Contains bitmask values indicating features that the font supports. These features
 * include kerning support and embedded bitmaps.
 */
typedef STFontInfoFlags      XSTFontInfoFlags;

/**
 * This structure contains metric information about the font. See STFontMetrics in 
 * sttypes.h for more information about the structure, it's members, and their values.
 */
typedef STFontMetrics        XSTFontMetrics;

/**
 * Contains the weight descriptor for the font. This value ranges from Thin to Black. See
 * STFontWeightClass in sttypes.h for more information about the valid values.
 */
typedef STFontWeightClass    XSTFontWeightClass;

/**
 * Contains the width descriptor for the font. This value ranges from Ultra condensed
 * to ultra expanded. See STFontWidthClass in sttypes.h for more information about 
 * valid values.
 */
typedef STFontWidthClass     XSTFontWidthClass;

/**
 * Contains the inclination descriptor for the font. This value ranges from Normal to
 * Slanted. See STFontStyle for more information about valid values.
 */
typedef STFontStyle          XSTFontStyle;

/**
 * Contains a bitmask of the areas to search for fonts. Bitmasks include system, local
 * and user. See STFontLocationsMask for more information about valid values.
 */
typedef uint32_t             XSTFontLocationMask;


/************************************ XST Style Typedefs ****************************/

typedef XID		XSTStyle;               /**< XID refering to STStyle object */

/**
 * Contains a value of an OpenType or TrueTypeGX features that is available for the
 * particular font. See STFontFeatureTag in sttypes.h for more information about the
 * valid values.
 */
typedef unsigned int    XSTFontFeatureTag;

/**
 * Contains the equality value for the style. These values range from equal, unequal,
 * to subset and superset. See STStyleComparison in sttypes.h for more information on
 * the valid values.
 */
typedef STStyleComparison    XSTStyleComparison;

/**
 * This bitmask indicates the type of strike through to use. Strike throughs may be  
 * single, or double lines and may be thick. See STStrikeThrough in sttypes.h for 
 * more information.
 */
typedef STStrikeThrough      XSTStrikeThroughEffects;

/**
 * This bitmask indicates the various style effects to use during this style run. 
 * Style effects include ligature splitting, algorithmic styles, vertical text, etc.  
 * See STStyleEffects in sttypes.h for more information.
 */
typedef STStyleEffects       XSTStyleEffects;

/**
 * This bitmask indicates the type of underline to use. Underlines may be single, 
 * double, dashes, or wavy and may be thick. Additionally, there may be two 
 * underlines where one underline is represented by the lower half of the bitmask and
 * the other by the upper half. See STUnderline in sttypes.h for more information.
 */
typedef STUnderline          XSTUnderlineEffects;

/**
 * This bitmask indicates the values of the Style that are desired to change, or that
 * have been previously changed. See STStyleMask in sttypes.h for more information on
 * the valid values.
 */
typedef STStyleMask          XSTStyleMask;

/**
 * XSTLineMetrics contains basic metric information. See STLineMetrics in sttypes.h 
 * for more information on the structure.
 */
typedef STLineMetrics	     XSTLineMetrics;


/********************************** XST GlyphVector Typedefs ************************/

typedef XID		XSTGlyphVector;  /**< STGlyphVector                        */
typedef STPoint		XSTPoint;

/**
 *  An XST styled glyph structure.
 */
typedef struct {
	STGlyph	glyph;
	XSTStyle style;
	STPoint pos;
} XSTStyledGlyph;

/************************************** XST GC Typedefs *****************************/

typedef unsigned int    XSTRGBAColor;       /**< Single color in RGBA format */
typedef unsigned int    XSTOutputType;      /**< Assign to XST_RASTER_OUTPUT/VECTOR */
typedef unsigned int    XSTAlphaMask;       /**< Mask of alpha min/max values */

#define XST_RASTER_OUTPUT	ST_DEVICE_RASTER
#define XST_VECTOR_OUTPUT	ST_DEVICE_VECTOR

/**
 * Transformation matrix 
 *
 * x' = xx * x + xy * y + tx
 * y' = yx * x + yy * y + ty
 *
 * See STMatrix in sttypes.h for more information about the structure
 */
typedef STMatrix                XSTMatrix;		

/**
 * XSTAlpha is a structure containing the min and max alpha values to associate with a
 * particular XST drawable object. The valid objects are: Text, Highlight, Underline,
 * and Strikethrough. The range for the values goes from 0.0 to 1.0. Min must be less
 * than max.
 */
typedef struct {
        double min;       /**< minimum alpha value */
        double max;       /**< maximum alpha value. < 1.0 is semi-transparent */
} XSTAlphaStruct;

/**
 * This pointer to the structure is used to allow users to pass NULL to the function
 * indicating that no change is necessary or desired for that alpha range.
 */
typedef XSTAlphaStruct         *XSTAlpha;        

/**
 * Contains the format of the output device along with a bitmask of the flags to use for
 * output. See STOutputMode in sttypes.h for more information about valid values.
 */
typedef STOutputMode            XSTOutputMode;

/**
 * This bitmask represents which colors to set or which colors have been previously set.
 * See STGraphicsColorMask in sttypes.h for more information about valid values.
 */
typedef STGraphicsColorMask     XSTGraphicsColorMask;


/************************************* XST Line Typedefs ****************************/

typedef unsigned int         XSTLine;         /**< XID referring to an STLine object */

/**
 * XSTCaret contains two end points of the caret line
 */
typedef struct {
        Rational ax;                    /**< Upper end point X value of caret */
        Rational ay;                    /**< Upper end point Y value of caret */
        Rational bx;                    /**< Lower end point X value of caret */
        Rational by;                    /**< Lower end point Y value of caret */
} XSTCaret;

/**
 * XSTTrapezoid contains four corners of the trapezoid bounding the text. See 
 * STTrapezoid for more information about the structure.
 */
typedef STTrapezoid          XSTTrapezoid;

/**
 * XSTRectangle contains two points indicating the bounding corners around 
 * untranslated text
 */
typedef STRectangle          XSTRectangle;

/**
 * Contains the caret direction type. See STCaretDirection in sttypes.h for more 
 * information about valid values.
 */
typedef STCaretDirection     XSTCaretDirection;

/**
 * Contains the caret movement type. See STCaretMovement in sttypes.h for more 
 * information about valid values.
 */
typedef STCaretMovement      XSTCaretMovement;


/************************************ XST Scaler Typedefs ***************************/

/**
 * This bitmask indicates the capabilities of the layout engine.
 */
typedef STLayoutEngineFlags  XSTLayoutEngineFlags;

/************************************ XST Scaler Typedefs ***************************/

/**
 * This bitmask indicates the capabilities of the scaler. Abilities include hinting,
 * support for various output formats, algorithmic styles, etc. See STScalerFlags in 
 * sttypes.h for more information about valid values.
 */
typedef STScalerFlags        XSTScalerFlags;

/**
 * Contains the mode for applying hints. See STHintingMode in sttypes.h for more 
 * information.
 */
typedef STHintingMode        XSTHintingMode;

/**
 * Contains the mode for using embedded bitmaps. See STSbitsMode in sttypes.h for more
 * information.
 */
typedef STSbitsMode          XSTSbitsMode;

/**
 * This bitmask indicates the font type that the font server is using for the font. 
 * This value differs slightly from the STFontType value. See STFontMask in
 * sttypes.h for more information about the valid values.
 */
typedef STFontMask XSTScalerFontMask;


/************************************* XST Text Typedefs ****************************/

/**
 * XID referring to an STText object
 */
typedef XID		     XSTText;

/**
 * Contains text change notification indicators of what type of change is occurring. 
 * From inserted text to removed text. See STTextChanged for more information on the 
 * valid values.
 */
typedef STTextChanged        XSTTextChangedType;

/**
 * Contains information on the caret origin and glyph orgin setting. See STBounds for
 * more information on the valid values.
 */
typedef STBounds             XSTBounds;

/**
 * This bitmask indicates the values of the Text that are desired to change, or that 
 * have been previously changed. See STTextMask in sttypes.h for more information on 
 * the valid values.
 */
typedef STTextMask           XSTTextMask;

/**
 * Contains the direction of the text. See STDirection in sttypes.h for more 
 * information about the valid values.
 */
typedef STDirection XSTDirection;

/**
 * Contains the justification of the text. See STJustification in sttypes.h for more 
 * information about the valid values.
 */
typedef STJustification XSTJustification;

/**
 * Contains the flush factor of the line. See STFlushFactor in sttypes.h for more 
 * information about the valid values.
 */
typedef STFlushFactor XSTFlushFactor;

/************************************ XST General Typedefs **************************/

/**
 * XSTBaselineMask indicates which of the baselines are set in the array for set/get
 */
typedef STBaselineMask XSTBaselineMask;

/**
 * XSTExtLineMetrics contains basic and extended metric information
 */
typedef STExtLineMetrics	XSTExtLineMetrics;

/**
 * Contains the language/locale information. This is used by Styles for the langauge 
 * of the text, and for requesting font information in a particular language. See  
 * stlangdef.h for valid values.
 */
typedef uint32_t                XSTLocale;

/**
 * This is a type cast for all strings passed into and out of XST. By casting the 
 * string to an XSTString, then all formats and encoding can be converted by ICU 
 * without problems of bounding.
 */
typedef uint32_t                XSTString;

/**
 * @}
 */
#endif
