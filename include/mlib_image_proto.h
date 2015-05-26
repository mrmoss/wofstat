/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_IMAGE_PROTO_H
#define	_MLIB_IMAGE_PROTO_H

#pragma ident	"@(#)mlib_image_proto.h	9.2	07/03/20 SMI"

#include <mlib_types.h>
#include <mlib_status.h>
#include <mlib_image_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Arithmetic Operations ( arith ) */

mlib_status mlib_ImageAbs(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageAbs_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageAbs_Fp_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageAbs_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageAdd(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageAdd_Fp(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageAdd_Fp_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageAdd_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageAve(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageAve_Fp(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageAve_Fp_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageAve_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageBlend(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2,
    const mlib_image *alpha);

/* src1dst = src1dst * alpha + src2 * (1 - alpha) */
mlib_status mlib_ImageBlend1_Fp_Inp(
    mlib_image *src1dst,
    const mlib_image *src2,
    const mlib_image *alpha);

/* src1dst = src1dst * alpha + src2 * (1 - alpha) */
mlib_status mlib_ImageBlend1_Inp(
    mlib_image *src1dst,
    const mlib_image *src2,
    const mlib_image *alpha);

/* src2dst = src1 * alpha + src2dst * (1 - alpha) */
mlib_status mlib_ImageBlend2_Fp_Inp(
    mlib_image *src2dst,
    const mlib_image *src1,
    const mlib_image *alpha);

/* src2dst = src1 * alpha + src2dst * (1 - alpha) */
mlib_status mlib_ImageBlend2_Inp(
    mlib_image *src2dst,
    const mlib_image *src1,
    const mlib_image *alpha);

mlib_status mlib_ImageBlend_Fp(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2,
    const mlib_image *alpha);

mlib_status mlib_ImageBlendMulti(
    mlib_image *dst,
    const mlib_image **srcs,
    const mlib_image **alphas,
    const mlib_s32 *c,
    mlib_s32 n);

mlib_status mlib_ImageBlendMulti_Fp(
    mlib_image *dst,
    const mlib_image **srcs,
    const mlib_image **alphas,
    const mlib_d64 *c,
    mlib_s32 n);

mlib_status mlib_ImageBlendRGBA2ARGB(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageBlendRGBA2BGRA(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageBlendColor(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *color,
    mlib_s32 cmask);

mlib_status mlib_ImageBlendColor_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *color,
    mlib_s32 cmask);

mlib_status mlib_ImageBlendColor_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *color,
    mlib_s32 cmask);

mlib_status mlib_ImageBlendColor_Inp(
    mlib_image *srcdst,
    const mlib_s32 *color,
    mlib_s32 cmask);

mlib_status mlib_ImageConstAdd(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

mlib_status mlib_ImageConstAdd_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *c);

mlib_status mlib_ImageConstAdd_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *c);

mlib_status mlib_ImageConstAdd_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageConstDiv(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *consts);

mlib_status mlib_ImageConstDivShift(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *consts,
    mlib_s32 shift);

mlib_status mlib_ImageConstDivShift_Inp(
    mlib_image *srcdst,
    const mlib_s32 *consts,
    mlib_s32 shift);

mlib_status mlib_ImageConstDiv_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *consts);

mlib_status mlib_ImageConstDiv_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *consts);

mlib_status mlib_ImageConstDiv_Inp(
    mlib_image *srcdst,
    const mlib_d64 *consts);

mlib_status mlib_ImageConstMul(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *consts);

mlib_status mlib_ImageConstMulShift(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *consts,
    mlib_s32 shift);

mlib_status mlib_ImageConstMulShift_Inp(
    mlib_image *srcdst,
    const mlib_s32 *consts,
    mlib_s32 shift);

mlib_status mlib_ImageConstMul_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *consts);

mlib_status mlib_ImageConstMul_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *consts);

mlib_status mlib_ImageConstMul_Inp(
    mlib_image *srcdst,
    const mlib_d64 *consts);

mlib_status mlib_ImageConstSub(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

mlib_status mlib_ImageConstSub_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *c);

mlib_status mlib_ImageConstSub_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *c);

mlib_status mlib_ImageConstSub_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageDiv1_Fp_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageDiv2_Fp_Inp(
    mlib_image *src2dst,
    const mlib_image *src1);

mlib_status mlib_ImageDivAlpha(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 cmask);

mlib_status mlib_ImageDivAlpha_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 cmask);

mlib_status mlib_ImageDivAlpha_Fp_Inp(
    mlib_image *img,
    mlib_s32 cmask);

mlib_status mlib_ImageDivAlpha_Inp(
    mlib_image *img,
    mlib_s32 cmask);

mlib_status mlib_ImageDivConstShift(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *consts,
    mlib_s32 shift);

mlib_status mlib_ImageDivConstShift_Inp(
    mlib_image *srcdst,
    const mlib_s32 *consts,
    mlib_s32 shift);

mlib_status mlib_ImageDivShift(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2,
    mlib_s32 shift);

mlib_status mlib_ImageDivShift1_Inp(
    mlib_image *src1dst,
    const mlib_image *src2,
    mlib_s32 shift);

