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

/* @(#)Xst_conv.h	1.18 04/04/13 SMI */

#ifndef _XSTCONV_H
#define _XSTCONV_H

#include "Xst_typedef.h"
#include "Xst_string.h"

#define XST_DEFAULT_LOCALE	"en_US.UTF-8"

/********************************* XSTConv General Defines **************************/

/******************************* XSTConv Function Prototypes ************************/
#ifndef XST_LANG_STRUCT_ONLY


void *_XSTConvUTF16toX ( char *iToCode, 
                         char *iString, 
                         XSTCount iStringLength,
                         XSTCount *oStringLength );

utf16 *_XSTConvXtoUTF16 ( char *iFromCode, 
                          char *iString, 
                          XSTCount iStringLength, 
                          XSTCount *oStringLength);

void _XSTConvIconvClose ();

char *_XSTConvGetFromCodeWLocale ( char *iLocale );
char *_XSTConvGetFromCodeWEncoding ( XSTEncoding iEnc );

XSTCount _XSTConvGetBytesPerCharacter ( char *iFromCode );

XSTEncoding _XSTConvGetEncoding	( char *iFromCode );

int _XSTConvGetPModified ();

XSTLocale _XSTConvGetLocale ( char *iFromCode );

XSTEncoding _XSTConvGetEncoding ( char *iLocale );

XSTEncoding _XSTGetEncoding ( char *);
#endif
#endif
