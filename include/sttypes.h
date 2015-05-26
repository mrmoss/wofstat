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
 */

/* $Id: sttypes.tmpl,v 1.8 2004/05/30 23:07:18 adg Exp $ */


/**
 * @file sttypes.h
 * @brief STSF Type definitions
 * @author Alexander Gelfenbain <adg@sun.com>
 * @version 0.11
 */


#ifndef __STTYPES_H
#define __STTYPES_H

#if HAVE_CONFIG_H
#include <config.h>
#elif defined(__sun) && defined(__SVR4)
#define HAVE_SYS_TYPES_H 1
#endif

#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#if HAVE_INTTYPES_H
#include <inttypes.h>
#else
#if HAVE_SYS_INTTYPES_H
#include <sys/inttypes.h>
#endif
#endif

/* STSF external files (persistent font cache and the layout of /var/tmp/stsf)
   are compatible between any two versions of STSF with identical major and minor
   version numbers.
 */

#define STSF_VERSION_MAJOR  0  
#define STSF_VERSION_MINOR  11  
#define STSF_VERSION_UPDATE 1 
#define STSF_BUILD 272 
#define STSF_VERSION_STRING "STSF 0.11.1 build 272"


/*@{*/

/*
 *  Constants and data types
 */

typedef uint8_t byte;                                   /**< A byte */
typedef uint32_t              ucs4;                     /**< A character in UCS-4 encoding */
typedef uint16_t              utf16;                    /**< A character or a component of a character in UTF-16 encoding */
typedef byte                  utf8;                     /**< A characer or a component of a character in UTF-16 encoding */

typedef int32_t F16Dot16;                               /**< fixed 16.16 */
typedef int32_t F24Dot8;                                /**< fixed 24.8 */
typedef int16_t F2Dot14;                                /**< fixed: 2.14 */
typedef F16Dot16 Fixed;                                 /**< generic fixed */

struct STOpaqueTypeEnv;
struct STOpaqueText;
struct STOpaqueLine;
struct STOpaqueStyle;
struct STOpaqueGlyphVector;
struct STOpaqueGraphicsStruct;
                                                            
typedef struct STOpaqueTypeEnv *STTypeEnv;              /**< Type environment object */
typedef struct STOpaqueText *STText;                    /**< Text object */
typedef struct STOpaqueGlyphVector *STGlyphVector;      /**< Glyph vector object */
typedef struct STOpaqueLine *STLine;                    /**< Line object */
typedef struct STOpaqueStyle *STStyle;                  /**< Style object */
typedef struct STOpaqueGraphics *STGraphics;            /**< Graphics */

typedef uint32_t STObject;                              /**< Generic drop-in object ID */
typedef uint32_t STScaler;                              /**< Scaler ID */
typedef uint32_t STLayoutEngine;                        /**< Layout Engine ID */
typedef void    *STPointer;                             /**< A generic pointer */
typedef uintptr_t STHangle;                             /**< A generic handle data type the same size as a pointer */

#define ST_DEFAULT_SCALER 0                             /**< Default scaler ID */

typedef uint32_t STTag;                   /**< untypes 4 character tag */
typedef uint32_t STFont;                  /**< font ID */
typedef uint32_t STFontFamily;            /**< font family ID */
typedef uint32_t STRGBAColor;             /**< 32 bit RGBA color */
typedef int STJustification;              /**< Text justification */
typedef double STFlushFactor;             /**< Line flush factor */

typedef int STPosition;                   /**< Location of character position within text */
typedef int STCount;                      /**< Number of items */
typedef int STCharCount;                  /**< Number of characters */
typedef double STBaseline;                /**< Baseline value */

#define ST_BEGINNING          0           /**< STPosition: index of the first character or glyph of an object */
#define ST_END                16777216    /**< STCount: Index of the last character or glyph */
#define ST_ALL                16777216    /**< STCount or STCharCount: Value that specifies all remaining characters or glyphs */

typedef size_t STSize;                    /**< Size of data in bytes */
typedef off_t STFileOffset;               /**< Offset within a file */

typedef int STBoolean;                    /**< A Boolean type */
typedef uint32_t STMask;                  /**< A 32 bit wide bitmask */
#if 0 
typedef uint32_t STGlyph;                 /**< A glyph */
#endif
typedef uint16_t STGlyph;                 /**< A glyph */


#if !defined(TRUE) || !defined(FALSE)
#define TRUE ((STBoolean) (1 == 1))     /**< Definition of TRUE */
#define FALSE ((STBoolean) (1 == 0))    /**< Definition of FALSE */
#endif

typedef int STDirection;                  /**< Text direction */
#define ST_DIRECTION_LTR 0
#define ST_DIRECTION_RTL 1



/**
 * STStyleBitMask
 * This bitmask is ORed together to indicate which values to change for the following 
 * functions:
 *   STStyleSetFont
 *   STStyleSetScaler
 *   STStyleSetEffects
 *   STStyleCompare
 *   STStyleClear
 *   STStyleResetAttributes
 *   STStyleCopyAttributes
 *   STStyleOverwriteAttributes
 *   STStyleUnderwriteAttributes
 *   STStyleSetOptions
 *
 * A bitmask is returned by the following functions to indicate values that were previously
 * set:
 *   STStyleGetFont
 *   STStyleGetScaler
 *   STStyleGetOptions
 *   STStyleGetEffects
 */

typedef uint32_t STStyleMask;
#define ST_SM_FONTID                    1               /**< Change or changed FontID */
#define ST_SM_SIZE                      (1 << 1)        /**< Change or changed Size */
#define ST_SM_LANGUAGE                  (1 << 2)        /**< Change or changed Language */
#define ST_SM_BASELINE                  (1 << 3)        /**< Change or changed Baseline */
                                                        /* (1 << 4) is undocumented */
#define ST_SM_EFFECTS                   (1 << 5)        /**< Change or changed Style Effects */
#define ST_SM_STRIKETHROUGH             (1 << 6)        /**< Change or changed Strike Through */
#define ST_SM_UNDERLINE                 (1 << 7)        /**< Change or changed Underline */
#define ST_SM_SCALER                    (1 << 8)        /**< Change or changed Scaler */
#define ST_SM_HINTINGMODE               (1 << 9)        /**< Change or changed Hinting mode */
#define ST_SM_SBITSMODE                 (1 << 10)       /**< Change or changed Use Embedded Bitmaps */
#define ST_SM_LAYOUTENGINE              (1 << 11)       /**< Change or changed layout engine */
#define ST_SM_IMPOSEWIDTH               (1 << 12)       /**< Change or changed imposed width */
#define ST_SM_BEFOREWITHSTREAMSHIFT     (1 << 13)       /**< Change or changed weight factor for with-stream shift applied before each glyph */
#define ST_SM_AFTERWITHSTREAMSHIFT      (1 << 14)       /**< Change or changed weight factor for with-stream shift applied after each glyph */
#define ST_SM_CROSSSTREAMSHIFT          (1 << 15)       /**< Change or changed cross-stream shift weight factor */
#define ST_SM_HANGINGINHIBITFACTOR      (1 << 16)       /**< Change or changed hanging glyph weight factor */
#define ST_SM_KERNINGINHIBITFACTOR      (1 << 16)       /**< Change or changed kerning weight factor */
#define ST_SM_DECOMPINHIBITFACTOR       (1 << 17)       /**< Change or changed ligature decomposition weight factor */
#define ST_SM_PRIVATEDATA               (1 << 18)       /**< Change or changed private data */

#define ST_SM_LAST ST_SM_PRIVATEDATA                    /** Largest defined STStyleMask value */
#define ST_SM_ALL             0xFFFFFFFF                /**< Change or changed All applicable fields */


/**
 * STGraphicsColorMask 
 * This bitmask is ORed together to indicate which colors to change for the 
 * following functions:
 *   STGraphicsNew
 *   STGraphicsSetColors
 *
 * A bitmask is returned by the following functions to indicate values that were previously
 * set:
 *   STGraphicsGetColors
 */


typedef uint32_t STGraphicsColorMask;
#define ST_GM_COLOR_TEXT      (1 << 0)                  /**< Normal text color */
#define ST_GM_COLOR_HLTEXT    (1 << 1)                  /**< Highlighted text color */
#define ST_GM_COLOR_HLBG      (1 << 2)                  /**< Highlighted background color */
#define ST_GM_COLOR_ST        (1 << 3)                  /**< Strikethrough color */
#define ST_GM_COLOR_HLST      (1 << 4)                  /**< Highlighted strikethrough color */
#define ST_GM_COLOR_UL1       (1 << 5)                  /**< First underline color */
#define ST_GM_COLOR_HLUL1     (1 << 6)                  /**< Highlighted first underline color */
#define ST_GM_COLOR_UL2       (1 << 7)                  /**< Second underline color */
#define ST_GM_COLOR_HLUL2     (1 << 8)                  /**< Highlighted second underline color */
#define ST_GM_COLOR_ALL       0x1FF                     /**< 9 different colors */



/**
 * STTextMask 
 * This bitmask is ORed together to indicate which values to change for the following 
 * functions:
 *   STTextSetControls
 *   STTextCopyAttributes
 *   STTextResetAttributes
 *
 * A bitmask is returned by the following functions to indicate values that were previously
 * set:
 *   STTextGetControls
 */
typedef uint32_t STTextMask;
#define ST_TM_DIRECTION       1                 /**< Change direction of text flow */
#define ST_TM_JUSTIFICATION   (1 << 1)          /**< Change text justification */
#define ST_TM_FLUSHFACTOR     (1 << 2)          /**< Change text flush factor */
#define ST_TM_LANGUAGE        (1 << 3)          /**< Change text language */
#define ST_TM_FALLBACKPOLICY  (1 << 4)          /**< Change text fallback policy */
#define ST_TM_ASCENT          (1 << 5)          /**< Change text imposed ascent */
#define ST_TM_DESCENT         (1 << 6)          /**< Change text imposed descent */
#define ST_TM_LEADING         (1 << 7)          /**< Change text imposed leading */
#define ST_TM_WIDTH           (1 << 8)          /**< Change text imposed width */

#define ST_TM_LINEMETRICS     (ST_TM_WIDTH |   \
                               ST_TM_ASCENT |  \
                               ST_TM_DESCENT | \
                               ST_TM_LEADING)   /**< Change all imposed line metric properties */

#define ST_TM_BASELINES       (1 << 9)          /**< Change one or more text baseline */
#define ST_TM_FALLBACKS       (1 << 10)         /**< Change font fallbacks */
                                          
#define ST_TM_ALL             0xFFFFFFFF  /**< Change all applicable text fields */

/**
 * STStyleEffects 
 * This bitmask indicates the style effects to use for the length of the style run.
 * It is ORed together and used in the following functions:
 *    STStyleSetEffects
 *
 * It is returned to indicate which fields are set by the following functions:
 *    STStyleGetEffects
 */
typedef uint32_t STStyleEffects;
#define ST_SE_LIGATURESPLIT             1                   /**< Specifies if caret can be positioned inside ligatures */
#define ST_SE_SLANTEDCARET              (1 << 1)            /**< Specifies if caret and selections should be parallel
                                                                 to the angle of the text or perpendicular to the baseline */
#define ST_SE_OPTALIGNMENT              (1 << 2)            /**< Automatic adjustment of optical positions at the
                                                                 beginning and end of lines */
#define ST_SE_NO_CROSSKERN              (1 << 3)            /**< Disabled cross-stream kerning defined in a font */
#define ST_SE_NO_KERN                   (1 << 4)            /**< Disable kerning */
#define ST_SE_EMBOLDEN                  (1 << 5)            /**< Alogirthmically embolden the font */
#define ST_SE_ITALICIZE                 (1 << 6)            /**< Algorithmically italicezes the font */
#define ST_SE_CONDENSED                 (1 << 7)            /**< Decreases the horizontal distance between all glyphs */
#define ST_SE_EXTENDED                  (1 << 8)            /**< Increases the horizontal distance between all glyphs */
#define ST_SE_VERTICALTEXT              (1 << 9)            /**< Specifies vertical glyph orientation */
#define ST_SE_FORCEHANGING              (1 << 10)           /**< Should hanging glyphs extend into the margins */

/**
 * STStrikeThrough
 * Use this value to set the type of strike through to use for the style run. 
 * Low 16 bits of this type are used as an ordinal number that reflects the
 * type of the strike through effect and the high 16 bits are used to specify
 * styles that can be applied to the strike through effect.
 *
 * This value is used in the following functions:
 *    STStyleSetEffects
 *
 * It is returned to indicate the type of strike through by the following functions:
 *    STStyleGetEffects
 */
typedef uint32_t STStrikeThrough;

#define ST_STRIKETHROUGH_NONE   0                 /**< Do not strike the text through */
#define ST_STRIKETHROUGH_SINGLE 1                 /**< Draws a horisontal line through text */
#define ST_STRIKETHROUGH_DOUBLE 2                 /**< Draws two horisontal lines through text */

#define ST_STRIKETHROUGH_THICK  0x80000000        /**< Makes it thick */



/**
 * STUnderline
 * STUnderline represent information about two underline effects applied to the style.
 * It uses low 16 of STUnderline for the first underline effect and high 16 bits
 * for the second. Each of the 16 bit values is split in two pieces - low 8 bits
 * represent the type of an underline and high 8 bits represent modifiers (such as
 * thickness) applied to the base type of an underline.
 *
 * The bitmask is used in the following functions:
 *    STStyleSetEffects
 *
 * It is returned to indicate the type of underline by the following functions:
 *    STStyleGetEffects
 */

typedef uint32_t STUnderline;

#define ST_UNDERLINE_NONE               0               /**< Do not underline text */
#define ST_UNDERLINE_SINGLE             1               /**< Draws a single line parallel to the baseline */
#define ST_UNDERLINE_SOLID              ST_UNDERLINE_SIGNLE
#define ST_UNDERLINE_DOT                2               /**< Draws a line of dots */
#define ST_UNDERLINE_DASH               3               /**< Draws a line of dashes */
#define ST_UNDERLINE_LONGDASH           4               /**< Draws a line of long dashes */
#define ST_UNDERLINE_DOTDASH            5               /**< Draws a line of dot-dash pairs */
#define ST_UNDERLINE_WAVE               6               /**< Underlines with a wave */
#define ST_UNDERLINE_WAVE_SAWTOOTH      7
#define ST_UNDERLINE_SHORT_SQUARE_WAVE  8
#define ST_UNDERLINE_LONG_SQUARE_WAVE   9

