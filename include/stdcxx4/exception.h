/*
        Copyright 07/02/98 Sun Microsystems, Inc. All Rights Reserved
*/
/* exception.h

   @(#)exception.h	1.2  07/02/98 11:32:35

   Compatibility declaration for ISO standard exception interface
*/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <new>

using std::exception;
using std::bad_exception;
using std::set_unexpected;
using std::unexpected;
using std::set_terminate;
using std::terminate;

typedef std::exception xmsg;
typedef std::bad_exception xunexpected;

typedef std::bad_alloc xalloc;

#endif
