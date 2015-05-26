/*
 * Copyright (c) 2002 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#pragma	ident "@(#)ce.h 1.81	07/10/02 SMI"

#ifndef	_CE_H
#define	_CE_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef M_MULTIDATA
#define M_MULTIDATA     0x02            /* reserved for multi-data use only */
#endif

/*
 * Cassini diagnostics IOCTLS.
 */
#define	CE_IOC		('CE' << 8)

#define	CE_GET32		(CE_IOC|1)
#define	CE_PUT32		(CE_IOC|2)
#define CE_GET_TX_RING_SZ	(CE_IOC|3)
#define CE_GET_TX_DESC		(CE_IOC|4)
#define CE_GLOBAL_RESET		(CE_IOC|5)
#define CE_TX_SIDE_RESET	(CE_IOC|6)
#define CE_RX_SIDE_RESET	(CE_IOC|7)
#define CE_RESET_MAC		(CE_IOC|8)

#define	CE_GET_MII		(CE_IOC|11)
#define	CE_PUT_MII		(CE_IOC|12)

#ifdef _KERNEL
typedef enum  {
                DVMA,
                DMA,
                SDMA
} dma_method_t;

typedef enum {
	MIF_POLL_STOP,
	MIF_POLL_START
} soft_mif_enable_t, *p_soft_mif_enable_t;

typedef enum {
	NO_XCVR,
	INT_MII_XCVR,
	EXT_MII_XCVR,
	PCS_XCVR
} xcvr_inuse_t, *p_xcvr_inuse_t;

#ifdef TX_ONE_BUF
#define TX_BCOPY_MAX 1514
#else
#define TX_BCOPY_MAX 256
#endif
#define TX_STREAM_MIN 512
#define TX_FASTDVMA_MIN 1024
typedef enum {
	NONE,
	SMALL,
	MEDIUM,
	LARGE
} dma_size_t;

typedef enum {
	USE_NONE,
	USE_BCOPY,
	USE_DVMA,
	USE_DMA,
	USE_SDMA
} dma_type_t;

typedef enum {
	NOT_IN_USE,
	HDR_BUF,
	MTU_BUF,
	RE_ASSEMBLY_BUF,
	FREE_BUF
} rx_page_state_t;

typedef struct {
	uint32_t msg_type;
	dma_type_t dma_type;
} block_mv_t;

/*
 * Definitions for module_info.
 */
#define	CE_IDNUM	(132)		/* module ID number */
#define	CE_NAME		"ce"		/* module name */
#define	CE_MINPSZ	(0)		/* min packet size */
#define	CE_MAXPSZ	(ETHERMTU)	/* max packet size */
#define	CE_HIWAT	(2048 * CE_MAXPSZ)
					/* hi-water mark */
#define	CE_LOWAT	(1)		/* lo-water mark */
#define	CE_HIWAT_MAX	(192000 * CE_MAXPSZ)
#define	CE_HIWAT_MIN	(2 * CE_MAXPSZ)
#define	CE_LOWAT_MAX	(192000 * CE_MAXPSZ)
#define	CE_LOWAT_MIN	(1)

#ifndef	D_HOTPLUG
#define	D_HOTPLUG	0x00
#endif

#ifdef	SUNTRUNKING
#define	GETRUNK
#include	<sys/nettr.h>
#include	<sys/nettr_ge.h>
#endif

#define	INIT_BUCKET_SIZE	16	/* Initial Hash Bucket Size */
#define	NMCFILTER_REGS		NMCFILTER_BITS/HASH_REG_WIDTH
					/* Number of multicast filter regs */
typedef enum {
	ndd_instance,
	ndd_autoneg,
	ndd_anar_1000fdx,
	ndd_anar_1000hdx,
	ndd_anar_100T4,
	ndd_anar_100fdx,
	ndd_anar_100hdx,
	ndd_anar_10fdx,
	ndd_anar_10hdx,
	ndd_anar_asmpause,
	ndd_anar_pause,
	ndd_master_cfg_enable,
	ndd_master_cfg_value,
	ndd_use_int_xcvr,
	ndd_enable_ipg0,
	ndd_ipg0,
	ndd_ipg1,
	ndd_ipg2,
	ndd_rx_intr_pkts,
	ndd_rx_intr_time,
	ndd_red_dv4to6k,
        ndd_red_dv6to8k,
	ndd_red_dv8to10k,
	ndd_red_dv10to12k,
	ndd_tx_dma_weight,
	ndd_rx_dma_weight,
	ndd_infinite_burst,
	ndd_disable_64bit,
#ifdef ACCEPT_JUMBO
	ndd_accept_jumbo,
#endif
#ifdef LAGGR
	ndd_laggr_multistream,
#endif
#ifdef AIC_FEATURE
	ndd_aic_max_pkts,
	ndd_aic_max_latency,
#endif
#ifdef CSFB_FIX
	ndd_link_status,
	ndd_link_mode,
	ndd_link_speed,
#endif
} ndd_param_index_t;

/*
 * Named Dispatch Parameter Management Structure
 */
typedef struct _ndd_param_t {
	uint32_t minimum;
	uint32_t maximum;
	uint32_t value;
	uint32_t old_value;
	char   *fcode_name;
	char   *name;
} ndd_param_t, *p_ndd_param_t;

typedef enum {
	ce_lb_normal,
	ce_lb_ext1000,
	ce_lb_ext100,
	ce_lb_ext10,
	ce_lb_phy1000,
	ce_lb_phy,
	ce_lb_serdes,
	ce_lb_mac1000,
	ce_lb_mac
} ce_lb_t;
	
typedef struct ether_addr ether_addr_st, *p_ether_addr_t;
typedef struct ether_header ether_header_t, *p_ether_header_t;
typedef queue_t *p_queue_t;
typedef mblk_t *p_mblk_t;

/*
 * Private DLPI full dlsap address format.
 */
typedef struct _ce_dladdr_t {
	ether_addr_st dl_phys;
	uint16_t dl_sap;
} ce_dladdr_t, *p_ce_dladdr_t;

/*
 * Per stream flags.
 */
typedef union _sb_flags_t {
	uint32_t value;
	struct {
		uint32_t fast_mode:1;
		uint32_t raw_mode:1;
		uint32_t ndd_mode:1;
		uint32_t hw_tcp_ck_on:1;
		uint32_t zero_copy:1;
		uint32_t lb_mode:1;
		uint32_t qos_mode:1;
		uint32_t trunk_mode:1;
		uint32_t intr_mode:1;
	} bits;
} sb_flags_t, *p_sb_flags_t;

