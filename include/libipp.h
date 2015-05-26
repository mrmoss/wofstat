/*
 * Copyright 2001-2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_LIBIPP_H
#define	_LIBIPP_H

#pragma ident	"@(#)libipp.h	1.1	02/02/26 SMI"

#include <libnvpair.h>
#include <ipp/ipp.h>

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	DEBUG

#define	DBG_ERR	0x00000001
#define	DBG_IO	0x00000002

#endif	/* DEBUG */

/*
 * interface functions
 */

extern int	ipp_action_create(const char *, const char *, nvlist_t **,
    ipp_flags_t);
extern int	ipp_action_destroy(const char *, ipp_flags_t);
extern int	ipp_action_modify(const char *, nvlist_t **, ipp_flags_t);
extern int	ipp_action_info(const char *, int (*)(nvlist_t *, void *),
    void *, ipp_flags_t);
extern int	ipp_action_mod(const char *, char **);
extern int	ipp_list_mods(char ***, int *);
extern int	ipp_mod_list_actions(const char *, char ***, int *);
extern void	ipp_free(char *);
extern void	ipp_free_array(char **, int);

#ifdef	__cplusplus
}
#endif

#endif	/* _LIBIPP_H */
