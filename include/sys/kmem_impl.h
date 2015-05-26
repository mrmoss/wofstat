/*
 * Copyright (c) 1994, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_KMEM_IMPL_H
#define	_SYS_KMEM_IMPL_H

#pragma ident	"@(#)kmem_impl.h	1.20	12/01/20 SMI"

#include <sys/kmem.h>
#include <sys/vmem.h>
#include <sys/thread.h>
#include <sys/t_lock.h>
#include <sys/time.h>
#include <sys/kstat.h>
#include <sys/cpuvar.h>
#include <sys/systm.h>
#include <vm/page.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * kernel memory allocator: implementation-private data structures
 */

#define	KMF_AUDIT	0x00000001	/* transaction auditing */
#define	KMF_DEADBEEF	0x00000002	/* deadbeef checking */
#define	KMF_REDZONE	0x00000004	/* redzone checking */
#define	KMF_CONTENTS	0x00000008	/* freed-buffer content logging */
#define	KMF_STICKY	0x00000010	/* if set, override /etc/system */
#define	KMF_NOMAGAZINE	0x00000020	/* disable per-cpu magazines */
#define	KMF_FIREWALL	0x00000040	/* put all bufs before unmapped pages */
#define	KMF_LITE	0x00000100	/* lightweight debugging */

#define	KMF_HASH	0x00000200	/* cache has hash table */
#define	KMF_RANDOMIZE	0x00000400	/* randomize other kmem_flags */

#define	KMF_DUMPDIVERT	0x00001000	/* use alternate memory at dump time */
#define	KMF_DUMPUNSAFE	0x00002000	/* flag caches used at dump time */
#define	KMF_PREFILL	0x00004000	/* Prefill the slab when created. */
#define	KMF_DUMPOVERFLOW 0x00008000	/* flag unsafe allocs */

#define	KMF_BUFTAG	(KMF_DEADBEEF | KMF_REDZONE)
#define	KMF_TOUCH	(KMF_BUFTAG | KMF_LITE | KMF_CONTENTS)
#define	KMF_RANDOM	(KMF_TOUCH | KMF_AUDIT | KMF_NOMAGAZINE)
#define	KMF_DEBUG	(KMF_RANDOM | KMF_FIREWALL)

#define	KMEM_STACK_DEPTH	15

#define	KMEM_FREE_PATTERN		0xdeadbeefdeadbeefULL
#define	KMEM_UNINITIALIZED_PATTERN	0xbaddcafebaddcafeULL
#define	KMEM_REDZONE_PATTERN		0xfeedfacefeedfaceULL
#define	KMEM_REDZONE_BYTE		0xbb

/*
 * Redzone size encodings for kmem_alloc() / kmem_free().  We encode the
 * allocation size, rather than storing it directly, so that kmem_free()
 * can distinguish frees of the wrong size from redzone violations.
 *
 * A size of zero is never valid.
 */
#define	KMEM_SIZE_ENCODE(x)	(251 * (x) + 1)
#define	KMEM_SIZE_DECODE(x)	((x) / 251)
#define	KMEM_SIZE_VALID(x)	((x) % 251 == 1 && (x) != 1)

/*
 * The bufctl (buffer control) structure keeps some minimal information
 * about each buffer: its address, its slab, and its current linkage,
 * which is either on the slab's freelist (if the buffer is free), or
 * on the cache's buf-to-bufctl hash table (if the buffer is allocated).
 * In the case of non-hashed, or "raw", caches (the common case), only
 * the freelist linkage is necessary: the buffer address is at a fixed
 * offset from the bufctl address, and the slab is at the end of the page.
 *
 * NOTE: bc_next must be the first field; raw buffers have linkage only.
 */
typedef struct kmem_bufctl {
	struct kmem_bufctl	*bc_next;	/* next bufctl struct */
	void			*bc_addr;	/* address of buffer */
	struct kmem_slab	*bc_slab;	/* controlling slab */
} kmem_bufctl_t;

/*
 * The KMF_AUDIT version of the bufctl structure.  The beginning of this
 * structure must be identical to the normal bufctl structure so that
 * pointers are interchangeable.
 */
typedef struct kmem_bufctl_audit {
	struct kmem_bufctl	*bc_next;	/* next bufctl struct */
	void			*bc_addr;	/* address of buffer */
	struct kmem_slab	*bc_slab;	/* controlling slab */
	kmem_cache_t		*bc_cache;	/* controlling cache */
	hrtime_t		bc_timestamp;	/* transaction time */
	kthread_t		*bc_thread;	/* thread doing transaction */
	struct kmem_bufctl	*bc_lastlog;	/* last log entry */
	void			*bc_contents;	/* contents at last free */
	int			bc_depth;	/* stack depth */
	pc_t			bc_stack[KMEM_STACK_DEPTH];	/* pc stack */
} kmem_bufctl_audit_t;

