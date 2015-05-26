/*
 * GNOME Speech - Speech services for the GNOME desktop
 *
 * Copyright 2002 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * speaker.h: definition of the SynthesisDriver object.  This object
 *                    provides convenience functions and implementations of
 *                    some methods which are defined in the GNOME Speech
 *		    interface.  the purpose of this object is to simplify
 *		    GNOME Speech TTS driver development.  (implementation in
 *                  synthesisdriver.c)
 *
 */

#ifndef _SPEAKER_H_
#define _SPEAKER_H_


#include <bonobo/bonobo-object.h>
#include <gnome-speech/GNOME_Speech.h>


#define SPEAKER_TYPE        (speaker_get_type ())
#define SPEAKER(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), SPEAKER_TYPE, Speaker))
#define SPEAKER_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), SPEAKER_TYPE, SpeakerClass))
#define IS_SPEAKER(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), SPEAKER_TYPE))
#define IS_SPEAKER_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), SPEAKER_TYPE))
#define SPEAKER_GET_CLASS(o)           (G_TYPE_INSTANCE_GET_CLASS ((o), SPEAKER_TYPE, SpeakerClass))


/*
 *
 * Structure definiing index queue entry.  there should be a cleaner
 * way to do this than putting it here, but...
 *
 */

typedef struct {
	BonoboObject parent;

	/* Pointer to the DectalkSynthesisDriver */

	GObject *driver;
	GNOME_Speech_SpeechCallback cb;

	/* Speech Parameters */

	GSList *parameters;
	gboolean parameter_refresh;
} Speaker;

typedef struct {
	BonoboObjectClass parent_class;
	POA_GNOME_Speech_Speaker__epv epv;
} SpeakerClass;

typedef gboolean (*parameter_set_func) (Speaker *s,
					gdouble new_value);


GType
speaker_get_type   (void);
void
speaker_add_parameter (Speaker *s,
		       const gchar *name,
		       gdouble min,
		       gdouble current,
		       gdouble max,
		       parameter_set_func set_func);
void
speaker_add_parameter_value_description (Speaker *s,
					 const gchar *name,
					 gdouble value,
					 gchar *description);
gboolean
speaker_set_parameter (Speaker *s,
		       gchar *name,
		       gdouble value);
gboolean
speaker_refresh_parameters (Speaker *s);
gboolean
speaker_needs_parameter_refresh (Speaker *s);

#endif /* _SPEAKER_H_ */
