/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __GSWITCHIT_PLUGIN_H__
#define __GSWITCHIT_PLUGIN_H__

#include <gtk/gtk.h>
#include <gconf/gconf-client.h>
#include <libgswitchit/gswitchit_xkb_config.h>

#define MAX_LOCAL_NAME_BUF_LENGTH 512

struct _GSwitchItPlugin;

typedef struct _GSwitchItPluginContainer {
	GConfClient *confClient;
} GSwitchItPluginContainer;

typedef const struct _GSwitchItPlugin
*(*GSwitchItPluginGetPluginFunc) (void);

typedef gboolean (*GSwitchItPluginInitFunc) (GSwitchItPluginContainer *
					     pc);

typedef void (*GSwitchItPluginGroupChangedFunc) (int newGroup);

typedef void (*GSwitchItPluginConfigChangedFunc) (const GSwitchItXkbConfig
						  * from,
						  const GSwitchItXkbConfig
						  * to);

typedef int (*GSwitchItPluginWindowCreatedFunc) (const Window win,
						 const Window parent);

typedef void (*GSwitchItPluginTermFunc) (void);

typedef GtkWidget *(*GSwitchItPluginCreateWidget) (void);

typedef GtkWidget *(*GSwitchItPluginDecorateWidget) (GtkWidget * widget,
						     const gint group,
						     const char
						     *groupDescription,
						     GSwitchItXkbConfig *
						     config);

typedef
void (*GSwitchItPluginConfigureProperties) (GSwitchItPluginContainer *
					    pc, GtkWindow * parent);

typedef struct _GSwitchItPlugin {
	const char *name;

	const char *description;

// implemented
	GSwitchItPluginInitFunc initCallback;

// implemented
	GSwitchItPluginTermFunc termCallback;

// implemented
	GSwitchItPluginConfigureProperties configurePropertiesCallback;

// implemented
	GSwitchItPluginGroupChangedFunc groupChangedCallback;

// implemented
	GSwitchItPluginWindowCreatedFunc windowCreatedCallback;

// implemented
	GSwitchItPluginDecorateWidget decorateWidgetCallback;

// non implemented
	GSwitchItPluginConfigChangedFunc configChangedCallback;

// non implemented
	GSwitchItPluginCreateWidget createWidgetCallback;

} GSwitchItPlugin;

typedef char
 GroupDescriptionsBuffer[XkbNumKbdGroups][MAX_LOCAL_NAME_BUF_LENGTH];

/**
 * Functions accessible for plugins
 */

extern void GSwitchItPluginContainerInit (GSwitchItPluginContainer * pc,
					  GConfClient * confClient);

extern void GSwitchItPluginContainerTerm (GSwitchItPluginContainer * pc);

extern void GSwitchItPluginContainerReinitUi (GSwitchItPluginContainer *
					      pc);

extern guint GSwitchItPluginGetNumGroups (GSwitchItPluginContainer * pc);

extern void
GSwitchItPluginLoadLocalizedGroupNames (GSwitchItPluginContainer * pc,
					const
					GroupDescriptionsBuffer **
					outDescr);

#endif
