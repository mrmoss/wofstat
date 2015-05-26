/*
 * Copyright 2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _IFDHANDLER_H
#define	_IFDHANDLER_H

#pragma ident	"@(#)ifdhandler.h	1.1	02/11/25 SMI"

/*
 * The content of this file is based on content
 * of "ifdhandler.h" and "pcscdefines.h" file in
 * the "MUSCLE PC/SC IFD Driver Developer Kit".
 * To view license terms, attribution,
 * and copyright for the content of this file,
 * the default path is /var/sadm/pkg/SUNWocfh/install/copyright.
 * If the Solaris operating environment has been installed
 * anywhere other than the default, modify the given path
 * to access the file at the installed location.
 *
 */

/*
 *
 * License:   Copyright (C) 1999 David Corcoran
 *            <corcoran@linuxnet.com>
 * Purpose:   This provides reader specific low-level calls.
 *            See http://www.linuxnet.com for more information.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Basic data types used in various functions
 */
typedef unsigned long	DWORD;
typedef unsigned long	*PDWORD;
typedef unsigned long	*PULONG;
typedef unsigned char	UCHAR;
typedef unsigned char	*PUCHAR;
typedef char		*LPSTR;
typedef long		RESPONSECODE;

/*
 * Various Capability TAGs supported
 */
#define	TAG_IFD_ATR			0x0303
#define	TAG_IFD_SLOTNUM			0x0180
#define	TAG_IFD_SLOTS_NUMBER		0x0FAE
#define	TAG_IFD_SIMULTANEOUS_ACCESS	0x0FAF

/*
 * Power up/down/reset states of smart card
 */
#define	IFD_POWER_UP			500
#define	IFD_POWER_DOWN			501
#define	IFD_RESET			502

/*
 * PTS(Protocol Type Selection)
 */
#define	IFD_NEGOTIATE_PTS1		1
#define	IFD_NEGOTIATE_PTS2		2
#define	IFD_NEGOTIATE_PTS3		4

typedef struct _SCARD_IO_HEADER
{
	DWORD Protocol;
	DWORD Length;
} SCARD_IO_HEADER, *PSCARD_IO_HEADER;

/*
 * Various RESPONSECODE definitions
 */
#define	IFD_SUCCESS			0
#define	IFD_ERROR_TAG			600
#define	IFD_ERROR_SET_FAILURE		601
#define	IFD_ERROR_VALUE_READ_ONLY	602
#define	IFD_ERROR_PTS_FAILURE		605
#define	IFD_ERROR_NOT_SUPPORTED		606
#define	IFD_PROTOCOL_NOT_SUPPORTED	607
#define	IFD_ERROR_POWER_ACTION		608
#define	IFD_ERROR_SWALLOW		609
#define	IFD_ERROR_EJECT			610
#define	IFD_ERROR_CONFISCATE		611
#define	IFD_COMMUNICATION_ERROR		612
#define	IFD_RESPONSE_TIMEOUT		613
#define	IFD_NOT_SUPPORTED		614
#define	IFD_ICC_PRESENT			615
#define	IFD_ICC_NOT_PRESENT		616

/*
 * Miscellaneous defines
 */
#define	MAX_RESPONSE_SIZE		264	/* Max. size of resp. buffer */
#define	MAX_BUFFER_SIZE			264	/* Max. size of req. buffer */
#define	MAX_ATR_SIZE			33	/* Max size of ATR + 1 */

/*
 * Functions prototypes
 */
RESPONSECODE IFDHCreateChannelByName(DWORD, LPSTR);
RESPONSECODE IFDHCreateChannel(DWORD, DWORD);
RESPONSECODE IFDHCloseChannel(DWORD);
RESPONSECODE IFDHGetCapabilities(DWORD, DWORD, PDWORD, PUCHAR);
RESPONSECODE IFDHSetCapabilities(DWORD, DWORD, DWORD, PUCHAR);
RESPONSECODE IFDHSetProtocolParameters(DWORD, DWORD, UCHAR,
	UCHAR, UCHAR, UCHAR);
RESPONSECODE IFDHPowerICC(DWORD, DWORD, PUCHAR, PDWORD);
RESPONSECODE IFDHTransmitToICC(DWORD, SCARD_IO_HEADER, PUCHAR,
	DWORD, PUCHAR, PDWORD, PSCARD_IO_HEADER);
RESPONSECODE IFDHControl(DWORD, PUCHAR, DWORD, PUCHAR, PDWORD);
RESPONSECODE IFDHICCPresence(DWORD);

#ifdef __cplusplus
}
#endif

#endif /* _IFDHANDLER_H */
