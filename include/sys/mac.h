/*
 * Copyright (c) 2005, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_MAC_H
#define	_SYS_MAC_H

#pragma ident	"@(#)mac.h	1.15	11/09/21 SMI"

#include <sys/types.h>
#include <sys/ddi.h>
#include <sys/sunddi.h>
#include <sys/stream.h>

/*
 * MAC Services Module
 */

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * MAC-Type version identifier.  This is used by mactype_alloc() and
 * mactype_register() to verify that incompatible MAC-Type plugins don't
 * register.
 */
#define	MACTYPE_VERSION	0x1

typedef	struct __mac_ring_driver	*mac_ring_driver_t;
typedef	struct __mac_ring_handle	*mac_ring_handle_t;
typedef	struct __mac_group_driver	*mac_group_driver_t;
typedef	struct __mac_group_handle	*mac_group_handle_t;
typedef	struct __mac_intr_handle	*mac_intr_handle_t;

typedef enum {
	LINK_STATE_UNKNOWN = -1,
	LINK_STATE_DOWN,
	LINK_STATE_UP
} link_state_t;

typedef enum {
	LINK_DUPLEX_UNKNOWN = 0,
	LINK_DUPLEX_HALF,
	LINK_DUPLEX_FULL
} link_duplex_t;

typedef enum {
	LINK_FLOWCTRL_NONE = 0,
	LINK_FLOWCTRL_RX,
	LINK_FLOWCTRL_TX,
	LINK_FLOWCTRL_BI
} link_flowctrl_t;

typedef enum {
	LINK_TAGMODE_VLANONLY = 0,
	LINK_TAGMODE_NORMAL
} link_tagmode_t;

/*
 * Defines range of uint32_t values
 */
typedef struct mac_propval_uint32_range_s {
	uint32_t mpur_min;
	uint32_t mpur_max;
} mac_propval_uint32_range_t;

/*
 * Data type of property values.
 */
typedef enum {
	MAC_PROPVAL_UINT8,
	MAC_PROPVAL_UINT32,
	MAC_PROPVAL_STR
} mac_propval_type_t;

/*
 * Captures possible values for a given property. A property can have
 * range of values (int32, int64, uint32, uint64, et al) or collection/
 * enumeration of values (strings).
 * Can be used as a value-result parameter.
 */
typedef struct mac_propval_range_s {
	uint_t			mpr_count;	/* count of ranges */
	mac_propval_type_t	mpr_type;	/* type of value */
	union {
		mac_propval_uint32_range_t mpr_uint32[1];
		int a;

	} u1;
} mac_propval_range_t;

#define	mpr_range_uint32	u1.mpr_uint32

/*
 * Maximum MAC address length
 */
#define	MAXMACADDRLEN	20

#define	MAXLINKPROPNAME 256

/*
 * Public properties.
 * Some of the properties below are defined to maintain compatibility with
 * Opensolaris drivers. Those properties are not valid for solaris based
 * drivers. Please look at man mac(9E) to find which properties are valid
 * for Solaris driver.
 *
 * Note that there are 2 sets of parameters: the *_EN_* values are
 * those that the Administrator configures for autonegotiation. The
 * _ADV_* values are those that are currently exposed over the wire.
 */
