/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the KDE libraries

   Copyright (C) 1997 Martin Jones (mjones@kde.org)
   Copyright (C) 1997 Torben Weis (weis@kde.org)
   Copyright (C) 1999, 2000 Helix Code, Inc.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/
#ifndef _HTMLIMAGE_H_
#define _HTMLIMAGE_H_

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk-pixbuf/gdk-pixbuf-loader.h>
#include "htmlobject.h"

#define HTML_IMAGE_FACTORY(x) ((HTMLImageFactory *)(x))
#define HTML_IMAGE_POINTER(x) ((HTMLImagePointer *)(x))
#define HTML_IS_IMAGE(x) (HTML_CHECK_TYPE ((x), HTML_TYPE_IMAGE))

struct _HTMLImagePointer {
	gint refcount;
	gchar *url;
	GdkPixbufLoader *loader;
	GdkPixbufAnimation *animation;
	GdkPixbufAnimationIter *iter;
	GSList *interests; /* A list of HTMLImage's, or a NULL pointer for the background pixmap */
	HTMLImageFactory *factory;
	gint stall;
	guint stall_timeout;
	guint animation_timeout;
};

#define HTML_IMAGE(x) ((HTMLImage *)(x))
#define HTML_IMAGE_POINTER(x) ((HTMLImagePointer *)(x))

struct _HTMLImage {
	HTMLObject object;
        HTMLImagePointer *image_ptr;

	HTMLColor *color;

	guint have_color: 1;

	gint8 border;

	gint16 specified_width;
	gint16 specified_height;
	gboolean percent_width  : 1;
	gboolean percent_height : 1;
	gboolean ismap : 1;
	gboolean animation_active : 1;

	gint8 hspace;
	gint8 vspace;

	HTMLVAlignType valign;

	gchar *url;
	gchar *target;
	gchar *alt;
	gchar *usemap;
	gchar *final_url;	
};

struct _HTMLImageClass {
	HTMLObjectClass parent_class;
};


extern HTMLImageClass image_class;


void        html_image_type_init          (void);
void        html_image_class_init         (HTMLImageClass   *klass,
					   HTMLType          type,
					   guint             object_size);
void        html_image_init               (HTMLImage        *image,
					   HTMLImageClass   *klass,
					   HTMLImageFactory *imf,
					   const gchar      *filename,
					   const gchar      *url,
					   const gchar      *target,
					   gint16            width,
					   gint16            height,
					   gboolean          percent_width,
					   gboolean          percent_height,
					   gint8             border,
					   HTMLColor        *border_color,
					   HTMLVAlignType    valign,
					   gboolean          reload);
HTMLObject *html_image_new                (HTMLImageFactory *imf,
					   const gchar      *filename,
					   const gchar      *url,
					   const gchar      *target,
					   gint16            width,
					   gint16            height,
					   gboolean          percent_width,
					   gboolean          percent_height,
					   gint8             border,
					   HTMLColor        *border_color,
					   HTMLVAlignType    valign,
					   gboolean          reload);
void        html_image_set_size           (HTMLImage        *image,
					   gint              w,
					   gint              h,
					   gboolean          pw,
					   gboolean          ph);
void        html_image_set_spacing        (HTMLImage        *image,
					   gint              hspace,
					   gint              vspace);
void        html_image_set_url            (HTMLImage        *image,
					   const gchar      *url);
void        html_image_set_valign         (HTMLImage        *image,
					   HTMLVAlignType    valign);
void        html_image_set_border         (HTMLImage        *image,
					   gint              border);
void        html_image_set_alt            (HTMLImage        *image,
					   gchar            *alt);
void        html_image_set_map            (HTMLImage        *image,
					   gchar            *mapuri,
					   gboolean         ismap);
gchar      *html_image_resolve_image_url  (GtkHTML          *html,
					   gchar            *image_url);

void        html_image_edit_set_url        (HTMLImage       *image,
					    const gchar     *url);
guint       html_image_get_actual_width    (HTMLImage       *image,
					    HTMLPainter     *painter);
guint       html_image_get_actual_height   (HTMLImage       *image,
					    HTMLPainter     *painter);
/* FIXME move to htmlimagefactory.c */
HTMLImageFactory *html_image_factory_new                    (HTMLEngine       *e);
void              html_image_factory_free                   (HTMLImageFactory *factory);
void              html_image_factory_cleanup                (HTMLImageFactory *factory); /* Does gc etc. - removes unused image entries */
void              html_image_factory_stop_animations        (HTMLImageFactory *factory);
void              html_image_factory_start_animations       (HTMLImageFactory *factory);
void              html_image_factory_set_animate            (HTMLImageFactory *factory,
						             gboolean animate);
gboolean          html_image_factory_get_animate            (HTMLImageFactory *factory);
void              html_image_factory_deactivate_animations  (HTMLImageFactory *factory);
HTMLImagePointer *html_image_factory_register               (HTMLImageFactory *factory,
							     HTMLImage        *i,
							     const char       *filename,
							     gboolean          reload);
void              html_image_factory_unregister             (HTMLImageFactory *factory,
							     HTMLImagePointer *pointer,
							     HTMLImage        *i);
void              html_image_factory_move_images            (HTMLImageFactory *dst,
							     HTMLImageFactory *src);
void              html_image_factory_ref_all_images         (HTMLImageFactory *factory);
void              html_image_factory_unref_all_images       (HTMLImageFactory *factory);
void              html_image_factory_ref_image_ptr          (HTMLImageFactory *factory,
							     const gchar      *url);
void              html_image_factory_unref_image_ptr        (HTMLImageFactory *factory,
							     const gchar      *url);
#endif /* _HTMLIMAGE_H_ */
