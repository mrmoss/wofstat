/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/*
   Copyright (C) 2000 Helix Code, Inc.
   Copyright (C) 2001 Ximian, Inc.

   The Gnome Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Gnome Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Gnome Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Author: Radek Doulik <rodo@ximian.com>

*/

#ifndef _HTML_ENUMS_H
#define _HTML_ENUMS_H

#define MAX_WIDGET_WIDTH 32000

typedef enum {
	BUTTON_NORMAL,
	BUTTON_SUBMIT,
	BUTTON_RESET
} HTMLButtonType;

typedef enum {
	HTML_CHANGE_NONE = 0,
	HTML_CHANGE_MIN_WIDTH = 1 << 0,
	HTML_CHANGE_PREF_WIDTH = 1 << 1,
	HTML_CHANGE_SIZE = 1 << 2,
	HTML_CHANGE_WORD_WIDTH = 1 << 3,
	HTML_CHANGE_ALL_CALC = ((HTML_CHANGE_SIZE << 1) - 1),
	HTML_CHANGE_ALL = ((HTML_CHANGE_WORD_WIDTH << 1) - 1)
} HTMLChangeFlags;

typedef enum {
	HTML_CLEAR_NONE,
	HTML_CLEAR_LEFT,
	HTML_CLEAR_RIGHT,
	HTML_CLEAR_ALL
} HTMLClearType;

/* Paragraph style.  Notice that the `H*' elements must be consecutive.  */
typedef enum {
	HTML_CLUEFLOW_STYLE_NORMAL,
	HTML_CLUEFLOW_STYLE_H1,
	HTML_CLUEFLOW_STYLE_H2,
	HTML_CLUEFLOW_STYLE_H3,
	HTML_CLUEFLOW_STYLE_H4,
	HTML_CLUEFLOW_STYLE_H5,
	HTML_CLUEFLOW_STYLE_H6,
	HTML_CLUEFLOW_STYLE_ADDRESS,
	HTML_CLUEFLOW_STYLE_PRE,
	HTML_CLUEFLOW_STYLE_LIST_ITEM,
	HTML_CLUEFLOW_NUMSTYLES
} HTMLClueFlowStyle;

typedef enum {
	HTMLBgColor = 0,
	HTMLTextColor,
	HTMLLinkColor,
	HTMLVLinkColor,
	HTMLALinkColor,
	HTMLHighlightColor,
	HTMLHighlightTextColor,
	HTMLHighlightNFColor,
	HTMLHighlightTextNFColor,
	HTMLSpellErrorColor,

	HTMLColors
} HTMLColorId;

typedef enum {
	HTML_ENGINE_CURSOR_UP,
	HTML_ENGINE_CURSOR_DOWN,
	HTML_ENGINE_CURSOR_RIGHT,
	HTML_ENGINE_CURSOR_LEFT,
	HTML_ENGINE_CURSOR_HOME,
	HTML_ENGINE_CURSOR_END,
	HTML_ENGINE_CURSOR_PGUP,
	HTML_ENGINE_CURSOR_PGDOWN
} HTMLEngineCursorMovement;

typedef enum {
	HTML_ENGINE_SET_CLUEFLOW_NONE = 0,
	HTML_ENGINE_SET_CLUEFLOW_STYLE = 1 << 0,
	HTML_ENGINE_SET_CLUEFLOW_ALIGNMENT = 1 << 1,
	HTML_ENGINE_SET_CLUEFLOW_INDENTATION = 1 << 2,
	HTML_ENGINE_SET_CLUEFLOW_INDENTATION_DELTA = 1 << 3,
	HTML_ENGINE_SET_CLUEFLOW_INDENTATION_ALL = 5
} HTMLEngineSetClueFlowStyleMask;

typedef enum {
	HTML_FIT_NONE,
	HTML_FIT_PARTIAL,
	HTML_FIT_COMPLETE
} HTMLFitType;

typedef enum {
	HTML_GLOSSARY_DL = 1,
	HTML_GLOSSARY_DD = 2
} HTMLGlossaryEntry;

typedef enum {
	HTML_HALIGN_LEFT,
	HTML_HALIGN_CENTER,
	HTML_HALIGN_RIGHT,
	HTML_HALIGN_NONE
} HTMLHAlignType;

