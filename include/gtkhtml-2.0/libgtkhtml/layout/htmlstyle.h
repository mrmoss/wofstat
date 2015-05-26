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

#ifndef __HTMLSTYLE_H__
#define __HTMLSTYLE_H__

typedef struct _HtmlStyle HtmlStyle;
typedef struct _HtmlStyleBox HtmlStyleBox;
typedef struct _HtmlStyleSurround HtmlStyleSurround;
typedef struct _HtmlStyleVisual HtmlStyleVisual;
typedef struct _HtmlStyleBorderInfo HtmlStyleBorderInfo;
typedef struct _HtmlStyleBorder HtmlStyleBorder;
typedef struct _HtmlStyleOutline HtmlStyleOutline;
typedef struct _HtmlStyleBackground HtmlStyleBackground;
typedef struct _HtmlLengthBox HtmlLengthBox;
typedef struct _HtmlStyleInherited HtmlStyleInherited;

enum  _HtmlBackgroundRepeatType {
	HTML_BACKGROUND_REPEAT_REPEAT = 0,
	HTML_BACKGROUND_REPEAT_REPEAT_X,
	HTML_BACKGROUND_REPEAT_REPEAT_Y,
	HTML_BACKGROUND_REPEAT_NO_REPEAT,
	HTML_BACKGROUND_REPEAT_SCALE
};

typedef enum _HtmlBackgroundRepeatType HtmlBackgroundRepeatType;

#include <glib.h>
#include <pango/pango.h>

#include <libgtkhtml/css/cssvalue.h>
#include <libgtkhtml/graphics/htmlcolor.h>
#include <libgtkhtml/graphics/htmlfontspecification.h>
#include <libgtkhtml/graphics/htmlimagefactory.h>

G_BEGIN_DECLS

#define HTML_BORDER_WIDTH_THIN 1
#define HTML_BORDER_WIDTH_MEDIUM 3
#define HTML_BORDER_WIDTH_THICK 5

typedef enum {
	HTML_STYLE_CHANGE_NONE = 0,
	HTML_STYLE_CHANGE_REPAINT,
	HTML_STYLE_CHANGE_RELAYOUT,
	HTML_STYLE_CHANGE_RECREATE
} HtmlStyleChange;

typedef enum {
	HTML_LENGTH_AUTO = 0,
	HTML_LENGTH_FIXED,
	HTML_LENGTH_PERCENT
} HtmlLengthType;

typedef struct {
	guint type:2;
	gint value;
} HtmlLength;


typedef enum {
	HTML_DISPLAY_INLINE = 0,
	HTML_DISPLAY_BLOCK,
	HTML_DISPLAY_LIST_ITEM,
	HTML_DISPLAY_RUN_IN,
	HTML_DISPLAY_COMPACT,
	HTML_DISPLAY_MARKER,
	HTML_DISPLAY_TABLE,
	HTML_DISPLAY_INLINE_TABLE,
	HTML_DISPLAY_TABLE_ROW_GROUP,
	HTML_DISPLAY_TABLE_HEADER_GROUP,
	HTML_DISPLAY_TABLE_FOOTER_GROUP,
	HTML_DISPLAY_TABLE_ROW,
	HTML_DISPLAY_TABLE_COLUMN_GROUP,
	HTML_DISPLAY_TABLE_COLUMN,
	HTML_DISPLAY_TABLE_CELL,
	HTML_DISPLAY_TABLE_CAPTION,
	HTML_DISPLAY_NONE
} HtmlDisplayType;

typedef enum {
	HTML_CAPTION_SIDE_TOP = 0,
	HTML_CAPTION_SIDE_RIGHT,
	HTML_CAPTION_SIDE_BOTTOM,
	HTML_CAPTION_SIDE_LEFT
} HtmlCaptionSideType;

typedef enum {
	HTML_TABLE_LAYOUT_AUTO = 0,
	HTML_TABLE_LAYOUT_FIXED
} HtmlTableLayoutType;

