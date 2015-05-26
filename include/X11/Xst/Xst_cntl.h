/*
 * Copyright 2001, 2002, Sun Microsystems, Inc.
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

/* @(#)Xst_cntl.c	1.54 03/03/06 SMI */

#define NEED_REPLIES

void XSTEnable(Display *dpy);


/* **********************************************************************************
 * XSTDisable(Display *)
 *
 * Returns:     NONE
 * Called by:   USER
 * Calls:       NONE
 *
 * @dpy:	X display pointer
 *
 * This function sends a protocol message to the server to disable the ST extension.
 * By doing this, no applications may use the ST server extension.  This may be a bug.
 * May only want to disable ST for this application.  This function is meaningless 
 * for local applications as they are already at the fallback doing ST locally.
 */
void XSTDisable(Display *dpy);

/* **********************************************************************************
 * XSTVersion(Display *)
 *
 * Returns:     version
 * Called by:   USER
 * Calls:       NONE
 *
 * @dpy:	X display pointer
 *
 * This function sends a protocol message to retreive the version information.
 */
unsigned int XSTVersion(Display *dpy);


/* **********************************************************************************
 * XSTInfo(Display *)
 *
 * Returns:     STSTUS
 * Called by:   USER
 * Calls:       NONE
 *
 * @dpy:	X display pointer
 *
 * This function sends a protocol message to get the status of the ST extension.
 */
int XSTInfo(Display *dpy);

/* **********************************************************************************
 * XSTClientSide(Display *)
 *
 * Returns:     STSTUS
 * Called by:   USER
 * Calls:       NONE
 *
 * @dpy:	X display pointer
 *
 * This function tells the local application to use client side rendering.
 */
int XSTClient(Display *dpy);

/* **********************************************************************************
 * XSTServerSide(Display *)
 *
 * Returns:     STSTUS
 * Called by:   USER
 * Calls:       NONE
 *
 * @dpy:	X display pointer
 *
 * This function tells the local application to use server side rendering.
 */
int XSTServer(Display *dpy);
