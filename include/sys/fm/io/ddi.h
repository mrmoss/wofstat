/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_FM_IO_DDI_H
#define	_SYS_FM_IO_DDI_H

#pragma ident	"@(#)ddi.h	1.4	10/01/01 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#define	DDI_DVR_MAX_CLASS		32

/* IO-specific FMA ereport class defintions */
#define	DDI_IO_CLASS			"io"

/* leaf driver detected ereport definitions */
#define	DDI_FM_DEVICE			"device"
#define	DDI_FM_DEVICE_INVAL_STATE	"inval_state"
#define	DDI_FM_DEVICE_NO_RESPONSE	"no_response"
#define	DDI_FM_DEVICE_STALL		"stall"
#define	DDI_FM_DEVICE_BADINT_LIMIT	"badint_limit"
#define	DDI_FM_DEVICE_INTERN_CORR	"intern_corr"
#define	DDI_FM_DEVICE_INTERN_UNCORR	"intern_uncorr"
#define	DDI_FM_DEVICE_FW_CORRUPT	"fw_corrupt"
#define	DDI_FM_DEVICE_FW_MISMATCH	"fw_mismatch"

/* service impact ereport definitions */
#define	DDI_FM_SERVICE_IMPACT		"service"
#define	DDI_FM_SERVICE_LOST		"lost"
#define	DDI_FM_SERVICE_DEGRADED		"degraded"
#define	DDI_FM_SERVICE_RESTORED		"restored"
#define	DDI_FM_SERVICE_UNAFFECTED	"unaffected"

/* Driver defect ereport specifications */
#define	DVR_ERPT		"ddi."
#define	DVR_ECONTEXT		"context"	/* Invalid calling context */
#define	DVR_EINVAL		"einval"	/* Invalid calling semantic */
#define	DVR_EFMCAP		"fm-capability"	/* Improper FM capability */
#define	DVR_EVER		"version"	/* Invalid structure version */

/* Required payload member names */
#define	DVR_NAME		"dvr-name"
#define	DVR_STACK		"dvr-stack"
#define	DVR_STACK_DEPTH		"dvr-stack-depth"
#define	DVR_ERR_SPECIFIC	"dvr-error-specific"

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_FM_IO_DDI_H */
