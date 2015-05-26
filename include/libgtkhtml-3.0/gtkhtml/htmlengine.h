/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library

   Copyright (C) 1997 Martin Jones (mjones@kde.org)
   Copyright (C) 1997 Torben Weis (weis@kde.org)
   Copyright (C) 1999, 2000 Helix Code, Inc.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef _HTMLENGINE_H_
#define _HTMLENGINE_H_

#include <glib-object.h>
#include <gdk/gdktypes.h>
#include <gtk/gtkwidget.h>
#include "gtkhtml-types.h"

#include "htmltypes.h"
#include "htmlenums.h"
#include "htmlcursor.h"


#define HTML_TYPE_ENGINE                 (html_engine_get_type ())
#define HTML_ENGINE(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), HTML_TYPE_ENGINE, HTMLEngine))
#define HTML_ENGINE_CLASS(klass)         (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_ENGINE, HTMLEngineClass))
#define HTML_IS_ENGINE(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HTML_TYPE_ENGINE))
#define HTML_IS_ENGINE_CLASS(klass)      (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_ENGINE))


/* FIXME extreme hideous ugliness in the following lines.  */

#define LEFT_BORDER 10
#define RIGHT_BORDER 10
#define TOP_BORDER 10
#define BOTTOM_BORDER 10

/* FIXME this needs splitting.  */

struct _HTMLEngine {
	GObject parent;
	HTMLDrawQueue *draw_queue;

	HTMLPainter *painter;

	HTMLSettings *settings;
	HTMLSettings *defaultSettings;

	HTMLUndo *undo;

	GdkWindow *window;
	GdkGC *invert_gc;

	gboolean editable;
	gboolean caret_mode;

	HTMLObject *clipboard;
	guint       clipboard_len;
	GList      *clipboard_stack;

	HTMLObject *primary;
	guint       primary_len;

	/* Freeze counter.  When greater than zero, we never trigger relayouts
           nor repaints.  When going from nonzero to zero, we relayout and
           repaint everything.  */
	guint freeze_count;
	guint thaw_idle_id;
	gint block_redraw;
	gboolean need_redraw;
	GSList *pending_expose;

	gboolean parsing;
	HTMLTokenizer *ht;
	HTMLStringTokenizer *st;
	HTMLObject *clue;
	
	HTMLObject *flow;

	gint leftBorder;
	gint rightBorder;
	gint topBorder;
	gint bottomBorder;

	/* Current indentation level.  */
	guint indent_level;

	/* For the widget */
	gint width;
	gint height;

	HTMLHAlignType divAlign;
	HTMLHAlignType pAlign;

	/* Number of tokens parsed in the current time-slice */
	gint parseCount;
	gint granularity;

	/* Offsets */
	gint x_offset, y_offset;

	gboolean inTitle;
	gboolean inPre;
	gboolean inOption;
	gboolean inTextArea;
	gboolean eat_space;
	gboolean allow_frameset;
	gboolean newPage;
	gboolean begin;
 
	HTMLStack *span_stack;
	HTMLStack *clueflow_style_stack; /* Clueflow style stack, elements are HTMLClueFlowStyles.  */
	HTMLStack *frame_stack;
	HTMLStack *body_stack;

	gchar *url;
	gchar *target;

	HTMLBlockStackElement *blockStack;

	/* timer id to schedule paint events */
	guint updateTimer;

	/* timer id for parsing routine */
	guint timerId;

	guint redraw_idle_id;

	/* FIXME: replace with a `gchar *'?  */
	GString *title;

	gboolean writing;

	/* The background pixmap, an HTMLImagePointer */
        gpointer bgPixmapPtr;
  
	/* Stack of lists currently active */
	HTMLStack *listStack;

	/* Stack of embedded "object"'s */
	HTMLStack *embeddedStack;

	/* The associated widget.  */
	GtkHTML *widget;

        gpointer image_factory;

