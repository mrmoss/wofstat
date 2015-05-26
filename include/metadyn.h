/*
 * Copyright (c) 1998, 2000 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef	_METADYN_H
#define	_METADYN_H

#pragma ident	"@(#)metadyn.h	2.1	00/06/22 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#define	METALDPATH_DEFAULT "/usr/lib"
#define	METATOOLLDPATH_DEFAULT "/usr/sadm/lib/lvm"

typedef enum {
	/*
	 * Conversion of driver name from cinfo should have occurred,
	 * but something prevented that from taking place.
	 */
	Convert_Error,

	/*
	 * The library being called doesn't handle this driver so nothing
	 * was done.
	 */
	Convert_Noop,

	/*
	 * Conversion completed without errors.
	 */
	Convert_Okay
} meta_convert_e;

meta_convert_e convert_path(mdname_t *, struct dk_cinfo *, mdcinfo_t *,
    md_error_t *);

typedef enum {
	/*
	 * While trying to determine information regarding the enclosure,
	 * such as tray, bus, or world wide number and error occurred.
	 */
	Enclosure_Error,

	/*
	 * This library doesn't handle this device name. No changes have been
	 * made to the structures.
	 */
	Enclosure_Noop,

	/*
	 * Successfully determined all pertinent information regarding
	 * the enclosure.
	 */
	Enclosure_Okay
} meta_enclosure_e;

meta_enclosure_e get_enclosure(mdname_t *, mdcinfo_t *, md_error_t *);

typedef enum {
	/*
	 * When one library tries to load another and finds the second
	 * library already locked, lock_and_load will return this value.
	 */
	Library_Locked,

	/*
	 * If all goes well during a library load we'll receive this
	 * return code.
	 */
	Library_Unlocked,

	/*
	 * Failed to even open the requested library
	 */
	Library_Open_Error
} meta_library_e;

meta_library_e lock_and_load(const char *, void **);
void unlock_and_unload(void *);

char *get_phys_name(char *);

#ifdef	__cplusplus
}
#endif

#endif	/* _METADYN_H */
