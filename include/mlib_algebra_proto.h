/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_ALGEBRA_PROTO_H
#define	_MLIB_ALGEBRA_PROTO_H

#pragma ident	"@(#)mlib_algebra_proto.h	9.1	05/11/23 SMI"

#include <mlib_types.h>
#include <mlib_status.h>

#ifdef __cplusplus
extern "C" {
#endif

/* addition of vectors */
mlib_status mlib_VectorAdd_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

#define	mlib_VectorAdd_S16_U8_Sat	mlib_VectorAdd_S16_U8_Mod
#define	mlib_VectorAdd_S16_S8_Sat	mlib_VectorAdd_S16_S8_Mod
#define	mlib_VectorAdd_S32_S16_Sat	mlib_VectorAdd_S32_S16_Mod

mlib_status mlib_VectorAdd_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);

/* addition of complex vectors */
mlib_status mlib_VectorAdd_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

#define	mlib_VectorAdd_S16C_U8C_Sat	mlib_VectorAdd_S16C_U8C_Mod
#define	mlib_VectorAdd_S16C_S8C_Sat	mlib_VectorAdd_S16C_S8C_Mod
#define	mlib_VectorAdd_S32C_S16C_Sat	mlib_VectorAdd_S32C_S16C_Mod

mlib_status mlib_VectorAdd_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAdd_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);

/* subtraction of vectors */
mlib_status mlib_VectorSub_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

#define	mlib_VectorSub_S16_U8_Sat	mlib_VectorSub_S16_U8_Mod
#define	mlib_VectorSub_S16_S8_Sat	mlib_VectorSub_S16_S8_Mod
#define	mlib_VectorSub_S32_S16_Sat	mlib_VectorSub_S32_S16_Mod

mlib_status mlib_VectorSub_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);

/* subtraction of complex vectors */
mlib_status mlib_VectorSub_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

#define	mlib_VectorSub_S16C_U8C_Sat	mlib_VectorSub_S16C_U8C_Mod
#define	mlib_VectorSub_S16C_S8C_Sat	mlib_VectorSub_S16C_S8C_Mod
#define	mlib_VectorSub_S32C_S16C_Sat	mlib_VectorSub_S32C_S16C_Mod

mlib_status mlib_VectorSub_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSub_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);

/* addition of vector to a scalar */
mlib_status mlib_VectorAddS_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);

#define	mlib_VectorAddS_S16_U8_Sat	mlib_VectorAddS_S16_U8_Mod
#define	mlib_VectorAddS_S16_S8_Sat	mlib_VectorAddS_S16_S8_Mod
#define	mlib_VectorAddS_S32_S16_Sat	mlib_VectorAddS_S32_S16_Mod

mlib_status mlib_VectorAddS_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);

/* addition of complex vector to a scalar */
mlib_status mlib_VectorAddS_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);

#define	mlib_VectorAddS_S16C_U8C_Sat	mlib_VectorAddS_S16C_U8C_Mod
#define	mlib_VectorAddS_S16C_S8C_Sat	mlib_VectorAddS_S16C_S8C_Mod
#define	mlib_VectorAddS_S32C_S16C_Sat	mlib_VectorAddS_S32C_S16C_Mod

mlib_status mlib_VectorAddS_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorAddS_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);

/* subtraction of vector from a scalar */
mlib_status mlib_VectorSubS_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);

#define	mlib_VectorSubS_S16_U8_Sat	mlib_VectorSubS_S16_U8_Mod
#define	mlib_VectorSubS_S16_S8_Sat	mlib_VectorSubS_S16_S8_Mod
#define	mlib_VectorSubS_S32_S16_Sat	mlib_VectorSubS_S32_S16_Mod

mlib_status mlib_VectorSubS_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);

/* subtraction of complex vector from a scalar */
mlib_status mlib_VectorSubS_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);

#define	mlib_VectorSubS_S16C_U8C_Sat	mlib_VectorSubS_S16C_U8C_Mod
#define	mlib_VectorSubS_S16C_S8C_Sat	mlib_VectorSubS_S16C_S8C_Mod
#define	mlib_VectorSubS_S32C_S16C_Sat	mlib_VectorSubS_S32C_S16C_Mod

mlib_status mlib_VectorSubS_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSubS_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);

/* multiplication of vector to a scalar */
mlib_status mlib_VectorMulS_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16_U8_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);

#define	mlib_VectorMulS_S16_S8_Sat	mlib_VectorMulS_S16_S8_Mod
#define	mlib_VectorMulS_S32_S16_Sat	mlib_VectorMulS_S32_S16_Mod

