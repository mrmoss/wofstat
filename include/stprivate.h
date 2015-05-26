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

/* $Id: stprivate.h,v 1.2 2004/05/30 23:07:17 adg Exp $ */

/**
 * @file stprivate.h
 * @brief STSF private interfaces
 * @author Alexander Gelfenbain <adg@sun.com>
 * @version 0.11
 */

#ifndef __STPRIVATE_H
#define __STPRIVATE_H

/*
 * STSF Configuration Parameters and their default values.
 *
 */

/*
 * GM_NBUCKETS                31991     STGlyphVector.c
 * Number of buckets in the client-side glyph vector metrics hash table.
 * It should be a prime number
 *
 * RM_NBUCKETS                3911      STGlyphVector.c
 * Number of buckets in the client-side glyph vector rendering properties hash table.
 * It should be a prime number
 *
 * DEFAULT_FONT_SIZE          N/A       STGlyphVector.c
 * Default font size if none is specified in STStyle object
 *
 * BITMAP_BUFFER_SIZE         N/A       STGlyphVector.c (ST Client Library buffer)
 *                                      stfs.c (font server buffer)
 * Size of the buffer to rasterize glyphs into
 *
 * FI_CACHE_COUNT             N/A       fontmanager.c
 * Number of cached font instances. Font instances are cached after they are deallocted
 * (the user calls FontManagerDisposeFontInstance() but they are kept in the cache.
 * As soon as the number of deallocated font instances reaches FI_CACHE_COUNT,
 * they are removed from the cache.
 *
 * FPE_NDIRSLOTS_INIT         N/A        fontprobe.c fontenumerator.c
 * FPE_NDIRSLOTS_INCR         N/A        fontprobe.c fontenumerator.c    
 *
 * VFSORT_INIT                N/A       fontenumerator.c
 * Initial number of slots in the VirtualFontSorter structure.
 *
 * VFSORT_INCR                N/A       fontenumerator.c
 * Number of additional slots added to the VirtualFontSorter in case of the overflow
 *
 *
 * FENUM_FINITA (double >= 0)           0.5       fontenumerator.c
 * FENUM_FINITB (int >= 0)              0         fontenumeraror.c
 * Control the number of allocated elements of fontarray and fontIDArray
 *      n = (FENUM_INITA + 1) * <Number of found fonts> + FENUM_INITB
 * Setting both constants to 0 causes fontenumerator not to allocate any additional entries
 * 
 * FENUM_BINITA  (double >= 0)           0.2       fontenumerator.c 
 * FENUM_BINITB  (int >= 0)              10       fontenumeraror.c 
 * Controls the number of allocated elements of bfontarray
 *
 *
 * FENUM_FINCRA (double >= 0)            0.0            fontenumerator.c
 * FENUM_FINCRB int >= 0                 200            fontenumerator.c
 *
 * Control allocatation of additional entries in the fontarray when the array needs to grow
 *      n = (FENUM_FINCRA + 1) * <delta> + FENUM_FINCRB;
 *
 *
 * FENUM_BINCRA (double >= 0)            0.0            fontenumerator.c
 * FENUM_BINCRB int >= 0                 200            fontenumerator.c
 *
 * Control allocatation of additional entries in the bfontarray when the array needs to grow
 *      n = (FENUM_FINCRA + 1) * <delta> + FENUM_FINCRB;
 *
 * FENUM_NFONTPATH_INCR                                  fontenumerator.c
 * Number of elements that fontpath array grows by
 *
 * TEMP_PATTERN                         "XXXXXX"                fontserver.c
 * Temporary font file name pattern
 *
 * STSF_TEMPDIR                         "/var/tmp/stsf"         stsf-door.c
 * Root directory for STSF temporary files 
 *
 * PROTO_BUFSIZE                        N/A                     stfs.c
 * size of a per-connection protocol receive buffer
 *
 * PROTO_MAXBUFSIZE                     N/A                     stfs.c
 * maximal size of a per-connection protocol receive buffer
 *
 * NCID                                 N/A                     stfs.c
 * maximal number of unique CIDs for session fonts per client connection
 *
 * AMOUNT_TO_CHECKSUM                                           type1probe.c, truetypeprobe.c
 * An argument to GetChecksum() function that determines how many initial bytes
 * of the file participate in md5 calculation. The value of "0" means that the
 * entire file needs to be included in md5 calculation
 *
 * NOTE: pcfprobe.c does not use this knob
 *
 * SHMEM_DIR                            N/A                     handler.c
 * SHMEM_PATTERN                        N/A                     handler.c
 * 
 * Directory and temprorary file pattern for per-client shared-memory files.
 *
 * SHMEM_SIZE                           N/A                     stfs-door.c
 * Amount of per-client shared memory, maximal amount: (uint32_t) -1
 *
 * SHMEM_PROTO                          N/A                     stfs-door.c
 * Size of the client/server communication protocol buffer, < SHMEM_SIZE
 *
 * STFS_UID                             N/A                     stfs-door.c
 * STFS_GID
 * Effective UID and GID of the stfontserverd process
 *
 * NCLIENTS_INIT                        N/A                     fontserver.c
 * Initial size of the dictionary that stores per-client data in the font
 * server. The dictionary will grow when needed, so this number should be set
 * to a typical number of client processes
 *
 * RESCAN_DELAY                         N/A                     fontenumerator.c
 * SAVE_DELAY                           N/A                     fontenumerator.c
 * Delay in seconds between incremental font update and persistent font cache
 * save operations. This will prevent DOS attacks.
 * 
 * 
 *
 */

