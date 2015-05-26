/*
 * Copyright (c) 1994, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_SCSI_IMPL_SERVICES_H
#define	_SYS_SCSI_IMPL_SERVICES_H

#pragma ident	"@(#)services.h	1.46	11/03/04 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Implementation services not classified by type
 */

#ifdef	_KERNEL

#ifdef	__STDC__

struct scsi_key_strings {
	int key;
	char *message;
};

struct scsi_asq_key_strings {
	ushort_t asc;
	ushort_t ascq;
	char *message;
};

extern int scsi_poll(struct scsi_pkt *);
extern struct scsi_pkt *get_pktiopb(struct scsi_address *,
    caddr_t *datap, int cdblen, int statuslen,
    int datalen, int readflag, int (*func)());
extern void free_pktiopb(struct scsi_pkt *, caddr_t datap, int datalen);
extern char *scsi_dname(int dtyp);
extern char *scsi_rname(uchar_t reason);
extern char *scsi_mname(uchar_t msg);
extern char *scsi_cname(uchar_t cmd, char **cmdvec);
extern char *scsi_cmd_name(uchar_t cmd, struct scsi_key_strings *cmdlist,
    char *tmpstr);
extern char *scsi_sname(uchar_t sense_key);
extern char *scsi_esname(uint_t sense_key, char *tmpstr);
extern char *scsi_asc_name(uint_t asc, uint_t ascq, char *tmpstr);
extern void scsi_vu_errmsg(struct scsi_device *devp, struct scsi_pkt *pktp,
    char *drv_name, int severity, daddr_t blkno, daddr_t err_blkno,
    struct scsi_key_strings *cmdlist, struct scsi_extended_sense *sensep,
    struct scsi_asq_key_strings *asc_list,
    char *(*decode_fru)(struct scsi_device *, char *, int, uchar_t));
extern void scsi_errmsg(struct scsi_device *devp, struct scsi_pkt *pkt,
    char *label, int severity, daddr_t blkno, daddr_t err_blkno,
    struct scsi_key_strings *cmdlist, struct scsi_extended_sense *sensep);
/*PRINTFLIKE4*/
extern void scsi_log(dev_info_t *dev, char *label,
    uint_t level, const char *fmt, ...) __KPRINTFLIKE(4);

#else	/* __STDC__ */

extern int scsi_poll();
extern struct scsi_pkt *get_pktiopb();
extern void free_pktiopb();
extern char *scsi_dname(), *scsi_rname(), *scsi_cname(), *scsi_mname();
extern char *scsi_sname(), *scsi_esname(), *scsi_asc_name();
extern void scsi_vu_errmsg(), scsi_errmsg(), scsi_log();

#endif	/* __STDC__ */

extern char *scsi_state_bits;
extern char *sense_keys[NUM_SENSE_KEYS + NUM_IMPL_SENSE_KEYS];


#define	SCSI_DEBUG	0xDEB00000

#define	SCSI_ERR_ALL		0
#define	SCSI_ERR_UNKNOWN	1
#define	SCSI_ERR_INFO		2
#define	SCSI_ERR_RECOVERED	3
#define	SCSI_ERR_RETRYABLE	4
#define	SCSI_ERR_FATAL		5
#define	SCSI_ERR_NONE		6


/*
 * Common Capability Strings Array
 */
