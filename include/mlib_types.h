/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_TYPES_H
#define	_MLIB_TYPES_H

#pragma ident	"@(#)mlib_types.h	9.1	05/11/23 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>
#if defined(_MSC_VER)
#include <float.h>	/* for FLT_MAX and DBL_MAX */
#endif

#ifndef DBL_MAX
/* max decimal value of a "double" */
#define	DBL_MAX	1.7976931348623157E+308
#endif

#ifndef FLT_MAX
/* max decimal value of a "float" */
#define	FLT_MAX	3.402823466E+38F
#endif

#ifndef FLT_MIN
/* min normalized value of a "float" */
#define	FLT_MIN	1.175494351e-38F
#endif

typedef char mlib_s8;
typedef unsigned char mlib_u8;
typedef short mlib_s16;
typedef unsigned short mlib_u16;
typedef int mlib_s32;
typedef unsigned int mlib_u32;
typedef float mlib_f32;
typedef double mlib_d64;

#if defined(__SUNPRO_C) || defined(__SUNPRO_CC) || defined(__GNUC__) || \
	defined(__ICC)

#if defined(__linux__)

#include <malloc.h>	/* for ptrdiff_t */
#include <stdint.h>	/* for uintptr_t */
typedef uintptr_t mlib_addr;

#else

#include <stddef.h>	/* for ptrdiff_t */
#if defined(_SYS_INT_TYPES_H)
typedef uintptr_t mlib_addr;
#elif defined(_LP64) || defined(_I32LPx)
typedef unsigned long mlib_addr;
#else
typedef unsigned int mlib_addr;
#endif

#endif /* !defined(__linux__) */

#ifdef _LP64

typedef long mlib_s64;
typedef unsigned long mlib_u64;

#define	MLIB_S64_MIN	LONG_MIN
#define	MLIB_S64_MAX	LONG_MAX

#define	MLIB_S64_CONST(x)	x##L
#define	MLIB_U64_CONST(x)	x##UL

#elif (__STDC__ - 0 == 0) || defined(__GNUC__) || defined(__ICC)

#if defined(_NO_LONGLONG)

typedef union
{
	mlib_d64 d64;
	mlib_s32 s32[2];
} mlib_s64;

typedef union
{
	mlib_d64 d64;
	mlib_u32 u32[2];
} mlib_u64;

#else

typedef long long mlib_s64;
typedef unsigned long long mlib_u64;

#define	MLIB_S64_MIN	LLONG_MIN
#define	MLIB_S64_MAX	LLONG_MAX

#define	MLIB_S64_CONST(x)	x##LL
#define	MLIB_U64_CONST(x)	x##ULL

#endif /* !defined(_NO_LONGLONG) */

#endif /* _LP64 */

#elif defined(_MSC_VER)

#if defined(_NO_LONGLONG)

typedef union
{
	mlib_d64 d64;
	mlib_s32 s32[2];
} mlib_s64;

typedef union
{
	mlib_d64 d64;
	mlib_u32 u32[2];
} mlib_u64;

#else

typedef __int64 mlib_s64;
typedef unsigned __int64 mlib_u64;

#define	MLIB_S64_MIN	_I64_MIN
#define	MLIB_S64_MAX	_I64_MAX

#define	MLIB_S64_CONST(x)	x##I64
#define	MLIB_U64_CONST(x)	x##UI64

#endif /* !defined(_NO_LONGLONG) */

#include <stddef.h>
#if defined(_WIN64)
typedef uintptr_t mlib_addr;
#else
typedef unsigned int mlib_addr;
#endif /* !defined(_WIN64) */

#else

#error  "unknown platform"

#endif /* defined(__SUNPRO_C) || defined(__SUNPRO_CC) ... */

typedef void *mlib_ras;

#define	MLIB_S8_MIN	SCHAR_MIN
#define	MLIB_S8_MAX	SCHAR_MAX
#define	MLIB_U8_MIN	0
#define	MLIB_U8_MAX	UCHAR_MAX
#define	MLIB_S16_MIN	SHRT_MIN
#define	MLIB_S16_MAX	SHRT_MAX
#define	MLIB_U16_MIN	0
#define	MLIB_U16_MAX	USHRT_MAX
#define	MLIB_S32_MIN	INT_MIN
#define	MLIB_S32_MAX	INT_MAX
#define	MLIB_U32_MIN	0
#define	MLIB_U32_MAX	UINT_MAX
#define	MLIB_F32_MIN	-FLT_MAX
#define	MLIB_F32_MAX	FLT_MAX
#define	MLIB_D64_MIN	-DBL_MAX
#define	MLIB_D64_MAX	DBL_MAX

#ifdef __cplusplus
}
#endif

#endif /* _MLIB_TYPES_H */
