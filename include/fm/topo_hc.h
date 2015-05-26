/*
 * Copyright (c) 2006, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _TOPO_HC_H
#define	_TOPO_HC_H

#pragma ident	"@(#)topo_hc.h	1.14	11/03/21 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Allowable hardware component names for hc FMRIs
 */
#define	BANK		"bank"
#define	BAY		"bay"
#define	BLADE		"blade"
#define	BRANCH		"branch"
#define	CMP		"CMP"
#define	CENTERPLANE	"centerplane"
#define	CHASSIS		"chassis"
#define	CHIP		"chip"
#define	CORE		"core"
#define	STRAND		"strand"
#define	CHIP_SELECT	"chip-select"
#define	CONTROLLER	"controller"
#define	CPU		"cpu"
#define	CPUBOARD	"cpuboard"
#define	DIMM		"dimm"
#define	DISK		"disk"
#define	DRAM		"dram"
#define	DRAMCHANNEL	"dram-channel"
#define	FAN		"fan"
#define	FANBOARD	"fanboard"
#define	FANMODULE	"fanmodule"
#define	HBA		"hba"
#define	HOSTBRIDGE	"hostbridge"
#define	INTERCONNECT	"interconnect"
#define	IOBOARD		"ioboard"
#define	IPORT		"iport"
#define	MEMBOARD	"memboard"
#define	MEMORYBUFFER	"memory-buffer"
#define	MEMORYCONTROL	"memory-controller"
#define	MICROCORE	"micro-core"
#define	MOTHERBOARD	"motherboard"
#define	NIU		"niu"
#define	NIUFN		"niufn"
#define	PCI_BUS		"pcibus"
#define	PCI_DEVICE	"pcidev"
#define	PCI_FUNCTION    "pcifn"
#define	PCIEX_BUS	"pciexbus"
#define	PCIEX_DEVICE	"pciexdev"
#define	PCIEX_FUNCTION  "pciexfn"
#define	PCIEX_ROOT	"pciexrc"
#define	PCIEX_SWUP	"pciexswu"
#define	PCIEX_SWDWN	"pciexswd"
#define	POWERBOARD	"powerboard"
#define	POWERMODULE	"powermodule"
#define	PSU		"psu"
#define	RANK		"rank"
#define	RECEPTACLE	"receptacle"
#define	RISER		"riser"
#define	SASEXPANDER	"sas-expander"
#define	SHELF		"shelf"
#define	SCSI_DEVICE	"scsi-device"
#define	SES_ENCLOSURE	"ses-enclosure"
#define	SP		"sp"
#define	SUBCHASSIS	"subchassis"
#define	SYSTEMBOARD	"systemboard"
#define	XAUI		"xaui"
#define	XFP		"xfp"

/*
 * Allowable hc node property group and property names
 */
#define	TOPO_PGROUP_IO		"io"
#define	TOPO_IO_DEVTYPE		"devtype"
#define	TOPO_IO_DRIVER		"driver"
#define	TOPO_IO_MODULE		"module"
#define	TOPO_IO_DEV		"dev"
#define	TOPO_IO_DEVID		"devid"
#define	TOPO_IO_DEV_PATH	"devfs-path"
#define	TOPO_IO_AP_PATH		"ap-path"
#define	TOPO_IO_PHYS_PATH	"phys-path"

#define	TOPO_PGROUP_PCI		"pci"
#define	TOPO_PCI_VENDID		"vendor-id"
#define	TOPO_PCI_DEVID		"device-id"
#define	TOPO_PCI_EXCAP		"extended-capabilities"
#define	TOPO_PCI_BDF		"BDF"
#define	TOPO_PCI_CLASS		"class-code"
#define	TOPO_PCI_AADDR		"assigned-addresses"

#define	TOPO_PGROUP_BINDING	"binding"
#define	TOPO_BINDING_OCCUPANT	"occupant-path"

#define	TOPO_PGROUP_STORAGE	"storage"
#define	TOPO_STORAGE_INITIATOR_PORT	"initiator-port"
#define	TOPO_STORAGE_INITIATOR_PORT_PM	"initiator-port-pm"
#define	TOPO_STORAGE_TARGET_PORT	"target-port"
#define	TOPO_STORAGE_TARGET_PORT_L0ID	"target-port-l0id"
#define	TOPO_STORAGE_TARGET_PORT_L0IDS	"target-port-l0ids"
#define	TOPO_STORAGE_ATTACHED_PORT	"attached-port"
#define	TOPO_STORAGE_TARGET_PORT_PM	"target-port-pm"
#define	TOPO_STORAGE_ATTACHED_PORT_PM	"attached-port-pm"
#define	TOPO_STORAGE_DEVID		"devid"
#define	TOPO_STORAGE_LUN64		"lun64"
#define	TOPO_STORAGE_DEVICE_TYPE	"inquiry-device-type"
#define	TOPO_STORAGE_MANUFACTURER	"manufacturer"
#define	TOPO_STORAGE_MODEL		"model"
#define	TOPO_STORAGE_FIRMWARE_REV	"firmware-revision"
#define	TOPO_STORAGE_SAS_PHY_MASK	"receptacle-pm"
#define	TOPO_STORAGE_SAS_CONNECTOR_TYPE	"sas-connector-type"

#define	TOPO_PGROUP_SES		"ses"
/* Applied  any SES standard related topo node. */
#define	TOPO_PROP_NODE_ID	"node-id"
#define	TOPO_PROP_TARGET_PATH	"target-path"
#define	TOPO_PROP_SES_DEVID	"ses-devid"
#define	TOPO_PROP_SES_DEV_PATH	"ses-devfs-path"
#define	TOPO_PROP_SES_PHYS_PATH	"ses-phys-path"
#define	TOPO_PROP_SES_TARGET_PORT "ses-target-port"

#define	TOPO_PGROUP_SMP		"smp"
/* host SMP target related info for an expander node. */
#define	TOPO_PROP_SMP_DEVID	"smp-devid"
#define	TOPO_PROP_SMP_DEV_PATH	"smp-devfs-path"
#define	TOPO_PROP_SMP_PHYS_PATH	"smp-phys-path"
#define	TOPO_PROP_SMP_TARGET_PORT	"smp-target-port"
#define	TOPO_PROP_SAS_ADDR	"sas-address"
#define	TOPO_PROP_PHY_COUNT	"phy-count"
#define	TOPO_PROP_PATHS		"paths"
#define	TOPO_PROP_CHASSIS_TYPE	"chassis-type"
#define	TOPO_PROP_SAS_PHY_MASK	"phy-mask"
#define	TOPO_PROP_SAS_CONNECTOR_TYPE	"sas-connector-type"

#ifdef	__cplusplus
}
#endif

#endif	/* _TOPO_HC_H */
