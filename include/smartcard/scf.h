/*
 * Copyright 2001-2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SMARTCARD_SCF_H
#define	_SMARTCARD_SCF_H

#pragma ident	"@(#)scf.h	1.1	02/02/24 SMI"

/*
 * Smartcard Low-Level API header file.
 *
 * This file contains all typedefs, prototypes, and #defines needed to use
 * the low-level Smart Card Framework (SCF) functions.
 */

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Typedefs.
 */
typedef unsigned int SCF_Status_t;
typedef uint32_t SCF_Event_t;
typedef struct SCF_PrivateSession_t *SCF_Session_t;
typedef struct SCF_PrivateTerminal_t *SCF_Terminal_t;
typedef struct SCF_PrivateCard_t *SCF_Card_t;
typedef struct SCF_PrivateListenerHandle_t *SCF_ListenerHandle_t;


/*
 * Structs.
 */
struct SCF_BinaryData_t {
	size_t length;
	uint8_t *data;
};

/*
 * Function Prototypes.
 */
SCF_Status_t SCF_Session_getSession(SCF_Session_t *);
SCF_Status_t SCF_Session_close(SCF_Session_t);
SCF_Status_t SCF_Session_getInfo(SCF_Session_t, const char *, void *);
SCF_Status_t SCF_Session_freeInfo(SCF_Session_t, void *);
SCF_Status_t SCF_Session_getTerminal(SCF_Session_t, const char *,
		SCF_Terminal_t *);

SCF_Status_t SCF_Terminal_close(SCF_Terminal_t);
SCF_Status_t SCF_Terminal_getInfo(SCF_Terminal_t, const char *, void *);
SCF_Status_t SCF_Terminal_freeInfo(SCF_Terminal_t, void *);
SCF_Status_t SCF_Terminal_waitForCardPresent(SCF_Terminal_t, unsigned int);
SCF_Status_t SCF_Terminal_waitForCardAbsent(SCF_Terminal_t, unsigned int);
SCF_Status_t SCF_Terminal_addEventListener(SCF_Terminal_t, SCF_Event_t,
		void(*)(SCF_Event_t, SCF_Terminal_t, void *), void *,
		SCF_ListenerHandle_t *);
SCF_Status_t SCF_Terminal_updateEventListener(SCF_Terminal_t,
		SCF_ListenerHandle_t, SCF_Event_t);
SCF_Status_t SCF_Terminal_removeEventListener(SCF_Terminal_t,
		SCF_ListenerHandle_t);
SCF_Status_t SCF_Terminal_getCard(SCF_Terminal_t, SCF_Card_t *);

SCF_Status_t SCF_Card_close(SCF_Card_t);
SCF_Status_t SCF_Card_getInfo(SCF_Card_t, const char *, void *);
SCF_Status_t SCF_Card_freeInfo(SCF_Card_t, void *);
SCF_Status_t SCF_Card_lock(SCF_Card_t, unsigned int);
SCF_Status_t SCF_Card_unlock(SCF_Card_t);
SCF_Status_t SCF_Card_exchangeAPDU(SCF_Card_t, const uint8_t *, size_t,
		uint8_t *, size_t *);
SCF_Status_t SCF_Card_waitForCardRemoved(SCF_Card_t, unsigned int);
SCF_Status_t SCF_Card_reset(SCF_Card_t);

const char *SCF_strerror(SCF_Status_t);


/*
 * #defines
 */
#define	SCF_STATUS_SUCCESS		0 /* Success.			*/
#define	SCF_STATUS_FAILED		1 /* An internal error occurred	*/
#define	SCF_STATUS_BADERRORCODE		2 /* (invalid error code)	*/
#define	SCF_STATUS_BADARGS		3 /* Invalid arguments supplied	*/
#define	SCF_STATUS_BADHANDLE		4 /* The handle is not valid	*/
#define	SCF_STATUS_BADTERMINAL		5 /* Unknown terminal name	*/
#define	SCF_STATUS_COMMERROR		6 /* Connection to server lost	*/
#define	SCF_STATUS_CARDLOCKED		7 /* Access denied due to lock	*/
#define	SCF_STATUS_DOUBLELOCK		8 /* Cannot lock card twice	*/
#define	SCF_STATUS_NOCARD		9 /* No card found in terminal	*/
#define	SCF_STATUS_CARDREMOVED		10 /* The card has been removed	*/
#define	SCF_STATUS_TIMEOUT		11 /* Timeout expired		*/
#define	SCF_STATUS_NOSPACE		12 /* APDU exceeds buffer size	*/
#define	SCF_STATUS_UNKNOWNPROPERTY	13 /* Property name not found	*/
#define	SCF_STATUS_NOLISTENER		14 /* No listener found		*/
#define	SCF_STATUS_MAX			14

#define	SCF_EVENT_COMMERROR		0x0001
#define	SCF_EVENT_TERMINALCLOSED	0x0002
#define	SCF_EVENT_CARDINSERTED		0x0004
#define	SCF_EVENT_CARDREMOVED		0x0008
#define	SCF_EVENT_CARDPRESENT		0x0010
#define	SCF_EVENT_CARDABSENT		0x0020
#define	SCF_EVENT_CARDRESET		0x0040
#define	SCF_EVENT_ALL			0x007F

#define	SCF_TIMEOUT_MAX 99999990

#ifdef __cplusplus
}
#endif

#endif /* _SMARTCARD_SCF_H */
