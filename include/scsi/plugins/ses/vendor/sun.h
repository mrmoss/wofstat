/*
 * Copyright (c) 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_VENDOR_SUN_H
#define	_VENDOR_SUN_H

#pragma ident	"@(#)sun.h	1.1	11/01/13 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Node properties
 */
#define	SUN_DIAGPAGE_FRUID	SES2_DIAGPAGE_VENDOR_0

typedef enum sun_element_type {
	SES_ET_SUNW_FANMODULE = 0x90,
	SES_ET_SUNW_FRU = 0x91,
	SES_ET_SUNW_SERVICE_PROCESSOR = 0x92,
	SES_ET_SUNW_ETHERNET_SWITCH = 0x93,
	SES_ET_SUNW_POWERBOARD = 0x94,
	SES_ET_SUNW_POWERMODULE = 0x95,
	SES_ET_SUNW_FANBOARD = 0x96
} sun_element_type;

#ifdef	__cplusplus
}
#endif

#endif	/* _VENDOR_SUN_H */