#define GM_NBUCKETS 13
#define RM_NBUCKETS 13
#define DEFAULT_FONT_SIZE 12.0
#define BITMAP_BUFFER_SIZE 131072
#define FI_CACHE_COUNT 4000
#define VFSORT_INIT 100
#define VFSORT_INCR 100

/* #define FENUM_FINITA 0.5     */
/* #define FENUM_FINITB 0       */
/* #define FENUM_BINITA 0.2     */
/* #define FENUM_BINITB 10      */

/* #define FENUM_FINCRA    0.0  */
/* #define FENUM_FINCRB    200  */
/* #define FENUM_BINCRA    0.0  */
/* #define FENUM_BINCRB    200  */
/* #define MAX_URL_COUNT 50     */
/* #define TEMP_PATTERN    "XXXXXX" */

#define FENUM_NFONTPATH_INCR 20

#define FPE_NDIRSLOTS_INIT 128
#define FPE_NDIRSLOTS_INCR 128
 
#ifdef SOLARIS_DOORS
#define TEMP_DOOR_PATTERN   "XXXXXX"
#endif


#define STSF_TEMPDIR            "/var/tmp/stsf"

#define STSF_TEMPFONTDIR        STSF_TEMPDIR "/fonts"
#define PFC_FILENAME            STSF_TEMPDIR "/stsf.pfc"        

#define PROTO_BUFSIZE           65536
#define PROTO_MAXBUFSIZE        65536 * 4
#define NCID                    64
 
#define STFS_DOOR               "/var/run/stsf_door"

#define SHMEM_PATTERN           "XXXXXX"
#define SHMEM_SIZE              1024*1024                        /* 1M per client */
#define SHMEM_PROTO             128*1024                         /* 128K per client */

/* small shared cache for testing */
/* #define SHMEM_SIZE              10000 */

#define STFS_UID    1           /* Solaris daemon */
#define STFS_GID    12          /* Solaris daemon */


#if 1
#define AMOUNT_TO_CHECKSUM 1024
#else 
#define AMOUNT_TO_CHECKSUM 0       /* Full file - slow! */
#endif

#define NCLIENTS_INIT 20

#define SAVE_DELAY  30              /* XXX bump up in production versions to 5 minutes */
#define RESCAN_DELAY 30


/* Default colors */

#define ST_DEFAULT_COLOR_TEXT         0x00000000
#define ST_DEFAULT_COLOR_HLTEXT       0x00000000
#define ST_DEFAULT_COLOR_HLBG         0x00C0C0C0
#define ST_DEFAULT_COLOR_ST           0x0000FF00
#define ST_DEFAULT_COLOR_HLST         0x0000C000
#define ST_DEFAULT_COLOR_UL1          0x00FF0000
#define ST_DEFAULT_COLOR_HLUL1        0x00C00000
#define ST_DEFAULT_COLOR_UL2          0x000000FF
#define ST_DEFAULT_COLOR_HLUL2        0x000000C0

/* Number of baselines to allocate internally */
#define ST_BASELINE_COUNT ST_BASELINE_LAST + 1

/* One undocumented value of a STStyleMask */
#define ST_SM_FEATURE                   (1 << 4)        /**< Change or changed Feature list */


/* Default attributes of a new STText object */
#define ST_DEFAULT_TEXT_DIRECTION       ST_DIRECTION_LTR
#define ST_DEFAULT_TEXT_WIDTH           0.0
#define ST_DEFAULT_TEXT_ASCENT          0.0
#define ST_DEFAULT_TEXT_DESCENT         0.0
#define ST_DEFAULT_TEXT_LEADING         0.0
#define ST_DEFAULT_TEXT_FALLBACKPOLICY  ST_FB_SEARCHALL
#define ST_DEFAULT_TEXT_LANGUAGE        ST_LANGUAGE_DEFAULT
#define ST_DEFAULT_TEXT_FLUSHFACTOR     0.0
#define ST_DEFAULT_TEXT_JUSTIFICATION   0.0

#define FSLOADER_LOADED 0x53544F4B          /* STOK: stfontserverd was loaded by the watchdog */
#define FSLOADER_ALREADY 0x53545346         /* STSF: stfontserverd has been previously loaded */
#define FSLOADER_NOSERVER 0x4E4F5354        /* NOST: error starting stfontserverd */
#define FSLOADER_FAILED 0x4E4F5355          /* timeout waiting for the server to open the door */



