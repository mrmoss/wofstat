
#ifndef __e_marshal_MARSHAL_H__
#define __e_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* BOOLEAN:INT,INT,OBJECT,INT,INT,UINT (e-marshal.list:1) */
extern void e_marshal_BOOLEAN__INT_INT_OBJECT_INT_INT_UINT (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* BOOLEAN:INT,POINTER,INT,OBJECT,INT,INT,UINT (e-marshal.list:2) */
extern void e_marshal_BOOLEAN__INT_POINTER_INT_OBJECT_INT_INT_UINT (GClosure     *closure,
                                                                    GValue       *return_value,
                                                                    guint         n_param_values,
                                                                    const GValue *param_values,
                                                                    gpointer      invocation_hint,
                                                                    gpointer      marshal_data);

/* BOOLEAN:NONE (e-marshal.list:3) */
extern void e_marshal_BOOLEAN__VOID (GClosure     *closure,
                                     GValue       *return_value,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint,
                                     gpointer      marshal_data);
#define e_marshal_BOOLEAN__NONE	e_marshal_BOOLEAN__VOID

/* BOOLEAN:OBJECT (e-marshal.list:4) */
extern void e_marshal_BOOLEAN__OBJECT (GClosure     *closure,
                                       GValue       *return_value,
                                       guint         n_param_values,
                                       const GValue *param_values,
                                       gpointer      invocation_hint,
                                       gpointer      marshal_data);

/* BOOLEAN:OBJECT,DOUBLE,DOUBLE,BOOLEAN (e-marshal.list:5) */
extern void e_marshal_BOOLEAN__OBJECT_DOUBLE_DOUBLE_BOOLEAN (GClosure     *closure,
                                                             GValue       *return_value,
                                                             guint         n_param_values,
                                                             const GValue *param_values,
                                                             gpointer      invocation_hint,
                                                             gpointer      marshal_data);

/* BOOLEAN:POINTER,POINTER,INT,INT,INT (e-marshal.list:6) */
extern void e_marshal_BOOLEAN__POINTER_POINTER_INT_INT_INT (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* BOOLEAN:POINTER,POINTER,POINTER,INT,INT,INT (e-marshal.list:7) */
extern void e_marshal_BOOLEAN__POINTER_POINTER_POINTER_INT_INT_INT (GClosure     *closure,
                                                                    GValue       *return_value,
                                                                    guint         n_param_values,
                                                                    const GValue *param_values,
                                                                    gpointer      invocation_hint,
                                                                    gpointer      marshal_data);

/* BOOLEAN:STRING,INT (e-marshal.list:8) */
extern void e_marshal_BOOLEAN__STRING_INT (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* DOUBLE:OBJECT,DOUBLE,DOUBLE,BOOLEAN (e-marshal.list:9) */
extern void e_marshal_DOUBLE__OBJECT_DOUBLE_DOUBLE_BOOLEAN (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* INT:BOXED (e-marshal.list:10) */
extern void e_marshal_INT__BOXED (GClosure     *closure,
                                  GValue       *return_value,
                                  guint         n_param_values,
                                  const GValue *param_values,
                                  gpointer      invocation_hint,
                                  gpointer      marshal_data);

/* INT:INT (e-marshal.list:11) */
extern void e_marshal_INT__INT (GClosure     *closure,
                                GValue       *return_value,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint,
                                gpointer      marshal_data);

/* INT:INT,INT,BOXED (e-marshal.list:12) */
extern void e_marshal_INT__INT_INT_BOXED (GClosure     *closure,
                                          GValue       *return_value,
                                          guint         n_param_values,
                                          const GValue *param_values,
                                          gpointer      invocation_hint,
                                          gpointer      marshal_data);

/* INT:INT,POINTER,INT,BOXED (e-marshal.list:13) */
extern void e_marshal_INT__INT_POINTER_INT_BOXED (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);

/* INT:OBJECT,BOXED (e-marshal.list:14) */
extern void e_marshal_INT__OBJECT_BOXED (GClosure     *closure,
                                         GValue       *return_value,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint,
                                         gpointer      marshal_data);

/* INT:POINTER (e-marshal.list:15) */
extern void e_marshal_INT__POINTER (GClosure     *closure,
                                    GValue       *return_value,
                                    guint         n_param_values,
                                    const GValue *param_values,
                                    gpointer      invocation_hint,
                                    gpointer      marshal_data);

/* NONE:BOXED (e-marshal.list:16) */
#define e_marshal_VOID__BOXED	g_cclosure_marshal_VOID__BOXED
#define e_marshal_NONE__BOXED	e_marshal_VOID__BOXED

/* NONE:BOXED,INT (e-marshal.list:17) */
extern void e_marshal_VOID__BOXED_INT (GClosure     *closure,
                                       GValue       *return_value,
                                       guint         n_param_values,
                                       const GValue *param_values,
                                       gpointer      invocation_hint,
                                       gpointer      marshal_data);
#define e_marshal_NONE__BOXED_INT	e_marshal_VOID__BOXED_INT

/* NONE:BOXED,INT,INT (e-marshal.list:18) */
extern void e_marshal_VOID__BOXED_INT_INT (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);
#define e_marshal_NONE__BOXED_INT_INT	e_marshal_VOID__BOXED_INT_INT

/* NONE:DOUBLE (e-marshal.list:19) */
#define e_marshal_VOID__DOUBLE	g_cclosure_marshal_VOID__DOUBLE
#define e_marshal_NONE__DOUBLE	e_marshal_VOID__DOUBLE

/* NONE:INT (e-marshal.list:20) */
#define e_marshal_VOID__INT	g_cclosure_marshal_VOID__INT
#define e_marshal_NONE__INT	e_marshal_VOID__INT

/* NONE:INT,INT (e-marshal.list:21) */
extern void e_marshal_VOID__INT_INT (GClosure     *closure,
                                     GValue       *return_value,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint,
                                     gpointer      marshal_data);
#define e_marshal_NONE__INT_INT	e_marshal_VOID__INT_INT

/* NONE:INT,INT,BOXED (e-marshal.list:22) */
extern void e_marshal_VOID__INT_INT_BOXED (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);
#define e_marshal_NONE__INT_INT_BOXED	e_marshal_VOID__INT_INT_BOXED

/* NONE:INT,INT,OBJECT (e-marshal.list:23) */
extern void e_marshal_VOID__INT_INT_OBJECT (GClosure     *closure,
                                            GValue       *return_value,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint,
                                            gpointer      marshal_data);
#define e_marshal_NONE__INT_INT_OBJECT	e_marshal_VOID__INT_INT_OBJECT

/* NONE:INT,INT,OBJECT,BOXED,UINT,UINT (e-marshal.list:24) */
extern void e_marshal_VOID__INT_INT_OBJECT_BOXED_UINT_UINT (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);
#define e_marshal_NONE__INT_INT_OBJECT_BOXED_UINT_UINT	e_marshal_VOID__INT_INT_OBJECT_BOXED_UINT_UINT

/* NONE:INT,INT,OBJECT,INT,INT,BOXED,UINT,UINT (e-marshal.list:25) */
extern void e_marshal_VOID__INT_INT_OBJECT_INT_INT_BOXED_UINT_UINT (GClosure     *closure,
                                                                    GValue       *return_value,
                                                                    guint         n_param_values,
                                                                    const GValue *param_values,
                                                                    gpointer      invocation_hint,
                                                                    gpointer      marshal_data);
#define e_marshal_NONE__INT_INT_OBJECT_INT_INT_BOXED_UINT_UINT	e_marshal_VOID__INT_INT_OBJECT_INT_INT_BOXED_UINT_UINT

/* NONE:INT,INT,OBJECT,POINTER,UINT,UINT (e-marshal.list:26) */
extern void e_marshal_VOID__INT_INT_OBJECT_POINTER_UINT_UINT (GClosure     *closure,
                                                              GValue       *return_value,
                                                              guint         n_param_values,
                                                              const GValue *param_values,
                                                              gpointer      invocation_hint,
                                                              gpointer      marshal_data);
#define e_marshal_NONE__INT_INT_OBJECT_POINTER_UINT_UINT	e_marshal_VOID__INT_INT_OBJECT_POINTER_UINT_UINT

/* NONE:INT,INT,OBJECT,UINT (e-marshal.list:27) */
extern void e_marshal_VOID__INT_INT_OBJECT_UINT (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);
#define e_marshal_NONE__INT_INT_OBJECT_UINT	e_marshal_VOID__INT_INT_OBJECT_UINT

/* NONE:INT,INT,STRING,STRING (e-marshal.list:28) */
extern void e_marshal_VOID__INT_INT_STRING_STRING (GClosure     *closure,
                                                   GValue       *return_value,
                                                   guint         n_param_values,
                                                   const GValue *param_values,
                                                   gpointer      invocation_hint,
                                                   gpointer      marshal_data);
#define e_marshal_NONE__INT_INT_STRING_STRING	e_marshal_VOID__INT_INT_STRING_STRING

/* NONE:INT,INT,STRING,STRING,POINTER (e-marshal.list:29) */
extern void e_marshal_VOID__INT_INT_STRING_STRING_POINTER (GClosure     *closure,
                                                           GValue       *return_value,
                                                           guint         n_param_values,
                                                           const GValue *param_values,
                                                           gpointer      invocation_hint,
                                                           gpointer      marshal_data);
#define e_marshal_NONE__INT_INT_STRING_STRING_POINTER	e_marshal_VOID__INT_INT_STRING_STRING_POINTER

/* NONE:INT,POINTER (e-marshal.list:30) */
extern void e_marshal_VOID__INT_POINTER (GClosure     *closure,
                                         GValue       *return_value,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint,
                                         gpointer      marshal_data);
#define e_marshal_NONE__INT_POINTER	e_marshal_VOID__INT_POINTER

/* NONE:INT,POINTER,INT,BOXED (e-marshal.list:31) */
extern void e_marshal_VOID__INT_POINTER_INT_BOXED (GClosure     *closure,
                                                   GValue       *return_value,
                                                   guint         n_param_values,
                                                   const GValue *param_values,
                                                   gpointer      invocation_hint,
                                                   gpointer      marshal_data);
#define e_marshal_NONE__INT_POINTER_INT_BOXED	e_marshal_VOID__INT_POINTER_INT_BOXED

/* NONE:INT,POINTER,INT,OBJECT (e-marshal.list:32) */
extern void e_marshal_VOID__INT_POINTER_INT_OBJECT (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);
#define e_marshal_NONE__INT_POINTER_INT_OBJECT	e_marshal_VOID__INT_POINTER_INT_OBJECT

/* NONE:INT,POINTER,INT,OBJECT,BOXED,UINT,UINT (e-marshal.list:33) */
extern void e_marshal_VOID__INT_POINTER_INT_OBJECT_BOXED_UINT_UINT (GClosure     *closure,
                                                                    GValue       *return_value,
                                                                    guint         n_param_values,
                                                                    const GValue *param_values,
                                                                    gpointer      invocation_hint,
                                                                    gpointer      marshal_data);
#define e_marshal_NONE__INT_POINTER_INT_OBJECT_BOXED_UINT_UINT	e_marshal_VOID__INT_POINTER_INT_OBJECT_BOXED_UINT_UINT

/* NONE:INT,POINTER,INT,OBJECT,INT,INT,BOXED,UINT,UINT (e-marshal.list:34) */
extern void e_marshal_VOID__INT_POINTER_INT_OBJECT_INT_INT_BOXED_UINT_UINT (GClosure     *closure,
                                                                            GValue       *return_value,
                                                                            guint         n_param_values,
                                                                            const GValue *param_values,
                                                                            gpointer      invocation_hint,
                                                                            gpointer      marshal_data);
#define e_marshal_NONE__INT_POINTER_INT_OBJECT_INT_INT_BOXED_UINT_UINT	e_marshal_VOID__INT_POINTER_INT_OBJECT_INT_INT_BOXED_UINT_UINT

/* NONE:INT,POINTER,INT,OBJECT,UINT (e-marshal.list:35) */
extern void e_marshal_VOID__INT_POINTER_INT_OBJECT_UINT (GClosure     *closure,
                                                         GValue       *return_value,
                                                         guint         n_param_values,
                                                         const GValue *param_values,
                                                         gpointer      invocation_hint,
                                                         gpointer      marshal_data);
#define e_marshal_NONE__INT_POINTER_INT_OBJECT_UINT	e_marshal_VOID__INT_POINTER_INT_OBJECT_UINT

/* NONE:INT,STRING (e-marshal.list:36) */
extern void e_marshal_VOID__INT_STRING (GClosure     *closure,
                                        GValue       *return_value,
                                        guint         n_param_values,
                                        const GValue *param_values,
                                        gpointer      invocation_hint,
                                        gpointer      marshal_data);
#define e_marshal_NONE__INT_STRING	e_marshal_VOID__INT_STRING

/* NONE:NONE (e-marshal.list:37) */
#define e_marshal_VOID__VOID	g_cclosure_marshal_VOID__VOID
#define e_marshal_NONE__NONE	e_marshal_VOID__VOID

/* NONE:OBJECT (e-marshal.list:38) */
#define e_marshal_VOID__OBJECT	g_cclosure_marshal_VOID__OBJECT
#define e_marshal_NONE__OBJECT	e_marshal_VOID__OBJECT

/* NONE:OBJECT,OBJECT (e-marshal.list:39) */
extern void e_marshal_VOID__OBJECT_OBJECT (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);
#define e_marshal_NONE__OBJECT_OBJECT	e_marshal_VOID__OBJECT_OBJECT

/* NONE:OBJECT,DOUBLE,DOUBLE,BOOLEAN (e-marshal.list:40) */
extern void e_marshal_VOID__OBJECT_DOUBLE_DOUBLE_BOOLEAN (GClosure     *closure,
                                                          GValue       *return_value,
                                                          guint         n_param_values,
                                                          const GValue *param_values,
                                                          gpointer      invocation_hint,
                                                          gpointer      marshal_data);
#define e_marshal_NONE__OBJECT_DOUBLE_DOUBLE_BOOLEAN	e_marshal_VOID__OBJECT_DOUBLE_DOUBLE_BOOLEAN

/* NONE:POINTER (e-marshal.list:41) */
#define e_marshal_VOID__POINTER	g_cclosure_marshal_VOID__POINTER
#define e_marshal_NONE__POINTER	e_marshal_VOID__POINTER

/* NONE:POINTER,BOOLEAN (e-marshal.list:42) */
extern void e_marshal_VOID__POINTER_BOOLEAN (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);
#define e_marshal_NONE__POINTER_BOOLEAN	e_marshal_VOID__POINTER_BOOLEAN

/* NONE:POINTER,BOOLEAN,BOOLEAN,BOOLEAN (e-marshal.list:43) */
extern void e_marshal_VOID__POINTER_BOOLEAN_BOOLEAN_BOOLEAN (GClosure     *closure,
                                                             GValue       *return_value,
                                                             guint         n_param_values,
                                                             const GValue *param_values,
                                                             gpointer      invocation_hint,
                                                             gpointer      marshal_data);
#define e_marshal_NONE__POINTER_BOOLEAN_BOOLEAN_BOOLEAN	e_marshal_VOID__POINTER_BOOLEAN_BOOLEAN_BOOLEAN

/* NONE:POINTER,INT (e-marshal.list:44) */
extern void e_marshal_VOID__POINTER_INT (GClosure     *closure,
                                         GValue       *return_value,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint,
                                         gpointer      marshal_data);
#define e_marshal_NONE__POINTER_INT	e_marshal_VOID__POINTER_INT

/* NONE:POINTER,INT,INT (e-marshal.list:45) */
extern void e_marshal_VOID__POINTER_INT_INT (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);
#define e_marshal_NONE__POINTER_INT_INT	e_marshal_VOID__POINTER_INT_INT

/* NONE:POINTER,INT,INT,INT (e-marshal.list:46) */
extern void e_marshal_VOID__POINTER_INT_INT_INT (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);
#define e_marshal_NONE__POINTER_INT_INT_INT	e_marshal_VOID__POINTER_INT_INT_INT

/* NONE:POINTER,INT,OBJECT (e-marshal.list:47) */
extern void e_marshal_VOID__POINTER_INT_OBJECT (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);
#define e_marshal_NONE__POINTER_INT_OBJECT	e_marshal_VOID__POINTER_INT_OBJECT

/* NONE:POINTER,POINTER (e-marshal.list:48) */
extern void e_marshal_VOID__POINTER_POINTER (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);
#define e_marshal_NONE__POINTER_POINTER	e_marshal_VOID__POINTER_POINTER

/* NONE:POINTER,POINTER,INT (e-marshal.list:49) */
extern void e_marshal_VOID__POINTER_POINTER_INT (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);
#define e_marshal_NONE__POINTER_POINTER_INT	e_marshal_VOID__POINTER_POINTER_INT

/* OBJECT:OBJECT,DOUBLE,DOUBLE,BOOLEAN (e-marshal.list:50) */
extern void e_marshal_OBJECT__OBJECT_DOUBLE_DOUBLE_BOOLEAN (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* POINTER:NONE (e-marshal.list:51) */
extern void e_marshal_POINTER__VOID (GClosure     *closure,
                                     GValue       *return_value,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint,
                                     gpointer      marshal_data);
#define e_marshal_POINTER__NONE	e_marshal_POINTER__VOID

G_END_DECLS

#endif /* __e_marshal_MARSHAL_H__ */

