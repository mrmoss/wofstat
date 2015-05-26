/*
 * Copyright (c) 1998, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_USB_HUB_H
#define	_SYS_USB_HUB_H

#pragma ident	"@(#)hub.h	1.8	12/04/23 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#define	USB_DESCR_TYPE_SETUP_HUB	0x2900
#define	USB3_DESCR_TYPE_SETUP_HUB	0x2a00

/*
 * Section 11.11.2.1 allows up to 255 ports.
 * For simplicity, only a maximum of 31 ports is currently allowed
 */
#define	MAX_PORTS 31

typedef struct usb_hub_descr {
	uchar_t		bDescLength;	/* size of descriptor */
	uchar_t		bDescriptorType; /* descriptor type */
	uchar_t		bNbrPorts;	/* number of ports */
	uint16_t	wHubCharacteristics; /* hub characteristics */
	uchar_t		bPwrOn2PwrGood;	/* time in ms from the time */
				/* power on sequence begins on a port */
				/* until power is good on that port */
	uchar_t		bHubContrCurrent; /* max current requirements */
	uchar_t		DeviceRemovable;
					/* removable device attached */
	uchar_t		PortPwrCtrlMask;
					/* power control mask */
} usb_hub_descr_t;

/*
 * SuperSpeed hub descriptor, refer to the table 10-3 in USB 3.0 v1.0 spec.
 */
typedef struct usb3_hub_descr {
	uchar_t		bDescLength;	/* size of descriptor */
	uchar_t		bDescriptorType;
					/* descriptor type */
	uchar_t		bNbrPorts;	/* number of ports */
	uint16_t	wHubCharacteristics;
					/* hub characteristics */
	uchar_t		bPwrOn2PwrGood;	/* time in ms from the time */
				/* power on sequence begins on a port */
				/* until power is good on that port */
	uchar_t		bHubContrCurrent;
					/* max current requirements */
	uchar_t		bHubHdrDecLat;	/* Hub Packet Header Decode Latency */
	uint16_t	wHubDelay; 	/* Hub delay */
	uint16_t	DeviceRemovable;
					/* removable device attached */
} usb3_hub_descr_t;

#define	USB3_HUB_DESCR_SIZE	12
#define	USB_HUB_TT_SHIFT	5
#define	USB_HUB_TT_MASK		0x60

/*
 * it is specific for the xhci root hub.
 */
typedef struct xhci_rh_data {
	usb_hub_descr_t	usb2_hub_descr; /* usb2 hub descriptor */
	uint8_t		port_array[256]; /* xhci root hub ports array info */
} xhci_rh_data_t;

/* setup the wIndex value for port_link request */
#define	PORT_LINK_VAL(link_state, port)	(((link_state << 3) & 0xff00) |  \
					    (port & 0xff))

#define	ROOT_HUB_DESCRIPTOR_LENGTH	9
#define	ROOT_HUB_DESCRIPTOR_TYPE	0x29
#define	ROOT_HUB_ADDR			0x01	/* address of USB2.0 root hub */

#define	USB3_HUB_DESCR_TYPE		0x2a
#define	USB3_ROOT_HUB_ADDR		0x80	/* address of USB3.0 root hub */

/* Values for wHubCharacteristics */
#define	HUB_CHARS_POWER_SWITCHING_MODE	0x03
#define	HUB_CHARS_GANGED_POWER		0x00
#define	HUB_CHARS_INDIVIDUAL_PORT_POWER	0x01
#define	HUB_CHARS_NO_POWER_SWITCHING	0x02
#define	HUB_CHARS_COMPOUND_DEV		0x04
#define	HUB_CHARS_GLOBAL_OVER_CURRENT	0x00
#define	HUB_CHARS_INDIV_OVER_CURRENT	0x08
#define	HUB_CHARS_NO_OVER_CURRENT	0x10