typedef enum {
	MAC_PROP_DUPLEX = 0x00000001,
	MAC_PROP_SPEED,
	MAC_PROP_STATUS,
	MAC_PROP_AUTONEG,
	MAC_PROP_EN_AUTONEG,
	MAC_PROP_MTU,
	MAC_PROP_ZONE,
	MAC_PROP_AUTOPUSH,
	MAC_PROP_FLOWCTRL,
	MAC_PROP_ADV_1000FDX_CAP,
	MAC_PROP_EN_1000FDX_CAP,
	MAC_PROP_ADV_1000HDX_CAP,
	MAC_PROP_EN_1000HDX_CAP,
	MAC_PROP_ADV_100FDX_CAP,
	MAC_PROP_EN_100FDX_CAP,
	MAC_PROP_ADV_100HDX_CAP,
	MAC_PROP_EN_100HDX_CAP,
	MAC_PROP_ADV_10FDX_CAP,
	MAC_PROP_EN_10FDX_CAP,
	MAC_PROP_ADV_10HDX_CAP,
	MAC_PROP_EN_10HDX_CAP,
	MAC_PROP_ADV_100T4_CAP,
	MAC_PROP_EN_100T4_CAP,
	MAC_PROP_IPTUN_HOPLIMIT,
	MAC_PROP_IPTUN_ENCAPLIMIT,
	MAC_PROP_WL_ESSID,
	MAC_PROP_WL_BSSID,
	MAC_PROP_WL_BSSTYPE,
	MAC_PROP_WL_LINKSTATUS,
	MAC_PROP_WL_DESIRED_RATES,
	MAC_PROP_WL_SUPPORTED_RATES,
	MAC_PROP_WL_AUTH_MODE,
	MAC_PROP_WL_ENCRYPTION,
	MAC_PROP_WL_RSSI,
	MAC_PROP_WL_PHY_CONFIG,
	MAC_PROP_WL_CAPABILITY,
	MAC_PROP_WL_WPA,
	MAC_PROP_WL_SCANRESULTS,
	MAC_PROP_WL_POWER_MODE,
	MAC_PROP_WL_RADIO,
	MAC_PROP_WL_ESS_LIST,
	MAC_PROP_WL_KEY_TAB,
	MAC_PROP_WL_CREATE_IBSS,
	MAC_PROP_WL_SETOPTIE,
	MAC_PROP_WL_DELKEY,
	MAC_PROP_WL_KEY,
	MAC_PROP_WL_MLME,
	MAC_PROP_TAGMODE,
	MAC_PROP_ADV_10GFDX_CAP,
	MAC_PROP_EN_10GFDX_CAP,
	MAC_PROP_PVID,
	MAC_PROP_LLIMIT,
	MAC_PROP_LDECAY,
	MAC_PROP_RESOURCE,
	MAC_PROP_RESOURCE_EFF,
	MAC_PROP_RXRINGSRANGE,
	MAC_PROP_TXRINGSRANGE,
	MAC_PROP_MAX_TX_RINGS_AVAIL,
	MAC_PROP_MAX_RX_RINGS_AVAIL,
	MAC_PROP_MAX_RXHWCLNT_AVAIL,
	MAC_PROP_MAX_TXHWCLNT_AVAIL,
	MAC_PROP_PRIVATE = -1,
	MAC_DERIVED_PROP = -2
} mac_prop_id_t;

/*
 * Flags to figure out r/w status of legacy ndd props.
 */
#define	MAC_PROP_PERM_READ		0x0001
#define	MAC_PROP_PERM_WRITE		0x0010
#define	MAC_PROP_MAP_KSTAT		0x0100
#define	MAC_PROP_PERM_RW		(MAC_PROP_PERM_READ|MAC_PROP_PERM_WRITE)
#define	MAC_PROP_FLAGS_RK		(MAC_PROP_PERM_READ|MAC_PROP_MAP_KSTAT)

#ifdef	_KERNEL

/*
 * Opaque handle types.
 */
typedef	struct mac_t			*mac_handle_t;
typedef struct __mac_notify_handle	*mac_notify_handle_t;
typedef struct __mac_rx_handle		*mac_rx_handle_t;
typedef struct __mac_txloop_handle	*mac_txloop_handle_t;
typedef struct __mac_resource_handle	*mac_resource_handle_t;

/*
 * Provide mapping for legacy ndd ioctls relevant to that mactype.
 * Note that the ndd ioctls are obsolete, and may be removed in a future
 * release of Solaris. The ndd ioctls are not typically used in legacy
 * ethernet drivers. New datalink drivers of all link-types should use
 * dladm(1m) interfaces for administering tunables and not have to provide
 * a mapping.
 */

typedef	int (*prop_func_t)(mac_handle_t, char *, int, long, void *);

typedef struct mac_ndd_mapping_s {
	char		*mp_name;
	union {
		mac_prop_id_t	u_id;
		uint_t		u_kstat;
		int		u_derived;
	} u_mp_id;
	prop_func_t	mp_func;
	long		mp_minval;
	long		mp_maxval;
	size_t		mp_valsize;
	int		mp_flags;
} mac_ndd_mapping_t;

