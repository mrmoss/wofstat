#ifndef __GDK_MEDIALIB_H__
#define __GDK_MEDIALIB_H__

#include <config.h>

#ifdef USE_MEDIALIB
#include <mlib_image.h>
#include <mlib_video.h>

extern mlib_image *mlib_ImageSet (mlib_image *image, mlib_type type, 
                                  mlib_s32 channels, mlib_s32 width,
                                  mlib_s32 height, mlib_s32 stride,
                                  const void *data);

#include <gdktypes.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

gboolean _gdk_use_medialib (void);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* USE_MEDIALIB */

#endif /* __GDK_MEDIALIB_H__ */

