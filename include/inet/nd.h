/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _INET_ND_H
#define	_INET_ND_H

#pragma ident	"@(#)nd.h	1.17	06/05/03 SMI"

#include <sys/types.h>
#include <inet/common.h>
#include <inet/led.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	ND_BASE		('N' << 8)	/* base */
#define	ND_GET		(ND_BASE + 0)	/* Get a value */
#define	ND_SET		(ND_BASE + 1)	/* Set a value */

#ifdef	_KERNEL
/* ND callback function prototypes */
typedef	int (*ndgetf_t)(queue_t *, MBLKP, caddr_t, cred_t *);
typedef	int (*ndsetf_t)(queue_t *, MBLKP, char *, caddr_t, cred_t *);

/* Named dispatch table entry */
typedef struct  nde_s {
	char    *nde_name;
	pfi_t	nde_get_pfi;
	pfi_t	nde_set_pfi;
	caddr_t nde_data;
} NDE;

/* Name dispatch table */
typedef struct  nd_s {
	int	nd_free_count;	/* number of unused nd table entries */
	int	nd_size;	/* size (in bytes) of current table */
	NDE	*nd_tbl;	/* pointer to table in heap */
} ND;

#define	NDE_ALLOC_COUNT 32
#define	NDE_ALLOC_SIZE  (sizeof (NDE) * NDE_ALLOC_COUNT)

/* 64K STREAM limit - the max ndd info header. */
#define	ND_MAX_BUF_LEN	65303

/*
 * See uts/common/inet/nd.c for comments on how to use these routines.
 */
extern boolean_t	nd_load(caddr_t *, char *, ndgetf_t, ndsetf_t, caddr_t);
extern void		nd_unload(caddr_t *, char *);
extern void		nd_free(caddr_t *);
extern int		nd_getset(queue_t *, caddr_t, MBLKP);

/*
 * Canned nd_get and nd_set routines for use with nd_load().
 */
extern int	nd_get_default(queue_t *, MBLKP, caddr_t, cred_t *);
extern int	nd_get_long(queue_t *, MBLKP, caddr_t, cred_t *);
extern int	nd_get_names(queue_t *, MBLKP, caddr_t, cred_t *);
extern int	nd_set_default(queue_t *, MBLKP, char *, caddr_t, cred_t *);
extern int	nd_set_long(queue_t *, MBLKP, char *, caddr_t, cred_t *);

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _INET_ND_H */
