/*
 * Copyright (c) 2010, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_MAC_PROVIDER_H
#define	_SYS_MAC_PROVIDER_H

#pragma ident	"@(#)mac_provider.h	1.2	11/10/11 SMI"

#include <sys/types.h>
#include <sys/ddi.h>
#include <sys/sunddi.h>
#include <sys/stream.h>
#include <sys/mkdev.h>
#include <sys/mac.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * MAC Information (text emitted by modinfo(1m))
 */
#define	MAC_INFO	"MAC Services v1.2"

/*
 * MAC version identifier.  This is used by mac_alloc() mac_register() to
 * verify that incompatible drivers don't register.
 */
#define	MAC_VERSION	0x1

#define	XCVR_UNDEFINED		0
#define	XCVR_NONE		1
#define	XCVR_10			2
#define	XCVR_100T4		3
#define	XCVR_100X		4
#define	XCVR_100T2		5
#define	XCVR_1000X		6
#define	XCVR_1000T		7

#ifdef	_KERNEL

/*
 * LSO capability
 */
typedef struct lso_basic_tcp_ipv4_s {
	t_uscalar_t	lso_max;		/* maximum payload */
} lso_basic_tcp_ipv4_t;

/*
 * Future LSO capabilities can be added at the end of the mac_capab_lso_t.
 * When such capability is added to the GLDv3 framework, the size of the
 * mac_capab_lso_t it allocates and passes to the drivers increases. Older
 * drivers wil access only the (upper) sections of that structure, that is the
 * sections carrying the capabilities they understand. This ensures the
 * interface can be safely extended in a binary compatible way.
 */
typedef	struct mac_capab_lso_s {
	t_uscalar_t		lso_flags;
	lso_basic_tcp_ipv4_t	lso_basic_tcp_ipv4;
	/* Add future lso capabilities here */
} mac_capab_lso_t;

/*
 * MAC layer capabilities.  These capabilities are handled by the drivers'
 * mc_capab_get() callbacks.  Some capabilities require the driver to fill
 * in a given data structure, and others are simply boolean capabilities.
 * Note that capability values must be powers of 2 so that consumers and
 * providers of this interface can keep track of which capabilities they
 * care about by keeping a bitfield of these things around somewhere.
 */
typedef enum {
	MAC_CAPAB_HCKSUM	= 0x0001,	/* data is a uint32_t */
	MAC_CAPAB_POLL		= 0x0002,	/* boolean only, no data */
	MAC_CAPAB_MULTIADDRESS	= 0x0004,	/* multiaddress_capab_t */
	MAC_CAPAB_LSO		= 0x0008,	/* data is mac_capab_lso_t */

	/* add new capabilities below */

	/* Private driver capabilities */
	MAC_CAPAB_RINGS		= 0x0100,	/* data is mac_capab_rings_t */
	MAC_CAPAB_SHARES	= 0x0200,	/* data is mac_capab_share_t */

	/*
	 * Consolidation private capabilities. Should not be used by third
	 * party drivers.
	 */
	MAC_CAPAB_IOV		= 0x1000	/* data is mac_capab_iov_t */
} mac_capab_t;

/* mma_flags values */
#define	MMAC_SLOT_USED		0x1   /* address slot used */
#define	MMAC_SLOT_UNUSED	0x2   /* free address slot */
#define	MMAC_VENDOR_ADDR	0x4   /* address returned is vendor supplied */

typedef struct mac_multi_address_s {
	mac_addr_slot_t	mma_slot;	/* slot for add/remove/get/set */
	uint_t		mma_addrlen;
	uint8_t		mma_addr[MAXMACADDRLEN];
	uint_t		mma_flags;
} mac_multi_addr_t;

typedef int	(*maddr_reserve_t)(void *, mac_multi_addr_t *);
typedef int	(*maddr_add_t)(void *, mac_multi_addr_t *);
typedef int	(*maddr_remove_t)(void *, mac_addr_slot_t);
typedef int	(*maddr_modify_t)(void *, mac_multi_addr_t *);
typedef int	(*maddr_get_t)(void *, mac_multi_addr_t *);