#define ST_UNDERLINE_DOUBLE   (1 << 14)                 /**< Doubles the selected underline */
#define ST_UNDERLINE_THICK    (1 << 15)                 /**< Makes the selected underline thick */

#define ST_COMBINE_UNDERLINES(a, b) ((a) << 16 | (b))   /**< Use this macro to combine two underline values into a single bitmask to set for the style */
#define ST_GET_FIRST_UNDERLINE(a) (( (a) & 0x0000FFFF ));
#define ST_GET_SECOND_UNDERLINE(a) (( (a) & 0xFFFF0000 ) >> 16 );

/**
 * STOutputMode
 * an OR of one of the ST_OM_ constants and one or more ST_OF_ flags 
 * The bitmask is used in the following functions:
 *    STGraphicsNew
 *    STGraphicsSetDevice
 *
 * It is returned to indicate the output mode and any formatting options by the following 
 * functions:
 *    STGraphicsGetDevice
 */
typedef uint32_t STOutputMode;  

#define ST_OM_MASK                  0x0000FFFF                 /**< Output mode portion of mask */
#define ST_OF_MASK                  0xFFFF0000                 /**< Output format portion of mask */

#define ST_OM_RASTER_MONO           1                          /**< Two-color rendering */
#define ST_OM_RASTER_GRAYSCALE      2                          /**< Anti-aliased mode */
#define ST_OM_RASTER_GREYSCALE      ST_OM_RASTER_GRAYSCALE     /**< Anti-aliased mode */
#define ST_OM_RASTER_LCD            3                          /**< Optimized for LCD output */
#define ST_OM_RASTER_TV             4                          /**< Optimized for TV output */
#define ST_OM_RASTER_MONO_BITSWAPPED 5                         /**< Two-color rendering */
#define ST_OM_VECTOR                32                         /**< Vector based output */

#define ST_OF_SUPPRESS_FRACTIONAL_METRICS 0x00010000           /**< Do not use fractional metrics */
#define ST_OF_SUPPRESS_FRACTIONAL_DELTAS  0x00020000           /**< Do not use fractional deltas */
#define ST_OF_HINT_OUTLINES 0x00040000                         /**< Grid-fitted outlines */

/**
 * STHintingMode
 * This value is used to inform the scaler what type of hinting to apply to the font. Note that
 * the scaler must support the requested hinting mode or no change will occur.
 * The value is used in the following functions:
 *    STStyleSetScaler
 *
 * It is returned to indicate the hinting mode used by the following functions:
 *    STStyleGetScaler
 */
typedef uint32_t STHintingMode;
#define ST_IGNORE_HINTS 1                 /**< Ignore font hints */
#define ST_APPLY_HINTS  2                 /**< Apply font hints */
#define ST_AUTOHINT     3                 /**< Turn autohinting on */


/**
 * STSbitsMode
 * This value is used to inform the scaler whether to use embedded bitmaps or not. Note that the
 * scaler must support embedded bitmaps.
 * The value is used in the following functions:
 *    STStyleSetScaler
 *
 * It is returned to indicate the hinting mode used by the following functions:
 *    STStyleGetScaler
 */
typedef uint32_t STSbitsMode;
#define ST_IGNORE_SBITS       1           /**< Do not use embedded glyph bitmaps */
#define ST_USE_SBITS          2           /**< Use embedded glyph bitmaps */


/**
 * STFontMetrics struct
 */

typedef struct {
    double hAscent;                     /**< horizontal ascender */
    double hDescent;                    /**< horizontal descender */
    double hLeading;                    /**< horizontal leading */
    double vAscent;                     /**< vertical ascender */
    double vDescent;                    /**< vertical descender */
    double vLeading;                    /**< vertical leading */
    double italicAngle;                 /**< italic angle in radians */
    double xMin;                        /**< top left corner of bounding box */
    double yMin;                        /**< top left corner of bounding box */
    double xMax;                        /**< bottom right corner of bounding box */
    double yMax;                        /**< bottom right corner of bounding box */
    int widthClass;                     /**< value from 1 to 9 */
    int weightClass;                    /**< value from 100 to 900 */
} STFontMetrics;



typedef STFontMetrics *STFontMetricsPtr;


/**
 * STLineMetrics struct 
 */
typedef struct {
    double ascent;                                /**< Ascent, positive direction - up */
    double descent;                               /**< Descent, positive direction - down */
    double leading;                               /**< Leading, if > 0 - make lines farther apart, if < 0 makes lines closer */
} STLineMetrics, *STLineMetricsPtr;

/** 
 * STExtLineMetrics struct
 */

typedef struct {
    double ascent;                                /**< Ascent, positive direction - up */
    double descent;                               /**< Descent, positive direction - down */
    double leading;                               /**< Leading, if > 0 - make lines farther apart, if < 0 makes lines closer */
    double width;                                 /**< Text width in horizontal mode or height in vertical */
} STExtLineMetrics, *STExtLineMetricsPtr;



/**
 * Defines a text caret. 
 */
typedef struct {
    double ax;                        /**< X Origin of the caret */
    double ay;                        /**< Y Origin of the caret */
    double bx;                        /**< X End Point of the caret */
    double by;                        /**< Y End point of the caret */
} STCaret, *STCaretPtr;

/**
 * Defines a trapezoid for bounding boxes. 
 */
typedef struct {
    double ax;                       /**< X coordinate of the first point*/
    double ay;                       /**< Y coordinate of the first point*/
    double bx;                       /**< X coordinate of the second point*/
    double by;                       /**< Y coordinate of the second point*/
    double cx;                       /**< X coordinate of the third point*/
    double cy;                       /**< Y coordinate of the third point*/
    double dx;                       /**< X coordinate of the fourth point*/
    double dy;                       /**< Y coordinate of the fourth point*/
} STTrapezoid, *STTrapezoidPtr;

/**
 * Rectangular bounding box. 
 */
typedef struct {
    double ax;                        /**< One corner of the bounding box */
    double ay;                        /**< One corner of the bounding box */
    double bx;                        /**< Opposite corner of the bounding box */
    double by;                        /**< Opposite corner of the bounding box */
} STRectangle, *STRectanglePtr;

/**
 * A point
 */
typedef struct {
    double x;                         /**< X Coordinate value */
    double y;                         /**< Y Coordinate value */
} STPoint, *STPointPtr;


    
/**
 * Transformation matrix
 *
 * x' = xx * x + xy * y + tx
 * y' = yx * x + yy * y + ty
 *
 */

#if 0
typedef struct {
    double xx;                        /**< transformation matrix value */
    double xy;                        /**< transformation matrix value */
    double yx;                        /**< transformation matrix value */
    double yy;                        /**< transformation matrix value */
    double tx;                        /**< transformation matrix value for x translation */
    double ty;                        /**< transformation matrix value for y translation */
} STMatrix, *STMatrixPtr;
#endif


typedef struct {
    double xx;              /**< transformation matrix value */
    double xy;              /**< transformation matrix value */
    double yx;              /**< transformation matrix value */
    double yy;              /**< transformation matrix value */
    double tx;              /**< transformation matrix value for x translation */
    double ty;              /**< transformation matrix value for y translation */
} STMatrix;



typedef STMatrix *STMatrixPtr;


/**
 * Styled glyph - a combination of a glyph ID, pointer to the style object and glyph's
 * position in user space
 */
typedef struct {
    STGlyph id;                           /**< Glyph ID within the font specified by the Style object */
    STStyle *style;                       /**< Pointer to the style object */
    STPoint pos;                          /**< X and Y position of the glyph origin */
} STStyledGlyph;

/**
 * Baselines 
 */



/**
 * Defines standard baselines.
 */

typedef uint32_t STBaselineFlag;
#define ST_BASELINE_ROMAN 0                 /**< The standard Roman baseline */
#define ST_BASELINE_CENTERED 1              /**< The baseline used in ideographic scripts like Chinese, Japanese and Korean */
#define ST_BASELINE_HANGING 2               /**< The baseline used in Devanagiri and similar scripts */
#define ST_BASELINE_LOWCENTERED 3           /**< Similar to STCenteredBaseline but with the glyphs lowered.
                                                 Used to align Roman glyphs within ideographic fonts with Roman glyphs in Roman fonts */
#define ST_BASELINE_MATH 4                  /**< The baseline for setting mathematics. Centered on symbols such as the minus sign */
#define ST_BASELINE_LAST ST_BASELINE_MATH   /**< The ordinal number of the last defined baseline */

typedef uint32_t STBaselineMask;
#define ST_BM_ROMAN             (1 << ST_BASELINE_ROMAN)
#define ST_BM_CENTERED          (1 << ST_BASELINE_CENTERED)
#define ST_BM_HANGING           (1 << ST_BASELINE_HANGING)
#define ST_BM_LOWCENTERED       (1 << ST_BASELINE_LOWCENTERED)
#define ST_BM_MATH              (1 << ST_BASELINE_MATH)
#define ST_BM_LAST              (1 << ST_BASELINE_LAST)


/**
 * Defines bounds type
 */

typedef uint32_t STBounds;
#define ST_BOUNDS_CARET_ORIGINS 0       /**< The caret origin is halfway between two characters */
#define ST_BOUNDS_DEVICE_ORIGINS 1      /**< Glyph origins in device space */
#define ST_BOUNDS_FRACTIONAL_ORIGINS 2  /**< Glyph origins in user space */


/**
 * Defines font fallback policy
 */

typedef uint32_t STFontFallbackPolicy;
#define ST_FB_NOSUBSTITUTION 0                    /**< Do not substitute fonts */
#define ST_FB_USEFONTLIST 1                       /**< Search only fonts on a substitution font list */
#define ST_FB_SEARCHALL 2                         /**< Search all available fonts */


/**
 * Defines caret movement type
 */
typedef int STCaretMovement;
#define ST_CM_BYCHARACTER      0        /**< Move caret one character at a time */
#define ST_CM_BYWORD           1        /**< Move caret one word at a time */
#define ST_CM_BYUNICODECLUSTER 2        /**< Move caret one unicode cluster at a time */


/**
 * Defines caret direction type
 */
typedef int STCaretDirection;

#define ST_CD_LEFT 0                    /**< Move caret left */
#define ST_CD_RIGHT 1                   /**< Move caret right */
#define ST_CD_PREVIOUS 2                /**< Move caret to the previous movement value. Takes bidi into account */
#define ST_CD_NEXT 3                    /**< Move caret to the next movement value. Takes bidi into account */


/**
 * Text change notification
 */
typedef int STTextChanged;
#define ST_TC_INSERTED 0                /**< Text has been inserted */
#define ST_TC_REMOVED 1                 /**< Text has been removed */
#define ST_TC_REPLACED 2                /**< Text has been replaced with an equal amount of text */

/**
 * Style comparison result.
 */

typedef int STStyleComparison;
#define ST_SC_IDENTICAL 0               /**< Two styles are identical, i.e. contain the same set of
                                             keys with the same values */
/* everything else is not documented for now */
                                 



/**
 * STScalerFlags - returned by STScalerGetInfo()
 */
typedef uint32_t STScalerFlags;
#define ST_SF_SBITS          0x00000001           /**< scaler supports embedded bitmaps for TrueType and OpenType fonts */
#define ST_SF_HINTS          0x00000002           /**< scaler supports hints */
#define ST_SF_AUTOHINTING    0x00000004           /**< scaler supports autohinting */
#define ST_SF_BITMAP         0x00000008           /**< scaler supports B&W single bit bitmap generation */
#define ST_SF_GRAYSCALE      0x00000010           /**< scaler supports single byte antialised alpha-mask generation*/
#define ST_SF_LCDOPTIMIZED   0x00000020           /**< scaler supports LCD optimized output for horizontally stacked RGB subpixels */
#define ST_SF_EMBOLDEN       0x00000040           /**< scaler supports algorithmic emboldening */
#define ST_SF_OBLIQUE        0x00000080           /**< scaler supports algorithmic oblique */
#define ST_SF_FRACDELTAS     0x00000100           /**< scaler supports fractional glyph positioning */
#define ST_SF_LCDOPTIMIZED_H ST_SF_LCDOPTIMIZED 
#define ST_SF_LCDOPTIMIZED_V 0x00000200           /**< scaler supports LCD optimized output for vertically stacked RGB subpixels */ 

typedef uint32_t STLayoutEngineFlags;
#define ST_LF_AAT             0x00000001          /**< layout engine supports GX-style tables */
#define ST_LF_OPENTYPE        0x00000002          /**< layout engine supports OpenType-style tables */

typedef unsigned int STFontType;                  /**< Font type value, from 1 to 32. Font type values 24 and above 
                                                       are reserved for ST Font Server internal use. */
typedef unsigned int STFontMask;                  /**< Font type mask */

#define ST_FT_UNKNOWN         0                             /**< Font type is not known */
#define ST_FM_UNAVAILABLE     0xFFFFFFFF                    /**< Font is no longer available */

#define ST_FT_TRUETYPE        1                             /**< Classic TrueType */
#define ST_FM_TRUETYPE        (1 << (ST_FT_TRUETYPE - 1))   /**< TrueType font mask */

#define ST_FT_TTC             2                             /**< Microsoft TrueType Collection File */
#define ST_FM_TTC             (1 << (ST_FT_TTC - 1))        /**< Microsoft TrueType Collection font mask */

#define ST_FT_TYPE1           3                             /**< Adobe Type1 */
#define ST_FM_TYPE1           (1 << (ST_FT_TYPE1 - 1))      /**< Adobe Type1 font mask */

#define ST_FT_OPENTYPE_TTF    4                             /**< OpenType with TrueType glyph procedures */
#define ST_FM_OPENTYPE_TTF    (1 << (ST_FT_OPENTYPE_TTF - 1)) /**< OpenType with TrueType glyph procedures font mask */

#define ST_FT_OPENTYPE_OTF    5                             /**< OpenType with Type1 glyph procedures */
#define ST_FM_OPENTYPE_OTF    (1 << (ST_FT_OPENTYPE_OTF - 1)) /**< OpenType with Type1 glyph procedures font mask */

#define ST_FT_TRUETYPE_GX     6                             /**< TrueType with GX extensions */
#define ST_FM_TRUETYPE_GX     (1 << (ST_FT_TRUETYPE_GX - 1)) /**< TrueType with GX extensions font mask */

