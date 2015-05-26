/*
 * Copyright 2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _IPP_DLCOSMK_DLCOSMK_H
#define	_IPP_DLCOSMK_DLCOSMK_H

#pragma ident	"@(#)dlcosmk.h	1.1	02/02/26 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Header file for DL CoS marker -- marks 802.1d user priority field on
 * VLAN devices
 */

#define	DLCOSMK_NEXT_ACTION_NAME	"dlcosmk.next_action"	/* string */
#define	DLCOSMK_COS			"dlcosmk.cos" 		/* uint8 */
#define	DLCOSMK_BAND			"dlcosmk.bband" 	/* uint8 */
#define	DLCOSMK_PRI			"dlcosmk.dlpri" 	/* uint8 */

#ifdef	__cplusplus
}
#endif

#endif /* _IPP_DLCOSMK_DLCOSMK_H */
