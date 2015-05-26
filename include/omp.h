/*
 */

/*
 * Copyright (c) 1999, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_OMP_H
#define	_OMP_H

#pragma ident	"@(#)omp.h	1.6	11/03/06 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
#define __SUNW_OMP_THROW_NOTHING throw()
#else
#define __SUNW_OMP_THROW_NOTHING
#endif

typedef enum {
    OL_UNLOCKED=-1,
    OL_INIT,
    OL_LOCKED
} omp_lock_t;

typedef struct {
    omp_lock_t      lock;
    short           owner;
    unsigned short  count;  
} omp_nest_lock_t;

typedef enum omp_sched_t {
    omp_sched_static = 1,
    omp_sched_dynamic = 2,
    omp_sched_guided = 3,
    omp_sched_auto = 4,

    sunw_mp_sched_reserved = 501
} omp_sched_t;

void omp_set_num_threads (int) __SUNW_OMP_THROW_NOTHING;
int omp_get_num_threads (void) __SUNW_OMP_THROW_NOTHING;

int omp_get_max_threads (void) __SUNW_OMP_THROW_NOTHING;
int omp_get_thread_num (void) __SUNW_OMP_THROW_NOTHING;
int omp_get_num_procs (void) __SUNW_OMP_THROW_NOTHING;

int omp_in_parallel (void) __SUNW_OMP_THROW_NOTHING;

void omp_set_dynamic (int) __SUNW_OMP_THROW_NOTHING;
int omp_get_dynamic (void) __SUNW_OMP_THROW_NOTHING;

void omp_set_nested (int) __SUNW_OMP_THROW_NOTHING;
int omp_get_nested (void) __SUNW_OMP_THROW_NOTHING;

void omp_init_lock (omp_lock_t *) __SUNW_OMP_THROW_NOTHING;
void omp_init_nest_lock (omp_nest_lock_t *) __SUNW_OMP_THROW_NOTHING;

void omp_destroy_lock (omp_lock_t *) __SUNW_OMP_THROW_NOTHING;
void omp_destroy_nest_lock (omp_nest_lock_t *) __SUNW_OMP_THROW_NOTHING;

void omp_set_lock (omp_lock_t *) __SUNW_OMP_THROW_NOTHING;
void omp_set_nest_lock (omp_nest_lock_t *) __SUNW_OMP_THROW_NOTHING;

void omp_unset_lock (omp_lock_t *) __SUNW_OMP_THROW_NOTHING;
void omp_unset_nest_lock (omp_nest_lock_t *) __SUNW_OMP_THROW_NOTHING;

int  omp_test_lock (omp_lock_t *) __SUNW_OMP_THROW_NOTHING;
int  omp_test_nest_lock (omp_nest_lock_t *) __SUNW_OMP_THROW_NOTHING;

double omp_get_wtick (void) __SUNW_OMP_THROW_NOTHING;
double omp_get_wtime (void) __SUNW_OMP_THROW_NOTHING;

void omp_set_schedule (omp_sched_t kind, int modifier) __SUNW_OMP_THROW_NOTHING;
void omp_get_schedule (omp_sched_t *kind, int *modifier) __SUNW_OMP_THROW_NOTHING;

void omp_set_max_active_levels (int num) __SUNW_OMP_THROW_NOTHING;
int omp_get_max_active_levels (void) __SUNW_OMP_THROW_NOTHING;

int omp_get_level (void) __SUNW_OMP_THROW_NOTHING;
int omp_get_active_level (void) __SUNW_OMP_THROW_NOTHING;

int omp_get_thread_limit (void) __SUNW_OMP_THROW_NOTHING;

int omp_get_ancestor_thread_num (int level) __SUNW_OMP_THROW_NOTHING;

int omp_get_team_size (int level) __SUNW_OMP_THROW_NOTHING;

int omp_in_final(void) __SUNW_OMP_THROW_NOTHING;

#ifdef __cplusplus
}
#endif

#endif	/* _OMP_H */
