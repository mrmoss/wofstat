/*
 * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.
 */

/*
 * This is the Solaris uCMA header file. This contains Solaris specific
 * data structures and defines for the sol_ucma driver.
 */

#ifndef	_SYS_IB_CLIENTS_OF_SOL_UCMA_SOL_UCMA_H
#define	_SYS_IB_CLIENTS_OF_SOL_UCMA_SOL_UCMA_H

#pragma ident	"@(#)sol_ucma.h	1.1	10/05/14 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/ksynch.h>
#include <sys/ib/clients/of/ofa_solaris.h>
#include <sys/ib/clients/of/sol_ofs/sol_ofs_common.h>
#include <sys/ib/clients/of/sol_ucma/sol_rdma_user_cm.h>

/*
 * MAX Number of PATHS supported. This is the same as
 * supported by RDMA CM library API revisit - TBD
 *
 * MAX Number of Listens supported
 */
#define	SOL_UCMA_MAX_PATHS	2
#define	SOL_UCMA_MAX_LISTEN	128

/* Defines for file_evt_close_flag */
#define	SOL_UCMA_EVT_NONE	0x00
#define	SOL_UCMA_EVT_PROGRESS	0x01
#define	SOL_UCMA_EVT_DISABLED	0x02

/*
 * RDMA-CM Event File structure
 */
typedef struct {
	sol_ofs_uobj_t	file_uobj;
	kmutex_t	file_mutex;
	genlist_t	file_id_list;

	/*
	 * Events data
	 *	pollhead - for chpoll(9e)
	 *	event_cv - for blocking wait at GET_EVENT
	 *	evt_list - List of Events
	 *	pending_evt_cnt - Pending Events to be pushed
	 *		to userland.
	 */
	struct pollhead	*file_pollhead;
	kcondvar_t	file_evt_cv;
	kcondvar_t	file_evt_close_cv;
	genlist_t	file_evt_list;
	uint32_t	file_pending_evt_cnt;
	uint8_t		file_evt_close_flag;
} sol_ucma_file_t;

typedef enum  {
	SOL_UCMA_FLUSH_QP_NONE,
	SOL_UCMA_FLUSH_QP_DONE,
	SOL_UCMA_FLUSH_QP_PENDING
} sol_ucma_flush_qp_t;

/*
 * Structure for each IDs created using rdma_create_id()
 */
#define	SOL_UCMA_CHAN_CONNECT_FLAG	0x01

typedef struct {
	sol_ofs_uobj_t		chan_uobj;
	kmutex_t		chan_mutex;
	genlist_entry_t		*chan_list_ent;
	sol_ucma_file_t		*chan_file;

	/* Channel id and user ID for this Channel */
	uint32_t		chan_id;
	uint64_t		chan_user_id;

	/* Total events for this channel */
	uint32_t		chan_evt_cnt;

	/* rdma_cm_id for this channel */
	struct rdma_cm_id	*chan_rdma_id;

	uint32_t		chan_qp_num;
	void			*chan_qp_hdl;

	/* Flush QP flag for this channel */
	sol_ucma_flush_qp_t	chan_flush_qp_flag;

	int			chan_backlog;

	uint16_t		chan_flags;
} sol_ucma_chan_t;

typedef struct sol_ucma_mcast_s {
	sol_ofs_uobj_t		mcast_uobj;
	uint64_t		mcast_uid;
	uint32_t		mcast_id;
	sol_ucma_chan_t		*mcast_chan;
	struct sockaddr		mcast_addr;
	uint32_t		mcast_events;
} sol_ucma_mcast_t;

/*
 * UCMA Event Structure
 */
typedef struct sol_ucma_event_s {
	sol_ucma_event_resp_t	event_resp;
	sol_ucma_chan_t		*event_chan;
	sol_ucma_mcast_t	*event_mcast;
} sol_ucma_event_t;

/*
 * Global structure for  Solaris UCMA Driver.
 */
#define	SOL_UCMA_CLNT_HDL_UNINITIALIZED	0x00
#define	SOL_UCMA_CLNT_HDL_INITIALIZING	0x01
#define	SOL_UCMA_CLNT_HDL_INITIALIZED	0x02
typedef struct sol_ucma_s {
	kmutex_t		ucma_mutex;
	kcondvar_t		ucma_open_cv;
	dev_info_t		*ucma_dip;
	uint_t			ucma_num_file;

	ldi_ident_t		ucma_ldi_ident;
	ldi_handle_t		ucma_ldi_hdl;
	ddi_modhandle_t		ucma_mod_hdl;

	void			*ucma_ib_clnt_hdl;
	void			*ucma_iw_clnt_hdl;

	/* Client Handle flag	*/
	uint8_t			ucma_clnt_hdl_flag;
} sol_ucma_t;

#ifdef __cplusplus
}
#endif

#endif /* _SYS_IB_CLIENTS_OF_SOL_UCMA_SOL_UCMA_H */
