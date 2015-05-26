/*
 * Copyright (c) 2000 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef	_SYS_VLAN_IF_H
#define	_SYS_VLAN_IF_H

#pragma	ident "@(#)vlan_if.h 1.8	04/07/29 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * vlan_if.h:
 *
 *	Exported interfaces between the VLAN loadable module
 *	misc/vlan (vlan.c) and the Ethernet Drivers.
 */

#define	VID_0		0		/* user priority information */
#define	VID_DEFAULT	1		/* default VID */
#define	VID_RESERVED	0x0fff		/* reserved */

/*
 * Need to override the compiler structure packing
 * since the hardware is not compatible with the compiler
 * packing.
 */
#pragma pack(2)

/*
 * 802.1Q ethernet protocol type
 */
typedef enum {
	ETHERVLAN_TAG	= 0x8100	/* 802.1Q ethernet protocol type */
} vlanProtocol_t;

#define	ETHERVLAN_TAG		0x8100
#define	VLAN_MAX_IEEE		4094
#define	VLAN_MAX_PPA_ALLOWED	1000
#define	VLAN_MAX_VID_ALLOWED	4094

/*
 * 802.1Q: ethernet-encoded tag header
 * 	TPID (tag protocol identifier): byte 1 and byte 2
 *	TCI  (tag control information): byte 2 and byte 3
 *
 */
typedef union vtci_s {
	uint16_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint16_t user_pri:3;	/* user priority (8 levels) */
		uint16_t cfi: 1;	/* canonical format indicator */
		uint16_t vid: 12;	/* VLAN identifier */
#else
		uint16_t vid: 12;	/* VLAN identifier */
		uint16_t cfi: 1;	/* canonical format indicator */
		uint16_t user_pri: 3;	/* user priority (8 levels) */
#endif
	} bits;
} vtci_t;

typedef struct vtaghdr_s {
	uint16_t	protocol;	/* protocol ID (0x8100) */
	vtci_t		tci;
} vtaghdr_t;

#define	VLAN_TAG_SIZE	(sizeof (vtaghdr_t))

/*
 * Should include /usr/include/sys/ethernet.h
 * before include vlan_if.h.
 */
typedef struct vlan_header {
	struct	ether_addr	ether_dhost;
	struct	ether_addr	ether_shost;
	vtaghdr_t 		ether_tag;
	ushort_t		ether_type;
} vlan_header_t;

/*
 * Restore to default packing.
 */
#pragma pack()

/*
 *      user priorities and traffic classes
 *      BACKGROUND (1) and SPARE (2) are lower than
 *	DEFAULT_BEST_EFFORT (0).
 *      NETWORK_CONTROL (7) is the highest priority
 */
typedef	enum	{
	DEFAULT_BEST_EFFORT,
	BACKGROUND,
	SPARE,
	EXCELLENT_EFFORT,
	CONTROLLED,
	VIDEO,
	VOICE,
	NETWORK_CONTROL
} vlan_pri_t;


typedef struct vlan_pri_strings {
	int8_t user_priority;
	char *traffic_type;
} vlan_pri_strings_t;

#ifdef	LATER

/*
 * list of user priorities:
 * vlan_priority[0] is lowest
 */
static struct vlan_pri_strings vlan_priority[] = {
	1, "Background",
	2, "Standard(spare)",
	0, "Best Effort(default)",
	3, "Excellent Effort(Business Critical)",
	4, "Controlled Load (Streaming Multimedia",
	5, "Video (Interactive Media, 100ms)",
	6, "Voice (Interactive Voice, 10ms)",
	7, "Network Control (Reserved Traffic)",
	-1, NULL
};
#endif

/*
 * DL_SUBS_BIND_REQ:
 *
 * For DLPI users such snoop if it wants to
 * capture all raw VLANs information.
 *
 */
#define	VLAN_ALL_VIDS	-1

#define	DLPI_ADD_SUB_BIND_TYPE
#ifdef DLPI_ADD_SUB_BIND_TYPE
#define	DL_SUN_VLAN_BIND	0xf000
#endif

#define	VLAN_HEADER_SIZE	(sizeof (vlan_header_t))
#define	ETHERNET_HEADER_SIZE	(sizeof (struct ether_header))

#define	VLAN_GET_VID(dl_ppa)	(dl_ppa / VLAN_MAX_PPA_ALLOWED)
#define	VLAN_GET_PPA(dl_ppa)	(dl_ppa % VLAN_MAX_PPA_ALLOWED)

#define	IS_VLAN_PACKET(ptr)	\
	(ntohs(((struct vlan_header *)ptr)-> \
			ether_tag.protocol) == ETHERVLAN_TAG)

