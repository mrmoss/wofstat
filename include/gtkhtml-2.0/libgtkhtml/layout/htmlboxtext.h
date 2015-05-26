/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000-2001 CodeFactory AB
   Copyright (C) 2000-2001 Jonas Borgström <jonas@codefactory.se>
   Copyright (C) 2000-2001 Anders Carlsson <andersca@codefactory.se>
   
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

#ifndef __HTMLBOXTEXT_H__
#define __HTMLBOXTEXT_H__

#include <glib.h>
#include "htmlbox.h"

G_BEGIN_DECLS

typedef struct _HtmlBoxText HtmlBoxText;
typedef struct _HtmlBoxTextClass HtmlBoxTextClass;

#define HTML_TYPE_BOX_TEXT (html_box_text_get_type ())
#define HTML_BOX_TEXT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_TEXT, HtmlBoxText))
#define HTML_BOX_TEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_TEXT, HtmlBoxTextClasss))
#define HTML_IS_BOX_TEXT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_TEXT))
#define HTML_IS_BOX_TEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_TEXT))

GType    html_box_text_get_type (void);

HtmlBox *html_box_text_new      (gboolean master);

void     html_box_text_set_text              (HtmlBoxText *box, gchar *text);
void     html_box_text_free_relayout         (HtmlBoxText *box);
gchar *  html_box_text_get_text              (HtmlBoxText *box, int *text_len);
gboolean html_box_text_is_master             (HtmlBoxText *box);
gint     html_box_text_get_len               (HtmlBoxText *box);
void     html_box_text_set_generated_content (HtmlBoxText *text, gchar *txt);


typedef enum {
	HTML_BOX_TEXT_SELECTION_NONE = 0,
	HTML_BOX_TEXT_SELECTION_START,
	HTML_BOX_TEXT_SELECTION_END,
	HTML_BOX_TEXT_SELECTION_FULL,
	HTML_BOX_TEXT_SELECTION_BOTH
} HtmlBoxTextSelection;

gint html_box_text_get_index (HtmlBoxText *text, gint x_pos);
void html_box_text_get_character_extents (HtmlBoxText *text, gint index, GdkRectangle *rect);
void html_box_text_set_selection (HtmlBoxText *text, HtmlBoxTextSelection, gint start_index, gint end_index);

typedef struct _HtmlBoxTextMaster HtmlBoxTextMaster;
typedef struct _HtmlBoxTextItemData HtmlBoxTextItemData;

struct _HtmlBoxText {
	HtmlBox parent_object;

	HtmlBoxTextMaster *master; /* NULL for slave boxes */
	
	gboolean generated_content: 1;
	gboolean forced_newline: 1;
        guint selection: 3;
	gint16 sel_start_index;
	gint16 sel_end_index;

	guchar *canon_text; /* Pointer into one array owned by master */
	gint length; /* canon text length in bytes */

	HtmlBoxTextItemData *item_data; /* Which item is this box from */
	guint item_offset; /* offset into item for wrapping */
	
	PangoGlyphString *glyphs;
	guint ascent, descent;
};

struct _HtmlBoxTextClass {
	HtmlBoxClass parent_class;
};

G_END_DECLS

#endif /* __HTMLBOXTEXT_H__ */
