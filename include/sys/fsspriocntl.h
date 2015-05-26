/*
 * Copyright (c) 2001 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef	_SYS_FSSPRIOCNTL_H
#define	_SYS_FSSPRIOCNTL_H

#pragma ident	"@(#)fsspriocntl.h	1.1	01/04/05 SMI"

#include <sys/types.h>
#include <sys/fss.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Fair-share class specific structures for the priocntl system call.
 */
typedef struct fssparms {
	pri_t		fss_uprilim;	/* user priority limit */
	pri_t		fss_upri;	/* user priority */
} fssparms_t;

typedef struct fssinfo {
	pri_t	fss_maxupri;	/* configured limit on user priority range */
} fssinfo_t;

#define	FSS_NOCHANGE	-32768

/*
 * Fair-sharing class specific keys for the priocntl system call varargs
 * interface.
 */
#define	FSS_KY_UPRILIM	1	/* user priority limit */
#define	FSS_KY_UPRI	2	/* user priority */

/*
 * The following is used by the dispadmin(1M) command for scheduler
 * administration and is not for general use.
 */
typedef struct fssadmin {
	short	fss_quantum;
	short	fss_cmd;
} fssadmin_t;

#define	FSS_GETADMIN	1
#define	FSS_SETADMIN	2

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_FSSPRIOCNTL_H */
