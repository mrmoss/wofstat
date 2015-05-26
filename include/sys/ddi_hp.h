/*
 * Copyright (c) 2010, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_DDI_HP_H
#define	_SYS_DDI_HP_H

#pragma ident	"@(#)ddi_hp.h	1.3	12/06/26 SMI"

/*
 * Sun DDI hotplug support definitions
 */

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * ddi_hp_cn_state_t
 *
 * Typedef of generic hotplug state machine for Hotplug Connection (CN)
 */
typedef enum {
	DDI_HP_CN_STATE_EMPTY		= 0x1000, /* Empty */
	DDI_HP_CN_STATE_PRESENT		= 0x2000, /* A Device Present */
	DDI_HP_CN_STATE_POWERED		= 0x3000, /* Powered */
	DDI_HP_CN_STATE_ENABLED		= 0x4000, /* Enabled */
	DDI_HP_CN_STATE_PORT_EMPTY	= 0x5000, /* PORT Empty */
	DDI_HP_CN_STATE_PORT_PRESENT	= 0x6000, /* A Device Node Present */
	DDI_HP_CN_STATE_OFFLINE		= 0x7000, /* Driver not attached */
	DDI_HP_CN_STATE_ATTACHED	= 0x8000, /* Device driver attached */
	DDI_HP_CN_STATE_MAINTENANCE	= 0x9000, /* Device in maintenance */
	DDI_HP_CN_STATE_ONLINE		= 0xa000  /* Device is ready */
} ddi_hp_cn_state_code_t;


/* Probe one node by each change-state command */
#define	DDI_HP_FLAG_PROBE_ONE	0x1

typedef struct ddi_hp_cn_state {
	ddi_hp_cn_state_code_t state_code;
	int flags; /* DDI_HP_FLAG_PROBE_ONE */
} ddi_hp_cn_state_t;

#if defined(_SYSCALL32)
typedef struct ddi_hp_cn_state32 {
	uint32_t state_code;
	int32_t flags; /* DDI_HP_FLAG_PROBE_ONE */
} ddi_hp_cn_state32_t;
#endif

/*
 * ddi_hp_cn_type_t
 *
 * Typedef for Hotplug Connection (CN) types.
 */
typedef enum {
	DDI_HP_CN_TYPE_PORT_PCI		= 0x0001, /* PCI Function */
	DDI_HP_CN_TYPE_PORT_IOV_PF	= 0x0002, /* IOV Physical Function */
	DDI_HP_CN_TYPE_PORT_IOV_VF	= 0x0003, /* IOV Virtual Function */
	DDI_HP_CN_TYPE_PORT_SUN4V	= 0x0004, /* SUN4V bus device */
	DDI_HP_CN_TYPE_PCI		= 0x1001, /* PCI bus slot */
	DDI_HP_CN_TYPE_PCIE		= 0x1002  /* PCI Express slot */
} ddi_hp_cn_type_t;

/* All connector types will have 0x1000 bit set */
#define	DDI_HP_CN_TYPE_CONNECTOR_MASK	0x1000

#define	DDI_HP_CN_TYPE_STR_PORT_PCI	"Virtual-Port-PCI"
#define	DDI_HP_CN_TYPE_STR_PORT_IOV_PF	"Virtual-Port-IOV-PF"
#define	DDI_HP_CN_TYPE_STR_PORT_IOV_VF	"Virtual-Port-IOV-VF"
#define	DDI_HP_CN_TYPE_STR_PORT_SUN4V	"Virtual-Port-SUN4V"

/*
 * The value set to ddi_hp_cn_info_t->cn_num_dpd_on in the case of the
 * connection does not depend on any other connections.
 */
#define	DDI_HP_CN_NUM_NONE	-1

/*
 * ddi_hp_cn_info_t
 *
 * Hotplug Connection (CN) information structure
 */
typedef struct ddi_hp_cn_info {
	char			*cn_name;	/* Name of the Connection */
	/*
	 * Connection number.
	 */
	int			cn_num;
	/*
	 * Depend-on connection number;
	 * The connection number on which this connection is depending on.
	 * If this connection does not depend on any other connections
	 * under the same parent node, then it's cn_num_dpd_on is set to
	 * DDI_HP_CN_NUM_NONE.
	 */
	int			cn_num_dpd_on;

	ddi_hp_cn_type_t	cn_type;	/* Type: Port, PCI, PCIE, ... */

	/*
	 * Description string for types of Connection. Set by bus software
	 * and read by users only.
	 */
	char			*cn_type_str;
	/*
	 * The child device of this Port.
	 * It is NULL if this is a Connector.
	 */
	dev_info_t		*cn_child;

	ddi_hp_cn_state_code_t	cn_state;	/* Hotplug Connection state */
	/*
	 * The top state to which this connection is allowed to be upgraded.
	 * By default, it is DDI_HP_CN_STATE_ONLINE.
	 */
	ddi_hp_cn_state_code_t	cn_state_ceiling;
	uint32_t		cn_state_ceiling_handle;

	time32_t		cn_last_change;	/* Last time state changed. */
} ddi_hp_cn_info_t;

typedef struct ddi_hp_property {
	char	*nvlist_buf;
	size_t	buf_size;
} ddi_hp_property_t;

#if defined(_SYSCALL32)
typedef struct ddi_hp_property32 {
	caddr32_t	nvlist_buf;
	uint32_t	buf_size;
} ddi_hp_property32_t;
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DDI_HP_H */
