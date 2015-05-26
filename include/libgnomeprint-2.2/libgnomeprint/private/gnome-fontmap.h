/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  gnome-fontmap.h: fontmap implementation
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
 *
 *  Authors:
 *    Lauris Kaplinski <lauris@ximian.com>
 *    Chema Celorio <chema@celorio.com>
 *    Tambet Ingo <tambet@ximian.com>
 *
 *  Copyright (C) 2000-2003 Ximian, Inc.
 *
 */

#ifndef __GNOME_FONTMAP_H__
#define __GNOME_FONTMAP_H__

#include <glib.h>

G_BEGIN_DECLS

#include <libxml/tree.h>
#include <libgnomeprint/gnome-font-face.h>

typedef struct _GPFontMap        GPFontMap;
typedef struct _GPFontEntry      GPFontEntry;
typedef struct _GPFontEntryAlias GPFontEntryAlias;
typedef struct _GPFamilyEntry    GPFamilyEntry;

typedef enum {
	GP_FONT_ENTRY_UNKNOWN,
	GP_FONT_ENTRY_TYPE1,
	GP_FONT_ENTRY_TRUETYPE,
	GP_FONT_ENTRY_ALIAS
} GPFontEntryType;

struct _GPFontMap {
	gint refcount;
	gint num_fonts;

	GHashTable *fontdict;	  /* Name -> FontEntry */
	GHashTable *familydict;	  /* Family name -> FamilyEntry */
	GHashTable *filenamedict; /* File/index -> FontEntry */

	GSList *fonts;	        /* List of FontEntries, sorted A-Z */
	GSList *families;	/* List of FamilyEntries, sorted A-Z */

	GList *fontlist;	/* List of font names (pointing to entry->name) */
	GList *familylist;	/* List of family names (pointing to entry->name */
};

struct _GPFontEntry {
	GPFontEntryType type;

	gint refcount;

	GnomeFontFace * face;

	gchar *name;
	gchar *familyname;
	gchar *speciesname;
	gchar *file;
	gint   index;
	gchar *unused;
	gint   italic_angle; /* italic < 0 */
	GnomeFontWeight Weight;

	gboolean is_alias; 
};

struct _GPFamilyEntry {
	gint refcount;
	gchar *name;
	GSList *fonts; /* List with GPFontEntry childs */

	gboolean is_alias;
};

struct _GPFontEntryAlias {
	GPFontEntry entry;
	GPFontEntry * ref;
};


GPFontMap * gp_fontmap_get (void);
void        gp_fontmap_release (GPFontMap *);

void        gp_font_entry_ref   (GPFontEntry * entry);
void        gp_font_entry_unref (GPFontEntry * entry);

GnomeFontWeight gp_fontmap_lookup_weight (const gchar * weight);

G_END_DECLS

#endif /* __GNOME_FONTMAP_H__ */