#define	mp_prop_id	u_mp_id.u_id
#define	mp_kstat	u_mp_id.u_kstat
#define	mp_derived	u_mp_id.u_derived

typedef struct mac_stat_info_s {
	uint_t		msi_stat;
	char		*msi_name;
	uint_t		msi_type;	/* as defined in kstat_named_init(9F) */
	uint64_t	msi_default;
} mac_stat_info_t;

/*
 * There are three ranges of statistics values.  0 to 1 - MAC_STAT_MIN are
 * interface statistics maintained by the mac module.  MAC_STAT_MIN to 1 -
 * MACTYPE_STAT_MIN are common MAC statistics defined by the mac module and
 * maintained by each driver.  MACTYPE_STAT_MIN and above are statistics
 * defined by MAC-Type plugins and maintained by each driver.
 */
#define	MAC_STAT_MIN		1000
#define	MACTYPE_STAT_MIN	2000

#define	IS_MAC_STAT(stat)	\
	(stat >= MAC_STAT_MIN && stat < MACTYPE_STAT_MIN)
#define	IS_MACTYPE_STAT(stat)	(stat >= MACTYPE_STAT_MIN)

/*
 * Statistics maintained by the mac module, and possibly populated as link
 * statistics.
 */
enum mac_mod_stat {
	MAC_STAT_LINK_STATE,
	MAC_STAT_LINK_UP,
	MAC_STAT_PROMISC
};

enum mac_driver_stat {
	/* MIB-II stats (RFC 1213 and RFC 1573) */
	MAC_STAT_IFSPEED = MAC_STAT_MIN,
	MAC_STAT_MULTIRCV,
	MAC_STAT_BRDCSTRCV,
	MAC_STAT_MULTIXMT,
	MAC_STAT_BRDCSTXMT,
	MAC_STAT_NORCVBUF,
	MAC_STAT_IERRORS,
	MAC_STAT_UNKNOWNS,
	MAC_STAT_NOXMTBUF,
	MAC_STAT_OERRORS,
	MAC_STAT_COLLISIONS,
	MAC_STAT_RBYTES,
	MAC_STAT_IPACKETS,
	MAC_STAT_OBYTES,
	MAC_STAT_OPACKETS
};

#define	MAC_NSTAT	(MAC_STAT_OPACKETS - MAC_STAT_IFSPEED + 1)

#define	MAC_STAT_ISACOUNTER(_stat) (		\
	    (_stat) == MAC_STAT_MULTIRCV ||	\
	    (_stat) == MAC_STAT_BRDCSTRCV ||	\
	    (_stat) == MAC_STAT_MULTIXMT ||	\
	    (_stat) == MAC_STAT_BRDCSTXMT ||	\
	    (_stat) == MAC_STAT_NORCVBUF ||	\
	    (_stat) == MAC_STAT_IERRORS ||	\
	    (_stat) == MAC_STAT_UNKNOWNS ||	\
	    (_stat) == MAC_STAT_NOXMTBUF ||	\
	    (_stat) == MAC_STAT_OERRORS ||	\
	    (_stat) == MAC_STAT_COLLISIONS ||	\
	    (_stat) == MAC_STAT_RBYTES ||	\
	    (_stat) == MAC_STAT_IPACKETS ||	\
	    (_stat) == MAC_STAT_OBYTES ||	\
	    (_stat) == MAC_STAT_OPACKETS)

/*
 * Immutable information. (This may not be modified after registration).
 */
typedef struct mac_info_s {
	uint_t		mi_media;
	uint_t		mi_sdu_min;
	uint_t		mi_sdu_max;
	uint_t		mi_addr_length;
	uint8_t		*mi_unicst_addr;
	uint8_t		*mi_brdcst_addr;
} mac_info_t;

typedef int mac_addr_slot_t;

/*
 * Multiple Rings capability
 */
typedef enum {
	MAC_RING_TYPE_RX	= 1,	/* Receive ring */
	MAC_RING_TYPE_TX	= 2	/* Transmit ring */
} mac_ring_type_t;

