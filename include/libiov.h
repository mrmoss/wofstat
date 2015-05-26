/*
 * Copyright (c) 2011, 2012, Oracle and/or its affiliates. All rights reserved.
 */
/*
 * This file defines the private interface used LDoms agent
 */

#ifndef	_LIBIOV_H
#define	_LIBIOV_H

#pragma ident	"@(#)libiov.h	1.2	12/06/26 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/sunddi.h>
#include <sys/iovcfg.h>

extern int iov_get_pf_list(nvlist_t **);
extern int iov_devparam_get(char *, uint32_t *, uint32_t *, void **);
extern int iov_devparam_validate(char *, int, char **, nvlist_t **);

#if defined(__sparc)
#define	IOV_HP_F_QUERY	0x1

extern int iov_rc_add(int rc_address, char **error_str);
extern int iov_rc_remove(int rc_address, uint_t hp_flags, char **error_str);
extern int iov_remove(int rc_address, char *path, uint_t hp_flags,
    char **error_str);
extern int iov_add(int rc_address, char *path, char **error_str);
extern int iov_hp_online(char *path, char *connection, char **error_str);
extern int iov_hp_offline(char *path, char *connection, uint_t flags,
    char **error_str);
extern int iov_hp_set_offline_ceiling(char *path, char *connection,
    uint32_t *handlep, char **error_str);
extern int iov_hp_clear_offline_ceiling(char *path, char *connection,
    uint32_t handle, char **error_str);
extern int iov_path_to_port(char *pathname, char **parentp, char **portp);
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _LIBIOV_H */
