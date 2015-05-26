/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library

   Copyright (C) 2000 Helix Code, Inc.
   Author:            Radek Doulik <rodo@helixcode.com>

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

#ifndef _GTK_HTML_TYPES_H_
#define _GTK_HTML_TYPES_H_

#include <libgnomeprint/gnome-print.h>
#include "gtkhtml-enums.h"

typedef struct _GtkHTML GtkHTML;
typedef struct _GtkHTMLClass GtkHTMLClass;
typedef struct _GtkHTMLClassProperties GtkHTMLClassProperties;
typedef struct _GtkHTMLEditorAPI GtkHTMLEditorAPI;
typedef struct _GtkHTMLEmbedded GtkHTMLEmbedded;
typedef struct _GtkHTMLEmbeddedClass GtkHTMLEmbeddedClass;
typedef struct _GtkHTMLEmbeddedPrivate GtkHTMLEmbeddedPrivate;
typedef struct _GtkHTMLPrivate GtkHTMLPrivate;
typedef struct _GtkHTMLStream GtkHTMLStream;

typedef char **(* GtkHTMLStreamTypesFunc) (GtkHTMLStream *stream, 
					   gpointer user_data);
typedef void   (* GtkHTMLStreamCloseFunc) (GtkHTMLStream *stream,
					   GtkHTMLStreamStatus status,
					   gpointer user_data);
typedef void   (* GtkHTMLStreamWriteFunc) (GtkHTMLStream *stream,
					   const gchar *buffer,
					   size_t size,
					   gpointer user_data);

/* FIXME 1st param should be Engine */
typedef gboolean (* GtkHTMLSaveReceiverFn)   (gpointer     engine,
					      const gchar *data,
					      size_t       len,
					      gpointer     user_data);

typedef void (*GtkHTMLPrintCallback) (GtkHTML *html, GnomePrintContext *print_context,
				      gdouble x, gdouble y, gdouble width, gdouble height, gpointer user_data);

#endif