typedef enum {
	HTML_VERTICAL_ALIGN_BASELINE = 0,
	HTML_VERTICAL_ALIGN_SUB,
	HTML_VERTICAL_ALIGN_SUPER,
	HTML_VERTICAL_ALIGN_TOP,
	HTML_VERTICAL_ALIGN_TEXT_TOP,
	HTML_VERTICAL_ALIGN_MIDDLE,
	HTML_VERTICAL_ALIGN_TEXT_BOTTOM,
	HTML_VERTICAL_ALIGN_BOTTOM
	
} HtmlVerticalAlignType;

typedef enum {
	HTML_DIRECTION_LTR = 0,
	HTML_DIRECTION_RTL
} HtmlDirectionType;

typedef enum {
	HTML_UNICODE_BIDI_NORMAL = 0,
	HTML_UNICODE_BIDI_EMBED,
	HTML_UNICODE_BIDI_OVERRIDE
} HtmlUnicodeBidiType;

typedef enum {
	HTML_VISIBILITY_VISIBLE = 0,
	HTML_VISIBILITY_HIDDEN,
	HTML_VISIBILITY_COLLAPSE
} HtmlVisibilityType;

typedef enum {
	HTML_CLEAR_NONE = 0,
	HTML_CLEAR_LEFT,
	HTML_CLEAR_RIGHT,
	HTML_CLEAR_BOTH
} HtmlClearType;

typedef enum {
	HTML_TEXT_TRANSFORM_NONE = 0,
	HTML_TEXT_TRANSFORM_CAPITALIZE,
	HTML_TEXT_TRANSFORM_UPPERCASE,
	HTML_TEXT_TRANSFORM_LOWERCASE
} HtmlTextTransformType;

typedef enum {
	HTML_WHITE_SPACE_NORMAL = 0,
	HTML_WHITE_SPACE_PRE,
	HTML_WHITE_SPACE_NOWRAP
} HtmlWhiteSpaceType;

typedef enum {
	HTML_BORDER_STYLE_NONE = 0,
	HTML_BORDER_STYLE_HIDDEN,
	HTML_BORDER_STYLE_DOTTED,
	HTML_BORDER_STYLE_DASHED,
	HTML_BORDER_STYLE_SOLID,
	HTML_BORDER_STYLE_DOUBLE,
	HTML_BORDER_STYLE_GROOVE,
	HTML_BORDER_STYLE_RIDGE,
	HTML_BORDER_STYLE_INSET,
	HTML_BORDER_STYLE_OUTSET
} HtmlBorderStyleType;

typedef enum {
	HTML_LIST_STYLE_TYPE_DISC = 0,
	HTML_LIST_STYLE_TYPE_CIRCLE,
	HTML_LIST_STYLE_TYPE_SQUARE,
	HTML_LIST_STYLE_TYPE_DECIMAL,
	HTML_LIST_STYLE_TYPE_DECIMAL_LEADING_ZERO,
	HTML_LIST_STYLE_TYPE_LOWER_ROMAN,
	HTML_LIST_STYLE_TYPE_UPPER_ROMAN,
	HTML_LIST_STYLE_TYPE_LOWER_GREEK,
	HTML_LIST_STYLE_TYPE_LOWER_ALPHA,
	HTML_LIST_STYLE_TYPE_LOWER_LATIN,
	HTML_LIST_STYLE_TYPE_UPPER_ALPHA,
	HTML_LIST_STYLE_TYPE_UPPER_LATIN,
	HTML_LIST_STYLE_TYPE_HEBREW,
	HTML_LIST_STYLE_TYPE_ARMENIAN,
	HTML_LIST_STYLE_TYPE_GEORGIAN,
	HTML_LIST_STYLE_TYPE_CJK_IDEOGRAPHIC,
	HTML_LIST_STYLE_TYPE_HIRAGANA,
	HTML_LIST_STYLE_TYPE_KATAKANA,
	HTML_LIST_STYLE_TYPE_HIRAGANA_IROHA,
	HTML_LIST_STYLE_TYPE_KATAKANA_IROHA,
	HTML_LIST_STYLE_TYPE_NONE
} HtmlListStyleTypeType;