#define ST_FT_EOT             7                             /**< Embedded OpenType */
#define ST_FM_EOT             (1 << (ST_FT_EOT - 1))        /**< Embedded OpenType font mask */

#define ST_FT_T2K             8                             /**< FontFusion T2K format, Asian and Roman */
#define ST_FM_T2K             (1 << (ST_FT_T2K - 1))        /**< FontFusion T2K font mask */

#define ST_FT_PFR             9                             /**< TrueDoc PFR font */
#define ST_FM_PFR             (1 << (ST_FT_PFR - 1))        /**< TrueDoc PFR font mask */

#define ST_FT_INTELLIFONT     10                            /**< Intellifont */
#define ST_FM_INTELLIFONT     (1 << (ST_FT_INTELLIFONT - 1)) /**< Intellifont font mask */

#define ST_FT_SPEEDO          11                            /**< Speedo font */
#define ST_FM_SPEEDO          (1 << (ST_FT_SPEEDO - 1))     /**< Speedo font mask */


/**
 * Font Info Flags
 * These refer to the capabilities of the font
 */
typedef uint32_t STFontInfoFlags;

#define ST_FI_SBITS 1       /**< Embedded bitmaps are available for this font */
#define ST_FI_KERN 2        /**< Kerning data is available for this font */
#define ST_FI_SCALABLE 3    /**< Scalable outlines are available for this font */

/**
 * Rendering Mode
 */
typedef int STRenderingMode;
#define ST_RM_INVALID 0           /**< not a valid rendering mode */
#define ST_RM_SIMPLEBITMAP 1      /**< 1 bit per pixel bitmap */
#define ST_RM_ALPHAMASK 2         /**< Anti-aliased alpha-mask 4 or 8 bits per pixel */
#define ST_RM_LOOKUPTABLE 3       /**< Color lookup table, 8 bits per pixel */
#define ST_RM_THREE_ALPHAMASKS 4       /**< FreeType LCD rendering mode */

/**
 * Color lookup table
 */
#if 0
typedef struct {
    int n;                                /**< Number of entries in c array */
    uint32_t c[256];                      /**< Array of RGB colors */
} STLookupTable;
#endif


typedef struct {
    int n;                  /**< Number of entries in c array */
    uint32_t c[256];        /**< Array of RGB colors */
} STLookupTable;



/**
 * Rendering parameters
 */
typedef struct {
    STRenderingMode mode;        /**< mode used to render, LCD, B&W, etc */
    int bitsPerPixel;            /**< pixel depth */
    STLookupTable clut;          /**< color lookup table */
} STRenderingParams;

/**
 * Private data sent to bitblt function
 */
typedef struct {
    STRenderingParams rparams;       /**< Rendering parameters */
    int x;                           /**< X coordinate to render at */
    int y;                           /**< Y coordinate to render at */
    int w;                           /**< width to render */
    int h;                           /**< height to render */
    int sx;                          /**< source X within passed data */
    int sy;                          /**< source Y within passed data */
    int bytesPerRow;                 /**< bytes per row of passed data */
    int highlighted;                 /**< is text highlighted */
    byte *source;                    /**< Ignored by ST but used by XST to store a pointer to the source bitmap image. */
} STBitBltRec;

typedef STBitBltRec *STBitBltPtr;    /**< Pointer to STBitBltRec */


/** @defgroup Device STDevice class and its children
 * @{
 */

/**
 * STDevice is an abstract class that defines an output device. Objects of this class should be 
 * instantiated by users of ST API. STDevice children - STRasterDevice and STVectorDevice define 
 * callback functions that are called by STClientLibrary as it renders the line of text.  
 *
 * In addition to the callback function STDevice communicates important characteristics of an output device,
 * such as its depth and resolution to STClientLibrary.
 *
 * STRasterDevice and STVectorDevice include a transformation matrics that defines an affine
 * transform from user-space coordinates to device-space coordinates. It can be accessed
 * directly or through STGraphics methods.
 * 
 */




/**
 * Type of output device (Raster or Vector)
 */
typedef int STDeviceType;
#define ST_DEVICE_RASTER 1                              /**< Identifies STRasterDevice */
#define ST_DEVICE_VECTOR 2                              /**< Identifies STVectorDevice */


/**
 * STDevice structure
 */
typedef struct stdevice {
    STDeviceType devType;                               /**< Class type */
} STDeviceStruct;

typedef STDeviceStruct *STDevice;      /**< Pointer to STDeviceStruct structure */

struct STRasterDeviceStruct;
struct STVectorDeviceStruct;

/**
 * Raster callback function.
 * 
 * @param dev                   the "this" pointer
 * @param bbdata                identifies properties of the source bitmap
 * @param source                pointer to the (0,0) point in the source bitmap
 *
 */
typedef void (*BitBltF)(struct STRasterDeviceStruct *dev,   
                        STBitBltPtr bbdata,
                        byte *source               
                       );

/**
 * Raster highlight callback function
 *
 * @param dev                   the "this" pointer
 * @param trap                  trapezoid bounding highlighted region
 * @param depth                 depth of drawable
 * @param mode                  rendering mode (LCD, B&W, etc)
 */
typedef void (*HighlightF)(struct STRasterDeviceStruct *dev,
                           STTrapezoid *trap,
                           int depth,
                           STRenderingMode mode
                          );

/**
 * Raster underline callback function
 *
 * @param dev                   the "this" pointer
 * @param p1                    coordinate value to start underline
 * @param p2                    coordinate value to end underline
 * @param depth                 depth of drawable
 * @param uleffects             type of underline to draw
 * @param mode                  rendering mode (LCD, B&W, etc)
 */
typedef void (*UnderlineF)(struct STRasterDeviceStruct *dev,
                           STPoint p1,
                           STPoint p2,
                           int highlight,
                           int depth,
                           STUnderline uleffects,
                           STRenderingMode mode
                          );

/**
 * Raster strike through callback function
 *
 * @param dev                   the "this" pointer
 * @param p1                    coordinate value to start underline
 * @param p2                    coordinate value to end underline
 * @param depth                 depth of drawable
 * @param seffects              type of strikethrough to draw
 * @param mode                  rendering mode (LCD, B&W, etc)
 */
typedef void (*StrikeThroughF)(struct STRasterDeviceStruct *dev,
                               STPoint p1,
                               STPoint p2,
                               int highlight,
                               int depth,
                               STStrikeThrough steffects,
                               STRenderingMode mode
                              );

/**
 * STRasterDevice is a class that specifies raster devices.
 */
struct STRasterDeviceStruct {
    STDeviceType devType;               /**< fRasterDevice */

    uint32_t width;                       /**< Width */
    uint32_t height;                      /**< Heihgt */
    uint16_t ppix;                        /**< Horizontal points per inch resolution */
    uint16_t ppiy;                        /**< Vertical points per inch resolution */
    uint16_t bpp;                         /**< bits per pixel */

    void *p;                            /**< private data */

    BitBltF bitblt;                     /**< blit function */
    HighlightF highlight;               /**< blit function */
    UnderlineF underline;               /**< blit function */
    StrikeThroughF strikethrough;       /**< blit function */
};

typedef struct STRasterDeviceStruct *STRasterDevice; /**< Pointer to STRasterDeviceStruct structure */

/** @} */

#define F16DOT16_TO_INT(A)              ( (A) >> 16 )                /**< Convert F16.16 to int     */
#define F16DOT16_TO_FLOAT(A)            ( (A) / 65536.0 )            /**< Convert F16.16 to float   */
#define INT_TO_F16DOT16(A)              ( (A) << 16 )                /**< Convert int to F16.16     */
#define FLOAT_TO_F16DOT16(A)            ( (F16Dot16) (A * 65536.0) ) /**< Convert float to F16.16   */
#define F26DOT6_TO_FLOAT(A)             ( (A) / 64.0)                /**< Convert F26.6 to float    */

typedef uint32_t STLocale;                          /**< ST_SCRIPT_VARIANT_* | ST_TERRITORY_* | ST_LANGUAGE_*   */
typedef uint32_t STScriptVariant;                   /**< ST_SCRIPTVARIANT_*                                     */
typedef uint32_t STLanguage;                        /**< ST_LANGUAGE_*                                          */
typedef uint32_t STTerritory;                       /**< ST_TERRITORY_*                                         */

typedef uint32_t STScript;                          /**< ST_SCRIPT_*                                            */

/**
 * Weight of font as described by the font
 */
typedef uint16_t STFontWeightClass;
#define ST_WEIGHT_THIN 1             /**< Font weight described as thin */
#define ST_WEIGHT_EXTRALIGHT 2       /**< Font weight described as extra light */
#define ST_WEIGHT_LIGHT 3            /**< Font weight described as light */
#define ST_WEIGHT_NORMAL 4           /**< Font weight described as normal */
#define ST_WEIGHT_MEDIUM 5           /**< Font weight described as medium */
#define ST_WEIGHT_SEMIBOLD 6         /**< Font weight described as semi bold */
#define ST_WEIGHT_BOLD 7             /**< Font weight described as bold */
#define ST_WEIGHT_EXTRABOLD 8        /**< Font weight described as extra bold */
#define ST_WEIGHT_BLACK 9            /**< Font weight described as black */
#define ST_WEIGHT_UNKNOWN 10         /**< Font weight described as unknown */

/**
 * Width of font as described by the font
 */
typedef uint16_t STFontWidthClass;
#define ST_WIDTH_ULTRA_CONDENSED 1                /**< Font width ultra condensed */
#define ST_WIDTH_EXTRA_CONDENSED 2                /**< Font width extra condensed */
#define ST_WIDTH_CONDENSED 3                      /**< Font width condensed */
#define ST_WIDTH_SEMI_CONDENSED 4                 /**< Font width semi condensed */
#define ST_WIDTH_NORMAL 5                         /**< Font width normal */
#define ST_WIDTH_SEMI_EXPANDED 6                  /**< Font width semi expanded */
#define ST_WIDTH_EXPANDED 7                       /**< Font width expanded */
#define ST_WIDTH_EXTRA_EXPANDED 8                 /**< Font width extra expanded */
#define ST_WIDTH_ULTRA_EXPANDED 9                 /**< Font width ultra expanded */
#define ST_WIDTH_UNKNOWN 10                       /**< Font width unknown */

/**
 * STFontStyle denotes the value that the font has embedded for its italicity. This is a value
 * stored in the font and is not associated with the name of the font. The name may say oblique, 
 * or included, but if the value specifies italic, then the STFontStyle will be italic.
 */
typedef uint16_t STFontStyle;
#define ST_STYLE_NORMAL 1                         /**< Font style normal */
#define ST_STYLE_ITALIC 2                         /**< Font style italic */
#define ST_STYLE_OBLIQUE 3                        /**< Font style oblique */
#define ST_STYLE_INCLINED 4                       /**< Font style inclined */
#define ST_STYLE_SLANTED 5                        /**< Font style slanted */
#define ST_STYLE_REVERSE_ITALIC 6                 /**< Font style reverse italic */
#define ST_STYLE_REVERSE_OBLIQUE 7                /**< Font style reverse oblique */
#define ST_STYLE_UNKNOWN 8                        /**< Font style unknown */


#define ST_PLATFORM_ANY 0xFFFF                    /**< Use any platform ID in font */
#define ST_ENCODING_ANY 0xFFFF                    /**< Use any encoding ID in font */
#define ST_LANGUAGE_ANY 0xFFFF                    /**< Use any language ID in font */
#define ST_NAME_ANY 0xFFFF                        /**< Use any name ID in font */


/**
 * Known scaler and layout engine tags.
 *
 * Sun Microsystems, Inc. maintains an open registry of tags.
 * Submit new tags by sending an email message to
 *        stsf-registry@sun.com
 *
 */

#define ST_SCALER_DUMMY                 0x444D4D59          /**< 'DMMY' Dummy scaler for testing */
#define ST_SCALER_FONTFUSION            0x46465553          /**< 'FFUS' Bitstream FontFusion scaler */
#define ST_SCALER_FREETYPE1             0x46545931          /**< 'FTY1' FreeType version 1 scaler  */
#define ST_SCALER_FREETYPE2             0x46545932          /**< 'FTY2' FreeType version 2 scaler  */
#define ST_SCALER_XATM                  0x5841544D          /**< 'XATM' Adobe XATM-based scaler */
#define ST_SCALER_LUNA                  0x4C554E41          /**< 'LUNA' Luna scaler */
#define ST_LAYOUTENGINE_ICU             0x49435530          /**< 'ICU0' IBM ICU Layout Engine */

/* TT contstants */
/**
 * Platform ID values
 */

#define TT_PLATFORM_UNICODE 0                     /**< Unicode encoding for platform ID */
#define TT_PLATFORM_MACINTOSH 1                   /**< Apple Mac encoding for platform ID */
#define TT_PLATFORM_ISO 2                         /**< ISO encoding for platform ID */
#define TT_PLATFORM_MICROSOFT 3                   /**< Microsoft encoding for platform ID */
#define TT_PLATFORM_CUSTOM 4                      /**< Custom encoding for platform ID */

#define TT_ENCODING_UNICODE_10 0                  /**< Unicode 1.0 semantics */
#define TT_ENCODING_UNICODE_11 1                  /**< Unicode 1.1 semantics */
#define TT_ENCODING_UNICODE_ISO10646 2            /**< ISO 10646:1993 semantics */
#define TT_ENCODING_UNICODE_20 3                  /**< Unicode 2.0 and onward semantics */


/* Microsoft platform-specific encoding IDs */

#define TT_ENCODING_MS_SYMBOL 0                   /**< Microsoft symbol encoding */
#define TT_ENCODING_MS_UNICODE 1                  /**< Microsoft unicode encoding */
#define TT_ENCODING_MS_SHIFTJIS 2                 /**< Microsoft shift JIS encoding */
#define TT_ENCODING_MS_PRC 3                      /**< Microsoft PRC encoding */
#define TT_ENCODING_MS_BIG5 4                     /**< Microsoft BIG5 encoding */
#define TT_ENCODING_MS_WANSUNG 5                  /**< Microsoft WANSUNG encoding */
#define TT_ENCODING_MS_JOHAB 6                    /**< Microsoft JOHAB encoding */
#define TT_ENCODING_MS_UCS4 10                    /**< Microsoft UCS4 encoding */

