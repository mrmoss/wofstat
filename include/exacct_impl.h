/*
 * Copyright (c) 1999-2001 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef	_EXACCT_IMPL_H
#define	_EXACCT_IMPL_H

#pragma ident	"@(#)exacct_impl.h	1.2	01/10/10 SMI"

#include <sys/exacct.h>
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct _ea_file_depth {
	int	efd_nobjs;		/* number of objects in group */
	int	efd_obj;		/* index of curr object within group */
} ea_file_depth_t;

typedef struct _ea_file_impl {
	char	*ef_filename;		/* file name */
	char	*ef_creator;		/* file creator */
	char	*ef_hostname;		/* file hostname */
	FILE	*ef_fp;			/* file stream pointer */
	ea_file_depth_t *ef_depth;	/* pointer to depth stack */
	char	*ef_buf;		/* pointer for buffer consumption */
	ssize_t	ef_bufsize;		/* remaining bytes in buffer */
	void	*ef_lpad[1];
	offset_t ef_advance;		/* bytes to advance on next op */
	offset_t ef_opad[2];
	mode_t	ef_oflags;		/* flags to open(2) */
	int	ef_fd;			/* file descriptor */
	int	ef_version;		/* exacct file version */
	int	ef_ndeep;		/* current depth in allocated stack */
	int	ef_mxdeep;		/* maximum depth of allocated stack */
	int	ef_ipad[1];
} ea_file_impl_t;

#ifdef	__cplusplus
}
#endif

#endif	/* _EXACCT_IMPL_H */
