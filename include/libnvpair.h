/*
 * Copyright (c) 2000, 2010, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_LIBNVPAIR_H
#define	_LIBNVPAIR_H

#pragma ident	"@(#)libnvpair.h	1.6	10/07/14 SMI"

#include <sys/nvpair.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>

#ifdef	__cplusplus
extern "C" {
#endif

void nvlist_print(FILE *, nvlist_t *);
int nvpair_value_match(nvpair_t *, int, char *, char **);
int nvpair_value_match_regex(nvpair_t *, int, char *, regex_t *, char **);
void dump_nvlist(nvlist_t *, int);

#ifdef	__cplusplus
}
#endif

#endif	/* _LIBNVPAIR_H */
