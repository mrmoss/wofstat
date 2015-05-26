/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * bonobo-ui-engine.h: The Bonobo UI/XML Sync engine.
 *
 * Author:
 *	Michael Meeks (michael@helixcode.com)
 *
 * Copyright 2000 Helix Code, Inc.
 */

#ifndef _BONOBO_UI_ENGINE_H_
#define _BONOBO_UI_ENGINE_H_

#include <glib/gmacros.h>
#include <bonobo/bonobo-object.h>

G_BEGIN_DECLS

typedef struct _BonoboUIEngine BonoboUIEngine;

#include <bonobo/bonobo-ui-container.h>

/* Various useful bits */
void bonobo_ui_engine_deregister_dead_components     (BonoboUIEngine *engine);
void bonobo_ui_engine_deregister_component_by_ref    (BonoboUIEngine *engine,
						      Bonobo_Unknown  ref);
void bonobo_ui_engine_deregister_component           (BonoboUIEngine *engine,
						      const char     *name);
void bonobo_ui_engine_register_component             (BonoboUIEngine *engine,
						      const char     *name,
						      Bonobo_Unknown  component);
GList         *bonobo_ui_engine_get_component_names  (BonoboUIEngine *engine);
Bonobo_Unknown bonobo_ui_engine_get_component        (BonoboUIEngine *engine,
						      const char     *name);

/* Configuration stuff */
void               bonobo_ui_engine_config_set_path  (BonoboUIEngine *engine,
						      const char     *path);
const char        *bonobo_ui_engine_config_get_path  (BonoboUIEngine *engine);

/* Misc. */
void               bonobo_ui_engine_set_ui_container (BonoboUIEngine    *engine,
						      BonoboUIContainer *ui_container);
BonoboUIContainer *bonobo_ui_engine_get_ui_container (BonoboUIEngine    *engine);


/* Used in Nautilus */
#ifndef BONOBO_UI_DISABLE_DEPRECATED
void bonobo_ui_engine_freeze (BonoboUIEngine *engine);
void bonobo_ui_engine_thaw   (BonoboUIEngine *engine);
void bonobo_ui_engine_update (BonoboUIEngine *engine);
#endif

#define BONOBO_TYPE_UI_ENGINE            (bonobo_ui_engine_get_type ())
#define BONOBO_UI_ENGINE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BONOBO_TYPE_UI_ENGINE, BonoboUIEngine))
#define BONOBO_UI_ENGINE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BONOBO_TYPE_UI_ENGINE, BonoboUIEngineClass))
#define BONOBO_IS_UI_ENGINE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BONOBO_TYPE_UI_ENGINE))
#define BONOBO_IS_UI_ENGINE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BONOBO_TYPE_UI_ENGINE))

GType         bonobo_ui_engine_get_type      (void) G_GNUC_CONST;

/* Private - implementation details */
#ifdef BONOBO_UI_INTERNAL

typedef enum {
	BONOBO_UI_ERROR_OK = 0,
	BONOBO_UI_ERROR_BAD_PARAM,
	BONOBO_UI_ERROR_INVALID_PATH,
	BONOBO_UI_ERROR_INVALID_XML
} BonoboUIError;

#include <bonobo/bonobo-ui-sync.h>

typedef struct _BonoboUIEnginePrivate BonoboUIEnginePrivate;

struct _BonoboUIEngine {
	GObject parent;

	BonoboUIEnginePrivate *priv;
};

typedef struct {
	GObjectClass parent_class;

	/* Signals */
	void (*add_hint)      (BonoboUIEngine *engine,
			       const char     *str);
	void (*remove_hint)   (BonoboUIEngine *engine);

	void (*emit_verb_on)  (BonoboUIEngine *engine,
			       BonoboUINode   *node);

	void (*emit_event_on) (BonoboUIEngine *engine,
			       BonoboUINode   *node,
			       const char     *state);

	void (*destroy)       (BonoboUIEngine *engine);

} BonoboUIEngineClass;

BonoboUIEngine *bonobo_ui_engine_construct     (BonoboUIEngine   *engine,
						GObject          *view);
BonoboUIEngine *bonobo_ui_engine_new           (GObject          *view);
GObject        *bonobo_ui_engine_get_view      (BonoboUIEngine   *engine);

void          bonobo_ui_engine_add_sync        (BonoboUIEngine   *engine,
						BonoboUISync     *sync);
void          bonobo_ui_engine_remove_sync     (BonoboUIEngine   *engine,
						BonoboUISync     *sync);
GSList       *bonobo_ui_engine_get_syncs       (BonoboUIEngine   *engine);

void          bonobo_ui_engine_update_node     (BonoboUIEngine   *engine,
						BonoboUISync     *sync,
						BonoboUINode     *node);
void          bonobo_ui_engine_queue_update    (BonoboUIEngine   *engine,
						GtkWidget        *widget,
						BonoboUINode     *node,
						BonoboUINode     *cmd_node);

GtkWidget    *bonobo_ui_engine_build_control   (BonoboUIEngine   *engine,
						BonoboUINode     *node);

