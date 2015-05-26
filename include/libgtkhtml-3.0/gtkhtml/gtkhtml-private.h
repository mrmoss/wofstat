/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.

    Copyright 1999, 2000 Helix Code, Inc.
    
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef _GTKHTML_PRIVATE_H
#define _GTKHTML_PRIVATE_H

#include <libgnomeprint/gnome-print.h>
#include <libgnomeprint/gnome-print-job.h>
#include <gtk/gtkimcontext.h>
#include <gtk/gtkwidget.h>
#include "gtkhtml-types.h"
#include "htmltypes.h"

struct _GtkHTMLPrivate {
	guint idle_handler_id;
	guint scroll_timeout_id;

	GtkHTMLParagraphStyle paragraph_style;
	guint paragraph_indentation;
	GtkHTMLParagraphAlignment paragraph_alignment;
	GtkHTMLFontStyle insertion_font_style;

	gboolean update_styles;

	gint selection_type;

	gchar *content_type;
	char  *base_url;

	GtkWidget *search_input_line;

	GnomePrintJob *print_master;

	guint notify_spell_id;

	GtkIMContext *im_context;
	gboolean need_im_reset;
	gint im_pre_len;
	gint im_pre_pos;
	GtkHTMLFontStyle im_orig_style;
	gboolean im_block_reset;

	HTMLObject *dnd_object;
	HTMLObject *dnd_real_object;
	gboolean    dnd_in_progress;
	gchar      *dnd_url;

	guint32     event_time;
	gboolean    selection_as_cite;

	gboolean    magic_links;
	gboolean    magic_smileys;
	gboolean    inline_spelling;
};

void  gtk_html_private_calc_scrollbars  (GtkHTML                *html,
					 gboolean               *changed_x,
					 gboolean               *changed_y);
void  gtk_html_editor_event_command     (GtkHTML                *html,
					 GtkHTMLCommandType      com_type,
					 gboolean                before);
void  gtk_html_editor_event             (GtkHTML                *html,
					 GtkHTMLEditorEventType  event,
					 GValue                 *args);
void  gtk_html_api_set_language         (GtkHTML                *html);
void  gtk_html_im_reset                 (GtkHTML                *html);
void  gtk_html_set_fonts                (GtkHTML                *html,
					 HTMLPainter            *painter);

#endif /* _GTKHTML_PRIVATE_H */
