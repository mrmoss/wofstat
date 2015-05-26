/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000 CodeFactory AB
   Copyright (C) 2000 Jonas Borgstr\366m <jonas@codefactory.se>
   Copyright (C) 2000 Anders Carlsson <andersca@codefactory.se>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef __DOM_CHARACTER_DATA_H__
#define __DOM_CHARACTER_DATA_H__

#include <libgtkhtml/dom/dom-types.h>
#include <libgtkhtml/dom/core/dom-node.h>

#define DOM_TYPE_CHARACTER_DATA             (dom_character_data_get_type ())
#define DOM_CHARACTER_DATA(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_CHARACTER_DATA, DomCharacterData))
#define DOM_CHARACTER_DATA_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_CHARACTER_DATA, DomCharacterDataClass))
#define DOM_IS_CHARACTER_DATA(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_CHARACTER_DATA))
#define DOM_IS_CHARACTER_DATA_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_CHARACTER_DATA))
#define DOM_CHARACTER_DATA_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DOM_TYPE_CHARACTER_DATA, DomCharacterDataClass))

struct _DomCharacterData {
	DomNode parent;
};

struct _DomCharacterDataClass {
	DomNodeClass parent_class;
};

GType dom_character_data_get_type (void);

DomString *dom_CharacterData__get_data (DomCharacterData *cdata);
void dom_CharacterData__set_data (DomCharacterData *cdata, const DomString *data, DomException *exc);
gulong dom_CharacterData__get_length (DomCharacterData *cdata);
DomString *dom_CharacterData_substringData (DomCharacterData *cdata, gulong offset, gulong count, DomException *exc);
void dom_CharacterData_deleteData (DomCharacterData *cdata, gulong offset, gulong count, DomException *exc);
void dom_CharacterData_replaceData (DomCharacterData *cdata, gulong offset, gulong count, DomString *arg, DomException *exc);
void dom_CharacterData_appendData (DomCharacterData *cdata, const DomString *arg, DomException *exc);

#endif /* __DOM_CHARACTER_DATA_H__ */