typedef enum {
	HTML_TEXT_ALIGN_DEFAULT = 0,
	HTML_TEXT_ALIGN_LEFT,
	HTML_TEXT_ALIGN_RIGHT,
	HTML_TEXT_ALIGN_CENTER,
	HTML_TEXT_ALIGN_JUSTIFY,
	HTML_TEXT_ALIGN_STRING /* Fix this */
} HtmlTextAlignType;

typedef enum {
	HTML_FLOAT_NONE = 0,
	HTML_FLOAT_LEFT,
	HTML_FLOAT_RIGHT,
	HTML_FLOAT_CENTER
} HtmlFloatType;

typedef enum {
	HTML_OVERFLOW_VISIBLE = 0,
	HTML_OVERFLOW_HIDDEN,
	HTML_OVERFLOW_SCROLL,
	HTML_OVERFLOW_AUTO
} HtmlOverflowType;

typedef enum {
	HTML_POSITION_STATIC = 0,
	HTML_POSITION_FIXED,
	HTML_POSITION_ABSOLUTE,
	HTML_POSITION_RELATIVE
} HtmlPositionType;

typedef enum {
	HTML_CURSOR_AUTO = 0,
	HTML_CURSOR_CROSSHAIR,
	HTML_CURSOR_DEFAULT,
	HTML_CURSOR_POINTER,
	HTML_CURSOR_MOVE,
	HTML_CURSOR_E_RESIZE,
	HTML_CURSOR_NE_RESIZE,
	HTML_CURSOR_NW_RESIZE,
	HTML_CURSOR_N_RESIZE,
	HTML_CURSOR_SE_RESIZE,
	HTML_CURSOR_SW_RESIZE,
	HTML_CURSOR_S_RESIZE,
	HTML_CURSOR_W_RESIZE,
	HTML_CURSOR_TEXT,
	HTML_CURSOR_WAIT,
	HTML_CURSOR_HELP
} HtmlCursorType;

struct _HtmlStyleBox {
	gint refcount;
	
	HtmlLength width;
	HtmlLength min_width;
	HtmlLength max_width;
	
	HtmlLength height;
	HtmlLength min_height;
	HtmlLength max_height;
};

struct _HtmlLengthBox {
	HtmlLength top;
	HtmlLength right;
	HtmlLength bottom;
	HtmlLength left;
};

struct _HtmlStyleBackground {
	gint refcount;
	
	HtmlColor color;
	HtmlImage *image;

	guint repeat:3;
};

struct _HtmlStyleVisual {
	HtmlLengthBox clip;
};

struct _HtmlStyleSurround {
	gint refcount;

	HtmlLengthBox margin;
	HtmlLengthBox padding;
	HtmlLengthBox position;
};

struct _HtmlStyleBorderInfo {
	gushort width;
	HtmlColor *color;
	HtmlBorderStyleType border_style;
};

struct _HtmlStyleBorder {
	gint refcount;
	
	HtmlStyleBorderInfo left;
	HtmlStyleBorderInfo right;
	HtmlStyleBorderInfo top;
	HtmlStyleBorderInfo bottom;
};

struct _HtmlStyleOutline {
	gint refcount;
	
	gushort width;
	HtmlColor *color;
	HtmlBorderStyleType style;
};


struct _HtmlStyleInherited {
	gint refcount;
	
	gint16 line_height; /* Line height in pixels */
	HtmlLength text_indent;

	gint word_spacing:8;
	gint letter_spacing:8;
	guint cursor:4;
	
  	gushort border_spacing_horiz;
	gushort border_spacing_vert;
  
	guint direction:1;
	gint8 bidi_level;

	HtmlColor *color;
	HtmlFontSpecification *font_spec;
	guint text_align:3;

	guint caption_side:2;
  	guint white_space:2;
  	guint list_style_type:5;
};

struct _HtmlStyle {
	gint refcount;

	guint display:6;
	guint visibility:2;

	guint vertical_align:5;
	guint position:3;

	guint Float:2;
	guint overflow:2;
	guint text_transform:2;
	guint clear:3;
	guint unicode_bidi:3;
	guint table_layout:1;
	guint blink:1;
	guint has_hover_style:1;
	guint has_active_style:1;
	guint has_focus_style:1;

