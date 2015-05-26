/*
 * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_INET_IP_NETINFO_H
#define	_INET_IP_NETINFO_H

#pragma ident	"@(#)ip_netinfo.h	1.3	09/01/06 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef _KERNEL

extern ddi_taskq_t *eventq_queue_nic;

extern void ip_net_g_init();
extern void ip_net_g_destroy();
extern void ip_net_init(ip_stack_t *, netstack_t *);
extern void ip_net_destroy(ip_stack_t *);
extern void ipv4_hook_init(ip_stack_t *);
extern void ipv6_hook_init(ip_stack_t *);
extern void ipv4_hook_destroy(ip_stack_t *);
extern void ipv6_hook_destroy(ip_stack_t *);
extern void ipv4_hook_shutdown(ip_stack_t *);
extern void ipv6_hook_shutdown(ip_stack_t *);
extern void ip_ne_queue_func(void *);

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _INET_IP_NETINFO_H */
