/*
 * Copyright 2001-2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_USB_CBI_H
#define	_SYS_USB_CBI_H

#pragma ident	"@(#)usb_cbi.h	1.2	02/05/15 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * This header file contains definitions used by
 * USB Mass Storage Class's CBI transport.
 */

/* CBI Class req */
#define	CBI_REQUEST_TYPE	(USB_DEV_REQ_HOST_TO_DEV | \
				USB_DEV_REQ_TYPE_CLASS | \
				USB_DEV_REQ_RCPT_IF)
#define	CBI_WVALUE		0x00	/* wValue: reserved to 00 */
#define	CBI_SELF_TEST		0x04	/* For Command Block Reset */
#define	CBI_CBR_VALUE		0xff	/* Command Block Reset value */
#define	CBI_CLASS_CMD_LEN	0x0C	/* Command len 12 bytes */

/*
 * CBI Command Block Status values
 */
#define	CBI_STATUS_PASS			0x0	/* Command passed */
#define	CBI_STATUS_FAILED		0x1	/* Command failed */
#define	CBI_STATUS_PHASE_ERR		0x2	/* Command has a phase error */
#define	CBI_STATUS_PERSISTENT_FAIL	0x3	/* Command fails persistently */
#define	CBI_STATUS_MASK			0x3	/* Command status MASK */


#ifdef __cplusplus
}
#endif

#endif	/* _SYS_USB_CBI_H */
