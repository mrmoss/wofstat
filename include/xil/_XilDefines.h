/*------------------------------------------------------------------------
*
*   File:     _XilDefines.h
*   Project:  XIL
*   Revision: 1.44
*   Last Mod: 10:21:24, 02/25/98
*
*   Description:
*
*     Definition of basic XIL defines and typedefs for both C and C++
*     programs.
*
*------------------------------------------------------------------------
*       COPYRIGHT
*-----------------------------------------------------------------------*/
#ifndef _XIL_DEFINES_H
#define _XIL_DEFINES_H

#include <limits.h>

/*
 *  XIL uses some definitions from Xlib.
 */

#ifdef _WINDOWS
#include <windows.h>
#include <float.h>
#else
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif

/*
 *  XIL data types
 */
typedef unsigned char       Xil_unsigned8;
typedef char                Xil_signed8;

typedef unsigned short      Xil_unsigned16;
typedef short               Xil_signed16;

typedef unsigned int        Xil_unsigned32;
typedef int                 Xil_signed32;

/*
 *  long long is not part of ANSI C.  If we're compiling with strict ANSI C
 *  compliance, then we must not use unsigned long long.
 */

#ifdef _WINDOWS
typedef _int64              XilLongLong;
typedef unsigned _int64     XilULongLong;
#elif ((__STDC__ - 0 == 0 || defined(IRIX)) || \
    (__GNUC__ >= 2 && defined(__USE_GNU))) \
    && !defined(_NO_LONGLONG)
typedef long long           XilLongLong;
typedef unsigned long long  XilULongLong;
#elif defined(_NO_LONGLONG)
typedef long                XilLongLong;
typedef unsigned long       XilULongLong;
#else
typedef long long           XilLongLong;
typedef unsigned long long  XilULongLong;
#endif /* _WINDOWS */

#if ((__STDC__ - 0 == 0 || defined(IRIX)) || \
    (__GNUC__ >= 2 && defined(__USE_GNU))) \
    && !defined(_NO_LONGLONG)
typedef XilLongLong         Xil_signed64;
typedef XilULongLong        Xil_unsigned64;
#endif /* __STDC__ - 0 == 0 && !defined(_NO_LONGLONG) */


typedef float               Xil_float32;
typedef double              Xil_float64;
typedef long double         Xil_float128;

/*
 *  Either TRUE or FALSE
 */
typedef int                 Xil_boolean;

/*
 *  XIL defines
 */

#ifndef NULL
#define NULL (void*)0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/*
 * NOTE: The following six symbolic name definitions used not to have the
 * prefix "XIL_". This caused serious problems on Win32 systems wherein the
 * definition of MINSHORT is defined as 0xffff which is -32768 in two's
 * complement (see WINNT.H). In some cases this definition superseded the
 * one in this file so that the value +32768 occurred where -32768 was
 * expected as a result of the WINNT.H definition not having included a
 * cast to unsigned short ("WORD"). To eliminate potential confusion with such
 * externally defined symbolic names, the prefix "XIL_" was added to all
 * occurrences of these definitions.
 */
#ifndef XIL_MAXBYTE
#define XIL_MAXBYTE     ((Xil_unsigned8)255)
#endif

#ifndef XIL_MINBYTE
#define XIL_MINBYTE     ((Xil_unsigned8)0)
#endif

#ifndef XIL_MAXSHORT
#define XIL_MAXSHORT	((Xil_signed16)32767)
#endif

#ifndef XIL_MINSHORT
#define XIL_MINSHORT	((Xil_signed16)-32768)
#endif

#ifndef XIL_MAXDOUBLE
#ifdef _WINDOWS
#define XIL_MAXDOUBLE	DBL_MAX
#else
/*
 * NOTE: On SunOS MAXDOUBLE this is defined in <values.h>.
 */
#define XIL_MAXDOUBLE   MAXDOUBLE
#endif /* _WINDOWS */
#endif /* !XIL_MAXDOUBLE */

#ifndef XIL_MAXFLOAT
#ifdef _WINDOWS
#define XIL_MAXFLOAT	FLT_MAX
#else
/*
 * NOTE: On SunOS MAXFLOAT is defined in <values.h> and <math.h>.
 */
#define XIL_MAXFLOAT	MAXFLOAT
#endif /* _WINDOWS */
#endif /* !XIL_MAXFLOAT */

/*
 * The following symbolic name definitions are for backward compatibility.
 * These definitions are not officially part of the XIL API but were available
 * to users via public header files and so could be in external use.
 */
#ifndef MAXBYTE
#define MAXBYTE		XIL_MAXBYTE
#endif

#ifndef MINBYTE
#define MINBYTE		XIL_MINBYTE
#endif

