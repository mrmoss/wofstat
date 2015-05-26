/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_LIBDISKSTATUS_H
#define	_LIBDISKSTATUS_H

#pragma ident	"@(#)libdiskstatus.h	1.1	08/01/21 SMI"

#include <libnvpair.h>
#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct disk_status disk_status_t;

/*
 * Error definitions
 */
#define	EDS_BASE	2000

enum {
	EDS_NOMEM = EDS_BASE,		/* memory allocation failure */
	EDS_CANT_OPEN,			/* failed to open device */
	EDS_NO_TRANSPORT,		/* no supported transport */
	EDS_NOT_SUPPORTED,		/* status information not supported */
	EDS_NOT_SIMULATOR,		/* not a valid simulator file */
	EDS_IO				/* I/O error */
};

/*
 * Basic library functions
 */
extern disk_status_t *disk_status_open(const char *, int *);
extern void disk_status_close(disk_status_t *);
extern const char *disk_status_errmsg(int);
extern void disk_status_set_debug(boolean_t);
extern int disk_status_errno(disk_status_t *);

/*
 * Miscellaneous functions.
 */
extern const char *disk_status_path(disk_status_t *);

/*
 * Main entry point.
 */
extern nvlist_t *disk_status_get(disk_status_t *);

/*
 * Utility function to simulate predictive failure (device-specific).
 */
extern int disk_status_test_predfail(disk_status_t *);

#ifdef	__cplusplus
}
#endif

#endif	/* _LIBDISKSTATUS_H */