#if defined(_KERNEL)

#define	DEPENDS_ON_VLAN		" misc/vlan"

/*
 * opaque info handle:
 *
 *	This VLAN info handle is returned when the vlan_info_alloc()
 *	successfully allocates a VLAN info handle structure. This handle
 *	is passed to some of other vlan interface functions.
 *
 */
typedef struct vlan_info_handle		*vlan_info_handle_t;

/*
 * opaque VLAN vid/qos stream handle:
 *
 *	This VLAN stream handle is returned when the vlan_vid_register()
 *	successfully allocates a VLAN vid/qos handle structure. This handle
 *	is passed to some of other vlan interface functions.
 *
 */
typedef struct vlan_stream_handle	*vlan_stream_handle_t;

/*
 * VLAN interface functions returned values.
 */
#define	VLAN_SUCCESS		0	/* Call succeeded */
#define	VLAN_BADADDR		1	/* DLSAP improper format */
#define	VLAN_BADPPA		2	/* Invalid PPA */
#define	VLAN_BADQOSTYPE		3	/* Invalid QOS parameters */
#define	VLAN_BAD_ARG		4	/* Invalid argument */
#define	VLAN_SEND_RAW		5	/* Send packet in raw mode */
#define	VLAN_ONE_SAP_VID	6	/* Only one SAP register */
#define	VLAN_IS_VLAN_PKT	7	/* Is a VLAN packet */
#define	VLAN_NOT_VLAN_PKT	8	/* Not a VLAN packet */
#define	VLAN_IS_VLAN_DEV	9	/* Is a VLAN device */
#define	VLAN_NOTSUPPORTED	10	/* Unsupported operation */
#define	VLAN_NOMEM		11	/* Unable to allocate memory */
#define	VLAN_FAILURE		12	/* unsuccessful completion */

/*
 * Exported interface functions.
 *
 */
extern	int vlan_info_alloc(char *, int, ddi_iblock_cookie_t,
	vlan_info_handle_t *);
extern	void vlan_info_free(vlan_info_handle_t *);

extern	int vlan_vid_stream_alloc(vlan_info_handle_t, t_uscalar_t,
	int (*)(), void *, vlan_stream_handle_t *);
extern	int vlan_vid_stream_free(vlan_stream_handle_t *);

extern	int vlan_stream_sap_register(vlan_stream_handle_t, t_uscalar_t);
extern	int vlan_stream_sap_unregister(vlan_stream_handle_t, t_uscalar_t);
extern	int vlan_stream_sap_find_one(vlan_stream_handle_t, vlan_info_handle_t,
	t_uscalar_t, uint16_t);

extern	void vlan_setinfo_mtu(vlan_stream_handle_t, mblk_t *);
extern	mblk_t *vlan_setinfo_cl_qos(vlan_stream_handle_t, mblk_t *, int *);

extern	int vlan_set_cl_qos_req(vlan_stream_handle_t, mblk_t *);
extern	void vlan_set_u_pri_to_band(mblk_t *, uchar_t);

extern	int vlan_set_sbind_req(vlan_stream_handle_t, mblk_t *);
extern	int vlan_set_subind_req(vlan_stream_handle_t, mblk_t *);

extern	uint32_t vlan_set_fast_b_band_q(vlan_stream_handle_t, mblk_t *);
extern	void vlan_set_b_band_default(mblk_t *, uint32_t *, uint32_t *);

extern	mblk_t *vlan_mkfastpath_eheader(vlan_stream_handle_t, mblk_t *,
		t_uscalar_t, struct ether_addr *, int *);
extern	mblk_t *vlan_unitdata_req(vlan_stream_handle_t, mblk_t *,
	t_uscalar_t, struct ether_addr *, int *);

extern	mblk_t *vlan_read_format(mblk_t *, int *);
extern	int vlan_read_proc(vlan_stream_handle_t, vlan_info_handle_t,
	mblk_t *);
extern	int vlan_vid_packet(vlan_stream_handle_t, mblk_t *);
extern	int vlan_send_up_match(vlan_stream_handle_t, mblk_t *, boolean_t);

extern  int vlan_kstat_update(vlan_info_handle_t, kstat_t *, int);
extern  int vlan_stat_update_kname(vlan_info_handle_t, mblk_t *,
	char *, uint32_t);

extern	int vlan_is_vlan_pkt(unsigned char *);
extern	int vlan_is_vlan_dev(vlan_stream_handle_t);


#endif  /* defined(_KERNEL) */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_VLAN_IF_H */
