/*
 * Copyright (c) 2000 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef	_SYS_VLAN_IMPL_H
#define	_SYS_VLAN_IMPL_H

#pragma	ident "@(#)vlan_impl.h 1.5	00/12/18 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * vlan_impl.h:
 *
 *	Private data structures and definitions used by the vlan
 *	interface module vlan.c. They are private to the vlan
 *	interfaces and should not be referenced by any code outside
 *	vlan.c.
 */

/*
 * Taken from from sys/strsun.h for common STREAMS declarations.
 */
#define	DB_BASE(mp)	((mp)->b_datap->db_base)
#define	DB_LIM(mp)	((mp)->b_datap->db_lim)
#define	DB_REF(mp)	((mp)->b_datap->db_ref)
#define	DB_TYPE(mp)	((mp)->b_datap->db_type)

#define	MBLKL(mp)	((mp)->b_wptr - (mp)->b_rptr)
#define	MBLKSIZE(mp)	((mp)->b_datap->db_lim - (mp)->b_datap->db_base)
#define	MBLKHEAD(mp)	((mp)->b_rptr - (mp)->b_datap->db_base)
#define	MBLKTAIL(mp)	(mp)->b_datap->db_lim - (mp)->b_wptr)

#define	MBLKIN(mp, off, len)	((off <= MBLKL(mp)) && \
	(((mp)->b_rptr + off + len) <= (mp)->b_wptr))

#define	OFFSET(base, p)	((caddr_t)(p) - (caddr_t)(base))

extern size_t	msgsize(mblk_t *);


#define	ether_bcopy(a, b)	(bcopy(a, b, 6))

/*
 * Non-VLAN ethernet headers
 */
typedef	struct ether_header	*eehp;

/*
 * VLAN ethernet headers
 */

typedef	struct vlan_header	*veehp;

typedef	caddr_t			*cptr;

#define	GET_VID_LIST(p)		((vlan_vid_list_t *)(*((cptr)p)))
#define	GET_VINFO_LIST(p)	((vlan_info_handle_impl_t *)(*((cptr)p)))

#define	PUT_VLAN_PTR1(p, value)	((*((cptr)p)) = (caddr_t)value)
#define	PUT_VLAN_PTR(p, value)	((*((cptr)p)) = (caddr_t)value)

#define	IS_VLAN_DEVICE(ptr)	\
{				\
	vlan_stream_handle_impl_t *vqptr;	\
	vqptr = (vlan_stream_handle_impl_t *)*ptr;	\
	return (vqptr->vidlist != NULL)	\
}

/*
 * open stream's VID/VLAN state information (GVRP)
 */
#define	VID_IDLE	0x00	/* VID is idle (not ready to use) */
#define	VID_INITIALIZED	0x01	/* VID is configured (static) */
#define	VID_PENDING	0x02	/* Waiting for GVRP to complete */
#define	VID_GVRP_OK	0x04	/* VID is configured (GVRP) */
#define	VID_QOS_SET	0x08	/* DL_UDQOS_REQ enabled */
#define	VID_SET_RAW	0x10	/* DLPI to set VLAN (send up Raw packet) */
#define	VID_SET_ALLVIDS	0x100	/* DLPI to receive all VLANS */

/*
 * DLPI destination sap ethernet header
 */
typedef struct ether_dladdr {
	struct	ether_addr	dl_phys;
	uint16_t		dl_sap;
} ether_dladdr_t;

/*
 * kstat statistics on a VLAN device.
 */
typedef	struct vlan_kstat {
	kstat_named_t	ipackets;		/* packets received */
	kstat_named_t	opackets;		/* packets transmitted */
#ifdef	HARDWARE
	uint64_t	ierrors;		/* input errors */
	uint64_t	oerrors;		/* output errors */
#endif
	kstat_named_t	ipackets64;		/* packets received */
	kstat_named_t	opackets64;		/* packets transmitted */
	kstat_named_t	rbytes;			/* # octets received */
						/* MIB - ifInOctets */

	kstat_named_t	obytes;			/* # octets transmitted */
						/* MIB - ifOutOctets */

	kstat_named_t	rbytes64;		/* bytes received */
	kstat_named_t	obytes64;		/* bytes transmitted */
	kstat_named_t	multircv;		/* # multicast received */
						/* delivered to upper layer */

	kstat_named_t	multixmt;		/* # multicast packets */
						/* requested to be sent */
						/* MIB - ifOutNUcastPkts */

	kstat_named_t	brdcstrcv;		/* # broadcast packets */
						/* delivered to upper layer */
						/* MIB - ifInNUcastPkts */

	kstat_named_t	brdcstxmt;		/* # broadcast packets */
						/* requested to be sent */
						/* MIB - ifOutNUcastPkts */

	kstat_named_t	norcvbuf;		/* # rcv packets discarded */
						/* MIB - ifInDiscards */

	kstat_named_t	noxmtbuf;		/* # xmt packets discarded */
	kstat_named_t	nocanput;		/* # packets could not be  */
						/* sent up because the queue */
						/*  was flow controlled */
	kstat_named_t	maxvids;		/* Max VID allowed (PPA) */
	kstat_named_t	vid_allocated;		/* # VIDS in use (PPA) */

} vlan_kstat_t;

