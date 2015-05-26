/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_BL_H
#define	_SYS_BL_H

#pragma ident	"@(#)bl.h	1.2	04/12/28 SMI"

/*
 * The interfaces described below are private to FMA.
 */

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/processor.h>
#include <sys/fm/protocol.h>

#define	BLIOC_INSERT		(('B' << 8) | 0x01)
#define	BLIOC_DELETE		(('B' << 8) | 0x02)

typedef struct bl_req {
	caddr_t		bl_fmri;	/* buffer containing packed FMRI */
	size_t		bl_fmrisz;	/* size of packed FMRI */
	caddr_t		bl_class;	/* event class reason for blacklist */
} bl_req_t;

#if defined(_SYSCALL32)
typedef struct bl_req32 {
	caddr32_t	bl_fmri;
	size32_t	bl_fmrisz;
	caddr32_t	bl_class;
} bl_req32_t;
#endif	/* _SYSCALL32 */

#define	BL_FMRI_MAX_BUFSIZE	8192	/* maximum allowed packed FMRI size */

#ifdef _KERNEL

extern int blacklist(int, const char *, nvlist_t *, const char *);

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_BL_H */
