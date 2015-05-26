/*
 * Copyright (c) 1994, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_SCSI_IMPL_TYPES_H
#define	_SYS_SCSI_IMPL_TYPES_H

#pragma ident	"@(#)types.h	1.23	12/02/29 SMI"

/*
 * Local Types for SCSI subsystems
 */

#ifdef	_KERNEL

#include <sys/kmem.h>
#include <sys/map.h>
#include <sys/open.h>
#include <sys/uio.h>
#include <sys/sysmacros.h>

#include <sys/buf.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>

#include <sys/conf.h>

#include <sys/scsi/impl/services.h>
#include <sys/scsi/impl/transport.h>
#include <sys/scsi/impl/smp_transport.h>
#include <sys/scsi/impl/scsi_sas.h>
#include <sys/scsi/impl/scsi_obsolete.h>

#endif	/* _KERNEL */

#include <sys/scsi/impl/uscsi.h>

#endif	/* _SYS_SCSI_IMPL_TYPES_H */