/* Name IDs */
#define TT_NAME_COPYRIGHTNOTICE 0                 /**< Copyright string */
#define TT_NAME_FONTFAMILY 1                      /**< Font Family name string */
#define TT_NAME_FONTSUBFAMILY 2                   /**< Font Typeface name string */
#define TT_NAME_UNIQUEID 3                        /**< Unique ID string */
#define TT_NAME_FULLFONTNAME 4                    /**< Full Font name string */
#define TT_NAME_VERSIONSTRING 5                   /**< Version string */
#define TT_NAME_POSTSCRIPTNAME 6                  /**< Postscript name string */
#define TT_NAME_TRADEMARK 7                       /**< Trademark string */
#define TT_NAME_MANUFACTURERNAME 8                /**< Manufacturer name string */
#define TT_NAME_DESIGNERNAME 9                    /**< Designer string */
#define TT_NAME_DESCRIPTION 10                    /**< Description string */
#define TT_NAME_VENDORURL 11                      /**< Vendor URL string */
#define TT_NAME_DESIGNERURL 12                    /**< Designer URL string */
#define TT_NAME_LICENSEDESCRIPTION 13             /**< License description string */
#define TT_NAME_LICENSEINFOURL 14                 /**< License info URL string */
#define TT_NAME_PREFERREDFAMILY 16                /**< Preferred family name string */
#define TT_NAME_PREFERREDSUBFAMILY 17             /**< Preferred family typeface name string */
#define TT_NAME_COMPATIBLEFULL 18                 /**< Full compatible name string */
#define TT_NAME_SAMPLETEXT 19                     /**< sample text string */
#define TT_NAME_POSTSCRIPTCIDNAME 20              /**< Postscript CID name string */


/* Microsoft Language ID */

#define TT_LANGUAGE_MS_ARABIC_SAUDIARABIA 0x0401         /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_IRAQ 0x0801                /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_EGYPT 0x0c01               /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_LIBYA 0x1001               /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_ALGERIA 0x1401             /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_MOROCCO 0x1801             /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_TUNISIA 0x1c01             /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_OMAN 0x2001                /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_YEMEN 0x2401               /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_SYRIA 0x2801               /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_JORDAN 0x2c01              /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_LEBANON 0x3001             /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_KUWAIT 0x3401              /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_UAE 0x3801                 /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_BAHRAIN 0x3c01             /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_ARABIC_QATAR 0x4001               /**< Microsoft Arabic language ID */
#define TT_LANGUAGE_MS_BULGARIAN_BULGARIA 0x0402         /**< Microsoft Bulgarian language ID */
#define TT_LANGUAGE_MS_CATALAN_SPAIN 0x0403              /**< Microsoft Catalan language ID */
#define TT_LANGUAGE_MS_CHINESE_TAIWAN 0x0404             /**< Microsoft Chinese language ID */
#define TT_LANGUAGE_MS_CHINESE_PRC 0x0804                /**< Microsoft Chinese language ID */
#define TT_LANGUAGE_MS_CHINESE_HONGKONG 0x0c04           /**< Microsoft Chinese language ID */
#define TT_LANGUAGE_MS_CHINESE_SINGAPORE 0x1004          /**< Microsoft Chinese language ID */
#define TT_LANGUAGE_MS_CHINESE_MACAU 0x1404              /**< Microsoft Chinese language ID */
#define TT_LANGUAGE_MS_CZECH_CZECHREPUBLIC 0x0405        /**< Microsoft Czech language ID */
#define TT_LANGUAGE_MS_DANISH_DENMARK 0x0406             /**< Microsoft Danish language ID */
#define TT_LANGUAGE_MS_GERMAN_GERMANY 0x0407             /**< Microsoft German language ID */
#define TT_LANGUAGE_MS_GERMAN_SWITZERLAND 0x0807         /**< Microsoft German language ID */
#define TT_LANGUAGE_MS_GERMAN_AUSTRIA 0x0c07             /**< Microsoft German language ID */
#define TT_LANGUAGE_MS_GERMAN_LUXEMBOURG 0x1007          /**< Microsoft German language ID */
#define TT_LANGUAGE_MS_GERMAN_LIECHTENSTEIN 0x1407       /**< Microsoft German language ID */
#define TT_LANGUAGE_MS_GREEK_GREECE 0x0408               /**< Microsoft Greek language ID */
#define TT_LANGUAGE_MS_ENGLISH_US 0x0409                 /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_UK 0x0809                 /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_AUSTRALIA 0x0c09          /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_CANADA 0x1009             /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_NEWZEALAND 0x1409         /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_IRELAND 0x1809            /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_SOUTHAFRICA 0x1c09        /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_JAMAICA 0x2009            /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_CARIBBEAN 0x2409          /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_BELIZE 0x2809             /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_TRINIDAD 0x2c09           /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_ZIMBABWE 0x3009           /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_ENGLISH_PHILIPPINES 0x3409        /**< Microsoft English language ID */
#define TT_LANGUAGE_MS_SPANISH_SPAIN_TRADITIONALSORT 0x040a  /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_MEXICO 0x080a             /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_SPAININTERNATIONALSORT 0x0c0a /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_GUATEMALA 0x100a          /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_COSTARICA 0x140a          /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_PANAMA 0x180a             /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_DOMINICANREPUBLIC 0x1c0a  /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_VENEZUELA 0x200a          /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_COLOMBIA 0x240a           /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_PERU 0x280a               /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_ARGENTINA 0x2c0a          /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_ECUADOR 0x300a            /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_CHILE 0x340a              /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_URUGUAY 0x380a            /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_PARAGUAY 0x3c0a           /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_BOLIVIA 0x400a            /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_ELSALVADOR 0x440a         /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_HONDURAS 0x480a           /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_NICARAGUA 0x4c0a          /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_SPANISH_PUERTORICO 0x500a         /**< Microsoft Spanish language ID */
#define TT_LANGUAGE_MS_FINNISH_FINLAND 0x040b            /**< Microsoft Finnish language ID */
#define TT_LANGUAGE_MS_FRENCH_FRANCE 0x040c              /**< Microsoft French language ID */
#define TT_LANGUAGE_MS_FRENCH_BELGIUM 0x080c             /**< Microsoft French language ID */
#define TT_LANGUAGE_MS_FRENCH_CANADA 0x0c0c              /**< Microsoft French language ID */
#define TT_LANGUAGE_MS_FRENCH_SWITZERLAND 0x100c         /**< Microsoft French language ID */
#define TT_LANGUAGE_MS_FRENCH_LUXEMBOURG 0x140c          /**< Microsoft French language ID */
#define TT_LANGUAGE_MS_FRENCH_MONACO 0x180c              /**< Microsoft French language ID */
#define TT_LANGUAGE_MS_HEBREW_ISRAEL 0x040d              /**< Microsoft Hebrew language ID */
#define TT_LANGUAGE_MS_HUNGARIAN_HUNGARY 0x040e          /**< Microsoft Hungarian language ID */
#define TT_LANGUAGE_MS_ICELANDIC_ICELAND 0x040f          /**< Microsoft Icelandic language ID */
#define TT_LANGUAGE_MS_ITALIAN_ITALY 0x0410              /**< Microsoft Italian language ID */
#define TT_LANGUAGE_MS_ITALIAN_SWITZERLAND 0x0810        /**< Microsoft Italian language ID */
#define TT_LANGUAGE_MS_JAPANESE_JAPAN 0x0411             /**< Microsoft Japanese language ID */
#define TT_LANGUAGE_MS_KOREAN_KOREA_EXTENDEDWANSUNG 0x0412  /**< Microsoft Korean language ID */
#define TT_LANGUAGE_MS_DUTCH_NETHERLANDS 0x0413          /**< Microsoft Dutch language ID */
#define TT_LANGUAGE_MS_DUTCH_BELGIUM 0x0813              /**< Microsoft Dutch language ID */
#define TT_LANGUAGE_MS_NORWEGIAN_NORWAY_BOKMAL 0x0414    /**< Microsoft Norwegian language ID */
#define TT_LANGUAGE_MS_NORWEGIAN_NORWAY_NYNORSK 0x0814   /**< Microsoft Norwegian language ID */
#define TT_LANGUAGE_MS_POLISH_POLAND 0x0415              /**< Microsoft Polish language ID */
#define TT_LANGUAGE_MS_PORTUGUESE_BRAZIL 0x0416          /**< Microsoft Portuguese language ID */
#define TT_LANGUAGE_MS_PORTUGUESE_PORTUGAL 0x0816        /**< Microsoft Portuguese language ID */
#define TT_LANGUAGE_MS_ROMANIAN_ROMANIA 0x0418           /**< Microsoft Romanian language ID */
#define TT_LANGUAGE_MS_RUSSIAN_RUSSIA 0x0419             /**< Microsoft Russian language ID */
#define TT_LANGUAGE_MS_CROATIAN_CROATIA 0x041a           /**< Microsoft Croatian language ID */
#define TT_LANGUAGE_MS_SERBIAN_SERBIA_LATIN 0x081a       /**< Microsoft Serbian language ID */
#define TT_LANGUAGE_MS_SERBIAN_SERBIA_CYRILLIC 0x0c1a    /**< Microsoft Serbian language ID */
#define TT_LANGUAGE_MS_SLOVAK_SLOVAKIA 0x041b            /**< Microsoft Slovak language ID */
#define TT_LANGUAGE_MS_ALBANIAN_ALBANIA 0x041c           /**< Microsoft Albanian language ID */
#define TT_LANGUAGE_MS_SWEDISH_SWEDEN 0x041d             /**< Microsoft Swedish language ID */
#define TT_LANGUAGE_MS_SWEDISH_FINLAND 0x081d            /**< Microsoft Swedish language ID */
#define TT_LANGUAGE_MS_THAI_THAILAND 0x041e              /**< Microsoft Thai language ID */
#define TT_LANGUAGE_MS_TURKISH_TURKEY 0x041f             /**< Microsoft Turkish language ID */
#define TT_LANGUAGE_MS_URDU_PAKISTAN 0x0420              /**< Microsoft Urdu language ID */
#define TT_LANGUAGE_MS_INDONESIAN_INDONESIA 0x0421       /**< Microsoft Indonesian language ID */
#define TT_LANGUAGE_MS_UKRAINIAN_UKRAINE 0x0422          /**< Microsoft Ukrainian language ID */
#define TT_LANGUAGE_MS_BELARUSIAN_BELARUS 0x0423         /**< Microsoft Belarusian language ID */
#define TT_LANGUAGE_MS_SLOVENIAN_SLOVENIA 0x0424         /**< Microsoft Slovenian language ID */
#define TT_LANGUAGE_MS_ESTONIAN_ESTONIA 0x0425           /**< Microsoft Estonian language ID */
#define TT_LANGUAGE_MS_LATVIAN_LATVIA 0x0426             /**< Microsoft Latvian language ID */
#define TT_LANGUAGE_MS_LITHUANIAN_LITHUANIA 0x0427       /**< Microsoft Lithuanian language ID */
#define TT_LANGUAGE_MS_FARSI_IRAN 0x0429                 /**< Microsoft Farsi language ID */
#define TT_LANGUAGE_MS_VIETNAMESE_VIETNAM 0x042a         /**< Microsoft Vietnamese language ID */
#define TT_LANGUAGE_MS_ARMENIAN_ARMENIA 0x042b           /**< Microsoft Armenian language ID */
#define TT_LANGUAGE_MS_AZERI_AZERBAIJAN_LATIN 0x042c     /**< Microsoft Azeri language ID */
#define TT_LANGUAGE_MS_AZERI_AZERBAIJAN_CYRILLIC 0x082c  /**< Microsoft Azeri language ID */
#define TT_LANGUAGE_MS_BASQUE_SPAIN 0x042d               /**< Microsoft Basque language ID */
#define TT_LANGUAGE_MS_MACEDONIAN_MACEDONIA 0x042f       /**< Microsoft Macedonian language ID */
#define TT_LANGUAGE_MS_AFRIKAANS_SOUTHAFRICA 0x0436      /**< Microsoft Afrikaans language ID */
#define TT_LANGUAGE_MS_GEORGIAN_GEORGIA 0x0437           /**< Microsoft Georgian language ID */
#define TT_LANGUAGE_MS_FAEROESE_FAEROEISLANDS 0x0438     /**< Microsoft Faeroese language ID */
#define TT_LANGUAGE_MS_HINDI_INDIA 0x0439                /**< Microsoft Hindi language ID */
#define TT_LANGUAGE_MS_MALAY_MALAYSIA 0x043e             /**< Microsoft Malay language ID */
#define TT_LANGUAGE_MS_MALAY_BRUNEIDARUSSALAM 0x083e     /**< Microsoft Malay language ID */
#define TT_LANGUAGE_MS_KAZAKH_KAZAKSTAN 0x043f           /**< Microsoft Kazakh language ID */
#define TT_LANGUAGE_MS_SWAHILI_KENYA 0x0441              /**< Microsoft Swahili language ID */
#define TT_LANGUAGE_MS_UZBEK_UZBEKISTAN_LATIN 0x0443     /**< Microsoft Uzbek language ID */
#define TT_LANGUAGE_MS_UZBEK_UZBEKISTAN_CYRILLIC 0x0843  /**< Microsoft Uzbek language ID */
#define TT_LANGUAGE_MS_TATAR_TATARSTAN 0x0444            /**< Microsoft Tatar language ID */
#define TT_LANGUAGE_MS_PUNJABI_INDIA 0x0446              /**< Microsoft Punjabi language ID */
#define TT_LANGUAGE_MS_GUJARATI_INDIA 0x0447             /**< Microsoft Gujarati language ID */
#define TT_LANGUAGE_MS_TAMIL_INDIA 0x0449                /**< Microsoft Tamil language ID */
#define TT_LANGUAGE_MS_TELUGU_INDIA 0x044a               /**< Microsoft Telugu language ID */
#define TT_LANGUAGE_MS_KANNADA_INDIA 0x044b              /**< Microsoft Kannada language ID */
#define TT_LANGUAGE_MS_MARATHI_INDIA 0x044e              /**< Microsoft Marathi language ID */
#define TT_LANGUAGE_MS_SANSKRIT_INDIA 0x044f             /**< Microsoft Sanskrit language ID */
#define TT_LANGUAGE_MS_KONKANI_INDIA 0x0457              /**< Microsoft Konkani language ID */
#define TT_LANGUAGE_MS_KYRGYZ_KYRGYZSTAN 0x0440          /**< Microsoft Kyrgyz language ID */
#define TT_LANGUAGE_MS_MONGOLIAN_MONGOLIA_CYRILLIC 0x0450 /**< Microsoft Mongolian language ID */
#define TT_LANGUAGE_MS_GALICIAN_SPAIN 0x0456             /**< Microsoft Galician language ID */
#define TT_LANGUAGE_MS_SYRIAC_SYRIA 0x045A               /**< Microsoft Syriac language ID */
#define TT_LANGUAGE_MS_DIVEHI_MALDIVES 0x0465            /**< Microsoft Divehi language ID */