/*
 * Grouping type of a ring group
 *
 * MAC_GROUP_TYPE_STATIC: The ring group can not be re-grouped.
 * MAC_GROUP_TYPE_DYNAMIC: The ring group support dynamic re-grouping
 */
typedef enum {
	MAC_GROUP_TYPE_STATIC	= 1,	/* Static ring group */
	MAC_GROUP_TYPE_DYNAMIC	= 2	/* Dynamic ring group */
} mac_group_type_t;

typedef	int	(*mac_intr_enable_t)(mac_intr_handle_t);
typedef	int	(*mac_intr_disable_t)(mac_intr_handle_t);

typedef	struct mac_intr_s {
	mac_intr_handle_t	mi_handle;
	mac_intr_enable_t	mi_enable;
	mac_intr_disable_t	mi_disable;
} mac_intr_t;

/*
 * MAC interface callback types.
 */
typedef enum {
	MAC_NOTE_LINK,
	MAC_NOTE_PROMISC,
	MAC_NOTE_UNICST,
	MAC_NOTE_TX,
	MAC_NOTE_RESOURCE,
	MAC_NOTE_DEVPROMISC,
	MAC_NOTE_FASTPATH_FLUSH,
	MAC_NOTE_SDU_SIZE,
	MAC_NOTE_CAPAB_CHG,
	MAC_NNOTE	/* must be the last entry */
} mac_notify_type_t;

typedef void		(*mac_notify_t)(void *, mac_notify_type_t);
typedef void		(*mac_rx_t)(void *, mac_resource_handle_t, mblk_t *);
typedef void		(*mac_txloop_t)(void *, mblk_t *);
typedef void		(*mac_blank_t)(void *, time_t, uint_t);

/*
 * MAC promiscuous types
 */
typedef enum {
	MAC_PROMISC = 0x01,		/* MAC instance is promiscuous */
	MAC_DEVPROMISC = 0x02		/* Device is promiscuous */
} mac_promisc_type_t;

/*
 * MAC resource types
 */
typedef enum {
	MAC_RX_FIFO = 1
} mac_resource_type_t;

typedef struct mac_rx_fifo_s {
	mac_resource_type_t	mrf_type;	/* MAC_RX_FIFO */
	mac_blank_t		mrf_blank;
	void			*mrf_arg;
	time_t			mrf_normal_blank_time;
	uint_t			mrf_normal_pkt_count;
} mac_rx_fifo_t;

typedef union mac_resource_u {
	mac_resource_type_t	mr_type;
	mac_rx_fifo_t		mr_fifo;
} mac_resource_t;

typedef mac_resource_handle_t	(*mac_resource_add_t)(void *, mac_resource_t *);

typedef enum {
	MAC_ADDRTYPE_UNICAST,
	MAC_ADDRTYPE_MULTICAST,
	MAC_ADDRTYPE_BROADCAST
} mac_addrtype_t;

typedef struct mac_header_info_s {
	size_t		mhi_hdrsize;
	size_t		mhi_pktsize;
	const uint8_t	*mhi_daddr;
	const uint8_t	*mhi_saddr;
	uint32_t	mhi_origsap;
	uint32_t	mhi_bindsap;
	mac_addrtype_t	mhi_dsttype;
	uint16_t	mhi_tci;
	uint_t		mhi_istagged:1;
} mac_header_info_t;

/*
 * MAC-Type plugin interfaces
 */

typedef int		(*mtops_addr_verify_t)(const void *, void *);
typedef boolean_t	(*mtops_sap_verify_t)(uint32_t, uint32_t *, void *);
typedef mblk_t		*(*mtops_header_t)(const void *, const void *,
    uint32_t, void *, mblk_t *, size_t);
typedef int		(*mtops_header_info_t)(mblk_t *, void *,
    mac_header_info_t *);
typedef boolean_t	(*mtops_pdata_verify_t)(void *, size_t);
typedef	mblk_t		*(*mtops_header_modify_t)(mblk_t *, void *);

