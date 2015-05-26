/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef LABEL_BUILDER_H
#define LABEL_BUILDER_H

G_BEGIN_DECLS

#include <tsol/label.h>
#include <glib.h>
#include <gtk/gtkdialog.h>

#define GNOME_TYPE_LABEL_BUILDER            (gnome_label_builder_get_type ())
#define GNOME_LABEL_BUILDER(obj)            (GTK_CHECK_CAST ((obj), GNOME_TYPE_LABEL_BUILDER, GnomeLabelBuilder))
#define GNOME_LABEL_BUILDER_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), GNOME_TYPE_LABEL_BUILDER, GnomeLabelBuilderClass))
#define GNOME_IS_LABEL_BUILDER(obj)         (GTK_CHECK_TYPE ((obj), GNOME_TYPE_LABEL_BUILDER))
#define GNOME_IS_LABEL_BUILDER_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GNOME_TYPE_LABEL_BUILDER))

enum {
	LBUILD_MODE_SL,
	LBUILD_MODE_CLR
};

enum {
	PROP_LBUILD_0,
	PROP_MODE,
	PROP_MESSAGE,
	PROP_SL,
	PROP_CLR,
	PROP_UPPER_BOUND,
	PROP_LOWER_BOUND
};

typedef struct _GnomeLabelBuilderDetails	GnomeLabelBuilderDetails;

typedef struct _GnomeLabelBuilder {
        GtkDialog parent;
	
        GnomeLabelBuilderDetails *details;
} GnomeLabelBuilder;

typedef struct _GnomeLabelBuilderClass {
	GtkDialogClass parent_class;

} GnomeLabelBuilderClass;

GType gnome_label_builder_get_type (void);
GtkWidget *gnome_label_builder_new (char *msg, blevel_t *upper,
				    blevel_t *lower, int mode);

gboolean gnome_label_builder_show_help (GtkWidget *w);
G_END_DECLS

#endif /* LABEL_BUILDER_H */