typedef struct _mc_addr_t {
	ether_addr_st multcast_addr;
	uint_t mc_addr_cnt;	
} mc_addr_t, *p_mc_addr_t;	

typedef struct _mc_bucket_t {
	p_mc_addr_t addr_list;
	uint_t list_size;
} mc_bucket_t, *p_mc_bucket_t;

typedef struct _mc_table_t {
	p_mc_bucket_t bucket_list;
	uint_t buckets_used;
} mc_table_t, *p_mc_table_t;

typedef struct _hash_filter_t {
	uint_t hash_ref_cnt;
	uint16_t hash_filter_regs[NMCFILTER_REGS];
	uint32_t hash_bit_ref_cnt[NMCFILTER_BITS];
} hash_filter_t, *p_hash_filter_t;

typedef struct _filter_t {
	uint32_t all_phys_cnt;
	uint32_t all_multicast_cnt;
	uint32_t all_sap_cnt;
} filter_t, *p_filter_t;

/*
 * Per-Stream information.
 *
 * Each instance is dynamically allocated at open() and free'd
 * at close().  Each per-Stream instance points to at most one
 * per-device structure using the sb_gep field.  All instances
 * are threaded together into one list of active instances
 * ordered on minor device number.
 */

typedef struct _ce_str_t {
	struct _ce_str_t *sb_nextp;	/* next in list */
	struct _ce_str_t *sb_ce_nextp;	/* list associated with an instance. */
	struct _ce_str_t *sb_pstr_nxt;
	struct _ce_str_t *sb_mstr_nxt;
	struct _ce_str_t *sb_sap_nextp;	/* list associated with a sap. */
	queue_t	*sb_rq;			/* pointer to our rq */
	struct _ce_t *sb_cep;		/* attached device */
	t_uscalar_t sb_state;		/* current DL state */
	t_uscalar_t sb_sap;		/* bound sap */
	filter_t filter;		/* Current stream filter. */
	sb_flags_t sb_flags;		/* misc. flags */
	uint32_t sb_notifications;	/* DLPI notifications */
	minor_t sb_minor;		/* minor device number */
	mc_table_t sb_mctab;		/* Multicast Address table. */
	kmutex_t sb_lock;		/* protect this structure */
	int	(*sb_canputp)();
					/* Control canput procedure upstream */
	void	(*sb_putp)();
					/* Control put procedure for upstream */
	int	(*sb_start)();
					/* Control start procedure */
#ifdef	VLAN
	vlan_stream_handle_t	vlan_stream_handle; /* VLAN opaque stream handle */
#endif
#ifdef LAGGR
	void	*laggr_frmstr;		/* laggr module handle ; laggr_pt */
#endif
	t_uscalar_t	sb_style;	/* In which style the stream opened */
	t_uscalar_t	sb_ppa;		/* ppa for real minor nodes */
} ce_str_t, *p_ce_str_t;

typedef struct _ce_sap_node_t {
	struct _ce_sap_node_t *left;
	struct _ce_sap_node_t *right;
	struct _ce_sap_node_t *root;
	t_uscalar_t sap;
	p_ce_str_t str_list;
	uint_t str_cnt;
} ce_sap_node_t, *p_ce_sap_node_t;

typedef enum {
	NO_MSG = 0x0,		/* No message output or storage. */
	CONSOLE = 0x1,		/* Messages are go to the console. */
	BUFFER = 0x2,		/* Messages are go to the system buffer. */
	CON_BUF = 0x3,		/* Messages are go to the console and */
				/* system buffer. */
	VERBOSE = 0x4		/* Messages are go out only in VERBOSE node. */
} out_msg_t, *p_out_msg_t;

typedef enum {
	DBG_NO_MSG = 0x0,	/* No message output or storage. */
	DBG_CONSOLE = 0x1,	/* Messages are go to the console. */
	DBG_BUFFER = 0x2,	/* Messages are go to the system buffer. */
	DBG_CON_BUF = 0x3,	/* Messages are go to the console and */
				/* system buffer. */
	STR_LOG = 4		/* Sessage sent to streams logging driver. */
} out_dbgmsg_t, *p_out_dbgmsg_t;

typedef enum {
	NO_DEBUG,
	RX_CTL,
	VPD_CTL,
	DDI_CTL,
	MEM_CTL,
	SAP_CTL,
	IOC_CTL,
	MOD_CTL,
	DMA_CTL,
	STR_CTL,
	MDT_CTL,
	PATH,
	INT_CTL,
	KST_CTL,
	PCS_CTL,
	MII_CTL,
	MIF_CTL,
	DBG_ALL
} debug_level_t, *p_debug_level_t;

#ifdef CE_DEBUG
#define CE_DEBUG_MSG(params) ce_debug_msg params 
#else
#define CE_DEBUG_MSG(params)
#endif

#ifdef TX_DEBUG
#define TX_HIST_ELEMENTS 100000

typedef struct _ce_txhist_t {
	uint_t pkt_cnt;
	uint_t frag_cnt;
	uint_t frag_index;
	uint64_t tdes0;
	uint64_t tdes1;
	uint64_t frag_data[2];
} ce_txhist_t, *p_ce_txhist_t;
#endif

typedef struct _tx_msg_t {
	block_mv_t flags;
	caddr_t small_dma_block;        /* Premapped small DMA block. */
	ddi_dma_handle_t small_dma_handle;
	uint64_t small_dma_ioaddr;
	ddi_dma_handle_t dma_handle;
	ddi_dma_handle_t dvma_handle;
	p_mblk_t tx_message;             /* The block being transitted.*/
	uint32_t tx_msg_size;
	ddi_dma_cookie_t dma_cookie;
	size_t bytes_used;
	int head;
	int tail;
} tx_msg_t, *p_tx_msg_t;

