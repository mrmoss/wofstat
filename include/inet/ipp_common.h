/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_INET_IPP_COMMON_H
#define	_INET_IPP_COMMON_H

#pragma ident	"@(#)ipp_common.h	1.5	07/03/20 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef _KERNEL
#include <ipp/ipp.h>

/*
 * IPP  -- IP Policy -- interface.
 *
 * WARNING: Everything in this file is private, belonging to the IPP
 * subsystem.  The interfaces and declarations made here are subject
 * to change.
 */

extern uint32_t ipp_action_count;

/* Whether ip policy is enabled at callout position proc */
#define	IPP_ENABLED(proc, ipst)	((ipp_action_count != 0) && \
	(~((ipst)->ips_ip_policy_mask) & (proc)))

/* Apply IPQoS policies for inbound traffic? */
#define	IP6_IN_IPP(flags, ipst) (IPP_ENABLED(IPP_LOCAL_IN, ipst) &&	\
	(!((flags) & IP6_NO_IPPOLICY)))

/* Apply IPQoS policies for oubound traffic? */
#define	IP6_OUT_IPP(flags, ipst)	\
	(IPP_ENABLED(IPP_LOCAL_OUT, ipst) && (!((flags) & IP6_NO_IPPOLICY)))

/* Extracts 8 bit traffic class from IPV6 flow label field */
#ifdef  _BIG_ENDIAN
#define	__IPV6_TCLASS_FROM_FLOW(n)	(((n)>>20) & 0xff)
#else
#define	__IPV6_TCLASS_FROM_FLOW(n)	((((n)<<4) | (((n)>>12) & 0xf)) & 0xff)
#endif /* _BIG_ENDIAN */

typedef	enum {
	IPP_LOCAL_IN =	0x01,
	IPP_LOCAL_OUT =	0x02,
	IPP_FWD_IN =	0x04,
	IPP_FWD_OUT =	0x08
} ip_proc_t;

/* IP private data structure */
typedef	struct ip_priv {
	ip_proc_t	proc;
	uint32_t	ill_index;
} ip_priv_t;

/* The entry point for ip policy processing */
extern void ip_process(ip_proc_t, mblk_t **, uint32_t);
extern void ip_priv_free(void *);
#endif /* _KERNEL */


#ifdef	__cplusplus
}
#endif

#endif	/* _INET_IPP_COMMON_H */
