/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_SIGNAL_PROTO_H
#define	_MLIB_SIGNAL_PROTO_H

#pragma ident	"@(#)mlib_signal_proto.h	9.1	05/11/23 SMI"

#include <mlib_types.h>
#include <mlib_status.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Up-Sampling, Down-Sampling */

mlib_status mlib_SignalUpSample_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 factor,
    mlib_s32 phase,
    mlib_s32 n);

mlib_status mlib_SignalUpSample_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 factor,
    mlib_s32 phase,
    mlib_s32 n);

mlib_status mlib_SignalUpSample_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 factor,
    mlib_s32 phase,
    mlib_s32 n);

mlib_status mlib_SignalUpSample_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 factor,
    mlib_s32 phase,
    mlib_s32 n);

mlib_status mlib_SignalDownSample_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 factor,
    mlib_s32 phase,
    mlib_s32 n);

mlib_status mlib_SignalDownSample_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 factor,
    mlib_s32 phase,
    mlib_s32 n);

mlib_status mlib_SignalDownSample_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 factor,
    mlib_s32 phase,
    mlib_s32 n);

mlib_status mlib_SignalDownSample_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 factor,
    mlib_s32 phase,
    mlib_s32 n);

/* Up-Sampling with Filtering */

mlib_status mlib_SignalUpSampleFIRInit_S16_S16(
    void **state,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_s32 factor,
    mlib_s32 phase);

mlib_status mlib_SignalUpSampleFIRInit_S16S_S16S(
    void **state,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_s32 factor,
    mlib_s32 phase);

mlib_status mlib_SignalUpSampleFIR_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalUpSampleFIR_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *state,
    mlib_s32 n);

void mlib_SignalUpSampleFIRFree_S16_S16(
    void *state);

void mlib_SignalUpSampleFIRFree_S16S_S16S(
    void *state);

mlib_status mlib_SignalUpSampleFIRInit_F32_F32(
    void **state,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_s32 factor,
    mlib_s32 phase);

mlib_status mlib_SignalUpSampleFIRInit_F32S_F32S(
    void **state,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_s32 factor,
    mlib_s32 phase);

mlib_status mlib_SignalUpSampleFIR_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalUpSampleFIR_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *state,
    mlib_s32 n);

void mlib_SignalUpSampleFIRFree_F32_F32(
    void *state);

void mlib_SignalUpSampleFIRFree_F32S_F32S(
    void *state);

/* Rational Sample Rate Conversion */

mlib_status mlib_SignalReSampleFIRInit_S16_S16(
    void **state,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_s32 ufactor,
    mlib_s32 uphase,
    mlib_s32 dfactor,
    mlib_s32 dphase);

mlib_status mlib_SignalReSampleFIRInit_S16S_S16S(
    void **state,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_s32 ufactor,
    mlib_s32 uphase,
    mlib_s32 dfactor,
    mlib_s32 dphase);

mlib_status mlib_SignalReSampleFIR_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalReSampleFIR_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *state,
    mlib_s32 n);

void mlib_SignalReSampleFIRFree_S16_S16(
    void *state);

void mlib_SignalReSampleFIRFree_S16S_S16S(
    void *state);

mlib_status mlib_SignalReSampleFIRInit_F32_F32(
    void **state,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_s32 ufactor,
    mlib_s32 uphase,
    mlib_s32 dfactor,
    mlib_s32 dphase);

mlib_status mlib_SignalReSampleFIRInit_F32S_F32S(
    void **state,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_s32 ufactor,
    mlib_s32 uphase,
    mlib_s32 dfactor,
    mlib_s32 dphase);

mlib_status mlib_SignalReSampleFIR_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalReSampleFIR_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *state,
    mlib_s32 n);

void mlib_SignalReSampleFIRFree_F32_F32(
    void *state);

void mlib_SignalReSampleFIRFree_F32S_F32S(
    void *state);

/* 16-Bit to 8-Bit  Quantization */

mlib_status mlib_SignalQuant_U8_S16(
    mlib_u8 *dst,
    const mlib_s16 *src,
    const mlib_s16 *thresh,
    mlib_s32 n);

mlib_status mlib_SignalQuant_U8S_S16S(
    mlib_u8 *dst,
    const mlib_s16 *src,
    const mlib_s16 *thresh,
    mlib_s32 n);

/* Float to 8-Bit  Quantization */

mlib_status mlib_SignalQuant_U8_F32(
    mlib_u8 *dst,
    const mlib_f32 *src,
    const mlib_f32 *thresh,
    mlib_s32 n);

mlib_status mlib_SignalQuant_U8S_F32S(
    mlib_u8 *dst,
    const mlib_f32 *src,
    const mlib_f32 *thresh,
    mlib_s32 n);

/* Float to 16-Bit  Quantization */

mlib_status mlib_SignalQuant_S16_F32(
    mlib_s16 *dst,
    const mlib_f32 *src,
    const mlib_f32 *thresh,
    mlib_s32 n);

mlib_status mlib_SignalQuant_S16S_F32S(
    mlib_s16 *dst,
    const mlib_f32 *src,
    const mlib_f32 *thresh,
    mlib_s32 n);

mlib_status mlib_SignalQuant2_S16_F32(
    mlib_s16 *dst,
    const mlib_f32 *src,
    const mlib_f32 *thresh,
    mlib_s32 length,
    mlib_s16 offset,
    mlib_s32 n);

mlib_status mlib_SignalQuant2_S16S_F32S(
    mlib_s16 *dst,
    const mlib_f32 *src,
    const mlib_f32 *thresh,
    mlib_s32 length,
    mlib_s16 offset,
    mlib_s32 n);

/* Hard Limiting */

mlib_status mlib_SignalLimit_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *low,
    const mlib_s16 *high,
    mlib_s32 n);

mlib_status mlib_SignalLimit_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *low,
    const mlib_s16 *high,
    mlib_s32 n);

mlib_status mlib_SignalLimit_S16(
    mlib_s16 *srcdst,
    const mlib_s16 *low,
    const mlib_s16 *high,
    mlib_s32 n);

mlib_status mlib_SignalLimit_S16S(
    mlib_s16 *srcdst,
    const mlib_s16 *low,
    const mlib_s16 *high,
    mlib_s32 n);

mlib_status mlib_SignalLimit_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *low,
    const mlib_f32 *high,
    mlib_s32 n);

mlib_status mlib_SignalLimit_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *low,
    const mlib_f32 *high,
    mlib_s32 n);

mlib_status mlib_SignalLimit_F32(
    mlib_f32 *srcdst,
    const mlib_f32 *low,
    const mlib_f32 *high,
    mlib_s32 n);

mlib_status mlib_SignalLimit_F32S(
    mlib_f32 *srcdst,
    const mlib_f32 *low,
    const mlib_f32 *high,
    mlib_s32 n);

/* Channel Merge and Split */

mlib_status mlib_SignalMerge_S16S_S16(
    mlib_s16 *dst,
    const mlib_s16 *ch0,
    const mlib_s16 *ch1,
    mlib_s32 n);

mlib_status mlib_SignalMerge_F32S_F32(
    mlib_f32 *dst,
    const mlib_f32 *ch0,
    const mlib_f32 *ch1,
    mlib_s32 n);