	/*
	 * This list holds strings which are displayed in the view,
	 * but are not actually contained in the HTML source.
	 * e.g. The numbers in an ordered list.
	 * FIXME?
	 */
	GList *tempStrings;

	HTMLMap *map;
	HTMLForm *form;
	HTMLSelect *formSelect;
	HTMLTextArea *formTextArea;
	GList *formList;
	GString *formText;

	/* This is TRUE if we cannot insert a paragraph break (which is just an
           extra empty line).  It's set to FALSE as soon as some element is
           added to a flow.  The purpose is to avoid having paragraph breaks to
           be inserted in sequence, or after elements that have some vspace of
           their own.  */
	gboolean avoid_para;

	/* This is TRUE if we want a paragraph break to be inserted before the
           next element.  */
	gboolean pending_para;

	/* Alignment for the pending paragraph we are going to insert.  */
	HTMLHAlignType pending_para_alignment;

	/* Whether we have the keyboard focus.  */
	guint have_focus : 1;

	HTMLInterval *selection;
	gboolean selected_in;

	/* --- */

	/* Editing stuff.  -- FIXME it should be in a separate object.  */

	/* The current position of the cursor.  */
	HTMLCursor *cursor;

	/* If no region is active, this is NULL.  Otherwise, this is
           one extreme of the selected region.  The other extreme is
           always the cursor.  */
	HTMLCursor *mark;

	/* Hide counter for the cursor.  When greater than zero, it
           means the cursor is invisible.  */
	gint cursor_hide_count;

	/* Timer ID for cursor blink.  */
	gint blinking_timer_id;

	/* Blinking status (visible/invisible).  */
	gboolean blinking_status;

	/* Font style for insertion.  If HTML_FONT_STYLE_DEFAULT, use that of
           the text we are in.  */
	GtkHTMLFontStyle  insertion_font_style;
	HTMLColor        *insertion_color;
	gchar            *insertion_url;
	gchar            *insertion_target;

	/* if we are doing shift selection - Shift + some event (arrows, mouse motion, ...) */
	gboolean shift_selection;

	/* This object is used to update the keyboard selection in the
           idle loop.  */
	HTMLEngineEditSelectionUpdater *selection_updater;

	/* keeps selection between operation, which are changing selection
	   and need restore it after done */
	GList *selection_stack;

	/* search & replace */
	HTMLSearch  *search_info;
	HTMLReplace *replace_info;

	/* id-to-object mapping */
	GHashTable *id_table;

	/* table contains data, which are set to objects by type during parse time */
	GHashTable *class_data;

	/* table of maps */
	GHashTable *map_table;

	gdouble min_split_index;

	gboolean need_spell_check;
	gint block_events;
	gchar *language;

	GSList *cursor_position_stack;
	gboolean selection_mode;
	gint block_selection;

	HTMLCursorRectangle cursor_cell;
	HTMLCursorRectangle cursor_table;
	HTMLCursorRectangle cursor_image;

	GList *cut_and_paste_stack;

	gboolean block;
	gint opened_streams;

	HTMLObject *focus_object;

	gboolean save_data;
	gint saved_step_count;

	gboolean expose;
	gboolean need_update;
};

/* must be forward referenced *sigh* */
struct _HTMLEmbedded;

struct _HTMLEngineClass {
	GObjectClass parent_class;
	
	void (* title_changed) (HTMLEngine *engine);
	void (* set_base) (HTMLEngine *engine, const gchar *base);
	void (* set_base_target) (HTMLEngine *engine, const gchar *base_target);
	void (* load_done) (HTMLEngine *engine);
        void (* url_requested) (HTMLEngine *engine, const char *url, GtkHTMLStream *handle);
	void (* draw_pending) (HTMLEngine *engine);
        void (* redirect) (HTMLEngine *engine, const char *url, int delay);
        void (* submit) (HTMLEngine *engine, const gchar *method, const gchar *action, const gchar *encoding);
	gboolean (* object_requested) (HTMLEngine *engine, GtkHTMLEmbedded *);
};


