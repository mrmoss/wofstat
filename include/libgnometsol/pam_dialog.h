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

#ifndef GNOME_TSOL_PASSWORD_DIALOG_H
#define GNOME_TSOL_PASSWORD_DIALOG_H

#include <gtk/gtkdialog.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

G_BEGIN_DECLS

#define GNOME_TYPE_TSOL_PASSWORD_DIALOG            (gnome_tsol_password_dialog_get_type ())
#define GNOME_TSOL_PASSWORD_DIALOG(obj)            (GTK_CHECK_CAST ((obj), GNOME_TYPE_TSOL_PASSWORD_DIALOG, GnomeTsolPasswordDialog))
#define GNOME_TSOL_PASSWORD_DIALOG_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), GNOME_TYPE_TSOL_PASSWORD_DIALOG, GnomeTsolPasswordDialogClass))
#define GNOME_IS_TSOL_PASSWORD_DIALOG(obj)         (GTK_CHECK_TYPE ((obj), GNOME_TYPE_TSOL_PASSWORD_DIALOG))
#define GNOME_IS_TSOL_PASSWORD_DIALOG_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GNOME_TYPE_TSOL_PASSWORD_DIALOG))


typedef struct _GnomeTsolPasswordDialog        GnomeTsolPasswordDialog;
typedef struct _GnomeTsolPasswordDialogClass   GnomeTsolPasswordDialogClass;
typedef struct _GnomeTsolPasswordDialogDetails GnomeTsolPasswordDialogDetails;

struct _GnomeTsolPasswordDialog
{
	GtkDialog gtk_dialog;

	GnomeTsolPasswordDialogDetails *details;
};

struct _GnomeTsolPasswordDialogClass
{
	GtkDialogClass parent_class;
};

GtkType    gnome_tsol_password_dialog_get_type (void);

GtkWidget* gnome_tsol_password_dialog_new      (const char *dialog_title,
					   const char *prompt,
					   const char *message,
					   gboolean sys_modal,
					   gboolean hide_input);

gchar*	gnome_tsol_password_dialog_get_auth_token		(GnomeTsolPasswordDialog *password_dialog);
void  	gnome_tsol_password_dialog_set_message			(GnomeTsolPasswordDialog *password_dialog,
						gchar *message);
void 	gnome_tsol_password_dialog_set_input_prompt		(GnomeTsolPasswordDialog *password_dialog,
						gchar *prompt);
void	gnome_tsol_password_dialog_set_input_visibility	(GnomeTsolPasswordDialog *password_dialog,
						gboolean visible);
G_END_DECLS

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GNOME_TSOL_PASSWORD_DIALOG_H */
