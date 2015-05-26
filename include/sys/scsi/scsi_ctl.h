/*
 * Copyright (c) 2006, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_SCSI_SCSI_CTL_H
#define	_SYS_SCSI_SCSI_CTL_H

#pragma ident	"@(#)scsi_ctl.h	1.24	11/03/04 SMI"

#include <sys/scsi/scsi_types.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * SCSI Control Information
 *
 * Defines for stating level of reset.
 * RESET_ALL, RESET_TARGET, and RESET_LUN defined for tran_reset (invoked
 * by target/ioctl)
 * RESET_BUS defined for tran_bus_reset (invoked by ioctl)
 */

#define	RESET_ALL	0	/* reset SCSI bus, host adapter, everything */
#define	RESET_TARGET	1	/* reset SCSI target */
#define	RESET_BUS	2	/* reset SCSI bus only */
#define	RESET_LUN	3	/* reset SCSI logical unit */

/*
 * Defines for scsi_reset_notify flag, to register or cancel
 * the notification of external and internal SCSI bus resets.
 */
#define	SCSI_RESET_NOTIFY	0x01	/* register the reset notification */
#define	SCSI_RESET_CANCEL	0x02	/* cancel the reset notification */

/*
 * Define for scsi_get_name string length.
 * This is needed because MAXNAMELEN is not part of DDI.
 */
#define	SCSI_MAXNAMELEN		MAXNAMELEN

/*
 * Property for customizing hotplug procedure
 */
#define	SCSI_NO_QUIESCE	"scsi-no-quiesce"

#ifdef	_KERNEL

/*
 * Kernel function declarations
 */

/*
 * Capabilities functions
 */

#ifdef	__STDC__
extern int scsi_ifgetcap(struct scsi_address *ap, char *cap, int whom);
extern int scsi_ifsetcap(struct scsi_address *ap, char *cap, int value,
	int whom);
#else	/* __STDC__ */
extern int scsi_ifgetcap(), scsi_ifsetcap();
#endif	/* __STDC__ */

/*
 * Abort and Reset functions
 */

#ifdef	__STDC__
extern int scsi_abort(struct scsi_address *ap, struct scsi_pkt *pkt);
extern int scsi_reset(struct scsi_address *ap, int level);
extern int scsi_reset_notify(struct scsi_address *ap, int flag,
	void (*callback)(caddr_t), caddr_t arg);
extern int scsi_clear_task_set(struct scsi_address *ap);
extern int scsi_terminate_task(struct scsi_address *ap, struct scsi_pkt *pkt);
#else	/* __STDC__ */
extern int scsi_abort(), scsi_reset();
extern int scsi_reset_notify();
extern int scsi_clear_task_set();
extern int scsi_terminate_task();
#endif	/* __STDC__ */

/*
 * Other functions
 */

#ifdef	__STDC__
extern int scsi_clear_aca(struct scsi_address *ap);
extern int scsi_ua_get_reportdev(struct scsi_device *sd, char *ba, int len);
extern int scsi_ua_get(struct scsi_device *sd, char *ua, int len);
#else	/* __STDC__ */
extern int scsi_clear_aca();
extern int scsi_ua_get_reportdev();
extern int scsi_ua_get();
#endif	/* __STDC__ */

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SCSI_SCSI_CTL_H */
