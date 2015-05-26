/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *		PROPRIETARY NOTICE (Combined)
 *
 * This source code is unpublished proprietary information
 * constituting, or derived under license from AT&T's UNIX(r) System V.
 * In addition, portions of such source code were derived from Berkeley
 * 4.3 BSD under license from the Regents of the University of
 * California.
 *
 *
 *
 *		Copyright Notice
 *
 * Notice of copyright on this source code product does not indicate
 * publication.
 *
 *	(c) 1983,1984,1985,1986,1987,1988,1989  AT&T.
 *		All rights reserved.
 *
 */

/*
 * Copyright (c) 1989, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_PATHNAME_H
#define	_SYS_PATHNAME_H

#pragma ident	"@(#)pathname.h	1.24	12/06/21 SMI"

#include <sys/vnode.h>
#include <sys/cred.h>
#include <sys/uio.h>
#include <sys/dirent.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Pathname structure.
 * System calls that operate on path names gather the path name
 * from the system call into this structure and reduce it by
 * peeling off translated components.  If a symbolic link is
 * encountered the new path name to be translated is also
 * assembled in this structure.
 *
 * By convention pn_buf is not changed once it's been set to point
 * to the underlying storage; routines which manipulate the pathname
 * do so by changing pn_path and pn_pathlen.  pn_pathlen is redundant
 * since the path name is null-terminated, but is provided to make
 * some computations faster.
 */
typedef struct pathname {
	char	*pn_buf;		/* underlying storage */
	char	*pn_path;		/* remaining pathname */
	size_t	pn_pathlen;		/* remaining length */
	size_t	pn_bufsize;		/* total size of pn_buf */
} pathname_t;

#define	pn_pathleft(pnp)	((pnp)->pn_pathlen)

extern void	pn_alloc(struct pathname *);
extern void	pn_alloc_size(struct pathname *, size_t);
extern int	pn_get(const char *, enum uio_seg, struct pathname *);
extern int	pn_get_buf(const char *, enum uio_seg, struct pathname *,
			void *, size_t);
extern int	pn_set(struct pathname *, const char *);
extern int	pn_insert(struct pathname *, struct pathname *, size_t);
extern int	pn_getsymlink(vnode_t *, struct pathname *, cred_t *);
extern int	pn_getcomponent(struct pathname *, char *);
extern void	pn_setlast(struct pathname *);
extern void	pn_skipslash(struct pathname *);
extern int	pn_fixslash(struct pathname *);
extern int	pn_addslash(struct pathname *);
extern void	pn_free(struct pathname *);

extern int lookupname(char *, enum uio_seg, int follow,
		vnode_t **, vnode_t **);
extern int lookupnameat(char *, enum uio_seg, int follow,
		vnode_t **, vnode_t **, vnode_t *);
extern int lookuppn(struct pathname *, struct pathname *, int follow,
		vnode_t **, vnode_t **);
extern int lookuppnat(struct pathname *, struct pathname *, int follow,
		vnode_t **, vnode_t **, vnode_t *);

extern int lookuppnvp(struct pathname *, struct pathname *, int follow,
		vnode_t **, vnode_t **, vnode_t *, vnode_t *, cred_t *);
extern int traverse(vnode_t **);
extern vnode_t *vn_under(vnode_t *);

extern int vnodetopath(vnode_t *, vnode_t *, char *, size_t, cred_t *);
extern int dogetcwd(char *, size_t);
extern int dirfindvp(vnode_t *, vnode_t *, vnode_t *, cred_t *, char *,
		size_t, dirent64_t **);

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_PATHNAME_H */
