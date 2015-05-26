#ifndef __HTMLBOXFORM_H__
#define __HTMLBOXFORM_H__

typedef struct _HtmlBoxForm HtmlBoxForm;
typedef struct _HtmlBoxFormClass HtmlBoxFormClass;

#include <gdk/gdk.h>
#include <libgtkhtml/layout/htmlboxblock.h>
#include <libgtkhtml/layout/html/htmlboxembedded.h>

G_BEGIN_DECLS

#define HTML_TYPE_BOX_FORM (html_box_form_get_type ())
#define HTML_BOX_FORM(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), HTML_TYPE_BOX_FORM, HtmlBoxForm))
#define HTML_BOX_FORM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_TYPE_BOX_FORM, HtmlBoxFormClasss))
#define HTML_IS_BOX_FORM(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), HTML_TYPE_BOX_FORM))
#define HTML_IS_BOX_FORM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HTML_TYPE_BOX_FORM))

struct _HtmlBoxForm {
	HtmlBoxBlock parent_object;

	GHashTable *radio_groups;
};

struct _HtmlBoxFormClass {
	HtmlBoxBlockClass parent_class;
};

GType    html_box_form_get_type (void);
HtmlBox *html_box_form_new (void);

GSList *html_box_form_get_radio_group (HtmlBoxForm *form, gchar *id);
void    html_box_form_set_radio_group (HtmlBoxForm *form, gchar *id, GSList *list);

G_END_DECLS

#endif /* __HTMLBOXFORM_H__ */