mlib_status mlib_VectorMulS_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);

/* multiplication of complex vector to a scalar */
mlib_status mlib_VectorMulS_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16C_U8C_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16C_S8C_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32C_S16C_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulS_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n);

/* multiplication of vector to a scalar with shifting */
mlib_status mlib_VectorMulSShift_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n,
    mlib_s32 shift);

/* multiplication of complex vector to a scalar with shifting */
mlib_status mlib_VectorMulSShift_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulSShift_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 n,
    mlib_s32 shift);

/* multiplication of vector to a matrix */
mlib_status mlib_VectorMulM_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16_U8_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16_S8_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S32_S16_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

/* multiplication of complex vector to a complex matrix */
mlib_status mlib_VectorMulM_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16C_U8C_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16C_S8C_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S32C_S16C_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_VectorMulM_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

/* multiplication of vector to a matrix with shifting */
mlib_status mlib_VectorMulMShift_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulMShift_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);

/* complex multiplication of vector to a matrix with shifting */
mlib_status mlib_VectorMulMShift_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulMShift_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);

/* linear function on vector */
mlib_status mlib_VectorScale_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16_U8_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 n);

#define	mlib_VectorScale_S16_S8_Sat	mlib_VectorScale_S16_S8_Mod
#define	mlib_VectorScale_S32_S16_Sat	mlib_VectorScale_S32_S16_Mod

mlib_status mlib_VectorScale_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 n);

/* linear function on complex vector */
mlib_status mlib_VectorScale_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16C_U8C_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16C_S8C_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32C_S16C_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 n);

mlib_status mlib_VectorScale_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 n);
mlib_status mlib_VectorScale_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 n);

/* multiplication of vector to a scalar plus addition */
mlib_status mlib_VectorMulSAdd_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16_U8_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    const mlib_s32 *c,
    mlib_s32 n);

#define	mlib_VectorMulSAdd_S16_S8_Sat	mlib_VectorMulSAdd_S16_S8_Mod
#define	mlib_VectorMulSAdd_S32_S16_Sat	mlib_VectorMulSAdd_S32_S16_Mod

mlib_status mlib_VectorMulSAdd_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    const mlib_s32 *c,
    mlib_s32 n);

/* multiplication of complex vector to a scalar plus addition */
mlib_status mlib_VectorMulSAdd_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16C_U8C_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16C_S8C_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32C_S16C_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    const mlib_s32 *c,
    mlib_s32 n);

mlib_status mlib_VectorMulSAdd_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    const mlib_s32 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorMulSAdd_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    const mlib_s32 *c,
    mlib_s32 n);

/* multiplication of vectors */
mlib_status mlib_VectorMul_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16_U8_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

#define	mlib_VectorMul_S16_S8_Sat	mlib_VectorMul_S16_S8_Mod
#define	mlib_VectorMul_S32_S16_Sat	mlib_VectorMul_S32_S16_Mod

mlib_status mlib_VectorMul_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);

/* multiplication of complex vectors */
mlib_status mlib_VectorMul_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16C_U8C_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16C_S8C_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32C_S16C_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

mlib_status mlib_VectorMul_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorMul_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);

/* multiplication of vectors with shifting */
mlib_status mlib_VectorMulShift_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n,
    mlib_s32 shift);

/* multiplication of complex vectors with shifting */
mlib_status mlib_VectorMulShift_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_VectorMulShift_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n,
    mlib_s32 shift);

