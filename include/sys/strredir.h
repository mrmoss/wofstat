/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_STRREDIR_H
#define	_SYS_STRREDIR_H

#pragma ident	"@(#)strredir.h	1.10	10/03/16 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * strredir.h:	Declarations for the redirection driver and its matching
 *		STREAMS module.
 */

/*
 * The module's module id.
 *
 * XXX:	Since there's no authority responsible for administering this name
 *	space, there's no guarantee that this value is unique.  That wouldn't
 *	be so bad except that the DKI now suggests that ioctl cookie values
 *	should be based on module id to make them unique...
 */
#define	STRREDIR_MODID	7326

/*
 * Redirection ioctls:
 */
#define	SRIOCSREDIR	((STRREDIR_MODID<<16) | 1)	/* set redir target */
#define	SRIOCISREDIR	((STRREDIR_MODID<<16) | 2)	/* is redir target? */


/*
 * Everything from here on is of interest only to the kernel.
 */
#ifdef	_KERNEL

/* name of the module used to detect closes on redirected streams */
#define	STRREDIR_MOD	"redirmod"

extern void srpop(vnode_t *, boolean_t);

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_STRREDIR_H */