/* maddr_flag values */
#define	MADDR_VENDOR_ADDR	0x01	/* addr returned is vendor supplied */

/* multiple mac address: add/remove/set/get mac address */
typedef struct multiaddress_capab_s {
	int		maddr_naddr;	/* total addresses */
	int		maddr_naddrfree;	/* free address slots */
	uint_t		maddr_flag;	/* MADDR_VENDOR_ADDR bit can be set */
	/* driver entry points */
	void		*maddr_handle;	/* cookie to be used for the calls */
	maddr_reserve_t	maddr_reserve;	/* reserve a factory address */
	maddr_add_t	maddr_add;	/* add a new unicst address */
	maddr_remove_t	maddr_remove;	/* remove an added address */
	maddr_modify_t	maddr_modify;	/* modify an added address */
	maddr_get_t	maddr_get;	/* get address from specified slot */
} multiaddress_capab_t;

typedef struct __mac_prop_info_handle *mac_prop_info_handle_t;

/*
 * MAC driver entry point types.
 */
typedef int		(*mac_getstat_t)(void *, uint_t, uint64_t *);
typedef	int		(*mac_start_t)(void *);
typedef void		(*mac_stop_t)(void *);
typedef int		(*mac_setpromisc_t)(void *, boolean_t);
typedef int		(*mac_multicst_t)(void *, boolean_t, const uint8_t *);
typedef int		(*mac_unicst_t)(void *, const uint8_t *);
typedef void		(*mac_ioctl_t)(void *, queue_t *, mblk_t *);
typedef void		(*mac_resources_t)(void *);
typedef mblk_t		*(*mac_tx_t)(void *, mblk_t *);
typedef boolean_t	(*mac_getcapab_t)(void *, mac_capab_t, void *);
typedef int		(*mac_open_t)(void *);
typedef void		(*mac_close_t)(void *);
typedef int		(*mac_set_prop_t)(void *, const char *, mac_prop_id_t,
			    uint_t, const void *);
typedef int		(*mac_get_prop_t)(void *, const char *, mac_prop_id_t,
			    uint_t, void *);
typedef void		(*mac_prop_info_t)(void *, const char *, mac_prop_id_t,
			    mac_prop_info_handle_t);

typedef struct mac_txinfo_s {
	mac_tx_t		mt_fn;
	void			*mt_arg;
} mac_txinfo_t;

/*
 * Drivers must set all of these callbacks except for mc_resources,
 * mc_ioctl, and mc_getcapab, which are optional.  If any of these optional
 * callbacks are set, their appropriate flags must be set in mc_callbacks.
 * Any future additions to this list must also be accompanied by an
 * associated mc_callbacks flag so that the framework can grow without
 * affecting the binary compatibility of the interface.
 */
typedef struct mac_callbacks_s {
	uint_t		mc_callbacks;	/* Denotes which callbacks are set */
	mac_getstat_t	mc_getstat;	/* Get the value of a statistic */
	mac_start_t	mc_start;	/* Start the device */
	mac_stop_t	mc_stop;	/* Stop the device */
	mac_setpromisc_t mc_setpromisc;	/* Enable or disable promiscuous mode */
	mac_multicst_t	mc_multicst;	/* Enable or disable a multicast addr */
	mac_unicst_t	mc_unicst;	/* Set the unicast MAC address */
	mac_tx_t	mc_tx;		/* Transmit a packet */
	mac_resources_t	mc_resources;	/* Get the device resources */
	mac_ioctl_t	mc_ioctl;	/* Process an unknown ioctl */
	mac_getcapab_t	mc_getcapab;	/* Get capability information */
	mac_open_t	mc_open;	/* Open the device */
	mac_close_t	mc_close;	/* Close the device */
	mac_set_prop_t	mc_setprop;
	mac_get_prop_t	mc_getprop;
	mac_prop_info_t	mc_propinfo;

} mac_callbacks_t;

/*
 * Flags for mc_callbacks.  Requiring drivers to set the flags associated
 * with optional callbacks initialized in the structure allows the mac
 * module to add optional callbacks in the future without requiring drivers
 * to recompile.
 */