typedef struct _tx_ring_t {
	kmutex_t lock;
	uint8_t index;
	uint_t size;
	uint_t wrap_mask;
	uint_t rd_index;
	uint_t wr_index;
	uint_t descs_pending;
	boolean_t queueing;
	ddi_dma_handle_t descriptors_h;
	ddi_acc_handle_t descriptors_mh; 
	p_tx_desc_t descriptors_vp;
	ddi_dma_cookie_t descriptors_pp;
	p_tx_msg_t msg_ring;
	ddi_dma_handle_t tiny_buf_h;
	ddi_acc_handle_t tiny_buf_mh; 
	kmutex_t dvma_lock;
	uint_t dvma_wr_index;
	uint_t dvma_rd_index;
	uint_t dvma_pending;
	uint_t dvma_available;
	uint_t dvma_wrap_mask;
	ddi_dma_handle_t *dvma_ring;
	kmutex_t sq_lock;
	p_mblk_t head;
	p_mblk_t tail;
#ifdef TX_DEBUG
	uint_t ce_txpkt_cnt;
	p_ce_txhist_t txhist_base;
	p_ce_txhist_t txhist;
#endif
#ifdef ONE_PKT_KICK
	boolean_t wait_for_tx_all;
#endif
} tx_ring_t, *p_tx_ring_t;

typedef struct _tx_rings_t {
	p_tx_ring_t *rings;
	ddi_dma_handle_t comp_wrb_h;
	ddi_acc_handle_t comp_wrb_mh;
	uint16_t *comp_wrb_vp;
	ddi_dma_cookie_t comp_wrb_pp;
} tx_rings_t, *p_tx_rings_t;

typedef struct _rx_msg_t {
	kmutex_t lock;
	boolean_t in_use;
	uint32_t ref_cnt;
	frtn_t freeb;
	uint32_t old_frtn_t;		/* For backward compatibility 2.5.1 */
	uint32_t old_frtn_t1;		/* For backward compatibility 2.5.1 */
	ddi_dma_cookie_t dma_ioaddr;
	size_t bytes_arrived;
	size_t bytes_expected;
	uchar_t *buffer;
	size_t size;
	uint32_t pri;
	p_mblk_t rx_message;
} rx_msg_t, *p_rx_msg_t;

typedef struct _rx_dma_handle_t {
	block_mv_t flags;
	ddi_dma_handle_t dma_handle;
} rx_dma_handle_t, *p_rx_dma_handle_t;

typedef struct _flow_tab_t {
	int pkt_cnt;
	int drainq_index; /* cpu id */
	p_mblk_t mmd_msg;
	boolean_t release_flow;
	p_mblk_t first;
	p_mblk_t last;
	uint32_t flow_id;
} flow_tab_t, *p_flow_tab_t;


#define MAX_FLOWS_PENDING 2048
#define PFIFO_REDTHR1   1024
#define PFIFO_RED1CNT   32
#define PFIFO_REDTHR2   1536
#define PFIFO_RED2CNT   16
#define PFIFO_REDTHR3   (PFIFO_QDEPTH-1)
#define PFIFO_QDEPTH    2048
#define PFIFO_QMASK     (PFIFO_QDEPTH-1)


typedef struct _ce_taskq_t {
	struct _ce_t *cep;
	taskq_t *drain_queue; /* taskid */
	boolean_t drain_pending; /*acts like exit flag*/
	uint32_t flows_pending; /* total number of elements in queue */
	int wr_index; /* acts like tail */
	int rd_index; /* acts like head */
	uint32_t taskid;
	kmutex_t lock;
	flow_tab_t flow_tab[MAX_FLOWS_PENDING];
    p_mblk_t   mblk_tab[MAX_FLOWS_PENDING];
    uint32_t active_threads;
    
#define CETHREAD_RUNNING       0
#define CETHREAD_MUSTEXIT      1
#define CETHREAD_EXITING       2
    uint16_t        REDmark;
    uint16_t        REDcnt;
    uchar_t         exitflag;
        
} ce_taskq_t, *p_ce_taskq_t;

#ifdef RX_DEBUG
#define RXBUF_HIST_ELEMENTS 100000

typedef struct _ce_rxbufhist_t {
	uint_t buf_cnt;
	uint64_t rdes0;
	uint64_t rdes1;
} ce_rxbufhist_t, *p_ce_rxbufhist_t;
#endif

#ifdef RX_DEBUG
#define RXCOMP_HIST_ELEMENTS 100000

typedef struct _ce_rxcomphist_t {
	uint_t comp_cnt;
	uint64_t rdes0;
	uint64_t rdes1;
	uint64_t rdes2;
	uint64_t rdes3;
} ce_rxcomphist_t, *p_ce_rxcomphist_t;
#endif

typedef struct _rx_ring_t {
	uint_t comp_size;
	uint_t comp_wrap_mask;
	uint_t comp_rd_index;
	ddi_dma_handle_t comp_desc_ring_h;
	ddi_acc_handle_t comp_desc_ring_mh;
	p_rx_c_desc_t comp_desc_ring_vp;
	ddi_dma_cookie_t comp_desc_ring_pp;
#ifdef RX_DEBUG
	uint_t ce_rxcomp_cnt;
	p_ce_rxcomphist_t rxcomphist_base;
	p_ce_rxcomphist_t rxcomphist;
#endif
} rx_ring_t, *p_rx_ring_t;

typedef struct _rx_rings_t {
	kmutex_t lock;
	p_rx_ring_t *rings;
	uint_t buf_size;
	uint_t buf_wrap_mask;
	uint_t buf_wr_index;
	ddi_dma_handle_t buf_desc_ring_h;
	ddi_acc_handle_t buf_desc_ring_mh;
	p_rx_b_desc_t buf_desc_ring_vp;
	ddi_dma_cookie_t buf_desc_ring_pp;
	p_rx_msg_t *rx_msg_ring;
	p_rx_msg_t *rx_msg_spares;
	p_rx_dma_handle_t rx_dma_handles;
	p_rx_dma_handle_t rx_dma_spare_hdls;
	p_flow_tab_t flow_tab;
	p_srv_fifo_t *srv_fifos;
	p_ce_taskq_t *taskq_tab;/* pts to cpu arrays of queues */
#ifdef RX_DEBUG
	uint_t ce_rxbuf_cnt;
	p_ce_rxbufhist_t rxbufhist_base;
	p_ce_rxbufhist_t rxbufhist;
#endif
	uint32_t *dispatch_tab;
} rx_rings_t, *p_rx_rings_t;

