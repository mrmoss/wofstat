/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_SHA1_H
#define	_SYS_SHA1_H

#pragma ident	"@(#)sha1.h	1.4	07/03/05 SMI"

#include <sys/types.h>		/* for uint_* */

#ifdef	__cplusplus
extern "C" {
#endif

/* SHA-1 context. */
typedef struct 	{
	uint32_t state[5];	/* state (ABCDE) */
	uint32_t count[2];	/* number of bits, modulo 2^64 (msb first) */
	union 	{
		uint8_t		buf8[64];	/* undigested input */
		uint32_t	buf32[16];	/* realigned input */
	} buf_un;
} SHA1_CTX;

void SHA1Init(SHA1_CTX *);
void SHA1Update(SHA1_CTX *, const void *, size_t);
void SHA1Final(void *, SHA1_CTX *);

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_SHA1_H */