/*
 *   SHARED MEMORY LAYOUT
 *
 *      +0      8   uint64_t        Client ID
 *      +8      4   uint32_t        Total length of the shared memory
 *      +12     4   uint32_t        Offset to the glyph bitmap area
 *      +16     4   uint32_t        Glyph bitmap area size
 *
 *
 *
 *
 */
#if 0
#define SM_CID               0
#define SM_SIZE              8
#define SM_BITMAPS_OFFS      12
#define SM_BITMAPS_SIZE      16
#endif

#if 0
/* #define DOUBLE_XY_TO_FRACDELTA(x, y) ((byte) (64 * ((x) - floor(x))) | ((byte) (64 * ((y) - floor(y))) << 8)) */
#else
#define DOUBLE_XY_TO_FRACDELTA(x, y) 0
#endif

typedef struct {
    uint64_t cid;           
    uint32_t size;
    uint32_t sc_offset;
    uint32_t sc_size;
    uint32_t proto_offset;
    uint32_t proto_size;
} SharedMemoryHeader;




typedef struct {
    F16Dot16 xx;    /**< transformation matrix value */
    F16Dot16 xy;    /**< transformation matrix value */
    F16Dot16 yx;    /**< transformation matrix value */
    F16Dot16 yy;    /**< transformation matrix value */
} TMatrix;



typedef TMatrix *TMatrixPtr;            /**< Pointer to TMatrix structure */

/**
 * 16.16 transformation matrix with tx, ty 
 */
typedef struct {
    F16Dot16 xx;			/**< transformation matrix value */
    F16Dot16 xy;			/**< transformation matrix value */
    F16Dot16 yx;			/**< transformation matrix value */
    F16Dot16 yy;			/**< transformation matrix value */
    F16Dot16 tx;			/**< transformation matrix value for x translation */
    F16Dot16 ty;			/**< transformation matrix value for y translation */
} FMatrix;

typedef FMatrix *FMatrixPtr;            /**< Pointer to FMatrix structure */


/**
 * 16.16 point  
 */
typedef struct {
    F16Dot16 x;                         /**< Coordinate value */
    F16Dot16 y;                         /**< Coordinate value */
} TPoint;

/*@}*/

typedef TPoint *TPointPtr;              /**< Pointer to TPoint structure */


/**
 * This bitmask is used to specify which locations to search for fonts. Use the following
 * functions to set this value:
 *    STTypeEnvSetLocations
 *
 * The bitmask is returned to indicate which locations are presently being searched by the
 * following functions:
 *    STTypeEnvGetLocations
 */
typedef uint32_t STFontLocationsMask;
#define ST_FL_SYSTEM                    1                   /**< Search the system-specific place (/usr/X11/lib/fonts) */
#define ST_FL_LOCAL                     (1 << 1)            /**< Search the local folder like (/usr/local/lib/fonts) */
#define ST_FL_USER                      (1 << 2)            /**< Search the user folder (~/.fonts) */



typedef struct {
    uint16_t platformID;        /**< TrueType platform ID. See TT_PLATFORM_ */
    uint16_t encodingID;        /**< TrueType encoding ID. See TT_ENCODING_ */
    uint16_t languageID;        /**< TrueType language ID. See TT_LANGUAGE_ */
    uint16_t nameID;            /**< TrueType name ID. See TT_NAME_ */
} STNameTag;




typedef STNameTag *STNameTagPtr;                  /**< Pointer to STNameTag structure */
 
/**
 * Expanded STNameTag which includes the string along with the tag desciptor
 */
typedef struct {
    uint16_t platformID;                  /**< Platform ID                                     */
    uint16_t encodingID;                  /**< Platform-specific encoding ID                   */
    uint16_t languageID;                  /**< Language ID                                     */
    uint16_t nameID;                      /**< Name ID                                         */
    uint16_t slen;                        /**< String length in bytes                          */
    byte  *sptr;                        /**< Pointer to string data (not zero-terminated!)   */
} NameRecord; 

/** Font features. Values are specified in FontFeatureTags enum */
typedef uint32_t STFontFeatureTag;


typedef struct {
    F16Dot16 xAdvH;         /**< X Advance vector for horizontal writing mode */
    F16Dot16 yAdvH;         /**< Y Advance vector for horizontal writing mode */
    F16Dot16 xAdvV;         /**< X Advance vector for vertical writing mode */
    F16Dot16 yAdvV;         /**< Y Advance vector for vertical writing mode */
    F16Dot16 topH;          /**< top Vector from glyph origin to top-left corner in horisontal mode */
    F16Dot16 leftH;         /**< left Vector from glyph origin to top-left corner in horisontal mode */
    F16Dot16 topV;          /**< top Vector from glyph origin to top-left corner in vertical mode */
    F16Dot16 leftV;         /**< left Vector from glyph origin to top-left corner in vertical mode */
} STGlyphMetrics;




typedef struct {
    int16_t xMin;
    int16_t yMin;
    int16_t xMax;
    int16_t yMax;
} FUnitBBox;




