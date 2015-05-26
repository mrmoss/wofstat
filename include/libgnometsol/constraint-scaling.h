/*  2005-09-12 Erwann Chenede - <erwann.chenede@sun.com> */

#ifndef __CONSTRAINT_SCALING_H__
#define __CONSTRAINT_SCALING_H__
#include <gtk/gtk.h>

/* constraint scaling stuff */
typedef struct _ConstraintImage ConstraintImage;
struct _ConstraintImage
{
  gchar     *filename;
  GdkPixbuf *pixbuf;
  GdkPixbuf *scaled;
  gboolean   stretch;
  gint       border_left;
  gint       border_right;
  gint       border_bottom;
  gint       border_top;
  guint      hints[3][3];
  gboolean   recolorable;
  GdkColor   colorize_color;
  gboolean   use_as_bkg_mask;
};

typedef struct _HighlightStripe HighlightStripe;

struct _HighlightStripe
{
  ConstraintImage *image;
  char           *name;
};

typedef enum {
  CONSTRAINT_CONSTANT_ROWS = 1 << 0,
  CONSTRAINT_CONSTANT_COLS = 1 << 1,
  CONSTRAINT_MISSING = 1 << 2
} ConstraintHints;

typedef enum
{
  COMPONENT_NORTH_WEST = 1 << 0,
  COMPONENT_NORTH      = 1 << 1,
  COMPONENT_NORTH_EAST = 1 << 2,
  COMPONENT_WEST       = 1 << 3,
  COMPONENT_CENTER     = 1 << 4,
  COMPONENT_EAST       = 1 << 5,
  COMPONENT_SOUTH_EAST = 1 << 6,
  COMPONENT_SOUTH      = 1 << 7,
  COMPONENT_SOUTH_WEST = 1 << 8,
  COMPONENT_ALL           = 1 << 9
} ConstraintComponent;

void
gnome_tsol_render_coloured_label (GtkWidget *label);

void
gnome_tsol_render_coloured_label_for_zone (GtkWidget *label, const char *zonename);

void
gnome_tsol_constraint_image_render (ConstraintImage *cimage,
				    GdkWindow    *window,
				    GdkBitmap    *mask,
				    GdkRectangle *clip_rect,
				    gboolean      center,
				    gint          x,
				    gint          y,
				    gint          width,
				    gint          height);

void
gnome_tsol_constraint_image_set_border (ConstraintImage *pb,
					gint         left,
					gint         right,
					gint         top,
					gint         bottom);

void
gnome_tsol_constraint_image_set_stretch (ConstraintImage *pb,
					 gboolean     stretch);

void
gnome_tsol_constraint_image_colorize (ConstraintImage *image,
				      GdkColor  *color,
				      int	alpha,
				      gboolean   use_alpha);

#endif /*__CONSTRAINT_SCALING_H__*/
