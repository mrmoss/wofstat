/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _MLIB_VOLUME_TYPES_H
#define	_MLIB_VOLUME_TYPES_H

#pragma ident	"@(#)mlib_volume_types.h	9.1	05/11/23 SMI"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	void **slices;
	mlib_s32 xsize;
	mlib_s32 ysize;
	mlib_s32 *offsets;
	mlib_s32 nslices;
	mlib_s32 nregions;
	mlib_s32 *zindices;
	mlib_d64 *zcoords;
	mlib_d64 *zsrates;
} mlib_genvolume;

typedef struct
{
	void *voxels;
	mlib_s32 xysize;
	mlib_s32 zsize;
} mlib_blkvolume;

typedef struct
{
	void **results;
	mlib_s32 nrays;
	mlib_d64 **starts;
	mlib_d64 **incs;
	mlib_s32 *nsteps;
	mlib_d64 *image_z;
	mlib_d64 *im_incs;
} mlib_rays;

#ifdef __cplusplus
}
#endif

#endif /* _MLIB_VOLUME_TYPES_H */
