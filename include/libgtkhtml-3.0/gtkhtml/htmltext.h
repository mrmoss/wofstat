/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the KDE libraries

   Copyright (C) 1997 Martin Jones (mjones@kde.org)
   Copyright (C) 1997 Torben Weis (weis@kde.org)
   Copyright (C) 1999, 2000, 2001 Helix Code, Inc.
   
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
#ifndef _HTMLTEXT_H_
#define _HTMLTEXT_H_

#include "htmlobject.h"

#define HTML_TEXT(x) ((HTMLText *)(x))
#define HTML_TEXT_CLASS(x) ((HTMLTextClass *)(x))
#define HTML_IS_TEXT(x) (HTML_CHECK_TYPE ((x), HTML_TYPE_TEXT))

struct _SpellError {
	guint off;
	guint len;
};

struct _HTMLPangoAttrFontSize {
        PangoAttrInt attr_int;
	GtkHTMLFontStyle style;
};

struct _HTMLText {
	HTMLObject object;
	
	gchar   *text;
	guint    text_len;
	guint	 text_bytes;
	guint   *word_width;
	guint    words;

	PangoAttrList    *attr_list;
	PangoAttrList    *extra_attr_list;
	GtkHTMLFontStyle  font_style;
	HTMLFontFace     *face;
	HTMLColor        *color;

	guint select_start;
	guint select_length;

	GList *spell_errors;
	GList *items;
};

struct _HTMLTextClass {
	HTMLObjectClass object_class;

        void         	   (* queue_draw)     (HTMLText *text, HTMLEngine *engine,
					       guint offset, guint len);

	GtkHTMLFontStyle   (* get_font_style) (const HTMLText *text);
	HTMLColor        * (* get_color)      (HTMLText *text, HTMLPainter *painter);

	void               (* set_font_style) (HTMLText *text, HTMLEngine *engine, GtkHTMLFontStyle style);
	void               (* set_color)      (HTMLText *text, HTMLEngine *engine, HTMLColor *color);
};

extern HTMLTextClass html_text_class;

void              html_text_type_init                    (void);
void              html_text_class_init                   (HTMLTextClass    *klass,
							  HTMLType          type,
							  guint             object_size);
void              html_text_init                         (HTMLText         *text_object,
							  HTMLTextClass    *klass,
							  const gchar      *text,
							  gint              len,
							  GtkHTMLFontStyle  font_style,
							  HTMLColor        *color);
HTMLObject       *html_text_new                          (const gchar      *text,
							  GtkHTMLFontStyle  font_style,
							  HTMLColor        *color);
HTMLObject       *html_text_new_with_len                 (const gchar      *text,
							  gint              len,
							  GtkHTMLFontStyle  font_style,
							  HTMLColor        *color);
void              html_text_queue_draw                   (HTMLText         *text,
							  HTMLEngine       *engine,
							  guint             offset,
							  guint             len);
GtkHTMLFontStyle  html_text_get_font_style               (const HTMLText   *text);
HTMLColor        *html_text_get_color                    (HTMLText         *text,
							  HTMLPainter      *painter);
void              html_text_set_font_style               (HTMLText         *text,
							  HTMLEngine       *engine,
							  GtkHTMLFontStyle  style);
void              html_text_set_color                    (HTMLText         *text,
							  HTMLEngine       *engine,
							  HTMLColor        *color);
void              html_text_append                       (HTMLText         *text,
							  const gchar      *str,
							  gint              len);
void              html_text_set_text                     (HTMLText         *text,
							  const gchar      *new_text);
void              html_text_set_font_face                (HTMLText         *text,
							  HTMLFontFace     *face);
gint              html_text_get_nb_width                 (HTMLText         *text,
							  HTMLPainter      *painter,
							  gboolean          begin);
guint             html_text_get_bytes                    (HTMLText         *text);
guint             html_text_get_index                    (HTMLText         *text,
							  guint             offset);
gunichar          html_text_get_char                     (HTMLText         *text,
							  guint             offset);
gchar            *html_text_get_text                     (HTMLText         *text,
							  guint             offset);
GList *           html_text_get_items                    (HTMLText         *text,
							  HTMLPainter      *painter);
void              html_text_spell_errors_clear           (HTMLText         *text);
void              html_text_spell_errors_clear_interval  (HTMLText         *text,
							  HTMLInterval     *i);
void              html_text_spell_errors_add             (HTMLText         *text,
							  guint             off,
							  guint             len);
gboolean          html_text_magic_link                   (HTMLText         *text,
							  HTMLEngine       *engine,
							  guint             offset);
gint              html_text_trail_space_width            (HTMLText         *text,
							  HTMLPainter      *painter);
void              html_text_request_word_width           (HTMLText         *text,
							  HTMLPainter      *painter);
gboolean          html_text_convert_nbsp                 (HTMLText         *text,
							  gboolean          free_text);
gint              html_text_get_line_offset              (HTMLText         *text,
							  HTMLPainter      *painter);
gint              html_text_text_line_length             (const gchar      *text,
							  gint             *line_offset,
							  guint             len,
							  gint             *tabs);
GtkHTMLFontStyle  html_text_get_style_conflicts          (HTMLText           *text,
							  GtkHTMLFontStyle    style,
							  gint                start_index,
							  gint                end_index);

void              html_text_free_attrs                   (GSList             *attrs);

HTMLTextSlave    *html_text_get_slave_at_offset          (HTMLObject         *o,
                                                          gint                offset);

/*
 * protected
 */
typedef HTMLObject * (* HTMLTextHelperFunc)       (HTMLText *, gint begin, gint end);
HTMLObject *html_text_op_copy_helper    (HTMLText           *text,
					 GList              *from,
					 GList              *to,
					 guint              *len,
					 HTMLTextHelperFunc  f);
HTMLObject *html_text_op_cut_helper     (HTMLText           *text,
					 HTMLEngine         *e,
					 GList              *from,
					 GList              *to,
					 GList              *left,
					 GList              *right,
					 guint              *len,
					 HTMLTextHelperFunc  f);
void        html_text_clear_word_width  (HTMLText           *text);

#endif /* _HTMLTEXT_H_ */
