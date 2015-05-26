/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_GRAPHICS_PROTO_H
#define	_MLIB_GRAPHICS_PROTO_H

#pragma ident	"@(#)mlib_graphics_proto.h	9.2	06/06/06 SMI"

#include <mlib_types.h>
#include <mlib_status.h>
#include <mlib_image_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 2-D DRAWING FUNCTIONS */

mlib_status mlib_GraphicsDrawPoint_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPoint_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolypoint_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolypoint_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLine_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLine_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolyline_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolyline_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawArc_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawArc_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c);

mlib_status mlib_GraphicsFillArc_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c);

mlib_status mlib_GraphicsFillArc_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangle_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangle_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangle_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangle_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawRectangle_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawRectangle_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c);

mlib_status mlib_GraphicsFillRectangle_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c);

mlib_status mlib_GraphicsFillRectangle_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolygon_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolygon_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillPolygon_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillPolygon_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawCircle_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawCircle_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c);

mlib_status mlib_GraphicsFillCircle_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c);

mlib_status mlib_GraphicsFillCircle_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawEllipse_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawEllipse_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c);

mlib_status mlib_GraphicsFillEllipse_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c);

mlib_status mlib_GraphicsFillEllipse_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c);

mlib_status mlib_GraphicsBoundaryFill_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsBoundaryFill_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFloodFill_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFloodFill_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c,
    mlib_s32 c2);

/* 2-D DRAWING FUNCTIONS WITH ALPHA BLENDING */

mlib_status mlib_GraphicsDrawPoint_B_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPoint_B_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolypoint_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolypoint_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLine_B_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLine_B_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawArc_B_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawArc_B_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillArc_B_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillArc_B_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_B_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_B_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_B_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_B_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawRectangle_B_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawRectangle_B_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillRectangle_B_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillRectangle_B_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_B_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_B_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawCircle_B_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawCircle_B_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillCircle_B_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillCircle_B_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawEllipse_B_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 alpha);

mlib_status mlib_GraphicsDrawEllipse_B_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 alpha);

mlib_status mlib_GraphicsFillEllipse_B_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 alpha);

mlib_status mlib_GraphicsFillEllipse_B_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 alpha);

/* 2-D DRAWING FUNCTIONS IN XOR MODE */

mlib_status mlib_GraphicsDrawPoint_X_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPoint_X_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolypoint_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolypoint_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLine_X_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLine_X_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolyline_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolyline_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawArc_X_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawArc_X_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillArc_X_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillArc_X_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawTriangle_X_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawTriangle_X_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillTriangle_X_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillTriangle_X_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawRectangle_X_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawRectangle_X_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillRectangle_X_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillRectangle_X_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 w,
    mlib_s32 h,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolygon_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolygon_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillPolygon_X_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillPolygon_X_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawCircle_X_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawCircle_X_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillCircle_X_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillCircle_X_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawEllipse_X_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawEllipse_X_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillEllipse_X_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 c2);

mlib_status mlib_GraphicsFillEllipse_X_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 c2);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING */

mlib_status mlib_GraphicsDrawLine_A_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLine_A_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolyline_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolyline_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawArc_A_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawArc_A_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c);

mlib_status mlib_GraphicsFillArc_A_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c);

mlib_status mlib_GraphicsFillArc_A_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangle_A_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangle_A_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangle_A_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangle_A_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolygon_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolygon_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillPolygon_A_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillPolygon_A_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawCircle_A_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawCircle_A_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c);

mlib_status mlib_GraphicsFillCircle_A_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c);

mlib_status mlib_GraphicsFillCircle_A_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawEllipse_A_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawEllipse_A_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c);

mlib_status mlib_GraphicsFillEllipse_A_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c);

mlib_status mlib_GraphicsFillEllipse_A_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING AND ALPHA BLENDING */

mlib_status mlib_GraphicsDrawLine_AB_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLine_AB_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawArc_AB_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawArc_AB_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillArc_AB_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillArc_AB_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_f32 t1,
    mlib_f32 t2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_AB_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_AB_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_AB_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_AB_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_AB_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_AB_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawCircle_AB_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawCircle_AB_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillCircle_AB_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillCircle_AB_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 r,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawEllipse_AB_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 alpha);

mlib_status mlib_GraphicsDrawEllipse_AB_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 alpha);

mlib_status mlib_GraphicsFillEllipse_AB_8(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 alpha);

