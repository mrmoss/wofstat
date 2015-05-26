/*
 * Copyright 2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _IPMP_H
#define	_IPMP_H

#pragma ident	"@(#)ipmp.h	1.1	02/11/27 SMI"

/*
 * General IPMP-related definitions and functions.
 *
 * These interfaces may only be used within ON or after signing a contract
 * with ON.  For documentation, refer to PSARC/2002/615.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/sysevent/ipmp.h>

/*
 * IPMP library error codes.
 */
enum {
	IPMP_SUCCESS,		/* operation succeeded */
	IPMP_FAILURE,		/* operation failed (check errno) */
	IPMP_EMINRED,		/* minimum failover redundancy not met */
	IPMP_EFBDISABLED,	/* failback disabled */
	IPMP_EFBPARTIAL,	/* unable to completely fail back */
	IPMP_EINVAL,		/* invalid argument */
	IPMP_ENOMEM,		/* out of memory */
	IPMP_ENOMPATHD,		/* cannot contact in.mpathd */
	IPMP_EUNKGROUP,		/* unknown IPMP group */
	IPMP_EUNKIF,		/* interface is not using IPMP */
	IPMP_EPROTO,		/* unable to communicate with in.mpathd */
	IPMP_NERR		/* number of error codes */
};

typedef struct ipmp_state *ipmp_handle_t;

extern int ipmp_open(ipmp_handle_t *);
extern void ipmp_close(ipmp_handle_t);
extern const char *ipmp_errmsg(int);

#ifdef __cplusplus
}
#endif

#endif /* _IPMP_H */