typedef struct {
    int16_t xMin;
    int16_t yMin;
    int16_t xMax;
    int16_t yMax;
    uint16_t aw;            /**< Advance width in horizontal writing mode */
    int16_t lsb;            /**< Left sidebearing in horizontal writing mode */
    uint16_t ah;            /**< Advance height in vertical writing mode */
    int16_t tsb;            /**< sidebearing in vertical writing mode */
} FUnitGlyphMetrics;




typedef struct {
    uint32_t scalerID;
    uint32_t instanceID;
    uint32_t glyphID;
    uint16_t fracdelta;
} STGlyphKey;




typedef struct {
    double xh;    /**< X Kerning vector for horizontal writing mode */
    double yh;    /**< Y Kerning vector for horizontal writing mode */
    double xv;    /**< X Kerning vector for vertical writing mode */
    double yv;    /**< Y Kerning vector for vertical writing mode */
} STKernData;



/**
 * A Bezier curve
 */
typedef struct {
    double ax;                        
    double ay;                        
    double bx;                        
    double by;                        
    double cx;                        
    double cy;                        
    double dx;                        
    double dy;                        
} STBezierCurve;

/**
 * A B-spline
 */
typedef struct {
    double ax;                        
    double ay;                        
    double bx;                        
    double by;                        
    double cx;                        
    double cy;                        
} STBSpline;

/**
 * A line
 */
typedef struct {
    double x0;                        /**< X Coordinate value start point of the line */
    double y0;                        /**< Y Coordinate value start point of the line */
    double x1;                        /**< X Coordinate value end point of the line */
    double y1;                        /**< Y Coordinate value end point of the line */
} STLineSeg;

/**
 * Type of path element for vector font output
 */
typedef enum {
    fBezierCurve,                     /**< path element is a bezier curve */
    fBSpline,                         /**< path element is a BSpline curve */
    fLineSeg                          /**< path element is a line segment */
} STPathElement;

/**
 * A path
 */
typedef struct {
    int count;                        /**< Number of elements in path */
    STPathElement *type;              /**< Array of element types in path */
    void *element;                    /**< ??? */
} STPath;   


/**
 * STScaledMaxBox
 */

typedef struct {
    int32_t width;  
    int32_t height;
    F16Dot16 xAdvH; 
    F16Dot16 yAdvH; 
    F16Dot16 xAdvV;    
    F16Dot16 yAdvV;    
    F16Dot16 topH;    
    F16Dot16 leftH;   
    F16Dot16 topV;    
    F16Dot16 leftV;   
} STScaledMaxBox;


typedef STLookupTable *STLookupTablePtr;  /**< Pointer to STLookupTable structure */

/**
 * Outline callback function
 *
 * @param dev			the "this" pointer
 * @param path			an outline path in device space
 */
typedef void (*CopyOutlineF)(struct STVectorDeviceStruct *dev, 
                             STPath path);              


/**
 * STVectorDevice is a class that specifies vector devices.
 */
struct STVectorDeviceStruct {
    STDeviceType devType;               /**< fVectorDevice */
    STMatrix  matrix;                   /**< transformation matrix associated with device */
    
    uint16_t ppix;                        /**< Horisontal resolution for hinted outlines */
    uint16_t ppiy;                        /**< Vertical resolution for hinted outlines */
    
    void *p;                            /**< private data */

    CopyOutlineF copyoutl;              /**< vector function */
};

typedef struct STVectorDeviceStruct *STVectorDevice; /**< Pointer to STVectorDeviceStruct */


/* Font Server data types */
typedef uint32_t FSRenderFlags;
typedef STRenderingMode FSRenderingMode;

#define FS_RF_SBITS            0x00000001               /* Turn sbit support on */
#define FS_RF_HINTS            0x00000002               /* Turn native hints on */
#define FS_RF_AUTOHINT         0x00000004               /* Turn auto-hinting on, incompatible with FS_ENABLE_HINTS */
#define FS_RF_BLACKANDWHITE    0x00000008               /* 1 bit black and white mode */
#define FS_RF_GRAYSCALE        0x00000010               /* Turn grey-scale mode on */
#define FS_RF_LCD              0x00000020               /* Turn LCD optimization on */
#define FS_RF_EMBOLDEN         0x00000040               /* Algorithmically embolden the font */
#define FS_RF_ITALICISE        0x00000080               /* Algorithmically italicize the font */
#define FS_RF_FRACDELTAS       0x00000100               /* Fractonal deltas for glyph rendering */
#define FS_RF_BITSWAPPED       0x00000200               /* Bit-swap all bytes in the bitmap */
#define FS_RF_EMBOLDENBITMAPS  0x00000400               /* Embolden glyph bitmaps instead of outlines */
#define FS_RF_VERTICAL         0x00010000               /* Vertical writing mode */
#define FS_RF_GREYSCALE FS_RF_GRAYSCALE

typedef enum {
    fHorisontalMetrics = 1,                       /* Horisontal metrics is valid */
    fVerticalMetrics = 2,                         /* Vertical metrics is valid */
    fSubstitutedBitmap = 4                        /* The scaler substituted a bitmap */
} ScaledGlyphFlags;