mlib_status mlib_GraphicsFillEllipse_AB_32(
    mlib_image *buffer,
    mlib_s16 x,
    mlib_s16 y,
    mlib_s32 a,
    mlib_s32 b,
    mlib_f32 t,
    mlib_s32 c,
    mlib_s32 alpha);

/* 2-D DRAWING FUNCTIONS WITH GOURAUD SHADING */

mlib_status mlib_GraphicsDrawLine_G_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c1,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLine_G_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c1,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolyline_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawPolyline_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangle_G_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsDrawTriangle_G_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsFillTriangle_G_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsFillTriangle_G_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsDrawPolygon_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawPolygon_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillPolygon_G_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillPolygon_G_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

/* 2-D DRAWING FUNCTIONS WITH ALPHA BLENDING AND GOURAUD SHADING */

mlib_status mlib_GraphicsDrawLine_BG_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLine_BG_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_BG_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_BG_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_BG_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_BG_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_BG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_BG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH Z BUFFERING */

mlib_status mlib_GraphicsDrawLine_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLine_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolyline_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolyline_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangle_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangle_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangle_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangle_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolygon_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolygon_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillPolygon_Z_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillPolygon_Z_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

/* 2-D DRAWING FUNCTIONS WITH ALPHA BLENDING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLine_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLine_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_BZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_BZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING AND GOURAUD SHADING */

mlib_status mlib_GraphicsDrawLine_AG_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c1,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLine_AG_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c1,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolyline_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawPolyline_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangle_AG_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsDrawTriangle_AG_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsFillTriangle_AG_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsFillTriangle_AG_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsDrawPolygon_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawPolygon_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillPolygon_AG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillPolygon_AG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c);

/*
 * 2-D DRAWING FUNCTIONS WITH ANTIALIASING, ALPHA BLENDING AND
 * GOURAUD SHADING
 */

mlib_status mlib_GraphicsDrawLine_ABG_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLine_ABG_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_ABG_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_ABG_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_ABG_8(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_ABG_32(
    mlib_image *buffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_ABG_8(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_ABG_32(
    mlib_image *buffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLine_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawLine_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolyline_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolyline_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangle_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawTriangle_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangle_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c);

mlib_status mlib_GraphicsFillTriangle_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolygon_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsDrawPolygon_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillPolygon_AZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

mlib_status mlib_GraphicsFillPolygon_AZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING, ALPHA BLENDING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLine_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLine_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_ABZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_ABZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    mlib_s32 c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH GOURAUD SHADING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLine_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c1,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLine_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c1,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolyline_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawPolyline_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangle_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsDrawTriangle_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsFillTriangle_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsFillTriangle_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsDrawPolygon_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawPolygon_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillPolygon_GZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillPolygon_GZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

/* 2-D DRAWING FUNCTIONS WITH ALPHA BLENDING, GOURAUD SHADING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLine_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLine_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_BGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_BGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

/* 2-D DRAWING FUNCTIONS WITH ANTIALIASING, GOURAUD SHADING AND Z BUFFERING */

mlib_status mlib_GraphicsDrawLine_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c1,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawLine_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c1,
    mlib_s32 c2);

mlib_status mlib_GraphicsDrawPolyline_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawPolyline_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawTriangle_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsDrawTriangle_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsFillTriangle_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsFillTriangle_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3);

mlib_status mlib_GraphicsDrawPolygon_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsDrawPolygon_AGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillPolygon_AGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c);

mlib_status mlib_GraphicsFillPolygon_AGZ_32(
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

mlib_status mlib_GraphicsDrawLine_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawLine_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolyline_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawTriangle_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsFillTriangle_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    mlib_s16 x1,
    mlib_s16 y1,
    mlib_s16 z1,
    mlib_s16 x2,
    mlib_s16 y2,
    mlib_s16 z2,
    mlib_s16 x3,
    mlib_s16 y3,
    mlib_s16 z3,
    mlib_s32 c1,
    mlib_s32 c2,
    mlib_s32 c3,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsDrawPolygon_ABGZ_32(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_ABGZ_8(
    mlib_image *buffer,
    mlib_image *zbuffer,
    const mlib_s16 *x,
    const mlib_s16 *y,
    const mlib_s16 *z,
    mlib_s32 npoints,
    const mlib_s32 *c,
    mlib_s32 a);

mlib_status mlib_GraphicsFillPolygon_ABGZ_32(
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

#endif /* _MLIB_GRAPHICS_PROTO_H */
