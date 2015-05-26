/*
 * Copyright (c) 1994, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_SCSI_IMPL_INQUIRY_H
#define	_SYS_SCSI_IMPL_INQUIRY_H

#pragma ident	"@(#)inquiry.h	1.9	11/03/04 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Implementation inquiry data that is not within
 * the scope of any released SCSI standard.
 */

/*
 * Minimum inquiry data length (includes up through RDF field)
 */

#define	SUN_MIN_INQLEN	4

/*
 * Inquiry data size definition
 */
#define	SUN_INQSIZE	(sizeof (struct scsi_inquiry))

/*
 * SCSI inquiry properties.  The following properties figuratively
 * represent 'inquiry' data.  Some of the values may be more detailed
 * (longer in length) than the basic 'struct scsi_inquiry' fields. For
 * example the INQUIRY_REVISION_ID field in 'struct scsi_inquiry' is
 * four bytes long, but SATA's 'Identify Device Data' is eight bytes.
 * In situations like this an HBA driver's tran_tgt_init(9E)
 * implementation may establish different, more detailed, values than
 * those returned by 'struct scsi_inquiry'.  In addition some
 * properties like 'serial number' and 'capacity' are never derived
 * from 'struct scsi_inquiry'.  Instead, the information is obtained
 * from an INQUIRY command to another page (page 0x80 for serial
 * number), by some other SCSI commands (like READ_CAPACITY for
 * capacity), or by some HBA driver specific mechanism.
 */
#define	INQUIRY_DEVICE_TYPE	"inquiry-device-type"	/* int */
#define	INQUIRY_VENDOR_ID	"inquiry-vendor-id"	/* string */
#define	INQUIRY_PRODUCT_ID	"inquiry-product-id"	/* string */
#define	INQUIRY_REVISION_ID	"inquiry-revision-id"	/* string */
#define	INQUIRY_SERIAL_NO	"inquiry-serial-no"	/* string */

#ifdef  _KERNEL
int	scsi_ascii_inquiry_len(char *field, size_t length);
#endif  /* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SCSI_IMPL_INQUIRY_H */
