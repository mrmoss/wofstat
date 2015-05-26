/*
 * Copyright (c) 1990,1993-1994 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#pragma ident "@(#)allplanesstr.h	35.2 00/06/07 INCLUDE_EXT SMI"

#ifndef _ALLPLANESSTR_H_
#define _ALLPLANESSTR_H_

#include "allplanes.h"

#define ALLPLANESNAME "SUN_ALLPLANES"
#define ALLPLANES_MAJOR_VERSION	1	/* current version numbers */
#define ALLPLANES_MINOR_VERSION	0

typedef struct {
    CARD8       reqType;		/* always AllPlanesReqCode */
    CARD8       allplanesReqType;	/* always X_AllPlanesQueryVersion */
    CARD16	length B16;
} xAllPlanesQueryVersionReq;
#define sz_xAllPlanesQueryVersionReq	4

typedef struct {
    BYTE        type;			/* X_Reply */
    CARD8       unused;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD16	majorVersion B16;
    CARD16	minorVersion B16;
    CARD32	pad0 B32;
    CARD32	pad1 B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
} xAllPlanesQueryVersionReply;
#define sz_xAllPlanesQueryVersionReply	32

typedef struct {
    CARD8       reqType;		/* always AllPlanesReqCode */
    CARD8       allplanesReqType;	/* always X_AllPlanesPolySegment */
    CARD16	length B16;
    Drawable	drawable B32;
} xAllPlanesPolySegmentReq;
#define sz_xAllPlanesPolySegmentReq 8

typedef xAllPlanesPolySegmentReq xAllPlanesPolyRectangleReq;
#define sz_xAllPlanesPolyRectangleReq 8

typedef xAllPlanesPolySegmentReq xAllPlanesPolyFillRectangleReq;
#define sz_xAllPlanesPolyFillRectangleReq 8

typedef struct {
    CARD8       reqType;		/* always AllPlanesReqCode */
    CARD8       allplanesReqType;	/* always X_AllPlanesPolyPoint */
    CARD16	length B16;
    Drawable	drawable B32;
    BYTE	coordMode;
    CARD8	pad0;
    CARD16	pad1 B16;
} xAllPlanesPolyPointReq;
#define sz_xAllPlanesPolyPointReq 12

typedef xAllPlanesPolyPointReq xAllPlanesPolyLineReq;
#define sz_xAllPlanesPolyLineReq 12
#endif /* _ALLPLANESSTR_H_ */
