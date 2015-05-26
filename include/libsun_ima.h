/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/* header file for iSCSI tunable parameters properties function */

#ifndef	_LIBSUN_IMA_H
#define	_LIBSUN_IMA_H

#pragma ident	"@(#)libsun_ima.h	1.1	10/01/31 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#include <ima.h>

typedef enum {
	ISCSI_RX_TIMEOUT_VALUE = 1,
	ISCSI_CONN_DEFAULT_LOGIN_MAX = 2,
	ISCSI_LOGIN_POLLING_DELAY = 3
} ISCSI_TUNABLE_OBJECT_TYPE;

typedef struct _ISCSI_TUNABLE_PARAM {
	ISCSI_TUNABLE_OBJECT_TYPE tunable_objectType;
	IMA_CHAR *tunable_objectValue;
} ISCSI_TUNABLE_PARAM;

IMA_API IMA_STATUS SUN_IMA_SetTunableProperties(
		IMA_OID oid,
		ISCSI_TUNABLE_PARAM *param
);

IMA_API IMA_STATUS SUN_IMA_GetTunableProperties(
		IMA_OID oid,
		ISCSI_TUNABLE_PARAM *param
);

#ifdef __cplusplus
}
#endif

#endif /* _LIBSUN_IMA_H */
