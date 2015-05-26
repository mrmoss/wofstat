/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_IB_ADAPTERS_MLNX_UMAP_H
#define	_SYS_IB_ADAPTERS_MLNX_UMAP_H

#pragma ident	"@(#)mlnx_umap.h	1.4	08/12/03 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * mlnx_umap.h
 *	Contains all of the definions necessary for communicating the data
 *	needed for direct userland access to resources on Mellanox HCAs.
 */

/*
 * Note: The structs in this file are used in the interface(s)
 *	between kernel service drivers, e.g. daplt, and the libraries
 *	on top of them, e.g. udapl_tavor.so.1.  When any of the
 *	structs in this file change, any version control between the
 *	kernel service driver and the library will need to change.
 *
 * There is a version control on the structs defined here.  The library
 * (consumer of structs from ibt_ci_data_out()) must verify a version
 * field to correctly read the data provided by the kernel driver
 * (tavor, arbel, and hermon).
 */

#define	MLNX_UMAP_IF_VERSION	2

/*
 * The following defines are used in the database type field for each database
 * entry.  They specify the type of object (UAR pages, PIDs, CQ, QP, and MR
 * umemcookie) that corresponds to the database key value.  On database queries,
 * this type value must match the search criterion.
 */
#define	MLNX_UMAP_UARPG_RSRC		0x11
#define	MLNX_UMAP_BLUEFLAMEPG_RSRC	0x12
#define	MLNX_UMAP_PID_RSRC		0x22
#define	MLNX_UMAP_CQMEM_RSRC		0x33
#define	MLNX_UMAP_QPMEM_RSRC		0x44
#define	MLNX_UMAP_MRMEM_RSRC		0x55
#define	MLNX_UMAP_SRQMEM_RSRC		0x66
#define	MLNX_UMAP_DBRMEM_RSRC		0x77
#define	MLNX_UMAP_RSRC_TYPE_MASK	0xFF
#define	MLNX_UMAP_RSRC_TYPE_SHIFT	8

/* umap structures */

typedef struct mlnx_umap_cq_data_out_s {
	uint_t		mcq_rev;
	uint32_t	mcq_cqnum;
	uint64_t	mcq_mapoffset;
	uint64_t	mcq_maplen;
	uint32_t	mcq_numcqe;
	uint32_t	mcq_cqesz;

	/* Arbel/Hermon doorbell records */
	uint64_t	mcq_armdbr_mapoffset;
	uint64_t	mcq_armdbr_maplen;
	uint64_t	mcq_polldbr_mapoffset;
	uint64_t	mcq_polldbr_maplen;
	uint32_t	mcq_armdbr_offset;
	uint32_t	mcq_polldbr_offset;
} mlnx_umap_cq_data_out_t;

typedef struct mlnx_umap_qp_data_out_s {
	uint_t		mqp_rev;
	uint32_t	mqp_qpnum;
	uint64_t	mqp_mapoffset;
	uint64_t	mqp_maplen;

	uint32_t	mqp_rq_off;
	uint32_t	mqp_rq_desc_addr;
	uint32_t	mqp_rq_numwqe;
	uint32_t	mqp_rq_wqesz;

	uint32_t	mqp_sq_off;
	uint32_t	mqp_sq_desc_addr;
	uint32_t	mqp_sq_numwqe;
	uint32_t	mqp_sq_wqesz;

	/* Arbel/Hermon doorbell records */
	uint64_t	mqp_sdbr_mapoffset;
	uint64_t	mqp_sdbr_maplen;
	uint64_t	mqp_rdbr_mapoffset;
	uint64_t	mqp_rdbr_maplen;
	uint32_t	mqp_sdbr_offset;
	uint32_t	mqp_rdbr_offset;

	/* Hermon send queue headroom, in units of wqes */
	uint32_t	mqp_sq_headroomwqes;
} mlnx_umap_qp_data_out_t;

typedef struct mlnx_umap_srq_data_out_s {
	uint_t		msrq_rev;
	uint32_t	msrq_srqnum;
	uint64_t	msrq_mapoffset;
	uint64_t	msrq_maplen;
	uint32_t	msrq_desc_addr;
	uint32_t	msrq_numwqe;
	uint32_t	msrq_wqesz;
	uint32_t	msrq_pad1;	/* reserved */

	/* Arbel/Hermon doorbell records */
	uint64_t	msrq_rdbr_mapoffset;
	uint64_t	msrq_rdbr_maplen;
	uint32_t	msrq_rdbr_offset;
	uint32_t	msrq_reserved;
} mlnx_umap_srq_data_out_t;

typedef struct mlnx_umap_pd_data_out_s {
	uint_t		mpd_rev;
	uint32_t	mpd_pdnum;
} mlnx_umap_pd_data_out_t;

#ifdef __cplusplus
}
#endif

#endif	/* _SYS_IB_ADAPTERS_MLNX_UMAP_H */
