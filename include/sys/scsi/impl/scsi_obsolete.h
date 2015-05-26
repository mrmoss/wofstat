
/*
 * Copyright (c) 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_SCSI_IMPL_SCSI_OBSOLETE_H
#define	_SYS_SCSI_IMPL_SCSI_OBSOLETE_H

#pragma ident	"@(#)scsi_obsolete.h	1.1	12/02/29 SMI"

/*
 * Obsoleted SCSA DDI Interfaces
 */
#include <sys/scsi/scsi.h>

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	_KERNEL

#ifdef  __STDC__

extern int scsi_hba_attach(dev_info_t *, ddi_dma_lim_t *,
    struct scsi_hba_tran *, int, void *);
extern struct scsi_pkt *scsi_dmaget(struct scsi_pkt *,
    opaque_t, int (*)(void));
extern struct scsi_pkt *scsi_pktalloc(struct scsi_address *,
    int, int, int (*)(void));
extern struct scsi_pkt *scsi_resalloc(struct scsi_address *, int, int,
    void *, int (*)(void));
extern void scsi_resfree(struct scsi_pkt *);

#else   /* __STDC__ */

extern int scsi_hba_attach();
extern struct scsi_pkt *scsi_dmaget();
extern struct scsi_pkt *scsi_pktalloc();
extern struct scsi_pkt *scsi_resalloc();
extern void scsi_resfree();

#endif  /* __STDC__ */

#define	scsi_pktfree	scsi_resfree

#endif /* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SCSI_IMPL_SCSI_OBSOLETE_H */
