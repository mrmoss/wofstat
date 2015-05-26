/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_IB_MGT_IBMF_IBMF_UTILS_H
#define	_SYS_IB_MGT_IBMF_IBMF_UTILS_H

#pragma ident	"@(#)ibmf_utils.h	1.1	03/08/05 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This file contains helper functions for parsing management
 * datagram MADs.
 */
void
ibmf_utils_unpack_data(char *format, uchar_t *data, size_t datalen,
    void *structure, size_t structlen);

void
ibmf_utils_pack_data(char *format, void *structure, size_t structlen,
    uchar_t *data, size_t datalen);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_IB_MGT_IBMF_IBMF_UTILS_H */
