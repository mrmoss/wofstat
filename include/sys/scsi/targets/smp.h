/*
 * Copyright (c) 2006, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_SCSI_TARGETS_SMP_H
#define	_SYS_SCSI_TARGETS_SMP_H

#pragma ident	"@(#)smp.h	1.2	11/03/04 SMI"

#include <sys/types.h>
#include <sys/scsi/scsi.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if defined(_KERNEL)

/*
 * smp_open_flag: field indicating open smp instance.
 *	0 = closed, 1 = shared open, 2 = exclusive open.
 */
#define	SMP_CLOSED	0
#define	SMP_SOPENED	1
#define	SMP_EXOPENED	2

typedef struct smp_state {
	struct smp_device	*smp_sd;	/* pointer to smp_device */
	kmutex_t 		smp_mutex;	/* mutex */
	uint32_t 		smp_open_flag;	/* open flag */
	kcondvar_t		smp_cv;		/* condition variable */
	uint32_t		smp_busy;	/* busy */
} smp_state_t;

#define	SMP_ESTIMATED_NUM_DEVS	4		/* for soft-state allocation */
#define	SMP_DEFAULT_RETRY_TIMES	5

#define	SMP_FLAG_REQBUF		0x1
#define	SMP_FLAG_RSPBUF		0x2
#define	SMP_FLAG_XFER		0x4

#endif /* defined(_KERNEL) */


#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SCSI_TARGETS_SMP_H */