/*
 * For USB 3.0 hub, the b5-b15 are reserved.
 * refer to the table 10-3 in the USB3.0 spec
 */
#define	HUB_CHARS_TT_THINK_TIME		0x60
#define	HUB_CHARS_TT_16FS_TIME		0x20
#define	HUB_CHARS_TT_24FS_TIME		0x40
#define	HUB_CHARS_TT_32FS_TIME		0x60
#define	HUB_CHARS_PORT_INDICATOR	0x80

/* Default Power On to Power Good time */
#define	HUB_DEFAULT_POPG	10
#define	USB3_HUB_DEFAULT_POPG	100

/* Hub Status */
#define	HUB_CHANGE_STATUS	0x01

/* Class Specific bmRequestType values Table 11-10 */
#define	HUB_HANDLE_PORT_FEATURE_TYPE	(USB_DEV_REQ_HOST_TO_DEV \
					|USB_DEV_REQ_TYPE_CLASS \
					|USB_DEV_REQ_RCPT_OTHER)

#define	HUB_GET_PORT_STATUS_TYPE	(USB_DEV_REQ_DEV_TO_HOST \
					|USB_DEV_REQ_TYPE_CLASS \
					|USB_DEV_REQ_RCPT_OTHER)

#define	HUB_CLASS_REQ_TYPE		(USB_DEV_REQ_DEV_TO_HOST \
					|USB_DEV_REQ_TYPE_CLASS)

#define	HUB_HANDLE_HUB_FEATURE_TYPE	USB_DEV_REQ_TYPE_CLASS

#define	HUB_HANDLE_HUB_PORTERROR_TYPE	USB_DEV_REQ_DEV_TO_HOST

#define	HUB_SET_DEPTH_TYPE		USB_DEV_REQ_TYPE_CLASS

/* bmRequestType for getting device status */
#define	HUB_GET_DEVICE_STATUS_TYPE	(USB_DEV_REQ_DEV_TO_HOST \
					|USB_DEV_REQ_TYPE_STANDARD \
					|USB_DEV_REQ_RCPT_DEV)

/* Port Status Field Bits - Table 11-15 in USB2.0 spec. */
#define	PORT_STATUS_CCS		0x0001	/* port connection status */
#define	PORT_STATUS_PES		0x0002	/* port enable status */
#define	PORT_STATUS_PSS		0x0004	/* port suspend status */
					/* Reserved for the USB 3.0 hub */
#define	PORT_STATUS_POCI	0x0008	/* port over current indicator */
#define	PORT_STATUS_PRS		0x0010	/* port reset status */
#define	PORT_STATUS_PPS		0x0100	/* port power status for USB 2.0 hub */
#define	PORT_STATUS_LSDA	0x0200	/* low speed device */
#define	PORT_STATUS_HSDA	0x0400	/* high speed device */
#define	PORT_STATUS_PIC		0x1000	/* port indicator control */

#define	PORT_STATUS_MASK	0x171f
#define	PORT_STATUS_OK		0x103	/* connected, enabled, power */

/*
 * Port link state, bit 5-8 in the table 10-10 of USB 3.0 spec.
 * They are reserved for USB 2.0 hub.
 */
#define	PORT_LINK_STATE_MASK	0x1e0
#define	PORT_LINK_U0		0x0
#define	PORT_LINK_U1		0x20
#define	PORT_LINK_U2		0x40
#define	PORT_LINK_U3		0x60
#define	PORT_LINK_SS_DISABLED	0x80
#define	PORT_LINK_RX_DETECT	0xa0
#define	PORT_LINK_SS_INACTIVE	0xc0
#define	PORT_LINK_POLLING	0xe0
#define	PORT_LINK_RECOVERY	0x100
#define	PORT_LINK_HOT_RESET	0x120
#define	PORT_LINK_COMPLIANCE	0x140
#define	PORT_LINK_LOOPBACK	0x160

