/*
 * This handles smartcard reader communications.
 *
 * MUSCLE SmartCard Development ( http://www.linuxnet.com )
 *
 * Copyright (C) 1999-2003
 *  David Corcoran <corcoran@linuxnet.com>
 *  Ludovic Rousseau <ludovic.rousseau@free.fr>
 *
 * $Id: winscard.h,v 1.1 2004/06/10 19:52:34 ehersked Exp $
 */

#ifndef	_WINSCARD_H_
#define	_WINSCARD_H_

#pragma ident	"@(#)winscard.h	1.2 04/06/08"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__APPLE__)
#include <PCSC/pcsclite.h>
#else
#include <pcsclite.h>
#endif

	LONG SCardEstablishContext(ULONG dwScope,
		const void *pvReserved1,
		const void *pvReserved2,
		LONG *phContext);

	LONG SCardReleaseContext(LONG hContext);

	LONG SCardSetTimeout(LONG hContext, ULONG dwTimeout);

	LONG SCardConnect(LONG hContext,
		const char *szReader,
		ULONG dwShareMode,
		ULONG dwPreferredProtocols,
		LONG *phCard, ULONG *pdwActiveProtocol);

	LONG SCardReconnect(LONG hCard,
		ULONG dwShareMode,
		ULONG dwPreferredProtocols,
		ULONG dwInitialization,
		ULONG *pdwActiveProtocol);

	LONG SCardDisconnect(LONG hCard, ULONG dwDisposition);

	LONG SCardBeginTransaction(LONG hCard);

	LONG SCardEndTransaction(LONG hCard, ULONG dwDisposition);

	LONG SCardCancelTransaction(LONG hCard);

	LONG SCardStatus(LONG hCard,
		char *mszReaderNames,
		ULONG *pcchReaderLen,
		ULONG *pdwState,
		ULONG *pdwProtocol,
		unsigned char *pbAtr, ULONG *pcbAtrLen);

	LONG SCardGetStatusChange(LONG hContext,
		ULONG dwTimeout,
		LPSCARD_READERSTATE_A rgReaderStates, ULONG cReaders);

	LONG SCardControl(LONG hCard,
		const unsigned char *pbSendBuffer,
		ULONG cbSendLength,
		unsigned char *pbRecvBuffer, ULONG *pcbRecvLength);

	LONG SCardTransmit(LONG hCard,
		LPCSCARD_IO_REQUEST pioSendPci,
		const unsigned char *pbSendBuffer,
		ULONG cbSendLength,
		LPSCARD_IO_REQUEST pioRecvPci,
		unsigned char *pbRecvBuffer, ULONG *pcbRecvLength);

	LONG SCardListReaderGroups(LONG hContext,
		char *mszGroups, ULONG *pcchGroups);

	LONG SCardListReaders(LONG hContext,
		const char *mszGroups,
		char *mszReaders, ULONG *pcchReaders);

	LONG SCardCancel(LONG hContext);

	void SCardUnload(void);

#ifdef __cplusplus
}
#endif

#endif /* _WINSCARD_H_ */
