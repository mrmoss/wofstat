/*
 * bonobo-ui-util.h: Bonobo UI utility functions
 *
 * Author:
 *	Michael Meeks (michael@helixcode.com)
 *
 * Copyright 2000, 2001 Ximian, Inc.
 */
#ifndef _BONOBO_UI_XML_UTIL_H_
#define _BONOBO_UI_XML_UTIL_H_

#include <gtk/gtkwidget.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <bonobo/bonobo-ui-component.h>

G_BEGIN_DECLS

char      *bonobo_ui_util_pixbuf_to_xml       (GdkPixbuf         *pixbuf);
GdkPixbuf *bonobo_ui_util_xml_to_pixbuf       (const char        *xml);

GtkWidget *bonobo_ui_util_xml_get_icon_widget (BonoboUINode      *node,
					       GtkIconSize        icon_size);

void       bonobo_ui_util_xml_set_pixbuf      (BonoboUINode      *node,
					       GdkPixbuf         *pixbuf);

void       bonobo_ui_util_build_help_menu     (BonoboUIComponent *listener,
					       const char        *app_prefix,
					       const char        *app_name,
					       BonoboUINode      *parent);

char      *bonobo_ui_util_get_ui_fname        (const char        *component_prefix,
					       const char        *file_name);

void       bonobo_ui_util_translate_ui        (BonoboUINode      *node);

void       bonobo_ui_util_fixup_help          (BonoboUIComponent *component,
					       BonoboUINode      *node,
					       const char        *app_prefix,
					       const char        *app_name);

void       bonobo_ui_util_fixup_icons         (BonoboUINode      *node);

/*
 * Does all the translation & other grunt.
 */
BonoboUINode   *bonobo_ui_util_new_ui       (BonoboUIComponent *component,
					     const char        *fname,
					     const char        *app_prefix,
					     const char        *app_name);

void            bonobo_ui_util_set_ui       (BonoboUIComponent *component,
					     const char        *app_prefix,
					     const char        *file_name,
					     const char        *app_name,
					     CORBA_Environment *opt_ev);

void            bonobo_ui_util_set_pixbuf   (BonoboUIComponent *component,
					     const char        *path,
					     GdkPixbuf         *pixbuf,
					     CORBA_Environment *opt_ev);

gchar          *bonobo_ui_util_accel_name   (guint              accelerator_key,
					     GdkModifierType    accelerator_mods);

void            bonobo_ui_util_accel_parse  (const char        *name,
					     guint             *accelerator_key,
					     GdkModifierType   *accelerator_mods);

#define         bonobo_ui_util_decode_str(s,e) g_strdup (s)
#define         bonobo_ui_util_encode_str(s)   g_strdup (s)

G_END_DECLS

#endif /* _BONOBO_UI_XML_UTIL_H_ */
