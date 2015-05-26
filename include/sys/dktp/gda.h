/*
 * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_DKTP_GDA_H
#define	_SYS_DKTP_GDA_H

#pragma ident	"@(#)gda.h	1.9	09/03/19 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#define	GDA_RTYCNT	3

#define	GDA_BP_PKT(bp)	((struct cmpkt *)(bp)->av_back)

#ifdef  _KERNEL

extern void 	gda_inqfill(char *p, int l, char *s);
/*PRINTFLIKE4*/
extern void	gda_log(dev_info_t *, char *, uint_t, const char *, ...)
	__KPRINTFLIKE(4);
extern void	gda_errmsg(struct scsi_device *, struct cmpkt *, char *,
			int, daddr_t, daddr_t, char **, char **);
extern struct 	cmpkt *gda_pktprep(opaque_t objp, struct cmpkt *in_pktp,
			opaque_t dmatoken, int (*func)(caddr_t), caddr_t arg);
extern void	gda_free(opaque_t objp, struct cmpkt *pktp, struct buf *bp);

#endif  /* _KERNEL */

#define	GDA_GETGEOM_HEAD(X) (((X) >> 16) & 0xff)
#define	GDA_GETGEOM_SEC(X)  ((X) & 0xff)
#define	GDA_SETGEOM(hd, sec) (((hd) << 16) | (sec))

#define	GDA_KMFLAG(callback) (((callback) == DDI_DMA_SLEEP) ? \
				KM_SLEEP: KM_NOSLEEP)

#define	GDA_ALL			0
#define	GDA_UNKNOWN		1
#define	GDA_INFORMATIONAL	2
#define	GDA_RECOVERED		3
#define	GDA_RETRYABLE		4
#define	GDA_FATAL		5

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DKTP_GDA_H */
