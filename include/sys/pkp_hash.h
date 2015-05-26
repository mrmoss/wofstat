/*
 * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_PKP_HASH_H_
#define	_PKP_HASH_H_

#pragma ident	"@(#)pkp_hash.h	1.1	10/09/17 SMI"

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pearson's string hash
 *
 * See: Communications of the ACM, June 1990 Vol 33 pp 677-680
 * http://portal.acm.org/citation.cfm?doid=78973.78978
 */
#define	PKP_HASH_SIZE		256

extern uint_t pkp_tab_hash(char *, int);

#ifdef __cplusplus
}
#endif

#endif /* _PKP_HASH_H_ */
