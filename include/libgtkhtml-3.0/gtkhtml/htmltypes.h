/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library

   Copyright (C) 2000 Helix Code, Inc.
   Author:            Radek Doulik <rodo@helixcode.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHcANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef _HTML_TYPES_H_
#define _HTML_TYPES_H_

#include <glib.h>

#include "gtkhtml-enums.h"
#include "gtkhtml-types.h"

#include "htmlenums.h"

#define HTML_CHECK_TYPE(object, otype) ((object) \
                                        && (HTML_OBJECT (object))->klass \
                                        && (HTML_OBJECT (object))->klass->type == otype)

typedef struct _HTMLAnchor HTMLAnchor;
typedef struct _HTMLAnchorClass HTMLAnchorClass;
typedef struct _HTMLBlockStackElement HTMLBlockStackElement;
typedef struct _HTMLButton HTMLButton;
typedef struct _HTMLButtonClass HTMLButtonClass;
typedef struct _HTMLCheckBox HTMLCheckBox;
typedef struct _HTMLCheckBoxClass HTMLCheckBoxClass;
typedef struct _HTMLClue HTMLClue;
typedef struct _HTMLClueAligned HTMLClueAligned;
typedef struct _HTMLClueAlignedClass HTMLClueAlignedClass;
typedef struct _HTMLClueClass HTMLClueClass;
typedef struct _HTMLClueFlow HTMLClueFlow;
typedef struct _HTMLClueFlowClass HTMLClueFlowClass;
typedef struct _HTMLClueH HTMLClueH;
typedef struct _HTMLClueHClass HTMLClueHClass;
typedef struct _HTMLClueV HTMLClueV;
typedef struct _HTMLClueVClass HTMLClueVClass;
typedef struct _HTMLColor HTMLColor;
typedef struct _HTMLColorSet HTMLColorSet;
typedef struct _HTMLCursor HTMLCursor;
typedef struct _HTMLCursorRectagle HTMLCursorRectangle;
typedef struct _HTMLDrawQueue HTMLDrawQueue;
typedef struct _HTMLDrawQueueClearElement HTMLDrawQueueClearElement;
typedef struct _HTMLEmbedded HTMLEmbedded;
typedef struct _HTMLEmbeddedClass HTMLEmbeddedClass;
typedef struct _HTMLEngine HTMLEngine;
typedef struct _HTMLEngineClass HTMLEngineClass;
typedef struct _HTMLEngineEditSelectionUpdater HTMLEngineEditSelectionUpdater;
typedef struct _HTMLEngineSaveState HTMLEngineSaveState;
typedef gchar HTMLFontFace;
typedef struct _HTMLFont HTMLFont;
typedef struct _HTMLFontManager HTMLFontManager;
typedef struct _HTMLFontSet HTMLFontSet;
typedef struct _HTMLForm HTMLForm;
typedef struct _HTMLFrame HTMLFrame;
typedef struct _HTMLFrameClass HTMLFrameClass;
typedef struct _HTMLFrameset HTMLFrameset;
typedef struct _HTMLFramesetClass HTMLFramesetClass;
typedef struct _HTMLGdkPainter HTMLGdkPainter;
typedef struct _HTMLGdkPainterClass HTMLGdkPainterClass;
typedef struct _HTMLHidden HTMLHidden;
typedef struct _HTMLHiddenClass HTMLHiddenClass;
typedef struct _HTMLHSpace HTMLHSpace;
typedef struct _HTMLHSpaceClass HTMLHSpaceClass;
typedef struct _HTMLIFrame HTMLIFrame;
typedef struct _HTMLIFrameClass HTMLIFrameClass;
typedef struct _HTMLImage HTMLImage;
typedef struct _HTMLImageAnimation HTMLImageAnimation;
typedef struct _HTMLImageClass HTMLImageClass;
typedef struct _HTMLImageFactory HTMLImageFactory;
typedef struct _HTMLImageInput HTMLImageInput;
typedef struct _HTMLImageInputClass HTMLImageInputClass;
typedef struct _HTMLImagePointer HTMLImagePointer;
typedef struct _HTMLInterval HTMLInterval;
typedef struct _HTMLLinkText HTMLLinkText;
typedef struct _HTMLLinkTextClass HTMLLinkTextClass;
typedef struct _HTMLList HTMLList;
typedef struct _HTMLMap HTMLMap;
typedef struct _HTMLMapClass HTMLMapClass;
typedef struct _HTMLObject HTMLObject;
typedef struct _HTMLObjectClass HTMLObjectClass;
typedef struct _HTMLObjectClearRectangle HTMLObjectClearRectangle;
typedef struct _HTMLPainter HTMLPainter;
typedef struct _HTMLPainterClass HTMLPainterClass;
typedef struct _HTMLPangoAttrFontSize HTMLPangoAttrFontSize;
typedef struct _HTMLPoint HTMLPoint;
typedef struct _HTMLPrinter HTMLPrinter;
typedef struct _HTMLPrinterClass HTMLPrinterClass;
typedef struct _HTMLRadio HTMLRadio;
typedef struct _HTMLRadioClass HTMLRadioClass;
typedef struct _HTMLReplace HTMLReplace;
typedef struct _HTMLRule HTMLRule;
typedef struct _HTMLRuleClass HTMLRuleClass;
typedef struct _HTMLSelect HTMLSelect;
typedef struct _HTMLSelectClass HTMLSelectClass;
typedef struct _HTMLSearch HTMLSearch;
typedef struct _HTMLSettings HTMLSettings;
typedef struct _HTMLStack HTMLStack;
typedef struct _HTMLStringTokenizer HTMLStringTokenizer;
typedef struct _HTMLTable HTMLTable;
typedef struct _HTMLTableCell HTMLTableCell;
typedef struct _HTMLTableCellClass HTMLTableCellClass;
typedef struct _HTMLTableClass HTMLTableClass;
typedef struct _HTMLText HTMLText;
typedef struct _HTMLTextArea HTMLTextArea;
typedef struct _HTMLTextAreaClass HTMLTextAreaClass;
typedef struct _HTMLTextClass HTMLTextClass;
typedef struct _HTMLTextInput HTMLTextInput;
typedef struct _HTMLTextInputClass HTMLTextInputClass;
typedef struct _HTMLTextSlave HTMLTextSlave;
typedef struct _HTMLTextSlaveClass HTMLTextSlaveClass;
typedef struct _HTMLTokenizer HTMLTokenizer;
typedef struct _HTMLTokenizerClass HTMLTokenizerClass;
typedef struct _HTMLUndo HTMLUndo;
typedef struct _HTMLUndoData HTMLUndoData;
typedef struct _HTMLUndoAction HTMLUndoAction;
typedef struct _HTMLVSpace HTMLVSpace;
typedef struct _HTMLVSpaceClass HTMLVSpaceClass;
typedef struct _SpellError SpellError;

typedef void     (* HTMLObjectForallFunc)       (HTMLObject        *self,
						 HTMLEngine        *e,
						 gpointer          data);
typedef gpointer (* HTMLFontManagerAllocFont)   (gchar            *face_name,
						 gdouble           size,
						 GtkHTMLFontStyle  style);
typedef void     (* HTMLFontManagerRefFont)     (gpointer          font);
typedef void     (* HTMLFontManagerUnrefFont)   (gpointer          font);
typedef void     (* HTMLStackFreeFunc)          (gpointer          data);
typedef void     (* HTMLUndoFunc)               (HTMLEngine        *engine,
						 HTMLUndoData      *data,
						 HTMLUndoDirection  dir,
						 guint              position_after);
typedef void     (* HTMLUndoDataDestroyFunc)    (HTMLUndoData      *data);

/* FIXME */
typedef GtkHTMLSaveReceiverFn HTMLEngineSaveReceiverFn;

#endif