#ifndef MAXSHORT
#define MAXSHORT	XIL_MAXSHORT
#endif

#ifndef MINSHORT
#define MINSHORT	XIL_MINSHORT
#endif


/*
 *  XIL version number typedef.
 *
 *  These tests for long long availability have been borrowed from
 *  /usr/include/sys/types.h.  They should only be needed when the API is
 *  being compiled with a strict ANSI C compiler.
 *
 *  If long long is not available, then an unsigned long is used in
 *  its place.  We ensure that the functionality is maintained by
 *  swapping the 32-bit quantities so the least significant word of
 *  the 64-bit quantity is returned in the case of an application that
 *  has been built with the XilVersionNumber as an unsigned long
 *  instead of an unsigned long long.
 *
 *  For xil_lookup_get_version(), we only guarentee that the numbers are
 *  unique, not that they're meaningful.
 */
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
typedef XilULongLong            XilVersionNumber;
#else
typedef unsigned long           XilVersionNumber;
#endif  /* __STDC__ - 0 == 0 && !defined(_NO_LONGLONG) */


/*
 *  Success or failure return values
 */
typedef enum __XilStatus {
    XIL_SUCCESS, XIL_FAILURE = 2
} XilStatus;

/*
 *  The number of supported XIL datatypes
 */
#define XIL_DATATYPES   17

/*
 *  The supported data types
 */
typedef enum __XilDataType {
    XIL_BIT,
    XIL_BYTE,
    XIL_SHORT,
    XIL_FLOAT,
    XIL_UNSIGNED_4,
    XIL_SIGNED_8,
    XIL_UNSIGNED_16,
    XIL_SIGNED_32,
    XIL_UNSIGNED_32,
    XIL_SIGNED_64,
    XIL_UNSIGNED_64,
    XIL_FLOAT_64,
    XIL_FLOAT_128,
    XIL_COMPLEX_FLOAT_32,
    XIL_COMPLEX_FLOAT_64,
    XIL_COMPLEX_MAG_FLOAT_32,
    XIL_COMPLEX_MAG_FLOAT_64
} XilDataType;

/* 
 * Define equivalent types 
 */
#define XIL_UNSIGNED_8  XIL_BYTE
#define XIL_SIGNED_16   XIL_SHORT
#define XIL_FLOAT_32    XIL_FLOAT

/*
 *  Complex data structure
 */
typedef struct __XilComplexFloat32 {
    float   real;
    float   img;
} XilComplexFloat32;

typedef struct __XilComplexFloat64 {
    double  real;
    double  img;
} XilComplexFloat64;

typedef struct __XilComplexMagFloat32 {
    float   mag;
    float   phase;
} XilComplexMagFloat32;

typedef struct __XilComplexMagFloat64 {
    double  mag;
    double  phase;
} XilComplexMagFloat64;


/*
 * Used with the IO device attribute COLORMAP
 */
#ifdef _WINDOWS
typedef struct _WColor {
    Xil_unsigned32 palIndex;
    PALETTEENTRY   palEntry;
} WColor;

typedef struct __XilColorList {
    Xil_unsigned32 cmap;
    WColor*        colors;
    Xil_unsigned32 ncolors;
} XilColorList;
#else
typedef struct __XilColorList {
    Colormap       cmap;
    XColor*        colors;
    Xil_unsigned32 ncolors;
} XilColorList;
#endif /* _WINDOWS */

/*
 *  The alignment on bit images
 */
#define XIL_BIT_ALIGNMENT 8

/*
 *  Supported edge conditions
 */
typedef enum __XilEdgeCondition {
    XIL_EDGE_NO_WRITE,
    XIL_EDGE_ZERO_FILL,
    XIL_EDGE_EXTEND
} XilEdgeCondition;

/*
 *  Supported edge detection algorithms
 */
typedef enum __XilEdgeDetection {
    XIL_EDGE_DETECT_SOBEL
} XilEdgeDetection;

/*
 *  Supported transpose types
 */
typedef enum __XilFlipType {
    XIL_FLIP_X_AXIS,
    XIL_FLIP_Y_AXIS,
    XIL_FLIP_MAIN_DIAGONAL,
    XIL_FLIP_ANTIDIAGONAL,
    XIL_FLIP_90,
    XIL_FLIP_180,
    XIL_FLIP_270
} XilFlipType;

/*
 *  Object types
 */
typedef enum {
   XIL_IMAGE,
   XIL_IMAGE_TYPE,
   XIL_LOOKUP,
   XIL_CIS,
   XIL_DITHER_MASK,
   XIL_KERNEL,
   XIL_SEL,
   XIL_ROI,
   XIL_ROI_LIST,      /* OBSOLETE - not in XIL 1.3 GPI */
   XIL_HISTOGRAM,
   XIL_COLORSPACE,
   XIL_ATTRIBUTE,
   XIL_INTERPOLATION_TABLE,
   /*
    *  New objects for XIL 1.3
    */
   XIL_STORAGE,
   XIL_DEVICE,
   XIL_COLORSPACE_LIST
} XilObjectType;

