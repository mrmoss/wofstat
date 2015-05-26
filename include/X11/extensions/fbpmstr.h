/*
 * Copyright (c) 1999 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#pragma ident   "@(#)fbpmstr.h	1.3	00/06/07 SMI"


#define X_FBPMGetVersion	0
#define X_FBPMCapable		1
#define X_FBPMEnable		4
#define X_FBPMDisable		5
#define X_FBPMForceLevel	6
#define X_FBPMInfo       	7

#define FBPMNumberEvents	0

#define FBPMNumberErrors	0

#define FBPMMajorVersion	1
#define FBPMMinorVersion	1

#define FBPMExtensionName	"FBPM"

typedef struct {
    CARD8	reqType;	/* always FBPMCode */
    CARD8	fbpmReqType;	/* always X_FBPMGetVersion */
    CARD16	length B16;
    CARD16	majorVersion B16;
    CARD16	minorVersion B16;
} xFBPMGetVersionReq;
#define sz_xFBPMGetVersionReq 8

typedef struct {
    BYTE	type;			/* X_Reply */
    CARD8	pad0;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD16	majorVersion B16;
    CARD16	minorVersion B16;
    CARD32	pad1 B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
} xFBPMGetVersionReply;
#define sz_xFBPMGetVersionReply 32

typedef struct {
    CARD8	reqType;	/* always FBPMCode */
    CARD8	fbpmReqType;	/* always X_FBPMCapable */
    CARD16	length B16;
} xFBPMCapableReq;
#define sz_xFBPMCapableReq 4

typedef struct {
    BYTE	type;			/* X_Reply */
    CARD8	pad0;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    BOOL	capable;
    CARD8	pad1;
    CARD16	pad2 B16;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
    CARD32	pad7 B32;
} xFBPMCapableReply;
#define sz_xFBPMCapableReply 32

typedef struct {
    CARD8	reqType;	/* always FBPMCode */
    CARD8	fbpmReqType;	/* always X_FBPMEnable */
    CARD16	length B16;
    CARD16      level B16;      /* power level requested */
    CARD16      pad0 B16;

} xFBPMEnableReq;
#define sz_xFBPMEnableReq 8

typedef struct {
    CARD8	reqType;	/* always FBPMCode */
    CARD8	fbpmReqType;	/* always X_FBPMDisable */
    CARD16	length B16;
} xFBPMDisableReq;
#define sz_xFBPMDisableReq 4

typedef struct {
    CARD8	reqType;	/* always FBPMCode */
    CARD8	fbpmReqType;	/* always X_FBPMInfo */
    CARD16	length B16;
} xFBPMInfoReq;
#define sz_xFBPMInfoReq 4

typedef struct {
    BYTE	type;			/* X_Reply */
    CARD8	pad0;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD16      power_level B16;
    BOOL        state;
    CARD8       pad1;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xFBPMInfoReply;
#define sz_xFBPMInfoReply 32

typedef struct {
    CARD8       reqType;        /* always FBPMCode */
    CARD8       fbpmReqType;    /* always X_FBPMForceLevel */
    CARD16      length B16;
    CARD16      level B16;      /* power level requested */
    CARD16      pad0 B16;
} xFBPMForceLevelReq;
#define sz_xFBPMForceLevelReq 8

