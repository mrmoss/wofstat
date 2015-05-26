/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _STDIO_TAG_H
#define	_STDIO_TAG_H

#pragma ident	"@(#)stdio_tag.h	1.4	04/09/28 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef	__FILE_TAG
#if defined(__cplusplus) && !defined(__GNUC__) && (__cplusplus < 54321L)
#define	__FILE_TAG	FILE
#else
#define	__FILE_TAG	__FILE
#endif
typedef struct __FILE_TAG __FILE;
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _STDIO_TAG_H */
