/*
 * Copyright (c) 2001, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_SCSI_SCSI_PARAMS_H
#define	_SYS_SCSI_SCSI_PARAMS_H

#pragma ident	"@(#)scsi_params.h	1.16	11/03/04 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#define	NUM_SENSE_KEYS		16	/* total number of Sense keys */

#define	NTAGS			256	/* number of tags per lun */

/*
 * General parallel SCSI parameters
 */
#define	NTARGETS		8	/* total # of targets per SCSI bus */
#define	NTARGETS_WIDE		16	/* #targets per wide SCSI bus */
#define	NLUNS_PER_TARGET	8	/* number of luns per target */

/*
 * the following defines are useful for settings max LUNs in nexus/target
 * drivers
 */
#define	SCSI_16LUNS_PER_TARGET		16
#define	SCSI_32LUNS_PER_TARGET		32
#define	SCSI_1LUN_PER_TARGET		1
#define	SCSI_8LUN_PER_TARGET		NLUNS_PER_TARGET

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SCSI_SCSI_PARAMS_H */