/* Macintosh platform-specific encoding IDs  (script manager codes) */
#define TT_ENCODING_APPLE_ROMAN 0                        /**< Apple Roman encoding ID */
#define TT_ENCODING_APPLE_JAPANESE 1                     /**< Apple Japanese encoding ID */
#define TT_ENCODING_APPLE_TRADITIONALCHINESE 2           /**< Apple Chinese encoding ID */
#define TT_ENCODING_APPLE_KOREAN 3                       /**< Apple Korean encoding ID */
#define TT_ENCODING_APPLE_ARABIC 4                       /**< Apple Arabic encoding ID */
#define TT_ENCODING_APPLE_HEBREW 5                       /**< Apple Hebrew encoding ID */
#define TT_ENCODING_APPLE_GREEK 6                        /**< Apple Greek encoding ID */
#define TT_ENCODING_APPLE_RUSSIAN 7                      /**< Apple Russian encoding ID */
#define TT_ENCODING_APPLE_RSYMBOL 8                      /**< Apple RSymbol encoding ID */
#define TT_ENCODING_APPLE_DEVANAGARI 9                   /**< Apple Devanagari encoding ID */
#define TT_ENCODING_APPLE_GURMUKHI 10                    /**< Apple Gurmukhi encoding ID */
#define TT_ENCODING_APPLE_GUJARATI 11                    /**< Apple Gujarati encoding ID */
#define TT_ENCODING_APPLE_ORIYA 12                       /**< Apple Oriya encoding ID */
#define TT_ENCODING_APPLE_BENGALI 13                     /**< Apple Bengali encoding ID */
#define TT_ENCODING_APPLE_TAMIL 14                       /**< Apple Tamil encoding ID */
#define TT_ENCODING_APPLE_TELUGU 15                      /**< Apple Telugu encoding ID */
#define TT_ENCODING_APPLE_KANNADA 16                     /**< Apple Kannada encoding ID */
#define TT_ENCODING_APPLE_MALAYALAM 17                   /**< Apple Malayalam encoding ID */
#define TT_ENCODING_APPLE_SINHALESE 18                   /**< Apple Sinhalese encoding ID */
#define TT_ENCODING_APPLE_BURMESE 19                     /**< Apple Burmese encoding ID */
#define TT_ENCODING_APPLE_KHMER 20                       /**< Apple Khmer encoding ID */
#define TT_ENCODING_APPLE_THAI 21                        /**< Apple Thai encoding ID */
#define TT_ENCODING_APPLE_LAOTIAN 22                     /**< Apple Laotian encoding ID */
#define TT_ENCODING_APPLE_GEORGIAN 23                    /**< Apple Georgian encoding ID */
#define TT_ENCODING_APPLE_ARMENIAN 24                    /**< Apple Armenian encoding ID */
#define TT_ENCODING_APPLE_SIMPLIFIEDCHINESE 25           /**< Apple Chinese encoding ID */
#define TT_ENCODING_APPLE_TIBETAN 26                     /**< Apple Tibetan encoding ID */
#define TT_ENCODING_APPLE_MONGOLIAN 27                   /**< Apple Mongolian encoding ID */
#define TT_ENCODING_APPLE_GEEZ 28                        /**< Apple Geez encoding ID */
#define TT_ENCODING_APPLE_SLAVIC 29                      /**< Apple Slavic encoding ID */
#define TT_ENCODING_APPLE_VIETNAMESE 30                  /**< Apple Vietnamese encoding ID */
#define TT_ENCODING_APPLE_SINDHI 31                      /**< Apple Sindhi encoding ID */
#define TT_ENCODING_APPLE_UNINTERPRETED 32               /**< Apple Uninterpreted encoding ID */

/* Macintosh Language IDs */
#define TT_LANGUAGE_APPLE_ENGLISH 0                      /**< Apple English language ID */
#define TT_LANGUAGE_APPLE_FRENCH 1                       /**< Apple French language ID */
#define TT_LANGUAGE_APPLE_GERMAN 2                       /**< Apple German language ID */
#define TT_LANGUAGE_APPLE_ITALIAN 3                      /**< Apple Italian language ID */
#define TT_LANGUAGE_APPLE_DUTCH 4                        /**< Apple Dutch language ID */
#define TT_LANGUAGE_APPLE_SWEDISH 5                      /**< Apple Swedish language ID */
#define TT_LANGUAGE_APPLE_SPANISH 6                      /**< Apple Spanish language ID */
#define TT_LANGUAGE_APPLE_DANISH 7                       /**< Apple Danish language ID */
#define TT_LANGUAGE_APPLE_PORTUGUESE 8                   /**< Apple Portuguese language ID */
#define TT_LANGUAGE_APPLE_NORWEGIAN 9                    /**< Apple Norwegian language ID */
#define TT_LANGUAGE_APPLE_HEBREW 10                      /**< Apple Hebrew language ID */
#define TT_LANGUAGE_APPLE_JAPANESE 11                    /**< Apple Japanese language ID */
#define TT_LANGUAGE_APPLE_ARABIC 12                      /**< Apple Arabic language ID */
#define TT_LANGUAGE_APPLE_FINNISH 13                     /**< Apple Finnish language ID */
#define TT_LANGUAGE_APPLE_GREEK 14                       /**< Apple Greek language ID */
#define TT_LANGUAGE_APPLE_ICELANDIC 15                   /**< Apple Icelandic language ID */
#define TT_LANGUAGE_APPLE_MALTESE 16                     /**< Apple Maltese language ID */
#define TT_LANGUAGE_APPLE_TURKISH 17                     /**< Apple Turkish language ID */
#define TT_LANGUAGE_APPLE_CROATIAN 18                    /**< Apple Croatian language ID */
#define TT_LANGUAGE_APPLE_TRADITIONALCHINESE 19          /**< Apple Chinese language ID */
#define TT_LANGUAGE_APPLE_URDU 20                        /**< Apple Urdu language ID */
#define TT_LANGUAGE_APPLE_HINDI 21                       /**< Apple Hindi language ID */
#define TT_LANGUAGE_APPLE_THAI 22                        /**< Apple Thai language ID */
#define TT_LANGUAGE_APPLE_KOREAN 23                      /**< Apple Korean language ID */
#define TT_LANGUAGE_APPLE_LITHUANIAN 24                  /**< Apple Lithuanian language ID */
#define TT_LANGUAGE_APPLE_POLISH 25                      /**< Apple Polish language ID */
#define TT_LANGUAGE_APPLE_HUNGARIAN 26                   /**< Apple Hungarian language ID */
#define TT_LANGUAGE_APPLE_ESTONIAN 27                    /**< Apple Estonian language ID */
#define TT_LANGUAGE_APPLE_LATVIAN 28                     /**< Apple Latvian language ID */
#define TT_LANGUAGE_APPLE_SAMI 29                        /**< Apple Sami language ID */
#define TT_LANGUAGE_APPLE_FAROESE 30                     /**< Apple Faroese language ID */
#define TT_LANGUAGE_APPLE_FARSIPERSIAN 31                /**< Apple Farsi language ID */
#define TT_LANGUAGE_APPLE_RUSSIAN 32                     /**< Apple Russian language ID */
#define TT_LANGUAGE_APPLE_SIMPLIFIEDCHINESE 33           /**< Apple Chinese language ID */
#define TT_LANGUAGE_APPLE_FLEMISH 34                     /**< Apple Flemish language ID */
#define TT_LANGUAGE_APPLE_IRISHGAELIC 35                 /**< Apple Irish language ID */
#define TT_LANGUAGE_APPLE_ALBANIAN 36                    /**< Apple Albanian language ID */
#define TT_LANGUAGE_APPLE_ROMANIAN 37                    /**< Apple Romanian language ID */
#define TT_LANGUAGE_APPLE_CZECH 38                       /**< Apple Czech language ID */
#define TT_LANGUAGE_APPLE_SLOVAK 39                      /**< Apple Slovak language ID */
#define TT_LANGUAGE_APPLE_SLOVENIAN 40                   /**< Apple Solvenian language ID */
#define TT_LANGUAGE_APPLE_YIDDISH 41                     /**< Apple Yiddish language ID */
#define TT_LANGUAGE_APPLE_SERBIAN 42                     /**< Apple Serbian language ID */
#define TT_LANGUAGE_APPLE_MACEDONIAN 43                  /**< Apple Macedonian language ID */
#define TT_LANGUAGE_APPLE_BULGARIAN 44                   /**< Apple Bulgarian language ID */
#define TT_LANGUAGE_APPLE_UKRAINIAN 45                   /**< Apple Ukrainian language ID */
#define TT_LANGUAGE_APPLE_BYELORUSSIAN 46                /**< Apple Byelorussian language ID */
#define TT_LANGUAGE_APPLE_UZBEK 47                       /**< Apple Uzbek language ID */
#define TT_LANGUAGE_APPLE_KAZAKH 48                      /**< Apple Kazakh language ID */
#define TT_LANGUAGE_APPLE_CYRILLICAZERBAIJANI 49         /**< Apple Azerbi language ID */
#define TT_LANGUAGE_APPLE_ARABICAZERBAIJANI 50           /**< Apple Azerbi language ID */
#define TT_LANGUAGE_APPLE_ARMENIAN 51                    /**< Apple Armenian language ID */
#define TT_LANGUAGE_APPLE_GEORGIAN 52                    /**< Apple Georgian language ID */
#define TT_LANGUAGE_APPLE_MOLDAVIAN 53                   /**< Apple Moldavian language ID */
#define TT_LANGUAGE_APPLE_KIRGHIZ 54                     /**< Apple Kirghiz language ID */
#define TT_LANGUAGE_APPLE_TAJIGI 55                      /**< Apple Tajigi language ID */
#define TT_LANGUAGE_APPLE_TURKMEN 56                     /**< Apple Turkmen language ID */
#define TT_LANGUAGE_APPLE_MONGOLIAN 57                   /**< Apple Mongolian language ID */
#define TT_LANGUAGE_APPLE_CYRILLICMONGOLIAN 58           /**< Apple Mongolian language ID */
#define TT_LANGUAGE_APPLE_PASHTO 59                      /**< Apple Pashto language ID */
#define TT_LANGUAGE_APPLE_KURDISH 60                     /**< Apple Kurdish language ID */
#define TT_LANGUAGE_APPLE_KASHMIRI 61                    /**< Apple Kashmiri language ID */
#define TT_LANGUAGE_APPLE_SINDHI 62                      /**< Apple Sindhi language ID */
#define TT_LANGUAGE_APPLE_TIBETAN 63                     /**< Apple Tibetan language ID */
#define TT_LANGUAGE_APPLE_NEPALI 64                      /**< Apple Nepali language ID */
#define TT_LANGUAGE_APPLE_SANSKRIT 65                    /**< Apple Sanskrit language ID */
#define TT_LANGUAGE_APPLE_MARATHI 66                     /**< Apple Marathi language ID */
#define TT_LANGUAGE_APPLE_BENGALI 67                     /**< Apple Bengali language ID */
#define TT_LANGUAGE_APPLE_ASSAMESE 68                    /**< Apple Assamese language ID */
#define TT_LANGUAGE_APPLE_GUJARATI 69                    /**< Apple Gujarati language ID */
#define TT_LANGUAGE_APPLE_PUNJABI 70                     /**< Apple Punjabi language ID */
#define TT_LANGUAGE_APPLE_ORIYA 71                       /**< Apple Oriya language ID */
#define TT_LANGUAGE_APPLE_MALAYALAM 72                   /**< Apple malayalam language ID */
#define TT_LANGUAGE_APPLE_KANNADA 73                     /**< Apple Kannada language ID */
#define TT_LANGUAGE_APPLE_TAMIL 74                       /**< Apple Tamil language ID */
#define TT_LANGUAGE_APPLE_TELUGU 75                      /**< Apple Telugu language ID */
#define TT_LANGUAGE_APPLE_SINHALESE 76                   /**< Apple Sinhalese language ID */
#define TT_LANGUAGE_APPLE_BURMESE 77                     /**< Apple Burmese language ID */
#define TT_LANGUAGE_APPLE_KHMER 78                       /**< Apple Khmer language ID */
#define TT_LANGUAGE_APPLE_LAO 79                         /**< Apple Lao language ID */
#define TT_LANGUAGE_APPLE_VIETNAMESE 80                  /**< Apple Vietnamese language ID */
#define TT_LANGUAGE_APPLE_INDONESIAN 81                  /**< Apple Indonesian language ID */
#define TT_LANGUAGE_APPLE_TAGALONG 82                    /**< Apple Tagalong language ID */
#define TT_LANGUAGE_APPLE_ROMANMALAY 83                  /**< Apple Malay language ID */
#define TT_LANGUAGE_APPLE_ARABICMALAY 84                 /**< Apple Malay language ID */
#define TT_LANGUAGE_APPLE_AMHARIC 85                     /**< Apple Amharic language ID */
#define TT_LANGUAGE_APPLE_TIGRINYA 86                    /**< Apple Tiginya language ID */
#define TT_LANGUAGE_APPLE_GALLA 87                       /**< Apple Galla language ID */
#define TT_LANGUAGE_APPLE_SOMALI 88                      /**< Apple Somali language ID */
#define TT_LANGUAGE_APPLE_SWAHILI 89                     /**< Apple Swahili language ID */
#define TT_LANGUAGE_APPLE_KINYARWANDARUANDA 90           /**< Apple Kinyarwandaruanda language ID */
#define TT_LANGUAGE_APPLE_RUNDI 91                       /**< Apple Rundi language ID */
#define TT_LANGUAGE_APPLE_NYANJACHEWA 92                 /**< Apple Nyanjachewa language ID */
#define TT_LANGUAGE_APPLE_MALAGASY 93                    /**< Apple Malagasy language ID */
#define TT_LANGUAGE_APPLE_ESPERANTO 94                   /**< Apple Esperanto language ID */
#define TT_LANGUAGE_APPLE_WELSH 128                      /**< Apple Welsh language ID */
#define TT_LANGUAGE_APPLE_BASQUE 129                     /**< Apple Basque language ID */
#define TT_LANGUAGE_APPLE_CATALAN 130                    /**< Apple Catalan language ID */
#define TT_LANGUAGE_APPLE_LATIN 131                      /**< Apple Latin language ID */
#define TT_LANGUAGE_APPLE_QUENCHUA 132                   /**< Apple Quenchua language ID */
#define TT_LANGUAGE_APPLE_GUARANI 133                    /**< Apple Guarani language ID */
#define TT_LANGUAGE_APPLE_AYMARA 134                     /**< Apple Aymara language ID */
#define TT_LANGUAGE_APPLE_TATAR 135                      /**< Apple Tatar language ID */
#define TT_LANGUAGE_APPLE_UIGHUR 136                     /**< Apple Uighur language ID */
#define TT_LANGUAGE_APPLE_DZONGKHA 137                   /**< Apple Dzongkha language ID */
#define TT_LANGUAGE_APPLE_ROMANJAVANESE 138              /**< Apple Javanese language ID */
#define TT_LANGUAGE_APPLE_ROMANSUNDANESE 139             /**< Apple Sundanese language ID */
#define TT_LANGUAGE_APPLE_GALICIAN 140                   /**< Apple Galician language ID */
#define TT_LANGUAGE_APPLE_AFRIKAANS 141                  /**< Apple Aftikaans language ID */
#define TT_LANGUAGE_APPLE_BRETON 142                     /**< Apple Breton language ID */
#define TT_LANGUAGE_APPLE_INUKTITUT 143                  /**< Apple Inuktitut language ID */
#define TT_LANGUAGE_APPLE_SCOTTISHGAELIC 144             /**< Apple Scottish language ID */
#define TT_LANGUAGE_APPLE_MANXGAELIC 145                 /**< Apple Manx language ID */
#define TT_LANGUAGE_APPLE_IRISHGAELICWITHDOT 146         /**< Apple Irish language ID */
#define TT_LANGUAGE_APPLE_TONGAN 147                     /**< Apple Tongan language ID */
#define TT_LANGUAGE_APPLE_POLYTONICGREEK 148             /**< Apple Greek language ID */
#define TT_LANGUAGE_APPLE_GREENLANDIC 149                /**< Apple Greeenlandic language ID */
#define TT_LANGUAGE_APPLE_ROMANAZERBAIJANI 150           /**< Apple Azerbaijani language ID */