/* Object construction.  */
guint       html_engine_get_type      (void);
HTMLEngine *html_engine_new           (GtkWidget *);
void        html_engine_realize       (HTMLEngine *engine,
				       GdkWindow  *window);
void        html_engine_unrealize     (HTMLEngine *engine);

void      html_engine_saved     (HTMLEngine *e);
gboolean  html_engine_is_saved  (HTMLEngine *e);

/* Editability control.  */
void      html_engine_set_editable  (HTMLEngine *e,
				     gboolean    editable);
gboolean  html_engine_get_editable  (HTMLEngine *e);

/* Focus.  */
void  html_engine_set_focus  (HTMLEngine *engine,
			      gboolean    have_focus);

/* Tokenizer. */
void html_engine_set_tokenizer (HTMLEngine *engine,
				HTMLTokenizer *tok);

/* Parsing control.  */
GtkHTMLStream *html_engine_begin            (HTMLEngine  *p, 
					     char        *content_type);
void           html_engine_parse            (HTMLEngine  *p);
void           html_engine_stop_parser      (HTMLEngine  *e);

/* Rendering control.  */
gint  html_engine_calc_min_width       (HTMLEngine *e);
gboolean  html_engine_calc_size        (HTMLEngine *e,
					GList     **changed_objs);
gint  html_engine_get_doc_height       (HTMLEngine *p);
gint  html_engine_get_doc_width        (HTMLEngine *e);
gint  html_engine_get_max_width        (HTMLEngine *e);
gint  html_engine_get_max_height       (HTMLEngine *e);
void  html_engine_draw                 (HTMLEngine *e,
					gint        x,
					gint        y,
					gint        width,
					gint        height);
void  html_engine_expose               (HTMLEngine *e,
					GdkEventExpose *event);
void  html_engine_draw_background      (HTMLEngine *e,
					gint        x,
					gint        y,
					gint        width,
					gint        height);

/* Scrolling.  */
void      html_engine_schedule_update      (HTMLEngine  *e);
void      html_engine_schedule_redraw      (HTMLEngine  *e);
void      html_engine_block_redraw         (HTMLEngine  *e);
void      html_engine_unblock_redraw       (HTMLEngine  *e);
gboolean  html_engine_make_cursor_visible  (HTMLEngine  *e);
gboolean  html_engine_goto_anchor          (HTMLEngine  *e,
					    const gchar *anchor);

/* Draw/clear queue.  */
void  html_engine_flush_draw_queue  (HTMLEngine *e);
void  html_engine_queue_draw        (HTMLEngine *e,
				     HTMLObject *o);
void  html_engine_queue_clear       (HTMLEngine *e,
				     gint        x,
				     gint        y,
				     guint       width,
				     guint       height);

void  html_engine_set_painter       (HTMLEngine  *e,
				     HTMLPainter *painter);

/* Getting objects through pointer positions.  */
HTMLObject  *html_engine_get_object_at  (HTMLEngine *e,
					 gint        x,
					 gint        y,
					 guint      *offset_return,
					 gboolean    for_cursor);
HTMLPoint   *html_engine_get_point_at   (HTMLEngine *e,
					 gint        x,
					 gint        y,
					 gboolean    for_cursor);
const gchar *html_engine_get_link_at    (HTMLEngine *e,
					 gint        x,
					 gint        y);

/* Form support.  */
void  html_engine_form_submitted  (HTMLEngine  *engine,
				   const gchar *method,
				   const gchar *action,
				   const gchar *encoding);

/* Misc.  (FIXME: Should die?) */
gchar *html_engine_canonicalize_url  (HTMLEngine *e,
				      const char *in_url);

