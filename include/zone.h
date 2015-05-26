/*
 * Copyright (c) 2003, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _ZONE_H
#define	_ZONE_H

#pragma ident	"@(#)zone.h	1.10	11/08/09 SMI"

#include <sys/types.h>
#include <sys/zone.h>
#include <sys/priv.h>
#include <tsol/label.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Functions for mapping between id and name for active zones.
 */
extern zoneid_t		getzoneid(void);
extern zoneid_t		getzoneidbyname(const char *);
extern ssize_t		getzonenamebyid(zoneid_t, char *, size_t);

/*
 * NOTE
 *
 * The remaining contents of this file are private to the implementation
 * of Solaris and are subject to change at any time without notice,
 * Applications using these interfaces may fail to run on future releases.
 */

extern int zonept(int, zoneid_t);
extern int zone_get_id(const char *, zoneid_t *);

/* System call API */
extern zoneid_t	zone_create(const char *, const char *,
    const struct priv_set *, const char *, size_t, const char *, size_t, int *,
    int, int, const bslabel_t *, int);
extern int	zone_boot(zoneid_t, const char *);
extern int	zone_destroy(zoneid_t);
extern ssize_t	zone_getattr(zoneid_t, int, void *, size_t);
extern int	zone_setattr(zoneid_t, int, void *, size_t);
extern int	zone_enter(zoneid_t);
extern int	zone_list(zoneid_t *, uint_t *);
extern int	zone_shutdown(zoneid_t);
extern int	zone_version(int *);
extern int	zone_add_datalink(zoneid_t, char *);
extern int	zone_remove_datalink(zoneid_t, char *);
extern int	zone_check_datalink(zoneid_t *, char *);
extern int	zone_list_datalink(zoneid_t, int *, char *);
extern ssize_t	zone_getattr_defunct(uint64_t, int, void *, size_t);
extern int	zone_list_defunct(uint64_t *, uint_t *);

#ifdef	__cplusplus
}
#endif

#endif /* _ZONE_H */
