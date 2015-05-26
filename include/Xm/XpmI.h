/*
 * (c) Copyright 1996 Digital Equipment Corporation.
 * (c) Copyright 1996 Hewlett-Packard Company.
 * (c) Copyright 1996 International Business Machines Corp.
 * (c) Copyright 1996 Sun Microsystems, Inc.
 * (c) Copyright 1996 Novell, Inc.
 * (c) Copyright 1996 FUJITSU LIMITED.
 * (c) Copyright 1996 Hitachi.
 *
 *	XpmI.h	version 1.9, last updated 04/11/30.
 */
#include "XpmP.h"

#ifndef _XpmI_h
#define _XpmI_h

/* Xpm internal symbols are prefixed with _Xm */

#define xpmParseData            _Xmxpm21ParseData
#define xpmParseDataAndCreate   _XmxpmParseDataAndCreate
#define xpmFreeColorTable       _Xmxpm21FreeColorTable
#define xpmInitAttributes       _XmxpmInitAttributes
#define xpmInitXpmImage         _XmxpmInitXpmImage
#define xpmInitXpmInfo          _XmxpmInitXpmInfo
#define xpmSetInfoMask          _XmxpmSetInfoMask
#define xpmSetInfo              _XmxpmSetInfo
#define xpmSetAttributes        _Xmxpm21SetAttributes
#define xpmCreatePixmapFromImage _XmxpmCreatePixmapFromImage
#define xpmCreateImageFromPixmap _XmxpmCreateImageFromPixmap
#define xpmHashTableInit        _XmxpmHashTableInit
#define xpmHashTableFree        _XmxpmHashTableFree
#define xpmHashSlot             _XmxpmHashSlot
#define xpmHashIntern           _XmxpmHashIntern
#define xpmNextString           _Xmxpm21NextString
#define xpmNextUI               _Xmxpm21NextUI
#define xpmGetString            _Xmxpm21GetString
#define xpmNextWord             _Xmxpm21NextWord
#define xpmGetCmt               _Xmxpm21GetCmt
#define xpmParseHeader          _XmxpmParseHeader
#define xpmParseValues          _XmxpmParseValues
#define xpmParseColors          _XmxpmParseColors
#define xpmParseExtensions      _XmxpmParseExtensions
#define xpmReadRgbNames         _XmxpmReadRgbNames
#define xpmGetRgbName           _XmxpmGetRgbName
#define xpmFreeRgbNames         _XmxpmFreeRgbNames
#define xpmGetRGBfromName       _XmxpmGetRGBfromName
#define xpm_xynormalizeimagebits _Xmxpm_xynormalizeimagebits
#define xpm_znormalizeimagebits _Xmxpm_znormalizeimagebits
#define xpmstrdup               _Xmxpmstrdup
#define xpmstrcasecmp           _Xmxpmstrcasecmp
#define xpmatoui                _Xmxpmatoui
#define xpmDataTypes            _XmxpmDataTypes
#define xpmColorKeys            _Xmxpm21ColorKeys

/* The following is the original XpmI.h header file,
   except that it includes XpmP.h instead of xpm.h */

/*
 * Copyright (C) 1989-95 GROUPE BULL
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * GROUPE BULL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of GROUPE BULL shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization from GROUPE BULL.
 */

/***************************************************************************
* XpmI.h:                                                                  *
*  XPM library - Internal Include file					   *
*  ** Everything defined here is subject to changes any time. **           *
*  Developed by Arnaud Le Hors                                             *
***************************************************************************/

/*
 * The code related to FOR_MSW has been added by
 * HeDu (hedu@cul-ipn.uni-kiel.de) 4/94
 */

#ifndef XPMI_h
#define XPMI_h

/*
 * lets try to solve include files
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/isa_defs.h>
#include <limits.h>

/* stdio.h doesn't declare popen on a Sequent DYNIX OS */
#ifdef sequent
extern FILE *popen();
#endif

#if defined(SYSV) || defined(SVR4) || defined(VMS) || defined(WIN32)
#include <string.h>

#ifndef index
#define index strchr
#endif

#ifndef rindex
#define rindex strrchr
#endif

#else  /* defined(SYSV) || defined(SVR4) || defined(VMS) */
#include <strings.h>
#endif

#if defined(SYSV) || defined(SVR4) || defined(VMS) || defined(WIN32)
#ifndef bcopy
#define bcopy(source, dest, count) memcpy(dest, source, count)
#endif
#ifndef bzero
#define bzero(b, len) memset(b, 0, len)
#endif
#endif

/* the following is defined in X11R6 but not in previous versions */
#if defined(__alpha) || defined(_LP64) /* Wyoming 64-bit Fix */
#ifndef LONG64
#define LONG64
#endif
#endif

