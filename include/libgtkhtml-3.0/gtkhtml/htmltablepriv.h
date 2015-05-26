/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* This file is part of the GtkHTML library

   Copyright (C) 2001 Ximian, Inc.
   Authors:           Radek Doulik (rodo@ximian.com)

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHcANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef _HTMLTABLE_PRIV_H_
#define _HTMLTABLE_PRIV_H_

#include "htmltypes.h"

void  html_table_alloc_cell  (HTMLTable     *table,
			      gint           r,
			      gint           c);
void  html_table_set_cell    (HTMLTable     *table,
			      gint           r,
			      gint           c,
			      HTMLTableCell *cell);

#endif
