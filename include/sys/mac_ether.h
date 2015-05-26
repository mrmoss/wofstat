/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_MAC_ETHER_H
#define	_SYS_MAC_ETHER_H

#pragma ident	"@(#)mac_ether.h	1.1	07/02/02 SMI"

/*
 * Ethernet MAC Plugin
 */

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	_KERNEL

#define	MAC_PLUGIN_IDENT_ETHER	"mac_ether"

enum ether_stat {
	/* RFC 1643 stats */
	ETHER_STAT_ALIGN_ERRORS = MACTYPE_STAT_MIN,
	ETHER_STAT_FCS_ERRORS,
	ETHER_STAT_FIRST_COLLISIONS,
	ETHER_STAT_MULTI_COLLISIONS,
	ETHER_STAT_SQE_ERRORS,
	ETHER_STAT_DEFER_XMTS,
	ETHER_STAT_TX_LATE_COLLISIONS,
	ETHER_STAT_EX_COLLISIONS,
	ETHER_STAT_MACXMT_ERRORS,
	ETHER_STAT_CARRIER_ERRORS,
	ETHER_STAT_TOOLONG_ERRORS,
	ETHER_STAT_MACRCV_ERRORS,

	/* MII/GMII stats */
	ETHER_STAT_XCVR_ADDR,
	ETHER_STAT_XCVR_ID,
	ETHER_STAT_XCVR_INUSE,
	ETHER_STAT_CAP_1000FDX,
	ETHER_STAT_CAP_1000HDX,
	ETHER_STAT_CAP_100FDX,
	ETHER_STAT_CAP_100HDX,
	ETHER_STAT_CAP_10FDX,
	ETHER_STAT_CAP_10HDX,
	ETHER_STAT_CAP_ASMPAUSE,
	ETHER_STAT_CAP_PAUSE,
	ETHER_STAT_CAP_AUTONEG,
	ETHER_STAT_ADV_CAP_1000FDX,
	ETHER_STAT_ADV_CAP_1000HDX,
	ETHER_STAT_ADV_CAP_100FDX,
	ETHER_STAT_ADV_CAP_100HDX,
	ETHER_STAT_ADV_CAP_10FDX,
	ETHER_STAT_ADV_CAP_10HDX,
	ETHER_STAT_ADV_CAP_ASMPAUSE,
	ETHER_STAT_ADV_CAP_PAUSE,
	ETHER_STAT_ADV_CAP_AUTONEG,
	ETHER_STAT_LP_CAP_1000FDX,
	ETHER_STAT_LP_CAP_1000HDX,
	ETHER_STAT_LP_CAP_100FDX,
	ETHER_STAT_LP_CAP_100HDX,
	ETHER_STAT_LP_CAP_10FDX,
	ETHER_STAT_LP_CAP_10HDX,
	ETHER_STAT_LP_CAP_ASMPAUSE,
	ETHER_STAT_LP_CAP_PAUSE,
	ETHER_STAT_LP_CAP_AUTONEG,
	ETHER_STAT_LINK_ASMPAUSE,
	ETHER_STAT_LINK_PAUSE,
	ETHER_STAT_LINK_AUTONEG,
	ETHER_STAT_LINK_DUPLEX
};

#define	ETHER_NSTAT	(ETHER_STAT_LINK_DUPLEX - ETHER_STAT_ALIGN_ERRORS + 1)