/*
 *  The number of XIL objects in the enumeration
 */
#define XIL_NUM_OBJECT_TYPES    16

/*
 *  Storage types -- new for XIL 1.3
 */
typedef enum {
    XIL_STORAGE_TYPE_UNDEFINED,
    XIL_PIXEL_SEQUENTIAL,
    XIL_BAND_SEQUENTIAL,
    XIL_GENERAL
} XilStorageType;

/*
 *  Storage Movement Types -- new for XIL 1.3
 */
typedef enum {
    XIL_ALLOW_MOVE,
    XIL_KEEP_STATIONARY,
    XIL_REPLACE
} XilStorageMovement;

/*
 *  Tiling Modes -- new for XIL 1.3
 */
typedef enum {
    XIL_TILING,
    XIL_STRIPPING,
    XIL_WHOLE_IMAGE
} XilTilingMode;

/*
 *  Colorspace types -- new for XIL 1.3
 */
typedef enum {
    XIL_COLORSPACE_NAME,
    XIL_COLORSPACE_FILENAME,
    XIL_COLORSPACE_KCS_ID
} XilColorspaceType;
    
/*
 *  Active Buffer types -- new for XIL 1.3
 */
typedef enum {
    XIL_BACK_RIGHT_BUFFER  = -8,
    XIL_BACK_LEFT_BUFFER   = -7,
    XIL_FRONT_RIGHT_BUFFER = -6,
    XIL_FRONT_LEFT_BUFFER  = -5,
    XIL_RIGHT_BUFFER       = -4,
    XIL_LEFT_BUFFER        = -3,
    XIL_FRONT_BUFFER = -2,
    XIL_BACK_BUFFER  = -1
} XilBufferId;

/*
 * Special window capabilities -- new for XIL 1.4
 */
typedef enum {
    XIL_DOUBLE_BUFFER = 1,
    XIL_STEREO        = 2
} XilWindowCaps;

    
/*
 *  Error Category defines
 */
typedef enum XilErrorCategory {
    XIL_ERROR_SYSTEM,
    XIL_ERROR_RESOURCE,
    XIL_ERROR_ARITHMETIC,
    XIL_ERROR_CIS_DATA,
    XIL_ERROR_USER,
    XIL_ERROR_CONFIGURATION,
    XIL_ERROR_OTHER,
    XIL_ERROR_INTERNAL
} XilErrorCategory;

/*
 *  PhotoCD Definitions for support of SUNWPhotoCD I/O Device
 */
#define XIL_PHOTOCD_RESOLUTIONS 8

typedef enum __XilPhotoCDResolution {
    XIL_PHOTOCD_INVALID    = -1,
    XIL_PHOTOCD_16TH_BASE  = 0,
    XIL_PHOTOCD_4TH_BASE   = 1,
    XIL_PHOTOCD_BASE       = 2,
    XIL_PHOTOCD_4X_BASE    = 3,
    XIL_PHOTOCD_16X_BASE   = 4,
    XIL_PHOTOCD_64X_BASE   = 5,
    XIL_PHOTOCD_256X_BASE  = 6,
    XIL_PHOTOCD_1024X_BASE = 7
} XilPhotoCDResolution;

typedef enum __XilPhotoCDFormat {
    XIL_PHOTOCD_RGB,
    XIL_PHOTOCD_YCC
} XilPhotoCDFormat;

typedef enum __XilPhotoCDRotate {
    XIL_PHOTOCD_CCW0   = 0,
    XIL_PHOTOCD_CCW90  = 1,
    XIL_PHOTOCD_CCW180 = 2,
    XIL_PHOTOCD_CCW270 = 3
} XilPhotoCDRotate;

/*
 * Structure Definitions for the Jpeg DCT-based Codec
 */
typedef enum __XilJpegCompressedDataFormat {
    INTERCHANGE,
    ABBREVIATED_FORMAT
} XilJpegCompressedDataFormat;

typedef struct __XilJpegQTable {
    int table;
    int (*value)[8];
} XilJpegQTable;

typedef enum __XilJpegHTableType {
    DC,
    AC
} XilJpegHTableType;

typedef struct __XilJpegHTableValue {
    int bits;
    int pattern;
} XilJpegHTableValue;

typedef struct __XilJpegHTable {
    int table;
    XilJpegHTableType type;
    XilJpegHTableValue *value;
} XilJpegHTable;