#define	SCSI_CAP_DMA_MAX		0
#define	SCSI_CAP_MSG_OUT		1
#define	SCSI_CAP_DISCONNECT		2
#define	SCSI_CAP_SYNCHRONOUS		3
#define	SCSI_CAP_WIDE_XFER		4
#define	SCSI_CAP_PARITY			5
#define	SCSI_CAP_INITIATOR_ID		6
#define	SCSI_CAP_UNTAGGED_QING		7
#define	SCSI_CAP_TAGGED_QING		8
#define	SCSI_CAP_ARQ			9
#define	SCSI_CAP_LINKED_CMDS		10
#define	SCSI_CAP_SECTOR_SIZE		11
#define	SCSI_CAP_TOTAL_SECTORS		12
#define	SCSI_CAP_GEOMETRY		13
#define	SCSI_CAP_RESET_NOTIFICATION	14
#define	SCSI_CAP_QFULL_RETRIES		15
#define	SCSI_CAP_QFULL_RETRY_INTERVAL	16
#define	SCSI_CAP_SCSI_VERSION		17
#define	SCSI_CAP_INTERCONNECT_TYPE	18
#define	SCSI_CAP_LUN_RESET		19
#define	SCSI_CAP_CDB_LEN		20
#define	SCSI_CAP_DMA_MAX_ARCH		21
#define	SCSI_CAP_TRAN_LAYER_RETRIES	22

#define	SCSI_CAP_ASCII		{				\
	"dma-max", "msg-out", "disconnect", "synchronous",	\
	"wide-xfer", "parity", "initiator-id", "untagged-qing",	\
	"tagged-qing", "auto-rqsense", "linked-cmds",		\
	"sector-size", "total-sectors", "geometry",		\
	"reset-notification", "qfull-retries",			\
	"qfull-retry-interval", "scsi-version",			\
	"interconnect-type", "lun-reset",			\
	"max-cdb-length", "dma-max-arch",			\
	"tran-layer-retries", NULL }

/*
 * Definitions used by some capabilities
 */
/*					SCSI_CAP_SCSI_VERSION */
#define	SCSI_VERSION_1			1
#define	SCSI_VERSION_2			2
#define	SCSI_VERSION_3			3

/*					SCSI_CAP_INTERCONNECT_TYPE */
#define	INTERCONNECT_PARALLEL		1
#define	INTERCONNECT_FIBRE		2	/* PLDA or hard ALPA */
#define	INTERCONNECT_1394		3
#define	INTERCONNECT_SSA		4	/* -EOLed */
#define	INTERCONNECT_FABRIC		5	/* soft ALPA or Switch */
#define	INTERCONNECT_USB		6
#define	INTERCONNECT_ATAPI		7
#define	INTERCONNECT_ISCSI		8
#define	INTERCONNECT_IBSRP		9
#define	INTERCONNECT_SATA		10
#define	INTERCONNECT_SAS		11
#define	INTERCONNECT_MAX		12	/* Change this appropriately, */
						/* as new one(s) are added.   */
						/* Is always the last & max.  */

/*					INTERCONNECT TYPE STRINGS */
#define	INTERCONNECT_PARALLEL_STR	"SPI"
#define	INTERCONNECT_FIBRE_STR		"FIBRE"
#define	INTERCONNECT_1394_STR		"1394"
#define	INTERCONNECT_SSA_STR		""
#define	INTERCONNECT_FABRIC_STR		"FABRIC"
#define	INTERCONNECT_USB_STR		"USB"
#define	INTERCONNECT_ATAPI_STR		"ATAPI"
#define	INTERCONNECT_ISCSI_STR		"iSCSI"
#define	INTERCONNECT_IBSRP_STR		"IB"
#define	INTERCONNECT_SATA_STR		"SATA"
#define	INTERCONNECT_SAS_STR		"SAS"
#define	INTERCONNECT_TYPE_ASCII		{				\
					"",				\
					INTERCONNECT_PARALLEL_STR,	\
					INTERCONNECT_FIBRE_STR,		\
					INTERCONNECT_1394_STR,		\
					INTERCONNECT_SSA_STR,		\
					INTERCONNECT_FABRIC_STR,	\
					INTERCONNECT_USB_STR,		\
					INTERCONNECT_ATAPI_STR,		\
					INTERCONNECT_ISCSI_STR,		\
					INTERCONNECT_IBSRP_STR,		\
					INTERCONNECT_SATA_STR,		\
					INTERCONNECT_SAS_STR,		\
					NULL				\
					};

/*
 * Compatibility...
 */

#define	scsi_cmd_decode	scsi_cname

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SCSI_IMPL_SERVICES_H */
