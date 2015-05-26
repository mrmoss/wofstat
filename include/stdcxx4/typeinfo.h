/*
        Copyright 06/05/98 Sun Microsystems, Inc. All Rights Reserved
*/
/* typoinfo.h

   @(#)typeinfo.h	1.1  06/05/98 11:07:58

   Compatibility declaration for ISO standard typeinfo interface
*/

#ifndef _TYPEINFO_H
#define _TYPEINFO_H

#include <exception.h>

#include <typeinfo>

using std::type_info;
using std::bad_typeid;
using std::bad_cast;

#endif