	guint has_before_style:1;
	guint has_after_style:1;
	HtmlStyleBorder *border;
	HtmlStyleOutline *outline;
	HtmlStyleBox *box;
	HtmlStyleVisual *visual;
	HtmlStyleSurround *surround;
	HtmlStyleBackground *background;
	HtmlStyleInherited *inherited;

	gchar *content; /* FIXME: support other types then string */
};

HtmlStyle *html_style_new         (HtmlStyle *parent);
HtmlStyle *html_default_style_new (void);
HtmlStyle *html_style_ref         (HtmlStyle *style);
void       html_style_unref       (HtmlStyle *style);

void html_length_set_value (HtmlLength *length, gint value, HtmlLengthType type);
gint html_length_get_value (const HtmlLength *length, gint base);

gboolean html_length_equals         (const HtmlLength *length1, const HtmlLength *length2);
void     html_length_set            (HtmlLength *length, const HtmlLength *length2);
gboolean html_length_from_css_value (HtmlFontSpecification *font_spec, CssValue *val, HtmlLength *length);

void html_style_set_color      (HtmlStyle *style, HtmlColor *color);
void html_style_set_direction  (HtmlStyle *style, HtmlDirectionType direction);
void html_style_set_bidi_level (HtmlStyle *style, int level);

/* FIXME: Remove debugging functions */
void html_debug_print_style (HtmlStyle *style);

/* Functions for inherited properties */
HtmlStyleInherited *html_style_inherited_new           (void);
HtmlStyleInherited *html_style_inherited_dup           (HtmlStyleInherited *inherited);
void                html_style_inherited_ref           (HtmlStyleInherited *inherited);
void                html_style_inherited_unref         (HtmlStyleInherited *inherited);
void                html_style_set_style_inherited     (HtmlStyle *style, HtmlStyleInherited *inherited);
void                html_style_set_color               (HtmlStyle *style, HtmlColor *color);
void                html_style_set_direction           (HtmlStyle *style, HtmlDirectionType direction);
void                html_style_set_bidi_level          (HtmlStyle *style, int level);
void                html_style_set_text_decoration     (HtmlStyle *style, HtmlFontDecorationType decoration);
void                html_style_set_font_variant        (HtmlStyle *style, HtmlFontVariantType variant);
void                html_style_set_font_weight         (HtmlStyle *style, HtmlFontWeightType weight);
void                html_style_set_font_weight_bolder  (HtmlStyle *style);
void                html_style_set_font_weight_lighter (HtmlStyle *style);
void                html_style_set_font_style          (HtmlStyle *style, HtmlFontStyleType font_style);
void                html_style_set_font_family         (HtmlStyle *style, const gchar *family);
void                html_style_set_font_stretch        (HtmlStyle *style, HtmlFontStretchType type);
void                html_style_set_font_size_html      (HtmlStyle *style, gint htmlsize);
void                html_style_set_font_size           (HtmlStyle *style, HtmlFontSpecification *font_spec, CssValue *val);
void                html_style_set_line_height         (HtmlStyle *style, HtmlFontSpecification *font_spec, CssValue *val);
void                html_style_set_cursor              (HtmlStyle *style, HtmlCursorType cursor);
void                html_style_set_border_spacing      (HtmlStyle *style, gushort horiz, gushort vert);
void                html_style_set_caption_side        (HtmlStyle *style, HtmlCaptionSideType type);
void                html_style_set_text_align          (HtmlStyle *style, HtmlTextAlignType type);
void                html_style_set_white_space         (HtmlStyle *style, HtmlWhiteSpaceType type);

/* Functions for box properties */
void          html_style_box_ref        (HtmlStyleBox *box);
void          html_style_box_unref      (HtmlStyleBox *box);
void          html_style_set_style_box  (HtmlStyle *style, HtmlStyleBox *box);
HtmlStyleBox *html_style_box_new        (void);
HtmlStyleBox *html_style_box_dup        (HtmlStyleBox *box);
void          html_style_set_width      (HtmlStyle *style, const HtmlLength *width);
void          html_style_set_height     (HtmlStyle *style, const HtmlLength *height);
void          html_style_set_min_width  (HtmlStyle *style, const HtmlLength *min_width);
void          html_style_set_max_width  (HtmlStyle *style, const HtmlLength *max_width);
void          html_style_set_min_height (HtmlStyle *style, const HtmlLength *min_height);
void          html_style_set_max_height (HtmlStyle *style, const HtmlLength *max_height);

