/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_FIBRE_CHANNEL_FC_TYPES_H
#define	_SYS_FIBRE_CHANNEL_FC_TYPES_H

#pragma ident	"@(#)fc_types.h	1.9	04/02/19 SMI"

/*
 * Types for FC Transport subsystems.
 *
 * This file picks up specific as well as generic type
 * defines, and also serves as a wrapper for many common
 * includes.
 */

#include <sys/types.h>
#include <sys/param.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(_BIT_FIELDS_LTOH) && !defined(_BIT_FIELDS_HTOL)
#error	One of _BIT_FIELDS_LTOH or _BIT_FIELDS_HTOL must be defined
#endif	/* _BIT_FIELDS_LTOH */

#ifdef	_KERNEL
#include <sys/systm.h>
#include <sys/cmn_err.h>
#include <sys/debug.h>
#include <sys/devops.h>
#include <sys/callb.h>
#include <sys/disp.h>
#include <sys/taskq.h>
#endif	/* _KERNEL */

#ifndef	_SYS_SCSI_SCSI_TYPES_H


#ifdef	__STDC__
typedef void *opaque_t;
#else	/* __STDC__ */
typedef char *opaque_t;
#endif	/* __STDC__ */

#endif /* _SYS_SCSI_SCSI_TYPES_H */

/* Sysevent defs */
#define	EC_SUNFC		"EC_sunfc"
#define	ESC_SUNFC_PORT_ATTACH	"ESC_sunfc_port_attach"
#define	ESC_SUNFC_PORT_DETACH	"ESC_sunfc_port_detach"
#define	ESC_SUNFC_PORT_ONLINE	"ESC_sunfc_port_online"
#define	ESC_SUNFC_PORT_OFFLINE	"ESC_sunfc_port_offline"
#define	ESC_SUNFC_PORT_RSCN	"ESC_sunfc_port_rscn"
#define	ESC_SUNFC_TARGET_ADD	"ESC_sunfc_target_add"
#define	ESC_SUNFC_TARGET_REMOVE	"ESC_sunfc_target_remove"

/* T11 FC-HBA state change tracking */
typedef uint64_t    fc_hba_state_change_t;

typedef struct port_id {
#if	defined(_BIT_FIELDS_LTOH)
	uint32_t	port_id : 24,		/* Port Identifier */
			priv_lilp_posit : 8;	/* LILP map position */
#else
	uint32_t	priv_lilp_posit : 8,	/* LILP map position */
			port_id : 24;		/* Port Identifier */
#endif	/* _BIT_FIELDS_LTOH */
} fc_portid_t;

typedef struct hard_addr {
#if	defined(_BIT_FIELDS_LTOH)
	uint32_t	hard_addr : 24,		/* hard address */
			rsvd : 8;		/* reserved */
#else
	uint32_t	rsvd : 8,
			hard_addr : 24;		/* hard address */
#endif	/* _BIT_FIELDS_LTOH */
} fc_hardaddr_t;

typedef struct port_type {
#if defined(_BIT_FIELDS_LTOH)
	uint32_t	rsvd   		: 24,
			port_type	: 8;
#else
	uint32_t	port_type   	: 8,
			rsvd		: 24;
#endif	/* _BIT_FIELDS_LTOH */
} fc_porttype_t;

/*
 * FCA post reset behavior
 */
typedef enum fc_reset_action {
	FC_RESET_RETURN_NONE,		/* Can't return any */
	FC_RESET_RETURN_ALL,		/* Return all commands reached here */
	FC_RESET_RETURN_OUTSTANDING	/* Return ones that haven't gone out */
} fc_reset_action_t;

/*
 * FCA DMA behavior on Unaligned buffers
 */
typedef enum fc_dma_behavior {
	FC_ALLOW_STREAMING,		/* Streaming mode for all xfers */
	FC_NO_STREAMING			/* Disable Streaming on unaligned */
					/* buffer or byte counts */
} fc_dma_behavior_t;


/*
 * FCA FCP command and response allocation in DVMA space
 */
typedef enum fc_fcp_dma {
	FC_DVMA_SPACE,			/* allocation should be in DVMA mem */
	FC_NO_DVMA_SPACE		/* allocation shouldn't be DVMA mem */
} fc_fcp_dma_t;


/*
 * FC Transport exported header files to all Consumers
 */

#ifdef	_KERNEL
#include <sys/fibre-channel/impl/fcph.h>
#include <sys/fibre-channel/fc_appif.h>
#include <sys/fibre-channel/impl/fc_linkapp.h>
#include <sys/fibre-channel/impl/fcgs2.h>
#include <sys/fibre-channel/impl/fc_fla.h>
#include <sys/fibre-channel/impl/fcal.h>
#include <sys/fibre-channel/impl/fctl.h>
#include <sys/fibre-channel/impl/fc_error.h>
#endif	/* _KERNEL */

/*
 * For drivers which do not include these - must be last
 */
#ifdef	_KERNEL
#include <sys/ddi.h>
#include <sys/sunddi.h>
#include <sys/stat.h>
#include <sys/sunndi.h>
#include <sys/devctl.h>
#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_FIBRE_CHANNEL_FC_TYPES_H */
