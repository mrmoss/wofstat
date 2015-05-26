/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_VUID_WHEEL_H
#define	_SYS_VUID_WHEEL_H

#pragma ident	"@(#)vuid_wheel.h	1.1	04/02/10 SMI"

#include <sys/vuid_event.h>	/* for VUIOC definition */

#ifdef	__cplusplus
extern "C" {
#endif

#define	VUID_WHEEL_MAX_COUNT	256
#define	VUIDGWHEELCOUNT		(VUIOC|15)
#define	VUIDGWHEELINFO		(VUIOC|16)
#define	VUIDGWHEELSTATE		(VUIOC|17)
#define	VUIDSWHEELSTATE		(VUIOC|18)

typedef struct {
	int	vers;		/* set to VUID_WHEEL_INFO_VERS */
	int	id;
	int	format;
} wheel_info;

#define	VUID_WHEEL_INFO_VERS		1

#define	VUID_WHEEL_FORMAT_UNKNOWN	0
#define	VUID_WHEEL_FORMAT_HORIZONTAL	1
#define	VUID_WHEEL_FORMAT_VERTICAL	2

typedef struct {
	int		vers;		/* set to VUID_WHEEL_STATE_VERS */
	int		id;
	uint32_t	stateflags;
} wheel_state;

#define	VUID_WHEEL_STATE_VERS		1
#define	VUID_WHEEL_STATE_ENABLED	(1 << 0) /* Can get & set */
#define	VUID_WHEEL_DELTAMASK		0x000000FF

#define	VUID_WHEEL_GETDELTA(event_value)	\
		((signed char) ((event_value) & VUID_WHEEL_DELTAMASK))

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_VUID_WHEEL_H */