typedef struct {
    ScaledGlyphFlags flags;
    int32_t width;          /* width of the character in pixels */
    int32_t height;         /* height of the character in pixels */
    int32_t bytesPerRow;    /* number of bytes per one scan line */
    F16Dot16 xAdvH;         /* Advance vector for horisontal writing mode */
    F16Dot16 yAdvH;         /* Advance vector for horisontal writing mode */
    F16Dot16 xAdvV;         /* Advance vector for vertical writing mode */
    F16Dot16 yAdvV;         /* Advance vector for vertical writing mode */
    F16Dot16 topH;          /* Vector from glyph origin to top-left corner in horisontal mode */
    F16Dot16 leftH;         /* Vector from glyph origin to top-left corner in horisontal mode */
    F16Dot16 topV;          /* Vector from glyph origin to top-left corner in vertical mode */
    F16Dot16 leftV;         /* Vector from glyph origin to top-left corner in vertical mode */
} ScaledGlyphData;




typedef struct {
    double xMin;            /* global bounding box: xMin */
    double yMin;            /* global bounding box: yMin */
    double xMax;            /* global bounding box: xMax */
    double yMax;            /* global bounding box: yMax */
    double hlinegap;
    double hascent;
    double hdescent;
} ScaledFontMetrics;



/**
 * Finds a font by its name. If the font name (iName) is NULL, it
 * returns the first available font. iNameID parameter indicates the
 * name ID of the name, as defined in TrueType/OpenType specs.
 * A special value of iNameID (ST_NAME_ANY) indicates that ST will search
 * for the specified font name among all names. Standard name ID
 * values are defined in sttags.h header file.
 *
 * @param iEnv                type environment object
 * @param iName               a UTF-16 string that specifies the name
 * @param iNameLength         number of UTF-16 characters in the iName string
 * @param iNameID             meaning of the name
 * @param oFont               a pointer to STFont variable where on
 *                            return the resulting font ID is stored
 *
 * @return status
 */
STStatus STTypeEnvFindFont(STTypeEnv iEnv,
                           const utf16 *iName,
                           STCharCount iNameLength,
                           uint16_t iNameID,
                           STFont *oFont);

/**
 * Finds all fonts by their Unicode name and returns an array of font IDs.
 * See STTypeEnvFindFont() for more information.
 * 
 *
 * @param iEnv                type environment object
 * @param iName               a UTF-16 string that specifies the name
 * @param iNameLength         number of UTF-16 characters in the iName string 
 * @param iNameID             meaning of the name
 * @param oFontCount          a pointer to a variable where on return
 *                            the number of returned fontIDs is stored
 * @param oFont               a pointer to an array of STFont variables where
 *                            the resulting font IDs are stored on return.
 *                            If this pointer is NULL the function just counts
 *                            all fonts with the name iName.
 *                            The array is allocated inside this function,
 *                            and the caller is responsible for freeing up
 *                            the memory.
 *                            
 *
 * @return status
 */
STStatus STTypeEnvFindAllFonts(STTypeEnv iEnv,
                               const utf16 *iName,
                               STCharCount iNameLength,
                               uint16_t iNameID,
                               STCount *oFontCount,
                               STFont **oFont);

/**
 * Finds a font by its platform-specific name and returns the font ID.
 * Platform-specific names are defined in TrueType/OpenType specs.
 * STSF synthesizes TrueType-compliant names for non-TrueType fonts.
 * iPlatformID, iEncodingID, iLanguageID, and iNameID have special
 * values of ST_PLATFORM_ANY, ST_ENCODING_ANY, ST_LANGUAGE_ANY, and ST_NAME_ANY
 * that indicate that their values do not matter. If the font name
 * is NULL, the first font that satisfies the search criterion
 * is returned.
 *
 * @param iEnv                type environment object
 * @param iName               a string that specifies the name
 * @param iNameLength         number of bytes in the name
 * @param iPlatformID         platform ID
 * @param iEncodingID         platform-specific encoding ID
 * @param iLanguageID         language ID
 * @param iNameID             meaning of the name
 * @param oFont               a pointer to STFont variable where on
 *                            return the resulting font ID is stored
 *
 * @return status
 */
STStatus STTypeEnvFindFontByPlatformName(STTypeEnv iEnv,
                                         const byte *iName,
                                         int iNameLength,
                                         uint16_t iPlatformID,
                                         uint16_t iEncodingID,
                                         uint16_t iLanguageID,
                                         uint16_t iNameID,
                                         STFont *oFont);

/**
 * Finds all fonts by their Platform name and returns an array of font IDs.
 * See STTypeEnvFindFontByPlatformName() for more information.
 *
 *
 * @param iEnv                type environment object
 * @param iName               a string that specifies the name
 * @param iNameLength         number of bytes in the name
 * @param iPlatformID         platform ID
 * @param iEncodingID         platform-specific encoding ID
 * @param iLanguageID         language ID
 * @param iNameID             meaning of the name
 * @param oFontCount          a pointer to a variable where on return
 *                            the number of returned fontIDs is stored
 * @param oFont               a pointer to an array of STFont variables where
 *                            the resulting font IDs are stored on return.
 *                            If this pointer is NULL the function just counts
 *                            all fonts with the name iName.
 *                            The array is allocated inside this function,
 *                            and the caller is responsible for freeing up
 *                            the memory.
 *                            
 *
 * @return status
 */
