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

/* @(#)Xst_ext.h	1.7 04/07/27 SMI */

#ifndef _XSTEXT_H
#define _XSTEXT_H

#include <X11/Xmd.h>
#include "Xst_typedef.h"

typedef struct {
    XExtCodes *codes;
    CARD32 serverSignature;
    CARD32 serverCapabilities;
} XSTCodes;

/***
typedef struct Matrix3Struct
{
    double xx;
    double xy;
    double yx;
    double yy;
    double tx;
    double ty;
#ifdef THREEBYTHREE
    double xz;
    double yz;
    double tz;
#endif
}
Matrix3, XSTMatrix, *Matrix3Ptr;
***/
typedef struct {
    XSTMatrix matrix;
    Bool      matrix_dirty;
    double    hdpi;
    double    vdpi;
} XSTData;

XSTCodes *_XSTCodes (Display *dpy);
XSTData  *_XSTGCData(Display *dpy, GC gc);

#endif
