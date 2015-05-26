/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_MSIO_H
#define	_SYS_MSIO_H

#pragma ident	"@(#)msio.h	1.13	05/06/01 SMI"	/* SunOS4.0 1.6 */

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Mouse related ioctls
 */
typedef struct {
	int	jitter_thresh;
	int	speed_law;
	int	speed_limit;
} Ms_parms;

typedef struct {
	int	height;			/* height of the screen */
	int	width;			/* width of the screen */
}Ms_screen_resolution;

#define	MSIOC		('m'<<8)	/* same as mtio.h - change ? */
#define	MSIOGETPARMS	(MSIOC|1)	/* get / set jitter, speed  */
#define	MSIOSETPARMS	(MSIOC|2)	/* law, or speed limit */
#define	MSIOBUTTONS	(MSIOC|3)	/* get number of buttons */
#define	MSIOSRESOLUTION	(MSIOC|4)	/* Set screen resolution for mouse */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_MSIO_H */
