/*
 * Copyright 2000-2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_SYSEVENT_DOMAIN_H
#define	_SYS_SYSEVENT_DOMAIN_H

#pragma ident	"@(#)domain.h	1.2	02/07/17 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Event type EC_DOMAIN/ESC_DOMAIN_STATE_CHANGE schema
 *	Event Class	- EC_DOMAIN
 *	Event Sub-Class	- ESC_DOMAIN_STATE_CHANGE
 *	Event Publisher	- SUNW:kern:[domain env monitor]
 *	Attribute Name	- DOMAIN_VERSION
 *	Attribute Type	- SE_DATA_TYPE_UINT32
 *	Attribute Value	- [version of the schema]
 *	Attribute Name	- DOMAIN_WHAT_CHANGED
 *	Attribute Type	- SE_DATA_TYPE_STRING
 *	Attribute Value	- DOMAIN_RESERVED_ATTR | DOMAIN_KEYSWITCH | DOMAIN_FRU
 */
#define	DOMAIN_VERSION		"domain_version"
#define	DOMAIN_WHAT_CHANGED	"domain_what_changed"
#define	DOMAIN_KEYSWITCH	"domain_keyswitch"
#define	DOMAIN_FRU		"domain_fru"
#define	DOMAIN_RESERVED_ATTR	""

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_SYSEVENT_DOMAIN_H */
