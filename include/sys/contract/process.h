/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_CONTRACT_PROCESS_H
#define	_SYS_CONTRACT_PROCESS_H

#pragma ident	"@(#)process.h	1.1	04/07/15 SMI"

#include <sys/contract.h>
#include <sys/time.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct ctmpl_process ctmpl_process_t;
typedef struct cont_process cont_process_t;

/*
 * ctr_params flags
 */
#define	CT_PR_INHERIT	0x1	/* give contract to parent */
#define	CT_PR_NOORPHAN	0x2	/* kill when contract is abandoned */
#define	CT_PR_PGRPONLY	0x4	/* only kill process group on fatal errors */
#define	CT_PR_REGENT	0x8	/* automatically detach inherited contracts */
#define	CT_PR_ALLPARAM	0xf

/*
 * ctr_ev_* flags
 */
#define	CT_PR_EV_EMPTY	0x1	/* contract is empty */
#define	CT_PR_EV_FORK	0x2	/* process was forked (and was added) */
#define	CT_PR_EV_EXIT	0x4	/* process exited (and left contract) */
#define	CT_PR_EV_CORE	0x8	/* process dumps core */
#define	CT_PR_EV_SIGNAL	0x10	/* process received fatal signal */
#define	CT_PR_EV_HWERR	0x20	/* process experienced uncorrectable error */
#define	CT_PR_ALLEVENT	0x3f
#define	CT_PR_ALLFATAL	(CT_PR_EV_CORE | CT_PR_EV_SIGNAL | CT_PR_EV_HWERR)

/*
 * ctp_id values
 */
#define	CTPP_EV_FATAL		0
#define	CTPP_PARAMS		1
#define	CTPP_SUBSUME		2

/*
 * Status fields
 */
#define	CTPS_PARAMS		"ctps_params"
#define	CTPS_EV_FATAL		"ctps_ev_fatal"
#define	CTPS_MEMBERS		"ctps_members"
#define	CTPS_CONTRACTS		"ctps_contracts"

/*
 * Event fields
 */
#define	CTPE_PID	"ctpe_pid"
#define	CTPE_PPID	"ctpe_ppid"
#define	CTPE_ZCOREFILE	"ctpe_zcorefile"
#define	CTPE_GCOREFILE	"ctpe_gcorefile"
#define	CTPE_PCOREFILE	"ctpe_pcorefile"
#define	CTPE_SIGNAL	"ctpe_signal"
#define	CTPE_SENDER	"ctpe_sender"
#define	CTPE_SENDCT	"ctpe_sendct"
#define	CTPE_EXITSTATUS	"ctpe_exitstatus"

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_CONTRACT_PROCESS_H */
