/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_VIDEO_PROTO_H
#define	_MLIB_VIDEO_PROTO_H

#pragma ident	"@(#)mlib_video_proto.h	9.10	06/05/27 SMI"

#include <mlib_types.h>
#include <mlib_status.h>
#include <mlib_image_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward and Inverse Discrete Cosine Transform */

mlib_status mlib_VideoDCT8x8_S16_U8(
    mlib_s16 coeffs[64],
    const mlib_u8 *block,
    mlib_s32 stride);

mlib_status mlib_VideoDCT8x8Quantize_S16_U8(
    mlib_s16 coeffs[64],
    const mlib_u8 *block,
    const mlib_d64 dqtable[64],
    mlib_s32 stride);

mlib_status mlib_VideoDCT8x8Quantize_S16_S16_B12(
    mlib_s16 coeffs[64],
    const mlib_s16 *block,
    const mlib_d64 dqtable[64]);

mlib_status mlib_VideoDCT8x8_S16_S16_B10(
    mlib_s16 coeffs[64],
    const mlib_s16 *block);

mlib_status mlib_VideoDCT8x8_S16_S16_B12(
    mlib_s16 coeffs[64],
    const mlib_s16 *block);

mlib_status mlib_VideoIDCT8x8_U8_S16(
    mlib_u8 *block,
    const mlib_s16 *coeffs,
    mlib_s32 stride);

mlib_status mlib_VideoDeQuantizeIDCT8x8_U8_S16(
    mlib_u8 *block,
    const mlib_s16 *coeffs,
    const mlib_d64 *dqtable,
    mlib_s32 stride);

mlib_status mlib_VideoIDCT8x8_S16_S16_B12(
    mlib_s16 *block,
    const mlib_s16 *coeffs);

mlib_status mlib_VideoDeQuantizeIDCT8x8_S16_S16_B12(
    mlib_s16 *block,
    const mlib_s16 *coeffs,
    const mlib_d64 *dqtable);

mlib_status mlib_VideoIDCT8x8_U8_S16_Q1(
    mlib_u8 *block,
    const mlib_s16 *coeffs,
    mlib_s32 stride);

mlib_status mlib_VideoIDCT8x8_S16_S16_Q1(
    mlib_s16 *block,
    const mlib_s16 *coeffs);

mlib_status mlib_VideoIDCT8x8_S16_S16_Q1_Mismatch(
    mlib_s16 *block,
    const mlib_s16 *coeffs);

mlib_status mlib_VideoIDCT8x8_U8_S16_DC(
    mlib_u8 *block,
    const mlib_s16 *coeffs,
    mlib_s32 stride);

mlib_status mlib_VideoIDCT8x8_S16_S16_DC(
    mlib_s16 *block,
    const mlib_s16 *coeffs);

mlib_status mlib_VideoDCT8x8_S16_U8_NA(
    mlib_s16 coeffs[64],
    const mlib_u8 *block,
    mlib_s32 stride);

mlib_status mlib_VideoDCT8x8Quantize_S16_U8_NA(
    mlib_s16 coeffs[64],
    const mlib_u8 *block,
    const mlib_d64 dqtable[64],
    mlib_s32 stride);

mlib_status mlib_VideoDCT8x8Quantize_S16_S16_B12_NA(
    mlib_s16 coeffs[64],
    const mlib_s16 *block,
    const mlib_d64 dqtable[64]);

mlib_status mlib_VideoDCT8x8_S16_S16_B10_NA(
    mlib_s16 coeffs[64],
    const mlib_s16 *block);

mlib_status mlib_VideoIDCT8x8_U8_S16_NA(
    mlib_u8 *block,
    const mlib_s16 *coeffs,
    mlib_s32 stride);

mlib_status mlib_VideoDeQuantizeIDCT8x8_U8_S16_NA(
    mlib_u8 *block,
    const mlib_s16 *coeffs,
    const mlib_d64 *dqtable,
    mlib_s32 stride);

mlib_status mlib_VideoIDCT8x8_S16_S16_B12_NA(
    mlib_s16 *block,
    const mlib_s16 *coeffs);

mlib_status mlib_VideoDeQuantizeIDCT8x8_S16_S16_B12_NA(
    mlib_s16 *block,
    const mlib_s16 *coeffs,
    const mlib_d64 *dqtable);

mlib_status mlib_VideoIDCT_IEEE_S16_S16(
    mlib_s16 *block,
    const mlib_s16 *coeffs);

mlib_status mlib_VideoDCT2x2_S16_S16(
    mlib_s16 *coeffs,
    const mlib_s16 *block);

