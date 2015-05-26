#ifndef __XMUSOLARIS_H__
#define __XMUSOLARIS_H__
#pragma ident "@(#)XmuSolaris.h	1.2 96/06/24   SMI" 
/*
 *   ----------------------------------------------------------------- 
 *          Copyright (C) 1996  Sun Microsystems, Inc
 *                      All rights reserved. 
 *            Notice of copyright on this source code 
 *            product does not indicate publication. 
 *   
 *                    RESTRICTED RIGHTS LEGEND: 
 *   Use, duplication, or disclosure by the Government is subject 
 *   to restrictions as set forth in subparagraph (c)(1)(ii) of 
 *   the Rights in Technical Data and Computer Software clause at 
 *   DFARS 52.227-7013 and in similar clauses in the FAR and NASA 
 *   FAR Supplement. 
 *   ----------------------------------------------------------------- 
 */
#include <X11/Xlib.h>
#ifdef __cplusplus
extern "C" {
#endif


Status XSolarisGetVisualGamma (Display *dpy, int screen_number, Visual *visual,
			double *gamma);

Bool XSolarisCheckColormapEquivalence(Display *dpy,  int screen_number,
				Visual *pVis1, Visual* pVis2);

#ifdef __cplusplus
}
#endif

#endif /* __XMUSOLARIS_H__ */
