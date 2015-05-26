/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* gnome-password-dialog.h - A use password prompting dialog widget.

   Copyright (C) 2006 Sun Microsystemts, Inc.

   The Gnome Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Gnome Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Gnome Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Authors: Niall Power <niall.power@sun.com>
*/

#ifndef GNOME_TSOL_MESSAGE_DIALOG_H
#define GNOME_TSOL_MESSAGE_DIALOG_H

#include <gtk/gtkmessagedialog.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

G_BEGIN_DECLS

#define GNOME_TYPE_TSOL_MESSAGE_DIALOG            (gnome_tsol_message_dialog_get_type ())
#define GNOME_TSOL_MESSAGE_DIALOG(obj)            (GTK_CHECK_CAST ((obj), GNOME_TYPE_TSOL_MESSAGE_DIALOG, GnomeTsolMessageDialog))
#define GNOME_TSOL_MESSAGE_DIALOG_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), GNOME_TYPE_TSOL_MESSAGE_DIALOG, GnomeTsolMessageDialogClass))
#define GNOME_IS_TSOL_MESSAGE_DIALOG(obj)         (GTK_CHECK_TYPE ((obj), GNOME_TYPE_TSOL_MESSAGE_DIALOG))
#define GNOME_IS_TSOL_MESSAGE_DIALOG_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GNOME_TYPE_TSOL_MESSAGE_DIALOG))

typedef struct _GnomeTsolMessageDialog        GnomeTsolMessageDialog;
typedef struct _GnomeTsolMessageDialogClass   GnomeTsolMessageDialogClass;
typedef struct _GnomeTsolMessageDialogDetails GnomeTsolMessageDialogDetails;

struct _GnomeTsolMessageDialog
{
	GtkMessageDialog parent_instance;

	GnomeTsolMessageDialogDetails *details;
};

struct _GnomeTsolMessageDialogClass
{
	GtkMessageDialogClass parent_class;
};

GtkType    gnome_tsol_message_dialog_get_type (void);

GtkWidget* gnome_tsol_message_dialog_new      (GtkWindow      *parent,
                                        GtkDialogFlags  flags,
                                        GtkMessageType  type,
                                        GtkButtonsType  buttons,
                                        gboolean sys_modal,
                                        const gchar    *message_format,
                                        ...) G_GNUC_PRINTF (6, 7);

G_END_DECLS

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GNOME_TSOL_MESSAGE_DIALOG_H */
