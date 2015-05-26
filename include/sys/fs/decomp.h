/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1983, 1984, 1985, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*
 * University Copyright- Copyright (c) 1982, 1986, 1988
 * The Regents of the University of California
 * All Rights Reserved
 *
 * University Acknowledgment- Portions of this document are derived from
 * software developed by the University of California, Berkeley, and its
 * contributors.
 */

#ifndef	_SYS_DECOMP_H
#define	_SYS_DECOMP_H

#pragma ident	"@(#)decomp.h	1.1	08/06/06 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#define	CH_MAGIC	0x5a636d70	/* Zcmp */

#define	CH_VERSION	1

#define	CH_ALG_ZLIB	1

struct comphdr {
	uint64_t	ch_magic;
	uint64_t	ch_version;
	uint64_t	ch_algorithm;
	uint64_t	ch_fsize;
	uint64_t	ch_blksize;
	uint64_t	ch_blkmap[1];
};

#define	ZMAXBUF(n)	((n) + ((n) / 1000) + 12)

#ifdef	_KERNEL

struct dcnode {
	struct vnode	*dc_vp;
	struct vnode	*dc_subvp;
	struct kmem_cache *dc_bufcache;
	kmutex_t	dc_lock;
	struct dcnode	*dc_hash;
	struct dcnode	*dc_lrunext;
	struct dcnode	*dc_lruprev;
	struct comphdr	*dc_hdr;
	size_t		dc_hdrsize;
	size_t		dc_zmax;
	int		dc_mapcnt;
};

#define	VTODC(vp)	((struct dcnode *)(vp)->v_data)
#define	DCTOV(dp)	((dp)->dc_vp)

struct vnode	*decompvp(struct vnode *, struct cred *);

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DECOMP_H */