typedef struct __XilJpegBandQTable {
    int band;
    int table;
} XilJpegBandQTable;

typedef struct __XilJpegBandHTable {
    int band;
    int table;
    XilJpegHTableType type;
} XilJpegBandHTable;


/*
 * Structure Definitions for the Jpeg Lossless Codec
 */
typedef enum {
    ONE_D1=1,
    ONE_D2,
    ONE_D3,
    TWO_D1,
    TWO_D2,
    TWO_D3,
    TWO_D4
 }  XilJpegLLBandSelectorType;

typedef struct __XilJpegLLBandSelector {
    int band;
    XilJpegLLBandSelectorType selector;
} XilJpegLLBandSelector;

typedef struct __XilJpegLLBandPtTransform {
    int band;
    int PtTransform;
} XilJpegLLBandPtTransform;

/*
 * Structure Definitions for the Mpeg1 Codec
 */
typedef enum {
    I=1, P, B, D
} XilMpeg1FrameType;

typedef enum {
    NullDefaultRatio,
    Ratio_1_0,		/* 1.0		*/
    Ratio_0_6735,	/* 0.6735	*/
    Ratio_0_7031,	/* 0.7031	*/
    Ratio_0_7615,	/* 0.7615	*/
    Ratio_0_8055,	/* 0.8055	*/
    Ratio_0_8437,	/* 0.8437	*/
    Ratio_0_8935,	/* 0.8935	*/
    Ratio_0_9157,	/* 0.9157	*/
    Ratio_0_9815,	/* 0.9815	*/
    Ratio_1_0255,	/* 1.0255	*/
    Ratio_1_0695,	/* 1.0695	*/
    Ratio_1_0950,	/* 1.0950	*/
    Ratio_1_1575,	/* 1.1575	*/
    Ratio_1_2015	/* 1.2015	*/
} XilMpeg1PelAspectRatio;

typedef enum {
    NullDefaultRate,
    Rate_23_976,	/* 23.976	*/
    Rate_24,		/* 24.0		*/
    Rate_25,		/* 25.0		*/
    Rate_29_97,		/* 29.97	*/
    Rate_30,		/* 30.0		*/
    Rate_50,		/* 50.0		*/
    Rate_59_94,		/* 59.94	*/
    Rate_60		/* 60.0		*/
} XilMpeg1PictureRate;

typedef struct __XilMpeg1TimeCode {
    Xil_boolean		drop_frame_flag;
    Xil_unsigned32	hours;
    Xil_unsigned32	minutes;
    Xil_unsigned32	seconds;
    Xil_unsigned32	pictures;
} XilMpeg1TimeCode;

typedef struct __XilMpeg1Pattern {
    char*		pattern;
    Xil_unsigned32	repeat_count;
} XilMpeg1Pattern;


/*
 * Structure Definitions for the Cell Codecs (Cell and CellB)
 */

/*
 *  Used with the Cell CIS attribute RDWR_INDICES
 */
typedef struct __XilIndexList {
    Xil_unsigned32*  pixels;        /* pointer to array of pixel values */
    Xil_unsigned16   ncolors;       /* number of pixel values */
} XilIndexList;

/*
 *  Used with the Cell CIS attribute USER_DATA
 */
typedef struct __XilCellUserData {
    Xil_unsigned8*   data;         /* pointer to the data */
    Xil_unsigned32   length;       /* number of bytes in the data */
} XilCellUserData;

/*
 *  Used with the Cell CIS attribute ENCODING_TYPE
 */
typedef enum __XilCellEncodingType {
    BTC,
    DITHER
} XilCellEncodingType;


/*
 * Structure Definitions for the H.261 (Px64) Codecs
 */
typedef struct __XilH261MVSearchRange {
    int x;	/* horizontal search limit */
    int y;	/* vertical search limit */
} XilH261MVSearchRange;

typedef enum {
    QCIF=1,
    CIF
} XilH261SourceFormat;

/*
 *  Function declaration for the callback which is used by
 *  xil_cis_put_bits_ptr() to indicate XIL is done with the user provided
 *  compressed data.
 */
typedef void (*XIL_FUNCPTR_DONE_WITH_DATA)(void*);

/*
 *  Function declaration for indicating XIL is done with a user-provided data
 *  pointer.  The second argument is for a user-provided argument.  This
 *  typedef is used via xil_storage_set_data_release().
 */
typedef void (*XilDataReleaseFuncPtr)(void*, void*);

#ifdef _WINDOWS
#define Display void*
#define Window  void*
#define Visual  void*
#define Region  HRGN
#endif

/*
 *  Private libxil interface includes
 */
#ifdef _XIL_LIBXIL_PRIVATE
#include "XilDefinesPrivate.hh"
#endif

#endif  /* _XIL_DEFINES_H */
