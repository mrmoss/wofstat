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

#ifndef __DOM_TYPES_H__
#define __DOM_TYPES_H__

#include <glib-object.h>

typedef gchar DomString;
typedef gboolean DomBoolean;
typedef gushort DomException;
typedef guint64 DomTimeStamp;

typedef struct _DomAttr DomAttr;
typedef struct _DomAttrClass DomAttrClass;

typedef struct _DomCharacterData DomCharacterData;
typedef struct _DomCharacterDataClass DomCharacterDataClass;

typedef struct _DomComment DomComment;
typedef struct _DomCommentClass DomCommentClass;

typedef struct _DomDocument DomDocument;
typedef struct _DomDocumentClass DomDocumentClass;

typedef struct _DomDocumentRange DomDocumentRange;

typedef struct _DomElement DomElement;
typedef struct _DomElementClass DomElementClass;

typedef struct _DomEvent DomEvent;
typedef struct _DomEventClass DomEventClass;

typedef struct _DomEntity DomEntity;
typedef struct _DomEntityClass DomEntityClass;

typedef struct _DomKeyEvent DomKeyEvent;
typedef struct _DomKeyEventClass DomKeyEventClass;

typedef struct _DomNamedNodeMap DomNamedNodeMap;
typedef struct _DomNamedNodeMapClass DomNamedNodeMapClass;

typedef struct _DomNode DomNode;
typedef struct _DomNodeClass DomNodeClass;

typedef struct _DomNodeIterator DomNodeIterator;
typedef struct _DomNodeIteratorClass DomNodeIteratorClass;

typedef struct _DomRange DomRange;
typedef struct _DomRangeClass DomRangeClass;

typedef struct _DomText DomText;
typedef struct _DomTextClass DomTextClass;

typedef struct _DomStyleSheet DomStyleSheet;
typedef struct _DomStyleSheetClass DomStyleSheetClass;

typedef struct _DomCSSStyleSheet DomCSSStyleSheet;
typedef struct _DomCSSStyleSheetClass DomCSSStyleSheetClass;

typedef struct _DomCSSRuleList DomCSSRuleList;
typedef struct _DomCSSRuleListClass DomCSSRuleListClass;

typedef struct _DomCSSRule DomCSSRule;
typedef struct _DomCSSRuleClass DomCSSRuleClass;

typedef struct _DomCSSStyleRule DomCSSStyleRule;
typedef struct _DomCSSStyleRuleClass DomCSSStyleRuleClass;

typedef struct _DomCSSStyleDeclaration DomCSSStyleDeclaration;
typedef struct _DomCSSStyleDeclarationClass DomCSSStyleDeclarationClass;

typedef struct _DomCSSValue DomCSSValue;
typedef struct _DomCSSValueClass DomCSSValueClass;

typedef struct _DomMouseEvent DomMouseEvent;
typedef struct _DomMouseEventClass DomMouseEventClass;

typedef struct _DomHTMLAnchorElement DomHTMLAnchorElement;
typedef struct _DomHTMLAnchorElementClass DomHTMLAnchorElementClass;

typedef struct _DomHTMLElement DomHTMLElement;
typedef struct _DomHTMLElementClass DomHTMLElementClass;

typedef struct _DomHTMLSelectElement DomHTMLSelectElement;
typedef struct _DomHTMLSelectElementClass DomHTMLSelectElementClass;

typedef struct _DomHTMLOptionElement DomHTMLOptionElement;
typedef struct _DomHTMLOptionElementClass DomHTMLOptionElementClass;

typedef struct _DomHTMLFormElement DomHTMLFormElement;
typedef struct _DomHTMLFormElementClass DomHTMLFormElementClass;

typedef struct _DomHTMLInputElement DomHTMLInputElement;
typedef struct _DomHTMLInputElementClass DomHTMLInputElementClass;

typedef struct _DomHTMLObjectElement DomHTMLObjectElement;
typedef struct _DomHTMLObjectElementClass DomHTMLObjectElementClass;

typedef struct _DomHTMLTextAreaElement DomHTMLTextAreaElement;
typedef struct _DomHTMLTextAreaElementClass DomHTMLTextAreaElementClass;

typedef struct _DomHTMLCollection DomHTMLCollection;
typedef struct _DomHTMLCollectionClass DomHTMLCollectionClass;

/* Exceptions */
enum {
	DOM_UNSPECIFIED_EVENT_TYPE_ERR = 0, 
	DOM_INDEX_SIZE_ERR = 1,
	DOM_DOMSTRING_SIZE_ERR = 2,
	DOM_HIERARCHY_REQUEST_ERR = 3,
	DOM_WRONG_DOCUMENT_ERR = 4,
	DOM_INVALID_CHARACTER_ERR = 5,
	DOM_NO_DATA_ALLOWED_ERR = 6,
	DOM_NO_MODIFICATION_ALLOWED_ERR = 7,
	DOM_NOT_FOUND_ERR = 8,
	DOM_NOT_SUPPORTED_ERR = 9,
	DOM_INUSE_ATTRIBUTE_ERR = 10,
	DOM_INVALID_STATE_ERR = 11,
	DOM_SYNTAX_ERR = 12,
	DOM_INVALID_MODIFICATION_ERR = 13,
	DOM_NAMESPACE_ERR = 14,
	DOM_INVALID_ACCESS_ERR = 15,
	DOM_NO_EXCEPTION = 255
};

enum {
	DOM_ELEMENT_NODE = 1,
	DOM_ATTRIBUTE_NODE = 2,
	DOM_TEXT_NODE = 3,
	DOM_CDATA_SECTION_NODE = 4,
	DOM_ENTITY_REFERENCE_NODE = 5,
	DOM_ENTITY_NODE = 6,
	DOM_PROCESSING_INSTRUCTION_NODE = 7,
	DOM_COMMENT_NODE = 8,
	DOM_DOCUMENT_NODE = 9,
	DOM_DOCUMENT_TYPE_NODE = 10,
	DOM_DOCUMENT_FRAGMENT_NODE = 11,
	DOM_NOTATION_NODE = 12
};

#define DOM_SET_EXCEPTION(code) if (exc) { *exc = code; }

#endif /* __DOM_TYPES_H__ */
