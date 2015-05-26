/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-file-selection.h
 * Copyright 2000, 2001, Ximian, Inc.
 *
 * Authors:
 *   Chris Lahey <clahey@ximian.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License, version 2, as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef __E_FILE_SELECTION_H__
#define __E_FILE_SELECTION_H__

#include <gtk/gtkfilesel.h>

#ifdef __cplusplus
extern "C" {
#pragma }
#endif /* __cplusplus */

/* EFileSelection - A class derived from FileSelection for the purpose of adding
 * FileSelection hacks.
 */

#define E_FILE_SELECTION_TYPE			(e_file_selection_get_type ())
#define E_FILE_SELECTION(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), E_FILE_SELECTION_TYPE, EFileSelection))
#define E_FILE_SELECTION_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), E_FILE_SELECTION_TYPE, EFileSelectionClass))
#define E_IS_FILE_SELECTION(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), E_FILE_SELECTION_TYPE))
#define E_IS_FILE_SELECTION_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((obj), E_FILE_SELECTION_TYPE))

typedef struct _EFileSelection       EFileSelection;
typedef struct _EFileSelectionClass  EFileSelectionClass;
typedef struct _EFileSelectionPrivate  EFileSelectionPrivate;

struct _EFileSelection
{
	GtkFileSelection  parent;

	EFileSelectionPrivate *priv;
};

struct _EFileSelectionClass
{
	GtkFileSelectionClass parent_class;
};


GtkType     e_file_selection_get_type       (void);
GtkWidget  *e_file_selection_new            (char           *title);
gchar     **e_file_selection_get_filenames  (EFileSelection *filesel);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __E_FILE_SELECTION_H__ */