#define	MC_RESOURCES	0x001
#define	MC_IOCTL	0x002
#define	MC_GETCAPAB	0x004
#define	MC_OPEN		0x0008
#define	MC_CLOSE	0x0010
#define	MC_SETPROP	0x0020
#define	MC_GETPROP	0x0040
#define	MC_PROPINFO	0x0080
#define	MC_PROPERTIES	(MC_SETPROP | MC_GETPROP | MC_PROPINFO)

typedef	struct mac_ring_info_s mac_ring_info_t;
typedef	struct mac_group_info_s mac_group_info_t;

typedef void	(*mac_get_ring_t)(void *, mac_ring_type_t, const int, const int,
    mac_ring_info_t *, mac_ring_handle_t);
typedef void	(*mac_get_group_t)(void *, mac_ring_type_t, const int,
    mac_group_info_t *, mac_group_handle_t);

typedef void	(*mac_group_add_ring_t)(mac_group_driver_t,
    mac_ring_driver_t, mac_ring_type_t);
typedef void	(*mac_group_rem_ring_t)(mac_group_driver_t,
    mac_ring_driver_t, mac_ring_type_t);

/*
 * Multiple Rings Capability
 */
typedef struct	mac_capab_rings_s {
	mac_ring_type_t		mr_type;	/* Ring type */
	mac_group_type_t	mr_group_type;	/* Grouping type */
	void			*mr_handle;	/* Group Driver Handle. */
	uint_t			mr_rnum;	/* Number of rings */
	uint_t			mr_gnum;	/* Number of ring groups */
	mac_get_ring_t		mr_rget;	/* Get ring from driver */
	mac_get_group_t		mr_gget;	/* Get ring group from driver */
	mac_group_add_ring_t	mr_gadd_ring;	/* Add ring into a group */
	mac_group_rem_ring_t	mr_grem_ring;	/* Remove ring from a group */
} mac_capab_rings_t;

/*
 * Common ring functions and driver interfaces
 */
typedef	int	(*mac_ring_start_t)(mac_ring_driver_t);
typedef	void	(*mac_ring_stop_t)(mac_ring_driver_t);

typedef	mblk_t	*(*mac_ring_send_t)(void *, mblk_t *);
typedef	mblk_t *(*mac_ring_poll_t)(void *, int);

typedef struct mac_ring_info_s {
	mac_ring_driver_t	mr_driver;
	mac_ring_start_t	mr_start;
	mac_ring_stop_t		mr_stop;
	mac_intr_t		mr_intr;
	union {
		mac_ring_send_t	send;
		mac_ring_poll_t	poll;
	} mrfunion;
} mac_ring_info_s;

#define	mr_send		mrfunion.send
#define	mr_poll		mrfunion.poll

typedef	int	(*mac_group_start_t)(mac_group_driver_t);
typedef	void	(*mac_group_stop_t)(mac_group_driver_t);
typedef	int	(*mac_add_mac_addr_t)(void *, const uint8_t *);
typedef	int	(*mac_rem_mac_addr_t)(void *, const uint8_t *);

struct mac_group_info_s {
	mac_group_driver_t	mrg_driver;	/* Driver reference */
	mac_group_start_t	mrg_start;	/* Start the group */
	mac_group_stop_t	mrg_stop;	/* Stop the group */
	uint_t			mrg_count;	/* Count of rings */
	mac_intr_t		mrg_intr;	/* Optional per-group intr */

	/* Only used for rx groups */
	mac_add_mac_addr_t	mrg_addmac;	/* Add a MAC address */
	mac_rem_mac_addr_t	mrg_remmac;	/* Remove a MAC address */
};

/*
 * Share management functions.
 */
typedef uint64_t mac_share_handle_t;

/*
 * Returns a Share handle to the client calling from above.
 */
typedef int    (*mac_alloc_share_t)(void *, uint64_t cookie,
    uint64_t *rcookie, mac_share_handle_t *);

/*
 * Destroys the share previously allocated and unallocates
 * all share resources (e.g. DMA's assigned to the share).
 */