mlib_status mlib_VideoDCT4x4_S16_S16(
    mlib_s16 *coeffs,
    const mlib_s16 *block);

mlib_status mlib_VideoDCT16x16_S16_S16(
    mlib_s16 *coeffs,
    const mlib_s16 *block);

mlib_status mlib_VideoDCT16x16_S16_S16_B10(
    mlib_s16 *coeffs,
    const mlib_s16 *block);

/*  aliases for compatibility */
#define	mlib_VideoDCT_S16_U8		mlib_VideoDCT8x8_S16_U8
#define	mlib_VideoDCT_S16_S16		mlib_VideoDCT8x8_S16_S16_B10
#define	mlib_VideoDCT8x8_S16_S16	mlib_VideoDCT8x8_S16_S16_B10
#define	mlib_VideoIDCT_U8_S16		mlib_VideoIDCT8x8_U8_S16
#define	mlib_VideoIDCT_S16_S16		mlib_VideoIDCT8x8_S16_S16_B12
#define	mlib_VideoIDCT8x8_S16_S16	mlib_VideoIDCT8x8_S16_S16_B12
#define	mlib_VideoDCT_S16_U8_NA		mlib_VideoDCT8x8_S16_U8_NA
#define	mlib_VideoDCT_S16_S16_NA	mlib_VideoDCT8x8_S16_S16_B10_NA
#define	mlib_VideoDCT8x8_S16_S16_NA	mlib_VideoDCT8x8_S16_S16_B10_NA
#define	mlib_VideoIDCT_U8_S16_NA	mlib_VideoIDCT8x8_U8_S16_NA
#define	mlib_VideoIDCT_S16_S16_NA	mlib_VideoIDCT8x8_S16_S16_B12_NA
#define	mlib_VideoIDCT8x8_S16_S16_NA	mlib_VideoIDCT8x8_S16_S16_B12_NA

/*  Motion Estimation */

mlib_s32 mlib_VideoSumAbsDiff(
    mlib_u8 *block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 stride);

/*  Motion Compensation */