typedef struct _ce_stats_t {
	/*
	 *  Overall structure size
	 */
	size_t		stats_size;

	/*
	 * Link Input/Output stats
	 */
	uint64_t	ipackets;
	uint64_t	ierrors;
	uint64_t	opackets;
	uint64_t	oerrors;
	uint64_t	collisions;

	/*
	 * MIB II variables
	 */
	uint64_t	rbytes;		/* # bytes received */
	uint64_t	obytes;		/* # bytes transmitted */
	uint32_t	multircv;	/* # multicast packets received */
	uint32_t	multixmt;	/* # multicast packets for xmit */
	uint32_t	brdcstrcv;	/* # broadcast packets received */
	uint32_t	brdcstxmt;	/* # broadcast packets for xmit */
	uint32_t	norcvbuf;	/* # rcv packets discarded */
	uint32_t	noxmtbuf;	/* # xmit packets discarded */

	/*
	 * Transmit MAC statistics.
	 */
	uint32_t	first_collision;
	uint32_t	excessive_collisions;
	uint32_t	late_collisions;
	uint32_t	peak_attempts;

	/*
	 * Receive MAC statistics.
	 */
	uint32_t	length_err;
	uint32_t	alignment_err;
	uint32_t	crc_err;
	uint32_t	code_violations;

	uint16_t	rev_id;

        /*
         * Transciever state informations.
         */
	uint32_t	xcvr_inits;
	xcvr_inuse_t	xcvr_inuse;
	uint32_t	xcvr_addr;
        uint32_t	xcvr_id;
        uint32_t	cap_autoneg;
        uint32_t	cap_1000fdx;
        uint32_t	cap_1000hdx;
        uint32_t	cap_100T4;
        uint32_t	cap_100fdx;
        uint32_t	cap_100hdx;
        uint32_t	cap_10fdx;
        uint32_t	cap_10hdx;
        uint32_t	cap_asmpause;
        uint32_t	cap_pause;

	/*
	 * Advertised capabilities.
	 */
	uint32_t	adv_cap_autoneg;
	uint32_t	adv_cap_1000fdx;
	uint32_t	adv_cap_1000hdx;
	uint32_t	adv_cap_100T4;
	uint32_t	adv_cap_100fdx;
	uint32_t	adv_cap_100hdx;
	uint32_t	adv_cap_10fdx;
	uint32_t	adv_cap_10hdx;
	uint32_t	adv_cap_asmpause;
	uint32_t	adv_cap_pause;

	/*
	 * Link partner capabilities.
	 */
	uint32_t	lp_cap_autoneg;
	uint32_t	lp_cap_1000fdx;
	uint32_t	lp_cap_1000hdx;
	uint32_t	lp_cap_100T4;
	uint32_t	lp_cap_100fdx;
	uint32_t	lp_cap_100hdx;
	uint32_t	lp_cap_10fdx;
	uint32_t	lp_cap_10hdx;
	uint32_t	lp_cap_asmpause;
	uint32_t	lp_cap_pause;

	/*
	 * Physical link statistics.
	 */
	uint32_t	link_T4;
	uint32_t        link_speed;
	uint32_t        link_duplex;
	uint32_t        link_asmpause;
	uint32_t        link_pause;
	uint32_t        link_up;

	/*
	 * Lets the user know the MTU currently in use by
	 * the physical MAC port.
	 */
	uint32_t        mac_mtu;
#ifdef SATURNB2_WA
	/*
	 * Saturn Collision hang.
	 */
	uint32_t        mac_reset;
#endif
	ce_lb_t		lb_mode;
	uint32_t	qos_mode;
	uint32_t	trunk_mode;

	/*
	 * Tx Statistics.
	 */
	uint32_t	tx_inits;
	uint32_t	tx_starts;
	uint32_t	tx_nocanput;
	uint32_t	tx_msgdup_fail;
	uint32_t	tx_allocb_fail;
	uint32_t	tx_no_desc;
	uint32_t	tx_dma_bind_fail;
	uint32_t	tx_max_pkt_err;
	uint32_t	tx_uflo;
	uint32_t	tx_queue[NO_OF_TX_RINGS];

	uint32_t	tx_hdr_pkts;
	uint32_t	tx_ddi_pkts;
	uint32_t	tx_dvma_pkts;

#ifdef MULTI_DATA_TX
	uint32_t	mdt_reqs;
	uint32_t	mdt_hdr_bufs;
	uint32_t	mdt_pld_bufs;
	uint32_t	mdt_pkts;
	uint32_t	mdt_hdrs;
	uint32_t	mdt_plds;
	uint32_t	mdt_hdr_bind_fail;
	uint32_t	mdt_pld_bind_fail;
#endif

#ifdef ACCEPT_JUMBO
	uint32_t	tx_jumbo_pkts;
#endif
#ifdef TX_MBLK_DEST
	uint32_t	tx_1_desc;
	uint32_t	tx_2_desc;
	uint32_t	tx_3_desc;
	uint32_t	tx_4_desc;
	uint32_t	tx_5_desc;
	uint32_t	tx_6_desc;
	uint32_t	tx_7_desc;
	uint32_t	tx_8_desc;
	uint32_t	tx_max_desc;
#endif
	uint32_t	tx_max_pend;

	/*
	 * Rx Statistics.
	 */
	uint32_t	rx_inits;
#ifdef ACCEPT_JUMBO
	uint32_t	rx_jumbo_pkts;
#endif
	uint32_t	rx_hdr_pkts;
	uint32_t	rx_mtu_pkts;
	uint32_t	rx_split_pkts;
	uint32_t	rx_no_buf;
	uint32_t	rx_no_comp_wb;
	uint32_t	rx_ov_flow;
	uint32_t	rx_len_mm;
	uint32_t	rx_tag_err;
	uint32_t	rx_nocanput;
	uint32_t	rx_msgdup_fail;
	uint32_t	rx_allocb_fail;

	/*
	 * Receive buffer management statistics.
	 */
	uint32_t	rx_new_pages;
	uint32_t	rx_new_hdr_pgs;
	uint32_t	rx_new_mtu_pgs;
	uint32_t	rx_new_nxt_pgs;
	uint32_t	rx_reused_pgs;
	uint32_t	rx_hdr_drops;
	uint32_t	rx_mtu_drops;
	uint32_t	rx_nxt_drops;

#ifdef MULTI_DATA
	uint32_t	rx_mdr_pkts;
#endif
	/*
	 * Receive flow statistics
	 */
	uint32_t	rx_rel_flow;
	uint32_t	rx_rel_bit;

	uint32_t	rx_pkts_dropped;

	/*
	 * PCI Bus Statistics.
	 */
	uint32_t	pci_bus_speed;
	uint32_t	pci_err;
	uint32_t	pci_rta_err;
	uint32_t	pci_rma_err;
	uint32_t	pci_parity_err;
	uint32_t	pci_bad_ack_err;
	uint32_t	pci_drto_err;
	uint32_t	pci_dmawz_err;
	uint32_t	pci_dmarz_err;

	uint32_t	rx_taskq_waits;
	uint32_t	taskq_disable;

	/*
	 * Some statistics added to support bringup, these
	 * should be removed.
	 */
	uint32_t	user_defined;

} ce_stats_t, *p_ce_stats_t;

