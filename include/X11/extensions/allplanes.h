/*
 * Copyright (c) 1990,1994 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#pragma ident   "@(#)allplanes.h	35.2	00/06/07 SMI"

/* @(#)allplanes.h	35.2 00/06/07 INCLUDE_XEXT SMI */

#ifndef _ALLPLANES_H_
#define _ALLPLANES_H_

#define X_AllPlanesQueryVersion			0
#define X_AllPlanesPolyPoint			1
#define X_AllPlanesPolyLine			2
#define X_AllPlanesPolySegment			3
#define X_AllPlanesPolyRectangle		4
#define X_AllPlanesPolyFillRectangle		5

#define AllPlanesNumberEvents			0

#ifndef _ALLPLANES_SERVER_

extern Bool XAllPlanesQueryExtension();
extern Status XAllPlanesQueryVersion();
extern void XAllPlanesDrawPoints();
extern void XAllPlanesDrawLines();
extern void XAllPlanesDrawSegments();
extern void XAllPlanesDrawRectangles();
extern void XAllPlanesFillRectangles();

#endif /* _ALLPLANES_SERVER_ */

#endif /* _ALLPLANES_H_ */