/*
 * A kmem_buftag structure is appended to each buffer whenever any of the
 * KMF_BUFTAG flags (KMF_DEADBEEF, KMF_REDZONE, KMF_VERIFY) are set.
 */
typedef struct kmem_buftag {
	uint64_t		bt_redzone;	/* 64-bit redzone pattern */
	kmem_bufctl_t		*bt_bufctl;	/* bufctl */
	intptr_t		bt_bxstat;	/* bufctl ^ (alloc/free) */
} kmem_buftag_t;

/*
 * A variant of the kmem_buftag structure used for KMF_LITE caches.
 * Previous callers are stored in reverse chronological order. (i.e. most
 * recent first)
 */
typedef struct kmem_buftag_lite {
	kmem_buftag_t		bt_buftag;	/* a normal buftag */
	pc_t			bt_history[1];	/* zero or more callers */
} kmem_buftag_lite_t;

#define	KMEM_BUFTAG_LITE_SIZE(f)	\
	(offsetof(kmem_buftag_lite_t, bt_history[f]))

#define	KMEM_BUFTAG(cp, buf)		\
	((kmem_buftag_t *)((char *)(buf) + (cp)->cache_buftag))

#define	KMEM_BUFCTL(cp, buf)		\
	((kmem_bufctl_t *)((char *)(buf) + (cp)->cache_bufctl))

#define	KMEM_BUF(cp, bcp)		\
	((void *)((char *)(bcp) - (cp)->cache_bufctl))

#define	KMEM_SLAB(cp, buf)		\
	((kmem_slab_t *)P2END((uintptr_t)(buf), (cp)->cache_slabsize) - 1)

/*
 * Define an alternate heap area to be used during crash dump
 * processing.  If this alternate heap area overflows then the regular
 * heap is used. If this happens the kmem data structures will appear
 * to be corrupted. Overflow occurred if kdd_hiwater > kdd_size. The
 * ::kmem_dump dcmd in mdb displays this information.
 */
typedef struct kmem_dump_log {
	kmem_cache_t	*kdl_cache;
	uint_t		kdl_allocs;		/* # of dump allocations */
	uint_t		kdl_frees;		/* # of dump frees */
	uint_t		kdl_overflows;		/* # of overflows */
	uint_t		kdl_free_nondump;	/* # of non-dump frees */
} kmem_dump_log_t;

#define	KMEM_DUMP_LOGS  (100)
#define	KMEM_NODUMPLOG	((kmem_dump_log_t *)-1)

/* Test for dump heap error condition */
#define	KMEM_DUMP_WARN(cp)				\
	(((cp)->cache_flags & KMF_DUMPOVERFLOW) ||	\
	    (((cp)->cache_flags & KMF_DUMPUNSAFE) &&	\
		(cp)->cache_dumplog != NULL))

typedef struct kmem_dump {
	size_t	kdd_size;		/* size of heap area */
	size_t	kdd_hiwater;		/* maximum heap demand */
	void	*kdd_start;		/* start of pre-reserved heap */
	void	*kdd_end;		/* end of heap area */
	void	*kdd_curr;		/* current free heap pointer */
	size_t	kdd_used;		/* heap bytes in use */
	uint_t	kdd_oversize_allocs;	/* count of allocs */
	uint_t	kdd_oversize_max;	/* maximum size */
	int	kdd_overflows;		/* count overflows */
	int	kdd_log_idx;		/* highest log index */
} kmem_dump_t;

/* Append to each buf created in the pre-reserved heap */
typedef struct kmem_dumpctl {
	void	*kdc_next;		/* cache dump free list linkage */
} kmem_dumpctl_t;

#define	KMEM_DUMPCTL(cp, buf)	\
	((kmem_dumpctl_t *)P2ROUNDUP((uintptr_t)(buf) + (cp)->cache_bufsize, \
	    sizeof (void *)))

/* Test for using alternate memory at dump time */
#define	KMEM_DUMP(cp)		((cp)->cache_flags & KMF_DUMPDIVERT)
#define	KMEM_DUMPCC(ccp)	((ccp)->cc_flags & KMF_DUMPDIVERT)

/*
 * The "CPU" macro loads a cpu_t that refers to the cpu that the current
 * thread is running on at the time the macro is executed.  A context switch
 * may occur immediately after loading this data structure, leaving this
 * thread pointing at the cpu_t for the previous cpu.  This is not a problem;
 * we'd just end up checking the previous cpu's per-cpu cache, and then check
 * the other layers of the kmem cache if need be.
 *
 * It's not even a problem if the old cpu gets DR'ed out during the context
 * switch.  The cpu-remove DR operation bzero()s the cpu_t, but doesn't free
 * it.  So the cpu_t's cpu_cache_offset would read as 0, causing us to use
 * cpu 0's per-cpu cache.
 *
 * So, there is no need to disable kernel preemption while using the CPU macro
 * below since if we have been context switched, there will not be any
 * correctness problem, just a momentary use of a different per-cpu cache.
 */