/*
 * CE Device Channel instance state information.
 *
 * Each instance is dynamically allocated on first attach.
 */
typedef struct _ce_t {
	dev_info_t	*dip;		/* associated dev_info */
	int		instance;	/* instance number */
	p_dev_regs_t	dev_regs;
	p_soft_regs_t	soft_regs;
	p_ce_stats_t	statsp;
	kstat_t		*ksp;
	p_ndd_param_t	param_arr;
	caddr_t		ndd_list;

	ether_addr_st	factaddr;	/* factory mac address */
	ether_addr_st	ouraddr;	/* individual address */
	kmutex_t	ouraddr_lock;	/* Lock to protect the ouraddr. */

	p_ce_str_t	str_list;	/* All streams open to this instance. */
	p_ce_str_t	pstr_list;	/* Promiscuous for this instance. */
	p_ce_str_t	mstr_list;	/* Multicast for this instance. */
	p_ce_sap_node_t sap_tree;	/* Sap tree. */

	krwlock_t	str_list_rxlock;/* Lock to protect the list. */
	void		*padding0[2];	/* Padding for solaris 2.6 support. */
	kmutex_t	str_list_txlock;/* Lock to protect the list. */

	ddi_iblock_cookie_t	interrupt_cookie;

	int suspended;			/* suspention state of the driver */
	mii_bmsr_t bmsr;		/* xcvr status at last poll. */
	mii_bmsr_t soft_bmsr;		/* xcvr status kept by software. */
	kmutex_t mif_lock;		/* Lock to protect the list. */
	
	filter_t filter;		/* Current instance filter */
	p_hash_filter_t hash_filter;	/* Multicast hash filter. */
	krwlock_t	filter_lock;	/* Lock to protect the filters. */
	void		*padding1[2];	/* Padding for solaris 2.6 support. */

	p_tx_rings_t tx_rings;

	p_rx_rings_t rx_rings;

	ddi_dma_handle_t dmasparehandle;

	ulong_t sys_page_sz;
	ulong_t sys_page_mask;
	ulong_t sys_burst_sz;

	uint8_t cache_line;

	timeout_id_t ce_pcs_poll_timerid;

	uint_t need_periodic_reclaim;
	timeout_id_t reclaim_timer;

	uint8_t msg_min;
	uint8_t crc_size;
#ifdef SATURNB2_WA
	uint32_t tx_pkts_pend;
#endif
	rnd_handle_t rnd_handle;

#ifdef TEST_ENCRYPTION
	p_rx_rings_t rxenc_rings;
#endif	
#ifdef	SUNTRUNKING
	getrunk_t	*trunkp;	/* trunking ptr if trunked */
	ether_addr_st	savaddr;	/* used in trunking */
	struct nettr_stats stats;
#endif
#ifdef AIC_FEATURE
	int aic_trend;
	int aic_pkts;
	int aic_fls;
#endif
	boolean_t hard_props_read;

	boolean_t ce_htraffic;		/* True: Heavly network traffic*/
	uint32_t ce_ncpus;		/* number of cpus */
	uint32_t ce_cpumask;
	uint32_t ce_intrpkt;		/* consective intrs with single pkt*/
	uchar_t ce_rxmode;      
	uint32_t active_threads;
#define RX_INTR 0
#define RX_THREAD 1
#ifdef	VLAN
	vlan_info_handle_t vlan_info_handle; /* VLAN opaque info handle */
#endif

#ifdef LAGGR
	uint_t	laggr_flags;	/* DISABLED | ENABLED | AGGREGATED | LINKUP.. */
	void	*laggr_frmdev;	/* laggr module handle : laggr_pt */
	void	*laggr_def_frmdev;	/* def. laggr module handle :laggr_pt */
#endif
	int	taskq_disable;
} ce_t, *p_ce_t;

