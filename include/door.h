/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_DOOR_H
#define	_DOOR_H

#pragma ident	"@(#)door.h	1.10	10/01/01 SMI"

#include <sys/types.h>
#include <sys/door.h>
#include <ucred.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ASM

/*
 * Doors API
 */
int	door_create(void (*)(void *, char *, size_t, door_desc_t *, uint_t),
    void *, uint_t);
int	door_revoke(int);
int	door_info(int, door_info_t *);
int	door_call(int, door_arg_t *);
int	door_return(char *, size_t, door_desc_t *, uint_t);
int	door_cred(door_cred_t *);
int	door_ucred(ucred_t **);
int	door_bind(int);
int	door_unbind(void);
typedef void door_server_func_t(door_info_t *);
door_server_func_t *door_server_create(door_server_func_t *);

typedef void door_server_procedure_t(void *, char *, size_t, door_desc_t *,
    uint_t);
typedef int door_xcreate_server_func_t(door_info_t *,
    void *(*)(void *), void *, void *);
typedef void door_xcreate_thrsetup_func_t(void *);

int	door_xcreate(door_server_procedure_t *, void *, uint_t,
	    door_xcreate_server_func_t *, door_xcreate_thrsetup_func_t *,
	    void *, int);

#endif /* _ASM */

#ifdef __cplusplus
}
#endif

#endif	/* _DOOR_H */
