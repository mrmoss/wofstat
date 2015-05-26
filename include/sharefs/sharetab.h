/*
 * Copyright (c) 2007, 2010, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SHAREFS_SHARETAB_H
#define	_SHAREFS_SHARETAB_H

#pragma ident	"@(#)sharetab.h	1.2	10/09/17 SMI"

#include <sys/pkp_hash.h>

/*
 * This header defines the glue to keeping a sharetab in memory.
 * It is broken out from sharefs.h in the case that it will be
 * reused in userland.
 */

/*
 * Note:
 * Must include share/share.h before this header.
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sh_list {		/* cached share list */
	struct sh_list	*shl_next;
	share_t		*shl_sh;
} sh_list_t;

typedef struct sharefs_hash_head {
	share_t		*ssh_sh;
	uint_t		ssh_count;
} sharefs_hash_head_t;

#define	SHARETAB_HASHES		PKP_HASH_SIZE

typedef struct sharetab {
	sharefs_hash_head_t	s_buckets[SHARETAB_HASHES];
	char			*s_fstype;
	struct sharetab		*s_next;
	uint_t			s_count;
} sharetab_t;

#ifdef __cplusplus
}
#endif

#endif /* !_SHAREFS_SHARETAB_H */