typedef void (*mac_free_share_t)(mac_share_handle_t);

typedef void (*mac_share_query_t)(mac_share_handle_t shdl,
    mac_ring_type_t type, uint32_t *rmin, uint32_t *rmax,
    uint64_t *rmap, uint64_t *gnum);

/*
 * Basic idea, bind previously created ring groups to shares
 * for them to be exported (or shared) by another domain.
 * These interfaces bind/unbind the ring group to a share.  The
 * of doing such causes the resources to be shared with the guest.
 */
typedef int (*mac_share_add_group_t)(mac_share_handle_t,
    mac_group_handle_t);
typedef int (*mac_share_rem_group_t)(mac_share_handle_t,
    mac_group_handle_t);

typedef struct  mac_capab_share_s {
	uint_t			ms_snum;	/* Number of shares (vr's) */
	void			*ms_handle;	/* Handle to driver. */
	mac_alloc_share_t	ms_salloc;	/* Get a share from driver. */
	mac_free_share_t	ms_sfree;	/* Return a share to driver. */
	mac_share_add_group_t	ms_sadd;	/* Add a group to the share. */
	mac_share_rem_group_t	ms_sremove;	/* Remove group from share. */
	mac_share_query_t	ms_squery;	/* Query share constraints */
} mac_capab_share_t;

typedef struct mac_register_s {
	uint_t		m_version;	/* set by mac_alloc() */
	const char	*m_type_ident;
	void		*m_driver;	/* Driver private data */
	dev_info_t	*m_dip;
	uint_t		m_instance;
	uint8_t		*m_src_addr;
	uint8_t		*m_dst_addr;
	mac_callbacks_t	*m_callbacks;
	uint_t		m_min_sdu;
	uint_t		m_max_sdu;
	void		*m_pdata;
	size_t		m_pdata_size;
	char		**m_priv_props;
	uint32_t	m_margin;
} mac_register_t;

/*
 * Client interface functions.
 */
extern int			mac_open(const char *, mac_handle_t *);
extern void			mac_close(mac_handle_t);
extern const mac_info_t		*mac_info(mac_handle_t);
extern boolean_t		mac_info_get(const char *, mac_info_t *);
extern uint64_t			mac_stat_get(mac_handle_t, uint_t);
extern int			mac_start(mac_handle_t);
extern void			mac_stop(mac_handle_t);
extern int			mac_promisc_set(mac_handle_t, boolean_t,
    mac_promisc_type_t);
extern boolean_t		mac_promisc_get(mac_handle_t,
    mac_promisc_type_t);
extern int 			mac_multicst_add(mac_handle_t, const uint8_t *);
extern int 			mac_multicst_remove(mac_handle_t,
    const uint8_t *);
extern boolean_t		mac_unicst_verify(mac_handle_t,
    const uint8_t *, uint_t);
extern int			mac_unicst_set(mac_handle_t, const uint8_t *);
extern void			mac_unicst_get(mac_handle_t, uint8_t *);
extern void			mac_dest_get(mac_handle_t, uint8_t *);
extern void			mac_resources(mac_handle_t);
extern void			mac_ioctl(mac_handle_t, queue_t *, mblk_t *);
extern const mac_txinfo_t	*mac_tx_get(mac_handle_t);
extern link_state_t		mac_link_get(mac_handle_t);
extern mac_notify_handle_t	mac_notify_add(mac_handle_t, mac_notify_t,
    void *);
extern void			mac_notify_remove(mac_handle_t,
    mac_notify_handle_t);
extern void			mac_notify(mac_handle_t);
extern mac_rx_handle_t		mac_rx_add(mac_handle_t, mac_rx_t, void *);
extern void			mac_rx_remove(mac_handle_t, mac_rx_handle_t,
    boolean_t);
extern void			mac_rx_remove_wait(mac_handle_t);
extern mblk_t			*mac_txloop(void *, mblk_t *);
extern mac_txloop_handle_t	mac_txloop_add(mac_handle_t, mac_txloop_t,
    void *);
