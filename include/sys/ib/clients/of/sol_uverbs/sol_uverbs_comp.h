/*
 * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_IB_CLIENTS_OF_SOL_UVERBS_SOL_UVERBS_COMP_H
#define	_SYS_IB_CLIENTS_OF_SOL_UVERBS_SOL_UVERBS_COMP_H

#pragma ident	"@(#)sol_uverbs_comp.h	1.1	10/05/14 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 *
 * NAME: sol_uverbs_comp.h
 *
 * DESC: OFED User Verbs Kernel Completion Queue related defines and structures.
 *
 */


/*
 * Definitions
 */

/*
 * Structures
 */

/*
 * Functions - See sol_uverbs_comp.c for descriptions.
 */
int
sol_uverbs_create_cq(uverbs_uctxt_uobj_t *uctxt, char *buf, int in_len,
								int out_len);

int
sol_uverbs_destroy_cq(uverbs_uctxt_uobj_t *uctxt, char *buf, int in_len,
								int out_len);

int
sol_uverbs_resize_cq(uverbs_uctxt_uobj_t *uctxt, char *buf, int in_len,
								int out_len);

int
sol_uverbs_req_notify_cq(uverbs_uctxt_uobj_t *uctxt, char *buf, int in_len,
								int out_len);

int
sol_uverbs_poll_cq(uverbs_uctxt_uobj_t *uctxt, char *buf, int in_len,
								int out_len);

void
sol_uverbs_comp_event_handler(ibt_cq_hdl_t ibt_cq, void *arg);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_IB_CLIENTS_OF_SOL_UVERBS_SOL_UVERBS_COMP_H */
