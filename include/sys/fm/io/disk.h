/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_FM_IO_DISK_H
#define	_SYS_FM_IO_DISK_H

#pragma ident	"@(#)disk.h	1.1	08/01/21 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#define	DISK_ERROR_CLASS		"io.disk"

#define	FM_FAULT_DISK_PREDFAIL		"predictive-failure"
#define	FM_FAULT_DISK_OVERTEMP		"over-temperature"
#define	FM_FAULT_DISK_TESTFAIL		"self-test-failure"

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_FM_IO_DISK_H */