STStatus STTypeEnvFindAllFontsByPlatformName(STTypeEnv iEnv,
                                             const byte *iName,
                                             int iNameLength,
                                             uint16_t iPlatformID,
                                             uint16_t iEncodingID,
                                             uint16_t iLanguageID,
                                             uint16_t iNameID,
                                             STCount *oFontCount,
                                             STFont **oFont);



STStatus STTypeEnvFindFontsByURL(STTypeEnv iEnv,
                                 const char *iURL,
                                 STCount *oFontCount,
                                 STFont **oFont);

/**
 * Finds the font by its cryptographically-secure signature
 *
 *
 * @param iEnv                type environment object
 * @param iSignature          pointer to a buffer that contains the signature
 * @param oFont               the font ID is stored there
 */
STStatus STTypeEnvFindFontBySignature(STTypeEnv iEnv,
                                      const byte *iSignature,
                                      STFont *oFont);
    
/**
 * Creates an STSF font from several data streams.
 *
 * @param iEnv                type environment object
 * @param iDataCount          number of data streams
 * @param iData               array of iDataCount pointers to data
 * @param iDataLength         array of data region lengths
 * @param oFontCount          number of created fonts
 * @param oFont               array of allocated font IDs
 *
 * @return STStatus
 */
STStatus STTypeEnvCreateFonts(STTypeEnv iEnv,
                              STCount iDataCount,
                              byte **iData,
                              size_t *iDataLength,
                              STCount *oFontCount,
                              STFont **oFont);
/**
 * Disposes of a font previously created with STCreateFont().
 * This function will return an error code if attempt is made
 * to destroy a font that was not previously created with STCreateFont()
 * All fonts that have not been explicitly destroyed will be destroyed
 * when the Type Environment object from which they were created
 * is destroyed.
 *
 * @param iEnv                type environment object
 * @param iFont               font ID of a previously created font.
 *
 * @return STStatus
 */
STStatus STTypeEnvDestroyFonts(STTypeEnv iEnv,
                               STCount iFontCount,
                               STFont *iFont);

STStatus STTypeEnvCreateFontsFromURL(STTypeEnv iEnv,
                                     STCount iURLCount,
                                     char **iURL,
                                     STCount *oFontCount,
                                     STFont **oFont);

/**
 * Specfies which pre-defined locations STSF should scan for fonts.
 *
 * @param iEnv                type environment object
 * @param iMask               one or more flags ORed together
 *
 * @return STStatus
 */
STStatus STTypeEnvSetLocations(STTypeEnv iEnv,
                               STFontLocationsMask iMask);

/**
 * Returns the previously set font locations mask.
 *
 * @param iEnv                type environment object
 * @param oMask               one or more flags ORed together
 *
 * @return STStatus
 */
STStatus STTypeEnvGetLocations(STTypeEnv iEnv,
                               STFontLocationsMask *oMask);



/**
 * Extracts all name string tags from the font.
 *
 * @param iEnv                type environment object
 * @param iFont               font ID
 * @param oNameCount          number of retrieved string tags is stored here
 * @param oNameStrings        pointer to an array of STNameStringTag structures
 *                            allocated by this function.
 *
 * @return STStatus
 */
STStatus STFontGetNameTags(STTypeEnv iEnv,
                           STFont iFont,
                           STCount *oNameCount,
                           STNameTagPtr *oNameTags);

/**
 * Extracts a string specified by the string tag from the font.
 *
 * @param iEnv                type environment object
 * @param iFont               font ID
 * @param iNameTag            NameTag that specifies the string
 * @param oStringLength       address of a variable where the length of the
 *			      resulting string in bytes is stored
 * @param oStringData         address of a pointer that on return will point
 *			      to memory allocated by this function that holds
 *			      name string data.
 */
STStatus STFontGetNameString(STTypeEnv iEnv,
                             STFont iFont,
                             STNameTagPtr iNameTag,
                             int *oStringLength,
                             byte **oStringData);

/**
 * Retrieves offsets of all baselines defined in the font from the Roman 
 * baseline. First (lastBaseline + 1) baselines are predefined.
 *
 * @param iEnv                type environment object
 * @param iFont               a font ID
 * @param oBaselines          pointer to an array where on return the
 *			      baselines are stored
 *
 * @return STStatus
 */
STStatus STFontGetBaselines(STTypeEnv iEnv,
                            STFont iFont,
                            STBaselineMask *oBaselineMask,
                            STBaseline **oBaselines);

/**
 * Retrieves all font features from the font. ST supports both AAT style
 * font features and OpenType font features. ST font features are "feature
 * selectors" in AAT terminology, AAT font features do not have
 * any predefined tags by themselves.
 *
 * @param iEnv                type environment object
 * @param iFont               a font ID
 * @param oFeatureCount       the number of features is stored here.
 * @param oFeatureArray       an array feature tags is stored here. Memory
 *                            is allocated by this function and the caller
 *                            is responsible for freeing it.
 *
 * @return STStatus
 */

