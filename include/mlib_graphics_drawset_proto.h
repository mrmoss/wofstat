/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_GRAPHICS_DRAWSET_PROTO_H
#define	_MLIB_GRAPHICS_DRAWSET_PROTO_H

#pragma ident	"@(#)mlib_graphics_drawset_proto.h	9.2	06/06/06 SMI"

#include <mlib_types.h>
#include <mlib_status.h>
#include <mlib_image_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 2-D DRAWING FUNCTIONS */

mlib_status mlib_GraphicsDrawPointSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPointSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineFanSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineFanSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineStripSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineStripSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleFanSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleFanSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleStripSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleStripSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleFanSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleFanSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleStripSet_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleStripSet_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

/* 2-D DRAWING FUNCTIONS WITH ALPHA BLENDING */

mlib_status mlib_GraphicsDrawPointSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPointSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS IN XOR MODE */

mlib_status mlib_GraphicsDrawPointSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPointSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLineSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLineSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLineFanSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLineFanSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLineStripSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLineStripSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawTriangleSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawTriangleSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawTriangleFanSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawTriangleFanSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawTriangleStripSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawTriangleStripSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillTriangleSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillTriangleSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillTriangleFanSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillTriangleFanSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillTriangleStripSet_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillTriangleStripSet_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING */

mlib_status mlib_GraphicsDrawLineSet_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineSet_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineFanSet_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineFanSet_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineStripSet_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineStripSet_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleSet_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleSet_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleFanSet_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleFanSet_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleStripSet_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleStripSet_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleSet_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleSet_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleFanSet_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleFanSet_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleStripSet_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleStripSet_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING AND ALPHA BLENDING */

mlib_status mlib_GraphicsDrawLineSet_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineSet_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH GOURAUD SHADING */

mlib_status mlib_GraphicsDrawLineSet_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineSet_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineFanSet_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineFanSet_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineStripSet_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineStripSet_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleSet_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleSet_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleFanSet_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleFanSet_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleStripSet_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleStripSet_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleSet_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleSet_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleFanSet_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleFanSet_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleStripSet_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleStripSet_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

/* 2-D DRAWING FUNCTIONS WITH ALPHA BLENDING AND GOURAUD SHADING */

mlib_status mlib_GraphicsDrawLineSet_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineSet_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH Z BUFFERING */

mlib_status mlib_GraphicsDrawLineSet_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineSet_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineFanSet_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineFanSet_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineStripSet_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineStripSet_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleSet_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleSet_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleFanSet_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleFanSet_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleStripSet_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleStripSet_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleSet_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleSet_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleFanSet_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleFanSet_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleStripSet_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleStripSet_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

/* 2-D DRAWING FUNCTIONS WITH ALPHA BLENDING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLineSet_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineSet_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING AND GOURAUD SHADING */

mlib_status mlib_GraphicsDrawLineSet_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineSet_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineFanSet_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineFanSet_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineStripSet_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineStripSet_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleSet_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleSet_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleFanSet_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleFanSet_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleStripSet_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleStripSet_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleSet_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleSet_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleFanSet_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleFanSet_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleStripSet_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleStripSet_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

/*
 * 2-D DRAWING FUNCTIONS WITH ANTIALIASING, ALPHA BLENDING AND
 * GOURAUD SHADING
 */

mlib_status mlib_GraphicsDrawLineSet_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineSet_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLineSet_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineSet_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineFanSet_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineFanSet_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineStripSet_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLineStripSet_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleSet_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleSet_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleFanSet_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleFanSet_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleStripSet_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangleStripSet_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleSet_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleSet_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleFanSet_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleFanSet_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleStripSet_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangleStripSet_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING, ALPHA BLENDING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLineSet_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineSet_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH GOURAUD SHADING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLineSet_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineSet_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineFanSet_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineFanSet_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineStripSet_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineStripSet_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleSet_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleSet_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleFanSet_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleFanSet_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleStripSet_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleStripSet_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleSet_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleSet_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleFanSet_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleFanSet_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleStripSet_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleStripSet_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

/* 2-D DRAWING FUNCTIONS WITH ALPHA BLENDING, GOURAUD SHADING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLineSet_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineSet_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING, GOURAUD SHADING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLineSet_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineSet_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineFanSet_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineFanSet_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineStripSet_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawLineStripSet_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleSet_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleSet_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleFanSet_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleFanSet_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleStripSet_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangleStripSet_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleSet_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleSet_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleFanSet_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleFanSet_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleStripSet_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillTriangleStripSet_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

/*
 * 2-D DRAWING FUNCTIONS WITH ANTIALIASING,
 * ALPHA BLENDING, GOURAUD SHADING AND Z BUFFERING
 */

mlib_status mlib_GraphicsDrawLineSet_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineSet_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineFanSet_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLineStripSet_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleSet_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleFanSet_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangleStripSet_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleSet_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleFanSet_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangleStripSet_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

#ifdef __cplusplus
}
#endif

#endif /* _MLIB_GRAPHICS_DRAWSET_PROTO_H */
