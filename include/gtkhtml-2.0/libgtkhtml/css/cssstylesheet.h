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

#ifndef __CSSSTYLESHEET_H__
#define __CSSSTYLESHEET_H__

#include "cssvalue.h"

G_BEGIN_DECLS

typedef struct _CssStylesheet CssStylesheet;
typedef struct _CssDeclaration CssDeclaration;
typedef struct _CssRuleset CssRuleset;
typedef struct _CssTail CssTail;
typedef struct _CssAttrVal CssAttrVal;
typedef struct _CssSimpleSelector CssSimpleSelector;
typedef struct _CssSelector CssSelector;
typedef struct _CssStatement CssStatement;

enum _CssStatementType {
	CSS_RULESET,
	CSS_IMPORT_RULE,
	CSS_MEDIA_RULE,
	CSS_PAGE_RULE,
	CSS_CHARSET_RULE,
	CSS_FONT_FACE_RULE,
	CSS_UNKNOWN_RULE
};
typedef enum _CssStatementType CssStatementType;

enum _CssCombinator {
	CSS_COMBINATOR_PLUS,
	CSS_COMBINATOR_GT,
	CSS_COMBINATOR_TILDE,
	CSS_COMBINATOR_EMPTY
};
typedef enum _CssCombinator CssCombinator;

enum _CssAttrValType {
	CSS_ATTR_VAL_IDENT,
	CSS_ATTR_VAL_STRING
};
typedef enum _CssAttrValType CssAttrValType;

struct _CssAttrVal {
	CssAttrValType type;
	union {
		HtmlAtom id;
		gchar *str;
	} a;
};

struct _CssStatement {
	CssStatementType type;

	union {
		CssRuleset *ruleset;
		struct {
			CssValue *media_list;
			gint n_rs;
			CssRuleset **rs;
		} media_rule;

		struct {
			HtmlAtom name;

			HtmlAtom pseudo;
			
			gint n_decl;
			CssDeclaration **decl;
		} page_rule;

		struct {
			gint n_decl;
			CssDeclaration **decl;
		} font_face_rule;

		struct {
			CssStylesheet *sheet;
			CssValue *url;
			gboolean fetched;
			gboolean fetching;
		} import_rule;

	} s;
};

struct _CssSelector {
	gint n_simple;
	CssSimpleSelector **simple;
	CssCombinator *comb;

	/* Specificity */
	gint a, b, c;
};

struct _CssDeclaration {
	gint property;
	CssValue *expr;
	gboolean important;
};

struct _CssRuleset {
	gint n_sel;
	CssSelector **sel;
	
	gint n_decl;
	CssDeclaration **decl;
};

struct _CssParser {
	gchar *str;
	gint len;
};

struct _CssSimpleSelector {
	gboolean is_star;
	HtmlAtom element_name;

	gint n_tail;
	CssTail *tail;
};

enum _CssTailType {
	CSS_TAIL_ATTR_SEL,
	CSS_TAIL_ID_SEL,
	CSS_TAIL_CLASS_SEL,
	CSS_TAIL_PSEUDO_SEL
};
typedef enum _CssTailType CssTailType;

enum _CssAttrMatch {
	CSS_MATCH_EMPTY,
	CSS_MATCH_PREFIXMATCH,
	CSS_MATCH_SUFFIXMATCH,
	CSS_MATCH_SUBSTRINGMATCH,
	CSS_MATCH_EQ,
	CSS_MATCH_INCLUDES,
	CSS_MATCH_DASHMATCH
};
typedef enum _CssAttrMatch CssAttrMatch;

struct _CssTail {
	CssTailType type;

	union {
		struct {
			HtmlAtom att;
			CssAttrMatch match;
			CssAttrVal val;
		} attr_sel;
		struct {
			HtmlAtom id;
		} id_sel;
		struct {
			HtmlAtom class;
		} class_sel;
		struct {
			HtmlAtom name;
		} pseudo_sel;
	} t;
};

struct _CssStylesheet {
	gboolean disabled;
	GSList *stat;
};

void css_simple_selector_destroy (CssSimpleSelector *ss);
void css_selector_destroy (CssSelector *sel);
void css_tail_destroy (CssTail *tail);

void css_stylesheet_destroy (CssStylesheet *stylesheet);
void css_selector_calc_specificity (CssSelector *sel);

void css_ruleset_destroy (CssRuleset *set);

G_END_DECLS

#endif /* __CSSSTYLESHEET_H__ */
