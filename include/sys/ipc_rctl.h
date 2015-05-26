/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_IPC_RCTL_H
#define	_SYS_IPC_RCTL_H

#pragma ident	"@(#)ipc_rctl.h	1.1	07/02/07 SMI"

#include <sys/rctl.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct ipc_rqty {		/* datum protected by:	*/
	rctl_qty_t	ipcq_shmmni;	/* shm's ipcs_lock	*/
	rctl_qty_t	ipcq_semmni;	/* sem's ipcs_lock	*/
	rctl_qty_t	ipcq_msgmni;	/* msg's ipcs_lock	*/
} ipc_rqty_t;

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_IPC_RCTL_H */