#define STOP_POLL_THRESH 9
#define START_POLL_THRESH 2
typedef struct _ce_kstat_t {
	/*
	 * Link Input/Output stats
	 */
	kstat_named_t	ipackets;
	kstat_named_t	ipackets64;
	kstat_named_t	ierrors;
	kstat_named_t	opackets;
	kstat_named_t	opackets64;
	kstat_named_t	oerrors;
	kstat_named_t	collisions;

	/*
	 * required by kstat for MIB II objects(RFC 1213)
	 */
	kstat_named_t	rbytes; 	/* # octets received */
						/* MIB - ifInOctets */
	kstat_named_t	rbytes64;
	kstat_named_t	obytes; 	/* # octets transmitted */
						/* MIB - ifOutOctets */
	kstat_named_t	obytes64;
	kstat_named_t	multircv; 	/* # multicast packets */
						/* delivered to upper layer */
						/* MIB - ifInNUcastPkts */
	kstat_named_t	multixmt; 	/* # multicast packets */
						/* requested to be sent */
						/* MIB - ifOutNUcastPkts */
	kstat_named_t	brdcstrcv;	/* # broadcast packets */
						/* delivered to upper layer */
						/* MIB - ifInNUcastPkts */
	kstat_named_t	brdcstxmt;	/* # broadcast packets */
						/* requested to be sent */
						/* MIB - ifOutNUcastPkts */
	kstat_named_t	norcvbuf; 	/* # rcv packets discarded */
						/* MIB - ifInDiscards */
	kstat_named_t	noxmtbuf; 	/* # xmt packets discarded */
						/* MIB - ifOutDiscards */

	/*
	 * Transmit MAC statistics.
	 */
	kstat_named_t	first_collision;
	kstat_named_t	excessive_collisions;
	kstat_named_t	late_collisions;
	kstat_named_t	peak_attempts;

	/*
	 * Receive MAC statistics.
	 */
	kstat_named_t	length_err;
	kstat_named_t	alignment_err;
	kstat_named_t	crc_err;
	kstat_named_t	code_violations;

	kstat_named_t	ifspeed; 
	kstat_named_t	promisc; 
	kstat_named_t	rev_id; 

	/*
	 * Transciever state informations.
	 */
	kstat_named_t	xcvr_inits;
	kstat_named_t	xcvr_inuse;
	kstat_named_t	xcvr_addr;
	kstat_named_t	xcvr_id;
	kstat_named_t	cap_autoneg;
	kstat_named_t	cap_1000fdx;
	kstat_named_t	cap_1000hdx;
	kstat_named_t	cap_100T4;
	kstat_named_t	cap_100fdx;
	kstat_named_t	cap_100hdx;
	kstat_named_t	cap_10fdx;
	kstat_named_t	cap_10hdx;
	kstat_named_t	cap_asmpause;
	kstat_named_t	cap_pause;

	/*
	 * Advertised capabilities.
	 */
	kstat_named_t	adv_cap_autoneg;
	kstat_named_t	adv_cap_1000fdx;
	kstat_named_t	adv_cap_1000hdx;
	kstat_named_t	adv_cap_100T4;
	kstat_named_t	adv_cap_100fdx;
	kstat_named_t	adv_cap_100hdx;
	kstat_named_t	adv_cap_10fdx;
	kstat_named_t	adv_cap_10hdx;
	kstat_named_t	adv_cap_asmpause;
	kstat_named_t	adv_cap_pause;

	/*
	 * Link partner capabilities.
	 */
	kstat_named_t	lp_cap_autoneg;
	kstat_named_t	lp_cap_1000fdx;
	kstat_named_t	lp_cap_1000hdx;
	kstat_named_t	lp_cap_100T4;
	kstat_named_t	lp_cap_100fdx;
	kstat_named_t	lp_cap_100hdx;
	kstat_named_t	lp_cap_10fdx;
	kstat_named_t	lp_cap_10hdx;
	kstat_named_t	lp_cap_asmpause;
	kstat_named_t	lp_cap_pause;

	/*
	 * Shared link setup.
	 */
	kstat_named_t	link_T4;
	kstat_named_t	link_speed;
	kstat_named_t	link_duplex;
	kstat_named_t	link_asmpause;
	kstat_named_t	link_pause;
	kstat_named_t	link_up;
	
	/*
	 * Lets the user know the MTU currently in use by
	 * the physical MAC port.
	 */
	kstat_named_t	mac_mtu;
#ifdef SATURNB2_WA
	/*
	 * Saturn Collision hang.
	 */
	kstat_named_t	mac_reset;
#endif
	kstat_named_t	lb_mode;
	kstat_named_t	qos_mode;
	kstat_named_t	trunk_mode;

	/*
	 * Tx Statistics.
	 */
	kstat_named_t	tx_inits;
	kstat_named_t	tx_starts;
	kstat_named_t	tx_nocanput;
	kstat_named_t	tx_msgdup_fail;
	kstat_named_t	tx_allocb_fail;
	kstat_named_t	tx_no_desc;
	kstat_named_t	tx_dma_bind_fail;
	kstat_named_t	tx_max_pkt_err;
	kstat_named_t	tx_uflo;
	kstat_named_t	tx_queue[NO_OF_TX_RINGS];

	kstat_named_t	tx_hdr_pkts;
	kstat_named_t	tx_ddi_pkts;
	kstat_named_t	tx_dvma_pkts;

#ifdef MULTI_DATA_TX
	kstat_named_t	mdt_reqs;
	kstat_named_t	mdt_hdr_bufs;
	kstat_named_t	mdt_pld_bufs;
	kstat_named_t	mdt_pkts;
	kstat_named_t	mdt_hdrs;
	kstat_named_t	mdt_plds;
	kstat_named_t	mdt_hdr_bind_fail;
	kstat_named_t	mdt_pld_bind_fail;
#endif
#ifdef ACCEPT_JUMBO
	kstat_named_t	tx_jumbo_pkts;
#endif
#ifdef TX_MBLK_DEST
	kstat_named_t	tx_1_desc;
	kstat_named_t	tx_2_desc;
	kstat_named_t	tx_3_desc;
	kstat_named_t	tx_4_desc;
	kstat_named_t	tx_5_desc;
	kstat_named_t	tx_6_desc;
	kstat_named_t	tx_7_desc;
	kstat_named_t	tx_8_desc;
	kstat_named_t	tx_max_desc;
#endif
	kstat_named_t	tx_max_pend;

	/*
	 * Rx Statistics.
	 */
	kstat_named_t	rx_inits;
#ifdef ACCEPT_JUMBO
	kstat_named_t	rx_jumbo_pkts;
#endif
	kstat_named_t	rx_hdr_pkts;
	kstat_named_t	rx_mtu_pkts;
	kstat_named_t	rx_split_pkts;
	kstat_named_t	rx_no_buf;
	kstat_named_t	rx_no_comp_wb;
	kstat_named_t	rx_ov_flow;
	kstat_named_t	rx_len_mm;
	kstat_named_t	rx_tag_err;
	kstat_named_t	rx_nocanput;
	kstat_named_t	rx_msgdup_fail;
	kstat_named_t	rx_allocb_fail;

	/*
	 * Receive buffer management statistics.
	 */
	kstat_named_t	rx_new_pages;
	kstat_named_t	rx_new_hdr_pgs;
	kstat_named_t	rx_new_mtu_pgs;
	kstat_named_t	rx_new_nxt_pgs;
	kstat_named_t	rx_reused_pgs;
	kstat_named_t	rx_hdr_drops;
	kstat_named_t	rx_mtu_drops;
	kstat_named_t	rx_nxt_drops;

#ifdef MULTI_DATA
	kstat_named_t	rx_mdr_pkts;
#endif
	/*
	 * Receive flow statistics
	 */
	kstat_named_t	rx_rel_flow;
	kstat_named_t	rx_rel_bit;
	
	kstat_named_t   rx_pkts_dropped;

	/*
	 * PCI Bus Statistics.
	 */
	kstat_named_t	pci_bus_speed;
	kstat_named_t	pci_err;
	kstat_named_t	pci_rta_err;
	kstat_named_t	pci_rma_err;
	kstat_named_t	pci_parity_err;
	kstat_named_t	pci_bad_ack_err;
	kstat_named_t	pci_drto_err;
	kstat_named_t	pci_dmawz_err;
	kstat_named_t	pci_dmarz_err;

	kstat_named_t	rx_taskq_waits;
	kstat_named_t	taskq_disable;

	/*
	 * Some statistics added to support bringup, these
	 * should be removed.
	 */
	kstat_named_t	user_defined;

} ce_kstat_t, *p_ce_kstat_t;