typedef struct mactype_ops_s {
	uint_t			mtops_ops;
	/*
	 * mtops_unicst_verify() returns 0 if the given address is a valid
	 * unicast address, or a non-zero errno otherwise.
	 */
	mtops_addr_verify_t	mtops_unicst_verify;
	/*
	 * mtops_multicst_verify() returns 0 if the given address is a
	 * valid multicast address, or a non-zero errno otherwise.  If the
	 * media doesn't support multicast, ENOTSUP should be returned (for
	 * example).
	 */
	mtops_addr_verify_t	mtops_multicst_verify;
	/*
	 * mtops_sap_verify() returns B_TRUE if the given SAP is a valid
	 * SAP value, or B_FALSE otherwise.
	 */
	mtops_sap_verify_t	mtops_sap_verify;
	/*
	 * mtops_header() is used to allocate and construct a MAC header.
	 */
	mtops_header_t		mtops_header;
	/*
	 * mtops_header_info() is used to gather information on a given MAC
	 * header.
	 */
	mtops_header_info_t	mtops_header_info;
	/*
	 * mtops_pdata_verify() is used to verify the validity of MAC
	 * plugin data.  It is called by mac_register() if the driver has
	 * supplied MAC plugin data, and also by mac_pdata_update() when
	 * drivers update the data.
	 */
	mtops_pdata_verify_t	mtops_pdata_verify;
	/*
	 * mtops_header_cook() is an optional callback that converts (or
	 * "cooks") the given raw header (as sent by a raw DLPI consumer)
	 * into one that is appropriate to send down to the MAC driver.
	 * Following the example above, an Ethernet header sent down by a
	 * DLPI consumer would be converted to whatever header the MAC
	 * driver expects.
	 */
	mtops_header_modify_t	mtops_header_cook;
	/*
	 * mtops_header_uncook() is an optional callback that does the
	 * opposite of mtops_header_cook().  It "uncooks" a given MAC
	 * header (as received from the driver) for consumption by raw DLPI
	 * consumers.  For example, for a non-Ethernet plugin that wants
	 * raw DLPI consumers to be fooled into thinking that the device
	 * provides Ethernet access, this callback would modify the given
	 * mblk_t such that the MAC header is converted to an Ethernet
	 * header.
	 */
	mtops_header_modify_t	mtops_header_uncook;
} mactype_ops_t;

/*
 * mtops_ops exists for the plugin to enumerate the optional callback
 * entrypoints it has defined.  This allows the mac module to define
 * additional plugin entrypoints in mactype_ops_t without breaking backward
 * compatibility with old plugins.
 */
#define	MTOPS_PDATA_VERIFY	0x001
#define	MTOPS_HEADER_COOK	0x002
#define	MTOPS_HEADER_UNCOOK	0x004

typedef struct mactype_register_s {
	uint_t		mtr_version;	/* set by mactype_alloc() */
	const char	*mtr_ident;
	mactype_ops_t	*mtr_ops;
	uint_t		mtr_mactype;
	uint_t		mtr_addrlen;
	uint8_t		*mtr_brdcst_addr;
	mac_stat_info_t	*mtr_stats;
	size_t		mtr_statcount;
	mac_ndd_mapping_t	*mtr_mapping;
	size_t			mtr_mappingcount;
} mactype_register_t;

/*
 * Driver interface functions.
 */

extern void 			mac_unicst_update(mac_handle_t,
    const uint8_t *);

extern void			mac_sdu_get(mac_handle_t, uint_t *, uint_t *);
extern int			mac_maxsdu_update(mac_handle_t, uint_t);
extern int			mac_pdata_update(mac_handle_t, void *,
    size_t);

extern mactype_register_t	*mactype_alloc(uint_t);
extern void			mactype_free(mactype_register_t *);
extern int			mactype_register(mactype_register_t *);
extern int			mactype_unregister(const char *);
extern void			mac_capab_update(mac_handle_t);

/*
 * MAC Hashing policy bits.
 */
#define	MAC_PKT_HASH_L2		0x01
#define	MAC_PKT_HASH_L3		0x02
#define	MAC_PKT_HASH_L4		0x04

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_MAC_H */
