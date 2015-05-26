/*
 * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_AMD_IOMMU_H
#define	_SYS_AMD_IOMMU_H

#pragma ident	"@(#)amd_iommu.h	1.2	09/05/27 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/sunddi.h>
#include <sys/iommulib.h>

#ifdef _KERNEL

typedef struct amd_iommu_state {
	int	aioms_instance;			/* instance */
	dev_info_t *aioms_devi;			/* dip */
	struct amd_iommu *aioms_iommu_start;	/* start of list of IOMMUs */
	struct amd_iommu *aioms_iommu_end;	/* end of list of IOMMUs */
	int aioms_nunits;			/* # of IOMMUs in function */
} amd_iommu_state_t;

int amd_iommu_setup(dev_info_t *dip, amd_iommu_state_t *statep);
int amd_iommu_teardown(dev_info_t *dip, amd_iommu_state_t *statep);
int amd_iommu_lookup_src_bdf(uint16_t bdf, uint16_t *src_bdfp);

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_AMD_IOMMU_H */