typedef enum  {
    ST_NO_ERROR = 0,                    /**< no error */
    ST_OK = ST_NO_ERROR,                /**< ditto */
    ST_MEMORY,                          /**< memory allocation error */
    ST_NULL_OR_EMPTY_STRING,            /**< unexpected NULL or empty argument to a function */
    ST_NULL_POINTER,                    /**< unexpected NULL pointer */
    ST_INVALID_ARGUMENT,                /**< invalid argument to an STSF function */
    ST_BAD_FONTPATH,                    /**< invalid font path */
    ST_FONTENUMERATOR_FAILED,           /**< error in font enumerator */
    ST_BAD_SCALERPATH,                  /**< invalid scaler path */
    ST_SCALERENUMERATOR_FAILED,         /**< error in scaler enumerator */
    ST_FONTMANAGER_FAILED,              /**< error in font manager */
    ST_BAD_FONTID,                      /**< font ID is not valid */
    ST_NO_SCALER,                       /**< no scaler is available for the font */
    ST_BUFSIZE,                         /**< insufficient size of a buffer */
    ST_BITDEPTH,                        /**< incorrect bit depth of a raster device */
    ST_PADDING,                         /**< incorrect bitmap padding */
    ST_SERVER_ERROR,                    /**< error communicating with the STFontServer */
    ST_FONT_NOT_FOUND,                  /**< font with the specified name does not exist */
    ST_SCALER_NOT_FOUND,                /**< scaler with the specified scaler ID does not exist */
    ST_LAYOUTENGINE_NOT_FOUND,          /**< layout engine with the specified ID does not exits */
    ST_TEXT_RANGE,                      /**< invalid range of text of the Layout object */
    ST_RENDER_FLAGS,                    /**< invalid rendering flags */
    ST_BAD_TYPEENV,                     /**< corrupted type environment */
    ST_BAD_FONTSIZE,                    /**< font size is not valid */
    ST_UNKNOWN_LANGUAGE,                /**< unknown language */
    ST_UNKNOWN_ENCODING,                /**< unknown encoding */
    ST_NAME_NOT_FOUND,                  /**< name was not found in the font */
    ST_BAD_FONTINSTANCE,                /**< incorrect font instance */
    ST_BAD_FAMILYID,                    /**< fontfamily ID is not valid */
    ST_OBJECT_NOT_FOUND,                /**< drop-in object with the specified tag is not available */
    ST_RANGE,                           /**< index is out of range */
    ST_COUNT,                           /**< object count is incorrect */
    ST_FILEIO,                          /**< error reading or writing files */
    ST_WRONG_FONTTYPE,                  /**< operation not applicable to the selected font */
    ST_CONN_ERROR,                      /**< Client/Server connection error */
    ST_CONN_SEND_ERROR,                 /**< Client/Server connection send error */
    ST_CONN_RECEIVE_ERROR,              /**< Client/Server connection receive error */
    ST_CONN_TIMEOUT_ERROR,              /**< Client/Server connection timeout error */
    ST_PROTO_BUFF,                      /**< Protocol packet is too big */
    ST_PROTO_PACK,                      /**< Error packing or unpacking request parameters */
    ST_PROTO_ERROR,                     /**< Client/Server protocol error */
    ST_LANGUAGE_CHANGED,                /**< STFontGetUnicodeName() replaced the value of ioLanguage */
    ST_PROTECTION,                      /**< Protection violation */
    ST_URL_ERROR,                       /**< File at the specified URL does not exist */
    ST_BAD_COLORMASK,                   /**< Invalid value of STGraphicsColorMap argument */
    ST_NOT_IMPLEMENTED,                 /**< feature not implemented */
    ST_INTERNAL_ERROR,                  /**< internal error */
    ST_BAD_BASELINEMASK,                /**< Invalid value of ST*SetMetrics argument */
    ST_MAX_ERROR                        /**< total number of error codes defined, no function returns this code */
} STStatus;


/*
 * STLocale: ST_SCRIPT_* | ST_LANGUAGE_* | ST_TERRITORY_*
 */

/*
 * STLocale bits:
 *
 *        XX...... ........ ........ ........     reserved, should be set to 0
 *        ..XX.... ........ ........ ........     script variant: 0-3
 *        ....XXXX XXXXXXXX XX...... ........     territory code: 0-16383
 *        ........ ........ ..XXXXXX XXXXXXXX     language code: 0-16383
 *
 */

#define ST_SCRIPTVARIANT_MASK                               0x30000000          /**< Bitmask of the script variant bitfield */
#define ST_TERRITORY_MASK                                   0x0FFFC000          /**< Bitmask of the territory bitfield */
#define ST_LANGUAGE_MASK                                    0x00003FFF          /**< Bitmask of the language bitfield */

#define ST_SCRIPTVARIANT(a)             ((a) & ST_SCRIPTVARIANT_MASK)           /**< Macro that returns the script variant of an STLocale value */
#define ST_TERRITORY(a)                 ((a) & ST_TERRITORY_MASK)               /**< Macro that returns the territory of an STLocale value */ 
#define ST_LANGUAGE(a)                  ((a) & ST_LANGUAGE_MASK)                /**< Macro that returns the langauge of an STLocale value */ 
#define ST_LOCALE(s, t, l)              ((s) | (t) | (l))                       /**< Create an STLocale value from script variant, territory and language */
#define ST_LOCALE2(t, l)                ((t) | (l))                             /**< Create an STLocale value from territory and language */ 


/* Script variant */

#define ST_SCRIPTVARIANT_DEFAULT                                0x00000000

#define ST_SCRIPTVARIANT_0                                      0x00000000
#define ST_SCRIPTVARIANT_1                                      0x10000000
#define ST_SCRIPTVARIANT_2                                      0x20000000
#define ST_SCRIPTVARIANT_3                                      0x30000000

/* Territory */

#define ST_TERRITORY_DEFAULT                                    0x00000000
#define ST_TERRITORY_NOTERRITORY                                (0x3FFF << 14)

