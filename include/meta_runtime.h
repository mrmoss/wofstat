/*
 * Copyright (c) 1998, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _META_RUNTIME_H
#define	_META_RUNTIME_H

#pragma ident	"@(#)meta_runtime.h	2.2	12/01/04 SMI"

/*
 * Declares functions that return the values of runtime
 * parameters set in /etc/lvm/runtime.cf.  All
 * the functions declared in this file are defined in
 * SUNWmd/lib/libmeta/meta_runtime.c unless otherwise
 * noted.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

extern
boolean_t
do_owner_ioctls(void);

extern
boolean_t
disk_do_devid_check(void);

#ifdef __cplusplus
}
#endif

#endif /* _META_RUNTIME_H */
