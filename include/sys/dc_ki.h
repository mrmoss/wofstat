/*
 * Copyright 1998, 2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _DC_KI_H
#define	_DC_KI_H

#pragma ident	"@(#)dc_ki.h	1.2	02/09/20 SMI"

#include <sys/types.h>
#include <sys/sunddi.h>
#include <sys/modctl.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The routine is used for all drivers that are loaded into
 * memory before root is mounted. They are implemented in
 * misc/cl_bootstrap module in SunCluster consolidation.
 */

extern void cluster(void);
extern int clboot_modload(struct modctl *mp);
extern int clboot_loadrootmodules();
extern int clboot_rootconf();
extern void clboot_mountroot();

#ifdef __cplusplus
}
#endif

#endif /* _DC_KI_H */