typedef	struct vlan_stat {
	uint64_t	ipackets;		/* packets received */
	uint64_t	opackets;		/* packets transmitted */
#ifdef	HARDWARE
	uint64_t	ierrors;		/* input errors */
	uint64_t	oerrors;		/* output errors */
#endif
	/*
	 * PSARC 1997/198
	 */
	uint64_t	ipackets64;		/* packets received */
	uint64_t	opackets64;		/* packets transmitted */

	uint64_t	rbytes64;		/* bytes received */
	uint64_t	obytes64;		/* bytes transmitted */

	uint64_t	rbytes;			/* # octets received */
						/* MIB - ifInOctets */

	uint64_t	obytes;			/* # octets transmitted */
						/* MIB - ifOutOctets */

	uint32_t	multircv;		/* # multicast received */
						/* delivered to upper layer */
						/* MIB - ifInNUcastPkts */

	uint32_t	multixmt;		/* # multicast packets */
						/* requested to be sent */
						/* MIB - ifOutNUcastPkts */

	uint32_t	brdcstrcv;		/* # broadcast packets */
						/* delivered to upper layer */
						/* MIB - ifInNUcastPkts */

	uint32_t	brdcstxmt;		/* # broadcast packets */
						/* requested to be sent */
						/* MIB - ifOutNUcastPkts */

	uint32_t	norcvbuf;		/* # rcv packets discarded */
						/* MIB - ifInDiscards */

	uint32_t	noxmtbuf;		/* # xmt packets discarded */

	uint32_t	nocanput;		/* # rcv packets discarded */
						/* because the upper queue */
						/* was flow controlled */

	uint32_t	maxvids;		/* total VLANS configured */
	uint32_t	vid_allocated;		/* VLANs in used */
} vlan_stat_t;

/*
 * DLPI QOS offsets
 */
#define	DLSAPLEN	((sizeof (uint16_t) + ETHERADDRL))
#define	DL_QOS_CL_SEL1_SIZE sizeof (dl_qos_cl_sel1_t)
#define	DL_QOS_CL_RANG1_SIZE sizeof (dl_qos_cl_range1_t)

#define	QOS_CL_SEL1_OFFSET (DL_INFO_ACK_SIZE + DLSAPLEN + ETHERADDRL)
#define	OS_CL_RANG1_OFFSET \
	(DL_INFO_ACK_SIZE + DLSAPLEN + ETHERADDRL + DL_QOS_CL_SEL1_SIZE)

#define	DL_PRIORITY_MAX	100	/* dlpi.h: 100 is the max. */
#define	DL_PRIORITY_MIN	0	/* dlpi.h: 0 is the min. */

/*
 * priority queues for background (0) and
 * priority is higher than 0 (b_band is not 1 or 0)
 *
 * background will be processed after default priority
 * and higher priority ones will be processed before
 * default when the write service scheduler is run.
 *
 * VLAN priority:
 *    in sequence form highest to lowest:
 *	7,6,5,4,3,0,1,2 (2 is reserved/spare)
 *
 */

/*
 * Map b_band to 802.1D user priorities.
 *
 * mapping: b_band to user priority
 *
 *  b_band: 		user priority
 *   0   - 31			0
 *   32  - 63			1
 *   64  - 95			2
 *   96  - 127			3
 *   128 - 159			4
 *   160 - 191			5
 *   192 - 223			6
 *   224 - 255			7
 *
 * Map 8 user priorities to 4 priority queues:
 *
 *   queue[0]: highest for user priority  6, 7
 *   queue[1]:         for user priority  4, 5
 *   queue[2]:         for user priority  2, 3 (2 is spare)
 *   queue[3]: lowest  for user priority  0, 1
 */

#define	VLAN_PRIORITY_QUEUE_MAX	4
#define	VLAN_PRIORITY_QUEUE_HIGHEST	0
#define	VLAN_PRIORITY_QUEUE_DEFAULT	2
#define	VLAN_PRIORITY_QUEUE_LOWEST	3


/*
 * Data structure for the IPv4 and IPv6 list.
 */
