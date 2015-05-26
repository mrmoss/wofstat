/*------------------------------------------------------------------------
*
*   File:	xil.h
*   Project:	XIL
*   Revision:	1.18
*   Last Mod:	11:05:35, 06/19/01
*
*  Description:
*		
*	C-side of defines and includes for XIL c-bindings
*	
*-----------------------------------------------------------------------*/

#ifndef _XIL_API_H
#define _XIL_API_H

#ifndef SUNXIL_WARNING_DISABLE
#error  "Solaris XIL has been declared Obsolete and may not \
be present in versions of Solaris after Solaris 9. \
#define SUNXIL_WARNING_DISABLE (or use -D) \
to disable this message." 
#endif


/*
 *  XIL lookup version number typedef.
 *
 *  These tests for long long availability have been borrowed from
 *  /usr/include/sys/types.h.
 *
 *  If long long is not available, then an unsigned long is used in
 *  its place.  We ensure that the functionality is maintained by
 *  swapping the 32-bit quantities so the least significant word of
 *  the 64-bit quantity is returned in the case of an application that
 *  has been built with the XilVersionNumber as an unsigned long
 *  instead of an unsigned long long.
 *
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
typedef unsigned long long      XilVersionNumber;
#else
typedef unsigned long           XilVersionNumber;
#endif
 */


#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <xil/_XilDefines.h>


#ifdef _WINDOWS
typedef char *caddr_t;
#endif

/*
 *  Doing the typedef to pointer to structure enables ANSI C type checking
 *  even though the ptr inside is garbage.
 */  
typedef struct __XilObject {
  caddr_t ptr;
} *XilObject;

typedef struct __XilImage {
  caddr_t ptr;
} *XilImage;

typedef struct __XilImageType {
  caddr_t ptr;
} *XilImageType;

typedef struct __XilRoi {
  caddr_t ptr;
} *XilRoi;

typedef struct __XilSystemState {
  caddr_t ptr;
} *XilSystemState;

typedef struct __XilSel {
  caddr_t ptr;
} *XilSel;

typedef struct __XilKernel {
  caddr_t ptr;
} *XilKernel;

typedef struct __XilLookup {
  caddr_t ptr;
} *XilLookup;

typedef struct __XilError {
  caddr_t ptr;
} *XilError;

/*
 *  This lives here because it can't live in XilDefines.h due to a convolct
 *  between the C++ understanding of XilError and the C understanding of
 *  XilError (which are different).
 */
typedef Xil_boolean (*XilErrorFunc)(XilError);

typedef struct __XilCis {
  caddr_t ptr;
} *XilCis;

typedef struct __XilDitherMask {
  caddr_t ptr;
} *XilDitherMask;

typedef struct __XilHistogram {
  caddr_t ptr;
} *XilHistogram;

typedef struct __XilColorspace {
  caddr_t ptr;
} *XilColorspace;

/*
 *  Objects New for XIL 1.2
 */
typedef struct __XilDevice {
  caddr_t ptr;
} *XilDevice;

typedef struct __XilInterpolationTable {
  caddr_t ptr;
} *XilInterpolationTable;

/*
 *  New Objects for XIL 1.3
 */
typedef struct __XilStorage {
  caddr_t ptr;
} *XilStorage;

typedef struct __XilColorspaceList {
  caddr_t ptr;
} *XilColorspaceList;

/*
 *  Definition of pre-XIL 1.3 API in-memory defines and typedefs.
 *
 *  Of course, these are still supported as part of the XIL API.  They
 *  are used by xil_get_memory_storage() and xil_set_memory_storage()
 *  which do not support band sequential or tiled storage data formats.
 *
 *  Applications are encouraged to use the new XilStorage object and
 *  its associated interfaces for managing image storage since it
 *  supports tiled storage and band sequential storage.
 */

typedef struct __XilMemoryStorageBit {
   Xil_unsigned8* data;            /* pointer to the first byte of the image */
   unsigned int   scanline_stride; /* the number of bytes between scanlines */
   unsigned long  band_stride;     /* the number of bytes between bands */
   unsigned char  offset;          /* the number of bits to the first pixel */
} XilMemoryStorageBit;

typedef struct __XilMemoryStorageByte {
   Xil_unsigned8* data;            /* pointer to the first byte of the image */
   unsigned long  scanline_stride; /* the number of bytes between scanlines */
   unsigned int   pixel_stride;    /* the number of bytes between pixels */
} XilMemoryStorageByte;

typedef struct __XilMemoryStorageShort {
   Xil_signed16* data;             /* pointer to the first word of the image */
   unsigned long scanline_stride;  /* the number of words between scanlines */
   unsigned int  pixel_stride;     /* the number of words between pixels */
} XilMemoryStorageShort;

/*
 *  Previous releases of XIL had an unsupported/undocumented structure here for
 *  describing floating point data.  We ensure binary compatibility with the
 *  supported interface be replacing it with a place-holder for the
 *  undocumented structure.
 */
typedef struct __XilMemoryStoragePlaceHolderForBackwardCompatibility {
   void*         a;
   unsigned long b;
   unsigned int  c;
} XilMemoryStoragePlaceHolderForBackwardCompatibility;

typedef union __XilMemoryStorage {
    XilMemoryStorageBit   bit;
    XilMemoryStorageByte  byte;
    XilMemoryStorageShort shrt;
    XilMemoryStoragePlaceHolderForBackwardCompatibility backward_compatible_space;
} XilMemoryStorage;

/*
 *  Function declaration for an image's data supply routine which is specified
 *  by xil_set_data_supply_routine() binding.
 *
 *  NOTE:  A second declaration of XilDataSupplyFuncPtr lives in
 *         XilDefinesPrivate.hh because XilStorage is a pointer inside of
 *         XIL. 
 */
typedef int  (*XilDataSupplyFuncPtr)(XilImage     image,
                                     XilStorage   storage,
                                     unsigned int x,
                                     unsigned int y,
                                     unsigned int xsize,
                                     unsigned int ysize,
                                     void*        user_args);
/*
 *  Include C Prototypes of XIL functions
 */
#include <xil/_c_bindings.h>

#ifdef __cplusplus
}
#endif

#endif /* _XIL_API_H */
