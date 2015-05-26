/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_TSOL_TSYSCALL_H
#define	_SYS_TSOL_TSYSCALL_H

#pragma ident	"@(#)tsyscall.h	1.1	06/05/03 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * the defines for subcode of labelsys system call.
 */

#define	TSOL_SYSLABELING	1
#define	TSOL_TNRH		2
#define	TSOL_TNRHTP		3
#define	TSOL_TNMLP		4
#define	TSOL_GETLABEL		5
#define	TSOL_FGETLABEL		6

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_TSOL_TSYSCALL_H */
