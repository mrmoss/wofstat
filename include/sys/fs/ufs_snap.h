/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_FS_UFS_SNAP_H
#define	_SYS_FS_UFS_SNAP_H

#pragma ident	"@(#)ufs_snap.h	1.4	04/08/26 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/fssnap_if.h>
#include <sys/vnode.h>
#include <sys/cred.h>

/* debug levels */
#define	UFSSNAPDB_CREATE	0x01
#define	UFSSNAPDB_DELETE	0x02

/* Constants */
#define	UFS_MAX_SNAPBACKFILESIZE	(1LL << 39)  /* 512 GB */

extern int ufs_snap_create(struct vnode *, struct fiosnapcreate_multi *,
    cred_t *);
extern int ufs_snap_delete(struct vnode *, struct fiosnapdelete *, cred_t *);

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_FS_UFS_SNAP_H */
