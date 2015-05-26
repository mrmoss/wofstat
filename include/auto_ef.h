/*
 * Copyright (c) 2003 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef _AUTO_EF_H
#define _AUTO_EF_H

#ident  "@(#)auto_ef.h 1.6 03/07/18 SMI"

#include <sys/types.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct auto_ef_info *auto_ef_t;

#define AE_LEVEL_0 0
#define AE_LEVEL_1 1
#define AE_LEVEL_2 2
#define AE_LEVEL_3 3

extern size_t auto_ef_file(auto_ef_t **, const char *, int);
extern size_t auto_ef_str (auto_ef_t **, const char *, size_t, int);
extern void auto_ef_free(auto_ef_t *);
extern char *auto_ef_get_encoding(auto_ef_t);
extern double auto_ef_get_score(auto_ef_t);

#ifdef __cplusplus
}
#endif

#endif /* _AUTO_EF_H */
