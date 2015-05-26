#ifndef __GNOME_FONT_DIALOG_H__
#define __GNOME_FONT_DIALOG_H__

/*
 *  Copyright (C) 1999-2001 Ximian Inc. and authors
 *
 *  Authors:
 *    Chris Lahey <clahey@ximian.com>
 *    Lauris Kaplinski <lauris@ximian.com>
 *
 *  Font selector, preview and dialog implementation
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public License
 *  as published by the Free Software Foundation; either version 2 of
 *  the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glib.h>

G_BEGIN_DECLS

#define GNOME_TYPE_FONT_PREVIEW (gnome_font_preview_get_type ())
#define GNOME_FONT_PREVIEW(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_FONT_PREVIEW, GnomeFontPreview))
#define GNOME_FONT_PREVIEW_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_FONT_PREVIEW, GnomeFontPreviewClass))
#define GNOME_IS_FONT_PREVIEW(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_FONT_PREVIEW))
#define GNOME_IS_FONT_PREVIEW_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_FONT_PREVIEW))
#define GNOME_FONT_PREVIEW_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_FONT_PREVIEW, GnomeFontPreviewClass))

#define GNOME_TYPE_FONT_SELECTION (gnome_font_selection_get_type ())
#define GNOME_FONT_SELECTION(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_FONT_SELECTION, GnomeFontSelection))
#define GNOME_FONT_SELECTION_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_FONT_SELECTION, GnomeFontSelectionClass))
#define GNOME_IS_FONT_SELECTION(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_FONT_SELECTION))
#define GNOME_IS_FONT_SELECTION_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_FONT_SELECTION))
#define GNOME_FONT_SELECTION_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_FONT_SELECTION, GnomeFontSelectionClass))

#define GNOME_TYPE_FONT_DIALOG (gnome_font_dialog_get_type ())
#define GNOME_FONT_DIALOG(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), GNOME_TYPE_FONT_DIALOG, GnomeFontDialog))
#define GNOME_FONT_DIALOG_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNOME_TYPE_FONT_DIALOG, GnomeFontDialogClass))
#define GNOME_IS_FONT_DIALOG(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNOME_TYPE_FONT_DIALOG))
#define GNOME_IS_FONT_DIALOG_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), GNOME_TYPE_FONT_DIALOG))
#define GNOME_FONT_DIALOG_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GNOME_TYPE_FONT_DIALOG, GnomeFontDialogClass))

typedef struct _GnomeFontSelection	     GnomeFontSelection;
typedef struct _GnomeFontSelectionClass	     GnomeFontSelectionClass;

typedef struct _GnomeFontPreview	     GnomeFontPreview;
typedef struct _GnomeFontPreviewClass	     GnomeFontPreviewClass;

typedef struct _GnomeFontDialog GnomeFontDialog;
typedef struct _GnomeFontDialogClass GnomeFontDialogClass;

#include <gtk/gtkwidget.h>
#include <libgnomeprint/gnome-font.h>

/*
 * INTERNALS ARE PRIVATE UNTIL THEY ARE STABILIZED
 *
 * We implement single signal at moment:
 *
 * void (*font_set) (GnomeFontSelection *selection, GnomeFont *font);
 *
 * You have to ref font in handler, if you want to guarantee it's persistence
 *
 */

/*****************************************************************************
 * GtkFontSelection functions.
 *   see the comments in the GtkFontSelectionDialog functions.
 *****************************************************************************/

GtkType	gnome_font_selection_get_type (void);

GtkWidget *gnome_font_selection_new (void);

/*
 * Reading of selection
 *
 * Font and Face are given with reference, so do not forget to unref these
 */

GnomeFontFace *gnome_font_selection_get_face (GnomeFontSelection *fontsel);
gdouble gnome_font_selection_get_size (GnomeFontSelection *fontsel);
GnomeFont *gnome_font_selection_get_font (GnomeFontSelection *fontsel);

/*
 * You can unref font instantly
 */

void gnome_font_selection_set_font (GnomeFontSelection *fontsel, GnomeFont *font);

/*
 * GnomeFontPreview
 */

GtkType gnome_font_preview_get_type (void);

GtkWidget * gnome_font_preview_new (void);

/*
 * Sets UTF-8 demonstration phrase (NULL means font's default one)
 */

void gnome_font_preview_set_phrase (GnomeFontPreview *preview, const guchar *phrase);

void gnome_font_preview_set_font (GnomeFontPreview *preview, GnomeFont *font);
void gnome_font_preview_set_color (GnomeFontPreview *preview, guint32 color);

/*****************************************************************************
 * GnomeFontSelectionDialog functions.
 *   most of these functions simply call the corresponding function in the
 *   GnomeFontSelection.
 *****************************************************************************/

GtkType gnome_font_dialog_get_type (void);

GtkWidget *gnome_font_dialog_new (const gchar *title);

GtkWidget *gnome_font_dialog_get_fontsel (GnomeFontDialog *gfsd);

GtkWidget *gnome_font_dialog_get_preview (GnomeFontDialog *gfsd);

G_END_DECLS

#endif /* __GNOME_FONT_DIALOG_H__ */



