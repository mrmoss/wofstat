/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_INTTYPES_H
#define	_SYS_INTTYPES_H

#pragma ident	"@(#)inttypes.h	1.3	03/12/04 SMI"

/*
 * This header, <sys/inttypes.h>, contains (through nested inclusion) the
 * vast majority of the facilities specified for <inttypes.h> as defined
 * by the ISO C Standard, ISO/IEC 9899:1999 Programming language - C.
 *
 * Kernel/Driver developers are encouraged to include this file to access
 * the fixed size types, limits and utility macros. Application developers
 * should use the standard defined header <inttypes.h>.
 */

#include <sys/feature_tests.h>
#include <sys/int_types.h>
#if !defined(_XOPEN_SOURCE) || defined(_XPG6) || defined(__EXTENSIONS__)
#include <sys/int_limits.h>
#include <sys/int_const.h>
#include <sys/int_fmtio.h>
#endif

#endif /* _SYS_INTTYPES_H */
