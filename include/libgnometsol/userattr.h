/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef USERATTR_H
#define USERATTR_H

#include <user_attr.h>

#define USERATTR_CLEARANCE              "clearance"
#define USERATTR_LABELVIEW              "labelview"
#define USERATTR_LABELVIEW_EXTERNAL     "external"
#define USERATTR_LABELVIEW_HIDESL       "hidesl"
#define USERATTR_HIDESL                 USERATTR_LABELVIEW_HIDESL
#define USERATTR_LABELVIEW_INTERNAL     "internal"
#define USERATTR_LABELVIEW_SHOWSL       "showsl"
#define USERATTR_LABELTRANS             "labeltrans"
#define USERATTR_LOCK                   "lock_after_retries"
#define USERATTR_LOCK_NO                "no"
#define USERATTR_LOCK_YES               "yes"
#define USERATTR_MINLABEL               "min_label"
#define USERATTR_PASSWD                 "password"
#define USERATTR_PASSWD_AUTOMATIC       "automatic"
#define USERATTR_PASSWD_MANUAL          "manual"
#define USERATTR_TYPE_ROLE              USERATTR_TYPE_NONADMIN_KW

char *gnome_tsol_get_usrattr_val (userattr_t *uattr, char *keywd);

#endif /* USERATTR_H */
