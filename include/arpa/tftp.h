/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *		PROPRIETARY NOTICE (Combined)
 *
 * This source code is unpublished proprietary information
 * constituting, or derived under license from AT&T's UNIX(r) System V.
 * In addition, portions of such source code were derived from Berkeley
 * 4.3 BSD under license from the Regents of the University of
 * California.
 *
 *
 *
 *		Copyright Notice
 *
 * Notice of copyright on this source code product does not indicate
 * publication.
 *
 *	(c) 1983,1984,1985,1986,1987,1988,1989  AT&T.
 *		All rights reserved.
 *
 * Copyright (c) 1986-1989,2001 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef _ARPA_TFTP_H
#define	_ARPA_TFTP_H

#pragma ident	"@(#)tftp.h	1.8	01/12/21 SMI"	/* SVr4.0 1.1	*/

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Trivial File Transfer Protocol (RFC 1350, RFC 2347)
 */
#define	SEGSIZE		512		/* data segment size */

/*
 * Packet types.
 */
#define	RRQ	01			/* read request */
#define	WRQ	02			/* write request */
#define	DATA	03			/* data packet */
#define	ACK	04			/* acknowledgement */
#define	ERROR	05			/* error code */
#define	OACK	06			/* option acknowledgement */

struct	tftphdr {
	short		th_opcode;	/* packet type */
	ushort_t	th_block;	/* block # */
	char		th_data[1];	/* data or error string */
};

#define	th_code		th_block	/* error code overlay on tu_block */
#define	th_stuff	th_block	/* ditto */

#define	th_msg		th_data

/*
 * Error codes.
 */
#define	EUNDEF		0		/* not defined */
#define	ENOTFOUND	1		/* file not found */
#define	EACCESS		2		/* access violation */
#define	ENOSPACE	3		/* disk full or allocation exceeded */
#define	EBADOP		4		/* illegal TFTP operation */
#define	EBADID		5		/* unknown transfer ID */
#define	EEXISTS		6		/* file already exists */
#define	ENOUSER		7		/* no such user */
#define	EOPTNEG		8		/* option negotiation error */

#ifdef	__cplusplus
}
#endif

#endif	/* _ARPA_TFTP_H */
