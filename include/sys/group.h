/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_GROUP_H
#define	_GROUP_H

#pragma ident	"@(#)group.h	1.3	10/03/22 SMI"

/*
 * Group Abstraction
 */

#ifdef	__cplusplus
extern "C" {
#endif

#if (defined(_KERNEL) || defined(_KMEMUSER))
#include <sys/types.h>

#define	GRP_RESIZE	0x1	/* Resize group capacity if needed */
#define	GRP_NORESIZE	0x2	/* Do not resize group capacity; may fail */

/*
 * group structure
 */
typedef struct group {
	uint_t		grp_size;	/* # of elements */
	uint_t		grp_capacity;	/* current group capacity */
	void		**grp_set;	/* element vector */
} group_t;

typedef uint_t group_iter_t;


/*
 * Return the number of elements in the group
 */
#define	GROUP_SIZE(grp)			((grp)->grp_size)

/*
 * Access the element at the specified group index
 */
#define	GROUP_ACCESS(grp, index)	((grp)->grp_set[index])

/*
 * Group creation / destruction
 */
void		group_create(group_t *);
void		group_destroy(group_t *);

/*
 * Expand a group's holding capacity
 */
void		group_expand(group_t *, uint_t);

/*
 * Group element iteration
 */
void		group_iter_init(group_iter_t *);
void		*group_iterate(group_t *, group_iter_t *);

/*
 * Add / remove an element (or elements) from the group
 */
int		group_add(group_t *, void *, int);
int		group_remove(group_t *, void *, int);
void		group_empty(group_t *);

/*
 * Add / remove / access an element at a specified index.
 * The group must already have sufficient capacity to hold
 * an element at the specified index.
 */
int		group_add_at(group_t *, void *, uint_t);
void		group_remove_at(group_t *, uint_t);

/*
 * Search for an element in a group.
 * Returns an index that may be used with the *_at()
 * routines above to add or remove the element.
 */
uint_t		group_find(group_t *, void *);

/*
 * Convert a group to a string with list of integers.
 *
 * The consecutive integer values are represented using x-y notation.
 * The resulting string looks like "1,2-5,8"
 *
 * The convert argument is used to map group elements to integer IDs.
 * The output buffer and its length are specfied in the arguments.
 */
extern char *group2intlist(group_t *, char *, size_t, int (convert)(void*));

#endif	/* !_KERNEL && !_KMEMUSER */

#ifdef	__cplusplus
}
#endif

#endif /* _GROUP_H */
