/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * e-cache.h
 * Copyright 2000, 2001, Ximian, Inc.
 *
 * Authors:
 *   Lauris Kaplinski <lauris@ximian.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License, version 2, as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef _E_CACHE_H_
#define _E_CACHE_H_

#include <sys/types.h>
#include <glib.h>

G_BEGIN_DECLS

typedef struct _ECache ECache;

typedef gpointer (* ECacheDupFunc) (gconstpointer data);
typedef void (* ECacheFreeFunc) (gpointer data);

ECache * e_cache_new (GHashFunc key_hash_func,
		      GCompareFunc key_compare_func,
		      ECacheDupFunc key_dup_func,
		      ECacheFreeFunc key_free_func,
		      ECacheFreeFunc object_free_func,
		      size_t softlimit,
		      size_t hardlimit);

void e_cache_ref (ECache * cache);
void e_cache_unref (ECache * cache);

gpointer e_cache_lookup (ECache * cache, gconstpointer key);
gpointer e_cache_lookup_notouch (ECache * cache, gconstpointer key);

gboolean e_cache_insert (ECache * cache, gpointer key, gpointer data, size_t size);

void e_cache_invalidate (ECache * cache, gpointer key);
void e_cache_invalidate_all (ECache * cache);

size_t e_cache_query_object_size (ECache * cache, gconstpointer key);

G_END_DECLS

#endif
