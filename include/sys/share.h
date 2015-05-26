/*
 * Copyright (c) 1996-1998,2001 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef _SYS_SHARE_H
#define	_SYS_SHARE_H

#pragma ident	"@(#)share.h	1.7	01/04/07 SMI"

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Maximum size of a shrlock owner.
 * Must be large enough to handle a netobj.
 */
#define	MAX_SHR_OWNER_LEN	1024

/*
 * Contents of shrlock owner field for local share requests
 */
struct shr_locowner {
	pid_t	sl_pid;
	int	sl_id;
};

struct shrlock {
	short	s_access;
	short	s_deny;
	int32_t	s_sysid;	/* 0 if local otherwise passed by lm */
	pid_t	s_pid;		/* 0 if remote otherwise local pid */
	int	s_own_len;	/* if 0 and F_UNSHARE matching sysid */
	caddr_t	s_owner;	/* variable length opaque owner */
};

struct shrlocklist {
	struct shrlock *shr;
	struct shrlocklist *next;
};

#if defined(_KERNEL)
struct flock64;

extern int add_share(struct vnode *, struct shrlock *);
extern int del_share(struct vnode *, struct shrlock *);
extern void cleanshares(struct vnode *, pid_t);
extern int shr_has_remote_shares(vnode_t *, int32_t);
extern int proc_has_nbmand_share_on_vp(vnode_t *, pid_t);
extern int share_blocks_lock(vnode_t *, struct flock64 *);
extern int wait_for_share(vnode_t *, struct flock64 *);
#endif /* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_SHARE_H */
