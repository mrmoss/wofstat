/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_PROJECT_H
#define	_SYS_PROJECT_H

#pragma ident	"@(#)project.h	1.14	07/09/26 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/kstat.h>
#include <sys/types.h>
#include <sys/mutex.h>
#include <sys/rctl.h>
#include <sys/ipc_rctl.h>
#include <sys/zone.h>

typedef struct kproject_kstat {
	kstat_named_t kpk_zonename;
	kstat_named_t kpk_usage;
	kstat_named_t kpk_value;
} kproject_kstat_t;

typedef struct kproject_data {		/* Datum protected by: */
	rctl_qty_t	kpd_shmmax;	/* shm's ipcs_lock */
	ipc_rqty_t	kpd_ipc;	/* shm|sem|msg's ipcs lock */
	rctl_qty_t	kpd_devlockmem;	/* umem_devlockmem_rctl_lock */
	rctl_qty_t	kpd_locked_mem;	 /* zone_rctl_lock */
	rctl_qty_t	kpd_locked_mem_ctl; /* kpj_rctls->rcs_lock */
	rctl_qty_t	kpd_contract;	/* contract_lock */
	kmutex_t	kpd_crypto_lock;
	rctl_qty_t	kpd_crypto_mem;	/* crypto_rctl_lock */
	rctl_qty_t	kpd_crypto_mem_ctl; /* kpj_rctls->rcs_lock */
	kstat_t		*kpd_lockedmem_kstat; /* locked memory kstat */
} kproject_data_t;

struct cpucap;

/*
 * The first two fields of this structure must not be reordered.
 */
typedef struct kproject {
	projid_t 	kpj_id;		/* project ID		*/
	zoneid_t	kpj_zoneid;	/* zone ID		*/
	struct zone	*kpj_zone;	/* zone pointer		*/
	uint_t		kpj_count;	/* reference counter	*/
	uint32_t	kpj_shares;	/* number of shares	*/
	rctl_set_t	*kpj_rctls;	/* resource control set */
	struct kproject	*kpj_prev;	/* previous project	*/
	struct kproject	*kpj_next;	/* next project		*/
	kproject_data_t	kpj_data;	/* subsystem-specfic data */
	kmutex_t	kpj_poolbind;	/* synch. with pools	*/
	rctl_qty_t	kpj_nlwps;	/* protected by project's zone's */
					/* zone_nlwps_lock */
	rctl_qty_t	kpj_nlwps_ctl;	/* protected by kpj_rctls->rcs_lock */
	rctl_qty_t	kpj_ntasks;	/* protected by project's zone's */
					/* zone_nlwps_lock */
	rctl_qty_t	kpj_ntasks_ctl;	/* protected by kpj_rctls->rcs_lock */
	struct cpucap	*kpj_cpucap;	/* CPU cap data			*/
} kproject_t;

#ifdef _KERNEL

/*
 * Flags for project_hold_by_id()
 */
#define	PROJECT_HOLD_FIND	1
#define	PROJECT_HOLD_INSERT	2

struct zone;

void project_init(void);
kproject_t *project_hold(kproject_t *);
kproject_t *project_hold_by_id(projid_t, struct zone *, int);
void project_rele(kproject_t *);
int project_walk_all(zoneid_t, int (*)(kproject_t *, void *), void *);
projid_t curprojid(void);

extern kproject_t *proj0p;
extern rctl_hndl_t rc_project_nlwps;
extern rctl_hndl_t rc_project_ntasks;
extern rctl_hndl_t rc_project_locked_mem;
extern rctl_hndl_t rc_project_devlockmem;
extern rctl_hndl_t rc_project_crypto_mem;

#endif /* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_PROJECT_H */
