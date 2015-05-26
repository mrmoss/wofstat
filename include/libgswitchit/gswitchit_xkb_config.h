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

#ifndef __GSWITCHIT_XKB_CONFIG_H__
#define __GSWITCHIT_XKB_CONFIG_H__

#include <X11/Xlib.h>
#include <X11/XKBlib.h>

#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gconf/gconf-client.h>

extern const char GSWITCHIT_CONFIG_XKB_KEY_OVERRIDE_SETTINGS[];
extern const char GSWITCHIT_CONFIG_XKB_KEY_MODEL[];
extern const char GSWITCHIT_CONFIG_XKB_KEY_LAYOUTS[];
extern const char GSWITCHIT_CONFIG_XKB_KEY_OPTIONS[];

/*
 * XKB configuration
 */
typedef struct _GSwitchItXkbConfig {
	gboolean overrideSettings;
	gchar *model;
	GSList *layouts;
	GSList *options;

	/*< private > */
	GConfClient *confClient;
} GSwitchItXkbConfig;

/**
 * XKB config functions
 */
extern void GSwitchItXkbConfigInit (GSwitchItXkbConfig * xkbConfig,
				    GConfClient * confClient);
extern void GSwitchItXkbConfigTerm (GSwitchItXkbConfig * xkbConfig);

extern void GSwitchItXkbConfigLoad (GSwitchItXkbConfig * xkbConfig);

extern void GSwitchItXkbConfigSave (GSwitchItXkbConfig * xkbConfig);

extern void GSwitchItXkbConfigLoadInitial (GSwitchItXkbConfig * xkbConfig);

extern gboolean GSwitchItXkbConfigEquals (GSwitchItXkbConfig * xkbConfig1,
					  GSwitchItXkbConfig * xkbConfig2);

extern gboolean GSwitchItXkbConfigActivate (GSwitchItXkbConfig *
					    xkbConfig);

/**
 * Common functions
 */
extern const char *GSwitchItConfigMergeItems (const char *parent,
					      const char *child);

extern gboolean GSwitchItConfigSplitItems (const char *merged,
					   char **parent, char **child);

extern Bool GSwitchItConfigGetDescriptions (const char *name,
					    char **layoutShortDescr,
					    char **layoutDescr,
					    char **variantShortDescr,
					    char **variantDescr);

extern const char *GSwitchItConfigFormatFullLayout (const char
						    *layoutDescr, const char
						    *variantDescr);

#endif
