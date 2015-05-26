/*
 * Copyright (c) 2000-2001 by Sun Microsystems, Inc.
 * All rights reserved.
 *
 * This header file defines the public interfaces for the default
 * audio mixer sample rate converter.
 *
 * CAUTION: This header file has not gone through a formal review process.
 *	Thus its commitment level is very low and may change or be removed
 *	at any time.
 */

#ifndef	_SYS_AM_SRC1_H
#define	_SYS_AM_SRC1_H

#pragma ident	"@(#)am_src1.h	1.3	01/01/10 SMI"

#ifdef	__cplusplus
extern "C" {
#endif


#define	AM_SRC1_MOD_NAME	"Audio Sample Rate Conv. #1"

#ifdef _KERNEL

/*
 * am_ad_src1_info_t	- mixer mode Audio Driver sample rate conversion #1 info
 */
struct am_ad_src1_info {
	uint_t		ad_from_sr;	/* going from this sample rate */
	uint_t		ad_to_sr;	/* to this sample rate */
	uint_t		ad_nconv;	/* number of conversions */
	uint_t		ad_u0;		/* up conversion parameter #1 */
	uint_t		ad_u1;		/* up conversion parameter #2 */
	uint_t		ad_u2;		/* up conversion parameter #3 */
	uint_t		ad_u3;		/* up conversion parameter #4 */
	uint_t		ad_d0;		/* conversion parameter #1 */
	uint_t		ad_d1;		/* conversion parameter #2 */
	uint_t		ad_d2;		/* conversion parameter #3 */
	uint_t		ad_d3;		/* conversion parameter #4 */
	uint_t		ad_k;		/* filter shift */
};
typedef struct am_ad_src1_info am_ad_src1_info_t;

#define	AM_SRC1_FILTER		0x40000000	/* filter if ORed with ad_p?? */

extern am_ad_src_entry_t am_src1;	/* sample rate conversion routine #1 */

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_AM_SRC1_H */
