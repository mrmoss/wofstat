/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_SYSDC_H
#define	_SYS_SYSDC_H

#pragma ident	"@(#)sysdc.h	1.1	10/03/12 SMI"

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

struct _kthread;

#define	SYSDC_THREAD_BATCH	0x1	/* thread does batch processing */
extern void sysdc_thread_enter(struct _kthread *, uint_t, uint_t);

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SYSDC_H */
