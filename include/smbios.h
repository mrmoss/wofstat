/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SMBIOS_H
#define	_SMBIOS_H

#pragma ident	"@(#)smbios.h	1.1	06/03/19 SMI"

#include <sys/smbios.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * This header file defines the interfaces available from the SMBIOS access
 * library, libsmbios, and an equivalent kernel module.  This API can be used
 * to access DMTF SMBIOS data from a device, file, or raw memory buffer.
 * This is NOT yet a public interface, although it may eventually become one in
 * the fullness of time after we gain more experience with the interfaces.
 *
 * In the meantime, be aware that any program linked with this API in this
 * release of Solaris is almost guaranteed to break in the next release.
 *
 * In short, do not user this header file or these routines for any purpose.
 */

#ifdef	__cplusplus
}
#endif

#endif	/* _SMBIOS_H */