BonoboUINode *bonobo_ui_engine_widget_get_node   (GtkWidget        *widget);
void          bonobo_ui_engine_widget_set_node   (BonoboUIEngine   *engine,
						  GtkWidget        *widget,
						  BonoboUINode     *node);
BonoboUIError bonobo_ui_engine_xml_set_prop      (BonoboUIEngine   *engine,
						  const char       *path,
						  const char       *property,
						  const char       *value,
						  const char       *component);
CORBA_char   *bonobo_ui_engine_xml_get_prop      (BonoboUIEngine   *engine,
						  const char       *path,
						  const char       *prop,
						  gboolean         *invalid_path);
void          bonobo_ui_engine_prune_widget_info (BonoboUIEngine   *engine,
						  BonoboUINode     *node,
						  gboolean          save_custom);

BonoboUINode *bonobo_ui_engine_get_path        (BonoboUIEngine   *engine,
						const char       *path);
void          bonobo_ui_engine_dirty_tree      (BonoboUIEngine   *engine,
						BonoboUINode     *node);
void          bonobo_ui_engine_clean_tree      (BonoboUIEngine   *engine,
						BonoboUINode     *node);
void          bonobo_ui_engine_dump            (BonoboUIEngine   *engine,
						FILE             *out,
						const char       *msg);

/* Extra Node data accessors */
CORBA_Object  bonobo_ui_engine_node_get_object (BonoboUIEngine   *engine,
						BonoboUINode     *node);
gboolean      bonobo_ui_engine_node_is_dirty   (BonoboUIEngine   *engine,
						BonoboUINode     *node);
GtkWidget    *bonobo_ui_engine_node_get_widget (BonoboUIEngine   *engine,
						BonoboUINode     *node);
const char   *bonobo_ui_engine_node_get_id     (BonoboUIEngine   *engine,
						BonoboUINode     *node);
BonoboUINode *bonobo_ui_engine_get_cmd_node    (BonoboUIEngine   *engine,
						BonoboUINode     *from_node);
void          bonobo_ui_engine_node_set_dirty  (BonoboUIEngine   *engine,
						BonoboUINode     *node,
						gboolean          dirty);
void          bonobo_ui_engine_stamp_custom    (BonoboUIEngine *engine,
						BonoboUINode   *node);
void          bonobo_ui_engine_widget_set      (BonoboUIEngine    *engine,
						const char        *path,
						GtkWidget         *widget);
void          bonobo_ui_engine_stamp_root      (BonoboUIEngine *engine,
						BonoboUINode   *node,
						GtkWidget      *widget);
/* Signal firers */
void          bonobo_ui_engine_add_hint        (BonoboUIEngine   *engine,
						const char       *str);
void          bonobo_ui_engine_remove_hint     (BonoboUIEngine   *engine);
void          bonobo_ui_engine_emit_verb_on    (BonoboUIEngine   *engine,
						BonoboUINode     *node);
void          bonobo_ui_engine_emit_event_on   (BonoboUIEngine   *engine,
						BonoboUINode     *node,
						const char       *state);
void          bonobo_ui_engine_emit_verb_on_w  (BonoboUIEngine   *engine,
						GtkWidget        *widget);
void          bonobo_ui_engine_emit_event_on_w (BonoboUIEngine   *engine,
						GtkWidget        *widget,
						const char       *state);


/* Helpers */
char         *bonobo_ui_engine_get_attr           (BonoboUINode     *node,
						   BonoboUINode     *cmd_node,
						   const char       *attr);
void          bonobo_ui_engine_widget_attach_node (GtkWidget        *widget,
						   BonoboUINode     *node);


/* Interface used by UIContainer maps to BonoboUIXml */
CORBA_char      *bonobo_ui_engine_xml_get         (BonoboUIEngine   *engine,
						   const char       *path,
						   gboolean          node_only);
gboolean         bonobo_ui_engine_xml_node_exists (BonoboUIEngine   *engine,
						   const char       *path);
BonoboUIError    bonobo_ui_engine_xml_merge_tree  (BonoboUIEngine    *engine,
						   const char        *path,
						   BonoboUINode      *tree,
						   const char        *component);
BonoboUIError    bonobo_ui_engine_xml_rm          (BonoboUIEngine    *engine,
						   const char        *path,
						   const char        *by_component);
BonoboUIError    bonobo_ui_engine_object_set      (BonoboUIEngine   *engine,
						   const char       *path,
						   Bonobo_Unknown    object,
						   CORBA_Environment *ev);
BonoboUIError    bonobo_ui_engine_object_get      (BonoboUIEngine    *engine,
						   const char        *path,
						   Bonobo_Unknown    *object,
						   CORBA_Environment *ev);

void bonobo_ui_engine_exec_verb (BonoboUIEngine                    *engine,
				 const CORBA_char                  *cname,
				 CORBA_Environment                 *ev);
void bonobo_ui_engine_ui_event  (BonoboUIEngine                    *engine,
				 const CORBA_char                  *id,
				 const Bonobo_UIComponent_EventType type,
				 const CORBA_char                  *state,
				 CORBA_Environment                 *ev);

#endif /* BONOBO_UI_INTERNAL */

G_END_DECLS

#endif /* _BONOBO_UI_ENGINE_H_ */
