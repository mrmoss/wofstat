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

#ifndef _HTML_UNDO_ACTION_H
#define _HTML_UNDO_ACTION_H

#include "htmltypes.h"

/* #define UNDO_DEBUG */

#define HTML_UNDO_ACTION(x) ((HTMLUndoAction *) x)
struct _HTMLUndoAction {
	
	gchar *description;             /* A text description of the action, to be displayed in the menus.  */
	HTMLUndoFunc function;	        /* Function to call when the action is performed.  */
	HTMLUndoData *data;             /* Data to pass to the action function when it's called.  */
	guint position;                 /* Cursor position, to be set when the action is executed.  */
	guint position_after;           /* cursor position to go after undo action executed */

#ifdef UNDO_DEBUG
	gboolean is_level;
#endif
};

HTMLUndoAction *html_undo_action_new      (const gchar            *description,
					   HTMLUndoFunc            function,
					   HTMLUndoData           *data,
					   guint                   position,
					   guint                   position_after);
void            html_undo_action_destroy  (HTMLUndoAction         *action);

#endif /* _HTML_UNDO_ACTION_H */