extern void			mac_txloop_remove(mac_handle_t,
    mac_txloop_handle_t);
extern boolean_t		mac_active_set(mac_handle_t);
extern void			mac_active_clear(mac_handle_t);
extern void			mac_resource_set(mac_handle_t,
    mac_resource_add_t, void *);
extern dev_info_t		*mac_devinfo_get(mac_handle_t);
extern boolean_t		mac_capab_get(mac_handle_t, mac_capab_t,
    void *);
extern boolean_t		mac_sap_verify(mac_handle_t, uint32_t,
    uint32_t *);
extern mblk_t			*mac_header(mac_handle_t, const uint8_t *,
    uint32_t, mblk_t *, size_t);
extern int			mac_header_info(mac_handle_t, mblk_t *,
    mac_header_info_t *);
extern mblk_t			*mac_header_cook(mac_handle_t, mblk_t *);
extern mblk_t			*mac_header_uncook(mac_handle_t, mblk_t *);

/*
 * Driver interface functions.
 */
extern mac_register_t		*mac_alloc(uint_t);
extern void			mac_free(mac_register_t *);
extern int			mac_register(mac_register_t *, mac_handle_t *);
extern int  			mac_unregister(mac_handle_t);
extern void 			mac_rx(mac_handle_t, mac_resource_handle_t,
    mblk_t *);
extern void 			mac_link_update(mac_handle_t, link_state_t);
extern void 			mac_unicst_update(mac_handle_t,
    const uint8_t *);
extern void			mac_sdu_get(mac_handle_t, uint_t *, uint_t *);
extern int			mac_maxsdu_update(mac_handle_t, uint_t);
extern void			mac_tx_update(mac_handle_t);
extern void			mac_resource_update(mac_handle_t);
extern mac_resource_handle_t	mac_resource_add(mac_handle_t,
    mac_resource_t *);
extern int			mac_pdata_update(mac_handle_t, void *,
    size_t);
extern void			mac_multicst_refresh(mac_handle_t,
    mac_multicst_t, void *, boolean_t);
extern void			mac_unicst_refresh(mac_handle_t, mac_unicst_t,
    void *);
extern void			mac_promisc_refresh(mac_handle_t,
    mac_setpromisc_t, void *);
extern void			mac_init_ops(struct dev_ops *, const char *);
extern void			mac_fini_ops(struct dev_ops *);
extern mactype_register_t	*mactype_alloc(uint_t);
extern void			mactype_free(mactype_register_t *);
extern int			mactype_register(mactype_register_t *);
extern int			mactype_unregister(const char *);
extern int			mac_vlan_create(mac_handle_t, const char *,
    minor_t);
extern void			mac_vlan_remove(mac_handle_t, const char *);
extern uint64_t			mac_pkt_hash(mblk_t *, uint8_t, boolean_t);


extern void			mac_prop_info_set_default_uint8(
				    mac_prop_info_handle_t, uint8_t);
extern void			mac_prop_info_set_default_str(
				    mac_prop_info_handle_t, const char *);
extern void			mac_prop_info_set_default_uint64(
				    mac_prop_info_handle_t, uint64_t);
extern void			mac_prop_info_set_default_uint32(
				    mac_prop_info_handle_t, uint32_t);
extern void			mac_prop_info_set_default_link_flowctrl(
				    mac_prop_info_handle_t, link_flowctrl_t);
extern void			mac_prop_info_set_range_uint32(
				    mac_prop_info_handle_t, uint32_t, uint32_t);
extern void			mac_prop_info_set_perm(mac_prop_info_handle_t,
				    uint8_t);

extern void			mac_hcksum_get(mblk_t *, uint32_t *,
				    uint32_t *, uint32_t *, uint32_t *,
				    uint32_t *);
extern void			mac_hcksum_set(mblk_t *, uint32_t, uint32_t,
				    uint32_t, uint32_t, uint32_t);

extern void			mac_lso_get(mblk_t *, uint32_t *, uint32_t *);

#endif /* _KERNEL */

#ifdef __cplusplus
}
#endif

#endif /* _SYS_MAC_PROVIDER_H */
