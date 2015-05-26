/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library

   Copyright (C) 2000 Helix Code, Inc.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHcANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef _HTML_SELECTION_H_
#define _HTML_SELECTION_H_

#include "htmltypes.h"

void      html_engine_select_interval                (HTMLEngine   *e,
						      HTMLInterval *i);
void      html_engine_select_region                  (HTMLEngine   *e,
						      gint          x1,
						      gint          y1,
						      gint          x2,
						      gint          y2);
void      html_engine_select_word                    (HTMLEngine   *e);
void      html_engine_select_line                    (HTMLEngine   *e);
void      html_engine_select_all                     (HTMLEngine   *e);
void      html_engine_unselect_all                   (HTMLEngine   *e);
void      html_engine_clear_selection                (HTMLEngine   *e);
void      html_engine_disable_selection              (HTMLEngine   *e);
gchar    *html_engine_get_selection_string           (HTMLEngine   *e);
gboolean  html_engine_is_selection_active            (HTMLEngine   *e);
gboolean  html_engine_point_in_selection             (HTMLEngine   *e,
						      HTMLObject   *obj,
						      guint         offset);
void      html_engine_activate_selection             (HTMLEngine   *e,
						      guint32       time);
void      html_engine_deactivate_selection           (HTMLEngine   *e);
void      html_engine_update_selection_active_state  (HTMLEngine   *e,
						      guint32       time);
void      html_engine_block_selection                (HTMLEngine   *e);
void      html_engine_unblock_selection              (HTMLEngine   *e);
gboolean  html_selection_word                        (gunichar      uc);
gboolean  html_selection_spell_word                  (gunichar      uc,
						      gboolean     *cited);

#endif
