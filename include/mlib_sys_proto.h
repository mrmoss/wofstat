/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_SYS_PROTO_H
#define	_MLIB_SYS_PROTO_H

#pragma ident	"@(#)mlib_sys_proto.h	9.1	05/11/23 SMI"

#ifdef __cplusplus
extern "C" {
#endif

void *mlib_malloc(
    size_t size);
void *mlib_realloc(
    void *ptr,
    size_t size);
void mlib_free(
    void *ptr);
void *mlib_memset(
    void *s,
    mlib_s32 c,
    size_t n);
void *mlib_memcpy(
    void *s1,
    const void *s2,
    size_t n);
void *mlib_memmove(
    void *s1,
    const void *s2,
    size_t n);

char *mlib_version();

#ifdef __SUNPRO_C
#pragma returns_new_memory(mlib_malloc, mlib_realloc)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _MLIB_SYS_PROTO_H */
