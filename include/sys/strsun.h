/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_STRSUN_H
#define	_SYS_STRSUN_H

#pragma ident	"@(#)strsun.h	1.27	06/05/03 SMI"

#include <sys/stream.h>
#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Solaris DDI STREAMS utility routines.
 *
 * See the appropriate section 9F manpage for documentation.
 */

#define	DB_BASE(mp)	((mp)->b_datap->db_base)
#define	DB_LIM(mp)	((mp)->b_datap->db_lim)
#define	DB_REF(mp)	((mp)->b_datap->db_ref)
#define	DB_TYPE(mp)	((mp)->b_datap->db_type)
#define	DB_FLAGS(mp)	((mp)->b_datap->db_flags)

#define	MBLKL(mp)	((mp)->b_wptr - (mp)->b_rptr)
#define	MBLKSIZE(mp)	((mp)->b_datap->db_lim - (mp)->b_datap->db_base)
#define	MBLKHEAD(mp)	((mp)->b_rptr - (mp)->b_datap->db_base)
#define	MBLKTAIL(mp)	((mp)->b_datap->db_lim - (mp)->b_wptr)
#define	MBLKIN(mp, off, len) (((off) <= MBLKL(mp)) && \
			(((mp)->b_rptr + (off) + (len)) <= (mp)->b_wptr))

#define	MBLK_GETLABEL(mp) \
	(DB_CRED(mp) != NULL ? crgetlabel(DB_CRED(mp)) : NULL)

#ifdef	_KERNEL
extern void	mcopyin(mblk_t *, void *, size_t, void *);
extern void	mcopyout(mblk_t *, void *, size_t, void *, mblk_t *);
extern void	merror(queue_t *, mblk_t *, int);
extern void	mioc2ack(mblk_t *, mblk_t *, size_t, int);
extern void	miocack(queue_t *, mblk_t *, int, int);
extern void	miocnak(queue_t *, mblk_t *, int, int);
extern int	miocpullup(mblk_t *, size_t);
extern mblk_t	*mexchange(queue_t *, mblk_t *, size_t, uchar_t, int32_t);
extern size_t	msgsize(mblk_t *);
extern void	mcopymsg(mblk_t *, void *);

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_STRSUN_H */