#pragma weak taskq_create
#pragma weak taskq_destroy
#pragma weak taskq_dispatch
#pragma weak taskq_wait
#pragma weak pci_report_pmcap

#pragma	weak ddi_check_acc_handle
#pragma	weak ddi_check_dma_handle
#pragma	weak ddi_dev_report_fault
#pragma	weak ddi_get_devstate
#pragma	weak _u4ft_ddi_check_access
#pragma	weak _u4ft_ddi_report_fault
#pragma	weak _u4ft_ddi_dev_is_usable
extern uint_t _u4ft_ddi_check_access(ddi_acc_handle_t);
extern void _u4ft_ddi_report_fault(dev_info_t *,
			ddi_fault_impact_t, const char *);
extern int _u4ft_ddi_dev_is_usable(dev_info_t *, boolean_t);

#pragma weak vlan_vid_stream_free
#pragma weak vlan_setinfo_cl_qos
#pragma weak vlan_info_free
#pragma weak vlan_read_format
#pragma weak vlan_kstat_update
#pragma weak vlan_stream_sap_find_one
#pragma weak vlan_info_alloc
#pragma weak vlan_stat_update_kname
#pragma weak vlan_stream_sap_register
#pragma weak vlan_set_cl_qos_req
#pragma weak vlan_is_vlan_dev
#pragma weak vlan_is_vlan_pkt
#pragma weak vlan_vid_stream_alloc
#pragma weak vlan_unitdata_req
#pragma weak vlan_set_sbind_req
#pragma weak vlan_set_fast_b_band_q
#pragma weak vlan_set_subind_req
#pragma weak vlan_mkfastpath_eheader
#pragma weak vlan_send_up_match
#pragma weak vlan_stream_sap_unregister

#pragma weak laggr_reg_dev
#pragma weak laggr_unreg_dev
#pragma weak laggr_get_dev
#pragma weak laggr_get_trunkhead
#pragma weak laggr_reg_sap
#pragma weak laggr_unreg_sap
#pragma weak laggr_reg_mcaddr
#pragma weak laggr_unreg_mcaddr
#pragma weak laggr_set_mac_addr
#pragma weak laggr_ioc
#pragma weak laggr_update_active_links
#pragma weak laggr_get_mac_addr
#pragma weak laggr_get_str
#pragma weak laggr_set_qos
#pragma weak trunk_version

#pragma weak rnd_provider_register
#pragma weak rnd_provider_unregister

#pragma weak is_vmloaned_mblk

#define taskq_create(a, b, c, d, e, f) \
	(taskq_create != NULL ? taskq_create(a, b, c, d, e, f) : (taskq_t *)1)
#define taskq_destroy(a) \
	if (taskq_destroy != NULL) taskq_destroy(a)
#ifdef TQ_DEFAULTPRI
#define taskq_dispatch(a, b, c, d, e) \
	(taskq_dispatch != NULL ? taskq_dispatch(a, b, c, d, e) : 0)
#else
#define TQ_DEFAULTPRI KM_NOSLEEP
#define taskq_dispatch(a, b, c, d, e) \
	(taskq_dispatch != NULL ? taskq_dispatch(a, b, c, e) : 0)
#endif
#ifndef TQ_NOSLEEP
#define TQ_NOSLEEP KM_NOSLEEP
#endif
#define taskq_wait(a) \
	if (taskq_wait != NULL) taskq_wait(a)
#define pci_report_pmcap(a, b, c) \
	(pci_report_pmcap != NULL ? pci_report_pmcap(a, b, c) : 0)

#ifdef HARDENING
#define	ddi_check_acc_handle(a) \
	(ddi_check_acc_handle != NULL ? ddi_check_acc_handle(a) : \
		(_u4ft_ddi_check_access != NULL ? \
			(_u4ft_ddi_check_access(a) == 1 ? \
				DDI_FAILURE : DDI_SUCCESS) : \
		DDI_SUCCESS))
#define	ddi_check_dma_handle(a) \
	(ddi_check_dma_handle != NULL ? ddi_check_dma_handle(a) :\
		(_u4ft_ddi_check_access != NULL ? \
			(_u4ft_ddi_check_access(a) == 2 ? \
				DDI_FAILURE : DDI_SUCCESS) : \
		DDI_SUCCESS))
#define	ddi_dev_report_fault(a, b, c, m) \
	if (ddi_dev_report_fault != NULL) \
		ddi_dev_report_fault(a, b, c, m); \
	else if (_u4ft_ddi_report_fault != NULL) \
		_u4ft_ddi_report_fault(a, b, m); \
	else if (b == DDI_SERVICE_RESTORED) { \
		cmn_err(CE_NOTE, "ce%d: %s", ddi_get_instance(a), m); \
	} else if (b == DDI_SERVICE_DEGRADED) { \
		cmn_err(CE_WARN, "ce%d: %s", ddi_get_instance(a), m); \
	}

#define	ddi_get_devstate(a) \
	(ddi_get_devstate != NULL ? ddi_get_devstate(a) :\
		(_u4ft_ddi_dev_is_usable != NULL ? \
			(_u4ft_ddi_dev_is_usable(a, B_FALSE) == 2001 ? \
				DDI_DEVSTATE_OFFLINE : \
			(_u4ft_ddi_dev_is_usable(a, B_FALSE) == 42 ? \
				DDI_DEVSTATE_DEGRADED : \
			(_u4ft_ddi_dev_is_usable(a, B_FALSE) == 123 ? \
				DDI_DEVSTATE_UP : \
			(_u4ft_ddi_dev_is_usable(a, B_FALSE) == 999 ? \
				DDI_DEVSTATE_DEGRADED : \
			(_u4ft_ddi_dev_is_usable(a, B_FALSE) == 666 ? \
				DDI_DEVSTATE_DOWN : DDI_DEVSTATE_UP))))) :\
		DDI_DEVSTATE_UP))