#define	KMEM_CPU_CACHE(cp)                                              \
	(kmem_cpu_cache_t *)((char *)(&cp->cache_cpu) + CPU->cpu_cache_offset)

#define	KMEM_MAGAZINE_VALID(cp, mp)	\
	(((kmem_slab_t *)P2END((uintptr_t)(mp), PAGESIZE) - 1)->slab_cache == \
	    (cp)->cache_magtype->mt_cache)

#define	KMEM_SLAB_MEMBER(sp, buf)	\
	((size_t)(buf) - (size_t)(sp)->slab_base < \
	    (sp)->slab_cache->cache_slabsize)

#define	KMEM_BUFTAG_ALLOC	0xa110c8edUL
#define	KMEM_BUFTAG_FREE	0xf4eef4eeUL

typedef struct kmem_slab {
	struct kmem_cache	*slab_cache;	/* controlling cache */
	void			*slab_base;	/* base of allocated memory */
	struct kmem_slab	*slab_next;	/* next slab on freelist */
	struct kmem_slab	*slab_prev;	/* prev slab on freelist */
	struct kmem_bufctl	*slab_head;	/* first free buffer */
	long			slab_refcnt;	/* outstanding allocations */
	long			slab_chunks;	/* chunks (bufs) in this slab */
} kmem_slab_t;

#define	KMEM_HASH_INITIAL	64

#define	KMEM_HASH(cp, buf)	\
	((cp)->cache_hash_table +	\
	(((uintptr_t)(buf) >> (cp)->cache_hash_shift) & (cp)->cache_hash_mask))

typedef struct kmem_magazine {
	void	*mag_next;
	void	*mag_round[1];		/* one or more rounds */
} kmem_magazine_t;

/*
 * The magazine types for fast per-cpu allocation
 */
typedef struct kmem_magtype {
	short		mt_magsize;	/* magazine size (number of rounds) */
	int		mt_align;	/* magazine alignment */
	size_t		mt_minbuf;	/* all smaller buffers qualify */
	size_t		mt_maxbuf;	/* no larger buffers qualify */
	kmem_cache_t	*mt_cache;	/* magazine cache */
} kmem_magtype_t;

#define	KMEM_CPU_CACHE_SIZE	64	/* must be power of 2 */
#define	KMEM_CPU_PAD		(KMEM_CPU_CACHE_SIZE - sizeof (kmutex_t) - \
	2 * sizeof (uint64_t) - 2 * sizeof (void *) - sizeof (int) - \
	5 * sizeof (short))
#define	KMEM_CACHE_SIZE(ncpus)	\
	((size_t)(&((kmem_cache_t *)0)->cache_cpu[ncpus]))

/* Offset from kmem_cache->cache_cpu for per cpu caches */
#define	KMEM_CPU_CACHE_OFFSET(cpuid)                                    \
	((size_t)(&((kmem_cache_t *)0)->cache_cpu[cpuid]) -             \
	(size_t)(&((kmem_cache_t *)0)->cache_cpu))

typedef struct kmem_cpu_cache {
	kmutex_t	cc_lock;	/* protects this cpu's local cache */
	uint64_t	cc_alloc;	/* allocations from this cpu */
	uint64_t	cc_free;	/* frees to this cpu */
	kmem_magazine_t	*cc_loaded;	/* the currently loaded magazine */
	kmem_magazine_t	*cc_ploaded;	/* the previously loaded magazine */
	int		cc_flags;	/* CPU-local copy of cache_flags */
	short		cc_rounds;	/* number of objects in loaded mag */
	short		cc_prounds;	/* number of objects in previous mag */
	short		cc_magsize;	/* number of rounds in a full mag */
	short		cc_dump_rounds;	/* dump time copy of cc_rounds */
	short		cc_dump_prounds; /* dump time copy of cc_prounds */
	char		cc_pad[KMEM_CPU_PAD]; /* for nice alignment */
} kmem_cpu_cache_t;

/*
 * The magazine lists used in the depot.
 */
typedef struct kmem_maglist {
	kmem_magazine_t	*ml_list;	/* magazine list */
	long		ml_total;	/* number of magazines */
	long		ml_min;		/* min since last update */
	long		ml_reaplimit;	/* max reapable magazines */
	uint64_t	ml_alloc;	/* allocations from this list */
} kmem_maglist_t;

#define	KMEM_CACHE_NAMELEN	31