#define ST_TERRITORY_AFGHANISTAN                                (  1 << 14)            
#define ST_TERRITORY_ALBANIA                                    (  2 << 14)            
#define ST_TERRITORY_ALGERIA                                    (  3 << 14)            
#define ST_TERRITORY_AMERICAN_SAMOA                             (  4 << 14)            
#define ST_TERRITORY_ANDORRA                                    (  5 << 14)            
#define ST_TERRITORY_ANGOLA                                     (  6 << 14)            
#define ST_TERRITORY_ANGUILLA                                   (  7 << 14)               
#define ST_TERRITORY_ANTARCTICA                                 (  8 << 14)            
#define ST_TERRITORY_ANTIGUA_AND_BARBUDA                        (  9 << 14)
#define ST_TERRITORY_ARGENTINA                                  ( 10 << 14)
#define ST_TERRITORY_ARMENIA                                    ( 11 << 14)             
#define ST_TERRITORY_ARUBA                                      ( 12 << 14)             
#define ST_TERRITORY_AUSTRALIA                                  ( 13 << 14)
#define ST_TERRITORY_AUSTRIA                                    ( 14 << 14)
#define ST_TERRITORY_AZERBAIJAN                                 ( 15 << 14)             
#define ST_TERRITORY_BAHAMAS                                    ( 16 << 14)
#define ST_TERRITORY_BAHRAIN                                    ( 17 << 14)
#define ST_TERRITORY_BANGLADESH                                 ( 18 << 14)
#define ST_TERRITORY_BARBADOS                                   ( 19 << 14)
#define ST_TERRITORY_BELARUS                                    ( 20 << 14)              
#define ST_TERRITORY_BELGIUM                                    ( 21 << 14)
#define ST_TERRITORY_BELIZE                                     ( 22 << 14)
#define ST_TERRITORY_BENIN                                      ( 23 << 14)             
#define ST_TERRITORY_BERMUDA                                    ( 24 << 14)
#define ST_TERRITORY_BHUTAN                                     ( 25 << 14)
#define ST_TERRITORY_BOLIVIA                                    ( 26 << 14)
#define ST_TERRITORY_BOSNIA_AND_HERZEGOWINA                     ( 27 << 14)
#define ST_TERRITORY_BOTSWANA                                   ( 28 << 14)
#define ST_TERRITORY_BOUVET_ISLAND                              ( 29 << 14)
#define ST_TERRITORY_BRAZIL                                     ( 30 << 14)
#define ST_TERRITORY_BRITISH_INDIAN_OCEAN_TERRITORY             ( 31 << 14)
#define ST_TERRITORY_BRITISH_VIRGIN_ISLANDS                     ( 32 << 14)
#define ST_TERRITORY_BRUNEI_DARUSSALAM                          ( 33 << 14)
#define ST_TERRITORY_BULGARIA                                   ( 34 << 14)             
#define ST_TERRITORY_BURKINA_FASO                               ( 35 << 14)             
#define ST_TERRITORY_BURUNDI                                    ( 36 << 14)             
#define ST_TERRITORY_CAMBODIA                                   ( 37 << 14)             
#define ST_TERRITORY_CAMEROON                                   ( 38 << 14)             
#define ST_TERRITORY_CANADA                                     ( 39 << 14)             
#define ST_TERRITORY_CAPE_VERDE                                 ( 40 << 14)             
#define ST_TERRITORY_CAYMAN_ISLANDS                             ( 41 << 14)             
#define ST_TERRITORY_CENTRAL_AFRICAN_REPUBLIC                   ( 42 << 14)             
#define ST_TERRITORY_CHAD                                       ( 43 << 14)             
#define ST_TERRITORY_CHILE                                      ( 44 << 14)             
#define ST_TERRITORY_CHINA                                      ( 45 << 14)             
#define ST_TERRITORY_CHRISTMAS_ISLAND                           ( 46 << 14)             
#define ST_TERRITORY_COCOS_ISLANDS                              ( 47 << 14)             
#define ST_TERRITORY_COLOMBIA                                   ( 48 << 14)             
#define ST_TERRITORY_COMOROS                                    ( 49 << 14)             
#define ST_TERRITORY_CONGO                                      ( 50 << 14)             
#define ST_TERRITORY_COOK_ISLANDS                               ( 51 << 14)             
#define ST_TERRITORY_COSTA_RICA                                 ( 52 << 14)             
#define ST_TERRITORY_COTE_DIVOIRE                               ( 53 << 14)             
#define ST_TERRITORY_CROATIA                                    ( 54 << 14)                  
#define ST_TERRITORY_CUBA                                       ( 55 << 14)             
#define ST_TERRITORY_CYPRUS                                     ( 56 << 14)             
#define ST_TERRITORY_CZECH_REPUBLIC                             ( 57 << 14)              
#define ST_TERRITORY_DENMARK                                    ( 58 << 14)             
#define ST_TERRITORY_DJIBOUTI                                   ( 59 << 14)             
#define ST_TERRITORY_DOMINICA                                   ( 60 << 14)             
#define ST_TERRITORY_DOMINICAN_REPUBLIC                         ( 61 << 14)             
#define ST_TERRITORY_EAST_TIMOR                                 ( 62 << 14)             
#define ST_TERRITORY_ECUADOR                                    ( 63 << 14)             
#define ST_TERRITORY_EGYPT                                      ( 64 << 14)             
#define ST_TERRITORY_EL_SALVADOR                                ( 65 << 14)             
#define ST_TERRITORY_EQUATORIAL_GUINEA                          ( 66 << 14)             
#define ST_TERRITORY_ERITREA                                    ( 67 << 14)             
#define ST_TERRITORY_ESTONIA                                    ( 68 << 14)              
#define ST_TERRITORY_ETHIOPIA                                   ( 69 << 14)             
#define ST_TERRITORY_FALKLAND_ISLANDS                           ( 70 << 14)             
#define ST_TERRITORY_FAROE_ISLANDS                              ( 71 << 14)             
#define ST_TERRITORY_FIJI                                       ( 72 << 14)             
#define ST_TERRITORY_FINLAND                                    ( 73 << 14)             
#define ST_TERRITORY_FRANCE                                     ( 74 << 14)             
#define ST_TERRITORY_FRENCH_GUIANA                              ( 75 << 14)             
#define ST_TERRITORY_FRENCH_POLYNESIA                           ( 76 << 14)             
#define ST_TERRITORY_FRENCH_SOUTHERN_TERRITORIES                ( 77 << 14)             
#define ST_TERRITORY_GABON                                      ( 78 << 14)             
#define ST_TERRITORY_GAMBIA                                     ( 79 << 14)             
#define ST_TERRITORY_GEORGIA                                    ( 80 << 14)              
#define ST_TERRITORY_GERMANY                                    ( 81 << 14)             
#define ST_TERRITORY_GHANA                                      ( 82 << 14)             
#define ST_TERRITORY_GIBRALTAR                                  ( 83 << 14)             
#define ST_TERRITORY_GREECE                                     ( 84 << 14)             
#define ST_TERRITORY_GREENLAND                                  ( 85 << 14)             
#define ST_TERRITORY_GRENADA                                    ( 86 << 14)             
#define ST_TERRITORY_GUADELOUPE                                 ( 87 << 14)             
#define ST_TERRITORY_GUAM                                       ( 88 << 14)             
#define ST_TERRITORY_GUATEMALA                                  ( 89 << 14)             
#define ST_TERRITORY_GUINEA                                     ( 90 << 14)             
#define ST_TERRITORY_GUINEA_BISSAU                              ( 91 << 14)             
#define ST_TERRITORY_GUYANA                                     ( 92 << 14)             
#define ST_TERRITORY_HAITI                                      ( 93 << 14)             
#define ST_TERRITORY_HEARD_AND_MC_DONALD_ISLANDS                ( 94 << 14)             
#define ST_TERRITORY_HONDURAS                                   ( 95 << 14)             
#define ST_TERRITORY_HONG_KONG                                  ( 96 << 14)             
#define ST_TERRITORY_HUNGARY                                    ( 97 << 14)             
#define ST_TERRITORY_ICELAND                                    ( 98 << 14)             
#define ST_TERRITORY_INDIA                                      ( 99 << 14)             
#define ST_TERRITORY_INDONESIA                                  (100 << 14)
#define ST_TERRITORY_IRAN                                       (101 << 14)
#define ST_TERRITORY_IRAQ                                       (102 << 14)
#define ST_TERRITORY_IRELAND                                    (103 << 14)
#define ST_TERRITORY_ISRAEL                                     (104 << 14)
#define ST_TERRITORY_ITALY                                      (105 << 14)
#define ST_TERRITORY_JAMAICA                                    (106 << 14)
#define ST_TERRITORY_JAPAN                                      (107 << 14)
#define ST_TERRITORY_JORDAN                                     (108 << 14)
#define ST_TERRITORY_KAZAKHSTAN                                 (109 << 14)             
#define ST_TERRITORY_KENYA                                      (110 << 14)
#define ST_TERRITORY_KIRIBATI                                   (111 << 14)
#define ST_TERRITORY_KUWAIT                                     (112 << 14)
#define ST_TERRITORY_KYRGYZSTAN                                 (113 << 14)             
#define ST_TERRITORY_LAOS                                       (114 << 14)
#define ST_TERRITORY_LATVIA                                     (115 << 14)             
#define ST_TERRITORY_LEBANON                                    (116 << 14)
#define ST_TERRITORY_LESOTHO                                    (117 << 14)
#define ST_TERRITORY_LIBERIA                                    (118 << 14)
#define ST_TERRITORY_LIBYA                                      (119 << 14)
#define ST_TERRITORY_LIECHTENSTEIN                              (120 << 14)
#define ST_TERRITORY_LITHUANIA                                  (121 << 14)             
#define ST_TERRITORY_LUXEMBOURG                                 (122 << 14)
#define ST_TERRITORY_MACAU                                      (123 << 14)
#define ST_TERRITORY_MACEDONIA                                  (124 << 14)
#define ST_TERRITORY_MADAGASCAR                                 (125 << 14)
#define ST_TERRITORY_MALAWI                                     (126 << 14)
#define ST_TERRITORY_MALAYSIA                                   (127 << 14)
#define ST_TERRITORY_MALDIVES                                   (128 << 14)
#define ST_TERRITORY_MALI                                       (129 << 14)
#define ST_TERRITORY_MALTA                                      (130 << 14)
#define ST_TERRITORY_MARSHALL_ISLANDS                           (131 << 14)
#define ST_TERRITORY_MARTINIQUE                                 (132 << 14)
#define ST_TERRITORY_MAURITANIA                                 (133 << 14)
#define ST_TERRITORY_MAURITIUS                                  (134 << 14)
#define ST_TERRITORY_MAYOTTE                                    (135 << 14)             
#define ST_TERRITORY_METROPOLITAN_FRANCE                        (136 << 14)             
#define ST_TERRITORY_MEXICO                                     (137 << 14)
#define ST_TERRITORY_MICRONESIA                                 (138 << 14)
#define ST_TERRITORY_MOLDOVA                                    (139 << 14)             
#define ST_TERRITORY_MONACO                                     (140 << 14)
#define ST_TERRITORY_MONGOLIA                                   (141 << 14)
#define ST_TERRITORY_MONTSERRAT                                 (142 << 14)
#define ST_TERRITORY_MOROCCO                                    (143 << 14)
#define ST_TERRITORY_MOZAMBIQUE                                 (144 << 14)
#define ST_TERRITORY_MYANMAR                                    (145 << 14)
#define ST_TERRITORY_NAMIBIA                                    (146 << 14)
#define ST_TERRITORY_NAURU                                      (147 << 14)
#define ST_TERRITORY_NEPAL                                      (148 << 14)
#define ST_TERRITORY_NETHERLANDS                                (149 << 14)
#define ST_TERRITORY_NETHERLANDS_ANTILLES                       (150 << 14)
#define ST_TERRITORY_NEW_CALEDONIA                              (151 << 14)
#define ST_TERRITORY_NEW_ZEALAND                                (152 << 14)
#define ST_TERRITORY_NICARAGUA                                  (153 << 14)
#define ST_TERRITORY_NIGER                                      (154 << 14)
#define ST_TERRITORY_NIGERIA                                    (155 << 14)
#define ST_TERRITORY_NIUE                                       (156 << 14)
#define ST_TERRITORY_NORFOLK_ISLAND                             (157 << 14)
#define ST_TERRITORY_NORTHERN_MARIANA_ISLANDS                   (158 << 14)
#define ST_TERRITORY_NORTH_KOREA                                (159 << 14)
#define ST_TERRITORY_NORWAY                                     (160 << 14)
#define ST_TERRITORY_OMAN                                       (161 << 14)
#define ST_TERRITORY_PAKISTAN                                   (162 << 14)
#define ST_TERRITORY_PALAU                                      (163 << 14)
#define ST_TERRITORY_PANAMA                                     (164 << 14)
#define ST_TERRITORY_PAPUA_NEW_GUINEA                           (165 << 14)
#define ST_TERRITORY_PARAGUAY                                   (166 << 14)
#define ST_TERRITORY_PERU                                       (167 << 14)
#define ST_TERRITORY_PHILIPPINES                                (168 << 14)
#define ST_TERRITORY_PITCAIRN                                   (169 << 14)
#define ST_TERRITORY_POLAND                                     (170 << 14)
#define ST_TERRITORY_PORTUGAL                                   (171 << 14)
#define ST_TERRITORY_PUERTO_RICO                                (172 << 14)
#define ST_TERRITORY_QATAR                                      (173 << 14)
#define ST_TERRITORY_REUNION                                    (174 << 14)
#define ST_TERRITORY_ROMANIA                                    (175 << 14)
#define ST_TERRITORY_RUSSIAN_FEDERATION                         (176 << 14)
#define ST_TERRITORY_RUSSIA ST_TERRITORY_RUSSIAN_FEDERATION
#define ST_TERRITORY_RWANDA                                     (177 << 14)
#define ST_TERRITORY_SAINT_KITTS_AND_NEVIS                      (178 << 14)
#define ST_TERRITORY_SAINT_LUCIA                                (179 << 14)
#define ST_TERRITORY_SAINT_VINCENT_AND_THE_GRENADINES           (180 << 14)
#define ST_TERRITORY_SAMOA                                      (181 << 14)
#define ST_TERRITORY_SAN_MARINO                                 (182 << 14)
#define ST_TERRITORY_SAO_TOME_AND_PRINCIPE                      (183 << 14)
#define ST_TERRITORY_SAUDI_ARABIA                               (184 << 14)
#define ST_TERRITORY_SENEGAL                                    (185 << 14)
#define ST_TERRITORY_SEYCHELLES                                 (186 << 14)
#define ST_TERRITORY_SIERRA LEONE                               (187 << 14)
#define ST_TERRITORY_SINGAPORE                                  (188 << 14)
#define ST_TERRITORY_SLOVAKIA                                   (189 << 14) 
#define ST_TERRITORY_SLOVENIA                                   (190 << 14) 
#define ST_TERRITORY_SOLOMON_ISLANDS                            (191 << 14)
#define ST_TERRITORY_SOMALIA                                    (192 << 14)
#define ST_TERRITORY_SOUTH_AFRICA                               (193 << 14)
#define ST_TERRITORY_SOUTH_KOREA                                (194 << 14)
#define ST_TERRITORY_SPAIN                                      (195 << 14)
#define ST_TERRITORY_SRI_LANKA                                  (196 << 14)
#define ST_TERRITORY_ST_HELENA                                  (197 << 14)
#define ST_TERRITORY_ST_PIERRE_AND_MIQUELON                     (198 << 14)
#define ST_TERRITORY_SUDAN                                      (199 << 14)
#define ST_TERRITORY_SURINAME                                   (200 << 14)
#define ST_TERRITORY_SVALBARD_AND_JAN_MAYEN_ISLANDS             (201 << 14)
#define ST_TERRITORY_SWAZILAND                                  (202 << 14)
#define ST_TERRITORY_SWEDEN                                     (203 << 14)
#define ST_TERRITORY_SWITZERLAND                                (204 << 14)
#define ST_TERRITORY_SYRIA                                      (205 << 14)
#define ST_TERRITORY_TAIWAN                                     (206 << 14)
#define ST_TERRITORY_TAJIKISTAN                                 (207 << 14) 
#define ST_TERRITORY_TANZANIA                                   (208 << 14)
#define ST_TERRITORY_THAILAND                                   (209 << 14)
#define ST_TERRITORY_TOGO                                       (210 << 14)
#define ST_TERRITORY_TOKELAU                                    (211 << 14)
#define ST_TERRITORY_TONGA                                      (212 << 14)
#define ST_TERRITORY_TRINIDAD_AND_TOBAGO                        (213 << 14)
#define ST_TERRITORY_TUNISIA                                    (214 << 14)
#define ST_TERRITORY_TURKEY                                     (215 << 14)
#define ST_TERRITORY_TURKMENISTAN                               (216 << 14) 
#define ST_TERRITORY_TURKS_AND_CAICOS_ISLANDS                   (217 << 14)
#define ST_TERRITORY_TUVALU                                     (218 << 14)
#define ST_TERRITORY_UGANDA                                     (219 << 14)
#define ST_TERRITORY_UNITED_KINGDOM                             (220 << 14)
#define ST_TERRITORY_UKRAINE                                    (221 << 14)
#define ST_TERRITORY_UNITED_ARAB_EMIRATES                       (222 << 14)
#define ST_TERRITORY_URUGUAY                                    (223 << 14)
#define ST_TERRITORY_UNITED_STATES                              (224 << 14)
#define ST_TERRITORY_UNITED_STATES_MINOR_OUTLYING_ISLANDS       (225 << 14)
#define ST_TERRITORY_UNITED_STATES_VIRGIN_ISLANDS               (226 << 14)
#define ST_TERRITORY_UZBEKISTAN                                 (227 << 14) 
#define ST_TERRITORY_VANUATU                                    (228 << 14)
#define ST_TERRITORY_VATICAN                                    (229 << 14)
#define ST_TERRITORY_VENEZUELA                                  (230 << 14)
#define ST_TERRITORY_VIETNAM                                    (231 << 14)
#define ST_TERRITORY_WALLIS_AND_FUTUNA_ISLANDS                  (232 << 14)
#define ST_TERRITORY_WESTERN_SAHARA                             (233 << 14)
#define ST_TERRITORY_YEMEN                                      (234 << 14)
#define ST_TERRITORY_YUGOSLAVIA                                 (235 << 14)
#define ST_TERRITORY_ZAIRE                                      (236 << 14)
#define ST_TERRITORY_ZAMBIA                                     (237 << 14)
#define ST_TERRITORY_ZIMBABWE                                   (238 << 14)
                                                                
#define ST_TERRITORY_UK ST_TERRITORY_UNITED_KINGDOM                     
#define ST_TERRITORY_US ST_TERRITORY_UNITED_STATES                   

/* Language */
                                                               
#define ST_LANGUAGE_DEFAULT                                     0x00000000             
#define ST_LANGUAGE_NOLANGUAGE                                  0x3FFF
                                                               
