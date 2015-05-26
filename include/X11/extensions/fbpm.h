/*
 * Copyright (c) 1999-2000 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#pragma ident   "@(#)fbpm.h	1.9	03/05/27 SMI"

#define FBPMModeOn	0
#define FBPMModeStandby	1
#define FBPMModeSuspend	2
#define FBPMModeOff	3

#define DDXStatError 0
#define DDXStatFbOk  1
#define DDXStatMonOk 2
#define DDXStatOk	(DDXStatFbOk | DDXStatMonOk)

#ifndef DPMS_SERVER

Bool FBPMQueryExtension(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);
Status FBPMGetVersion(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);
Bool FBPMCapable(
#if NeedFunctionPrototypes
Display *
#endif
);
Bool FBPMEnable(
#if NeedFunctionPrototypes
Display *, 
int
#endif
);
Status FBPMDisable(
#if NeedFunctionPrototypes
Display *
#endif
);
Status FBPMForceLevel(
#if NeedFunctionPrototypes
Display *, 
CARD16
#endif
);
Status FBPMInfo(
#if NeedFunctionPrototypes
Display *, 
CARD16 *, 
BOOL *
#endif
);

#endif