STStatus STFontGetFeatures(STTypeEnv iEnv,
                           STFont iFont,
                           STCount *oFeatureCount,
                           STFontFeatureTag **oFeatureArray);

/**
 * Counts all glyphs in the font. Available glyph IDs are in the
 * range 0..oGlyphCount.
 *
 * @param iEnv                type environment object
 * @param iFont               a font ID
 * @param oGlyphCount         number of glyphs in the font
 *
 * @return STStatus
 */

STStatus STFontCountGlyphs(STTypeEnv iEnv,
                           STFont iFont,
                           STCount *oGlyphCount);


/**
 * Calculates a cryptographically-secure font signature and
 * copies it to an allocated buffer pointed
 *
 * @param iEnv                type environment object
 * @param iFont               a font ID
 * @param oSignature          a pointer to the allocated signature buffer
 *                            is stored there
 */
STStatus STFontGetSignature(STTypeEnv iEnv,
                            STFont iFont,
                            byte **oSignature);

/**
 * Serializes a Style object to an XML stream. Used mainly for debugging.
 *
 * @param iStyle              a Style object
 * @param iFileDes            a file descriptor of an output file
 *
 * @return STStatus
 */
STStatus STStyleSerialize(STStyle iStyle,
                          int iFileDes);

/**
 * Reads in an XML stream and deserializes a Style object from it.
 *
 * @param oStyle              pointer to a created STStyle object
 *                            is stored there.
 * @param iFileDes            an file descriptor of an input file
 *
 * @return STStatus
 */
STStatus STStyleDeserialize(STStyle *oStyle,
                            int iFileDes);

/**
 * Sets the layout engine for the style.
 *
 * @param iStyle              the style object
 * @param iMask               bitmask iwth ST_SM_LAYOUTENGINE bit set
 * @param iLayoutEngine       layout engine ID
 *
 * @return STStatus
 */

STStatus STStyleSetLayoutEngine(STStyle iStyle,
                                STStyleMask iMask,
                                STLayoutEngine iLayoutEngine);

/**
 * Retrieves the layout engine of the style.
 *
 * @param iStyle              the style object
 * @param oMask               bitmask that indicates whether the layout engine was set
 *                            for this style previously
 * @param oLayoutEngine       layout engine ID
 */
STStatus STStyleGetLayoutEngine(STStyle iStyle,
                                STStyleMask *oMask,
                                STLayoutEngine *oLayoutEngine);

/**
 * Writes an XML representation of the STText object environment to
 * the output stream.
 *
 * @param iText               STText object
 * @param iFileDes            file descriptor of an open file
 *
 * @return STStatus
 */
STStatus STTextSerialize(STText iText,
                         int iFileDes);

/**
 * Reads a previously serialized STText object
 * from an input stream and creates a new STText object
 *
 * @param oText               new STText object 
 * @param iFileDes            file descriptor of an open file
 *
 * @return STStatus
 */
STStatus STTextDeserialize(STText *oText,
                           int iFileDes);



/**
 * Writes an XML representation of the STLine object environment to
 * the output stream.
 *
 * @param iLine               STLine object
 * @param iFileDes            file descriptor of an open file
 *
 * @return STStatus
 */
STStatus STLineSerialize(STLine iLine,
                         int iFileDes);

/**
 * Reads a previously serialized STLine object
 * from an input stream and creates a new STLine object
 *
 * @param oLine               new STLine object
 * @param iFileDes            file descriptor of an open file
 *
 * @return STStatus
 */
STStatus STLineDeserialize(STLine *Line,
                           int iFileDes);

/**
 * Writes an XML representation of a glyph vector to a file stream.
 *
 * @param iGlyphVector        a glyph vector
 * @param iFileDes            a file descriptor open for writing
 *
 * @return STStatus
 */
STStatus STGlyphVectorSerialize(STGlyphVector iGlyphVector,
                                int iFileDes);

/**
 * Constructs a glyph vector from its serialized representation.
 *
 * @param oGlyphVector        on return a newly allocated glyph vector is stored there
 * @param iFileDes            a file descriptor open for reading
 *
 * @return STStatus
 */
STStatus STGlyphVectorDeserialize(STGlyphVector *oGlyphVector,
                                  int iFileDes);

typedef struct {
    STTag       tableTag;       /**< sfnt tag */
    size_t      size;           /**< table size in bytes */
    off_t       offset;         /**< offset within the original file. The value of -1 indicates
                                     that this table is auto-synthesized */
} STTableDescriptor;
        

STStatus STFontGetTables(STTypeEnv iEnv,
                         STFont iFont,
                         STCount *oTableCount,
                         STTableDescriptor **oTables);
                         
/**
 * Removes characters from the beginning or from the end of the line.
 *
 * @param iLine               STLine object
 * @param iFromEnd            true if characters are removed from line end,
 *				false if from line start
 * @param iCharCount          specifies the number of removed characters
 *
 * @return STStatus
 */
