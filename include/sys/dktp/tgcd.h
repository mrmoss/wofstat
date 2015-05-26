/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_DKTP_TGCD_H
#define	_SYS_DKTP_TGCD_H

#pragma ident	"@(#)tgcd.h	1.5	04/09/28 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(_LP64)

struct	tgcd_obj {
	opaque_t		cd_data;
	struct tgcd_objops	*cd_ops;
};

struct	tgcd_objops {
	int	(*cd_init)();
	int	(*cd_free)();
	int	(*cd_identify)();
	int	(*cd_ioctl)();
	int	cd_resv[2];
};

#define	TGCD_INIT(X, tgpassthruobjp) \
	(*((struct tgcd_obj *)(X))->cd_ops->cd_init)\
	(((struct tgcd_obj *)(X))->cd_data, (tgpassthruobjp))
#define	TGCD_FREE(X) (*((struct tgcd_obj *)(X))->cd_ops->cd_free) ((X))
#define	TGCD_IDENTIFY(X, inqp, dip) \
	(*((struct tgcd_obj *)(X))->cd_ops->cd_identify)\
		(((struct tgcd_obj *)(X))->cd_data, (inqp), (dip))
#define	TGCD_IOCTL(X, cmdp, dev, cmd, arg, flag) \
	(*((struct tgcd_obj *)(X))->cd_ops->cd_ioctl) \
	(((struct tgcd_obj *)(X))->cd_data, (cmdp), (dev), (cmd), (arg), (flag))

#endif /* !defined(_LP64) */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DKTP_TGCD_H */
