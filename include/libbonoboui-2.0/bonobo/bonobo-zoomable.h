/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 *  Bonobo::Zoomable - zoomable interface for Controls.
 *
 *  Authors: Maciej Stachowiak <mjs@eazel.com>
 *           Martin Baulig <baulig@suse.de>
 *
 *  Copyright (C) 2000 Eazel, Inc.
 *                2000 SuSE GmbH.
 */

#ifndef _BONOBO_ZOOMABLE_H_
#define _BONOBO_ZOOMABLE_H_

#include <bonobo/bonobo-object.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_ZOOMABLE        (bonobo_zoomable_get_type ())
#define BONOBO_ZOOMABLE(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), BONOBO_TYPE_ZOOMABLE, BonoboZoomable))
#define BONOBO_ZOOMABLE_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), BONOBO_TYPE_ZOOMABLE, BonoboZoomableClass))
#define BONOBO_IS_ZOOMABLE(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), BONOBO_TYPE_ZOOMABLE))
#define BONOBO_IS_ZOOMABLE_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), BONOBO_TYPE_ZOOMABLE))
#define BONOBO_ZOOMABLE_GET_CLASS(o)(G_TYPE_INSTANCE_GET_CLASS ((o), BONOBO_TYPE_ZOOMABLE, BonoboZoomableClass))

typedef struct _BonoboZoomablePrivate	BonoboZoomablePrivate;

typedef struct {
        BonoboObject		object;

	BonoboZoomablePrivate	*priv;
} BonoboZoomable;

typedef struct {
	BonoboObjectClass	parent;

	POA_Bonobo_Zoomable__epv epv;

	void (*set_frame)	(BonoboZoomable *zoomable);
	void (*set_zoom_level)	(BonoboZoomable *zoomable,
				 CORBA_float     zoom_level);

	void (*zoom_in)		(BonoboZoomable *zoomable);
	void (*zoom_out)	(BonoboZoomable *zoomable);
	void (*zoom_to_fit)	(BonoboZoomable *zoomable);
	void (*zoom_to_default)	(BonoboZoomable *zoomable);

	gpointer dummy[4];
} BonoboZoomableClass;

GType		 bonobo_zoomable_get_type                       (void) G_GNUC_CONST;

BonoboZoomable	*bonobo_zoomable_new				(void);

void		 bonobo_zoomable_set_parameters			(BonoboZoomable	*zoomable,
								 float           zoom_level,
								 float		 min_zoom_level,
								 float		 max_zoom_level,
								 gboolean	 has_min_zoom_level,
								 gboolean	 has_max_zoom_level);

void		 bonobo_zoomable_set_parameters_full		(BonoboZoomable	*zoomable,
								 float           zoom_level,
								 float		 min_zoom_level,
								 float		 max_zoom_level,
								 gboolean	 has_min_zoom_level,
								 gboolean	 has_max_zoom_level,
								 gboolean	 is_continuous,
								 CORBA_float    *preferred_zoom_levels,
								 const gchar   **preferred_zoom_level_names,
								 gint		 num_preferred_zoom_levels);
void             bonobo_zoomable_add_preferred_zoom_level       (BonoboZoomable *zoomable,
                                                                 CORBA_float     zoom_level,
                                                                 const gchar    *zoom_level_name);

void		 bonobo_zoomable_report_zoom_level_changed	(BonoboZoomable	   *zoomable,
								 float		    new_zoom_level,
								 CORBA_Environment *opt_ev);
void		 bonobo_zoomable_report_zoom_parameters_changed	(BonoboZoomable    *zoomable,
								 CORBA_Environment *opt_ev);


G_END_DECLS

#endif /* _BONOBO_ZOOMABLE_H_ */