/* Cursor */
HTMLCursor *html_engine_get_cursor        (HTMLEngine *e);
void        html_engine_normalize_cursor  (HTMLEngine *e);

/* Freezing/thawing.  */
gboolean  html_engine_frozen  (HTMLEngine *engine);
void      html_engine_freeze  (HTMLEngine *engine);
void      html_engine_thaw    (HTMLEngine *engine);

/* Creating an empty document.  */
void      html_engine_load_empty                (HTMLEngine *engine);

/* Search & Replace */

void      html_engine_replace                   (HTMLEngine *e,
						 const gchar *text,
						 const gchar *rep_text,
						 gboolean case_sensitive,
						 gboolean forward,
						 gboolean regular,
						 void (*ask)(HTMLEngine *, gpointer), gpointer ask_data);
void      html_engine_replace_do                (HTMLEngine *e, HTMLReplaceQueryAnswer answer);
gint      html_engine_replaced                  (void);

/* Magic links */
void      html_engine_init_magic_links          (void);

/* spell checking */
void      html_engine_spell_check              (HTMLEngine  *e);
void      html_engine_clear_spell_check        (HTMLEngine  *e);
gchar    *html_engine_get_spell_word           (HTMLEngine  *e);
gboolean  html_engine_spell_word_is_valid      (HTMLEngine  *e);
void      html_engine_replace_spell_word_with  (HTMLEngine  *e,
						const gchar *word);
void      html_engine_set_language             (HTMLEngine  *e,
						const gchar *language);
const gchar *html_engine_get_language          (HTMLEngine *e);

/* view size - for image size specified in percent */
gint  html_engine_get_view_width   (HTMLEngine *e);
gint  html_engine_get_view_height  (HTMLEngine *e);

/* id support */
void        html_engine_add_object_with_id  (HTMLEngine  *e,
					     const gchar *id,
					     HTMLObject  *obj);
HTMLObject *html_engine_get_object_by_id    (HTMLEngine  *e,
					     const gchar *id);

HTMLEngine *html_engine_get_top_html_engine (HTMLEngine *e);
void        html_engine_thaw_idle_flush     (HTMLEngine *e);

/* class data */
const gchar *html_engine_get_class_data        (HTMLEngine  *e,
						const gchar *class_name,
						const gchar *key);
GHashTable  *html_engine_get_class_table       (HTMLEngine  *e,
						const gchar *class_name);
void         html_engine_set_class_data        (HTMLEngine  *e,
						const gchar *class_name,
						const gchar *key,
						const gchar *value);
void         html_engine_clear_class_data      (HTMLEngine  *e,
						const gchar *class_name,
						const gchar *key);
void         html_engine_clear_all_class_data  (HTMLEngine  *e);
gboolean  html_engine_intersection  (HTMLEngine *e,
				     gint       *x1,
				     gint       *y1,
				     gint       *x2,
				     gint       *y2);
void  html_engine_add_expose  (HTMLEngine *e,
			       gint        x,
			       gint        y,
			       gint        width,
			       gint        height,
			       gboolean    expose);
void html_engine_redraw_selection (HTMLEngine *e);

gboolean    html_engine_focus              (HTMLEngine       *e,
					    GtkDirectionType  dir);
HTMLObject *html_engine_get_focus_object   (HTMLEngine       *e);
void        html_engine_set_focus_object   (HTMLEngine       *e,
					    HTMLObject       *o);
void        html_engine_update_focus_if_necessary (HTMLEngine	*e, 
						   HTMLObject	*o,
						   gint		offset);
void        html_engine_draw_focus_object  (HTMLEngine       *e);

HTMLMap *html_engine_get_map  (HTMLEngine  *e,
			       const gchar *name);

gboolean html_engine_selection_contains_object_type (HTMLEngine *e,
						     HTMLType obj_type);
gboolean html_engine_selection_contains_link        (HTMLEngine *e);

#endif /* _HTMLENGINE_H_ */
