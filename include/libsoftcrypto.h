/*
 * Copyright (c) 2011, Oracle and/or its affiliates. All rights reserved.
 */


#ifndef _LIBSOFTCRYPTO_H
#define	_LIBSOFTCRYPTO_H

#pragma ident	"@(#)libsoftcrypto.h	1.1	11/01/06 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <strings.h>
#include <sys/crypto/spi.h>
#include <sys/crypto/common.h>

typedef enum mechanism {
	CRYPTO_AES_ECB = 1,
	CRYPTO_AES_CBC,
	CRYPTO_AES_CBC_PAD,	/* Unsupported */
	CRYPTO_AES_CTR,		/* Unsupported */
	CRYPTO_AES_CCM,		/* Unsupported */
	CRYPTO_AES_GCM,		/* Unsupported */
	CRYPTO_AES_GMAC,	/* Unsupported */
	CRYPTO_AES_CFB128
} ucrypto_mech_t;


/*
 * This is a private interface to software crypto in the libsoftcrypto
 * library.
 *
 * Crypto context:
 *
 * crypto_ctx_t is a pointer to the crypto context that must be passed to
 * each of the functions to perform a multi-part operation.  The init
 * function will allocate and final function will the free the context.
 * On failure of any of the multi-part functions, the context will
 * be freed.
 * For atomic operations, the contexts in handled internally and no
 * user interaction is needed.
 *
 * IV:
 * Currently supported mechanisms take an (uchar_t *) as their initialization
 * vector.  Future, more complicated mechanisms may take structures.
 *
 * Output length:
 * For functions that have an "out_len", this variable will be set to
 * the length of the data returned by the operation.  In case the function
 * failures the value is not guaranteed to be zero.
 */

/* Encrypt multi-part */
extern int ucrypto_encrypt_init(crypto_ctx_t *context,
    ucrypto_mech_t mech_type, uchar_t *key_str, size_t key_len,
    void *iv, size_t iv_len);

extern int ucrypto_encrypt_update(crypto_ctx_t *context, uchar_t *in,
    size_t in_len, uchar_t *out, size_t *out_len);

extern int ucrypto_encrypt_final(crypto_ctx_t *context, uchar_t *out,
    size_t *out_len);

/* Encrypt atomic */
extern int ucrypto_encrypt(ucrypto_mech_t mech_type, uchar_t *key_str,
	size_t key_len, void *iv, size_t iv_len, uchar_t *in,
	size_t in_len, uchar_t *out, size_t *out_len);

/* Decrypt multi-part */
extern int ucrypto_decrypt_init(crypto_ctx_t *context,
    ucrypto_mech_t mech_type, uchar_t *key_str, size_t key_len,
    void *iv, size_t iv_len);

extern int ucrypto_decrypt_update(crypto_ctx_t *context, uchar_t *in,
    size_t in_len, uchar_t *out, size_t *out_len);

extern int ucrypto_decrypt_final(crypto_ctx_t *context, uchar_t *out,
    size_t *out_len);

/* Decrypt atomic */
extern int ucrypto_decrypt(ucrypto_mech_t mech_type, uchar_t *key_str,
    size_t key_len, void *iv, size_t iv_len, uchar_t *in,
    size_t in_len, uchar_t *out, size_t *out_len);


#ifdef __cplusplus
}
#endif

#endif /* _LIBSOFTCRYPTO_H */