STStatus STLineShrink(STLine iLine,
                      STBoolean iFromEnd,
                      STCharCount iCharCount);


/**
 * Get a single color (XST uses it now that STGraphics is opaque.
 * iWhichColor should contain only a single bit set, otherwise
 * this function is going to return an ST_BAD_COLORMASK error.
 */
STStatus STGraphicsGetColor(STGraphics iGraphics,
                            STGraphicsColorMask iWhichColor,
                            STRGBAColor *oColor);



/**
 * Returns the current transformation matrix of an STDevice object.
 *
 * @param iDevice             STDevice object
 * @param oMatrix             transformation matrix is stored there
 *
 * @return STStatus
 */
STStatus STDeviceGetMatrix(STDevice iDevice,
                           STMatrix *oMatrix);
/**
 * Replaces the current transformation matrix with a new one.
 *
 * @param iDevice             STDevice object
 * @param iMatrix             new transformation matrix
 *
 * @return STStatus
 */
STStatus STDeviceSetMatrix(STDevice iDevice,
                           STMatrix iMatrix);

/**
 * Concatenates the current transformation matrix with the new one.
 *
 * @param iDevice             STDevice object
 * @param iMatrix             transformation matrix
 *
 * @return STStatus
 */
STStatus STDeviceConcatMatrix(STDevice iDevice,
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
STStatus STDeviceTranslate(STDevice iDevice,
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
STStatus STDeviceScale(STDevice iDevice,
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
STStatus STDeviceRotate(STDevice iDevice,
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
STStatus STDeviceShear(STDevice iDevice,
                       double shx,
                       double shy);


/**
 * Get and set STSF system configuration parameters 
 *
 */
STStatus STSysCtlByName(const char *name, 
                        void *oldp, 
                        size_t *oldlenp, 
                        void *newp, 
                        size_t newlen);


/**
 * This function examines the internal ST Client Library glyph cache
 * associated with the previously rendered glyph vector and returns 
 * either one of the two things
 *  
 *   - array of pointers to memory regions associated
 *     with individual rendered glyphs of a glyph vector
 *     (sharedcache.payloadsize property is not 0)
 *
 *   - array of integers that indicate whether the particular 
 *     glyph is still present in the cache and is available to the client 
 *     without performing an STSF Font Server protocol request
 *     (sharedcache.payloadsize property is 0)
 *
 * When a glyph vector is rendered, glyphs are cached for 
 * an unpredictable period of time by the ST Client Library.
 * While they are cached, an extra amount of memory may be associated
 * with a glyph to store any information the client application
 * might desire to store in there. This amount of memory is
 * constant for a ST session and it needs to be specified by 
 * setting the "sharedcache.payloadsize" property
 * with STSysCtlByName() prior to establishing an ST session
 * (creating a new Type Environment object).
 *
 *
 * @param iGlyphVector          a glyph vector
 * @param iStartFrom            first glyph in the range or ST_BEGINNING 
 * @param iGlyphCount           number of glyphs in the range or ST_ALL 
 * @param iGraphics             a graphics object -  a raster or an outline device
 * @param oPayloadPtr           an array of at least iGlyphCount pointers (void *)
 *                              allocated by the function caller where the return
 *                              values (pointers to payload data or integer flags)
 *                              will be stored. If the caller is not interested
 *                              in this information, NULL can be passed to this
 *                              function
 * @param oGlyphPtr             an array of at least iGlyphCount pointers (void *)
 *                              allocated by the function caller where pointers
 *                              to glyph-specific data stored in shared cache
 *                              is located. These pointers can be used to pair up glyph 
 *                              payload data with glyph data received by the device
 *                              callbacks
 * @param oGlyphCount           number of glyphs available in the ST Client Library
 *                              glyph cache (i.e. number of non-NULL pointers or 
 *                              "1" flags in oPayloadPtr[] )
 *
 * @return STStatus (ST_NULL_POINTER, ST_RANGE) 
 */
STStatus STGlyphVectorQuery(STGlyphVector iGlyphVector,
                            STPosition iStartFrom,
                            STCount iGlyphCount,
                            STGraphics iGraphics,
                            STMatrix *oMatrix,
                            STScaledMaxBox *oMaxBox,
                            void **oPayloadPtr,
                            void **oGlyphPtr,
                            STCount *oGlyphCount); 

/**
 * Retrieves an X and Y positions of a styled glyph in a glyph vector
 * and stores them in oPosition.
 *
 * @param iGlyphVector          a glyph vector
 * @param iGlyphIndex           index of a styled glyph
 * @param oPosition             X and Y coordinates will be stored in there
 *
 * @return STStstus (ST_NULL_POINTER, ST_RANGE)
 *
 */


STStatus STGlyphVectorGetGlyphPosition(STGlyphVector iGlyphVector,
                                       STPosition iGlyphIndex,
                                       STPoint *oPosition);



#endif /* __STPRIVATE_H */
/* vim: set syntax=c: */

