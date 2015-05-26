/*
 * Copyright (c) 1999, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_HOTPLUG_PCI_PCICFG_H
#define	_SYS_HOTPLUG_PCI_PCICFG_H

#pragma ident	"@(#)pcicfg.h	1.11	12/09/25 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/* Bitmask flag for probing */
typedef	uint_t	pcicfg_flags_t;

#define	PCICFG_FLAG_PROBE_READONLY	0x1 /* virtual hotplug */
#define	PCICFG_FLAG_ENABLE_ARI		0x2 /* boot case */
#define	PCICFG_FLAG_PROBE_ONE		0x4 /* one level probe */

struct attach_tctl {
	dev_info_t	*dip;
	ksema_t	sema;
	int		err;
};

/*
 * Interfaces exported by PCI configurator module, kernel/misc/pcicfg.
 */
int pcicfg_configure(dev_info_t *, uint_t, uint_t, pcicfg_flags_t);
int pcicfg_unconfigure(dev_info_t *, uint_t, uint_t, pcicfg_flags_t);
int pcicfg_config_vf(dev_info_t *);
int pcicfg_unconfig_vf(dev_info_t *);

#define	PCICFG_SUCCESS DDI_SUCCESS
#define	PCICFG_FAILURE DDI_FAILURE
#define	PCICFG_NODEVICE	(-2)
#define	PCICFG_AGAIN (-3)

#define	PCICFG_ALL_DEVICE 0xffffffff
#define	PCICFG_ALL_FUNC 0xffffffff

/*
 * The following subclass definition for Non Transparent bridge should
 * be moved to pci.h.
 */
#define	PCI_BRIDGE_STBRIDGE	0x9

#define	PCICFG_CONF_INDIRECT_MAP	1
#define	PCICFG_CONF_DIRECT_MAP		0

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_HOTPLUG_PCI_PCICFG_H */