#else
#define	ddi_check_acc_handle(a) DDI_SUCCESS
#define	ddi_check_dma_handle(a) DDI_SUCCESS
#define	ddi_dev_report_fault(a, b, c, d)
#define	ddi_get_devstate(a) DDI_DEVSTATE_UP
#endif

#define vlan_vid_stream_free(b) \
	(vlan_vid_stream_free != NULL ? vlan_vid_stream_free(b) : 1)
#define vlan_setinfo_cl_qos(a, b, c) \
	(vlan_setinfo_cl_qos != NULL ? vlan_setinfo_cl_qos(a, b, c) : b)
#define vlan_info_free(a) \
	if (vlan_info_free != NULL) vlan_info_free(a)
#define vlan_read_format(a, b) \
	(vlan_read_format != NULL ? vlan_read_format(a, b) : NULL)
#define vlan_kstat_update(a, b, c) \
	(vlan_kstat_update != NULL ? vlan_kstat_update(a, b, c) : 1)
#define vlan_stream_sap_find_one(a, b, c, d) \
	(vlan_stream_sap_find_one != NULL ? \
		vlan_stream_sap_find_one(a, b, c, d) : VLAN_FAILURE)
#define vlan_info_alloc(a, b, c, d) \
	(vlan_info_alloc != NULL ? vlan_info_alloc(a, b, c, d) : 1)
#define vlan_stat_update_kname(a, b, c, d) \
	(vlan_stat_update_kname != NULL ? \
		vlan_stat_update_kname(a, b, c, d) : 1)
#define vlan_stream_sap_register(a, b) \
	(vlan_stream_sap_register != NULL ? vlan_stream_sap_register(a, b) : 1)
#define vlan_set_cl_qos_req(a, b) \
	(vlan_set_cl_qos_req != NULL ? vlan_set_cl_qos_req(a, b) : 1)
#define vlan_is_vlan_dev(a) \
	(vlan_is_vlan_dev != NULL ? vlan_is_vlan_dev(a) : VLAN_FAILURE)
#define	vlan_is_vlan_pkt(a) \
	vlan_is_vlan_pkt != NULL ? vlan_is_vlan_pkt(a) : 0)
#define vlan_vid_stream_alloc(a, b, c, d, e) \
	(vlan_vid_stream_alloc != NULL ? \
	vlan_vid_stream_alloc(a, b, c, d, e) : 0)
#define vlan_unitdata_req(a, b, c, d, e) \
	(vlan_unitdata_req != NULL ? vlan_unitdata_req(a, b, c, d, e) : NULL)
#define vlan_set_sbind_req(a, b) \
	(vlan_set_sbind_req != NULL ? vlan_set_sbind_req(a, b) : 1)
#define vlan_set_fast_b_band_q(a, b) \
	(vlan_set_fast_b_band_q != NULL ? vlan_set_fast_b_band_q(a, b) : 1)
#define vlan_set_subind_req(a, b) \
	(vlan_set_subind_req != NULL ? vlan_set_subind_req(a, b) : 1)
#define vlan_mkfastpath_eheader(a, b, c, d, e) \
	(vlan_mkfastpath_eheader != NULL ? \
		vlan_mkfastpath_eheader(a, b, c, d, e) : NULL)
#define vlan_send_up_match(a, b, c) \
	(vlan_send_up_match != NULL ? \
		vlan_send_up_match(a, b, c) : VLAN_NOT_VLAN_PKT)
#define vlan_stream_sap_unregister(a, b) \
	(vlan_stream_sap_unregister != NULL ? \
		vlan_stream_sap_unregister(a, b) : 1)

#define laggr_reg_dev(a, b, c, d) \
	(laggr_reg_dev != NULL ? laggr_reg_dev(a, b, c, d) : NULL)
#define laggr_unreg_dev(a, b) \
	(laggr_unreg_dev != NULL ? laggr_unreg_dev(a, b) : 1)
#define laggr_get_dev(a, b, c) \
	(laggr_get_dev  != NULL ? laggr_get_dev(a, b, c) : 0)
#define laggr_get_trunkhead(a) \
	(laggr_get_trunkhead != NULL ? laggr_get_trunkhead(a) : NULL)
#define laggr_reg_sap(a, b, c) \
	(laggr_reg_sap != NULL ? laggr_reg_sap(a, b, c) : NULL)
#define laggr_unreg_sap(a, b, c) \
	(laggr_unreg_sap != NULL ? laggr_unreg_sap(a, b, c) : 1)
#define laggr_reg_mcaddr(a, b, c, d, e) \
	(laggr_reg_mcaddr != NULL ? laggr_reg_mcaddr(a, b, c, d, e) : 1)
#define laggr_unreg_mcaddr(a, b, c, d) \
	(laggr_unreg_mcaddr != NULL ? laggr_unreg_mcaddr(a, b, c, d) : 1)
#define laggr_set_mac_addr(a, b) \
	if (laggr_set_mac_addr != NULL) 	\
		laggr_set_mac_addr(a, b);
#define laggr_ioc(a, b, c, d, e) \
	if (laggr_ioc != NULL) \
		laggr_ioc(a, b, c, d, e)
#define laggr_update_active_links(a, b, c, d) \
	(laggr_update_active_links != NULL ? \
	laggr_update_active_links(a, b, c, d) : 1)
#define laggr_get_mac_addr(a) \
	(laggr_get_mac_addr != NULL ? laggr_get_mac_addr(a) : 0)
#define laggr_get_str(a, b, c, d, e) \
	(laggr_get_str != NULL ? laggr_get_str(a, b, c, d, e) : 0)
#define laggr_set_qos(a, b, c) \
	if (laggr_set_qos != NULL) \
		laggr_set_qos(a, b, c);

#define rnd_provider_register(a, b) \
	(rnd_provider_register != NULL ? \
		rnd_provider_register(a, b) : 0)
#define rnd_provider_unregister(a) \
	(rnd_provider_unregister != NULL ? \
		rnd_provider_unregister(a) : 0)

#define is_vmloaned_mblk(a, b, c) \
	(is_vmloaned_mblk != NULL ? \
		is_vmloaned_mblk(a, b, c) : 0)

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif
