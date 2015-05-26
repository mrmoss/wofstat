/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_DKTP_TGPASSTHRU_H
#define	_SYS_DKTP_TGPASSTHRU_H

#pragma ident	"@(#)tgpassthru.h	1.4	04/09/28 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(_LP64)

struct	tgpassthru_obj {
	opaque_t			pt_data;
	struct tgpassthru_objops	*pt_ops;
};

struct	tgpassthru_objops {
	int	(*pt_init)();
	int	(*pt_free)();
	int	(*pt_transport)();
	void	*pt_resv[2];
};

#define	TGPASSTHRU_INIT(X) (*((struct tgpassthru_obj *)(X))->pt_ops->pt_init)\
	(((struct tgpassthru_obj *)(X))->pt_data)
#define	TGPASSTHRU_FREE(X) (*((struct tgpassthru_obj *)(X))->pt_ops->pt_free)\
	((X))
#define	TGPASSTHRU_TRANSPORT(X, cmdp, dev, flag) \
	(*((struct tgpassthru_obj *)(X))->pt_ops->pt_transport) \
	(((struct tgpassthru_obj *)(X))->pt_data, (cmdp), (dev), (flag))

#endif	/* !defined(_LP64) */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DKTP_TGPASSTHRU_H */