typedef struct sap_list_entry {
	struct vlan_stream_handle_impl *first;
	struct vlan_stream_handle_impl *last;
	kmutex_t list_lock;
	uint32_t sap_cnt;
} vlani_sap_list_entry_t;


/*
 * Data structure to hold the registered VID information for one VID.
 */
typedef struct vlan_list_reg {
	uint32_t	vlan_list_regcnt; /* same VID elements */
	uint16_t	vlan_id;	  /* VID */
	/*
	 * IPv4 and ipv6 lists
	 */
	vlani_sap_list_entry_t ipv4_list;
	vlani_sap_list_entry_t ipv6_list;
} vlan_list_reg_t;

/*
 * VID structure - used to define the per VLAN VID information.
 */
typedef struct vlan_vid_list {
	struct vlan_info_handle_impl	*vlanp;	/* pointer to vlan info */
	uint16_t	vlan_vid;		/* VID */
	int		vlan_ppa;		/* device PPA */
	uint16_t	vlan_vid_index;		/* index to this table */
	t_uscalar_t	vid_state;		/* GVRP */
	struct vlan_vid_list *vlan_list_start; 	/* start of the list */
	t_uscalar_t	vlan_att_ppa;		/* DLPI attach PPA number */
	vlan_list_reg_t	vlan_reg_list;		/* same VID list */
	/*
	 * network statistics for this VID
	 */
	vlan_stat_t	vlan_stat;		/* VID's network statistics */
	kstat_t 	*vlan_ksp;    		/* kstat pointer */

} vlan_vid_list_t;

typedef	struct	vlan_vid_htable {
	vlan_vid_list_t	*vlan_vid_tab;		/* start of vid list for */
						/*  this hash bucket */
	uint16_t	vlan_hash_vid_size;	/* vid hash table size  */
	uint16_t	vlan_vid_used;		/* # of VID set */
	void		*vlan_pad;
} vlan_vid_htable_t;

/*
 * per DLPI user's VID list and QoS
 */
typedef struct vlan_stream_handle_impl {
	struct vlan_stream_handle_impl *next; 	/* same SAP link list */
	struct vlan_stream_handle_impl *prev; 	/* same SAP link list */
	struct vlan_info_handle_impl *vlan_info;
	vlan_vid_list_t	*vidlist;		/* VID info list of this VID */
	t_scalar_t	vid;			/* VID	*/
	t_scalar_t	dl_sap;			/* dl sap */
	t_scalar_t	vid_state;		/* VID	state */
	t_scalar_t	subs_sap;		/* subsequent DLSAP */
	t_scalar_t	subs_sap_state;		/* subsequent DLSAP state */
	void		*vid_pad;		/* padding */
	dl_qos_cl_sel1_t qos_cl_sel1;		/* DLPI user selected QoS */
	t_uscalar_t	dl_qos_length;		/* length of qos values */
	t_uscalar_t	dl_qos_offset;		/* offset from start of block */
	t_uscalar_t	dl_qos_range_length; 	/* range of qos */
	t_uscalar_t	dl_qos_range_offset; 	/* offset from start of block */
	uint32_t	qos_cl_state;		/* state for this DLPI  user */
	t_scalar_t	qos_priority;		/* priority value */
	uchar_t		version;		/* implementation version */
} vlan_stream_handle_impl_t;

#define	VLAN_VERSION_1		1
#define	VLAN_VERSION		VLAN_VERSION_1
#define	VLAN_VERSION_STRING	"v1"

/*
 * Per device vlan info data structure
 */
typedef struct vlan_info_handle_impl {
	void		*drv_ks_private;	/* driver kstat private data */
	char		vlan_dev_name[16];	/* driver name */
	int		dev_ppa;		/* device instance (PPA) */
	uint32_t	vlan_vid_hash_alloc;	/* hash table size */
	uint32_t	vid_allocated;		/* unique VID used per PPA */
	uint32_t	vid_open_streams;	/* streams opened on this VID */
	vlan_vid_htable_t *vlan_vid_htable;
	kmutex_t	vlan_lock;
	uchar_t		version;		/* implementation version */
} vlan_info_handle_impl_t;


#define	VLAN_MAX_VIDS		4096
#define	VLAN_DEFAULT_VIDS	VLAN_MAX_VIDS
#define	VLAN_HASH_TABLE_SIZE	4096
#define	VLAN_HASH_VLAN_SIZE	16

#define	VLAN_VID_LIST_SIZE	  (sizeof (vlan_vid_list_t))
#define	VLAN_LIST_HASH_TABLE_SIZE (VLAN_HASH_VLAN_SIZE * VLAN_VID_LIST_SIZE)