/* dot product of vectors */
mlib_status mlib_VectorDotProd_U8_Sat(
    mlib_d64 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorDotProd_S8_Sat(
    mlib_d64 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorDotProd_S16_Sat(
    mlib_d64 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorDotProd_S32_Sat(
    mlib_d64 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

/* dot product of complex vectors */
mlib_status mlib_VectorDotProd_U8C_Sat(
    mlib_d64 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorDotProd_S8C_Sat(
    mlib_d64 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorDotProd_S16C_Sat(
    mlib_d64 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorDotProd_S32C_Sat(
    mlib_d64 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

/* vector norm */
mlib_status mlib_VectorNorm_U8_Sat(
    mlib_d64 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorNorm_S8_Sat(
    mlib_d64 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorNorm_S16_Sat(
    mlib_d64 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorNorm_S32_Sat(
    mlib_d64 *z,
    const mlib_s32 *x,
    mlib_s32 n);

/* sum of absolute values of the vector */
mlib_status mlib_VectorSumAbs_U8_Sat(
    mlib_d64 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorSumAbs_S8_Sat(
    mlib_d64 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorSumAbs_S16_Sat(
    mlib_d64 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorSumAbs_S32_Sat(
    mlib_d64 *z,
    const mlib_s32 *x,
    mlib_s32 n);

/* zeroing of vector */
mlib_status mlib_VectorZero_U8(
    mlib_u8 *z,
    mlib_s32 n);
mlib_status mlib_VectorZero_S8(
    mlib_s8 *z,
    mlib_s32 n);
mlib_status mlib_VectorZero_S16(
    mlib_s16 *z,
    mlib_s32 n);
mlib_status mlib_VectorZero_S32(
    mlib_s32 *z,
    mlib_s32 n);

/* zeroing of complex vector */
mlib_status mlib_VectorZero_U8C(
    mlib_u8 *z,
    mlib_s32 n);
mlib_status mlib_VectorZero_S8C(
    mlib_s8 *z,
    mlib_s32 n);
mlib_status mlib_VectorZero_S16C(
    mlib_s16 *z,
    mlib_s32 n);
mlib_status mlib_VectorZero_S32C(
    mlib_s32 *z,
    mlib_s32 n);

/* set of vector to a scalar */
mlib_status mlib_VectorSet_U8(
    mlib_u8 *z,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSet_S8(
    mlib_s8 *z,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSet_S16(
    mlib_s16 *z,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSet_S32(
    mlib_s32 *z,
    const mlib_s32 *c,
    mlib_s32 n);

/* set of complex vector to a scalar */
mlib_status mlib_VectorSet_U8C(
    mlib_u8 *z,
    const mlib_u8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSet_S8C(
    mlib_s8 *z,
    const mlib_s8 *c,
    mlib_s32 n);
mlib_status mlib_VectorSet_S16C(
    mlib_s16 *z,
    const mlib_s16 *c,
    mlib_s32 n);
mlib_status mlib_VectorSet_S32C(
    mlib_s32 *z,
    const mlib_s32 *c,
    mlib_s32 n);

/* copy of vector */
mlib_status mlib_VectorCopy_U8(
    mlib_u8 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorCopy_S8(
    mlib_s8 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorCopy_S16(
    mlib_s16 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorCopy_S32(
    mlib_s32 *z,
    const mlib_s32 *x,
    mlib_s32 n);

/* copy of complex vector */
mlib_status mlib_VectorCopy_U8C(
    mlib_u8 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorCopy_S8C(
    mlib_s8 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorCopy_S16C(
    mlib_s16 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorCopy_S32C(
    mlib_s32 *z,
    const mlib_s32 *x,
    mlib_s32 n);

/* expand of vector */
mlib_status mlib_VectorConvert_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S32_U8_Mod(
    mlib_s32 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S32_S8_Mod(
    mlib_s32 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    mlib_s32 n);

#define	mlib_VectorConvert_S16_U8_Sat	mlib_VectorConvert_S16_U8_Mod
#define	mlib_VectorConvert_S32_U8_Sat	mlib_VectorConvert_S32_U8_Mod
#define	mlib_VectorConvert_S16_S8_Sat	mlib_VectorConvert_S16_S8_Mod
#define	mlib_VectorConvert_S32_S8_Sat	mlib_VectorConvert_S32_S8_Mod
#define	mlib_VectorConvert_S32_S16_Sat	mlib_VectorConvert_S32_S16_Mod

/* expand of complex vector */
mlib_status mlib_VectorConvert_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S32C_U8C_Mod(
    mlib_s32 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S32C_S8C_Mod(
    mlib_s32 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    mlib_s32 n);

#define	mlib_VectorConvert_S16C_U8C_Sat	mlib_VectorConvert_S16C_U8C_Mod
#define	mlib_VectorConvert_S32C_U8C_Sat	mlib_VectorConvert_S32C_U8C_Mod
#define	mlib_VectorConvert_S16C_S8C_Sat	mlib_VectorConvert_S16C_S8C_Mod
#define	mlib_VectorConvert_S32C_S8C_Sat	mlib_VectorConvert_S32C_S8C_Mod
#define	mlib_VectorConvert_S32C_S16C_Sat	mlib_VectorConvert_S32C_S16C_Mod

/* pack of vector */
mlib_status mlib_VectorConvert_S8_U8_Sat(
    mlib_s8 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8_S8_Sat(
    mlib_u8 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8_S16_Sat(
    mlib_u8 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8_S16_Sat(
    mlib_s8 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8_S32_Sat(
    mlib_u8 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8_S32_Sat(
    mlib_s8 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S16_S32_Sat(
    mlib_s16 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8_U8_Mod(
    mlib_s8 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8_S8_Mod(
    mlib_u8 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8_S16_Mod(
    mlib_u8 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8_S16_Mod(
    mlib_s8 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8_S32_Mod(
    mlib_u8 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8_S32_Mod(
    mlib_s8 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S16_S32_Mod(
    mlib_s16 *z,
    const mlib_s32 *x,
    mlib_s32 n);

/* pack of complex vector */
mlib_status mlib_VectorConvert_S8C_U8C_Sat(
    mlib_s8 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8C_S8C_Sat(
    mlib_u8 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8C_S16C_Sat(
    mlib_u8 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8C_S16C_Sat(
    mlib_s8 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8C_S32C_Sat(
    mlib_u8 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8C_S32C_Sat(
    mlib_s8 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S16C_S32C_Sat(
    mlib_s16 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8C_U8C_Mod(
    mlib_s8 *z,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8C_S8C_Mod(
    mlib_u8 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8C_S16C_Mod(
    mlib_u8 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8C_S16C_Mod(
    mlib_s8 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_U8C_S32C_Mod(
    mlib_u8 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S8C_S32C_Mod(
    mlib_s8 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorConvert_S16C_S32C_Mod(
    mlib_s16 *z,
    const mlib_s32 *x,
    mlib_s32 n);

/* merge of the real and imaginary vectors */
mlib_status mlib_VectorMerge_U8C_U8(
    mlib_u8 *z,
    const mlib_u8 *r,
    const mlib_u8 *i,
    mlib_s32 n);
mlib_status mlib_VectorMerge_S8C_S8(
    mlib_s8 *z,
    const mlib_s8 *r,
    const mlib_s8 *i,
    mlib_s32 n);
mlib_status mlib_VectorMerge_S16C_S16(
    mlib_s16 *z,
    const mlib_s16 *r,
    const mlib_s16 *i,
    mlib_s32 n);
mlib_status mlib_VectorMerge_S32C_S32(
    mlib_s32 *z,
    const mlib_s32 *r,
    const mlib_s32 *i,
    mlib_s32 n);

/* split of complex vector */
mlib_status mlib_VectorSplit_U8_U8C(
    mlib_u8 *r,
    mlib_u8 *i,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorSplit_S8_S8C(
    mlib_s8 *r,
    mlib_s8 *i,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorSplit_S16_S16C(
    mlib_s16 *r,
    mlib_s16 *i,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorSplit_S32_S32C(
    mlib_s32 *r,
    mlib_s32 *i,
    const mlib_s32 *x,
    mlib_s32 n);

/* magnitude of complex vector */
mlib_status mlib_VectorMag_U8C(
    mlib_d64 *m,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMag_S8C(
    mlib_d64 *m,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMag_S16C(
    mlib_d64 *m,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorMag_S32C(
    mlib_d64 *m,
    const mlib_s32 *x,
    mlib_s32 n);

/* phase of complex vector */
mlib_status mlib_VectorAng_U8C(
    mlib_d64 *a,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorAng_S8C(
    mlib_d64 *a,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorAng_S16C(
    mlib_d64 *a,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorAng_S32C(
    mlib_d64 *a,
    const mlib_s32 *x,
    mlib_s32 n);

/* computation of complex conjugated vector */
mlib_status mlib_VectorConj_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConj_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConj_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    mlib_s32 n);

mlib_status mlib_VectorConj_S8C_Sat(
    mlib_s8 *xz,
    mlib_s32 n);
mlib_status mlib_VectorConj_S16C_Sat(
    mlib_s16 *xz,
    mlib_s32 n);
mlib_status mlib_VectorConj_S32C_Sat(
    mlib_s32 *xz,
    mlib_s32 n);

/*  computation of complex conjugated reverse vector */
mlib_status mlib_VectorConjRev_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConjRev_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConjRev_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    mlib_s32 n);

/* computation of complex conjugated extended vector */
mlib_status mlib_VectorConjSymExt_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorConjSymExt_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorConjSymExt_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    mlib_s32 n);

/* Euclidean distance of two vectors */
mlib_status mlib_VectorDistance_U8_Sat(
    mlib_d64 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorDistance_S8_Sat(
    mlib_d64 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorDistance_S16_Sat(
    mlib_d64 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorDistance_S32_Sat(
    mlib_d64 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

/* sum of absolute difference of two vectors */
mlib_status mlib_VectorSumAbsDiff_U8_Sat(
    mlib_d64 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSumAbsDiff_S8_Sat(
    mlib_d64 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorSumAbsDiff_S16_Sat(
    mlib_d64 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorSumAbsDiff_S32_Sat(
    mlib_d64 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);

/* change the endianness of vector */
mlib_status mlib_VectorReverseByteOrder_S16_S16(
    mlib_s16 *z,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_U16_U16(
    mlib_u16 *z,
    const mlib_u16 *x,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_S32_S32(
    mlib_s32 *z,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_U32_U32(
    mlib_u32 *z,
    const mlib_u32 *x,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_S64_S64(
    mlib_s64 *z,
    const mlib_s64 *x,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_U64_U64(
    mlib_u64 *z,
    const mlib_u64 *x,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_F32_F32(
    mlib_f32 *z,
    const mlib_f32 *x,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_D64_D64(
    mlib_d64 *z,
    const mlib_d64 *x,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_S16(
    mlib_s16 *zx,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_U16(
    mlib_u16 *zx,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_S32(
    mlib_s32 *zx,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_U32(
    mlib_u32 *zx,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_S64(
    mlib_s64 *zx,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_U64(
    mlib_u64 *zx,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_F32(
    mlib_f32 *zx,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder_D64(
    mlib_d64 *zx,
    mlib_s32 n);
mlib_status mlib_VectorReverseByteOrder(
    void *z,
    const void *x,
    mlib_s32 n,
    mlib_s32 s);
mlib_status mlib_VectorReverseByteOrder_Inp(
    void *zx,
    mlib_s32 n,
    mlib_s32 s);

/* minimum of vectors */
mlib_status mlib_VectorMinimum_U8(
    mlib_u8 *min,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimum_S8(
    mlib_s8 *min,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimum_S16(
    mlib_s16 *min,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimum_S32(
    mlib_s32 *min,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimum_F32(
    mlib_f32 *min,
    const mlib_f32 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimum_D64(
    mlib_d64 *min,
    const mlib_d64 *x,
    mlib_s32 n);

/* minimum of complex vectors */
mlib_status mlib_VectorMinimumMag_U8C(
    mlib_u8 *min,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimumMag_S8C(
    mlib_s8 *min,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimumMag_S16C(
    mlib_s16 *min,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimumMag_S32C(
    mlib_s32 *min,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimumMag_F32C(
    mlib_f32 *min,
    const mlib_f32 *x,
    mlib_s32 n);
mlib_status mlib_VectorMinimumMag_D64C(
    mlib_d64 *min,
    const mlib_d64 *x,
    mlib_s32 n);

/* maximum of vectors */
mlib_status mlib_VectorMaximum_U8(
    mlib_u8 *max,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximum_S8(
    mlib_s8 *max,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximum_S16(
    mlib_s16 *max,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximum_S32(
    mlib_s32 *max,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximum_F32(
    mlib_f32 *max,
    const mlib_f32 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximum_D64(
    mlib_d64 *max,
    const mlib_d64 *x,
    mlib_s32 n);

/* maximum of complex vectors */
mlib_status mlib_VectorMaximumMag_U8C(
    mlib_u8 *max,
    const mlib_u8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximumMag_S8C(
    mlib_s8 *max,
    const mlib_s8 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximumMag_S16C(
    mlib_s16 *max,
    const mlib_s16 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximumMag_S32C(
    mlib_s32 *max,
    const mlib_s32 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximumMag_F32C(
    mlib_f32 *max,
    const mlib_f32 *x,
    mlib_s32 n);
mlib_status mlib_VectorMaximumMag_D64C(
    mlib_d64 *max,
    const mlib_d64 *x,
    mlib_s32 n);

/* average of vectors */
mlib_status mlib_VectorAve_U8_U8(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S8_S8(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S16_U8(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S16_S8(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S16_S16(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S32_S16(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S32_S32(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_U8(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S8(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S16(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S32(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);

/* average of complex vectors */
mlib_status mlib_VectorAve_U8C_U8C(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S8C_S8C(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S16C_U8C(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S16C_S8C(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S16C_S16C(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S32C_S16C(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S32C_S32C(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_U8C(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S8C(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S16C(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 n);
mlib_status mlib_VectorAve_S32C(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 n);

/* addition of matrices */
mlib_status mlib_MatrixAdd_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixAdd_S16_U8_Sat	mlib_MatrixAdd_S16_U8_Mod
#define	mlib_MatrixAdd_S16_S8_Sat	mlib_MatrixAdd_S16_S8_Mod
#define	mlib_MatrixAdd_S32_S16_Sat	mlib_MatrixAdd_S32_S16_Mod

mlib_status mlib_MatrixAdd_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

/* addition of complex matrices */
mlib_status mlib_MatrixAdd_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixAdd_S16C_U8C_Sat	mlib_MatrixAdd_S16C_U8C_Mod
#define	mlib_MatrixAdd_S16C_S8C_Sat	mlib_MatrixAdd_S16C_S8C_Mod
#define	mlib_MatrixAdd_S32C_S16C_Sat	mlib_MatrixAdd_S32C_S16C_Mod

mlib_status mlib_MatrixAdd_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAdd_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

/* subtraction of matrices */
mlib_status mlib_MatrixSub_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixSub_S16_U8_Sat	mlib_MatrixSub_S16_U8_Mod
#define	mlib_MatrixSub_S16_S8_Sat	mlib_MatrixSub_S16_S8_Mod
#define	mlib_MatrixSub_S32_S16_Sat	mlib_MatrixSub_S32_S16_Mod

mlib_status mlib_MatrixSub_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

/* subtraction of complex matrices */
mlib_status mlib_MatrixSub_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixSub_S16C_U8C_Sat	mlib_MatrixSub_S16C_U8C_Mod
#define	mlib_MatrixSub_S16C_S8C_Sat	mlib_MatrixSub_S16C_S8C_Mod
#define	mlib_MatrixSub_S32C_S16C_Sat	mlib_MatrixSub_S32C_S16C_Mod

mlib_status mlib_MatrixSub_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSub_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

/* addition of matrix to a scalar */
mlib_status mlib_MatrixAddS_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixAddS_S16_U8_Sat	mlib_MatrixAddS_S16_U8_Mod
#define	mlib_MatrixAddS_S16_S8_Sat	mlib_MatrixAddS_S16_S8_Mod
#define	mlib_MatrixAddS_S32_S16_Sat	mlib_MatrixAddS_S32_S16_Mod

mlib_status mlib_MatrixAddS_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

/* addition of complex matrix to a scalar */
mlib_status mlib_MatrixAddS_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixAddS_S16C_U8C_Sat	mlib_MatrixAddS_S16C_U8C_Mod
#define	mlib_MatrixAddS_S16C_S8C_Sat	mlib_MatrixAddS_S16C_S8C_Mod
#define	mlib_MatrixAddS_S32C_S16C_Sat	mlib_MatrixAddS_S32C_S16C_Mod

mlib_status mlib_MatrixAddS_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAddS_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

/* subtraction of matrix from a scalar */
mlib_status mlib_MatrixSubS_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixSubS_S16_U8_Sat	mlib_MatrixSubS_S16_U8_Mod
#define	mlib_MatrixSubS_S16_S8_Sat	mlib_MatrixSubS_S16_S8_Mod
#define	mlib_MatrixSubS_S32_S16_Sat	mlib_MatrixSubS_S32_S16_Mod

mlib_status mlib_MatrixSubS_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

/* subtraction of complex matrix from a scalar */
mlib_status mlib_MatrixSubS_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixSubS_S16C_U8C_Sat	mlib_MatrixSubS_S16C_U8C_Mod
#define	mlib_MatrixSubS_S16C_S8C_Sat	mlib_MatrixSubS_S16C_S8C_Mod
#define	mlib_MatrixSubS_S32C_S16C_Sat	mlib_MatrixSubS_S32C_S16C_Mod

mlib_status mlib_MatrixSubS_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixSubS_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

/* multiplication of matrix to a scalar */
mlib_status mlib_MatrixMulS_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16_U8_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixMulS_S16_S8_Sat	mlib_MatrixMulS_S16_S8_Mod
#define	mlib_MatrixMulS_S32_S16_Sat	mlib_MatrixMulS_S32_S16_Mod

mlib_status mlib_MatrixMulS_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

/* multiplication of complex matrix to a scalar */
mlib_status mlib_MatrixMulS_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16C_U8C_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16C_S8C_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32C_S16C_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_MatrixMulS_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMulS_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n);

/* multiplication of matrix to a scalar with shifting */
mlib_status mlib_MatrixMulSShift_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);

/* multiplication of complex matrix to a scalar with shifting */
mlib_status mlib_MatrixMulSShift_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulSShift_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *c,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 shift);

/* linear function on matrix */
mlib_status mlib_MatrixScale_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16_U8_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 m,
    mlib_s32 n);

#define	mlib_MatrixScale_S16_S8_Sat	mlib_MatrixScale_S16_S8_Mod
#define	mlib_MatrixScale_S32_S16_Sat	mlib_MatrixScale_S32_S16_Mod

mlib_status mlib_MatrixScale_U8_Sat(
    mlib_u8 *xz,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S8_Sat(
    mlib_s8 *xz,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16_Sat(
    mlib_s16 *xz,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32_Sat(
    mlib_s32 *xz,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_U8_Mod(
    mlib_u8 *xz,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S8_Mod(
    mlib_s8 *xz,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16_Mod(
    mlib_s16 *xz,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32_Mod(
    mlib_s32 *xz,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 m,
    mlib_s32 n);

/* linear function on complex matrix */
mlib_status mlib_MatrixScale_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16C_U8C_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16C_S8C_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32C_S16C_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_MatrixScale_U8C_Sat(
    mlib_u8 *xz,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S8C_Sat(
    mlib_s8 *xz,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16C_Sat(
    mlib_s16 *xz,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32C_Sat(
    mlib_s32 *xz,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_U8C_Mod(
    mlib_u8 *xz,
    const mlib_u8 *a,
    const mlib_u8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S8C_Mod(
    mlib_s8 *xz,
    const mlib_s8 *a,
    const mlib_s8 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S16C_Mod(
    mlib_s16 *xz,
    const mlib_s16 *a,
    const mlib_s16 *b,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixScale_S32C_Mod(
    mlib_s32 *xz,
    const mlib_s32 *a,
    const mlib_s32 *b,
    mlib_s32 m,
    mlib_s32 n);

/* matrix transposition */
mlib_status mlib_MatrixTranspose_U8_U8(
    mlib_u8 *z,
    const mlib_u8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S8_S8(
    mlib_s8 *z,
    const mlib_s8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S16_S16(
    mlib_s16 *z,
    const mlib_s16 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S32_S32(
    mlib_s32 *z,
    const mlib_s32 *x,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_MatrixTranspose_U8(
    mlib_u8 *xz,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S8(
    mlib_s8 *xz,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S16(
    mlib_s16 *xz,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S32(
    mlib_s32 *xz,
    mlib_s32 n);

/* complex matrix transposition */
mlib_status mlib_MatrixTranspose_U8C_U8C(
    mlib_u8 *z,
    const mlib_u8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S8C_S8C(
    mlib_s8 *z,
    const mlib_s8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S16C_S16C(
    mlib_s16 *z,
    const mlib_s16 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S32C_S32C(
    mlib_s32 *z,
    const mlib_s32 *x,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_MatrixTranspose_U8C(
    mlib_u8 *xz,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S8C(
    mlib_s8 *xz,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S16C(
    mlib_s16 *xz,
    mlib_s32 n);
mlib_status mlib_MatrixTranspose_S32C(
    mlib_s32 *xz,
    mlib_s32 n);

/* unit matrix generation */
mlib_status mlib_MatrixUnit_U8(
    mlib_u8 *z,
    mlib_s32 n);
mlib_status mlib_MatrixUnit_S8(
    mlib_s8 *z,
    mlib_s32 n);
mlib_status mlib_MatrixUnit_S16(
    mlib_s16 *z,
    mlib_s32 n);
mlib_status mlib_MatrixUnit_S32(
    mlib_s32 *z,
    mlib_s32 n);

/* unit complex matrix generation */
mlib_status mlib_MatrixUnit_U8C(
    mlib_u8 *z,
    mlib_s32 n);
mlib_status mlib_MatrixUnit_S8C(
    mlib_s8 *z,
    mlib_s32 n);
mlib_status mlib_MatrixUnit_S16C(
    mlib_s16 *z,
    mlib_s32 n);
mlib_status mlib_MatrixUnit_S32C(
    mlib_s32 *z,
    mlib_s32 n);

/* matrices multiplication */
mlib_status mlib_MatrixMul_U8_U8_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16_U8_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S8_S8_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16_S8_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S32_S16_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S32_S32_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_U8_U8_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16_U8_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S8_S8_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16_S8_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S32_S16_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S32_S32_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);

/* complex matrices multiplication */
mlib_status mlib_MatrixMul_U8C_U8C_Sat(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16C_U8C_Sat(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S8C_S8C_Sat(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16C_S8C_Sat(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S32C_S16C_Sat(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S32C_S32C_Sat(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_U8C_U8C_Mod(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16C_U8C_Mod(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S8C_S8C_Mod(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16C_S8C_Mod(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S32C_S16C_Mod(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);
mlib_status mlib_MatrixMul_S32C_S32C_Mod(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n);

/* matrices multiplication with shifting */
mlib_status mlib_MatrixMulShift_S16_S16_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulShift_S16_S16_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n,
    mlib_s32 shift);

/* complex matrices multiplication with shifting */
mlib_status mlib_MatrixMulShift_S16C_S16C_Sat(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n,
    mlib_s32 shift);
mlib_status mlib_MatrixMulShift_S16C_S16C_Mod(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 l,
    mlib_s32 n,
    mlib_s32 shift);

/* minimum of matrices */
mlib_status mlib_MatrixMinimum_U8(
    mlib_u8 *min,
    const mlib_u8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimum_S8(
    mlib_s8 *min,
    const mlib_s8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimum_S16(
    mlib_s16 *min,
    const mlib_s16 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimum_S32(
    mlib_s32 *min,
    const mlib_s32 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimum_F32(
    mlib_f32 *min,
    const mlib_f32 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimum_D64(
    mlib_d64 *min,
    const mlib_d64 *x,
    mlib_s32 m,
    mlib_s32 n);

/* minimum of complex matrices */
mlib_status mlib_MatrixMinimumMag_U8C(
    mlib_u8 *min,
    const mlib_u8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimumMag_S8C(
    mlib_s8 *min,
    const mlib_s8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimumMag_S16C(
    mlib_s16 *min,
    const mlib_s16 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimumMag_S32C(
    mlib_s32 *min,
    const mlib_s32 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimumMag_F32C(
    mlib_f32 *min,
    const mlib_f32 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMinimumMag_D64C(
    mlib_d64 *min,
    const mlib_d64 *x,
    mlib_s32 m,
    mlib_s32 n);

/* maximum of matrices */
mlib_status mlib_MatrixMaximum_U8(
    mlib_u8 *max,
    const mlib_u8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximum_S8(
    mlib_s8 *max,
    const mlib_s8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximum_S16(
    mlib_s16 *max,
    const mlib_s16 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximum_S32(
    mlib_s32 *max,
    const mlib_s32 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximum_F32(
    mlib_f32 *max,
    const mlib_f32 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximum_D64(
    mlib_d64 *max,
    const mlib_d64 *x,
    mlib_s32 m,
    mlib_s32 n);

/* maximum of complex matrices */
mlib_status mlib_MatrixMaximumMag_U8C(
    mlib_u8 *max,
    const mlib_u8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximumMag_S8C(
    mlib_s8 *max,
    const mlib_s8 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximumMag_S16C(
    mlib_s16 *max,
    const mlib_s16 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximumMag_S32C(
    mlib_s32 *max,
    const mlib_s32 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximumMag_F32C(
    mlib_f32 *max,
    const mlib_f32 *x,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixMaximumMag_D64C(
    mlib_d64 *max,
    const mlib_d64 *x,
    mlib_s32 m,
    mlib_s32 n);

/* average of matrices */
mlib_status mlib_MatrixAve_U8_U8(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S8_S8(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S16_U8(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S16_S8(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S16_S16(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S32_S16(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S32_S32(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_U8(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S8(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S16(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S32(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

/* average of complex matrices */
mlib_status mlib_MatrixAve_U8C_U8C(
    mlib_u8 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S8C_S8C(
    mlib_s8 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S16C_U8C(
    mlib_s16 *z,
    const mlib_u8 *x,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S16C_S8C(
    mlib_s16 *z,
    const mlib_s8 *x,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S16C_S16C(
    mlib_s16 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S32C_S16C(
    mlib_s32 *z,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S32C_S32C(
    mlib_s32 *z,
    const mlib_s32 *x,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_U8C(
    mlib_u8 *xz,
    const mlib_u8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S8C(
    mlib_s8 *xz,
    const mlib_s8 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S16C(
    mlib_s16 *xz,
    const mlib_s16 *y,
    mlib_s32 m,
    mlib_s32 n);
mlib_status mlib_MatrixAve_S32C(
    mlib_s32 *xz,
    const mlib_s32 *y,
    mlib_s32 m,
    mlib_s32 n);

#ifdef __cplusplus
}
#endif

#endif /* _MLIB_ALGEBRA_PROTO_H */
