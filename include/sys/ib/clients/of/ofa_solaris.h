/*
 * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.
 */

/*
 *
 * NAME: ofa_solaris.h
 *
 * DESC: OFED Solaris wrapper
 *
 */

#ifndef _SYS_IB_CLIENTS_OFA_SOLARIS_H
#define	_SYS_IB_CLIENTS_OFA_SOLARIS_H

#pragma ident	"@(#)ofa_solaris.h	1.1	10/05/14 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _KERNEL

#include <sys/types.h>
#include <sys/byteorder.h>

typedef struct ofv_resp_addr_t {
	union {
		uint64_t	_r_ll;
		uint32_t	_r_la[2];
	} _resp_un;
} ofv_resp_addr_t;

#define	r_laddr		_resp_un._r_ll
#ifdef	_LONG_LONG_HTOL
#define	r_notused	_resp_un._r_la[0]
#define	r_addr		_resp_un._r_la[1]
#else
#define	r_addr		_resp_un._r_la[0]
#define	r_notused	_resp_un._r_la[1]
#endif	/* _LONG_LONG_HTOL */

#endif /* _KERNEL */

#ifdef __cplusplus
}
#endif

#endif /* _SYS_IB_CLIENTS_OFA_SOLARIS_H */