mlib_status mlib_ImageDivShift2_Inp(
    mlib_image *src2dst,
    const mlib_image *src1,
    mlib_s32 shift);

mlib_status mlib_ImageDiv_Fp(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageExp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageExp_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageExp_Fp_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageExp_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageInvert(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageInvert_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageInvert_Fp_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageInvert_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageLog(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageLog_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageLog_Fp_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageLog_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageMax(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageMax_Fp(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageMax_Fp_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageMax_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageMin(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageMin_Fp(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageMin_Fp_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageMin_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageMulAlpha(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 cmask);

mlib_status mlib_ImageMulAlpha_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 cmask);

mlib_status mlib_ImageMulAlpha_Fp_Inp(
    mlib_image *img,
    mlib_s32 cmask);

mlib_status mlib_ImageMulAlpha_Inp(
    mlib_image *img,
    mlib_s32 cmask);

mlib_status mlib_ImageMulShift(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2,
    mlib_s32 shift);

mlib_status mlib_ImageMulShift_Inp(
    mlib_image *src1dst,
    const mlib_image *src2,
    mlib_s32 shift);

mlib_status mlib_ImageMul_Fp(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageMul_Fp_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageScalarBlend(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2,
    const mlib_s32 *alpha);

mlib_status mlib_ImageScalarBlend_Fp(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2,
    const mlib_d64 *alpha);

mlib_status mlib_ImageScalarBlend_Fp_Inp(
    mlib_image *src1dst,
    const mlib_image *src2,
    const mlib_d64 *alpha);

mlib_status mlib_ImageScalarBlend_Inp(
    mlib_image *src1dst,
    const mlib_image *src2,
    const mlib_s32 *alpha);

mlib_status mlib_ImageScale(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *alpha,
    const mlib_s32 *beta,
    mlib_s32 shift);

mlib_status mlib_ImageScale2(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *alpha,
    const mlib_d64 *beta);

mlib_status mlib_ImageScale2_Inp(
    mlib_image *srcdst,
    const mlib_d64 *alpha,
    const mlib_d64 *beta);

mlib_status mlib_ImageScale_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *alpha,
    const mlib_d64 *beta);

mlib_status mlib_ImageScale_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *alpha,
    const mlib_d64 *beta);

mlib_status mlib_ImageScale_Inp(
    mlib_image *srcdst,
    const mlib_s32 *alpha,
    const mlib_s32 *beta,
    mlib_s32 shift);

mlib_status mlib_ImageSqrShift(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 shift);

mlib_status mlib_ImageSqrShift_Inp(
    mlib_image *srcdst,
    mlib_s32 shift);

mlib_status mlib_ImageSqr_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageSqr_Fp_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageSub(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

/* src1dst = src1dst - src2 */
mlib_status mlib_ImageSub1_Fp_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

/* src1dst = src1dst - src2 */
mlib_status mlib_ImageSub1_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

/* src2dst = src1 - src2dst */
mlib_status mlib_ImageSub2_Fp_Inp(
    mlib_image *src2dst,
    const mlib_image *src1);

/* src2dst = src1 - src2dst */
mlib_status mlib_ImageSub2_Inp(
    mlib_image *src2dst,
    const mlib_image *src1);

mlib_status mlib_ImageSub_Fp(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

/* Color Space Conversion ( color ) */

mlib_status mlib_ImageColorConvert1(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *cmat);

mlib_status mlib_ImageColorConvert1_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *cmat);

mlib_status mlib_ImageColorConvert2(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *cmat,
    const mlib_d64 *offset);

mlib_status mlib_ImageColorConvert2_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *cmat,
    const mlib_d64 *offset);

mlib_status mlib_ImageColorHSL2RGB(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorHSL2RGB_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorHSV2RGB(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorHSV2RGB_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2CIEMono(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2CIEMono_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2HSL(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2HSL_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2HSV(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2HSV_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2Mono(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *weight);

mlib_status mlib_ImageColorRGB2Mono_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *weight);

mlib_status mlib_ImageColorRGB2XYZ(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2XYZ_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2YCC(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorRGB2YCC_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorXYZ2RGB(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorXYZ2RGB_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorYCC2RGB(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageColorYCC2RGB_Fp(
    mlib_image *dst,
    const mlib_image *src);

/* Image Creation, Deletion, Setting and Query ( common ) */

mlib_image *mlib_ImageCreate(
    mlib_type type,
    mlib_s32 channels,
    mlib_s32 width,
    mlib_s32 height);

mlib_image *mlib_ImageCreateStruct(
    mlib_type type,
    mlib_s32 channels,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 stride,
    const void *data);

mlib_image *mlib_ImageCreateSubimage(
    mlib_image *img,
    mlib_s32 x,
    mlib_s32 y,
    mlib_s32 w,
    mlib_s32 h);

void mlib_ImageDelete(
    mlib_image *img);

mlib_status mlib_ImageSetPaddings(
    mlib_image *img,
    mlib_u8 left,
    mlib_u8 top,
    mlib_u8 right,
    mlib_u8 bottom);

mlib_status mlib_ImageSetFormat(
    mlib_image *img,
    mlib_format format);

mlib_status mlib_ImageSetStruct(
    mlib_image *img,
    mlib_type type,
    mlib_s32 channels,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 stride,
    const void *datbuf);

mlib_status mlib_ImageResetStruct(
    mlib_image *img,
    mlib_type type,
    mlib_s32 channels,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 stride,
    const void *datbuf);

mlib_status mlib_ImageSetSubimageStruct(
    mlib_image *subimg,
    const mlib_image *img,
    mlib_s32   x,
    mlib_s32   y,
    mlib_s32   w,
    mlib_s32   h);

mlib_status mlib_ImageResetSubimageStruct(
    mlib_image *subimg,
    const mlib_image *img,
    mlib_s32   x,
    mlib_s32   y,
    mlib_s32   w,
    mlib_s32   h);

static mlib_type mlib_ImageGetType(
    const mlib_image *img);

static mlib_s32 mlib_ImageGetChannels(
    const mlib_image *img);

static mlib_s32 mlib_ImageGetWidth(
    const mlib_image *img);

static mlib_s32 mlib_ImageGetHeight(
    const mlib_image *img);

static mlib_s32 mlib_ImageGetStride(
    const mlib_image *img);

static void *mlib_ImageGetData(
    const mlib_image *img);

static mlib_s32 mlib_ImageGetFlags(
    const mlib_image *img);

static mlib_u8 *mlib_ImageGetPaddings(
    const mlib_image *img);

static mlib_s32 mlib_ImageGetBitOffset(
    const mlib_image *img);

static mlib_format mlib_ImageGetFormat(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotAligned2(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotAligned4(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotAligned64(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotAligned8(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotHeight2X(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotHeight4X(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotHeight8X(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotOneDvector(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotStride8X(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotWidth2X(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotWidth4X(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsNotWidth8X(
    const mlib_image *img);

static mlib_s32 mlib_ImageIsUserAllocated(
    const mlib_image *img);

static mlib_s32 mlib_ImageTestFlags(
    const mlib_image *img,
    mlib_s32 flags);

/* Image Copying and Clearing ( copy ) */

mlib_status mlib_ImageClear(
    mlib_image *img,
    const mlib_s32 *color);

mlib_status mlib_ImageClearEdge(
    mlib_image *img,
    mlib_s32 dx,
    mlib_s32 dy,
    const mlib_s32 *color);

mlib_status mlib_ImageClearEdge_Fp(
    mlib_image *img,
    mlib_s32 dx,
    mlib_s32 dy,
    const mlib_d64 *color);

mlib_status mlib_ImageClear_Fp(
    mlib_image *img,
    const mlib_d64 *color);

mlib_status mlib_ImageCopy(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageCopyArea(
    mlib_image *img,
    mlib_s32 x,
    mlib_s32 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 dx,
    mlib_s32 dy);

mlib_status mlib_ImageCopyMask(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_image *mask,
    const mlib_s32 *thresh);

mlib_status mlib_ImageCopyMask_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_image *mask,
    const mlib_d64 *thresh);

mlib_status mlib_ImageCopySubimage(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 xd,
    mlib_s32 yd,
    mlib_s32 xs,
    mlib_s32 ys,
    mlib_s32 w,
    mlib_s32 h);

/* Data Format Conversion ( format ) */

mlib_status mlib_ImageChannelCopy(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 cmask);

mlib_status mlib_ImageChannelExtract(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 cmask);

mlib_status mlib_ImageChannelInsert(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 cmask);

mlib_status mlib_ImageChannelMerge(
    mlib_image *dst,
    const mlib_image **srcs);

mlib_status mlib_ImageChannelSplit(
    mlib_image **dsts,
    const mlib_image *src);

mlib_status mlib_ImageDataTypeConvert(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageReformat(
    void **dstData,
    const void **srcData,
    mlib_s32 numChannels,
    mlib_s32 xSize,
    mlib_s32 ySize,
    mlib_type dstDataType,
    const mlib_s32 *dstBandoffsets,
    mlib_s32 dstScanlinestride,
    mlib_s32 dstPixelstride,
    mlib_type srcDataType,
    const mlib_s32 *srcBandoffsets,
    mlib_s32 srcScanlinestride,
    mlib_s32 srcPixelstride);

/* Fourier Transformation ( fourier ) */

mlib_status mlib_ImageFourierTransform(
    mlib_image *dst,
    const mlib_image *src,
    mlib_fourier_mode mode);

/* Geometric Operations ( geom ) */

mlib_status mlib_ImageAffine(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *mtx,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageAffineIndex(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *mtx,
    mlib_filter filter,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageAffineTable(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *mtx,
    const void *interp_table,
    mlib_edge edge);

mlib_status mlib_ImageAffineTable_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *mtx,
    const void *interp_table,
    mlib_edge edge);

mlib_status mlib_ImageAffineTransform(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *mtx,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageAffineTransformIndex(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *mtx,
    mlib_filter filter,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageAffineTransform_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *mtx,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageAffine_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *mtx,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageFilteredSubsample(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 scaleX,
    mlib_s32 scaleY,
    mlib_s32 transX,
    mlib_s32 transY,
    const mlib_d64 *hKernel,
    const mlib_d64 *vKernel,
    mlib_s32 hSize,
    mlib_s32 vSize,
    mlib_s32 hParity,
    mlib_s32 vParity,
    mlib_edge edge);

mlib_status mlib_ImageFilteredSubsample_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 scaleX,
    mlib_s32 scaleY,
    mlib_s32 transX,
    mlib_s32 transY,
    const mlib_d64 *hKernel,
    const mlib_d64 *vKernel,
    mlib_s32 hSize,
    mlib_s32 vSize,
    mlib_s32 hParity,
    mlib_s32 vParity,
    mlib_edge edge);

mlib_status mlib_ImageFlipAntiDiag(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageFlipAntiDiag_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageFlipMainDiag(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageFlipMainDiag_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageFlipX(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageFlipX_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageFlipY(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageFlipY_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageGridWarp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_f32 *xWarpPos,
    const mlib_f32 *yWarpPos,
    mlib_d64 postShiftX,
    mlib_d64 postShiftY,
    mlib_s32 xStart,
    mlib_s32 xStep,
    mlib_s32 xNumCells,
    mlib_s32 yStart,
    mlib_s32 yStep,
    mlib_s32 yNumCells,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageGridWarpTable(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_f32 *xWarpPos,
    const mlib_f32 *yWarpPos,
    mlib_d64 postShiftX,
    mlib_d64 postShiftY,
    mlib_s32 xStart,
    mlib_s32 xStep,
    mlib_s32 xNumCells,
    mlib_s32 yStart,
    mlib_s32 yStep,
    mlib_s32 yNumCells,
    const void *table,
    mlib_edge edge);

mlib_status mlib_ImageGridWarpTable_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_f32 *xWarpPos,
    const mlib_f32 *yWarpPos,
    mlib_d64 postShiftX,
    mlib_d64 postShiftY,
    mlib_s32 xStart,
    mlib_s32 xStep,
    mlib_s32 xNumCells,
    mlib_s32 yStart,
    mlib_s32 yStep,
    mlib_s32 yNumCells,
    const void *table,
    mlib_edge edge);

mlib_status mlib_ImageGridWarp_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_f32 *xWarpPos,
    const mlib_f32 *yWarpPos,
    mlib_d64 postShiftX,
    mlib_d64 postShiftY,
    mlib_s32 xStart,
    mlib_s32 xStep,
    mlib_s32 xNumCells,
    mlib_s32 yStart,
    mlib_s32 yStep,
    mlib_s32 yNumCells,
    mlib_filter filter,
    mlib_edge edge);

void *mlib_ImageInterpTableCreate(
    mlib_type type,
    mlib_s32 width,
    mlib_s32 height,
    mlib_s32 leftPadding,
    mlib_s32 topPadding,
    mlib_s32 subsampleBitsH,
    mlib_s32 subsampleBitsV,
    mlib_s32 precisionBits,
    const void *dataH,
    const void *dataV);

void mlib_ImageInterpTableDelete(
    void *interp_table);

mlib_status mlib_ImagePolynomialWarp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *xCoeffs,
    const mlib_d64 *yCoeffs,
    mlib_s32 n,
    mlib_d64 preShiftX,
    mlib_d64 preShiftY,
    mlib_d64 postShiftX,
    mlib_d64 postShiftY,
    mlib_d64 preScaleX,
    mlib_d64 preScaleY,
    mlib_d64 postScaleX,
    mlib_d64 postScaleY,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImagePolynomialWarpTable(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *xCoeffs,
    const mlib_d64 *yCoeffs,
    mlib_s32 n,
    mlib_d64 preShiftX,
    mlib_d64 preShiftY,
    mlib_d64 postShiftX,
    mlib_d64 postShiftY,
    mlib_d64 preScaleX,
    mlib_d64 preScaleY,
    mlib_d64 postScaleX,
    mlib_d64 postScaleY,
    const void *interp_table,
    mlib_edge edge);

mlib_status mlib_ImagePolynomialWarpTable_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *xCoeffs,
    const mlib_d64 *yCoeffs,
    mlib_s32 n,
    mlib_d64 preShiftX,
    mlib_d64 preShiftY,
    mlib_d64 postShiftX,
    mlib_d64 postShiftY,
    mlib_d64 preScaleX,
    mlib_d64 preScaleY,
    mlib_d64 postScaleX,
    mlib_d64 postScaleY,
    const void *interp_table,
    mlib_edge edge);

mlib_status mlib_ImagePolynomialWarp_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *xCoeffs,
    const mlib_d64 *yCoeffs,
    mlib_s32 n,
    mlib_d64 preShiftX,
    mlib_d64 preShiftY,
    mlib_d64 postShiftX,
    mlib_d64 postShiftY,
    mlib_d64 preScaleX,
    mlib_d64 preScaleY,
    mlib_d64 postScaleX,
    mlib_d64 postScaleY,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageRotate(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 angle,
    mlib_d64 xcenter,
    mlib_d64 ycenter,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageRotate180(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageRotate180_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageRotate270(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageRotate270_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageRotate90(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageRotate90_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageRotateIndex(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 angle,
    mlib_d64 xcenter,
    mlib_d64 ycenter,
    mlib_filter filter,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageRotate_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 angle,
    mlib_d64 xcenter,
    mlib_d64 ycenter,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageSubsampleAverage(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 scalex,
    mlib_d64 scaley);

mlib_status mlib_ImageSubsampleAverage_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 scalex,
    mlib_d64 scaley);

mlib_status mlib_ImageSubsampleBinaryToGray(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 xscale,
    mlib_d64 yscale,
    const mlib_u8 *lutGray);

mlib_status mlib_ImageZoomIn2X(
    mlib_image *dst,
    const mlib_image *src,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageZoomIn2XIndex(
    mlib_image *dst,
    const mlib_image *src,
    mlib_filter filter,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageZoomIn2X_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageZoomOut2X(
    mlib_image *dst,
    const mlib_image *src,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageZoomOut2XIndex(
    mlib_image *dst,
    const mlib_image *src,
    mlib_filter filter,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageZoomOut2X_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageZoomTranslate(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_d64 tx,
    mlib_d64 ty,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageZoomTranslateTable(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_d64 tx,
    mlib_d64 ty,
    const void *interp_table,
    mlib_edge edge);

mlib_status mlib_ImageZoomTranslateTable_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_d64 tx,
    mlib_d64 ty,
    const void *interp_table,
    mlib_edge edge);

mlib_status mlib_ImageZoomTranslateToGray(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_d64 tx,
    mlib_d64 ty,
    mlib_filter filter,
    mlib_edge edge,
    const mlib_s32 *ghigh,
    const mlib_s32 *glow);

mlib_status mlib_ImageZoomTranslate_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_d64 tx,
    mlib_d64 ty,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageZoom(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageZoomIndex(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_filter filter,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageZoom_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_filter filter,
    mlib_edge edge);

mlib_status mlib_ImageZoomTranslateBlend(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_d64 tx,
    mlib_d64 ty,
    mlib_filter filter,
    mlib_edge edge,
    mlib_blend blend,
    mlib_s32 alpha,
    mlib_s32 cmask);

mlib_status mlib_ImageZoomBlend(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_filter filter,
    mlib_edge edge,
    mlib_blend blend,
    mlib_s32 alpha,
    mlib_s32 cmask);

mlib_status mlib_ImageZoomTranslateTableBlend(
    mlib_image *dst,
    const mlib_image *src,
    mlib_d64 zoomx,
    mlib_d64 zoomy,
    mlib_d64 tx,
    mlib_d64 ty,
    const void *table,
    mlib_edge edge,
    mlib_blend blend,
    mlib_s32 cmask);

/* Logical Operations ( logic ) */

mlib_status mlib_ImageAnd(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageAndNot(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

/* src1dst = src1dst & (~src2) */
mlib_status mlib_ImageAndNot1_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

/* src2dst = src1 & (~src2dst) */
mlib_status mlib_ImageAndNot2_Inp(
    mlib_image *src2dst,
    const mlib_image *src1);

mlib_status mlib_ImageAnd_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageConstAnd(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

mlib_status mlib_ImageConstAndNot(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

/* srcdst = (~srcdst) & c */
mlib_status mlib_ImageConstAndNot_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageConstAnd_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageConstNotAnd(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

mlib_status mlib_ImageConstNotAnd_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageConstNotOr(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

mlib_status mlib_ImageConstNotOr_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageConstNotXor(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

mlib_status mlib_ImageConstNotXor_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageConstOr(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

mlib_status mlib_ImageConstOrNot(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

/* srcdst = (~srcdst) | c */
mlib_status mlib_ImageConstOrNot_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageConstOr_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageConstXor(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *c);

mlib_status mlib_ImageConstXor_Inp(
    mlib_image *srcdst,
    const mlib_s32 *c);

mlib_status mlib_ImageNot(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageNotAnd(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageNotAnd_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageNotOr(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageNotOr_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageNotXor(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageNotXor_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageNot_Inp(
    mlib_image *srcdst);

mlib_status mlib_ImageOr(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageOrNot(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

/* src1dst = src1dst | (~src2) */
mlib_status mlib_ImageOrNot1_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

/* src2dst = src1 | (~src2dst) */
mlib_status mlib_ImageOrNot2_Inp(
    mlib_image *src2dst,
    const mlib_image *src1);

mlib_status mlib_ImageOr_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

mlib_status mlib_ImageXor(
    mlib_image *dst,
    const mlib_image *src1,
    const mlib_image *src2);

mlib_status mlib_ImageXor_Inp(
    mlib_image *src1dst,
    const mlib_image *src2);

/* Radiometric Operations ( radio ) */

mlib_status mlib_ImageColorTrue2IndexInit(
    void **colormap,
    mlib_s32 bits,
    mlib_type intype,
    mlib_type outtype,
    mlib_s32 channels,
    mlib_s32 entries,
    mlib_s32 offset,
    const void **table);

mlib_status mlib_ImageColorTrue2Index(
    mlib_image *dst,
    const mlib_image *src,
    const void *colormap);

void mlib_ImageColorTrue2IndexFree(
    void *colormap);

mlib_status mlib_ImageColorDitherInit(
    void **colormap,
    const mlib_s32 *dimensions,
    mlib_type intype,
    mlib_type outtype,
    mlib_s32 channels,
    mlib_s32 entries,
    mlib_s32 offset,
    void **lut);

void mlib_ImageColorDitherFree(
    void *colormap);

mlib_status mlib_ImageColorErrorDiffusion3x3(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    const void *colormap);

mlib_status mlib_ImageColorErrorDiffusionMxN(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 dm,
    mlib_s32 dn,
    mlib_s32 scale,
    const void *colormap);

mlib_status mlib_ImageColorOrderedDither8x8(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *dmask,
    mlib_s32 scale,
    const void *colormap);

mlib_status mlib_ImageColorOrderedDitherMxN(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 **dmask,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 scale,
    const void *colormap);

mlib_status mlib_ImageReplaceColor(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *color1,
    const mlib_s32 *color2);

mlib_status mlib_ImageReplaceColor_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *color1,
    const mlib_d64 *color2);

mlib_status mlib_ImageReplaceColor_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *color1,
    const mlib_d64 *color2);

mlib_status mlib_ImageReplaceColor_Inp(
    mlib_image *srcdst,
    const mlib_s32 *color1,
    const mlib_s32 *color2);

mlib_status mlib_ImageHistogram(
    mlib_s32 **histo,
    const mlib_image *img);

mlib_status mlib_ImageHistogram2(
    mlib_s32 **histo,
    const mlib_image *img,
    const mlib_s32 *numBins,
    const mlib_s32 *lowValue,
    const mlib_s32 *highValue,
    mlib_s32 xStart,
    mlib_s32 yStart,
    mlib_s32 xPeriod,
    mlib_s32 yPeriod);

mlib_status mlib_ImageLookUp(
    mlib_image *dst,
    const mlib_image *src,
    const void **table);

mlib_status mlib_ImageLookUp2(
    mlib_image *dst,
    const mlib_image *src,
    const void **table,
    const mlib_s32 *offsets,
    mlib_s32 channels);

mlib_status mlib_ImageLookUpMask(
    mlib_image *dst,
    const mlib_image *src,
    const void **table,
    mlib_s32 channels,
    mlib_s32 cmask);

mlib_status mlib_ImageLookUp_Inp(
    mlib_image *srcdst,
    const void **table);

mlib_status mlib_ImageThresh1(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *thresh,
    const mlib_s32 *ghigh,
    const mlib_s32 *glow);

mlib_status mlib_ImageThresh1_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *thresh,
    const mlib_d64 *ghigh,
    const mlib_d64 *glow);

mlib_status mlib_ImageThresh1_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *thresh,
    const mlib_d64 *ghigh,
    const mlib_d64 *glow);

mlib_status mlib_ImageThresh1_Inp(
    mlib_image *srcdst,
    const mlib_s32 *thresh,
    const mlib_s32 *ghigh,
    const mlib_s32 *glow);

mlib_status mlib_ImageThresh2(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *thresh,
    const mlib_s32 *glow);

mlib_status mlib_ImageThresh2_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *thresh,
    const mlib_d64 *glow);

mlib_status mlib_ImageThresh2_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *thresh,
    const mlib_d64 *glow);

mlib_status mlib_ImageThresh2_Inp(
    mlib_image *srcdst,
    const mlib_s32 *thresh,
    const mlib_s32 *glow);

mlib_status mlib_ImageThresh3(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *thresh,
    const mlib_s32 *ghigh);

mlib_status mlib_ImageThresh3_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *thresh,
    const mlib_d64 *ghigh);

mlib_status mlib_ImageThresh3_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *thresh,
    const mlib_d64 *ghigh);

mlib_status mlib_ImageThresh3_Inp(
    mlib_image *srcdst,
    const mlib_s32 *thresh,
    const mlib_s32 *ghigh);

mlib_status mlib_ImageThresh4(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *thigh,
    const mlib_s32 *tlow,
    const mlib_s32 *ghigh,
    const mlib_s32 *glow);

mlib_status mlib_ImageThresh4_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *thigh,
    const mlib_d64 *tlow,
    const mlib_d64 *ghigh,
    const mlib_d64 *glow);

mlib_status mlib_ImageThresh4_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *thigh,
    const mlib_d64 *tlow,
    const mlib_d64 *ghigh,
    const mlib_d64 *glow);

mlib_status mlib_ImageThresh4_Inp(
    mlib_image *srcdst,
    const mlib_s32 *thigh,
    const mlib_s32 *tlow,
    const mlib_s32 *ghigh,
    const mlib_s32 *glow);

mlib_status mlib_ImageThresh5(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *thigh,
    const mlib_s32 *tlow,
    const mlib_s32 *gmid);

mlib_status mlib_ImageThresh5_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *thigh,
    const mlib_d64 *tlow,
    const mlib_d64 *gmid);

mlib_status mlib_ImageThresh5_Fp_Inp(
    mlib_image *srcdst,
    const mlib_d64 *thigh,
    const mlib_d64 *tlow,
    const mlib_d64 *gmid);

mlib_status mlib_ImageThresh5_Inp(
    mlib_image *srcdst,
    const mlib_s32 *thigh,
    const mlib_s32 *tlow,
    const mlib_s32 *gmid);

/*
 * Linear and Not-Linear Spatial Operations,
 * Morphological Operations (spatial)
 */

mlib_status mlib_ImageConv2x2(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConv2x2Index(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageConv2x2_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *kernel,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConv3x3(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConv3x3Index(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageConv3x3_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *kernel,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConv4x4(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConv4x4Index(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageConv4x4_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *kernel,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConv5x5(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConv5x5Index(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageConv5x5_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *kernel,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConv7x7(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConv7x7Index(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 scale,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageConv7x7_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *kernel,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConvKernelConvert(
    mlib_s32 *ikernel,
    mlib_s32 *iscale,
    const mlib_d64 *fkernel,
    mlib_s32 m,
    mlib_s32 n,
    mlib_type type);

mlib_status mlib_ImageConvMxN(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 dm,
    mlib_s32 dn,
    mlib_s32 scale,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConvMxNIndex(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *kernel,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 dm,
    mlib_s32 dn,
    mlib_s32 scale,
    mlib_edge edge,
    const void *colormap);

mlib_status mlib_ImageConvMxN_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *kernel,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 dm,
    mlib_s32 dn,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConvolveMxN(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *kernel,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 dm,
    mlib_s32 dn,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageConvolveMxN_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *kernel,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 dm,
    mlib_s32 dn,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageDilate4(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageDilate4_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageDilate8(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageDilate8_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageErode4(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageErode4_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageErode8(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageErode8_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageGradient3x3(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *hmask,
    const mlib_d64 *vmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageGradient3x3_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *hmask,
    const mlib_d64 *vmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageGradientMxN(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *hmask,
    const mlib_d64 *vmask,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 dm,
    mlib_s32 dn,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageGradientMxN_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *hmask,
    const mlib_d64 *vmask,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 dm,
    mlib_s32 dn,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageMaxFilter3x3(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMaxFilter3x3_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMaxFilter5x5(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMaxFilter5x5_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMaxFilter7x7(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMaxFilter7x7_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMedianFilter3x3(
    mlib_image *dst,
    const mlib_image *src,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageMedianFilter3x3_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageMedianFilter3x3_US(
    mlib_image *dst,
    const mlib_image *src,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge,
    mlib_s32 bits);

mlib_status mlib_ImageMedianFilter5x5(
    mlib_image *dst,
    const mlib_image *src,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageMedianFilter5x5_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageMedianFilter5x5_US(
    mlib_image *dst,
    const mlib_image *src,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge,
    mlib_s32 bits);

mlib_status mlib_ImageMedianFilter7x7(
    mlib_image *dst,
    const mlib_image *src,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageMedianFilter7x7_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageMedianFilter7x7_US(
    mlib_image *dst,
    const mlib_image *src,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge,
    mlib_s32 bits);

mlib_status mlib_ImageMedianFilterMxN(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 m,
    mlib_s32 n,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageMedianFilterMxN_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 m,
    mlib_s32 n,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageMedianFilterMxN_US(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 m,
    mlib_s32 n,
    mlib_median_mask mmask,
    mlib_s32 cmask,
    mlib_edge edge,
    mlib_s32 bits);

mlib_status mlib_ImageMinFilter3x3(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMinFilter3x3_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMinFilter5x5(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMinFilter5x5_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMinFilter7x7(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageMinFilter7x7_Fp(
    mlib_image *dst,
    const mlib_image *src);

mlib_status mlib_ImageRankFilter3x3(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 rank);

mlib_status mlib_ImageRankFilter3x3_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 rank);

mlib_status mlib_ImageRankFilter3x3_US(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 rank,
    mlib_s32 bits);

mlib_status mlib_ImageRankFilter5x5(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 rank);

mlib_status mlib_ImageRankFilter5x5_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 rank);

mlib_status mlib_ImageRankFilter5x5_US(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 rank,
    mlib_s32 bits);

mlib_status mlib_ImageRankFilter7x7(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 rank);

mlib_status mlib_ImageRankFilter7x7_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 rank);

mlib_status mlib_ImageRankFilter7x7_US(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 rank,
    mlib_s32 bits);

mlib_status mlib_ImageRankFilterMxN(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 rank);

mlib_status mlib_ImageRankFilterMxN_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 rank);

mlib_status mlib_ImageRankFilterMxN_US(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 m,
    mlib_s32 n,
    mlib_s32 rank,
    mlib_s32 bits);

mlib_status mlib_ImageSConv3x3(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *hkernel,
    const mlib_s32 *vkernel,
    mlib_s32 scale,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageSConv3x3_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *hkernel,
    const mlib_d64 *vkernel,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageSConv5x5(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *hkernel,
    const mlib_s32 *vkernel,
    mlib_s32 scale,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageSConv5x5_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *hkernel,
    const mlib_d64 *vkernel,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageSConv7x7(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_s32 *hkernel,
    const mlib_s32 *vkernel,
    mlib_s32 scale,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageSConv7x7_Fp(
    mlib_image *dst,
    const mlib_image *src,
    const mlib_d64 *hkernel,
    const mlib_d64 *vkernel,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageSConvKernelConvert(
    mlib_s32 *ihkernel,
    mlib_s32 *ivkernel,
    mlib_s32 *iscale,
    const mlib_d64 *fhkernel,
    const mlib_d64 *fvkernel,
    mlib_s32 m,
    mlib_s32 n,
    mlib_type type);

mlib_status mlib_ImageSobel(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 cmask,
    mlib_edge edge);

mlib_status mlib_ImageSobel_Fp(
    mlib_image *dst,
    const mlib_image *src,
    mlib_s32 cmask,
    mlib_edge edge);

/* Image Statistics ( stat ) */

mlib_status mlib_ImageAutoCorrel(
    mlib_d64 *correl,
    const mlib_image *img,
    mlib_s32 dx,
    mlib_s32 dy);

mlib_status mlib_ImageAutoCorrel_Fp(
    mlib_d64 *correl,
    const mlib_image *img,
    mlib_s32 dx,
    mlib_s32 dy);

mlib_status mlib_ImageCrossCorrel(
    mlib_d64 *correl,
    const mlib_image *img1,
    const mlib_image *img2);

mlib_status mlib_ImageCrossCorrel_Fp(
    mlib_d64 *correl,
    const mlib_image *img1,
    const mlib_image *img2);

mlib_status mlib_ImageNormCrossCorrel(
    mlib_d64 *correl,
    const mlib_image *img1,
    const mlib_image *img2,
    const mlib_d64 *mean2,
    const mlib_d64 *sdev2);

mlib_status mlib_ImageNormCrossCorrel_Fp(
    mlib_d64 *correl,
    const mlib_image *img1,
    const mlib_image *img2,
    const mlib_d64 *mean2,
    const mlib_d64 *sdev2);

mlib_status mlib_ImageExtrema2(
    mlib_s32 *min,
    mlib_s32 *max,
    const mlib_image *img,
    mlib_s32 xStart,
    mlib_s32 yStart,
    mlib_s32 xPeriod,
    mlib_s32 yPeriod);

mlib_status mlib_ImageExtrema2_Fp(
    mlib_d64 *min,
    mlib_d64 *max,
    const mlib_image *img,
    mlib_s32 xStart,
    mlib_s32 yStart,
    mlib_s32 xPeriod,
    mlib_s32 yPeriod);

mlib_status mlib_ImageExtremaLocations(
    mlib_s32 *min,
    mlib_s32 *max,
    const mlib_image *img,
    mlib_s32 xStart,
    mlib_s32 yStart,
    mlib_s32 xPeriod,
    mlib_s32 yPeriod,
    mlib_s32 saveLocations,
    mlib_s32 maxRuns,
    mlib_s32 *minCounts,
    mlib_s32 *maxCounts,
    mlib_s32 **minLocations,
    mlib_s32 **maxLocations,
    mlib_s32 len);

mlib_status mlib_ImageExtremaLocations_Fp(
    mlib_d64 *min,
    mlib_d64 *max,
    const mlib_image *img,
    mlib_s32 xStart,
    mlib_s32 yStart,
    mlib_s32 xPeriod,
    mlib_s32 yPeriod,
    mlib_s32 saveLocations,
    mlib_s32 maxRuns,
    mlib_s32 *minCounts,
    mlib_s32 *maxCounts,
    mlib_s32 **minLocations,
    mlib_s32 **maxLocations,
    mlib_s32 len);

mlib_status mlib_ImageMaximum(
    mlib_s32 *max,
    const mlib_image *img);

mlib_status mlib_ImageMaximum_Fp(
    mlib_d64 *max,
    const mlib_image *img);

mlib_status mlib_ImageMean(
    mlib_d64 *mean,
    const mlib_image *img);

mlib_status mlib_ImageMean_Fp(
    mlib_d64 *mean,
    const mlib_image *img);

mlib_status mlib_ImageMinimum(
    mlib_s32 *min,
    const mlib_image *img);

mlib_status mlib_ImageMinimum_Fp(
    mlib_d64 *min,
    const mlib_image *img);

mlib_status mlib_ImageMoment2(
    mlib_d64 *moment,
    const mlib_image *img);

mlib_status mlib_ImageMoment2_Fp(
    mlib_d64 *moment,
    const mlib_image *img);

mlib_status mlib_ImageStdDev(
    mlib_d64 *sdev,
    const mlib_image *img,
    const mlib_d64 *mean);

mlib_status mlib_ImageStdDev_Fp(
    mlib_d64 *sdev,
    const mlib_image *img,
    const mlib_d64 *mean);

mlib_status mlib_ImageXProj(
    mlib_d64 *xproj,
    const mlib_image *img);

mlib_status mlib_ImageXProj_Fp(
    mlib_d64 *xproj,
    const mlib_image *img);

mlib_status mlib_ImageYProj(
    mlib_d64 *yproj,
    const mlib_image *img);

mlib_status mlib_ImageYProj_Fp(
    mlib_d64 *yproj,
    const mlib_image *img);

#ifdef __cplusplus
}
#endif

#endif /* _MLIB_IMAGE_PROTO_H */
