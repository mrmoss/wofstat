/*
 * Copyright (c) 1992, 2010, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_AVINTR_H
#define	_SYS_AVINTR_H

#pragma ident	"@(#)avintr.h	1.16	10/11/04 SMI"

#include <sys/mutex.h>
#include <sys/dditypes.h>
#include <sys/ddi_intr.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Period of autovector structures (add this in to get the next level).
 */
#define	MAXIPL	16
#define	INT_IPL(x) (x)
#define	AV_INT_SPURIOUS	-1

#ifdef	__STDC__
typedef uint_t (*avfunc)(caddr_t, caddr_t);
#else
typedef uint_t (*avfunc)();
#endif	/* __STDC__ */

struct autovec {

	/*
	 * Interrupt handler and argument to pass to it.
	 */

	struct autovec *av_link;	/* pointer to next on in chain */
	uint_t	(*av_vector)();
	caddr_t	av_intarg1;
	caddr_t	av_intarg2;
	uint_t	av_prilevel;		/* priority level */

	/*
	 * Interrupt handle/id (like intrspec structure pointer) used to
	 * identify a specific instance of interrupt handler in case we
	 * have to remove the interrupt handler later.
	 *
	 */
	void	*av_intr_id;
	dev_info_t *av_dip;
	ushort_t	av_flags;	/* pending flags */
	struct autovec *av_ipl_link;	/* pointer to next on ipl chain */
};

#define	AV_PENTRY_VECTMASK	0xff	/* low 8 bit used for irqno */
#define	AV_PENTRY_PEND	0x100	/* pending hardware interrupt */
#define	AV_PENTRY_ONPROC	0x200	/* being serviced by CPU */
#define	AV_PENTRY_LEVEL	0x8000	/* level-triggered interrupt */

struct av_head {
	struct 	autovec	*avh_link;
	ushort_t	avh_hi_pri;
	ushort_t	avh_lo_pri;
};

/* softing contains a bit field of software interrupts which are pending */
struct softint {
	int st_pending;
};

#ifdef _KERNEL

extern kmutex_t av_lock;
extern ddi_softint_hdl_impl_t softlevel1_hdl;
extern int add_avintr(void *intr_id, int lvl, avfunc xxintr, char *name,
	int vect, caddr_t arg1, caddr_t arg2, dev_info_t *);
extern int add_nmintr(int lvl, avfunc nmintr, char *name, caddr_t arg);
extern int add_avsoftintr(void *intr_id, int lvl, avfunc xxintr,
	char *name, caddr_t arg1, caddr_t arg2);
extern int rem_avsoftintr(void *intr_id, int lvl, avfunc xxintr);
extern int av_softint_movepri(void *intr_id, int old_lvl);
extern void update_avsoftintr_args(void *intr_id, int lvl, caddr_t arg2);
extern void rem_avintr(void *intr_id, int lvl, avfunc xxintr, int vect);
extern void wait_till_seen(int ipl);
extern uint_t softlevel1(caddr_t, caddr_t);

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_AVINTR_H */
