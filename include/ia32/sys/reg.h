/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_IA32_SYS_REG_H
#define	_IA32_SYS_REG_H

#pragma ident	"@(#)reg.h	1.8	04/09/28 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This file only exists for i386 backwards compatibility.
 * Kernel code should not include it.
 */

#ifdef _KERNEL
#error "kernel include of reg.h"
#else
#include <sys/regset.h>
#endif	/* _KERNEL */

#ifdef __cplusplus
}
#endif

#endif	/* _IA32_SYS_REG_H */
