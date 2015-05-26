/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.

    Copyright (C) 2000 Helix Code, Inc.

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

    Author: Ettore Perazzoli <ettore@helixcode.com>
*/

#ifndef _HTMLENGINE_SAVE_H
#define _HTMLENGINE_SAVE_H

#include "gtkhtml-enums.h"
#include "htmltypes.h"


struct _HTMLEngineSaveState {
	HTMLEngine *engine;
	HTMLEngineSaveReceiverFn receiver;
	guint br_count;
	const gchar *save_data_class_name;
	HTMLObject *save_data_object;
	GSList *data_to_remove;

	guint error : 1;
	guint inline_frames : 1;
	guint last_level;

	gpointer user_data;
};


/* Entity encoding.  This is used by the HTML objects to output stuff through
   entity-based encoding.  */
gboolean             html_engine_save_encode               (HTMLEngineSaveState       *state,
							    const gchar               *buffer,
							    guint                      length);
gboolean             html_engine_save_encode_string        (HTMLEngineSaveState       *state,
							    const gchar               *s);

/* Output function (no encoding).  This is used for tags and other things that
   must not be entity-encoded.  */
gboolean             html_engine_save_output_stringv       (HTMLEngineSaveState       *state,
							    const gchar               *format,
							    va_list                    ap);
gboolean             html_engine_save_output_string        (HTMLEngineSaveState       *state,
							    const gchar               *format,
							    ...);

/* Saving a whole tree.  */
gboolean             html_engine_save                      (HTMLEngine                *engine,
							    HTMLEngineSaveReceiverFn   receiver,
							    gpointer                   user_data);
gboolean             html_engine_save_plain                (HTMLEngine                *engine,
							    HTMLEngineSaveReceiverFn   receiver,
							    gpointer                   user_data);
void                 html_engine_save_buffer_free          (HTMLEngineSaveState       *state);
guchar              *html_engine_save_buffer_peek_text     (HTMLEngineSaveState       *state);
HTMLEngineSaveState *html_engine_save_buffer_new           (HTMLEngine                *engine,
							    gboolean                   inline_frames);
gchar               *html_engine_save_get_sample_body      (HTMLEngine                *e,
							    HTMLObject                *o);
const gchar         *html_engine_save_get_paragraph_align  (GtkHTMLParagraphAlignment  align);
const gchar         *html_engine_save_get_paragraph_style  (GtkHTMLParagraphStyle      style);
gchar               *html_encode_entities                  (const gchar               *input,
							    guint                      len,
							    guint                     *encoded_len_return);
gint                 html_engine_save_string_append_nonbsp (GString *out, const guchar *s, guint length);
#endif