#define ST_LANGUAGE_ABKHAZIAN                                   1   
#define ST_LANGUAGE_AFAR                                        2   
#define ST_LANGUAGE_AFRIKAANS                                   3   
#define ST_LANGUAGE_ALBANIAN                                    4   
#define ST_LANGUAGE_AMHARIC                                     5   
#define ST_LANGUAGE_ARABIC                                      6   
#define ST_LANGUAGE_ARMENIAN                                    7   
#define ST_LANGUAGE_ASSAMESE                                    8   
#define ST_LANGUAGE_AYMARA                                      9   
#define ST_LANGUAGE_AZERBAIJANI                                 10  
#define ST_LANGUAGE_BASHKIR                                     11  
#define ST_LANGUAGE_BASQUE                                      12  
#define ST_LANGUAGE_BENGALI                                     13  
#define ST_LANGUAGE_BHUTANI                                     14  
#define ST_LANGUAGE_BIHARI                                      15  
#define ST_LANGUAGE_BISLAMA                                     16  
#define ST_LANGUAGE_BRETON                                      17  
#define ST_LANGUAGE_BULGARIAN                                   18  
#define ST_LANGUAGE_BURMESE                                     19  
#define ST_LANGUAGE_BYELORUSSIAN                                20  
#define ST_LANGUAGE_CAMBODIAN                                   21  
#define ST_LANGUAGE_CATALAN                                     22  
#define ST_LANGUAGE_CHINESE                                     23  
#define ST_LANGUAGE_CORSICAN                                    24  
#define ST_LANGUAGE_CROATIAN                                    25  
#define ST_LANGUAGE_CZECH                                       26  
#define ST_LANGUAGE_DANISH                                      27  
#define ST_LANGUAGE_DUTCH                                       28  
#define ST_LANGUAGE_ENGLISH                                     29  
#define ST_LANGUAGE_ESPERANTO                                   30  
#define ST_LANGUAGE_ESTONIAN                                    31  
#define ST_LANGUAGE_FAEROESE                                    32  
#define ST_LANGUAGE_FIJI                                        33  
#define ST_LANGUAGE_FINNISH                                     34  
#define ST_LANGUAGE_FRENCH                                      35  
#define ST_LANGUAGE_FRISIAN                                     36  
#define ST_LANGUAGE_GALICIAN                                    37  
#define ST_LANGUAGE_GEORGIAN                                    38  
#define ST_LANGUAGE_GERMAN                                      39  
#define ST_LANGUAGE_GREEK                                       40  
#define ST_LANGUAGE_GREENLANDIC                                 41  
#define ST_LANGUAGE_GUARANI                                     42  
#define ST_LANGUAGE_GUJARATI                                    43  
#define ST_LANGUAGE_HAUSA                                       44  
#define ST_LANGUAGE_HEBREW                                      45  
#define ST_LANGUAGE_HINDI                                       46  
#define ST_LANGUAGE_HUNGARIAN                                   47  
#define ST_LANGUAGE_ICELANDIC                                   48  
#define ST_LANGUAGE_INDONESIAN                                  49  
#define ST_LANGUAGE_INTERLINGUA                                 50  
#define ST_LANGUAGE_INTERLINGUE                                 51  
#define ST_LANGUAGE_INUKTITUT                                   52  
#define ST_LANGUAGE_INUPIAK                                     53  
#define ST_LANGUAGE_IRISH                                       54  
#define ST_LANGUAGE_ITALIAN                                     55  
#define ST_LANGUAGE_JAPANESE                                    56  
#define ST_LANGUAGE_JAVANESE                                    57  
#define ST_LANGUAGE_KANNADA                                     58  
#define ST_LANGUAGE_KASHMIRI                                    59  
#define ST_LANGUAGE_KAZAKH                                      60  
#define ST_LANGUAGE_KINYARWANDA                                 61  
#define ST_LANGUAGE_KIRGHIZ                                     62  
#define ST_LANGUAGE_KIRUNDI                                     63  
#define ST_LANGUAGE_KOREAN                                      64  
#define ST_LANGUAGE_KURDISH                                     65  
#define ST_LANGUAGE_LAOTHIAN                                    66  
#define ST_LANGUAGE_LATIN                                       67  
#define ST_LANGUAGE_LATVIAN                                     68  
#define ST_LANGUAGE_LINGALA                                     69  
#define ST_LANGUAGE_LITHUANIAN                                  70  
#define ST_LANGUAGE_MACEDONIAN                                  71  
#define ST_LANGUAGE_MALAGASY                                    72  
#define ST_LANGUAGE_MALAY                                       73  
#define ST_LANGUAGE_MALAYALAM                                   74  
#define ST_LANGUAGE_MALTESE                                     75  
#define ST_LANGUAGE_MAORI                                       76  
#define ST_LANGUAGE_MARATHI                                     77  
#define ST_LANGUAGE_MOLDAVIAN                                   78  
#define ST_LANGUAGE_MONGOLIAN                                   79  
#define ST_LANGUAGE_NAURU                                       80  
#define ST_LANGUAGE_NEPALI                                      81  
#define ST_LANGUAGE_NORWEGIAN                                   82  
#define ST_LANGUAGE_OCCITAN                                     83  
#define ST_LANGUAGE_ORIYA                                       84  
#define ST_LANGUAGE_OROMO                                       85  
#define ST_LANGUAGE_PASHTO                                      86  
#define ST_LANGUAGE_PERSIAN                                     87  
#define ST_LANGUAGE_POLISH                                      88  
#define ST_LANGUAGE_PORTUGUESE                                  89  
#define ST_LANGUAGE_PUNJABI                                     90  
#define ST_LANGUAGE_QUECHUA                                     91  
#define ST_LANGUAGE_RHAETO_ROMANCE                              92  
#define ST_LANGUAGE_ROMANIAN                                    93  
#define ST_LANGUAGE_RUSSIAN                                     94  
#define ST_LANGUAGE_SAMOAN                                      95  
#define ST_LANGUAGE_SANGRO                                      96  
#define ST_LANGUAGE_SANSKRIT                                    97  
#define ST_LANGUAGE_SCOTS_GAELIC                                98  
#define ST_LANGUAGE_SERBIAN                                     99  
#define ST_LANGUAGE_SERBO_CROATIAN                              100 
#define ST_LANGUAGE_SESOTHO                                     101 
#define ST_LANGUAGE_SETSWANA                                    102 
#define ST_LANGUAGE_SHONA                                       103 
#define ST_LANGUAGE_SINDHI                                      104 
#define ST_LANGUAGE_SINHALESE                                   105 
#define ST_LANGUAGE_SISWATI                                     106 
#define ST_LANGUAGE_SLOVAK                                      107 
#define ST_LANGUAGE_SLOVENIAN                                   108 
#define ST_LANGUAGE_SOMALI                                      109 
#define ST_LANGUAGE_SPANISH                                     110 
#define ST_LANGUAGE_SUNDANESE                                   111 
#define ST_LANGUAGE_SWAHILI                                     112 
#define ST_LANGUAGE_SWEDISH                                     113 
#define ST_LANGUAGE_TAGALOG                                     114 
#define ST_LANGUAGE_TAJIK                                       115 
#define ST_LANGUAGE_TAMIL                                       116 
#define ST_LANGUAGE_TATAR                                       117 
#define ST_LANGUAGE_TELUGU                                      118 
#define ST_LANGUAGE_THAI                                        119 
#define ST_LANGUAGE_TIBETAN                                     120 
#define ST_LANGUAGE_TIGRINYA                                    121 
#define ST_LANGUAGE_TONGA                                       122 
#define ST_LANGUAGE_TSONGA                                      123 
#define ST_LANGUAGE_TURKISH                                     124 
#define ST_LANGUAGE_TURKMEN                                     125 
#define ST_LANGUAGE_TWI                                         126 
#define ST_LANGUAGE_UIGHUR                                      127 
#define ST_LANGUAGE_UKRAINIAN                                   128 
#define ST_LANGUAGE_URDU                                        129 
#define ST_LANGUAGE_UZBEK                                       130 
#define ST_LANGUAGE_VIETNAMESE                                  131 
#define ST_LANGUAGE_VOLAPUK                                     132 
#define ST_LANGUAGE_WELSH                                       133 
#define ST_LANGUAGE_WOLOF                                       134 
#define ST_LANGUAGE_XHOSA                                       135 
#define ST_LANGUAGE_YIDDISH                                     136 
#define ST_LANGUAGE_YORUBA                                      137 
#define ST_LANGUAGE_ZHUANG                                      138 
#define ST_LANGUAGE_ZULU                                        139 

/* Script */

#define ST_SCRIPT_ARABIC                        0x61726162 /* 'arab' (ARABIC) */
#define ST_SCRIPT_ARMENIAN                      0x61726D6E /* 'armn' (ARMENIAN) */
#define ST_SCRIPT_BENGALI                       0x62656E67 /* 'beng' (BENGALI) */
#define ST_SCRIPT_BOPOMOFO                      0x626F706F /* 'bopo' (BOPOMOFO) */
#define ST_SCRIPT_BRAILLE                       0x62726169 /* 'brai' (BRAILLE) */
#define ST_SCRIPT_CANADIAN_SYLLABICS            0x63616E73 /* 'cans' (CANADIAN SYLLABICS */
#define ST_SCRIPT_CHEROKEE                      0x63686572 /* 'cher' (CHEROKEE) */
#define ST_SCRIPT_COPTIC                        0x71616163 /* 'qaac' (COPTIC) */
#define ST_SCRIPT_CYRILLIC                      0x6379726C /* 'cyrl' (CYRILLIC) */
#define ST_SCRIPT_DESERET                       0x64737274 /* 'dsrt' (DESERET) */
#define ST_SCRIPT_DEVANAGARI                    0x64657661 /* 'deva' (DEVANAGARI) */
#define ST_SCRIPT_ETHIOPIC                      0x65746869 /* 'ethi' (ETHIOPIC) */
#define ST_SCRIPT_GEORGIAN                      0x67656F72 /* 'geor' (GEORGIAN) */
#define ST_SCRIPT_GOTHIC                        0x676F7468 /* 'goth' (GOTHIC) */
#define ST_SCRIPT_GREEK                         0x6772656B /* 'grek' (GREEK) */
#define ST_SCRIPT_GUJARATI                      0x67756A72 /* 'gujr' (GUJARATI) */
#define ST_SCRIPT_GURMUKHI                      0x67757275 /* 'guru' (GURMUKHI) */
#define ST_SCRIPT_HAN                           0x68616E69 /* 'hani' (HAN) */
#define ST_SCRIPT_HANGUL                        0x68616E67 /* 'hang' (HANGUL) */
#define ST_SCRIPT_HEBREW                        0x68656272 /* 'hebr' (HEBREW) */
#define ST_SCRIPT_HIRAGANA                      0x68697261 /* 'hira' (HIRAGANA) */
#define ST_SCRIPT_JAMO                          0x6A616D6F /* 'jamo' (HANGUL JAMO */
#define ST_SCRIPT_KANNADA                       0x6B6E6461 /* 'knda' (KANNADA) */
#define ST_SCRIPT_KATAKANA                      0x6B617461 /* 'kata' (KATAKANA) */
#define ST_SCRIPT_KHMER                         0x6B686D72 /* 'khmr' (KHMER) */
#define ST_SCRIPT_LAO                           0x6C616F6F /* 'laoo' (LAO) */ 
#define ST_SCRIPT_LATIN                         0x6C61746E /* 'latn' (LATIN) */
#define ST_SCRIPT_MALAYALAM                     0x6D6C796D /* 'mlym' (MALAYALAM) */
#define ST_SCRIPT_MONGOLIAN                     0x6D6F6E67 /* 'mong' (MONGOLIAN) */
#define ST_SCRIPT_MYANMAR                       0x6D796D72 /* 'mymr' (MYANMAR) */
#define ST_SCRIPT_OGHAM                         0x6F67616D /* 'ogam' (OGHAM) */
#define ST_SCRIPT_OLDITALIC                     0x6974616C /* 'ital' (OLD-ITALIC) */
#define ST_SCRIPT_ORIYA                         0x6F727961 /* 'orya' (ORIYA) */
#define ST_SCRIPT_RUNIC                         0x72756E72 /* 'runr' (RUNIC) */
#define ST_SCRIPT_SINHALA                       0x73696E68 /* 'sinh' (SINHALA) */
#define ST_SCRIPT_SYRIAC                        0x73797263 /* 'syrc' (SYRIAC) */
#define ST_SCRIPT_TAMIL                         0x74616D6C /* 'taml' (TAMIL) */
#define ST_SCRIPT_TELUGU                        0x74656C75 /* 'telu' (TELUGU) */
#define ST_SCRIPT_THAANA                        0x74686161 /* 'thaa' (THAANA) */
#define ST_SCRIPT_THAI                          0x74686169 /* 'thai' (THAI) */
#define ST_SCRIPT_TIBETAN                       0x74696274 /* 'tibt' (TIBETAN) */
#define ST_SCRIPT_CANADIAN_ABORIGINAL           0x63616E73 /* 'cans' (CANADIAN-ABORIGINAL) */
#define ST_SCRIPT_YI                            0x79696969 /* 'yiii' (YI) */    

#define ST_SCRIPT_ZYYY                          0x7A797979 /* 'zyyy' (COMMON) */
#define ST_SCRIPT_QAAI                          0x71616169 /* 'qaai' (INHERITED) */

#define ST_SCRIPT_NOSCRIPT                      0x00000000

/* XST Encodings */

typedef uint32_t XSTEncoding;                       /**< ST_SCRIPT_*                                            */


#define XST_ENCODING_NOENCODING                   -1
#define XST_ENCODING_DEFAULT                      0
#define XST_ENCODING_UTF7                         1
#define XST_ENCODING_UTF8                         2
#define XST_ENCODING_UTF16                        3
#define XST_ENCODING_UTF32                        4
#define XST_ENCODING_UCS2                         5
#define XST_ENCODING_UCS4                         6
#define XST_ENCODING_GLYPH8                       7
#define XST_ENCODING_GLYPH16                      8
#define XST_ENCODING_GLYPH32                      9
#define XST_ENCODING_ISO8859_1                    10
#define XST_ENCODING_ISO8859_2                    11
#define XST_ENCODING_ISO8859_3                    12
#define XST_ENCODING_ISO8859_4                    13
#define XST_ENCODING_ISO8859_5                    14
#define XST_ENCODING_ISO8859_6                    15
#define XST_ENCODING_ISO8859_7                    16
#define XST_ENCODING_ISO8859_8                    17
#define XST_ENCODING_ISO8859_9                    18
#define XST_ENCODING_ISO8859_10                   19
#define XST_ENCODING_ISO8859_11                   20
#define XST_ENCODING_ISO8859_12                   21
#define XST_ENCODING_ISO8859_13                   22
#define XST_ENCODING_ISO8859_14                   23
#define XST_ENCODING_ISO8859_15                   24
#define XST_ENCODING_US_ASCII                     25
#define XST_ENCODING_EUC                          26
#define XST_ENCODING_EUCJP                        27
#define XST_ENCODING_EUCKR                        28
#define XST_ENCODING_EUCZH                        29
#define XST_ENCODING_PCK                          30
#define XST_ENCODING_ANSI1251                     31
#define XST_ENCODING_KOI8R                        32
#define XST_ENCODING_TIS620                       33
#define XST_ENCODING_GB18030                      34
#define XST_ENCODING_GBK                          35
#define XST_ENCODING_BIG5HK                       36
#define XST_ENCODING_BIG5                         37

#define XST_ENCODING_MAX                          XST_ENCODING_BIG5

#endif /* __STTYPES_H */

/* vim: set syntax=c: */
