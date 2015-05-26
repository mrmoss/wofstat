/*
 * Copyright 2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_UUID_H
#define	_UUID_H

#pragma ident	"@(#)uuid.h	1.2	02/07/03 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/uuid.h>

extern void uuid_generate(uuid_t);
extern void uuid_generate_random(uuid_t);
extern void uuid_generate_time(uuid_t);
extern void uuid_copy(uuid_t, uuid_t);
extern void uuid_clear(uuid_t);
extern void uuid_unparse(uuid_t, char *);
extern int uuid_compare(uuid_t, uuid_t);
extern int uuid_is_null(uuid_t);
extern int uuid_parse(char *, uuid_t);
extern time_t uuid_time(uuid_t, struct timeval *);

#ifdef __cplusplus
}
#endif

#endif /* _UUID_H */