#ifdef VMS
#include <unixio.h>
#include <file.h>
#endif

/* The following should help people wanting to use their own memory allocation
 * functions. To avoid the overhead of a function call when the standard
 * functions are used these are all macros, even the XpmFree function which
 * needs to be a real function for the outside world though.
 * So if change these be sure to change the XpmFree function in misc.c
 * accordingly.
 */
#ifndef NO_XPMFREE_MACRO
#ifdef XpmFree
#undef XpmFree
#endif
#define XpmFree(ptr) free(ptr)
#endif

#ifndef FOR_MSW
#define XpmMalloc(size) malloc((size))
#define XpmRealloc(ptr, size) realloc((ptr), (size))
#define XpmCalloc(nelem, elsize) calloc((nelem), (elsize))
#else
/* checks for mallocs bigger than 64K */
#define XpmMalloc(size) boundCheckingMalloc((long)(size))/* in simx.[ch] */
#define XpmRealloc(ptr, size) boundCheckingRealloc((ptr),(long)(size))
#define XpmCalloc(nelem, elsize) \
		boundCheckingCalloc((long)(nelem),(long) (elsize))
#endif

#if defined(SCO) || defined(__USLC__)
#include <stdint.h>    /* For SIZE_MAX */
#endif
#include <sys/types.h>
#include <limits.h>
#ifndef SIZE_MAX
# ifdef ULONG_MAX
#  define SIZE_MAX ULONG_MAX
# else
#  define SIZE_MAX UINT_MAX
# endif
#endif


#define XPMARRAY 0
#define XPMFILE  1
#define XPMPIPE  2
#define XPMBUFFER 3

#define EOL '\n'
#define TAB '\t'
#define SPC ' '

typedef struct {
    char *type;			/* key word */
    char *Bcmt;			/* string beginning comments */
    char *Ecmt;			/* string ending comments */
    char Bos;			/* character beginning strings */
    char Eos;			/* character ending strings */
    char *Strs;			/* strings separator */
    char *Dec;			/* data declaration string */
    char *Boa;			/* string beginning assignment */
    char *Eoa;			/* string ending assignment */
}      xpmDataType;

extern xpmDataType xpmDataTypes[];

/*
 * rgb values and ascii names (from rgb text file) rgb values,
 * range of 0 -> 65535 color mnemonic of rgb value
 */
typedef struct {
    int r, g, b;
    char *name;
}      xpmRgbName;

/* Maximum number of rgb mnemonics allowed in rgb text file. */
#define MAX_RGBNAMES 1024

extern char *xpmColorKeys[];
extern char *_XmxpmColorKeys[];

#define TRANSPARENT_COLOR "None"	/* this must be a string! */

/* number of xpmColorKeys */
#define NKEYS 5

#define UNDEF_PIXEL 0x80000000

/* structures and functions related to hastable code */
typedef struct _xpmHashAtom {
    char *name;
    void *data;
}      *xpmHashAtom;

typedef struct {
    unsigned int size;
    unsigned int limit;
    unsigned int used;
    xpmHashAtom *atomTable;
}      xpmHashTable;

#define HashAtomData(i) ((void *)i)
#define HashColorIndex(slot) ((u_int)((*slot)->data))
#define USE_HASHTABLE (cpp > 2 && ncolors > 4)

#define _XmxpmGetC(mdata) \
	((!mdata->type || mdata->type == XPMBUFFER) ? \
	 (*mdata->cptr++) : (getc_unlocked(mdata->stream.file)))

/*
 * For backward compatibility
 */
typedef struct {
    u_int        type;
    union {
        FILE *file;
        char **data;
    }     stream;
    char                *cptr;
    u_int        line;
    int                 CommentLength;
    char                Comment[BUFSIZ];
    char                *Bcmt, *Ecmt, Bos, Eos;
}      xpmData;

/*
 * functions declarations
 */

/* From Xpmcreate.c */
extern void	xpm_xynormalizeimagebits(u_char *, XImage *);
extern void	xpm_znormalizeimagebits(u_char *, XImage *);
extern int	xpmParseDataAndCreate(Display	*, xpmData_21 *, XImage **, XImage **,
											 XpmImage *,  XpmInfo *, XpmAttributes_21 *);

/* From Xpmdata.c */
extern int xpmNextString(xpmData_21 *mdata);
extern int xpmNextUI(xpmData_21 *mdata, u_int *ui_return);
extern u_int xpmNextWord(xpmData_21 *mdata, char *buf, u_int buflen);
extern int xpmGetString(xpmData_21 *mdata, char **sptr, u_int *l);
extern int xpmGetCmt(xpmData_21 *mdata, char **cmt);
extern int xpmParseHeader(xpmData_21 *mdata);