#define	USB3_PORT_STATUS_PPS	0x0200	/* port power status for USB 3.0 hub */
#define	USB3_PORT_STATUS_OK	0x203	/* connected, enabled, power for */
					/* USB 3.0 hub */

/* Port speed status, bit 10-12, only for USB 3.0 hub */
#define	PORT_SPEED_MASK		0x1c00
#define	PORT_SUPER_SPEED	0
#define	USB3_PORT_STATUS_MASK	0x1ffb

/* Port Change Field Bits - Table 11-16 in USB2.0 spec */
#define	PORT_CHANGE_CSC		0x0001	/* connect status change */
#define	PORT_CHANGE_PESC	0x0002	/* port enable change */
					/* Reserved for the USB 3.0 hub */
#define	PORT_CHANGE_PSSC	0x0004	/* port suspend change */
					/* Reserved for the USB 3.0 hub */
#define	PORT_CHANGE_OCIC	0x0008	/* over current change */
#define	PORT_CHANGE_PRSC	0x0010	/* port reset change */

#define	PORT_CHANGE_MASK	0x001f

/* The 3 bits are specific for USB3.0, refer to table 10-11 in USB3.0 spec. */
#define	PORT_CHANGE_BH_PRSC	0x0020	/* port BH reset change */
#define	PORT_CHANGE_PLSC	0x0040	/* port link state change */
#define	PORT_CHANGE_PCEC	0x0080	/* port configure error change */

#define	USB3_PORT_CHANGE_MASK	0x00f9

/* Hub status Field Bits - Table 11-14 */
#define	HUB_LOCAL_POWER_STATUS	0x0001	/* state of the power supply */
#define	HUB_OVER_CURRENT	0x0002  /* global hub OC condition */

/* Hub change clear feature selectors - Table 11-15 */
#define	C_HUB_LOCAL_POWER_STATUS 0x0001 /* state of the power supply */
#define	C_HUB_OVER_CURRENT	 0x0002 /* global hub OC condition */

/* hub class feature selectors - Table 11-12. Table 10-7 in USB 3.0 spec */
#define	CFS_C_HUB_LOCAL_POWER		0
#define	CFS_C_HUB_OVER_CURRENT		1
#define	CFS_PORT_CONNECTION		0
#define	CFS_PORT_ENABLE			1
#define	CFS_PORT_SUSPEND		2
#define	CFS_PORT_OVER_CURRENT		3
#define	CFS_PORT_RESET			4
#define	CFS_PORT_LINK_STATE		5
#define	CFS_PORT_POWER			8
#define	CFS_PORT_LOW_SPEED		9
#define	CFS_C_PORT_CONNECTION		16
#define	CFS_C_PORT_ENABLE		17
#define	CFS_C_PORT_SUSPEND		18
#define	CFS_C_PORT_OVER_CURRENT 	19
#define	CFS_C_PORT_RESET		20
#define	CFS_PORT_TEST			21
#define	CFS_PORT_INDICATOR		22
#define	CFS_PORT_U1_TIMEOUT		23
#define	CFS_PORT_U2_TIMEOUT		24
#define	CFS_C_PORT_LINK_STATE		25
#define	CFS_C_PORT_CONFIG_ERROR		26
#define	CFS_PORT_REMOTE_WAKE_MASK	27
#define	CFS_BH_PORT_RESET		28
#define	CFS_C_BH_PORT_RESET		29
#define	CFS_FORCE_LINKPM_ACCEPT		30

/*
 * Hub class request code - Table 10-6 in USB 3.0 spec
 * Most of them are defined in the usbai.h as the standard requests.
 */
#define	USB_HUB_SET_DEPTH		0x0c
#define	USB_HUB_GET_PORT_ERR_CNT	0x0d

/* For the USB3.0 hubs, the valid value of depth is 0 through 4. */
#define	USB_HUB_MAX_DEPTH		4

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_USB_HUB_H */
