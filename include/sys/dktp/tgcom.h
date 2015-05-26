/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_DKTP_TGCOM_H
#define	_SYS_DKTP_TGCOM_H

#pragma ident	"@(#)tgcom.h	1.4	04/09/28 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

struct	tgcom_obj {
	opaque_t		com_data;
	struct tgcom_objops	*com_ops;
};

struct	tgcom_objops {
	int	(*com_init)(opaque_t);
	int	(*com_free)(struct tgcom_obj *);
	int	(*com_pkt)(opaque_t, struct buf *, int (*func)(caddr_t),
	    caddr_t);
	void	(*com_transport)(opaque_t, struct buf *);
	void	*com_resv[2];
};

#define	TGCOM_INIT(X) (*((struct tgcom_obj *)(X))->com_ops->com_init)\
	(((struct tgcom_obj *)(X))->com_data)
#define	TGCOM_FREE(X) (*((struct tgcom_obj *)(X))->com_ops->com_free) ((X))
#define	TGCOM_PKT(X, bp, cb, arg) \
	(*((struct tgcom_obj *)(X))->com_ops->com_pkt) \
		(((struct tgcom_obj *)(X))->com_data, (bp), (cb), (arg))
#define	TGCOM_TRANSPORT(X, bp) \
	(*((struct tgcom_obj *)(X))->com_ops->com_transport) \
		(((struct tgcom_obj *)(X))->com_data, (bp))

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DKTP_TGCOM_H */
