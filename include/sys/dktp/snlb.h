/*
 * Copyright (c) 1999-2001 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef _SYS_DKTP_SNLB_H
#define	_SYS_DKTP_SNLB_H

#pragma ident	"@(#)snlb.h	1.10	01/04/04 SMI"

#include <sys/dklabel.h>
#include <sys/dktp/altsctr.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	SNVTOC		DK_LABEL_LOC

#define	SNDKMAP		NDKMAP
#define	SNUSLICE_WHOLE	2
#define	SNFPART_WHOLE	0

struct	sn_lbdata {
	daddr_t		s_ustart;
	long		s_capacity;
	struct	dk_label s_dklb;
	struct	partition s_fpart[SNDKMAP];
	long		 *s_alts_altcount;
	struct	alts_ent **s_alts_firstalt;
	struct	alts_ent *s_alts_enttbl;	/* alternate sectors	*/
	long		s_alts_entused;
	tgdk_iob_handle	s_hdl_enttbl;
};

struct	sn_label {
	struct dklb_ext	*s_extp;
	opaque_t	s_dkobjp;
	kmutex_t	s_mutex;
	krwlock_t	s_rw_mutex;
	struct sn_lbdata s_data;
	struct	bbh_obj s_bbh;
	dev_t		s_dev;			/* so snlb can create prop */
	dev_info_t 	*s_dip;			/* ditto */
	ddi_devid_t	s_devid;
	int		s_flags;
};

/*
 * Bits in s_flags
 */
#define	SNLB_HWID	0x1	/* disk has a hardware devid */
#define	SNLB_FABID	0x2	/* disk has a fabricated devid */

#define	SNLB_PART(dev) (getminor((dev)) & (SNDKMAP|(SNDKMAP-1)))

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DKTP_SNLB_H */