/* Functions for surround properties */
void               html_style_surround_ref        (HtmlStyleSurround *surround);
void               html_style_surround_unref      (HtmlStyleSurround *surround);
void               html_style_set_style_surround  (HtmlStyle *style, HtmlStyleSurround *surround);
HtmlStyleSurround *html_style_surround_new        (void);
HtmlStyleSurround *html_style_surround_dup        (HtmlStyleSurround *surround);
void               html_style_set_position_top    (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_position_left   (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_position_right  (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_position_bottom (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_margin_top      (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_margin_left     (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_margin_right    (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_margin_bottom   (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_padding_top     (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_padding_left    (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_padding_right   (HtmlStyle *style, const HtmlLength *length);
void               html_style_set_padding_bottom  (HtmlStyle *style, const HtmlLength *length);

/* Functions for background properties */
HtmlStyleBackground *html_style_background_ref        (HtmlStyleBackground *background);
void                 html_style_background_unref      (HtmlStyleBackground *background);
void                 html_style_set_style_background  (HtmlStyle *style, HtmlStyleBackground *background);
HtmlStyleBackground *html_style_background_new        (void);
HtmlStyleBackground *html_style_background_dup        (HtmlStyleBackground *background);
void                 html_style_set_background_color  (HtmlStyle *style, HtmlColor *color);
void                 html_style_set_background_image  (HtmlStyle *style, HtmlImage *image);
void                 html_style_set_background_repeat (HtmlStyle *style, HtmlBackgroundRepeatType repeat);

/* Functions for border properties */
void             html_style_border_ref       (HtmlStyleBorder *border);
void             html_style_border_unref     (HtmlStyleBorder *border);
void             html_style_set_style_border (HtmlStyle *style, HtmlStyleBorder *border);
HtmlStyleBorder *html_style_border_new       (void);
HtmlStyleBorder *html_style_border_dup       (HtmlStyleBorder *border);

void html_style_set_border_top_width    (HtmlStyle *style, gint width);
void html_style_set_border_top_style    (HtmlStyle *style, HtmlBorderStyleType border_style);
void html_style_set_border_top_color    (HtmlStyle *style, HtmlColor *color);
void html_style_set_border_right_width  (HtmlStyle *style, gint width);
void html_style_set_border_right_style  (HtmlStyle *style, HtmlBorderStyleType border_style);
void html_style_set_border_right_color  (HtmlStyle *style, HtmlColor *color);
void html_style_set_border_bottom_width (HtmlStyle *style, gint width);
void html_style_set_border_bottom_style (HtmlStyle *style, HtmlBorderStyleType border_style);
void html_style_set_border_bottom_color (HtmlStyle *style, HtmlColor *color);
void html_style_set_border_left_width   (HtmlStyle *style, gint width);
void html_style_set_border_left_style   (HtmlStyle *style, HtmlBorderStyleType border_style);
void html_style_set_border_left_color   (HtmlStyle *style, HtmlColor *color);

/* Functions for outline properties */
HtmlStyleOutline *html_style_outline_ref       (HtmlStyleOutline *outline);
void              html_style_outline_unref     (HtmlStyleOutline *outline);
void              html_style_set_style_outline (HtmlStyle *style, HtmlStyleOutline *outline);
HtmlStyleOutline *html_style_outline_new       (void);
HtmlStyleOutline *html_style_outline_dup       (HtmlStyleOutline *border);

void html_style_set_outline_width (HtmlStyle *style, gint width);
void html_style_set_outline_style (HtmlStyle *style, HtmlBorderStyleType border_style);
void html_style_set_outline_color (HtmlStyle *style, HtmlColor *color);

HtmlStyleChange html_style_compare             (const HtmlStyle *s1, const HtmlStyle *s2);
void            html_style_set_list_style_type (HtmlStyle *style, HtmlListStyleTypeType type);

G_END_DECLS

#endif /* __HTML_ */