typedef enum {
	HTML_LIST_TYPE_UNORDERED,
	HTML_LIST_TYPE_ORDERED_ARABIC,
	HTML_LIST_TYPE_ORDERED_LOWER_ALPHA,
	HTML_LIST_TYPE_ORDERED_UPPER_ALPHA,
	HTML_LIST_TYPE_ORDERED_LOWER_ROMAN,
	HTML_LIST_TYPE_ORDERED_UPPER_ROMAN,
	HTML_LIST_TYPE_MENU,
	HTML_LIST_TYPE_DIR,
	HTML_LIST_TYPE_BLOCKQUOTE,
	HTML_LIST_TYPE_BLOCKQUOTE_CITE,
	HTML_LIST_TYPE_GLOSSARY_DL,
	HTML_LIST_TYPE_GLOSSARY_DD
} HTMLListType;

typedef enum {
	HTML_OBJECT_FLAG_NONE = 0,
	HTML_OBJECT_FLAG_SEPARATOR = 1 << 0,
	HTML_OBJECT_FLAG_SELECTED = 1 << 2,
	HTML_OBJECT_FLAG_ALLSELECTED = 1 << 3,
	HTML_OBJECT_FLAG_FIXEDWIDTH = 1 << 4,
	HTML_OBJECT_FLAG_ALIGNED = 1 << 5,
	HTML_OBJECT_FLAG_PRINTED = 1 << 6,
	HTML_OBJECT_FLAG_HIDDEN = 1 << 7
} HTMLObjectFlags;

typedef enum {
	RQA_Replace,
	RQA_ReplaceAll,
	RQA_Next,
	RQA_Cancel
} HTMLReplaceQueryAnswer;

/* This is a list of the HTML object classes we are using.  We use a static
   system because (a) it's faster and (b) we don't need/want an extensible
   object system.

   If you add new HTML classes, you should (a) update this list and (b) update
   the `html_types_init ()' function in `htmltype.c'.  */

typedef enum {
	HTML_TYPE_NONE,
	HTML_TYPE_ANCHOR,
	HTML_TYPE_BULLET,
	HTML_TYPE_BUTTON,
	HTML_TYPE_CHECKBOX,
	HTML_TYPE_CLUE,
	HTML_TYPE_CLUEALIGNED,
	HTML_TYPE_CLUEFLOW,
	HTML_TYPE_CLUEH,
	HTML_TYPE_CLUEV,
	HTML_TYPE_EMBEDDED,
	HTML_TYPE_HIDDEN,
	HTML_TYPE_HSPACE,
	HTML_TYPE_IMAGE,
	HTML_TYPE_IMAGEINPUT,
	HTML_TYPE_LINKTEXT,
	HTML_TYPE_OBJECT,
	HTML_TYPE_RADIO,
	HTML_TYPE_RULE,
	HTML_TYPE_SELECT,
	HTML_TYPE_TABLE,
	HTML_TYPE_TABLECELL,
	HTML_TYPE_TEXT,
	HTML_TYPE_TEXTAREA,
	HTML_TYPE_TEXTINPUT,
	HTML_TYPE_TEXTSLAVE,
	HTML_TYPE_VSPACE,
	HTML_TYPE_IFRAME,
	HTML_TYPE_FRAME,
	HTML_TYPE_FRAMESET,
	HTML_NUM_TYPES
} HTMLType;

typedef enum {
	HTML_UNDO_UNDO = 0,
	HTML_UNDO_REDO = 1,
	HTML_UNDO_END  = 2
} HTMLUndoDirection;

typedef enum {
	HTML_URL_DUP_ALL = 0,
	HTML_URL_DUP_NOPROTOCOL = 1 << 0,
	HTML_URL_DUP_NOUSERNAME = 1 << 1,
	HTML_URL_DUP_NOPASSWORD = 1 << 2,
	HTML_URL_DUP_NOHOSTNAME = 1 << 3,
	HTML_URL_DUP_NOPORT = 1 << 4,
	HTML_URL_DUP_NOPATH = 1 << 5,
	HTML_URL_DUP_NOREFERENCE = 1 << 6,
	HTML_URL_DUP_NOCGIARGS = 1 << 7
} HTMLURLDupFlags;

typedef enum {
	HTML_VALIGN_TOP,
	HTML_VALIGN_MIDDLE,
	HTML_VALIGN_BOTTOM,
	HTML_VALIGN_NONE
} HTMLVAlignType;

#endif