mlib_status mlib_SignalSplit_S16_S16S(
    mlib_s16 *ch0,
    mlib_s16 *ch1,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_SignalSplit_F32_F32S(
    mlib_f32 *ch0,
    mlib_f32 *ch1,
    const mlib_f32 *src,
    mlib_s32 n);

/* Data Type Convert with Shifting */

mlib_status mlib_SignalConvertShift_S8_U8_Sat(
    mlib_s8 *dst,
    const mlib_u8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S8S_U8S_Sat(
    mlib_s8 *dst,
    const mlib_u8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S16_U8_Sat(
    mlib_s16 *dst,
    const mlib_u8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S16S_U8S_Sat(
    mlib_s16 *dst,
    const mlib_u8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S32_U8_Sat(
    mlib_s32 *dst,
    const mlib_u8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S32S_U8S_Sat(
    mlib_s32 *dst,
    const mlib_u8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_F32_U8(
    mlib_f32 *dst,
    const mlib_u8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_F32S_U8S(
    mlib_f32 *dst,
    const mlib_u8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_U8_S8_Sat(
    mlib_u8 *dst,
    const mlib_s8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_U8S_S8S_Sat(
    mlib_u8 *dst,
    const mlib_s8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S16_S8_Sat(
    mlib_s16 *dst,
    const mlib_s8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S16S_S8S_Sat(
    mlib_s16 *dst,
    const mlib_s8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S32_S8_Sat(
    mlib_s32 *dst,
    const mlib_s8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S32S_S8S_Sat(
    mlib_s32 *dst,
    const mlib_s8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_F32_S8(
    mlib_f32 *dst,
    const mlib_s8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_F32S_S8S(
    mlib_f32 *dst,
    const mlib_s8 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_U8_S16_Sat(
    mlib_u8 *dst,
    const mlib_s16 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_U8S_S16S_Sat(
    mlib_u8 *dst,
    const mlib_s16 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S8_S16_Sat(
    mlib_s8 *dst,
    const mlib_s16 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S8S_S16S_Sat(
    mlib_s8 *dst,
    const mlib_s16 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S32_S16_Sat(
    mlib_s32 *dst,
    const mlib_s16 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S32S_S16S_Sat(
    mlib_s32 *dst,
    const mlib_s16 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_F32_S16(
    mlib_f32 *dst,
    const mlib_s16 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_F32S_S16S(
    mlib_f32 *dst,
    const mlib_s16 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_U8_S32_Sat(
    mlib_u8 *dst,
    const mlib_s32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_U8S_S32S_Sat(
    mlib_u8 *dst,
    const mlib_s32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S8_S32_Sat(
    mlib_s8 *dst,
    const mlib_s32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S8S_S32S_Sat(
    mlib_s8 *dst,
    const mlib_s32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S16_S32_Sat(
    mlib_s16 *dst,
    const mlib_s32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S16S_S32S_Sat(
    mlib_s16 *dst,
    const mlib_s32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_F32_S32(
    mlib_f32 *dst,
    const mlib_s32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_F32S_S32S(
    mlib_f32 *dst,
    const mlib_s32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_U8_F32_Sat(
    mlib_u8 *dst,
    const mlib_f32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_U8S_F32S_Sat(
    mlib_u8 *dst,
    const mlib_f32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S8_F32_Sat(
    mlib_s8 *dst,
    const mlib_f32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S8S_F32S_Sat(
    mlib_s8 *dst,
    const mlib_f32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S16_F32_Sat(
    mlib_s16 *dst,
    const mlib_f32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S16S_F32S_Sat(
    mlib_s16 *dst,
    const mlib_f32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S32_F32_Sat(
    mlib_s32 *dst,
    const mlib_f32 *src,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalConvertShift_S32S_F32S_Sat(
    mlib_s32 *dst,
    const mlib_f32 *src,
    mlib_s32 shift,
    mlib_s32 n);

/* Multiplication by a Scalar */

mlib_status mlib_SignalMulS_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulS_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulS_S16_Sat(
    mlib_s16 *srcdst,
    const mlib_s16 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulS_S16S_Sat(
    mlib_s16 *srcdst,
    const mlib_s16 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulS_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulS_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulS_F32(
    mlib_f32 *srcdst,
    const mlib_f32 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulS_F32S(
    mlib_f32 *srcdst,
    const mlib_f32 *c,
    mlib_s32 n);

/* Multiplication by a Scalar with Shifting */

mlib_status mlib_SignalMulSShift_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *c,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalMulSShift_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *c,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalMulSShift_S16_Sat(
    mlib_s16 *srcdst,
    const mlib_s16 *c,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalMulSShift_S16S_Sat(
    mlib_s16 *srcdst,
    const mlib_s16 *c,
    mlib_s32 shift,
    mlib_s32 n);

/* Multiplication by a Scalar plus Addition */

mlib_status mlib_SignalMulSAdd_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    const mlib_s16 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulSAdd_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    const mlib_s16 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulSAdd_S16_Sat(
    mlib_s16 *src1dst,
    const mlib_s16 *src2,
    const mlib_s16 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulSAdd_S16S_Sat(
    mlib_s16 *src1dst,
    const mlib_s16 *src2,
    const mlib_s16 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulSAdd_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src1,
    const mlib_f32 *src2,
    const mlib_f32 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulSAdd_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src1,
    const mlib_f32 *src2,
    const mlib_f32 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulSAdd_F32(
    mlib_f32 *src1dst,
    const mlib_f32 *src2,
    const mlib_f32 *c,
    mlib_s32 n);

mlib_status mlib_SignalMulSAdd_F32S(
    mlib_f32 *src1dst,
    const mlib_f32 *src2,
    const mlib_f32 *c,
    mlib_s32 n);

/* Multiplication by a Scalar with Shifting plus Addition */

mlib_status mlib_SignalMulSShiftAdd_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    const mlib_s16 *c,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalMulSShiftAdd_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    const mlib_s16 *c,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalMulSShiftAdd_S16_Sat(
    mlib_s16 *src1dst,
    const mlib_s16 *src2,
    const mlib_s16 *c,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalMulSShiftAdd_S16S_Sat(
    mlib_s16 *src1dst,
    const mlib_s16 *src2,
    const mlib_s16 *c,
    mlib_s32 shift,
    mlib_s32 n);

/* Multiplication */

mlib_status mlib_SignalMul_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    mlib_s32 n);

mlib_status mlib_SignalMul_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    mlib_s32 n);

mlib_status mlib_SignalMul_S16_Sat(
    mlib_s16 *src1dst,
    const mlib_s16 *src2,
    mlib_s32 n);

mlib_status mlib_SignalMul_S16S_Sat(
    mlib_s16 *src1dst,
    const mlib_s16 *src2,
    mlib_s32 n);

mlib_status mlib_SignalMul_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src1,
    const mlib_f32 *src2,
    mlib_s32 n);

mlib_status mlib_SignalMul_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src1,
    const mlib_f32 *src2,
    mlib_s32 n);

mlib_status mlib_SignalMul_F32(
    mlib_f32 *src1dst,
    const mlib_f32 *src2,
    mlib_s32 n);

mlib_status mlib_SignalMul_F32S(
    mlib_f32 *src1dst,
    const mlib_f32 *src2,
    mlib_s32 n);

/* Multiplication with Shifting */

mlib_status mlib_SignalMulShift_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalMulShift_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalMulShift_S16_Sat(
    mlib_s16 *src1dst,
    const mlib_s16 *src2,
    mlib_s32 shift,
    mlib_s32 n);

mlib_status mlib_SignalMulShift_S16S_Sat(
    mlib_s16 *src1dst,
    const mlib_s16 *src2,
    mlib_s32 shift,
    mlib_s32 n);

/* Convolution */

mlib_status mlib_SignalConv_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalConv_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalConv_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src1,
    const mlib_f32 *src2,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalConv_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src1,
    const mlib_f32 *src2,
    mlib_s32 m,
    mlib_s32 n);

/* Auto-Correlation */

mlib_status mlib_SignalAutoCorrel_S16(
    mlib_d64 *correl,
    const mlib_s16 *src,
    mlib_s32 disp,
    mlib_s32 n);

mlib_status mlib_SignalAutoCorrel_S16S(
    mlib_d64 *correl,
    const mlib_s16 *src,
    mlib_s32 disp,
    mlib_s32 n);

mlib_status mlib_SignalAutoCorrel_F32(
    mlib_d64 *correl,
    const mlib_f32 *src,
    mlib_s32 disp,
    mlib_s32 n);

mlib_status mlib_SignalAutoCorrel_F32S(
    mlib_d64 *correl,
    const mlib_f32 *src,
    mlib_s32 disp,
    mlib_s32 n);

/* Cross Correlation */

mlib_status mlib_SignalCrossCorrel_S16(
    mlib_d64 *correl,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    mlib_s32 n);

mlib_status mlib_SignalCrossCorrel_S16S(
    mlib_d64 *correl,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    mlib_s32 n);

mlib_status mlib_SignalCrossCorrel_F32(
    mlib_d64 *correl,
    const mlib_f32 *src1,
    const mlib_f32 *src2,
    mlib_s32 n);

mlib_status mlib_SignalCrossCorrel_F32S(
    mlib_d64 *correl,
    const mlib_f32 *src1,
    const mlib_f32 *src2,
    mlib_s32 n);

/* Sine Wave Generation */

mlib_status mlib_SignalSineWaveInit_S16(
    void **state,
    mlib_s16 mag,
    mlib_f32 freq,
    mlib_f32 phase);

mlib_status mlib_SignalSineWave_S16(
    mlib_s16 *sine,
    void *state,
    mlib_s32 n);

void mlib_SignalSineWaveFree_S16(
    void *state);

mlib_status mlib_SignalSineWaveInit_F32(
    void **state,
    mlib_f32 mag,
    mlib_f32 freq,
    mlib_f32 phase);

mlib_status mlib_SignalSineWave_F32(
    mlib_f32 *sine,
    void *state,
    mlib_s32 n);

void mlib_SignalSineWaveFree_F32(
    void *state);

/* White Noise Generator */

mlib_status mlib_SignalWhiteNoiseInit_S16(
    void **state,
    mlib_s16 mag,
    mlib_s16 seed);

mlib_status mlib_SignalWhiteNoise_S16(
    mlib_s16 *wnoise,
    void *state,
    mlib_s32 n);

void mlib_SignalWhiteNoiseFree_S16(
    void *state);

mlib_status mlib_SignalWhiteNoiseInit_F32(
    void **state,
    mlib_f32 mag,
    mlib_f32 seed);

mlib_status mlib_SignalWhiteNoise_F32(
    mlib_f32 *wnoise,
    void *state,
    mlib_s32 n);

void mlib_SignalWhiteNoiseFree_F32(
    void *state);

/* Gaussian Noise Generator */

mlib_status mlib_SignalGaussNoiseInit_S16(
    void **state,
    mlib_s16 mag,
    mlib_f32 mean,
    mlib_f32 stddev,
    mlib_s16 seed);

mlib_status mlib_SignalGaussNoise_S16(
    mlib_s16 *gnoise,
    void *state,
    mlib_s32 n);

void mlib_SignalGaussNoiseFree_S16(
    void *state);

mlib_status mlib_SignalGaussNoiseInit_F32(
    void **state,
    mlib_f32 mag,
    mlib_f32 mean,
    mlib_f32 stddev,
    mlib_f32 seed);

mlib_status mlib_SignalGaussNoise_F32(
    mlib_f32 *gnoise,
    void *state,
    mlib_s32 n);

void mlib_SignalGaussNoiseFree_F32(
    void *state);

/* Window Generation */

mlib_status mlib_SignalGenBartlett_S16(
    mlib_s16 *window,
    mlib_s32 n);

mlib_status mlib_SignalGenBartlett_F32(
    mlib_f32 *window,
    mlib_s32 n);

mlib_status mlib_SignalGenHanning_S16(
    mlib_s16 *window,
    mlib_s32 n);

mlib_status mlib_SignalGenHanning_F32(
    mlib_f32 *window,
    mlib_s32 n);

mlib_status mlib_SignalGenHamming_S16(
    mlib_s16 *window,
    mlib_s32 n);

mlib_status mlib_SignalGenHamming_F32(
    mlib_f32 *window,
    mlib_s32 n);

mlib_status mlib_SignalGenBlackman_S16(
    mlib_s16 *window,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalGenBlackman_F32(
    mlib_f32 *window,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalGenKaiser_S16(
    mlib_s16 *window,
    mlib_f32 beta,
    mlib_s32 n);

mlib_status mlib_SignalGenKaiser_F32(
    mlib_f32 *window,
    mlib_f32 beta,
    mlib_s32 n);

/* Windowing */

mlib_status mlib_SignalMulRectangular_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalMulRectangular_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalMulRectangular_S16(
    mlib_s16 *srcdst,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalMulRectangular_S16S(
    mlib_s16 *srcdst,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalMulRectangular_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalMulRectangular_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalMulRectangular_F32(
    mlib_f32 *srcdst,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalMulRectangular_F32S(
    mlib_f32 *srcdst,
    mlib_s32 m,
    mlib_s32 n);

mlib_status mlib_SignalMulBartlett_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulBartlett_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulBartlett_S16(
    mlib_s16 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulBartlett_S16S(
    mlib_s16 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulBartlett_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulBartlett_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulBartlett_F32(
    mlib_f32 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulBartlett_F32S(
    mlib_f32 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulHanning_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulHanning_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulHanning_S16(
    mlib_s16 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulHanning_S16S(
    mlib_s16 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulHanning_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulHanning_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulHanning_F32(
    mlib_f32 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulHanning_F32S(
    mlib_f32 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulHamming_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulHamming_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulHamming_S16(
    mlib_s16 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulHamming_S16S(
    mlib_s16 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulHamming_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulHamming_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_s32 n);

mlib_status mlib_SignalMulHamming_F32(
    mlib_f32 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulHamming_F32S(
    mlib_f32 *srcdst,
    mlib_s32 n);

mlib_status mlib_SignalMulBlackman_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalMulBlackman_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalMulBlackman_S16(
    mlib_s16 *srcdst,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalMulBlackman_S16S(
    mlib_s16 *srcdst,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalMulBlackman_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalMulBlackman_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalMulBlackman_F32(
    mlib_f32 *srcdst,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalMulBlackman_F32S(
    mlib_f32 *srcdst,
    mlib_f32 alpha,
    mlib_s32 n);

mlib_status mlib_SignalMulKaiser_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_f32 beta,
    mlib_s32 n);

mlib_status mlib_SignalMulKaiser_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_f32 beta,
    mlib_s32 n);

mlib_status mlib_SignalMulKaiser_S16(
    mlib_s16 *srcdst,
    mlib_f32 beta,
    mlib_s32 n);

mlib_status mlib_SignalMulKaiser_S16S(
    mlib_s16 *srcdst,
    mlib_f32 beta,
    mlib_s32 n);

mlib_status mlib_SignalMulKaiser_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_f32 beta,
    mlib_s32 n);

mlib_status mlib_SignalMulKaiser_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    mlib_f32 beta,
    mlib_s32 n);

mlib_status mlib_SignalMulKaiser_F32(
    mlib_f32 *srcdst,
    mlib_f32 beta,
    mlib_s32 n);

mlib_status mlib_SignalMulKaiser_F32S(
    mlib_f32 *srcdst,
    mlib_f32 beta,
    mlib_s32 n);

mlib_status mlib_SignalMulWindow_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *window,
    mlib_s32 n);

mlib_status mlib_SignalMulWindow_S16S_S16S(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *window,
    mlib_s32 n);

mlib_status mlib_SignalMulWindow_S16(
    mlib_s16 *srcdst,
    const mlib_s16 *window,
    mlib_s32 n);

mlib_status mlib_SignalMulWindow_S16S(
    mlib_s16 *srcdst,
    const mlib_s16 *window,
    mlib_s32 n);

mlib_status mlib_SignalMulWindow_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *window,
    mlib_s32 n);

mlib_status mlib_SignalMulWindow_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *window,
    mlib_s32 n);

mlib_status mlib_SignalMulWindow_F32(
    mlib_f32 *srcdst,
    const mlib_f32 *window,
    mlib_s32 n);

mlib_status mlib_SignalMulWindow_F32S(
    mlib_f32 *srcdst,
    const mlib_f32 *window,
    mlib_s32 n);

/* Finite Impose Response (FIR) Filtering */

mlib_status mlib_SignalFIRInit_S16_S16(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap);

mlib_status mlib_SignalFIRInit_S16S_S16S(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap);

mlib_status mlib_SignalFIR_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalFIR_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *filter,
    mlib_s32 n);

void mlib_SignalFIRFree_S16_S16(
    void *filter);

void mlib_SignalFIRFree_S16S_S16S(
    void *filter);

mlib_status mlib_SignalFIRInit_F32_F32(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap);

mlib_status mlib_SignalFIRInit_F32S_F32S(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap);

mlib_status mlib_SignalFIR_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalFIR_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *filter,
    mlib_s32 n);

void mlib_SignalFIRFree_F32_F32(
    void *filter);

void mlib_SignalFIRFree_F32S_F32S(
    void *filter);

/* Infinite Impose Response (IIR) Filtering */

mlib_status mlib_SignalIIRInit_Biquad_S16_S16(
    void **filter,
    const mlib_f32 *flt);

mlib_status mlib_SignalIIRInit_Biquad_S16S_S16S(
    void **filter,
    const mlib_f32 *flt);

mlib_status mlib_SignalIIR_Biquad_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalIIR_Biquad_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *filter,
    mlib_s32 n);

void mlib_SignalIIRFree_Biquad_S16_S16(
    void *filter);

void mlib_SignalIIRFree_Biquad_S16S_S16S(
    void *filter);

mlib_status mlib_SignalIIRInit_Biquad_F32_F32(
    void **filter,
    const mlib_f32 *flt);

mlib_status mlib_SignalIIRInit_Biquad_F32S_F32S(
    void **filter,
    const mlib_f32 *flt);

mlib_status mlib_SignalIIR_Biquad_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalIIR_Biquad_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *filter,
    mlib_s32 n);

void mlib_SignalIIRFree_Biquad_F32_F32(
    void *filter);

void mlib_SignalIIRFree_Biquad_F32S_F32S(
    void *filter);

mlib_status mlib_SignalIIRInit_P4_S16_S16(
    void **filter,
    const mlib_f32 *flt);

mlib_status mlib_SignalIIRInit_P4_S16S_S16S(
    void **filter,
    const mlib_f32 *flt);

mlib_status mlib_SignalIIR_P4_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalIIR_P4_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *filter,
    mlib_s32 n);

void mlib_SignalIIRFree_P4_S16_S16(
    void *filter);

void mlib_SignalIIRFree_P4_S16S_S16S(
    void *filter);

mlib_status mlib_SignalIIRInit_P4_F32_F32(
    void **filter,
    const mlib_f32 *flt);

mlib_status mlib_SignalIIRInit_P4_F32S_F32S(
    void **filter,
    const mlib_f32 *flt);

mlib_status mlib_SignalIIR_P4_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalIIR_P4_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *filter,
    mlib_s32 n);

void mlib_SignalIIRFree_P4_F32_F32(
    void *filter);

void mlib_SignalIIRFree_P4_F32S_F32S(
    void *filter);

/* Least Mean Square (LMS) Adaptive Filtering */

mlib_status mlib_SignalLMSFilterInit_S16_S16(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_f32 beta);

mlib_status mlib_SignalLMSFilterInit_S16S_S16S(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_f32 beta);

mlib_status mlib_SignalLMSFilter_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalLMSFilter_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalLMSFilterNonAdapt_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalLMSFilterNonAdapt_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *ref,
    void *filter,
    mlib_s32 n);

void mlib_SignalLMSFilterFree_S16_S16(
    void *filter);

void mlib_SignalLMSFilterFree_S16S_S16S(
    void *filter);

mlib_status mlib_SignalLMSFilterInit_F32_F32(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_f32 beta);

mlib_status mlib_SignalLMSFilterInit_F32S_F32S(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_f32 beta);

mlib_status mlib_SignalLMSFilter_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalLMSFilter_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalLMSFilterNonAdapt_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalLMSFilterNonAdapt_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *ref,
    void *filter,
    mlib_s32 n);

void mlib_SignalLMSFilterFree_F32_F32(
    void *filter);

void mlib_SignalLMSFilterFree_F32S_F32S(
    void *filter);

mlib_status mlib_SignalNLMSFilterInit_S16_S16(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_f32 beta);

mlib_status mlib_SignalNLMSFilterInit_S16S_S16S(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_f32 beta);

mlib_status mlib_SignalNLMSFilter_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalNLMSFilter_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalNLMSFilterNonAdapt_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalNLMSFilterNonAdapt_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    const mlib_s16 *ref,
    void *filter,
    mlib_s32 n);

void mlib_SignalNLMSFilterFree_S16_S16(
    void *filter);

void mlib_SignalNLMSFilterFree_S16S_S16S(
    void *filter);

mlib_status mlib_SignalNLMSFilterInit_F32_F32(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_f32 beta);

mlib_status mlib_SignalNLMSFilterInit_F32S_F32S(
    void **filter,
    const mlib_f32 *flt,
    mlib_s32 tap,
    mlib_f32 beta);

mlib_status mlib_SignalNLMSFilter_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalNLMSFilter_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalNLMSFilterNonAdapt_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *ref,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalNLMSFilterNonAdapt_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    const mlib_f32 *ref,
    void *filter,
    mlib_s32 n);

void mlib_SignalNLMSFilterFree_F32_F32(
    void *filter);

void mlib_SignalNLMSFilterFree_F32S_F32S(
    void *filter);

/* Pre-Emphasizing */

mlib_status mlib_SignalEmphasizeInit_S16_S16(
    void **filter,
    mlib_f32 alpha);

mlib_status mlib_SignalEmphasizeInit_S16S_S16S(
    void **filter,
    mlib_f32 alpha);

mlib_status mlib_SignalEmphasize_S16_S16_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalEmphasize_S16S_S16S_Sat(
    mlib_s16 *dst,
    const mlib_s16 *src,
    void *filter,
    mlib_s32 n);

void mlib_SignalEmphasizeFree_S16_S16(
    void *filter);

void mlib_SignalEmphasizeFree_S16S_S16S(
    void *filter);

mlib_status mlib_SignalEmphasizeInit_F32_F32(
    void **filter,
    mlib_f32 alpha);

mlib_status mlib_SignalEmphasizeInit_F32S_F32S(
    void **filter,
    mlib_f32 alpha);

mlib_status mlib_SignalEmphasize_F32_F32(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *filter,
    mlib_s32 n);

mlib_status mlib_SignalEmphasize_F32S_F32S(
    mlib_f32 *dst,
    const mlib_f32 *src,
    void *filter,
    mlib_s32 n);

void mlib_SignalEmphasizeFree_F32_F32(
    void *filter);

void mlib_SignalEmphasizeFree_F32S_F32S(
    void *filter);

/* Fast Fourier Transform 1 (FFT) */

mlib_status mlib_SignalFFT_1_S16C_S16C_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_S16_S16_Mod(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_S16C_S16_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcr,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_S16C_S16C(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_S16_S16(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_S16_S16C(
    mlib_s16 *dstr,
    const mlib_s16 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_S16C_Mod(
    mlib_s16 *datac,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_S16_Mod(
    mlib_s16 *datar,
    mlib_s16 *datai,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_S16C(
    mlib_s16 *datac,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_S16(
    mlib_s16 *datar,
    mlib_s16 *datai,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_F32C_F32(
    mlib_f32 *dstc,
    const mlib_f32 *srcr,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_F32_F32C(
    mlib_f32 *dstr,
    const mlib_f32 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_F32C(
    mlib_f32 *datac,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_F32C(
    mlib_f32 *datac,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_D64C_D64C(
    mlib_d64 *dstc,
    const mlib_d64 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_D64_D64(
    mlib_d64 *dstr,
    mlib_d64 *dsti,
    const mlib_d64 *srcr,
    const mlib_d64 *srci,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_D64C_D64(
    mlib_d64 *dstc,
    const mlib_d64 *srcr,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_D64C_D64C(
    mlib_d64 *dstc,
    const mlib_d64 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_D64_D64(
    mlib_d64 *dstr,
    mlib_d64 *dsti,
    const mlib_d64 *srcr,
    const mlib_d64 *srci,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_D64_D64C(
    mlib_d64 *dstr,
    const mlib_d64 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_D64C(
    mlib_d64 *datac,
    mlib_s32 order);

mlib_status mlib_SignalFFT_1_D64(
    mlib_d64 *datar,
    mlib_d64 *datai,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_D64C(
    mlib_d64 *datac,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_1_D64(
    mlib_d64 *datar,
    mlib_d64 *datai,
    mlib_s32 order);

/* FFT 1 with Windowing */

mlib_status mlib_SignalFFTW_1_S16C_S16C_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_1_S16_S16_Mod(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_1_S16C_S16_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcr,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_S16C_S16C(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_S16_S16(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_S16_S16C(
    mlib_s16 *dstr,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_1_S16C_Mod(
    mlib_s16 *datac,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_1_S16_Mod(
    mlib_s16 *datar,
    mlib_s16 *datai,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_S16C(
    mlib_s16 *datac,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_S16(
    mlib_s16 *datar,
    mlib_s16 *datai,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_1_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_1_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_1_F32C_F32(
    mlib_f32 *dstc,
    const mlib_f32 *srcr,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_F32_F32C(
    mlib_f32 *dstr,
    const mlib_f32 *srcc,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_1_F32C(
    mlib_f32 *datac,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_1_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_F32C(
    mlib_f32 *datac,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_1_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    const mlib_f32 *window,
    mlib_s32 order);

/* Fast Fourier Transform 2 (FFT) */

mlib_status mlib_SignalFFT_2_S16C_S16C(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_S16_S16(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_S16C_S16(
    mlib_s16 *dstc,
    const mlib_s16 *srcr,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_S16C_S16C_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_S16_S16_Mod(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_S16_S16C_Mod(
    mlib_s16 *dstr,
    const mlib_s16 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_S16C(
    mlib_s16 *datac,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_S16(
    mlib_s16 *datar,
    mlib_s16 *datai,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_S16C_Mod(
    mlib_s16 *datac,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_S16_Mod(
    mlib_s16 *datar,
    mlib_s16 *datai,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_F32C_F32(
    mlib_f32 *dstc,
    const mlib_f32 *srcr,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_F32_F32C(
    mlib_f32 *dstr,
    const mlib_f32 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_F32C(
    mlib_f32 *datac,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_F32C(
    mlib_f32 *datac,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_D64C_D64C(
    mlib_d64 *dstc,
    const mlib_d64 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_D64_D64(
    mlib_d64 *dstr,
    mlib_d64 *dsti,
    const mlib_d64 *srcr,
    const mlib_d64 *srci,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_D64C_D64(
    mlib_d64 *dstc,
    const mlib_d64 *srcr,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_D64C_D64C(
    mlib_d64 *dstc,
    const mlib_d64 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_D64_D64(
    mlib_d64 *dstr,
    mlib_d64 *dsti,
    const mlib_d64 *srcr,
    const mlib_d64 *srci,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_D64_D64C(
    mlib_d64 *dstr,
    const mlib_d64 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_D64C(
    mlib_d64 *datac,
    mlib_s32 order);

mlib_status mlib_SignalFFT_2_D64(
    mlib_d64 *datar,
    mlib_d64 *datai,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_D64C(
    mlib_d64 *datac,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_2_D64(
    mlib_d64 *datar,
    mlib_d64 *datai,
    mlib_s32 order);

/* FFT 2 with Windowing */

mlib_status mlib_SignalFFTW_2_S16C_S16C(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_2_S16_S16(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_2_S16C_S16(
    mlib_s16 *dstc,
    const mlib_s16 *srcr,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_S16C_S16C_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_S16_S16_Mod(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_S16_S16C_Mod(
    mlib_s16 *dstr,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_2_S16C(
    mlib_s16 *datac,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_2_S16(
    mlib_s16 *datar,
    mlib_s16 *datai,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_S16C_Mod(
    mlib_s16 *datac,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_S16_Mod(
    mlib_s16 *datar,
    mlib_s16 *datai,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_2_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_2_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_2_F32C_F32(
    mlib_f32 *dstc,
    const mlib_f32 *srcr,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_F32_F32C(
    mlib_f32 *dstr,
    const mlib_f32 *srcc,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_2_F32C(
    mlib_f32 *datac,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_2_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_F32C(
    mlib_f32 *datac,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_2_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    const mlib_f32 *window,
    mlib_s32 order);

/* Fast Fourier Transform 3 (FFT) */

mlib_status mlib_SignalFFT_3_S16C_S16C_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_S16_S16_Mod(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_S16C_S16_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcr,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_S16C_S16C_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_S16_S16_Mod(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_S16_S16C_Mod(
    mlib_s16 *dstr,
    const mlib_s16 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_S16C_Mod(
    mlib_s16 *datac,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_S16_Mod(
    mlib_s16 *datar,
    mlib_s16 *datai,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_S16C_Mod(
    mlib_s16 *datac,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_S16_Mod(
    mlib_s16 *datar,
    mlib_s16 *datai,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_F32C_F32(
    mlib_f32 *dstc,
    const mlib_f32 *srcr,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_F32_F32C(
    mlib_f32 *dstr,
    const mlib_f32 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_F32C(
    mlib_f32 *datac,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_F32C(
    mlib_f32 *datac,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_D64C_D64C(
    mlib_d64 *dstc,
    const mlib_d64 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_D64_D64(
    mlib_d64 *dstr,
    mlib_d64 *dsti,
    const mlib_d64 *srcr,
    const mlib_d64 *srci,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_D64C_D64(
    mlib_d64 *dstc,
    const mlib_d64 *srcr,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_D64C_D64C(
    mlib_d64 *dstc,
    const mlib_d64 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_D64_D64(
    mlib_d64 *dstr,
    mlib_d64 *dsti,
    const mlib_d64 *srcr,
    const mlib_d64 *srci,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_D64_D64C(
    mlib_d64 *dstr,
    const mlib_d64 *srcc,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_D64C(
    mlib_d64 *datac,
    mlib_s32 order);

mlib_status mlib_SignalFFT_3_D64(
    mlib_d64 *datar,
    mlib_d64 *datai,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_D64C(
    mlib_d64 *datac,
    mlib_s32 order);

mlib_status mlib_SignalIFFT_3_D64(
    mlib_d64 *datar,
    mlib_d64 *datai,
    mlib_s32 order);

/* FFT 3 with Windowing */

mlib_status mlib_SignalFFTW_3_S16C_S16C_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_3_S16_S16_Mod(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_3_S16C_S16_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcr,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_S16C_S16C_Mod(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_S16_S16_Mod(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_S16_S16C_Mod(
    mlib_s16 *dstr,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_3_S16C_Mod(
    mlib_s16 *datac,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_3_S16_Mod(
    mlib_s16 *datar,
    mlib_s16 *datai,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_S16C_Mod(
    mlib_s16 *datac,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_S16_Mod(
    mlib_s16 *datar,
    mlib_s16 *datai,
    const mlib_s16 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_3_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_3_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_3_F32C_F32(
    mlib_f32 *dstc,
    const mlib_f32 *srcr,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_F32C_F32C(
    mlib_f32 *dstc,
    const mlib_f32 *srcc,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_F32_F32(
    mlib_f32 *dstr,
    mlib_f32 *dsti,
    const mlib_f32 *srcr,
    const mlib_f32 *srci,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_F32_F32C(
    mlib_f32 *dstr,
    const mlib_f32 *srcc,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_3_F32C(
    mlib_f32 *datac,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalFFTW_3_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_F32C(
    mlib_f32 *datac,
    const mlib_f32 *window,
    mlib_s32 order);

mlib_status mlib_SignalIFFTW_3_F32(
    mlib_f32 *datar,
    mlib_f32 *datai,
    const mlib_f32 *window,
    mlib_s32 order);

/* Fast Fourier Transform 4 (FFT) */

mlib_status mlib_SignalFFT_4_S16C_S16C(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalFFT_4_S16_S16(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalFFT_4_S16C_S16(
    mlib_s16 *dstc,
    const mlib_s16 *srcr,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFT_4_S16C_S16C(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFT_4_S16_S16(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFT_4_S16_S16C(
    mlib_s16 *dstr,
    const mlib_s16 *srcc,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalFFT_4_S16C(
    mlib_s16 *datac,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalFFT_4_S16(
    mlib_s16 *datar,
    mlib_s16 *datai,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFT_4_S16C(
    mlib_s16 *datac,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFT_4_S16(
    mlib_s16 *datar,
    mlib_s16 *datai,
    mlib_s32 order,
    mlib_s32 *scale);

/* FFT 4 with Windowing */

mlib_status mlib_SignalFFTW_4_S16C_S16C(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalFFTW_4_S16_S16(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalFFTW_4_S16C_S16(
    mlib_s16 *dstc,
    const mlib_s16 *srcr,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFTW_4_S16C_S16C(
    mlib_s16 *dstc,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFTW_4_S16_S16(
    mlib_s16 *dstr,
    mlib_s16 *dsti,
    const mlib_s16 *srcr,
    const mlib_s16 *srci,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFTW_4_S16_S16C(
    mlib_s16 *dstr,
    const mlib_s16 *srcc,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalFFTW_4_S16C(
    mlib_s16 *datac,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalFFTW_4_S16(
    mlib_s16 *datar,
    mlib_s16 *datai,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFTW_4_S16C(
    mlib_s16 *datac,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

mlib_status mlib_SignalIFFTW_4_S16(
    mlib_s16 *datar,
    mlib_s16 *datai,
    const mlib_s16 *window,
    mlib_s32 order,
    mlib_s32 *scale);

/* ITU G.711 mu-law and A-law Companding */

mlib_status mlib_SignaluLaw2Linear(
    mlib_s16 *pcm,
    const mlib_u8 *ucode,
    mlib_s32 n);

mlib_status mlib_SignalLinear2uLaw(
    mlib_u8 *ucode,
    const mlib_s16 *pcm,
    mlib_s32 n);

mlib_status mlib_SignalALaw2Linear(
    mlib_s16 *pcm,
    const mlib_u8 *acode,
    mlib_s32 n);

mlib_status mlib_SignalLinear2ALaw(
    mlib_u8 *acode,
    const mlib_s16 *pcm,
    mlib_s32 n);

mlib_status mlib_SignaluLaw2ALaw(
    mlib_u8 *acode,
    const mlib_u8 *ucode,
    mlib_s32 n);

mlib_status mlib_SignalALaw2uLaw(
    mlib_u8 *ucode,
    const mlib_u8 *acode,
    mlib_s32 n);

/* ITU G.721/G.723 ADPCM Codec */

mlib_status mlib_SignalADPCMInit(
    void **state);

void mlib_SignalADPCMFree(
    void *state);

mlib_status mlib_SignalADPCM2Bits2Linear(
    mlib_s16 *pcm,
    const mlib_u8 *adpcm,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalLinear2ADPCM2Bits(
    mlib_u8 *adpcm,
    const mlib_s16 *pcm,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalADPCM3Bits2Linear(
    mlib_s16 *pcm,
    const mlib_u8 *adpcm,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalLinear2ADPCM3Bits(
    mlib_u8 *adpcm,
    const mlib_s16 *pcm,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalADPCM4Bits2Linear(
    mlib_s16 *pcm,
    const mlib_u8 *adpcm,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalLinear2ADPCM4Bits(
    mlib_u8 *adpcm,
    const mlib_s16 *pcm,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalADPCM5Bits2Linear(
    mlib_s16 *pcm,
    const mlib_u8 *adpcm,
    void *state,
    mlib_s32 n);

mlib_status mlib_SignalLinear2ADPCM5Bits(
    mlib_u8 *adpcm,
    const mlib_s16 *pcm,
    void *state,
    mlib_s32 n);

/* IMDCT, IMDCTSplit */

mlib_status mlib_SignalIMDCT_D64(
    mlib_d64 *data);

mlib_status mlib_SignalIMDCT_F32(
    mlib_f32 *data);

mlib_status mlib_SignalIMDCTSplit_D64(
    mlib_d64 *data);

mlib_status mlib_SignalIMDCTSplit_F32(
    mlib_f32 *data);

/* Linear Predictive Coding With Autocorrelation Method */

mlib_status mlib_SignalLPCAutoCorrelInit_S16(
    void **state,
    mlib_s32 length,
    mlib_s32 order);

mlib_status mlib_SignalLPCAutoCorrel_S16(
    mlib_s16 *coeff,
    mlib_s32 cscale,
    const mlib_s16 *signal,
    void *state);

mlib_status mlib_SignalLPCAutoCorrel_S16_Adp(
    mlib_s16 *coeff,
    mlib_s32 *cscale,
    const mlib_s16 *signal,
    void *state);

mlib_status mlib_SignalLPCAutoCorrelGetEnergy_S16(
    mlib_s16 *energy,
    mlib_s32 escale,
    void *state);

mlib_status mlib_SignalLPCAutoCorrelGetEnergy_S16_Adp(
    mlib_s16 *energy,
    mlib_s32 *escale,
    void *state);

mlib_status mlib_SignalLPCAutoCorrelGetPARCOR_S16(
    mlib_s16 *parcor,
    mlib_s32 pscale,
    void *state);

mlib_status mlib_SignalLPCAutoCorrelGetPARCOR_S16_Adp(
    mlib_s16 *parcor,
    mlib_s32 *pscale,
    void *state);

void mlib_SignalLPCAutoCorrelFree_S16(
    void *state);

mlib_status mlib_SignalLPCAutoCorrelInit_F32(
    void **state,
    mlib_s32 length,
    mlib_s32 order);

mlib_status mlib_SignalLPCAutoCorrel_F32(
    mlib_f32 *coeff,
    const mlib_f32 *signal,
    void *state);

mlib_status mlib_SignalLPCAutoCorrelGetEnergy_F32(
    mlib_f32 *energy,
    void *state);

mlib_status mlib_SignalLPCAutoCorrelGetPARCOR_F32(
    mlib_f32 *parcor,
    void *state);

void mlib_SignalLPCAutoCorrelFree_F32(
    void *state);

/* Linear Predictive Coding With Covariance Method */

mlib_status mlib_SignalLPCCovarianceInit_S16(
    void **state,
    mlib_s32 length,
    mlib_s32 order);

mlib_status mlib_SignalLPCCovariance_S16(
    mlib_s16 *coeff,
    mlib_s32 cscale,
    const mlib_s16 *signal,
    void *state);

mlib_status mlib_SignalLPCCovariance_S16_Adp(
    mlib_s16 *coeff,
    mlib_s32 *cscale,
    const mlib_s16 *signal,
    void *state);

void mlib_SignalLPCCovarianceFree_S16(
    void *state);

mlib_status mlib_SignalLPCCovarianceInit_F32(
    void **state,
    mlib_s32 length,
    mlib_s32 order);

mlib_status mlib_SignalLPCCovariance_F32(
    mlib_f32 *coeff,
    const mlib_f32 *signal,
    void *state);

void mlib_SignalLPCCovarianceFree_F32(
    void *state);

/* Convert LPC Coefficients To Cepstral Coefficients */

mlib_status mlib_SignalLPC2Cepstral_S16(
    mlib_s16 *cepst,
    mlib_s32 cscale,
    const mlib_s16 *lpc,
    mlib_s32 lscale,
    mlib_s16 gain,
    mlib_s32 gscale,
    mlib_s32 length,
    mlib_s32 order);

mlib_status mlib_SignalLPC2Cepstral_S16_Adp(
    mlib_s16 *cepst,
    mlib_s32 *cscale,
    const mlib_s16 *lpc,
    mlib_s32 lscale,
    mlib_s16 gain,
    mlib_s32 gscale,
    mlib_s32 length,
    mlib_s32 order);

mlib_status mlib_SignalLPC2Cepstral_F32(
    mlib_f32 *cepst,
    const mlib_f32 *lpc,
    mlib_f32 gain,
    mlib_s32 length,
    mlib_s32 order);

/* Convert LPC Coefficients To LSP Coefficients */

mlib_status mlib_SignalLPC2LSP_S16(
    mlib_s16 *lsp,
    const mlib_s16 *lpc,
    mlib_s32 lscale,
    mlib_s32 order);

mlib_status mlib_SignalLPC2LSP_F32(
    mlib_f32 *lsp,
    const mlib_f32 *lpc,
    mlib_s32 order);

/* Convert LSP Coefficients To LPC Coefficients */

mlib_status mlib_SignalLSP2LPC_S16(
    mlib_s16 *lpc,
    mlib_s32 lscale,
    const mlib_s16 *lsp,
    mlib_s32 order);

mlib_status mlib_SignalLSP2LPC_S16_Adp(
    mlib_s16 *lpc,
    mlib_s32 *lscale,
    const mlib_s16 *lsp,
    mlib_s32 order);

mlib_status mlib_SignalLSP2LPC_F32(
    mlib_f32 *lpc,
    const mlib_f32 *lsp,
    mlib_s32 order);

/* Perceptual Weighting */

mlib_status mlib_SignalLPCPerceptWeightInit_S16(
    void **state,
    mlib_s32 length,
    mlib_s32 order);

mlib_status mlib_SignalLPCPerceptWeight_S16(
    mlib_s16 *sigwgt,
    const mlib_s16 *signal,
    const mlib_s16 *lpc,
    mlib_s32 lscale,
    mlib_s16 r1,
    mlib_s16 r2,
    void *state);

void mlib_SignalLPCPerceptWeightFree_S16(
    void *state);

mlib_status mlib_SignalLPCPerceptWeightInit_F32(
    void **state,
    mlib_s32 length,
    mlib_s32 order);

mlib_status mlib_SignalLPCPerceptWeight_F32(
    mlib_f32 *sigwgt,
    const mlib_f32 *signal,
    const mlib_f32 *lpc,
    mlib_f32 r1,
    mlib_f32 r2,
    void *state);

void mlib_SignalLPCPerceptWeightFree_F32(
    void *state);

/* Open-Loop Pitch Analyze */

mlib_status mlib_SignalLPCPitchAnalyze_S16(
    mlib_s32 *pitch,
    const mlib_s16 *sigwgt,
    const mlib_s32 *region,
    mlib_s32 length);

mlib_status mlib_SignalLPCPitchAnalyze_F32(
    mlib_s32 *pitch,
    const mlib_f32 *sigwgt,
    const mlib_s32 *region,
    mlib_s32 length);

/* Cepstral Analysis */

mlib_status mlib_SignalCepstralInit_S16(
    void **state,
    mlib_s32 order);

mlib_status mlib_SignalCepstral_S16(
    mlib_s16 *cepst,
    mlib_s32 cscale,
    const mlib_s16 *signal,
    void *state);

mlib_status mlib_SignalCepstral_S16_Adp(
    mlib_s16 *cepst,
    mlib_s32 *cscale,
    const mlib_s16 *signal,
    void *state);

void mlib_SignalCepstralFree_S16(
    void *state);

mlib_status mlib_SignalCepstralInit_F32(
    void **state,
    mlib_s32 order);

mlib_status mlib_SignalCepstral_F32(
    mlib_f32 *cepst,
    const mlib_f32 *signal,
    void *state);

void mlib_SignalCepstralFree_F32(
    void *state);

/* Cepstral Analysis In Mel Frequency Scale */

mlib_status mlib_SignalMelCepstralInit_S16(
    void **state,
    mlib_s32 nlinear,
    mlib_s32 nmel,
    mlib_f32 melbgn,
    mlib_f32 melend,
    mlib_f32 meldiv,
    mlib_s32 order);

mlib_status mlib_SignalMelCepstral_S16(
    mlib_s16 *cepst,
    mlib_s32 cscale,
    const mlib_s16 *signal,
    void *state);

mlib_status mlib_SignalMelCepstral_S16_Adp(
    mlib_s16 *cepst,
    mlib_s32 *cscale,
    const mlib_s16 *signal,
    void *state);

void mlib_SignalMelCepstralFree_S16(
    void *state);

mlib_status mlib_SignalMelCepstralInit_F32(
    void **state,
    mlib_s32 nlinear,
    mlib_s32 nmel,
    mlib_f32 melbgn,
    mlib_f32 melend,
    mlib_f32 meldiv,
    mlib_s32 order);

mlib_status mlib_SignalMelCepstral_F32(
    mlib_f32 *cepst,
    const mlib_f32 *signal,
    void *state);

void mlib_SignalMelCepstralFree_F32(
    void *state);

/* Dynamic Time Warping Of Scalar Data */

mlib_status mlib_SignalDTWScalarInit_S16(
    void **state,
    const mlib_s16 *dref,
    mlib_s32 lref,
    mlib_s32 sref,
    mlib_s32 delta,
    mlib_s32 local,
    mlib_s32 slope);

mlib_status mlib_SignalDTWScalar_S16(
    mlib_d64 *dist,
    const mlib_s16 *dobs,
    mlib_s32 lobs,
    mlib_s32 sobs,
    void *state);

mlib_status mlib_SignalDTWScalarPath_S16(
    mlib_d64 *dist,
    mlib_s32 *path,
    mlib_s32 *lpath,
    const mlib_s16 *pdobs,
    mlib_s32 lobs,
    mlib_s32 sobs,
    void *state);

void mlib_SignalDTWScalarFree_S16(
    void *state);

mlib_status mlib_SignalDTWScalarInit_F32(
    void **state,
    const mlib_f32 *dref,
    mlib_s32 lref,
    mlib_s32 delta,
    mlib_s32 local,
    mlib_s32 slope);

mlib_status mlib_SignalDTWScalar_F32(
    mlib_d64 *dist,
    const mlib_f32 *dobs,
    mlib_s32 lobs,
    void *state);

mlib_status mlib_SignalDTWScalarPath_F32(
    mlib_d64 *dist,
    mlib_s32 *path,
    mlib_s32 *lpath,
    const mlib_f32 *pdobs,
    mlib_s32 lobs,
    void *state);

void mlib_SignalDTWScalarFree_F32(
    void *state);

/* Dynamic Time Warping Of Vector Data */

mlib_status mlib_SignalDTWVectorInit_S16(
    void **state,
    const mlib_s16 **dref,
    mlib_s32 lref,
    mlib_s32 ndata,
    mlib_s32 dtype,
    mlib_s32 sref,
    mlib_s32 delta,
    mlib_s32 local,
    mlib_s32 slope);

mlib_status mlib_SignalDTWVector_S16(
    mlib_d64 *dist,
    const mlib_s16 **dobs,
    mlib_s32 lobs,
    mlib_s32 sobs,
    void *state);

mlib_status mlib_SignalDTWVectorPath_S16(
    mlib_d64 *dist,
    mlib_s32 *path,
    mlib_s32 *lpath,
    const mlib_s16 **pdobs,
    mlib_s32 lobs,
    mlib_s32 sobs,
    void *state);

void mlib_SignalDTWVectorFree_S16(
    void *state);

mlib_status mlib_SignalDTWVectorInit_F32(
    void **state,
    const mlib_f32 **dref,
    mlib_s32 lref,
    mlib_s32 ndata,
    mlib_s32 dtype,
    mlib_s32 delta,
    mlib_s32 local,
    mlib_s32 slope);

mlib_status mlib_SignalDTWVector_F32(
    mlib_d64 *dist,
    const mlib_f32 **dobs,
    mlib_s32 lobs,
    void *state);

mlib_status mlib_SignalDTWVectorPath_F32(
    mlib_d64 *dist,
    mlib_s32 *path,
    mlib_s32 *lpath,
    const mlib_f32 **pdobs,
    mlib_s32 lobs,
    void *state);

void mlib_SignalDTWVectorFree_F32(
    void *state);

/* Dynamic Time Warping For K-best Paths Of Scalar Data */

mlib_status mlib_SignalDTWKScalarInit_S16(
    void **state,
    const mlib_s16 *dref,
    mlib_s32 lref,
    mlib_s32 kbest,
    mlib_s32 sref,
    mlib_s32 delta,
    mlib_s32 local,
    mlib_s32 slope);

mlib_status mlib_SignalDTWKScalar_S16(
    mlib_d64 *dist,
    const mlib_s16 *dobs,
    mlib_s32 lobs,
    mlib_s32 sobs,
    void *state);

mlib_status mlib_SignalDTWKScalarPath_S16(
    mlib_s32 *path,
    mlib_s32 *lpath,
    mlib_s32 kpath,
    void *state);

void mlib_SignalDTWKScalarFree_S16(
    void *state);

mlib_status mlib_SignalDTWKScalarInit_F32(
    void **state,
    const mlib_f32 *dref,
    mlib_s32 lref,
    mlib_s32 kbest,
    mlib_s32 delta,
    mlib_s32 local,
    mlib_s32 slope);

mlib_status mlib_SignalDTWKScalar_F32(
    mlib_d64 *dist,
    const mlib_f32 *dobs,
    mlib_s32 lobs,
    void *state);

mlib_status mlib_SignalDTWKScalarPath_F32(
    mlib_s32 *path,
    mlib_s32 *lpath,
    mlib_s32 kpath,
    void *state);

void mlib_SignalDTWKScalarFree_F32(
    void *state);

/* Dynamic Time Warping For K-best Paths Of Vector Data */

mlib_status mlib_SignalDTWKVectorInit_S16(
    void **state,
    const mlib_s16 **dref,
    mlib_s32 lref,
    mlib_s32 ndata,
    mlib_s32 kbest,
    mlib_s32 dtype,
    mlib_s32 sref,
    mlib_s32 delta,
    mlib_s32 local,
    mlib_s32 slope);

mlib_status mlib_SignalDTWKVector_S16(
    mlib_d64 *dist,
    const mlib_s16 **dobs,
    mlib_s32 lobs,
    mlib_s32 sobs,
    void *state);

mlib_status mlib_SignalDTWKVectorPath_S16(
    mlib_s32 *path,
    mlib_s32 *lpath,
    mlib_s32 kpath,
    void *state);

void mlib_SignalDTWKVectorFree_S16(
    void *state);

mlib_status mlib_SignalDTWKVectorInit_F32(
    void **state,
    const mlib_f32 **dref,
    mlib_s32 lref,
    mlib_s32 ndata,
    mlib_s32 kbest,
    mlib_s32 dtype,
    mlib_s32 delta,
    mlib_s32 local,
    mlib_s32 slope);

mlib_status mlib_SignalDTWKVector_F32(
    mlib_d64 *dist,
    const mlib_f32 **dobs,
    mlib_s32 lobs,
    void *state);

mlib_status mlib_SignalDTWKVectorPath_F32(
    mlib_s32 *path,
    mlib_s32 *lpath,
    mlib_s32 kpath,
    void *state);

void mlib_SignalDTWKVectorFree_F32(
    void *state);

#ifdef __cplusplus
}
#endif

#endif /* _MLIB_SIGNAL_PROTO_H */