#define	ETHER_STAT_ISACOUNTER(_ether_stat)				\
	    ((_ether_stat) == ETHER_STAT_ALIGN_ERRORS ||		\
		(_ether_stat) == ETHER_STAT_FCS_ERRORS ||		\
		(_ether_stat) == ETHER_STAT_FIRST_COLLISIONS ||		\
		(_ether_stat) == ETHER_STAT_MULTI_COLLISIONS ||		\
		(_ether_stat) == ETHER_STAT_SQE_ERRORS ||		\
		(_ether_stat) == ETHER_STAT_DEFER_XMTS ||		\
		(_ether_stat) == ETHER_STAT_TX_LATE_COLLISIONS ||	\
		(_ether_stat) == ETHER_STAT_EX_COLLISIONS ||		\
		(_ether_stat) == ETHER_STAT_MACXMT_ERRORS ||		\
		(_ether_stat) == ETHER_STAT_CARRIER_ERRORS ||		\
		(_ether_stat) == ETHER_STAT_TOOLONG_ERRORS ||		\
		(_ether_stat) == ETHER_STAT_MACRCV_ERRORS)

/*
 * Some drivers have a need to determine if a particular stat is a MII/GMII
 * physical layer 802.3 stat.
 */
#define	ETHER_STAT_ISMII(_ether_stat)					\
	((_ether_stat) == ETHER_STAT_XCVR_ADDR ||			\
	    (_ether_stat) == ETHER_STAT_XCVR_ID ||			\
	    (_ether_stat) == ETHER_STAT_XCVR_INUSE ||			\
	    (_ether_stat) == ETHER_STAT_CAP_1000FDX ||			\
	    (_ether_stat) == ETHER_STAT_CAP_1000HDX ||			\
	    (_ether_stat) == ETHER_STAT_CAP_100FDX ||			\
	    (_ether_stat) == ETHER_STAT_CAP_100HDX ||			\
	    (_ether_stat) == ETHER_STAT_CAP_10FDX ||			\
	    (_ether_stat) == ETHER_STAT_CAP_10HDX ||			\
	    (_ether_stat) == ETHER_STAT_CAP_ASMPAUSE ||			\
	    (_ether_stat) == ETHER_STAT_CAP_PAUSE ||			\
	    (_ether_stat) == ETHER_STAT_CAP_AUTONEG ||			\
	    (_ether_stat) == ETHER_STAT_ADV_CAP_1000FDX ||		\
	    (_ether_stat) == ETHER_STAT_ADV_CAP_1000HDX ||		\
	    (_ether_stat) == ETHER_STAT_ADV_CAP_100FDX ||		\
	    (_ether_stat) == ETHER_STAT_ADV_CAP_100HDX ||		\
	    (_ether_stat) == ETHER_STAT_ADV_CAP_10FDX ||		\
	    (_ether_stat) == ETHER_STAT_ADV_CAP_10HDX ||		\
	    (_ether_stat) == ETHER_STAT_ADV_CAP_ASMPAUSE ||		\
	    (_ether_stat) == ETHER_STAT_ADV_CAP_PAUSE ||		\
	    (_ether_stat) == ETHER_STAT_ADV_CAP_AUTONEG ||		\
	    (_ether_stat) == ETHER_STAT_LP_CAP_1000FDX ||		\
	    (_ether_stat) == ETHER_STAT_LP_CAP_1000HDX ||		\
	    (_ether_stat) == ETHER_STAT_LP_CAP_100FDX ||		\
	    (_ether_stat) == ETHER_STAT_LP_CAP_100HDX ||		\
	    (_ether_stat) == ETHER_STAT_LP_CAP_10FDX ||			\
	    (_ether_stat) == ETHER_STAT_LP_CAP_10HDX ||			\
	    (_ether_stat) == ETHER_STAT_LP_CAP_ASMPAUSE ||		\
	    (_ether_stat) == ETHER_STAT_LP_CAP_PAUSE ||			\
	    (_ether_stat) == ETHER_STAT_LP_CAP_AUTONEG ||		\
	    (_ether_stat) == ETHER_STAT_LINK_ASMPAUSE ||		\
	    (_ether_stat) == ETHER_STAT_LINK_PAUSE ||			\
	    (_ether_stat) == ETHER_STAT_LINK_AUTONEG ||			\
	    (_ether_stat) == ETHER_STAT_LINK_DUPLEX)

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_MAC_ETHER_H */
