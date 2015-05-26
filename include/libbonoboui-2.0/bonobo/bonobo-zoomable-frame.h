/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 *  Bonobo::ZoomableFrame - container side part of Bonobo::Zoomable.
 *
 *  Authors: Maciej Stachowiak <mjs@eazel.com>
 *           Martin Baulig <baulig@suse.de>
 *
 *  Copyright (C) 2000 Eazel, Inc.
 *                2000 SuSE GmbH.
 */
#ifndef _BONOBO_ZOOMABLE_FRAME_H_
#define _BONOBO_ZOOMABLE_FRAME_H_

#include <bonobo/bonobo-object.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_ZOOMABLE_FRAME        (bonobo_zoomable_frame_get_type ())
#define BONOBO_ZOOMABLE_FRAME(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), BONOBO_TYPE_ZOOMABLE_FRAME, BonoboZoomableFrame))
#define BONOBO_ZOOMABLE_FRAME_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), BONOBO_TYPE_ZOOMABLE_FRAME, BonoboZoomableFrameClass))
#define BONOBO_IS_ZOOMABLE_FRAME(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), BONOBO_TYPE_ZOOMABLE_FRAME))
#define BONOBO_IS_ZOOMABLE_FRAME_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BONOBO_TYPE_ZOOMABLE_FRAME))

typedef struct _BonoboZoomableFramePrivate	BonoboZoomableFramePrivate;

typedef struct {
        BonoboObject			object;

	BonoboZoomableFramePrivate	*priv;
} BonoboZoomableFrame;

typedef struct {
	BonoboObjectClass		parent;

	POA_Bonobo_ZoomableFrame__epv   epv;

	void (*zoom_level_changed)	(BonoboZoomableFrame *zframe,
					 float zoom_level);
	void (*zoom_parameters_changed)	(BonoboZoomableFrame *zframe);

	gpointer dummy[2];
} BonoboZoomableFrameClass;

GType			 bonobo_zoomable_frame_get_type			(void) G_GNUC_CONST;

BonoboZoomableFrame	*bonobo_zoomable_frame_new			(void);
Bonobo_Zoomable          bonobo_zoomable_frame_get_zoomable             (BonoboZoomableFrame    *zframe);

float		 bonobo_zoomable_frame_get_zoom_level			(BonoboZoomableFrame	*zframe);

float		 bonobo_zoomable_frame_get_min_zoom_level		(BonoboZoomableFrame	*zframe);
float		 bonobo_zoomable_frame_get_max_zoom_level		(BonoboZoomableFrame	*zframe);
gboolean	 bonobo_zoomable_frame_has_min_zoom_level		(BonoboZoomableFrame	*zframe);
gboolean	 bonobo_zoomable_frame_has_max_zoom_level		(BonoboZoomableFrame	*zframe);
gboolean	 bonobo_zoomable_frame_is_continuous			(BonoboZoomableFrame	*zframe);

GList		*bonobo_zoomable_frame_get_preferred_zoom_levels	(BonoboZoomableFrame	*zframe);
GList		*bonobo_zoomable_frame_get_preferred_zoom_level_names	(BonoboZoomableFrame	*zframe);

void		 bonobo_zoomable_frame_set_zoom_level			(BonoboZoomableFrame	*zframe,
									 float			 zoom_level);

void		 bonobo_zoomable_frame_zoom_in				(BonoboZoomableFrame	*zframe);
void		 bonobo_zoomable_frame_zoom_out				(BonoboZoomableFrame	*zframe);
void		 bonobo_zoomable_frame_zoom_to_fit			(BonoboZoomableFrame	*zframe);
void		 bonobo_zoomable_frame_zoom_to_default			(BonoboZoomableFrame	*zframe);
void		 bonobo_zoomable_frame_bind_to_zoomable			(BonoboZoomableFrame	*zframe,
									 Bonobo_Zoomable	 zoomable,
									 CORBA_Environment      *opt_ev);

G_END_DECLS

#endif /* _BONOBO_ZOOMABLE_FRAME_H_ */

