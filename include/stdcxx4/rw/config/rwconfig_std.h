/*
 * Copyright (c) 2009, 2010, Oracle and/or its affiliates. All rights reserved.
 */

#pragma ident	"@(#)rwconfig_std.h	1.1	10/11/05 SMI"

#ifndef __STDCXX_CONFIG_H
#define __STDCXX_CONFIG_H

#if defined(__i386) || defined(__amd64)

#if defined(__amd64)
#include "stdcxx_amd64.h"
#else
#include "stdcxx_i386.h"
#endif

#elif defined(__sparc) || defined(__sparcv9)

#if defined(__sparcv9)
#include "stdcxx_sparc64.h"
#else
#include "stdcxx_sparc32.h"
#endif

#else
#error "Unknown Solaris ISA."
#endif

#endif /* __STDCXX_CONFIG_H */

