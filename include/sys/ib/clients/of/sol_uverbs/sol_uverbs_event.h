/*
 * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_IB_CLIENTS_OF_SOL_UVERBS_SOL_UVERBS_EVENT_H
#define	_SYS_IB_CLIENTS_OF_SOL_UVERBS_SOL_UVERBS_EVENT_H

#pragma ident	"@(#)sol_uverbs_event.h	1.1	10/05/14 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 *
 * NAME: sol_uverbs_event.h
 *
 * DESC: Solaris User Verbs Kernel Async Event structures and definitions.
 *
 */


/*
 * Functions - See sol_uverbs_event.c for descriptions.
 */
uverbs_ufile_uobj_t *uverbs_alloc_event_file(uverbs_uctxt_uobj_t *uctxt,
    int is_async);

void uverbs_release_event_file(sol_ofs_uobj_t *uobj);

void uverbs_async_event_handler(void *clnt_private, ibt_hca_hdl_t hca_hdl,
    ibt_async_code_t code, ibt_async_event_t *event);

void uverbs_release_ucq_channel(uverbs_uctxt_uobj_t *uctxt,
    uverbs_ufile_uobj_t *comp_chan, uverbs_ucq_uobj_t *ucq);

void uverbs_release_ucq_uevents(uverbs_ufile_uobj_t *ev_file,
    uverbs_ucq_uobj_t *ucq);

void uverbs_release_uqp_uevents(uverbs_ufile_uobj_t *ev_file,
    uverbs_uqp_uobj_t *uqp);

void uverbs_release_usrq_uevents(uverbs_ufile_uobj_t *ev_file,
    uverbs_usrq_uobj_t *usrq);

void sol_uverbs_event_file_close(uverbs_ufile_uobj_t *);

int sol_uverbs_event_file_read(uverbs_ufile_uobj_t *, struct uio *uiop,
    cred_t *cred);

int sol_uverbs_event_file_poll(uverbs_ufile_uobj_t *, short events, int anyyet,
    short *reventsp, pollhead_t **phpp);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_IB_CLIENTS_OF_SOL_UVERBS_SOL_UVERBS_EVENT_H */
