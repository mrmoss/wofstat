/*
 * COPYRIGHT NOTICE
 * Copyright (c) 1990, 1991, 1992, 1993 Open Software Foundation, Inc.
 * ALL RIGHTS RESERVED (MOTIF).  See the file named COPYRIGHT.MOTIF
 * for the full copyright text.
 *
 */

/*
 *	ImageCachI.h	version 1.6, last updated 02/07/16.
 */

#ifndef _XmImageCacheI_h
#define _XmImageCacheI_h

#ifndef MOTIF12_HEADERS 

#include <Xm/XmP.h>

/* this name is used by XmeGetPixmapData to cache a pixmap in the
   pixmap cache with no associated name. _XmCachePixmap knows about it
   and will not add this one in the pixmap_data cache because it is a
   _name_ based pixmap cache used during conversion */
#define DIRECT_PIXMAP_CACHED ""

#ifdef __cplusplus
extern "C" {
#endif

/********    Private Function Declarations for ImageCache.c    ********/

extern Boolean _Xm21InstallImage(XImage *, char *, int, int);
extern Boolean _Xm21GetImage(Screen *, char *, XImage **);
extern Boolean _XmCachePixmap(Pixmap, Screen *, char *, Pixel, Pixel,
										int, Dimension, Dimension);
extern Pixmap _XmGetColoredPixmap(Screen *, char *, XmAccessColorData, int, Boolean);

extern Boolean _Xm21GetPixmapData(
		   Screen *screen,
		   Pixmap pixmap,
		   char **image_name,
		   int *depth,
		   Pixel *foreground,
		   Pixel *background,
		   int *hot_x,
		   int *hot_y,
		   unsigned int *width,
		   unsigned int *height) ;
extern Boolean _Xm21InImageCache(
			       String image_name);

extern Pixmap _XmGetScaledPixmap(Screen *, Widget, char *, XmAccessColorData,
											int, Boolean, double);

extern void _XmPutScaledImage (    
    Display*		 display ,
    Drawable		 d ,
    GC			 gc ,
    XImage*		 src_image ,
    int			 src_x ,
    int			 src_y ,
    int			 dest_x ,
    int			 dest_y ,
    unsigned int	 src_width ,
    unsigned int	 src_height, 
    unsigned int	 dest_width ,
    unsigned int	 dest_height);

extern void _XmCleanPixmapCache(Screen * screen, Widget shell);

/* for Xm.h */
extern Pixmap XmGetScaledPixmap(
    Widget widget,
    char *image_name,
    Pixel foreground,
    Pixel background,
    int depth,
    double scaling_ratio);

extern Boolean _XmInImageCache(Screen *, char *);


/********    End Private Function Declarations    ********/

#ifdef __cplusplus
}  /* Close scope of 'extern "C"' declaration which encloses file. */
#endif

#else /* MOTIF12_HEADERS */

/* 
 * @OSF_COPYRIGHT@
 * (c) Copyright 1990, 1991, 1992, 1993, 1994 OPEN SOFTWARE FOUNDATION, INC.
 * ALL RIGHTS RESERVED
 *  
*/ 
/*
 * HISTORY
 * Motif Release 1.2.5
*/
/************************************************************************* 
 **  (c) Copyright 1993, 1994 Hewlett-Packard Company
 **  (c) Copyright 1993, 1994 International Business Machines Corp.
 **  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
 **  (c) Copyright 1993, 1994 Novell, Inc.
 *************************************************************************/
#ifdef REV_INFO
#ifndef lint
static char rcsid[] = "$XConsortium: ImageCachI.h /main/cde1_maint/2 1995/08/18 19:07:38 drk $"
#endif
#endif

#include <Xm/XmP.h>
#ifdef __cplusplus
extern "C" {
#endif

/********    Private Function Declarations for Pixmap.c   ********/
extern Boolean _XmGetPixmapData( 
                        Screen *screen,
                        Pixmap pixmap,
                        char **image_name,
                        int *depth,
                        Pixel *foreground,
                        Pixel *background,
                        int *hot_x,
                        int *hot_y,
                        unsigned int *width,
                        unsigned int *height) ;
extern Boolean _XmInstallImage(
		        XImage *image,
		        char *image_name,
		        int hot_x,
		        int hot_y);
extern Boolean _XmGetImage(
		        Screen *screen,
		        char *image_name,
			XImage **imageRtn);
extern Boolean _XmInImageCache( 
                        char *image_name) ;
extern Pixmap _XmGetPixmap( 
                        Screen *screen,
                        char *image_name,
                        int depth,
                        Pixel foreground,
                        Pixel background);
extern Boolean _XmInstallPixmap( 
                        Pixmap pixmap,
                        Screen *screen,
                        char *image_name,
                        Pixel foreground,
                        Pixel background) ;
extern Boolean _XmInstallPixmapByDepth( Pixmap pixmap,
                                  Screen *screen,
				  char *image_name,
				  Pixel foreground,
				  Pixel background,
				  int depth);

/********    End Private Function Declarations    ********/


#ifdef __cplusplus
}  /* Close scope of 'extern "C"' declaration which encloses file. */
#endif


#endif /* MOTIF12_HEADERS */

#endif /* _ImageCachI_h */