mlib_status mlib_VideoInterpX_S16_U8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_S16_U8_16x16(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_S16_U8_16x8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_S16_U8_8x16(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_S16_U8_8x8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_S16_U8_8x4(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_U8_U8_16x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_U8_U8_16x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_U8_U8_8x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_U8_U8_8x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_U8_U8_8x4(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_S16_U8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_S16_U8_16x16(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_S16_U8_16x8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_S16_U8_8x16(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_S16_U8_8x8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_S16_U8_8x4(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_U8_U8_16x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_U8_U8_16x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_U8_U8_8x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_U8_U8_8x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpY_U8_U8_8x4(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_S16_U8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_S16_U8_16x16(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_S16_U8_16x8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_S16_U8_8x16(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_S16_U8_8x8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_S16_U8_8x4(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_U8_U8_16x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_U8_U8_16x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_U8_U8_8x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_U8_U8_8x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpXY_U8_U8_8x4(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpX_Y_XY_U8_U8(
    mlib_u8 *outputX,
    mlib_u8 *outputY,
    mlib_u8 *outputXY,
    const mlib_u8 *image,
    mlib_s32 stride,
    mlib_s32 width,
    mlib_s32 height);

mlib_status mlib_VideoCopyRef_S16_U8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_S16_U8_16x16(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_S16_U8_16x8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_S16_U8_8x16(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_S16_U8_8x8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_S16_U8_8x4(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_U8_U8_16x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_U8_U8_16x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_U8_U8_8x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_U8_U8_8x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRef_U8_U8_8x4(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRefAve_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRefAve_U8_U8_16x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRefAve_U8_U8_16x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRefAve_U8_U8_8x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRefAve_U8_U8_8x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoCopyRefAve_U8_U8_8x4(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoInterpAveXY_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveXY_U8_U8_16x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveXY_U8_U8_16x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveXY_U8_U8_8x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveXY_U8_U8_8x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveXY_U8_U8_8x4(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveX_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveX_U8_U8_16x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveX_U8_U8_16x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveX_U8_U8_8x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveX_U8_U8_8x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveX_U8_U8_8x4(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveY_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveY_U8_U8_16x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveY_U8_U8_16x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveY_U8_U8_8x16(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveY_U8_U8_8x8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoInterpAveY_U8_U8_8x4(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 frame_stride,
    mlib_s32 field_stride);

mlib_status mlib_VideoAddBlock_U8_S16(
    mlib_u8 *curr_block,
    const mlib_s16 *mc_block,
    mlib_s32 stride);

mlib_status mlib_VideoP64Loop_S16_U8(
    mlib_s16 *mc_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoP64Loop_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 stride);

mlib_status mlib_VideoH263OverlappedMC_S16_U8(
    mlib_s16 mc_block[64],
    const mlib_u8 *ref_block,
    mlib_s32 mch,
    mlib_s32 mcv,
    mlib_s32 mah,
    mlib_s32 mav,
    mlib_s32 mbh,
    mlib_s32 mbv,
    mlib_s32 mlh,
    mlib_s32 mlv,
    mlib_s32 mrh,
    mlib_s32 mrv,
    mlib_s32 ref_stride);

mlib_status mlib_VideoH263OverlappedMC_U8_U8(
    mlib_u8 *curr_block,
    const mlib_u8 *ref_block,
    mlib_s32 mch,
    mlib_s32 mcv,
    mlib_s32 mah,
    mlib_s32 mav,
    mlib_s32 mbh,
    mlib_s32 mbv,
    mlib_s32 mlh,
    mlib_s32 mlv,
    mlib_s32 mrh,
    mlib_s32 mrv,
    mlib_s32 curr_stride,
    mlib_s32 ref_stride);

mlib_status mlib_VideoP64Decimate_U8_U8(
    mlib_u8 *dst,
    const mlib_u8 *src,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

/* Quantize and Dequantize */

mlib_status mlib_VideoQuantizeInit_S16(
    mlib_d64 dqtable[64],
    const mlib_s16 iqtable[64]);

mlib_status mlib_VideoQuantize_S16(
    mlib_s16 icoeffs[64],
    const mlib_d64 dqtable[64]);

mlib_status mlib_VideoDeQuantizeInit_S16(
    mlib_d64 dqtable[64],
    const mlib_s16 iqtable[64]);

mlib_status mlib_VideoDeQuantize_S16(
    mlib_s16 icoeffs[64],
    const mlib_d64 dqtable[64]);

/* Color Conversion */

mlib_status mlib_VideoColorYUV2ABGR420(
    mlib_u8 *abgr,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 abgr_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2ABGR422(
    mlib_u8 *abgr,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 abgr_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2ABGR444(
    mlib_u8 *abgr,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 abgr_stride,
    mlib_s32 yuv_stride);

mlib_status mlib_VideoColorYUV2ARGB420(
    mlib_u8 *argb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 argb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2ARGB422(
    mlib_u8 *argb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 argb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2ARGB444(
    mlib_u8 *argb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 argb_stride,
    mlib_s32 yuv_stride);

mlib_status mlib_VideoColorYUV2RGB420(
    mlib_u8 *rgb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 rgb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2RGB422(
    mlib_u8 *rgb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 rgb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2RGB444(
    mlib_u8 *rgb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 rgb_stride,
    mlib_s32 yuv_stride);

mlib_status mlib_VideoColorYUV2ABGR411(
    mlib_u8 *abgr,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 abgr_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2ARGB411(
    mlib_u8 *argb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 argb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2RGB411(
    mlib_u8 *rgb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 rgb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

/* Up/Down Sampling for JPEG File Interchange Format */

mlib_status mlib_VideoUpSample422_Nearest(
    mlib_u8 *dst,
    const mlib_u8 *src,
    mlib_s32 n);

mlib_status mlib_VideoUpSample422_Nearest_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_VideoUpSample420_Nearest(
    mlib_u8 *dst0,
    mlib_u8 *dst1,
    const mlib_u8 *src,
    mlib_s32 n);

mlib_status mlib_VideoUpSample420_Nearest_S16(
    mlib_s16 *dst0,
    mlib_s16 *dst1,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_VideoUpSample422(
    mlib_u8 *dst,
    const mlib_u8 *src,
    mlib_s32 n);

mlib_status mlib_VideoUpSample422_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_VideoUpSample420(
    mlib_u8 *dst0,
    mlib_u8 *dst1,
    const mlib_u8 *src0,
    const mlib_u8 *src1,
    const mlib_u8 *src2,
    mlib_s32 n);

mlib_status mlib_VideoUpSample420_S16(
    mlib_s16 *dst0,
    mlib_s16 *dst1,
    const mlib_s16 *src0,
    const mlib_s16 *src1,
    const mlib_s16 *src2,
    mlib_s32 n);

mlib_status mlib_VideoDownSample422(
    mlib_u8 *dst,
    const mlib_u8 *src,
    mlib_s32 n);

mlib_status mlib_VideoDownSample422_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_VideoDownSample420(
    mlib_u8 *dst,
    const mlib_u8 *src0,
    const mlib_u8 *src1,
    mlib_s32 n);

mlib_status mlib_VideoDownSample420_S16(
    mlib_s16 *dst,
    const mlib_s16 *src0,
    const mlib_s16 *src1,
    mlib_s32 n);

/* Split and Merge multicomponent color row  */

mlib_status mlib_VideoColorSplit2(
    mlib_u8 *color1,
    mlib_u8 *color2,
    const mlib_u8 *colors,
    mlib_s32 n);

mlib_status mlib_VideoColorSplit2_S16(
    mlib_s16 *color1,
    mlib_s16 *color2,
    const mlib_s16 *colors,
    mlib_s32 n);

mlib_status mlib_VideoColorMerge2(
    mlib_u8 *colors,
    const mlib_u8 *color1,
    const mlib_u8 *color2,
    mlib_s32 n);

mlib_status mlib_VideoColorMerge2_S16(
    mlib_s16 *colors,
    const mlib_s16 *color1,
    const mlib_s16 *color2,
    mlib_s32 n);

mlib_status mlib_VideoColorSplit3(
    mlib_u8 *color1,
    mlib_u8 *color2,
    mlib_u8 *color3,
    const mlib_u8 *colors,
    mlib_s32 n);

mlib_status mlib_VideoColorSplit3_S16(
    mlib_s16 *color1,
    mlib_s16 *color2,
    mlib_s16 *color3,
    const mlib_s16 *colors,
    mlib_s32 n);

mlib_status mlib_VideoColorMerge3(
    mlib_u8 *colors,
    const mlib_u8 *color1,
    const mlib_u8 *color2,
    const mlib_u8 *color3,
    mlib_s32 n);

mlib_status mlib_VideoColorMerge3_S16(
    mlib_s16 *colors,
    const mlib_s16 *color1,
    const mlib_s16 *color2,
    const mlib_s16 *color3,
    mlib_s32 n);

mlib_status mlib_VideoColorSplit4(
    mlib_u8 *color1,
    mlib_u8 *color2,
    mlib_u8 *color3,
    mlib_u8 *color4,
    const mlib_u8 *colors,
    mlib_s32 n);

mlib_status mlib_VideoColorSplit4_S16(
    mlib_s16 *color1,
    mlib_s16 *color2,
    mlib_s16 *color3,
    mlib_s16 *color4,
    const mlib_s16 *colors,
    mlib_s32 n);

mlib_status mlib_VideoColorMerge4(
    mlib_u8 *colors,
    const mlib_u8 *color1,
    const mlib_u8 *color2,
    const mlib_u8 *color3,
    const mlib_u8 *color4,
    mlib_s32 n);

mlib_status mlib_VideoColorMerge4_S16(
    mlib_s16 *colors,
    const mlib_s16 *color1,
    const mlib_s16 *color2,
    const mlib_s16 *color3,
    const mlib_s16 *color4,
    mlib_s32 n);

/* Color Conversion for JPEG File Interchange Format */

mlib_status mlib_VideoColorJFIFYCC2RGB444(
    mlib_u8 *rgb,
    const mlib_u8 *y,
    const mlib_u8 *cb,
    const mlib_u8 *cr,
    mlib_s32 n);

mlib_status mlib_VideoColorJFIFYCC2RGB444_S16(
    mlib_s16 *rgb,
    const mlib_s16 *y,
    const mlib_s16 *cb,
    const mlib_s16 *cr,
    mlib_s32 n);

mlib_status mlib_VideoColorBGR2JFIFYCC444(
    mlib_u8 *y,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *bgr,
    mlib_s32 n);

mlib_status mlib_VideoColorBGR2JFIFYCC444_S16(
    mlib_s16 *y,
    mlib_s16 *cb,
    mlib_s16 *cr,
    const mlib_s16 *bgr,
    mlib_s32 n);

mlib_status mlib_VideoColorRGB2JFIFYCC444(
    mlib_u8 *y,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *rgb,
    mlib_s32 n);

mlib_status mlib_VideoColorRGB2JFIFYCC444_S16(
    mlib_s16 *y,
    mlib_s16 *cb,
    mlib_s16 *cr,
    const mlib_s16 *rgb,
    mlib_s32 n);

mlib_status mlib_VideoColorJFIFYCC2ARGB444(
    mlib_u8 *argb,
    const mlib_u8 *y,
    const mlib_u8 *cb,
    const mlib_u8 *cr,
    mlib_s32 n);

mlib_status mlib_VideoColorARGB2JFIFYCC444(
    mlib_u8 *y,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *argb,
    mlib_s32 n);

mlib_status mlib_VideoColorJFIFYCC2ABGR444(
    mlib_u8 *abgr,
    const mlib_u8 *y,
    const mlib_u8 *cb,
    const mlib_u8 *cr,
    mlib_s32 n);

mlib_status mlib_VideoColorABGR2JFIFYCC444(
    mlib_u8 *y,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *abgr,
    mlib_s32 n);

mlib_status mlib_VideoColorJFIFYCCK2CMYK444(
    mlib_u8 *cmyk,
    const mlib_u8 *y,
    const mlib_u8 *cb,
    const mlib_u8 *cr,
    const mlib_u8 *k,
    mlib_s32 n);

mlib_status mlib_VideoColorCMYK2JFIFYCCK444(
    mlib_u8 *y,
    mlib_u8 *cb,
    mlib_u8 *cr,
    mlib_u8 *k,
    const mlib_u8 *cmyk,
    mlib_s32 n);

mlib_status mlib_VideoColorARGB2JFIFYCC422(
    mlib_u8 *y,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *argb,
    mlib_s32 n);

mlib_status mlib_VideoColorABGR2JFIFYCC422(
    mlib_u8 *y,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *abgr,
    mlib_s32 n);

mlib_status mlib_VideoColorARGB2JFIFYCC420(
    mlib_u8 *y0,
    mlib_u8 *y1,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *argb0,
    const mlib_u8 *argb1,
    mlib_s32 n);

mlib_status mlib_VideoColorABGR2JFIFYCC420(
    mlib_u8 *y0,
    mlib_u8 *y1,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *abgr0,
    const mlib_u8 *abgr1,
    mlib_s32 n);

mlib_status mlib_VideoColorARGB2RGB(
    mlib_u8 *rgb,
    const mlib_u8 *argb,
    mlib_s32 n);

mlib_status mlib_VideoColorABGR2RGB(
    mlib_u8 *rgb,
    const mlib_u8 *abgr,
    mlib_s32 n);

mlib_status mlib_VideoColorRGB2ARGB(
    mlib_u8 *argb,
    const mlib_u8 *rgb,
    mlib_s32 n);

mlib_status mlib_VideoColorRGB2ABGR(
    mlib_u8 *abgr,
    const mlib_u8 *rgb,
    mlib_s32 n);

/* Color Conversion and Up/Down Sampling for JPEG File Interchange Format */

mlib_status mlib_VideoColorJFIFYCC2RGB422_Nearest(
    mlib_u8 *rgb,
    const mlib_u8 *y,
    const mlib_u8 *cb,
    const mlib_u8 *cr,
    mlib_s32 n);

mlib_status mlib_VideoColorJFIFYCC2RGB420_Nearest(
    mlib_u8 *rgb0,
    mlib_u8 *rgb1,
    const mlib_u8 *y0,
    const mlib_u8 *y1,
    const mlib_u8 *cb,
    const mlib_u8 *cr,
    mlib_s32 n);

mlib_status mlib_VideoColorJFIFYCC2RGB422(
    mlib_u8 *rgb,
    const mlib_u8 *y,
    const mlib_u8 *cb,
    const mlib_u8 *cr,
    mlib_s32 n);

mlib_status mlib_VideoColorJFIFYCC2RGB420(
    mlib_u8 *rgb0,
    mlib_u8 *rgb1,
    const mlib_u8 *y0,
    const mlib_u8 *y1,
    const mlib_u8 *cb0,
    const mlib_u8 *cr0,
    const mlib_u8 *cb1,
    const mlib_u8 *cr1,
    const mlib_u8 *cb2,
    const mlib_u8 *cr2,
    mlib_s32 n);

mlib_status mlib_VideoColorRGB2JFIFYCC422(
    mlib_u8 *y,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *rgb,
    mlib_s32 n);

mlib_status mlib_VideoColorRGB2JFIFYCC420(
    mlib_u8 *y0,
    mlib_u8 *y1,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *rgb0,
    const mlib_u8 *rgb1,
    mlib_s32 n);

mlib_status mlib_VideoColorBGR2JFIFYCC420(
    mlib_u8 *y0,
    mlib_u8 *y1,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *bgr0,
    const mlib_u8 *bgr1,
    mlib_s32 n);

mlib_status mlib_VideoColorBGR2JFIFYCC422(
    mlib_u8 *y,
    mlib_u8 *cb,
    mlib_u8 *cr,
    const mlib_u8 *bgr,
    mlib_s32 n);

/*  RGB -> YUV */

mlib_status mlib_VideoReversibleColorRGB2YUV_U8_U8(
    mlib_u8 *y,
    mlib_u8 *u,
    mlib_u8 *v,
    const mlib_u8 *r,
    const mlib_u8 *g,
    const mlib_u8 *b,
    mlib_s32 n,
    mlib_s32 depth);

mlib_status mlib_VideoReversibleColorRGB2YUV_S16_U8(
    mlib_s16 *y,
    mlib_s16 *u,
    mlib_s16 *v,
    const mlib_u8 *r,
    const mlib_u8 *g,
    const mlib_u8 *b,
    mlib_s32 n,
    mlib_s32 depth);

mlib_status mlib_VideoReversibleColorRGB2YUV_S16_S16(
    mlib_s16 *y,
    mlib_s16 *u,
    mlib_s16 *v,
    const mlib_s16 *r,
    const mlib_s16 *g,
    const mlib_s16 *b,
    mlib_s32 n,
    mlib_s32 depth);

mlib_status mlib_VideoReversibleColorRGB2YUV_S32_S16(
    mlib_s32 *y,
    mlib_s32 *u,
    mlib_s32 *v,
    const mlib_s16 *r,
    const mlib_s16 *g,
    const mlib_s16 *b,
    mlib_s32 n,
    mlib_s32 depth);

/*  RGB -> YUV */

mlib_status mlib_VideoReversibleColorYUV2RGB_U8_U8(
    mlib_u8 *r,
    mlib_u8 *g,
    mlib_u8 *b,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 n,
    mlib_s32 depth);

mlib_status mlib_VideoReversibleColorYUV2RGB_U8_S16(
    mlib_u8 *r,
    mlib_u8 *g,
    mlib_u8 *b,
    const mlib_s16 *y,
    const mlib_s16 *u,
    const mlib_s16 *v,
    mlib_s32 n,
    mlib_s32 depth);

mlib_status mlib_VideoReversibleColorYUV2RGB_S16_S16(
    mlib_s16 *r,
    mlib_s16 *g,
    mlib_s16 *b,
    const mlib_s16 *y,
    const mlib_s16 *u,
    const mlib_s16 *v,
    mlib_s32 n,
    mlib_s32 depth);

mlib_status mlib_VideoReversibleColorYUV2RGB_S16_S32(
    mlib_s16 *r,
    mlib_s16 *g,
    mlib_s16 *b,
    const mlib_s32 *y,
    const mlib_s32 *u,
    const mlib_s32 *v,
    mlib_s32 n,
    mlib_s32 depth);

/* Two-Ten Transform */

mlib_status mlib_VideoWaveletForwardTwoTenTrans_S16_U8(
    mlib_s16 *dst,
    const mlib_u8 *src,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 *level);

mlib_status mlib_VideoWaveletForwardTwoTenTrans_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 *level);

mlib_status mlib_VideoWaveletForwardTwoTenTrans_S32_S16(
    mlib_s32 *dst,
    const mlib_s16 *src,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 *level);

mlib_status mlib_VideoWaveletForwardTwoTenTrans_S32_S32(
    mlib_s32 *dst,
    const mlib_s32 *src,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 *level);

mlib_status mlib_VideoWaveletInverseTwoTenTrans_U8_S16(
    mlib_u8 *dst,
    const mlib_s16 *src,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 *level);

mlib_status mlib_VideoWaveletInverseTwoTenTrans_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 *level);

mlib_status mlib_VideoWaveletInverseTwoTenTrans_S16_S32(
    mlib_s16 *dst,
    const mlib_s32 *src,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 *level);

mlib_status mlib_VideoWaveletInverseTwoTenTrans_S32_S32(
    mlib_s32 *dst,
    const mlib_s32 *src,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 *level);

/*
 * Conversion from standard 2's Complement signed integer representation
 * to Sign Magnitude representation and back.
 */

mlib_status mlib_VideoSignMagnitudeConvert_S16_S16(
    mlib_s16 *dst,
    const mlib_s16 *src,
    mlib_s32 n);

mlib_status mlib_VideoSignMagnitudeConvert_S32_S32(
    mlib_s32 *dst,
    const mlib_s32 *src,
    mlib_s32 n);

mlib_status mlib_VideoSignMagnitudeConvert_S16(
    mlib_s16 *srcdst,
    mlib_s32 n);

mlib_status mlib_VideoSignMagnitudeConvert_S32(
    mlib_s32 *srcdst,
    mlib_s32 n);

/* Color Conversion YUV420 to ABGR with zooming and/or to window */

mlib_status mlib_VideoColorYUV2ABGR420_W(
    mlib_u8 *abgr,
    const mlib_u8 *y_inp,
    const mlib_u8 *u_inp,
    const mlib_u8 *v_inp,
    mlib_s32 wd,
    mlib_s32 ht,
    mlib_s32 rgb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride,
    mlib_s32 left,
    mlib_s32 top,
    mlib_s32 right,
    mlib_s32 bottom);

mlib_status mlib_VideoColorYUV2ABGR420_X2(
    mlib_u8 *abgr,
    const mlib_u8 *y_inp,
    const mlib_u8 *u_inp,
    const mlib_u8 *v_inp,
    mlib_s32 wd,
    mlib_s32 ht,
    mlib_s32 rgb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2ABGR420_WX2(
    mlib_u8 *abgr,
    const mlib_u8 *y_inp,
    const mlib_u8 *u_inp,
    const mlib_u8 *v_inp,
    mlib_s32 wd,
    mlib_s32 ht,
    mlib_s32 rgb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride,
    mlib_s32 left,
    mlib_s32 top,
    mlib_s32 right,
    mlib_s32 bottom);

mlib_status mlib_VideoColorYUV2ABGR420_X3(
    mlib_u8 *abgr,
    const mlib_u8 *y_inp,
    const mlib_u8 *u_inp,
    const mlib_u8 *v_inp,
    mlib_s32 wd,
    mlib_s32 ht,
    mlib_s32 rgb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

mlib_status mlib_VideoColorYUV2ABGR420_WX3(
    mlib_u8 *abgr,
    const mlib_u8 *y_inp,
    const mlib_u8 *u_inp,
    const mlib_u8 *v_inp,
    mlib_s32 wd,
    mlib_s32 ht,
    mlib_s32 rgb_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride,
    mlib_s32 left,
    mlib_s32 top,
    mlib_s32 right,
    mlib_s32 bottom);

/* YUV band-combine functions */

void mlib_VideoColorYUV420seq_to_YUYV422int(
    mlib_u32 *yuyv,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV411seq_to_YUYV422int(
    mlib_u32 *yuyv,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV422seq_to_YUYV422int(
    mlib_u32 *yuyv,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV420seq_to_UYVY422int(
    mlib_u32 *uyvy,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV411seq_to_UYVY422int(
    mlib_u32 *uyvy,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV422seq_to_UYVY422int(
    mlib_u32 *uyvy,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 y_stride,
    mlib_s32 uv_stride);

/* RGB band-combine functions */

void mlib_VideoColorRGBseq_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u8 *r,
    const mlib_u8 *g,
    const mlib_u8 *b,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorRGBint_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u8 *rgb,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorRGBint_to_BGRAint(
    mlib_u8 *bgra,
    const mlib_u8 *rgb,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorBGRint_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u8 *bgr,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

#define	mlib_VideoColorRGBint_to_ARGBint	mlib_VideoColorBGRint_to_ABGRint
#define	mlib_VideoColorBGRint_to_ARGBint	mlib_VideoColorRGBint_to_ABGRint
#define	mlib_VideoColorBGRint_to_RGBAint	mlib_VideoColorRGBint_to_BGRAint

void mlib_VideoColorRGBXint_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u32 *rgbx,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorRGBXint_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u32 *rgbx,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

#define	mlib_VideoColorBGRXint_to_ABGRint                 \
			mlib_VideoColorRGBXint_to_ARGBint
#define	mlib_VideoColorBGRXint_to_ARGBint                 \
			mlib_VideoColorRGBXint_to_ABGRint

void mlib_VideoColorXRGBint_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u32 *xrgb,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorXRGBint_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u32 *xrgb,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

#define	mlib_VideoColorXBGRint_to_ABGRint                 \
			mlib_VideoColorXRGBint_to_ARGBint
#define	mlib_VideoColorXBGRint_to_ARGBint                 \
			mlib_VideoColorXRGBint_to_ABGRint

/* YUV subsampling functions */

void mlib_VideoColorYUV444seq_to_YUYV422int(
    mlib_u32 *yuyv,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorYUV444int_to_YUYV422int(
    mlib_u32 *yuyv,
    const mlib_u8 *yuv,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorYUV444seq_to_UYVY422int(
    mlib_u32 *uyvy,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorYUV444int_to_UYVY422int(
    mlib_u32 *uyvy,
    const mlib_u8 *yuv,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorUYV444int_to_YUYV422int(
    mlib_u32 *yuyv,
    const mlib_u8 *uyv,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorUYV444int_to_UYVY422int(
    mlib_u32 *uyvy,
    const mlib_u8 *uyv,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

/* Band-shuffling functions */

void mlib_VideoColorABGRint_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u32 *abgr,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorRGBAint_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u32 *rgba,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorBGRAint_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u32 *bgra,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

#define	mlib_VideoColorBGRAint_to_ARGBint                 \
			mlib_VideoColorRGBAint_to_ABGRint
#define	mlib_VideoColorRGBAint_to_ARGBint                 \
			mlib_VideoColorBGRAint_to_ABGRint

/* Color-convert functions */

void mlib_VideoColorYUV420seq_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 ya_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV411seq_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 ya_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV422seq_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 ya_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV444seq_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorYUV420seq_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 ya_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV411seq_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 ya_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV422seq_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 ya_stride,
    mlib_s32 uv_stride);

void mlib_VideoColorYUV444seq_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u8 *y,
    const mlib_u8 *u,
    const mlib_u8 *v,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride);

void mlib_VideoColorYUYV422int_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u32 *yuyv,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorYUV444int_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u8 *yuv,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorYUYV422int_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u32 *yuyv,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorYUV444int_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u8 *yuv,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorUYVY422int_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u32 *uyvy,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorUYVY422int_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u32 *uyvy,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorUYV444int_to_ARGBint(
    mlib_u32 *argb,
    const mlib_u8 *uyv,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

void mlib_VideoColorUYV444int_to_ABGRint(
    mlib_u32 *abgr,
    const mlib_u8 *uyv,
    const mlib_u8 *a,
    mlib_u8 alpha,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 dst_stride,
    mlib_s32 src_stride,
    mlib_s32 a_stride);

/* Resizing functions */

void mlib_VideoColorResizeABGR(
    mlib_u32 *dst,
    const mlib_u32 *src,
    mlib_s32 dst_width,
    mlib_s32 dst_height,
    mlib_s32 dst_stride,
    mlib_s32 src_width,
    mlib_s32 src_height,
    mlib_s32 src_stride,
    mlib_filter filter);

/* Alpha-blending functions */

void mlib_VideoColorBlendABGR(
    mlib_u32 *dst,
    const mlib_u32 *src1,
    const mlib_u32 *src2,
    mlib_s32 src1_width,
    mlib_s32 src1_height,
    mlib_s32 src2_width,
    mlib_s32 src2_height,
    mlib_s32 src2_left,
    mlib_s32 src2_top,
    mlib_s32 dst_stride,
    mlib_s32 src1_stride,
    mlib_s32 src2_stride,
    mlib_blend src1_blend,
    mlib_blend src2_blend);

void mlib_VideoColorBlendABGR_Inp(
    mlib_u32 *src1dst,
    const mlib_u32 *src2,
    mlib_s32 src1dst_width,
    mlib_s32 src1dst_height,
    mlib_s32 src2_width,
    mlib_s32 src2_height,
    mlib_s32 src2_left,
    mlib_s32 src2_top,
    mlib_s32 src1dst_stride,
    mlib_s32 src2_stride,
    mlib_blend src1dst_blend,
    mlib_blend src2_blend);

void mlib_VideoColorBlendABGR_ResetAlpha(
    mlib_u32 *dst,
    const mlib_u32 *src1,
    const mlib_u32 *src2,
    mlib_s32 src1_width,
    mlib_s32 src1_height,
    mlib_s32 src2_width,
    mlib_s32 src2_height,
    mlib_s32 src2_left,
    mlib_s32 src2_top,
    mlib_s32 dst_stride,
    mlib_s32 src1_stride,
    mlib_s32 src2_stride,
    mlib_blend src1_blend,
    mlib_blend src2_blend);

void mlib_VideoColorBlendABGR_ResetAlpha_Inp(
    mlib_u32 *src1dst,
    const mlib_u32 *src2,
    mlib_s32 src1dst_width,
    mlib_s32 src1dst_height,
    mlib_s32 src2_width,
    mlib_s32 src2_height,
    mlib_s32 src2_left,
    mlib_s32 src2_top,
    mlib_s32 src1dst_stride,
    mlib_s32 src2_stride,
    mlib_blend src1dst_blend,
    mlib_blend src2_blend);

#ifdef __cplusplus
}
#endif

#endif /* _MLIB_VIDEO_PROTO_H */
