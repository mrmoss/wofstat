/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS__MD_STRIPE_H
#define	_SYS__MD_STRIPE_H

#pragma ident	"@(#)md_stripe.h	2.5	04/09/29 SMI"

#include <sys/lvm/mdvar.h>
#include <sys/lvm/md_mirror_shared.h>
#include <sys/lvm/md_rename.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * ms_comp32_od is for old 32 bit format only
 */
#if _LONG_LONG_ALIGNMENT == 8 && _LONG_LONG_ALIGNMENT_32 == 4
#pragma pack(4)
#endif
typedef struct ms_comp32_od {
	mdkey_t		un_key;
	dev32_t		un_dev;
	daddr32_t	un_start_block;	/* comp start blkno */
	md_m_shared32_od_t un_mirror;
} ms_comp32_od_t;


typedef struct ms_comp {	/* components */
	mdkey_t		un_key;		/* namespace key */
	md_dev64_t	un_dev;		/* device number, 64 bit */
	diskaddr_t	un_start_block;	/* comp start blkno */
	md_m_shared_t	un_mirror;	/* mirror shared data */
} ms_comp_t;
#if _LONG_LONG_ALIGNMENT == 8 && _LONG_LONG_ALIGNMENT_32 == 4
#pragma pack()
#endif

/*
 * ms_unit32_od is for old 32 bit format only
 */
#if _LONG_LONG_ALIGNMENT == 8 && _LONG_LONG_ALIGNMENT_32 == 4
#pragma pack(4)
#endif
typedef struct ms_unit32_od {
	mdc_unit32_od_t	c;
	int		un_hsp_id;	/* hot spare pool db record id */
	uint_t		un_nrows;	/* number of rows */
	uint_t		un_ocomp;	/* offset of  ms_comp array  */
	struct ms_row32_od {
		int	un_icomp;	/* ms_comp array index of first comp */
		uint_t	un_ncomp;	/* # comps in this row */
		int	un_blocks;	/* total blocks in this row */
		int	un_cum_blocks;	/* cum. blks in this and prev. rows */
		int	un_interlace;	/* # blks from each disk in a stripe */
	}un_row[1];
} ms_unit32_od_t;


typedef struct ms_unit {
	mdc_unit_t	c;
	int		un_hsp_id;	/* hot spare pool db record id */
	uint_t		un_nrows;	/* number of rows */
	uint_t		un_ocomp;	/* offset of  ms_comp array  */
	struct ms_row {
		int	un_icomp;	/* ms_comp array index of first comp */
		uint_t	un_ncomp;	/* # comps in this row */
		diskaddr_t un_blocks;	/* total blocks in this row */
		diskaddr_t un_cum_blocks;	/* cum. blks in rows */
		diskaddr_t un_interlace;	/* # blks from each disk */
	}un_row[1];
} ms_unit_t;
#if _LONG_LONG_ALIGNMENT == 8 && _LONG_LONG_ALIGNMENT_32 == 4
#pragma pack()
#endif

#ifdef _KERNEL

typedef struct md_sps {			/* stripe parent save */
	DAEMON_QUEUE
	ms_unit_t	*ps_un;
	mdi_unit_t	*ps_ui;
	buf_t		*ps_bp;
	caddr_t		 ps_addr;
	int		 ps_frags;
	int		 ps_flags;
	ms_comp_t	*ps_errcomp;
	/*
	 * New structure members should be added here; fields added
	 * after ps_mx will not be zeroed during initialization.
	 */
	kmutex_t	 ps_mx;
} md_sps_t;

#define	MD_SPS_ERROR		0x0001
#define	MD_SPS_DONTFREE		0x0002
#define	MD_SPS_DONE		0x0004

#define	SPS_FREE(kc, ps)			\
{						\
	if ((ps)->ps_flags & MD_SPS_DONTFREE)	\
		(ps)->ps_flags |= MD_SPS_DONE;	\
	else					\
		kmem_cache_free((kc), (ps));	\
}

typedef struct md_scs {
	DAEMON_QUEUE
	minor_t		 cs_mdunit;
	md_sps_t	*cs_ps;
	ms_comp_t	*cs_comp;
	/* Add new structure members HERE!! */
	buf_t		 cs_buf;
	/*  DO NOT add struture members here; cs_buf is dynamically sized */
} md_scs_t;

/* Externals from stripe.c */
extern int	stripe_build_incore(void *, int);
extern void	reset_stripe(ms_unit_t *, minor_t, int);
extern intptr_t	stripe_component_count(md_dev64_t, void *);
extern intptr_t	stripe_get_dev(md_dev64_t, void *, int, ms_cd_info_t *);
extern intptr_t stripe_replace_dev(md_dev64_t, void *, int, ms_new_dev_t *,
    mddb_recid_t *, int, void (**)(), void **);
extern void	stripe_replace_done(md_dev64_t, sv_dev_t *);

/* Externals from stripe_ioctl.c */
extern int	md_stripe_ioctl(dev_t dev, int cmd, void *data,
		    int mode, IOLOCK *lockp);

/* rename named service functions (stripe_ioctl.c) */
md_ren_svc_t	stripe_rename_check;

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS__MD_STRIPE_H */
