/*
 * Copyright (c) 1986, 2010, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_VM_RM_H
#define	_VM_RM_H

#pragma ident	"@(#)rm.h	1.26	10/04/07 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	_KERNEL

extern size_t rm_asrss(struct as *);
extern ushort_t rm_pctmemory(struct as *);

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _VM_RM_H */