#define	VLAN_GET_HASH(vid)	\
	(((vid >> 10) ^ (vid & 0x3ff)) % VLAN_HASH_TABLE_SIZE)

#define	VLAN_GET_SUBS_SAP(ptr)	\
	(vlan_stream_handle_impl_t *)ptr->subs_sap;

#define	IS_VLAN_ENABLED(ptr)	\
{				\
	vlan_stream_handle_impl_t *vqptr;	\
	vqptr = (vlan_stream_handle_impl_t *)*ptr;	\
	if (vqptr == NULL)		\
		return (FALSE);		\
	return (((vlan_stream_handle_impl_t *)vqptr->vidlist != NULL));	\
}
typedef	enum {
	VLAN_NO_MSG		= 0,
	VLAN_CON_MSG		= 1,
	VLAN_BUF_MSG		= 2,
	VLAN_VERB_MSG		= 3,
	VLAN_LOG_MSG		= 4
} vlan_msg_t;

#ifdef	DEBUG

typedef	enum {
	NO_MSG		= 0,
	ALLOC_MSG	= 1,
	REG_MSG		= 2,
	STREAMS_MSG	= 3,
	IOCTL_MSG	= 4,
	TX_MSG		= 5,
	RX_MSG		= 6,
	INFO_MSG	= 7,
	KSTAT_MSG	= 8,
	SUBS_MSG	= 9,
	SAP_REG_MSG	= 10
} vdebug_msg_t;

static	char	*vdebug_msg_string[] = {
	"NONE        ",
	"ALLOC       ",
	"REGISTER    ",
	"STREAMS     ",
	"IOCTL       ",
	"TX          ",
	"RX          ",
	"INFO        ",
	"KSTAT        ",
	"SUBS        ",
	"SAP_REG     ",
};

vlan_msg_t	vlan_msg_out = VLAN_VERB_MSG;
vdebug_msg_t	vlan_debug_level = 0;
vdebug_msg_t	vlan_debug_all = 0;

static char *vlan_dump_packet(char *, int);
static void vlan_debug_msg(char *, int, vlan_info_handle_impl_t *, vdebug_msg_t,
	char *, ...);


void	debug_enter(char *);

#define	VLAN_DEBUG_MSG1(t, f, a)	\
	vlan_debug_msg(__FILE__, __LINE__, (t), (f), (a));

#define	VLAN_DEBUG_MSG2(t, f, a, b)	\
	vlan_debug_msg(__FILE__, __LINE__, (t), (f), (a), (b));

#define	VLAN_DEBUG_MSG3(t, f, a, b, c)	\
	vlan_debug_msg(__FILE__, __LINE__, (t), (f), (a), (b), (c));

#define	VLAN_DEBUG_MSG4(t, f, a, b, c, d)	\
	vlan_debug_msg(__FILE__, __LINE__, (t), (f), (a), (b), (c), (d));

#define	VLAN_DEBUG_MSG5(t, f, a, b, c, d, e)	\
	vlan_debug_msg(__FILE__, __LINE__, (t), (f), (a), (b), (c), (d), (e));

#define	VLAN_DEBUG_MSG6(t, f, a, b, c, d, e, g)	\
	vlan_debug_msg(__FILE__, __LINE__, (t), (f), (a), (b), (c), (d), \
			(e), (g));

#define	VLAN_DEBUG_MSG7(t, f, a, b, c, d, e, g, h)	\
	vlan_debug_msg(__FILE__, __LINE__, (t), (f), (a), (b), (c), (d), \
			(e), (g), (h));

#else		/* end of DEBUG */

#define	VLAN_DEBUG_MSG1(t, f, a)
#define	VLAN_DEBUG_MSG2(t, f, a, b)
#define	VLAN_DEBUG_MSG3(t, f, a, b, c)
#define	VLAN_DEBUG_MSG4(t, f, a, b, c, d)
#define	VLAN_DEBUG_MSG5(t, f, a, b, c, d, e)
#define	VLAN_DEBUG_MSG6(t, f, a, b, c, d, e, g)
#define	VLAN_DEBUG_MSG7(t, f, a, b, c, d, e, g, h)

#endif		/* END OF not DEBUG */

/*
 * VLAN private functions.
 */
static vlan_vid_list_t *vlani_find_vid(vlan_vid_list_t *,
	uint16_t, uint16_t);

static int vlani_kstat_create(vlan_vid_list_t *, vlan_info_handle_impl_t *,
	int (*)(), void *);
static void vlani_kstat_delete(vlan_vid_list_t *, t_uscalar_t);
static int vlani_kstat_update(kstat_t *, int);

static	vlan_vid_list_t *vlani_find_vlist(vlan_info_handle_impl_t *, uint16_t);

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_VLAN_IMPL_H */
