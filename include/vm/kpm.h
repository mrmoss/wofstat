/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_VM_KPM_H
#define	_VM_KPM_H

#pragma ident	"@(#)kpm.h	1.1	03/11/09 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	_LP64
#define	SEGKPM_SUPPORT
#endif

#ifndef	_ASM

/*
 * Machine independent per instance kpm mapping structure
 */
struct kpme {
	struct kpme	*kpe_next;
	struct kpme	*kpe_prev;
	struct page	*kpe_page;	/* back pointer to (start) page */
};

#endif	/* _ASM */

#ifdef	__cplusplus
}
#endif

#endif	/* _VM_KPM_H */
