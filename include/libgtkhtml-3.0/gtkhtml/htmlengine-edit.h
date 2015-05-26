/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.
    Copyright (C) 1999, 2000 Helix Code, Inc.
    Copyright (C) 2001 Ximian, Inc.

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

#ifndef _HTMLENGINE_EDIT_H
#define _HTMLENGINE_EDIT_H

#include <glib.h>

#include "htmlengine.h"
#include "htmlclueflow.h"
#include "gtkhtml.h"

void                       html_engine_undo                       (HTMLEngine                *e);
void                       html_engine_redo                       (HTMLEngine                *e);
void                       html_engine_set_mark                   (HTMLEngine                *e);
void                       html_engine_select_spell_word_editable (HTMLEngine                *e);
void                       html_engine_select_word_editable       (HTMLEngine                *e);
void                       html_engine_select_line_editable       (HTMLEngine                *e);
void                       html_engine_select_paragraph_editable  (HTMLEngine                *e);
void                       html_engine_select_paragraph_extended  (HTMLEngine                *e);
void                       html_engine_select_all_editable        (HTMLEngine                *e);
void                       html_engine_clipboard_push             (HTMLEngine                *e);
void                       html_engine_clipboard_pop              (HTMLEngine                *e);
void                       html_engine_clipboard_clear            (HTMLEngine                *e);
void                       html_engine_selection_push             (HTMLEngine                *e);
void                       html_engine_selection_pop              (HTMLEngine                *e);
gboolean                   html_engine_selection_stack_top         (HTMLEngine                *e,
								    gint                      *cpos,
								    gint                      *mpos);
gboolean                   html_engine_selection_stack_top_modify  (HTMLEngine                *e,
								    gint                       delta);
void                       html_engine_cut_and_paste_begin        (HTMLEngine                *e,
								   const gchar               *undo_op_name,
								   const gchar               *redo_op_name);
void                       html_engine_cut_and_paste_end          (HTMLEngine                *e);
void                       html_engine_cut_and_paste              (HTMLEngine                *e,
								   const gchar               *undo_op_name,
								   const gchar               *redo_op_name,
								   HTMLObjectForallFunc       iterator,
								   gpointer                   data);
void                       html_engine_spell_check_range          (HTMLEngine                *e,
								   HTMLCursor                *begin,
								   HTMLCursor                *end);
void                       html_engine_set_data_by_type           (HTMLEngine                *e,
								   HTMLType                   object_type,
								   const gchar               *key,
								   const gchar               *value);
void                       html_engine_ensure_editable            (HTMLEngine                *e);
HTMLObject                *html_engine_new_text_empty             (HTMLEngine                *e);
HTMLObject                *html_engine_new_text                   (HTMLEngine                *e,
								   const gchar               *text,
								   gint                       len);
HTMLObject *               html_engine_new_link                   (HTMLEngine                *e,
								   const gchar               *text,
								   gint                       len,
								   gchar                     *url);
gboolean                   html_engine_cursor_on_bop              (HTMLEngine                *e);
guint                      html_engine_get_indent                 (HTMLEngine                *e);
void                       html_engine_indent_paragraph           (HTMLEngine                *e);
void                       html_engine_indent_pre_line            (HTMLEngine                *e);
void                       html_engine_fill_pre_line              (HTMLEngine                *e);
void                       html_engine_space_and_fill_line        (HTMLEngine                *e);
void                       html_engine_break_and_fill_line        (HTMLEngine                *e);
gboolean                   html_engine_next_cell                  (HTMLEngine                *e,
								   gboolean                   create);
gboolean                   html_engine_prev_cell                  (HTMLEngine                *e);
void                       html_engine_set_title                  (HTMLEngine                *e,
								   const gchar               *title);
/*
  static (non instance) methods
*/
gboolean                   html_is_in_word                        (gunichar                   uc);
HTMLHAlignType             paragraph_alignment_to_html            (GtkHTMLParagraphAlignment  alignment);
void                       paragraph_style_to_clueflow_style      (GtkHTMLParagraphStyle      style,
								   HTMLClueFlowStyle         *flow_style,
								   HTMLListType              *item_type);
GtkHTMLParagraphAlignment  html_alignment_to_paragraph            (HTMLHAlignType             alignment);
GtkHTMLParagraphStyle      clueflow_style_to_paragraph_style      (HTMLClueFlowStyle          style,
								   HTMLListType               item_type);

#endif /* _HTMLENGINE_EDIT_H */
