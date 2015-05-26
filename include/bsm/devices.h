/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_BSM_DEVICES_H
#define	_BSM_DEVICES_H

#pragma ident	"@(#)devices.h	1.7	07/06/22 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <secdb.h>

#define	DAOPT_AUTHS	"auths"
#define	DAOPT_CLASS	"class"
#define	DAOPT_CSCRIPT	"cleanscript"
#define	DAOPT_MINLABEL	"minlabel"
#define	DAOPT_MAXLABEL	"maxlabel"
#define	DAOPT_XDISPLAY	"xdpy"
#define	DAOPT_ZONE	"zone"
#define	DA_RESERVED	"reserved"

/*
 * These are unsupported, SUN-private interfaces.
 */

typedef struct {
	char	*da_devname;
	char	*da_devtype;
	char	*da_devauth;
	char	*da_devexec;
	kva_t	*da_devopts;
} devalloc_t;

typedef struct {
	char	*dmap_devname;
	char	*dmap_devtype;
	char	*dmap_devlist;
	char	**dmap_devarray;
} devmap_t;

int		getdadmline(char *, int, FILE *);

devalloc_t	*getdaent(void);
devalloc_t	*getdatype(char *);
devalloc_t	*getdanam(char *);
void		setdaent(void);
void		enddaent(void);
void		freedaent(devalloc_t *);
void		setdafile(char *);

devmap_t	*getdmapent(void);
devmap_t	*getdmaptype(char *);
devmap_t	*getdmapnam(char *);
devmap_t	*getdmapdev(char *);
void		setdmapent(void);
void		enddmapent(void);
void		freedmapent(devmap_t *);
void		setdmapfile(char *);
char		*getdmapfield(char *);
char		*getdmapdfield(char *);

#ifdef	__cplusplus
}
#endif

#endif	/* _BSM_DEVICES_H */
