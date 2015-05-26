/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2000-2001 CodeFactory AB
 * Copyright (C) 2000-2001 Anders Carlsson <andersca@codefactory.se>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __DOM_EVENT_H__
#define __DOM_EVENT_H__

#include <glib-object.h>
#include <libgtkhtml/dom/dom-types.h>
#include <libgtkhtml/dom/events/dom-eventtarget.h>

#define DOM_TYPE_EVENT             (dom_event_get_type ())
#define DOM_EVENT(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_EVENT, DomEvent))
#define DOM_EVENT_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_EVENT, DomEventClass))
#define DOM_IS_EVENT(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_EVENT))
#define DOM_IS_EVENT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_EVENT))
#define DOM_EVENT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_EVENT, DomEventClass))

enum {
	DOM_CAPTURING_PHASE = 1,
	DOM_AT_TARGET = 2,
	DOM_BUBBLING_PHASE = 3
};

struct _DomEvent {
	GObject parent;

	DomString *type;

	DomEventTarget *target;
	DomEventTarget *currentTarget;

	gushort eventPhase;
	
	DomBoolean bubbles;
	DomBoolean cancelable;
	DomTimeStamp timeStamp;

	/* To indicate if the event has been initialized or not */
	gboolean initialized;

	gboolean propagation_stopped;
	gboolean default_prevented;
};

struct _DomEventClass {
	GObjectClass parent_class;

};

GType dom_event_get_type (void);

DomString *dom_Event__get_type (DomEvent *event);
DomEventTarget *dom_Event__get_target (DomEvent *event);
DomEventTarget *dom_Event__get_currentTarget (DomEvent *event);
gushort dom_Event__get_eventPhase (DomEvent *event);
DomTimeStamp dom_Event__get_timeStamp (DomEvent *event);
void dom_Event_stopPropagation (DomEvent *event);
void dom_Event_preventDefault (DomEvent *event);

void dom_Event_initEvent (DomEvent *event, const DomString *eventTypeArg, DomBoolean canBubbleArg, DomBoolean cancelableArg);

#endif /* __DOM_EVENT_H__ */