struct kmem_cache {
	/*
	 * Statistics
	 */
	uint64_t	cache_slab_create;	/* slab creates */
	uint64_t	cache_slab_destroy;	/* slab destroys */
	uint64_t	cache_slab_alloc;	/* slab layer allocations */
	uint64_t	cache_slab_free;	/* slab layer frees */
	uint64_t	cache_alloc_fail;	/* total failed allocations */
	uint64_t	cache_buftotal;		/* total buffers */
	uint64_t	cache_bufmax;		/* max buffers ever */
	uint64_t	cache_bufslab;		/* buffers free in slab layer */
	uint64_t	cache_rescale;		/* # of hash table rescales */
	uint64_t	cache_lookup_depth;	/* hash lookup depth */
	uint64_t	cache_depot_contention;	/* mutex contention count */
	uint64_t	cache_depot_contention_prev; /* previous snapshot */

	/*
	 * Cache properties
	 */
	char		cache_name[KMEM_CACHE_NAMELEN + 1];
	size_t		cache_bufsize;		/* object size */
	size_t		cache_align;		/* object alignment */
	int		(*cache_constructor)(void *, void *, int);
	void		(*cache_destructor)(void *, void *);
	void		(*cache_reclaim)(void *);
	void		*cache_private;		/* opaque arg to callbacks */
	vmem_t		*cache_arena;		/* vmem source for slabs */
	int		cache_cflags;		/* cache creation flags */
	int		cache_flags;		/* various cache state info */
	uint32_t	cache_mtbf;		/* induced alloc failure rate */
	uint32_t	cache_pad1;		/* to align cache_lock */
	kstat_t		*cache_kstat;		/* exported statistics */
	kmem_cache_t	*cache_next;		/* forward cache linkage */
	kmem_cache_t	*cache_prev;		/* backward cache linkage */

	/*
	 * Slab layer
	 */
	kmutex_t	cache_lock;		/* protects slab layer */
	size_t		cache_chunksize;	/* buf + alignment [+ debug] */
	size_t		cache_slabsize;		/* size of a slab */
	size_t		cache_bufctl;		/* buf-to-bufctl distance */
	size_t		cache_buftag;		/* buf-to-buftag distance */
	size_t		cache_verify;		/* bytes to verify */
	size_t		cache_contents;		/* bytes of saved content */
	size_t		cache_color;		/* next slab color */
	size_t		cache_mincolor;		/* maximum slab color */
	size_t		cache_maxcolor;		/* maximum slab color */
	size_t		cache_hash_shift;	/* get to interesting bits */
	size_t		cache_hash_mask;	/* hash table mask */
	kmem_slab_t	*cache_freelist;	/* slab free list */
	kmem_slab_t	cache_nullslab;		/* end of freelist marker */
	kmem_cache_t	*cache_bufctl_cache;	/* source of bufctls */
	kmem_bufctl_t	**cache_hash_table;	/* hash table base */
	kmem_dump_log_t	*cache_dumplog;		/* log entry during dump */

	/*
	 * Depot layer
	 */
	kmutex_t	cache_depot_lock;	/* protects depot */
	kmem_magtype_t	*cache_magtype;		/* magazine type */
	void		*cache_dumpfreelist;	/* heap during crash dump */
	kmem_maglist_t	cache_full;		/* full magazines */
	kmem_maglist_t	cache_empty;		/* empty magazines */

	/*
	 * Per-CPU layer
	 */
	kmem_cpu_cache_t cache_cpu[1];		/* max_ncpus actual elements */
};

typedef struct kmem_cpu_log_header {
	kmutex_t	clh_lock;
	char		*clh_current;
	size_t		clh_avail;
	int		clh_chunk;
	int		clh_hits;
	char		clh_pad[64 - sizeof (kmutex_t) - sizeof (char *) -
				sizeof (size_t) - 2 * sizeof (int)];
} kmem_cpu_log_header_t;

typedef struct kmem_log_header {
	kmutex_t	lh_lock;
	char		*lh_base;
	int		*lh_free;
	size_t		lh_chunksize;
	int		lh_nchunks;
	int		lh_head;
	int		lh_tail;
	int		lh_hits;
	kmem_cpu_log_header_t lh_cpu[1];	/* ncpus actually allocated */
} kmem_log_header_t;

#define	KMEM_ALIGN		8	/* min guaranteed alignment */
#define	KMEM_ALIGN_SHIFT	3	/* log2(KMEM_ALIGN) */
#define	KMEM_VOID_FRACTION	8	/* never waste more than 1/8 of slab */

#define	KMEM_SLAB_IS_PARTIAL(sp)                \
	((sp)->slab_refcnt > 0 && (sp)->slab_refcnt < (sp)->slab_chunks)


#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_KMEM_IMPL_H */