/* From Xpmhashtab.c */
extern xpmHashAtom * xpmHashSlot(xpmHashTable *table, char *s);
extern int xpmHashIntern(xpmHashTable *table, char *tag, void *data);
extern int xpmHashTableInit(xpmHashTable *table);
extern void xpmHashTableFree(xpmHashTable *table);

/* From Xpmmisc.c */
#ifdef NEED_STRDUP
extern char *	xpmstrdup(char *s1);
#else
#undef xpmstrdup
#define xpmstrdup strdup
#endif
extern u_int xpmatoui(char *p, u_int l, u_int *ui_return);
extern char *	XpmGetErrorString(int errcode);
extern int XpmLibraryVersion();
extern void XpmFree(void *ptr);

/* From Xpmparse.c */
extern int xpmParseData(xpmData_21 *, XpmImage *, XpmInfo *);
extern int xpmParseValues(xpmData_21 *, u_int *, u_int *, u_int *,
								  u_int *, u_int *, u_int *, u_int *, u_int *);
extern int xpmParseColors(xpmData_21 *, u_int, u_int, XpmColor **, xpmHashTable *);
extern int xpmParseExtensions(xpmData_21 *, XpmExtension **, u_int *);

/* From Xpmrgb.c */
extern int xpmReadRgbNames(char *rgb_fname, xpmRgbName *rgbn);
extern char *xpmGetRgbName(xpmRgbName *, int, int, int, int);
extern void xpmFreeRgbNames(xpmRgbName *rgbn, int rgbn_max);
extern void xpmFreeRgbNames(xpmRgbName *rgbn, int rgbn_max);

/* From XpmDataObso.c */
extern u_int _XmXpmatoui(char *p, u_int l, u_int *ui_return);
extern int	_XmxpmNextString(xpmData * mdata);
extern int	_XmxpmNextUI(xpmData * mdata, u_int *ui_return);
extern u_int	_XmxpmNextWord(xpmData *, char *, u_int);
extern int	_XmxpmGetString(xpmData *mdata, char **sptr, u_int *l);
extern int	_XmxpmGetCmt(xpmData * mdata, char **cmt);
extern int	_XmxpmReadFile(char *filename, xpmData * mdata);
extern void	_XmxpmOpenArray(char **data, xpmData * mdata);
extern int	_XmXpmDataClose(xpmData * mdata);

#ifdef NEED_STRDUP
extern char *	xpmstrdup(char *s1);
#else
#undef xpmstrdup
#define xpmstrdup strdup
#endif

#ifdef NEED_STRCASECMP                   
extern int	xpmstrcasecmp(char *s1, char *s2);
#else
#undef xpmstrcasecmp
#define xpmstrcasecmp strcasecmp
#endif

/*
 * Macros
 *
 * The XYNORMALIZE macro determines whether XY format data requires
 * normalization and calls a routine to do so if needed. The logic in
 * this module is designed for LSBFirst byte and bit order, so
 * normalization is done as required to present the data in this order.
 *
 * The ZNORMALIZE macro performs byte and nibble order normalization if
 * required for Z format data.
 *
 * The XYINDEX macro computes the index to the starting byte (char) boundary
 * for a bitmap_unit containing a pixel with coordinates x and y for image
 * data in XY format.
 *
 * The ZINDEX* macros compute the index to the starting byte (char) boundary
 * for a pixel with coordinates x and y for image data in ZPixmap format.
 *
 */

#define XYNORMALIZE(bp, img) \
    if ((img->byte_order == MSBFirst) || (img->bitmap_bit_order == MSBFirst)) \
	xpm_xynormalizeimagebits((unsigned char *)(bp), img)

#define ZNORMALIZE(bp, img) \
    if (img->byte_order == MSBFirst) \
	xpm_znormalizeimagebits((unsigned char *)(bp), img)

#define XYINDEX(x, y, img) \
    ((y) * img->bytes_per_line) + \
    (((x) + img->xoffset) / img->bitmap_unit) * (img->bitmap_unit >> 3)

#define ZINDEX(x, y, img) ((y) * img->bytes_per_line) + \
    (((x) * img->bits_per_pixel) >> 3)

#define ZINDEX32(x, y, img) ((y) * img->bytes_per_line) + ((x) << 2)

#define ZINDEX16(x, y, img) ((y) * img->bytes_per_line) + ((x) << 1)

#define ZINDEX8(x, y, img) ((y) * img->bytes_per_line) + (x)

#define ZINDEX1(x, y, img) ((y) * img->bytes_per_line) + ((x) >> 3)

#ifdef __STDC__
#define Const const
#else
#define Const /**/
#endif

#endif

#endif /* _XpmI_h */
