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

/* @(#)Xst_scaler.h	1.8 04/07/27 SMI */

#ifndef _XSTSCALER_H
#define _XSTSCALER_H

#include "Xst_typedef.h"
#include "Xst_env.h"

/******************************** XSTScaler General Defines *************************/

/****************************** XSTScaler Function Prototypes ***********************/

/** @defgroup Scaler XSTScaler functions
 * @{
 */

/**
 * Retrieves general information from the scaler.
 *
 * @param dpy			X Display value
 * @param iEnv			XSTTypeEnv XID of the STTypeEnv object to use
 * @param iScaler		Scaler ID
 * @param oVersion		Scaler version
 * @param oShortName		Short ascii scaler name - up to 16 characters
 * @param oLongName		Free-form ascii scaler name
 * @param oNotice		Free-form ascii copyright notice
 * @param oSFlags		Scaler flags
 * @param oFFlags		Font types supported by the scaler
 *
 * @return scaler tag.
 */
XSTTag XSTScalerGetInfo ( Display           *dpy, 
                          XSTTypeEnv         iEnv, 
                          XSTScaler          iScaler, 
                          XSTVersionID      *oVersion, 
                          const char       **oShortName, 
                          const char       **oLongName, 
                          const char       **oNotice, 
                          XSTScalerFlags    *oSFlags, 
                          XSTScalerFontMask *oFFlags);

/**
 * Scaler ioctl - exchange control information with the scaler. This function may 
 * allocate memory for the data returned by the scaler. It is the callers 
 * responsiblity to free up this memory using XSTFree().
 *
 * @param dpy                   X Display value
 * @param iEnv                  XSTTypeEnv XID of the STTypeEnv object to use
 * @param iScaler               Scaler ID
 * @param iToScaler             This data is sent to the scaler
 * @param iToByteCount          Number of bytes in iToScaler
 * @param oFromByteCount        Number of bytes returned from the scaler
 *
 * @return pointer to data returned by the scaler
 */
void *XSTScalerControl(Display   *dpy,
		       XSTTypeEnv iEnv,
                       XSTScaler  iScaler,
                       void      *iToScaler,
                       XSTCount   iToByteCount,
                       XSTCount  *oFromByteCount);

/**
 * @}
 */
#endif
