/*
 * Copyright  2001, 2002, Sun Microsystems, Inc.
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

/* @(#)Xst_string.h	1.10 04/07/27 SMI */

#ifndef _XSTSTRING_H
#define _XSTSTRING_H

/******************************** XSTString General Defines *************************/

/******************************* XSTConv Function Prototypes ************************/

/** @defgroup String XSTString functions
 * @{
 */

/**
 * Returns the number of bytes in iString
 *
 * @param iString		pointer to string of characters
 * @param iEnc			Encoding of string. see Xst_enum.h for encoding types
 * @param iNumCharacters	Number of characters in the string.
 *
 * @return number of bytes
 */
XSTCount XSTStringCountBytes(char       *iString, 
		             XSTCount    iNumCharacters,
		             XSTEncoding iEnc);


/**
 * Returns the number of characters in iString
 *
 * @param iString		pointer to string of characters
 * @param iEnc			Encoding of string. see Xst_enum.h for encoding types
 * @param iNumBytes		Number of bytes in the string.
 *
 * @return number of characters
 */
XSTCount XSTStringCountCharacters(char       *iString, 
			          XSTCount    iNumBytes,
			          XSTEncoding iEnc);

/** 
 * @}  
 */
#endif
